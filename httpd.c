#include <iostream>
#include "httpd.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <fcntl.h>


//storage_directoryusing namespace std;

int start_httpd(char* server_port_str, char* storage_directory)
{
	//cerr << "Starting server (port: " << port <<
		//", doc_root: " << doc_root << ")" << endl;

       fprintf(stderr, "Starting server on port %s, using dir %s\n",
			server_port_str, storage_directory);
      int sockfd = socket(AF_INET,SOCK_STREAM, 0); // create the socket
         
      if(sockfd == -1)
      {
          printf("Error opening socket\n");
      	  return -1;
      }

      struct sockaddr_in my_sockaddr_in;
           
      memset(&my_sockaddr_in, 0, sizeof(my_sockaddr_in));

      my_sockaddr_in.sin_family = AF_INET;
      my_sockaddr_in.sin_port = htons(atoi(server_port_str));
      my_sockaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);
              

      int bindid =  bind(sockfd, (struct sockaddr*)&my_sockaddr_in,sizeof(my_sockaddr_in)); // create the bind
	
      if(bindid == -1)
      {
        printf("Error binding socket\n");
        return -1;
      }

      listen(sockfd,10);
    
      return 0;
      
}
