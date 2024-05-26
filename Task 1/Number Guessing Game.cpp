#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main()
{
	 srand(time(NULL));
	 int number = rand()%100+1;                   // IT GIVE RANDOM NUMBER BETWEEN 1-100
	 int N=0;
	 string name;
	 cout<<"Enter Your Name:";
	 cin>>name;
	 cout<<"You Successfully Entered In Number Guessing Game\n\n";
	 do
	 {
	 	cout << "# Enter Your Number (1-100):";
	 	cin >> N;
	 	
	 	if (N > number)
	 	cout << "You Guessed The Higher Number. Try Any Lower Number\n\n";
	 	else if (N < number)
	 	cout << "You Guessed The Lower Number. Try Any Higher Number\n\n";
	 	else
	 	cout << " Congratulation! You Won The Game:)";
	 }
	 
	 while(N != number);
	 
	 return 0; 
}
