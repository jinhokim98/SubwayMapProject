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
 ���� : ����
 ��ȯ�� : �� �̸�
*/
string SubwayStation::GetSubwayStationName()
{
	return stationName;
}

/*
 �Լ� �̸� : Getedgenum
 �Լ� ��� : �ش翪�� �� �� �ִ� ���� ���� ��ȯ�Ѵ�.
 ���� : ����
 ��ȯ�� : degree
*/
int SubwayStation::Getedgenum()
{
	return edgenum;
}

/*
 �Լ� �̸� : Getnext
 �Լ� ��� : ���� ���� ��ȯ
 ���� : int pointer_num ������ ���� (enum�� ����Ǿ�����)
 ��ȯ�� : �ش� ����
*/
Edge* SubwayStation::Getadj(int pointer_num)
{
	return adj[pointer_num];
}


/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� ���� ���� ����
 ���� : int pointer_num ������ ���� (enum�� ����Ǿ�����)
 ��ȯ�� : ����
*/
void SubwayStation::Setadj(Edge* next, int pointer_num)
{
	this->adj[pointer_num] = next;
}