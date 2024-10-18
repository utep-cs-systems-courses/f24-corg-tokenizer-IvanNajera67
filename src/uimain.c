#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_INPUT_LENGTH 5000
int is_digit(char c) {
    return c >= '0' && c <= '9';
}
int main() {
    char input[MAX_INPUT_LENGTH];
    List *history = init_history();

while (1) {
    printf("--> ");
    if (!fgets(input, sizeof(input), stdin)) break;
    if (input[0]=='e' && input[1]=='x' && input[2]== 'i' && input[3]== 't')
      break;
    if(input[0]=='h' && input[1]=='i' && input[2]== 's' && input[3]== 't' && input[4]=='o' && input[5]=='r' && input[6]== 'y'){
      print_history(history);
      continue;}
    if (input[0] == '!' && is_digit(input[1])) {
      int id = atoi(&input[1]);
      char *histNode = get_history(history, id);
      printf("%s\n", histNode ? histNode : "Error: empty slot");}
    else{
      add_history(history, input);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }

  free_history(history);
  return 0;

}
    
