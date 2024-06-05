#include "minitalk.h"
#include <stdio.h>

int ft_atoi(const char *str) {
  int sign;
  size_t result;
  size_t i;

  result = 0;
  sign = 1;
  i = 0;
  while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
    i++;
  if (str[i] == '-')
    sign = -1;
  if (str[i] == '-' || str[i] == '+')
    i++;
  while (str[i] >= '0' && str[i] <= '9') {
    result = (result * 10) + (str[i] - '0');
    i++;
  }
  return (result * sign);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("esto no esta bien");
    return 0;
  }
  printf("argc: %d\n", argc);
  printf("pid: %d\n", ft_atoi(argv[1]));

  kill(ft_atoi(argv[1]), );
  return 0;
}
