#pragma once
#include "CustomColor.h"

class FileManager
{
public:
	FileManager(int width, int height);
	void CreateFile(const char* fileName, CustomColor** color);
};

