#pragma once
class Color
{
public:
	Color();
	Color(float r, float g, float b, float a);
	Color(float r, float g, float b);
	~Color();

	float R;
	float G;
	float B;
	float A;
};

