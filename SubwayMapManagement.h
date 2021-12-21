#pragma once
#include "MakeGraph.h"

#define STATION_NUMBER 624

/*
 Ŭ���� �̸� : SubwayMapManagement
 Ŭ���� ��� : ����ö ���� �ִܽð��� ���ϰ� ���ִ� �Լ� : control Ŭ����
*/
class SubwayMapManagement
{
private:
	MakeGraph* metro;
	int transfer;				// ȯ��Ƚ��
	int distance_adj[STATION_NUMBER][STATION_NUMBER] = { 0, };	// ����ö�� �������


public:
	SubwayMapManagement();
	void print_degree();
	void print_map();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();
};