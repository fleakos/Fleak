// initrd.h -- Defines the interface for and structures relating to the initial ramdisk.
//             Written for JamesM's kernel development tutorials.

	#include "common.h"
	#include "fs.h"

	#ifndef INITRD_H
	#define INITRD_H
	#define MAX_DEVICES 30
	
	FILE *ROOT[10];	  // List of dir  nodes
	FILE *root_nodes; // List of file nodes.
	FILE *devices[10];


	static int SEMAPFORE=0;
	
	typedef struct{
	  unsigned int nfiles; // The number of files in the ramdisk.
	} initrd_header_t;

typedef struct{
    char magic;     	  // Magic number, for error checking.
    char name[64];  	  // Filename.
    unsigned int offset;  // Offset in the initrd that the file starts.
    unsigned int length;  // Length of the file.
	char date[30];		  // File date/time
	int entry;
} initrd_file_header_t;

// Initialises the initial ramdisk. It gets passed the address of the multiboot module,
// and returns a completed filesystem node.
	FILE *initialise_initrd(unsigned int location);

	unsigned int initrd_read(FILE *node, u32int offset, u32int size, u8int *buffer);
	static struct dirent *initrd_readdir(FILE *node, unsigned int index);
	static FILE *initrd_finddir(FILE *node, char *name);

	void mkdir(char* name);
	void mkfile(char* name, unsigned int location);
	void LoadDevices(void);
	int getNodes(void);
	int getDirs(void);
	
	FILE *getInitrd(void);
	
	static char device_list[MAX_DEVICES][20]={
		"LPT", "COM1",  "COM2", "COM3",
		"COM4","STDOUT","STDIN","STDERR",
		"MEM", "CMOS","CPU"
	};
	
	//A structure to a device or port(ex: LPT, COM, KEYBD, AUX)
	typedef struct{
		char name[20];	  		 //Name of command
		unsigned int (*read)();	 //Pointer to function
		unsigned int (*write)(); //Pointer to function
	}DEVICES;

unsigned int LPT_READ(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
unsigned int SCR_R(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
unsigned int SCR_W(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
#endif
