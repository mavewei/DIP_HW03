/* 
 * File:   fileIO.h
 * Author: mavewei
 */

#ifndef	READIMAGE_H
#define	READIMAGE_H

 int readImage(char *filename, unsigned char *image);
 int writeImagePGM(char *filename, int height, int width, unsigned char *image);

#endif