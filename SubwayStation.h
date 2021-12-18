#pragma once
#include <iostream>
#include "Edge.h"

#define STATION_NUMBER 625

/*
 Ŭ���� �̸� : SubwayStation
 Ŭ���� ��� : ����ö ���� �������� �����Ѵ�.
*/
class SubwayStation
{
private:
	std::string stationName;
	
	Edge* next = nullptr;				// ���� ������ ����Ű�� ������
	Edge* pre = nullptr;				// �� ������ ����Ű�� ������

public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();

	void Setnext(Edge* next);
	void Setpre(Edge* pre);

};

