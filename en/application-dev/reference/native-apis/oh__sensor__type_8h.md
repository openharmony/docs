# oh_sensor_type.h


## Overview

The **oh_sensor_type.h** file declares the common sensor attributes.

**Library**: libohsensor.so

**System capability**: SystemCapability.Sensors.Sensor

**Since**: 11

**Related module**: [Sensor](_sensor.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) | typedef enum [Sensor_Type](_sensor.md#sensor_type)<br>Defines an enum that enumerates the sensor types. |
| [Sensor_Result](_sensor.md#sensor_result) | typedef enum [Sensor_Result](_sensor.md#sensor_result)<br>Defines an enum that enumerates the sensor result codes. |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) | typedef enum [Sensor_Accuracy](_sensor.md#sensor_accuracy)<br>Defines an enum that enumerates the accuracy levels of data reported by a sensor. |
| [Sensor_Info](_sensor.md#sensor_info) | typedef struct [Sensor_Info](_sensor.md#sensor_info)<br>Defines the sensor information. |
| [Sensor_Event](_sensor.md#sensor_event) | typedef struct [Sensor_Event](_sensor.md#sensor_event)<br>Defines the sensor data information. |
| [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) | typedef struct [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid)<br>Defines the sensor subscription ID, which uniquely identifies a sensor. |
| [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) | typedef struct [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute)<br>Defines the sensor subscription attribute. |
| [Sensor_EventCallback](_sensor.md#sensor_eventcallback)) ([Sensor_Event](_sensor.md#sensor_event) \*event) | typedef void(\*<br>Defines the callback function used to report sensor data. |
| [Sensor_Subscriber](_sensor.md#sensor_subscriber) | typedef struct [Sensor_Subscriber](_sensor.md#sensor_subscriber)<br>Defines the sensor subscriber information. |


### Enums

| Name| Description|
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) {<br>[SENSOR_TYPE_ACCELEROMETER](_sensor.md) = 1, [SENSOR_TYPE_GYROSCOPE](_sensor.md) = 2, [SENSOR_TYPE_AMBIENT_LIGHT](_sensor.md) = 5, [SENSOR_TYPE_MAGNETIC_FIELD](_sensor.md) = 6,<br>[SENSOR_TYPE_BAROMETER](_sensor.md) = 8, [SENSOR_TYPE_HALL](_sensor.md) = 10, [SENSOR_TYPE_PROXIMITY](_sensor.md) = 12, [SENSOR_TYPE_ORIENTATION](_sensor.md) = 256,<br>[SENSOR_TYPE_GRAVITY](_sensor.md) = 257, [SENSOR_TYPE_ROTATION_VECTOR](_sensor.md) = 259, [SENSOR_TYPE_PEDOMETER_DETECTION](_sensor.md) = 265, [SENSOR_TYPE_PEDOMETER](_sensor.md) = 266,<br>[SENSOR_TYPE_HEART_RATE](_sensor.md) = 278<br>} | Enumerates the sensor types. |
| [Sensor_Result](_sensor.md#sensor_result) { [SENSOR_SUCCESS](_sensor.md) = 0, [SENSOR_PERMISSION_DENIED](_sensor.md) = 201, [SENSOR_PARAMETER_ERROR](_sensor.md) = 401, [SENSOR_SERVICE_EXCEPTION](_sensor.md) = 14500101 } | Enumerates the sensor result codes. |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) { [SENSOR_ACCURACY_UNRELIABLE](_sensor.md) = 0, [SENSOR_ACCURACY_LOW](_sensor.md) = 1, [SENSOR_ACCURACY_MEDIUM](_sensor.md) = 2, [SENSOR_ACCURACY_HIGH](_sensor.md) = 3 } | Enumerates the accuracy levels of data reported by a sensor. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Sensor_CreateInfos](_sensor.md#oh_sensor_createinfos) (uint32_t count) | [Sensor_Info](_sensor.md#sensor_info) \*\*<br>Creates an array of [Sensor_Info](_sensor.md#sensor_info) instances with the given number. |
| [OH_Sensor_DestroyInfos](_sensor.md#oh_sensor_destroyinfos) ([Sensor_Info](_sensor.md#sensor_info) \*\*sensors, uint32_t count) | int32_t<br>Destroys an array of [Sensor_Info](_sensor.md#sensor_info) instances and reclaims memory. |
| [OH_SensorInfo_GetName](_sensor.md#oh_sensorinfo_getname) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, char \*sensorName, uint32_t \*length) | int32_t<br>Obtains the sensor name. |
| [OH_SensorInfo_GetVendorName](_sensor.md#oh_sensorinfo_getvendorname) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, char \*vendorName, uint32_t \*length) | int32_t<br>Obtains the sensor's vendor name. |
| [OH_SensorInfo_GetType](_sensor.md#oh_sensorinfo_gettype) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br>Obtains the sensor type. |
| [OH_SensorInfo_GetResolution](_sensor.md#oh_sensorinfo_getresolution) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, float \*resolution) | int32_t<br>Obtains the sensor resolution. |
| [OH_SensorInfo_GetMinSamplingInterval](_sensor.md#oh_sensorinfo_getminsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, int64_t \*minSamplingInterval) | int32_t<br>Obtains the minimum data reporting interval of a sensor. |
| [OH_SensorInfo_GetMaxSamplingInterval](_sensor.md#oh_sensorinfo_getmaxsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) \*sensor, int64_t \*maxSamplingInterval) | int32_t<br>Obtains the maximum data reporting interval of a sensor. |
| [OH_SensorEvent_GetType](_sensor.md#oh_sensorevent_gettype) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br>Obtains the sensor type. |
| [OH_SensorEvent_GetTimestamp](_sensor.md#oh_sensorevent_gettimestamp) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, int64_t \*timestamp) | int32_t<br>Obtains the timestamp of sensor data. |
| [OH_SensorEvent_GetAccuracy](_sensor.md#oh_sensorevent_getaccuracy) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, [Sensor_Accuracy](_sensor.md#sensor_accuracy) \*accuracy) | int32_t<br>Obtains the accuracy of sensor data. |
| [OH_SensorEvent_GetData](_sensor.md#oh_sensorevent_getdata) ([Sensor_Event](_sensor.md#sensor_event) \*sensorEvent, float \*\*data, uint32_t \*length) | int32_t<br>Obtains sensor data. The data length and content depend on the sensor type. The format of the sensor data reported is as follows:<br>- SENSOR_TYPE_ACCELEROMETER: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_GYROSCOPE: data[0], data[1], and data[2], indicating the angular velocity of rotation around the x, y, and z axes of a device, respectively, in rad/s.<br>- SENSOR_TYPE_AMBIENT_LIGHT: data[0], indicating the ambient light intensity, in lux.<br>- SENSOR_TYPE_MAGNETIC_FIELD: data[0], data[1], and data[2], indicating the magnetic field strength around the x, y, and z axes of a device, respectively, in μT.<br>- SENSOR_TYPE_BAROMETER: data[0], indicating the atmospheric pressure, in hPa.<br>- SENSOR_TYPE_HALL: data[0], indicating the opening/closing state of the flip cover. The value **0** means that the flip cover is opened, and a value greater than 0 means that the flip cover is closed.<br>- SENSOR_TYPE_PROXIMITY: data[0], indicates the approaching state. The value **0** means the two objects are close to each other, and a value greater than 0 means that they are far away from each other.<br>- SENSOR_TYPE_ORIENTATION: data[0], data[1], and data[2], indicating the rotation angles of a device around the z, x, and y axes, respectively, in degree.<br>- SENSOR_TYPE_GRAVITY: data[0], data[1], and data[2], indicating the gravitational acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree. data[3] indicates the rotation vector.<br>- SENSOR_TYPE_PEDOMETER_DETECTION: data[0], indicating the pedometer detection status. The value **1** means that the number of detected steps changes.<br>- SENSOR_TYPE_PEDOMETER: data[0], indicating the number of steps a user has walked.<br>- SENSOR_TYPE_HEART_RATE: data[0], indicating the heart rate value. |
| [OH_Sensor_CreateSubscriptionId](_sensor.md#oh_sensor_createsubscriptionid) (void) | [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*<br>Creates a [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) instance. |
| [OH_Sensor_DestroySubscriptionId](_sensor.md#oh_sensor_destroysubscriptionid) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id) | int32_t<br>Destroys a [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) instance and reclaims memory. |
| [OH_SensorSubscriptionId_GetType](_sensor.md#oh_sensorsubscriptionid_gettype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, [Sensor_Type](_sensor.md#sensor_type) \*sensorType) | int32_t<br>Obtains the sensor type. |
| [OH_SensorSubscriptionId_SetType](_sensor.md#oh_sensorsubscriptionid_settype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_Type](_sensor.md#sensor_type) sensorType) | int32_t<br>Sets the sensor type. |
| [OH_Sensor_CreateSubscriptionAttribute](_sensor.md#oh_sensor_createsubscriptionattribute) (void) | [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*<br>Creates a [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) instance. |
| [OH_Sensor_DestroySubscriptionAttribute](_sensor.md#oh_sensor_destroysubscriptionattribute) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute) | int32_t<br>Destroys a [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) instance and reclaims memory. |
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_setsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, const int64_t samplingInterval) | int32_t<br>Sets the sensor data reporting interval. |
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, int64_t \*samplingInterval) | int32_t<br>Obtains the sensor data reporting interval. |
| [OH_Sensor_CreateSubscriber](_sensor.md#oh_sensor_createsubscriber) (void) | [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*<br>Creates a [Sensor_Subscriber](_sensor.md#sensor_subscriber) instance. |
| [OH_Sensor_DestroySubscriber](_sensor.md#oh_sensor_destroysubscriber) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | int32_t<br>Destroys a [Sensor_Subscriber](_sensor.md#sensor_subscriber) instance and reclaims memory. |
| [OH_SensorSubscriber_SetCallback](_sensor.md#oh_sensorsubscriber_setcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber, const [Sensor_EventCallback](_sensor.md#sensor_eventcallback) callback) | int32_t<br>Sets a callback function to report sensor data. |
| [OH_SensorSubscriber_GetCallback](_sensor.md#oh_sensorsubscriber_getcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber, [Sensor_EventCallback](_sensor.md#sensor_eventcallback) \*callback) | int32_t<br>Obtains the callback function used to report sensor data. |
