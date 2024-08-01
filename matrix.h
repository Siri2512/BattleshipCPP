#include <iostream>
#include <fstream>

const int MAX_SIZE = 10; // Maximum size for the matrix

void deleteMatrix(char** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

char** readMatrixFromFile(const std::string& filename, int size) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return nullptr;
    }

    char** matrix = new char*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            if (!(inputFile >> matrix[i][j])) {
                std::cerr << "Error reading data from file at position (" << i + 1 << ", " << j + 1 << ")\n";
                inputFile.close();
                deleteMatrix(matrix, size);
                return nullptr;
            }
        }
    }

    inputFile.close();
    return matrix;
}

void printMatrix(const char* const* matrix, int size) {
    std::cout<<"  ";
    for(int i = 0;i<size;i++)std::cout<<"\033[0;33m"<<i<<"\033[0m"<<" ";
    std::cout<<std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout<<"\033[0;33m"<<i<<"\033[0m"<<" ";
        for (int j = 0; j < size; ++j) {
            if(matrix[i][j] == '#')std::cout << matrix[i][j] << " ";
            else if(matrix[i][j] == 'X')std::cout <<"\033[0;31m"<<matrix[i][j]<<"\033[0m"<< " ";
            else if(matrix[i][j] != '#' || matrix[i][j] != 'X')std::cout <<"\033[0;32m"<<matrix[i][j]<<"\033[0m"<< " ";
        }
        std::cout << "\n";
    }
}

void updateMatrix(char** matrix, int size, char symbol, int row, int col) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = symbol;
    } else {
        std::cerr << "Invalid position\n";
    }
}

void writeMatrixToFile(const std::string& filename, char** matrix, int size) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << "\n";
    }

    outputFile.close();
}

// int main() {
//     const int size = 10;

//     char** player1 = readMatrixFromFile("grid.txt", size);
// 	char** player2 = readMatrixFromFile("grid.txt", size);
// 	while(1)
// 	{
// 		if (player1 != nullptr) {
// 			std::cout << "Matrix read from file 'grid.txt':\n";
// 			printMatrix(player1, size);

// 			// Take input from Player 1 and update the matrix
// 			char symbol;
// 			int row, col;
// 			std::cout << "Player 1, enter a symbol (alphabet) and position (row and column): ";
// 			std::cin >> symbol >> row >> col;

// 			updateMatrix(player1, size, symbol, row, col);

// 			// Print the updated matrix
// 			std::cout << "Updated Matrix:\n";
// 			printMatrix(player1, size);

// 			// Write the updated matrix back to the file
// 			// writeMatrixToFile("grid.txt", player1, size);

			
// 		}
// 		if (player2 != nullptr) {
// 			std::cout << "Matrix read from file 'grid.txt':\n";
// 			printMatrix(player2, size);

// 			// Take input from Player 2 and update the matrix
// 			char symbol;
// 			int row, col;
// 			std::cout << "Player 2, enter a symbol (alphabet) and position (row and column): ";
// 			std::cin >> symbol >> row >> col;

// 			updateMatrix(player2, size, symbol, row, col);

// 			// Print the updated matrix
// 			std::cout << "Updated Matrix:\n";
// 			printMatrix(player2, size);

// 			// Write the updated matrix back to the file
// 			//writeMatrixToFile("grid.txt", player2, size);
// 		}
// 	}
// 		// Deallocate memory
//         deleteMatrix(player1, size);
//         // Deallocate memory
//         deleteMatrix(player2, size);
    

//     return 0;
// }