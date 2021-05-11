import seaborn
import matplotlib
import pandas

# here is some shit code for visualising this shitfuckery

data = open("out.json").read()

data = pandas.read_json(data)

seaborn.scatterplot(data = data, x = 'x', y = 'y', hue = 'mark')
matplotlib.pyplot.show()