#include "tokenizer.h"
#include <stdio.h>

// Return true if c is a whitespace chracter
int space_char(char c)
{
  return c == ' ' || c == '\t'; 
}

//Return true if c is a NON-whitespace character
int non_space_char(char c){
  return c != ' ' && c != '\t' && c != '\0';
}


