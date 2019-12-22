#include "fuel_counter_upper/FuelCounterUpper.h"

unsigned int FCU::CalculateRequiredFuelForMass(unsigned int mass)
{
	return (mass / 3) - 2;
}
