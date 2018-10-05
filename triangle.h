#pragma once
#include "figures.h"

//using namespace std;

class triangle :public figures
{
public:
	triangle();
	triangle(point vert[]);
	~triangle();
	bool isRightTriangle(); //�������������
	bool isIsoscelesTriange(); //��������������
	bool isEquilateral(); //��������������
	double area();
	void formEdges();
};


void triangle::formEdges()
{
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[0]);
}

triangle::triangle()
{
	n = 3;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(i + time(NULL));
		v[i].x = rand() % 10;
		srand(time(NULL) + i + 10);
		v[i].y = rand() % 10;
	}
	formEdges();
}

triangle::triangle(point vert[])
{
	n = 3;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		v[i] = vert[i];
	}
	formEdges();
}

bool triangle::isRightTriangle()
{
	if (TriangleInequality())
	{
		if (isRightAngle(v[0], v[1], v[2])) return true;
		else if (isRightAngle(v[2], v[0], v[1])) return true;
		else if (isRightAngle(v[1], v[2], v[0])) return true;
	}
	return false;
}

bool triangle::isIsoscelesTriange()
{
	if (TriangleInequality())
	{
		if (abs(e[0] - e[1]) <= eps || abs(e[0] - e[2]) <= eps || abs(e[1] - e[2]) <= eps) return true;
	}
	return false;
}

bool triangle::isEquilateral()
{
	if (TriangleInequality() && abs(e[0] - e[1]) <= eps && abs(e[0] - e[2]) <= eps) return true;
	return false;
}

double triangle::area()
{
	double p = perimeter() / 2;
	return sqrt(p*(p - e[0]) * (p - e[1]) * (p - e[2]));
}

triangle::~triangle()
{
	delete[]e;
	delete[]v;
}
