%STEP 0: DEFINING ALL VARIABLES AND CONVENTIONS USED
	% prefix A implies it's all the data fetched from the csv files
	% convention is still A even if cardinality is limited
	% and a subset of stocks is selected

	% price, etc. are used to represent data for the period that is
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

	% FETCH ALL STOCK, MARKET, INFLATION AND RISKFREE DATA
		% Defining market so that it's the first element in all the cell matrices
		[Amonth Aday Ayear Aprice Avolume Amarketcap Afail_symbols Asuccess_symbols]=...
				get_all_stock_data(symbols_csv,symbols);

		[infmonth infyear infprice ] = all_inflation_data('inflation_rate_1200.csv');
	    [rfmonth rfyear rfprice] = all_riskfree_data('riskfreerate2.csv');
	% SPECIFY CARDINALITY (NUMBER OF STOCKS TO CONSIDER FOR ALLOCATION HERE)
		% limit_cardinality is 1 if you want to restrict the number of stocks
		limit_cardinality=1;
		if (limit_cardinality)
			firstlastran=0;
			cardinality=20; %The desired number of stocks to consider
			[Amonth,Aday,Ayear,Aprice,Avolume,Amarketcap,Asuccess_symbols]=...
			specify_cardinality(firstlastran,cardinality,Amonth,Aday,Ayear,...
								Aprice,Avolume,Amarketcap,Asuccess_symbols);	
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
				 Amonth,Aday,Ayear,Aprice,Avolume,Amarketcap,Asuccess_symbols);

	% NOW SELECT(SAME DATES), FROM THE INFLATION AND RISK FREE DATA
	[infvals] = fetch_inflation_data2...
	    (ucase_month,eyear,ucase_month,syear,infmonth,infyear,infprice);

	[riskfreevals] = fetch_riskfree_data2...
	    (ucase_month,eyear,ucase_month,syear,infmonth,infyear,rfprice);

	%DIVIDING THE DATA INTO BEFORE ALLOCAITON AND REBALANCING TIME PERIODS
		%Now select the total selected time period into the periods you want to use before
		%optimization (and consequently allocation begins ) and the period where the 
		%allocation of the portfolio is tracked(and rebalancing occurs)
		preopt_periods=30;
		% rebalnacing intervals
		num_rebal=4;
		% just as in capstone-matlab can call divide_data except the toal months parameter
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
	% Trying to call the python script firstpy.py
	% afterwards, try to pass parameters to the python console.

%------------STEP 4: doing intermediate calculations for values like moving average
%------------STEP 5: Starting computation for a particuar iteration. Arranging variables--------------
	% Use the beg_indices, end_indices to determine the particular index range
	% you're using for the current iteration. It will be some fac
	%Choosing hte subset of each quantiative data source we want to use for the iteration
	
	% this while loop ensures that values are being selected to represent
	% the specific iteration using the number of rebalncing periods as # of iterations
	while (balance_it<num_rebal)	


		prices2=cell2mat(prices);
		Cprices2=prices2(beg_indices(1):end_indices(1)+1,:);
		Cprices=num2cell(Cprices2,1)

		volumes2=cell2mat(volumes);
		Cvolumes2=volumes2(beg_indices(1):end_indices(1)+1,:);
		Cvolumes=num2cell(Cvolumes2,1)		
	
		marketcaps2=cell2mat(marketcaps);
		Cmarketcaps2=marketcaps2(beg_indices(1):end_indices(1)+1,:);
		Cmarketcaps=num2cell(Cmarketcaps2,1)

		d
		Cinfvals2=infvals(beg_indices(1):end_indices(1)+1,:);
		Cinfvals=num2cell(Cinfvals2,1)

		Criskfreevals2=riskfreevals(beg_indices(1):end_indices(1)+1,:);
		Criskfreevals=num2cell(Criskfreevals2,1)

		% The final values we care about when running the pyhton script 
		% are Cprices, Cvolumes, Cmarketcaps, Criskfree
	

%---SAVE THE MATLAB WORKSPACE,CALLING PYTHON, WHICH RETURNS WORKSPACE FOR MATLAB TO USE-
		writeto=W1_Mat2Py_path;
		save(writeto);


		%  CALL THE PYTHON SCRIPT
		py_call=horzcat('python ',first_Pypath);
		py_call
		system(py_call);

		% Load workspace variables created by python script
		% into MATLAB
		load(W1_Py2Mat_path);
		balance_it=balance_it+1;
	end
	% Remove both workspaces as they're no longer needed
	% rm_M2P_call=horzcat('rm ',W1_Mat2Py_path);
	% rm_P2M_call=horzcat('rm ',W1_Py2Mat_path);
	% system(rm_M2P_call);
	% system(rm_P2M_call);

	%Retrieve the variables from the python workspace
	% save(workspace_path¡,'-v6');
	% save('myfile.mat','-v6')
% ----------------------------------------------------------------



% ----------------------------------------------------------------
% Black-litterman Function Calls
	% undefined price variable defined here
	n_assets=size(prices,2) %this should be equal to success_assets
	% For now, the rest should remain as is BUT a large bulk fo the computation
	% should be done in the generate_BL_views function
	[BL_tau BL_P BL_Q] = generate_BL_views(n_assets)
	 
	[BL_Er, BL_sigma,BL_pi,BL_omega,rac]=...
	BL_expected_returns(prices, market, market_caps,...
						   BL_tau, BL_P, BL_Q, end_pred, PE_ratios);

	%The lines below uses the expected returns computed by black-litterman and implement
	%Mean-variance optimization equation by using BL_Er for expected returns

	[BL_x,BL_var,BL_portfolio_returns,BL_portfolio_prices]=...
	Black_Litterman(price,min_days,end_pred,initial_wealth,...
	desired_return_range,BL_Er,BL_sigma,rac);
	plot(1:length(BL_portfolio_returns),BL_portfolio_returns,'-k');
	title('Comparing Returns of Optimal Portfolios created with MVO & Black-Litterman')
	xlabel('Time (in Days)')
	ylabel('Daily Return of Portfolio')
	hold all
