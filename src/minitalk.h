#ifndef MINITALK_H
#define MINITALK_H

typedef struct s_bit_buffer {
  int byte;
  int bit;
} t_bit_buffer;

typedef enum s_bool {
  FALSE,
  TRUE
} t_bool;

// write, getpid, kill, pause
#include <unistd.h>

// signal, sigaction, sigemptyset, sigaddset
#include <signal.h>

// ft_printf
#include "./lib/printf/src/ft_printf.h"

#endif
