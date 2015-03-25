
# this file defines all the global variables and shared settings
# between scrape.py and delete.py

# use this file to specify the stocktickerlist, startdate, enddate and offset to start at

global offset,filename
offset=107
filename= '/Users/User/Desktop/Thesis-Final/Python_Files/input/stocklist_2.csv';

global start_month,start_day,start_year
global end_month,end_day,end_year
global interval

# January is month 0, December is month 11
start_month = '0'
start_day   = '1'
start_year  = '2002'

end_month   = '0'
end_day     = '20'
end_year    = '2015'

# interval is 'm','y' or 'd'
interval    = 'm'