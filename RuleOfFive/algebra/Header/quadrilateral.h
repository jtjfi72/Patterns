#pragma once

class quadrilateral
{
private:
	double base;
	double height;
	wchar_t * name;
	int namelength;

	void CopyMembers( quadrilateral const & obj);

	void CopyName(wchar_t const * name, int const length);

public:

	//default
	quadrilateral();
	//Copy
	quadrilateral(quadrilateral const &obj);
	quadrilateral & operator = (quadrilateral const & t);
	//Move
	quadrilateral(quadrilateral &&obj);
	void Move(quadrilateral && other);
	quadrilateral & operator = (quadrilateral && t);
	//Destructor
	~quadrilateral();

	double const GetBase();
	void SetBase(double const a);
	double const GetHeight();
	void SetHeight(double const a);
	double const GetArea();
	void SetName(wchar_t const * name, int const length);
	wchar_t const * GetName();
};

