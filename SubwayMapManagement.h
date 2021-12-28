#pragma once
#include <queue>
#include "MakeGraph.h"

#define INF 9999
#define TRANSFER_TIME 3

/*
 Ŭ���� �̸� : SubwayMapManagement
 Ŭ���� ��� : ����ö ���� �ִܽð��� ���ϰ� ���ִ� �Լ� : control Ŭ����
*/
class SubwayMapManagement
{
private:
	MakeGraph* metro;
	int transfer;								// ȯ��Ƚ��
	int distance_adj[STATION_NUMBER];	// ����ö�� �������
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