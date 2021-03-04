#!/usr/bin/env bash

echo ShortestPath
cd ShortestPath
make
./main &> benchmarks.csv

echo MaxFlow
cd ../MaxFlow
make
./main &> benchmarks.csv

echo Plots
cd ../Plots
python plot.py
