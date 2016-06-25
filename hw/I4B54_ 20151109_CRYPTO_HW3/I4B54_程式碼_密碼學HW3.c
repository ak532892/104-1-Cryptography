#include <stdio.h> //�ޤJ���Y��
#include <string.h>//�ޤJ�r��B�z�禡�w
//�Ƶ{��, �N��J���Ʀr�ন�G�i��æL�X
void convertToBinary(int n){
	int i;//�ŧi�j���ܼ�

	for(i = 128; i > 0; i/= 2)//�����ݳ̰��줸���h�֪���̧C�줸����
		printf("%d", n/i ? n%=i, 1 : 0);//�Y���G���ȦL1�Ϥ�0
}//�Ƶ{��������A��
//�Ƶ{��, �N��J���G�i��r���ন�Q�i��
int convertToDecimal(char *p){
	int result = 0;//�]�_�l�Ȭ�0

	for(; *p; p++)//��r�ꤣ���Ŧr���h�@���]�j��
		result = (result*2 + *p - '0');//�N���G�ন�Q�i��
	return result;//�^�ǵ��G
}//�Ƶ{��������A��
//�D�{��
int main(){
	//�ŧi�h����P1�PP2�M�g�����i���Ѧh����(�D�حn�D)
	char p1[20], p2[20], modulus[20] = "00011011";
	
	//���ܨϥΪ̿�JP1
	printf("�п�JP1(�N�h�����H�줸�覡�N��) = ");
	//Ū��P1���쵲��
	while(scanf("%s", p1) != EOF){
		//���ܨϥΪ̿�JP2
		printf("�п�JP2(�N�h�����H�줸�覡�N��) = ");
		//Ū��P2
		scanf("%s", p2);
		//�D�ܤ��i���Ѧh������x^8 + x^4 + x^3 + x + 1
		printf("irreducible polynomial = x^8 + x^4 + x^3 + x + 1\n");
		//�NP1, P2�M���i���Ѧh�����ন�Q�i��
		int p1Num = convertToDecimal(p1), p2Num = convertToDecimal(p2), modulusNum = convertToDecimal(modulus);
		//�����̫�ݭnXOR�����G
		int result[20], record = 0; 
	
		//�N���G�}�C��Ȥ�
		memset(result, -1, sizeof(result));
		//�ŧi�j���ܼƩMP1����
		int i, p1Length = strlen(p1);
	
		//�ΰj��ϵ۳X��P1����줸��
		for(i = p1Length-1;i >= 0; i--)
			if(p1[i] == '1')//�p�G�O1�h�����ݭn�x�s�䵲�G
				result[record++] = p1Length-1-i;//�ϵ�=�������G
		//�x�s�ݭn�i�檺�j���, ��P1���̰���+1 �M�ŧirecord���Ȧs�ܼ�
		int loopCount = result[record-1] + 1, record2 = 0;
		
		//�L�X���榡
		printf("%10s || %20s || %32s\n", "Powers", "Shift-Left Operation", "Exclusive-Or");
		//�i��j��L�X���e
		for(i = 0; i < loopCount; i++){
			//�P�_�ݭn�P���i���Ѧh������XOR�B��P�_
			int xorFlag = p2Num / 128;
		
			//�L�Xpowers
			printf("x^%d XOR P2 || ", i);
			//�p�G�O�Ĥ@��
			if(!i){
				//�h�L�X�G�i�쪺P2
				printf("%20s || ", " ");convertToBinary(p2Num);
				puts("");//����
				if(i == result[record2])//�p�G�ݭn����
					result[record + record2++] = p2Num;//�h����P2
				continue;//���L�o���j��
			}//if������A��
			p2Num <<= 1;//P2����
			p2Num %= 256;//P2�˱�̰��줸
			//�L�X������G�i�쪺P2
			printf("%12s", " ");convertToBinary(p2Num);printf(" || ");
			//�L�XP2
			convertToBinary(p2Num);
			//�p�G�ݭnXOR�B��
			if(xorFlag)	{
				//���ܦL�X�nXOR
				printf(" XOR ");convertToBinary(modulusNum);printf(" = ");
				//�NP2 XOR�᪺���G�L�X
				convertToBinary(p2Num ^= modulusNum);
			}//if������A��
			//�p�G�ݭn����
			if(i == result[record2]) 
				result[record + record2++] = p2Num;//�h����P2
			puts("");//����
		}//�j�骺����A��
		//���ܦL�XP1 XOR P2
		printf("------------------------------------------------------------------\n"
			   "P1 XOR P2 = ");
		int ans = 0;//�N�����k�s
		for(i = 0; i < record2; i++){//�ΰj��L�XP1 XOR P2
			if(i)	printf(" XOR "); //�p�G���O�Ĥ@���j��h�LXOR
			convertToBinary(result[record + i]);//�N���������G��X�Ө��ন2�i��
			ans ^= result[record + i];//�N���׻P���������G��XOR�B��
		}//�j�骺����A��
		//�L�X����
		printf(" = ");convertToBinary(ans);
		printf("\n�п�JP1(�N�h�����H�줸�覡�N��) = ");//���ܨϥΪ̿�JP1(�ĤG��)
	}//�j�骺����A��
	return 0;//�^�ǵ�main�N��{������
}//�D�{��������A��