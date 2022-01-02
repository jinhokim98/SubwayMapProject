#include <iostream>
#include "SubwayMapUI.h"

using namespace std;

/*
 생성자 : 관리객체를 만든다.
*/
SubwayMapUI::SubwayMapUI()
{
	metro_manage = new SubwayMapManagement;
}

/*
 함수 이름 : StartInterface
 함수 기능 : 사용자에게 초기화면을 보여준다
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapUI::StartInterface()
{
	cout << WELCOME_MESSAGE << endl << endl;
	precautions();

	cout << MENU_SELETE << endl;
	print_menu();
}

/*
 함수 이름 : precautions
 함수 기능 : 사용자에게 주의사항을 알려준다
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapUI::precautions()
{
	cout << "주의사항" << endl;
	cout << "동명이역구분 : 5호선 양평역은 '양평(5호선)' 경의중앙선 양평역은 '양평'으로 검색하세요 " << endl;
	cout << "이수역과 총신대입구역은 같으나 역명이 다른관계로 이수역으로 통일하였습니다." << endl;
	cout << "총신대입구역을 검색하려면 이수역으로 검색하세요. " << endl << endl;
}

/*
 함수 이름 : print_menu
 함수 기능 : 사용자에게 메뉴화면을 보여준다
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapUI::print_menu()
{
	cout << "1 : 역 검색" << endl;
	cout << "2 : 최단거리 검색" << endl << endl;
}

/*
 함수 이름 : Seletemenu
 함수 기능 : 메뉴를 선택한다. 1번과 2번이 아닌 것을 골랐을 때는 다시 선택하기
 인자 : 없음
 반환값 : 메뉴번호
*/
int SubwayMapUI::SeleteMenu()
{
	int menu;

	while (true)
	{
		cout << "메뉴 입력 : ";
		cin >> menu;

		if (menu == 1 || menu == 2)
			break;
		else
			cout << ERROR_MESSAGE_MENU << endl << endl;
	}
	
	return menu;
}

/*
 함수 이름 : StartSearchSystem
 함수 기능 : 검색 시스템을 실행한다.
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapUI::StartSearchSystem()
{
	string search_station;

	cout << START_SEARCH_SYSTEM << endl;

	cout << INPUT_SEARCH;
	search_station = InputStationName();
	
	bool success = metro_manage->CheckStationName(search_station);

	cout << endl;

	if (success)
		cout << search_station << "역은 존재합니다." << endl;
	else
		cout << ERROR_MESSAGE_SEARCH << endl;

	cout << endl;
}

/*
 함수 이름 : StartShortestRouteSystem
 함수 기능 : 최단거리 시스템을 실행한다.
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapUI::StartShortestRouteSystem()
{
	string start;
	string goal;

	cout << START_SHORTEST_ROUTE_SYSTEM << endl;

	cout << INPUT_START;
	start = InputStationName();
	cout << INPUT_GOAL;
	goal = InputStationName();

	cout << endl << SHOW_SHORTEST_ROUTE << endl << endl;

	bool search = metro_manage->Shortest_route(start, goal);

	if (search)
		metro_manage->print_path(start, goal);
	else
		cout << "실패" << endl;

}

/*
 함수 이름 : InputStationName
 함수 기능 : 역을 입력한다.
 인자 : 없음
 반환값 : 입력한 역 이름
*/
string SubwayMapUI::InputStationName()
{
	string station;

	cin >> station;

	return station;
}

/*
 소멸자 : 동적생성한 관리객체를 해제한다.
*/
SubwayMapUI::~SubwayMapUI()
{
	delete metro_manage;
}

