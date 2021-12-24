#include <iostream>
#include "SubwayStation.h"
#include "SubwayMapManagement.h"

#define WELCOME_MESSAGE "수도권 지하철 노선도 프로그램."

using namespace std;

int main()
{
	SubwayMapManagement metro;

	//metro.print_degree();

	bool search;
	string start;
	string goal;

	cout << WELCOME_MESSAGE << endl << endl;
	cout << "주의사항" << endl;
	cout << "동명이역구분 : 5호선 양평역은 '양평(5호선)' 경의중앙선 양평역은 '양평'으로 검색하세요 " << endl;
	cout << "이수역과 총신대입구역은 같으나 역명이 다른관계로 이수역으로 통일하였습니다." << endl;
	cout << "총신대입구역을 검색하려면 이수역으로 검색하세요. " << endl << endl;

	cout << "출발역을 입력하세요 : ";
	cin >> start;
	cout << "도착역을 입력하세요 : ";
	cin >> goal;

	cout << "최단시간루트는 다음과 같습니다. " << endl;

	search = metro.Shortest_route(start, goal);

	if (search)
		metro.print_path(start, goal);
	else
		cout << "실패" << endl;
	

	return 0;
}