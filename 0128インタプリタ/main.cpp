#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack {
	char type[10];			//�^��
	char val_name[10];		//�ϐ���
	int val_len;			//�ϐ����̕�����
	char column[1000];		//������
	int col_len;			//������̕�����
	int num;				//�l(����)
	float f_num;			//�l(�P���x����)
	double d_num;			//�l(�{���x����)
	struct _stack* next;	//���̍\���̂̃|�C���^�i�[�ꏊ
}Stack_I;

char buf1[100], buf2[100], buf3[100], ope;
char c_work1[100], c_work2[100], ope_work[100];
char ope_dec[2][5] = { { '+', '-', '*', '/', '%'}, {'1', '1', '2', '2', '2'} };

int i, j, k = 0, len1 = 0, len2, n_work1;
int cnt1 = 0, cnt2 = 0, ope_cnt = 0, n_cnt = 0;
int flg = 0, n_flg = 0, if_flg = 0, type_flg = 0;
int pri[100] = {};

double n_work2[100] = {}, n_work3;

//��r�ΏہFint�^
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

//��r�ΏہFfloat�^
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

//��r�ΏہFdouble�^
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
	printf("|�ϐ��錾                            |�^��                     |\n");
	printf("|�^�� ��`����ϐ��� [= �����l]      |�Echar,int,float,double  |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|����                                |                         |\n");
	printf("|scan �ϐ��� = �l                    |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|�o��                                |�o�͌`��                 |\n");
	printf("|print �l or �ϐ���                  |�Echar�^   ���� or ������|\n");
	printf("|                                    |�Eint�^    ����          |\n");
	printf("|                                    |�Efloat�^  �P���x����    |\n");
	printf("|                                    |�Edouble�^ �{���x����    |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|��r                                |��r���Z�q               |\n");
	printf("|if �ϐ���1 ��r���Z�q �ϐ���2 or �l |�E<,<=,>,>=,==,!=        |\n");
	printf("|                                    |                         |\n");
	printf("|�߂�l                              |                         |\n");
	printf("|true false                          |                         |\n");
	printf("|____________________________________|_________________________|\n");
	printf("|�v�Z                                                          |\n");
	printf("|calc �ϐ���1 = �l or �ϐ���2 ���Z�q �l or �ϐ���3             |\n");
	printf("|�E���Z�q�F+,-,*,/                                             |\n");
	printf("|______________________________________________________________|\n");
	printf("|�I��               |����                                      |\n");
	printf("|exit               |�E�����l��''��\"\"�ň͂܂����̂܂܏�������  |\n");
	printf("|                   |�E�v�Z����()���g���ꍇ�͋󔒂ŋ�؂邱��  |\n");
	printf("|                   |�E�����E������̔�r�͕s��                |\n");
	printf("|                   |�E���ɕϐ��Ƃ��Ē�`�����������o�͂�������|\n");
	printf("|                   |�@����\"\"�ň͂�����                        |\n");
	printf("�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P\n");
	printf("�R�[�h�����(�󔒂ŋ�؂邱��)\n");

	while (1)
	{
		scanf("%s", buf1);
		if (strncmp(buf1, "exit", 4) == 0) //����F�I��
		{
			free(sp1);
			return 0;
		}
		else if (strncmp(buf1, "int", 3) == 0) //�^����F����
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
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//�����l�����͂���Ă��邩�ǂ����̔���
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //�����l�Ȃ�
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //�����l����
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //�ϐ������\���̂ɓ���
						sp1->val_len = i - 1; //�ϐ����̕��������\���̂ɓ���

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //���������J�E���g
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1�ɐ��l���R�s�[
						sp1->num = atoi(c_work1); //������𐮐��ɕϊ�
						break;
					}
				}
			}

			//�z��̃��Z�b�g
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //�t���O�̃��Z�b�g
			len1 = 0; //�������̃��Z�b�g
		}
		else if (strncmp(buf1, "float", 5) == 0) //�^����F�P���x����
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
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);
			
			//�����l�����͂���Ă��邩�ǂ����̔���
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //�����l�Ȃ�
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //�����l����
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //�ϐ������\���̂ɓ���
						sp1->val_len = i - 1; //�ϐ����̕��������\���̂ɓ���

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //���������J�E���g
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1�ɐ��l���R�s�[
						sp1->f_num = atof(c_work1); //������������ɕϊ�
						break;
					}
				}
			}

			//�z��̃��Z�b�g
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //�t���O�̃��Z�b�g
			len1 = 0; //�������̃��Z�b�g
		}
		else if (strncmp(buf1, "double", 6) == 0) //�^����F�{���x����
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
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//�����l�����͂���Ă��邩�ǂ����̔���
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //�����l�Ȃ�
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //�����l����
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //�ϐ������\���̂ɓ���
						sp1->val_len = i - 1; //�ϐ����̕��������\���̂ɓ���

						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //���������J�E���g
						}

						strncpy(c_work1, &buf2[i + 2], len1); //c_work1�ɐ��l���R�s�[
						sp1->d_num = atof(c_work1); //������������ɕϊ�
						break;
					}
				}
			}

			//�z��̃��Z�b�g
			for (i = 0; i < len1; i++)
			{
				c_work1[i] = '\0';
			}
			flg = 0; //�t���O�̃��Z�b�g
			len1 = 0; //�������̃��Z�b�g
		}
		else if (strncmp(buf1, "char", 4) == 0) //�^����F����
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
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			else if (cnt1 == 1)
			{
				sp1->next = (Stack_I*)malloc(sizeof(Stack_I));
				sp1 = sp1->next;
				sp1->next = NULL;
				//�l�̃��Z�b�g
				sp1->num = 0;
				sp1->f_num = 0.0;
				sp1->d_num = 0.0;
			}
			strcpy(sp1->type, buf1);

			//�����l�����͂���Ă��邩�ǂ����̔���
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					flg = 1;
					break;
				}
			}

			if (flg == 0) //�����l�Ȃ�
			{
				strcpy(sp1->val_name, buf2);
				sp1->val_len = strlen(buf2);
			}
			else //�����l����
			{
				for (i = 0; buf2[i] != '\0'; i++)
				{
					if (buf2[i] == '=')
					{
						strncpy(sp1->val_name, buf2, i - 1); //�ϐ������\���̂ɓ���
						sp1->val_len = i - 1; //�ϐ����̕��������\���̂ɓ���
						
						for (j = i + 2; buf2[j] != '\0'; j++)
						{
							len1++; //���������J�E���g
						}

						strncpy(sp1->column, &buf2[i + 2], len1); //�\���̂ɕ�������R�s�[
						sp1->col_len = len1; //�\���̂ɕ���������
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
		else if (strncmp(buf1, "scan", 4) == 0) //����F����
		{
			scanf(" %[^\n]%*c", &buf2);
			for (i = 0; buf2[i] != '\0'; i++)
			{
				if (buf2[i] == '=')
				{
					strncpy(c_work1, buf2, i - 1); //�ϐ�����z��ɓ���
					for (j = i + 2; buf2[j] != '\0'; j++)
					{
						len1++; //���͒l�̕��������J�E���g
					}
					strncpy(c_work2, &buf2[i + 2], len1); //c_work2�ɓ��͂���l���R�s�[
					break;
				}
			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				if (strncmp(sp1->val_name, c_work1, sp1->val_len) == 0)
				{
					//���͂����ϐ��̌^�𔻒�
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
		else if (strncmp(buf1, "print", 5) == 0) //����F�o��
		{
			scanf("%s", buf2);
			len2 = strlen(buf2);
			sp1 = startp;
			while (sp1 != NULL)
			{
				//�o�͂���ϐ����\���̂��猟��
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
					//�o�͂���ϐ��̌^����
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

			if (sp1 == NULL) //�o�̓f�[�^���ϐ��łȂ��ꍇ
			{
				printf("%s\n", buf2);
			}
		}
		else if(strncmp(buf1, "calc", 4) == 0) //����F�v�Z
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
					//�v�Z�����l��������ϐ�����c_work1�ɃR�s�[
					strncpy(c_work1, buf2, i - 1);
					len2 = i - 1;
					break;
				}
			}

			j = i + 2;
			k = j;
			for (i = i + 2; buf2[i] != '\0'; i++)
			{
				//���Z�q�̔���
				if (buf2[i] == '+'
				 || buf2[i] == '-'
				 || buf2[i] == '*'
				 || buf2[i] == '/')
				{
					ope_work[ope_cnt++] = buf2[i]; //�擪���珇�ɉ��Z�q���L��
					cnt2++;
				}
			}

			ope_cnt = 0;
			while (buf2[j] != '\0')
			{
				if (buf2[j] == '(') // ( �������Ƃ��t���O�𑝂₷
				{
					flg += 2;
				}
				else if (buf2[j] == ')') // ) �������Ƃ��t���O�����炷
				{
					flg -= 2;
				}
				
				switch (buf2[j]) //���Z�q�̗D�揇�ʂ̌v�Z�E���
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
					  || buf2[j] == '.') //���ɕϐ��łȂ��l�������Ă���ꍇ
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
						//�v�Z�p�̔z��ɒl����
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

				//���̕ϐ��̂Ƃ���܂�buf2�̔z������炷
				while ((buf2[j] < 0x30 || buf2[j] > 0x39)
					&& (buf2[j] < 0x41 || buf2[j] > 0x5a)
					&& (buf2[j] < 0x61 || buf2[j] > 0x7a))
				{
					j++;
					//buf2�̔z��̍Ō�܂ŗ�����t���O�𗧂Ă�
					if (buf2[j] == '\0')
					{
						flg = 1;
						break;
					}
				}
				
				//�t���O�������Ă���ꍇ���[�v�𔲂���
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
					//�D�揇�ʂ���ԑ傫�����Z�q�̓Y���������
					if (pri[n_work1] < pri[i + 1])
					{
						n_work1 = i + 1;
					}
					i++;
				}

				//�D�揇�ʂ̑傫���Ƃ�����Ɍv�Z����
				switch (ope_work[n_work1])
				{
				case '+': //���Z
					n_work2[n_work1] = n_work2[n_work1] + n_work2[n_work1 + 1];
					//�v�Z�Ɏg�����l��O�ɋl�߂�
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '-': //���Z
					n_work2[n_work1] = n_work2[n_work1] - n_work2[n_work1 + 1];
					//�v�Z�Ɏg�����l��O�ɋl�߂�
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '*': //��Z
					n_work2[n_work1] = n_work2[n_work1] * n_work2[n_work1 + 1];
					//�v�Z�Ɏg�����l��O�ɋl�߂�
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				case '/': //���Z
					n_work2[n_work1] = n_work2[n_work1] / n_work2[n_work1 + 1];
					//�v�Z�Ɏg�����l��O�ɋl�߂�
					for (j = n_work1 + 2; j < cnt2 + 2; j++)
					{
						n_work2[j - 1] = n_work2[j];
					}
					break;
				}

				//���Z�q�ƗD�揇�ʂ�����O�ɋl�߂�
				for (j = n_work1 + 1; j < cnt2 + 1; j++)
				{
					pri[j - 1] = pri[j];
					ope_work[j - 1] = ope_work[j];
				}

			}

			sp1 = startp;
			while (sp1 != NULL)
			{
				//�v�Z���ʂ���͂���\���̂����
				if (strncmp(sp1->val_name, c_work1, len2) == 0)
				{
					//�v�Z���ʂ̓���
					//���͂���\���̂̌^�����
					if (strncmp(sp1->type, "int", 3) == 0)
					{
						//int�^
						sp1->num = n_work2[0];
					}
					else if (strncmp(sp1->type, "float", 5) == 0)
					{
						//float�^
						sp1->f_num = n_work2[0];
					}
					else if (strncmp(sp1->type, "double", 6) == 0)
					{
						//double�^
						sp1->d_num = n_work2[0];
					}
				}
				sp1 = sp1->next;
			}
			k = 0;
		}
		else if (strncmp(buf1, "if", 2) == 0) //����F��r
		{
			scanf(" %[^\n]%*c", &buf2);
			j = 0;
			for (i = 0; buf2[i] != '\0'; i++)
			{
				len1++;
				if (buf2[i + 1] == ' ' || buf2[i + 1] == '\0')
				{
					if (flg == 0) //�ϐ�1�̔���
					{
						strncpy(c_work1, &buf2[j], len1); //c_work1�ɕϐ������R�s�[
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 1;
					}
					else if (flg == 1) //��r���Z�q�̔���
					{
						strncpy(ope_work, &buf2[j], len1); //ope_work�ɉ��Z�q���R�s�[
						i += 1;
						j = i + 1;
						len1 = 0;
						flg = 2;
					}
					else //�ϐ�2�y�ђl�̔���
					{
						strncpy(c_work2, &buf2[j], len1); //c_work2�ɕϐ���or�l���R�s�[

						//���͒l���l�������ꍇ
						if (c_work2[0] >= 0x30 && c_work2[0] <= 0x39)
						{
							n_work3 = atof(c_work2); //���l�ɕϊ�
							n_flg = 1; //�t���O�𗧂Ă�
						}
						
						len1 = 0;
						flg = 0;
						break;
					}
				}
			}
			
			sp1 = startp;
			while (sp1 != NULL) //�ϐ�1�̏ꏊ�����
			{
				if (strncmp(c_work1, sp1->val_name, sp1->val_len) == 0)
				{
					//�ϐ�1�̌^����
					if (strncmp(sp1->type, "int", 3) == 0) //����Fint�^
					{
						type_flg = 0;
					}
					else if (strncmp(sp1->type, "float", 5) == 0) //����Ffloat�^
					{
						type_flg = 1;
					}
					else if (strncmp(sp1->type, "double", 6) == 0) //����Fdouble�^
					{
						type_flg = 2;
					}
					else //char�^�������ꍇ
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
					if (strncmp(c_work2, sp2->val_name, sp2->val_len) == 0) //�ϐ�2�̏ꏊ�����
					{
						//�ϐ�2�̌^����
						if (strncmp(sp2->type, "int", 3) == 0) //����Fint�^
						{
							n_work3 = sp2->num;
						}
						else if (strncmp(sp2->type, "float", 5) == 0) //����Ffloat�^
						{
							n_work3 = sp2->f_num;
						}
						else if (strncmp(sp2->type, "double", 6) == 0) //����Fdouble�^
						{
							n_work3 = sp2->d_num;
						}
						else //char�^�������ꍇ
						{
							if_flg = 2;
						}
						break;
					}
					sp2 = sp2->next;
				}
			}

			if (type_flg == 0) //�ϐ�1��int�^�������ꍇ
			{
				if_flg = int_if(sp1->num, n_work3, ope_work);
			}
			else if (type_flg == 1) //�ϐ�1��float�^�������ꍇ
			{
				if_flg = float_if(sp1->f_num, n_work3, ope_work);
			}
			else if (type_flg == 2) //�ϐ�1��double�^�������ꍇ
			{
				if_flg = double_if(sp1->d_num, n_work3, ope_work);
			}

			if (if_flg == 0) //�^�������ꍇ
			{
				printf("true\n");
			}
			else if(if_flg == 1) //�U�������ꍇ
			{
				printf("false\n");
			}
			else if (if_flg == 2) //��r�ł��Ȃ��ꍇ
			{
				printf("�����E������͔�r�ł��܂���\n");
			}
			
			len1 = strlen(ope_work); //��r���Z�q�̕���������
			for (i = 0; i < len1; i++) //ope_work�̒��g�����Z�b�g
			{
				ope_work[i] = '\0';
			}

			//�t���O�̃��Z�b�g
			n_flg = 0;
			if_flg = 0;
			type_flg = 0;
		}
	}
}