## 1605109
## Apr 22 2018 1245

x = -2*pi : 0.2 : 2*pi;
y = cos(x);
y1 = ncosX_1605109(x, 1);
y2 = ncosX_1605109(x, 3);
y3 = ncosX_1605109(x, 5);
y4 = ncosX_1605109(x, 20);

plot(x, y);
hold on;
plot(x, y1);
hold on;
plot(x, y2);
hold on;
plot(x, y3);
hold on;
plot(x, y4);
grid on;

title("cos(x) with different number of iterations");
xlabel("Values of x	");
ylabel("Values of cos(x)");