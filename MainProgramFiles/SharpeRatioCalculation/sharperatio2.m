%Takes in the asset prices for the desired periods
function [sratio mu_p sigma_p] = ...
	sharperatio2(asset_mu, asset_cov, xalloc, riskfreeprice)

	
	mu_p=asset_mu*xalloc';
	sigma_p=(xalloc*asset_cov*xalloc')^0.5;

	sratio=(mu_p-riskfreeprice)/sigma_p;

end

% [P_SRATIOS(:,1) S_SRATIOS(:,1)]=calculateSharpeRatio(asset_mu, asset_Q, ...
%             modelMVO_x, benchMVO_x,modelMVO_var,currriskfreeprices);