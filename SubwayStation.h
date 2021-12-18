#pragma once
#include <iostream>

#define STATION_NUMBER 625
#define INF 9999


/*
 클래스 이름 : SubwayStation
 클래스 기능 : 지하철 역의 정보들을 저장한다.
*/
class SubwayStation
{
private:
	std::string stationName;
	int distance_adj[STATION_NUMBER][STATION_NUMBER];	// 지하철역 인접행렬


public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();
	void SetMatrix(int source, int dest, int distance);
	void SetMatrix(int source, int dest, int distance, bool Is_one_way);

	SubwayStation* Getnext();

};

