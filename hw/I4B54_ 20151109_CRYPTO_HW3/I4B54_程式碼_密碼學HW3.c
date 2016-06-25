#include <stdio.h> //引入標頭檔
#include <string.h>//引入字串處理函式庫
//副程式, 將輸入的數字轉成二進位並印出
void convertToBinary(int n){
	int i;//宣告迴圈變數

	for(i = 128; i > 0; i/= 2)//直接看最高位元為多少直到最低位元為止
		printf("%d", n/i ? n%=i, 1 : 0);//若結果有值印1反之0
}//副程式的成對括號
//副程式, 將輸入的二進位字串轉成十進位
int convertToDecimal(char *p){
	int result = 0;//設起始值為0

	for(; *p; p++)//當字串不為空字元則一直跑迴圈
		result = (result*2 + *p - '0');//將結果轉成十進位
	return result;//回傳結果
}//副程式的成對括號
//主程式
int main(){
	//宣告多項式P1與P2和寫死不可分解多項式(題目要求)
	char p1[20], p2[20], modulus[20] = "00011011";
	
	//提示使用者輸入P1
	printf("請輸入P1(將多項式以位元方式代替) = ");
	//讀取P1直到結束
	while(scanf("%s", p1) != EOF){
		//提示使用者輸入P2
		printf("請輸入P2(將多項式以位元方式代替) = ");
		//讀取P2
		scanf("%s", p2);
		//題示不可分解多項式為x^8 + x^4 + x^3 + x + 1
		printf("irreducible polynomial = x^8 + x^4 + x^3 + x + 1\n");
		//將P1, P2和不可分解多項式轉成十進位
		int p1Num = convertToDecimal(p1), p2Num = convertToDecimal(p2), modulusNum = convertToDecimal(modulus);
		//紀錄最後需要XOR的結果
		int result[20], record = 0; 
	
		//將結果陣列初值化
		memset(result, -1, sizeof(result));
		//宣告迴圈變數和P1長度
		int i, p1Length = strlen(p1);
	
		//用迴圈反著訪問P1的單位元素
		for(i = p1Length-1;i >= 0; i--)
			if(p1[i] == '1')//如果是1則紀錄需要儲存其結果
				result[record++] = p1Length-1-i;//反著=紀錄結果
		//儲存需要進行的迴圈數, 為P1的最高項+1 和宣告record的暫存變數
		int loopCount = result[record-1] + 1, record2 = 0;
		
		//印出表格格式
		printf("%10s || %20s || %32s\n", "Powers", "Shift-Left Operation", "Exclusive-Or");
		//進行迴圈印出內容
		for(i = 0; i < loopCount; i++){
			//判斷需要與不可分解多項式做XOR運算與否
			int xorFlag = p2Num / 128;
		
			//印出powers
			printf("x^%d XOR P2 || ", i);
			//如果是第一次
			if(!i){
				//則印出二進位的P2
				printf("%20s || ", " ");convertToBinary(p2Num);
				puts("");//換行
				if(i == result[record2])//如果需要紀錄
					result[record + record2++] = p2Num;//則紀錄P2
				continue;//跳過這輪迴圈
			}//if的成對括號
			p2Num <<= 1;//P2左移
			p2Num %= 256;//P2捨棄最高位元
			//印出左移後二進位的P2
			printf("%12s", " ");convertToBinary(p2Num);printf(" || ");
			//印出P2
			convertToBinary(p2Num);
			//如果需要XOR運算
			if(xorFlag)	{
				//提示印出要XOR
				printf(" XOR ");convertToBinary(modulusNum);printf(" = ");
				//將P2 XOR後的結果印出
				convertToBinary(p2Num ^= modulusNum);
			}//if的成對括號
			//如果需要紀錄
			if(i == result[record2]) 
				result[record + record2++] = p2Num;//則紀錄P2
			puts("");//換行
		}//迴圈的成對括號
		//提示印出P1 XOR P2
		printf("------------------------------------------------------------------\n"
			   "P1 XOR P2 = ");
		int ans = 0;//將答案歸零
		for(i = 0; i < record2; i++){//用迴圈印出P1 XOR P2
			if(i)	printf(" XOR "); //如果不是第一次迴圈則印XOR
			convertToBinary(result[record + i]);//將紀錄的結果抓出來並轉成2進位
			ans ^= result[record + i];//將答案與紀錄的結果做XOR運算
		}//迴圈的成對括號
		//印出答案
		printf(" = ");convertToBinary(ans);
		printf("\n請輸入P1(將多項式以位元方式代替) = ");//提示使用者輸入P1(第二次)
	}//迴圈的成對括號
	return 0;//回傳給main代表程式結束
}//主程式的成對括號