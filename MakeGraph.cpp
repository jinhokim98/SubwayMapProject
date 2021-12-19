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

	stationinfo.close();
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

	fin.close();
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

		else if (edge[index]->GetSubwayLine() == "line2") // ��ȯ�� ���� ����
		{
			if (edge[index]->Getsource() == "��û")
				link_first_station(index);
			else if (edge[index]->Getdest() == "��û")
				link_last_station(index);				 
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
			else if (edge[index]->Getsource() == "����")	// �ܹ��� ���� ó��
			{
				link_line6_one_way_problem(index, "����");
				index++;									// ���Ͽ��� �������� �ű�

				for (int i = 0; i < 5;i++)					// ���� -> �ұ� -> ������ -> ���ų� -> ���� -> ����
				{
					link_line6_one_way_problem(index, "not����");
					index++;
				}
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
 �Լ� �̸� : link_line6_one_way_problem
 �Լ� ��� : 6ȣ���� �ܹ��� ������ �ذ����ش�.
			 �����̸� �� ���� ������ �̾��־���Ѵ�.
			 ������ �ƴϸ� ���� �̾����� �ʾƾ� �Ѵ�.
*/
void MakeGraph::link_line6_one_way_problem(int index, string name)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(nullptr);									// �� �� null
	edge[index]->Setnext(station[next_station_index]);				// ���� ���� �̾���

	if(name == "����")
		station[now_station_index]->Setpre(edge[preidx]);			// line6, 2�� <- ����
	else
		station[now_station_index]->Setpre(nullptr);				// null       <- ����

	station[now_station_index]->Setnext(edge[index]);				// ����	  -> line6, 1��
}

/*
 �Լ� �̸� : Getdegree
 �Լ� ��� : �� ������ degree�� �����Ͽ� �����Ѵ�.
*/
void MakeGraph::Getdegree(SubwayStation** sub, Edge** edge)
{
	int i = 0;
	int j = 0;
	int next_i = 0;
	int sub_idx = 0;
	int exceptional_case = 0;

	string neighbor_table[STATION_NUMBER][8];
	string station_name[STATION_NUMBER];

	for (int k = 0; k < STATION_NUMBER; k++)
		for (int l = 0; l < 8; l++)
			neighbor_table[k][l] = "null";	// �ǹ̾��� ���ڷ� ä���


	// �ҿ�� �� �Է�ó�� ����
	exceptional_case = SearchIndex(edge[i]->Getsource());
	neighbor_table[exceptional_case][j] = "����õ";

	// ��ȯ�� ����
	exceptional_case = SearchIndex("��û");
	neighbor_table[exceptional_case][j++] = "������";
	neighbor_table[exceptional_case][j] = "�������Ա�";

	j = 0;

	for (i = 0; i < EDGE_NUMBER - 1; i++)
	{
		next_i = i + 1;

		if (edge[i]->Getdest() == edge[next_i]->Getsource()) // �Ϲ����� ���̽�
		{
			sub_idx = SearchIndex(edge[i]->Getdest());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j++] = edge[i]->Getsource();
			neighbor_table[sub_idx][j] = edge[next_i]->Getdest();
			j = 0;

		}
		else	// ȣ���� ù ���̰ų� ������ ���� ���
		{
			// �� �� ó��
			sub_idx = SearchIndex(edge[i]->Getdest());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j] = edge[i]->Getsource();
			j = 0;

			// ���� �� ó��
			sub_idx = SearchIndex(edge[next_i]->Getsource());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j] = edge[next_i]->Getdest();
			j = 0;

		}
	}
	
	// 6ȣ�� �ܹ��� ���� �ذ�
	for (i = 325; i < 331; i++)
	{
		exceptional_case = SearchIndex(edge[i]->Getdest());

		for (j = 0; j < 4; j++)	// �� ���� �� ���� �ִ� degree�� 4�̹Ƿ�
		{
			if (neighbor_table[exceptional_case][j] == edge[i]->Getsource())
				neighbor_table[exceptional_case][j] = "null";	// ex) ���Ͽ��� ������ �� �� �����Ƿ� �����ش�.

		}
	}

	for (i = 0;i < STATION_NUMBER;i++)
	{
		station_name[i] = sub[i]->GetSubwayStationName();
	}

	int count = 0;

	for (i = 0;i < STATION_NUMBER;i++)
	{
		cout << station_name[i] << " : ";

		for (j = 0;j < 8;j++)
		{
			if (neighbor_table[i][j] != "null")
			{
				cout << neighbor_table[i][j] << ", ";
				count++;
			}
		}
		cout << count << endl;

		count = 0;
	}

	// ���� ��������
	int count_degree = 0;	// �ߺ��� ������ ����
	int degree_table_number[STATION_NUMBER] = { 0, };

	for (i = 0; i < STATION_NUMBER; i++)
	{

	}
}

Edge** MakeGraph::GetEdgePointer()
{
	return edge;
}

SubwayStation** MakeGraph::GetSubwayPointer()
{
	return station;
}

/*
 �Լ� �̸� : link_transferStation
 �Լ� ��� : ȯ�¿��� ���� ������ ó�����ش�.
*/
void MakeGraph::link_transferStation(int index, int degree)
{
	
}

/*
 �Լ� �̸� : SearchIndex
 �Լ� ��� : �� �̸��� ã�� �ε����� ��ȯ
			 ������ �����˻������� ���߿� �����˻����� �ٲ� ��
*/
int MakeGraph::SearchIndex(string name)
{
	for (int index = 0; index < STATION_NUMBER; index++)
	{
		if (station[index]->GetSubwayStationName() == name)
			return index;
	}
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
	//makeLine();
}


SubwayStation* MakeGraph::GetStation(string station_name)
{
	int index = SearchIndex(station_name);
	return station[index];
}


SubwayStation* MakeGraph::GetStation(Edge* q)
{
	if (q == nullptr)
		return nullptr;

	return q->Getnext();
}

Edge* MakeGraph::GetEdge(SubwayStation* p)
{
	if (p == nullptr)
		return nullptr;

	return p->Getnext();
}


/*
 �Ҹ��� : ���������� ��ü �迭���� �����Ѵ�.
*/
MakeGraph::~MakeGraph()
{
	for (int i = 0;i < STATION_NUMBER;i++)
		delete station[i];

	for (int i = 0;i < EDGE_NUMBER;i++)
		delete edge[i];
}