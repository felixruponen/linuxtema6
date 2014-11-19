#ifndef NULL
#define NULL 0
#endif

#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
{

        if (array == NULL)
                return -1;

        float resistance = 0;
        int i = 0;

        if (conn == 'S')
        {

                while (i < count)
                {
                        resistance += array[i];
                        i++;
                }

                return resistance;

        }
        else if (conn == 'P')
        {

		if (count == 2)
		{
			if (array[0] == NULL || array[1] == NULL)
				return 0;
			else
				return (array[0]*array[1])/(array[0]+array[1]);
		}
		else
		{

                	while (i < count)
                	{

                        	if (array[i] == NULL)
                                	return 0;
                        	else
                          	     	resistance += (1/array[i]);
				i++;
			}

	                /*
				Eftersom formeln är:
                	         1      1     1     1
        	                 -  =   -  +  -  +  -
	                        RES    R_1   R_2   R_N

	                        Blir resistansen:

                	         1
        	                 -  = RESULTAT
	                        RES

	                        1 = RESULTAT * RES

	                        RES = 1 / RESULTAT

	                */

			return (1/resistance);

                }

        }

        return -1;
}

