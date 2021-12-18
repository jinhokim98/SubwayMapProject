#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 생성자 : 역 이름 저장
*/
SubwayStation::SubwayStation(string stationName)
{
	this->stationName = stationName;
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
 함수 이름 : Setnext
 함수 기능 : 다음 역의 엣지 설정
*/
void SubwayStation::Setnext(Edge* next)
{
	this->next = next;
}

/*
 함수 이름 : Setpre
 함수 기능 : 전 역의 엣지 설정
*/
void SubwayStation::Setpre(Edge* pre)
{
	this->pre = pre;
}







/*
 
void SubwayStation::SetMatrix(int source, int dest, int distance)
{
	distance_adj[source][dest] = distance;
	distance_adj[dest][source] = distance;
}



void SubwayStation::SetMatrix(int source, int dest, int distance, bool Is_one_way)
{
	if (Is_one_way == true)
		distance_adj[source][dest] = distance;
}

*/