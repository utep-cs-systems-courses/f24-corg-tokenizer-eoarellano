#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
    int input = 1;
    char str[100];

    puts("Welcome to my tokenizer program!");

    while (input != 0)
    {
        puts("Please Select an option: Tokenizer: 1, History: 2, Quit: 0");
        scanf("%d", &input);
        getchar();
        switch (input)
        {
        case 1:
            puts("Tokenizer Selected");
            printf(">");
            fgets(str, sizeof(str), stdin);
            char **tokens = tokenize(str);
            print_tokens(tokens);
            break;
        case 2:
            printf("History selected\n");
            break;
        case 0:
            printf("Goodbye..\n");
            break;
        default:
            printf("Invalid option, please try again.\n");
            break;
        }
    }

    return 0;
}
