# Device Management Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 11600101 Service Invoking Exception

**Error Message**

Failed to execute the function.

**Possible Causes**

An error occurred during internal invocation.

**Solution**

Call the API again.

## 11600102 Failed to Obtain the Service

**Error Message**

Failed to obtain the service.

**Possible Causes**

The service is not started or fails to start.

**Solution**

Make sure the service is started and obtain the service again.

## 11600103 Authentication Unavailable

**Error Message**

Authentication unavailable.

**Possible Causes**

The last authentication service is still in progress.

**Solution**

Wait until the last authentication service is complete and call the authentication API again.

## 11600104 Discovery Unavailable

**Error Message**

Discovery unavailable.

**Possible Causes**

The last discovery service is still in progress.

**Solution**

Wait until the last discovery service is complete and call the discovery API again.

## 11600105 Publish Unavailable

**Error Message**

Publish unavailable.

**Possible Causes**

The last publish service is still in progress.

**Solution**

Wait until the last publish service is complete and call the publish API again.
