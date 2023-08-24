import cv2
import numpy as np
import matplotlib.pyplot as plt

img2 = cv2.imread('image.jpg')

plt.imshow(img2[:, :, ::-1])
plt.axis('off')


# func to apply transformation and visualize the result
def perform_Transformation(image, M):
    """
    Takes in input image and the transformation matrix 
    Appl
    """
    rows, cols, ch = image.shape

    dst = cv2.warpAffine(image, M, (cols, rows))

    plt.figure(figsize=(24, 8))
    plt.subplot(121)
    plt.imshow(image[:, :, ::-1])
    plt.axis('off')
    plt.title('Original Image')

    plt.subplot(122)
    plt.imshow(dst[:, :, ::-1])
    plt.axis('off')
    plt.title("Transformed Image")


# Translation
M = np.float32([[1, 0, 400],
                [0, 1, 50]])

# tranlates the image to 400 pixels in x direction and 50 pixels in y direction

perform_Transformation(img2, M)

# Scaling
M = np.float32([[0.4, 0, 0],
                [0, 0.4, 0]])

# scale image down by a factor of 0.4 in both directions
perform_Transformation(img2, M)

# Rotation
center = (img2.shape[1]//2, img2.shape[0]//2)
angle = -90
scale = 1

# rotate the image by 50 anti clockwise and scale the result by 0.6
rot_mat = cv2.getRotationMatrix2D(center, angle, scale)

perform_Transformation(img2, rot_mat)

# Sheer (vertical)
M = np.float32([[1, 0.4, 0],
                [0, 1, 0]])

perform_Transformation(img2, M)

# Sheer (horizontal)
M = np.float32([[1, 0, 0],
                [0.2, 1, 0]])

perform_Transformation(img2, M)

# Sheer (both added)
M = np.float32([[1, 0.4, 0],
                [0.2, 1, 0]])

perform_Transformation(img2, M)

plt.waitforbuttonpress()
# cv2.waitKey(0)
