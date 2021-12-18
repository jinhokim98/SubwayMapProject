#pragma once
#include "SubwayStation.h"
#include "Edge.h"

#define STATION_NUMBER 625
#define EDGE_NUMBER 723

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
	void link_last_station(int index);
	void link_line2_circle(int index);
	int SearchIndex(std::string name);

public:
	MakeGraph();
	void init();

	void print_Map();
	
	~MakeGraph();
};