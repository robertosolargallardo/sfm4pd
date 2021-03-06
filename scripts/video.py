import simplejson as json
import sys
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import matplotlib.image as mpimg
import matplotlib.animation as animation

if len(sys.argv) < 4:
   print "Not enough arguments!"
   print "python plot.py <settings-file-json> <map-file-png> <input-dir>"
   sys.exit(0)

Writer = animation.writers['ffmpeg']
writer = Writer(fps=15, metadata=dict(artist='Me'), bitrate=1800)

inputdir=sys.argv[3]

settings=json.load(open(sys.argv[1],"r"))

duration=int(settings["duration"])
xmin=float(settings["limits"]["bottom-left"]["lat"])
xmax=float(settings["limits"]["top-right"]["lat"])
ymin=float(settings["limits"]["bottom-left"]["lon"])
ymax=float(settings["limits"]["top-right"]["lon"])

reference_points=[]
for rp in settings["reference-points"]:
	reference_points.append([float(rp["lat"]),float(rp["lon"])])

img=plt.imread(sys.argv[2])
fig,ax=plt.subplots()
plt.plot(*zip(*reference_points),linestyle="",marker="o",markersize=10,color="green")
ln,=plt.plot([],[],'ro',animated=True,markersize=2.5,color="black");

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
#ani.save('output_valpo.mp4', writer=writer)
plt.show()
