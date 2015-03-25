% This function takes in the total months and total intervals
% and returns matrices of equally spaced interval(except the last one
% may be slightly longer in the case of numintervals not being a factor
% of total months.
function [beg_ind end_ind] = divide_date(numintervals,totalmonths)

	beg_ind=[];
	end_ind=[];
	indice_size=floor(totalmonths/numintervals);
	
	for i=1:numintervals-1
		beg_ind=[beg_ind; indice_size*(i-1)+1];
		end_ind=[end_ind; indice_size*i];
	end
	%if mod(totalmonths,numintervals)>0
	
		beg_ind=[beg_ind; (indice_size*(numintervals-1)+1)];
		end_ind=[end_ind; (indice_size*numintervals+mod(totalmonths,numintervals))];
	% end

		
end