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
	int edgenum;

	while (!stationinfo.eof())
	{
		stationinfo >> subwayname;
		stationinfo >> edgenum;

		station[index++] = new SubwayStation(subwayname, edgenum);	// �� ��ü �迭 ���� (�������)
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
		if (index >= EDGE_NUMBER) // ������ ������ ���� �߰����� �� �ݺ��� Ż��
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

		else if (edge[index]->GetSubwayLine() == "line6") // �ܹ��� ���� ó�� �ʿ�(�̰� ������ �� �ʹ�.)
		{
			if (edge[index]->Getsource() == "�ų�")
			{
				link_first_station(index);
			}
			else if (edge[index]->Getsource() == "����")	// �ܹ��� ���� ó�� // ���� -> �ұ� -> ������ -> ���ų� -> ���� -> ����
			{
				link_line6_one_way_problem(index, "����", false);
				index++;

				link_line6_one_way_problem(index, "����", false);
				index++;

				link_line6_one_way_problem(index, "�ұ�", true);
				index++;

				link_line6_one_way_problem(index, "������", false);
				index++;

				link_line6_one_way_problem(index, "���ų�", true);
				index++;

				link_line6_one_way_problem(index, "����", false);
			}
			else
				link_else_station(index);

			index++;
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

	link_station(firstcase, index, now_station_index, next_station_index, station[now_station_index]->Getedgenum());
}

/*
 �Լ� �̸� : link_else_station
 �Լ� ��� : ���� ù��° ������ ���� �ƴ϶�� �� ���� ����Ű�� �������� ����Ų��.
*/
void MakeGraph::link_else_station(int index)
{
	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// �� ���� �̾���
	edge[index]->Setnext(station[next_station_index]);				// ���� ���� �̾���

	link_station(elsecase, index, now_station_index, next_station_index, station[now_station_index]->Getedgenum());
}

/*
 �Լ� �̸� : link_last_station
 �Լ� ��� : ���� ������ ���̶�� ���� ���� null�� ó���Ѵ�.
*/
void MakeGraph::link_last_station(int index)
{
	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(station[now_station_index]);				// ����õ	  <- line1, 3��
	edge[index]->Setnext(station[next_station_index]);				// line1, 3�� -> ��õ

	link_station(lastcase, index, now_station_index, next_station_index, station[now_station_index]->Getedgenum());
}

/*
 �Լ� �̸� : link_line6_one_way_problem
 �Լ� ��� : 6ȣ���� �ܹ��� ������ �ذ����ش�.
			 �����̸� �� ���� ������ �̾��־���Ѵ�.
			 ������ �ƴϸ� ���� �̾����� �ʾƾ� �Ѵ�.
*/
void MakeGraph::link_line6_one_way_problem(int index, string name, bool Is_transfer_station)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// ���� �� �ε��� ����
	int next_station_index = SearchIndex(edge[index]->Getdest());	// ���� �� �ε��� ����

	edge[index]->Setpre(nullptr);									// �� �� null
	edge[index]->Setnext(station[next_station_index]);				// ���� ���� �̾���

	if (name == "����")
	{
		station[now_station_index]->Setadj(edge[preidx], trans0_pre);	// line6, 2�� <- ����
		station[now_station_index]->Setadj(edge[index], trans0_next);	// ����	  -> line6, 1��
	}
	else if (Is_transfer_station == false)	// ȯ�¿��� �ƴ� ���
	{
		station[now_station_index]->Setadj(nullptr, trans0_pre);		// null       <- ����
		station[now_station_index]->Setadj(edge[index], trans0_next);	// ����	  -> line6, 1��
	}
	else
	{
		station[now_station_index]->Setadj(nullptr, trans1_pre);		// 6ȣ���� 3ȣ������ �ʰ� ��������Ƿ� trans1�̴�. 
		station[now_station_index]->Setadj(edge[index], trans1_next);	// ����	  -> line6, 1��
	}
		
}


