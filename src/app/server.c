#include "../minitalk.h"
#include <unistd.h>

t_bit_buffer g_bit_buffer = {0, 0};

static void signal_handler(int sig, siginfo_t *info, void *context) {
  (void)context;
  (void)info;

  if (sig == SIGUSR1) {
    g_bit_buffer.byte |= (0 << g_bit_buffer.bit);
  } else if (sig == SIGUSR2) {
    g_bit_buffer.byte |= (1 << g_bit_buffer.bit);
  }
  g_bit_buffer.bit++;

  if (g_bit_buffer.bit >= 8) {
    if (g_bit_buffer.byte != 0) {
      write(1, &g_bit_buffer.byte, 1);
    }
    g_bit_buffer.byte = 0;
    g_bit_buffer.bit = 0;
  }
}

void init_sigaction(void) {
  struct sigaction sa;
  sa.sa_sigaction = &signal_handler;
  sa.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &sa, 0) == -1) {
    ft_printf("Error\n");
  }
  if (sigaction(SIGUSR2, &sa, 0) == -1) {
    ft_printf("Error\n");
  }
}

int main(void) {
  pid_t pid = getpid();
  ft_printf("Id del servidor: %d\n", pid);
  while (1) {
    init_sigaction();
    sleep(1);
  }

  return 0;
}
