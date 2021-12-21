#include <iostream>
#include "SubwayMapManagement.h"

#define INF 9999

using namespace std;

/*
 생성자 : metro 객체를 동적생성하고 지하철 노선도를 만든다.
*/
SubwayMapManagement::SubwayMapManagement()
{
	metro = new MakeGraph;
	metro->init();

	transfer = 0;

	for (int i = 0; i < STATION_NUMBER; i++)
	{
		for (int j = 0; j < STATION_NUMBER; j++)
		{
			distance_adj[i][j] = INF;
		}
	}
}

void SubwayMapManagement::print_degree()
{
	Edge** pedge = metro->GetEdgePointer();
	SubwayStation** psub = metro->GetSubwayPointer();

	metro->Getdegree(psub, pedge);
}

void SubwayMapManagement::print_map()
{
	SubwayStation* p = metro->GetStation("문산");
	Edge* q = nullptr;

	while (p->GetSubwayStationName() != "지평")
	{
		cout << p->GetSubwayStationName() << ", ";

		q = p->Getadj(trans0_next);
		
		if (q == nullptr)
			break;

		cout << q->GetSubwayLine() << ", ";
		cout << q->Getdistance() << ", " << endl;

		p = q->Getnext();
	}
}
/*
 소멸자 : 동적생성한 metro 객체를 지운다.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
