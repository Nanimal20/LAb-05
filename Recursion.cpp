#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) 
{
	if (num <= 1){
		return 1;
	}
	else{
		return num * CalculateFactorial(num - 1);
	}
}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

	if (num <= 1){
		return 1;
	}
	while (num > 1){
		s.push(num);
		num--;
	}
	while (!s.empty()){
		answer = answer * s.top();
		s.pop();
	}
	return answer;
}

//Chess Game Functions

QueenPosition::QueenPosition(int r, int c){ row = r; col = c;}

int QueenPosition::getRow() { 
	return row; 
	}
int QueenPosition::getCol() { 
	return col; 
	}
std::stack<QueenPosition*> *ChessBoard::getStack() { 
	return m_stack; 
	}
int ChessBoard::getFilled() { 
	return m_filled; 
	}
void ChessBoard::setFilled(int filled) { 
	m_filled = filled; 
	}


//Game Solving Functions
bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	bool done = false;
	std::stack<QueenPosition*> *stack = chessBoard.getStack();
	int b_row = 0;
	int failed = false;
	while(!done){
		// for loop rows
		failed = true;
		for (int row=b_row; row<8; row++){
			// if safe 
			if (CheckSafeQueens(chessBoard, row, col))
			{
				QueenPosition *qp = new QueenPosition(row, col);
				stack->push(qp);
				// update cols
				col++;
				failed = false;
				break;
			}
		}

		// couldn't place queen
		if (stack->size() == 8){
			// won
			done = true;
		}
		else if (failed){
			b_row = stack->top()->getRow() + 1;
			stack->pop();
			col--;
		}
		else{
			// could place queen
			b_row = 0;
			continue;
		}
	}
	return true;
}

bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) {
int i, j; 
	int count = 0;
	std::stack<QueenPosition*> *stack = getStack();
	std::stack<QueenPosition*> cpy = *stack;
	int size = stack->size(); 
 
    // Check this row on left side 
	cpy = *stack;
	count = 0;
	while (count < size){
		for (i = 0; i <= col; i++) {
			if (cpy.empty())
				continue;

			else if ( (cpy.top()->getCol() == i) &&
				(cpy.top()->getRow() == row) ){
				return false;
			}
		}
		if (cpy.empty()){
			break;}
		count++;
		cpy.pop();
	}

    // Check upper diagonal on left side 
	cpy = *stack;
	count = 0;
	while (count < size){
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if (cpy.empty()){
				continue;}
			if ( (cpy.top()->getCol() == j) &&(cpy.top()->getRow() == i) ){
				return false;
			}
		}
		if (cpy.empty())
			break;
		count++;
		cpy.pop();
	}	

    // Check lower diagonal on left side 
	cpy = *stack;
	count = 0;
	while (count < size){
		for (i = row, j = col; j >= 0 && i < 8; i++, j--){
			if (cpy.empty())
				continue;

			if ( (cpy.top()->getCol() == j) &&
				(cpy.top()->getRow() == i) ){
				return false;
			}
		}
		if (cpy.empty())
			break;
		count++;
		cpy.pop();
	}	
	return true; 
}


string ChessBoard::ToString() {

	string answer = "";
	std::stack<QueenPosition*> *stack = getStack();
	int temp = 0;
	for (int i = 7; i >= 0; i--) {
		for (int j = 7; j >= 0; j--) {
			temp = ( (stack->top()->getCol() == i) &&
					(stack->top()->getRow() == j) ) ? 1 : 0;
			
			if (temp){
				stack->pop();
			}
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer += str;
		}
		answer += "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.

	std::string retVal = "";
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;
	resourceThatNeedsToBeCleanedup = new MyFakeClass();
	try{
		SimpleExceptionMethod(i);
	} 
	catch (MyException1 &e) {
		retVal = "I got Exception 1";
	} 
	catch (MyException2 &e) {
		retVal = "I got Exception 2";
	} 
	catch (MyException3 &e) {
		retVal = "I got Exception 3";
	}

	if (retVal.empty()){
		retVal = "I did not get an Exception";
	}
	delete resourceThatNeedsToBeCleanedup;
	return retVal;
}


// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1){
		throw MyException1();
	}
	else if (i == 2){
		throw MyException2();
	}
	else if (i == 3){
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else{
		retVal = 20;
	}
	return;
}

//Exceptions

char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
char const* MyException3::what() const throw(){
	return "MyException3";
}

