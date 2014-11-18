#include <stdio.h>
#include <math.h>
#include "libpower.h"


float calc_power_r(float volt, float resistance)
{
	float power=(volt*volt)/resistance;
	return power;
}


float calc_power_i(float volt, float current)
{
	float power=volt*current;
	return power;
}
