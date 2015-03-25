#!/bin/bash
cd ~
matlab -nodesktop
cd /Users/User/Desktop/Thesis-Final/MainProgramFiles
addpath(genpath('/Users/User/Desktop/Thesis-Final'))
run main.m
cd python_analysis
python Mat_to_Py.py
cd MPF
# cd Python_analysis