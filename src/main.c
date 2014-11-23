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



	return 0;
}
