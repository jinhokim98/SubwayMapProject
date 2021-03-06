#include <iostream>
#include "Edge.h"
#include "SubwayStation.h"

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
 인자 : 없음
 반환값 : 호선정보
*/
string Edge::GetSubwayLine()
{
	return linenum;
}

/*
 함수 이름 : Getdistance
 함수 기능 : 역 간 거리 반환
 인자 : 없음
 반환값 : 역 간 거리
*/
int Edge::Getdistance()
{
	return distance;
}

/*
 함수 이름 : Getsource
 함수 기능 : 출발역 반환
 인자 : 없음
 반환값 : 출발역
*/
string Edge::Getsource()
{
	return source;
}

/*
 함수 이름 : Getdest
 함수 기능 : 도착역 반환
 인자 : 없음
 반환값 : 도착역
*/
string Edge::Getdest()
{
	return dest;
}

/*
 함수 이름 : Getnext
 함수 기능 : 다음 역 반환
 인자 : 없음
 반환값 : 다음 역
*/
SubwayStation* Edge::Getnext()
{
	return next;
}

/*
 함수 이름 : Getpre
 함수 기능 : 전 역 반환 
 인자 : 없음
 반환값 : 전 역
*/
SubwayStation* Edge::Getpre()
{
	return pre;
}

/*
 함수 이름 : Setnext
 함수 기능 : 다음 역 설정 // 역 객체의 다음 역 멤버변수를 수정
 인자 : SubwayStation* next  다음 역 
 반환값 : 없음
*/
void Edge::Setnext(SubwayStation* next)
{
	this->next = next;
}

/*
 함수 이름 : Setpre
 함수 기능 : 전 역 설정 // 역 객체의 전 역 멤버변수를 수정
 인자 : SubwayStation* pre  전 역
 반환값 : 없음
*/
void Edge::Setpre(SubwayStation* pre)
{
	this->pre = pre;
}

