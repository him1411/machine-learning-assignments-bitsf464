import numpy as np
import matplotlib.pyplot as plt
import math
from sklearn.linear_model import Ridge, RidgeCV
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
from sklearn.metrics import mean_squared_error
 
 
def f(x):
    return np.sin(2*x*math.pi)
 
 
fig = plt.figure()
 
x_train = np.array([ 0.03034727, 0.28123209 , 0.31573504 ,  0.45735108 ,  0.49361877,  0.52177581,  0.6201289,      0.72702858,
  0.74153876,  0.80955098,    0.86233346,  0.89754947,  0.94420532,0.99390639])
y_train = np.array([ 0.1260739,   0.90381741, 1.16475499,  0.32339779,  0.30614242, -0.20750192, -0.50380714,  -1.09301944,
 -1.17165272, -0.89129801,  -0.85572252, -0.7736467,  -0.21234812,-0.12717219])
 
x_test = np.array([0.31273956 , 0.46122891, 0.4917774, 0.7039386, 0.84386983, 0.97020886])
 
y_test = np.array([0.909136, 0.38747724, -0.92084687, -1-0.03804487,.03453301,-0.1177253])
 
# create matrix versions of these arrays
X_train = x_train[:, np.newaxis]
X_test = x_test[:, np.newaxis]
 
colors = ['teal', 'yellow','green', 'gold']
lw = 2
 
train_error = []
test_error = []
alphas = [1e-05, 0.05, 0.05, 0.0018389532461, 0.00650090924244, 0.0302731352613, 1e-05,
            0.000109988332361, 0.00046411367614, 0.00112653637803, 0.00226390365864]
for degree in range(11):
    for count, degree in enumerate([degree]):
        fig.clf()
        model = make_pipeline(PolynomialFeatures(degree), Ridge(alpha = alphas[degree]))
        model.fit(X_train, y_train)
        train_error.append(mean_squared_error(y_train, model.predict(X_train)))
        test_error.append(mean_squared_error(y_test, model.predict(X_test)))
plt.plot(np.arange(11), train_error, color='green', label='train')
plt.plot(np.arange(11), test_error, color='red', label='test')
plt.ylim((0.0, 1e0))
plt.ylabel('Mean Squared Error)')
plt.xlabel('Degree')
plt.legend(loc='lower left')
fig.savefig('Testing_Answer4_2.png', bbox_inches='tight')