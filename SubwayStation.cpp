#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 생성자 : 매개변수값들을 변수에 저장.
*/
SubwayStation::SubwayStation(string linenum, string stationName, int distance)
{
	this->linenum = linenum;
	this->stationName = stationName;
	this->distance = distance;
}

/*
 함수 이름 : GetSubwayLine
 함수 기능 : 호선번호 반환
*/
string SubwayStation::GetSubwayLine()
{
	return linenum;
}

/*
 함수 이름 : GetSubwayStationName
 함수 기능 : 역 이름 반환
*/
string SubwayStation::GetSubwayStationName()
{
	return stationName;
}

/*
 함수 이름 : Getdistance
 함수 기능 : 역 간 거리 반환
*/
int SubwayStation::Getdistance()
{
	return distance;
}

/*
 함수 이름 : Setnext
 함수 기능 : 다음 역 설정
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
 함수 이름 : Setpre
 함수 기능 : 전 역 설정
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
 소멸자 : 파일을 닫는다.
*/
SubwayStation::~SubwayStation()
{
	
}