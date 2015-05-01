# function should take in a python matrice that is pulled
# directly from a matlab workspace,modify it so that 
# it fits the characteristics and dimensiosn needed to conduct
# regression on it and then return the appropriate name
# as passed into the function

# Test: input is Cprices. Convert to 

# input is of type 1 x n where n is # of assets and 
# each element of this row vector contains a column vector
# with price, volume etc. for that asset for that time period
# 
# want to return vector with same name (but an m is appended to it)
# Say Cprices is passed in. return mCPrices where mCPrices[2][4]
# represents the price for asset 3(as python is zero based) and
# time period 5
import numpy as np
# var is the variable to convert.
# multiasset is boolean representing if it is multidimensional or not
# (as in the case of riskfree/inflation)

def toSciPyFormat(var,multiasset):
	
	numassets=var.shape[1]
	numtimeperiods=var[0,1].shape[0]
	Rvar = np.empty([numassets,numtimeperiods])
	
	for asset in range(0,numassets):
		Rvartemp=np.array([])
		# Avar represents a particular
		numtimeperiods=var[0,asset].shape[0]
		for timeperiod in range (0,numtimeperiods):
			print "in this iteration asset is %d, time period is %d" % (asset,timeperiod)
			print var[0,asset][timeperiod][0]
			Rvartemp=np.append(Rvartemp,var[0,asset][timeperiod][0])
			# print Rvar.shape
		# add the latest asset data to Rvar(as a column vector)
		print "Rvartemp is"
		print Rvartemp
		# Rvar=np.append(Rvar,Rvartemp)
		Rvar[asset]=Rvartemp		
	# Can now call Rvar[asset#][timeperiod#]

	return Rvar
# extract a column from a multidimensional NumPy array
# def column(matrix, i):
#     return [row[i] for row in matrix]

# this essentially reverse the toSciPyFormat function
# Note that this function might not be needed
# def toMatLabFormat(var):



#---------------------------------------------------------------
# Function should merge the amtrices together to create the
# "x" feature set that is used to produce the matrix 
# it should return this x vector as long as a string
# that represents the names off all the vectors used in combination
# to create this feature set
# (this function can be equivalently used for the predicted "y")

#---------------------------------------------------------------
# Function that takes in the name of a scipy vector and
# automaticaly creates python variables names that are 
# the same as that in the matlab workspace loaded in
# (eventually can combine this with function 1 above)

#------------------------------------------------------------
# Function that takes in the names and values
# to use for the x(predictors), and the y values(predicted)
# It also takes in the name of the type of ML technique 
# to be applied to it and eventually, perhaps even a set of dates
# that it may be applied to
# Try to make it modular enough that it can be applied and combined 
# to a specific set of assets