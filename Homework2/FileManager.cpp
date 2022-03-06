#include "FileManager.h"
#include "CustomColor.h"
#include <fstream>

static const int maxColorComponent = 255;

int imageWidth;
int imageHeight;

using namespace std;

FileManager::FileManager(int width, int height) {
	imageWidth = width;
	imageHeight = height;
}

void FileManager::CreateFile(const char* fileName, CustomColor** color)
{
	ofstream ppmFileStream(fileName, ios::out | ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			CustomColor colorToPrint = color[rowIdx][colIdx];
			ppmFileStream << colorToPrint.R << " " << colorToPrint.G << " " << colorToPrint.B << "\t";
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();
}
