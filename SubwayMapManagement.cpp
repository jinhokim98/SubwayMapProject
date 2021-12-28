#include <iostream>
#include "SubwayMapManagement.h"


using namespace std;

/*
 ������ : metro ��ü�� ���������ϰ� ����ö �뼱���� �����.
*/
SubwayMapManagement::SubwayMapManagement() : route(), short_route()
{
	metro = new MakeGraph;
	metro->init();

	transfer = 0;
	route_index = 0;
	
	for (int i = 0;i < STATION_NUMBER;i++)
	{
		distance_adj[i] = INF;
	}
}

void SubwayMapManagement::print_degree()
{
	Edge** pedge = metro->GetEdgePointer();
	SubwayStation** psub = metro->GetSubwayPointer();

	metro->Getdegree(psub, pedge);
}

void SubwayMapManagement::print_map()
{
	SubwayStation* p = metro->GetStation("����");
	Edge* q = nullptr;

	while (p->GetSubwayStationName() != "���")
	{
		cout << p->GetSubwayStationName() << ", ";

		q = p->Getadj(trans0_next);
		
		if (q == nullptr)
			break;

		cout << q->GetSubwayLine() << ", ";
		cout << q->Getdistance() << ", " << endl;

		p = q->Getnext();
	}
}

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

	priority_queue<pair<int, SubwayStation*>> queue;	// �켱���� ť ���
	SubwayStation* p = metro->GetStation(start);		// ��߿��� p�� ��´�.
	SubwayStation* move_p;
	SubwayStation* temp[8];	// ���� �ִ� degree�� 8�̹Ƿ�
	Edge* q[8];				// ���� �̾��� ������ ���� ����
	Edge* pre_q[8];			// ���� ���� �������� ���� (ȯ�¿���Ȯ��)
	bool first = true;		// ù��°�̸� ȯ������ �ʴ´�.

	for (i = 0;i < 8;i++)
		pre_q[i] = nullptr;

	queue.push(make_pair(0, p));

	distance_adj[start_index] = 0;					// ��߿����� ��߿��� 0��
	route[start_index] = p->GetSubwayStationName();	// ��߿� ǥ��

	while (queue.empty() != true) 
	{
		int distance = -queue.top().first;			// ť�� ž�� �ִ� �������� �Ÿ� ����
		move_p = queue.top().second;			    // ť�� ž�� �ִ� �� ����
		queue.pop();
		
		for (i = 0; i < 8;i++)
			temp[i] = move_p;
						
		for (i = 0;i < 8;i++) // �ش� ������ �� �� �ִ� ��� ���� Ž��
		{
			q[i] = temp[i]->Getadj(i);

			if (q[i] == nullptr)
				continue;

			if (first != true)
			{
				if (pre_q[i] != nullptr)
				{
					if (pre_q[i]->GetSubwayLine() == q[i]->GetSubwayLine()) // �� ������ ȣ���� �� ������ ȣ���� ���ٸ�
						next_cost = q[i]->Getdistance();		// ������������ �Ÿ��� �����صд�.
					else
						next_cost = q[i]->Getdistance() + 3;	// ȯ�½� 3�� �߰�
				}
			}
			else // ù��° �õ��� ��� ȯ���� �ƴϱ� ������ ȯ�¿��θ� �������� �ʰ� �Ÿ��� �߰�
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
				route[nextidx] = move_p->GetSubwayStationName();		// ��Ʈ�迭�� �� �� ���� ����
				queue.push(make_pair(-distance_adj[nextidx], temp[i]));	// ���� �Ÿ��� ���� ���� Ǫ���Ѵ�.
			}

			if (temp[i]->GetSubwayStationName() == goal)
			{
				return true;
			}

			next_cost = INF;				// ���簡 ������ �ٽ� inf��
			pre_q[i] = q[i];				// �� �� pre�� ����
		}

		first = false;
	}
	
	return false;
}

void SubwayMapManagement::print_path(string start, string goal)
{
	int start_idx = metro->SearchIndex(start);
	int goal_idx = metro->SearchIndex(goal);
	
	int index = goal_idx;

	short_route[route_index++] = goal;	// ������ ��Ʈ�� ����

	while (route[index] != start)
	{
		short_route[route_index++] = route[index];
		index = metro->SearchIndex(route[index]);
	}

	int i = route_index - 1;

	cout << start << " -> ";

	while (i >= 0)
	{
		cout << short_route[i] << " -> ";
		i--;
	}

	cout << endl;
	cout << distance_adj[goal_idx] << "��" << endl;
}


/*
 �Ҹ��� : ���������� metro ��ü�� �����.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
