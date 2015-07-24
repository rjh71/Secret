#include <stdio.h>
#include <string.h>

void encryption();
void decoding();

int main(void)
{
	int input_num;

	printf(">>>메뉴<<<\n");
	printf("1. 암호화\t2. 복호화\n");
	printf("메뉴를 선택하세요 : ");
	scanf("%d", &input_num);

	switch(input_num)
	{
		case 1 :
			encryption();
			break;

		case 2 :
			decoding();
			break;

		default :
			printf("다시 입력하세요.");
			break;
	}  	
	return 0;
}

void encryption()
{
	char input_words[100] = {' '};
	int secret_key[100] = {0};
	int input_key;
	char input_code[100] = {' '};
	int i = 0, j = 0, x, y;

	getchar();

	printf("암호키(a~z) : ");
	scanf("%s", input_words);
	
	x = strlen(input_words);


	for(i = 0; i < x; i++)
	{
		secret_key[i] = input_words[i] - 96;
	}

	printf("암호할 문장 : ");
	getchar();
	gets(input_code);
	
	y = strlen(input_code);


	while(input_code[j] != '\0')
	{
		if(y >= x)
		{
			for( i = 0; i < y/x*x; )
			{
				if(input_code[i] == ' ')
				{
					i++;
					j++;
					continue;
				}

				input_code[i] = input_code[i]+secret_key[i];

				if(input_code[i] > 122)
				{
					if(input_code[i] == ' ')
						continue;
					else
					{
						input_code[i] -= 26;
						i++;
						j++;
					}
				}
				else
				{
					i++;
					j++;
				}
			}
			for(i= y/x*x; i < y;)
			{
				if(input_code[i] == ' ')
				{
					i++;
					j++;
					continue;
				}

				else
				input_code[i] = input_code[i]+secret_key[i];

				if(input_code[i] > 122)
				{
					input_code[i] -= 26;
					i++;
					j++;
				}
				else
				{
					i++;
					j++;
				}
			}
		}
		else
		{
			for( i = 0; i < y; )

			{
				if(input_code[i] == ' ')
				{
					i++;
					j++;
					continue;
				}

				else
				input_code[i] = input_code[i]+secret_key[i];

				if(input_code[i] > 122)
				{
					if(input_code[i] == ' ')
					{
						i++;
						j++;
						continue;
					}
					else
					{
						input_code[i] -= 26;
						i++;
						j++;
					}
				}
				else
				{
					i++;
					j++;
				}
			}
		}
	}
	printf("%s", input_code);

}
void decoding()
{

}
