# Location Kit Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 3301000 Location Service Unavailable

**Error Information**

The location service is unavailable.

**Description**

This error code is reported when the location service is unavailable and relevant APIs cannot be called.

**Possible Causes**

1. The location service fails to be started. As a result, the communication between the application and the location service fails, and the location service is unavailable.

2. The GNSS chip fails to be initialized, and thus the GNSS positioning function becomes invalid.

3. The network positioning service is abnormal, and thus the network positioning function becomes invalid.

**Solution**

Add a retry mechanism.

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

The network locating is failed because the network cannot be accessed.

**Description**

This error code is reported if network positioning fails because network access is denied.

**Solution**

Check the device for Internet or Wi-Fi connectivity and an installed SIM card.<br>
</br>

**Error Information**

The positioning result does not meet the precision requirement (maxAccuracy) in the positioning request parameters.

**Description**

This error code is reported if positioning times out because the positioning result does not meet the requirement of **maxAccuracy**.

**Solution**

Increase the value of **maxAccuracy** for [LocationRequest](./js-apis-geoLocationManager.md#locationrequest) and [CurrentLocationRequest](./js-apis-geoLocationManager.md#currentlocationrequest) as follows:

- If [scenario](./js-apis-geoLocationManager.md#locationrequestscenario) is set to **NAVIGATION**, **TRAJECTORY_TRACKING** or **CAR_HAILING**, or [priority](./js-apis-geoLocationManager.md#locationrequestpriority) is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.

- If [scenario](./js-apis-geoLocationManager.md#locationrequestscenario) is set to **DAILY_LIFE_SERVICE** or **NO_POWER**, or [priority](./js-apis-geoLocationManager.md#locationrequestpriority) is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.<br>

**Error Information**

The system does not have a cache location.

**Description**

This error code is reported if the application fails to obtain the previous location because the system has not cached the location information.

**Solution**

If the system has not cached the location information, call [getCurrentLocation](./js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation) to obtain the real-time location information.<br>
</br>

**Error Information**

Failed to obtain the geographical location.

**Description**

This error code is reported if the location service has failed, leading to a failure to obtain the positioning result.

**Possible Causes**

1. Positioning timed out because of weak GNSS signals.

2. The system time is incorrectly set.

**Solution**

1. Move to an open area and try again.

2. Enable automatic setting on the **Time & Date** page.


## 3301300 Query Failed During Reverse Geocoding

**Error Information**

Reverse geocoding query failed.

**Description**

This error code is reported if the query during reverse geocoding has failed.

**Possible Causes**

- Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

- The x86 emulator does not support the reverse geocoding function. A reverse geocoding query fails if the x86 emulator is used for debugging.

**Solution**

- For the network problem, try the reverse geocoding query again after the network is resumed.

- For the x86 emulator problem, try the reverse geocoding query again on a real device.

## 3301400 Query Failed During Geocoding

**Error Information**

Geocoding query failed.

**Description**

This error code is reported if the query during geocoding has failed.

**Possible Causes**

- A certain request parameter is incorrect, or no result can be found based on the parameter.<br>

- Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Solution**

Check the request parameters or network status and try again.

## 3301500 Area Information Query Failed

**Error Information**

Failed to query the area information.

**Description**

This error code is reported if the query of the area information (including the country code) has failed.

**Possible Causes**

The correct area information is not found.

**Solution**

Add a retry mechanism.

## 3301600 Geofence Operation Failed

**Error Information**

Failed to operate the geofence.

**Description**

This error code is reported if a geofence operation, for example, adding, deleting, pausing, or resuming a geofence, has failed.

**Possible Causes**

1. The GNSS chip does not support the geofence function.

2. The bottom-layer service logic is abnormal.

**Solution**

1. Add the SysCap verification mechanism.

2. Add a retry mechanism.

## 3301601 Failed to Add a Geofence Due to a Limit on the Maximum Number

**Error Information**

The number of geofences exceeds the maximum.

**Description**

This error code is reported if the attempt to add a geofence fails because the number of geofences exceeds the maximum.

**Possible Causes**

The number of geofences has reached the maximum (that is, 1,000).

**Solution**

Delete unnecessary geofences before adding new ones.

## 3301602 Failed to Delete a Geofence Due to an Incorrect ID

**Error Information**

Failed to delete a geofence due to an incorrect ID.

**Description**

The ID of the geofence to be deleted is incorrect.

**Possible Causes**

The geofence ID passed to the geofence deletion API is incorrect.

**Solution**

Pass a correct geofence ID to the geofence deletion API.

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

Add a retry mechanism.

## 3301800 Failed to Start Wi-Fi or Bluetooth Scanning

**Error Information**

Failed to start Wi-Fi or Bluetooth scanning.

**Description**

This error code is reported if Wi-Fi or Bluetooth scanning fails to start.

**Possible Causes**

1. The Wi-Fi or Bluetooth service incurs an internal error.

2. Power consumption control is activated because of low battery level.

3. Wi-Fi or Bluetooth is disabled.

**Solution**

Disable and then enable Wi-Fi or Bluetooth.

## 3301900 Failed to Obtain the MAC Address of the Wi-Fi Hotspot

**Error Information**

Failed to obtain the hotspot MAC address because the Wi-Fi is not connected.

**Description**

This error code is reported if the attempt to obtain the MAC address of the Wi-Fi hotspot or router fails because the device is not connected to the Wi-Fi hotspot or router.

**Possible Causes**

1. Wi-Fi is disabled.

2. Wi-Fi is enabled, but the device is not connected to a Wi-Fi hotspot or router.

**Solution**

1. Enable Wi-Fi.

2. Connect to a router or Wi-Fi hotspot.
