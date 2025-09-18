# Link Enhancement Error Codes
<!--Kit: Distributed Service Kit-->
<!--Subsystem: DistributedSched-->
<!--Owner: @wangJE-->
<!--Designer: @lee_jet520-->
<!--Tester: @Ytt-test-->
<!--Adviser: @w_Machine_cc-->
> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 32390200 Client Connection Timeout

**Error Message**

Connect timeout.

**Description**

This error code is reported if a client connection fails due to a timeout.

**Possible Causes**

The server does not respond before the timeout.

**Solution**

Try again after the timeout. If a connection to the remote device exists, disconnect the connection and try again.

## 32390201 Server Service Not Started

**Error Message**

Peer server is not started.

**Description**

This error code is reported if the corresponding service on the server is not started.

**Possible Causes**

This error code is reported if the corresponding service on the server is not started.

**Solution**

Check whether the corresponding service is started on the target device. If not, start the service and then initiate a connection.

## 32390202 Number of Services Exceeding the Limit

**Error Message**

The number of servers exceeds the limit.

**Description**

This error code is reported if the number of services exceeds the limit.

**Possible Causes**

The number of requested services exceeds 10.

**Solution**

Call **close()** to release services that are no longer used.

## 32390203 Duplicate Service Name

**Error Message**

Duplicate server name.

**Description**

This error code is reported if a service with the same name is registered repeatedly.

**Possible Causes**

The name of the service being created already exists.

**Solution**

Check whether a service with the same name already exists. If yes, register the service with a different name.

## 32390204 Number of Connections Exceeding the Limit

**Error Message**

The number of connection exceeds the limit.

**Description**

This error code is reported if the number of connections exceeds the limit.

**Possible Causes**

The number of requested connections exceeds 10.

**Solution**

Call **close()** to release connections that are no longer used.

## 32390205 Connection Unavailable

**Error Message**

Connection is not ready.

**Description**

This error code is reported if a connection is unavailable.

**Possible Causes**

The client or server application is using a connection that has been disconnected.

**Solution**

Check whether the connection is available. If the connection is available, use the connection to perform operations.

## 32390206 Invalid Parameter

**Error Message**

Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.

**Description**

Parameter error.

**Possible Causes**

1. A mandatory parameter is not passed.

2. The parameter type is incorrect.

3. The number of parameters is incorrect.

4. A parameter is left empty.

**Solution**

Check whether mandatory parameters are passed and whether their types are correct. If the parameter verification fails, rectify the fault based on the possible causes in the API reference.

## 32390300 Internal Error

**Message**

Internal error.

**Description**

An internal error occurs.

**Possible Causes**
1. Invalid input device ID.

2. Invalid input name.

3. Abnormal internal state.

4. Incorrect API usage.

5. System errors, such as null pointer, insufficient memory, unexpected distributed service restart, IPC exception, and JS engine exception.

**Solution**

View the error log to identify the error cause. Take appropriate based on the actual cause:

1. If the device ID passed to the API is the same as that obtained from the Bluetooth system API, check whether the peer device is in the advertising state.

2. If the name passed from the client to the server is the same as that passed from the server to the client, check whether the name is correct by referring to the API reference.

3. Check whether objects are used after being closed.

4. Check whether the API is correctly used by referring to the API reference.

5. If the problem persists, restart or update the application or upgrade the device version.
