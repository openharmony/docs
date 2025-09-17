# HTTP Error Codes

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2300001 Protocol Not Supported

**Error Message**

Unsupported protocol.

**Description**

This error code is reported if the input protocol version is not supported by the server.

**Cause**

The input protocol version is not supported by the server.

**Solution**

Specify a protocol version supported by the server.

## 2300003 Incorrect URL Format

**Error Message**

Invalid URL format or missing URL.

**Description**

This error code is reported if the URL format is incorrect.

**Cause**

The format of the input URL is incorrect.

**Solution**

Specify a URL of the correct format.

## 2300005 Failed to Resolve the Domain Name of the Proxy Server

**Error Message**

Failed to resolve the proxy name.

**Description**

This error code is reported if the domain name of the proxy server cannot be resolved.

**Cause**

The URL of the proxy server is incorrect.

**Solution**

Specify a URL of the correct format.

## 2300006 Failed to Resolve the Domain Name of the Host

**Error Message**

Failed to resolve the host name.

**Description**

This error code is reported if the domain name of the host cannot be resolved.

**Cause**

1. The input URL is incorrect.

2. The network connection is abnormal.

**Solution**

1. Specify a URL of the correct format.

2. Rectify network connection faults.

## 2300007 Failed to Connect to the Server

**Error Message**

Failed to connect to the server.

**Description**

This error code is reported if the server connection failed.

**Cause**

The format of the input URL is incorrect.

**Solution**

Specify a URL of the correct format.

## 2300008 Invalid Data Returned by the Server

**Error Message**

Invalid server response.

**Description**

This error code is reported if the data returned by the server is invalid.

**Cause**

The server encounters an error and returns data in non-HTTP format.

**Solution**

Check the server implementation.

## 2300009 Access to Remote Resources Denied

**Error Message**

Access to the remote resource denied.

**Description**

This error code is reported if the access to remote resources is denied by the server.

**Cause**

The access to the specified resource is denied by the server.

**Solution**

Check whether access to the requested resource is allowed.

## 2300016 HTTP2 Framing Layer Error

**Error Message**

Error in the HTTP2 framing layer.

**Description**

This error code is reported if an error occurs on the HTTP2 framing layer.

**Cause**

HTTP2 is not supported by the server.

**Solution**

Capture and analyze packets to check whether HTTP2 is supported by the server.

## 2300018 Incomplete Data Returned by the Server

**Error Message**

Transferred a partial file.

**Description**

This error code is reported if data returned by the server is incomplete.

**Cause**

This problem is probable due to server implementation.

**Solution**

Check the server implementation.

## 2300023 Failed to Write Received Data to a Disk or Application

**Error Message**

Failed to write the received data to the disk or application.

**Description**

This error code is reported if an error occurs while writing received data to the disk or application.

**Cause**

- The application does not have the permission to write files or the file to be downloaded exceeds 5 MB.

- The **destroy** function is called before the data of the last request is fully received.

**Solution**

Check the application permission and the size of the file to be downloaded.

## 2300025 Failed to Upload Data

**Error Message**

Upload failed.

**Description**

This error code is reported if data upload fails.

**Cause**

The file is too large or the network is faulty. The server may reject the **STOR** command if FTP is used. The error buffer usually contains the reason from the server.

**Solution**

Check the file size and network status.

## 2300026 Failed to Open or Read Local Data from a File or Application

**Error Message**

Failed to open or read local data from the file or application.

**Description**

This error code is reported if an error occurs while opening or reading local data from a file or application.

**Cause**

The application does not have the data read permission.

**Solution**

Check the permissions granted to the application.

## 2300027 Insufficient Memory

**Error Message**

Out of memory.

**Description**

This error code is reported if the memory is insufficient.

**Cause**

This error code is reported if the memory is insufficient.

**Solution**

Check the system memory.

## 2300028 Operation Timeout

**Error Message**

Operation timeout.

**Description**

This error code is reported if the operation times out.

**Cause**

The TCP connection or the read/write operation times out.

**Solution**

Check whether the network is stable and the signal strength is strong. If the network is normal, check whether the server is overloaded or service processing is slow.

## 2300047 Maximum Redirections Reached

**Error Message**

The number of redirections reaches the maximum allowed.

**Description**

This error code is reported if the number of redirections reaches the maximum.

**Cause**

Redirections are too frequent.

**Solution**

Check the server implementation.

## 2300052 No Content Returned by the Server

