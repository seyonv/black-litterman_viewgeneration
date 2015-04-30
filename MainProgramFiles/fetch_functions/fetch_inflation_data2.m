%NOTE FORMAT OF INPUT MONTH IS SUPPOSED TO 
function [inftimeprices beg_ind end_ind] = fetch_inflation_data2(smonth,syear,emonth,eyear,...
											infmonth,infyear,data)

	x=strmatch(smonth,infmonth);
	
	for i=1:length(x)	
		if infyear(x(i))==syear
			beg_ind=x(i);
		end
	end
	x=strmatch(emonth,infmonth);
	for i=1:length(x)	
		if infyear(x(i))==eyear
			end_ind=x(i);
		end
	end

	inftimeprices=flipud(data(beg_ind:end_ind));


end