#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char** argv)
{
	int r;
	if (argc > 1)
	{
		r = atol(argv[1]);
	} else {
		// Fast Seed
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);

		// use nano-seconds instead of seconds
		srand((time_t)ts.tv_nsec);
		
		//srand(time(NULL)); // This seeds it too slow, output is the same if ran again within 1 second
		r = (rand()%7)+0;
	}
	switch(r)
	{
		case 0:
			std::cout << "\033[41mStop Poking Me!!\033[0m" << std::endl;
			break;
		case 1:
			std::cout << "\033[93mRedirecting Poke to Anthony...\n    ...   Anthony has been successfully poked.\033[0m" << std::endl;
			break;
		case 2:
			std::cout << "\033[91mError: Poke Failed. Redirecting Poke back at you...\033[0m" << std::endl;
			break;
		case 3:
			std::cout << "\033[45mDon't poke me there! That's my butt!\033[0m" << std::endl;
			break;
		case 4:
			std::cout << "\033[91mError: You accidentally stuck your finger into a sawblade instead of poking it and it wasn't pretty...\033[0m" << std::endl;
			break;
		case 5:
			std::cout << "\033[42mYou have successfully picked your nose!\033[0m" << std::endl;
			break;
		case 6:
			std::cout << "\033[42mYou have successfully and accidentally poked yourself in the eye!\033[0m" << std::endl;
			break;
		default:
			std::cout << "\033[91mError: Invalid Input!\033[0m" << std::endl;
			break;
	}
	return 0;
}
