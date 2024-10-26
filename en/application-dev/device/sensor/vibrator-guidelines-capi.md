# Vibrator Development (C/C++)


## When to Use

You can set different vibration effects as needed, for example, customizing the vibration intensity, frequency, and duration for button touches, alarm clocks, and incoming calls.

For details about the APIs, see [Vibrator API Reference](../../reference/apis-sensor-service-kit/vibrator_8h.md).


## Function Description

| Name                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| OHOS::Sensors::OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute) | Configues the vibrator to vibrate continuously for a given duration.|
| OHOS::Sensors::OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute) | Configues the vibrator to vibrate with the custom sequence.          |
| OHOS::Sensors::OH_Vibrator_Cancel()                          | Stops the vibration.                |

## Vibration Effect Description

Currently, two types of vibration effects are supported.

### Fixed-Duration Vibration

Only a fixed duration is passed in, and the device vibrates based on the default intensity and frequency.

### Custom Vibration

Custom vibration enables you to design desired vibration effects by customizing a vibration configuration file and orchestrating vibration forms based on the corresponding rules.


## How to Develop

1. Create a native C++ project.

   ![Create a project](figures/004.png)

2. Before using the vibrator on a device, you must declare the **ohos.permission.VIBRATE** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

   ```json
   "requestPermissions": [
         {
           "name": "ohos.permission.VIBRATE",
         },
       ]
   ```

3. Add the dynamic dependency libraries into the **CMakeLists.txt** file.

   ```c
   target_link_libraries(entry PUBLIC libace_napi.z.so)
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   target_link_libraries(entry PUBLIC libohvibrator.z.so)
   ```

4. Import modules.

   ```c
   #include <sensors/vibrator.h>
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <thread>
   #include <fcntl.h>
   #include <unistd.h>
   #include <sys/stat.h>
   ```

5. Define constants.

   ```c
   const int GLOBAL_RESMGR = 0xFF00;
   const char *TAG = "[NativeVibratorTest]";
   constexpr int32_t TIME_WAIT_FOR_OP = 2;
   ```

6. Configure the vibrator to vibrate continuously for a given duration.

   ```c
   static napi_value Vibration_Test(napi_env env, napi_callback_info info)
   {
       Vibrator_Attribute vibrateAttribute;
       vibrateAttribute.usage = VIBRATOR_USAGE_ALARM;
   
       int32_t ret = OH_Vibrator_PlayVibration(0, vibrateAttribute); // Configure the vibrator to vibrate continuously for a given duration.
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Vibration successful");
       if (ret != PARAMETER_ERROR) {
           return nullptr;
       }
       std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT_FOR_OP));
       ret = OH_Vibrator_Cancel(); // Stop vibration.
       if (ret == 0) {
           return nullptr;
       }
   }
   ```

8. Configure the vibrator to vibrate with the custom sequence.

   ```c
   static napi_value VibrationCustom_Test(napi_env env, napi_callback_info info)
   {
       int32_t fd = open("/data/test/vibrator/coin_drop.json", O_RDONLY);
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Test fd:%{public}d", fd);
       struct stat64 statbuf = { 0 };
       if (fd == 0) {
           close(fd);
           return nullptr;
       }
       if (fstat64(fd, &statbuf) == 0) {
           Vibrator_FileDescription fileDescription = {
               .fd = fd,
               .offset = 0,
               .length = statbuf.st_size
           };
           Vibrator_Attribute vibrateAttribute = {
               .usage = VIBRATOR_USAGE_RING
           };
           int32_t ret = OH_Vibrator_PlayVibrationCustom(fileDescription, vibrateAttribute); // Configure the vibrator to vibrate with the custom sequence.
           OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Vibratecustom successful");
           bool isSuccess = ((ret == 0) || (ret == UNSUPPORTED));
           if (isSuccess == true) {
               close(fd);
               return nullptr;
           }
       }
       std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT_FOR_OP));
       close(fd);
       OH_Vibrator_Cancel(); // Stop vibration.
   }
   ```
   
8. Introduce the NAPI APIs to the **index.d.ts** file in **types/libentry**.

   ```c
   export const vibration_Test: () => number;
   export const vibrationCustom_Test: () => number;
   ```

9. Write JavaScript test cases to test the APIs.
