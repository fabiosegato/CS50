#include "bmp.h"

void swap(int *a, int *b, int *c,int *a2,int *b2, int *c2);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]);

//sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);

