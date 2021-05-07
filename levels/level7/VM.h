#include <map>
#include <string>
#include <vector>
#include <fstream>


class VM  
{
public:
	VM(std::vector<unsigned char> commands);
	~VM() = default;
	std::vector<unsigned char> commands;
	int reg1;
	int reg2;
	bool zf;
	int ip;
	std::vector<int> stack;
	std::string user_input;
	int user_input_index;

	//if the first bit is set = reg1, else reg2


	void push(bool register1); //pushes reg1/reg2 OPCODE = 0X2
	void pop(bool register1);  // pops value into reg1/reg2 OPCODE = 0X4
	void x0_r(bool register1);  // xors reg1,reg2 storing results in one of them OPCODE = 0X8
	void cmp();  // cmp reg1, reg2 OPCODE = 0X10
	void load(bool register1); // loads the next 4 chars from commands into register OPCODE = 0X20
	void read(bool register1);
	void exit_not_zero();

	

	void run();
	void execute();

	
};