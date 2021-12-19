#include <iostream>
#include <fstream>
#include "makeGraph.h"

using namespace std;

ifstream stationinfo;
ifstream fin;

/*
 생성자 : 그래프를 만들 준비 : 파일을 연다.
*/
MakeGraph::MakeGraph()
{
	stationinfo.open("stationName.txt");

	if (stationinfo.fail())
	{
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}

	fin.open("station.txt");

	if (fin.fail())
	{
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}

	*station = nullptr;
	*edge = nullptr;
}

/*
 함수 이름 : initStation
 함수 기능 : 역 객체 생성
*/
void MakeGraph::initStation()
{
	int index = 0;

	string subwayname;

	while (!stationinfo.eof())
	{
		stationinfo >> subwayname;

		station[index++] = new SubwayStation(subwayname);	// 역 객체 배열 생성 (순서대로)
	}

	stationinfo.close();
}

/*
 함수 이름 : initEdge
 함수 기능 : 엣지 객체 생성
*/
void MakeGraph::initEdge()
{
	int index = 0;

	string linenum;			// 호선 번호
	string source;			// 출발역
	string dest;			// 도착역
	int distance;			// 역 간 거리

	while (!fin.eof())
	{
		fin >> linenum;
		fin >> source;
		fin >> dest;
		fin >> distance;

		edge[index++] = new Edge(linenum, source, dest, distance);	// 엣지 배열 생성 (순서대로)
	}

	fin.close();
}


