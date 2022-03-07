#pragma once
#include "CustomColor.h"

void RunCreateImageTask();
void RunCreateSingleShapeTask();
int main();
CustomColor** CreateSingleRectangle(CustomColor& colorMask, int rectangleWidth, int rectangleHeight);
void DrawRectangle(int originX, int originY, CustomColor** colorRectangle, int width, int height);
