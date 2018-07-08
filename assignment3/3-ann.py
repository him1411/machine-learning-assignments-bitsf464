import numpy as np 
import csv
from sklearn.neural_network import MLPClassifier
from sklearn import datasets, metrics, svm
from sklearn.metrics import (accuracy_score, average_precision_score,recall_score,classification_report)
from sklearn.model_selection import train_test_split
import pandas as pd

# First we load the dataset using Pandas library using pandas.read_csv

data=pd.read_csv('OnlineNewsPopularity.csv')
t = data.target
x = data.drop(['timedelta','url','shares','target'], axis=1)

#Training Data: 70% , Testing Data: 30%

train_data, test_data, t_train, t_test = train_test_split(x, t,test_size=0.3)

#Using MLPClassifier(), we implemented Artificial Neural Network Model with a hidden layer

clf=MLPClassifier(hidden_layer_sizes=(200,), activation='tanh', solver='sgd' )
clf.fit(train_data, t_train)
t_predict=clf.predict(test_data) 

#classification_report() gives metric such as recall and precision

print(classification_report(t_test, t_predict))

#accuracy_score() gives accuracy metric

print('Accuracy = ' +str(100*accuracy_score(t_test,t_predict))+"%")
