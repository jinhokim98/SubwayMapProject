#pragma once
#include "SubwayStation.h"
#define	STATIONINFO 751

/*
 클래스 이름 : SubwayMapManagement
 클래스 기능 : 지하철 역 객체를 호선을 잇기 위해 Linked List로 이어주고 
			   역간 최단 거리를 구하며, 환승횟수를 알려준다.
*/
class SubwayMapManagement
{
private:
	SubwayStation* station[STATIONINFO];		// 역 객체
	int weight_adjacency_matrix[STATION_NUMBER][STATION_NUMBER] = { 0, };	// 지하철역 인접행렬

	int transfer;				// 환승횟수

public:
	SubwayMapManagement();
	void initStation();
	void MakeGraph();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();

};