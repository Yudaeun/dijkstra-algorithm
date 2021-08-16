//작성자:  유다은
// 다익스트라 알고리즘을 그리디로 구현하고 해를 구한다.
//2020년 5월 14일
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int NUM=12; //노드 갯수 
int INF=100000000; //무 한 


int touch[13]; //방문한 노드
int length[13]; //최단 거리 
int F[13]; //노드를 거쳤는지 안 거쳤는지 표시  

struct Cityname{
	string city_name;
};

//전체 그래프를 작성하고 도시 이름을 작성한다. 
Cityname city[13] = {"","대구","울산", "부산", "광주", "울진", "대전", "동해", "청주", "천안", "강릉","서울", "인천" }; 
int W[13][13] =                        
{
   {0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,2,1,INF,INF,6,INF,6,INF,INF,INF,INF},
   {0,INF,0,2,INF,1,INF,INF,INF,INF,INF,INF,INF},
   {0,INF,3,0,4,INF,INF,INF,INF,INF,INF,INF,INF},
   {0,6,INF,5,0,INF,3,INF,INF,INF,INF,INF,INF},
   {0,3,3,INF,INF,0,5,3,2,INF,INF,INF,INF},
   {0,3,INF,INF,3,5,0,INF,INF,5,INF,INF,INF},
   {0,INF,INF,INF,INF,5,INF,0,2,INF,5,INF,INF},
   {0,INF,INF,INF,INF,2,INF,1,0,3,INF,13,INF},
   {0,INF,INF,INF,INF,INF,4,INF,4,0,INF,INF,3},
   {0,INF,INF,INF,INF,INF,INF,3,INF,INF,0,3,INF},
   {0,INF,INF,INF,INF,INF,INF,INF,8,INF,5,0,3},
   {0,INF,INF,INF,INF,INF,INF,INF,INF,1,INF,7,0}
};

int main(void){
	int min;
	int vnear; //인덱스인 마디로 가는 이음선 
	
	for(int n=1;n<=NUM;n++){
		length[n]=INF;
	}//초기화 
	
//	length[1]=0; //대구에서 출발! 
	length[11]=0; //서울에서 출발! 
	
	  for(int j=1;j<=NUM;j++){
	  	min=INF;
	  	for(int i=1;i<=NUM;i++){
	  		if((length[i]<min)&&F[i]==0){
	  			min=length[i];
	  			vnear=i;
			  }
		  }//최단거리에 해당하는 정점을 찾는다. 
		  
		  F[vnear]=1; //정점을 방문했다고 표시한다.
		   
		  for(int k=1;k<=NUM;k++){
		  	if(length[vnear]+W[vnear][k]<length[k]){
		  		length[k]=length[vnear]+W[vnear][k];
		  		touch[k]=vnear;
			  }
			  
		  }//vnear을 거쳐서 k까지 가는 거리가 지금까지 찾은 최단 경로보다 적으면 갱신 
	}
	//아래는 최단 경로 길이와 최단 경로를 출력을 한다. 
	for(int i=1;i<=NUM;i++){
		cout<<city[11].city_name<<" 에서 "<<city[i].city_name<<" 까지 가는 최단 경로의 길이= "<<length[i];
	    //서울에서 출발하면 city[1]을 city[11]로 바꾸면 된다. 
		cout<<"\n최단 경로= ";
		cout<<city[i].city_name;
		vnear=i;
		while(touch[vnear]!=0){
			cout<<" <-"<<city[touch[vnear]].city_name;
			vnear=touch[vnear];
		}
		printf("\n\n");
}printf("\n");
	
	return 0;
}
