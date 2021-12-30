#include <iostream>
#include <unistd.h>
#include "../include/Poller.h"

#define EVENT_SIZE 1024

using namespace std;

Poller::Poller() 
    : epollfd_(-1), 
    events_(EVENT_SIZE),
    channels_() 
{
    epollfd_ = epoll_create1(EPOLL_CLOEXEC);
    if(epollfd_ < 0) {
        perror("epoll_create error.");
        exit(1);
    }
    cout << "epoll create successfully" << endl;
}

Poller::~Poller() {
    close(epollfd_);
}

