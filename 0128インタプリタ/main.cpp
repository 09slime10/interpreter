#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack {
	char type[10];			//^¼
	char val_name[10];		//Ï¼
	int val_len;			//Ï¼Ì¶
	char column[1000];		//¶ñ
	int col_len;			//¶ñÌ¶
	int num;				//l(®)
	float f_num;			//l(P¸xÀ)
	double d_num;			//l({¸xÀ)
	struct _stack* next;	//Ì\¢ÌÌ|C^i[ê
}Stack_I;

char buf1[100], buf2[100], buf3[100], ope;
char c_work1[100], c_work2[100], ope_work[100];
char ope_dec[2][5] = { { '+', '-', '*', '/', '%'}, {'1', '1', '2', '2', '2'} };

int i, j, k = 0, len1 = 0, len2, n_work1;
int cnt1 = 0, cnt2 = 0, ope_cnt = 0, n_cnt = 0;
int flg = 0, n_flg = 0, if_flg = 0, type_flg = 0;
int pri[100] = {};

double n_work2[100] = {}, n_work3;

//ärÎÛFint^
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

//ärÎÛFfloat^
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

//ärÎÛFdouble^
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
	printf("|Ïé¾                            |^¼                     |\n");
	printf("|^¼ è`·éÏ¼ [= úl]      |Echar,int,float,double  |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|üÍ                                |                         |\n");
	printf("|scan Ï¼ = l                    |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|oÍ                                |oÍ`®                 |\n");
	printf("|print l or Ï¼                  |Echar^   ¶ or ¶ñ|\n");
	printf("|                                    |Eint^    ®          |\n");
	printf("|                                    |Efloat^  P¸xÀ    |\n");
	printf("|                                    |Edouble^ {¸xÀ    |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|är                                |ärZq               |\n");
	printf("|if Ï¼1 ärZq Ï¼2 or l |E<,<=,>,>=,==,!=        |\n");
	printf("|                                    |                         |\n");
	printf("|ßèl                              |                         |\n");
	printf("|true false                          |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|vZ                                                          |\n");
	printf("|calc Ï¼1 = l or Ï¼2 Zq l or Ï¼3             |\n");
	printf("|EZqF+,-,*,/                                             |\n");
	printf("|______________________________________________________________|\n");
	printf("|I¹               |Ó                                      |\n");
	printf("|exit               |EúlÍ''â\"\"ÅÍÜ¸»ÌÜÜ­±Æ  |\n");
	printf("|                   |EvZ®É()ðg¤êÍóÅæØé±Æ  |\n");
	printf("|                   |E¶E¶ñÌärÍsÂ                |\n");
	printf("|                   |EùÉÏÆµÄè`µ½¶ðoÍµ½¢Æ|\n");
	printf("|                   |@«Í\"\"ÅÍ¤±Æ                        |\n");
	printf("PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n");
	printf("R[hðüÍ(óÅæØé±Æ)\n");

	while (1)
	{
		scanf("%s", buf1);
		if (strncmp(buf1, "exit", 4) == 0) //»èFI¹
		{
			free(sp1);
			return 0;
		}
		else if (strncmp(buf1, "int", 3) == 0) //^»èF®
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
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//úlªüÍ³êÄ¢é©Ç¤©Ì»è
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //úlÈµ
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //úl è
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //Ï¼ð\¢ÌÉüÍ
						sp1->val_len = i - 1; //Ï¼Ì¶ð\¢ÌÉüÍ

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //¶ðJEg
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1ÉlðRs[
						sp1->num = atoi(c_work1); //¶ñð®ÉÏ·
						break;
					}
				}
			}

			//zñÌZbg
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //tOÌZbg
			len1 = 0; //¶ÌZbg
		}
		else if (strncmp(buf1, "float", 5) == 0) //^»èFP¸xÀ
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
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//úlªüÍ³êÄ¢é©Ç¤©Ì»è
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //úlÈµ
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //úl è
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //Ï¼ð\¢ÌÉüÍ
						sp1->val_len = i - 1; //Ï¼Ì¶ð\¢ÌÉüÍ

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //¶ðJEg
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1ÉlðRs[
						sp1->f_num = atof(c_work1); //¶ñðÀÉÏ·
						break;
					}
				}
			}

			//zñÌZbg
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //tOÌZbg
			len1 = 0; //¶ÌZbg
		}
		else if (strncmp(buf1, "double", 6) == 0) //^»èF{¸xÀ
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
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//úlªüÍ³êÄ¢é©Ç¤©Ì»è
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //úlÈµ
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //úl è
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //Ï¼ð\¢ÌÉüÍ
						sp1->val_len = i - 1; //Ï¼Ì¶ð\¢ÌÉüÍ

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //¶ðJEg
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1ÉlðRs[
						sp1->d_num = atof(c_work1); //¶ñðÀÉÏ·
						break;
					}
				}
			}

			//zñÌZbg
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //tOÌZbg
			len1 = 0; //¶ÌZbg
		}
		else if (strncmp(buf1, "char", 4) == 0) //^»èF¶
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
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//lÌZbg
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//úlªüÍ³êÄ¢é©Ç¤©Ì»è
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //úlÈµ
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //úl è
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //Ï¼ð\¢ÌÉüÍ
						sp1->val_len = i - 1; //Ï¼Ì¶ð\¢ÌÉüÍ
						
						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //¶ðJEg
						}

						strncpy(sp1->column, &buf2[i + 2], len1); //\¢ÌÉ¶ñðRs[
						sp1->col_len = len1; //\¢ÌÉ¶ðãü
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
		else if (strncmp(buf1, "scan", 4) == 0) //»èFüÍ
		{
			scanf(" %[^\n]%*c", &buf2);
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					strncpy(c_work1, buf2, i - 1); //Ï¼ðzñÉüÍ
					for (j = i + 2; buf2[j] != '\0'; j++)
					{
						len1++; //üÍlÌ¶ðJEg
					}
					strncpy(c_work2, &buf2[i + 2], len1); //c_work2ÉüÍ·élðRs[
					break;
				}
			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (strncmp(sp1->val_name, c_work1, sp1->val_len) == 0)
				{
					//üÍ³êéÏÌ^ð»è
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
		else if (strncmp(buf1, "print", 5) == 0) //»èFoÍ
		{
			scanf("%s", buf2);
			len2 = strlen(buf2);
			sp1 = startp;
			while (sp1 != NULL)
			{
				//oÍ·éÏð\¢Ì©çõ
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
					//oÍ·éÏÌ^»è
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

			if (sp1 == NULL) //oÍf[^ªÏÅÈ¢ê
			{
				printf("%s\n", buf2);
			}
		}
		else if(strncmp(buf1, "calc", 4) == 0) //»èFvZ
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
					//vZµ½lðãü·éÏ¼ðc_work1ÉRs[
					strncpy(c_work1, buf2, i - 1);
					len2 = i - 1;
					break;
				}
			}

			j = i + 2;
			k = j;
			for (i = i + 2; buf2[i] != '\0'; i++)
			{
				//ZqÌ»è
				if (buf2[i] == '+'
				 || buf2[i] == '-'
				 || buf2[i] == '*'
				 || buf2[i] == '/')
				{
					ope_work[ope_cnt++] = buf2[i]; //æª©çÉZqðL¯
					cnt2++;
				}
			}

			ope_cnt = 0;
			while (buf2[j] != '\0')
			{
				if (buf2[j] == '(') // ( ª½Æ«tOðâ·
				{
					flg += 2;
				}
				else if (buf2[j] == ')') // ) ª½Æ«tOð¸ç·
				{
					flg -= 2;
				}
				
				switch (buf2[j]) //ZqÌDæÊÌvZEãü
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
					  || buf2[j] == '.') //®ÉÏÅÈ­lªüÁÄ¢éê
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
						//vZpÌzñÉlðãü
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

				//ÌÏÌÆ±ëÜÅbuf2Ìzñð¸ç·
				while ((buf2[j] < 0x30 || buf2[j] > 0x39)
					&& (buf2[j] < 0x41 || buf2[j] > 0x5a)
					&& (buf2[j] < 0x61 || buf2[j] > 0x7a))
				{
					j++;
					//buf2ÌzñÌÅãÜÅ½çtOð§Äé
					if (buf2[j] == '\0')
					{
						flg = 1;
						break;
					}
				}
				
				//tOª§ÁÄ¢éê[vð²¯é
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
					//DæÊªêÔå«¢ZqÌY¦ðÁè
					if (pri[n_work1] < pri[i + 1])
					{
						n_work1 = i + 1;
					}
					i++;
				}

				//DæÊÌå«¢Æ±ëðæÉvZ·é
				switch (ope_work[n_work1])
				{
				case '+': //ÁZ
					n_work2[n_work1] = n_work2[n_work1] + n_work2[n_work1 + 1];
					//vZÉgÁ½lðOÉlßé
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '-': //¸Z
					n_work2[n_work1] = n_work2[n_work1] - n_work2[n_work1 + 1];
					//vZÉgÁ½lðOÉlßé
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '*': //æZ
					n_work2[n_work1] = n_work2[n_work1] * n_work2[n_work1 + 1];
					//vZÉgÁ½lðOÉlßé
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '/': //Z
					n_work2[n_work1] = n_work2[n_work1] / n_work2[n_work1 + 1];
					//vZÉgÁ½lðOÉlßé
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				}

				//ZqÆDæÊðêÂ¸ÂOÉlßé
				for (j = n_work1 + 1; j < cnt2 + 1; j++)
				{
					pri[j - 1] = pri[j];
					ope_work[j - 1] = ope_work[j];
				}

			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				//vZÊðüÍ·é\¢ÌðÁè
				if (strncmp(sp1->val_name, c_work1, len2) == 0)
				{
					//vZÊÌüÍ
					//üÍ·é\¢ÌÌ^ðÁè
					if (strncmp(sp1->type, "int", 3) == 0)
					{
						//int^
						sp1->num = n_work2[0];
					}
					else if (strncmp(sp1->type, "float", 5) == 0)
					{
						//float^
						sp1->f_num = n_work2[0];
					}
					else if (strncmp(sp1->type, "double", 6) == 0)
					{
						//double^
						sp1->d_num = n_work2[0];
					}
				}
				sp1 = sp1->next;
			}
			k = 0;
		}
		else if (strncmp(buf1, "if", 2) == 0) //»èFär
		{
			scanf(" %[^\n]%*c", &buf2);
			j = 0;
			for (i = 0; buf2[i] != '\0'; i++)
			{
				len1++;
				if (buf2[i + 1] == ' ' || buf2[i + 1] == '\0')
				{
					if (flg == 0) //Ï1Ì»è
					{
						strncpy(c_work1, &buf2[j], len1); //c_work1ÉÏ¼ðRs[
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 1;
					}
					else if (flg == 1) //ärZqÌ»è
					{
						strncpy(ope_work, &buf2[j], len1); //ope_workÉZqðRs[
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 2;
					}
					else //Ï2yÑlÌ»è
					{
						strncpy(c_work2, &buf2[j], len1); //c_work2ÉÏ¼orlðRs[

						//üÍlªl¾Á½ê
						if (c_work2[0] >= 0x30 && c_work2[0] <= 0x39)
						{
							n_work3 = atof(c_work2); //lÉÏ·
							n_flg = 1; //tOð§Äé
						}
						
						len1 = 0;
						flg = 0;
						break;
					}
				}
			}
			
			sp1 = startp;
			while (sp1 != NULL) //Ï1ÌêðÁè
			{
				if (strncmp(c_work1, sp1->val_name, sp1->val_len) == 0)
				{
					//Ï1Ì^»è
					if (strncmp(sp1->type, "int", 3) == 0) //»èFint^
					{
						type_flg = 0;
					}
					else if (strncmp(sp1->type, "float", 5) == 0) //»èFfloat^
					{
						type_flg = 1;
					}
					else if (strncmp(sp1->type, "double", 6) == 0) //»èFdouble^
					{
						type_flg = 2;
					}
					else //char^¾Á½ê
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
					if (strncmp(c_work2, sp2->val_name, sp2->val_len) == 0) //Ï2ÌêðÁè
					{
						//Ï2Ì^»è
						if (strncmp(sp2->type, "int", 3) == 0) //»èFint^
						{
							n_work3 = sp2->num;
						}
						else if (strncmp(sp2->type, "float", 5) == 0) //»èFfloat^
						{
							n_work3 = sp2->f_num;
						}
						else if (strncmp(sp2->type, "double", 6) == 0) //»èFdouble^
						{
							n_work3 = sp2->d_num;
						}
						else //char^¾Á½ê
						{
							if_flg = 2;
						}
						break;
					}
					sp2 = sp2->next;
				}
			}

			if (type_flg == 0) //Ï1ªint^¾Á½ê
			{
				if_flg = int_if(sp1->num, n_work3, ope_work);
			}
			else if (type_flg == 1) //Ï1ªfloat^¾Á½ê
			{
				if_flg = float_if(sp1->f_num, n_work3, ope_work);
			}
			else if (type_flg == 2) //Ï1ªdouble^¾Á½ê
			{
				if_flg = double_if(sp1->d_num, n_work3, ope_work);
			}

			if (if_flg == 0) //^¾Á½ê
			{
				printf("true\n");
			}
			else if(if_flg == 1) //U¾Á½ê
			{
				printf("false\n");
			}
			else if (if_flg == 2) //ärÅ«È¢ê
			{
				printf("¶E¶ñÍärÅ«Ü¹ñ\n");
			}
			
			len1 = strlen(ope_work); //ärZqÌ¶ðãü
			for (i = 0; i < len1; i++) //ope_workÌgðZbg
			{
				ope_work[i] = '\0';
			}

			//tOÌZbg
			n_flg = 0;
			if_flg = 0;
			type_flg = 0;
		}
	}
}