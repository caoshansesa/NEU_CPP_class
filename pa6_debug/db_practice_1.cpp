
// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25


//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.


#include<iostream>
using namespace std; //bug 1: miss std namespace

bool func(int n); // Bug 2, return type is wrong. 
					//Bug 3, arguement type is wrong
int main() { // Bug 4. return type is wrong
        int input = 0; // Bug5: , input type. 
							//Bug6, init with 0;
		  cout<<"enter an integer please";
		  cin >> input;  //Bug 7. it does not take the input 
          bool returned_val = func(input);
													 //8. FUNCTION NAME is wrong
													 //9 THE INPUT IS WRONG 
													 //10, DOES NOT define the type of return value
        if (!returned_val){ 							//11. THE LOGIC IS FLIPED
                cout<<"It is not a palindrome" <<endl;  //12 Missing end ;  and missing the "" for string
        }
        else{
                cout<<"It is a palindrome"<<endl;
        }
		
		return 0;// 13, TYPO MISS ;
}

//the return value of your func should be true / false only
bool func(int n)				// 14 api siginture
                               // 15 return type
{
            int given_number  =n;// 13, WRONG TYPE of n
                               // 14, IT HAS TO BE ASSIGNED AS N
                               //  15, MISS ;
            int temp = 0; 
			int remainder=0; //16, remainder NOT DEFINED 
	if(n == 0){return true;} //Bug: 17, check 0

	if(n<0){cout<< "negative number!"<<endl; return false;}   //Bug18: check the retrun false
        while (n !=0) { //loop until n is not zero 
		remainder = n % 10; //take the mod instead of the division 
		n/=10; //divide and reassign
                temp = (temp * 10) + remainder; //reassign temp 
                        
            }

            return (given_number==temp);   	
}

