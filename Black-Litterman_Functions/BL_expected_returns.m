
function [BL_Er, BL_sigma, BL_pi, BL_omega,rac] = ...
	BL_expected_returns(data, market, market_caps,...
						BL_tau, BL_P, BL_Q)

	%obtain the covariance of expected retursn of the data (BL_sigma)
	r_it = (data(2:end,:)./data(1:end-1,:)) - 1;
	BL_sigma=cov(r_it);

    % disp(BL_sigma);
    for i = 1:size(BL_P,1)
        BL_omega(i) = BL_P(i,:)*BL_sigma*BL_P(i,:)';
    end

    BL_omega = diag(BL_tau*BL_omega);
    
	%Calculating Risk aversion coefficient - value is 0.0286
	risk_aversion_coefficient=...
	comp_risk_aversion_coefficient(mean(market),0,cov(market));	

    rac = risk_aversion_coefficient;

	%calculating portion investmen in each asset, weighted by market capitalization
	[cap_weights]=capweights(market_caps);

	%Calculate the implied excess equilibrium return vector (BL_Pi)
	%This is the Inverse optimization step
	BL_pi=risk_aversion_coefficient*BL_sigma*cap_weights';

	%Use the below equation to computer E[R], which
	%represents the new combined return vector
	BL_Er=(inv(inv(BL_tau*BL_sigma)+BL_P'*inv(BL_omega)*BL_P)) * ...
	      (inv(BL_tau*BL_sigma)*BL_pi+BL_P'*inv(BL_omega)*BL_Q);
    BL_Er = BL_Er';
    
    BL_sigma = inv(inv(BL_tau * BL_sigma) + BL_P'*inv(BL_omega)*BL_P);

end


%{
BL_x =

    0.1934    0.2849    0.1763    0.0121    0.1529    0.0160    0.1645

    %}