#include<stdio.h> 
#define MAX 1000000
void display(int i) {
	for (int t = MAX / 10; t; t /= 10) {
		//����м����ݵ�ǰ��0  �����磺 ��ʾ12345000001    12345 000001��Ϊ����ȷ��ʾ�м��0ҲҪ���
		printf("%d", i / t % 10);
	}
}
int main() {
	int a[500] = { 0 };
	int i, j,  k;		//k ��0ָʾ�� 
	int c;
	int N;
	scanf("%d",&N) ;

	a[0] = 1;//�׳˴�1��ʼ 
	for (i = 1, k = 0; i<=N; i++) {
		if (a[k] == 0)k++;	
		/*�����α�
		���׳����ϴ��ʱ�򣬻����ĩ�ˣ�������ǰ�ˣ����ִ�����0������Щ0���Բ��ò�����㣬
		��˲���k��Ϊһ��ָʾ������������Щ0���� 
		*/ 
		for (j = k, c = 0; a[j]; j++) {
			a[j] = (a[j] * i + c); 
			c = a[j] / MAX;
			a[j] %= MAX;
		}
		
		a[j] = c;
		if (a[j] == 0)j--;
		printf("%d!\t=%d", i, a[j--]);
		for (; j >= 0; j--)
			display(a[j]);
		putchar('\n');
	}
}
