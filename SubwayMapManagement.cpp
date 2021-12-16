#include <iostream>
#include <fstream>
#include "SubwayMapManagement.h"

using namespace std;

ifstream fin;

/*
 ������ : station.txt������ �о�´�.
*/
SubwayMapManagement::SubwayMapManagement()
{
	fin.open("station.txt");

	if (fin.fail())
	{
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}
	
}

/*
 �Լ� �̸� : initStation
 �Լ� ��� : station.txt���� �� ������ �ҷ��� SubwayStation��ü�� �����.
			 �� �� ���߿��Ḯ��Ʈ�� ��ü�� �ٿ� �뼱�� �����.
*/
void SubwayMapManagement::initStation()
{
	int index = 0;		// ��ü �迭 �ε���

	string subwayline;
	string subwayname;
	int distance;
	
	// ��ü �����
	while (!fin.eof())
	{
		fin >> subwayline;
		fin >> subwayname;
		fin >> distance;

		station[index++] = new SubwayStation(subwayline, subwayname, distance);
	}

	index = 0;

	// �뼱 �����(1ȣ�� ~ ����������)
	while (true)
	{
		if (station[index]->GetSubwayLine() == "line1")
		{
			if (station[index]->GetSubwayStationName() == "�ҿ��") // ù ��
			{
				station[index]->Setnext(station[++index]);	// �ҿ�� -> ����õ
				station[--index]->Setpre(nullptr);			// null   <- �ҿ��
				index++;									// �ε��� ����õ����
			}
			else if (station[index]->GetSubwayStationName() == "��õ")	// ������
			{
				station[index]->Setnext(nullptr);			// ��õ -> null
				station[index]->Setpre(station[--index]);	// ����õ <- ��õ
				index += 2;									// ���� ȣ������ �̵�
			}
			else
			{
				station[index]->Setnext(station[++index]);	// ���� ���� �̾���
				station[--index]->Setpre(station[--index]);	// �� ���� �̾���
				index += 2;									// �ε��� ���� ������ �ű�
			}
		}
		else if (station[index]->GetSubwayLine() == "line1_Sinchang")
		{
			if (station[index]->GetSubwayStationName() == "����")
			{
				station[index]->Setnext(station[++index]);	// ���� -> ��������д���
			}
		}
	}
}


/*
 �Լ� �̸� : MakeGraph
 �Լ� ��� : ����ö �� �׷����� �����.
*/
void SubwayMapManagement::MakeGraph()
{
	
}

/*
 �Ҹ��� : station.txt������ �ݴ´�.
		  ���� ������ ��ü���� delete�Ѵ�. 
*/
SubwayMapManagement::~SubwayMapManagement()
{
	fin.close();

	for (int i = 0;i < STATIONINFO; i++)
	{
		delete station[i];
	}
}


//