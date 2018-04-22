## 1605109
## Apr 22 2018 1230

function ret = ncosX_1605109 (x, n)
    ret = 0;
    mul = x.*x;
    mul = -mul;
    cur = 1;
    for i=1:n
        ret = ret + cur;
        cur = cur .* mul;
        cur = cur / (2*i-1);
        cur = cur / (2*i);
    endfor
endfunction