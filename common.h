#pragma once

#ifndef COMMON_H
#define COMMON_H

#define RC4KEYSIZE  16
#define AESKEYSIZE  32
#define AESIVSIZE   16 


//encryption.c
int rc4Encryption(unsigned char payload[], size_t payloadSize, unsigned char key[], size_t keySize, unsigned char **output);


#endif // !COMMON_H
