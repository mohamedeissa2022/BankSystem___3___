#pragma once
#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;
class clsScreenTheme
{
public:


	enum enScreenBackgraundColor { __black = 0, __white = 7, __red = 4, __blue = 1 , __Yellow=7, __Gray=8, __Purple=5, __Aqua=3, __LightBlue=9};
	enum enScreenTextColor { ___black = 0, ___white = 7, ___red = 4, ___blue = 1, ___Yellow = 7, ___Gray = 8, ___Purple = 5, ___Aqua = 3, ___LightBlue = 9};

	void setScreenThemeColor(enScreenBackgraundColor bgColor, enScreenTextColor txColor) {
		//string themeColor= to_string(bgColor).at(0) + to_string(txColor);
		char co[10] = { "Color "};
		co[6] = to_string(bgColor).at(0);
		co[7] = to_string(txColor).at(0);
		system(co);

	}
	void restThemeColor() {
		system("Color 07");
	}
};	
																								
											