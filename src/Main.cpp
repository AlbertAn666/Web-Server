
#include "../include/Channel.h"
#include "../include/EventLoop.h"
#include "../include/HTTPServer.h"

int main(int argc, char *argv[]) {
    EventLoop eventLoop;
    HTTPServer httpServer;

    httpServer.start();
    eventLoop.loop();
    return 0;
}