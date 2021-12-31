#include <iostream>
#include "SubwayStation.h"
#include "Edge.h"

using namespace std;

/*
 생성자 : 역 이름과 필요한 포인터 수를 저장하고
		  역 포인터를 모두 null로 초기화한다.
*/
SubwayStation::SubwayStation(string stationName, int edgenum)
{
	this->stationName = stationName;
	this->edgenum = edgenum;

	for (int i = trans0_next; i <= trans3_pre; i++)
	{
		adj[i] = nullptr;
	}
}

/*
 함수 이름 : GetSubwayStationName
 함수 기능 : 역 이름 반환
 인자 : 없음
 반환값 : 역 이름
*/
string SubwayStation::GetSubwayStationName()
{
	return stationName;
}

/*
 함수 이름 : Getedgenum
 함수 기능 : 해당역이 갈 수 있는 길의 수를 반환한다.
 인자 : 없음
 반환값 : degree
*/
int SubwayStation::Getedgenum()
{
	return edgenum;
}

/*
 함수 이름 : Getnext
 함수 기능 : 다음 엣지 반환
 인자 : int pointer_num 포인터 숫자 (enum에 기재되어있음)
 반환값 : 해당 엣지
*/
Edge* SubwayStation::Getadj(int pointer_num)
{
	return adj[pointer_num];
}


/*
 함수 이름 : Setnext
 함수 기능 : 다음 역의 엣지 설정
 인자 : int pointer_num 포인터 숫자 (enum에 기재되어있음)
 반환값 : 없음
*/
void SubwayStation::Setadj(Edge* next, int pointer_num)
{
	this->adj[pointer_num] = next;
}