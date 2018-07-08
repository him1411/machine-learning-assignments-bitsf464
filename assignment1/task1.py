import numpy as num
import matplotlib.pyplot as plot
import warnings
warnings.simplefilter('ignore', num.RankWarning)

#

def f(x):
    return num.sin(2 * num.pi * x) #calculating the sine of function for training data

def implementation ():
    for i in range(11):
        color=['r-','b-','b-', 'r-', 'r-', 'c-', 'm-', 'y-', 'k-', 'b-','r-']
        Xp = num.linspace(0, 1, 2000)  #this is number of points in the generated polynomials 
        plot.ylabel('t -> traing data')
        plot.xlabel('x -> inumut features')
        plot.title('Least Square Polynomial of Degree = '+str(i),color='red') 
        plot.plot(Xp, f(Xp), color='green')
        plot.plot(X, t, 'o')
        z = num.polyfit( X,t, i)  # this will poly fit the model 
        print("Polynomial of degree "+str(i)+" is "+str(z)+"\n")
        plot.plot(Xp,num.polyval(z,Xp),str(color[i]))
        warnings.simplefilter('ignore', num.RankWarning)
        plot.show()


if __name__ == "__main__":
    k=int(input("Enter the Number of inumuts:"))    # enter the values of K
    l=int(input("Enter the Number of errors:"))     # enter the values of l
    t=[]
    X = num.random.uniform(0, 1, size=k)            #randomly generate K values between 0 and 1
    X=num.array(X)
    f1=f(X)
    f1=num.array(f1)  //calculate sinusoidal
    meu=0
    sigma=0.1
    for i in range(k):
        for j in range(l):
            t.append(num.random.normal(meu, sigma)+f1[i])    #this will add noise to previously generated sine function
    
    X=num.repeat(X,l) #copy L times 
    t=num.array(t)  
    implementation()
