#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int row, column, rows, columns,
	rowg, columng, rowo, columno,
	obstacle;

int **board = 0;
int ** closedList = 0;

struct node
{
	int x, y;						// its own row and column
	int parentX, parentY;			// row and column of its parent
int g;							// its g value
int h;							// its h value
};


bool isObstacle(int ** board, int row, int col)
{
	bool isObstacle = false;
	if (board[row][col] == 3)
		isObstacle = true;
	return isObstacle;
}

bool isGoal(int row, int column)
{
	bool isGoal = false;
	if (row == rowg && column == columng)
		isGoal = true;
	return isGoal;
}

int calch(int row, int column)
{
	return abs((row - rowg) + (column - columng));
}

void path(int ** closedList, int row, int column)
{

	stack<int> path;

	while (closedList[row][column] / 100 != rows
		|| closedList[row][column] % 100 != columns)
	{
		path.push(closedList[row][column]);
		int tempR = closedList[row][column] / 100;
		int tempC = closedList[row][column] % 100;
		row = tempR;
		column = tempC;
	}

	path.push(closedList[row][column]);
	while (!path.empty())
	{
		int temp = path.top();
		path.pop();
		cout << temp / 100 << " " << temp % 100 << endl;
	}
	cout << rowg << " " << columng << endl
		<< "-1 -1" << endl;
}

void aStarSearch(int ** board)
{

	closedList = new int *[row];
	for (int i = 0; i < row; i++)
		closedList[i] = new int[column];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			closedList[i][j] = -1;
		}
	}

	node ** info = new node *[row];
	for (int i = 0; i < row; i++)
		info[i] = new node[column];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			info[i][j].g = -1;
			info[i][j].h = calch(i, j);
			info[i][j].parentX = -1;
			info[i][j].parentY = -1;
			info[i][j].x = i;
			info[i][j].y = j;
		}
	}

	info[rows][columns].g = 0;

	vector <node> openList;

	openList.push_back(info[rows][columns]);
	cout << rows << " " << columns << endl;

	while (!openList.empty())
	{
		node temp = openList.back();
		for (int i = 0; i < openList.size(); i++)
		{
			if (openList[i].g + openList[i].h > temp.g + temp.h)
			{
				for (int j = openList.size(); j > i + 1; j--)
				{
					openList[j - 1] = openList[j - 2];
				}
				openList[i] = temp;
				break;
			}
		}

		int i = openList[0].x;
		int j = openList[0].y;


		closedList[i][j] = 100 * info[i][j].parentX + info[i][j].parentY;


		if (isGoal(i, j))
		{

			cout << i << " " << j << endl
				<< "-1 -1" << endl;

			path(closedList, i, j);
			return;
		}

		openList.erase(openList.begin());

		int gNew;

		if (i > 0)
		{
			if (closedList[i - 1][j] == -1 && !isObstacle(board, i - 1, j))
			{
				gNew = info[i][j].g + 1;
				if (info[i - 1][j].g = -1 || info[i - 1][j].g > gNew)
				{
					info[i - 1][j].g = gNew;
					info[i - 1][j].parentX = i;
					info[i - 1][j].parentY = j;

					openList.push_back(info[i - 1][j]);

					cout << info[i - 1][j].x << " "
						<< info[i - 1][j].y << endl;
				}
			}
		}

		if (i + 1 < row)
		{
			if (closedList[i + 1][j] == -1 && !isObstacle(board, i + 1, j))
			{
				gNew = info[i][j].g + 1;
				if (info[i + 1][j].g = -1 || info[i + 1][j].g > gNew)
				{
					info[i + 1][j].g = gNew;
					info[i + 1][j].parentX = i;
					info[i + 1][j].parentY = j;
	
					openList.push_back(info[i + 1][j]);

					cout << info[i + 1][j].x << " "
						<< info[i + 1][j].y << endl;
				}
			}
		}

		if (j + 1 < column)
		{
			if (closedList[i][j + 1] == -1 && !isObstacle(board, i, j + 1))
			{
				gNew = info[i][j].g + 1;
				if (info[i][j + 1].g = -1 || info[i][j + 1].g > gNew)
				{
					info[i][j + 1].g = gNew;
					info[i][j + 1].parentX = i;
					info[i][j + 1].parentY = j;
	
					openList.push_back(info[i][j + 1]);

					cout << info[i][j + 1].x << " "
						<< info[i][j + 1].y << endl;
				}
			}
		}

		if (j > 0)
		{
			if (closedList[i][j - 1] == -1 && !isObstacle(board, i, j - 1))
			{
				gNew = info[i][j].g + 1;
				if (info[i][j - 1].g = -1 || info[i][j - 1].g > gNew)
				{
					info[i][j - 1].g = gNew;
					info[i][j - 1].parentX = i;
					info[i][j - 1].parentY = j;
	
					openList.push_back(info[i][j - 1]);

					cout << info[i][j - 1].x << " "
						<< info[i][j - 1].y << endl;
				}
			}
		}

	}
}

void input(int ** board)
{
	cin >> rows >> columns;
	board[rows][columns] = 1;

	cin >> rowg >> columng;
	board[rowg][columng] = 2;

	cin >> obstacle;
	if (obstacle != 0)
	{
		for (int i = 0; i < obstacle; i++)
		{
			cin >> rowo >> columno;
			board[rowo][columno] = 3;
		}
	}
}

void output(int ** board)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cerr << board[i][j] << " ";
		}
		cerr << endl;
	}
}

int main()
{
	cin >> row >> column;
	board = new int *[row];
	for (int i = 0; i < row; i++)
		board[i] = new int[column];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			board[i][j] = 0;
		}
	}

	input(board);

	aStarSearch(board);

	return 0;
}