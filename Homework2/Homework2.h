#pragma once
#include "CustomColor.h"
int main();
CustomColor** CreateSingleRectangle(CustomColor& colorMask, int rectangleWidth, int rectangleHeight);
void DrawRectangle(int originX, int originY, CustomColor** colorRectangle, int width, int height);
