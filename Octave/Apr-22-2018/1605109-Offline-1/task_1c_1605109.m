## Apr 22 2018
## 1245

for i = 1 : 51
	nc(i) = ncosX_1605109(1.5, i);
endfor

for i = 1 : 50
	err(i) = abs((nc(i+1) - nc(i)) / nc(i+1) * 100);
endfor

x = 1 : 50;
plot(x, err);
grid on;

ylim([-200, 1000]);
title("Relative Approximate Error of ncosX() at different iterations");
xlabel("Number of iterations");
ylabel("Relative Error");