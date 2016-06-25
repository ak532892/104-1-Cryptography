#include<stdio.h> //引入標頭檔
int main(){ //主程式
	int a, x, n; //宣告a, x, n三個數字計算y = a^x mod n

	printf("請輸入a = ");//提示使用者輸入a
	while(scanf("%d", &a) != EOF){//讀取a直到結束
		printf("請輸入x = ");//提示使用者輸入x
		scanf("%d", &x);//讀取x
		printf("請輸入n = ");//提示使用者輸入n
		scanf("%d", &n);//讀取n
		//宣告計數器i和起始y值
		int i = 0, y = 1;
		
		//印出表格格式
		printf("Calculation of %3d ^ %3d mod %3d\n"
			   " i xi %32s %25s\n"
		       "%15s(Initialization: y = 1) (Initialization: a = %3d)\n",
			   a, x, n, "Multiplication", "Squaring", " ", a);
		//當x還有值時, 進行迴圈印出內容
		while(x){
			printf("%2d%3d", i++, x%2);//印出迴圈次數和x二進制值
			if(x%2){//如果x二進制值是1
				//印出新的y值
				printf(" y = %3d * %3d mod %3d = %3d --> ", y, a, n, y*a % n);
				y = y*a % n;//套公式將y乘上a mod n 並給y新值
			}//if的成對括號
			else//如果x二進制值是0
				printf("%33s", " ");//印出空白調整表格
			if(x /= 2)//將x除以2 順便判斷是不是最後一次迴圈
				printf(" a = %3d^2 mod %3d = %3d\n", a, n, a*a % n);//印出新的a值
			a = a*a % n;//套公式將a平方 mod n 並給a新值
		}//迴圈的成對括號
		printf("\n請輸入a = ");//提示使用者輸入a(第二次)
	}//迴圈的成對括號
	return 0;//回傳給main代表程式結束
}//主程式的成對括號