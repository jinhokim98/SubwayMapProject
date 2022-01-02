#pragma once
#include <queue>
#include <tuple>
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
	int distance_adj[STATION_NUMBER];							// 지하철역 인접행렬
	std::pair<std::string, std::string> route[STATION_NUMBER];	// <전 역, 다음 엣지의 호선>
	std::string short_route[STATION_NUMBER];					// 최단루트를 기록하는 배열
	std::string line_info[STATION_NUMBER];						// 최단루트간 호선을 기록하는 배열(환승여부 알기위해)
	int route_index;											// short_route의 인덱스

	SubwayStation* FindPreStation(SubwayStation* move_p, Edge* pre_edge);
public:
	SubwayMapManagement();
	void print_degree();	// 시험용
	bool CheckStationName(std::string station);
	bool Shortest_route(std::string start, std::string goal);
	void print_path(std::string start, std::string goal);
	

	~SubwayMapManagement();
};