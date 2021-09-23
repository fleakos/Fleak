
// fs.h -- Defines the interface for and structures relating to the virtual file system.
//         Written for JamesM's kernel development tutorials.

#ifndef FS_H
#define FS_H

#include "common.h"

	//File attributes
	#define FS_FILE        0x01
	#define FS_DIRECTORY   0x02
	#define FS_CHARDEVICE  0x03
	#define FS_BLOCKDEVICE 0x04
	#define FS_PIPE        0x05
	#define FS_SYMLINK     0x06
	#define FS_MOUNTPOINT  0x08 // Is the file an active mountpoint?
	
	#define	S_IFIFO	0x1000	// FIFO
	#define	S_IFREG	0x8000	// Regular

	//File permissions
	#define	S_IEXEC	 0x0040
	#define	S_IWRITE 0x0080
	#define	S_IREAD	 0x0100


// These typedefs define the type of callbacks - called when read/write/open/close
// are called.
	struct fs_node;
	static char cdir[100];
	
	int IND;
	
typedef unsigned int(*read_type_t)(struct fs_node*,unsigned int,unsigned int,u8int*);
typedef unsigned int(*write_type_t)(struct fs_node*,unsigned int,unsigned int,u8int*);
typedef void(*open_type_t)(struct fs_node*);
typedef void(*close_type_t)(struct fs_node*);
typedef struct dirent *(*readdir_type_t)(struct fs_node*,unsigned int);
typedef struct fs_node *(*finddir_type_t)(struct fs_node*,char *name);
	
typedef struct fs_node{
    char name[128];      // The filename.
    unsigned int mask;   // The permissions mask.
    unsigned int uid;    // The owning user.
    unsigned int gid;    // The owning group.
    unsigned int flags;  // Includes the node type. See #defines above.
    unsigned int inode;  // This is device-specific - provides a way for a filesystem to identify files.
    unsigned int length; // Size of the file, in bytes.
    
	unsigned int id;   	
	unsigned int parent; 

	char date[30];
	
	read_type_t    read;
    write_type_t   write;
    open_type_t    open;
    close_type_t   close;
    readdir_type_t readdir;
    finddir_type_t finddir;
    struct fs_node *ptr; // Used by mountpoints and symlinks.
} FILE, DIR;

struct dirent{
    char name[128]; 	// Filename.
    unsigned int ino;   // Inode number. Required by POSIX.
};

	
	/* Standard read/write/open/close functions. Note that these are all suffixed with
       _fs to distinguish them from the read/write/open/close which deal with file descriptors
	   ,not file nodes.*/
	   
	extern FILE *fs_root; // The root of the filesystem.
	
	unsigned int read_fs(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
	unsigned int write_fs(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
	void open_fs(FILE *node, u8int read, u8int write);
	void close_fs(FILE *node);
	struct dirent *readdir(FILE *node, unsigned int index);

	FILE *finddir_fs(FILE *node, char *name);
	FILE *fopen(const char *name);
	void fread(void *ptr, FILE* file);
	DIR *opendir(const char* name);
	
	void ListDir(int argc, char *argv[]);
	void cat(int argc, char *argv[]);
	int chmod(const char* name, int mode);
	unsigned int LPT_READ(FILE *node, unsigned int offset, unsigned int size, u8int *buffer);
	
	typedef struct{
		char name[20];
		int gid;
		int uid;
		char home_folder[20];
		char pass[50];
	}USERS;
	
	void pwd(void);
	void chdir(char *name);
	
#endif
