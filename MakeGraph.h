#pragma once
#include "SubwayStation.h"
#include "Edge.h"
#define STATION_NUMBER 625
#define EDGE_NUMBER 726

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
	int SearchIndex(std::string name);

public:
	MakeGraph();
	void init();
	
	~MakeGraph();
};