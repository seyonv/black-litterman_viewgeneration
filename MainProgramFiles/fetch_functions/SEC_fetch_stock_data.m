%INPUT PARAMETERS
% month, day, year, price represent all the time series data
% succes_symbols represents the assets that succesfully
% FOR NOW ASSUME ROW 3000 IS THE SAME DATE FOR EVERY ASSET
% pass 

% SEC_Fetch_Stock_data returns the stock prices, market capitalizations
% the symbols
function [prices price_names2 volumes marketcaps num_assets catch_assets interval_size] = ...
	 	 SEC_fetch_stock_data...
	 	 (smonth,syear,emonth,eyear,...
	 	   month,day,year,price,volume,marketcap,success_symbols)


%------CODE TO FIND THE STARTING AND ENDING INDICES -----------
% ultimately returns beg_ind and end_ind
	x=strmatch(smonth,month{1});
	for i =1:length(x)
		if year{1}(x(i))==syear
			beg_ind=x(i);
		end
	end
	
	x=strmatch(emonth,month{1});
	% disp(emonth);
	% disp(month{1});
	% disp(x);
	% disp(eyear);
	% disp(year);
	disp(eyear);
	for i =1:length(x)
		disp(year{1}(x(i)));
		if year{1}(x(i))==eyear
			end_ind=x(i);
		end
	end
	interval_size=end_ind-beg_ind;
%-------------AFTER FINDING THE INDICES ITERATE THROUGH ASSETS TO GET PRICE DATA ----
	count=1;
	catch_assets=1; %why does catch_assets start at 1 and not at 0

		
	% this iterates over all but the ending, and assumes that the final one is 
	% the market index
	for i = 1:(length(success_symbols)-1)
		%symb_matrix{i}=SP500_symb_csv{i};
		try
			% disp('entered try block')
			prices{count}=flipud(price{i}(beg_ind:end_ind));
			volumes{count}=flipud(volume{i}(beg_ind:end_ind));
			marketcaps{count}=flipud(marketcap{i}(beg_ind:end_ind));
			price_names{count}=success_symbols(i);	
			count=count+1;	
			%disp(SP500_symb_csv(i))
		catch 
			catch_assets=catch_assets+1;
		end
	end
	num_assets=count-1; % add 1 for the market index
	
	% THIS SECTION IS CURRENTLY REMOVED-Market index specific iterations
		% as market information is being extracted from the fin
		% to add, insert a -1 to the above for loop and uncomment
		%retrieve time series price information for the marketprice
		% try
		% 	% marketprice=data{end}(beg_ind:end_ind);
		% 	marketprice2=marketcap{end}(beg_ind:end_ind);
		% 	marketname=success_symbols(end);
		% catch
		% end
		
		% marketprice=flipud(marketprice);
		% marketprice2=flipud(marketprice2);

	
	price_names2=[];


	for (i=1:length(price_names))
		price_names2=[price_names2; price_names{i}];
		% disp(price_names2)
	end

	

end