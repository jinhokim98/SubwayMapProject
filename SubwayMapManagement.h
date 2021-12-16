#pragma once
#include "SubwayStation.h"
#define	STATIONINFO 751

/*
 Ŭ���� �̸� : SubwayMapManagement
 Ŭ���� ��� : ����ö �� ��ü�� ȣ���� �ձ� ���� Linked List�� �̾��ְ� 
			   ���� �ִ� �Ÿ��� ���ϸ�, ȯ��Ƚ���� �˷��ش�.
*/
class SubwayMapManagement
{
private:
	SubwayStation* station[STATIONINFO];		// �� ��ü
	int weight_adjacency_matrix[STATION_NUMBER][STATION_NUMBER] = { 0, };	// ����ö�� �������

	int transfer;				// ȯ��Ƚ��

public:
	SubwayMapManagement();
	void initStation();
	void MakeGraph();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();

};