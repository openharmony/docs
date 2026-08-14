# oh_location.h
<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @liu-binjun-->
<!--Designer: @liu-binjun-->
<!--Tester: @mhy123456789-->
<!--Adviser: @RayShih-->

## Overview

Defines APIs for querying the location switch status, and starting and stopping location.

**File to include**: <LocationKit/oh_location.h>

**Library**: liblocation_ndk.so

**System capability**: SystemCapability.Location.Location.Core

**Since**: 13

**Related module**: [Location](capi-location.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [Location_ResultCode OH_Location_IsLocatingEnabled(bool* enabled)](#oh_location_islocatingenabled) | Checks whether the location switch is enabled.|
| [Location_ResultCode OH_Location_StartLocating(const Location_RequestConfig* requestConfig)](#oh_location_startlocating) | Starts the location process and subscribes to location changes.|
| [Location_ResultCode OH_Location_StopLocating(const Location_RequestConfig* requestConfig)](#oh_location_stoplocating) | Stops the location process and unsubscribes from location changes.|

## Function Description

### OH_Location_IsLocatingEnabled()

```c
Location_ResultCode OH_Location_IsLocatingEnabled(bool* enabled)
```

**Description**

Checks whether the location switch is enabled.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| bool* enabled | Pointer of the bool type, which is used to receive the location switch status.<br> If the value is **true**, the location switch is enabled. If the value is **false**, the location switch is disabled.<br> A null pointer is prohibited. If a null pointer is passed in, an error is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode) | Operation result. For details, see [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode).<br>     [LOCATION_SUCCESS](capi-oh-location-type-h.md#location_resultcode) if the location switch status is queried successfully;<br>     [LOCATION_INVALID_PARAM](capi-oh-location-type-h.md#location_resultcode) if the input parameter is a null pointer;<br>     [LOCATION_SERVICE_UNAVAILABLE](capi-oh-location-type-h.md#location_resultcode) if the location service is abnormal.|

### OH_Location_StartLocating()

```c
Location_ResultCode OH_Location_StartLocating(const Location_RequestConfig* requestConfig)
```

**Description**

Starts the location process and subscribes to location changes.

**Required permission**: ohos.permission.APPROXIMATELY_LOCATION

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [const Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the **Location_RequestConfig** instance, which can be created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig). This parameter is used to specify the location scene and location reporting interval.<br> For details, see [Location_RequestConfig](capi-location-location-requestconfig.md).|

**Returns**

| Type| Description|
| -- | -- |
| [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode) | Operation result. For details, see [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode).<br>     [LOCATION_SUCCESS](capi-oh-location-type-h.md#location_resultcode) if the location process is started successfully;<br>     [LOCATION_INVALID_PARAM](capi-oh-location-type-h.md#location_resultcode) if the input **requestConfig** is a null pointer;<br>     [LOCATION_PERMISSION_DENIED](capi-oh-location-type-h.md#location_resultcode) if the permission verification failed;<br>     [LOCATION_NOT_SUPPORTED](capi-oh-location-type-h.md#location_resultcode) if the device does not support this function;<br>     [LOCATION_SERVICE_UNAVAILABLE](capi-oh-location-type-h.md#location_resultcode) if the location service is abnormal;<br>     [LOCATION_SWITCH_OFF](capi-oh-location-type-h.md#location_resultcode) if the location switch is disabled.|

### OH_Location_StopLocating()

```c
Location_ResultCode OH_Location_StopLocating(const Location_RequestConfig* requestConfig)
```

**Description**

Stops the location process and unsubscribes from location changes.

**Required permission**: ohos.permission.APPROXIMATELY_LOCATION

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [const Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the **Location_RequestConfig** instance.<br> The value of this parameter must be the same as the pointer to **requestConfig** in [OH_Location_StartLocating](capi-oh-location-h.md#oh_location_startlocating).<br> For details, see [Location_RequestConfig](capi-location-location-requestconfig.md).<br> A null pointer is prohibited. If a null pointer is passed in, an error is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode) | Operation result. For details, see [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode).<br>     [LOCATION_SUCCESS](capi-oh-location-type-h.md#location_resultcode) if the location process is stopped successfully;<br>     [LOCATION_INVALID_PARAM](capi-oh-location-type-h.md#location_resultcode) if the input parameter is a null pointer,<br>         2. or the input parameter is different from the pointer to **requestConfig** in [OH_Location_StartLocating](capi-oh-location-h.md#oh_location_startlocating);<br>     [LOCATION_PERMISSION_DENIED](capi-oh-location-type-h.md#location_resultcode) if the permission verification failed;<br>     [LOCATION_NOT_SUPPORTED](capi-oh-location-type-h.md#location_resultcode) if the device does not support this function;<br>     [LOCATION_SERVICE_UNAVAILABLE](capi-oh-location-type-h.md#location_resultcode) if the location service is abnormal;<br>     [LOCATION_SWITCH_OFF](capi-oh-location-type-h.md#location_resultcode) if the location switch is disabled.|
