"""
Shape Detection Module

2021.6.11
"""

import cv2
import numpy as np

def getContours(img):
    
def drawContours(imgContour,contours):
    

def main():
    img = cv2.imread("../Resources/shapes.png")
    imgContour = img.copy()
    imgGray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    imgBlur = cv2.GaussianBlur(imgGray,(7,7),1)
    imgCanny = cv2.Canny(imgBlur,50,50)
    kernel = np.ones((5, 5))
    imgDil = cv2.dilate(imgCanny, kernel, iterations=1)
    contours = getContours(imgCanny)
    imgResult = drawContours(imgContour,contours)
    
    cv2.imshow("Output", imgResult)
    cv2.waitKey(0)

if __name__ == "__main__": #check whether we are running this script or we are calling this script from the other script
    main()
