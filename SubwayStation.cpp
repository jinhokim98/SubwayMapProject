#include <iostream>
#include "SubwayStation.h"

using namespace std;

/*
 생성자 : 매개변수값들을 변수에 저장.
		  거리행렬을 전부 9999로 저장 (다익스트라 알고리즘의 초기화 조건)
*/
SubwayStation::SubwayStation(string stationName)
{
	
	this->stationName = stationName;

	int i, j = 0;

	for (i = 0; i < STATION_NUMBER; i++)
	{
		for (j = 0; j < STATION_NUMBER; j++)
		{
			distance_adj[i][j] = INF;
		}
	}
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
 함수 이름 : SetMatrix
 함수 기능 : 역 간 거리를 행렬에 기록
*/
void SubwayStation::SetMatrix(int source, int dest, int distance)
{
	distance_adj[source][dest] = distance;
	distance_adj[dest][source] = distance;
}


/*
 함수 이름 : SetMatrix (단방향)
 함수 기능 : 단방향일 때 역 간 거리를 행렬에 기록
*/
void SubwayStation::SetMatrix(int source, int dest, int distance, bool Is_one_way)
{
	if (Is_one_way == true)
		distance_adj[source][dest] = distance;
}

SubwayStation* SubwayStation::Getnext()
{

}