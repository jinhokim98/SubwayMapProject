#include <iostream>
#include "SubwayMapManagement.h"


using namespace std;

/*
 생성자 : metro 객체를 동적생성하고 지하철 노선도를 만든다.
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
 함수 이름 : CheckStationName
 함수 기능 : UI로부터 받은 역 이름이 존재하는지 확인
 인자 : string station 역 이름
 반환값 : true or false
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
 함수 이름 : Shortest_route
 함수 기능 : 출발역과 도착역의 최단 거리와 루트를 계산한다.
 인자 : string start : 출발역
		string goal  : 도착역
 반환값 : true or false : 성공시 print_path 실행, 실패시 프로그램 종료
*/
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

	priority_queue<tuple<int, Edge*, SubwayStation*>> queue;	// 전 엣지까지 담는 우선순위 큐

	SubwayStation* p = metro->GetStation(start);				// 출발역을 p에 담는다.
	SubwayStation* temp[8];	// 역의 최대 degree가 8이므로
	Edge* q[8];				// 역에 이어진 엣지를 담을 변수
	
	string pre_linenum;		// 전 엣지의 호선정보
	SubwayStation* preStation = nullptr;

	bool first = true;		// 첫번째이면 환승하지 않는다.

	queue.push(make_tuple(0, nullptr, p));
	distance_adj[start_index] = 0;					// 출발역에서 출발역은 0분
	route[start_index] = make_pair(p->GetSubwayStationName(), " ");	// 출발역 표시, 엣지는 아직 이동하지 않았음으로 공백

	while (queue.empty() != true) 
	{
		int distance = -get<0>(queue.top());			// 큐의 탑에 있는 역까지의 거리 저장
		Edge* pre_edge = get<1>(queue.top());			// 역의 전 엣지
		SubwayStation* move_p = get<2>(queue.top());	// 큐의 탑에 있는 역 저장
		queue.pop();

		if (first != true)
			preStation = FindPreStation(move_p, pre_edge);	// 팝해서 나온 역의 전 역을 구한다.
		
		for (i = 0; i < 8;i++)							// 전 역을 현재 역으로 최신화
			temp[i] = move_p;
						
		for (i = 0;i < 8;i++)			// 해당 역에서 갈 수 있는 모든 역을 탐색
		{
			q[i] = temp[i]->Getadj(i);

			if (q[i] == nullptr)
				continue;

			if (first != true)
			{
				if (pre_edge->GetSubwayLine() == q[i]->GetSubwayLine()) // 전 엣지의 호선과 현 엣지의 호선이 같다면
					next_cost = q[i]->Getdistance();		// 다음역까지의 거리를 저장해둔다.
				else
					next_cost = q[i]->Getdistance() + 3;	// 환승시 3분 추가
			}
			else	// 첫번째 시도일 경우 환승이 아니기 때문에 환승여부를 생각하지 않고 거리만 추가
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
				route[nextidx].first = move_p->GetSubwayStationName();		// 루트배열에 전 역 정보 저장
				route[nextidx].second = q[i]->GetSubwayLine();				// 다음 엣지의 호선정보 저장
				queue.push(make_tuple(-distance_adj[nextidx], q[i], temp[i]));	// 다음 거리와 다음 역을 푸시한다.
			}

			next_cost = INF;				// 조사가 끝나면 다시 inf로
		}

		first = false;						// 처음이 아니면 환승의 여지가 있으므로 바꿔준다.
	}
	
	if (distance_adj[goal_index] != INF)	// 거리 배열이 무한대가 아니면 최단루트 검색 성공
		return true;
	else
		return false;
}

/*
 함수 이름 : FindPreStation
 함수 기능 : 팝에서 나온 역의 전 역을 구한다. 
 인자 : SubwayStation* move_p : 큐에서 팝한 역: 현재 역
		Edge* pre_edge		  : 큐에서 팝한 전 엣지
 반환값 : 전 역
 */
SubwayStation* SubwayMapManagement::FindPreStation(SubwayStation* move_p, Edge* pre_edge)
{
	Edge* q = pre_edge;
	SubwayStation* p = nullptr;

	if (q->Getnext() == move_p) // q의 다음이 팝한 역과 같다면 q의 전을 반환
		p = q->Getpre();
	else if (q->Getpre() == move_p) // q의 전이 팝한 역과 같다면 q의 다음을 반환
		p = q->Getnext();
	
	return p;

}

/*
 함수 이름 : print_path
 함수 기능 : 최단경로를 출력한다.
 인자 : string start : 출발역
		string goal  : 도착역
 반환값 : 없음
 */
void SubwayMapManagement::print_path(string start, string goal)
{
	int start_idx = metro->SearchIndex(start);
	int goal_idx = metro->SearchIndex(goal);
	
	int index = goal_idx;

	int transfer = 0;
	

	short_route[route_index] = goal;	// 도착역 루트에 저장
	line_info[route_index++] = " ";		// 루트 추적을 도착역부터 시작하므로 엣지 이동이 없다.

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
	cout << start << "역과 " << goal << "역 사이의 최단거리는 ";
	cout << distance_adj[goal_idx] << "분 입니다." << endl;

	for (i = 1; i < route_index - 2; i++)	//  첫 번째 배열의 값은 " " 이므로 제외
	{
		int j = i + 1;

		if (line_info[i] != line_info[j])
			transfer++;
	}

	cout << "총 환승횟수는 " << transfer << "회 입니다." << endl;
}

/*
 함수 이름 : print_degree (시험용)
 함수 기능 : 각 역의 degree를 알고 싶어서 사용했다.(메뉴에 구현하지 않음)
 인자 : 없음
 반환값 : 없음
*/
void SubwayMapManagement::print_degree()
{
	Edge** pedge = metro->GetEdgePointer();
	SubwayStation** psub = metro->GetSubwayPointer();

	metro->Getdegree(psub, pedge);
}


/*
 소멸자 : 동적생성한 metro 객체를 지운다.
*/
SubwayMapManagement::~SubwayMapManagement()
{
	delete metro;
}
