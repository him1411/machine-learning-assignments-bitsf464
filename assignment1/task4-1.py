import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
from sklearn.linear_model import BayesianRidge, LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
import warnings
from sklearn.linear_model import Ridge
 
k = int(input("Enter the Number k:"))
l = int(input("Enter the Number L:"))
t = []
count=0
 
 
def f(x):
    return np.sin(2 * np.pi * x)
 
 
X = np.random.uniform(0, 1, size=k)
X = np.array(X)
f1 = f(X)
f1 = np.array(f1)
mu = 0
sigma = 0.1
 
for i in range(k):
    for j in range(l):
        t.append(np.random.normal(mu, sigma) + f1[i])
 
X = np.repeat(X, l)
t = np.array(t)
 
 
lw=0.1
 
 
for degree in range(1,12):
    lambdas = np.arange(0, 0.006, 0.001)
    count=0
    plt.figure(figsize=(200,200))
    plt.suptitle('Bayesian Curve Fitting for polynomial of Degree = ' + str(degree - 1))
    for a in lambdas:
        clf_poly = BayesianRidge(compute_score=True)
        clf_poly.fit(np.vander(X, degree), t)
        #print(clf_poly.coef_[0:len(clf_poly.coef_)-1])
        X_plot = np.linspace(0, 1, 500)
        y_plot = f(X_plot)
        y_mean, y_std = clf_poly.predict(np.vander(X_plot, degree), return_std=True)
        ridge = make_pipeline(PolynomialFeatures(degree-1), Ridge(alpha=a, fit_intercept=False))
        ridge.fit(X[:, None], t)
        yp = ridge.predict(X_plot[:, None])
        ridge = make_pipeline(PolynomialFeatures(degree - 1), Ridge(alpha=0, fit_intercept=False))
        ridge.fit(X[:, None], t)
        y0 = ridge.predict(X_plot[:, None])
        warnings.simplefilter('ignore', np.RankWarning)
        count = count + 1
        plt.subplot(3, 2, count)
        plt.ylabel("Output y")
        plt.xlabel("Feature X")
        plt.errorbar(X_plot, y_mean, y_std, color='red', label="Polynomial Bayesian Regression", linewidth=lw, )
        plt.plot(X_plot, y_plot, color='green', label="Sine Curve")
        plt.plot(X, t, 'o')
        plt.plot(X_plot, yp, color='yellow', label="Lambda=" + str(a))
        plt.plot(X_plot, y0, color='grey', label="Lambda=0")
        plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=2, mode="expand", borderaxespad=0.)
        plt.subplots_adjust(hspace=0.8)
        plt.subplots_adjust(wspace=0.2)
 
    plt.show()