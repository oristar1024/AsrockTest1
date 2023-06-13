#pragma once
#include "ConsoleObject.h"

// Ό³Έν :
class Part : public ConsoleObject
{
public:
	// constrcuter destructer
	Part();
	~Part();

	// delete Function
	Part(const Part& _Other) = delete;
	Part(Part&& _Other) noexcept = delete;
	Part& operator=(const Part& _Other) = delete;
	Part& operator=(Part&& _Other) noexcept = delete;

	void SetPrev(Part* _prev);

	void Move();
	

protected:
	Part* Next = nullptr;
	Part* Prev = nullptr;
	int4 PrevPos;
private:
	
};

