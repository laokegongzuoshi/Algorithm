/*
���⣺��״��

    ��˵��ʫ����ף�һ���������Һ����Ӳ�������

    һ�죬�����žƺ����Ӽ���������ƺ����о�2���������߱߳���
    ���½����ߣ����ȥ��ơ�
	���һ����������һ����

    ��һ·�ϣ���һ��������5�Σ�������10�Σ���֪���һ���������ǻ��������ðѾƺȹ��ˡ� 

    ����������������ͻ��Ĵ��򣬿��԰������Ϊa��������Ϊb����babaabbabbabbbb ���Ǻ���Ĵ����������Ĵ�һ���ж����أ������������п��ܷ����ĸ�����������Ŀ�����ģ���
*/
#include<stdio.h>
#include<stdlib.h>
int count=0;
char map[16]="";
int main(){
	void fun(bool k,int hotel,int flower,int liquor,int a);
	map[0]='A';
	fun(true,4,10,1,1);// hotel
	fun(false,5,9,1,1);// hotel
	printf("%d",count);
	return 0; 
}

void fun(bool k,int hotel,int flower,int liquor,int a){
	if(k)liquor*=2;
	else liquor--;
	if(liquor>flower||liquor<0)return ;
	if(!hotel&&!flower&&!liquor){//�Ƶ����� �һ�Ҳ���ˣ���ҵ���� 
	count++;
	printf("%s\n",map);

	return ;
	}
	
	if(hotel>0){
		map[a]='A';
		fun(true,hotel-1,flower,liquor,a+1);	
	}
	if(flower>1||hotel==0){
		map[a]='B';
		fun(false,hotel,flower-1,liquor,a+1);
	}
	return ;
}


