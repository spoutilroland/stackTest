#include <stdlib.h>
#include <list>
class MyStack {
	private:
		std::list<int> stack_a;
		std::list<int> stack_b;
	public:
		MyStack();
		MyStack(std::list<int> stack_a);
		int front_a();
		int back_a();
		int front_b();
		int back_b();
		void sa();
		void sb();
        void pa();
		void pb();
		void ra();
		void rb();
        void rra();
		void rrb();
		void setMyStackA(std::list<int> stack){ this->stack_a = stack;};
		void setMyStackB(std::list<int> stack){ this->stack_b = stack;};
};
