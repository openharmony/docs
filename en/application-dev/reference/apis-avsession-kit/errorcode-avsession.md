# AVSession Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 6600101 Session Service Exception

**Error Message**

Session service exception.

**Description**

The session service is abnormal, and the application cannot obtain a response from the session service. For example, the session service is not running or the communication with the session service fails.

**Possible Causes**

The session service is killed during session restart.

**Solution**

1. The system retries the operation automatically. If the error persists for 3 seconds or more, stop the operation on the session or controller.

2. Destroy the current session or session controller and re-create it. If the re-creation fails, stop the operation on the session.

## 6600102 Session Does Not Exist

**Error Message**

The session does not exist.

**Description**

Parameters are set for or commands are sent to the session that does not exist.

**Possible Causes**

The session has been destroyed, and no session record exists on the server.

**Solution**

1. If the error occurs on the application, re-create the session. If the error occurs on Media Controller, stop sending query or control commands to the session.

2. If the error occurs on the session service, query the current session record and pass the correct session ID when creating the controller.

## 6600103 Session Controller Does Not Exist

**Error Message**

The session controller does not exist.

**Description**

A control command or an event is sent to the controller that does not exist.

**Possible Causes**

The controller has been destroyed.

**Solution**

Query the session record and create the corresponding controller.

## 6600104 Remote Session Connection Failure

**Error Message**

The remote session connection failed.

**Description**

The communication between the local session and the remote session fails.

**Possible Causes**

The communication between devices is interrupted.

**Solution**

Stop sending control commands to the session. Subscribe to output device changes, and resume the sending when the output device is changed.

## 6600105 Invalid Session Command

**Error Message**

Invalid session command.

**Description**

The control command or event sent to the session is not supported.

**Possible Causes**

The session does not support this command.

**Solution**

Stop sending the command or event. Query the commands supported by the session, and send a command supported.

## 6600106 Session Not Activated

**Error Message**

The session is not activated.

**Description**

A control command or event is sent to the session that is not activated.

**Possible Causes**

The session is in the inactive state.

**Solution**

Stop sending the command or event. Subscribe to the session activation status, and resume the sending when the session is activated.

## 6600107 Too Many Commands or Events

**Error Message**

Too many commands or events.

**Description**

The session client sends too many messages or commands to the server in a period of time, causing the server to be overloaded.

**Possible Causes**

The server is overloaded with messages or events.

**Solution**

Control the frequency of sending commands or events.

## 6600108 Device Connection Failure

**Error Message**

Device connection failed.

**Description**

Connection to the device fails.

**Possible Causes**

The device connection logic is abnormal or the device status is abnormal.

**Solution**

Refresh the device list and check whether the device is offline.

## 6600109 Remote Session Does Not Exist

**Error Message**

The remote connection is not established.

**Description**

The remote session does not exist, and the related API calls fail.

**Possible Causes**

The remote session has been destroyed or has not been created.

**Solution**

Query the session status again to determine whether the remote session exists.
