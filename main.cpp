#include<iostream>
#include<stack>
#include"Stack.hpp"
#include<algorithm>
#include<sstream>
#include<cmath>
#include<string>

using namespace std;
void print_instruction()
{
	cout<<"                          welcome to Toan Tran PostFix calculator"<<endl;
  cout<<"here to instruction how to use this magic calculator"<<endl;
	cout<<"exchange function (key word 'x') for example input '1 2 x -' will calculate '2-1'"<<endl;		
  cout<<"  sum    function (key word 's') for example input '1 2 3 s' will calculate 1+2+3"<<endl;
	cout<<" average function (key word 'a') for example input '1 2 3 a' will calculate average of sum '1+2+3'"<<endl;
  cout<<"calculations: addition (+), subtraction (-), multiplication (*), division (/), remainder operation (%), power increase (^), square root (v)"<<endl;
}

bool check_input(string input)
{
	int count=0;
	bool success=true;
  string check="1234567890";
	string symbol="xsa+-*^/%v.";

	int space=count_if(input.begin(),input.end(),[](char i){return i ==' ';});
  for(long unsigned int a=0;a<input.length();a++)
	{
		for(long unsigned int b=0;b<symbol.length();b++)
		{
			if(input[a]==check[b]||input[a]==symbol[b])
			{
				count++;
				continue;
			}
			
		}
	}

	count=(count==(input.length()-space)) ? success=true : success=false;
	return success;
}

void check_minus(string input,string &check_subtract)
{
	for(long unsigned int a=0;a<input.length();a++)
	{
		if(input[a]=='-'&&input[a+1]!=' ')
		{
       check_subtract+='-';
		}
		else check_subtract+='n';
	}
  //cout<<endl<<check_subtract;
}


void calculate(string input,string check_subtract)
{
	int num=0;
	Stack store;
	//cout<<"this state calculattor run"<<endl;
	string check="1234567890";
	string symbol="xsw+-*^/%v";
	double result=0;
	double swap1=0;
	double swap2=0;
  string number;
	string decimal_number;
	double d;
	for(unsigned long int a=0;a<input.length();a++)
	{
	switch (input[a])
	{
	case '1':
		number+='1';
		break;
	case '2':
		number+='2';
		break;
	case '3':
		number+='3';
		break;
	case '4':
		number+='4';
		break;
	case '5':
		number+='5';
		break;
	case '6':
		number+='6';
		break;
	case '7':
		number+='7';
		break;
	case '8':
		number+='8';
		break;
	case '9':
		number+='9';
		break;
	case '0':
		number+='0';
		break;
	case '.':
	  number+='.';
	  break;
  case ' ':
	  // istringstream(number) >> d;
	  // if(number!=" ")store.push(d);
	  if(number!=" ")store.push(stof(number));
		number=' ';
		break;
	case 'x':
	  store.top(swap1);
		store.pop();
		store.top(swap2);
		store.pop();
		store.push(swap1);
		store.push(swap2);
	  break;
	case 's':
	  while (!store.empty())
			{
				store.top(swap1);
				result+=swap1;
				store.pop();
			}
			store.push(result);
			result=0;
	  break;
	case 'a':
	  num=0;
	  while (!store.empty())
			{
				store.top(swap1);
				result+=swap1;
				store.pop();
				num++;
			}
			result=result/num;
			store.push(result);
			result=0;
	  break;
	case '+':
	  store.top(swap1);
		result+=swap1;
		store.pop();
		store.top(swap1);
		result+=swap1;
		store.pop();
		store.push(result);
		result=0;
	  break;
	case '-':
	if(number==" "&&check_subtract[a]=='-')
	{
    number+='-';
	}
	else{
    //swap
	  store.top(swap1);
		store.pop();
		store.top(swap2);
		store.pop();
		store.push(swap1);
		store.push(swap2);
		//calculator
		store.top(swap1);
		result+=swap1;
		store.pop();
		store.top(swap1);
		result-=swap1;
		store.pop();
		store.push(result);
		result=0;
	}
	  break;
	case '*':
	  store.top(swap1);
		store.pop();
		store.top(swap2);
		result=swap2*swap1;
		store.pop();
		store.push(result);
		result=0;
		break;
	case '^':
	  store.top(swap1);
		result+=swap1;
		store.pop();
		store.top(swap1);
		result=pow(swap1,result);
		store.pop();
		store.push(result);
		result=0;
	  break;
	case '/':
	  store.top(swap1);
		result+=swap1;
		store.pop();
		store.top(swap1);
		result=swap1/result;
		store.pop();
		store.push(result);
		result=0;
	  break;
	case '%':
	  store.top(swap1);
		result+=swap1;
		store.pop();
		store.top(swap1);
		result=swap1-(int)(swap1/result)*result;
		store.pop();
		store.push(result);
		result=0;
	  break;
	case 'v':
	  store.top(swap1);
		result+=sqrt(swap1);
		store.pop();
		store.push(result);
		result=0;
	  break;
	}
 }
  store.top(result);
	cout<<result;
	store.pop();
}
//variable = (condition) ? expressionTrue : expressionFalse;
int main(){
   string check_subtract;
	 string input;
	 string c;
	 print_instruction();
   int b=1;
   for(int a=0;a<3;)
		{
			 cout<<"\n\n\nInput your equation in Postfix form : ";
       getline(cin,input);
	     input+=" ";
	     check_minus(input,check_subtract);

	     if(check_input(input)==1)	calculate(input,check_subtract);
	     else cout<<"!!!!invalid input only these symbols are valid (1 2 3 4 5 6 7 8 9 0 . and x s a + - * ^ / % v"<<endl;
	     a=0;
		   cout<<"\n\n>>>>>>continue calculate enter: (c) else enter other character: ";
		   getline(cin,c);
			 if(c!="c")
			 {
				 break;
			 }
			 c=' ';
		}	 
}