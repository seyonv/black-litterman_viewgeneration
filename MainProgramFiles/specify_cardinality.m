% this function is used to specify the number of assets you want to create 
% in the black-litterman function
% It can either pick the first 
function [Cmonth,Cday,Cyear,Cprice,Cvolume,Cmarketcap,Csuccess_symbols]=...
    specify_cardinality(firstlastran,cardinality,Amonth,Aday,Ayear,Aprice,...
    					Avolume,Amarketcap,Asuccess_symbols)

    % this determines if one should use first n, last n or random n assets
    num_assets=size(Amonth,2);
    if (firstlastran==0)
    	beg_ind=1
	    end_ind=cardinality
    elseif (firstlastrand==1)
	    beg_ind=num_assets-cardinality
	    end_ind=num_assets
    elseif (firstlastrand==2)
    	error('have not yet implemented random selection for this choice')
    else
    	error('firstlastrand passed is invalid');
    end

    %Curly braces access the contents of a cell array while 
    % parentheses access the cell elements themselves
    Cmonth=Amonth(beg_ind:end_ind);
    Cday=Aday(beg_ind:end_ind);
    Cyear=Ayear(beg_ind:end_ind);
    Cprice=Aprice(beg_ind:end_ind);
    Cvolume=Avolume(beg_ind:end_ind);
    Cmarketcap=Amarketcap(beg_ind:end_ind);
    Csuccess_symbols=Asuccess_symbols(beg_ind:end_ind);


end