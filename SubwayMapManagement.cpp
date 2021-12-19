#include <iostream>
#include "SubwayMapManagement.h"

#define INF 9999

using namespace std;

/*
 ������ : metro ��ü�� ���������ϰ� ����ö �뼱���� �����.
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

void SubwayMapManagement::print_Map()
{
	SubwayStation* p = metro->GetStation("�ҿ��");
	Edge* q = nullptr;


	while (!p)
	{
		cout << p->GetSubwayStationName() << ", ";

		q = p->Getnext();
		cout << q->GetSubwayLine() << ", ";
		cout << q->Getdistance() << ", ";

		p = q->Getnext();
	}
}
/*
 �Ҹ��� : ���������� metro ��ü�� �����.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
