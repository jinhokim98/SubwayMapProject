#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 ������ : �� �̸� ����
*/
SubwayStation::SubwayStation(string stationName)
{
	this->stationName = stationName;
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
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� ���� ���� ����
*/
void SubwayStation::Setnext(Edge* next)
{
	this->next = next;
}

/*
 �Լ� �̸� : Setpre
 �Լ� ��� : �� ���� ���� ����
*/
void SubwayStation::Setpre(Edge* pre)
{
	this->pre = pre;
}







/*
 
void SubwayStation::SetMatrix(int source, int dest, int distance)
{
	distance_adj[source][dest] = distance;
	distance_adj[dest][source] = distance;
}



void SubwayStation::SetMatrix(int source, int dest, int distance, bool Is_one_way)
{
	if (Is_one_way == true)
		distance_adj[source][dest] = distance;
}

*/