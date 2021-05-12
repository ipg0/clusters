from matplotlib.pyplot import show
from seaborn import scatterplot
from pandas import read_json
# here is some shit code for visualising this shitfuckery

data = read_json("out.json")

scatterplot(data = data, x = 'x', y = 'y', hue = 'clusterMark')
show()