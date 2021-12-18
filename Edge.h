#pragma once
#include <iostream>
#include "SubwayStation.h"


/*
 Ŭ���� �̸� : Edge
 Ŭ���� ��� : �� ������ ȣ������ �̾��ش�.
*/
class Edge
{
private:
	std::string linenum;			// ȣ�� ��ȣ
	std::string source;				// ��߿�
	std::string dest;				// ������
	int distance;					// �� �� �Ÿ�
	SubwayStation* next = nullptr;			// ���� ���� �̾��ִ� ������
	SubwayStation* pre = nullptr;				// �� ���� �̾��ִ� ������

public:
	Edge(std::string linenum, std::string source, std::string dest, int distance);

	std::string GetSubwayLine();
	int Getdistance();
	std::string Getsource();		
	std::string Getdest();	

	void Setnext(SubwayStation* next);
	void Setpre(SubwayStation* pre);
};