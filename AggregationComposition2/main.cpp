//
//  main.cpp
//  AggregationComposition
//
//  Created by abbas raza on 6/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of composition/aggregation along with inheritance.

	                --------
    -------------> | Device | <------------
   |                --------               |
   |                   ^                   |
   |                   |                   |
   |                   |                   |
 --------           ---------          ------------
| Camera |         | Display |-------⬥| SmartPhone |
 --------           ---------          ------------
    |                                       ⬥
    |                                       |
     ---------------------------------------

 - Aggregation: has a
   Composition: consists of
   Inheritance: is kind of
 
 - Inheritance:
   Camera is kind of device
   Display is kind of device
   SmartPhone is kind of device
 
 - Composition/Aggregation:
   SmartPhone (has a) / (consists of) a Camera.
   SmartPhone (has a) / (consists of) a Display.
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
		std::cout << "Model: " << model << " Manufactured By: " << manufacturer << std::endl;
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

class SmartPhone : public Device
{
private:
	std::string os;
	Camera cam;
	Display dis;
public:
	SmartPhone(std::string o = "Android", int mod = 6, std::string man = "Google",
			   int display_m = 13449, std::string display_man = "ABCD",
			   int camera_m = 12344, std::string camera_man = "EFGH") : os(o), Device(mod, man), dis(display_m, display_man), cam(camera_m, camera_man)
	{
	}
	void show_device_data()
	{
		std::cout << "Operating System: " << os << std::endl;
		Device::show_device_data(); // Base class (Device) of SmartPhone's function called. No conflict with Camera/Display
		                            // because of single inheritance.
		cam.show_device_data();
		dis.show_device_data();
		//cam.Device::print_nothing();
	}
	void take_picture_and_display()
	{
		cam.take_picture();
		dis.display_picture();
	}
};

int main(int argc, const char * argv[])
{
	SmartPhone p;

	p.show_device_data();
	p.take_picture_and_display();

	return 0;
}