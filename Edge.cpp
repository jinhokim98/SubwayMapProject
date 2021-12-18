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
 �Լ� �̸� : Getnext
 �Լ� ��� : ���� �� ��ȯ
*/
SubwayStation* Edge::Getnext()
{
	return next;
}

/*
 �Լ� �̸� : Getpre
 �Լ� ��� : �� �� ��ȯ 
*/
SubwayStation* Edge::Getpre()
{
	return pre;
}

/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� �� ���� // �� ��ü�� ���� �� ��������� ����
*/
void Edge::Setnext(SubwayStation* next)
{
	this->next = next;
}

/*
 �Լ� �̸� : Setpre
 �Լ� ��� : �� �� ���� // �� ��ü�� �� �� ��������� ����
*/
void Edge::Setpre(SubwayStation* pre)
{
	this->pre = pre;
}

