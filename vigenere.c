#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

int main(int argc, char *argv[]){

	if (argc == 1)
		return 1;

	char user_inp[MAX_LENGTH];
	
	int cipher_len = strlen(argv[1]);
	int cipher[cipher_len];

	int plaintext_len, i, k=0, print;

	for (i = 0 ; i < cipher_len ; i++){
		
		if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			cipher[i] = argv[1][i] - 'a';
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			cipher[i] = argv[1][i] - 'A';
		else 
			return 1;
	}

	printf("plaintext:  ");
	fgets(user_inp, MAX_LENGTH, stdin);
	
	plaintext_len = strlen(user_inp);

	printf("ciphertext:  ");

	for(i = 0 ; i < plaintext_len ; i++){
		
		if(user_inp[i] >= 'a' && user_inp[i] <= 'z'){
			print = (user_inp[i] - 'a' + cipher[k])%26 + 'a';
			printf("%c", print);

			k = (k+1)%cipher_len;
		} else if (user_inp[i] >= 'A' && user_inp[i] <= 'Z'){
			print = (user_inp[i] - 'A' + cipher[k])%26 + 'A';
			printf("%c", print);
			
			k = (k+1)%cipher_len;
		} else
			printf("%c", user_inp[i]);	
	}
	printf("\n");

	return 0;
}
