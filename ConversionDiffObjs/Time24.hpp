//
//  Time24.hpp
//  MasterC++
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

#ifndef Time24_h
#define Time24_h

class Time12; // forward declaration

class Time24
{
private:
	int h;
	int m;
	int s;
public:
	Time24():h(0), m(0), s(0)
	{
	}
	Time24(int hour, int minute, int second): h(hour), m(minute), s(second)
	{
	}
	void show_time()
	{
		std::cout << h << ":" << m << ":" << s << std::endl;
	}
	int get_hours()
	{
		return h;
	}
	int get_minutes()
	{
		return m;
	}
	int get_seconds()
	{
		return s;
	}

#ifndef USE_METHOD_2
	operator Time12();
#endif
};

#endif /* Time24_h */
