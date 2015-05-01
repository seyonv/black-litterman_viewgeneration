function [cap_weights,available_marketcaps]=capweights(oldmarket_cap)

	%this represesnts number of assets that don't have market capatilization
	%data available on Yahoo finance
	unavailable_marketcaps=0; 
	
	sum_marketcaps=0;
	market_cap={}

	% Note the use of (1) as opposed to  size(oldmarket_cap{1},1)
	% means the oldest date is being used as opposed to the most recent date

	for i=1:length(oldmarket_cap)
		market_cap{i}=oldmarket_cap{i}(1);
	end
	for i=1:length(market_cap)
		sum_marketcaps=sum_marketcaps+market_cap{i};
	end
	count=1;
	for i=1:length(market_cap)
		cap_weights(i)=market_cap{i}/sum_marketcaps;
		
	end

	available_marketcaps=length(market_cap);
	



end