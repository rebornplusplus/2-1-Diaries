## 1605109
## Apr 22 2018 1300

function ret = task_2_func_1605109(x)
	if x == 1
		x = x - 0.00001;
	elseif x == -2
		x = x + 0.00001;
	endif
	ret = ((x.*(sqrt(6./(2+x))))./(1-x)) - 0.05 ;
endfunction
