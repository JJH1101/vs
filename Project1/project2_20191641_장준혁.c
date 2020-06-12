#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 list 정의
typedef struct
{
	char name[31]; //variable name을 저장
	int value[100]; //integer value들을 저장
	int n; //integer value의 개수를 저장
}list;

int main()
{
	list info[32]; //variable name과 integer value들, integer value의 개수를 저장하는 구조체

	char line[500]; //사용자가 엔터키를 누르기 전까지 입력하는 것들을 저장하는 배열

	char com[7]; //command를 저장하는 배열

	char check; //사용자가 포맷 이외의 입력을 했는지를 확인하기 위해 사용하는 변수

	char num[400]; //사용자가 입력하는 integer value들을 저장하기 위한 배열

	char temp[12]; //num에 character로 저장된 integer value들을 integer로 변환하기 위해 사용하는 배열

	char var[31]; //명령어 'PRINT', 'INSERT', 'SORT'에서 사용자가 입력한 variable name을 저장

	int ins[32]; //insert할 integer value들을 저장

	int index; //insert할 index를 저장
	
	int flag; //내림차순으로 정렬할건지 오름차순으로 정렬할건지의 여부를 결정하는 변수

	int tmp; //sort하기 위해 사용하는 변수

	int i = 0, j = 0, k = 0, l = 0; //for문 안에서 사용되는 변수들

	for (;;)
	{
		printf(">> ");

		fgets(line, 500, stdin); //사용자가 엔터키를 누르기 전까지 입력되는 것을을 line에 저장

		sscanf(line, "%s", com); //첫번째 공백 앞까지, 공백이 없을경우 '\n'앞까지의 문자열을 com에 저장

		/* 
		com이 EXIT이면 프로그램 종료
		사용자가 EXIT 이외에 다른 것을 입력했으면 "error\n" 출력
		*/
		if (strcmp(com,"EXIT") == 0)
		{
			if (sscanf(line, "%s %c", com, &check) == 1) //check를 사용해 사용자가 EXIT 이외에 다른 입력을 했는지 확인
				break;
			else
				printf("error\n");
		}


		/*
		사용자가 "LIST {variable name} {integer values}"의 포맷으로 입력했으면 variable name을 info[i].name에 저장하고, integer value들을 info[i].value에 저장 후 integer value의 개수를 info[i].n에 저장
		포맷보다 적게 입력했을 경우 "error\n" 출력, 단 integer value는 없어도 됨
		variable name이 LIST, PRINT, INSERT, SORT, EXIT 중의 하나일 경우 "error\n" 출력
		variable name에 알파벳 이외의 다른 문자가 있을 경우 "error\n" 출력
		integer value가 없으면 빈 리스트 생성
		integer value가 integer가 아니면 "error\n" 출력
		*/
		else if (strcmp(com, "LIST") == 0)
		{
			//line의 첫 공백 전까지의 문자열을 com에 두번째 공백 전까지의 스트링을 info[i].name에 나머지를 num에 저장
			if (sscanf(line, "%s %s %[^n]s", com, info[i].name, num) >= 2)
			{
				//variable name이 LIST, PRINT, INSERT, SORT, EXIT 중의 하나일 경우 "error\n" 출력 후 for문 시작 부분으로 돌아감
				if (strcmp(info[i].name, "LIST") == 0 || strcmp(info[i].name, "PRINT") == 0 || strcmp(info[i].name, "INSERT") == 0 || strcmp(info[i].name, "SORT") == 0 || strcmp(info[i].name, "EXIT") == 0)
				{
					printf("error\n");
					continue;
				}
				
				//info[i].name이 알파벳으로만 이루어졌는지 확인
				for (j = 0; j < strlen(info[i].name); j++)
				{
					if (info[i].name[j] < 'A' || info[i].name[j] > 'z')
						break;
					else if ('Z' < info[i].name[j] && info[i].name[j] < 'a')
						break;
				}

				//info[i].name이 알파벳으로만 이루어졌으면
				if (j == strlen(info[i].name))
				{
					//num에 입력된 것이 없으면 info[i].n을 0으로 설정하고 i를 1증가 후 for문 처음으로 돌아감
					if (sscanf(line, "%s %s %[^n]s", com, info[i].name, num) == 2)
					{
						info[i].n = 0;
						i++;
						continue;
					}

					l = 0, k = 0; //l과 k의 값 0으로 초기화

					//num에 저장된 것들이 integer인지 확인
					for (j = 0; j < strlen(num); j++)
					{
						//num[j]가 공백 또는 '\n'이 아니면 num[j]의 값을 temp[k]에 대입 후 k의 값 1증가
						if (num[j] != ' ' && num[j] != '\n')
						{
							temp[k] = num[j];
							k++;
						}

						//num[j]가 공백 또는 '\n'이면
						else
						{
							temp[k] = '\0'; //temp[k]를 '\0'로 설정

							// temp[0]이 '-'이면
							if (temp[0] == '-')
							{
								//temp가 integer값들로 이루어졌는지 확인
								for (k = 1; k < strlen(temp); k++)
								{
									if ('0' > temp[k] || temp[k] > '9')
										break;
								}

								//temp가 integer값들로 이루어졌으면 temp를 integer로 변환 후 info[i].value[l]에 저장하고 k의 값을 0으로 초기화하고 l의 값 1증가
								if (k == strlen(temp))
								{
									info[i].value[l] = atoi(temp);
									k = 0;
									l++;
								}

								//temp가 integer가 아니면 for문 탈출
								else
									break;
							}

							//temp[0]이 숫자이면
							else if ('0' <= temp[0] && temp[0] <= '9')
							{
								//temp가 integer값들로 이루어졌는지 확인
								for (k = 1; k < strlen(temp); k++)
								{
									if ('0' > temp[k] || temp[k] > '9')
										break;
								}

								//temp가 integer값들로 이루어졌으면 temp를 integer로 변환 후 info[i].value[l]에 저장하고 k의 값을 0으로 초기화하고 l의 값 1증가
								if (k == strlen(temp))
								{
									info[i].value[l] = atoi(temp);
									k = 0;
									l++;
								}

								//temp가 integer가 아니면 for문 탈출
								else
									break;
							}
							//temp[0]이 '-' 또는 숫자가 아니면 for문 탈출
							else
								break;
						}
					}

					//num에 저장된 것들이 모두 integer이면(공백, '\n', '\0' 제외) info[i].n에 l의 값을 대입, i의 값 1증가 후 for문 처음으로 돌아감
					if (j == strlen(num))
					{
						info[i].n = l;
						i++;
						continue;
					}

					//num에 저장된 것들 중 integer가 아닌 것이 있으면(공백, '\n', '\0' 제외) "error\n" 출력 후 for문 처음으로 돌아감
					else
					{
						printf("error\n");
						continue;
					}
				}

				//info[i].name에 알파벳이 아닌 것이 있으면 "error\n" 출력 후 for문 처음으로 돌아감
				else
				{
					printf("error\n");
					continue;
				}
			}

			//사용자가 LIST만 입력하고 variable name을 입력하지 않으면 "error\n" 출력 후 처음으로 돌아감
			else
			{
				printf("error\n");
				continue;
			}
		}

		/*
		사용자가 "PRINT {varname}의 포맷으로 입력했으면 varname에 저장된 값들을 출력 (varname이 info[i].name이면 info[i].value를 출력)
		포맷보다 더 적거나 더 많게 입력했으면 "error\n" 출력
		varname에 저장된 integer값이 없으면 "empty\n" 출력
		list에서 varname을 찾을 수 없으면 "not found\n" 출력
		*/
		else if (strcmp(com, "PRINT") == 0)
		{
			//"PRINT {varname}의 포맷으로 입력했으면 varname을 var에 저장.
			if (sscanf(line, "%s %s %c", com, var, &check) == 2)
			{
				//var이 info.name에 있는지 확인
				for (j = 0; j < i; j++)
				{
					//var이 info[j].name이면
					if (strcmp(var, info[j].name) == 0)
					{
						//info[j].value에 저장된 integer value가 없으면 "empty\n" 출력 후 for문 탈출
						if (info[j].n == 0)
						{
							printf("empty\n");
							break;
						}
						//info[j].value에 저장된 integer value들이 있으면 저장된 값들 출력 후 for문 탈출
						else
						{
							for (k = 0; k < info[j].n; k++)
								printf("%d ", info[j].value[k]);
							printf("\n");
							break;
						}
					}
				}

				//var을 찾을 수 없으면 "not found\n" 출력
				if (j == i)
					printf("not found\n");
			}
			//포맷보다 더 적거나 더 많게 입력했으면 "error\n" 출력
			else
				printf("error\n");
		}

		/*
		사용자가 "INSERT {variable name} {index} {integer values}의 포맷으로 입력하면 {variable name}에 저장된 integer값의 {index}에 {integer values}를 삽입
		포맷보다 적게 입력하면 "error\n" 출력
		index가 list length 보다 크면 "error\n" 출력
		삽입 후에 list length가 32보다 크면 "error\n" 출력
		list에서 variable name을 찾을 수 없으면 "not found" 출력
		integer values가 integer가 아니면 "error\n" 출력
		*/
		else if (strcmp(com, "INSERT") == 0)
		{
			//사용자가 "INSERT {variable name} {index} {integer values}의 포맷으로 입력하면 variable name을 var에 index를 index에 나머지를 num에 저장
			if (sscanf(line, "%s %s %d %[^n]s", com, var, &index, num) == 4)
			{
				//var이 info.name에 있는지 확인
				for (j = 0; j < i; j++)
				{
					//var이 info[j].name과 같으면
					if (strcmp(var, info[j].name) == 0)
					{
						//index가 저장된 integer값의 개수와 크거나 같으면 "error\n" 출력 후 for문 탈출
						if (index >= info[j].n)
						{
							printf("error\n");
							break;
						}
						int a;
						l = 0, k = 0; // l과 k의 값 0으로 초기화

						//num에 저장된 것들이 integer인지 확인
						for (a = 0; a < strlen(num); a++)
						{
							//num[a]가 공백 또는 '\n'이 아니면 num[j]의 값을 temp[k]에 대입 후 k의 값 1증가
							if (num[a] != ' ' && num[a] != '\n')
							{
								temp[k] = num[a];
								k++;
							}

							//num[a]가 공백 또는 '\n'이면
							else
							{
								temp[k] = '\0'; //temp[k]를 '\0'으로 설정

								//temp[0]이 '-'이면
								if (temp[0] == '-')
								{
									//temp가 integer값들로 이루어졌는지 확인
									for (k = 1; k < strlen(temp); k++)
									{
										if ('0' > temp[k] || temp[k] > '9')
											break;
									}

									//temp가 integer값들로 이루어졌으면 temp를 integer로 변환 후 ins[l]에 저장하고 k의 값을 0으로 초기화하고 l의 값 1증가
									if (k == strlen(temp))
									{
										ins[l] = atoi(temp);
										k = 0;
										l++;
									}

									//temp가 integer가 아니면 for문 탈출
									else
										break;
								}

								//temp[0]이 숫자이면
								else if ('0' <= temp[0] && temp[0] <= '9')
								{
									//temp가 integer값들로 이루어졌는지 확인
									for (k = 1; k < strlen(temp); k++)
									{
										if ('0' > temp[k] || temp[k] > '9')
											break;
									}

									//temp가 integer값들로 이루어졌으면 temp를 integer로 변환 후 ins[l]에 저장하고 k의 값을 0으로 초기화하고 l의 값 1증가
									if (k == strlen(temp))
									{
										ins[l] = atoi(temp);
										k = 0;
										l++;
									}

									//temp가 integer가 아니면 for문 탈출
									else
										break;
								}

								//temp[0]이 '-' 또는 숫자가 아니면 for문 탈출
								else
									break;
							}
						}

						//num에 저장된 것들이 모두 integer이면(공백, '\n', '\0' 제외)
						if (a == strlen(num))
						{
							//삽입 후에 저장된 integer value의 개수가 32개 이상이면 "error\n" 출력 후 for문 탈출
							if (info[j].n + l > 32)
							{
								printf("error\n");
								break;
							}

							//삽입 후 저장된 integer value의 개수가 32개 이하이면
							else
							{
								//index부터 저장된 integer value들의 인덱스를 l씩 증가시킴
								for (k = info[j].n; k >= index; k--)
								{
									info[j].value[k + l] = info[j].value[k];
								}
								//info[j].n(저장된 integer value들의 개수)를 l만큼 증가시킴
								info[j].n += l;
								//ins에 저장된 값들을 삽입
								for (k = 0; k < l; k++)
								{
									info[j].value[k + index] = ins[k];
								}
								break;
							}
						}
						//num에 저장된 것들 중 integer가 아닌 것이 있으면(공백, '\n', '\0' 제외) "error\n" 출력 후 for문 탈출
						else
						{
							printf("error\n");
							break;
						}
					}
				}

				//var을 찾을 수 없으면 "not found"를 출력
				if (j == i)
					printf("not found\n");
			}

			//포맷보다 적게 입력하면 "error\n" 출력
			else
				printf("error\n");
		}


		/*
		사용자가 "SORT {variable name} {flag}의 포맷으로 입력하면 flag가 1이면 variable name에 저장된 integer value들을 오름차순으로, -1이면 내림차순으로 정렬
		포맷보다 많거나 적게 입력하면 "error\n" 출력
		flag가 1이나 -1이 아니면 "error\n" 출력
		variable name을 찾을 수 없으면 "not found\n" 출력
		*/
		else if (strcmp(com, "SORT") == 0)
		{
			//"SORT {variable name} {flag}의 포맷으로 입력하면 variable name을 var에 flag를 flag에 저장
			if (sscanf(line, "%s %s %d %c", com, var, &flag, &check) == 3)
			{
				//info.name에 var이 있는지 확인
				for (j = 0; j < i; j++)
				{
					//var이 info[j].name과 같으면
					if (strcmp(var, info[j].name) == 0)
					{
						//flag가 1이면 오름차순으로 정렬 후 for문 탈출
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

						//flag가 -1이면 내림차순으로 정렬 후 for문 탈출
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

						//flag가 1이나 -1이 아니면 "error\n" 출력 후 for문 탈출
						else
						{
							printf("error\n");
							break;
						}
					}
				}

				//var을 찾을 수 없으면 "not found" 출력
				if (j == i)
					printf("not found\n");
			}
			//포맷보다 더 많거나 더 적게 입력하면 "error\n" 출력
			else
				printf("error\n");
		}

		//com이 LIST, PRINT, INSERT, SORT, EXIT 중 하나가 아니라면 "error\n" 출력
		else
			printf("error\n");
	}

	return 0; //프로그램 종료
}