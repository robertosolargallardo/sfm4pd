import simplejson as json
import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import matplotlib.image as mpimg
import matplotlib.animation as animation

if len(sys.argv) < 3:
   print "Not enough arguments!"
   print "python plot.py <settings-file-json> <input-dir>"
   sys.exit(0)

Writer = animation.writers['ffmpeg']
writer = Writer(fps=15, metadata=dict(artist='Me'), bitrate=1800)

inputdir=sys.argv[2]

settings=json.load(open(sys.argv[1],"r"))

duration=int(settings["duration"])
xmin=float(settings["limits"]["bottom-left"]["lat"])
xmax=float(settings["limits"]["top-right"]["lat"])
ymin=float(settings["limits"]["bottom-left"]["lon"])
ymax=float(settings["limits"]["top-right"]["lon"])

img=plt.imread("/home/rsolar/PositionGeo/make_video/test.png")
fig,ax=plt.subplots()
ln,=plt.plot([],[],'ro',animated=True)

def init():
	ax.set_xlim(xmin,xmax)
	ax.set_ylim(ymin,ymax)
	ax.set_xticks([])
	ax.set_yticks([])
	ax.imshow(img,zorder=0,extent=[xmin,xmax,ymin,ymax])
	return ln,

def update(frame):
	data=[[float(x) for x in line.strip().split(",")] for line in open(inputdir+"/positions_"+repr(frame)+".txt",'r')]
	ln.set_data(*zip(*data))
	return ln,

ani=FuncAnimation(fig,update,duration,init_func=init,blit=True,interval=100)
ani.save('output.mp4', writer=writer)
#plt.show()
