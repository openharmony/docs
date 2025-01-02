# Location Kit Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 3301000 Location Service Unavailable

**Error Message**

The location service is unavailable.

**Description**

This error code is reported if the location service is unavailable and relevant APIs cannot be called.

**Possible Cause**

1. The location service fails to be started, leading to a communication failure between the application and the location service.

2. The GNSS chip fails to be initialized, leading to a GNSS positioning failure.

3. The network positioning service is abnormal, leading to a network positioning failure.

**Procedure**

Stop calling the API.

## 3301100 Positioning Failed Due to Location Service Switch Turning-off

**Error Message**

The location switch is off.

**Description**

This error code is reported if positioning fails because the location service switch is turned off.

**Possible Cause**

The location service switch is turned off, which makes basic functions such as continuous positioning and immediate positioning unavailable.

**Procedure**

Display a prompt asking for enabling the location service.

## 3301200 Failed to Obtain the Positioning Result

**Error Message**

Failed to obtain the geographical location.

**Description**

This error code is reported if the location service fails, leading to a failure to obtain the positioning result.

**Possible Cause**

1. Positioning times out because of weak GNSS signals.

2. Positioning times out because the network positioning service is abnormal.

3. Positioning times out because the positioning result does not meet the requirement of **maxAccuracy**.

4. The application fails to obtain the previous location because the system does not cache the location information.

5. The system time is incorrectly set.

**Procedure**

1. Move to an open area and try again.

2. Check the device for Internet or Wi-Fi connectivity and an installed SIM card.

3. Check whether the **maxAccuracy** field in the location request is properly set.

4. Use **getCurrentLocation** to obtain the real-time location if no location information is cached in the system.

5. Enable automatic setting on the **Time & Date** page.


## 3301300 Query Failed During Reverse Geocoding

**Error Message**

Reverse geocoding query failed.

**Description**

This error code is reported if the query during reverse geocoding has failed.

**Possible Cause**

- Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

- The x86 emulator does not support the reverse geocoding function. A reverse geocoding query fails if the x86 emulator is used for debugging.

**Procedure**

- For the network problem, try the reverse geocoding query again after the network is resumed.

- For the x86 emulator problem, try the reverse geocoding query again on a real device.

## 3301400 Query Failed During Geocoding

**Error Message**

Geocoding query failed.

**Description**

This error code is reported if the query during geocoding has failed.

**Possible Cause**

1. A certain request parameter is incorrect, or no result can be found based on the parameter.<br>
2. Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Procedure**

Check the request parameters or network status and try again.

## 3301500 Area Information Query Failed

**Error Message**

Failed to query the area information.

**Description**

This error code is reported if the query of the area information (including the country code) has failed.

**Possible Cause**

The correct area information is not found.

**Procedure**

Stop calling the API for querying the country code.

## 3301600 Geofence Operation Failed

**Error Message**

Failed to operate the geofence.

**Description**

This error code is reported if a geofence operation, for example, adding, deleting, pausing, or resuming a geofence, has failed.

**Possible Cause**

1. The GNSS chip does not support the geofence function.

2. The bottom-layer service logic is abnormal.

**Procedure**

Stop calling the geofence operation API.

## 3301601 Failed to Add a Geofence Due to a Limit on the Maximum Number

**Error Message**

The number of geofences exceeds the maximum.

**Description**

This error code is reported if the attempt to add a geofence fails because the number of geofences exceeds the maximum.

**Possible Cause**

The number of geofences has reached the maximum.

**Procedure**

Delete unnecessary geofences before adding new ones.

## 3301602 Failed to Delete a Geofence Due to an Incorrect ID

**Error Message**

Failed to delete a geofence due to an incorrect ID.

**Description**

The ID of the geofence to be deleted is incorrect.

**Possible Cause**

The geofence ID passed to the geofence deletion API is incorrect.

**Procedure**

Pass a correct geofence ID to the geofence deletion API.

## 3301700 No Response to the Request

**Error Message**

No response to the request.

**Description**

This error code is reported if no response is received for an asynchronous request that requires a user to click a button for confirmation or requires a response from the GNSS chip or network server.

**Possible Cause**

1. The user does not click a button as required for confirmation.

2. The GNSS chip does not respond.

3. The network server does not respond.

**Procedure**

Stop calling relevant APIs.

## 3301800 Failed to Start Wi-Fi or Bluetooth Scanning

**Error Message**

Failed to start Wi-Fi or Bluetooth scanning.

**Description**

This error code is reported if Wi-Fi or Bluetooth scanning fails to start.

**Possible Cause**

1. The Wi-Fi or Bluetooth service incurs an internal error.

2. Power consumption control is activated because of low battery level.

3. Wi-Fi or Bluetooth is disabled.

**Procedure**

Disable and then enable Wi-Fi or Bluetooth.

## 3301900 Failed to Obtain the MAC Address of the Wi-Fi Hotspot

**Error Message**

Failed to obtain the hotpot MAC address because the Wi-Fi is not connected.

**Description**

This error code is reported if the attempt to obtain the MAC address of the Wi-Fi hotspot or router fails because the device is not connected to the Wi-Fi hotspot or router.

**Possible Cause**

1. Wi-Fi is disabled.

2. Wi-Fi is enabled, but the device is not connected to a Wi-Fi hotspot or router.

**Procedure**

1. Enable Wi-Fi.

2. Connect to a router or Wi-Fi hotspot.
