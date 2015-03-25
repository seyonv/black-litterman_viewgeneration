# print "testing if call to python works"
# attempt to read in workspace1.mat
# /Users/User/Desktop/Thesis-Final/MainProgramFiles/workspace_files

import scipy.io
import numpy as np
import pdb #this is the python debugger
import matplotlib.pyplot as plt
from ML_functions import *
import numpy as np
import datetime
date_string = datetime.datetime.now().strftime("%Y-%m-%d-%H:%M")

from globalpython import *


# define readfrom path an writeto path
readfrom = W1_Mat2Py_path
writeto  = W1_Py2Mat_path

fileW1 = scipy.io.loadmat(readfrom);
pyVolume=fileW1['Avolume']
pyPrice=fileW1['Aprice']

# For the first element of Voluem and Price (1 particular stock)
# perform a kNN analysis

#pyVolume[0,i] is stock i and only 1 row exists
i=1
oldx= pyVolume[0,i] #has shape of (62,1)
oldy= pyPrice[0,i]

x=np.array([])
y=np.array([])
for i in range(0,oldx.size):
	x=np.append(x,oldx[i][0])

for i in range(0, oldy.size):
	y=np.append(y,oldy[i][0])	

assert (x.shape == y.shape),"size of x and y vectors are not equal"
# size_divide 
#write function to separate the points into training, validation and test
#
trainX=x[0:20]
validX=x[20:40]
testX=x[40:61]

trainY=y[0:20]
validY=y[20:40]
testY=y[40:61]


print "-------------PART A(K NearestNeighbors(k=1))-----------------\n"
A_predY,MSE_A=kNN1(trainX,trainY,testX,testY)
print "MSE on test set: %f" %MSE_A


# use kNN to find the future stock price of a stock based on only the volume as the 
# x Vector (the y vector would be the corresponding stock price)
#  
print "\n/---------PART C(Linear Regression,2 features(including bias))--------"
polydegree=1
C_weights,C_predY,C_MSE=PolynomialRegression(trainX,trainY,testX,testY,polydegree)

print C_MSE


# Code to eventually save python variables as a MATLAB workspace
# Define the Key(what it's name will be when MATLAB accesses it)
# and the value(the variable as saved in python(this must exist already))
scipy.io.savemat(writeto, 
				 mdict={'D_MSE': C_MSE,
				 	   'A_predY':A_predY,
				 	    'MSE_A':MSE_A})