**Error Message**

The server returned nothing (no header or data).

**Description**

This error code is reported if no content is returned by the server.

**Cause**

This problem is probable due to server implementation.

**Solution**

Check the server implementation.

## 2300055 Failed to Send Network Data

**Error Message**

Failed to send data to the peer.

**Description**

This error code is reported if an error occurs while sending network data to the peer end.

**Cause**

This problem is probable due to a network fault.

**Solution**

Rectify network faults.

## 2300056 Failed to Receive Network Data

**Error Message**

Failed to receive data from the peer.

**Description**

This error code is reported if an error occurred while receiving network data from the peer end.

**Cause**

This problem is probable due to a network fault.

**Solution**

Rectify network faults.

## 2300058 Local SSL Certificate Error

**Error Message**

Local SSL certificate error.

**Description**

This error code is reported if the local SSL certificate is incorrect.

**Cause**

The format of the SSL certificate is incorrect.

**Solution**

Check the format of the SSL certificate.

## 2300059 Failed to Use the Specified SSL Cipher Algorithm

**Error Message**

The specified SSL cipher cannot be used.

**Description**

This error code is reported if the specified SSL cipher algorithm cannot be used.

**Cause**

The system does not support the cipher algorithm negotiated between the client and server.

**Solution**

Capture and analyze packets to check whether the cipher algorithm is supported.

## 2300060 Incorrect SSL Certificate or SSH Key of the Remote Server

**Error Message**

Invalid SSL peer certificate or SSH remote key.

**Description**

This error code is reported if the SSL certificate or SSH key of the remote server is incorrect.

**Cause**

It is probable that the server identity verification fails because the certificate has expired.

**Solution**

Check whether the certificate is valid.

## 2300061 Unrecognized or Incorrect HTTP Encoding Format

**Error Message**

Invalid HTTP encoding format.

**Description**

This error code is reported if the HTTP encoding format cannot be identified or is incorrect.

**Cause**

The HTTP encoding format is incorrect.

**Solution**

Check the server implementation. Currently, only gzip encoding is supported.

## 2300063 Maximum File Size Exceeded

**Error Message**

Maximum file size exceeded.

**Description**

This error code is reported if the maximum file size is exceeded.

**Cause**

The downloaded file is too large.

**Solution**

Check the server implementation.

## 2300070 Insufficient Server Disk Space

**Error Message**

Remote disk full.

**Description**

This error code is reported if the server disk space is insufficient.

**Cause**

The server disk is full.

**Solution**

Check the server disk space.

## 2300073 Uploaded File Already Exists

**Error Message**

Remote file already exists.

**Description**

This error code is reported if the server finds that the uploaded file already exists.

**Cause**

The uploaded file already exists.

**Solution**

Check the server for files that already exist.

## 2300077 No SSL CA Certificate or Access Permission

**Error Message**

The SSL CA certificate does not exist or is inaccessible.

**Description**

This error code is reported if the SSL CA certificate does not exist or the access permission is not available.

**Cause**

The SSL CA certificate is not available or the access permission is not granted.

**Solution**

Check whether the SSL CA certificate exists or the access permission is granted.

## 2300078 URL Requested File Not Found

**Error Message**

Remote file not found.

**Description**

This error code is reported if the file requested by the specified URL does not exist.

**Cause**

This error code is reported if the file requested by the specified URL does not exist.

**Solution**

Check whether the file requested by the specified URL exists.

## 2300094 Identity Verification Failed

**Error Message**

Authentication error.

**Description**

This error code is reported if identity verification fails.

**Cause**

The specified identity verification field does not match that on the server.

**Solution**

Check whether the specified identity verification field matches that on the server.

## 2300997 Plaintext HTTP Access Intercepted

**Error Message**

Cleartext traffic not permitted.

**Description**

This error code is reported if plaintext HTTP access is intercepted.

**Cause**

The plaintext access is not allowed in the **network_config.json** file.

**Solution**

Check the setting of the **cleartextTrafficPermitted** field in the **network_config.json** file.

## 2300998 Domain Access Denied

**Error Message**

It is not allowed to access this domain.

**Description**

This error code is reported if access to a certain domain is prohibited.

**Cause**

An incorrect server domain name is configured for the atomic service.

**Solution**

Configure a correct server domain name for the atomic service.

## 2300999 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported if an internal error occurs.

**Cause**

An unknown error occurs.

**Solution**

Try again or contact technical support.
