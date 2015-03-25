#The Beautiful soup library is responsbile for scraping a webpages HTML text 

from bs4 import BeautifulSoup
from globalvar import *
import requests
import os
import csv
import re



def parseTickers(file):
    tickers = []
    with open(file, 'rU') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar=' ')
        for row in spamreader:
            tickers.append(row[0])
    #ticker is an array that holds all symbols from TSX100
    return tickers

def deleteDuplicates(ticker,isindex):
    rows = []
    lastmonth = " "
    scrape_path='/Users/User/Desktop/Thesis-Final/Python_Files/output/scrape/d'
    with open(scrape_path+ticker+'.csv', 'rb') as inputfile:
        reader = csv.reader(inputfile)
        for row in reader:
            key = (row[0], row[1][:5])
            month = key[0][:3]
            if month == lastmonth:
                # 2 consequtive months are the same
                removed = rows.pop()
                print "Removed: " + str(removed)
            rows.append(row)
            lastmonth = month

    # modify the write location that the final csv files are saved to
    # previously 'output/scrape/'
    set1_path='/Users/User/Desktop/Thesis-Final/csv_files/set1/'
    with open(set1_path+ticker+'.csv', 'wb') as outputfile:
        writer = csv.writer(outputfile)
        for row in rows:
            writer.writerow([row[0], row[1],row[2],row[3]])

index = 0
# loop over each ticker and get data
tickers = parseTickers(filename)
print "Fetching from file: " + filename + "..."


for ticker in tickers:

    # for .csv in ticker symbol
    ticker = ticker.replace('.csv', '')
    # for wikipedia stock names
    ticker = ticker.replace('.', '-')
    if index>=offset:
        print "Processing Stock ("+str(index)+"): " + ticker
        if ticker in ('LOMMX','VWELX','^GSPC','^GSPTSE'):
            isindex=1;
            
        else:
            isindex=0;
        deleteDuplicates(ticker,isindex)
    index += 1
# output to a csv
