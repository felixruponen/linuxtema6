#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libcomponent.h"


int e_resistance(float orig_resistance, float *res_array) 
{
	float e12[12] = { 1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2 };

	int count = 0;

	while(orig_resistance != 0 && count < 3) {

		int length = 1;

		if(orig_resistance >= 10) {
			length = pow(10, (int) log10(orig_resistance));	
		}
		
		printf("SIZE: %d\n", length);
		printf("ORIG: %f\n", orig_resistance);

		for(int i = (sizeof(e12) / sizeof(float)) - 1; i >= 0; i--) {
			
			if(orig_resistance >= (e12[i] * length)) {

				res_array[count] = e12[i] * length;
				orig_resistance -= e12[i] * length;

				break;
			}

		}
		count++;
	}
	
	return count;
}