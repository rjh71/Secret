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
	char input_words[100];
	int secret_key[100];
	int input_key;
	char input_code[100];
	int i = 0, j = 0;
	int x, y;

	getchar();

	printf("암호키 : ");
	scanf("%s", input_words);

	while(input_words[i] != '\0')
	{
		secret_key[i] = input_words[i] - 96;
		i++;
	}
	i = 0;

	printf("암호할 문장 : ");
	scanf("%s", input_code);

	x = strlen(input_words);
	y = strlen(input_code);

	while(input_code[i] != '\0')
	{
		if(input_code[i] == ' ')
		{
			i++;
			continue;
		}
		for (i = 0; i < ((y/x) * x); i++)
		{
			if (j != x)
				input_code[i] = input_code[i] + secret_key[j];
			else
				j = 0;
		}
		for (i = ((y/x)*x); i < y; i++)
		{
			if (j != x)
				input_code[i] = input_code[i] + secret_key[j];
			else
				j = 0;
		}
		if(input_code[i] == ' ')
		{
			i++;
			continue;
		}
		input_code[i] = input_code[i] + secret_key[j];
		if(input_code[i] > 122)
		{
			input_code[i] -= 26;
			i++;
		}
		else
		{
			i++;
		}
	}
	printf("암호화된 문장 : %s", input_code);

}
void decoding()
{
	char input_word;
	int secret_key;
	int input_key;
	char input_code[100];
	int i = 0;

	getchar();

	printf("암호키(a~z) : ");
	scanf("%c", &input_word);

	secret_key = input_word - 96;

	printf("암호할 문장 : ");

	getchar();

	gets(input_code);

	while(input_code[i] != '\0')
	{
		if(input_code[i] == ' ')
		{
			i++;
			continue;
		}
		input_code[i] = input_code[i]-secret_key;
		if(input_code[i] < 97)
		{
			input_code[i] += 26;
			i++;
		}
		else
			i++;
	}
	printf("암호화된 문장 : %s", input_code);
}
