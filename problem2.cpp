
#include <iostream>
using namespace std;
template<class T>
        class Node
                {

                public:
                    T data;
                    Node * next;

                    Node(T data)
                    {
                        next=NULL;
                        this->data=data;
                    }

                };

template<class T>

        class queue
                {
            Node<T> *head,*tail;
            int siz;
                public:
                    queue()
                    {
                        head=tail=NULL;
                        siz=0;
                    }
                    queue(const queue <T> &q)
                    {
                        head= q.head;
                        tail=q.tail;
                    }
                    void push(T data)
                    {
                        Node<T>* temp=new Node<T>(data);

                        //if the queue is empty make head and tail pointing to the new node
                        if(tail==NULL)
                        {
                            head=tail=temp;

                        }
                        /*if queue wasn't empty
                         * we make new node make last node pointing to it
                         * make tail pointing to this node
                         */
                        else
                        {
                            tail->next=temp;
                            tail=temp;
                        }
                        siz++;

                    }
                    void push(Node<T>* n)
                    {
                        if(tail==NULL)
                        {
                            head=tail=n;

                        }
                        else
                        {
                            tail->next=n;
                            tail=n;
                        }
                        siz++;
                    }


                    Node<T>* pop()
                    {
                        //if queue is empty cout massage
                        if(head==NULL)
                        {
                            cout<<"Queue is empty"<<endl;
                        }
                        else
                        {
                            //store previous head in tep nod and move head to next node then delete temp(previous head)
                            Node<T>* temp;
                            temp=head;
                            head=head->next;

                            //If front becomes NULL so the queue becomes empty so we make the tail equal null
                            if(head==NULL)
                            {
                                tail=NULL;
                            }
                            return temp;  //return the deleted node

                        }


                        siz--;

                    }

                    bool isFull()
                    {
                        return false;
                    }

                    bool empty()
                    {
                        if(head==tail&&head==NULL)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    int size()
                    {
                        return siz;
                    }

                    T front()   //return the data of the first node
                    {
                        return head->data;
                    }
                    T back()    //return the data of the first node
                    {
                        return tail->data;
                    }
                    Node<T>* Front()  //return the pointer to first node
                    {
                        return head;
                    }
                    Node<T>* Back()   //return the pointer to last node
                    {
                        return tail;
                    }


                    Node<T> * pointing_to_index(int index)  //make pointer point to the targeted element
                    {
                        Node<T> * temp=head;
                        while(index--)
                        {
                            temp=temp->next;
                        }
                        return temp;
                    }

                };


int main() {
    queue<int>q;
    char c;
    cin>>c;
    int num;
    while(cin>>num>>c)   //input tickets of the queue
        {

        q.push(num);
        if(c==']')
        {
            break;
        }
        }
    int k,time=0;

    cin>>k;
    if(k<0||k>=q.size())  //check the validation of index
        {
        cout<<"This person doesn't exist"<<endl;
        }

    Node<int>* target;
    target=   q.pointing_to_index( k);
    while(target->data!=0)
    {
        if(q.front()>0)
        {
            q.Front()->data--;
            time++;
            q.push(q.pop());
        }
        else if(q.front()==0)
        {
            q.pop();
        }
    }
    cout<<time<<endl;

    /*
     * example inputs
     * first test case
       [ 5 , 1 , 1 , 1 ]
       0
     *  //////////
     *  second test case
        [ 2 , 3 , 2 ]
        2
    *///////////////

    return 0;
}
