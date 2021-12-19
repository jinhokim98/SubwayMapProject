#pragma once
#include <iostream>

#define STATION_NUMBER 624

class Edge;

/*
 Ŭ���� �̸� : SubwayStation
 Ŭ���� ��� : ����ö ���� �������� �����Ѵ�.
*/
class SubwayStation
{
private:
	std::string stationName;
	
	// �� ���� �ִ� �������� ȣ���� 4�������� ������ �����͸� �ִ� 8�� �غ��Ѵ�.

	Edge* next = nullptr;				// ���� ������ ����Ű�� ������
	Edge* pre = nullptr;				// �� ������ ����Ű�� ������

	Edge* trans1_next = nullptr;		// ȯ�¿��� �� �ٸ� ȣ���� ���� ����
	Edge* trans1_pre = nullptr;			// ȯ�¿��� �� �ٸ� ȣ���� �� ����

	Edge* trans2_next = nullptr;		// ȯ�¿��� �� �� �ٸ� ȣ���� ���� ����
	Edge* trans2_pre = nullptr;			// ȯ�¿��� �� �� �ٸ� ȣ���� �� ����
	
	Edge* trans3_next = nullptr;		// ȯ�¿��� �� �� �ٸ� ȣ���� ���� ����
	Edge* trans3_pre = nullptr;			// ȯ�¿��� �� �� �ٸ� ȣ���� �� ����

public:
	SubwayStation(std::string stationName);
	std::string GetSubwayStationName();

	Edge* Getnext();
	Edge* Getpre();
	void Setnext(Edge* next);
	void Setpre(Edge* pre);

};

