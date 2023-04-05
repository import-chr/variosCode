%
% Cdte. 1/a. Christian Jair Loeza Ramirez
% No. 08 - 3 I.C.I. A
%
clear
close all
clc

%delimitacion del eje x
eje_x = -8:0.1:8;

%variables
L = 2; %valor de L
a_0 = 8 / 3; %valor de a0
f_x = a_0 / L; %valor inicial de la serie de f(x)

%iteraciones
for n = 1:1:1000
    %valor de an en la sumatoria
    a_n = ((16 * cos(n * pi()) / (n^2 * pi()^2)) * (cos((n * pi() * eje_x) / L)));
    %se omite bn debido a su valor de 0
    %se asigna el valor de an a una f(x) temporal que ayuda a la suma iterativa
    f_x_prev = a_n;
    %se asigna a f(x) el valor de la f(x) temporal
    f_x = f_x + f_x_prev;

    %se grafica la serie
    plot(eje_x, f_x), title('Serie Parcial de Fourier'), xlabel('x'), ylabel('f(x)');

    %pausa para ver los cambios
    pause(0.01);
end