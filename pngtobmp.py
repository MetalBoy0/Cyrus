# This script converts a specified the PNG image (including transparent background) to BMP format.

import sys
from cv2 import imread, imwrite, IMREAD_UNCHANGED



def png_to_bmp(png_path, bmp_path):
    # Read the PNG image
    png_img = imread(png_path, IMREAD_UNCHANGED)

    # Save the PNG image as BMP
    imwrite(bmp_path, png_img)


if __name__ == '__main__':
    
    # Check if the correct number of arguments are provided
    if len(sys.argv) != 2:
        print('Usage: python pngtobmp.py <input_png_path> <output_bmp_path>')
        sys.exit(1)

    # Get the input PNG path and output BMP path
    png_path = sys.argv[1]
    bmp_path = png_path.replace('.png', '.bmp')

    # Convert the PNG image to BMP format
    png_to_bmp(png_path, bmp_path)
    print(f'PNG image "{png_path}" converted to BMP format and saved as "{bmp_path}"')