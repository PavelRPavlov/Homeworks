#pragma once
class CustomColor
{
	public:
		int R;
		int G;
		int B;
		CustomColor();
		CustomColor(int r, int g, int b);
		static int ToInt(CustomColor color);
		static CustomColor* ToColor(int color);
		static CustomColor* GetNextMask(CustomColor currentMask);
};

