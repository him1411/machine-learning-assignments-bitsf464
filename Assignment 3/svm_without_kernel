import numpy as np 
import csv
from sklearn.svm import SVC
from sklearn import datasets, metrics, svm
from sklearn.metrics import (accuracy_score, average_precision_score,recall_score,classification_report)
from sklearn.model_selection import train_test_split
import pandas as pd


data=pd.read_csv('OnlineNewsPopularity.csv')
t = data.target
x = data.drop(['timedelta','url','shares','target'], axis=1)

#Training Data: 70% , Testing Data: 30%

train_data, test_data, t_train, t_test = train_test_split(x, t,test_size=0.3)

clf=SVC(kernel='linear', cache_size=10000 )
clf.fit(train_data, t_train)
t_predict=clf.predict(test_data) 
print(classification_report(t_test, t_predict))
print('Accuracy = ' +str(100*accuracy_score(t_test,t_predict))+"%")
