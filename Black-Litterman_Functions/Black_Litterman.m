% This function takes the computed black-litterman variables
% and applies them to compute the resulting portfolio(BL_x are the weights)
function [BL_x,BL_var]=...
	Black_Litterman(data,R_range,BL_Er,BL_sigma,rac);

	%represents number of assets with available market_caps
	n_assets=size(data,2); 
	[BL_x, BL_var] = sMVO(n_assets, R_range , BL_Er, BL_sigma);
    %BL_x = inv(rac * BL_sigma) * BL_Er;
    %BL_var = [];
	% time horizon over which we are 'predicting'(# of time periods)
	diff_days = size(data,1);

	% the vector of days in the time horizon
	pred_days = 1:diff_days;

	% calculate the actual returns of the portfolio and market over the
	% prediction region

	% REMOVED THIS ENTIRE SECTION
	% projection = data(end_pred:min_days, :)';
	% projected_returns = projection(:, 2:end)./projection(:, 1:end-1) - 1; 
	% BL_portfolio_returns = BL_x * projected_returns;

	% set the initial wealth to be 1
	% initial_wealth=1;
	% BL_portfolio_price(1) = initial_wealth;

	%initial_wealth = W; Given by user

	% Don't need to know BL_portfolio price exactly
	% for i = 1:size(BL_portfolio_returns,2);
	%     BL_portfolio_price(i+1) = BL_portfolio_price(i)* ...
	%     						  (1 + BL_portfolio_returns(i));
	% end
end