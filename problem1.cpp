
#include <iostream>
using namespace std;

const int SIZE = 10000;
template<class T>
        class Stack {
        private:
            T* list =new T[SIZE];
            int length;

        public:
            //default constructor

            Stack(){
                length=0;
            }

            //parameterized constructor
            Stack(int l)
            {

                length =l;
            }


            bool isEmpty()
            {
                return (length==0);
            }

            //push element at the top of stack
            void push(T value)
            {
                if (length >= SIZE)
                    cout << "Stack is full";
                else
                {
                    length++;
                    list[length] = value;

                }
            }

            //pop the top element
            void pop()
            {
                if (isEmpty())
                    cout << "stack is empty";
                else
                    length--;
            }


            //return the top element
            T& Top()
            {
                if (isEmpty())
                    cout << "stack is empty";
                else
                    return list[length];

            }


            void print() {
                for (int i=length; i>=0; i--)
                {
                    cout<<list[i]<<" ";
                }
                cout<<endl;
            }

            int getSize()
            {
                return length;
            }

            void reverse()
            {
                Stack<T> reversedStack;
                while(!isEmpty())
                {

                    reversedStack.push(Top());
                    pop();
                }
                reversedStack.print();
            }

            ~Stack()
            {
                delete []list;
            }

        };


int main() {

    string res= "",tmp,path;
    while (true)
    {
        cin>>path;
        if(path=="0") break;

        Stack<string> s;

        for (int i = 0; i < path.length(); i++) {
            tmp="";

            if (path[i] == '/')
                i++;

            while ( path[i] != '/') {
                tmp+=path[i];
                i++;
            }

            if (tmp == "..") {
                if (!s.isEmpty())
                    s.pop();
            } else if (tmp == ".")
                continue;

            else if (tmp.length() != 0)
                s.push(tmp);
        }

        //    s.print();

        while (!s.isEmpty()){
            res="/"+ s.Top()+res;
            s.pop();
        }
        if(res.size()==0){
            res= "/";
        }
        cout<< res<<endl;
        res="";
    }

    return 0;
}

/*

/home//foo/
/home/
/../
/../a/b/./c/../
/a/../

*/