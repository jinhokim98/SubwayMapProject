#include <iostream>
#include "SubwayMapUI.h"

using namespace std;

/*
 함수 이름 : main
 함수 기능 : 수도권 지하철 노선도 프로그램
			 역 검색과 최단거리 시스템을 실행할 수 있다.
 인자 : 없음
 반환값 : 정상종료
*/
int main()
{
	int menu;

	SubwayMapUI SeoulMetro;			// UI 객체 생성

	SeoulMetro.StartInterface();	// 인터페이스 실행
	menu = SeoulMetro.SeleteMenu();	// 메뉴 선택

	cout << endl;

	switch (menu)
	{
	case 1:
		SeoulMetro.StartSearchSystem();
		break;

	case 2:
		SeoulMetro.StartShortestRouteSystem();
		break;
	}

	return 0;
}
