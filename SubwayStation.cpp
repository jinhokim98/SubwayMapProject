#include <iostream>
#include "SubwayStation.h"
#include "Edge.h"

using namespace std;

/*
 ������ : �� �̸��� �ʿ��� ������ ���� �����ϰ�
		  �� �����͸� ��� null�� �ʱ�ȭ�Ѵ�.
*/
SubwayStation::SubwayStation(string stationName, int edgenum)
{
	this->stationName = stationName;
	this->edgenum = edgenum;

	for (int i = trans0_next; i <= trans3_pre; i++)
	{
		adj[i] = nullptr;
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
 �Լ� �̸� : Getedgenum
 �Լ� ��� : �ش翪�� �� �� �ִ� ���� ���� ��ȯ�Ѵ�.
*/
int SubwayStation::Getedgenum()
{
	return edgenum;
}

/*
 �Լ� �̸� : Getnext
 �Լ� ��� : ���� ���� ��ȯ
*/
Edge* SubwayStation::Getadj(int pointer_num)
{
	return adj[pointer_num];
}


/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� ���� ���� ����
*/
void SubwayStation::Setadj(Edge* next, int pointer_num)
{
	this->adj[pointer_num] = next;
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