#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void initialize();
int whichCell();
void interpreter();
void confirmOverwrite();
void lexer();
void parser();

struct CellProperties { // Defines each cell as a struct containing both the name/equation and the calculated value.
    char equation[100];
    double value;
    int defined;
};

struct Token {
    double value;
    int type;
};

void initialize(int row, int col, struct CellProperties (*cell)[col])
{
    for (int i = 0; i < row; i++) // Initializes all CellProperties.
    {
        for (int j = 0; j < col; j++)
        {
            cell[i][j].defined = 0;
            cell[i][j].value = 0;
        }
    }
}

int main ()
{
    int row = 10, col = 10; // Sets the grid size.
    int selectedRow, selectedCol;

    struct CellProperties cell[row][col];

    initialize(row, col, cell); // Makes sure the every cell is "undefined"
    whichCell(&selectedRow, &selectedCol, row, col, cell); // Checks which cell that should be operated.

    return 0;
}

int whichCell(int selectedRow, int selectedCol, int row, int col, struct CellProperties (*cell)[col])
{
    printf("Enter cell: ");
    scanf("%d %d", &selectedRow, &selectedCol);

    if (cell[selectedRow][selectedCol].defined == 1) {
        confirmOverwrite(selectedRow, selectedCol, row, col, cell);
        return 0;
    }
    interpreter(selectedRow, selectedCol, row, col, cell);
    return 0;   
}

void confirmOverwrite(int selectedRow, int selectedCol, int row, int col, struct CellProperties (*cell)[col])
{
    char overWrite;
    printf("Cell is defined, overwrite?\nY/n: ");
    scanf("%c", &overWrite);
    if (overWrite == 'y' || overWrite == 'Y')
    {
        interpreter(selectedRow, selectedCol, row, col, cell);
    }
    printf("Cancelled.\n");
}
void interpreter(int selectedRow, int selectedCol, int row, int col, struct CellProperties (*cell)[col])
{
    printf("Write equation: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Makes fgets work.

        if (fgets(cell[selectedRow][selectedCol].equation, sizeof(cell[selectedRow][selectedCol].equation), stdin) != NULL)
        {
            if (cell[selectedRow][selectedCol].equation[0] == '=') //Determines if the equation should be a name or calculated into a value.
                {
                    lexer(selectedRow, selectedCol, row, col, cell);
                }
                else
                {
                    printf("Cell[%d][%d]: %s\n", selectedRow, selectedCol, cell[selectedRow][selectedCol].equation);
                }
                cell[selectedRow][selectedCol].defined = 1; // Make sure the cell looks occupied.
        }
        else
        {
            printf("Wrong syntax, try again.\n");
            interpreter(selectedRow, selectedCol, row, col, cell);
        }
}

void lexer(int selectedRow, int selectedCol, int row, int col, struct CellProperties (*cell)[col])
{
    int tokenNumber = 0;
    int decimalCounter = 0;
    int equationLength = strlen(cell[selectedRow][selectedCol].equation);
    char equation[equationLength];
    strcpy(equation, cell[selectedRow][selectedCol].equation);
    struct Token tokens[100] = {0};
    enum type 
    {
        NUMBER,
        OPERATOR,
    };

    for (int i = strlen(equation) - 1; i > 0; i--) // -1 to ignore the '='.
    {
        if (equation[i] == ' ')
        {
            decimalCounter = 0;
        }
        else if (equation[i] >= '0' && equation[i] <= '9')
        {
            tokens[tokenNumber].value = tokens[tokenNumber].value + (equation[i] - 48) * pow(10, decimalCounter); // 48 to transform into decimal.
            tokens[tokenNumber].type = NUMBER;
            decimalCounter++;
        }
        else if (equation[i] == '+')
        {
            tokenNumber++;
            tokens[tokenNumber].value = equation[i];
            tokens[tokenNumber].type = OPERATOR;
            tokenNumber++;
            decimalCounter = 0;
        }
        else
        {
            decimalCounter = 0;
        }
    }

    printf("Tokens:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%lf, ", tokens[i].value);
    }

}
