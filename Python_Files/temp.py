from bs4 import BeautifulSoup
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
    
    start_month = '00'
    start_day = '1'
    start_year = '2000'

    end_month = '10'
    end_day = '10'
    end_year = '2014'

    # interval is 'm','y' or 'd'
    interval = 'm'
    pg = 0
    lastdate = False
    # open CSV writer

    # adding d to this in order to ensure that when calling for file lcoation
    # there is a difference between csv's in csv_files and the ones
    # in python_files/output/scrape
    # 
    csvfile = open('/Users/User/Desktop/Thesis-Final/Python_Files/output/scrape/d'+ticker+'.csv', 'wb')
    writer = csv.writer(csvfile)

    # fetching the number of outstanding shares for the stock (not an index)
    if not(isindex):
        sharesurl = 'http://download.finance.yahoo.com/d/quotes.csv?s=' + stock + '&f=j2'
        response = urllib2.urlopen(sharesurl)
        cr = csv.reader(response)
        # this represents the # of shares outstanding
        for row in cr:
            print row[0]

            if (row[0]!='N/A'):
                a=int(row[0])
            elif (row[0]=='N/A'):
                print ('equality condition is here')
                a=0
    else:
        a=2 
        # set a to an arbitrary value so you can ignore the marketcap
        # for the stock indices 

        


    data_available = True
    while data_available:
        # print a

        url = 'https://ca.finance.yahoo.com/q/hp?s=' + stock + '&a=' + start_month + '&b='+start_day+'&c='+start_year + '&d=' + end_month + '&e=' + end_day + '&f='+end_year+'&g='+interval+'&z=66&y='+str(pg)
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
                # print(item)
                # if re.search('[a-zA-Z]+', item):
                if re.search('[a-zA-Z]+', item) and not any(n in item for n in exclude):
                    # date format 1 Mon day Year

                    date = item.replace(",", "")
                    # print(item)
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

                elif '.' in item  and 'Dividend' not in item:
                    # price object
                    # print(item)
                    priceitemcount+=1
                    if dateitem and priceitemcount==5 : # add if date has already been set
                        # print(item)
                        item = item.replace(",", "")
                        priceitem.append(item)
                        priceitemcount=0


                elif 'Dividend' in item:
                    # Dividend payment, delete previous date
                    dateitem = []
                    priceitem = []
                    priceitemcount=0


                if dateitem and priceitem:
                    # recall that a represents shares outstanding
                    #if priceitem[0] < 1 then you want to make it a string instead
                    #so get_all_stock_data function will return an error

                    if (priceitem[0] > 1):
                        writer.writerow([dateitem[0], priceitem[0], a*float(priceitem[0])])
                    else:
                        print ('priceitem[0] <1')
                        writer.writerow([dateitem[0],priceitem[0], a*float(priceitem[0])])

                    lastdate = dateitem[0]
                    lastmon = lastdate[:3]
                    dateitem = []
                    priceitem = []
                    priceitemcount=0

            pg += 66
            if pg > 594:
                data_available = False
        else:
            data_available = False



# import ticker symbols csv file
filename = '/Users/User/Desktop/Thesis-Final/Python_Files/input/stocklist_1.csv'
offset = 0
index = 0

# loop over each ticker and get data
tickers = parseTickers(filename)
print "Fetching from file: " + filename + "..."


for ticker in tickers:

    # for .csv in ticker symbol
    ticker = ticker.replace('.csv', '')
    # for wikipedia stock names
    ticker = ticker.replace('.', '-')

    # now at EQR, 170
    if index >= offset:
        print "Scraping Stock ("+str(index)+"): " + ticker
        # look at ticker to determine if it's a stock index or not
        if ticker in ('LOMMX','VWELX','GSPC','^GSPTSE'):
            isindex=1;
            print str(index) + " is a market index or fund, not a stock"
        else:
            isindex=0;
        scrapYahooPage(ticker,isindex)
    # this index is simply used to only print stocks past the offset
    index += 1

