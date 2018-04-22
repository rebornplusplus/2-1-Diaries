## 1605109
## Apr 22 2018 1353

function ret = secant_1605109(fun, xl, xu, es, n)
	ea = 1.1 * es;
	xr = 0;
	
	for i = 1 : n
		if(ea <= es)
			break
		endif
		
		xr = xu - (((xl - xu)/(fun(xl)-fun(xu)))*fun(xu));
		if(and((i>1), (xr != 0)))
			ea = (xr - xu) / xr * 100;
			ea = abs(ea);
		endif
		
		xl = xu;
		xu = xr;
	endfor
	
	ret = xr;
	fprintf("Estimated root for %d iterations: %f\n", n, ret);
	fprintf("Error = %f percent\n", ea);
endfunction
