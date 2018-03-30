#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "httpd.h"
#include <stdio.h>
//using namespace std;

int usage(char * argv0)
{
  //cerr << "Usage: " << argv0 << " listen_port docroot_dir" << endl;
        fprintf(stderr,"listen_port docroot_dir:%s\n",argv0);
        
        return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		usage(argv[0]);
		return 1;
	}

	long int port = strtol(argv[1], NULL, 10);

	if (errno == EINVAL || errno == ERANGE) {
		usage(argv[0]);
		return 2;
	}

	if (port <= 0 || port > USHRT_MAX) {
	  //cerr << "Invalid port: " << port << endl; 
                fprintf(stderr,"Invalid port:%ld\n",port);
		return 3;
	}
       
        char* listenPort = argv[1];
	char* doc_root = argv[2];
        
        return start_httpd(listenPort, doc_root);

	//	return 0;
}
