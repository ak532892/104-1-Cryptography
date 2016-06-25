#include <stdio.h>
//引入標頭檔
//副程式, 在Zn集合中找出a的乘法反元素
int multiplicative_inverse( int r1, int r2, int t1, int t2 ){
	/*
	用遞迴實作extended Euclidean algorithm
	先判斷r2是否為0是的話不繼續遞迴, 否則繼續遞迴
	若r2為0在判斷r1是否為1
	若r1為1表示有解->印出, 否則無解->印出
	若r1為1在判斷t1是否小於零是的話mod t2(原始n)轉為正數並印出, 否則直接印出解答
	*/
	return r2 ? multiplicative_inverse( r2, r1 % r2, t2, t1 - r1 / r2 * t2 ) : 
		 r1 == 1 ? ( t1 < 0 ? printf( "%d\n", t1 + t2 ) : printf( "%d\n", t1 ) ) : 
		 printf( "不存在\n" );
}//副程式的成對括號
//副程式, 在Zn集合中找出a的加法反元素
int additive_inverse( int n, int a ){
	/*
	根據定義(a+b)%n=0, b為a的加法反元素, 要求出b推導過程如下:
	(a+b)=k*n -> 因為0<=a+b<=2n-2 所以 k=0 or 1
	a+b=0 or a+b=n -> b = (-a) or (n-a)
	因為a和b屬於0~n-1所以只有當a=0時b = -a = 0
	當a不等於0時回傳n-a
	a=0回傳a
	*/
	return a ? ( n - a ) : a;
}//副程式的成對括號
//主程式
int main(){
	//宣告Zn大小與某一整數a 
	int n, a;
	
	//提示使用者輸入n值
	printf( "請輸入Zn的大小 = " );
	//讀取n值直到檔案結束
	while( scanf( "%d", &n ) != EOF ){
		//宣告索引i給迴圈使用 
		int i;
		
		//印出Zn 
		printf( "Zn = {" );
		//用迴圈印出Zn集合 
		for( i = 0; i < n; i++ ){
			if( !i )//判斷第一個數字 
				printf( "%d", i );//印出集合數字
			else//判斷第一個以外的數字 
				printf( ", %d", i );//印出集合數字 
		}//迴圈的成對括號
		//印出Zn的結束框 
		printf( "}\n" );
		
		//提示使用者輸入a值
		printf( "請輸入Zn集合中的某一整數a = " );
		//讀取a值 
		scanf( "%d", &a );

		//由副程式去尋找a的加法反元素並印出
		printf( "%d的加法反元素: %d\n", a, additive_inverse( n, a ) );
		
		//準備要印出a的乘法反元素
		printf( "%d的乘法反元素: ", a );

		//由副程式去尋找a的乘法反元素並印出
		multiplicative_inverse( n, a, 0, 1 );

		//提示使用者輸入n值
		printf( "------------------\n請輸入Zn的大小 = " );
	}//迴圈的成對括號
	return 0;//回傳給main代表程式結束
}//主程式的成對括號