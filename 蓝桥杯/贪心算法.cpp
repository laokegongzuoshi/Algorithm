/*��һ������������������M=150����7����Ʒ����Ʒ�����Էָ�������С��
Ҫ�󾡿�����װ�뱳���е���Ʒ�ܼ�ֵ��󣬵����ܳ�����������
��Ʒ A B C D E F G
���� 35kg 	30kg 	6kg 	50kg 	40kg 	10kg 	25kg
��ֵ 10$ 	40$ 	30$ 	50$ 	35$ 	40$ 	30$
*/
#define WeightMax 200
#include<stdio.h>
#include<string.h>
int weight[7];
int value[7];
int VM=0,VW=0;						//����ֵ
char item[7]="",item2[7];
int fun2(char a,int b);				//����item���Ƿ����a
int main() {
	int fun(int a,int weights,int values);//��ȣ����������ܼ�ֵ
	int p;
	puts("Please enter goods information");
	printf("A\tB\tC\tD\tE\tF\tG\n");
	scanf("%d\t%d\t%d\t%d\t%d\t%d\t%d",&weight[0],&weight[1],&weight[2],&weight[3],&weight[4],&weight[5],&weight[6]);
	scanf("%d\t%d\t%d\t%d\t%d\t%d\t%d",&value[0],&value[1],&value[2],&value[3],&value[4],&value[5],&value[6]);
	for(p=0; p<7; p++) {
		item[0]=p+'A';
		fun(1,weight[p],value[p]);
	}
	printf("%s\t%d\t%d\n",item2,VW,VM);
	return 0;
}
int fun(int a,int weights,int values) {
	int p;
	for(p=0; p<7; p++) {
		if(fun2(p+'A',a+1)||weights+weight[p]>WeightMax)continue;
		else {
			item[a]='A'+p;
			fun(a+1,weights+weight[p],values+value[p]);
			item[a]=NULL;
		}
	}
//printf("%s\t%d\t%d\n",item,weights,values);
	item[a]=NULL;
	if(VM<values) {
		VM=values;
		VW=weights;
		strcpy(item2,item);
	}
	return 0;
}

int fun2(char a,int b) {
	int p;
	for(p=0; p<b; p++)
		if(a==item[p])return 1;
	return 0;
}


