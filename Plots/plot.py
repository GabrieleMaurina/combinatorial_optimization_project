import pandas as pd
import matplotlib.pyplot as plt

SP = pd.read_csv('../ShortestPath/benchmarks.csv')
for i in range(0,24,4):
	data = SP.iloc[i:i+4]
	data.plot(\
		x='|E|',\
		y=['dijkstra','bellman_ford','moore'],\
		ylabel='time(ms)',\
		title=f'Time(ms) vs |E|: density={SP.iloc[i]["density"]}, delta={int(SP.iloc[i]["delta"])}',\
		alpha=0.8,
		linewidth=5)
print(SP)

MF = pd.read_csv('../MaxFlow/benchmarks.csv')
for i in range(0,24,4):
	data = MF.iloc[i:i+4]
	data.plot(\
		x='|E|',\
		y=['bfs','bfs_bi','dijkstra','dijkstra_bi'],\
		ylabel='time(ms)',\
		title=f'Time(ms) vs |E|: density={SP.iloc[i]["density"]}, delta={int(SP.iloc[i]["delta"])}',\
		alpha=0.8,
		linewidth=5)
print(MF)

for i in plt.get_fignums():
    plt.figure(i)
    plt.savefig(f'fig{i}.pdf')
