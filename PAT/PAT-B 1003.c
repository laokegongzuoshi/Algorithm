#include<stdio.h>
void PAT(const int a,const int b,const int c){
	if(b==1)
		if(a==c)puts("YES");
		else puts("NO");
	else PAT(a,b-1,c-a);
}
int main(){
	int n;
	int a,b,c,k,i;
	char str[100];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		a=b=c=k=0;
		for(i=0;str[i];i++){
			if(str[i]!='P'&&str[i]!='T'&&str[i]!='A'){ //�ж��Ƿ�����Ƿ��ַ� 
				i=0;
				break;
			}
			if(k==0)a++;
			else if(k==1)b++;
			else if(k==2)c++;
			else {
				i=0;
				break;
			}
			if(str[i]=='P'&&k==0)k=1;        //�ж�PAT�Ƿ����� ���� ����ΪTAP 
			else if(str[i]=='T'&&k==1)k=2;
		}
		if(i&&b-1)PAT(a-1,b-1,c);
		else puts("NO");
	}
}