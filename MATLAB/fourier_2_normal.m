clear   % limpia todas las variables
close all   % cerrar todas las posibles ventanas de imagenes
clc     % limpiar la ventana de comandos

x_valores = -9:0.1:9;
a_0 = 0;
L = pi();
f_x = 0;
f_x = f_x + a_0 / 2;	% Se puede poner 0 en a_0 / 2 porque a_0 = 0
a_n_sumatorio = 0;

for n = 1:1:1000
	% a_n = (6/(n^2*(pi()^2))) * (cos(n * pi()) - 1);
    % a_n_sumatorio = a_n * cos((n*pi()*x_valores)/L);

    b_n = ( 2 / (n * pi() )) * ( 1 - cos(n * pi()));
    b_n_sumatorio = b_n * sin( (n * pi() * x_valores) / L);

    f_x = f_x + a_n_sumatorio + b_n_sumatorio;

    plot(x_valores, f_x, 'LineWidth', 0.5)               % Valores de X, Valores de Y, (lineWidth) -> ancho de linea
    title('Gráfica de Fourier')       % insertar titulo
    xlabel('x')        % etiqueta del eje x
    ylabel('f(x)')        % etiqueta del eje y
    pause(0.01)
end