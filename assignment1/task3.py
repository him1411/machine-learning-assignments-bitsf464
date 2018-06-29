import numpy as num
import matplotlib.pyplot as plot
from scipy import stats
from sklearn.linear_model import BayesianRidge, LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
 
def f(x):
    return num.sin(2 * num.pi * x)

def baysian_curve ():
    for degree in range(1,12):
        clf_poly = BayesianRidge(compute_score=True)
        clf_poly.fit(num.vander(X, degree), t)
        #print(clf_poly.coef_[0:len(clf_poly.coef_)-1])
        X_plot = num.linspace(0, 1, 500)
        y_plot = f(X_plot)
        y_mean, y_std = clf_poly.predict(num.vander(X_plot, degree), return_std=True)
        plot.figure(figsize=(6,5))
        plot.title('Bayesian Curve Fitting for polynomial of Degree = ' + str(degree-1) , color='black')
        plot.errorbar(X_plot, y_mean, y_std, color='red', label="Polynomial Bayesian Regression",  linewidth=lw)
        plot.plot(X_plot, y_plot, color='green', label="Sine Curve")
        plot.plot(X,t,'o')
        plot.ylabel("Output y")
        plot.xlabel("Feature X")
        plot.legend(loc="lower left")
        plot.subplots_adjust(hspace=2.0)
        plot.subplots_adjust(wspace=0.2)
        plot.show()

if __name__ == "__main__":
    k = int(input("Enter the Number k:"))
    l = int(input("Enter the Number L:"))
    t = []
    X = num.random.uniform(0, 1, size=k)
    X = num.array(X)
    f1 = f(X)
    f1 = num.array(f1)
    mu = 0
    sigma = 0.1
    
    for i in range(k):
        for j in range(l):
            t.append(num.random.normal(mu, sigma) + f1[i])
    
    X = num.repeat(X, l)
    t = num.array(t)
    lw=0.2
    baysian_curve()
 