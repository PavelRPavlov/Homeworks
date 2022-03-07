#pragma once
#include "CustomColor.h"

class RectangleDrawer
{
	public:
		RectangleDrawer(CustomColor** bigPicture);
		void DrawRectangle(int originX, int originY, CustomColor& colorMask, int width, int height);
	private:
		CustomColor** CreateSingleRectangle(CustomColor& colorMask, int rectangleWidth, int rectangleHeight);
};

