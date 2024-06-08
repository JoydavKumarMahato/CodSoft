#include<iostream>
using namespace std;
int addition(int,int);
int subtraction(int,int);
int multiplication(int,int);
float division(int,int);
int main()
{
    int N1,N2;
    char opr;
    
    cout<<"Enter Your First Number:";
    if(!(cin>>N1)){                                           // INPUT ERROR
        cout<<"Error! your input is not a number";
        return 1;
    }
    cout<<"Enter Your Second Number:";
    if(!(cin>>N2)){                                           // INPUT ERROR
        cout<<"Error! your second input is not a number";
        return 1;
    }

    top:
    cout<<"\nEnter Operator: + , - , * , /:";
    cin>>opr;
    if(opr=='+')
    addition(N1,N2);         
    else if(opr=='-')
    subtraction(N1,N2);         
    else if(opr=='*')
    multiplication(N1,N2);        
    else if(opr=='/')
    division(N1,N2);        
    else{  
        cout<<"\nYou Entered The Wrong Oprator.. Please Enter The Right Operator.\n";
        goto top;
    }
    return 0;
}
int addition(int a, int b)
{
    int x=a+b;
    cout<<"\nAddition is :( "<<a<<" + "<<b<<" ) = "<<x;           // Addition
    return 0;
}
int subtraction(int a, int b)
{
    int x=a-b;
    cout<<"\nSubtraction is :( "<<a<<" - "<<b<<" ) = "<<x;       // Subtraction
    return 0;
}
int multiplication(int a, int b)
{
    int x=a*b;
    cout<<"\nMultiplication is :( "<<a<<" * "<<b<<" ) = "<<x;    // Multiplication
    return 0;
}
float division(int a, int b)
{
    top:
    float x;
    if(b==0){
    cout<<"Value Is Not Defined. Try Any Other Numbers.";      // If Second Number Is 0 And Using '/' Operator
    cout<<"\n\nEnter Your First Number:";
    cin>>a;
    cout<<"Enter Your Second Number:";
    cin>>b;
    goto top;
    }
    else{
        x=(float)a/b;
    cout<<"\nDivision is :( "<<a<<" / "<<b<<" ) = "<<x;      // Division
    }
    return 0;
}
