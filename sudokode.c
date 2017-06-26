// Nicholas Espinosa
// COP 3502 - 0001
// Sudokode (Szumlanski Version)

#include <stdio.h>
#define SIZE 9

// Filling the array that will be used
void fillArray(int array[][SIZE], int box[][SIZE])
{
	// Initializing necessary variables
	int i, j, k, l;

	// Creating an array of the puzzle itself
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}

	// Creating an array for each 3x3 grid
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			// Determining Row
			if(i < 3)
			{
				if(j > 5)
					k = 2;
				else if(j > 2)
					k = 1;
				else
					k = 0;
			}
			else if(i < 6)
			{
				if(j > 5)
					k = 5;
				else if(j > 2)
					k = 4;
				else
					k = 3;
			}
			else 
			{
				if(j > 5)
					k = 8;
				else if(j > 2)
					k = 7;
				else
					k = 6;
			}

			//Determining Column
			if((i % 3) == 0)
				l = (j % 3);
			else if((i % 3) == 1)
				l = (j % 3) + 3;
			else
				l =  (j % 3) + 6;

			// Assigning value
			box[k][l] = array[i][j];
		}
	}
}

// Comparing numbers to determine if solution is correct
int compare(int array[][SIZE], int box[][SIZE])
{
	// Initializing necessary variables
	int i, j, k, l, comp;

	// Comparing Columns
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			comp = array[i][j];
			
			for(k = j + 1; k < SIZE; k++)
			{
				if(comp == array[i][k])
					return 1;
			}
		}
	}

	// Comparing Rows
	for(j = 0; j < SIZE; j++)
	{
		for(i = 0; i < SIZE; i++)
		{
			comp = array[i][j];
			
			for(k = i + 1; k < SIZE; k++)
			{
				if(comp == array[k][j])
					return 1;
			}
		}
	}

	// Comparing each 3x3 grid within the puzzle solution
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			comp = box[i][j];
			
			for(k = j + 1; k < SIZE; k++)
			{
				if(comp == box[i][k])
					return 1;
			}
		}
	}

	return 0;
}

// Main Fuction
int main(void)
{
	// Initializing necessary variables
	int i, numPuzzles, board[SIZE][SIZE], boxes[SIZE][SIZE], flag = 0;
	
	// Determining number of puzzles
	scanf("%d", &numPuzzles);
	
	for(i = 0; i < numPuzzles; i++)
	{
		// Filling the array for each puzzle and 3x3 within each puzzle
		fillArray(board, boxes);
		
		// Comparing the numbers to determine if the solution is correct
		flag = compare(board, boxes);

		// If the solution is flagged, then it is not a correct solution
		if(flag == 1)
			printf("NO");
		else
			printf("YES");
		
		printf("\n");
	}

	return 0;
}



