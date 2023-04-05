clear                                                                      %limpia todas las variables
close all                                                                  %cerrar todas las posibles ventanas de imagenes
clc                                                                        %limpiar la ventana de comandos

x_valores = -9:0.1:9;
a_0 = 0;
L = pi();
f_x = 0;
f_x = f_x + (a_0 / 2);                                                     %valor de la serie con el coeficiente de a_0

for n = 1:1:1000
	% a_n = 0;

    b_n = ( 2 / (n * pi() )) * ( 1 - cos(n * pi()));                       %valor de b_n
    b_n_sumatorio = b_n * sin( (n * pi() * x_valores) / L);                %valor iterado de b_n

    f_x = f_x + b_n_sumatorio;                                             %valor iterado de la Serie de Fourier

    plot(x_valores, f_x, 'LineWidth', 0.5)                                 %valores de X, valores de Y, (lineWidth) -> ancho de linea
    title('Gráfica de Fourier')                                            %insertar titulo
    xlabel('x')                                                            %etiqueta del eje x
    ylabel('f(x)')                                                         %etiqueta del eje y
    pause(0.01)
end