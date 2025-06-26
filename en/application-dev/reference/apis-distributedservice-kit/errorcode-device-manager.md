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

The previous authentication service is still in progress.

**Solution**

Wait until the previous authentication service is complete and call the authentication API again.

## 11600104 Discovery Unavailable

**Error Message**

Discovery unavailable.

**Possible Causes**

The previous discovery service is still in progress.

**Solution**

Wait until the previous discovery service is complete and call the discovery API again.

## 11600105 Publish Unavailable

**Error Message**

Publish unavailable.

**Possible Causes**

The previous publish service is still in progress.

**Solution**

Wait until the previous publish service is complete and call the publish API again.

## 11600106 Failed to Obtain Data from the Cloud

**Error Message**

Failed to get data from the cloud.

**Possible Causes**

The network connection is abnormal, or the network request returns an error.

**Solution**

Ensure that the network connection is normal and call the API again with correct parameters.

## 11600107 Login Account Required

**Error Message**

A login account is required.

**Possible Causes**

No login account is available on the device.

**Solution**

Use the correct account to log in to the device and call the API again.

## 11600108 Unlawful Information in Device Name

**Error Message**

The device name contains non-compliant content.

**Possible Causes**

The new device name contains unlawful information.

**Solution**

Ensure that the device name complies with laws and regulations.

## 32300001 Transport Stream Repeatedly Created

**Error Message**

Only one stream can be created for the current session.

**Possible Causes**

This error code is reported if a session for which a transport stream is created already has a transport stream.

**Solution**

Ensure that the task of the previous transport stream is complete. Use **destroyStream** to close the transport stream before creating a new one.

## 32300002 Stream Receive End Not Started

**Error Message**

The stream at the receive end is not started.

**Possible Causes**

This error code is reported if the receive end is not started before

**Solution**

the transmission of transport streams begins.

## 32300003 Bit Rate Not Supported

**Error Message**

Bitrate not supported.

**Possible Causes**

This error code is reported if the configured bit rate does not match the bit rate supported by the device.

**Solution**

Select an appropriate bit rate based on network conditions and requirements.

## 32300004 Color Space Not Supported

**Error Message**

Color space not supported.

**Possible Causes**

This error code is reported if the color space output type is set to **OH_COLORSPACE_BT2020_HLG_LIMIT** but the actual output type is not the specified type.

**Solution**

Ensure that the color space output type is within the supported range.
