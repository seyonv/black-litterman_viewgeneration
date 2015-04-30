% This function returns the apprtopriate inflation fil
% for monthly, quarterly or annual data

function [inf_file endcol] = return_inflation_file(inflation_interval)
	if (strcmp(inflation_interval,'monthly'))
		inf_file='inflation_data_monthly.csv';
		endcol=12;
	elseif (strcmp(inflation_interval,'quarterly'))
		inf_file='inflation_data_quarterly.csv';
		endcol=4;
	elseif (strcmp(inflation_interval,'annually'))
		inf_file='inflation_data_annual.csv';
		endcol=1;
	end
end