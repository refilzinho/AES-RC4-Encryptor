#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int rc4Encryption(unsigned char payload[], size_t payloadSize, unsigned char key[], size_t keySize, unsigned char **output){
	unsigned char s[256];
	unsigned char *tmp;
	int i,j=0;
	int temp;

	*output = (unsigned char *)malloc(sizeof(unsigned char)*payloadSize);
	if(*output == NULL){
		perror("[+] erro malloc");
		return -1;
	}

	memset(*output, 0, payloadSize);

	tmp = *output;
	

	//initialize s-box
	for(i=0;i<256;i++){
		s[i] = i;
	}

	//permutation
	for(i=0;i<256;i++){
		j = (j + s[i] +key[i%keySize])%256;

		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

	}
	
	i,j=0;

	for(int k=0; k<payloadSize;k++){
		i = (i+1)%256;
		j = (j+s[i])%256;
		
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

		*tmp = payload[k] ^ s[(s[i] + s[j])%256];
		tmp++;

	}

	return 0;
}