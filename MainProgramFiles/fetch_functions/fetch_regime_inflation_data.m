%returns inflation data used to compute the RS model. It may be either
%monthly, quarterly or annually depending on the filename passed
function [inf_data inf_data_avg] =  ...
		fetch_regime_inflation_data(s_year,e_year,s_month,e_month,filename)

	s_year=s_year-1914;
	e_year=e_year-1914;
	inf_data=csvread(filename,s_year,s_month,[s_year,s_month,e_year,e_month]);

	inf_data=inf_data';
	inf_data=inf_data(:);

	%inf_data_avg=csvread(filename,s_year,13,[s_year,13,e_year,13]);
	inf_data_avg=csvread...
	(filename,s_year,e_month+1,[s_year,e_month+1,e_year,e_month+1]);

	
end