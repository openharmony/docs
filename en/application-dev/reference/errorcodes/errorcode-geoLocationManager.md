# Location Subsystem Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 3301000 Location Service Unavailable

**Error Information**

Location service is unavailable.

**Description**

This error code is reported when the location service is unavailable and relevant APIs cannot be called.

**Possible Causes**

1. The location service fails to be started. As a result, the communication between the application and the location service fails, and the location service is unavailable.

2. The GNSS chip fails to be initialized, and thus the GNSS positioning function becomes invalid.

3. The network positioning service is abnormal, and thus the network positioning function becomes invalid.

**Solution**

Stop calling the API.

## 3301100 Location Service Unavailable Because of Switch Toggled Off

**Error Information**

The location switch is off.

**Description**

This error code is reported when the location service is unavailable because the service switch is toggled off.

**Possible Causes**

The location service switch is toggled off, which makes basic functions such as continuous positioning and immediate positioning unavailable.

**Solution**

Display a prompt asking for enabling the location service.

## 3301200 Failed to Obtain the Positioning Result

**Error Information**

Failed to obtain the geographical location.

**Description**

This error code is reported if the location service has failed, leading to a failure to obtain the positioning result.

**Possible Causes**

1. Positioning timed out because of weak GNSS signals.

2. Positioning timed out because the network positioning service is abnormal.

**Solution**

Initiate a positioning request again.

## 3301300 Query Failed During Reverse Geocoding

**Error Information**

Reverse geocoding query failed.

**Description**

This error code is reported if the query during reverse geocoding has failed.

**Possible Causes**

Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Solution**

Perform a query again.

## 3301400 Query Failed During Geocoding

**Error Information**

Geocoding query failed.

**Description**

This error code is reported if the query during geocoding has failed.

**Possible Causes**

Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Solution**

Perform a query again.

## 3301500 Area Information Query Failed

**Error Information**

Failed to query the area information.

**Description**

This error code is reported if the query of the area information (including the country code) has failed.

**Possible Causes**

The correct area information is not found.

**Solution**

Stop calling the API for querying the country code.

## 3301600 Geofence Operation Failed

**Error Information**

Failed to operate the geofence.

**Description**

This error code is reported if a geofence operation, for example, adding, deleting, pausing, or resuming a geofence, has failed.

**Possible Causes**

1. The GNSS chip does not support the geofence function.

2. The bottom-layer service logic is abnormal.

**Solution**

Stop calling the geofence operation API.

## 3301700 No Response to the Request

**Error Information**

No response to the request.

**Description**

This error code is reported if no response is received for an asynchronous request that requires a user to click a button for confirmation or requires a response from the GNSS chip or network server.

**Possible Causes**

1. The user does not click a button as required for confirmation.

2. The GNSS chip does not respond.

3. The network server does not respond.

**Solution**

Stop calling relevant APIs.

## 3301800 Failed to Start Wi-Fi or Bluetooth Scanning

**Error Information**

Failed to start WiFi or Bluetooth scanning.

**Description**

This error code is reported if Wi-Fi or Bluetooth scanning fails to start.

**Possible Causes**

1. The Wi-Fi or Bluetooth service incurs an internal error.

2. Power consumption control is activated because of low battery level.

3. Wi-Fi or Bluetooth is not enabled.

**Solution**

Turn off Wi-Fi or Bluetooth, and then turn it on again.
