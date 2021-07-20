#include "Tracer.hpp"

Tracer::Tracer(double observerLatitude, double observerLongitude,
               double observerElevation)
	: loader(observerLatitude, observerLongitude, observerElevation),
	  latitude(observerLatitude), longitude(observerLongitude),
	  elevation(observerElevation)
{
	/* Nothing to do */
}

