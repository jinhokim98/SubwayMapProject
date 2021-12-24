#include <iostream>
#include "SubwayStation.h"
#include "SubwayMapManagement.h"

#define WELCOME_MESSAGE "������ ����ö �뼱�� ���α׷�."

using namespace std;

int main()
{
	SubwayMapManagement metro;

	//metro.print_degree();

	bool search;
	string start;
	string goal;

	cout << WELCOME_MESSAGE << endl << endl;
	cout << "���ǻ���" << endl;
	cout << "�����̿����� : 5ȣ�� ������ '����(5ȣ��)' �����߾Ӽ� ������ '����'���� �˻��ϼ��� " << endl;
	cout << "�̼����� �ѽŴ��Ա����� ������ ������ �ٸ������ �̼������� �����Ͽ����ϴ�." << endl;
	cout << "�ѽŴ��Ա����� �˻��Ϸ��� �̼������� �˻��ϼ���. " << endl << endl;

	cout << "��߿��� �Է��ϼ��� : ";
	cin >> start;
	cout << "�������� �Է��ϼ��� : ";
	cin >> goal;

	cout << "�ִܽð���Ʈ�� ������ �����ϴ�. " << endl;

	search = metro.Shortest_route(start, goal);

	if (search)
		metro.print_path(start, goal);
	else
		cout << "����" << endl;
	

	return 0;
}