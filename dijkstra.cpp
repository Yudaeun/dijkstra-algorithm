//�ۼ���:  ������
// ���ͽ�Ʈ�� �˰����� �׸���� �����ϰ� �ظ� ���Ѵ�.
//2020�� 5�� 14��
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int NUM=12; //��� ���� 
int INF=100000000; //�� �� 


int touch[13]; //�湮�� ���
int length[13]; //�ִ� �Ÿ� 
int F[13]; //��带 ���ƴ��� �� ���ƴ��� ǥ��  

struct Cityname{
	string city_name;
};

//��ü �׷����� �ۼ��ϰ� ���� �̸��� �ۼ��Ѵ�. 
Cityname city[13] = {"","�뱸","���", "�λ�", "����", "����", "����", "����", "û��", "õ��", "����","����", "��õ" }; 
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
	int vnear; //�ε����� ����� ���� ������ 
	
	for(int n=1;n<=NUM;n++){
		length[n]=INF;
	}//�ʱ�ȭ 
	
//	length[1]=0; //�뱸���� ���! 
	length[11]=0; //���￡�� ���! 
	
	  for(int j=1;j<=NUM;j++){
	  	min=INF;
	  	for(int i=1;i<=NUM;i++){
	  		if((length[i]<min)&&F[i]==0){
	  			min=length[i];
	  			vnear=i;
			  }
		  }//�ִܰŸ��� �ش��ϴ� ������ ã�´�. 
		  
		  F[vnear]=1; //������ �湮�ߴٰ� ǥ���Ѵ�.
		   
		  for(int k=1;k<=NUM;k++){
		  	if(length[vnear]+W[vnear][k]<length[k]){
		  		length[k]=length[vnear]+W[vnear][k];
		  		touch[k]=vnear;
			  }
			  
		  }//vnear�� ���ļ� k���� ���� �Ÿ��� ���ݱ��� ã�� �ִ� ��κ��� ������ ���� 
	}
	//�Ʒ��� �ִ� ��� ���̿� �ִ� ��θ� ����� �Ѵ�. 
	for(int i=1;i<=NUM;i++){
		cout<<city[11].city_name<<" ���� "<<city[i].city_name<<" ���� ���� �ִ� ����� ����= "<<length[i];
	    //���￡�� ����ϸ� city[1]�� city[11]�� �ٲٸ� �ȴ�. 
		cout<<"\n�ִ� ���= ";
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
