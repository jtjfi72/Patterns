#include "../Header/quadrilateral.h"
#include <utility> 

using namespace std;

quadrilateral::quadrilateral() :
	name{ nullptr }, namelength{ 0 }, base{ 0 }, height{ 0 }
{
}
//Copy constructor
quadrilateral::quadrilateral(quadrilateral const & obj)
{
	CopyMembers(obj);
}

void quadrilateral::CopyMembers(quadrilateral const & obj)
{
	CopyName(obj.name, obj.namelength);
	base = obj.base;
	height = obj.height;
}

void quadrilateral::CopyName(wchar_t const * src, int const length)
{
	if (name != nullptr)
	{
		delete name;
	}
	namelength = length;
	name = new wchar_t[length];
	wchar_t * dst = this->name;
	int i = 0;
	while (i < length)
	{
		*dst++ = *src++;
		i++;
	}
}

quadrilateral & quadrilateral::operator=(quadrilateral const & obj)
{
	//self assignment test
	if (&obj != this)
	{
		CopyMembers(obj);
	}
	return *this;
}

//Move constructor
quadrilateral::quadrilateral(quadrilateral && other)
{
	Move(std::forward<quadrilateral>(other));
}

void quadrilateral::Move(quadrilateral && other)
{
	name = other.name;
	namelength = other.namelength;
	base = other.base;
	height = other.height;

	other.name = nullptr;
	other.namelength = 0;
	other.base = 0;
	other.height = 0;
}

//Move assigment
quadrilateral & quadrilateral::operator=(quadrilateral && other)
{
	if (this != &other)
	{
		Move(std::forward<quadrilateral>(other));
	}
	return *this;
}

quadrilateral::~quadrilateral()
{
	if (name != nullptr)
	{
		delete name;
	}
}

double const quadrilateral::GetBase()
{
	return base;
}

void quadrilateral::SetBase(double const a)
{
	base = a;
}

double const quadrilateral::GetHeight()
{
	return height;
}

void quadrilateral::SetHeight(double const a)
{
	height = a;
}

double const quadrilateral::GetArea()
{
	return height * base;
}

void quadrilateral::SetName(wchar_t const * obj, int const length)
{
	CopyName(obj, length);
}

wchar_t const * quadrilateral::GetName()
{
	return name;
}
