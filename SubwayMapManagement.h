#pragma once
#include <queue>
#include <tuple>
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
	int distance_adj[STATION_NUMBER];							// ����ö�� �������
	std::pair<std::string, std::string> route[STATION_NUMBER];	// <�� ��, ���� ������ ȣ��>
	std::string short_route[STATION_NUMBER];					// �ִܷ�Ʈ�� ����ϴ� �迭
	std::string line_info[STATION_NUMBER];						// �ִܷ�Ʈ�� ȣ���� ����ϴ� �迭(ȯ�¿��� �˱�����)
	int route_index;											// short_route�� �ε���

	SubwayStation* FindPreStation(SubwayStation* move_p, Edge* pre_edge);
public:
	SubwayMapManagement();
	void print_degree();	// �����
	bool CheckStationName(std::string station);
	bool Shortest_route(std::string start, std::string goal);
	void print_path(std::string start, std::string goal);
	

	~SubwayMapManagement();
};