#ifndef HTTPD_H
#define HTTPD_H

#include <string>

//using namespace std;

int start_httpd(char* port, char* doc_root);

struct HTTPMessage {
  char* message;
  char* client_address;
};

struct HTTPRequest{
  char* message;
  char* client_address;
};

struct HTTPResponse {
  char* message;
  char* client_address;
};


#endif // HTTPD_H
