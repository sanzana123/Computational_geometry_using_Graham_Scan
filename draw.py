import matplotlib.pyplot as pp
import numpy as np

data = np.loadtext(fname = 'convext.txt', delimiter= ' ')
print(data)

X=[]
Y=[]

for i in range(len(data)):
    for j in range(2):
        if j==0:
            X.append(data[i][j])
        else:
            Y.append(data[i][j])

print(X)
print(Y)

pp.plot(X, Y, label='T(N)')
pp.xlabel('SIZEN')
pp.ylabel('Operations Count')
pp.title('Grahams Scan')
pp.legend()
pp.show()