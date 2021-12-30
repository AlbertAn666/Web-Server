/*
Poller is the encapsulation of IO multiplexing with epoll, this class dowen't own the Channel objects.
Poller is the member of EventLoop and is only used for calling of its owner EventLoop during IO thread.
The TTL is the same as that of EventLoop
*/

#ifndef _POLLER_H_
#define _POLLER_H_

#include <iostream>
#include <vector>
#include <map>
#include <sys/epoll.h>
#include "Channel.h"

using namespace std;

class Poller {
public: 
    typedef vector<Channel*> ChannelList;

    Poller();
    ~Poller();
    void poll(ChannelList &activeChannels);
    void AddChannel(Channel *channel);
    void RemoveChannel(Channel *channel);
    void UpdateChannel(Channel *channel);

private:
    typedef map<uint32_t, Channel*> ChannelMap;
    typedef vector<struct epoll_event> EventList;

    ChannelMap channels_; // the map of fd to Channel*
    EventList events_;

    int epollfd_;
};

#endif