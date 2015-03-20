% This function computes the sharpe ratio and modified sharpe ratio computed
% for each portfolio
function[P_SRATIOS S_SRATIOS] = ...
		calculateSharpeRatio(asset_mu, asset_Q, temp_Q, modelMVO_x, benchMVO_x, ...
							 modelMVO_var, currriskfreeprices)

	%Using our model version of the Sharpe ratio, Preface M

	[P_premodel_sratios] = ...
		(asset_mu*modelMVO_x'-currriskfreeprices(end)/100)/(modelMVO_var^0.5);

	[P_preMVO_sratios P_preMVO_smu P_preMVO_s_sigmap]=...
	    sharperatio2(asset_mu,temp_Q,benchMVO_x,currriskfreeprices(end)/100);

	%--------------------------------------------------------------------------------------
	%Using regular version of the Sharpe ratio, Preface S
	[S_premodel_sratios S_premodel_smu S_premodel_s_sigmap]=...
	    sharperatio2(asset_mu,asset_Q,modelMVO_x,currriskfreeprices(end)/100);

	[S_preMVO_sratios S_preMVO_smu S_postMVO_sigmap]=...
	    sharperatio2(asset_mu,asset_Q,benchMVO_x,currriskfreeprices(end)/100);

	P_SRATIOS = [P_premodel_sratios; P_preMVO_sratios];
	S_SRATIOS = [S_premodel_sratios; S_preMVO_sratios];
end

% [P_SRATIOS(:,1) S_SRATIOS(:,1)]=calculateSharpeRatio(asset_mu, asset_Q, temp_Q, ...
%     modelMVO_x(1,:), benchMVO_x(1,:),modelMVO_var,currriskfreeprices);