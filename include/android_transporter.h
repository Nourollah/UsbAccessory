// **************************************************************************************************************** //
// Created by amirmasoud on 8/17/20.
/**
 * Android Open usb_accessory transporter implementation for libusb-1.0
 */

#ifndef ACCESSORY_ANDROID_TRANSPORTER_H
#define ACCESSORY_ANDROID_TRANSPORTER_H

#include <libusb-1.0/libusb.h>

class android_transporter
{
private:
    libusb_context *contex;
    struct libusb_device_handle* handle;
    uint8_t inEP;
    uint8_t outEP;
    int verProtocol;
    libusb_transfer* inTransfer;
    char versionString[15]; // Bigger than 10, just in case
    pthread_t readThread;
    pthread_t writeThread;
    int ThreadRunner;

public:

    android_transporter();
    ~android_transporter();

    int read(unsigned char *buf, int len, unsigned int timeout, pthread_t readThread);
    int read_async(libusb_transfer_cb_fn callback, char* buffer, int bufferLen, void* userData, unsigned int timeOut, pthread_t readThread);
    int write(unsigned char *buf, int len, unsigned int timeout, pthread_t writeThread);
    int write_async(libusb_transfer_cb_fn callback, char* buffer, int bufferLen, void* userData, unsigned int timeOut, pthread_t writeThread);
    int handle_async(struct timeval* tv);
    int send_string(int index, const char *str);

};


#endif //ACCESSORY_ANDROID_TRANSPORTER_H