# SubwayMapProject
##Find_Shortest_Way


수도권 지하철의 전체 역을 대상으로
해당역부터 해당역까지의 최단시간, 최소환승루트를 표현하는 프로그램이다.
급행열차는 생각하지 않았으며 소요시간은 서울교통공사 사이버 스테이션의 열차정보를 통해 알아내었다.

**예외상황**
경의중앙선의 임진강역은 1일 3회 운행으로 문산역으로 밖에 운행을 하지 않음으로 제외한다.
경춘선의 광운대역도 이와 비슷함으로 제외함
1호선 광명, 서동탄역도 비슷하여 제외함

1. 사용할 자료구조 : Linked List
2. 사용할 알고리즘 : Dijkstra algorithm