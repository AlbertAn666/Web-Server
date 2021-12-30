#ifndef _HTTPSERVER_H_
#define _HTTPSERVER_H_

#include <iostream>
using namespace std;

class HTTPServer {
public:
    HTTPServer();
    ~HTTPServer();

    void start();
};

#endif