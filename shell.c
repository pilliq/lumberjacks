#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  char line[50*10];
  char **tokens;
  int i;

  while ((tokens = calloc(11, sizeof(char*))) != NULL);

  for (i = 0; i < sizeof(tokens); i++)
  {
    printf("%d\n", i);
  }

  while (1)
  {
    fgets(line, sizeof(line), stdin);
    printf("%s", line);
    if (strcmp(line, "exit") == 0)
    {
      printf("Hi\n");
      break;
    }
  }
}

/**
 * Takes a list of token and returns a list of commands.
 * @return array of strings
 */
char***
get_command_list(char* tokens[])
{
  int i;
  for (i = 0; i < sizeof(tokens); i++)
  {
    printf("i");
  }
  return 0;
}
