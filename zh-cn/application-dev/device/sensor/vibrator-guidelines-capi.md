# 振动开发指导(C/C++)
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--SE: @butterls-->
<!--TSE: @murphy84-->

## 场景介绍

当设备需要设置不同的振动效果时，可以调用Vibrator模块，例如：设备的按键可以设置不同强度和不同时长的振动，闹钟和来电可以设置不同强度和时长的单次或周期振动。

详细的接口介绍请参考[Vibrator接口](../../reference/apis-sensor-service-kit/vibrator_8h.md)。


## 函数说明

| 名称                                                         | 描述                           |
| ------------------------------------------------------------ | ------------------------------ |
| OHOS::Sensors::OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute) | 控制马达在指定时间内持续振动。 |
| OHOS::Sensors::OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute) | 播放自定义振动序列。           |
| OHOS::Sensors::OH_Vibrator_Cancel()                          | 停止马达振动。                 |

## 振动效果说明

目前支持两类振动效果，如下所示。

### 固定时长振动

传入一个固定时长，马达按照默认强度和频率触发振动。

### 自定义振动

自定义振动提供给用户设计自己所需振动效果的能力，用户可通过自定义振动配置文件，并遵循相应规则编排所需振动形式，使能更加开放的振感交互体验。


## 开发步骤

1. 新建一个Native C++工程。

   ![输入图片说明](figures/004.png)

2. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

   ```json
   "requestPermissions": [
         {
           "name": "ohos.permission.VIBRATE",
         },
       ]
   ```

3. CMakeLists.txt文件中引入动态依赖库。

   ```c
   target_link_libraries(entry PUBLIC libace_napi.z.so)
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
   target_link_libraries(entry PUBLIC libohvibrator.z.so)
   ```

4. 导入模块。

   ```c
   #include <sensors/vibrator.h>
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include <thread>
   #include <fcntl.h>
   #include <unistd.h>
   #include <sys/stat.h>
   ```

5. 定义常量。

   ```c
   const int GLOBAL_RESMGR = 0xFF00;
   const char *TAG = "[NativeVibratorTest]";
   constexpr int32_t TIME_WAIT_FOR_OP = 2;
   ```

6. 控制马达在指定时间内持续振动和停止马达振动。

   ```c
   static napi_value Vibration_Test(napi_env env, napi_callback_info info)
   {
       Vibrator_Attribute vibrateAttribute;
       vibrateAttribute.usage = VIBRATOR_USAGE_ALARM;
   
       int32_t ret = OH_Vibrator_PlayVibration(0, vibrateAttribute); // 控制马达在指定时间内持续振动。
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Vibration successful");
       if (ret != PARAMETER_ERROR) {
           return nullptr;
       }
       std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT_FOR_OP));
       ret = OH_Vibrator_Cancel(); // 停止马达振动。
       if (ret == 0) {
           return nullptr;
       }
   }
   ```

8. 播放自定义振动序列。

   ```c
   static napi_value VibrationCustom_Test(napi_env env, napi_callback_info info)
   {
       int32_t fd = open("/data/test/vibrator/coin_drop.json", O_RDONLY);
       OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Test fd:%{public}d", fd);
       struct stat64 statbuf = { 0 };
       if (fd < 0) {
           OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "File open failed");
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
           int32_t ret = OH_Vibrator_PlayVibrationCustom(fileDescription, vibrateAttribute); // 播放自定义振动序列。
           OH_LOG_Print(LOG_APP, LOG_INFO, GLOBAL_RESMGR, TAG, "Vibratecustom successful");
           bool isSuccess = ((ret == 0) || (ret == UNSUPPORTED));
           if (isSuccess == true) {
               close(fd);
               return nullptr;
           }
       }
       std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT_FOR_OP));
       close(fd);
       OH_Vibrator_Cancel(); // 停止马达振动。
   }
   ```
   
8. 在types/libentry路径下index.d.ts文件中引入Napi接口。

   ```c
   export const vibration_Test: () => number;
   export const vibrationCustom_Test: () => number;
   ```

9. 编写Js用例调用接口。
