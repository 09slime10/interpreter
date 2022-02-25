#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack {
	char type[10];			//型名
	char val_name[10];		//変数名
	int val_len;			//変数名の文字数
	char column[1000];		//文字列
	int col_len;			//文字列の文字数
	int num;				//値(整数)
	float f_num;			//値(単精度実数)
	double d_num;			//値(倍精度実数)
	struct _stack* next;	//次の構造体のポインタ格納場所
}Stack_I;

char buf1[100], buf2[100], buf3[100], ope;
char c_work1[100], c_work2[100], ope_work[100];
char ope_dec[2][5] = { { '+', '-', '*', '/', '%'}, {'1', '1', '2', '2', '2'} };

int i, j, k = 0, len1 = 0, len2, n_work1;
int cnt1 = 0, cnt2 = 0, ope_cnt = 0, n_cnt = 0;
int flg = 0, n_flg = 0, if_flg = 0, type_flg = 0;
int pri[100] = {};

double n_work2[100] = {}, n_work3;

//比較対象：int型
int int_if(int x, double y, char s[])
{
	int flg = 0;

	if (strncmp(s, "<=", 2) == 0)
	{
		if (x <= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">=", 2) == 0)
	{
		if (x >= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "==", 2) == 0)
	{
		if (x == y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "!=", 2) == 0)
	{
		if (x != y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "<", 1) == 0)
	{
		if (x < y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">", 1) == 0)
	{
		if (x > y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}

	return flg;
}

//比較対象：float型
int float_if(float x, double y, char s[])
{
	int flg = 0;

	if (strncmp(s, "<=", 2) == 0)
	{
		if (x <= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">=", 2) == 0)
	{
		if (x >= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "==", 2) == 0)
	{
		if (x == y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "!=", 2) == 0)
	{
		if (x != y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "<", 1) == 0)
	{
		if (x < y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">", 1) == 0)
	{
		if (x > y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}

	return flg;
}

//比較対象：double型
int double_if(double x, double y, char s[])
{
	int flg = 0;

	if (strncmp(s, "<=", 2) == 0)
	{
		if (x <= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">=", 2) == 0)
	{
		if (x >= y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "==", 2) == 0)
	{
		if (x == y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "!=", 2) == 0)
	{
		if (x != y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, "<", 1) == 0)
	{
		if (x < y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}
	else if (strncmp(s, ">", 1) == 0)
	{
		if (x > y)
		{
			flg = 0;
		}
		else
		{
			flg = 1;
		}
	}

	return flg;
}

int main()
{
	Stack_I* sp1 = NULL;
	Stack_I* sp2 = NULL, * startp = NULL;

	printf("________________________________________________________________\n");
	printf("|変数宣言                            |型名                     |\n");
	printf("|型名 定義する変数名 [= 初期値]      |・char,int,float,double  |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|入力                                |                         |\n");
	printf("|scan 変数名 = 値                    |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|出力                                |出力形式                 |\n");
	printf("|print 値 or 変数名                  |・char型   文字 or 文字列|\n");
	printf("|                                    |・int型    整数          |\n");
	printf("|                                    |・float型  単精度実数    |\n");
	printf("|                                    |・double型 倍精度実数    |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|比較                                |比較演算子               |\n");
	printf("|if 変数名1 比較演算子 変数名2 or 値 |・<,<=,>,>=,==,!=        |\n");
	printf("|                                    |                         |\n");
	printf("|戻り値                              |                         |\n");
	printf("|true false                          |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|計算                                                          |\n");
	printf("|calc 変数名1 = 値 or 変数名2 演算子 値 or 変数名3             |\n");
	printf("|・演算子：+,-,*,/                                             |\n");
	printf("|______________________________________________________________|\n");
	printf("|終了               |注意                                      |\n");
	printf("|exit               |・初期値は''や\"\"で囲まずそのまま書くこと  |\n");
	printf("|                   |・計算式に()を使う場合は空白で区切ること  |\n");
	printf("|                   |・文字・文字列の比較は不可                |\n");
	printf("|                   |・既に変数として定義した文字を出力したいと|\n");
	printf("|                   |　きは\"\"で囲うこと                        |\n");
	printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("コードを入力(空白で区切ること)\n");

	while (1)
	{
		scanf("%s", buf1);
		if (strncmp(buf1, "exit", 4) == 0) //判定：終了
		{
			free(sp1);
			return 0;
		}
		else if (strncmp(buf1, "int", 3) == 0) //型判定：整数
		{
			scanf(" %[^\n]%*c", &buf2);

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (sp1->next == NULL)
				{
					break;
				}
				sp1 = sp1->next;
			}

			if (cnt1 == 0)
			{
				cnt1++;
				sp1 = (Stack_I*)malloc(sizeof(Stack_I));
				startp = sp1;
				startp->next = NULL;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//初期値が入力されているかどうかの判定
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //初期値なし
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //初期値あり
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //変数名を構造体に入力
						sp1->val_len = i - 1; //変数名の文字数を構造体に入力

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //文字数をカウント
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1に数値をコピー
						sp1->num = atoi(c_work1); //文字列を整数に変換
						break;
					}
				}
			}

			//配列のリセット
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //フラグのリセット
			len1 = 0; //文字数のリセット
		}
		else if (strncmp(buf1, "float", 5) == 0) //型判定：単精度実数
		{
			scanf(" %[^\n]%*c", &buf2);

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (sp1->next == NULL)
				{
					break;
				}
				sp1 = sp1->next;
			}

			if (cnt1 == 0)
			{
				cnt1++;
				sp1 = (Stack_I*)malloc(sizeof(Stack_I));
				startp = sp1;
				startp->next = NULL;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//初期値が入力されているかどうかの判定
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //初期値なし
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //初期値あり
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //変数名を構造体に入力
						sp1->val_len = i - 1; //変数名の文字数を構造体に入力

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //文字数をカウント
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1に数値をコピー
						sp1->f_num = atof(c_work1); //文字列を実数に変換
						break;
					}
				}
			}

			//配列のリセット
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //フラグのリセット
			len1 = 0; //文字数のリセット
		}
		else if (strncmp(buf1, "double", 6) == 0) //型判定：倍精度実数
		{
			scanf(" %[^\n]%*c", &buf2);

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (sp1->next == NULL)
				{
					break;
				}
				sp1 = sp1->next;
			}

			if (cnt1 == 0)
			{
				cnt1++;
				sp1 = (Stack_I*)malloc(sizeof(Stack_I));
				startp = sp1;
				startp->next = NULL;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//初期値が入力されているかどうかの判定
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //初期値なし
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //初期値あり
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //変数名を構造体に入力
						sp1->val_len = i - 1; //変数名の文字数を構造体に入力

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //文字数をカウント
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1に数値をコピー
						sp1->d_num = atof(c_work1); //文字列を実数に変換
						break;
					}
				}
			}

			//配列のリセット
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //フラグのリセット
			len1 = 0; //文字数のリセット
		}
		else if (strncmp(buf1, "char", 4) == 0) //型判定：文字
		{
			scanf(" %[^\n]%*c", &buf2);

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (sp1->next == NULL)
				{
					break;
				}
				sp1 = sp1->next;
			}

			if (cnt1 == 0)
			{
				cnt1++;
				sp1 = (Stack_I*)malloc(sizeof(Stack_I));
				startp = sp1;
				startp->next = NULL;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//値のリセット
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//初期値が入力されているかどうかの判定
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //初期値なし
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //初期値あり
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //変数名を構造体に入力
						sp1->val_len = i - 1; //変数名の文字数を構造体に入力
						
						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //文字数をカウント
						}

						strncpy(sp1->column, &buf2[i + 2], len1); //構造体に文字列をコピー
						sp1->col_len = len1; //構造体に文字数を代入
					}
				}
			}

			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			len1 = 0;
			flg = 0;
		}
		else if (strncmp(buf1, "scan", 4) == 0) //判定：入力
		{
			scanf(" %[^\n]%*c", &buf2);
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					strncpy(c_work1, buf2, i - 1); //変数名を配列に入力
					for (j = i + 2; buf2[j] != '\0'; j++)
					{
						len1++; //入力値の文字数をカウント
					}
					strncpy(c_work2, &buf2[i + 2], len1); //c_work2に入力する値をコピー
					break;
				}
			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (strncmp(sp1->val_name, c_work1, sp1->val_len) == 0)
				{
					//入力される変数の型を判定
					if (strncmp(sp1->type, "int", 3) == 0)
					{
						sp1->num = atoi(c_work2);
					}
					else if (strncmp(sp1->type, "float", 5) == 0)
					{
						sp1->f_num = atof(c_work2);
					}
					else if (strncmp(sp1->type, "double", 6) == 0)
					{
						sp1->d_num = atof(c_work2);
					}
					else if (strncmp(sp1->type, "char", 4) == 0)
					{
						strncpy(sp1->column, c_work2, len1);
						sp1->col_len = len1;
					}
				}
				sp1 = sp1->next;
			}
			len1 = 0;
		}
		else if (strncmp(buf1, "print", 5) == 0) //判定：出力
		{
			scanf("%s", buf2);
			len2 = strlen(buf2);
			sp1 = startp;
			while (sp1 != NULL)
			{
				//出力する変数を構造体から検索
				if (buf2[0] == '"')
				{
					for (i = 1; i <= len2 - 2; i++)
					{
						printf("%c", buf2[i]);
					}
					printf("\n");
					break;
				}
				else if (strncmp(sp1->val_name, buf2, len2) == 0)
				{
					//出力する変数の型判定
					if (strncmp(sp1->type, "int", 3) == 0)
					{
						printf("%d\n", sp1->num);
						break;
					}
					else if (strncmp(sp1->type, "float", 5) == 0)
					{
						printf("%f\n", sp1->f_num);
						break;
					}
					else if (strncmp(sp1->type, "double", 6) == 0)
					{
						printf("%lf\n", sp1->d_num);
						break;
					}
					else if (strncmp(sp1->type, "char", 4) == 0)
					{
						for (i = 0; i < sp1->col_len; i++)
						{
							printf("%c", sp1->column[i]);
						}
						printf("\n");
						break;
					}
				}
				sp1 = sp1->next;
			}

			if (sp1 == NULL) //出力データが変数でない場合
			{
				printf("%s\n", buf2);
			}
		}
		else if(strncmp(buf1, "calc", 4) == 0) //判定：計算
		{
			scanf(" %[^\n]%*c", &buf2);
			if (sp1 != NULL)
			{
				sp1->next = NULL;
			}

			for(i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					//計算した値を代入する変数名をc_work1にコピー
					strncpy(c_work1, buf2, i - 1);
					len2 = i - 1;
					break;
				}
			}

			j = i + 2;
			k = j;
			for (i = i + 2; buf2[i] != '\0'; i++)
			{
				//演算子の判定
				if (buf2[i] == '+'
				 || buf2[i] == '-'
				 || buf2[i] == '*'
				 || buf2[i] == '/')
				{
					ope_work[ope_cnt++] = buf2[i]; //先頭から順に演算子を記憶
					cnt2++;
				}
			}

			ope_cnt = 0;
			while (buf2[j] != '\0')
			{
				if (buf2[j] == '(') // ( が来たときフラグを増やす
				{
					flg += 2;
				}
				else if (buf2[j] == ')') // ) が来たときフラグを減らす
				{
					flg -= 2;
				}
				
				switch (buf2[j]) //演算子の優先順位の計算・代入
				{
				case '+':
					pri[ope_cnt] = (ope_dec[1][0] - '0') + flg;
					ope_cnt++;
					break;
				case '-':
					pri[ope_cnt] = (ope_dec[1][1] - '0') + flg;
					ope_cnt++;
					break;
				case '*':
					pri[ope_cnt] = (ope_dec[1][2] - '0') + flg;
					ope_cnt++;
					break;
				case '/':
					pri[ope_cnt] = (ope_dec[1][3] - '0') + flg;
					ope_cnt++;
					break;
				default:
					break;
				}
				j++;
			}

			j = k;
			n_cnt = 0;
			len1 = 0;
			sp1 = startp;
			while (sp1 != NULL)
			{
				while (buf2[j] != '\0')
				{
					if ((buf2[j] >= 0x30 && buf2[j] <= 0x39) 
					  || buf2[j] == '.') //式に変数でなく値が入っている場合
					{
						len1++;
						if (buf2[j + 1] == ' ' || buf2[j + 1] == '\0')
						{
							strncpy(c_work2, &buf2[k], len1);
							n_work2[n_cnt++] = atof(c_work2);
						}
					}
					else if (strncmp(&buf2[j], sp1->val_name, sp1->val_len) == 0)
					{
						//計算用の配列に値を代入
						if (strncmp(sp1->type, "int", 3) == 0)
						{
							n_work2[n_cnt++] = sp1->num;
							break;
						}
						else if (strncmp(sp1->type, "float", 5) == 0)
						{
							n_work2[n_cnt++] = sp1->f_num;
							break;
						}
						else if (strncmp(sp1->type, "double", 6) == 0)
						{
							n_work2[n_cnt++] = sp1->d_num;
							break;
						}
					}
					sp1 = sp1->next;

					if (sp1 == NULL)
					{
						j++;
						sp1 = startp;
					}
				}
				sp1 = startp;
				j++;

				//次の変数のところまでbuf2の配列をずらす
				while ((buf2[j] < 0x30 || buf2[j] > 0x39)
					&& (buf2[j] < 0x41 || buf2[j] > 0x5a)
					&& (buf2[j] < 0x61 || buf2[j] > 0x7a))
				{
					j++;
					//buf2の配列の最後まで来たらフラグを立てる
					if (buf2[j] == '\0')
					{
						flg = 1;
						break;
					}
				}
				
				//フラグが立っている場合ループを抜ける
				if (flg == 1)
				{
					break;
				}
			}

			i = 0;
			flg = 0;
			while (ope_work[0] != '\0')
			{
				i = 0;
				n_work1 = i;
				while (pri[i] != 0)
				{
					//優先順位が一番大きい演算子の添え字を特定
					if (pri[n_work1] < pri[i + 1])
					{
						n_work1 = i + 1;
					}
					i++;
				}

				//優先順位の大きいところを先に計算する
				switch (ope_work[n_work1])
				{
				case '+': //加算
					n_work2[n_work1] = n_work2[n_work1] + n_work2[n_work1 + 1];
					//計算に使った値を前に詰める
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '-': //減算
					n_work2[n_work1] = n_work2[n_work1] - n_work2[n_work1 + 1];
					//計算に使った値を前に詰める
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '*': //乗算
					n_work2[n_work1] = n_work2[n_work1] * n_work2[n_work1 + 1];
					//計算に使った値を前に詰める
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '/': //除算
					n_work2[n_work1] = n_work2[n_work1] / n_work2[n_work1 + 1];
					//計算に使った値を前に詰める
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				}

				//演算子と優先順位を一つずつ前に詰める
				for (j = n_work1 + 1; j < cnt2 + 1; j++)
				{
					pri[j - 1] = pri[j];
					ope_work[j - 1] = ope_work[j];
				}

			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				//計算結果を入力する構造体を特定
				if (strncmp(sp1->val_name, c_work1, len2) == 0)
				{
					//計算結果の入力
					//入力する構造体の型を特定
					if (strncmp(sp1->type, "int", 3) == 0)
					{
						//int型
						sp1->num = n_work2[0];
					}
					else if (strncmp(sp1->type, "float", 5) == 0)
					{
						//float型
						sp1->f_num = n_work2[0];
					}
					else if (strncmp(sp1->type, "double", 6) == 0)
					{
						//double型
						sp1->d_num = n_work2[0];
					}
				}
				sp1 = sp1->next;
			}
			k = 0;
		}
		else if (strncmp(buf1, "if", 2) == 0) //判定：比較
		{
			scanf(" %[^\n]%*c", &buf2);
			j = 0;
			for (i = 0; buf2[i] != '\0'; i++)
			{
				len1++;
				if (buf2[i + 1] == ' ' || buf2[i + 1] == '\0')
				{
					if (flg == 0) //変数1の判定
					{
						strncpy(c_work1, &buf2[j], len1); //c_work1に変数名をコピー
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 1;
					}
					else if (flg == 1) //比較演算子の判定
					{
						strncpy(ope_work, &buf2[j], len1); //ope_workに演算子をコピー
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 2;
					}
					else //変数2及び値の判定
					{
						strncpy(c_work2, &buf2[j], len1); //c_work2に変数名or値をコピー

						//入力値が値だった場合
						if (c_work2[0] >= 0x30 && c_work2[0] <= 0x39)
						{
							n_work3 = atof(c_work2); //数値に変換
							n_flg = 1; //フラグを立てる
						}
						
						len1 = 0;
						flg = 0;
						break;
					}
				}
			}
			
			sp1 = startp;
			while (sp1 != NULL) //変数1の場所を特定
			{
				if (strncmp(c_work1, sp1->val_name, sp1->val_len) == 0)
				{
					//変数1の型判定
					if (strncmp(sp1->type, "int", 3) == 0) //判定：int型
					{
						type_flg = 0;
					}
					else if (strncmp(sp1->type, "float", 5) == 0) //判定：float型
					{
						type_flg = 1;
					}
					else if (strncmp(sp1->type, "double", 6) == 0) //判定：double型
					{
						type_flg = 2;
					}
					else //char型だった場合
					{
						if_flg = 2;
					}
					break;
				}
				sp1 = sp1->next;
			}

			if (n_flg == 0)
			{
				sp2 = startp;
				while (sp2 != NULL)
				{
					if (strncmp(c_work2, sp2->val_name, sp2->val_len) == 0) //変数2の場所を特定
					{
						//変数2の型判定
						if (strncmp(sp2->type, "int", 3) == 0) //判定：int型
						{
							n_work3 = sp2->num;
						}
						else if (strncmp(sp2->type, "float", 5) == 0) //判定：float型
						{
							n_work3 = sp2->f_num;
						}
						else if (strncmp(sp2->type, "double", 6) == 0) //判定：double型
						{
							n_work3 = sp2->d_num;
						}
						else //char型だった場合
						{
							if_flg = 2;
						}
						break;
					}
					sp2 = sp2->next;
				}
			}

			if (type_flg == 0) //変数1がint型だった場合
			{
				if_flg = int_if(sp1->num, n_work3, ope_work);
			}
			else if (type_flg == 1) //変数1がfloat型だった場合
			{
				if_flg = float_if(sp1->f_num, n_work3, ope_work);
			}
			else if (type_flg == 2) //変数1がdouble型だった場合
			{
				if_flg = double_if(sp1->d_num, n_work3, ope_work);
			}

			if (if_flg == 0) //真だった場合
			{
				printf("true\n");
			}
			else if(if_flg == 1) //偽だった場合
			{
				printf("false\n");
			}
			else if (if_flg == 2) //比較できない場合
			{
				printf("文字・文字列は比較できません\n");
			}
			
			len1 = strlen(ope_work); //比較演算子の文字数を代入
			for (i = 0; i < len1; i++) //ope_workの中身をリセット
			{
				ope_work[i] = '\0';
			}

			//フラグのリセット
			n_flg = 0;
			if_flg = 0;
			type_flg = 0;
		}
	}
}