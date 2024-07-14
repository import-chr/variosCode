import cv2
import numpy as np

main_capture = cv2.VideoCapture('plasma.mp4')
# RES = 1920, 1080

while True:
    imagen = main_capture.read()[1]
    imagen_dim = cv2.resize(imagen, (800, 500))
    # redim = cv2.resize(imagen, RES, interpolation = cv2.INTER_AREA)
    imagen_gris = cv2.cvtColor(imagen_dim, cv2.COLOR_BGR2GRAY)
    imagen_borde = cv2.Canny(imagen_gris, 30, 60)

    # cv2.imshow('imagen original', imagen_dim)
    # cv2.imshow("imagen gris", imagen_gris)
    cv2.imshow("imagen bordes", imagen_borde)
    
    if cv2.waitKey(33) == ord("q"):
        break

cv2.destroyAllWindows()