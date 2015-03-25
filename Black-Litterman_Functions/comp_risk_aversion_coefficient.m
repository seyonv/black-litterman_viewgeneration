function [rac]=comp_risk_aversion_coefficient(market_return, risk_free_rate, market_var)
	rac = [market_return-risk_free_rate]/market_var;
end