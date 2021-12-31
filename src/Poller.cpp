/*
struct epoll_event is defined as:
typedef union epoll_data {
    void *ptr;
    int fd;
    uint32_t u32;
    uint64_t u64;
} epoll_data_t;

struct epoll_event {
    uint32_t events;
    epoll_data_t data;
}
*/

#include <iostream>
#include <unistd.h>
#include <sys/epoll.h>
#include "../include/Poller.h"

#define EVENT_SIZE 1024
#define TIMEOUT 1000

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

void Poller::poll(ChannelList &activeChannels) {
    // return the number of file descriptors ready for the requested I/O.
    int numfd = epoll_wait(epollfd_, &*events_.begin(), events_.size(), TIMEOUT);  
    if(numfd == -1) {
        perror("epoll_wait error");
        exit(1);
    }
    
}

