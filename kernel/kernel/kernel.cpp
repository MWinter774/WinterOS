extern "C"
int kmain(void* mbd, unsigned int magic)
{
	if(magic!=0x2BADB002)
	{
		return -1;
	}
	char* fb = (char*)0x000B8000;
	fb[0]='A';
	fb[1]=0x28;
	return 0;
}
