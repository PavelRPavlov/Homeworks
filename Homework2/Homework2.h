#pragma once
#include "CustomColor.h"

void RunCreateImageTask(int imageWidth, int imageHeight, int imageColumns, int imageRows);
void RunCreateSingleShapeTask(int imageWidth, int imageHeight, int circleRadius);
int main();
CustomColor** InitPicture(int imageWidth, int imageHeight);
