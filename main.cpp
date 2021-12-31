#include <iostream>
#include "SubwayMapUI.h"

using namespace std;

/*
 �Լ� �̸� : main
 �Լ� ��� : ������ ����ö �뼱�� ���α׷�
			 �� �˻��� �ִܰŸ� �ý����� ������ �� �ִ�.
 ���� : ����
 ��ȯ�� : ��������
*/
int main()
{
	int menu;

	SubwayMapUI SeoulMetro;			// UI ��ü ����

	SeoulMetro.StartInterface();	// �������̽� ����
	menu = SeoulMetro.SeleteMenu();	// �޴� ����

	cout << endl;

	switch (menu)
	{
	case 1:
		SeoulMetro.StartSearchSystem();
		break;

	case 2:
		SeoulMetro.StartShortestRouteSystem();
		break;
	}

	return 0;
}
