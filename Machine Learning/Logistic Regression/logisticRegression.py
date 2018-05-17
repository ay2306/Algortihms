import numpy as np
import math

def hypothesis(x,theta):
    sum = 0
    i = 0
    while i < len(x):
        sum = sum * (x[i]*theta[i])
        i = i + 1
    num =  (1/(1+math.exp(-1*sum))) #Note that math.exp(x) returns e^x
    return num

def costFunction(x,y,theta):
    sum = 0
    i = 0
    for i in range(len(y)):
        if y[i] == 0:
            sum = sum - math.log(hypothesis(x[i],theta))
        elif y[i] == 1:
            sum = sum - math.log(1-hypothesis(x[i],theta))
    print "COST WHEN theta = " + str(theta) + " is " + str(sum/(len(y)))
    return sum/(len(y))

def gradientDescent(x,y,theta,alpha,iterations):
    for i in range(iterations):
        theta = gradientDescentStep(x,y,theta,alpha)  
    return theta
def gradientDescentStep(x,y,theta,alpha):
    tmp_theta = []
    for j in range(len(theta)):
        sum = 0
        for i in range(len(y)):
            sum = sum + ((hypothesis(x[i],theta)-y[i])*x[i][j])
        sum = sum*alpha
        tmp_theta.append(theta[j] - sum)
    return tmp_theta

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
    data = np.loadtxt('ex2data2.txt',delimiter=',')
    x = []
    y = []
    for element in data:
        tmp = [1]
        i = 0
        for i in range(len(element)-1):
            tmp.append(float(element[i]))
            i = i + 1
        x.append(tmp)
        y.append(float(element[i]))
    x = feature_scaling(x)
    initial_theta = []
    for i in range(len(x[1])):
        initial_theta.append(0)
    alpha = 0.001
    initial_cost = costFunction(x,y,initial_theta)
    print ("STARTING Gradient Descent theta = " + str(initial_theta) + " with cost = " + str(initial_cost))
    iterationNumber = 1500
    theta = gradientDescent(x,y,initial_theta,alpha,iterationNumber)
    # print theta
    finalCost = costFunction(x,y,theta)
    print ("After 150000 iteration of Gradient Descent \ntheta = " + str(theta) + " with cost = " + str(finalCost))
    return theta


if __name__ == "__main__":
    theta = main_function()
    x = [1,0.92684,0.3633]
    print (hypothesis(x,theta))