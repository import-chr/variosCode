import cv2
import numpy as np

camara = cv2.VideoCapture(0)

while camara.isOpened():
    fotograma = camara.read()[1]
    fotograma_gris = cv2.cvtColor(fotograma, cv2.COLOR_BGR2GRAY)
    fotograma_bordes = cv2.Canny(fotograma_gris, 30, 60)
    cv2.imshow("imagen original", fotograma)
    cv2.imshow("imagen gris", fotograma_gris)
    cv2.imshow("imagen bordes", fotograma_bordes)
    
    if cv2.waitKey(33) == ord("q"):
        break

camara.release()
cv2.destroyAllWindows()