#include <iostream>
#include <string>
using namespace std;

class BigInt {

    string str;
    long long int num;


public :


    BigInt (){str= "";}

    BigInt (string decStr)
    {
        str = decStr;
    }

    BigInt (long long int decInt)
    {
        num = decInt;
    }

    BigInt operator+(BigInt anotherDec)
    {
        if (str[0]== '-' && anotherDec.str[0]== '-')
        {
            str.erase(0,1);
            anotherDec.str.erase(0,1);

             BigInt x;

        int carry=0;
        for (int i =str.size()-1; i>=0; i--)
             {
               carry = (str[i]- '0')+(anotherDec.str[i]- '0')+ carry;
               x.str = char((carry%10)+ '0')+ x.str;
               carry /=10;
             }
        if (carry == 1)
            {
              x.str = '1' + x.str;
            }

        x.str = '-' + x.str;
        return x;


        }
        else if (anotherDec.str[0]== '-')
        {
            anotherDec.str.erase(0,1);

            BigInt x;

           int carry=0,subtract;
        for (int i =str.size()-1; i>=0; i--)
            {
               subtract = (str[i]- '0')-(anotherDec.str[i]- '0')- carry;
                if (subtract < 0) {
                     subtract = subtract + 10;
                       carry = 1;
        }
        else
            carry = 0;

        x.str.push_back(subtract + '0');
        }
        return x;

        }else if (str[0]== '-')
        {
            str.erase(0,1);

            BigInt x;

           int carry=0,subtract;
          for (int i =str.size()-1; i>=0; i--)
            {
               subtract = (str[i]- '0')-(anotherDec.str[i]- '0')- carry;
                if (subtract < 0) {
                     subtract = subtract + 10;
                       carry = 1;
         }
         else
            carry = 0;

         x.str.push_back(subtract + '0');
         }
         x.str = '-' + x.str;
         return x;
        }

        else
        {
            BigInt x;

        int carry=0;
        for (int i =str.size()-1; i>=0; i--)
             {
               carry = (str[i]- '0')+(anotherDec.str[i]- '0')+ carry;
               x.str = char((carry%10)+ '0')+ x.str;
               carry /=10;
             }
        if (carry == 1)
            {
              x.str = '1' + x.str;
            }
        return x;
        }




    }

    BigInt& operator =(const BigInt& anotherdec)
    {
        str= anotherdec.str;
        return *this;
    }


    friend ostream& operator<<(ostream& out, const BigInt& b)
              {
                 out<<b.str<<endl;
                 return out;
              }

    friend int Size (BigInt x);







};


int Size (BigInt x)
{
    cout<< "the size of the number is "<<x.str.size()<<endl;
}




int main()
{


BigInt a("5555"),b("4444"),c;


cout << "Test case 1"<<endl;
cout << "num 1 = "<<a<<endl;
cout << "num 2 = "<<b<<endl;
cout << "the expected value = 9999"<<endl;
c=a+b;
cout << "num 1 + num 2 = "<<c<<endl;
Size(c);

cout <<endl;

BigInt d("6666"),e("-5555"),f;

cout << "Test case 2"<<endl;
cout << "num 1 = "<<d<<endl;
cout << "num 2 = "<<e<<endl;
cout << "the expected value = 1111"<<endl;
f=d+e;
cout << "num 1 + num 2 = "<<f<<endl;
Size(f);


cout <<endl;




BigInt g("-6666"),h("5555"),i;

cout << "Test case 3"<<endl;
cout << "num 1 = "<<g<<endl;
cout << "num 2 = "<<h<<endl;
cout << "the expected value = -1111"<<endl;
i=g+h;
cout << "num 1 + num 2 = "<<i<<endl;
Size(i);


cout <<endl;


BigInt j("-5555"),k("-4444"),l;


cout << "Test case 4"<<endl;
cout << "num 1 = "<<j<<endl;
cout << "num 2 = "<<k<<endl;
cout << "the expected value = -9999"<<endl;
l=j+k;
cout << "num 1 + num 2 = "<<l<<endl;
Size(l);


cout <<endl;


BigInt m("5555"),n("-5555"),o;


cout << "Test case 5"<<endl;
cout << "num 1 = "<<m<<endl;
cout << "num 2 = "<<n<<endl;
cout << "the expected value = 0000"<<endl;
o=m+n;
cout << "num 1 + num 2 = "<<o<<endl;
Size(o);

cout <<endl;










    return 0;
}