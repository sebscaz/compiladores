#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Stack {

private:
   int MAX;
   int top;
   int* items;

public:
	Stack(int size){
		MAX = size;
		top = -1;
		items = new int[MAX];
	}

	~Stack(){ delete [] items; }

	void push(int c){
		if(full()){
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	int pop(){
		if(empty()){
			cout << "Stack Empty!" << endl;
			exit(1);
		}

		return items[top--];
	}

	int empty(){ return top == -1; }

	int full(){ return top+1 == MAX; }
};
/*
int main(){

	Stack st(20);

        //random number seed
        srand(time(NULL));
        int i = 0;

        //place 20 random integers on the stack
        while(i < 20){
            int n = rand() % 100 + 1; //numbers 1 to 100
            st.push(n); //add to the stack
            i++;
        }

        //remove all the data
	for(int j = 0; j < 20; j++)
		cout << st.pop() << " ";

	return 0;
}*/
