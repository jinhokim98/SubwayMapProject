#pragma once
#include <iostream>

#define STATION_NUMBER 625

enum pointer_name
{
	trans0_next, trans0_pre, trans1_next, trans1_pre, trans2_next, trans2_pre, trans3_next, trans3_pre
};

class Edge;

/*
 Ŭ���� �̸� : SubwayStation
 Ŭ���� ��� : ����ö ���� �������� �����Ѵ�.
*/
class SubwayStation
{
private:
	std::string stationName;		// �� �̸�
	int edgenum;					// �ش翪�� �� �� �ִ� ���� ��
	Edge* adj[8];	// �� ���� �ִ� �������� ȣ���� 4�������� ������ �����͸� �ִ� 8�� �غ��Ѵ�.

public:
	SubwayStation(std::string stationName, int edgenum);
	std::string GetSubwayStationName();
	int Getedgenum();

	Edge* Getadj(int pointer_num);
	void Setadj(Edge* next, int pointer_num);

};

