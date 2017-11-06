//
//  main.cpp
//  MultipleInheritance1
//
//  Created by abbas raza on 5/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Multiple inheritance fail/not a solution ?
 
 - Camera is kind of Device --> true
   Display is kind of Device --> true
   SmartPhone is kind of Camera --> not really true?
   SmartPhone is kind of Display --> not really true?
   SmartPhone is kind of Device --> true

 - Lots of ambiguity
 
             ---------------------
            |                     |
		    V                     |
	    --------                  |
   --> | Device | <----           |
  |     --------       |          |
  |                    |          |
  |                    |          |
 --------           ---------     |
| Camera |         | Display |    |
 --------           ---------     |
  ^                      ^        |
  |                      |        |
  |                      |        |
  |     ------------     |        |
   --- | SmartPhone | ---         |
	    ------------              |
            |                     |
             ---------------------
 
*/

#include <iostream>

class Device
{
private:
	int model;
	std::string manufacturer;
public:
	Device(int mod = 0, std::string man = "") : model(mod), manufacturer(man)
	{
	}
	void show_device_data()
	{
		std::cout << "Model: " << model << " Manufactured By: " << manufacturer << std::endl;
	}
	void print_nothing()
	{
	}
};

class Camera : public Device
{
private:
	int mp;
	bool flash;
public:
	Camera(int mod = 0, std::string man = "", int pix = 4, bool f = false) : Device(mod, man), mp(pix), flash(f)
	{
	}
	void take_picture()
	{
		std::cout << "Taking picture..." << std::endl;
	}
	void show_device_data()
	{
		std::cout << "Camera specs: " << std::endl;
		Device::show_device_data();
		std::cout << "Mega Pixel: " << mp << " Flash support: " << (flash ? "YES" : "NO") << std::endl;
	}
};

class Display : public Device
{
private:
	int size_inch;
	int ppi;
	bool touch;
public:
	Display(int mod = 0, std::string man = "", int s = 4, int p = 380, bool t = false) : Device(mod, man), size_inch(s), ppi(p), touch(t)
	{
	}
	void display_picture()
	{
		std::cout << "Displaying picture" << std::endl;
	}
	void show_device_data()
	{
		std::cout << "Display specs: " << std::endl;
		Device::show_device_data();
		std::cout << "Screen Size(inches): " << size_inch << " ppi: " << ppi << " Touch supported: " << (touch ? "YES" : "NO") << std::endl;
	}
};

class SmartPhone : public Device, public Display, public Camera // why can't inherit Device here. lots of ambigiuty
{
private:
	std::string os;
public:
	SmartPhone(std::string o = "Android", int mod = 6, std::string man = "Google",
			   int display_m = 13449, std::string display_man = "ABCD",
			   int camera_m = 12344, std::string camera_man = "EFGH") : os(o), Device(mod, man), Display(display_m, display_man), Camera(camera_m, camera_man)
	{
	}
	void show_device_data()
	{
		std::cout << "Operating System: " << os << std::endl;
		Device::show_device_data(); // we have 3 copies of Deivce now ??? which one do we mean??
		Display::show_device_data();
		Camera::show_device_data();
	}
	void take_picture_and_display()
	{
		Camera::take_picture();
		Display::display_picture();
	}
};

int main(int argc, const char * argv[])
{
	SmartPhone p;
	//p.Camera::show_device_data();
	p.show_device_data();
	p.take_picture_and_display();
	return 0;
}