#include <stdio.h>
#include <stdlib.h>
#include "libcomponent/libcomponent.h"
#include "libpower/libpower.h"
#include "libresistance/libresistance.h"

int main()
{

	float current;
	printf("Ange spänningskälla i V: ");
	scanf("%f", &current);

	char conn;
	printf("Ange koppling [S | P]: ");
	scanf(" %c", &conn);

	int componentCount;
	printf("Antal komponenter: ");
	scanf("%i", &componentCount);

	int i = 0;
	float *components = (float*)malloc(componentCount+1);

	while (i < componentCount)
	{
		printf("Ange komponent %d i Ohm: ", i+1);
		scanf("%f", &components[i]);
		i++;
	}

	float resultRes = calc_resistance(componentCount,conn,components);
	printf("Ersättningsresistans: %.0f Ohm\n", resultRes);

	float power = calc_power_r (current,resultRes);
	printf("Effekt: %.2f W\n",power);

	int resultECount = e_resistance(resultRes, components);

	printf("Ersättningsresistans i E12-serien kopplade i serier: ");

	i=0;
	int i2 = 0;

	while(i < componentCount && i2 < resultECount)
	{

		if (components[i] != 0)
		{
			printf( ((i2 == (resultECount-1)) ? "%.0f" : "%.0f, "), components[i]);
			i2++;
		}

		i++;
	}

	printf("\n");
	free(components);

	return 0;
}
