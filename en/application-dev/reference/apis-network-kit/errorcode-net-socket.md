# Socket Error Codes

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).
> Socket error code mapping: 2301000 + [Kernel Error Codes](./errorcode-kernel.md).
> Socket error code mapping: 2303100 + [Kernel Error Codes](./errorcode-kernel.md).

## 2301001 Operation Not Allowed

**Error Message**

Operation not permitted.

**Description**

This error code is reported if an operation is not allowed.

**Cause**

The operation is illegal.

**Procedure**

Check the operation procedure.

## 2301002 File Not Exist

**Error Message**

No such file or directory.

**Description**

This error code is reported if the requested file does not exist.

**Cause**

The requested file does not exist.

**Procedure**

Check the file name or file path.

## 2301003 Process Not Exist

**Error Message**

No such process.

**Description**

This error code is reported if a process does not exist.

**Cause**

This error code is reported if a process does not exist.

**Procedure**

Check the process information.

## 2301004 System Call Interrupted

**Error Message**

Interrupted system call.

**Description**

This error code is reported if the system call is interrupted.

**Cause**

The system call is interrupted.

**Procedure**

Rectify system call errors.

**Description of TCP/UDP error codes:**
> Mapping format of other TCP/UDP Socket error codes: 2301000 + Linux kernel error code (errno). For details, see Linux kernel error codes.

## 2300002 System Internal Error

**Error Message**

System internal error.

**Description**

This error code is reported if a system internal error occurs.

**Cause**

1. The memory is abnormal.

2. A null pointer is present.

**Procedure**

1. Check whether the memory space is sufficient. If not, clear the memory and try again.

2. Check whether the system is normal. If not, try again later or restart the device.

## 2301206 Failed to Connect to the Proxy Server via SOCKS5

**Error Message**

Socks5 failed to connect to the proxy server.

**Description**

This error code is reported if a SOCKS5 client fails to connect to the proxy server.

**Cause**

The proxy server address is incorrect.

**Procedure**

Check whether the proxy server address is correct.

## 2301207 Invalid User Name or Password for SOCKS5 Authentication

**Error Message**

Socks5 username or password is invalid.

**Description**

This error code is reported if the user name or password is invalid when the SOCKS5 client uses the password authentication mode.

**Cause**

The user name or password is incorrect.

**Procedure**

Check whether the user name and password are correct.

## 2301208 Failed to Connect to the Remote Server via SOCKS5

**Error Message**

Socks5 failed to connect to the remote server.

**Description**

This error code is reported if a SOCKS5 proxy fails to connect to the remote server.

**Cause**

The network of the remote server is faulty.

**Procedure**

Check the network status of the remote server.

## 2301209 Authentication Mode Negotiation Failed for SOCKS5

**Error Message**

Socks5 failed to negotiate the authentication method.

**Description**

This error code is reported if a SOCKS5 client fails to negotiate the authentication mode with the proxy server.

**Cause**

The proxy server does not support the authentication mode provided by the SOCKS5 client.

**Procedure**

Check whether the proxy server supports the authentication mode provided by the SOCKS5 client.

## 2301210 Failed to Send Messages via SOCKS5

**Error Message**

Socks5 failed to send the message.

**Description**

This error code is reported if a SOCKS5 client fails to send messages due to a system call error.

**Cause**

This problem is usually caused by memory overflows and invalid parameters. Check the log for Linux kernel errors.

**Procedure**

Create a socket and initiate a connection again.

## 2301211 Failed to Receive Messages via SOCKS5

**Error Message**

Socks5 failed to receive the message.

**Description**

This error code is reported if a SOCKS5 client fails to receive messages due to a system call error.

**Cause**

This problem is usually caused by memory overflows and invalid parameters. Check the log for Linux kernel errors.

**Procedure**

Create a socket and initiate a connection again.

## 2301212 Failed to Serialize Messages for SOCKS5

**Error Message**

Socks5 serialization error.

**Description**

This error code is reported if message fails to be serialized for a SOCKS5 client.

**Cause**

The user name or password is too long, or the address and protocol type of the proxy server and the remote server do not match.

**Procedure**

Check whether the user name and password exceed the length limit and whether the addresses and protocol types of the proxy server and remote server match.

## 2301213 Failed to Deserialize Messages for SOCKS5

**Error Message**

Socks5 deserialization error.

**Description**

This error code is reported if message fails to be deserialized for a SOCKS5 client.

**Cause**

