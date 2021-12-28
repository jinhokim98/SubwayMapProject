#include <iostream>
#include "SubwayStation.h"
#include "SubwayMapManagement.h"

#define WELCOME_MESSAGE "������ ����ö �뼱�� ���α׷�"
#define	INPUT_START "��߿��� �Է��ϼ��� : "
#define INPUT_GOAL "�������� �Է��ϼ��� : "
#define	SHOW_SHORTEST_ROUTE "�ִܽð���Ʈ�� ������ �����ϴ�. "

void precautions();

using namespace std;

int main()
{
	SubwayMapManagement metro;

	//metro.print_degree();

	bool search;
	string start;
	string goal;

	cout << WELCOME_MESSAGE << endl << endl;
	precautions();

	cout << INPUT_START;
	cin >> start;
	cout << INPUT_GOAL;
	cin >> goal;

	cout << endl << SHOW_SHORTEST_ROUTE << endl << endl;

	search = metro.Shortest_route(start, goal);

	if (search)
		metro.print_path(start, goal);
	else
		cout << "����" << endl;
	

	return 0;
}

void precautions()
{
	cout << "���ǻ���" << endl;
	cout << "�����̿����� : 5ȣ�� ������ '����(5ȣ��)' �����߾Ӽ� ������ '����'���� �˻��ϼ��� " << endl;
	cout << "�̼����� �ѽŴ��Ա����� ������ ������ �ٸ������ �̼������� �����Ͽ����ϴ�." << endl;
	cout << "�ѽŴ��Ա����� �˻��Ϸ��� �̼������� �˻��ϼ���. " << endl << endl;
}