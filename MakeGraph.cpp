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
		if (index > EDGE_NUMBER) // ������ ������ ���� �߰����� �� �ݺ��� Ż��
			break;

		if (edge[index]->GetSubwayLine() == "line1")
		{
			if (edge[index]->Getsource() == "�ҿ��")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��õ")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line1_Sinchang") // ������ ��� �ٽ� �� �� �����غ���
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��â")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2") // ��ȯ�� ó�� �ʿ�
		{
			if (edge[index]->Getsource() == "��û")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��û")
			{
				link_last_station(index);				 
				link_line2_circle(index);				  // ��ȯ�� ���� ó��
			}
			else
				link_else_station(index);
			
			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Seongsu")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "�ż���")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Sinjeong")
		{
			if (edge[index]->Getsource() == "�ŵ���")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��ġ��")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line3")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line4")
		{
			if (edge[index]->Getsource() == "���")
				link_first_station(index);
			else if (edge[index]->Getdest() == "���̵�")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else if (edge[index]->Getdest() == "�ϳ��˴ܻ�")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5_Macheon")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��õ")
				link_last_station(index);
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
			else if (edge[index]->Getsource() == "����")	// �ܹ��� ���� ó��(last ó��)
			{
				for (int i = 0; i < 5;i++)					// ���� -> �ұ� -> ������ -> ���ų� -> ���� -> ����
				{
					link_first_station(index);
					index++;
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
			else if (edge[index]->Getdest() == "���")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line8")
		{
			if (edge[index]->Getsource() == "�ϻ�")
				link_first_station(index);
			else if (edge[index]->Getdest() == "���")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line9")
		{
			if (edge[index]->Getsource() == "��ȭ")
				link_first_station(index);
			else if (edge[index]->Getdest() == "�߾Ӻ��ƺ���")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon1")
		{
			if (edge[index]->Getsource() == "���")
				link_first_station(index);
			else if (edge[index]->Getdest() == "�۵��޺���������")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon2")
		{
			if (edge[index]->Getsource() == "�˴ܿ���")
				link_first_station(index);
			else if (edge[index]->Getdest() == "�")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Suinbundang")
		{
			if (edge[index]->Getsource() == "û����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��õ")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Sinbundang")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongui_Jungang")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Airport")
		{
			if (edge[index]->Getsource() == "���￪")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��õ����2�͹̳�")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongchun")
		{
			if (edge[index]->Getsource() == "û����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��õ")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Uijeongbu")
		{
			if (edge[index]->Getsource() == "�߰�")
				link_first_station(index);
			else if (edge[index]->Getdest() == "ž��")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Yongin")
		{
			if (edge[index]->Getsource() == "����")
				link_first_station(index);
			else if (edge[index]->Getdest() == "���뿡������")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeonggang")
		{
			if (edge[index]->Getsource() == "�Ǳ�")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Wooyi")
		{
			if (edge[index]->Getsource() == "�ż���")
				link_first_station(index);
			else if (edge[index]->Getdest() == "���ѻ����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Seahae")
		{
			if (edge[index]->Getsource() == "�һ�")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gimpo_Gold")
		{
			if (edge[index]->Getsource() == "��������")
				link_first_station(index);
			else if (edge[index]->Getdest() == "����")
				link_last_station(index);
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
*/
void MakeGraph::link_first_station(int index)
{
	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// �ҿ��	  <- line1, 4��
	edge[index]->Setnext(station[next_station_index]);				// line1, 4�� -> ����õ

	station[now_station_index]->Setnext(edge[index]);				// �ҿ��	  -> line1, 4�� (<- null������ �⺻ ���� null�̹Ƿ� ������ �������� �ʴ´�.)
	
}

/*
 �Լ� �̸� : link_else_station
 �Լ� ��� : ���� ù��° ������ ���� �ƴ϶�� �� ���� ����Ű�� �������� ����Ų��.
*/
void MakeGraph::link_else_station(int index)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// �� ���� �̾���
	edge[index]->Setnext(station[next_station_index]);				// ���� ���� �̾���

	station[now_station_index]->Setpre(edge[preidx]);				// line1, 4�� <- ����õ
	station[now_station_index]->Setnext(edge[index]);				// ����õ	  -> line1, 3��
}

/*
 �Լ� �̸� : link_last_station
 �Լ� ��� : ���� ������ ���̶�� ���� ���� null�� ó���Ѵ�.
*/
void MakeGraph::link_last_station(int index)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// ����õ	  <- line1, 3��
	edge[index]->Setnext(station[next_station_index]);				// line1, 3�� -> ��õ

	station[now_station_index]->Setpre(edge[preidx]);				// line1, 2�� <- ����õ
	station[now_station_index]->Setnext(edge[index]);				// ����õ     -> line1, 3��

	station[next_station_index]->Setpre(edge[index]);				// line1, 3�� <- ��õ (-> null������ �⺻ ���� null�̹Ƿ� ������ �������� �ʴ´�.)
}


/*
 �Լ� �̸� : link_line2_circle
 �Լ� ��� : 2ȣ�� ��ȯ�� ���� �ذ�
*/
void MakeGraph::link_line2_circle(int index)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// ������	  <- line2, 3��
	edge[index]->Setnext(station[next_station_index]);				// line2, 3�� -> ��û

	station[now_station_index]->Setpre(edge[preidx]);				// line2, 3�� <- ��û
	station[next_station_index]->Setnext(edge[index]);				// ��û  	  -> line2, 2��(�������Ա�)
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

void print_map()
{
	SubwayStation* p = nullptr;

	int i = 0;

	while(!p)
	{
		
	}
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










/*
void MakeGraph::link_first_station(int index)
{
	edge[index]->Setpre(nullptr);											// null   <- �ҿ��
	edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// �ҿ�� -> ����õ

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

	//station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// �ҿ�� <-> ����õ�� 4���� ����Ѵ�.
}

void MakeGraph::link_else_station(int index)
{
	edge[index]->Setpre(station[SearchIndex(edge[--index]->Getsource())]);	// �� ���� �̾���
	edge[++index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);	// ���� ���� �̾���

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation�� ��߿� �ε����� ���Ѵ�.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation�� ������ �ε����� ���Ѵ�.

	station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// ����õ <-> ������ 3���� ����Ѵ�.
}
*/