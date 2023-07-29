//
//  main.cpp
//  circles
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
// circles.cpp
// circles as graphics objects
//#include "msoftcon.h"         // for graphics functions
////////////////////////////////////////////////////////////////

/* Purpose of this program:
 - To show that how physical objects like circle can be implemented in c++.
*/

class circle
{
private:
	int xCo, yCo;
	int radius;
	//color fillcolor;
	//fstyle fillstyle;
public:
	void set(int x, int y, int r/*, color fc, fstyle fs*/)
	{
		xCo = x;
		yCo = y;
		radius = r;
		//fillcolor = fc;
		//fillstyle = fs;
	}
	void draw() {
		//draws the circle
		//set_color(fillcolor);
		//set_fill_style(fillstyle);
		//draw_circle(xCo, yCo, radius);
		std::cout << "sorry no graphics support yet" << std::endl;
	}
	//set color
	//set fill
	//draw solid circle
};

int main()
{
	circle c1;
	circle c2;
	circle c3;
	//initialize graphics system
	//create circles
	//set circle attributes
	c1.set(15, 7, 5 /*,cBLUE, X_FILL*/);
	c2.set(41, 12, 7 /*, cRED, O_FILL*/);
	c3.set(65, 18, 4 /*, cGREEN, MEDIUM_FILL*/);

	c1.draw();

	return 0;
}