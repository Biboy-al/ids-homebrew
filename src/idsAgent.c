#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <pcap/pcap.h>
#include <netinet/in.h>

#include "include/pCap.h"
#include "include/errorHand.h"
#include "include/packetHeaders.h"

const int MANAPORT = 8888;

struct sockaddr_in serverAddr;

char msg[] = "HELLO MANAGMENT SYSTEM";

int sockfd;

char IP[] = "127.0.0.1";


void readPacket(const unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet);

int main(){
	//createSocket();

	//close(sockfd);

	struct sniffer *sniff = initSinffer("eth0");

	startCap(sniff, readPacket);


}

//creates a socket to communicate with the IDS managment system 

int createSocket(){

	sockfd = checkError(socket(AF_INET, SOCK_DGRAM, 0), "Socket Failed");

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(IP);
	serverAddr.sin_port = htons(MANAPORT);

	 checkError(sendto(sockfd, msg, sizeof(msg), 0,(struct sockaddr*)&serverAddr, sizeof(serverAddr)), "Cannot send message");

	 printf("message Sent");
	return 0;

}

void readPacket(const unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet){

	struct sniff_ethernet *eth = (struct sniff_ethernet*) packet;

	struct sniff_ip *ip = (struct sniff_ip  *)(packet + SIZE_ETHERNET);
	
	struct in_addr ip_src =  ip->ip_src;

	printf("packet Recived from %s:\n", inet_ntoa(ip_src) );
}