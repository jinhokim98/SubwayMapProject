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
		if (index >= 726) // 마지막 역까지 전부 추가했을 때 반복문 탈출
			break;

		if (edge[index]->GetSubwayLine() == "line1")
		{
			if (edge[index]->Getsource() == "소요산")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line1_Sinchang") // 지선일 경우 다시 한 번 생각해보자
		{
			if (edge[index]->Getsource() == "구로")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2") // 순환선 처리 필요
		{
			if (edge[index]->Getsource() == "시청") // 순환선 처리
			{
				edge[index]->Setpre(station[SearchIndex("충정로")]);					// 충정로 <- 시청
				edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// 시청   -> 을지로입구

				int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation의 출발역 인덱스를 구한다.
				int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation의 도착역 인덱스를 구한다.

				station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// 시청 -> 을지로입구는 2분을 기록한다.
			}
			else
				link_else_station(index);
			
			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Seongsu")
		{
			if (edge[index]->Getsource() == "성수")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line2_Sinjeong")
		{
			if (edge[index]->Getsource() == "신도림")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line3")
		{
			if (edge[index]->Getsource() == "대화")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line4")
		{
			if (edge[index]->Getsource() == "당고개")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5")
		{
			if (edge[index]->Getsource() == "방화")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line5_Macheon")
		{
			if (edge[index]->Getsource() == "강동")
				link_first_station(index);
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
			else if (edge[index]->Getsource() == "역촌")	// 단방향 구간 처리
			{
				for (int i = 0; i < 5;i++)					// 역촌 -> 불광 -> 독바위 -> 연신내 -> 구산 -> 응암
				{
					edge[index]->Setpre(nullptr);											// null   <- 역촌
					edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// 역촌 -> 불광

					int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation의 출발역 인덱스를 구한다.
					int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation의 도착역 인덱스를 구한다.

					station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance(), true);	// 역촌 -> 불광은 4분을 기록한다.
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
			if (edge[index]->Getsource() == "석남")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line8")
		{
			if (edge[index]->Getsource() == "암사")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line9")
		{
			if (edge[index]->Getsource() == "개화")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon1")
		{
			if (edge[index]->Getsource() == "계양")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Incheon2")
		{
			if (edge[index]->Getsource() == "검단오류")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Suinbundang")
		{
			if (edge[index]->Getsource() == "청량리")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Sinbundang")
		{
			if (edge[index]->Getsource() == "강남")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongui_Jungang")
		{
			if (edge[index]->Getsource() == "문산")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Airport")
		{
			if (edge[index]->Getsource() == "서울역")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeongchun")
		{
			if (edge[index]->Getsource() == "청량리")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Uijeongbu")
		{
			if (edge[index]->Getsource() == "발곡")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Yongin")
		{
			if (edge[index]->Getsource() == "기흥")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gyeonggang")
		{
			if (edge[index]->Getsource() == "판교")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Wooyi")
		{
			if (edge[index]->Getsource() == "신설동")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Seahae")
		{
			if (edge[index]->Getsource() == "소사")
				link_first_station(index);
			else
				link_else_station(index);

			index++;
		}

		else if (edge[index]->GetSubwayLine() == "line_Gimpo_Gold")
		{
			if (edge[index]->Getsource() == "김포공항")
				link_first_station(index);
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
			 행렬에 다음역까지 걸리는 거리 값 대입 // 소요산 -> 동두천 4분 대입
*/
void MakeGraph::link_first_station(int index)
{
	edge[index]->Setpre(nullptr);											// null   <- 소요산
	edge[index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);		// 소요산 -> 동두천

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation의 출발역 인덱스를 구한다.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation의 도착역 인덱스를 구한다.

	station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// 소요산 <-> 동두천은 4분을 기록한다.
}

/*
 함수 이름 : link_else_station
 함수 기능 : 역이 첫번째 역이 아니라면 전 역을 가리키고 다음역을 가리킨다.
			 행렬에 다음역까지 걸리는 거리 값 대입 // 동두천 -> 보산 3분 기록
*/
void MakeGraph::link_else_station(int index)
{
	edge[index]->Setpre(station[SearchIndex(edge[--index]->Getsource())]);	// 전 역과 이어줌
	edge[++index]->Setnext(station[SearchIndex(edge[index]->Getdest())]);	// 다음 역과 이어줌

	int now_index = SearchIndex(edge[index]->Getsource());						// SubwayStation의 출발역 인덱스를 구한다.
	int next_index = SearchIndex(edge[index]->Getdest());						// SubwayStation의 도착역 인덱스를 구한다.

	station[now_index]->SetMatrix(now_index, next_index, edge[index]->Getdistance());	// 동두천 <-> 보산은 3분을 기록한다.
}

/*
 함수 이름 : SearchIndex
 함수 기능 : 역 이름을 찾아 인덱스를 반환
			 지금은 순차검색이지만 나중에 이진검색으로 바꿀 것
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
 함수 이름 : init
 함수 기능 : public 함수
			 initStation(), initEdge(), makeLine()을 실행한다.
*/
void MakeGraph::init()
{
	initStation();
	initEdge();
	makeLine();
}

/*
 소멸자 : 파일 닫고 동적생성한 객체 배열들을 해제한다.
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