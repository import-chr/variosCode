# -*- coding: utf-8 -*-
"""
Created on Mon Apr 15 19:37:44 2024

@author: AORUS
"""
from selenium import webdriver
from selenium.webdriver.common.by import By
import pyautogui as pyG
import time

def subir_solucion(sudoku):
    for l in range(3):
        pyG.press('left')

    for row in sudoku:
        for ele in row:
            pyG.press(str(ele))
            pyG.press('right')
        
        pyG.press('down')
    
        for c in range(8):
            pyG.press('left')
    
    print("Listo...")
    
    return

def leer_web_sudoku(dificultad = "hard"):
    driver = webdriver.Firefox()
    url = "https://www.nytimes.com/puzzles/sudoku/" + dificultad
    
    print("Leyendo SUDOKU desde {}".format(url))
    
    driver.get(url)
    time.sleep(2)
    
    sudoku_dict = {}
    grid = driver.find_element(By.CLASS_NAME, 'su-board')
    cells = grid.find_elements(By.TAG_NAME, 'div')
    
    for el in cells:
        cell = el.get_attribute("data-cell")
        val = el.get_attribute("aria-label")
        
        if cell is None or val is None:
            continue
        
        sudoku_dict[int(cell)] = 0 if val == "empty" else int(val)
        
    # print(sudoku_dict)
    
    sudoku = []
    x, y = 0, 0
    
    for i in range(81):
        if x == 9:
            y += 1
            x = 0
        
        if x == 0:
            sudoku.append([])
        
        sudoku[y].append(sudoku_dict[i])
        x += 1
    
    print_sudoku(sudoku)
    print()
    
    return sudoku

def sudoku_manual() -> list[list[int]]:
    sudoku: list[list[int]] = [[0,0,0,9,0,7,0,3,0],
                               [0,0,8,4,0,3,0,0,0],
                               [0,0,7,0,2,0,0,5,4],
                               [9,7,0,3,4,1,5,8,0],
                               [5,8,0,7,0,6,0,0,2],
                               [6,3,0,2,8,5,0,9,1],
                               [0,1,5,0,0,0,0,0,0],
                               [0,0,0,6,0,0,0,2,0],
                               [0,0,0,5,7,0,0,0,0]]
    return sudoku

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
    for fila in range(9):
        for columna in range(9):
            if sudoku[fila][columna] == 0:
                for valor in range(1, 10):
                    if es_posible(columna, fila, valor, sudoku):
                        sudoku[fila][columna] = valor
                        
                        resuleto = resolver_sudoku(sudoku)
                        
                        if resuleto:
                            return True
                        
                        sudoku[fila][columna] = 0
                
                return False

    return True


diff_sudoku = leer_web_sudoku()
resuelto = resolver_sudoku(diff_sudoku)

if resuelto:
    print("SUDOKU resuelto...")
    print_sudoku(diff_sudoku)
    subir_solucion(diff_sudoku)
else:
    print("SUDOKU no resuelto...")