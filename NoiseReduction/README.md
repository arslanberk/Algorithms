# Algorithms
**Erosion Algorithm** to find edges of the shape in the image file. Erosion is one of the two basic operators in the area of mathematical morphology, the other being dilation. 
**Median Filter Algorithm** to remove noise. The median filter is a nonlinear digital filtering technique, often used to remove noise.

# Attention
To see correct results on terminal window, it is needed to follow these requirements on Windows Command Prompt;
- Screen buffer size: width - 121 , height - 1000
- Window size: width - 121 , height - 60 
- Font: Consolas 
- Font Size: 14
- g++ for makefile

**Important:** If you do not follow these instructions, you will have problem to see images in correct shapes on terminal/command prompt.

# Installation
It is always possible to compile through any C/C++ IDE, or through 'makefile' using 'make' command. 

Usage:
- 'make' command compiles and deploys the application as an executable file (NoiseReduction.exe)
- 'make clean' command removes any created *.o files and executable file (NoiseReduction.exe)

**Important:** 'image.txt' and 'noise.txt' files must be in the same directory with the executable file.

# Image Files
Image files, 'image.txt' and 'noise.txt', contain 0 and 1 to construct a simple image to apply algorithms.
'image.txt' does not contain noise while 'noise.txt' contains noise.
