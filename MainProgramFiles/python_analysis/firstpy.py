# print "testing if call to python works"
# attempt to read in workspace1.mat
# /Users/User/Desktop/Thesis-Final/MainProgramFiles/workspace_files

import scipy.io
import numpy as np
import pdb #this is the python debugger
import matplotlib.pyplot as plt
from ML_functions import *
import numpy as np
from globalpython import *
from datafunctions import *
import datetime
date_string = datetime.datetime.now().strftime("%Y-%m-%d-%H:%M")




# define readfrom path an writeto path
readfrom = W1_Mat2Py_path
writeto2  = W1_Py2Mat_path
fileW1 = scipy.io.loadmat(readfrom);
# print fileW1
# READ & STORE ALL VARIABLES YOU NEED FROM THE MATLAB WORKSPACE
# All fetched quantitative data is here
locals().update(fileW1)

# This dictionary represents ever element you want to iterate over
toSciPyList={'pyCprices':pyCprices, 'pyCvolumes':pyCvolumes,'pyCmarketscaps':pyCmarketcaps}

mCprices=toSciPyFormat(pyCprices,1)
mCvolumes=toSciPyFormat(pyCvolumes,1)
mCmarketcaps=toSciPyFormat(pyCmarketcaps,1)
# mCriskfreevals=toSciPyFormat(Criskfreevals)

# for key in toSciPyList d = {'a':1, 'b':2}
# # >>> for key,val in d.items():
# #         exec(key + '=val'):
# 	toSciPyList[key]=toSciPyFormat(toSciPyList[key])
# 	exec ( +'=')
# 	# print key,toSciPyList[key].shape
# 	# print 'using key value now'
# 	# print key,value.shape
# 	# print





# mCpricecol0=column(mCprices,0)
# now you want to modify Cprices to become mCprices
# representing that it has been modified by the function
# and is now useable as part of a feature set in regression, NN
# or otherwise
# 
# Perform this conversion on the list of variables written belw
# Cprices,Cvolumes,Cmarketcaps,Criskfreevals,Cinfvals
# 



# scipy.io.savemat(writeto2, 
# 				 mdict={'C_MSE': C_MSE,
# 				 	   'A_predY':A_predY,
# 				 	    'MSE_A':MSE_A})

scipy.io.savemat(writeto2, 
				 mdict={'mCprices': mCprices,
				 	   'mCvolumes':mCvolumes})
