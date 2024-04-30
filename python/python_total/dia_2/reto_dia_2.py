nombre: str = input('Nombre: ')
total_ventas: float = float(input('Total de ventas en el mes: '))
ganancias: float = round(total_ventas * 0.13, 2)

print(f'Hola {nombre}, usted vendio ${total_ventas}; sus ganancias de este mes son: ${ganancias}')