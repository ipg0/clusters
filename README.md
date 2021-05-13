# clusters
A tool for finding point clusters in a 2D linear space.

<h2>I/O</h2>

clusters uses unified JSON format for input and output, but also contains an interactive point generator. It runs interactively in terminal and uses <a href=https://pandas.pydata.org/>Pandas</a> and <a href=https://seaborn.pydata.org/>Seaborn</a> to plot the results.
Input / output JSON files must be / are formatted as follows:

A list `[...]` of dictionaries `{...}`, each containing three values, namely: `"x"` and `"y"` of type `double` and `"clusterMark"` of type `int`.

Values of `"clusterMark"` don't matter when used as input, in output files this value corresponds to the index of the cluster each point belongs to.

<h3>Example:</h3>

```json
[{
  "x": 10,
  "y": 20,
  "clusterMark": 0
}, {
    ...
}, {
  ...
}]
```

<h2>Algorithms</h2>
clusters implements following search algorithms:
<h4>- FOREL (Formal Element)</h4>
<h4>- K Means</h4>
<h4>- Wave Search (the greatest connected component approach)</h4>

<h2>Building from source / Installation</h2>

clusters doesn't need any special libraries apart from Seaborn and Pandas:

```
sudo pip3 install pandas seaborn
```

clusters is built from source code using the following commands (bash):

```
git clone https://github.com/notblank00/clusters.git
cd clusters
cmake .
make
```
Due to complicated inter-language interactions between clusters and its visualizer, it does not support moving / linking / running it outside of its native directory, so to make clusters executable from anywhere you can create a shell script like the following:

<h4>file: clusters-global</h4>

```bash
#!/bin/bash
cd /original/path/to/clusters; ./clusters
```
Then make it executable:

```bash
chmod +x ./clusters-global
```

And now you can link this script into the binary folder:

```bash
sudo ln ./clusters-global /usr/bin/clusters
```

So now you can launch clusters from anywhere with just a `clusters` command.
