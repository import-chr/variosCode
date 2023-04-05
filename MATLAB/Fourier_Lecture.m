clear
close all
clc

%Serie Fourier
%f_x = 0;
eje_x = -7:0.01:7;

a_0 = -3/2;
f_x = a_0;

%Sumatoria
for n = 1:1:1000
    a_n = (6 / (n^2 * pi()^2)) * (cos(n*pi()) - 1) * cos((n * pi() * eje_x) / 2);
    b_n = (-6 / (n * pi()) * cos(n * pi()) * sin((n * pi() * eje_x) / 2));
    f_x_prev = a_n + b_n;
    f_x = f_x + f_x_prev;

    plot(eje_x, f_x);

    pause(0.01);
end
