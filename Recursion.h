#include <vector>
#include <string.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class  IFactorialComputer
{
public:
	IFactorialComputer() {};
	virtual int CalculateFactorial(int numberToComputer) = 0;
};

class  FactorialByRecursion : public IFactorialComputer
{
public:
	FactorialByRecursion() {};
	int CalculateFactorial(int num);
};

class  FactorialByStack : public IFactorialComputer
{
public:
	FactorialByStack() {};
	
	int CalculateFactorial(int num);

private:
	std::stack <int> s;
};

class  MyFakeClass
{
public:
	MyFakeClass() {std::cout << "Constructor for MyFakeClass was called" << std::endl;}
	~MyFakeClass() { std::cout << "Destructor for MyFakeClass was called" << std::endl; }
};

class  MyBaseException : public std::exception{
public:
virtual char const* what() const throw();
};

class  MyException1 : MyBaseException{
public:
	virtual char const* what() const throw();
};


class  MyException2 : MyBaseException{
public:
	virtual char const* what() const throw();
};

class  MyException3 : MyBaseException{
public:
	virtual char const* what() const throw();
};


extern  std::string CallSimpleExceptionMethod(int i);
extern  void SimpleExceptionMethod(int i);

//New QueenSolver Class

class QueenPosition{
public:
	QueenPosition(int r, int c);
	void setCoords(int row, int col);
	int getRow();
	int getCol();
private:
	int row;
	int col;
};

// This class is exported from the RecursionList.dll
class  ChessBoard {
public:
	ChessBoard(){
		for (int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				m_board[i][j]=0;
			}	
		}
		m_stack = new::stack<QueenPosition*>;
		m_filled = 0;
	}

	ChessBoard(int board [8][8]){
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				m_board[i][j] = board[8][8];
			}
		}
		m_stack = new::stack<QueenPosition*>;
		m_filled = 0;
	}

	std::string ToString();
	
	bool Solve(ChessBoard chessboard, int col);
	auto getBoard(); // TODO
	std::stack<QueenPosition*> *getStack();	
	int getFilled();
	void setFilled(int filled);

private:
    bool CheckSafeQueens(ChessBoard chessBoard, int i, int col);
	int m_board[8][8]; //zero is free, while 1 is a placed queen
	
	// TODO: add your methods here.

	bool checkQueenPosition(QueenPosition *pos);
	std::stack<QueenPosition*> *m_stack;
	int m_filled;
};

