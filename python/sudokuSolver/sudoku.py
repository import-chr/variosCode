# -*- coding: utf-8 -*-
"""
Created on Mon Apr 15 19:37:44 2024

@author: AORUS
"""

sudoku: list[list[int]] = [[0,0,0,9,0,7,0,3,0],
                           [0,0,8,4,0,3,0,0,0],
                           [0,0,7,0,2,0,0,5,4],
                           [9,7,0,3,4,1,5,8,0],
                           [5,8,0,7,0,6,0,0,2],
                           [6,3,0,2,8,5,0,9,1],
                           [0,1,5,0,0,0,0,0,0],
                           [0,0,0,6,0,0,0,2,0],
                           [0,0,0,5,7,0,0,0,0]]

def print_sudoku(sudoku):
    for cell in sudoku:
        print(cell)

def coordenada_grid(indexVal):
    if indexVal <= 2:
        return 0
    elif indexVal <= 5:
        return 1
    else:
        return 2

def obtener_grid(x, y, sudoku):
    subgrid_col = coordenada_grid(x)
    subgrid_fila = coordenada_grid(y)
    
    grid = []
    
    for fila in sudoku[subgrid_fila * 3: subgrid_fila * 3 + 3]:
        for col in fila[subgrid_col * 3: subgrid_col * 3 + 3]:
            grid.append(col)
    
    return grid

def es_posible(x, y, v, sudoku):
    # revisar fila
    if v in sudoku[y]:
        return False
    
    # revisar columna
    col = [fila[x] for fila in sudoku]
    
    if v in col:
        return False
    
    # revisar grid 3x3
    grid3x3 = obtener_grid(x, y, sudoku)
    
    if v in grid3x3:
        return False
    
    return True

def resolver_sudoku(sudoku):
    for y in range(9):
        for x in range(9):
            if sudoku[y][x] == 0:
                for valor in range(1, 10):
                    if es_posible(x, y, valor, sudoku):
                        sudoku[y][x] = valor
                        
                        resolver_sudoku(sudoku)
                        
                        sudoku[y][x] = 0
                return
    print_sudoku(sudoku)
    return


resolver_sudoku(sudoku)