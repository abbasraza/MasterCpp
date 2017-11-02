//
//  Time12.hpp
//  MasterC++
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

#ifndef Time12_h
#define Time12_h

class Time24; // forward declaration

class Time12
{
private:
	int h;
	int m;
	int s;
	bool before_noon;
public:
	Time12(): h(0), m(0), s(0), before_noon(true)
	{
	}
	Time12(int hour, int minute, int second, bool am): h(hour), m(minute), s(second), before_noon(am)
	{
	}
	void show_time()
	{
		std::cout << h << ":" << m << ":" << s << " " << (before_noon ? "AM" : "PM") << std::endl;
	}
#ifdef USE_METHOD_2
	Time12(Time24 t);
#endif
};


#endif /* Time12_h */
