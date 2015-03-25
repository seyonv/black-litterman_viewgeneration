%Step 1: Retrieve and organize all data

	% declare the symbol file, save all the csv data into MATLAB's variables
	clear
	clc
	SymbolFile='''symb1.m''';
	run(eval(SymbolFile));

	% Fetch ALL the stock data and store into matrices
	[Amonth Aday Ayear Aprice Avolume Amarketcap Afail_symbols Asuccess_symbols]=...
			get_all_stock_data(symbols_csv,symbols);
% ----------------------------------------------------------------

	% assuming using the same month for start and end month
	lcase_month='Jan';
	syear=2010;
	eyear=2012;
	ucase_month=upper(lcase_month);

	% set the start and end dates fr
	% return values for SEC_fetch_stock_data are the prices,names, volumes, marketcaps
	% number of successful assets, number of failed assets and # of total months
	% (all for the current iteration)
	[price pricenames volumes mmarketcaps success_assets fail_assets totalmonths] = ...
			SEC_fetch_stock_data(lcase_month,eyear,lcase_month,syear,...
							  Amonth,Aday,Ayear,Aprice,Avolume,Amarketcap,Asuccess_symbols);

	% Can call the specify cardinality function here
	firstlastran=0;
	cardinality=5; %The desired number of stocks to consider
	[Cmonth,Cday,Cyear,Cprice,Cvolume,Cmarketcap,Csuccess_symbols]=...
		specify_cardinality(firstlastran,cardinality,Amonth,Aday,Ayear,...
							Aprice,Avolume,Amarketcap,Asuccess_symbols);
	% Now the option is available to use fewer stocks and such`
% ----------------------------------------------------------------
% THIS SECTION SHOULD SEND THE MATLAB CODE TO PYTHON FOR MORE ANALYSIS
% AND APPLICATION OF REGRESSION TECHNIQUES

%---------------DEFINING ALL PATH VARIABLES USED IN PROGRAM -------------------
% --------------Saving MATLAB workspace & calling python script----------------
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

	% SAVE THE MATLAB WORKSPACE SO PYTHON SCRIPT CAN ACCESS
	writeto=W1_Mat2Py_path;
	save(writeto);


	%  CALL THE PYTHON SCRIPT
	py_call=horzcat('python ',first_Pypath);
	py_call
	system(py_call);

	% Load workspace variables created by python script
	% into MATLAB
	load(W1_Py2Mat_path);

	% Remove both workspaces as they're no longer needed
	rm_M2P_call=horzcat('rm ',W1_Mat2Py_path);
	rm_P2M_call=horzcat('rm ',W1_Py2Mat_path);
	system(rm_M2P_call);
	system(rm_P2M_call);

	%Retrieve the variables from the python workspace
	% save(workspace_path¡,'-v6');
	% save('myfile.mat','-v6')
% ----------------------------------------------------------------



% ----------------------------------------------------------------
% Black-litterman Function Calls
	n_assets=size(price,2) %this should be equal to success_assets
	% For now, the rest should remain as is BUT a large bulk fo the computation
	% should be done in the generate_BL_views function
	[BL_tau BL_P BL_Q] = generate_BL_views(n_assets)
	 
	[BL_Er, BL_sigma,BL_pi,BL_omega,rac]=...
	BL_expected_returns(price, market, market_caps,...
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
