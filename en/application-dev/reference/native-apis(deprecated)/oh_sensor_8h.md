# oh_sensor.h


## Overview

The **oh_sensor.h** file declares the APIs for operating sensors, including obtaining sensor information and subscribing to and unsubscribing from sensor data.

**Library**: libohsensor.so

**System capability**: SystemCapability.Sensors.Sensor

**Since**: 11

**Related module**: [Sensor](_sensor.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Sensor_GetInfos](_sensor.md#oh_sensor_getinfos)([Sensor_Info](_sensor.md#sensor_info) \*\*infos, uint32_t \*count) | Obtains information about all sensors on the device. |
| [OH_Sensor_Subscribe](_sensor.md#oh_sensor_subscribe)(const [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_SubscriptionAttribute](_sensor.md#sensor_subscriptionattribute) \*attribute, const [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | Subscribe to sensor data. The system will report sensor data to the subscriber at the specified frequency.<br>To subscribe to data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To subscribe to data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To subscribe to data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To subscribe to data of health-related sensors, such as heart rate sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the subscription fails. You do not need to request any permission to subscribe to data of other types of sensors.|
| [OH_Sensor_Unsubscribe](_sensor.md#oh_sensor_unsubscribe)(const [Sensor_SubscriptionId](_sensor.md#sensor_subscriptionid) \*id, const [Sensor_Subscriber](_sensor.md#sensor_subscriber) \*subscriber) | Unsubscribes from sensor data.<br>To unsubscribe from data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To unsubscribe from data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To unsubscribe from data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To unsubscribe from data of health-related sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the unsubscription fails. You do not need to request any permission to unsubscribe from data of other types of sensors.|
