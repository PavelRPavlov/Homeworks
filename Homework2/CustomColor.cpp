#include "CustomColor.h"

CustomColor::CustomColor() : CustomColor(0, 0, 0) {};

CustomColor::CustomColor(int r, int g, int b) {
		R = r;
		G = g;
		B = b;
	};

int CustomColor::ToInt(CustomColor color) {
	int result = 0;
	if (color.B > 0)
	{
		result = result + 1;
	}
	if (color.G > 0)
	{
		result = result + 2;
	}
	if (color.R > 0)
	{
		result = result + 4;
	}
	return result;
}

CustomColor* CustomColor::ToColor(int color) {
	CustomColor* result = new CustomColor();
	result->R = (color >> 2) & 1;
	result->G = (color >> 1) & 1;
	result->B = color & 1;
	return result;
}

CustomColor* CustomColor::GetNextMask(CustomColor currentMask) {
	int color = ToInt(currentMask);
	color += 1;
	if (color > 7)
	{
		color = 1;
	}
	auto returnColor = ToColor(color);
	return returnColor;
}