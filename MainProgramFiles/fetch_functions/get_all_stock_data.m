function [month day year price marketcap fail_symbols success_symbols] = ...
	get_all_stock_data(SP500_symb_csv,SP500_symb)



	
	[month,day,year,price, marketcap,fail_symbols,success_symbols]=deal(cell(1,1));
	
	fc=1;
	sc=1;
	for i=1:length(SP500_symb_csv)
		try
			curr_csv=char(SP500_symb_csv(i));
			curr_symb=char(SP500_symb(i));
			

			[month{sc} day{sc} year{sc} price{sc} marketcap{sc}] = ...
			 textread(curr_csv ,'%s %d %d %f %f','delimiter',',: ');
			disp(marketcap{sc});
			if (marketcap{sc}>1)
				success_symbols{sc}=curr_symb;
				sc=sc+1;
			else
				fail_symbols{fc}=curr_symb;
				fc=fc+1;
			end
			

		catch
			curr_symb=char(SP500_symb(i));
			
			fail_symbols{fc}=curr_symb;
			fc=fc+1;
		end
	end	
	% eliminating the last row of failed symbols
	disp(sc)
	month(sc-1)=[]
	day(sc-1)=[]
	year(sc-1)=[]
	price(sc-1)=[]
	marketcap(sc-1)=[]
	%BY THE END OF THIS LOOP WE HAVE DAILY TIME SERIES DATA
	%NOW ITERATE THROUGH MONTH VECTOR AND DELETE EVERY ELEMENT
	% WHICH HAS THE SAME MONTH

	% price_names=[];

	% for (i=1:length(success_symbols))
	% 	price_names=[price_names; success_symbols(i)];
	% end

	% success_symbols=price_names;







end