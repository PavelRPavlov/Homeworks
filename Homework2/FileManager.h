#pragma once
#include "CustomColor.h"

class FileManager
{
public:
	static const int MaxColorComponent = 255;
	FileManager(int width, int height);
	void CreateFile(const char* fileName, CustomColor** color);
};

