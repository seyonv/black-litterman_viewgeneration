if isempty(currentFigures), currentFigures = []; end;
close(setdiff(findall(0, 'type', 'figure'), currentFigures))
clear mex
delete *.mexmaci64
[~,~,~] = rmdir('/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/codegen','s');
delete /Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/hlblacklitterman.m
delete /Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/testMex.m
clear all
load old_workspace
delete old_workspace.mat
delete /Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization/cleanup.m
cd /Users/User/Desktop/Thesis-Final
rmdir('/Users/User/Desktop/Thesis-Final/coderdemo_portfolio_optimization','s');
