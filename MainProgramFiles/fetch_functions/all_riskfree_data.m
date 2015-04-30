function [rfmonth rfyear rfprice] = all_riskfree_data(filename)

	%[infmonth, infyear, infprice] = deal(cell(1,1));

	
	[rfmonth rfyear rfprice] = ...
					textread(filename, '%s %d %f','delimiter',',');

end