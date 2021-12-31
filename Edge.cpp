#include <iostream>
#include "Edge.h"
#include "SubwayStation.h"

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
 ���� : ����
 ��ȯ�� : ȣ������
*/
string Edge::GetSubwayLine()
{
	return linenum;
}

/*
 �Լ� �̸� : Getdistance
 �Լ� ��� : �� �� �Ÿ� ��ȯ
 ���� : ����
 ��ȯ�� : �� �� �Ÿ�
*/
int Edge::Getdistance()
{
	return distance;
}

/*
 �Լ� �̸� : Getsource
 �Լ� ��� : ��߿� ��ȯ
 ���� : ����
 ��ȯ�� : ��߿�
*/
string Edge::Getsource()
{
	return source;
}

/*
 �Լ� �̸� : Getdest
 �Լ� ��� : ������ ��ȯ
 ���� : ����
 ��ȯ�� : ������
*/
string Edge::Getdest()
{
	return dest;
}

/*
 �Լ� �̸� : Getnext
 �Լ� ��� : ���� �� ��ȯ
 ���� : ����
 ��ȯ�� : ���� ��
*/
SubwayStation* Edge::Getnext()
{
	return next;
}

/*
 �Լ� �̸� : Getpre
 �Լ� ��� : �� �� ��ȯ 
 ���� : ����
 ��ȯ�� : �� ��
*/
SubwayStation* Edge::Getpre()
{
	return pre;
}

/*
 �Լ� �̸� : Setnext
 �Լ� ��� : ���� �� ���� // �� ��ü�� ���� �� ��������� ����
 ���� : SubwayStation* next  ���� �� 
 ��ȯ�� : ����
*/
void Edge::Setnext(SubwayStation* next)
{
	this->next = next;
}

/*
 �Լ� �̸� : Setpre
 �Լ� ��� : �� �� ���� // �� ��ü�� �� �� ��������� ����
 ���� : SubwayStation* pre  �� ��
 ��ȯ�� : ����
*/
void Edge::Setpre(SubwayStation* pre)
{
	this->pre = pre;
}

