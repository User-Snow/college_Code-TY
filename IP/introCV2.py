import cv2
#reading an image
image = cv2.imread('image.jpg', 1)

cv2.imshow('Example1', image)

#resizing an image
resize = cv2.resize(image, (0, 0), fx = 0.4, fy = 0.4)

cv2.imshow('Resized', resize)

# cv2.destroyAllWindows()
# Rotating image
(rows, cols) = resize.shape[:2]
 
M = cv2.getRotationMatrix2D((cols / 2, rows / 2), 180, 1)

res = cv2.warpAffine(resize, M, (cols, rows))

cv2.imshow('rotated', res)

#Edge detection using canny algo
edges = cv2.Canny(resize, 100, 200)

cv2.imshow('Edges', edges)

#to show image infinitely(Pause)
cv2.waitKey(0)
