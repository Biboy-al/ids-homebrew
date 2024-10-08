# IDS-Hombrew

What Will this do?
------------------
This project is about making a host-based IDS that will monitor the anomalies activity of a host. This will be both a FIM (File Integrity Monitoring) and HIDS system.

This HIDS will utilize a signature based detection method. Pre-defined rules will be setup inorder to focus on certain objects. For file integrity, the system will generate a hash of each file, where it will be used to generate a snapshot of the system. 
The snap shot will go on and be used to detect any anomalies 

This system will have a central IDS managment system, and agents. These agents are placed on diffrent hosts.

Main Functionality:
--------------------
* have modifiable rules that the users can change
 
* Monitors the:
  * Internal Systems
    
    * changes to files and directories
    * Checks for file access
    * Running new process
    * Show system logs
    * The managment system itself will hash these files when sensors are placed
      
  * Network activity
    
    * Monitors incoming packets
    * services running at a given time
      
*  Logs the these events
  
    * The events in question will have this format:
      
      * ID | Event Time | Location
        
* Will use a Socket communication method to have the host managment system talk to the agents.

     

Will draw inspiration from:
-------------------------

* tripwire


Components:
-----------
* IDS manager - will log, and analyse the data given by the agents
  * Logs the traffic seen in some form of persistent storage
  * Analyses and alerts(through the interface) of any anomalous behaviour
* Agent(s) - Will collect the data from the host:
  * Network functionality
    * Looks at the incoming traffic
    * Sends this data to the managment system 
  * File System functionality
    * Looks at the hashes of the file system objects perodically
    * Reports it back to the managment system 
* Database - Will have cryptorgraphc information about the files being monitored:
  * Hashes and checksums
  * Digital signatures
* Communication channel - these componets will be it's own process and will utilize socket-based communications.

Secure Algorithms Used:
----------------------
* will use SHA256 hash function to hash directories/files (use openssl/md2.h)

CheckList:
-----------

- [x] Implement the communication Method
  - [x] sockets
- [ ] Implement the agent
  - [ ] Implement the file system functionality
    - [X] Implement the hashing function
    - [ ] Use it to on a file and check if the hash has been changed
  - [ ] Implement The network sniffing functionality
    - [X] Sniff the network
    - [ ] Send the packets to the managment system
- [ ] Implement managment system functionality
  - [ ] Add new rules
  - [ ] Have a alerts of triggered rules
  - [ ] Logs activity in a file
- [ ] Implement persistent storage
  - [ ] persistent storage for known network attacks
  - [ ] Persistent storage for hashes 
     

Further Reading:
-----------------

* [What is HIDS](https://www.bulletproof.co.uk/blog/host-based-intrusion-detection-systems)
* [OSSEC HIDS setup](https://www.youtube.com/watch?v=7c8xowHz0Ko&ab_channel=AkamaiDeveloper)
* [How Tripewide checks for file integrity](https://manpages.ubuntu.com/manpages/focal/man8/tripwire.8.html#:~:text=Using%20the%20policy%20file%20rules,in%20the%20Tripwire%20configuration%20file.)
* [How snort checks fo anomalies](https://www.zenarmor.com/docs/network-security-tutorials/what-is-snort#:~:text=Snort%20uses%20both%20anomaly%2Dbased,identify%20potentially%20harmful%20network%20activities.)
* [How to use libpcap in C](https://www.tcpdump.org/pcap.html)
* [Components in a IDS](https://www.tookitaki.com/glossary/intrusion-detection-system-ids#:~:text=Key%20Components%20of%20IDS,-An%20IDS%20comprises&text=Sensors%3A%20Gather%20raw%20data%2C%20often,configure%2C%20and%20control%20the%20IDS)


