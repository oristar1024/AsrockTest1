#include "Part.h"

Part::Part() 
{
	SetChar('P');
}

Part::~Part() 
{
}

void Part::SetPrev(Part* _prev) 
{
	Prev = _prev;
	SetPos(Prev->PrevPos);
}

void Part::Move()
{
	PrevPos = GetPos();
	SetPos(Prev->PrevPos);
}