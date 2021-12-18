#pragma once
#include <iostream>
#include "SubwayStation.h"


/*
 클래스 이름 : Edge
 클래스 기능 : 각 역들을 호선별로 이어준다.
*/
class Edge
{
private:
	std::string linenum;			// 호선 번호
	std::string source;				// 출발역
	std::string dest;				// 도착역
	int distance;					// 역 간 거리
	SubwayStation* next = nullptr;			// 다음 역을 이어주는 포인터
	SubwayStation* pre = nullptr;				// 전 역을 이어주는 포인터

public:
	Edge(std::string linenum, std::string source, std::string dest, int distance);

	std::string GetSubwayLine();
	int Getdistance();
	std::string Getsource();		
	std::string Getdest();	

	void Setnext(SubwayStation* next);
	void Setpre(SubwayStation* pre);
};