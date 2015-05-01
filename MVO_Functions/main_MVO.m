function [ MVO_x MVO_var adjvector  nominal_return temp_Q] = main_MVO( historical_inflation, historical_asset_returns,...
        expected_inflation, inflation_variance, infbeta, R, transaction_cost, previous_portfolio)
        % expected_inflation, inflation_variance, infbeta, R, transaction_cost, max_transactions, previous_portfolio)
    %{
    historical_inflation: time series data for inflation values over the
    relevant period
        
    **IN DECIMAL FORM**

    historical_asset_returns: time series data for relevant assets over
    relevant periods

    expected_inflation: inflation calculated through markov RS model
        
    inflation_variance: inflation variance calculated through markov RS
        
    beta: vector of n beta values corresponding to each asset for the current
    regime
        
    %}

    r_M = historical_inflation';
    r_it = historical_asset_returns;
    mu_M = expected_inflation;
    del_M = inflation_variance;

    [T, n] = size(r_it);
    c = [zeros(3*n,1);];
    Aeq = [ones(1,n) zeros(1,2*n)
           eye(n) -eye(n) eye(n)];
    beq = [1; previous_portfolio];
    lb=zeros(3*n,1);
    
    ub=9999*ones(3*n,1);    
    
    nominal_return = prod(1+r_it).^(1/T) - 1;
    nominal_return = nominal_return';
    % disp(size(nominal_return));
    % disp(size(infbeta));
    % disp(size(mu_M));
    adjusted_return = nominal_return + infbeta*mu_M;
    alpha = nominal_return(1:end)-infbeta*mu_M;
    % disp(nominal_return(1:end))
    % disp(infbeta:mu_M)
    % disp(size(r_it(:,1)));
    % disp(size(alpha(1)));
    % disp(size(infbeta(1)));
    for i=1:n
        epsi(:,i)=r_it(:,i)-(alpha(i)+infbeta(i)*r_M(:,1));
    end
    % infbeta=infbeta.^(-1);
    del_epsi=diag(cov(epsi));
    for i = 1:n;
        for j = 1:n;
            if i==j
                Q_sf(i,i)=infbeta(i)^2*del_M+del_epsi(i);
            else
                Q_sf(i,j)=infbeta(i)*infbeta(j)*del_M;
            end
        end
    end
    
    temp_Q = Q_sf;
    
    Q_sf = [Q_sf zeros(n,2*n); zeros(2*n, 3*n)];
    
    options = optimset('Algorithm', 'interior-point-convex', 'TolFun', 1/10^10, 'MaxIter', 1000, 'TolCon', 1/(10^10));
                
    % Solve Single Factor model and store SD values
    disp('____________________')
    disp(size(adjusted_return'));
    disp(size(zeros(1,2*n)));
    disp(size(zeros(1,n)));
    disp(size(ones(1,2*n)));

    for i = 1:length(R);
        A=[-(adjusted_return') transaction_cost*ones(1,2*n);];
            %zeros(1,n) transaction_cost * ones(1,2*n)];
        b=[-R(i); ]%max_transactions];

        
        [MVO_x(i,:), fval(i,1)] = quadprog(Q_sf, c, A,b, Aeq,beq,...
                                          lb,ub,[],options);
        MVO_var(i,1)=(MVO_x(i,:)*Q_sf*MVO_x(i,:)');
        MVO_x=MVO_x(i,1:n);
        
    end
    
    adjvector = [MVO_x' adjusted_return diag(temp_Q) infbeta];

end


