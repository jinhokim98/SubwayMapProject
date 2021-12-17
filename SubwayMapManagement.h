#pragma once
#include "MakeGraph.h"

/*
 Ŭ���� �̸� : SubwayMapManagement
 Ŭ���� ��� : ����ö ���� �ִܽð��� ���ϰ� ���ִ� �Լ� : control Ŭ����
*/
class SubwayMapManagement
{
private:
	MakeGraph* metro;
	int transfer;				// ȯ��Ƚ��

public:
	SubwayMapManagement();
	void Shortest_route(std::string start, std::string goal);

	~SubwayMapManagement();
};