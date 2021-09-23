
#ifndef _SHELL_
#define _SHELL_

#define MAX_HISTORY  100
#define MAX_ARGS     100
#define MAX_COMMANDS 100

//A structure containing the histoy of commands
typedef	struct{	
	char command[100];
	int max;
}history[MAX_HISTORY];

//Screen color
typedef	struct{	
	char fore;
	char back;
}COLOR;

typedef struct{
	char command[20];	//Name of command
	unsigned char addr; //Address of function
}TASK;

//Define the cursor structure
typedef struct{
	int x;
	int y;
	//int visivle
	//int mode/size
}cursor;

extern cpu_dump();
//A variable containing the prompt


extern cursor cursor_pos();
extern void shell(void);
void color(int argc, char *argv[]);

//void get_cpu(void);
void off(void);
void logon(void);
void logtime(void);
void f_logo();
void device(int argc, char *argv[]);

               //input        //output
int set_args(const char *str,char *argv[]);
//static int split_to_argv(char *str, char *argv[])

void exec(int argc, char* argv[]);


void int32_test(void);
void man(int argc, char *argv[]);
void echo(int argc, char *argv[]);
void flags(int argc, char* argv[]);
void dump(int argc, char* argv[]);

//void int32_test(int argc, char* argv[]);


void create_task(char *com, unsigned char addr);
void testing(void);
void kill_proc(void);

void write_font(void);
void Print_8x8_Gray(int x,int y,unsigned char c);
//Set The console prompt
void setPrompt(int argc, const char *argv[]);
char* getPrompt();

void switch_paging(int argc, char *argv[]);

	/*char *argv[100]; //All the agruments   (global)
	int argc;        //Number of arguments (global)
*/
/*
	static char *argv[100];  //All the agruments   (global)
	static int argc;         //Number of arguments (global)
*/
	//The list of commands and pointers to their functions
	typedef struct{
		char command[20];	//Name of command
		void (*execute)();	//Pointer to function
		char desc[200];     //Description of the command
	}shell_command;

	void system(const char* command);
	
#endif

