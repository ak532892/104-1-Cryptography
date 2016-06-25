#include<stdio.h>
//引入標頭檔
#include<ctype.h>
//引入函式庫處理字串
#include<string.h>
//引入函式庫處理字串
void readMe(void);//函式原型
void generateKey(char*);//函式原型
void encryption(char*);//函式原型
void decryption(char*);//函式原型
//主程式
int main(){
	//宣告要執行動作的選項
	char option;
	//宣告key
	char key[25];
	
	//由副程式印出程式使用說明
	readMe();
	//提示使用者輸入
	printf("? ");
	//使用者輸入選項
	scanf("%c", &option);
	//清空在緩衝區的換行 
	getchar();
	
	//當選項不為4時, 一直進行詢問動作
	while( option != '4' ){
		//取出選項的值並進行配對
		switch(option){
			case '1'://如果是1的話產生金鑰
				generateKey(key);//將key傳入並呼叫副程式
				break;//跳出switch
			case '2'://如果是2的話加密明文
				encryption(key);//將key傳入並呼叫副程式
				break;//跳出switch
			case '3'://如果是3的話解密密文
				decryption(key);//將key傳入並呼叫副程式
				break;//跳出switch
			default://其他狀況
				//提示使用者輸入錯誤
				printf("不合法輸入\n");
				//由副程式印出程式使用說明
				readMe();
				break;//跳出switch
		}//switch的成對括號
		//提示使用者輸入
		printf("? ");
		//使用者輸入選項
		scanf("%c", &option);
		//清空在緩衝區的換行
		getchar();
	}//迴圈的成對括號
	return 0;//回傳給main代表程式結束
}//主程式的成對括號
//副程式, 印出使用說明
void readMe(void){	
	//提示使用者輸入下列選項
	printf("請輸入選項: \n"
		   "(1) 產生金鑰\n"
		   "(2) 執行加密\n"
		   "(3) 執行解密\n"
		   "(4) 結束程式\n");
}//副程式的成對括號
//副程式, 產生key
void generateKey(char *key) {
	//宣告暫時的填充字串
	char tempFillWord[1000];
	
	//提示使用者輸入填充字串
	printf("輸入填充字串以產生秘密金鑰(I和J為同一字):\n");
	//使用者輸入暫時的填充字串
	gets(tempFillWord);
	
	//宣告填充字串
	char fillWord[1000] = {};
	//宣告迴圈變數i和完成填充的字元數
	int i, fillNum = 0;
	//跑迴圈將tempFillWord掃過一次並儲存於處理過後的fillWord
	for(i = 0; i < strlen(tempFillWord); i++){
		if( isalpha(tempFillWord[i]) )//判斷是否為字母
			fillWord[fillNum++] = toupper(tempFillWord[i]);//是的話將tempFillWord都轉成大寫並儲存於fillWord
	}//迴圈的成對括號
	
	//字元數歸零
	fillNum = 0;
	//宣告dup陣列用於判斷重複與否
	int dup[26] = {};
	//跑迴圈將填充字串填補進key裡
	for(i = 0; i < strlen(fillWord); i++){
		//如果填充字串有J則轉為I
		if( fillWord[i] == 'J' ) fillWord[i] = 'I';
		//如果填充字串沒有重複則加入Key
		if( !dup[fillWord[i] - 'A'] )	key[fillNum++] = fillWord[i];
		//將重複的填充字串記錄
		dup[fillWord[i] - 'A']++;
	}//迴圈的成對括號
	
	//跑迴圈將剩下沒填補的字放進key裡
	for(i = 0; i < 26; i++){
		//如果沒重複且字元不是j的話
		if( !dup[i] && (i != 9) )
			key[fillNum++] = i + 'A';//將字母依序放進key裡
	}//迴圈的成對括號
	
	//輸出金鑰
	printf("金鑰:\n");
	//跑迴圈並依序輸出金鑰
	for(i = 0; i < 25; i++){
		//如果金鑰裡面字元是I則輸出I/J
		if(key[i] == 'I')	printf(" I/J");
		//否則按照4格位子正常輸出
		else	printf("%4c", key[i]);
		//判斷每5個字元換行
		if( !( (i+1)%5 ) )	puts("");
	}//迴圈的成對括號
}//副程式的成對括號
//副程式, 加密明文
void encryption(char *key) {
	//宣告明文
	char plaintext[1000] = {};

	//提示使用者輸入明文字串
	printf("輸入明文字串並進行加密('X'為填充字元):\n");
	//使用者輸入明文
	gets(plaintext);
	
	//宣告純字母明文
	char alphaPlaintext[1000] = {};
	//宣告迴圈變數i和填充後的字元數
	int i, fillNum = 0;
	//跑迴圈將plaintext掃過一次並儲存於處理過後的alphaPlaintext
	for(i = 0; i < strlen(plaintext); i++){
		if( isalpha(plaintext[i]) ){//判斷是否為字母
			//是的話將plaintext都轉成大寫並儲存於alphaPlaintext
			alphaPlaintext[fillNum++] = toupper(plaintext[i]);
			//如果字是J則轉成I
			if(alphaPlaintext[fillNum-1] == 'J')	
				alphaPlaintext[fillNum-1] = 'I';//轉成I
		}//if的成對括號
	}//迴圈的成對括號
	
	//填充後的字元數歸零
	fillNum = 0;
	//宣告填充X後的明文
	char fillXPlaintext[1000] = {};
	//將明文和X放入另一字串, 每次看兩個字元
	for(i = 1; i < strlen(alphaPlaintext); i+=2, fillNum+=2){
		//將明文直接放入填充X後的明文
		fillXPlaintext[fillNum] = alphaPlaintext[i-1];
		//如果兩個字元不相同
		if( alphaPlaintext[i-1] != alphaPlaintext[i] )
			fillXPlaintext[fillNum+1] = alphaPlaintext[i];//將明文直接放入填充X後的明文
		else{//否則
			fillXPlaintext[fillNum+1] = 'X';//放X進填充X後的明文
			i--;//i-1避免跳過一個字元
		}//else成對括號
	}//迴圈的成對括號

	//判斷填充後的字元數是否為奇數
	if( !(fillNum%2) ){
		fillXPlaintext[fillNum] = alphaPlaintext[i-1];//將明文直接放進填充X的明文
		fillXPlaintext[fillNum+1] = 'X';//將X放進填充X的明文
	}//if的成對括號
	
	//提示輸出密文
	printf("密文:\n");
	
	//找到的位置
	char *firstPtr;
	//宣告座標模擬二唯陣列位置
	int x1, y1, x2, y2;
	//用迴圈輸出密文
	for(i = 0; i < strlen(fillXPlaintext); i+=2){
		//找填充X後的明文內的字對應到key的位置
		firstPtr = strchr(key, fillXPlaintext[i]);
		//將位置設給x1和y1
		x1 = (firstPtr-key) / 5, y1 = (firstPtr-key) % 5;
		//找填充X後的明文內的字對應到key的位置
		firstPtr = strchr(key, fillXPlaintext[i+1]);
		//將位置設給x2和y2
		x2 = (firstPtr-key) / 5, y2 = (firstPtr-key) % 5;

		//三個case 一同行二同列三不同行不同列
		if(x1 == x2)//同行
			y1++, y2++;//將找到的位置往下移
		else if(y1 == y2)//同列
			x1++, x2++;//將找到的位置往右移
		else{//不同行不同列
			int t = y1;//將y1指定給t
			y1 = y2, y2 = t;//交換y1和y2
		}//else的成對括號

		//防止超過邊界
		x1 %= 5, y1 %= 5, x2 %= 5, y2 %= 5;
		//印出密文
		printf("%c%c ", *(key + x1*5 + y1), *(key + x2*5 + y2));
	}//迴圈的成對括號

	puts("");//換行
}//副程式的成對括號
//副程式, 解密密文
void decryption(char *key) {
	//宣告暫時的密文
	char tempCiphertext[1000];
	
	//提示使用者輸入密文字串
	printf("輸入密文字串並進行解密(I和J為同一字)('X'為填充字元):\n");
	//使用者輸入暫時的填充字串
	gets(tempCiphertext);
	
	//宣告密文
	char ciphertext[1000] = {};
	//宣告迴圈變數i和完成填充的字元數
	int i, fillNum = 0;
	//跑迴圈將tempCiphertext掃過一次並儲存於處理過後的ciphertext
	for(i = 0; i < strlen(tempCiphertext); i++){
		if( isalpha(tempCiphertext[i]) )//判斷是否為字母
			ciphertext[fillNum++] = toupper(tempCiphertext[i]);
			//是的話將tempCiphertext都轉成大寫並儲存於ciphertext
	}//迴圈的成對括號

	//找到的位置和宣告填充X後的明文
	char *firstPtr, fillXPlaintext[1000] = {};
	//宣告座標模擬二唯陣列位置
	int x1, y1, x2, y2;
	//用迴圈輸出密文
	for(i = 0; i < strlen(ciphertext); i+=2){
		//找密文內的字對應到key的位置
		firstPtr = strchr(key, ciphertext[i]);
		//將位置設給x1和y1
		x1 = (firstPtr-key) / 5, y1 = (firstPtr-key) % 5;
		//找密文內的字對應到key的位置
		firstPtr = strchr(key, ciphertext[i+1]);
		//將位置設給x2和y2
		x2 = (firstPtr-key) / 5, y2 = (firstPtr-key) % 5;

		//三個case 一同行二同列三不同行不同列
		if(x1 == x2)//同行
			y1--, y2--;//將找到的位置往上移
		else if(y1 == y2)//同列
			x1--, x2--;//將找到的位置往左移
		else{//不同行不同列
			int t = y1;//將y1指定給t
			y1 = y2, y2 = t;//交換y1和y2
		}//else的成對括號

		//防止超過邊界
		if(x1 < 0)	x1 += 5;if(y1 < 0)	y1 += 5;
		if(x2 < 0)	x2 += 5;if(y2 < 0)	y2 += 5;
		//填充X明文還原回去
		fillXPlaintext[i] = *(key + x1*5 + y1), 
		fillXPlaintext[i+1] = *(key + x2*5 + y2);
	}//迴圈的成對括號

	//宣告明文
	char plaintext[1000] = {};
	//填充後的字元數規零
	fillNum = 0;
	//用迴圈跑過一次fillXPlaintext並刪除填充x部分
	for(i = 0; i < strlen(fillXPlaintext); i++){
		//如果是X則跳過這輪迴圈
		if(fillXPlaintext[i] == 'X')	continue;
		//將填充X的明文存給明文
		plaintext[fillNum++] = fillXPlaintext[i];
	}//迴圈的成對括號
	//提示輸出明文
	printf("明文:\n");
	//用迴圈輸出明文一次兩個字元
	for(i = 0; i < strlen(plaintext); i++){
		//如果2個字元就印空白
		if((i+1)%2)	printf(" ");
		printf("%c", plaintext[i]);//輸出明文
	}//迴圈的成對括號
	//換行
	puts("");
}//副程式的成對括號