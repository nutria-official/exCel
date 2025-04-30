#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input();
void math();
void reset();
void help();
void commandList();
void action();
void read();
void back();
void mathOperationList();

int main()
{
    int gridSize;
    printf("Enter the grid size: ");
    scanf("%d", &gridSize);

    float **cell = malloc(gridSize * sizeof(float *)); // Makes dynamic memory - I've gotta understand this better.
    for (int i = 0; i < gridSize; i++)
    {
        cell[i] = malloc(gridSize * sizeof(float));
    }

    action(cell, gridSize);
    return 0;
}

void action(float **cell, int gridSize)
{
    enum commands
    {
        INPUT,
        MATH,
        READ,
        RESET,
        HELP,
        EXIT
    };
    int command;

    printf("What do you want to do?\n");
    commandList();
    scanf("%d", &command);

    switch ((enum commands)command) // Calls the given command.
    {
    case INPUT:
        input(cell, gridSize);
        break;
    case MATH:
        math(cell, gridSize);
        break;
    case READ:
        read(cell, gridSize);
        break;
    case RESET:
        reset(cell, gridSize);
        break;
    case HELP:
        help();
        break;
    case EXIT:
        printf("exiting...\n");
        exit(0);

    default:
        printf("Invalid input. Try again.\n");
        action(cell, gridSize);
    }
}
void commandList()
{
    printf("Commands:\n");
    printf("0: INPUT\n");
    printf("1: MATH\n");
    printf("2: READ\n");
    printf("3: RESET\n");
    printf("4: HELP\n");
    printf("5: EXIT\n");
}

void input(float **cell, int gridSize)
{
    int row, col;
    float value;
    printf("row:\n");
    scanf("%d", &row);
    printf("col:\n");
    scanf("%d", &col);
    printf("value:\n");
    scanf("%f", &value);

    cell[row][col] = value;

    printf("cell[%d][%d] set to %f\n", row, col, value);
    action(cell, gridSize);
}

void math()
{
    enum mathOperations
    {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        SUM,
        BACK
    };

    int row, col, operation;
    float newValue;

    printf("row:\n");
    scanf("%d", &row);
    printf("col:\n");
    scanf("%d", &col);
    mathOperationList(&operation);
    switch ((enum mathOperations)operation)
    {
    case ADD:
        break;
    case SUBTRACT:
        break;
    case MULTIPLY:
        break;
    case DIVIDE:
        break;
    case SUM:
        break;
    case BACK:
        break;
    default:
        printf("Invalid input. Try again.\n");
        mathOperationList(&operation);
    }
}

void mathOperationList(int *operation)
{
    printf("operation list:\n");
    printf("0: ADD\n");
    printf("1: SUBTRACT\n");
    printf("2: MULTIPLY\n");
    printf("3: DIVIDE\n");
    printf("4: SUM\n");
    printf("5: BACK\n");
    scanf("%p", &operation);
}

void read(float **cell, int gridSize)
{
    int row, col;

    printf("row:\n");
    scanf("%d", &row);
    printf("col:\n");
    scanf("%d", &col);
    printf("cell[%d][%d] = %f\n", row, col, cell[row][col]);
    action(cell, gridSize);
}
void reset(float **cell, int gridSize)
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cell[i][j] = 0;
        }
    }
    printf("All cells have been reset\n");
    action(cell, gridSize);
}

void help()
{
    printf("help has run\n"); // Placeholder.
}
