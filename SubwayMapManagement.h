#pragma once
#include <queue>
#include "MakeGraph.h"

#define INF 9999
#define TRANSFER_TIME 3

/*
 클래스 이름 : SubwayMapManagement
 클래스 기능 : 지하철 역의 최단시간을 구하게 해주는 함수 : control 클래스
*/
class SubwayMapManagement
{
private:
	MakeGraph* metro;
	int transfer;								// 환승횟수
	int distance_adj[STATION_NUMBER];	// 지하철역 인접행렬
	std::string route[STATION_NUMBER];
	std::string short_route[STATION_NUMBER];
	int route_index;

public:
	SubwayMapManagement();
	void print_degree();
	void print_map();
	bool Shortest_route(std::string start, std::string goal);
	void print_path(std::string start, std::string goal);
	

	~SubwayMapManagement();
};