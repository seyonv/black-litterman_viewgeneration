% This function takes in the asset allocatiosn of standard MVO and our custom BLlation
% hedged model. It also tak

%% MVO_COMPARISON 
%{
    Take in the two MVO weightings, one for standard MVO and the other for
    Black-Litterman MVO, then show their projected returns over the sample
    period, alongside the market returns for that period. 
    
    This function can be modified accodingly if more benchmark models are
    added.
    
    MVO_x: vector of weights corresponding to standard MVO w/ transactions
    BL_x: vector of weights corresponding to our model
    asset_returns: relevant for the relevant assets over the sample
    period
    market_returns: market returns 
%}
function [cumul_MVO cumul_BL cumul_SP] = ...
        MVO_comparison( MVO_x, BL_x, projected_returns,...
                        market_returns,startyear,endyear)

    
    [T n] = size(projected_returns);

    
    MVO_returns = projected_returns*MVO_x;
    BL_returns = projected_returns*BL_x;

    cumul_MVO(1) = MVO_returns(1);
    cumul_BL(1) = BL_returns(1);
    cumul_SP(1) = market_returns(1);
  


    for i = 2:T
        cumul_MVO(i) = (1+cumul_MVO(i-1))*(1+MVO_returns(i))  - 1;
        cumul_BL(i) = (1+cumul_BL(i-1))*(1+BL_returns(i)) - 1;
        cumul_SP(i) =  (1+cumul_SP(i-1))*(1+market_returns(i)) - 1;
    end

    portfolio_MVO=1 * (1 + cumul_MVO);
    portfolio_BL=1 * (1 + cumul_BL);
    portfolio_SP=1 * (1 + cumul_SP);

    figure
    plot(1:T,cumul_MVO*100, '-b');
    hold all
    plot(1:T,cumul_BL*100, '-r');
    hold all
    plot(1:T,cumul_SP*100, '-g');
    
  %  plot(1:T,currBLprices,'-m');

    h = {'Standard MVO', 'Black-Litterman', 'S&P500'};
    h = legend(h);
     
    grid on;

    title(['Comparing Cumulative Returns of Model-Generated Portfolios and Market'...
        ,num2str(startyear),' to ',num2str(endyear)])
    xlabel('Time (in months)')
    ylabel('Cumulative Monthly Returns (in %)')
     

    figure
    plot(1:T,MVO_returns, '-b');
    hold all
    plot(1:T,BL_returns, '-r');
    hold all
    plot(1:T,market_returns,'-g');
    hold all
  %  plot(1:T,currBLprices, '-m');

    h = {'Standard MVO', 'Black-Litterman', 'S&P500'};

    title(['Comparing Return Values of Model-Generated Portfolios and Market'...
        ,num2str(startyear),' to ',num2str(endyear)])
    xlabel('Time (in months)')
    ylabel('Monthly Returns')

  
    
    h = legend(h);
     
    grid on;
    
    hold all 
    
    
end

