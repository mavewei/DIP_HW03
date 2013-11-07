/* 
 * File:   convolution.cpp
 * Author: mavewei
 *
 * Created on October 31, 2013, 5:28 PM
 */

 #include "problem_02.h"

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