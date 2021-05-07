#include "VM.h"
#include <iostream>
#include <utility>
#include <cstring>


VM::VM(std::vector<unsigned char> commands)
	: commands(std::move(commands)), ip(0), reg1(0), reg2(0),zf(false),user_input_index(0)
{
	std::cout << "ENTER ADMIN PASSWORD:" << std::endl;
	std::cin >> this->user_input;
	if(this->user_input.size() != 14)
	{
		std::cout << "PASSWORDS LENGTH DOES NOT MATCH!" << std::endl;
		exit(EXIT_FAILURE);
	}
};

void VM::run()
{
	
	while (true)
	{
		this->execute();
	}
}

void VM::execute()
{
	if (this->commands.size() == static_cast<size_t>(ip))
	{
		std::cout << "CONGRATULATIONS!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	unsigned char command = this->commands[this->ip++];
	const bool register1 = static_cast<bool>(command & 0x1);
	
	command = static_cast<char>(command & 0xfe);
	if (command & 0x2)
	{
		this->push(register1);
	}

	else if (command & 0x4)
	{
		this->pop(register1);
	}

	else if (command & 0x8)
	{
		this->x0_r(register1);
	}

	else if (command & 0x10)
	{
		this->cmp();
	}

	else if ((command & 0x20))
	{
		this->load(register1);
	}
	

	else if ((command & 0x40))
	{
		this->read(register1);
	}

	else if (command & 0x80)
	{
		this->exit_not_zero();
	}

	else
	{
		std::cerr << "Unknown command: " << std::hex << (char)(command | 0x1) << " ip = " << this->ip;
		exit(1);
	}

	if(!(command & 0x10))
	{
		this->zf = false;
	}
}

void VM::push(bool register1)
	{
		if (register1)
		{
			this->stack.push_back(this->reg1);
		}
		else
		{
			this->stack.push_back(this->reg2);
		}
	}

void VM::pop(bool register1)
{
	if (register1)
	{
		this->reg1 = this->stack.back();
	}
	else
	{
		this->reg2 = this->stack.back();
	}

	this->stack.pop_back();
}

void VM::x0_r(bool register1)
{
	if (register1)
	{
		this->reg1 = this->reg1 ^ this->reg2;
	}

	else
	{
		this->reg2 = this->reg1 ^ this->reg2;
	}
}

void VM::cmp()
{
	this->zf = (this->reg1 == this->reg2);
}

void VM::load(bool register1)
{
	if(register1)
	{
		std::memcpy(&this->reg1, &this->commands[ip], sizeof(this->reg1));
	}

	else
	{
		std::memcpy(&this->reg2, &this->commands[ip], sizeof(this->reg2));
	}

	this->ip += 4;
}

void VM::read(bool register1)
{
	if(register1)
	{
		this->reg1 = static_cast<int>(this->user_input[this->user_input_index++]);
	}

	else
	{
		this->reg2 = static_cast<int>(this->user_input[this->user_input_index++]);
	}
}

void VM::exit_not_zero()
{
	if (!this->zf)
	{
		std::cout << "bye" << std::endl;
		exit(0);
	}
	
}

