// Channel is used for register and response for IO event
#include <iostream>
#include <sys/epoll.h>
#include "../include/Channel.h"

using namespace std;

Channel::Channel() { }
Channel::~Channel() { }
void Channel::HandleEvent() {
    if(events_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP)) {
        if(ReadCallback) ReadCallback();
    } else if(events_ & (EPOLLOUT)) {
        if(WriteCallback) WriteCallback();
    } else {
        if(ErrorCallback) ErrorCallback();
    }
}