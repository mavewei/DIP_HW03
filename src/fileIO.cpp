/* 
 * File:   fileIO.cpp
 * Author: mavewei
 *
 * Created on October 31, 2013, 5:28 PM
 */

 #include "problem_02.h"

 int readImage(char *filename, unsigned char *image) {
 	FILE *fp;
 	if((fp = fopen(filename, "rb")) != NULL) {
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