function [cap_weights]=capweights(oldmarket_cap)

	%this represesnts number of assets that don't have market capatilization
	%data available on Yahoo finance
	unavailable_marketcaps=0; 
	
	sum_marketcaps=0;
	market_cap={}

	% Note the use of (1) as opposed to  size(oldmarket_cap{1},1)
	% means the oldest date is being used as opposed to the most recent date

	% size(oldmarket_cap) should return 23 x 17 (# of time periods by # of assets)
	for i=1:size(oldmarket_cap,2)
		market_cap{i}=oldmarket_cap(1,i);
		sum_marketcaps=sum_marketcaps+market_cap{i};
	end
	
	for i=1:length(market_cap)
		cap_weights(i)=market_cap{i}/sum_marketcaps;
		
	end

	
	



end