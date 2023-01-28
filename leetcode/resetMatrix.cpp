void makeRowsCols0(int **input, int rows, int cols) {
	// Write your code here	
	int col0 = 1;
	for (int i = 0; i < rows; i++) {
        if (input[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (input[i][j] == 0)
                input[i][0] = input[0][j] = 0;
    }
	for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (input[i][0] == 0 || input[0][j] == 0)
                input[i][j] = 0;
        if (col0 == 0) input[i][0] = 0;
    }

}


