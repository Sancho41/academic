#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *sep, char *string)
{
  char **string_vector;
  char *token;
  char *aux;
  int index = 0;
  char *s;
  char *sp;

  s = malloc(sizeof(char) * strlen(string));
  sp = malloc(sizeof(char) * strlen(sep));

  strcpy(s, string);
  strcpy(sp, sep);

  if (sep == string)
  {
    sp = " ";
  }

  token = strtok(s, sp);

  string_vector = (char **)malloc(sizeof(char *));

  while (token != NULL)
  {
    aux = (char *)malloc(sizeof(char) * strlen(token));

    string_vector = (char **)realloc(string_vector, sizeof(char *) * (index + 1));

    strcpy(aux, token);

    string_vector[index] = aux;

    token = strtok(NULL, sp);
    index++;
  }

  string_vector = (char **)realloc(string_vector, sizeof(char *) * (index));

  string_vector[index] = malloc(sizeof(char));
  string_vector[index] = "\0";

  return string_vector;
}

typedef struct String
{
  char *text;
  int size;
  char **(*split)();
} String;

String str(char *text)
{
  String string;
  string.text = text;
  string.size = strlen(text);
  string.split = split;
  return string;
}

void print(char **v)
{
  int i = 0;
  printf("['%s'", v[i]);
  while (strcmp(v[++i], "\0"))
    printf(", '%s'", v[i]);
  printf("]\n");
}

String input()
{
  char *string;
  String new;
  scanf("%m[^\n]s", &string);
  new = str(string);
  return new;
}

int main()
{
  print(input().split());
  print(input().split());
  return 0;
}
