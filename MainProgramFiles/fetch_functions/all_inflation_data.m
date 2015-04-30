% This function returns the inflation rates used to compute inflation betas

function [infmonth infyear infprice] = all_inflation_data(filename)
	
	[infmonth infyear infprice] = textread(filename, '%s %d %f','delimiter',',');

end