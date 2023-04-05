% comentar el código

clear   % limpia todas las variables
close all   % cerrar todas las posibles ventanas de imagenes
clc     % limpiar la ventana de comandos

% x_valores = -7:1:7     %x_valores (declaracion)   : el paso (inicio , decremento , fin)
x_1 = -2:0.1:0;
x_2 = 0:0.1:2;
y_1 = -3*ones(size(x_1));       % ones (crea un vector de unos con el tamaño especificado)
y_2 = 3*x_2-3;

plot(x_1,y_1,'LineWidth',4)               % para buscar (lineWidth) -> ancho de linea
title('Gráfica de Fourier 1')       % insertar titulo
xlabel('x')        % etiqueta del eje x
ylabel('f(x)')        % etiqueta del eje y
hold on         % retener la grafica
plot(x_2,y_2,'LineWidth',4)
hold off        % soltar la gráfica

x_valores = -2:0.001:7;
%%
L = 2;
a_0 = -3;
f_x = 0;
f_x = f_x + a_0 / 2;

for n = 1:1:1000                % Se puede colocar 1:1000 (por default el incremento 
    a_n = (6/(n^2*(pi()^2))) * (cos(n * pi()) - 1);
    a_n_sumatorio = a_n * cos((n*pi()*x_valores)/L);
    b_n = (-6/(n*pi())) * cos(n * pi());
    b_n_sumatorio = b_n * sin((n*pi()*x_valores)/L);

    f_x = f_x + a_n_sumatorio + b_n_sumatorio;
    plot(x_valores, f_x)
    pause(0.1)
end

figure(2)
plot(x_valores, f_x)