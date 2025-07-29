# Media Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 5400101 Memory Allocation Failed

**Error Message**

No memory.

**Description**

Failed to allocate memory.

**Possible Causes**

1. The number of instances exceeds 16.
2. The new or malloc process fails, causing a null pointer.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400102 Unsupported Operation

**Error Message**

Operation not allowed.

**Description**

This operation is not allowed.

**Possible Causes**

This operation is not allowed in the current state.

**Solution**

Switch the instance to the correct state and perform the operation.

## 5400103 I/O Error

**Error Message**

I/O error.

**Description**

An I/O error occurs.

**Possible Causes**

The data interaction between the media and other modules (graphics, audio, network, HDI, and camera) is abnormal.

**Solution**

Ensure that the network is normal, destroy this instance, and re-create it. If the re-creation fails, stop related operations.

## 5400104 Operation Timeout

**Error Message**

Operation timeout.

**Description**

The operation timed out.

**Possible Causes**

1. The network connection times out. (The default network timeout period is 15 seconds, and the timer starts after the buffered event is reported.)
2. Accessing other modules times out.

**Solution**

1. Check whether the network is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400105 Play Service Dead

**Error Message**

Service died.

**Description**

The playback service is dead.

**Possible Causes**

The playback service is dead.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5400106 Format Not Supported

**Error Message**

Unsupported format.

**Description**

The format is not supported.

**Possible Causes**

The file format is not supported.

**Solution**

Use a supported format.

For details about the supported formats, see [Media Kit Overview](../../media/media/media-kit-intro.md).

## 5400107 Audio Focus Conflict

**Error Message**

Audio interrupted.

**Description**

Recording fails due to audio focus conflicts.

**Possible Causes**

Another process occupies the audio focus.

**Solution**

Destroy the current instance and check whether another process is recording. If you can stop the other process, you can create the current instance again.

## 5400108 Parameter Value Out of Range

**Error Message**

The parameter check failed, parameter value out of range.

**Description**

The parameter check fails because the value is beyond the allowable range.

**Possible Causes**

The value of the parameter exceeds the expected range.

**Solution**

Adjust the parameter value to fall within the acceptable range.

<!--Del-->
## 5400109 Session ID Does Not Exist

**Error Message**

Sessions not exist. Return by promise.

**Description**

This error is reported when the session ID does not exists.

**Possible Causes**

The session ID does not exist.

**Solution**

Pass in a correct session ID.
<!--DelEnd-->

## 5411001 Failed to Parse or Connect to the Server Address

**Error Message**

Can not find host.

**Description**

An error occurred when parsing or connecting to the server address.

**Possible Causes**

1. The server address is incorrect.
2. The server address fails to be parsed.

**Solution**

Try another server address.

## 5411002 Network Connection Timeout

**Error Message**

Connection time out.

**Description**

Network connection times out.

**Possible Causes**

The network is abnormal.

**Solution**

1. Check whether the network is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411003 Data or Link Exception Caused by Network Exceptions

**Error Message**

NetWork abnormal.

**Description**

Data or links are abnormal due to network exceptions.

**Possible Causes**

The network is abnormal.

**Solution**

Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411004 Network Disabled

**Error Message**

NetWork unavailable.

**Description**

The network is unavailable.

**Possible Causes**

The network is disabled.

**Solution**

1. Check whether the network is disabled.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411005 Access Denied

**Error Message**

No permission.

**Description**

No access permission.

**Possible Causes**

No access permission.

**Solution**

1. Check whether you have the access permission.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411006 Client Request Parameter Is Incorrect or Exceeds the Processing Capability

**Error Message**

Network access denied.

**Description**

The client request parameter is incorrect or exceeds the processing capability.

**Possible Causes**

The client request parameter is incorrect or exceeds the processing capability.

**Solution**

1. Correct the request parameter.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411007 No Resource Available

**Error Message**

Cannot find available network resources.

**Description**

No network resource is available.

**Possible Causes**

The server address is abnormal.

**Solution**

1. Check whether the server address is correct.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411008 Server Fails to Verify the Client Certificate

**Error Message**

SSL client cert needed.

**Description**

The SSL client is untrusted, and the server fails to verify the client certificate.

**Possible Causes**

The certificate is not carried, is invalid, or has expired.

**Solution**

1. Check whether the SSL certificate is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411009 SSL Connection Failed

**Error Message**

SSL connection failed.

**Description**

The SSL connection fails.

**Possible Causes**

The SSL connection fails.

**Solution**

1. Check whether the SSL connection has expired.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411010 Client Fails to Verify the Server Certificate

**Error Message**

SSL server cert untrusted.

**Description**

The SSL server is untrusted, and the client fails to verify the server certificate.

**Possible Causes**

The certificate is not carried, is invalid, or has expired.

**Solution**

1. Check whether the SSL certificate is normal.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5411011 Unsupported Request Due to Network Protocol Errors

**Error Message**

Unsupportted request.

**Description**

The client request parameter is incorrect or exceeds the processing capability.

**Possible Causes**

The client request parameter is incorrect or exceeds the processing capability.

**Solution**

1. Check whether the client request parameter is correct.
2. Destroy this instance and re-create it. If the re-creation fails, stop related operations.

## 5410002 Seek in SEEK_CONTINUOUS Mode Is Not Supported

**Error Message**

seek continuous is unsupported.

**Description**

The media source or device does not support the seek operation in SEEK_CONTINUOUS mode.

**Possible Causes**

The media source or device does not support the seek operation in SEEK_CONTINUOUS mode.

**Solution**

1. This error code informs the client about the behavior when seeking is not supported in SEEK_CONTINUOUS mode. The client does not need to handle this.

## 5410003 Super Resolution Is Not Supported

**Error Message**

super resolution not supported.

**Description**

The media source or device does not support super resolution.

**Possible Causes**

Super resolution is available only for non-HDR and non-DRM videos with a resolution of 1080p or lower. If the media source does not meet the super resolution requirements or the current device does not support super resolution, this error is reported when an API related to super resolution is called.

**Solution**

Do not call super resolution related APIs for the media source on the current device.

## 5410004 Super Resolution Is Not Enabled

**Error Message**

super resolution not enabled.

**Description**

Super resolution is not enabled. As a result, super resolution related APIs are unavailable.

**Possible Causes**

Super resolution is not enabled by using [PlaybackStrategy](./arkts-apis-media-i.md#playbackstrategy12).

**Solution**

Enable super resolution before calling related APIs.
