#pragma once
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
using namespace chrono;

class Cocoroach
{
private:

public:
	int Id;
	milliseconds Time;
	Cocoroach();
	Cocoroach(int);

};

