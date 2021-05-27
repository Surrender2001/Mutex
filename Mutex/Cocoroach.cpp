#include "Cocoroach.h"

Cocoroach::Cocoroach()
{
	Time = milliseconds(0);
}

Cocoroach::Cocoroach(int id):Cocoroach()
{
	this->Id = id;
}
