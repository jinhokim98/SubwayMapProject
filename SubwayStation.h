#pragma once
#include <iostream>

#define STATION_NUMBER 625

enum pointer_name
{
	trans0_next, trans0_pre, trans1_next, trans1_pre, trans2_next, trans2_pre, trans3_next, trans3_pre
};

class Edge;

/*
 클래스 이름 : SubwayStation
 클래스 기능 : 지하철 역의 정보들을 저장한다.
*/
class SubwayStation
{
private:
	std::string stationName;		// 역 이름
	int edgenum;					// 해당역이 갈 수 있는 길의 수
	Edge* adj[8];	// 한 역에 최대 지나가는 호선이 4개임으로 역마다 포인터를 최대 8개 준비한다.

public:
	SubwayStation(std::string stationName, int edgenum);
	std::string GetSubwayStationName();
	int Getedgenum();

	Edge* Getadj(int pointer_num);
	void Setadj(Edge* next, int pointer_num);

};

