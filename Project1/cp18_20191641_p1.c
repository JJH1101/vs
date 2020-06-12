#include <stdio.h>

union rope {
	unsigned long long ll[1];
	unsigned int i[2];
	unsigned short s[4];
	unsigned char c[8];
};

typedef enum {
	ROPE_C = 1, ROPE_S = 2,ROPE_I = 4, ROPE_LL = 8
}rope_type;

void print_rope(union rope r, rope_type t, int idx) {
	switch (t) {
	case ROPE_C:
		printf("=%02X=", r.c[idx]);
		break;
	case ROPE_S:
		printf("=%04X=", r.s[idx]);
		break;
	case ROPE_I:
		printf("=%08X=", r.i[idx]);
		break;
	case ROPE_LL:
		printf("=%016llX=", r.ll[idx]);
		break;
	default:
		printf("\n");
	}
}

int main()
{
	union rope r = { 0x0123456789ABCDEF };

	int input, rope = 1;

	for (int i = 7; i >= 0; i--)
		print_rope(r, ROPE_C, i);
	print_rope(r, 0, 0);
	
	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		print_rope(r, ROPE_S, 3);
		for (int i = 5; i >= 0; i--)
			print_rope(r, ROPE_C, i);
		print_rope(r, 0, 0);
	}

	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		for (int i = 3; i >= 2; i --)
			print_rope(r, ROPE_S, i);
		for (int i = 5; i >= 0; i--)
			print_rope(r, ROPE_C, i);
		print_rope(r, 0, 0);
	}

	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		print_rope(r, ROPE_I, 1);
		for (int i = 3; i >= 0; i--)
			print_rope(r, ROPE_C, i);
		print_rope(r, 0, 0);
	}

	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		print_rope(r, ROPE_I, 1);
		print_rope(r, ROPE_S, 2);
		for (int i = 1; i >= 0; i--)
			print_rope(r, ROPE_C, i);
		print_rope(r, 0, 0);
	}

	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		print_rope(r, ROPE_I, 1);
		print_rope(r, ROPE_S, 1);
		print_rope(r, ROPE_S, 0);
		print_rope(r, 0, 0);
	}

	scanf("%d", &input);
	if (input == 0)
		return 0;
	else if (input == 1)
	{
		print_rope(r, ROPE_I, 1);
		print_rope(r, ROPE_I, 0);
		print_rope(r, 0, 0);
	}

	for (;;)
	{
		scanf("%d", &input);
		if (input == 0)
			return 0;
		else if (input == 1)
		{
			print_rope(r, ROPE_LL, 0);
			print_rope(r, 0, 0);
		}
	}

	return 0;
}
