from bs4 import BeautifulSoup
from globalvar import *
import requests
import os
import csv
import re
import urllib2



def parseTickers(file):
    tickers = []
    with open(file, 'rU') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar=' ')
        for row in spamreader:
            tickers.append(row[0])
    #ticker is an array that holds all symbols from TSX100
    return tickers

# The parameters entereed are the ticker symbol to download and
# a boolean representing if it is the last or among the last tickers
# this indicates the stock is an index and a market cap
# should not be retrieved for it
def scrapYahooPage(ticker,isindex):
    # craft url query
    stock = ticker
    
    # recall that 0 is january, 11 is december
   

    
    # interval = 'm'
    pg = 0
    lastdate = False
  
    csvfile = open('/Users/User/Desktop/Thesis-Final/Python_Files/output/scrape/d'+ticker+'.csv', 'wb')
    writer = csv.writer(csvfile)

    # fetching the number of outstanding shares for the stock (not an index)
    if not(isindex):
        sharesurl = 'http://download.finance.yahoo.com/d/quotes.csv?s=' + stock + '&f=j2'
        
        response = urllib2.urlopen(sharesurl)
        cr = csv.reader(response)
        # this represents the # of shares outstanding
        for row in cr:
            if (row[0]!='N/A'):
                a=int(row[0])
            elif (row[0]=='N/A'):
                print ('equality condition is here')
                a=0
    else:
        a=2 
        print str(index) + " is a market index or fund, not a stock"
        # set a to an arbitrary value so you can ignore the marketcap
        # for the stock indices and they will have values

        


    data_available = True
    while data_available:
        # print a

        url = 'https://ca.finance.yahoo.com/q/hp?s=' + stock + '&a=' + start_month + '&b='+start_day+'&c='+start_year + '&d=' + end_month + '&e=' + end_day + '&f='+end_year+'&g='+interval+'&z=66&y='+str(pg)
        # print "url is "+url
        r = requests.get(url)
        soup = BeautifulSoup(r.text)

        data = soup.find(attrs={'class': 'yfnc_datamodoutline1'})

        if data:
            try:
                rows = data.findAll('td')
            except Exception:
                if(lastdate):
                    print "Last row of prices: " + str(lastdate)
                else:
                    print "No data available"
                data_available = False
                pass
            dateitem = []
            priceitem = []
            volumeitem = []
            lastdate = " "
            lastmon = " "
            month_dict = {'01': 'Jan',
                          '02': 'Feb',
                          '03': 'Mar',
                          '04': 'Apr',
                          '05': 'May',
                          '06': 'Jun',
                          '07': 'Jul',
                          '08': 'Aug',
                          '09': 'Sep',
                          '10': 'Oct',
                          '11': 'Nov',
                          '12': 'Dec'}
            # filter out rows for page end, dividend, split
            exclude = ['Close', 'Dividend', ":", "Split"]
            priceitemcount=0
            for row in rows:
                # print a
                box = row.findAll(text=True)
                item = ','.join(box)
                # print(item[0],row)
                itemlength=len(item.decode("utf-8"))
                # print "Current element is "+str(item)+" ,it's length is "+str(itemlength)
                # print len(item.decode("utf-8"));
                # if re.search('[a-zA-Z]+', item):
                if re.search('[a-zA-Z]+', item) and not any(n in item for n in exclude):
                    # date format 1 Mon day Year

                    date = item.replace(",", "")
                    
                    date = date.replace('"', "")

                    if lastmon not in date:
                        dateitem.append(date)
                    else:
                        dateitem = [date]

                    priceitemcount=0

                elif '-' in item:
                    # date in format 2 year-mon-day
                    datetxt = item.replace("-", " ")
                    date = str(month_dict.get(str(datetxt[5:7]))) + " " + str(datetxt[8:11]) + " " + str(datetxt[:4])
                    if lastmon not in date:
                        dateitem.append(date)
                    else:
                        dateitem = [date]
                    priceitemcount=0

                elif '.' in item  and 'Dividend' not in item and 'Stock Split' not in item:
                    # price object
                    # print(item)
                    priceitemcount+=1
                    # add if date has already been set & you want the adjusted close
                    # as every fifth value will contain the adjusted close
                    if dateitem and priceitemcount==5 :
                        # print(item)
                        item = item.replace(",", "")
                        priceitem.append(item)
                        priceitemcount=0

                # else if item has length longer than 6, is not an index
                # (becuse we use volume=0 to determine which elements are indices)
                elif (len(item.decode("utf-8")) > 6 
                      and 'Dividend' not in item 
                      and 'Stock Split' not in item
                      and isindex==0):
                    # remve commas and quotes before appending it to volume item
                    item = item.replace(",", "")
                    item = item.replace("\"", "")
                    # before appending it to volumeitem
                    volumeitem.append(item)

                elif 'Dividend' in item:
                    # Dividend payment, delete previous date
                    # delete the previous volume item as well
                    dateitem = []
                    priceitem = []
                    volumeitem = []
                    priceitemcount=0


                # if you have the date, adjusted price and volume
                # then you may append the row to the csv file
                if ((dateitem and priceitem and volumeitem) or
                    (dateitem and priceitem and isindex)):
                    if (isindex):
                        volumeitem.append(0);
                    # recall that a represents shares outstanding
                    #if priceitem[0] < 1 then you want to make it a string instead
                    #so get_all_stock_data function will return an error
                    if (priceitem[0] > 1):
                        writer.writerow([dateitem[0], priceitem[0], volumeitem[0], a*float(priceitem[0])])
                    else:
                        print ('priceitem[0] <1')
                        writer.writerow([dateitem[0],priceitem[0], volumeitem[0], a*float(priceitem[0])])

                    lastdate = dateitem[0]
                    lastmon = lastdate[:3]
                    dateitem = []
                    priceitem = []
                    volumeitem = []
                    priceitemcount=0

            pg += 66
            if pg > 594:
                data_available = False
        else:
            data_available = False


# loop over each ticker and get data
tickers = parseTickers(filename)
print "Fetching from file: " + filename + "..."

index = 0
for ticker in tickers:

    # for .csv in ticker symbol
    ticker = ticker.replace('.csv', '')
    # for wikipedia stock names
    ticker = ticker.replace('.', '-')

    # now at EQR, 170
    if index >= offset:
        print "Scraping Stock ("+str(index)+"): " + ticker
        # look at ticker to determine if it's a stock index or not
        if ticker in ('LOMMX','VWELX','^GSPC','^GSPTSE'):
            isindex=1;
            
        else:
            isindex=0;
        scrapYahooPage(ticker,isindex)
    # this index is simply used to only print stocks past the offset
    index += 1

