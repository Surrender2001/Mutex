#include<iostream>
#include<mutex>
#include<thread>
#include<ctime>
#include<vector>
#include<algorithm>
#include"Cocoroach.h"
#include"Race.h"

using namespace std;
using namespace chrono;

int main()
{
	thread t1, t2,t3;

	Cocoroach c1(1);
	Cocoroach c2(2);
	Cocoroach c3(3);
	Cocoroach c4(4);
	Cocoroach c5(5);
	Cocoroach c6(6);
	Cocoroach c7(7);
	Cocoroach c8(8);
	Cocoroach c9(9);
	Cocoroach c10(10);

	Race r1(1);
	r1.AddInRace(c1);
	r1.AddInRace(c2);
	r1.AddInRace(c3);


	Race r2(2);
	r2.AddInRace(c4);
	r2.AddInRace(c5);
	r1.AddInRace(c6);


	Race r3(3);
	r2.AddInRace(c7);
	r1.AddInRace(c8);
	r1.AddInRace(c9);

	t1 = thread(Race::Start, ref(r1));
	t2 = thread(Race::Start, ref(r2));
	//t3 = thread(Race::Start, ref(r3));


	t1.join();
	t2.join();

	return 0;
}