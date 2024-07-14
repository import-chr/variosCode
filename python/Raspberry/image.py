import cv2
import numpy as np

imagen = cv2.imread('EMI1.png')
imagen_dim = cv2.resize(imagen, (500, 500))
imagen_gris = cv2.cvtColor(imagen_dim, cv2.COLOR_BGR2GRAY)
imagen_borde = cv2.Canny(imagen_gris, 30, 60)

cv2.imshow('imagen original', imagen_dim)
cv2.imshow("imagen gris", imagen_gris)
cv2.imshow("imagen bordes", imagen_borde)
cv2.waitKey()
cv2.destroyAllWindows()