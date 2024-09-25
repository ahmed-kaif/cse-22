function [v,ea,iter] = iter_calc(x, es, maxit)
  %initialization
  iter = 1; % iteration counter
  sol = 1; % current solution
  ea = 100; % approximate error

  % Iterative calculation
  while(1)
    solold = sol; % previous solution
    sol = sol + x ^ iter / factorial(iter);
    iter = iter + 1;
    if sol ~= 0
        ea = abs((sol - solold)/sol) * 100;
    endif

    if ea <= es || iter >= maxit, break, end
  end
  v = sol;
  end

