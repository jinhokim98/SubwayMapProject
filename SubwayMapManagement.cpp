#include <iostream>
#include "SubwayMapManagement.h"


using namespace std;

/*
 ������ : metro ��ü�� ���������ϰ� ����ö �뼱���� �����.
*/
SubwayMapManagement::SubwayMapManagement() : short_route()
{
	metro = new MakeGraph;
	metro->init();

	route_index = 0;
	
	for (int i = 0;i < STATION_NUMBER;i++)
	{
		distance_adj[i] = INF;
	}
}

/*
 �Լ� �̸� : CheckStationName
 �Լ� ��� : UI�κ��� ���� �� �̸��� �����ϴ��� Ȯ��
 ���� : string station �� �̸�
 ��ȯ�� : true or false
*/
bool SubwayMapManagement::CheckStationName(string station)
{
	int request = metro->SearchIndex(station);

	if (request == -1)
		return false;
	else
		return true;
}

/*
 �Լ� �̸� : Shortest_route
 �Լ� ��� : ��߿��� �������� �ִ� �Ÿ��� ��Ʈ�� ����Ѵ�.
 ���� : string start : ��߿�
		string goal  : ������
 ��ȯ�� : true or false : ������ print_path ����, ���н� ���α׷� ����
*/
bool SubwayMapManagement::Shortest_route(string start, string goal)
{
	int i = 0;
	int next_cost = INF;

	int start_index = metro->SearchIndex(start);
	int goal_index = metro->SearchIndex(goal);
	
	if (start_index == -1 || goal_index == -1)
	{
		cout << "�Է��Ͻ� ���� ���� ���Դϴ�." << endl;
		exit(100);
	}

	priority_queue<tuple<int, Edge*, SubwayStation*>> queue;	// �� �������� ��� �켱���� ť

	SubwayStation* p = metro->GetStation(start);				// ��߿��� p�� ��´�.
	SubwayStation* temp[8];	// ���� �ִ� degree�� 8�̹Ƿ�
	Edge* q[8];				// ���� �̾��� ������ ���� ����
	
	string pre_linenum;		// �� ������ ȣ������
	SubwayStation* preStation = nullptr;

	bool first = true;		// ù��°�̸� ȯ������ �ʴ´�.

	queue.push(make_tuple(0, nullptr, p));
	distance_adj[start_index] = 0;					// ��߿����� ��߿��� 0��
	route[start_index] = make_pair(p->GetSubwayStationName(), " ");	// ��߿� ǥ��, ������ ���� �̵����� �ʾ������� ����

	while (queue.empty() != true) 
	{
		int distance = -get<0>(queue.top());			// ť�� ž�� �ִ� �������� �Ÿ� ����
		Edge* pre_edge = get<1>(queue.top());			// ���� �� ����
		SubwayStation* move_p = get<2>(queue.top());	// ť�� ž�� �ִ� �� ����
		queue.pop();

		if (first != true)
			preStation = FindPreStation(move_p, pre_edge);	// ���ؼ� ���� ���� �� ���� ���Ѵ�.
		
		for (i = 0; i < 8;i++)							// �� ���� ���� ������ �ֽ�ȭ
			temp[i] = move_p;
						
		for (i = 0;i < 8;i++)			// �ش� ������ �� �� �ִ� ��� ���� Ž��
		{
			q[i] = temp[i]->Getadj(i);

			if (q[i] == nullptr)
				continue;

			if (first != true)
			{
				if (pre_edge->GetSubwayLine() == q[i]->GetSubwayLine()) // �� ������ ȣ���� �� ������ ȣ���� ���ٸ�
					next_cost = q[i]->Getdistance();		// ������������ �Ÿ��� �����صд�.
				else
					next_cost = q[i]->Getdistance() + 3;	// ȯ�½� 3�� �߰�
			}
			else	// ù��° �õ��� ��� ȯ���� �ƴϱ� ������ ȯ�¿��θ� �������� �ʰ� �Ÿ��� �߰�
			{
				next_cost = q[i]->Getdistance();
			}

			if (i % 2 == 0)		// next
				temp[i] = q[i]->Getnext();
			else				// pre
				temp[i] = q[i]->Getpre();

			// �����ͷ� ������ ���� ���� �ε��� �˱�
			string next_station = temp[i]->GetSubwayStationName();
			int nextidx = metro->SearchIndex(next_station);

			// �� �ִܰŸ����� ���Ӱ� ã�� ����� �Ÿ��� �� ª�ٸ� ª�� �Ÿ��� ������ �� queue�� Ǫ��
			if (distance_adj[nextidx] > distance + next_cost)
			{
				distance_adj[nextidx] = distance + next_cost;
				route[nextidx].first = move_p->GetSubwayStationName();		// ��Ʈ�迭�� �� �� ���� ����
				route[nextidx].second = q[i]->GetSubwayLine();				// ���� ������ ȣ������ ����
				queue.push(make_tuple(-distance_adj[nextidx], q[i], temp[i]));	// ���� �Ÿ��� ���� ���� Ǫ���Ѵ�.
			}

			next_cost = INF;				// ���簡 ������ �ٽ� inf��
		}

		first = false;						// ó���� �ƴϸ� ȯ���� ������ �����Ƿ� �ٲ��ش�.
	}
	
	if (distance_adj[goal_index] != INF)	// �Ÿ� �迭�� ���Ѵ밡 �ƴϸ� �ִܷ�Ʈ �˻� ����
		return true;
	else
		return false;
}

