#pragma once
#include <iostream>
#include "Edge.h"

#define STATION_NUMBER 625

/*
 클래스 이름 : SubwayStation
 클래스 기능 : 지하철 역의 정보들을 저장한다.
*/
class SubwayStation
{
private:
	std::string stationName;
	
	Edge* next = nullptr;				// 다음 엣지를 가리키는 포인터
	Edge* pre = nullptr;				// 전 엣지를 가리키는 포인터

public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();

	void Setnext(Edge* next);
	void Setpre(Edge* pre);

};

