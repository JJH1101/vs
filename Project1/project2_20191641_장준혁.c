#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ü list ����
typedef struct
{
	char name[31]; //variable name�� ����
	int value[100]; //integer value���� ����
	int n; //integer value�� ������ ����
}list;

int main()
{
	list info[32]; //variable name�� integer value��, integer value�� ������ �����ϴ� ����ü

	char line[500]; //����ڰ� ����Ű�� ������ ������ �Է��ϴ� �͵��� �����ϴ� �迭

	char com[7]; //command�� �����ϴ� �迭

	char check; //����ڰ� ���� �̿��� �Է��� �ߴ����� Ȯ���ϱ� ���� ����ϴ� ����

	char num[400]; //����ڰ� �Է��ϴ� integer value���� �����ϱ� ���� �迭

	char temp[12]; //num�� character�� ����� integer value���� integer�� ��ȯ�ϱ� ���� ����ϴ� �迭

	char var[31]; //��ɾ� 'PRINT', 'INSERT', 'SORT'���� ����ڰ� �Է��� variable name�� ����

	int ins[32]; //insert�� integer value���� ����

	int index; //insert�� index�� ����
	
	int flag; //������������ �����Ұ��� ������������ �����Ұ����� ���θ� �����ϴ� ����

	int tmp; //sort�ϱ� ���� ����ϴ� ����

	int i = 0, j = 0, k = 0, l = 0; //for�� �ȿ��� ���Ǵ� ������

	for (;;)
	{
		printf(">> ");

		fgets(line, 500, stdin); //����ڰ� ����Ű�� ������ ������ �ԷµǴ� ������ line�� ����

		sscanf(line, "%s", com); //ù��° ���� �ձ���, ������ ������� '\n'�ձ����� ���ڿ��� com�� ����

		/* 
		com�� EXIT�̸� ���α׷� ����
		����ڰ� EXIT �̿ܿ� �ٸ� ���� �Է������� "error\n" ���
		*/
		if (strcmp(com,"EXIT") == 0)
		{
			if (sscanf(line, "%s %c", com, &check) == 1) //check�� ����� ����ڰ� EXIT �̿ܿ� �ٸ� �Է��� �ߴ��� Ȯ��
				break;
			else
				printf("error\n");
		}


		/*
		����ڰ� "LIST {variable name} {integer values}"�� �������� �Է������� variable name�� info[i].name�� �����ϰ�, integer value���� info[i].value�� ���� �� integer value�� ������ info[i].n�� ����
		���˺��� ���� �Է����� ��� "error\n" ���, �� integer value�� ��� ��
		variable name�� LIST, PRINT, INSERT, SORT, EXIT ���� �ϳ��� ��� "error\n" ���
		variable name�� ���ĺ� �̿��� �ٸ� ���ڰ� ���� ��� "error\n" ���
		integer value�� ������ �� ����Ʈ ����
		integer value�� integer�� �ƴϸ� "error\n" ���
		*/
		else if (strcmp(com, "LIST") == 0)
		{
			//line�� ù ���� �������� ���ڿ��� com�� �ι�° ���� �������� ��Ʈ���� info[i].name�� �������� num�� ����
			if (sscanf(line, "%s %s %[^n]s", com, info[i].name, num) >= 2)
			{
				//variable name�� LIST, PRINT, INSERT, SORT, EXIT ���� �ϳ��� ��� "error\n" ��� �� for�� ���� �κ����� ���ư�
				if (strcmp(info[i].name, "LIST") == 0 || strcmp(info[i].name, "PRINT") == 0 || strcmp(info[i].name, "INSERT") == 0 || strcmp(info[i].name, "SORT") == 0 || strcmp(info[i].name, "EXIT") == 0)
				{
					printf("error\n");
					continue;
				}
				
				//info[i].name�� ���ĺ����θ� �̷�������� Ȯ��
				for (j = 0; j < strlen(info[i].name); j++)
				{
					if (info[i].name[j] < 'A' || info[i].name[j] > 'z')
						break;
					else if ('Z' < info[i].name[j] && info[i].name[j] < 'a')
						break;
				}

				//info[i].name�� ���ĺ����θ� �̷��������
				if (j == strlen(info[i].name))
				{
					//num�� �Էµ� ���� ������ info[i].n�� 0���� �����ϰ� i�� 1���� �� for�� ó������ ���ư�
					if (sscanf(line, "%s %s %[^n]s", com, info[i].name, num) == 2)
					{
						info[i].n = 0;
						i++;
						continue;
					}

					l = 0, k = 0; //l�� k�� �� 0���� �ʱ�ȭ

					//num�� ����� �͵��� integer���� Ȯ��
					for (j = 0; j < strlen(num); j++)
					{
						//num[j]�� ���� �Ǵ� '\n'�� �ƴϸ� num[j]�� ���� temp[k]�� ���� �� k�� �� 1����
						if (num[j] != ' ' && num[j] != '\n')
						{
							temp[k] = num[j];
							k++;
						}

						//num[j]�� ���� �Ǵ� '\n'�̸�
						else
						{
							temp[k] = '\0'; //temp[k]�� '\0'�� ����

							// temp[0]�� '-'�̸�
							if (temp[0] == '-')
							{
								//temp�� integer����� �̷�������� Ȯ��
								for (k = 1; k < strlen(temp); k++)
								{
									if ('0' > temp[k] || temp[k] > '9')
										break;
								}

								//temp�� integer����� �̷�������� temp�� integer�� ��ȯ �� info[i].value[l]�� �����ϰ� k�� ���� 0���� �ʱ�ȭ�ϰ� l�� �� 1����
								if (k == strlen(temp))
								{
									info[i].value[l] = atoi(temp);
									k = 0;
									l++;
								}

								//temp�� integer�� �ƴϸ� for�� Ż��
								else
									break;
							}

							//temp[0]�� �����̸�
							else if ('0' <= temp[0] && temp[0] <= '9')
							{
								//temp�� integer����� �̷�������� Ȯ��
								for (k = 1; k < strlen(temp); k++)
								{
									if ('0' > temp[k] || temp[k] > '9')
										break;
								}

								//temp�� integer����� �̷�������� temp�� integer�� ��ȯ �� info[i].value[l]�� �����ϰ� k�� ���� 0���� �ʱ�ȭ�ϰ� l�� �� 1����
								if (k == strlen(temp))
								{
									info[i].value[l] = atoi(temp);
									k = 0;
									l++;
								}

								//temp�� integer�� �ƴϸ� for�� Ż��
								else
									break;
							}
							//temp[0]�� '-' �Ǵ� ���ڰ� �ƴϸ� for�� Ż��
							else
								break;
						}
					}

					//num�� ����� �͵��� ��� integer�̸�(����, '\n', '\0' ����) info[i].n�� l�� ���� ����, i�� �� 1���� �� for�� ó������ ���ư�
					if (j == strlen(num))
					{
						info[i].n = l;
						i++;
						continue;
					}

					//num�� ����� �͵� �� integer�� �ƴ� ���� ������(����, '\n', '\0' ����) "error\n" ��� �� for�� ó������ ���ư�
					else
					{
						printf("error\n");
						continue;
					}
				}

				//info[i].name�� ���ĺ��� �ƴ� ���� ������ "error\n" ��� �� for�� ó������ ���ư�
				else
				{
					printf("error\n");
					continue;
				}
			}

			//����ڰ� LIST�� �Է��ϰ� variable name�� �Է����� ������ "error\n" ��� �� ó������ ���ư�
			else
			{
				printf("error\n");
				continue;
			}
		}

		/*
		����ڰ� "PRINT {varname}�� �������� �Է������� varname�� ����� ������ ��� (varname�� info[i].name�̸� info[i].value�� ���)
		���˺��� �� ���ų� �� ���� �Է������� "error\n" ���
		varname�� ����� integer���� ������ "empty\n" ���
		list���� varname�� ã�� �� ������ "not found\n" ���
		*/
		else if (strcmp(com, "PRINT") == 0)
		{
			//"PRINT {varname}�� �������� �Է������� varname�� var�� ����.
			if (sscanf(line, "%s %s %c", com, var, &check) == 2)
			{
				//var�� info.name�� �ִ��� Ȯ��
				for (j = 0; j < i; j++)
				{
					//var�� info[j].name�̸�
					if (strcmp(var, info[j].name) == 0)
					{
						//info[j].value�� ����� integer value�� ������ "empty\n" ��� �� for�� Ż��
						if (info[j].n == 0)
						{
							printf("empty\n");
							break;
						}
						//info[j].value�� ����� integer value���� ������ ����� ���� ��� �� for�� Ż��
						else
						{
							for (k = 0; k < info[j].n; k++)
								printf("%d ", info[j].value[k]);
							printf("\n");
							break;
						}
					}
				}

				//var�� ã�� �� ������ "not found\n" ���
				if (j == i)
					printf("not found\n");
			}
			//���˺��� �� ���ų� �� ���� �Է������� "error\n" ���
			else
				printf("error\n");
		}

		/*
		����ڰ� "INSERT {variable name} {index} {integer values}�� �������� �Է��ϸ� {variable name}�� ����� integer���� {index}�� {integer values}�� ����
		���˺��� ���� �Է��ϸ� "error\n" ���
		index�� list length ���� ũ�� "error\n" ���
		���� �Ŀ� list length�� 32���� ũ�� "error\n" ���
		list���� variable name�� ã�� �� ������ "not found" ���
		integer values�� integer�� �ƴϸ� "error\n" ���
		*/
		else if (strcmp(com, "INSERT") == 0)
		{
			//����ڰ� "INSERT {variable name} {index} {integer values}�� �������� �Է��ϸ� variable name�� var�� index�� index�� �������� num�� ����
			if (sscanf(line, "%s %s %d %[^n]s", com, var, &index, num) == 4)
			{
				//var�� info.name�� �ִ��� Ȯ��
				for (j = 0; j < i; j++)
				{
					//var�� info[j].name�� ������
					if (strcmp(var, info[j].name) == 0)
					{
						//index�� ����� integer���� ������ ũ�ų� ������ "error\n" ��� �� for�� Ż��
						if (index >= info[j].n)
						{
							printf("error\n");
							break;
						}
						int a;
						l = 0, k = 0; // l�� k�� �� 0���� �ʱ�ȭ

						//num�� ����� �͵��� integer���� Ȯ��
						for (a = 0; a < strlen(num); a++)
						{
							//num[a]�� ���� �Ǵ� '\n'�� �ƴϸ� num[j]�� ���� temp[k]�� ���� �� k�� �� 1����
							if (num[a] != ' ' && num[a] != '\n')
							{
								temp[k] = num[a];
								k++;
							}

							//num[a]�� ���� �Ǵ� '\n'�̸�
							else
							{
								temp[k] = '\0'; //temp[k]�� '\0'���� ����

								//temp[0]�� '-'�̸�
								if (temp[0] == '-')
								{
									//temp�� integer����� �̷�������� Ȯ��
									for (k = 1; k < strlen(temp); k++)
									{
										if ('0' > temp[k] || temp[k] > '9')
											break;
									}

									//temp�� integer����� �̷�������� temp�� integer�� ��ȯ �� ins[l]�� �����ϰ� k�� ���� 0���� �ʱ�ȭ�ϰ� l�� �� 1����
									if (k == strlen(temp))
									{
										ins[l] = atoi(temp);
										k = 0;
										l++;
									}

									//temp�� integer�� �ƴϸ� for�� Ż��
									else
										break;
								}

								//temp[0]�� �����̸�
								else if ('0' <= temp[0] && temp[0] <= '9')
								{
									//temp�� integer����� �̷�������� Ȯ��
									for (k = 1; k < strlen(temp); k++)
									{
										if ('0' > temp[k] || temp[k] > '9')
											break;
									}

									//temp�� integer����� �̷�������� temp�� integer�� ��ȯ �� ins[l]�� �����ϰ� k�� ���� 0���� �ʱ�ȭ�ϰ� l�� �� 1����
									if (k == strlen(temp))
									{
										ins[l] = atoi(temp);
										k = 0;
										l++;
									}

									//temp�� integer�� �ƴϸ� for�� Ż��
									else
										break;
								}

								//temp[0]�� '-' �Ǵ� ���ڰ� �ƴϸ� for�� Ż��
								else
									break;
							}
						}

						//num�� ����� �͵��� ��� integer�̸�(����, '\n', '\0' ����)
						if (a == strlen(num))
						{
							//���� �Ŀ� ����� integer value�� ������ 32�� �̻��̸� "error\n" ��� �� for�� Ż��
							if (info[j].n + l > 32)
							{
								printf("error\n");
								break;
							}

							//���� �� ����� integer value�� ������ 32�� �����̸�
							else
							{
								//index���� ����� integer value���� �ε����� l�� ������Ŵ
								for (k = info[j].n; k >= index; k--)
								{
									info[j].value[k + l] = info[j].value[k];
								}
								//info[j].n(����� integer value���� ����)�� l��ŭ ������Ŵ
								info[j].n += l;
								//ins�� ����� ������ ����
								for (k = 0; k < l; k++)
								{
									info[j].value[k + index] = ins[k];
								}
								break;
							}
						}
						//num�� ����� �͵� �� integer�� �ƴ� ���� ������(����, '\n', '\0' ����) "error\n" ��� �� for�� Ż��
						else
						{
							printf("error\n");
							break;
						}
					}
				}

				//var�� ã�� �� ������ "not found"�� ���
				if (j == i)
					printf("not found\n");
			}

			//���˺��� ���� �Է��ϸ� "error\n" ���
			else
				printf("error\n");
		}


		/*
		����ڰ� "SORT {variable name} {flag}�� �������� �Է��ϸ� flag�� 1�̸� variable name�� ����� integer value���� ������������, -1�̸� ������������ ����
		���˺��� ���ų� ���� �Է��ϸ� "error\n" ���
		flag�� 1�̳� -1�� �ƴϸ� "error\n" ���
		variable name�� ã�� �� ������ "not found\n" ���
		*/
		else if (strcmp(com, "SORT") == 0)
		{
			//"SORT {variable name} {flag}�� �������� �Է��ϸ� variable name�� var�� flag�� flag�� ����
			if (sscanf(line, "%s %s %d %c", com, var, &flag, &check) == 3)
			{
				//info.name�� var�� �ִ��� Ȯ��
				for (j = 0; j < i; j++)
				{
					//var�� info[j].name�� ������
					if (strcmp(var, info[j].name) == 0)
					{
						//flag�� 1�̸� ������������ ���� �� for�� Ż��
						if (flag == 1)
						{
							for (k = 0; k < info[j].n - 1; k++)
							{
								for (l = 0; l < info[j].n - k - 1; l++)
								{
									if (info[j].value[l] > info[j].value[l + 1])
									{
										tmp = info[j].value[l];
										info[j].value[l] = info[j].value[l + 1];
										info[j].value[l + 1] = tmp;
									}
								}
							}
							break;
						}

						//flag�� -1�̸� ������������ ���� �� for�� Ż��
						else if (flag == -1)
						{
							for (k = 0; k < info[j].n - 1; k++)
							{
								for (l = 0; l < info[j].n - k - 1; l++)
								{
									if (info[j].value[l] < info[j].value[l + 1])
									{
										tmp = info[j].value[l];
										info[j].value[l] = info[j].value[l + 1];
										info[j].value[l + 1] = tmp;
									}
								}
							}
							break;
						}

						//flag�� 1�̳� -1�� �ƴϸ� "error\n" ��� �� for�� Ż��
						else
						{
							printf("error\n");
							break;
						}
					}
				}

				//var�� ã�� �� ������ "not found" ���
				if (j == i)
					printf("not found\n");
			}
			//���˺��� �� ���ų� �� ���� �Է��ϸ� "error\n" ���
			else
				printf("error\n");
		}

		//com�� LIST, PRINT, INSERT, SORT, EXIT �� �ϳ��� �ƴ϶�� "error\n" ���
		else
			printf("error\n");
	}

	return 0; //���α׷� ����
}