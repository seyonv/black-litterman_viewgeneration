% INput parameters are an array representing all the ticker symbols
% and an array representing all the csv's to parse through

% Ouput parameters are array for ALL data organized by date, price, volume, marketcap
% and separating the symbols that failed and succeeded
function [month day year price volume marketcap fail_symbols success_symbols] = ...
	get_all_stock_data(symb_csv,symb)



	[month,day,year,price, volume,marketcap,fail_symbols,success_symbols]=deal(cell(1,1));
	
	fc=1;
	sc=1;
	last_was_fail=0;
	for i=1:length(symb_csv)
		try
			curr_csv=char(symb_csv(i));
			curr_symb=char(symb(i));
			
			% textread parses through the csv file and in one iteration
			% returns the values of all elements for that particualr file
			[month{sc} day{sc} year{sc} price{sc} volume{sc} marketcap{sc}] = ...
			 textread(curr_csv ,'%s %d %d %f %d %f','delimiter',',: ');
			% disp(marketcap{sc});
			% fprintf('current success count value is %d',sc);
			if (marketcap{sc}>1)
				success_symbols{sc}=curr_symb;
				% this is to ensure that all the dates are lined up 
				% for every stock and no rows are jumped or skipped 
				if (i>1)
					disp('i >1');
					tempbool=isequal(month{sc},month{sc-1});
					disp(tempbool);
					% fprintf('iteration %d, stock %s and boolean is %d\n',...
					% 	     i,curr_symb,tempbool);
					
				end
				sc=sc+1;
			else
				fail_symbols{fc}=curr_symb;
				fc=fc+1;
			end
			last_was_fail=0;

		catch
			curr_symb=char(symb(i));
			
			fail_symbols{fc}=curr_symb;
			fc=fc+1;
			last_was_fail=1;
		end
	end	
	% eliminating the last row of failed symbols
	% only do this if the last parsed value was a fail not a successc
	if last_was_fail==1
		month(sc-1)=[];
		day(sc-1)=[];
		year(sc-1)=[];
		price(sc-1)=[];
		volume(sc-1)=[];
		marketcap(sc-1)=[];
	end
	%BY THE END OF THIS LOOP WE HAVE DAILY TIME SERIES DATA
	%NOW ITERATE THROUGH MONTH VECTOR AND DELETE EVERY ELEMENT
	% WHICH HAS THE SAME MONTH

	% price_names=[];

	% for (i=1:length(success_symbols))
	% 	price_names=[price_names; success_symbols(i)];
	% end

	% success_symbols=price_names;







end