The length of the response packets sent by the server does not comply with the protocol.

**Procedure**

Check the response data packets of the server.

## 2303104 System Call Interrupted

**Error Message**

Interrupted system call.

**Description**

This error code is reported if the system call is interrupted.

**Cause**

Calling the **connect** function may result in a long blocking time. In such a case, the system generates an interrupt signal and returns an **EINTR** error.

**Procedure**

Call the **connect** function to try network connection again.

## 2303109 Error File Number

**Error Message**

Bad file number.

**Description**

This error code is reported if an operation is performed on a locally closed socket.

**Cause**

The socket FD may be closed.

**Procedure**

Check whether the socket is closed unexpectedly.

## 2303111 Requested Resource Temporarily Unavailable

**Error Message**

Resource temporarily unavailable. Try again.

**Description**

This error code is reported if the requested system resource is temporarily unavailable.

**Cause**

The system resources are in use.

**Procedure**

Try again later.

## 2303188 Socket Operations on Non-Sockets

**Error Message**

Not a socket.

**Description**

This error code is reported if a socket descriptor is not specified for the **socket** parameter.

**Cause**

A socket descriptor is not specified for the **socket** parameter.

**Procedure**

Check whether the descriptor is correctly obtained.

## 2303191 Incorrect Socket Protocol Type

**Error Message**

Incorrect socket protocol type.

**Description**

This error code is reported if the type of the specified socket protocol is incorrect.

**Cause**

The socket function is called with an unsupported socket protocol type. For example, the protocol type cannot be set to **SOCK_STREAM** socket for the the Internet UDP protocol.

**Procedure**

Check whether the socket protocol type is correct.

## 2303198 Network Address Already In Use

**Error Message**

Address already in use.

**Description**

This error code is reported if a network address has been used.

**Cause**

The probable cause can be any of the following: The application attempts to bind a socket to an IP address/port that has been used for an existing socket. The socket is not properly closed. The socket is still being closed.

**Procedure**

Try another network address.

## 2303199 Failed to Assign the Requested Address

**Error Message**

Address not available.

**Description**

This error code is reported if the requested address is invalid in its context.

**Cause**

The remote address or port is invalid for the remote server.

**Procedure**

Check whether the address or port is correct.

## 2303200 Network Disabled

**Error Message**

Network is down.

**Description**

This error code is reported if the network is disabled.

**Cause**

The network service is not started or has been stopped.

**Procedure**

Check the network connection.

## 2303210 Connection Timeout

**Error Message**

Connection timed out.

**Description**

This error code is reported if the connection to the remote server cannot be set up for a long time.

**Cause**

It is probable that a server breakdown has occurred.

**Procedure**

If the issue cannot be resolved locally, verify whether the remote server has encountered a fault.

## 2303501 Null SSL

**Error Message**

SSL is null.

**Description**

This error code is reported if the SSL is null.

**Cause**

The returned error information is null when an internal function fails to be executed.

**Procedure**

Call the function again.

## 2303502 TLS Read Error

**Error Message**

An error occurred when reading data on the TLS socket.

**Description**

This error code is reported if an error occurs while reading data on the TLS socket.

**Cause**

The underlying socket is blocked.

**Procedure**

Perform data receiving again.

## 2303503 TLS Write Error

**Error Message**

An error occurred when writing data on the TLS socket.

**Description**

This error code is reported if an error occurs while writing data on the TLS socket.

**Cause**

When the send buffer is full, the underlying socket sends an **EWOUDLBLOCK** error, which means that the server does not read the data sent from the client.

**Procedure**

Check the server status, and rectify the fault.

## 2303504 x509 Failed to Look Up the x509 Certificate

**Error Message**

An error occurred when verifying the x509 certificate.

**Description**

An error occurred when verifying the x509 certificate.

**Cause**

The local certificate does not match the server certificate.

**Procedure**

Check whether the local CA matches the server certificate.

## 2303505 TLS System Call Error

**Error Message**

An error occurred in the TLS system call.

**Description**

This error code is reported if the TLS system call fails because of fatal I/O errors.

**Cause**

Network communication fails because of network faults.

**Procedure**

For details, see the Linux kernel error codes (errno).

## 2303506 Failed to Close TLS Connections

**Error Message**

Failed to close the TLS connection.

**Description**

This error code is reported if the TLS/SSL connection to be closed has been disabled.

**Cause**

The TLS/SSL connection to be closed has been disabled.

**Procedure**

Initiate a new TLS/SSL connection.
