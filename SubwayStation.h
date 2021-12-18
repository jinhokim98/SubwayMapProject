#pragma once
#include <iostream>

#define STATION_NUMBER 625
#define INF 9999


/*
 Ŭ���� �̸� : SubwayStation
 Ŭ���� ��� : ����ö ���� �������� �����Ѵ�.
*/
class SubwayStation
{
private:
	std::string stationName;
	int distance_adj[STATION_NUMBER][STATION_NUMBER];	// ����ö�� �������


public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();
	void SetMatrix(int source, int dest, int distance);
	void SetMatrix(int source, int dest, int distance, bool Is_one_way);

	SubwayStation* Getnext();

};

