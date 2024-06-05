#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(char character)
{
	return (write(1, &character, 1));
}

int	print_int_base(int number, int base, char *base_str)
{
	int	characters_printed;

	characters_printed = 0;
	if (number < 0)
	{
		characters_printed += print_char('-');
		if (-(number / base) > 0)
			characters_printed += print_int_base(-(number / base), base,
					base_str);
		number = -(number % base);
	}
	if (number >= base)
	{
		characters_printed += print_int_base(number / base, base, base_str);
		characters_printed += print_char(base_str[number % base]);
	}
	else
		characters_printed += print_char(base_str[number]);
	return (characters_printed);
}

static void handler(int signum) {
  // print_int_base(signum, 10, "0123456789");
  if (signum == 10)
    write(STDOUT_FILENO, "0", 1);
  if (signum == 12)
    write(STDOUT_FILENO, "1", 1);
}

// static void sigusr1handler(int signum)

int main(void) {
  pid_t pid = getpid();
  printf("Id del servidor: %d\n", pid);

  struct sigaction sa;
  sa.sa_handler = handler;
  // sigemptyset(&sa.sa_mask);

  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  while (1) {
    pause();
  }

  return 0;
}
