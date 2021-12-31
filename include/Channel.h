/*
Selectable io channel. Used for register and response io events. Note that it does not own file descriptor
It is the member of EventLoop, TCPConnection, ...
*/

#ifndef _CHANNEL_H_
#define _CHANNEL_H_

# include <iostream>
# include <functional>
using namespace std;

class Channel {
public:
    typedef std::function<void()> Callback;

    Channel();
    ~Channel();
    void HandleEvent();
    uint32_t GetFd() { return fd_; }
    uint32_t GetEvents() { return events_; }
    void SetFd(uint32_t fd) { fd_ = fd; }
    void SetEvents(uint32_t events) { events_ = events; }
    void SetReadCallback(Callback CallbackFunc) { ReadCallback = CallbackFunc; }
    void SetWriteCallback(Callback CallbackFunc) { WriteCallback = CallbackFunc; }
    void SetErrorCallback(Callback CallbackFunc) { ErrorCallback = CallbackFunc; }



private:
    uint32_t fd_;
    uint32_t events_;
    Callback ReadCallback;
    Callback WriteCallback;
    Callback ErrorCallback;

};

#endif