/*
 �Լ� �̸� : FindPreStation
 �Լ� ��� : �˿��� ���� ���� �� ���� ���Ѵ�. 
 ���� : SubwayStation* move_p : ť���� ���� ��: ���� ��
		Edge* pre_edge		  : ť���� ���� �� ����
 ��ȯ�� : �� ��
 */
SubwayStation* SubwayMapManagement::FindPreStation(SubwayStation* move_p, Edge* pre_edge)
{
	Edge* q = pre_edge;
	SubwayStation* p = nullptr;

	if (q->Getnext() == move_p) // q�� ������ ���� ���� ���ٸ� q�� ���� ��ȯ
		p = q->Getpre();
	else if (q->Getpre() == move_p) // q�� ���� ���� ���� ���ٸ� q�� ������ ��ȯ
		p = q->Getnext();
	
	return p;

}

/*
 �Լ� �̸� : print_path
 �Լ� ��� : �ִܰ�θ� ����Ѵ�.
 ���� : string start : ��߿�
		string goal  : ������
 ��ȯ�� : ����
 */
void SubwayMapManagement::print_path(string start, string goal)
{
	int start_idx = metro->SearchIndex(start);
	int goal_idx = metro->SearchIndex(goal);
	
	int index = goal_idx;

	int transfer = 0;
	

	short_route[route_index] = goal;	// ������ ��Ʈ�� ����
	line_info[route_index++] = " ";		// ��Ʈ ������ ���������� �����ϹǷ� ���� �̵��� ����.

	while (route[index].first != start)
	{
		short_route[route_index] = route[index].first;
		line_info[route_index++] = route[index].second;
		index = metro->SearchIndex(route[index].first);
	}

	int i = route_index - 1;

	cout << start << " -> ";

	while (i >= 0)
	{
		cout << short_route[i] << " -> ";
		i--;
	}

	cout << endl;
	cout << start << "���� " << goal << "�� ������ �ִܰŸ��� ";
	cout << distance_adj[goal_idx] << "�� �Դϴ�." << endl;

	for (i = 1; i < route_index - 2; i++)	//  ù ��° �迭�� ���� " " �̹Ƿ� ����
	{
		int j = i + 1;

		if (line_info[i] != line_info[j])
			transfer++;
	}

	cout << "�� ȯ��Ƚ���� " << transfer << "ȸ �Դϴ�." << endl;
}

/*
 �Լ� �̸� : print_degree (�����)
 �Լ� ��� : �� ���� degree�� �˰� �; ����ߴ�.(�޴��� �������� ����)
 ���� : ����
 ��ȯ�� : ����
*/
void SubwayMapManagement::print_degree()
{
	Edge** pedge = metro->GetEdgePointer();
	SubwayStation** psub = metro->GetSubwayPointer();

	metro->Getdegree(psub, pedge);
}


/*
 �Ҹ��� : ���������� metro ��ü�� �����.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
