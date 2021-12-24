#pragma once
#include "SubwayStation.h"
#include "Edge.h"

enum location
{
	firstcase,
	elsecase,
	lastcase
};

#define EDGE_NUMBER 723

/*
 클래스 이름 : makeGraph
 클래스 기능 : 역 객체와 엣지객체를 만들어 그래프를 만든다.
*/
class MakeGraph
{
private:

	SubwayStation* station[STATION_NUMBER];		// 역 객체
	Edge* edge[EDGE_NUMBER];					// 엣지 객체

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

	//시험용
	void Getdegree(SubwayStation** sub, Edge** edge);
	Edge** GetEdgePointer();
	SubwayStation** GetSubwayPointer();

	SubwayStation* GetStation(std::string station_name);
	SubwayStation* GetStation(Edge* q);

	Edge* GetEdge(SubwayStation* p, int pointer_num);

	int SearchIndex(std::string name);
	
	~MakeGraph();
};