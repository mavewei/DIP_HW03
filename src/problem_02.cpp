/* 
 * File:   problem_02.cpp
 * Author: mavewei
 *
 * Created on October 31, 2013, 5:28 PM
 */

 #include <stdio.h>
 #include <stdlib.h>

 #define HEIGHT 	64
 #define WIDTH 		64
 #define fileNums	16
 #define VERBOSE	1
 using namespace std;

 int convolution(int x, int y, unsigned char *image, double *mask);
 int readImage(char *filename, unsigned char *image);
 int writeImagePGM(char *filename, int height, int width, unsigned char *image);

 int main(int argc, char *argv[])
 {
 	int x, y, fileSum, mask;
 	char inputFilename[32], oriOutputFilename[32];
 	unsigned char *imgIn[fileNums];

 	if(VERBOSE) printf("\n  -- READ SAMPLE IMAGE -- \n");
 	for(fileSum = 0; fileSum < fileNums; fileSum++) {
 		if(fileSum < 9) {
 			sprintf(inputFilename, "sample0%d.raw", fileSum + 1);
 		}
 		else
 		{
 			sprintf(inputFilename, "sample%d.raw", fileSum + 1);
 		}
 		imgIn[fileSum] = (unsigned char *) calloc((HEIGHT * WIDTH), sizeof(unsigned char));
 		if(!readImage(inputFilename, imgIn[fileSum])) {
 			fprintf(stderr, "***ERROR: Failed to find input image!");
 			return -1;
 		}
 		// if(VERBOSE) printf("\n  -- WRITE SAMPLE IMAGE TO PGM --");
 		// if(fileSum < 9) {
 		// 	sprintf(oriOutputFilename, "sample0%d.pgm", fileSum + 1);
 		// }
 		// else
 		// {
 		// 	sprintf(oriOutputFilename, "sample%d.pgm", fileSum + 1);
 		// }
 		// if(!writeImagePGM(oriOutputFilename, HEIGHT, WIDTH, imgIn[fileSum])) {
 		// 	fprintf(stderr, "***ERROR: Failed writting output image!");
 		// 	return -1;
 		// }
 	}

 	double Mag[HEIGHT][WIDTH] = {}, sumArray[fileNums][9] = {};
 	double k3Mean[3][9] = {}, getMean, total, sum;
 	/*Laws' Mask 3X3*/
 	double lawMask[9][9] = {
 		{1, 2, 1, 2, 4, 2, 1, 2, 1},
 		{1, 0, -1, 2, 0, -2, 1, 0, -1},
 		{-1, 2, -1, -2, 4, -2, -1, 2, -1},
 		{-1, -2, -1, 0, 0, 0, 1, 2, 1},
 		{1, 0, -1, 0, 0, 0, -1, 0, 1},
 		{-1, 2, -1, 0, 0, 0, 1, -2, 1},
 		{-1, -2, -1, 2, 4, 2, -1, -2, -1},
 		{-1, 0, 1, 2, 0, -2, -1, 0, 1},
 		{1, -2, 1, -2, 4, -2, 1, -2, 1},
 	};
 	double lawMaskCoe[9] = {36, 12, 12, 12, 4, 4, 12, 4, 4}; 	

 	for(fileSum = 0; fileSum < fileNums; fileSum++) {
 		for(mask = 0; mask < 9; mask++) {
 			total = 0;
 			for(x = 0; x < HEIGHT; x++) {
 				for(y = 0; y < WIDTH; y++) {
 					sum = 0;
 					/*Convolution with Law Kernel Mask 3X3*/
 					sum = convolution(x, y, imgIn[fileSum], lawMask[mask]);
 					sum = sum / lawMaskCoe[mask];
 					total += sum;
 					Mag[x][y] = sum;
 				}
 			}
 			/*Get each sample whole mean value*/
 			getMean = total / (HEIGHT * WIDTH);
 			total = 0;
 			for(x = 0; x < HEIGHT; x++) {
 				for(y = 0; y < WIDTH; y++) {
 					total += (Mag[x][y] - getMean) * (Mag[x][y] - getMean);
 				}
 			}
 			total = total / (HEIGHT * WIDTH);
 			sumArray[fileSum][mask] = total;
 			k3Mean[0][mask] += total;
 		}
 	}
 	return 0;
 }

 int convolution(int x, int y, unsigned char *image, double *mask) {
 	int m, n, ptX, ptY;
 	double sum = 0.0;
 	for(m = -1; m < 2; m++) {
 		for(n = -1; n < 2; n++) {
 			ptX = x + m;
 			ptY = y + n;
 			if(ptX < 0){
 				ptX = 0;
 			} else if(ptX > (HEIGHT - 1)){
 				ptX = (HEIGHT - 1);
 			}
 			if(ptY < 0) {
 				ptY = 0;
 			} else if(ptY > (WIDTH - 1)) {
 				ptY = (WIDTH - 1);
 			}
 			sum += image[(ptX) * WIDTH + (ptY)] * mask[3 * (m + 1) + (n + 1)];
 		}
 	}
 	return sum;
 }

 int readImage(char *filename, unsigned char *image) {
 	FILE *fp;
 	if(fp = fopen(filename, "rb")) {
 		fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);
 		fclose(fp);
 		return 1;
 	} else {
 		return 0;
 	}
 }

 int writeImagePGM(char *filename, int height, int width, unsigned char *image) {
 	FILE *fp;
 	fp = fopen(filename, "wb");
 	if (fp) {
 		fprintf(fp, "P5\n\n%d %d 255\n", height, width);
 		fwrite(image, sizeof(unsigned char), height * width, fp);
 		fclose(fp);
 		return 1;
 	} else {
 		return 0;        
 	}
 }