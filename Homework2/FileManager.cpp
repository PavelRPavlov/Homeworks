#include "FileManager.h"
#include "CustomColor.h"
#include <fstream>

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
	ppmFileStream << MaxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			auto colorToPrint = color[rowIdx][colIdx];
			ppmFileStream << colorToPrint.R << " " << colorToPrint.G << " " << colorToPrint.B << "\t";
		}
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
}
