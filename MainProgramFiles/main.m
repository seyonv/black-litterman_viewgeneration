%STEP 0: DEFINING ALL VARIABLES AND CONVENTIONS USED
	% prefix A implies it's all the data fetched from the csv files
	% convention is still A even if cardinality is limited
	% and a subset of stocks is selected. Therefore, this is the 
	% meaning of the prefix A NOT being present

	% prices, etc. are used to represent data for the entire period that is
	% being tested over(so it comprise a multitude of iteration periods)
	% plural notation is always used for multi-dimensional variables
	% lcase_month,ucase_month used to represent month for stock/(inflation/riskfree
	% data respsectivley

	% Cprices, Cvolumes repreesent a specific time period being iterated over
%Step 1: Retrieve and organize all data


	% declare the symbol file, save all the csv data into MATLAB's variables
	clear
	clc
	SymbolFile='''symb1.m''';
	run(eval(SymbolFile));

	% FETCH ALL STOCK, MARKET, INFLATION AND RISKFREE DATA2
		% Defining market so that it's the first element in all the cell matrices
		[Amonth Aday Ayear Aprice Avolume Amarketcap Afail_symbol Asuccess_symbol]=...
				get_all_stock_data(symbols_csv,symbols);

		[infmonth infyear infprice ] = all_inflation_data('inflation_rate_1200.csv');
	    [rfmonth rfyear rfprice] = all_riskfree_data('riskfreerate2.csv');
	% SPECIFY CARDINALITY (NUMBER OF STOCKS TO CONSIDER FOR ALLOCATION HERE)
		% limit_cardinality is 1 if you want to restrict the number of stocks
		limit_cardinality=1;
		if (limit_cardinality)
			firstlastran=0;
			cardinality=20; %The desired number of stocks to consider
			[Amonth,Aday,Ayear,Aprice,Avolume,Amarketcap,Asuccess_symbol]=...
			specify_cardinality(firstlastran,cardinality,Amonth,Aday,Ayear,...
								Aprice,Avolume,Amarketcap,Asuccess_symbol);	
		end
		

% ----------------------------------------------------------------
% Step 2: Define the subset of time you want to get data for
	% assuming using the same month for start and end month

	% Note that first available date is Jan 2, 2002 
	% 			last available date is Jan 2, 2015
	lcase_month='Jan';
	syear=2002;
	eyear=2010;
	ucase_month=upper(lcase_month);

	% set the start and end dates fr
	% return values for SEC_fetch_stock_data are the prices,names, volumes, marketcaps
	% number of successful assets, number of failed assets and # of total months
	% (all for the current iteration)
	[prices pricenames volumes marketcaps success_assets fail_assets totalmonths] = ...
			SEC_fetch_stock_data(lcase_month,eyear,lcase_month,syear,...
				 Amonth,Aday,Ayear,Aprice,Avolume,Amarketcap,Asuccess_symbol);

	% NOW SELECT(SAME DATES), FROM THE INFLATION AND RISK FREE DATA
	[infvals] = fetch_inflation_data2...
	    (ucase_month,eyear,ucase_month,syear,infmonth,infyear,infprice);

	[riskfreevals] = fetch_riskfree_data2...
	    (ucase_month,eyear,ucase_month,syear,infmonth,infyear,rfprice);

	%DIVIDING THE DATA INTO (1) BEFORE ALLOCATION** AND (2) REBALANCING TIME PERIODS
		%Now select the total selected time period into the periods you want to use before
		%optimization (and consequently allocation begins ) and the period where the 
		%allocation of the portfolio is tracked(and rebalancing occurs)
		preopt_periods=30;
		% rebalancing intervals
		num_rebal=3;
		% just as in capstone-matlab can call divide_data except the total months parameter
		% being passed in is reduced by the preopt_periods (pass in totalmonths-preopt_periods)
		% and add preopt_periods when referencing the period you want
		[beg_indices end_indices indice_size]=...
			divide_data(preopt_periods,num_rebal,totalmonths);
		balance_it=0; %define the current balancing period that you're on

%---STEP 3: DEFINING ALL PATH VARIABLES USED IN PROGRAM, saving MAT workspace & calling python--
	thesis_path=['/Users/User/Desktop/Thesis-Final'];
	main_path=strcat(thesis_path,'/MainProgramFiles');
	py_analysis_path=strcat(main_path,'/python_analysis');
	Mat2Py_path=strcat(py_analysis_path,'/Mat2Py_Files');
	Py2Mat_path=strcat(py_analysis_path,'/Py2Mat_Files');
	% prefix W stands for a defined workspace and its corresponding #
	W1_Mat2Py_path=strcat(Mat2Py_path,'/M2Pworkspace1.mat');
	W1_Py2Mat_path=strcat(Py2Mat_path,'/P2Mworkspace1.mat');
	
	% python script execution path
	first_Pypath=strcat(py_analysis_path,'/firstpy.py');


%---STEP 4: doing intermediate calculations for values like moving average
%---STEP 5: Starting computation for a particuar iteration. Arranging variables--------------
	% Use the beg_indices, end_indices to determine the particular index range
	% you're using for the current iteration. It will be some fac
	%Choosing hte subset of each quantiative data source we want to use for the iteration
	
	% this while loop ensures that values are being selected to represent
	% the specific iteration using the number of rebalncing periods as # of iterations
	% while (balance_it<num_rebal)	
		prices2=cell2mat(prices);
		Cprices=prices2(beg_indices(1):end_indices(1)+1,:);
		pyCprices=num2cell(Cprices,1)

		volumes2=cell2mat(volumes);
		Cvolumes=volumes2(beg_indices(1):end_indices(1)+1,:);
		pyCvolumes=num2cell(Cvolumes,1)		
	
		marketcaps2=cell2mat(marketcaps);
		Cmarketcaps=marketcaps2(beg_indices(1):end_indices(1)+1,:);
		pyCmarketcaps=num2cell(Cmarketcaps,1)

		Cinfvals=infvals(beg_indices(1):end_indices(1)+1,:);
		pyCinfvals=num2cell(Cinfvals,1)

		Criskfreevals=riskfreevals(beg_indices(1):end_indices(1)+1,:);
		pyCriskfreevals=num2cell(Criskfreevals,1)

		% Now try and modify the prices to accomodate for rolling averages
		% create Python variables for 10-day, 50-day rolling averages as well
		% RETURNS and the covariance matrix so there is no need to convert it in python


		% The final values we care about when running the python script 
		% are Cprices, Cvolumes, Cmarketcaps, Criskfree


%---STEP 6: SAVE THE MATLAB WORKSPACE,CALLING PYTHON, WHICH RETURNS WORKSPACE FOR MATLAB TO USE-
		writeto=W1_Mat2Py_path;
		save(writeto);


		%  CALL THE PYTHON SCRIPT
		py_call=horzcat('python ',first_Pypath);
		py_call
		system(py_call);

		% Load workspace variables created by python script
		% into MATLAB
		load(W1_Py2Mat_path);
		% this is the loop variable used to count if the total number of 
		% rebalancing periods has been completed yet
		balance_it=balance_it+1;
	% end
	% Remove both workspaces as they're no longer needed
	% rm_M2P_call=horzcat('rm ',W1_Mat2Py_path);
	% rm_P2M_call=horzcat('rm ',W1_Py2Mat_path);
	% system(rm_M2P_call);
	% system(rm_P2M_call);

	%Retrieve the variables from the python workspace
	% save(workspace_path¡,'-v6');
	% save('myfile.mat','-v6')


%---STEP 7: BLACK-LITTERMAN COMPUTATION STARTS HERE(function calls defined below)--------
	% undefined price variable defined here
	n_assets=size(prices,2)-1
	 %this should be equal to success_assets (minus 1 for market)
	% For now, the rest should remain as is BUT a large bulk fo the computation
	% should be done in the generate_BL_views function
	[BL_tau BL_P BL_Q] = generate_BL_views(n_assets)



		
	
	% Recall that we can treat the computation of BL_expected returns is a 
	% specific subset of the rpices used over the entire time period
	% as we are optimizing over multime indepenednet time frames
	% Therefore, the line belows uses Cprices to attain a specific time 
	% period as well as convert it to ensure that it is a matrix not a cell array
	% asset_prices=cell2mat(prices);

	%Parameters are first number of time divisions, then total months

	% Cprices=asset_prices(beg_indices(1):end_indices(1)+1,:);

	% Modify the function below so that you are using prices instead of market
	% as convention is that market data is the first element of every matrix
	% BL_expected_returns(prices, market, market_caps,...
	% 					   BL_tau, BL_P, BL_Q, end_pred, PE_ratios);
	
	[BL_Er, BL_sigma,BL_pi,BL_omega,rac]=...
		BL_expected_returns(Cprices(:,2:end),Cprices(:,1),Cmarketcaps(:,2:end),...
							BL_tau,BL_P,BL_Q);

	%The lines below uses the expected returns computed by black-litterman and implement
	%Mean-variance optimization equation by using BL_Er for expected returns

	% Set the desired_return parameter to the constraint for MVO
	desired_return=0.007
	[BL_x,BL_var]=...
		Black_Litterman(Cprices(:,2:end),desired_return,BL_Er,BL_sigma,rac);

	
	% Now plot how the Black-Litterman Allocation does over time in comparison to 
	% plot(1:length(BL_portfolio_returns),BL_portfolio_returns,'-k');
	% title('Comparing Returns of Optimal Portfolios created with MVO & Black-Litterman')
	% xlabel('Time (in Days)')
	% ylabel('Daily Return of Portfolio')
	% hold all
