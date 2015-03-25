
# The format of the functions must be o
# 
import numpy as np
def compute_MSE(n, y_predict, y_true):
    ydiff = abs(y_predict - y_true)
    ydiff2=ydiff*ydiff
    oneA = np.ones(ydiff.shape)
    MSE = pow(n, -1) * (np.dot(ydiff2, oneA))
    return MSE


#specific K nearest neighbour for K=1
def kNN1(xtrain, ytrain, xtest, ytest):
    ypred = np.zeros(xtest.shape)
    for i in range(0, xtest.size):
        test = xtest[i]
        dist = xtrain - test * (np.ones(xtrain.size))
        ind = np.argmin(dist * dist)
        ypred[i] = ytrain[ind]

    assert ypred.size==ytest.size==xtest.size
    MSE = compute_MSE(xtest.size, ypred, ytest)
    return ypred, MSE
#Computing K-nearest neighbours using the SciKit Learn Library



def kNN(xtrain, ytrain, xtest, ytest, k):
    ypred = np.zeros(xtest.shape)
    for i in range(0, xtest.size):
        test = xtest[i]
        dist = xtrain - test * (np.ones(xtrain.size))
        dist2 = dist * dist
        dist_ind = dist2.argsort()[:k]
        currtot = 0
        for j in range(0, dist_ind.size):
            currtot += ytrain[dist_ind[j]]
        value = currtot / float(dist_ind.size)
        ypred[i] = value

    MSE = compute_MSE(xtest.size, ypred, ytest)
    return ypred,MSE

def kNNSci(num_neighbours,xtrain,ytrain,xtest,ytest):
    

    xtrain=xtrain.reshape(xtrain.shape[0],1)
    xtest=xtest.reshape(xtest.shape[0],1)
    neigh = KNeighborsRegressor(num_neighbours)
    ypred=neigh.fit(xtrain,ytrain).predict(xtest)
    # for i, weights in enumerate(['uniform','distance']):
    #     neigh = KNeighborsRegressor(num_neighbours,weights=weights)
    #     ypred=neigh.fit(xtrain,ytrain).predict(xtest)
    
    #     plt.subplot(2, 1, i + 1)
    #     plt.scatter(xtrain, ytrain, c='k', label='data')
    #     plt.plot(xtest, ypred, c='g', label='prediction')
    #     plt.axis('tight')
    #     plt.legend()
    #     plt.title("KNeighborsRegressor (k = %i, weights = '%s')" % (num_neighbours,
    #                                                                 weights))
    # plt.show()

    
    MSE=mean_squared_error(ytest,ypred)
    return ypred,MSE


def PolynomialRegression(xtrain,ytrain,xtest,ytest,polydegree):
    p=np.polyfit(xtrain,ytrain,polydegree)
    ypred=np.polyval(p,xtest)
    MSE=np.mean((ypred-ytest)**2)

    return p,ypred,MSE

def LinearRegression(xtrain,ytrain,xtest,ytest):
    regr=linear_model.LinearRegression()
    regr.fit(xtrain,ytrain)
    weights=regr.coef_
    MSE=np.mean((regr.predict(xtest)-ytest)**2)
    ypred=regr.predict(xtest)
    return weights,MSE,ypred





