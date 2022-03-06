#include <iostream>
#include "FileManager.h"
#include "Homework2.h"
#include "CustomColor.h"

using namespace std;
CustomColor** bigPicture;

int main()
{
	int imageWidth = 1920;
	int imageHeight = 1080;
	int imageColumns = 4;
	int imageRows = 4;

	int rectangleWidth = imageWidth / imageColumns;
	int rectangleHeight = imageHeight / imageRows;

	bigPicture = new CustomColor * [imageHeight];
	for (int x = 0; x < imageHeight; x++)
	{
		bigPicture[x] = new CustomColor[imageWidth];
	}
	auto *mask = new CustomColor();
	for (int x = 0; x < imageRows; x++)
	{
		for (int y = 0; y < imageColumns; y++)
		{
			mask = CustomColor::GetNextMask(*mask);
			DrawRectangle(
				x * rectangleHeight,
				y * rectangleWidth,
				CreateSingleRectangle(
					*mask,
					rectangleWidth,
					rectangleHeight),
				rectangleWidth,
				rectangleHeight);
		}
	}

	FileManager* fileManager = new FileManager(imageWidth, imageHeight);
	const char* fileName = "output-file.ppm";
	fileManager->CreateFile(fileName, bigPicture);

	return 1;
}

void DrawRectangle(int originX, int originY, CustomColor** colorRectangle, int width, int height) {
	int i = 0;
	int j = 0;
	for (int x = originX; x < height + originX; x++)
	{
		for (int y = originY; y < width + originY; y++)
		{
			bigPicture[x][y] = colorRectangle[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

CustomColor** CreateSingleRectangle(CustomColor& colorMask, int rectangleWidth, int rectangleHeight) {

	CustomColor** result = new CustomColor * [rectangleHeight];

	for (int x = 0; x < rectangleHeight; x++)
	{
		result[x] = new CustomColor[rectangleWidth];
		for (int y = 0; y < rectangleWidth; y++)
		{
			unsigned char r = rand() % 255 * colorMask.R;
			unsigned char g = rand() % 255 * colorMask.G;
			unsigned char b = rand() % 255 * colorMask.B;
			result[x][y] = CustomColor(r, g, b);
		}
	}

	return result;
}
