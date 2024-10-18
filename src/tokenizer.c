#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
int space_char(char c){
  return (c==' ' || c== '\t');
}

int non_space_char(char c){
  return (c != ' ' && c!= '\0');
}
char *token_start(char *str){
  while (*str && space_char(*str)){
        str++;
  }
  if (*str == '\0') {
        return NULL;
  }
    return str;
}
char *token_terminator(char *token){
  while (*token && non_space_char(*token)) {
        token++;
    }
    while (*token && space_char(*token)) {
        token++;
    }
    return token;
}

int count_tokens(char *str){
  int count = 0;
    char *token = token_start(str);

    while (token){
        count++;
        token = token_start(token_terminator(token));
    }
    return count;
}
char *copy_str(char *inStr, short len){
  char *newStr = (char *)malloc(len + 1);
    if (!newStr) return NULL;
    for (short i = 0; i< len; i++){
      newStr[i] = inStr[i];
    }
    newStr[len] = '\0';
    return newStr;
}
char **tokenize(char* str){
  int tokenCount = count_tokens(str);
    char **tokens = (char **)malloc((tokenCount + 1) * sizeof(char *));
    if (!tokens) return NULL;

    char *token = token_start(str);
    int i = 0;

    while (token){
        char *end = token_terminator(token);
        short len = end - token;
        tokens[i] = copy_str(token, len);
        token = token_start(end);
        i++;
    }
    tokens[i] = NULL;
    return tokens;
}    
void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != NULL; i++) {
        printf("[%d]: %s\n", i, tokens[i]);
    }
}
void free_tokens(char **tokens){
 if (tokens) {
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}
