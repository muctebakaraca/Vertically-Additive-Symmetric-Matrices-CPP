#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

// Function prototypes.
void displayMatrixToScreen(int values[][20], int rowNum, int columnNum);
void displaySumtoScreen(int columns[], int columnNum);
void displayFileToScreen(ifstream &inputFile, string line);
void resetColumnsTracker(int columns[], int columnNum);

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    int rowNum, columnNum;
    string row, line;
    int values[20][20] = {};
    int columns[20] = {};

    inputFile.open("matrixes.txt");

    if (inputFile)
    {

        displayFileToScreen(inputFile, line);

        inputFile.open("matrixes.txt");

        while (inputFile >> rowNum >> columnNum)
        {

            int sortable[rowNum][columnNum], checks = columnNum/2;
            bool sym = false;
            int corrColl = columnNum - 1;
  
            cout << "Input:" << endl;

            for (int i = 0; i < rowNum; i++)
            {
                for (int k = 0; k < columnNum; k++)
                {
                    inputFile >> values[i][k];
                    columns[k] += values[i][k];
                    sortable[i][k] = values[i][k];
                }
            }


            // Displays the matrix onto the screen.
            displayMatrixToScreen(values, rowNum, columnNum);
            // Displays the added values of the columns
            displaySumtoScreen(columns, columnNum);


            for (int i = 0; i < checks; i++)
            {
                if (columns[i] == columns[corrColl-i])
                {
                    sym = true;
                }
                else
                {
                    sym = false;
                    break;
                }
            }

            if (sym == false)
            {
                cout << "Vertical additive symmetry: No";
            }
            else if (sym == true)
            {
                cout << "Vertical additive symmetry: Yes";
            }
            cout << endl;


            cout << "Sorted: " << endl;


            for (int i = 0; i < rowNum; i++) 
            {
                sort(sortable[i], sortable[i] + columnNum);
            }
            
            for (int i = 0; i < rowNum; i++)
            {
                cout << "      ";
                for (int k = 0; k < columnNum; k++)
                {
                    cout << setw(4) << right << sortable[i][k] << "  ";
                }
                cout << endl;
            }

            resetColumnsTracker(columns, columnNum);
            
            cout << "Press the enter key once or twice to continue..." << endl; cin.ignore(); cin.get();
        }
    }
    inputFile.close();
    cout << "Program Done";
    return 0;
}

void displayMatrixToScreen(int values[20][20],  int rowNum, int columnNum)
{
    // Displays the matrix to the screen
    for (int i = 0; i < rowNum; i++)
    {
        cout << "      ";
        for (int k = 0; k < columnNum; k++)
        {
            cout << setw(4) << right << values[i][k] << "  ";
        }
        cout << endl;
    }
}

void displaySumtoScreen(int columns[], int columnNum)
{
    cout << "Sums :" << endl;
    cout << "      ";
    for (int i = 0; i < columnNum; i++)
    {
        cout << setw(4) << right << columns[i] << "  ";
    }
    cout << endl;
}

void displayFileToScreen(ifstream &inputFile, string line)
{
    cout << "Given the following in the input file:" << endl;
    while (getline(inputFile, line))
    {
        cout << line << endl;
    }
    cout << endl;
    cout << "Output:" << endl;
    inputFile.close();
}

void resetColumnsTracker(int columns[], int columnNum)
{
    // Resets the columns tracker for the next matrix
    for (int i = 0; i < columnNum; i++)
    {
        columns[i] = 0;
    }
}
