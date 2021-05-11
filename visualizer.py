import matplotlib
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
# here is some shit code for visualising this shitfuckery

data = pd.read_json("out.json")

sns.scatterplot(data = data, x = 'x', y = 'y', hue = 'mark')
plt.show()