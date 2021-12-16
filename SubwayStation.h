#pragma once
#include <iostream>

#define STATION_NUMBER 625

/*
 Ŭ���� �̸� : SubwayStation
 Ŭ���� ��� : ����ö ���� �������� �����Ѵ�.
*/
class SubwayStation
{
private:
	std::string linenum;			// ȣ��
	std::string stationName;		// �� �̸�
	int distance;					// �Ÿ� 
	SubwayStation* next = nullptr;	// ���� ��(�ʱⰪ null)
	SubwayStation* pre = nullptr;	// �� ��  (�ʱⰪ null)

public:
	SubwayStation(std::string linenum, std::string stationName, int distance);
	std::string GetSubwayLine();
	std::string GetSubwayStationName();
	int Getdistance();
	void Setnext(SubwayStation* next);
	void Setpre(SubwayStation* pre);

	~SubwayStation();

};

