import numpy as np
import matplotlib.pyplot as plt

def plotData(x,y):
    plt.plot(x,y,'rx')
    plt.xlabel('Population of city in 10,000s')
    plt.ylabel('Profit in $10,000s')
    plt.show()


def gradientDescentStep(x,y,theta,alpha):
    tmp_theta = []
    for j in range(len(theta)):
        tmp_theta.append(theta[j])
        sum = 0
        for i in range(len(y)):
            sum = sum + ((hypothesis(x[i],theta)-y[i])*x[i][j])
        sum = sum/(len(y))
        sum = sum * alpha
        tmp_theta[j] = tmp_theta[j] - sum
    return tmp_theta

def gradientDescent(x,y,theta,alpha,iterations):
    cost = []
    for i in range(iterations):
        cost.append(costFunction(x,y,theta))
        theta = gradientDescentStep(np.array(x),np.array(y),theta,alpha)
    fs = open("Data.txt","w")
    for i in range(len(cost)):
        fs.write(str(cost[i]) + "," + str(i) + "\n")
    fs.close()
    return theta



def hypothesis(x,theta):
    sum = 0
    i = 0
    while i < len(theta):
        sum = sum + (x[i]*theta[i])
        i = i + 1
    return sum

def costFunction(X,Y,theta):
    m = len(Y)
    sum = 0
    i = 0
    while i < m:
        sum = sum + ((hypothesis(X[i],theta)-Y[i])**2)
        i = i + 1
    sum = sum/(2*m)
    return sum

def feature_scaling(x):
    sum = []
    min = []
    max = []
    for i in range(len(x[1])):
        sum.append(0)
        min.append(x[0][i])
        max.append(x[0][i])
    for i in range(len(x)):
        for j in range(len(x[1])):
            sum[j] = sum[j] + x[i][j]
            if(x[i][j] > max[j]):
                max[j] = x[i][j]
            if(x[i][j] < min[j]):
                min[j] = x[i][j]
    avg = []
    for i in range(len(x[1])):
        avg.append(sum[i]/len(x))
    for i in range(len(x)):
        for j in range(len(x[1])):
            x[i][j] = x[i][j] - avg[j]
            if(max[j] != min[j]):
                x[i][j] = x[i][j]/(max[j]-min[j])
            else:
                x[i][j] = 1
    return x
def main_function():
    data = np.loadtxt('ex1data2.txt',delimiter=',')
    x = []
    y = []
    # print(data)
    for element in data:
        tmp = [1]
        j = 0
        while j < (len(element)-1):
            tmp.append(float(element[j]))
            j = j + 1
        x.append(tmp)
        y.append(float(element[j]))
    x = feature_scaling(x)
    alpha = 0.01
    initital_theta = []
    for i in range(len(x[1])):
        initital_theta.append(0)

    intitial_cost = costFunction(x,y,initital_theta)
    print ("STARTING Gradient Descent theta = " + str(initital_theta) + " with cost = " + str(intitial_cost))
    iterationNumber = 15000
    theta = gradientDescent(x,y,initital_theta,alpha,iterationNumber)
    finalCost = costFunction(x,y,theta)
    print ("After 150000 iteration of Gradient Descent \ntheta = " + str(theta) + " with cost = " + str(finalCost))
    return theta

if __name__ == "__main__":
    print("PROGRAM STARTING")
    theta = main_function()