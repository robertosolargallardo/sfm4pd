import simplejson as json
import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

if len(sys.argv) < 3:
   print "Not enough arguments!"
   print "python plot.py <settings-file-json> <input-dir>"
   sys.exit(0)

inputdir=sys.argv[2]

settings=json.load(open(sys.argv[1],"r"))

duration=int(settings["duration"])
xmin=float(settings["limits"]["bottom-left"]["lat"])
xmax=float(settings["limits"]["top-right"]["lat"])
ymin=float(settings["limits"]["bottom-left"]["lon"])
ymax=float(settings["limits"]["top-right"]["lon"])

fig,ax=plt.subplots()
xdata,ydata=[],[]
ln,=plt.plot([],[],'ro',animated=True)

def init():
	ax.set_xlim(xmin,xmax)
	ax.set_ylim(ymin,ymax)
	return ln,

def update(frame):
	data=[[float(x) for x in line.strip().split(",")] for line in open(inputdir+"/positions_"+repr(frame)+".txt",'r')]
	ln.set_data(*zip(*data))
	return ln,

ani=FuncAnimation(fig,update,duration,init_func=init,blit=True,interval=100)
plt.show()

