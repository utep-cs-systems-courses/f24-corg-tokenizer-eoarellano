#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

// Return true if c is a whitespace chracter
int space_char(char c)
{
  if (c == ' ' || c == '\t') {
    return 1;
  }
  return 0;
  }

//Return true if c is a NON-whitespace character
int non_space_char(char c){
  if (c != ' ' && c != '\t' && c != '\0'){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next
   space-seperated token in zero-terminated str. */
char *token_start(char *str){
  while(*str != '\0' && space_char(*str)) {
    str++;
    }
    return str;
  }

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token) {                             
  while (*token != '\0' && non_space_char(*token)) {
    token++;
  }
  return token;
}

// Returns the length of the null-terminated string 'str'
int string_length(const char *str) {
  int length = 0;
  while (*str != '\0') {
    str++;
    length++;
  }
  return length;
}

// Counts the number of tokens in the string argument
int count_tokens(char *token) {
  int count = 0;
  char *token_start = NULL;

  while(*token != '\0') {
    //finds the start of the next token
    token_start = token_terminator(token);

    // incriments count if not NULL
    if (token_start != NULL) {
      count++;

      // Move str to next character after the token
      token = token_start;
    }

    // Skip leading whitespace
    while (*token != '\0' && space_char(*token)) {
      token++;
    }
    
  }
  return count;
}

/* Returns a freshly allocated new zero-terminated string containing                          
   a specified number of characters from the input string 'inStr'.*/
char *copy_str(char *inStr, short len) {

  //allocate memory for the new string                                                        
  char *copy = (char *)malloc((len + 1) * sizeof(char));

  //if memory allocation fails return NULL                                                    
  if (copy == NULL) {
    return NULL;
  }
                                             
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i];
  }
                                                       
  copy[len] = '\0';

  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char *str)
{
  int num_tokens = count_tokens(str);
  char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
  if (tokens == NULL)
  {
    return NULL; // Memory allocation failed
  }

  int token_index = 0;
  char *start = token_start(str);
  while (*start != '\0')
  {
    char *end = token_terminator(start);
    int length = end - start; // Find the length of the current token
    // Copy token into freshly allocated string
    tokens[token_index] = copy_str(start, length);
    token_index++; // move to next token
    start = token_start(end);
  }
  tokens[token_index] = NULL;

  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++)
  {
    printf("%s\n", tokens[i]);
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);  // Free each token
    }
    free(tokens);  // Free the array of pointers
}