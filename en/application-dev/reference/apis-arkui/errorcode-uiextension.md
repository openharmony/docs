# UIExtension Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 1011 Ability Startup Failure

**Error Message**

Failed to start the UIExtension ability.

**Description**

This error code is reported when the UIExtension ability fails to start.

**Possible Causes**

1. The configuration of the **Want** parameter is incorrect.
2. There is a type mismatch.
3. The provider application is not installed.

**Solution**

Verify the configuration of the **Want** parameter and the types, and ensure the application is installed.

## 1012 Failed to Switch the Ability to the Background

**Error Message**

Failed to switch the UIExtension ability to the background.

**Description**

This error code is reported when the UIExtension ability fails to be moved to the background.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 1013 Ability Termination Failure

**Error Message**

Failed to destroy the UIExtension ability.

**Description**

This error code is reported when the UIExtension ability fails to be terminated.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100011 No Synchronous Callback Registered

**Error Message**

No callback has been registered to respond to this request.

**Description**

This error code is reported when the UIExtension ability has not registered a synchronous callback.

**Possible Causes**

The component using the ability calls the **sendSync** API to send data to the launched ability before the ability registers a synchronous callback listener.

**Solution**

1. Register a synchronous callback listener in the UIExtension ability.
2. Calls the **sendSync** API from the component using the ability to send data to the launched ability.

## 100012 Data Transfer Failure

**Error Message**

Transferring data failed.

**Description**

This error code is reported when the data transfer fails.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100013 Nesting Not Allowed

**Error Message**

Cascading UIExtension components is not allowed.

**Description**

This error code is reported when illegal nesting of UIExtension components is detected.

**Possible Causes**

There might be nesting between UIExtension components.

**Solution**

Review UIExtension component specifications and avoid component nesting in special scenarios.

## 100014 Ability Exit Error

**Error Message**

The UIExtension ability exited unexpectedly.

**Description**

This error code is reported when the UIExtension ability exits abnormally.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100015 Lifecycle Timeout

**Error Message**

The lifecycle of the UIExtension ability has timed out.

**Description**

This error code is reported when the lifecycle of the UIExtension ability times out.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100016 Key Event Processing Timeout

**Error Message**

Key event processing by the UIExtension ability has timed out.

**Description**

This error code is reported when the UIExtension ability takes too long to process a key event.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100018 Ability Startup Failure (with the onTerminated Callback)

**Error Message**

Failed to start the UIExtension ability.

**Description**

This error code is reported when the UIExtension ability fails to start in a scenario where the **onTerminated** callback is set.

**Possible Causes**

1. The configuration of the **Want** parameter is incorrect.
2. There is a type mismatch.
3. The provider application is not installed.

**Solution**

Verify the configuration of the **Want** parameter and the types, and ensure the application is installed.

## 100019 Failed to Switch the Ability to the Background (with the onTerminated Callback)

**Error Message**

Failed to switch the UIExtension ability to the background.

**Description**

This error code is reported when the UIExtension ability fails to be moved to the background in a scenario where the **onTerminated** callback is set.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100020 Ability Termination Failure (with the onTerminated Callback)

**Error Message**

Failed to destroy the UIExtension ability.

**Description**

This error code is reported when the UIExtension ability fails to be terminated in a scenario where the **onTerminated** callback is set.

**Possible Causes**

Specific analysis is required based on AMS logs.

**Solution**

Analyze the AMS logs to troubleshoot.

## 100021 Transparent Node Detected

**Error Message**

Transparent node is detected in the UIExtension ability.

**Description**

This error code is reported when a transparent node is detected in the UIExtension ability.

**Possible Causes**

A transparent node is detected in the UIExtension ability, which may cause blocking.

**Solution**

Identify and remove transparent nodes.
