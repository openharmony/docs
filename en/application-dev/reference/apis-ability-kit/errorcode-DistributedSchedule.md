# Distributed Scheduler Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 16600001 The system ability works abnormally.

**Error Message**

The system ability works abnormally.

**Description**

This error code is reported when the system ability is abnormal.

**Possible Causes**

The possible causes are as follows:
1. The DMS service is not started.
2. The **binder** object of DMS is not obtained.
3. Other services on which ability continuation depends are not started or the **binder** object is not obtained.

**Solution**

Try again later or restart the device.

## 16600002 The specified token or callback is not registered.

**Error Message**

The specified token or callback is not registered.

**Description**

This error code is reported if the token or callback used in an API of **continuationManager** is not registered when the API is called.

**Possible Causes**

The specified token or callback is not registered.

**Solution**

Register the token or callback before calling the API.

## 16600003 The number of token registration times has reached the upper limit.

**Error Message**

The number of token registration times has reached the upper limit.

**Description**

This error code is reported when the number of times that the **continuationManager.registerContinuation** API is called has reached the upper limit.

**Possible Causes**

The number of token registration times has reached the upper limit.

**Solution**

Use a registered token. Do not register the token too frequently.

## 16600004 The specified callback has been registered.

**Error Message**

The specified callback has been registered.

**Description**

This error code is reported when the **continuationManager.on** API is called with a callback the same as a previous one.

**Possible Causes**

The same callback is used for repeated registration.

**Solution**

Use a different callback for registration.

## 16300501 The system ability works abnormally.

**Error Message**

The system ability works abnormally.

**Description**

This error code is reported when the system ability is abnormal.

**Possible Causes**

The possible causes are as follows:
1. The DMS service is not started.
2. The **binder** object of DMS is not obtained.
3. Other services on which ability continuation depends are not started or the **binder** object is not obtained.

**Solution**

Try again later or restart the device.

## 16300502 Failed to get the missionInfo of the specified missionId.

**Error Message**

Failed to get the missionInfo of the specified missionId.

**Description**

This error code is reported when calling the **distributedMissionManager.continueMission** API fails.

**Possible Causes**

The possible causes are as follows:
1. An incorrect mission ID is passed in.
2. The mission information corresponding to the mission ID does not exist.

**Solution**

Verify the mission ID.

## 16300503 The application is not installed on the remote end and installation-free is not supported.

**Error Message**

The application is not installed on the remote end and installation-free is not supported.

**Description**

This error code is reported if the application is not installed on the remote end and the installation-free feature is not supported when the **distributedMissionManager.continueMission** API is called.

**Possible Causes**

The application to continue is not installed on the remote end, and the installation-free feature is not supported.

**Solution**

1. Check whether the application has been installed on the remote end.
2. Check whether the remote end supports installation-free.

## 16300504 The application is not installed on the remote end and installation-free is supported. Try again with the freeInstall flag.

**Error Message**

The application is not installed on the remote end and installation-free is supported. Try again with the freeInstall flag.

**Description**

This error code is reported if the application is not installed on the remote end and installation-free is supported when the **distributedMissionManager.continueMission** API is called.

**Possible Causes**

The application to continue is not installed on the remote end, and installation-free is supported. However, the **freeInstall** flag is not carried.

**Solution**

Try again with the **freeInstall** flag.

## 16300505 The operation device must be the device where the application to be continued is currently located or the target device.

**Error Message**

The operation device must be the device where the application to be continued is currently located or the target device.

**Description**

This error code is reported if the operation device is not the device where the application to be continued is currently located (source device) or the target device when the **distributedMissionManager.continueMission** API is called.

**Possible Causes**

The operation device is not the source or target device.

**Solution**

Use the source or target device for the operation.

## 16300506 The local continuation task is already in progress.

**Error Message**

The local continuation task is already in progress.

**Description**

This error code is reported if the local continuation task is in progress when the **distributedMissionManager.continueMission** API is called.

**Possible Causes**

The continuation task has been initiated and is not complete yet.

**Solution**

Wait until the continuation task is complete.

