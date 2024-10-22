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
