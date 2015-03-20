function [er, ps, w, pw, lambda, theta] = hlblacklitterman(delta, weq, sigma, tau, P, Q, Omega)%#codegen
% hlblacklitterman
%   This function performs the Black-Litterman blending of the prior
%   and the views into a new posterior estimate of the returns as
%   described in the paper by He and Litterman.
% Inputs
%   delta  - Risk tolerance from the equilibrium portfolio
%   weq    - Weights of the assets in the equilibrium portfolio
%   sigma  - Prior covariance matrix
%   tau    - Coefficiet of uncertainty in the prior estimate of the mean (pi)
%   P      - Pick matrix for the view(s)
%   Q      - Vector of view returns
%   Omega  - Matrix of variance of the views (diagonal)
% Outputs
%   Er     - Posterior estimate of the mean returns
%   w      - Unconstrained weights computed given the Posterior estimates
%            of the mean and covariance of returns.
%   lambda - A measure of the impact of each view on the posterior estimates.
%   theta  - A measure of the share of the prior and sample information in the
%            posterior precision.

% Reverse optimize and back out the equilibrium returns
% This is formula (12) page 6.
pi = weq * sigma * delta;
% We use tau * sigma many places so just compute it once
ts = tau * sigma;
% Compute posterior estimate of the mean
% This is a simplified version of formula (8) on page 4.
er = pi' + ts * P' * inv(P * ts * P' + Omega) * (Q - P * pi');
% We can also do it the long way to illustrate that d1 + d2 = I
d = inv(inv(ts) + P' * inv(Omega) * P);
d1 = d * inv(ts);
d2 = d * P' * inv(Omega) * P;
er2 = d1 * pi' + d2 * pinv(P) * Q;
% Compute posterior estimate of the uncertainty in the mean
% This is a simplified and combined version of formulas (9) and (15)
ps = ts - ts * P' * inv(P * ts * P' + Omega) * P * ts;
posteriorSigma = sigma + ps;
% Compute the share of the posterior precision from prior and views,
% then for each individual view so we can compare it with lambda
theta=zeros(1,2+size(P,1));
theta(1,1) = (trace(inv(ts) * ps) / size(ts,1));
theta(1,2) = (trace(P'*inv(Omega)*P* ps) / size(ts,1));
for i=1:size(P,1)
    theta(1,2+i) = (trace(P(i,:)'*inv(Omega(i,i))*P(i,:)* ps) / size(ts,1));
end
% Compute posterior weights based solely on changed covariance
w = (er' * inv(delta * posteriorSigma))';
% Compute posterior weights based on uncertainty in mean and covariance
pw = (pi * inv(delta * posteriorSigma))';
% Compute lambda value
% We solve for lambda from formula (17) page 7, rather than formula (18)
% just because it is less to type, and we've already computed w*.
lambda = pinv(P)' * (w'*(1+tau) - weq)';
end

% Black-Litterman example code for MatLab (hlblacklitterman.m)
% Copyright (c) Jay Walters, blacklitterman.org, 2008.
%
% Redistribution and use in source and binary forms, 
% with or without modification, are permitted provided 
% that the following conditions are met:
%
% Redistributions of source code must retain the above 
% copyright notice, this list of conditions and the following 
% disclaimer.
% 
% Redistributions in binary form must reproduce the above 
% copyright notice, this list of conditions and the following 
% disclaimer in the documentation and/or other materials 
% provided with the distribution.
%  
% Neither the name of blacklitterman.org nor the names of its
% contributors may be used to endorse or promote products 
% derived from this software without specific prior written
% permission.
%  
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
% CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
% INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
% MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
% DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
% CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
% SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
% WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
% NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH 
% DAMAGE.
%
% This program uses the examples from the paper "The Intuition 
% Behind Black-Litterman Model  Portfolios", by He and Litterman,
% 1999.  You can find a copy of this  paper at the following url.
%     http:%papers.ssrn.com/sol3/papers.cfm?abstract_id=334304
%
% For more details on the Black-Litterman model you can also view
% "The BlackLitterman Model: A Detailed Exploration", by this author
% at the following url.
%     http:%www.blacklitterman.org/Black-Litterman.pdf
%