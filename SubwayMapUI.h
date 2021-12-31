#pragma once
#include "SubwayStation.h"
#include "SubwayMapManagement.h"

#define WELCOME_MESSAGE "수도권 지하철 노선도 프로그램"
#define MENU_SELETE "원하시는 메뉴를 선택하세요."
#define ERROR_MESSAGE_MENU "올바른 메뉴를 입력해주세요."
#define START_SEARCH_SYSTEM "역 검색 시스템을 실행합니다. "
#define INPUT_SEARCH "검색할 역을 입력하세요 : "
#define ERROR_MESSAGE_SEARCH "입력하신 역은 없는 역입니다."
#define START_SHORTEST_ROUTE_SYSTEM "최단거리 시스템을 실행합니다."
#define	INPUT_START "출발역을 입력하세요 : "
#define INPUT_GOAL "도착역을 입력하세요 : "
#define	SHOW_SHORTEST_ROUTE "최단시간루트는 다음과 같습니다. "

/*
 클래스 이름 : SubwayMapUI
 클래스 기능 : 사용자에게 보여지는 UI 제공
*/
class SubwayMapUI
{
private:
	SubwayMapManagement* metro_manage;	// 관리객체
	void precautions();
	void print_menu();

public:
	SubwayMapUI();
	void StartInterface();
	int SeleteMenu();
	void StartSearchSystem();
	void StartShortestRouteSystem();
	std::string InputStationName();

	~SubwayMapUI();
};