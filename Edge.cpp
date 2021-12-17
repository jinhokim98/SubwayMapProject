#include <iostream>
#include "Edge.h"

using namespace std;


/*
 ������ : ������� �ʱ�ȭ
*/
Edge::Edge(std::string linenum, std::string source, std::string dest, int distance)
{
	
	this->linenum = linenum;
	this->source = source;
	this->dest = dest;
	this->distance = distance;
}

/*
 �Լ� �̸� : GetSubwayLine
 �Լ� ��� : ȣ����ȣ ��ȯ
*/
string Edge::GetSubwayLine()
{
	return linenum;
}

/*
 �Լ� �̸� : Getdistance
 �Լ� ��� : �� �� �Ÿ� ��ȯ
*/
int Edge::Getdistance()
{
	return distance;
}

/*
 �Լ� �̸� : Getsource
 �Լ� ��� : ��߿� ��ȯ
*/
string Edge::Getsource()
{
	return source;
}

/*
 �Լ� �̸� : Getdest
 �Լ� ��� : ������ ��ȯ
*/
string Edge::Getdest()
{
	return dest;
}

/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� �� ����
*/
void Edge::Setnext(SubwayStation* next)
{
	if (next == nullptr)
	{
		this->next = nullptr;
	}

	this->next = next;
}

/*
 �Լ� �̸� : Setpre
 �Լ� ��� : �� �� ����
*/
void Edge::Setpre(SubwayStation* pre)
{
	if (pre == nullptr)
	{
		this->pre = nullptr;
	}

	this->pre = pre;
}

