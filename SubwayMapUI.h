#pragma once
#include "SubwayStation.h"
#include "SubwayMapManagement.h"

#define WELCOME_MESSAGE "������ ����ö �뼱�� ���α׷�"
#define MENU_SELETE "���Ͻô� �޴��� �����ϼ���."
#define ERROR_MESSAGE_MENU "�ùٸ� �޴��� �Է����ּ���."
#define START_SEARCH_SYSTEM "�� �˻� �ý����� �����մϴ�. "
#define INPUT_SEARCH "�˻��� ���� �Է��ϼ��� : "
#define ERROR_MESSAGE_SEARCH "�Է��Ͻ� ���� ���� ���Դϴ�."
#define START_SHORTEST_ROUTE_SYSTEM "�ִܰŸ� �ý����� �����մϴ�."
#define	INPUT_START "��߿��� �Է��ϼ��� : "
#define INPUT_GOAL "�������� �Է��ϼ��� : "
#define	SHOW_SHORTEST_ROUTE "�ִܽð���Ʈ�� ������ �����ϴ�. "

/*
 Ŭ���� �̸� : SubwayMapUI
 Ŭ���� ��� : ����ڿ��� �������� UI ����
*/
class SubwayMapUI
{
private:
	SubwayMapManagement* metro_manage;	// ������ü
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