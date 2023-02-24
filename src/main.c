#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "../includes/linkedlist.h"
#include "../includes/utils.h"

void sig_handler(int signum);

int run = 1;

int main()
{
	signal(SIGINT, sig_handler);
	node head = NULL;
	load_start_entries(&head);

	int opt; //current chosen option

	printf("---------Pradžia---------\n");
	
	do {
		print_usage();
		opt = get_input_number(NULL, 0, 7);
		
		switch (opt) {
		case 0:
			printf("--------Darbas baigtas--------\n");
			run = 0;
			break;

		case 1:
			add(&head);
			break;

		case 2:
			add_pos(&head);
			break;

		case 3:
			get_pos(head);
			break;

		case 4:
			get_field(head);
			break;

		case 5:
			print_all(head);
			break;

		case 6:

			delete_pos(&head);
			break;

		case 7:
			delete_all(&head);
			break;
		}
		fflush(stdout);
	} while (run);
	list_clear(&head);

	

	return 0;
}
void sig_handler(int signum)
{
	run = 0;
}
