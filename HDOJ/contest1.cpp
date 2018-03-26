#include<stdio.h>
struct Skill {
	int MP;				//ˮ�� 
	int Injury;		//�˺� 
}Skills[1000];

struct Monster {
	int HP;			
	int Armor;
}Monsters[100000];


int DFS(const int LessHP, const int Armor, const int * SkillsMap, int NowSkillLocation, const int MPCount);
int MinMP(struct Monster Monster, const int MonstersCount, const int SkillsCount);
int MinMPVlue;

int main() {
	int MonstersCount, SkillsCount;
	int MinMPCount = 0;
//	while (scanf("%d%d", &MonstersCount, &SkillsCount), MonstersCount) {
		scanf("%d%d", &MonstersCount, &SkillsCount);
		for (int n = 0; n<MonstersCount; n++)
			scanf("%d%d", &Monsters[n].HP, &Monsters[n].Armor);
		for (int m = 0; m<SkillsCount; m++)
			scanf("%d%d", &Skills[m].MP, &Skills[m].Injury);

		for (int n = 0; n<MonstersCount; n++) {
			//��n������
			MinMPCount += MinMP(Monsters[n], MonstersCount, SkillsCount);
			MinMPVlue = 0;
		}
		printf("%d", MinMPCount);
	
	return 0;
}

int MinMP(struct Monster Monster, const int MonstersCount, const int SkillsCount) {
	int SkillsMap[1000] = { 0 };

	//���˵��򲻳��˺��ļ��� 
	{
		int n , m ;
		for (n=m=0; n<SkillsCount; n++)
		if (Skills[n].Injury>Monster.Armor) {
			SkillsMap[m] = n;
			m++;
		}	
		SkillsMap[m]=-1;
		
		//
		for (int i=0;SkillsMap[i]!=-1;i++)
		printf("%d ",SkillsMap[i]);
		puts("\n����Ϊ���ܱ�");
	}

	DFS(Monster.HP, Monster.Armor, SkillsMap, 0, 0);
	return MinMPVlue;
}

int DFS(const int LessHP, const int Armor, const int * SkillsMap, int NowSkillLocation, const int MPCount) {
	
	//�����Ѿ�������
	if (LessHP <= 0) {
		//���Ѿ��ҵ�����Сˮ������ֵ�ȵ�ǰ����ֵ�󣬻��߻�û���ҳ��κη���  ��ô��Ϊ��ǰ��������ѷ���
		if (MinMPVlue == 0 ||MPCount<MinMPVlue) 
			MinMPVlue = MPCount;
			printf("Test Data:MinMPVlue = %d",MinMPVlue);
		return 0;
	}
	//��NowSkillLocation�ļ���ʹ��i��
	for (int i = 0;; i++) {
		printf("TestData:\nNowSkillLocation = %d\ni = %d\nLessHP = %d\nMPCount=%d\nSkillsMap[NowSkillLocation] = %d\n\n",NowSkillLocation,i,LessHP,MPCount,SkillsMap[NowSkillLocation]); 
		//�����ǰ�����Ѿ����������ҵ�����С����ˮ��ֵ����������� ���� �Ѿ�û�п��õ�����������
		if (MinMPVlue != 0 && MPCount + i*Skills[SkillsMap[NowSkillLocation]].MP > MinMPVlue	||
			SkillsMap[NowSkillLocation]==-1
			)return 0;
		
		//�ݹ���뵽��һ��λ�ü��ܵļ����ռ�,�����ݵ�ǰֵ
		DFS(
			LessHP - i*(Skills[SkillsMap[NowSkillLocation]].Injury - Armor),	
			Armor,
			SkillsMap,															//�����б�
			NowSkillLocation + 1,												//�����б�λ��+1
			MPCount + i*Skills[SkillsMap[NowSkillLocation]].MP					//��ǰˮ������+i�ε�ǰ��������Ҫ��ˮ��
		);
	}
}

