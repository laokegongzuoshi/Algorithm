#include<stdio.h>
int V[10000]={0};
//�˷�ԭ����λ�����Ӧ��
void shell(int *a,int n){
	int i,j,k,x;
	k=n/2; /*���ֵ*/
	while(k>=1) {
		for(i=k; i<n; i++) {
			x=a[i];
			j=i-k;
			while(j>=0&&x<a[j]) {
				a[j+k]=a[j];
				j-=k;
			}
			a[j+k]=x;
		}
		k/=2; /*��С���ֵ*/
	}
}
int main(){
	int N,M;
	int n,m;
	int p,i,i_max=0;
	long long F,R;
	int a[200]={0};
	scanf("%d%d",&N,&M);
	for(n=0;n<N;n++)
		scanf("%d",&V[n]);
	const long long F_MAX = 1 << N ;
	for(F=0;F<F_MAX;F++){
		for(p=m=i=0;p<N;p++)  //��λ��� 
			if((1<<p)&F){
				m+=V[p];
				i++;		//���� ��ҵĸ��� 
			}
		if(m==M){			//�жϴ�������Ƿ��������� 
			if(i>=i_max){		//�ҵ���С������	
				i_max=i;
				R = F;
			}
		}
	}
	if(i_max){		
		for(p=m=0;p<N;p++)		//�����д���һ�����鵱�� ��������� 
			if((1<<p)&R)a[m++]=V[p];
		shell(a,m);
		for(p=0;p<m-1;p++)
			printf("%d ",a[p]);
		printf("%d",a[p]);	
	}else printf("No Solution");
}