/*
 함수 이름 : makeLine
 함수 기능 : 역 객체와 엣지 객체를 사용하여 호선을 이어준다.
*/
void MakeGraph::makeLine()
{
	int index = 0;

	// 노선 만들기(1호선 ~ 김포골드라인)
	while (true)
	{
		if (index > EDGE_NUMBER) // 마지막 역까지 전부 추가했을 때 반복문 탈출
			break;

		if (edge[index]->GetSubwayLine() == "line1")
		{
			if (edge[index]->Getsource() == "소요산")
				link_first_station(index);
			else if (edge[index]->Getdest() == "인천")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line1_Sinchang") // 지선일 경우 다시 한 번 생각해보자
		{
			if (edge[index]->Getsource() == "구로")
				link_first_station(index);
			else if (edge[index]->Getdest() == "신창")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2") // 순환선 문제 없음
		{
			if (edge[index]->Getsource() == "시청")
				link_first_station(index);
			else if (edge[index]->Getdest() == "시청")
				link_last_station(index);				 
			else
				link_else_station(index);
			
			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Seongsu")
		{
			if (edge[index]->Getsource() == "성수")
				link_first_station(index);
			else if (edge[index]->Getdest() == "신설동")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Sinjeong")
		{
			if (edge[index]->Getsource() == "신도림")
				link_first_station(index);
			else if (edge[index]->Getdest() == "까치산")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line3")
		{
			if (edge[index]->Getsource() == "대화")
				link_first_station(index);
			else if (edge[index]->Getdest() == "오금")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line4")
		{
			if (edge[index]->Getsource() == "당고개")
				link_first_station(index);
			else if (edge[index]->Getdest() == "오이도")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5")
		{
			if (edge[index]->Getsource() == "방화")
				link_first_station(index);
			else if (edge[index]->Getdest() == "하남검단산")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5_Macheon")
		{
			if (edge[index]->Getsource() == "강동")
				link_first_station(index);
			else if (edge[index]->Getdest() == "마천")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line6") // 단방향 구간 처리 필요
		{
			if (edge[index]->Getsource() == "신내")
			{
				link_first_station(index);
				index++;
			}
			else if (edge[index]->Getsource() == "응암")	// 단방향 구간 처리
			{
				link_line6_one_way_problem(index, "응암");
				index++;									// 응암에서 역촌으로 옮김

				for (int i = 0; i < 5;i++)					// 역촌 -> 불광 -> 독바위 -> 연신내 -> 구산 -> 응암
				{
					link_line6_one_way_problem(index, "not응암");
					index++;
				}
			}
		}

		else if (edge[index]->GetSubwayLine() == "line7")
		{
			if (edge[index]->Getsource() == "석남")
				link_first_station(index);
			else if (edge[index]->Getdest() == "장암")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line8")
		{
			if (edge[index]->Getsource() == "암사")
				link_first_station(index);
			else if (edge[index]->Getdest() == "모란")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line9")
		{
			if (edge[index]->Getsource() == "개화")
				link_first_station(index);
			else if (edge[index]->Getdest() == "중앙보훈병원")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon1")
		{
			if (edge[index]->Getsource() == "계양")
				link_first_station(index);
			else if (edge[index]->Getdest() == "송도달빛축제공원")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon2")
		{
			if (edge[index]->Getsource() == "검단오류")
				link_first_station(index);
			else if (edge[index]->Getdest() == "운연")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Suinbundang")
		{
			if (edge[index]->Getsource() == "청량리")
				link_first_station(index);
			else if (edge[index]->Getdest() == "인천")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Sinbundang")
		{
			if (edge[index]->Getsource() == "강남")
				link_first_station(index);
			else if (edge[index]->Getdest() == "광교")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongui_Jungang")
		{
			if (edge[index]->Getsource() == "문산")
				link_first_station(index);
			else if (edge[index]->Getdest() == "지평")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Airport")
		{
			if (edge[index]->Getsource() == "서울역")
				link_first_station(index);
			else if (edge[index]->Getdest() == "인천공항2터미널")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongchun")
		{
			if (edge[index]->Getsource() == "청량리")
				link_first_station(index);
			else if (edge[index]->Getdest() == "춘천")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Uijeongbu")
		{
			if (edge[index]->Getsource() == "발곡")
				link_first_station(index);
			else if (edge[index]->Getdest() == "탑석")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Yongin")
		{
			if (edge[index]->Getsource() == "기흥")
				link_first_station(index);
			else if (edge[index]->Getdest() == "전대에버랜드")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeonggang")
		{
			if (edge[index]->Getsource() == "판교")
				link_first_station(index);
			else if (edge[index]->Getdest() == "여주")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Wooyi")
		{
			if (edge[index]->Getsource() == "신설동")
				link_first_station(index);
			else if (edge[index]->Getdest() == "북한산우이")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Seahae")
		{
			if (edge[index]->Getsource() == "소사")
				link_first_station(index);
			else if (edge[index]->Getdest() == "원시")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gimpo_Gold")
		{
			if (edge[index]->Getsource() == "김포공항")
				link_first_station(index);
			else if (edge[index]->Getdest() == "양촌")
				link_last_station(index);
			else
				link_else_station(index);

			index++;
		}

		else
		{
			cout << "예기치 못한 오류 발생" << endl;
			exit(100);
		}
	}
}

/*
 함수 이름 : link_first_station
 함수 기능 : 역이 첫번째 역이라면 전 역을 null로 처리하고 다음역을 가리킨다.
*/
void MakeGraph::link_first_station(int index)
{
	int now_station_index = SearchIndex(edge[index]->Getsource());	// 현재 역 인덱스 저장
	int next_station_index = SearchIndex(edge[index]->Getdest());	// 다음 역 인덱스 저장

	edge[index]->Setpre(station[now_station_index]);				// 소요산	  <- line1, 4분
	edge[index]->Setnext(station[next_station_index]);				// line1, 4분 -> 동두천

	station[now_station_index]->Setnext(edge[index]);				// 소요산	  -> line1, 4분 (<- null이지만 기본 값이 null이므로 다음은 설정하지 않는다.)
	
}

/*
 함수 이름 : link_else_station
 함수 기능 : 역이 첫번째 마지막 역이 아니라면 전 역을 가리키고 다음역을 가리킨다.
*/
void MakeGraph::link_else_station(int index)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// 현재 역 인덱스 저장
	int next_station_index = SearchIndex(edge[index]->Getdest());	// 다음 역 인덱스 저장

	edge[index]->Setpre(station[now_station_index]);				// 전 역과 이어줌
	edge[index]->Setnext(station[next_station_index]);				// 다음 역과 이어줌

	station[now_station_index]->Setpre(edge[preidx]);				// line1, 4분 <- 동두천
	station[now_station_index]->Setnext(edge[index]);				// 동두천	  -> line1, 3분
}

/*
 함수 이름 : link_last_station
 함수 기능 : 역이 마지막 역이라면 다음 역을 null로 처리한다.
*/
void MakeGraph::link_last_station(int index)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// 현재 역 인덱스 저장
	int next_station_index = SearchIndex(edge[index]->Getdest());	// 다음 역 인덱스 저장

	edge[index]->Setpre(station[now_station_index]);				// 동인천	  <- line1, 3분
	edge[index]->Setnext(station[next_station_index]);				// line1, 3분 -> 인천

	station[now_station_index]->Setpre(edge[preidx]);				// line1, 2분 <- 동인천
	station[now_station_index]->Setnext(edge[index]);				// 동인천     -> line1, 3분

	station[next_station_index]->Setpre(edge[index]);				// line1, 3분 <- 인천 (-> null이지만 기본 값이 null이므로 다음은 설정하지 않는다.)
}

/*
 함수 이름 : link_line6_one_way_problem
 함수 기능 : 6호선의 단방향 문제를 해결해준다.
			 응암이면 전 역인 새절과 이어주어야한다.
			 응암이 아니면 전을 이어주지 않아야 한다.
*/
void MakeGraph::link_line6_one_way_problem(int index, string name)
{
	int preidx = index;
	preidx--;

	int now_station_index = SearchIndex(edge[index]->Getsource());	// 현재 역 인덱스 저장
	int next_station_index = SearchIndex(edge[index]->Getdest());	// 다음 역 인덱스 저장

	edge[index]->Setpre(nullptr);									// 전 역 null
	edge[index]->Setnext(station[next_station_index]);				// 다음 역과 이어줌

	if(name == "응암")
		station[now_station_index]->Setpre(edge[preidx]);			// line6, 2분 <- 응암
	else
		station[now_station_index]->Setpre(nullptr);				// null       <- 역촌

	station[now_station_index]->Setnext(edge[index]);				// 응암	  -> line6, 1분
}

/*
 함수 이름 : Getdegree
 함수 기능 : 각 역들의 degree를 조사하여 저장한다.
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
			neighbor_table[k][l] = "null";	// 의미없는 문자로 채우기


	// 소요산 역 입력처리 위해
	exceptional_case = SearchIndex(edge[i]->Getsource());
	neighbor_table[exceptional_case][j] = "동두천";

	// 순환선 오류
	exceptional_case = SearchIndex("시청");
	neighbor_table[exceptional_case][j++] = "충정로";
	neighbor_table[exceptional_case][j] = "을지로입구";

	j = 0;

	for (i = 0; i < EDGE_NUMBER - 1; i++)
	{
		next_i = i + 1;

		if (edge[i]->Getdest() == edge[next_i]->Getsource()) // 일반적인 케이스
		{
			sub_idx = SearchIndex(edge[i]->Getdest());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j++] = edge[i]->Getsource();
			neighbor_table[sub_idx][j] = edge[next_i]->Getdest();
			j = 0;

		}
		else	// 호선의 첫 역이거나 마지막 역인 경우
		{
			// 끝 역 처리
			sub_idx = SearchIndex(edge[i]->Getdest());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j] = edge[i]->Getsource();
			j = 0;

			// 시작 역 처리
			sub_idx = SearchIndex(edge[next_i]->Getsource());

			while (neighbor_table[sub_idx][j] != "null")
				j++;

			neighbor_table[sub_idx][j] = edge[next_i]->Getdest();
			j = 0;

		}
	}
	
	// 6호선 단방향 문제 해결
	for (i = 325; i < 331; i++)
	{
		exceptional_case = SearchIndex(edge[i]->Getdest());

		for (j = 0; j < 4; j++)	// 이 구간 내 역의 최대 degree는 4이므로
		{
			if (neighbor_table[exceptional_case][j] == edge[i]->Getsource())
				neighbor_table[exceptional_case][j] = "null";	// ex) 응암에서 구산은 갈 수 없으므로 지워준다.

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

	// 내일 구현하자
	int count_degree = 0;	// 중복은 제외할 예정
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
 함수 이름 : link_transferStation
 함수 기능 : 환승역에 대한 문제를 처리해준다.
*/
void MakeGraph::link_transferStation(int index, int degree)
{
	
}

/*
 함수 이름 : SearchIndex
 함수 기능 : 역 이름을 찾아 인덱스를 반환
			 지금은 순차검색이지만 나중에 이진검색으로 바꿀 것
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
 함수 이름 : init
 함수 기능 : public 함수
			 initStation(), initEdge(), makeLine()을 실행한다.
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
 소멸자 : 동적생성한 객체 배열들을 해제한다.
*/
MakeGraph::~MakeGraph()
{
	for (int i = 0;i < STATION_NUMBER;i++)
		delete station[i];

	for (int i = 0;i < EDGE_NUMBER;i++)
		delete edge[i];
}