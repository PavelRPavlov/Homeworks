#include "RectangleDrawer.h"
#include "CustomColor.h"
#include "FileManager.h"
#include <stdlib.h>

CustomColor** bigPicture;

RectangleDrawer::RectangleDrawer(CustomColor** picture) {
	bigPicture = picture;
}

void RectangleDrawer::DrawRectangle(int originX, int originY, CustomColor& colorMask, int width, int height) {
	int rectangleX = 0;
	int rectangleY = 0;
	auto colorRectangle = CreateSingleRectangle(colorMask, width, height);

	for (int x = originX; x < height + originX; x++)
	{
		for (int y = originY; y < width + originY; y++)
		{
			bigPicture[x][y] = colorRectangle[rectangleX][rectangleY];
			rectangleY++;
		}
		rectangleY = 0;
		rectangleX++;
	}
}

CustomColor** RectangleDrawer::CreateSingleRectangle(CustomColor& colorMask, int rectangleWidth, int rectangleHeight) {

	auto** result = new CustomColor * [rectangleHeight];

	for (int x = 0; x < rectangleHeight; x++)
	{
		result[x] = new CustomColor[rectangleWidth];
		for (int y = 0; y < rectangleWidth; y++)
		{
			unsigned char r = rand() % FileManager::MaxColorComponent * colorMask.R;
			unsigned char g = rand() % FileManager::MaxColorComponent * colorMask.G;
			unsigned char b = rand() % FileManager::MaxColorComponent * colorMask.B;
			result[x][y] = CustomColor(r, g, b);
		}
	}
	return result;
}