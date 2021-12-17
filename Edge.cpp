#include <iostream>
#include "Edge.h"

using namespace std;


/*
 생성자 : 멤버변수 초기화
*/
Edge::Edge(std::string linenum, std::string source, std::string dest, int distance)
{
	
	this->linenum = linenum;
	this->source = source;
	this->dest = dest;
	this->distance = distance;
}

/*
 함수 이름 : GetSubwayLine
 함수 기능 : 호선번호 반환
*/
string Edge::GetSubwayLine()
{
	return linenum;
}

/*
 함수 이름 : Getdistance
 함수 기능 : 역 간 거리 반환
*/
int Edge::Getdistance()
{
	return distance;
}

/*
 함수 이름 : Getsource
 함수 기능 : 출발역 반환
*/
string Edge::Getsource()
{
	return source;
}

/*
 함수 이름 : Getdest
 함수 기능 : 도착역 반환
*/
string Edge::Getdest()
{
	return dest;
}

/*
 함수 이름 : Setnext
 함수 기능 : 다음 역 설정
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
 함수 이름 : Setpre
 함수 기능 : 전 역 설정
*/
void Edge::Setpre(SubwayStation* pre)
{
	if (pre == nullptr)
	{
		this->pre = nullptr;
	}

	this->pre = pre;
}

