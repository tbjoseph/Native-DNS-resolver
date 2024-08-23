## Overview
This project focuses on designing and implementing a non-ASCII application-layer protocol to issue recursive DNS queries to specified DNS servers and parse their responses using UDP. This system is crucial for environments such as educational institutions or VPNs, where specific DNS queries and responses need to be handled and understood programmatically without high-level library support.

## Features
* Custom UDP Implementation: Direct usage of UDP to send and receive DNS queries and responses, ensuring detailed control over network communication.
* Recursive DNS Queries: Ability to perform recursive DNS lookups by directly interacting with DNS servers specified by the user.
* Manual DNS Response Parsing: Parses DNS responses manually to extract detailed information from various sections of the DNS message structure.
* Command-line Interface: Users can specify the lookup string and DNS server IP via command-line arguments, making the tool adaptable for different testing scenarios.
* Robust Testing and Validation: Includes mechanisms to handle common DNS response errors and network issues, such as timeouts and malformed packets.
* Error Detection: Includes detailed detection for DNS-specific errors and anomalies in response packets.
* Retransmission Mechanism: Implements a simple retransmission mechanism for handling packet loss, with up to three retransmission attempts after a 10-second timeout.

## System Requirements
* UDP and DNS Understanding: Basic understanding of UDP protocols and DNS query/response formats.
* Development Environment: The system is implemented using C/C++ on Windows or similar platforms where direct socket programming is supported.

## Installation and Setup
* Compile the Program: Use a C/C++ compiler to compile the provided source files. Ensure all dependencies, like the Windows Socket library, are correctly configured.
* Prepare the Environment: The program requires no special installation but may require network configuration adjustments (e.g., firewall settings) to allow UDP communications.

## Usage
The program is run from the command line with two required arguments:
* The first argument is the domain name or IP address for the DNS lookup.
* The second argument is the IP address of the DNS server to query.

Example usage:
```
hw2.exe www.example.com 192.0.2.53
```
This command issues a DNS query for www.example.com to the DNS server at 192.0.2.53.

## Output Format
* Lookup Information: Displays the query sent, including the domain or IP looked up.
* Server Response: Detailed breakdown of the DNS response including transaction ID, flags, questions, answers, authority records, and additional records.
* Error Handling: Identifies and reports network errors and DNS-specific errors such as non-responses, malformed packets, and timeouts.

## Contribution
Contributors can extend the project by adding support for additional DNS record types, enhancing the user interface, or improving the robustness of the network error handling mechanisms.
