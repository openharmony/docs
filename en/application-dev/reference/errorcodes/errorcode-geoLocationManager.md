# Location Subsystem Error Codes

## 3301000 Location Service Unavailable

**Error Message**

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

**Error Message**

The location switch is off.

**Description**

This error code is reported when the location service is unavailable because the service switch is toggled off.

**Possible Causes**

The location service switch is toggled off, which makes basic functions such as continuous positioning and immediate positioning unavailable.

**Solution**

Display a prompt asking for enabling the location service.

## 3301200 Failure to Obtain the Positioning Result

**Error Message**

Failed to obtain the geographical location.

**Description**

This error code is reported when the location service fails, and no positioning result is obtained.

**Possible Causes**

1. Positioning timed out because of weak GNSS signals.

2. Positioning timed out because the network positioning service is abnormal.

**Solution**

Initiate a positioning request again.

## 3301300 Reverse Geocoding Query Failure

**Error Message**

Reverse geocoding query failed.

**Description**

This error code is reported for a reverse geocoding query failure.

**Possible Causes**

Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Solution**

Try the reverse geocoding query again.

## 3301400 Geocoding Query Failure

**Error Message**

Geocoding query failed.

**Description**

This error code is reported for a geocoding query failure.

**Possible Causes**

Network connection is poor, which makes the request fail to be sent from the device or the result fail to be returned from the cloud to the device.

**Solution**

Try the geocoding query again.

## 3301500 Area Information Query Failure

**Error Message**

Failed to query the area information.

**Description**

This error code is reported for the failure to query the area information (including the country code).

**Possible Causes**

The correct area information is not found.

**Solution**

Stop calling the API for querying the country code.

## 3301600 Geofence Operation Failure

**Error Message**

Failed to operate the geofence.

**Description**

This error code is reported when an operation (like adding, deleting, pausing, and resuming) fails to be performed on the geofence.

**Possible Causes**

1. The GNSS chip does not support the geofence function.

2. The bottom-layer service logic is abnormal.

**Solution**

Stop calling the geofence operation API.

## 3301700 No Response to the Request

**Error Message**

No response to the request.

**Description**

This error code is reported when no response is received for an asynchronous request that requires a user to click a button for confirmation or requires a response from the GNSS chip or network server.

**Possible Causes**

1. The user does not click a button as required for confirmation.

2. The GNSS chip does not respond.

3. The network server does not respond.

**Solution**

Stop calling relevant APIs.
