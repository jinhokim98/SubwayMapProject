#include <iostream>
#include <fstream>
#include "SubwayMapManagement.h"

using namespace std;

ifstream fin;

/*
 생성자 : station.txt파일을 읽어온다.
*/
SubwayMapManagement::SubwayMapManagement()
{
	fin.open("station.txt");

	if (fin.fail())
	{
		cerr << "파일을 찾을 수 없음" << endl;
		exit(100);
	}
	
}

/*
 함수 이름 : initStation
 함수 기능 : station.txt에서 역 정보를 불러와 SubwayStation객체를 만든다.
			 그 후 이중연결리스트로 객체를 붙여 노선을 만든다.
*/
void SubwayMapManagement::initStation()
{
	int index = 0;		// 객체 배열 인덱스

	string subwayline;
	string subwayname;
	int distance;
	
	// 객체 만들기
	while (!fin.eof())
	{
		fin >> subwayline;
		fin >> subwayname;
		fin >> distance;

		station[index++] = new SubwayStation(subwayline, subwayname, distance);
	}

	index = 0;

	// 노선 만들기(1호선 ~ 김포골드라인)
	while (true)
	{
		if (station[index]->GetSubwayLine() == "line1")
		{
			if (station[index]->GetSubwayStationName() == "소요산") // 첫 역
			{
				station[index]->Setnext(station[++index]);	// 소요산 -> 동두천
				station[--index]->Setpre(nullptr);			// null   <- 소요산
				index++;									// 인덱스 동두천으로
			}
			else if (station[index]->GetSubwayStationName() == "인천")	// 종착역
			{
				station[index]->Setnext(nullptr);			// 인천 -> null
				station[index]->Setpre(station[--index]);	// 동인천 <- 인천
				index += 2;									// 다음 호선으로 이동
			}
			else
			{
				station[index]->Setnext(station[++index]);	// 다음 역과 이어줌
				station[--index]->Setpre(station[--index]);	// 전 역과 이어줌
				index += 2;									// 인덱스 다음 역으로 옮김
			}
		}
		else if (station[index]->GetSubwayLine() == "line1_Sinchang")
		{
			if (station[index]->GetSubwayStationName() == "구로")
			{
				station[index]->Setnext(station[++index]);	// 구로 -> 가산디지털단지
			}
		}
	}
}


/*
 함수 이름 : MakeGraph
 함수 기능 : 지하철 역 그래프를 만든다.
*/
void SubwayMapManagement::MakeGraph()
{
	
}

/*
 소멸자 : station.txt파일을 닫는다.
		  동적 생성한 객체들을 delete한다. 
*/
SubwayMapManagement::~SubwayMapManagement()
{
	fin.close();

	for (int i = 0;i < STATIONINFO; i++)
	{
		delete station[i];
	}
}


//