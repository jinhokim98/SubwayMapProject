#pragma once
#include "SubwayStation.h"
#include "Edge.h"
#define STATION_NUMBER 625
#define EDGE_NUMBER 726

/*
 Ŭ���� �̸� : makeGraph
 Ŭ���� ��� : �� ��ü�� ������ü�� ����� �׷����� �����.
*/
class MakeGraph
{
private:

	SubwayStation* station[STATION_NUMBER];		// �� ��ü
	Edge* edge[EDGE_NUMBER];					// ���� ��ü

	void initStation();
	void initEdge();
	void makeLine();

	void link_first_station(int index);
	void link_else_station(int index);
	int SearchIndex(std::string name);

public:
	MakeGraph();
	void init();
	
	~MakeGraph();
};