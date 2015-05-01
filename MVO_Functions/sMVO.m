function [MVO_x MVO_var ] = sMVO(n_assets, return_range, mu, Q)
%% STANDARD MARKOWITZ MVO MODEL VIA QUADPROG
% Input the number of assets, the range of desired returns, the mean vector
% for the assets, and the covariance matrix. The function will return the 
% optimal portfolio weights in MVO_x, and the corresponding variance 
% function value in MVO_var.
%
% [optimal weights, corresponding optimal objective function] 
%   = sMVO(# of assets, range of desired returns, expected return vector, 
%           covariance matrix) 

% Set quadprog parameters
c = [zeros(n_assets,1);];
Aeq = [ones(1,n_assets);];
beq = [1;];
lb = [zeros(n_assets,1);];
ub = [];
R = return_range;

% Set quadprog options
options = optimset('Algorithm', 'active-set', 'TolFun', 1/10^8, 'MaxFunEvals', 100, 'MaxIter', 300);

A=[];
b=[];
%Solve MVO and store SD values for plotting

%Modify this so that it works for variable length R (length>1)
for i = 1:length(R);
    Aeq = [Aeq; mu];
    beq = [beq; R(i)];
    
    [MVO_x(i,:), MVO_var(i,1)] = quadprog(Q, c, A, b,Aeq, beq, lb, ub, [], options);
end

end

