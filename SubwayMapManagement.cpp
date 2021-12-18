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

/*
 �Ҹ��� : ���������� metro ��ü�� �����.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
