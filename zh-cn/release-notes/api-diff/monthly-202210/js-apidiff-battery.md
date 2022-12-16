| 操作 | 新版本 | 旧版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增||模块名：ohos.power<br>类名:power<br>方法名 or 属性名:shutdown|@ohos.power.d.ts|
|新增||模块名：ohos.power<br>类名:power<br>方法名 or 属性名:reboot|@ohos.power.d.ts|
|新增||模块名：ohos.power<br>类名:power<br>方法名 or 属性名:isActive|@ohos.power.d.ts|
|新增||模块名：ohos.power<br>类名:power<br>方法名 or 属性名:wakeup|@ohos.power.d.ts|
|新增||模块名：ohos.power<br>类名:power<br>方法名 or 属性名:suspend|@ohos.power.d.ts|
|新增||方法名 or 属性名：getPowerMode<br>函数：function getPowerMode(): DevicePowerMode;|@ohos.power.d.ts|
|新增||模块名：ohos.runningLock<br>类名:RunningLock<br>方法名 or 属性名:hold|@ohos.runningLock.d.ts|
|新增||模块名：ohos.runningLock<br>类名:RunningLock<br>方法名 or 属性名:isHolding|@ohos.runningLock.d.ts|
|新增||模块名：ohos.runningLock<br>类名:RunningLock<br>方法名 or 属性名:unhold|@ohos.runningLock.d.ts|
|新增||模块名：ohos.runningLock<br>类名:runningLock<br>方法名 or 属性名:isSupported|@ohos.runningLock.d.ts|
|新增||模块名：ohos.runningLock<br>类名:runningLock<br>方法名 or 属性名:create|@ohos.runningLock.d.ts|
|新增||模块名：ohos.runningLock<br>类名:runningLock<br>方法名 or 属性名:create|@ohos.runningLock.d.ts|
|新增||模块名：ohos.thermal<br>类名:thermal<br>方法名 or 属性名:registerThermalLevelCallback|@ohos.thermal.d.ts|
|新增||模块名：ohos.thermal<br>类名:thermal<br>方法名 or 属性名:unregisterThermalLevelCallback|@ohos.thermal.d.ts|
|新增||模块名：ohos.thermal<br>类名:thermal<br>方法名 or 属性名:getLevel|@ohos.thermal.d.ts|
|删除|模块名：ohos.power<br>类名:power<br>方法名 or 属性名:shutdownDevice||@ohos.power.d.ts|
|删除|模块名：ohos.power<br>类名:power<br>方法名 or 属性名:wakeupDevice||@ohos.power.d.ts|
|删除|模块名：ohos.power<br>类名:power<br>方法名 or 属性名:suspendDevice||@ohos.power.d.ts|
|废弃版本有变化|方法名 or 属性名：rebootDevice<br>废弃版本：N/A|方法名 or 属性名：rebootDevice<br>废弃版本：9<br>代替接口：{@link power|@ohos.power.d.ts|
|废弃版本有变化|方法名 or 属性名：isScreenOn<br>废弃版本：N/A|方法名 or 属性名：isScreenOn<br>废弃版本：9<br>代替接口：{@link power|@ohos.power.d.ts|
|废弃版本有变化|方法名 or 属性名：isScreenOn<br>废弃版本：N/A|方法名 or 属性名：isScreenOn<br>废弃版本：9|@ohos.power.d.ts|
|废弃版本有变化|方法名 or 属性名：lock<br>废弃版本：N/A|方法名 or 属性名：lock<br>废弃版本：9<br>代替接口：{@link RunningLock|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：isUsed<br>废弃版本：N/A|方法名 or 属性名：isUsed<br>废弃版本：9<br>代替接口：{@link RunningLock|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：unlock<br>废弃版本：N/A|方法名 or 属性名：unlock<br>废弃版本：9<br>代替接口：{@link RunningLock|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：isRunningLockTypeSupported<br>废弃版本：N/A|方法名 or 属性名：isRunningLockTypeSupported<br>废弃版本：9<br>代替接口：{@link RunningLock|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：isRunningLockTypeSupported<br>废弃版本：N/A|方法名 or 属性名：isRunningLockTypeSupported<br>废弃版本：9|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：createRunningLock<br>废弃版本：N/A|方法名 or 属性名：createRunningLock<br>废弃版本：9<br>代替接口：{@link RunningLock|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：createRunningLock<br>废弃版本：N/A|方法名 or 属性名：createRunningLock<br>废弃版本：9|@ohos.runningLock.d.ts|
|废弃版本有变化|方法名 or 属性名：subscribeThermalLevel<br>废弃版本：N/A|方法名 or 属性名：subscribeThermalLevel<br>废弃版本：9<br>代替接口：{@link thermal|@ohos.thermal.d.ts|
|废弃版本有变化|方法名 or 属性名：unsubscribeThermalLevel<br>废弃版本：N/A|方法名 or 属性名：unsubscribeThermalLevel<br>废弃版本：9<br>代替接口：{@link thermal|@ohos.thermal.d.ts|
|废弃版本有变化|方法名 or 属性名：getThermalLevel<br>废弃版本：N/A|方法名 or 属性名：getThermalLevel<br>废弃版本：9<br>代替接口：{@link thermal|@ohos.thermal.d.ts|
|废弃版本有变化|类名：BatteryResponse<br>废弃版本：9|类名：BatteryResponse<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：charging<br>废弃版本：9|方法名 or 属性名：charging<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：level<br>废弃版本：9|方法名 or 属性名：level<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|类名：GetStatusOptions<br>废弃版本：9|类名：GetStatusOptions<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|类名：Battery<br>废弃版本：9|类名：Battery<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|方法名 or 属性名：getStatus<br>废弃版本：9|方法名 or 属性名：getStatus<br>废弃版本：6|@system.battery.d.ts|
|废弃版本有变化|类名：BrightnessResponse<br>废弃版本：9|类名：BrightnessResponse<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：value<br>废弃版本：9|方法名 or 属性名：value<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessOptions<br>废弃版本：9|类名：GetBrightnessOptions<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessOptions<br>废弃版本：9|类名：SetBrightnessOptions<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：value<br>废弃版本：9|方法名 or 属性名：value<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：BrightnessModeResponse<br>废弃版本：9|类名：BrightnessModeResponse<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：mode<br>废弃版本：9|方法名 or 属性名：mode<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：GetBrightnessModeOptions<br>废弃版本：9|类名：GetBrightnessModeOptions<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：SetBrightnessModeOptions<br>废弃版本：9|类名：SetBrightnessModeOptions<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：mode<br>废弃版本：9|方法名 or 属性名：mode<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：SetKeepScreenOnOptions<br>废弃版本：9|类名：SetKeepScreenOnOptions<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：keepScreenOn<br>废弃版本：9|方法名 or 属性名：keepScreenOn<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：success<br>废弃版本：9|方法名 or 属性名：success<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：fail<br>废弃版本：9|方法名 or 属性名：fail<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：complete<br>废弃版本：9|方法名 or 属性名：complete<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|类名：Brightness<br>废弃版本：9|类名：Brightness<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：getValue<br>废弃版本：9|方法名 or 属性名：getValue<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：setValue<br>废弃版本：9|方法名 or 属性名：setValue<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：getMode<br>废弃版本：9|方法名 or 属性名：getMode<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：setMode<br>废弃版本：9|方法名 or 属性名：setMode<br>废弃版本：7|@system.brightness.d.ts|
|废弃版本有变化|方法名 or 属性名：setKeepScreenOn<br>废弃版本：9|方法名 or 属性名：setKeepScreenOn<br>废弃版本：7|@system.brightness.d.ts|
