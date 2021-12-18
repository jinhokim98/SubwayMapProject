#pragma once
#include "MakeGraph.h"

#define STATION_NUMBER 625

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

	void print_Map();

public:
	SubwayMapManagement();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();
};