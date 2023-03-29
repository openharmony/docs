# tftp


## Command Function

Trivial File Transfer Protocol (TFTP) is a protocol in the TCP/IP protocol suite for transferring files between clients and servers. TFTP provides simple and low-overhead file transfer services. The port number is 69.

The **tftp** command is used to transfer files with a TFTP server.


## Syntax

./bin/tftp *&lt;-g/-p&gt;**-l**[FullPathLocalFile] -r [RemoteFile] [Host]*


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| -g/-p | Specifies the file transfer direction.<br>- **-g**: obtains a file from the TFTP server.<br>- **-p**: uploads a file to the TFTP server.| N/A |
| -l&nbsp;FullPathLocalFile | Specifies the complete path of a local file.| N/A |
| -r&nbsp;RemoteFile | Specifies the file name on the server.| N/A |
| Host | Specifies the server IP address.| N/A |


## Usage Guidelines

1. Deploy a TFTP server on the server and configure the TFTP server correctly.

2. Use the **tftp** command to upload files from or download files to an OpenHarmony board.

3. The size of the file to be transferred cannot exceed 32 MB.
   > **NOTICE**<br>
   > TFTP is used for debugging and disabled by default. Do not use it in formal products.


## Example

Download the **out** file from the server.


## Output


```
OHOS # ./bin/tftp -g -l /nfs/out -r out 192.168.1.2
TFTP transfer finish
```

After the **tftp** command is executed, **TFTP transfer finish** is displayed if the file transfer is complete. If the file transfer fails, other information is displayed to help locate the fault.
