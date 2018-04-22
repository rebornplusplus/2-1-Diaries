## 1605109
## Apr 22 2018 1310

function ret = falseposition_1605109(fun, xl, xu, es, n)
	while(fun(xl) * fun(xu) >= 0)
		fprintf("Invalid input.\n");
		xl = input('Enter new first guess: ');
		xu = input('Enter new second guess: ');
	endwhile
	
	prev = 0;
	ea = 1.1*es;
	for i = 1 : n
		if ea <= es
			break
		endif
		
		xr = xu - (((xl - xu)/(fun(xl)-fun(xu)))*fun(xu));
		if(and((i > 1), (xr != 0)))
			ea = (xr - prev) / xr * 100;
			ea = abs(ea);
		endif
		
		test = fun(xl) * fun(xr);
		if(test == 0)
			ea = 0;
		elseif(test < 0)
			xu = xr;
		else
			xl = xr;
		endif
		prev = xr;
	endfor
	
	ret = prev;
	fprintf("Estimated root for %d iterations: %f\n", n, ret);
	fprintf("Error = %f percent\n", ea);
endfunction
