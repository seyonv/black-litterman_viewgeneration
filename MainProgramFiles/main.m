%Step 1: Retrieve and organize all data

% declare the symbol file, save all the csv data into MATLAB's variables
SymbolFile='''symb1.m''';
run(eval(SymbolFile));
[month day year price marketcap fail_symbols success_symbols]=...
						get_all_stock_data(symbols_csv,symbols);
% ----------------------------------------------------------------

lcase_month='Jan';
syear=2010;
eyear=2012;
ucase_month=upper(lcase_month);

% set the start and end dates fr
[tcurrprices currpricenames2 market_prices capprices num_assets2 catch_assets2 totalmonths] = ...
	SEC_fetch_stock_data...
        (lcase_month,eyear,lcase_month,syear,month,day,year,price,success_symbols);
smonth ='Jan'
SEC_fetch_stock_data(month, year, day )



% ----------------------------------------------------------------
% Black-litterman Function Calls

[BL_tau BL_P BL_Q] = generate_BL_views(n_assets)
        %Call function to return the Black-Litterman expected returns
        % from inverse optimization

[BL_Er, BL_sigma,BL_pi,BL_omega,rac]=...
BL_expected_returns(data, market, market_caps,...
					   BL_tau, BL_P, BL_Q, end_pred, PE_ratios);

%The lines below uses the expected returns computed by black-litterman and implement
%Mean-variance optimization equation by using BL_Er for expected returns

[BL_x,BL_var,BL_portfolio_returns,BL_portfolio_prices]=...
Black_Litterman(data,min_days,end_pred,initial_wealth,...
desired_return_range,BL_Er,BL_sigma,rac);
plot(1:length(BL_portfolio_returns),BL_portfolio_returns,'-k');
title('Comparing Returns of Optimal Portfolios created with MVO & Black-Litterman')
xlabel('Time (in Days)')
ylabel('Daily Return of Portfolio')
hold all