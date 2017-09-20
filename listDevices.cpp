#include <sys/types.h>
#include <sys/stat.h>
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
  struct hid_device_info *devs, *cur_dev;

  devs = hid_enumerate(0x0,0x0);
  cur_dev = devs;

  while(cur_dev) {
    std::cout << "HID Device:" << std::endl;
    std::cout << "\tPath: ";
    std::cout << cur_dev->path << std::endl;
    std::cout << "\tVendor ID: "; 
    std::cout << cur_dev->vendor_id << std::endl;
    std::cout << "\tProduct ID: ";
    std::cout << cur_dev->product_id << std::endl;
    std::cout << "\tSerial Number: ";
    std::cout << cur_dev->serial_number << std::endl;
    std::cout << "\tRelease Number: ";
    std::cout << cur_dev->release_number << std::endl;
    std::cout << "\tManufacturer String: ";
    std::cout << cur_dev->manufacturer_string << std::endl;
    std::cout << "\tProduct String: ";
    std::cout << cur_dev->product_string << std::endl;
    std::cout << "\tInterface Number: ";
    std::cout << cur_dev->interface_number << std::endl;
    cur_dev = cur_dev->next;
  }
  hid_free_enumeration(devs);
}


