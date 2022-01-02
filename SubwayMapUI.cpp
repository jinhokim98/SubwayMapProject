#include <iostream>
#include "SubwayMapUI.h"

using namespace std;

/*
 ������ : ������ü�� �����.
*/
SubwayMapUI::SubwayMapUI()
{
	metro_manage = new SubwayMapManagement;
}

/*
 �Լ� �̸� : StartInterface
 �Լ� ��� : ����ڿ��� �ʱ�ȭ���� �����ش�
 ���� : ����
 ��ȯ�� : ����
*/
void SubwayMapUI::StartInterface()
{
	cout << WELCOME_MESSAGE << endl << endl;
	precautions();

	cout << MENU_SELETE << endl;
	print_menu();
}

/*
 �Լ� �̸� : precautions
 �Լ� ��� : ����ڿ��� ���ǻ����� �˷��ش�
 ���� : ����
 ��ȯ�� : ����
*/
void SubwayMapUI::precautions()
{
	cout << "���ǻ���" << endl;
	cout << "�����̿����� : 5ȣ�� ������ '����(5ȣ��)' �����߾Ӽ� ������ '����'���� �˻��ϼ��� " << endl;
	cout << "�̼����� �ѽŴ��Ա����� ������ ������ �ٸ������ �̼������� �����Ͽ����ϴ�." << endl;
	cout << "�ѽŴ��Ա����� �˻��Ϸ��� �̼������� �˻��ϼ���. " << endl << endl;
}

/*
 �Լ� �̸� : print_menu
 �Լ� ��� : ����ڿ��� �޴�ȭ���� �����ش�
 ���� : ����
 ��ȯ�� : ����
*/
void SubwayMapUI::print_menu()
{
	cout << "1 : �� �˻�" << endl;
	cout << "2 : �ִܰŸ� �˻�" << endl << endl;
}

/*
 �Լ� �̸� : Seletemenu
 �Լ� ��� : �޴��� �����Ѵ�. 1���� 2���� �ƴ� ���� ����� ���� �ٽ� �����ϱ�
 ���� : ����
 ��ȯ�� : �޴���ȣ
*/
int SubwayMapUI::SeleteMenu()
{
	int menu;

	while (true)
	{
		cout << "�޴� �Է� : ";
		cin >> menu;

		if (menu == 1 || menu == 2)
			break;
		else
			cout << ERROR_MESSAGE_MENU << endl << endl;
	}
	
	return menu;
}

/*
 �Լ� �̸� : StartSearchSystem
 �Լ� ��� : �˻� �ý����� �����Ѵ�.
 ���� : ����
 ��ȯ�� : ����
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
		cout << search_station << "���� �����մϴ�." << endl;
	else
		cout << ERROR_MESSAGE_SEARCH << endl;

	cout << endl;
}

/*
 �Լ� �̸� : StartShortestRouteSystem
 �Լ� ��� : �ִܰŸ� �ý����� �����Ѵ�.
 ���� : ����
 ��ȯ�� : ����
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
		cout << "����" << endl;

}

/*
 �Լ� �̸� : InputStationName
 �Լ� ��� : ���� �Է��Ѵ�.
 ���� : ����
 ��ȯ�� : �Է��� �� �̸�
*/
string SubwayMapUI::InputStationName()
{
	string station;

	cin >> station;

	return station;
}

/*
 �Ҹ��� : ���������� ������ü�� �����Ѵ�.
*/
SubwayMapUI::~SubwayMapUI()
{
	delete metro_manage;
}

