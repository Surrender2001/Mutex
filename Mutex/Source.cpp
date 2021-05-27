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
	srand(time(nullptr));
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
	vector<Cocoroach>v1 = { c1,c2,c3 };
	vector<Cocoroach>v2 = { c4,c5,c6 };
	Race r1(1,v1);
	Race r2(2,v2);


	r1.getThreadReference()->join();
	r2.getThreadReference()->join();
	
	return 0;
}