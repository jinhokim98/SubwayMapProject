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
	int distance_adj[STATION_NUMBER][STATION_NUMBER];	// ����ö�� �������


public:
	SubwayMapManagement();
	void print_degree();
	void print_Map();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();
};