// horse.cpp
// models a horse race
//#include "msoftcon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int CPF = 5;
const int maxHorses = 7;
class track;
////////////////////////////////////////////////////////////////
class horse
{
private:
	const track* ptrTrack;        //pointer to track
	const int horse_number;       //this horse’s number
	float finish_time;
	float distance_run;
public:
	horse(const int n, const track* ptrT) : horse_number(n), ptrTrack(ptrT), distance_run(0.0)
	{
	}
	~horse()
	{
		/*empty*/
	}
	void display_horse(const float elapsed_time);
};

////////////////////////////////////////////////////////////////
class track
{
private:
	horse* hArray[maxHorses];
	int total_horses;
	int horse_count;
	const float track_length;
	float elapsed_time;
public:
	track(float lenT, int nH);
	~track();
	void display_track();
	void run();
	float get_track_len() const;  //return total track length
};  //end class track

//---------------------------------------------------------------
void horse::display_horse(float elapsed_time) //for each horse
{                                //display horse & number
	set_cursor_pos( 1 + int(distance_run * CPF),
				   2 + horse_number*2 );
	//horse 0 is blue
	set_color(static_cast<color>(cBLUE+horse_number));
	//draw horse
	char horse_char = '0' + static_cast<char>(horse_number);
	putch(' ');
	putch('\xDB');
	putch(horse_char);
	putch('\xDB');
	//until finish,
	if( distance_run < ptrTrack->get_track_len() + 1.0 / CPF )
	{
		if( rand() % 3 )
   distance_run += 0.2F;
		finish_time = elapsed_time;
	}
	else
	{                             //display finish time
		int mins = int(finish_time)/60;
		int secs = int(finish_time) - mins*60;
		std::cout << " Time=" << mins << ":" << secs;
	}
}  //end display_horse()
//---------------------------------------------------------------

track::track(float lenT, int nH) : track_length(lenT), total_horses(nH), horse_count(0), elapsed_time(0.0)
{
	init_graphics();           //start graphics
	total_horses = (total_horses > maxHorses) ? maxHorses : total_horses;
	for(int j=0; j<total_horses; j++)   //make each horse
		hArray[j] = new horse(horse_count++, this);
	time_t aTime;              //initialize random numbers
	srand( static_cast<unsigned>(time(&aTime)) );
	display_track();
}  //end track constructor

//---------------------------------------------------------------
track::~track()                     //track destructor
{
	for(int j=0; j<total_horses; j++) //delete each horse
		delete hArray[j];
}

//---------------------------------------------------------------
void track::display_track()
{
	clear_screen();                  //clear screen
	//display track
	for(int f=0; f<=track_length; f++)    //for each furlong
		for(int r=1; r<=total_horses*2 + 1; r++) //and screen row
		{
			set_cursor_pos(f*CPF + 5, r);
			if(f==0 || f==track_length)
				std::cout << '\xDE';
			else
				std::cout << '\xB3';
		}
}  //end display_track()
//draw start or finish line
//draw furlong marker

//---------------------------------------------------------------
void track::run()
{
	while( !kbhit() )
	{
		elapsed_time += 1.75;
		//update time
		//update each horse
		for(int j=0; j<total_horses; j++)
			hArray[j]->display_horse(elapsed_time);
		wait(500);
	}
	getch();                         //eat the keystroke
	std::cout << std::endl;
}

//---------------------------------------------------------------
float track::get_track_len() const
{
	return track_length;
}

/////////////////////////////////////////////////////////////////
int main()
{
	float length;
	int total;
	//get data from user
	std::cout << "\nEnter track length (furlongs; 1 to 12): ";
	std::cin >> length;
	std::cout << "\nEnter number of horses (1 to 7): ";
	std::cin >> total;
	track theTrack(length, total);
	theTrack.run();
	return 0;
}  //end main()