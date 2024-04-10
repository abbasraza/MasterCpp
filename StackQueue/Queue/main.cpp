//
//  main.cpp
//  Queue
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Implement queue class.
 - TODO needs improvements.
*/

#include <iostream>

class Queue
{
private:
	static const int max = 10;
	int q[max];
	int end;
public:
	Queue():end(0), q{}
	{

	}
	void enqueue(int v)
	{
		if (end == max)
		{
			std::cout << "Q Full" << std::endl;
		}
		else if (end < max)
		{
			q[end++] = v;
		}
	}
	int dequeue()
	{
		if (end)
		{
			int temp = q[0];
			for (int i = 0; i < end - 1; ++i)
			{
				q[i] = q[i + 1];
			}
			end--;
			return temp;
		}
		return -1;
	}
	void show()
	{
		std::cout << "Queue: ";
		if (end == 0)
		{
			std::cout << "Empty";
		}
		else
		{
			for (int i = 0; i < end; ++i)
			{
				std::cout << q[i] << " ";
			}
		}
		std::cout << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	Queue q1;
	q1.enqueue(0);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.enqueue(11);
	q1.enqueue(11);
	q1.enqueue(11);
	q1.enqueue(11);

	q1.show();
	
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;

	q1.show();
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;
	q1.show();

	std::cout << q1.dequeue() << std::endl;
	std::cout << q1.dequeue() << std::endl;

	q1.show();
	q1.show();
	q1.enqueue(10);
	q1.enqueue(11);
	q1.enqueue(12);
	q1.enqueue(13);
	q1.enqueue(14);
	q1.show();

    return 0;
}
