#include <iostream>
#include <math.h>
#include "FileManager.h"
#include "Homework2.h"
#include "CustomColor.h"
#include "RectangleDrawer.h"

using namespace std;

int main()
{
	RunCreateImageTask(1920, 1080, 4, 4);
	RunCreateSingleShapeTask(1920, 1080, 300);

	return 1;
}

void RunCreateSingleShapeTask(int imageWidth, int imageHeight, int circleRadius) {
	int shapeOriginX = imageHeight / 2;
	int shapeOriginY = imageWidth / 2;
	CustomColor backgroundColor = CustomColor(255, 255, 255);
	CustomColor foregroundColor = CustomColor(0, 0, 0);
	auto** bigPicture = InitPicture(imageWidth, imageHeight);
	double sqrCircleRadius = circleRadius * circleRadius;

	for (int x = 0; x < imageHeight; x++)
	{
		for (int y = 0; y < imageWidth; y++)
		{
			double dx = shapeOriginX - x;
			double dy = shapeOriginY - y;

			if (dx*dx + dy*dy <= sqrCircleRadius)
			{
				bigPicture[x][y] = foregroundColor;
			}
			else
			{
				bigPicture[x][y] = backgroundColor;
			}
		}
	}

	auto* fileManager = new FileManager(imageWidth, imageHeight);
	const char* fileName = "ShapePicture.ppm";
	fileManager->CreateFile(fileName, bigPicture);
}

void RunCreateImageTask(int imageWidth, int imageHeight, int imageColumns, int imageRows) {
	int rectangleWidth = imageWidth / imageColumns;
	int rectangleHeight = imageHeight / imageRows;
	auto** bigPicture = InitPicture(imageWidth, imageHeight);
	auto* singleRectangleColorMask = new CustomColor();
	auto* drawer = new RectangleDrawer(bigPicture);
	for (int x = 0; x < imageRows; x++)
	{
		for (int y = 0; y < imageColumns; y++)
		{
			singleRectangleColorMask = CustomColor::GetNextMask(*singleRectangleColorMask);
			drawer->DrawRectangle(
				x * rectangleHeight,
				y * rectangleWidth,
				*singleRectangleColorMask,
				rectangleWidth,
				rectangleHeight);
		}
	}

	auto* fileManager = new FileManager(imageWidth, imageHeight);
	const char* fileName = "BigPicture.ppm";
	fileManager->CreateFile(fileName, bigPicture);
}

CustomColor** InitPicture(int imageWidth, int imageHeight) {

	auto** bigPicture = new CustomColor * [imageHeight];
	for (int x = 0; x < imageHeight; x++)
	{
		bigPicture[x] = new CustomColor[imageWidth];
	}
	return bigPicture;
}