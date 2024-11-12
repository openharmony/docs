# Sensor


## Overview

The **Sensor** module provides APIs to manipulate sensors. For example, you can call APIs to obtain sensor information and subscribe to or unsubscribe from sensor data.

It also provides APIs to define common sensor attributes.

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_sensor.h](oh_sensor_8h.md) | Declares the APIs for operating sensors, including obtaining sensor information and subscribing to and unsubscribing from sensor data. |
| [oh_sensor_type.h](oh_sensor_type_8h.md) | Declares the common sensor attributes. |


### Types

| Name| Description|
| -------- | -------- |
| [Sensor_Type](#sensor_type) | Defines an enum for sensor types. |
| [Sensor_Result](#sensor_result) | Defines an enum for sensor result codes. |
| [Sensor_Accuracy](#sensor_accuracy) | Defines an enum for accuracy levels of data reported by a sensor.|
| [Sensor_Info](#sensor_info) | Defines a struct for the sensor information. |
| [Sensor_Event](#sensor_event) | Defines a struct for the sensor data information. |
| [Sensor_SubscriptionId](#sensor_subscriptionid) | Defines a struct for the sensor subscription ID, which uniquely identifies a sensor. |
| [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) | Defines a struct for the sensor subscription attribute.|
| void ([*Sensor_EventCallback](#sensor_eventcallback)) ([Sensor_Event](#sensor_event) \*event) | Defines the callback function used to report sensor data.|
| [Sensor_Subscriber](#sensor_subscriber) | Defines a struct for the sensor subscriber information. |


### Enums

| Name| Description|
| -------- | -------- |
| [Sensor_Type](#sensor_type) {<br>SENSOR_TYPE_ACCELEROMETER = 1, <br>SENSOR_TYPE_GYROSCOPE = 2,<br> SENSOR_TYPE_AMBIENT_LIGHT = 5, <br>SENSOR_TYPE_MAGNETIC_FIELD = 6,<br>SENSOR_TYPE_BAROMETER = 8,<br> SENSOR_TYPE_HALL = 10, <br>SENSOR_TYPE_PROXIMITY = 12,<br> SENSOR_TYPE_ORIENTATION = 256,<br>SENSOR_TYPE_GRAVITY = 257, <br>SENSOR_TYPE_LINEAR_ACCELERATION = 258,<br>SENSOR_TYPE_ROTATION_VECTOR = 259,<br>SENSOR_TYPE_GAME_ROTATION_VECTOR = 262,<br>SENSOR_TYPE_PEDOMETER_DETECTION = 265,<br> SENSOR_TYPE_PEDOMETER = 266,<br>SENSOR_TYPE_HEART_RATE = 278<br>} | Enumerates the sensor types. |
| [Sensor_Result](#sensor_result) { <br>SENSOR_SUCCESS = 0,<br> SENSOR_PERMISSION_DENIED = 201, <br>SENSOR_PARAMETER_ERROR = 401,<br> SENSOR_SERVICE_EXCEPTION = 14500101<br> } | Enumerates the sensor result codes. |
| [Sensor_Accuracy](#sensor_accuracy) { <br>SENSOR_ACCURACY_UNRELIABLE = 0, <br>SENSOR_ACCURACY_LOW = 1,<br> SENSOR_ACCURACY_MEDIUM = 2, <br>SENSOR_ACCURACY_HIGH = 3 <br>} | Defines an enum for accuracy levels of data reported by a sensor.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Sensor_GetInfos](#oh_sensor_getinfos)([Sensor_Info](#sensor_info) **infos, uint32_t *count) | Obtains information about all sensors on the device.                                |
| [OH_Sensor_Subscribe](#oh_sensor_subscribe)(const [Sensor_SubscriptionId](#sensor_subscriptionid) *id, const [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) *attribute, const [Sensor_Subscriber](#sensor_subscriber) *subscriber) | Subscribe to sensor data. The system will report sensor data to the subscriber at the specified frequency.<br>To subscribe to data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To subscribe to data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To subscribe to data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To subscribe to data of health-related sensors, such as heart rate sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the subscription fails.<br>You do not need to request any permission to subscribe to data of other types of sensors.|
| [OH_Sensor_Unsubscribe](#oh_sensor_unsubscribe)(const [Sensor_SubscriptionId](#sensor_subscriptionid) *id, const [Sensor_Subscriber](#sensor_subscriber) *subscriber) | Unsubscribes from sensor data.<br>To unsubscribe from data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To unsubscribe from data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To unsubscribe from data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To unsubscribe from data of health-related sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the unsubscription fails.<br>You do not need to request any permission to unsubscribe from data of other types of sensors.|
| [OH_Sensor_CreateInfos](#oh_sensor_createinfos)(uint32_t count) | Creates an array of [Sensor_Info](#sensor_info) instances with the given number.|
| [OH_Sensor_DestroyInfos](#oh_sensor_destroyinfos)([Sensor_Info](#sensor_info) **sensors, uint32_t count) | Destroys an array of [Sensor_Info](#sensor_info) instances and reclaims memory.|
| [OH_SensorInfo_GetName](#oh_sensorinfo_getname)([Sensor_Info](#sensor_info) *sensor, char *sensorName, uint32_t *length) | Obtains the sensor name. |
| [OH_SensorInfo_GetVendorName](#oh_sensorinfo_getvendorname)([Sensor_Info](#sensor_info)* sensor, char *vendorName, uint32_t *length) | Obtains the sensor's vendor name. |
| [OH_SensorInfo_GetType](#oh_sensorinfo_gettype)([Sensor_Info](#sensor_info)* sensor, [Sensor_Type](#sensor_type) *sensorType) | Obtains the sensor type. |
| [OH_SensorInfo_GetResolution](#oh_sensorinfo_getresolution)([Sensor_Info](#sensor_info)* sensor, float *resolution) | Obtains the sensor resolution.                                          |
| [OH_SensorInfo_GetMinSamplingInterval](#oh_sensorinfo_getminsamplinginterval)([Sensor_Info](#sensor_info)* sensor, int64_t *minSamplingInterval) | Obtains the minimum data reporting interval of a sensor. |
| [OH_SensorInfo_GetMaxSamplingInterval](#oh_sensorinfo_getmaxsamplinginterval)([Sensor_Info](#sensor_info)* sensor, int64_t *maxSamplingInterval) | Obtains the maximum data reporting interval of a sensor. |
| [OH_SensorEvent_GetType](#oh_sensorevent_gettype)([Sensor_Event](#sensor_event)* sensorEvent, [Sensor_Type](#sensor_type) *sensorType) | Obtains the sensor type. |
| [OH_SensorEvent_GetTimestamp](#oh_sensorevent_gettimestamp)([Sensor_Event](#sensor_event)* sensorEvent, int64_t *timestamp) | Obtains the timestamp of sensor data.                                    |
| [OH_SensorEvent_GetAccuracy](#oh_sensorevent_getaccuracy)([Sensor_Event](#sensor_event)* sensorEvent, Sensor_Accuracy *accuracy) | Obtains the accuracy of sensor data.                                      |
| [OH_SensorEvent_GetData](#oh_sensorevent_getdata)([Sensor_Event](#sensor_event)* sensorEvent, float **data, uint32_t *length) | Obtains sensor data.<br>The data length and content depend on the sensor type. The format of the sensor data reported is as follows:<br>- SENSOR_TYPE_ACCELEROMETER: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_GYROSCOPE: data[0], data[1], and data[2], indicating the angular velocity of rotation around the x, y, and z axes of a device, respectively, in rad/s.<br>- SENSOR_TYPE_AMBIENT_LIGHT: data[0], indicating the ambient light intensity, in lux. Since API version 12, two extra data records are returned, where **data[1]** indicates the color temperature (in kelvin), and **data[2]** indicates the infrared luminance (in cd/m²).<br>4. - SENSOR_TYPE_MAGNETIC_FIELD: data[0], data[1], and data[2], indicating the magnetic field strength around the x, y, and z axes of a device, respectively, in μT.<br>- SENSOR_TYPE_BAROMETER: data[0], indicating the atmospheric pressure, in hPa.<br>- SENSOR_TYPE_HALL: data[0], indicating the opening/closing state of the flip cover. The value **0** means that the flip cover is opened, and a value greater than 0 means that the flip cover is closed.<br>- SENSOR_TYPE_PROXIMITY: data[0], indicates the approaching state. The value **0** means the two objects are close to each other, and a value greater than 0 means that they are far away from each other.<br>- SENSOR_TYPE_ORIENTATION: data[0], data[1], and data[2], indicating the rotation angles of a device around the z, x, and y axes, respectively, in degree.<br>- SENSOR_TYPE_GRAVITY: data[0], data[1], and data[2], indicating the gravitational acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree. data[3] indicates the rotation vector.<br>- SENSOR_TYPE_PEDOMETER_DETECTION: data[0], indicating the pedometer detection status. The value **1** means that the number of detected steps changes.<br>- SENSOR_TYPE_PEDOMETER: data[0], indicating the number of steps a user has walked.<br>- SENSOR_TYPE_HEART_RATE: data[0], indicating the heart rate value.<br>- SENSOR_TYPE_LINEAR_ACCELERATION: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s². This parameter is supported since API version 13.<br>- SENSOR_TYPE_GAME_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree; data[3], indicating the rotation vector. This parameter is supported since API version 13.|
| [OH_Sensor_CreateSubscriptionId](#oh_sensor_createsubscriptionid)(void) | Creates a [Sensor_SubscriptionId](#sensor_subscriptionid) instance.|
| [OH_Sensor_DestroySubscriptionId](#oh_sensor_destroysubscriptionid)([Sensor_SubscriptionId](#sensor_subscriptionid) *id) | Destroys a [Sensor_SubscriptionId](#sensor_subscriptionid) instance and reclaims memory.|
| [OH_SensorSubscriptionId_GetType](#oh_sensorsubscriptionid_gettype)([Sensor_SubscriptionId](#sensor_subscriptionid) *id, [Sensor_Type](#sensor_type) *sensorType) | Obtains the sensor type. |
| [OH_SensorSubscriptionId_SetType](#oh_sensorsubscriptionid_settype)([Sensor_SubscriptionId](#sensor_subscriptionid)* id, const [Sensor_Type](#sensor_type) sensorType) | Sets the sensor type. |
| [OH_Sensor_CreateSubscriptionAttribute](#oh_sensor_createsubscriptionattribute)(void) | Creates a [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instance.|
| [OH_Sensor_DestroySubscriptionAttribute](#oh_sensor_destroysubscriptionattribute)([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) *attribute) | Destroys a [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instance and reclaims memory.|
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](#oh_sensorsubscriptionattribute_setsamplinginterval)([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)* attribute, const int64_t samplingInterval) | Sets the interval for reporting sensor data.                                 |
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](#sensor_subscriptionattribute)* attribute, int64_t *samplingInterval) | Obtains the interval for reporting sensor data.                                  |
| [OH_Sensor_CreateSubscriber](#oh_sensor_createsubscriber)(void) | Creates a [Sensor_Subscriber](#sensor_subscriber) instance.     |
| [OH_Sensor_DestroySubscriber](#oh_sensor_destroysubscriber)([Sensor_Subscriber](#sensor_subscriber) *subscriber) | Destroys a [Sensor_Subscriber](#sensor_subscriber) instance and reclaims memory.|
| [OH_SensorSubscriber_SetCallback](#oh_sensorsubscriber_setcallback)([Sensor_Subscriber](#sensor_subscriber)* subscriber, const [Sensor_EventCallback](#sensor_eventcallback) callback) | Sets a callback function to report sensor data.|
| [OH_SensorSubscriber_GetCallback](#oh_sensorsubscriber_getcallback)([Sensor_Subscriber](#sensor_subscriber)* subscriber, [Sensor_EventCallback](#sensor_eventcallback) *callback) | Obtains the callback function used to report sensor data.|


## Type Description


### Sensor_Accuracy

```
typedef enum Sensor_Accuracy Sensor_Accuracy
```
**Description**

Defines an enum for accuracy levels of data reported by a sensor.

**Since**: 11


### Sensor_Event

```
typedef struct Sensor_Event Sensor_Event
```
**Description**

Defines a struct for the sensor data information.

**Since**: 11


### Sensor_EventCallback

```
typedef void(*Sensor_EventCallback)(Sensor_Event *event)
```
**Description**

Defines the callback function used to report sensor data.

**Since**: 11


### Sensor_Info

```
typedef struct Sensor_Info Sensor_Info
```
**Description**

Defines a struct for the sensor information.

**Since**: 11


### Sensor_Result

```
typedef enum Sensor_Result Sensor_Result
```
**Description**

Defines an enum for sensor result codes.

**Since**: 11


### Sensor_Subscriber

```
typedef struct Sensor_Subscriber Sensor_Subscriber
```
**Description**

Defines a struct the sensor subscriber information.

**Since**: 11


### Sensor_SubscriptionAttribute

```
typedef struct Sensor_SubscriptionAttribute Sensor_SubscriptionAttribute
```
**Description**

Defines a struct for the sensor subscription attribute.

**Since**: 11


### Sensor_SubscriptionId

```
typedef struct Sensor_SubscriptionId Sensor_SubscriptionId
```
**Description**

Defines a struct for the sensor subscription ID, which uniquely identifies a sensor.

**Since**: 11


### Sensor_Type

```
typedef enum Sensor_Type Sensor_Type
```
**Description**

Defines an enum for sensor types.

**Since**: 11


## Enum Description


### Sensor_Accuracy

```
enum Sensor_Accuracy
```
**Description**

Defines an enum for accuracy levels of data reported by a sensor.

**Since**: 11

| Value| Description|
| -------- | -------- |
| SENSOR_ACCURACY_UNRELIABLE  | The sensor data is unreliable. It is possible that the sensor does not contact with the device to measure.|
| SENSOR_ACCURACY_LOW  | The sensor data is at a low accuracy level. The data must be calibrated based on the environment before being used.|
| SENSOR_ACCURACY_MEDIUM  | The sensor data is at a medium accuracy level. You are advised to calibrate the data based on the environment before using it.|
| SENSOR_ACCURACY_HIGH  | The sensor data is at a high accuracy level. The data can be used directly.|


### Sensor_Result

```
enum Sensor_Result
```
**Description**

Defines an enum for sensor result codes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| SENSOR_SUCCESS  | The operation is successful.|
| SENSOR_PERMISSION_DENIED  | Permission verification failed.|
| SENSOR_PARAMETER_ERROR  | Parameter check failed. For example, a mandatory parameter is not passed in, or the parameter type passed in is incorrect.|
| SENSOR_SERVICE_EXCEPTION  | The sensor service is abnormal.|


### Sensor_Type

```
enum Sensor_Type
```
**Description**

Defines an enum for sensor types.

**Since**: 11

| Value| Description|
| -------- | -------- |
| SENSOR_TYPE_ACCELEROMETER  | Acceleration sensor.|
| SENSOR_TYPE_GYROSCOPE  | Gyroscope sensor.|
| SENSOR_TYPE_AMBIENT_LIGHT  | Ambient light sensor.|
| SENSOR_TYPE_MAGNETIC_FIELD  | Magnetic field sensor.|
| SENSOR_TYPE_BAROMETER  | Barometer sensor|
| SENSOR_TYPE_HALL  | Hall effect sensor.|
| SENSOR_TYPE_PROXIMITY  | Proximity sensor.|
| SENSOR_TYPE_ORIENTATION  | Orientation sensor.|
| SENSOR_TYPE_GRAVITY  | Gravity sensor.|
| SENSOR_TYPE_ROTATION_VECTOR  | Rotation vector sensor.|
| SENSOR_TYPE_PEDOMETER_DETECTION  | Pedometer detection sensor.|
| SENSOR_TYPE_PEDOMETER  | Pedometer sensor.|
| SENSOR_TYPE_HEART_RATE  | Heart rate sensor.|


## Function Description


### OH_Sensor_CreateInfos()

```
Sensor_Info **OH_Sensor_CreateInfos(uint32_t count)
```
**Description**

Creates an array of [Sensor_Info](#sensor_info) instances with the given number.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| count | Number of [Sensor_Info](#sensor_info) instances to create.|

**Returns**

Returns the double pointer to the array of [Sensor_Info](#sensor_info) instances if the operation is successful; returns **NULL** otherwise.


### OH_Sensor_CreateSubscriber()

```
Sensor_Subscriber *OH_Sensor_CreateSubscriber(void)
```
**Description**

Creates a [Sensor_Subscriber](#sensor_subscriber) instance.

**Since**: 11

**Returns**

Returns the pointer to the [Sensor_Subscriber](#sensor_subscriber) instances if the operation is successful; returns **NULL** otherwise.


### OH_Sensor_CreateSubscriptionAttribute()

```
Sensor_SubscriptionAttribute *OH_Sensor_CreateSubscriptionAttribute(void)
```
**Description**

Creates a [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instance.

**Since**: 11

**Returns**

Returns the pointer to the [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instances if the operation is successful; returns **NULL** otherwise.


### OH_Sensor_CreateSubscriptionId()

```
Sensor_SubscriptionId *OH_Sensor_CreateSubscriptionId(void)
```
**Description**

Creates a [Sensor_SubscriptionId](#sensor_subscriptionid) instance.

**Since**: 11

**Returns**

Returns the pointer to the [Sensor_SubscriptionId](#sensor_subscriptionid) instances if the operation is successful; returns **NULL** otherwise.


### OH_Sensor_DestroyInfos()

```
int32_t OH_Sensor_DestroyInfos(Sensor_Info **sensors, uint32_t count)
```
**Description**

Destroys an array of [Sensor_Info](#sensor_info) instances and reclaims memory.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensors | Double pointer to the array of [Sensor_Info](#sensor_info) instances.|
| count | Number of [Sensor_Info](#sensor_info) instances to destroy.|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_Sensor_DestroySubscriber()

```
int32_t OH_Sensor_DestroySubscriber(Sensor_Subscriber *subscriber)
```
**Description**

Destroys a [Sensor_Subscriber](#sensor_subscriber) instance and reclaims memory.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Pointer to the [Sensor_Subscriber](#sensor_subscriber) instance.|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_Sensor_DestroySubscriptionAttribute()

```
int32_t OH_Sensor_DestroySubscriptionAttribute(Sensor_SubscriptionAttribute *attribute)
```
**Description**

Destroys a [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instance and reclaims memory.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| attribute | Pointer to the [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute) instance.|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_Sensor_DestroySubscriptionId()

```
int32_t OH_Sensor_DestroySubscriptionId(Sensor_SubscriptionId *id)
```
**Description**

Destroys a [Sensor_SubscriptionId](#sensor_subscriptionid) instance and reclaims memory.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Pointer to the [Sensor_SubscriptionId](#sensor_subscriptionid) instance.|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_Sensor_GetInfos()

```
Sensor_Result OH_Sensor_GetInfos(Sensor_Info **infos, uint32_t *count)
```
**Description**

Obtains information about all sensors on the device.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| infos | Double pointers to the information about all sensors on the device. For details, see [Sensor_Info](#sensor_info).|
| count | Pointer to the number of sensors on the device. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_Sensor_Subscribe()

```
Sensor_Result OH_Sensor_Subscribe(const Sensor_SubscriptionId *id, const Sensor_SubscriptionAttribute *attribute, const Sensor_Subscriber *subscriber)
```
**Description**

Subscribe to sensor data. The system will report sensor data to the subscriber at the specified frequency. To subscribe to data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission. To subscribe to data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission. To subscribe to data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission. To subscribe to data of health-related sensors, such as heart rate sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the subscription fails. You do not need to request any permission to subscribe to data of other types of sensors.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Pointer to the sensor subscription ID. For details, see [Sensor_SubscriptionId](#sensor_subscriptionid).|
| attribute | Pointer to the subscription attribute, which is used to specify the data reporting frequency. For details, see [Sensor_SubscriptionAttribute](#sensor_subscriptionattribute).|
| subscriber | Pointer to the subscriber information, which is used by the callback function to report sensor data. For details, see [Sensor_Subscriber](#sensor_subscriber).|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.

**Required Permissions**

ohos.permission.ACCELEROMETER, ohos.permission.GYROSCOPE, ohos.permission.ACTIVITY_MOTION, or ohos.permission.READ_HEALTH_DATA


### OH_Sensor_Unsubscribe()

```
Sensor_Result OH_Sensor_Unsubscribe(const Sensor_SubscriptionId *id, const Sensor_Subscriber *subscriber)
```
**Description**

Unsubscribes from sensor data. To unsubscribe from data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission. To unsubscribe from data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission. To unsubscribe from data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission. To unsubscribe from data of health-related sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the unsubscription fails. You do not need to request any permission to unsubscribe from data of other types of sensors.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Pointer to the sensor subscription ID. For details, see [Sensor_SubscriptionId](#sensor_subscriptionid).|
| subscriber | Pointer to the subscriber information, which is used by the callback function to report sensor data. For details, see [Sensor_Subscriber](#sensor_subscriber).|

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.

**Required Permissions**

ohos.permission.ACCELEROMETER, ohos.permission.GYROSCOPE, ohos.permission.ACTIVITY_MOTION, or ohos.permission.READ_HEALTH_DATA


### OH_SensorEvent_GetAccuracy()

```
int32_t OH_SensorEvent_GetAccuracy(Sensor_Event* sensorEvent, Sensor_Accuracy *accuracy)
```
**Description**

Obtains the accuracy of sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensorEvent | Pointer to the sensor data information. |
| accuracy | Pointer to the accuracy. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorEvent_GetData()

```
int32_t OH_SensorEvent_GetData(Sensor_Event* sensorEvent, float **data, uint32_t *length)
```
**Description**

Obtains sensor data. The data length and content depend on the sensor type. The format of the sensor data reported is as follows:

- SENSOR_TYPE_ACCELEROMETER: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s².

- SENSOR_TYPE_GYROSCOPE: data[0], data[1], and data[2], indicating the angular velocity of rotation around the x, y, and z axes of a device, respectively, in rad/s.

- SENSOR_TYPE_AMBIENT_LIGHT: data[0], indicating the ambient light intensity, in lux.

- SENSOR_TYPE_MAGNETIC_FIELD: data[0], data[1], and data[2], indicating the magnetic field strength around the x, y, and z axes of a device, respectively, in μT.

- SENSOR_TYPE_BAROMETER: data[0], indicating the atmospheric pressure, in hPa.

- SENSOR_TYPE_HALL: data[0], indicating the opening/closing state of the flip cover. The value **0** means that the flip cover is opened, and a value greater than 0 means that the flip cover is closed.

- SENSOR_TYPE_PROXIMITY: data[0], indicates the approaching state. The value **0** means the two objects are close to each other, and a value greater than 0 means that they are far away from each other.

- SENSOR_TYPE_ORIENTATION: data[0], data[1], and data[2], indicating the rotation angles of a device around the z, x, and y axes, respectively, in degree.

- SENSOR_TYPE_GRAVITY: data[0], data[1], and data[2], indicating the gravitational acceleration around the x, y, and z axes of a device, respectively, in m/s².

- SENSOR_TYPE_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree. data[3] indicates the rotation vector.

- SENSOR_TYPE_PEDOMETER_DETECTION: data[0], indicating the pedometer detection status. The value **1** means that the number of detected steps changes.

- SENSOR_TYPE_PEDOMETER: data[0], indicating the number of steps a user has walked.

- SENSOR_TYPE_HEART_RATE: data[0], indicating the heart rate value.

- SENSOR_TYPE_LINEAR_ACCELERATION: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s². This parameter is supported since API version 13.

- SENSOR_TYPE_GAME_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree; data[3], indicating the rotation vector. This parameter is supported since API version 13.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensorEvent | Pointer to the sensor data information. |
| data | Double pointer to the sensor data. |
| length | Pointer to the array length. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorEvent_GetTimestamp()

```
int32_t OH_SensorEvent_GetTimestamp(Sensor_Event* sensorEvent, int64_t *timestamp)
```
**Description**

Obtains the timestamp of sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensorEvent | Pointer to the sensor data information. |
| timestamp | Pointer to the timestamp. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorEvent_GetType()

```
int32_t OH_SensorEvent_GetType(Sensor_Event* sensorEvent, Sensor_Type *sensorType)
```
**Description**

Obtains the sensor type.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensorEvent | Pointer to the sensor data information. |
| sensorType | Pointer to the sensor type. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetMaxSamplingInterval()

```
int32_t OH_SensorInfo_GetMaxSamplingInterval(Sensor_Info* sensor, int64_t *maxSamplingInterval)
```
**Description**

Obtains the maximum data reporting interval of a sensor.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| maxSamplingInterval | Pointer to the maximum data reporting interval, in nanoseconds. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetMinSamplingInterval()

```
int32_t OH_SensorInfo_GetMinSamplingInterval(Sensor_Info* sensor, int64_t *minSamplingInterval)
```
**Description**

Obtains the minimum data reporting interval of a sensor.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| minSamplingInterval | Pointer to the minimum data reporting interval, in nanoseconds. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetName()

```
int32_t OH_SensorInfo_GetName (Sensor_Info* sensor, char *sensorName, uint32_t *length)
```
**Description**

Obtains the sensor name.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| sensorName | Pointer to the sensor data. |
| length | Pointer to the length, in bytes. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetResolution()

```
int32_t OH_SensorInfo_GetResolution(Sensor_Info* sensor, float *resolution)
```
**Description**

Obtains the sensor resolution.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| resolution | Pointer to the sensor resolution. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetType()

```
int32_t OH_SensorInfo_GetType(Sensor_Info* sensor, Sensor_Type *sensorType)
```
**Description**

Obtains the sensor type.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| sensorType | Pointer to the sensor type. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorInfo_GetVendorName()

```
int32_t OH_SensorInfo_GetVendorName(Sensor_Info* sensor, char *vendorName, uint32_t *length)
```
**Description**

Obtains the sensor's vendor name.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| sensor | Pointer to the sensor information. |
| vendorName | Pointer to the vendor name. |
| length | Pointer to the length, in bytes. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriber_GetCallback()

```
int32_t OH_SensorSubscriber_GetCallback(Sensor_Subscriber* subscriber, Sensor_EventCallback *callback)
```
**Description**

Obtains the callback function used to report sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Pointer to the sensor subscriber information. |
| callback | Pointer to the callback function. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriber_SetCallback()

```
int32_t OH_SensorSubscriber_SetCallback (Sensor_Subscriber* subscriber, const Sensor_EventCallback callback )
```
**Description**

Sets a callback function to report sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| subscriber | Pointer to the sensor subscriber information. |
| callback | Callback function to set. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriptionAttribute_GetSamplingInterval()

```
int32_t OH_SensorSubscriptionAttribute_GetSamplingInterval (Sensor_SubscriptionAttribute * attribute, int64_t * samplingInterval )
```
**Description**

Obtains the interval for reporting sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| attribute | Pointer to the sensor subscription attribute. |
| samplingInterval | Pointer to the data reporting interval, in nanoseconds. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriptionAttribute_SetSamplingInterval()

```
int32_t OH_SensorSubscriptionAttribute_SetSamplingInterval(Sensor_SubscriptionAttribute* attribute, const int64_t samplingInterval)
```
**Description**

Sets the interval for reporting sensor data.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| attribute | Pointer to the sensor subscription attribute. |
| samplingInterval | Data reporting interval to set, in nanoseconds. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriptionId_GetType()

```
int32_t OH_SensorSubscriptionId_GetType(Sensor_SubscriptionId* id, Sensor_Type *sensorType)
```
**Description**

Obtains the sensor type.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Pointer to the sensor subscription ID. |
| sensorType | Pointer to the sensor type. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.


### OH_SensorSubscriptionId_SetType()

```
int32_t OH_SensorSubscriptionId_SetType(Sensor_SubscriptionId* id, const Sensor_Type sensorType)
```
**Description**

Sets the sensor type.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Pointer to the sensor subscription ID. |
| sensorType | Sensor type to set. |

**Returns**

Returns **SENSOR_SUCCESS** if the operation is successful; returns an error code defined in [Sensor_Result](#sensor_result) otherwise.
