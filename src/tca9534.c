#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

// compile with -lpigpio


#define EXPANDER_REGISTER_INPUT 0x00
#define EXPANDER_REGISTER_OUTPUT 0x01
#define EXPANDER_REGISTER_POLARITY_INVERSION 0x02
#define EXPANDER_REGISTER_CONFIGURATION 0x03

int main(int argc, char *argv[])
{
   int i;
   int r;
   int handle;
   char aout;
   unsigned char command[2];
   unsigned char value[4];
   unsigned char str[8];

   int j;
   int key;

   if (gpioInitialise() < 0) return 1;


   handle = i2cOpen(1, 0x38, 0);

	while ( 1 )
	{
		// BFI
		command[0] = 0x01; // write register
		command[1] = 0x00; 

		i2cWriteDevice(handle, &command, 2);

		usleep ( 100000 );

		command[0] = 0x01; // write register
		command[1] = 0x01;

		i2cWriteDevice(handle, &command, 2);

		usleep ( 100000 );
	}
}