## 16300507 Failed to get the missionInfo of the specified bundleName.

**Error Message**

Failed to get the missionInfo of the specified bundle name.

**Description**

This error code is reported when calling the **distributedMissionManager.continueMission** API with **bundleName** specified fails.

**Possible Causes**

The possible causes are as follows:
1. An incorrect bundle name is passed in.
2. The mission information corresponding to the bundle name does not exist.

**Solution**

Verify the bundle name.

## 3 Failed to flatten the object.

**Error Message**

Failed to flatten the object.

**Description**

This error code is reported if the system parameter **DMS_PROXY_INTERFACE_TOKEN** fails flattening when an API of **continuationManager** is called.

**Possible Causes**

The system parameter **DMS_PROXY_INTERFACE_TOKEN** fails to be written in serialization.

**Solution**

Make sure the system functions properly. Restart the system when needed.

## 7 The object is null.

**Error Message**

The object is null.

**Description**

This error code is reported if DMS and other objects are empty or reading in serialization fails when an API of **continuationManager** is called.

**Possible Causes**

The possible causes are as follows:
1. Reading the input parameters in serialization fails.
2. The DMS service is not started or the **binder** object is not obtained.
3. Other services on which DMS depends are not started or the **binder** object is not obtained.

**Solution**

1. Check whether the input parameters are valid.
2. Check whether the DMS service is started normally. Restart the service or device when needed.
3. Check whether other services on which DMS depends are started normally. Restart the services or device when needed.

## 29360207 The number of registrations has reached the upper limit.

**Error Message**

The number of registrations has reached the upper limit.

**Description**

This error code is reported when the number of times that the **continuationManager.register** API is called exceeds the upper limit.

**Possible Causes**

The number of device registration times has reached the upper limit.

**Solution**

Restart the service and avoid frequent registration.

## 29360208 The token is not registered.

**Error Message**

The token is not registered.

**Description**

This error code is reported when an API of **continuationManager** is called with an unregistered token.

**Possible Causes**

The token is not registered.

**Solution**

Register a token and use it in the API.

## 29360209 The callback has been registered.

**Error Message**

The callback has been registered.

**Description**

This error code is reported when the **continuationManager.on** API is called with a callback the same as a previous one.

**Possible Causes**

The specified callback has been registered.

**Solution**

Do not use the same callback for repeated registration.

## 29360210 The callback is not registered.

**Error Message**

The callback is not registered.

**Description**

This error code is reported when the **off**, **updateConnectStatus**, or **startDeviceManager** API of **continuationManager** is called with a callback that has been not registered by calling **on**.

**Possible Causes**

The specified callback is not registered.

**Solution**

Register a callback and use it in the API.

## 29360211 Failed to connect to the ability.

**Error Message**

Failed to connect to the ability.

**Description**

This error code is reported if connection to the specified ability fails when the **startDeviceManager** API of **continuationManager** is called.

**Possible Causes**

The specified token is invalid or the target ability is not working properly.

**Solution**

Check whether the token is valid and whether the corresponding ability is normal. Restart the service or device when needed.

## 29360214 The type of callback is not supported.

**Error Message**

The type of callback is not supported.

**Description**

This error code is reported when the **callback** parameter in the **on** or **off** API of **continuationManager** is set to an incorrect type.

**Possible Causes**

The callback type is not supported.

**Solution**

Pass a supported type for the **callback** parameter.

## 29360215 Invalid connection state.

**Error Message**

Invalid connection state.

**Description**

This error code is reported when the **status** parameter in the **updateConnectStatus** API of **continuationManager** is invalid.

**Possible Causes**

The **status** parameter is invalid.

**Solution**

Use a valid value for the **status** parameter.

## 29360216 Invalid continuation mode.

**Error Message**

Invalid continuation mode.

**Description**

This error code is reported when the **ContinuationExtraParams.continuationMode** parameter in the **register** or **startDeviceManager** API of **continuationManager** is invalid.

**Possible Causes**

The **ContinuationExtraParams.continuationMode** parameter is invalid.

**Solution**

Use a valid value for the **ContinuationExtraParams.continuationMode** parameter.
