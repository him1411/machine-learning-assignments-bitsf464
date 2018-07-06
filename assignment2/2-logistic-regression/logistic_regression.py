import numpy as np 
import csv
from sklearn.linear_model import LogisticRegression
from sklearn import datasets, metrics, svm
from sklearn.metrics import (accuracy_score, average_precision_score,recall_score,classification_report)
from sklearn.model_selection import train_test_split
import pandas as pd


data=pd.read_csv('OnlineNewsPopularity.csv')
t = data.target
x = data.drop(['timedelta','url','shares','target'], axis=1)

#Training Data: 70% , Testing Data: 30%

train_data, test_data, t_train, t_test = train_test_split(x, t,test_size=0.3)

logistic = LogisticRegression() # Default L2 Regularization
logistic.fit(train_data, t_train)
t_predict = logistic.predict(test_data)
print(classification_report(t_test, t_predict))
print('Accuracy = ' +str(100*accuracy_score(t_test,t_predict))+"%")

"""Another way to get accuracy is through score = logistic.score(test_data, t_test)
print(score) """