
function [BL_x,BL_var,BL_portfolio_returns,BL_portfolio_price]=...
	Black_Litterman(data,min_days,end_pred,initial_wealth,R_range,...
					BL_Er,BL_sigma,rac);

	%represents number of assets with available market_caps
	n_assets=size(data,2); 
	[BL_x, BL_var] = sMVO(n_assets, R_range , BL_Er, BL_sigma);
    %BL_x = inv(rac * BL_sigma) * BL_Er;
    %BL_var = [];
	% time horizon over which we are 'predicting'
	diff_days = min_days - end_pred; 

	% the vector of days in the time horizon
	pred_days = 1:diff_days;

	% calculate the actual returns of the portfolio and market over the
	% prediction region
	projection = data(end_pred:min_days, :)';
	projected_returns = projection(:, 2:end)./projection(:, 1:end-1) - 1; 
	BL_portfolio_returns = BL_x * projected_returns;

	BL_portfolio_price(1) = initial_wealth;

	%initial_wealth = W; Given by user

	for i = 1:size(BL_portfolio_returns,2);
	    BL_portfolio_price(i+1) = BL_portfolio_price(i)* ...
	    						  (1 + BL_portfolio_returns(i));
	end
end