# Sensor Development (C/C++)


## When to Use

With the sensor module, a device can obtain sensor data. For example, the device can subscribe to data of the orientation sensor to detect its own orientation, and data of the pedometer sensor to learn the number of steps the user walks every day.

For details about the APIs, see [Sensor API Reference](../../reference/apis-sensor-service-kit/_sensor.md).

## Function Description

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Sensor_GetInfos(Sensor_Info **infos, uint32_t *count)     | Obtains information about all sensors on the device.                                |
| OH_Sensor_Subscribe(const Sensor_SubscriptionId *id, const Sensor_SubscriptionAttribute *attribute, const Sensor_Subscriber *subscriber) | Subscribe to sensor data. The system will report sensor data to the subscriber at the specified frequency.<br>To subscribe to data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To subscribe to data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To subscribe to data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To subscribe to data of health-related sensors, such as heart rate sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the subscription fails.<br>You do not need to request any permission to subscribe to data of other types of sensors.|
| OH_Sensor_Unsubscribe(const Sensor_SubscriptionId *id, const Sensor_Subscriber *subscriber) | Unsubscribes from sensor data.<br>To unsubscribe from data of acceleration sensors, request the **ohos.permission.ACCELEROMETER** permission.<br>To unsubscribe from data of gyroscope sensors, request the **ohos.permission.GYROSCOPE** permission.<br>To unsubscribe from data of pedometer-related sensors, request the **ohos.permission.ACTIVITY_MOTION** permission.<br>To unsubscribe from data of health-related sensors, request the **ohos.permission.READ_HEALTH_DATA** permission. Otherwise, the unsubscription fails.<br>You do not need to request any permission to unsubscribe from data of other types of sensors.|
| OH_Sensor_CreateInfos(uint32_t count)                        | Creates an array of instances with the given number. For details, see [Sensor_Info](../../reference/apis-sensor-service-kit/_sensor.md#sensor_info).|
| OH_Sensor_DestroyInfos(Sensor_Info **sensors, uint32_t count) | Destroys the array of instances and reclaims the memory. For details, see [Sensor_Info](../../reference/apis-sensor-service-kit/_sensor.md#sensor_info).|
| OH_SensorInfo_GetName(Sensor_Info *sensor, char *sensorName, uint32_t *length) | Obtains the sensor name.                                            |
| OH_SensorInfo_GetVendorName(Sensor_Info* sensor, char *vendorName, uint32_t *length) | Obtains the sensor's vendor name.                                      |
| OH_SensorInfo_GetType(Sensor_Info* sensor, Sensor_Type *sensorType) | Obtains the sensor type.                                            |
| OH_SensorInfo_GetResolution(Sensor_Info* sensor, float *resolution) | Obtains the sensor resolution.                                          |
| OH_SensorInfo_GetMinSamplingInterval(Sensor_Info* sensor, int64_t *minSamplingInterval) | Obtains the minimum data reporting interval of a sensor.                              |
| OH_SensorInfo_GetMaxSamplingInterval(Sensor_Info* sensor, int64_t *maxSamplingInterval) | Obtains the maximum data reporting interval of a sensor.                          |
| OH_SensorEvent_GetType(Sensor_Event* sensorEvent, Sensor_Type *sensorType) | Obtains the sensor type.                                            |
| OH_SensorEvent_GetTimestamp(Sensor_Event* sensorEvent, int64_t *timestamp) | Obtains the timestamp of sensor data.                                    |
| OH_SensorEvent_GetAccuracy(Sensor_Event* sensorEvent, Sensor_Accuracy *accuracy) | Obtains the accuracy of sensor data.                                      |
| OH_SensorEvent_GetData(Sensor_Event* sensorEvent, float **data, uint32_t *length) | Obtains sensor data.<br>The data length and content depend on the sensor type. The format of the sensor data reported is as follows:<br>- SENSOR_TYPE_ACCELEROMETER: data[0], data[1], and data[2], indicating the acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_GYROSCOPE: data[0], data[1], and data[2], indicating the angular velocity of rotation around the x, y, and z axes of a device, respectively, in rad/s.<br>- SENSOR_TYPE_AMBIENT_LIGHT: data[0], indicating the ambient light intensity, in lux. Since API version 12, two extra data records are returned, where **data[1]** indicates the color temperature (in kelvin), and **data[2]** indicates the infrared luminance (in cd/m²).<br> - SENSOR_TYPE_MAGNETIC_FIELD: data[0], data[1], and data[2], indicating the magnetic field strength around the x, y, and z axes of a device, respectively, in μT.<br>- SENSOR_TYPE_BAROMETER: data[0], indicating the atmospheric pressure, in hPa.<br>- SENSOR_TYPE_HALL: data[0], indicating the opening/closing state of the flip cover. The value **0** means that the flip cover is opened, and a value greater than 0 means that the flip cover is closed.<br>- SENSOR_TYPE_PROXIMITY: data[0], indicates the approaching state. The value **0** means the two objects are close to each other, and a value greater than 0 means that they are far away from each other.<br>- SENSOR_TYPE_ORIENTATION: data[0], data[1], and data[2], indicating the rotation angles of a device around the z, x, and y axes, respectively, in degree.<br>- SENSOR_TYPE_GRAVITY: data[0], data[1], and data[2], indicating the gravitational acceleration around the x, y, and z axes of a device, respectively, in m/s².<br>- SENSOR_TYPE_ROTATION_VECTOR: data[0], data[1] and data[2], indicating the rotation angles of a device around the x, y, and z axes, respectively, in degree. data[3] indicates the rotation vector.<br>- SENSOR_TYPE_PEDOMETER_DETECTION: data[0], indicating the pedometer detection status. The value **1** means that the number of detected steps changes.<br>- SENSOR_TYPE_PEDOMETER: data[0], indicating the number of steps a user has walked.<br>- SENSOR_TYPE_HEART_RATE: data[0], indicating the heart rate value.|
| OH_Sensor_CreateSubscriptionId(void)                         | Creates a **Sensor_SubscriptionId** instance.                        |
| OH_Sensor_DestroySubscriptionId(Sensor_SubscriptionId *id)   | Destroys a **Sensor_SubscriptionId** instance and reclaims memory.                  |
| OH_SensorSubscriptionId_SetType(Sensor_SubscriptionId* id, const Sensor_Type sensorType) | Sets the sensor type.                                            |
| OH_Sensor_CreateSubscriptionAttribute(void)                  | Creates a **Sensor_SubscriptionAttribute** instance.                      |
| OH_Sensor_DestroySubscriptionAttribute(Sensor_SubscriptionAttribute *attribute) | Destroys a **Sensor_SubscriptionAttribute** instance and reclaims memory.            |
| OH_SensorSubscriptionAttribute_SetSamplingInterval(Sensor_SubscriptionAttribute* attribute, const int64_t samplingInterval) | Sets the interval for reporting sensor data.                                    |
| OH_Sensor_CreateSubscriber(void)                             | Creates a **Sensor_Subscriber** instance.                             |
| OH_Sensor_DestroySubscriber(Sensor_Subscriber *subscriber)   | Destroys a **Sensor_Subscriber** instance and reclaims memory.                       |
| OH_SensorSubscriber_SetCallback(Sensor_Subscriber* subscriber, const Sensor_EventCallback callback) | Sets a callback function to report sensor data.                          |


## How to Develop

The following uses the acceleration sensor as an example to describe the development procedure.

1. Create a native C++ project.

   ![Create a project](figures/004.png)

2. Configure the acceleration sensor permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

   ```json
   "requestPermissions": [
         {
           "name": "ohos.permission.ACCELEROMETER",
         },
       ]
   ```

3. Add the dynamic dependency libraries into the **CMakeLists.txt** file.

   ```c
   target_link_libraries(entry PUBLIC libace_napi.z.so)
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   target_link_libraries(entry PUBLIC libohsensor.so)
   ```

4. Write the **napi_init.cpp** file to import related modules.

   ```c
   #include "sensors/oh_sensor.h"
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <thread>
   ```

5. Define constants.

   ```c
   const int GLOBAL_RESMGR = 0xFF00;
   const char *TAG = "[Sensor]";
   constexpr Sensor_Type SENSOR_ID { SENSOR_TYPE_ACCELEROMETER };
   constexpr uint32_t SENSOR_NAME_LENGTH_MAX = 64;
   constexpr int64_t SENSOR_SAMPLE_PERIOD = 200000000;
   constexpr int32_t SLEEP_TIME_MS = 1000;
   constexpr int64_t INVALID_VALUE = -1;
   constexpr float INVALID_RESOLUTION = -1.0F;
   Sensor_Subscriber *g_user = nullptr;
   ```

6. Define a callback function to receive sensor data.

   ```c
   void SensorDataCallbackImpl(Sensor_Event *event) {
       if (event == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "event is null");
           return;
       }
       int64_t timestamp = INVALID_VALUE;
       int32_t ret = OH_SensorEvent_GetTimestamp(event, &timestamp); // Obtain the timestamp of sensor data.
       if (ret != SENSOR_SUCCESS) {
           return;
       }
       Sensor_Type sensorType;
       ret = OH_SensorEvent_GetType(event, &sensorType); // Obtain the sensor type.
       if (ret != SENSOR_SUCCESS) {
           return;
       }
       Sensor_Accuracy accuracy = SENSOR_ACCURACY_UNRELIABLE;
       ret = OH_SensorEvent_GetAccuracy(event, &accuracy); // Obtain the accuracy of sensor data.
       if (ret != SENSOR_SUCCESS) {
           return;
       }
       float *data = nullptr;
       uint32_t length = 0;
       ret = OH_SensorEvent_GetData(event, &data, &length); // Obtain sensor data.
       if (ret != SENSOR_SUCCESS) {
           return;
       }
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "sensorType:%{public}d, dataLen:%{public}d, accuracy:%{public}d", sensorType, length, accuracy);
       for (uint32_t i = 0; i < length; ++i) {
           OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "data[%{public}d]:%{public}f", i, data[i]);
       }
   }
   ```

7. Obtain information about all sensors on the device. 

   ```c
   static napi_value GetSensorInfos(napi_env env, napi_callback_info info)
   {
       uint32_t count = 0;
       int32_t ret = OH_Sensor_GetInfos(nullptr, &count); // Obtain the number of all sensors on the device.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
       Sensor_Info **sensors = OH_Sensor_CreateInfos(count); // Create an array of instances with the given number.
       if (sensor == nullptr) {
           return nullptr;
       }        
       ret = OH_Sensor_GetInfos(sensors, &count); // Obtain information about all sensors on the device.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
       for (uint32_t i = 0; i < count; ++i) {
           char sensorName[SENSOR_NAME_LENGTH_MAX] = {};
           uint32_t length = SENSOR_NAME_LENGTH_MAX;
           ret = OH_SensorInfo_GetName(sensors[i], sensorName, &length); // Obtain the sensor name.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
           char vendorName[SENSOR_NAME_LENGTH_MAX] = {};
           length = SENSOR_NAME_LENGTH_MAX;
           ret = OH_SensorInfo_GetVendorName(sensors[i], vendorName, &length); // Obtain the manufacturer name of the sensor.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
           Sensor_Type sensorType;
           ret = OH_SensorInfo_GetType(sensors[i], &sensorType); // Obtain the sensor type.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
           float resolution = INVALID_RESOLUTION;
           ret = OH_SensorInfo_GetResolution(sensors[i], &resolution); // Obtain the sensor resolution.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
           int64_t minSamplePeriod = INVALID_VALUE;
           ret = OH_SensorInfo_GetMinSamplingInterval(sensors[i], &minSamplePeriod); // Obtain the minimum data reporting interval of a sensor.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
           int64_t maxSamplePeriod = INVALID_VALUE;
           ret = OH_SensorInfo_GetMaxSamplingInterval(sensors[i], &maxSamplePeriod); // Obtain the maximum data reporting interval of a sensor.
           if (ret != SENSOR_SUCCESS) {
               return nullptr;
           }
       }
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "GetSensorInfos sucessful");
       ret = OH_Sensor_DestroyInfos(sensors, count); // Destroy an array of instances and reclaim the memory.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
   }
   ```

8. Subscribe to and unsubscribe from sensor data.

   ```c
   static napi_value Subscriber(napi_env env, napi_callback_info info)
   {
       g_user = OH_Sensor_CreateSubscriber();                                         // Create a Sensor_Subscriber instance.
       int32_t ret = OH_SensorSubscriber_SetCallback(g_user, SensorDataCallbackImpl); // Set a callback function to report sensor data.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
   
       Sensor_SubscriptionId *id = OH_Sensor_CreateSubscriptionId(); // Create a Sensor_SubscriptionId instance.
       ret = OH_SensorSubscriptionId_SetType(id, SENSOR_ID); // Set the sensor type.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
   
       Sensor_SubscriptionAttribute *attr = OH_Sensor_CreateSubscriptionAttribute(); // Create a Sensor_SubscriptionAttribute instance.
       ret = OH_SensorSubscriptionAttribute_SetSamplingInterval(attr, SENSOR_SAMPLE_PERIOD); // Set the interval for reporting sensor data.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
   
       ret = OH_Sensor_Subscribe(id, attr, g_user); // Subscribe to sensor data.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Subscriber successful");
       std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
       ret = OH_Sensor_Unsubscribe(id, g_user); // Unsubscribe from sensor data.
       if (ret != SENSOR_SUCCESS) {
           return nullptr;
       }
       if (id != nullptr) {
           OH_Sensor_DestroySubscriptionId(id); // Destroy the Sensor_SubscriptionId instance and reclaim the memory.
       }
       if (attr != nullptr) {
           OH_Sensor_DestroySubscriptionAttribute(attr); // Destroy the Sensor_SubscriptionAttribute instance and reclaim the memory.
       }
       if (g_user != nullptr) {
           OH_Sensor_DestroySubscriber(g_user); // Destroy the Sensor_Subscriber instance and reclaim the memory.
           g_user = nullptr;
       }
   }
   ```
   
9. Add related APIs to the **Init** function.

   ```c
   static napi_value Init(napi_env env, napi_value exports)
      {
          napi_property_descriptor desc[] = {
              { "getSensorInfos", nullptr, GetSensorInfos, nullptr, nullptr, nullptr, napi_default, nullptr },
              { "subscriber", nullptr, Subscriber, nullptr, nullptr, nullptr, napi_default, nullptr }
          };
          napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
          return exports;
      }
      EXTERN_C_END
   ```

10. Introduce the NAPI APIs to the **index.d.ts** file in **types/libentry**.

   ```c
   export const getSensorInfos: () => number;
   export const subscriber: () => number;
   ```

   
