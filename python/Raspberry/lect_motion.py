import cv2
import numpy as np

camara = cv2.VideoCapture(0)
substractor = cv2.createBackgroundSubtractorMOG2()
substractor2 = cv2.createBackgroundSubtractorKNN()
# substractor3 = cv2.bgsegm.createBackgroundSubtractorGMG()

while camara.isOpened():
    fotograma = camara.read()[1]
    mask = substractor.apply(fotograma, 1)
    foreground = cv2.bitwise_and(fotograma, fotograma, mask = mask)
    
    cv2.imshow("imagen original", fotograma)
    cv2.imshow("foreground", foreground)
    
    if cv2.waitKey(33) == ord("q"):
        break

camara.release()
cv2.destroyAllWindows()