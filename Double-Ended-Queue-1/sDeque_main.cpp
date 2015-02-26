#include"sDeque.h"

int main(int argc, char **argv) {
	int op=0;
	std::string input;
	Deque *DQ = new Deque();

	while (op<7)
	{
		std::cin>> op;
		switch(op) {
		case 0:
			std::cin>>input;
			DQ->push_front(input);
			break;
		case 1:
			std::cin>>input;
			DQ->push_back(input);
			break;
		case 2:
			std::cout<<DQ->pop_front()<<std::endl;
			break;
		case 3:
			std::cout<<DQ->pop_back()<<std::endl;
			break;
		case 4:
			std::cout<<DQ->toStr();
			break;
		case 5:
			std::cout<<DQ->size()<<std::endl;
			break;
		case 6:
			std::cout<<DQ->empty()<<std::endl;
			break;
		}
	}

	return 0;

}

