#include<stdio.h> //�ޤJ���Y��
int main(){ //�D�{��
	int a, x, n; //�ŧia, x, n�T�ӼƦr�p��y = a^x mod n

	printf("�п�Ja = ");//���ܨϥΪ̿�Ja
	while(scanf("%d", &a) != EOF){//Ū��a���쵲��
		printf("�п�Jx = ");//���ܨϥΪ̿�Jx
		scanf("%d", &x);//Ū��x
		printf("�п�Jn = ");//���ܨϥΪ̿�Jn
		scanf("%d", &n);//Ū��n
		//�ŧi�p�ƾ�i�M�_�ly��
		int i = 0, y = 1;
		
		//�L�X���榡
		printf("Calculation of %3d ^ %3d mod %3d\n"
			   " i xi %32s %25s\n"
		       "%15s(Initialization: y = 1) (Initialization: a = %3d)\n",
			   a, x, n, "Multiplication", "Squaring", " ", a);
		//��x�٦��Ȯ�, �i��j��L�X���e
		while(x){
			printf("%2d%3d", i++, x%2);//�L�X�j�馸�ƩMx�G�i���
			if(x%2){//�p�Gx�G�i��ȬO1
				//�L�X�s��y��
				printf(" y = %3d * %3d mod %3d = %3d --> ", y, a, n, y*a % n);
				y = y*a % n;//�M�����Ny���Wa mod n �õ�y�s��
			}//if������A��
			else//�p�Gx�G�i��ȬO0
				printf("%33s", " ");//�L�X�ťսվ���
			if(x /= 2)//�Nx���H2 ���K�P�_�O���O�̫�@���j��
				printf(" a = %3d^2 mod %3d = %3d\n", a, n, a*a % n);//�L�X�s��a��
			a = a*a % n;//�M�����Na���� mod n �õ�a�s��
		}//�j�骺����A��
		printf("\n�п�Ja = ");//���ܨϥΪ̿�Ja(�ĤG��)
	}//�j�骺����A��
	return 0;//�^�ǵ�main�N��{������
}//�D�{��������A��