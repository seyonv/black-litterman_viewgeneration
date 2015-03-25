function [cap_weights,available_marketcaps]=capweights(market_cap, PE_ratios)

	%this represesnts number of assets that don't have market capatilization
	%data available on Yahoo finance
	unavailable_marketcaps=0; 
	
	sum_marketcaps=0;
	for i=1:length(market_cap)
		if(market_cap{i}=='NaN')|(PE_ratios{i}=='NaN')
			unavailable_marketcaps=unavailable_marketcaps+1;
		else
			sum_marketcaps=sum_marketcaps+market_cap{i};
		end
	end
	count=1;
	for i=1:length(market_cap)
		if(market_cap{i}~='NaN')&(PE_ratios{i}~='NaN')
			cap_weights(count)=market_cap{i}/sum_marketcaps;
			count=count+1;
		end
	end

	available_marketcaps=length(market_cap)-unavailable_marketcaps;
	



end