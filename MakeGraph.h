#pragma once
#include "SubwayStation.h"
#include "Edge.h"

enum location
{
	firstcase,
	elsecase,
	lastcase
};

#define EDGE_NUMBER 724

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
	void link_line6_one_way_problem(int index, std::string name, bool Is_transfer_station);

	void link_station(int loc, int index, int now_station_index, int next_station_index, int degree);
	void link_station_case(int loc, int index, int now_station_index, int next_station_index, int next, int pre, int degree);
	int check_next_station_case(int next_station_index);

public:

	MakeGraph();
	void init();

	//����� : �Ʒ��� ������ �Լ��� �� ���� degree�� �˱����� ����ߴ�.
	void Getdegree(SubwayStation** sub, Edge** edge);
	Edge** GetEdgePointer();
	SubwayStation** GetSubwayPointer();

	SubwayStation* GetStation(std::string station_name);

	int SearchIndex(std::string name);
	
	~MakeGraph();
};

