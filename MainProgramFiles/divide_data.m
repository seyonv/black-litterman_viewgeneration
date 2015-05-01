% This function takes in the total number of intervals
% ,number of periods to use before optimization (preoptp)
% ,the number of rebalancing periods



% function returns matrices of equally spaced interval(except the last one
% may be slightly longer in the case of num_rebal not being a factor
% of total months.
function [beg_ind end_ind indice_size] =...
	  divide_data(preopt_periods,num_rebal,totalmonths)

	totalmonths=totalmonths-preopt_periods;
	beg_ind=[];
	end_ind=[];
	indice_size=floor(totalmonths/num_rebal);
	
	for i=1:num_rebal-1
		beg_ind=[beg_ind; indice_size*(i-1)+1];
		end_ind=[end_ind; indice_size*i];
	end
	%if mod(totalmonths,num_rebal)>0
	% this portion covesr the last portion to ensure that all remaining time 
	% periods are stored from interval beg_ind(end) - end_ind(end)
		beg_ind=[beg_ind; (indice_size*(num_rebal-1)+1)];
		end_ind=[end_ind; (indice_size*num_rebal+mod(totalmonths,num_rebal))];
	% end
		beg_ind=beg_ind+preopt_periods
		end_ind=end_ind+preopt_periods
		
end