#include <iostream>
#include "FileManager.h"
#include "Homework2.h"
#include "CustomColor.h"
#include "RectangleDrawer.h"

using namespace std;

int main()
{
	RunCreateImageTask();
	RunCreateSingleShapeTask();

	return 1;
}

void RunCreateSingleShapeTask() {
	// TODO implement second task from homework #2
}

void RunCreateImageTask() {
	int imageWidth = 1920;
	int imageHeight = 1080;
	int imageColumns = 4;
	int imageRows = 4;
	int rectangleWidth = imageWidth / imageColumns;
	int rectangleHeight = imageHeight / imageRows;
	auto** bigPicture = new CustomColor * [imageHeight];
	auto* singleRectangleColorMask = new CustomColor();
	auto* drawer = new RectangleDrawer(bigPicture);

	for (int x = 0; x < imageHeight; x++)
	{
		bigPicture[x] = new CustomColor[imageWidth];
	}
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