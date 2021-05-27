#pragma once
#include<iostream>
#include<mutex>
#include<thread>
#include<vector>
#include<algorithm>
#include"Cocoroach.h"
using namespace std;
using namespace chrono;
class Race
{
private:

public:
	int id;
	static mutex mtx; // служебный мутекс, для красивого вывода на консоль из разных потоков
	vector<Cocoroach> Vec;
	Race(int);
	void AddInRace(Cocoroach c1);
	static void Start(Race&);
};

