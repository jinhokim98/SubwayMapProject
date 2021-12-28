#include <iostream>
#include "SubwayMapManagement.h"


using namespace std;

/*
 생성자 : metro 객체를 동적생성하고 지하철 노선도를 만든다.
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
	SubwayStation* p = metro->GetStation("논현");
	Edge* q = nullptr;

	while (p->GetSubwayStationName() != "장암")
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
		cout << "입력하신 역은 없는 역입니다." << endl;
		exit(100);
	}

	priority_queue<pair<int, SubwayStation*>> queue;	// 우선순위 큐 사용
	SubwayStation* p = metro->GetStation(start);		// 출발역을 p에 담는다.
	SubwayStation* move_p;
	SubwayStation* temp[8];	// 역의 최대 degree가 8이므로
	Edge* q[8];				// 역에 이어진 엣지를 담을 변수
	Edge* pre_q[8];			// 전의 역의 엣지정보 저장 (환승여부확인)
	bool first = true;		// 첫번째이면 환승하지 않는다.

	for (i = 0;i < 8;i++)
		pre_q[i] = nullptr;

	queue.push(make_pair(0, p));

	distance_adj[start_index] = 0;					// 출발역에서 출발역은 0분
	route[start_index] = p->GetSubwayStationName();	// 출발역 표시

	while (queue.empty() != true) 
	{
		int distance = -queue.top().first;			// 큐의 탑에 있는 역까지의 거리 저장
		move_p = queue.top().second;			    // 큐의 탑에 있는 역 저장
		queue.pop();
		
		for (i = 0; i < 8;i++)
			temp[i] = move_p;
						
		for (i = 0;i < 8;i++) // 해당 역에서 갈 수 있는 모든 역을 탐색
		{
			q[i] = temp[i]->Getadj(i);

			if (q[i] == nullptr)
				continue;

			if (first != true)
			{
				if (pre_q[i] != nullptr)
				{
					if (pre_q[i]->GetSubwayLine() == q[i]->GetSubwayLine()) // 전 엣지의 호선과 현 엣지의 호선이 같다면
						next_cost = q[i]->Getdistance();		// 다음역까지의 거리를 저장해둔다.
					else
						next_cost = q[i]->Getdistance() + 3;	// 환승시 3분 추가
				}
			}
			else // 첫번째 시도일 경우 환승이 아니기 때문에 환승여부를 생각하지 않고 거리만 추가
			{
				next_cost = q[i]->Getdistance();
			}

			if (i % 2 == 0)		// next
				temp[i] = q[i]->Getnext();
			else				// pre
				temp[i] = q[i]->Getpre();

			// 포인터로 도착한 다음 역의 인덱스 알기
			string next_station = temp[i]->GetSubwayStationName();
			int nextidx = metro->SearchIndex(next_station);

			// 현 최단거리보다 새롭게 찾은 경로의 거리가 더 짧다면 짧은 거리로 갱신한 후 queue에 푸시
			if (distance_adj[nextidx] > distance + next_cost)
			{
				distance_adj[nextidx] = distance + next_cost;
				route[nextidx] = move_p->GetSubwayStationName();		// 루트배열에 전 역 정보 저장
				queue.push(make_pair(-distance_adj[nextidx], temp[i]));	// 다음 거리와 다음 역을 푸시한다.
			}

			if (temp[i]->GetSubwayStationName() == goal)
			{
				return true;
			}

			next_cost = INF;				// 조사가 끝나면 다시 inf로
			pre_q[i] = q[i];				// 전 역 pre에 저장
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

	short_route[route_index++] = goal;	// 도착역 루트에 저장

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
	cout << distance_adj[goal_idx] << "분" << endl;
}


/*
 소멸자 : 동적생성한 metro 객체를 지운다.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