/*
 �Լ� �̸� : link_station
 �Լ� ��� : station�� edge* ��������� ä���ش�.

 ���� : int loc		: first=0, else=1, last=2,
		int index	: edge�� �ε��� ��
		int now_station_index : ���� ��
		int next_station_index: ���� ��
		int degree	: ���� ���� edge ��
 ��ȯ�� : ����
*/
void MakeGraph::link_station(int loc, int index, int now_station_index, int next_station_index, int degree)
{
	if (degree <= 2)	// ȯ�¿��� �ƴ� ��
		link_station_case(loc, index, now_station_index, next_station_index, trans0_next, trans0_pre, degree);
	else
	{
		// ȯ�¿������� ���� �����Ͱ� ä������ ���� ���
		if (station[now_station_index]->Getadj(trans0_next) == nullptr && station[now_station_index]->Getadj(trans0_pre) == nullptr)
			link_station_case(loc, index, now_station_index, next_station_index, trans0_next, trans0_pre, degree);
		
		else
		{
			if(station[now_station_index]->Getadj(trans1_next) == nullptr && station[now_station_index]->Getadj(trans1_pre) == nullptr)
				link_station_case(loc, index, now_station_index, next_station_index, trans1_next, trans1_pre, degree);
			
			else
			{
				if (station[now_station_index]->Getadj(trans2_next) == nullptr && station[now_station_index]->Getadj(trans2_pre) == nullptr)
					link_station_case(loc, index, now_station_index, next_station_index, trans2_next, trans2_pre, degree);
				else
					link_station_case(loc, index, now_station_index, next_station_index, trans3_next, trans3_pre, degree);
			}
		}	
	}
}
			

/*
 �Լ� �̸� : link_station_case
 �Լ� ��� : station�� edge* ��������� ȯ�¿��� ���� �ٸ��� �������ִ� �Լ�
 
 ���� : int loc		: first=0, else=1, last=2,
		int index	: edge�� �ε��� ��
		int now_station_index : ���� ��
		int next_station_index: ���� ��
		int next	: ���� ����
		int pre	    : �� ����
 ��ȯ�� : ����
*/
void MakeGraph::link_station_case(int loc, int index, int now_station_index, int next_station_index, int next, int pre, int degree)
{
	int check = next_station_index;
	int preidx = index - 1;	// edge��ü �迭�� �� index
	int check_next_station = 0;

	switch (loc)
	{
	case 0: // ù ��
		station[now_station_index]->Setadj(edge[index], next); // �ҿ��	-> line1, 4��
		break;
	case 1:	// ������ ��
		station[now_station_index]->Setadj(edge[preidx], pre); // line1, 4�� <- ����õ
		station[now_station_index]->Setadj(edge[index], next); // ����õ	-> line1, 3��
		break;
	case 2:	// ������ ��
		station[now_station_index]->Setadj(edge[preidx], pre); // line1, 2�� <- ����õ
		station[now_station_index]->Setadj(edge[index], next); // ����õ     -> line1, 3��
		
		// ��ġ��, ���, ���￪, ��û, �ż���, ����, ���̵�, ��õ�� ����
		if(check != 102 && check != 207 && check != 302 && check != 358 && check != 380 && check != 445 && check != 453 && check != 500) // 
			station[next_station_index]->Setadj(edge[index], pre); // line1, 3�� <- ��õ
		else
		{
			check_next_station = check_next_station_case(check);
			station[next_station_index]->Setadj(edge[index], check_next_station);
		}
		break;
	}
}

/*
 �Լ� �̸� : check_next_station_case
 �Լ� ��� : ���� ���� ������ ���� �� �� ���� ȯ�¿��� ��� ������ �ذ� 

 ���� : int next_station_index: ���� ��
 ��ȯ�� : ����
*/
int MakeGraph::check_next_station_case(int next_station_index)
{
	if (next_station_index == 500) // ���κд� ��õ
		return trans1_pre;
	else if (next_station_index == 302)
		return trans2_pre;
	else
		return trans1_pre;

	/*
		else if (next_station_index == 102)
		return trans0_pre;
	*/
}

/*
 �Լ� �̸� : Getdegree
 �Լ� ��� : �� ������ degree�� �����Ͽ� �����Ѵ�.
			 stationName�� ȯ�¿� degree���� ���ϱ� ���� ����Ͽ���.
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

	// ���̿� �Է�ó�� ����
	exceptional_case = SearchIndex("����");
	neighbor_table[exceptional_case][j] = "����";
	j = 0;

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

	int k = 0;
	int degree_table_number[STATION_NUMBER] = { 0, };

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

	return -1;
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

Edge* MakeGraph::GetEdge(SubwayStation* p, int pointer_num)
{
	if (p == nullptr)
		return nullptr;

	return p->Getadj(pointer_num);
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
