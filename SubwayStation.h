#pragma once
#include <iostream>

#define STATION_NUMBER 625

/*
 클래스 이름 : SubwayStation
 클래스 기능 : 지하철 역의 정보들을 저장한다.
*/
class SubwayStation
{
private:
	std::string linenum;			// 호선
	std::string stationName;		// 역 이름
	int distance;					// 거리 
	SubwayStation* next = nullptr;	// 다음 역(초기값 null)
	SubwayStation* pre = nullptr;	// 전 역  (초기값 null)

public:
	SubwayStation(std::string linenum, std::string stationName, int distance);
	std::string GetSubwayLine();
	std::string GetSubwayStationName();
	int Getdistance();
	void Setnext(SubwayStation* next);
	void Setpre(SubwayStation* pre);

	~SubwayStation();

};

