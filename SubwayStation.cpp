#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 ������ : �Ű����������� ������ ����.
*/
SubwayStation::SubwayStation(string linenum, string stationName, int distance)
{
	this->linenum = linenum;
	this->stationName = stationName;
	this->distance = distance;
}

/*
 �Լ� �̸� : GetSubwayLine
 �Լ� ��� : ȣ����ȣ ��ȯ
*/
string SubwayStation::GetSubwayLine()
{
	return linenum;
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
 �Լ� �̸� : Getdistance
 �Լ� ��� : �� �� �Ÿ� ��ȯ
*/
int SubwayStation::Getdistance()
{
	return distance;
}

/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� �� ����
*/
void SubwayStation::Setnext(SubwayStation* next)
{
	if (next == nullptr)
	{
		this->next = nullptr;
	}

	this->next = next;
}

/*
 �Լ� �̸� : Setpre
 �Լ� ��� : �� �� ����
*/
void SubwayStation::Setpre(SubwayStation* pre)
{
	if (pre == nullptr)
	{
		this->pre = nullptr;
	}

	this->pre = pre;
}

/*
 �Ҹ��� : ������ �ݴ´�.
*/
SubwayStation::~SubwayStation()
{
	
}