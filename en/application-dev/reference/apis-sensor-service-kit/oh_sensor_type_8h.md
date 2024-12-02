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
| [Sensor_Type](_sensor.md#sensor_type) | Defines an enum for sensor types. |
| [Sensor_Result](_sensor.md#sensor_result)                    | Defines an enum for sensor result codes.                |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) | Defines an enum that enumerates the accuracy levels of data reported by a sensor. |
| [Sensor_Info](_sensor.md#sensor_info) | Defines a struct for the sensor information. |
| [Sensor_Event](_sensor.md#sensor_event) | Defines a struct for the sensor data information. |
| [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) | Defines a struct for the sensor subscription ID, which uniquely identifies a sensor. |
| [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) | Defines a struct for the sensor subscription attribute. |
| void ([Sensor_EventCallback](_sensor.md#sensor_eventcallback)) ([Sensor_Event](_sensor.md#sensor_event) *event) | Defines the callback function used to report sensor data. |
| [Sensor_Subscriber](_sensor.md#sensor_subscriber) | Defines a struct for the sensor subscriber information. |


### Enums

| Name| Description|
| -------- | -------- |
| [Sensor_Type](_sensor.md#sensor_type) {<br>SENSOR_TYPE_ACCELEROMETER = 1,<br>SENSOR_TYPE_GYROSCOPE = 2, <br>SENSOR_TYPE_AMBIENT_LIGHT = 5,<br>SENSOR_TYPE_MAGNETIC_FIELD = 6,<br>SENSOR_TYPE_BAROMETER = 8, <br>SENSOR_TYPE_HALL = 10,<br>SENSOR_TYPE_PROXIMITY = 12,<br>SENSOR_TYPE_ORIENTATION = 256,<br>SENSOR_TYPE_GRAVITY = 257, <br>SENSOR_TYPE_ROTATION_VECTOR = 259,<br>SENSOR_TYPE_PEDOMETER_DETECTION = 265, <br>SENSOR_TYPE_PEDOMETER = 266,<br>SENSOR_TYPE_HEART_RATE = 278<br>} | Enumerates the sensor types. |
| [Sensor_Result](_sensor.md#sensor_result) {<br>SENSOR_SUCCESS = 0, <br>SENSOR_PERMISSION_DENIED = 201, <br>SENSOR_PARAMETER_ERROR = 401, <br>SENSOR_SERVICE_EXCEPTION = 14500101<br>} | Enumerates the sensor result codes. |
| [Sensor_Accuracy](_sensor.md#sensor_accuracy) { <br>SENSOR_ACCURACY_UNRELIABLE = 0,<br>SENSOR_ACCURACY_LOW = 1, <br>SENSOR_ACCURACY_MEDIUM = 2,<br>SENSOR_ACCURACY_HIGH = 3<br>} | Defines an enum that enumerates the accuracy levels of data reported by a sensor. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Sensor_CreateInfos](_sensor.md#oh_sensor_createinfos)(uint32_t count) | Creates an array of [Sensor_Info](_sensor.md#sensor_info) instances with the given number.|
| [OH_Sensor_DestroyInfos](_sensor.md#oh_sensor_destroyinfos)([Sensor_Info](_sensor.md#sensor_info) **sensors, uint32_t count) | Destroys an array of [Sensor_Info](_sensor.md#sensor_info) instances and reclaims memory.|
| [OH_SensorInfo_GetName](_sensor.md#oh_sensorinfo_getname)([Sensor_Info](_sensor.md#sensor_info) *sensor, char *sensorName, uint32_t *length) | Obtains the sensor name.                                            |
| [OH_SensorInfo_GetVendorName](_sensor.md#oh_sensorinfo_getvendorname)([Sensor_Info](_sensor.md#sensor_info) *sensor, char *vendorName, uint32_t *length) | Obtains the sensor's vendor name. |
| [OH_SensorInfo_GetType](_sensor.md#oh_sensorinfo_gettype)([Sensor_Info](_sensor.md#sensor_info) *sensor, | Obtains the sensor type.                                            |
| [OH_SensorInfo_GetResolution](_sensor.md#oh_sensorinfo_getresolution) ([Sensor_Info](_sensor.md#sensor_info) *sensor, float *resolution) | Obtains the sensor resolution. |
| [OH_SensorInfo_GetMinSamplingInterval](_sensor.md#oh_sensorinfo_getminsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) *sensor, int64_t *minSamplingInterval) | Obtains the minimum data reporting interval of a sensor. |
| [OH_SensorInfo_GetMaxSamplingInterval](_sensor.md#oh_sensorinfo_getmaxsamplinginterval) ([Sensor_Info](_sensor.md#sensor_info) *sensor, int64_t *maxSamplingInterval) | Obtains the maximum data reporting interval of a sensor. |
| [OH_SensorEvent_GetType](_sensor.md#oh_sensorevent_gettype) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, [Sensor_Type](_sensor.md#sensor_type) *sensorType) | Obtains the sensor type.                                            |
| [OH_SensorEvent_GetTimestamp](_sensor.md#oh_sensorevent_gettimestamp) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, int64_t *timestamp) | Obtains the timestamp of sensor data. |
| [OH_SensorEvent_GetAccuracy](_sensor.md#oh_sensorevent_getaccuracy) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, [Sensor_Accuracy](_sensor.md#sensor_accuracy) *accuracy) | Obtains the accuracy of sensor data.                                      |
| [OH_SensorEvent_GetData](_sensor.md#oh_sensorevent_getdata) ([Sensor_Event](_sensor.md#sensor_event) *sensorEvent, float **data, uint32_t *length) | Obtains sensor data. The data length and content depend on the sensor type. The format of the sensor data reported is as follows:<br> - SENSOR_TYPE_ACCELEROMETER: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_GYROSCOPE: data[0], data[1], and data[2], indicating the angular velocity of rotation around the x, y, and z axes of a device, respectively, in rad/s.<br>- SENSOR_TYPE_AMBIENT_LIGHT: data[0], indicating the ambient light intensity, in lux. Since API version 12, two extra data records are returned, where **data[1]** indicates the color temperature (in kelvin), and **data[2]** indicates the infrared luminance (in cd/m²).<br>- SENSOR_TYPE_MAGNETIC_FIELD: data[0], data[1], and data[2], indicating the magnetic field strength around the x, y, and z axes of a device, respectively, in μT.<br>- SENSOR_TYPE_BAROMETER: data[0], indicating the atmospheric pressure, in hPa.<br>- SENSOR_TYPE_HALL: data[0], indicating the opening/closing state of the flip cover. The value **0** means that the flip cover is opened, and a value greater than 0 means that the flip cover is closed.<br>- SENSOR_TYPE_PROXIMITY: data[0], indicates the approaching state. The value **0** means the two objects are close to each other, and a value greater than 0 means that they are far away from each other. - SENSOR_TYPE_ORIENTATION: data[0], data[1], and data[2], indicating the rotation angles of a device around the z, x, and y axes, respectively, in degree.<br>- SENSOR_TYPE_GRAVITY: data[0], data[1], and data[2], indicating the gravitational acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree. data[3] indicates the rotation vector.<br>- SENSOR_TYPE_PEDOMETER_DETECTION: data[0], indicating the pedometer detection status. The value **1** means that the number of detected steps changes.<br>- SENSOR_TYPE_PEDOMETER: data[0], indicating the number of steps a user has walked.<br>- SENSOR_TYPE_HEART_RATE: data[0], indicating the heart rate value.|
| [OH_Sensor_CreateSubscriptionId](_sensor.md#oh_sensor_createsubscriptionid) (void) | Creates a [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) instance. |
| [OH_Sensor_DestroySubscriptionId](_sensor.md#oh_sensor_destroysubscriptionid) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id) | Destroys a [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) instance and reclaims memory. |
| [OH_SensorSubscriptionId_GetType](_sensor.md#oh_sensorsubscriptionid_gettype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id, [Sensor_Type](_sensor.md#sensor_type) *sensorType) | Obtains the sensor type.                                            |
| [OH_SensorSubscriptionId_SetType](_sensor.md#oh_sensorsubscriptionid_settype) ([Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) *id, const [Sensor_Type](_sensor.md#sensor_type) sensorType) | Sets the sensor type. |
| [OH_Sensor_CreateSubscriptionAttribute](_sensor.md#oh_sensor_createsubscriptionattribute) (void) | Creates a [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) instance. |
| [OH_Sensor_DestroySubscriptionAttribute](_sensor.md#oh_sensor_destroysubscriptionattribute) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute) | Destroys a [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) instance and reclaims memory. |
| [OH_SensorSubscriptionAttribute_SetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_setsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute, const int64_t samplingInterval) | Sets the sensor data reporting interval. |
| [OH_SensorSubscriptionAttribute_GetSamplingInterval](_sensor.md#oh_sensorsubscriptionattribute_getsamplinginterval) ([Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) *attribute, int64_t *samplingInterval) | Obtains the sensor data reporting interval. |
| [OH_Sensor_CreateSubscriber](_sensor.md#oh_sensor_createsubscriber) (void) | Creates a [Sensor_Subscriber](_sensor.md#sensor_subscriber) instance.|
| [OH_Sensor_DestroySubscriber](_sensor.md#oh_sensor_destroysubscriber) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber) | Destroys a [Sensor_Subscriber](_sensor.md#sensor_subscriber) instance and reclaims memory. |
| [OH_SensorSubscriber_SetCallback](_sensor.md#oh_sensorsubscriber_setcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber, const [Sensor_EventCallback](_sensor.md#sensor_eventcallback) callback) | Sets a callback function to report sensor data. |
| [OH_SensorSubscriber_GetCallback](_sensor.md#oh_sensorsubscriber_getcallback) ([Sensor_Subscriber](_sensor.md#sensor_subscriber) *subscriber, [Sensor_EventCallback](_sensor.md#sensor_eventcallback) *callback) | Obtains the callback function used to report sensor data.                          |
