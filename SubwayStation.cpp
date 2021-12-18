#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 ������ : �Ű����������� ������ ����.
		  �Ÿ������ ���� 9999�� ���� (���ͽ�Ʈ�� �˰����� �ʱ�ȭ ����)
*/
SubwayStation::SubwayStation(string stationName)
{
	
	this->stationName = stationName;

	int i, j = 0;

	for (i = 0; i < STATION_NUMBER; i++)
	{
		for (j = 0; j < STATION_NUMBER; j++)
		{
			distance_adj[i][j] = INF;
		}
	}
}


/*
 �Լ� �̸� : GetSubwayStationName
 �Լ� ��� : �� �̸� ��ȯ
*/
string SubwayStation::GetSubwayStationName()
{
	return stationName;
}

/*
 �Լ� �̸� : SetMatrix
 �Լ� ��� : �� �� �Ÿ��� ��Ŀ� ���
*/
void SubwayStation::SetMatrix(int source, int dest, int distance)
{
	distance_adj[source][dest] = distance;
	distance_adj[dest][source] = distance;
}


/*
 �Լ� �̸� : SetMatrix (�ܹ���)
 �Լ� ��� : �ܹ����� �� �� �� �Ÿ��� ��Ŀ� ���
*/
void SubwayStation::SetMatrix(int source, int dest, int distance, bool Is_one_way)
{
	if (Is_one_way == true)
		distance_adj[source][dest] = distance;
}

SubwayStation* SubwayStation::Getnext()
{

}