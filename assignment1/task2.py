import numpy as num
import matplotlib.pyplot as plot
from sklearn.linear_model import Ridge, RidgeCV
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
from sklearn.metrics import mean_squared_error


def f(x):
    return num.sin(2*x*num.pi)      #generate the sinusoidal fucntion


if __name__ == "__main__":
    fig = plot.figure()
    x_plot = num.arange(0, 1, 0.001);   # randomly generate array between 0 and 1
    x = num.arange(0, 1, 0.001);        # randomly generate array between 0 and 1
    rng = num.random.RandomState(0)     
    rng.shuffle(x)
    k=int(input("Enter the Number of inumuts:"))   #input k elements 
    l=int(input("Enter the Number of errors:"))    #input l elements 
    t=[]
    X = num.random.uniform(0, 1, size=k)           #generate k-sized random array 
    X=num.array(X)
    f1=f(X)                      # generate array of sine values
    f1=num.array(f1)             
    mu=0
    sigma=0.1
    for i in range(k):
        for j in range(l):
            t.append(num.random.normal(mu, sigma)+f1[i])       #add noise to generated values 

    X=num.repeat(X,l)
    t=num.array(t)
    X_plot = x_plot[:, num.newaxis]  
    colors = ['teal', 'yellowgreen', 'gold']
    lw = 2
    alphas = num.linspace(0.00001,0.05,12000)     
    for degree in range(11):
        train_error = []
        for alpha in alphas:    
            for count, degree in enumerate([degree]):
                fig.clf()
                model = make_pipeline(PolynomialFeatures(degree), Ridge(alpha=alpha))  #polyomial fitting with ridge(L2) 
                model.fit(X[:,None], t)
                train_error.append(mean_squared_error(f(x_plot), model.predict(X_plot)))   #testing error
        minimum = "The optimal alpha for order " + str(degree) + " is " + str(alphas[num.argmin(train_error)])
        print(minimum)           
        plot.plot(alphas, train_error, color=colors[count], linewidth=lw)
        plot.title(minimum)
        fig.savefig(str(degree)+'regularization.png', bbox_inches='tight')      #plotting The data

