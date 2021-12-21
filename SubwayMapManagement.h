#pragma once
#include "MakeGraph.h"

#define STATION_NUMBER 624

/*
 클래스 이름 : SubwayMapManagement
 클래스 기능 : 지하철 역의 최단시간을 구하게 해주는 함수 : control 클래스
*/
class SubwayMapManagement
{
private:
	MakeGraph* metro;
	int transfer;				// 환승횟수
	int distance_adj[STATION_NUMBER][STATION_NUMBER] = { 0, };	// 지하철역 인접행렬


public:
	SubwayMapManagement();
	void print_degree();
	void print_map();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();
};