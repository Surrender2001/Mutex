#include "Race.h"

Race::Race(int id)
{
    this->id = id;
}

Race::Race(int id, vector<Cocoroach>vec):Race(id)
{
    Vec.swap(vec);
    Thread = thread(Start, ref(*this));
}

void Race::AddInRace(Cocoroach c1)
{
	Vec.push_back(c1);
}

mutex Race::mtx;

void Race::Start(Race& race)
{
    srand(time(nullptr));
    
    clock_t t0 = clock();
    vector<int> vec(race.Vec.size());
    vector<int>done(race.Vec.size());
    for (auto elem : vec)
        elem = 0;
    for (auto elem : done)
        elem = 0;
    int distance = 0, i = 0, place = 1, count_done = 0;

    
    while (!vec.empty())
    {
        
        for (int i = 0; i < vec.size();++i)
        {
            
            this_thread::sleep_for(seconds(rand() %  3 + 1));
            distance = rand() % 50 + 10;
            
            if (vec[i] < 100)
            {
                
                mtx.lock();
                cout <<"Race: "<<race.id << "\tCockroach " << race.Vec[i].Id << "\tdistance: " << vec[i] << "/100" << endl;
                mtx.unlock();
                vec[i] += distance;
            }
            else
            {
                
                done[i] == 1;
                clock_t t1 = clock();
                mtx.lock();
                cout << "Race: " << race.id << "\tCockroach " << race.Vec[i].Id << "\tdistance: 100/100\t time: "<< (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
                mtx.unlock();
                vec.erase(vec.begin() + i);
                
                
            }
        }
    

        
    }
    
}

thread* Race::getThreadReference()
{
    return &Thread;
}



