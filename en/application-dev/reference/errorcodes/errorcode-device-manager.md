# Device Management Error Codes

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

Check whether the service is started normally and obtain the service again.

## 11600103 Authentication Unavailable

**Error Message**

Authentication invalid.

**Possible Causes**

The last authentication service is still in progress.

**Procedure**

Wait until the last authentication service is complete and call the authentication API again.

## 11600104 Discovery Unavailable

**Error Message**

Discovery invalid.

**Possible Causes**

The last discovery service is still in progress.

**Solution**

Wait until the last discovery service is complete and call the discovery API again.

## 11600105 Publish Unavailable

**Error Message**

Publish invalid.

**Possible Causes**

The last publish service is still in progress.

**Solution**

Wait until the last publish service is complete and call the publish API again.
