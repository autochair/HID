#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <hidapi/hidapi.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <hidapi/hidapi.h>


int main (int argc, char* argv[])
{

  hid_device *handle;
  unsigned char buf[50];
  int res;
  short axisval;
  int buttonval;

  if(argc != 2)
    {
      std::cout << "Invalid parameters passed in.  Please pass in the path to the HID device." << std::endl;
      return -1;
    }
  
  handle = hid_open_path(argv[1]);

  while(1)
    {
      res = hid_read_timeout(handle, buf, sizeof(buf),3000);
      if(res > 0)
	{
	  std::cout << "REPORT\n\tID: " << (int)buf[0] << "\n\tData: ";
	  if((int)buf[0] == 3)
	    {
	      buttonval = (buf[1] & 0x02) >> 1;
	      std::cout << buttonval << " ";
	      buttonval = (buf[1] & 0x01);
	      std::cout << buttonval << " ";
	    }
	  else
	    {
	      for(int i = 0; i < 3; i++)
		{
		  axisval = (((short)buf[2*i+2] << 8) | (unsigned char)buf[2*i+1]);
		  std::cout << std::dec << axisval <<  " ";
		}
	    }
	  std::cout << std::endl;

	}
      else
	{
	  std::cout << "Read Timeout...\n";
	}
    }

}


