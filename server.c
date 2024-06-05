#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handler(int signum) {
  write(STDOUT_FILENO, "Señal recibida\n", 16);
}

int main(void) {
  pid_t pid = getpid();
  printf("Id del servidor: %d\n", pid);

  struct sigaction sa; 
  sa.sa_handler = handler;
  // sigemptyset(&sa.sa_mask);

  sigaction(SIGINT, &sa, NULL);

  pause();

  return 0;
}
