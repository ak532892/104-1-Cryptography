#include <stdio.h>
//�ޤJ���Y��
//�Ƶ{��, �bZn���X����Xa�����k�Ϥ���
int multiplicative_inverse( int r1, int r2, int t1, int t2 ){
	/*
	�λ��j��@extended Euclidean algorithm
	���P�_r2�O�_��0�O���ܤ��~�򻼰j, �_�h�~�򻼰j
	�Yr2��0�b�P�_r1�O�_��1
	�Yr1��1��ܦ���->�L�X, �_�h�L��->�L�X
	�Yr1��1�b�P�_t1�O�_�p��s�O����mod t2(��ln)�ର���ƨæL�X, �_�h�����L�X�ѵ�
	*/
	return r2 ? multiplicative_inverse( r2, r1 % r2, t2, t1 - r1 / r2 * t2 ) : 
		 r1 == 1 ? ( t1 < 0 ? printf( "%d\n", t1 + t2 ) : printf( "%d\n", t1 ) ) : 
		 printf( "���s�b\n" );
}//�Ƶ{��������A��
//�Ƶ{��, �bZn���X����Xa���[�k�Ϥ���
int additive_inverse( int n, int a ){
	/*
	�ھکw�q(a+b)%n=0, b��a���[�k�Ϥ���, �n�D�Xb���ɹL�{�p�U:
	(a+b)=k*n -> �]��0<=a+b<=2n-2 �ҥH k=0 or 1
	a+b=0 or a+b=n -> b = (-a) or (n-a)
	�]��a�Mb�ݩ�0~n-1�ҥH�u����a=0��b = -a = 0
	��a������0�ɦ^��n-a
	a=0�^��a
	*/
	return a ? ( n - a ) : a;
}//�Ƶ{��������A��
//�D�{��
int main(){
	//�ŧiZn�j�p�P�Y�@���a 
	int n, a;
	
	//���ܨϥΪ̿�Jn��
	printf( "�п�JZn���j�p = " );
	//Ū��n�Ȫ����ɮ׵���
	while( scanf( "%d", &n ) != EOF ){
		//�ŧi����i���j��ϥ� 
		int i;
		
		//�L�XZn 
		printf( "Zn = {" );
		//�ΰj��L�XZn���X 
		for( i = 0; i < n; i++ ){
			if( !i )//�P�_�Ĥ@�ӼƦr 
				printf( "%d", i );//�L�X���X�Ʀr
			else//�P�_�Ĥ@�ӥH�~���Ʀr 
				printf( ", %d", i );//�L�X���X�Ʀr 
		}//�j�骺����A��
		//�L�XZn�������� 
		printf( "}\n" );
		
		//���ܨϥΪ̿�Ja��
		printf( "�п�JZn���X�����Y�@���a = " );
		//Ū��a�� 
		scanf( "%d", &a );

		//�ѰƵ{���h�M��a���[�k�Ϥ����æL�X
		printf( "%d���[�k�Ϥ���: %d\n", a, additive_inverse( n, a ) );
		
		//�ǳƭn�L�Xa�����k�Ϥ���
		printf( "%d�����k�Ϥ���: ", a );

		//�ѰƵ{���h�M��a�����k�Ϥ����æL�X
		multiplicative_inverse( n, a, 0, 1 );

		//���ܨϥΪ̿�Jn��
		printf( "------------------\n�п�JZn���j�p = " );
	}//�j�骺����A��
	return 0;//�^�ǵ�main�N��{������
}//�D�{��������A��