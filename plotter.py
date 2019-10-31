import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import seaborn as sns

df = pd.read_csv("values.dat", names=['x','y1','y2','y3'])

plt.plot(df.x, df.y1, label='y(x)')
plt.plot(df.x, df.y2, label="y '(x)")
plt.plot(df.x, df.y3, label="y ''(x)")
plt.legend()
plt.grid()
plt.savefig("graph.png")
plt.close()

plt.plot(df.x, df.y1,'r')
plt.xlabel("x")
plt.ylabel("f(x)")
plt.grid()
# plt.show()
plt.savefig("graph_1.png")
plt.close()
plt.plot(df.x, df.y2,'b')
plt.xlabel("x")
plt.ylabel("f '(x)")
plt.grid()
# plt.show()
plt.savefig("graph_2.png")
plt.close()
plt.plot(df.x, df.y3,'g')
plt.xlabel("x")
plt.ylabel("f ''(x)")
plt.grid()
# plt.show()
plt.savefig("graph_3.png")
