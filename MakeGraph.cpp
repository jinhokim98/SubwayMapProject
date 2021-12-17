#include <iostream>
#include <fstream>
#include "makeGraph.h"

using namespace std;

ifstream stationinfo;
ifstream fin;

/*
 ������ : �׷����� ���� �غ� : ������ ����.
*/
MakeGraph::MakeGraph()
{
	stationinfo.open("stationName.txt");

	if (stationinfo.fail())
	{
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}

	fin.open("station.txt");

	if (fin.fail())
	{
		cerr << "������ ã�� �� ����" << endl;
		exit(100);
	}

	*station = nullptr;
	*edge = nullptr;
}

/*
 �Լ� �̸� : initStation
 �Լ� ��� : �� ��ü ����
*/
void MakeGraph::initStation()
{
	int index = 0;

	string subwayname;

	while (!stationinfo.eof())
	{
		stationinfo >> subwayname;

		station[index++] = new SubwayStation(subwayname);	// �� ��ü �迭 ���� (�������)
	}
}

/*
 �Լ� �̸� : initEdge
 �Լ� ��� : ���� ��ü ����
*/
void MakeGraph::initEdge()
{
	int index = 0;

	string linenum;			// ȣ�� ��ȣ
	string source;			// ��߿�
	string dest;			// ������
	int distance;			// �� �� �Ÿ�

	while (!fin.eof())
	{
		fin >> linenum;
		fin >> source;
		fin >> dest;
		fin >> distance;

		edge[index++] = new Edge(linenum, source, dest, distance);	// ���� �迭 ���� (�������)
	}

}

/*
 �Լ� �̸� : makeLine
 �Լ� ��� : �� ��ü�� ���� ��ü�� ����Ͽ� ȣ���� �̾��ش�.
*/
void MakeGraph::makeLine()
{
	int index = 0;

	// �뼱 �����(1ȣ�� ~ ����������)
	while (true)
	{
		if (index >= 726) // ������ ������ ���� �߰����� �� �ݺ��� Ż��
			break;

		if (edge[index]->GetSubwayLine() == "line1")
		{
			if (edge[index]->Getsource() == "�ҿ��")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line1_Sinchang") // ������ ��� �ٽ� �� �� �����غ���
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2") // ��ȯ�� ó�� �ʿ�
		{
			if (edge[index]->Getsource() == "��û") // ��ȯ�� ó��
			{
				edge[index]->Setpre(station[SearchIndex("������")]);					// ������ <- ��û
				edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// ��û   -> �������Ա�

				int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
				int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

				station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// ��û -> �������Ա��� 2���� ����Ѵ�.
			}
			else
				link_else_station(index);
			
			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Seongsu")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Sinjeong")
		{
			if (edge[index]->Getsource() == "�ŵ���")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line3")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line4")
		{
			if (edge[index]->Getsource() == "���")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5_Macheon")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line6") // �ܹ��� ���� ó�� �ʿ�
		{
			if (edge[index]->Getsource() == "�ų�")
			{
				link_first_station(index);
				index++;
			}
			else if (edge[index]->Getsource() == "����")	// �ܹ��� ���� ó��
			{
				for (int i = 0; i < 5;i++)					// ���� -> �ұ� -> ������ -> ���ų� -> ���� -> ����
				{
					edge[index]->Setpre(nullptr);											// null   <- ����
					edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// ���� -> �ұ�

					int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
					int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

					station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance(), true);	// ���� -> �ұ��� 4���� ����Ѵ�.
				}
			}
			else
			{
				link_else_station(index);
				index++;
			}
		}

		else if (edge[index]->GetSubwayLine() == "line7")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line8")
		{
			if (edge[index]->Getsource() == "�ϻ�")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line9")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon1")
		{
			if (edge[index]->Getsource() == "���")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon2")
		{
			if (edge[index]->Getsource() == "�˴ܿ���")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Suinbundang")
		{
			if (edge[index]->Getsource() == "û����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Sinbundang")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongui_Jungang")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Airport")
		{
			if (edge[index]->Getsource() == "���￪")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongchun")
		{
			if (edge[index]->Getsource() == "û����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Uijeongbu")
		{
			if (edge[index]->Getsource() == "�߰�")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Yongin")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeonggang")
		{
			if (edge[index]->Getsource() == "�Ǳ�")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Wooyi")
		{
			if (edge[index]->Getsource() == "�ż���")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Seahae")
		{
			if (edge[index]->Getsource() == "�һ�")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gimpo_Gold")
		{
			if (edge[index]->Getsource() == "��������")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else
		{
			cout << "����ġ ���� ���� �߻�" << endl;
			exit(100);
		}
	}
}

/*
 �Լ� �̸� : link_first_station
 �Լ� ��� : ���� ù��° ���̶�� �� ���� null�� ó���ϰ� �������� ����Ų��.
			 ��Ŀ� ���������� �ɸ��� �Ÿ� �� ���� // �ҿ�� -> ����õ 4�� ����
*/
void MakeGraph::link_first_station(int index)
{
	edge[index]->Setpre(nullptr);											// null   <- �ҿ��
	edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// �ҿ�� -> ����õ

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

	station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// �ҿ�� <-> ����õ�� 4���� ����Ѵ�.
}

/*
 �Լ� �̸� : link_else_station
 �Լ� ��� : ���� ù��° ���� �ƴ϶�� �� ���� ����Ű�� �������� ����Ų��.
			 ��Ŀ� ���������� �ɸ��� �Ÿ� �� ���� // ����õ -> ���� 3�� ���
*/
void MakeGraph::link_else_station(int index)
{
	edge[index]->Setpre(station[SearchIndex(edge[--index]->Getsource())]);	// �� ���� �̾���
	edge[++index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);	// ���� ���� �̾���

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

	station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// ����õ <-> ������ 3���� ����Ѵ�.
}

/*
 �Լ� �̸� : SearchIndex
 �Լ� ��� : �� �̸��� ã�� �ε����� ��ȯ
			 ������ �����˻������� ���߿� �����˻����� �ٲ� ��
*/
int MakeGraph::SearchIndex(string name)
{
	int index = 0;

	for (int i = 0; i < STATION_NUMBER; i++)
	{
		if (station[index]->GetSubwayStationName() == name)
			return index;
	}
	
	return index;
}

/*
 �Լ� �̸� : init
 �Լ� ��� : public �Լ�
			 initStation(), initEdge(), makeLine()�� �����Ѵ�.
*/
void MakeGraph::init()
{
	initStation();
	initEdge();
	makeLine();
}

/*
 �Ҹ��� : ���� �ݰ� ���������� ��ü �迭���� �����Ѵ�.
*/
MakeGraph::~MakeGraph()
{
	stationinfo.close();
	fin.close();

	for (int i = 0;i < STATION_NUMBER;i++)
		delete station[i];

	for (int i = 0;i < EDGE_NUMBER;i++)
		delete edge[i];
}