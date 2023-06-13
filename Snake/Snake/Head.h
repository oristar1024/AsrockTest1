#pragma once
#include "Part.h"
#include "Body.h"
#include <list>

// Ό³Έν :
class Head : public Part
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	Part* AddPart();

	Body* body = nullptr;
	std::list<Part*> partList;
protected:
	void Tick(float _Time);

private:
};

