#include <stdio.h>

void input();
void math();
void reset();
void help();
void commandList();

float columns[100][100];

enum commands
{
    INPUT,
    MATH,
    RESET,
    HELP
};

int main(void)
{
    int command;

    printf("What do you want to do?\n");
    commandList();
    scanf("%d", &command);

    switch ((enum commands)command) // Calls the given command.
    {
    case INPUT:
        input();
        break;
    case MATH:
        math();
        break;
    case RESET:
        reset();
        break;
    case HELP:
        help();
        break;
    default:
        printf("Invalid input. Try again.\n");
        main();
        command = 5;
        break;
    }

    return 0;
}
void commandList()
{
    printf("Commands:\n");
    printf("0: INPUT\n");
    printf("1: MATH\n");
    printf("2: RESET\n");
    printf("3: HELP\n");
}

void input()
{
    printf("input has run\n"); // Placeholder.
}

void math()
{
    printf("math has run\n"); // Placeholder.
}

void reset()
{
    printf("reset has run\n"); // Placeholder.
}

void help()
{
    printf("help has run\n"); // Placeholder.
}
