#pragma once
#include <iostream>

#define STATION_NUMBER 624

class Edge;

/*
 클래스 이름 : SubwayStation
 클래스 기능 : 지하철 역의 정보들을 저장한다.
*/
class SubwayStation
{
private:
	std::string stationName;
	
	// 한 역에 최대 지나가는 호선이 4개임으로 역마다 포인터를 최대 8개 준비한다.

	Edge* next = nullptr;				// 다음 엣지를 가리키는 포인터
	Edge* pre = nullptr;				// 전 엣지를 가리키는 포인터

	Edge* trans1_next = nullptr;		// 환승역일 때 다른 호선의 다음 엣지
	Edge* trans1_pre = nullptr;			// 환승역일 때 다른 호선의 전 엣지

	Edge* trans2_next = nullptr;		// 환승역일 때 또 다른 호선의 다음 엣지
	Edge* trans2_pre = nullptr;			// 환승역일 때 또 다른 호선의 전 엣지
	
	Edge* trans3_next = nullptr;		// 환승역일 때 또 다른 호선의 다음 엣지
	Edge* trans3_pre = nullptr;			// 환승역일 때 또 다른 호선의 전 엣지

public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();

	Edge* Getnext();
	Edge* Getpre();
	void Setnext(Edge* next);
	void Setpre(Edge* pre);

};

