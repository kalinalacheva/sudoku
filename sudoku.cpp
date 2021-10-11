#include<iostream>
using namespace std;
bool checkRow(char matrix[][9], int row, int number)
{
	bool check = true;
	for (int i = 0;i < 9;i++)
		if (int(matrix[row][i] - '0') == number)
			check = false;

	return check;
}
bool checkColumn(char matrix[][9], int column, int number)
{
	bool check = true;
	for (int i = 0;i < 9;i++)
		if (int(matrix[i][column] - '0') == number)
			check = false;

	return check;
}
bool checkSquare(char matrix[][9], int row, int column, int number)
{
	bool check = true;
	int col, r;
	if (column % 3 == 0) col = column;
	if (column % 3 == 1) col = column - 1;
	if (column % 3 == 2) col = column - 2;

	if (row % 3 == 0) r = row;
	if (row % 3 == 1) r = row - 1;
	if (row % 3 == 2) r = row - 2;

	for (int i = r;i <= r + 2;i++)
		for (int j = col;j <= col + 2;j++)
			if (int(matrix[i][j] - '0') == number)
				check = false;

	return check;

}
void printMatrix(char matrix[][9])
{
	cout << "    0 1 2   3 4 5   6 7 8" << endl << "  -------------------------" << endl;

	for (int i = 0;i < 9;i++)
	{
		cout << i << " ";
		for (int j = 0;j < 9;j++)
		{
			if (j % 3 == 0) cout << "| ";
			cout << matrix[i][j] << " ";
		}
		cout << "|" << endl;
		if (i % 3 == 2) cout << "  -------------------------" << endl;
	}
}
bool isFull(char matrix[][9])
{
	bool full = 1;
	for (int i = 0;i < 9;i++)
		for (int j = 0;j < 9;j++)
			if (matrix[i][j]<'1' || matrix[i][j]>'9') full = 0;

	return full;

}
char level1[9][9] = {
		   {'1','5','_','_','4','2','_','_','6'},
		   {'2','7','4','5','6','_','_','1','_'},
		   {'_','_','6','_','_','7','4','_','2'},
		   {'_','1','_','_','_','_','_','4','_'},
		   {'_','_','_','_','5','_','_','_','_'},
		   {'_','6','_','4','_','3','1','9','_'},
		   {'_','2','_','6','_','5','9','_','_'},
		   {'9','8','5','_','3','_','_','6','_'},
		   {'_','4','_','2','1','9','8','3','_'}
};
char    level2[9][9] = {
		   {'_','_','6','4','_','_','3','_','8'},
		   {'1','_','_','_','6','3','_','_','_'},
		   {'3','4','_','9','2','8','_','_','1'},
		   {'_','_','_','3','_','_','_','_','5'},
		   {'_','_','5','2','_','4','_','9','_'},
		   {'4','_','_','_','_','7','_','_','_'},
		   {'8','7','_','5','4','_','_','1','_'},
		   {'_','9','_','_','_','1','_','_','_'},
		   {'_','_','_','_','_','_','_','8','4'}
};
char	level3[9][9] = {
		   {'_','_','6','_','8','1','_','_','5'},
		   {'_','_','1','_','_','_','_','3','_'},
		   {'_','_','8','_','_','2','_','4','_'},
		   {'4','_','_','_','_','8','_','5','_'},
		   {'_','_','_','_','_','_','_','_','_'},
		   {'_','_','2','_','_','7','6','_','_'},
		   {'9','_','_','_','_','5','_','7','_'},
		   {'2','_','_','7','_','_','_','_','3'},
		   {'_','_','_','1','3','_','_','_','_'}
};
void chosenLevel(char matrix1[][9], char matrix2[][9])
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
			matrix1[i][j] = matrix2[i][j];
	}
}
bool isFilled[9][9], startNumbers[9][9];
int main()
{
	char sudokuBoard[9][9];
	int level, row, column, number;
	cout << "LEVEL:"; cin >> level;
	if (level == 1) chosenLevel(sudokuBoard, level1);
	if (level == 2) chosenLevel(sudokuBoard, level2);
	if (level == 3) chosenLevel(sudokuBoard, level3);
	cout << "HERE IS YOUR SUDOKU:" << endl;;
	printMatrix(sudokuBoard);

	for (int i = 0;i < 9;i++)
		for (int j = 0;j < 9;j++)
			if (sudokuBoard[i][j] >= '0' && sudokuBoard[i][j] <= '9') { isFilled[i][j] = 1; startNumbers[i][j] = 1; }

	while (isFull(sudokuBoard) == 0)
	{
		bool invalid = 0;
		cout << "ROW: ";    cin >> row;
		cout << "COLUMN: "; cin >> column;
		cout << "NUMBER: "; cin >> number;
		if (number == 0)
		{
			if (startNumbers[row][column] == 0) { sudokuBoard[row][column] = '_'; isFilled[row][column] = 0; }
			else {
				cout << "INVALID MOVE" << endl; invalid = 1;
			}
		}
		else
		{
			if (isFilled[row][column] == 1) {
				cout << "INVALID MOVE" << endl; invalid = 1;
			}
			else
			{
				if (checkColumn(sudokuBoard, column, number) == 0 || checkRow(sudokuBoard, row, number) == 0 || checkSquare(sudokuBoard, row, column, number) == 0)
				{
					cout << "INVALID MOVE" << endl;
					invalid = 1;
				}
				else
				{
					sudokuBoard[row][column] = char(number + '0');
					isFilled[row][column] = 1;
				}
			}
		}
		if (invalid == 0) {
			system("CLS");
			printMatrix(sudokuBoard);
		}
	}
}
