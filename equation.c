#include <stdio.h>
#include <stdlib.h>
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

void initialize(int ROW, int COL, struct CellProperties (*cell)[COL])
{
    for (int i = 0; i < ROW; i++) // Initializes all CellProperties.
    {
        for (int j = 0; j < COL; j++)
        {
            cell[i][j].defined = 0;
            cell[i][j].value = 0;
        }
    }
}

int main ()
{
    int ROW = 10, COL = 10; // Sets the grid size.
    int thisROW, thisCOL;

    struct CellProperties cell[ROW][COL];

    initialize(ROW, COL, cell); // Makes sure the every cell is "undefined"
    whichCell(&thisROW, &thisCOL, ROW, COL, cell); // Checks which cell that should be operated.

    return 0;
}

int whichCell(int thisROW, int thisCOL, int ROW, int COL, struct CellProperties (*cell)[COL])
{
    printf("Enter cell: ");
    scanf("%d %d", &thisROW, &thisCOL);
    if (cell[thisROW][thisCOL].defined == 1) {
        confirmOverwrite(thisROW, thisCOL, ROW, COL, cell);
        return 0;
    }
    interpreter(thisROW, thisCOL, ROW, COL, cell);
    return 0;   
}

void confirmOverwrite(int thisROW, int thisCOL, int ROW, int COL, struct CellProperties (*cell)[COL])
{
    char overWrite;
    printf("Cell is defined, overwrite?\nY/n: ");
    scanf("%c", &overWrite);
    if (overWrite == 'y' || overWrite == 'Y')
    {
        interpreter(thisROW, thisCOL, ROW, COL, cell);
    }
    printf("Cancelled.\n");
}
void interpreter(int thisROW, int thisCOL, int ROW, int COL, struct CellProperties (*cell)[COL])
{
    printf("Write equation: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Makes fgets work.

        if (fgets(cell[thisROW][thisCOL].equation, sizeof(cell[thisROW][thisCOL].equation), stdin) != NULL)
        {
            if (cell[thisROW][thisCOL].equation[0] == '=') //Determines if the equation should be a name or calculated into a value.
                {
                    lexer(thisROW, thisCOL, ROW, COL, cell);
                }
                else
                {
                    printf("Cell[%d][%d]: %s\n", thisROW, thisCOL, cell[thisROW][thisCOL].equation);
                }
                cell[thisROW][thisCOL].defined = 1; // Make sure the cell looks occupied.
        }
        else
        {
            printf("Wrong syntax, try again.\n");
            interpreter(thisROW, thisCOL, ROW, COL, cell);
        }
}

void lexer(int thisROW, int thisCOL, int ROW, int COL, struct CellProperties (*cell)[COL])
{
    int tokens[100] = {0};
    int token = 0;
    int decimalCounter = 0;

    for (int i = 1; i < sizeof(cell[thisROW][thisCOL].equation) - 1; i++) // i = 1 to ignore the '='.
    {
        if (cell[thisROW][thisCOL].equation[i] == ' ')
        {
            decimalCounter = 0;
            //printf("space was detected\n");
        }
        else if (cell[thisROW][thisCOL].equation[i] >= '0' && cell[thisROW][thisCOL].equation[i] <= '9')
        {
            tokens[token] = tokens[token] + (cell[thisROW][thisCOL].equation[i] - 48) * pow(10, decimalCounter); // 48 to transform into decimal.
            decimalCounter++;
        }
        else if (cell[thisROW][thisCOL].equation[i] == '+')
        {
            token++;
            tokens[token] = 43;
            token++;
            decimalCounter = 0;
        }
        else
        {
            decimalCounter = 0;
            continue;
        }
    }
    printf("Tokens:\n");
    for (int i = 0; i < sizeof(tokens); i++)
    {
        printf("%d, ", tokens[i]);
    }

}
