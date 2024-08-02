# 常见问题

## SDK版本问题

### 问题现象

编译或运行时报错：“usb/usb_ddk_api.h not found”, "hid/hid_ddk_api.h not found" 等

### 解决措施

编译时报错：请确认OpenHarmony/HarmonyOS版本，是否为最新版本

运行时报错：请确认设备的版本是否是4.1release版本及以上

### 问题现象

安装出现报错 “compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device” 

### 解决措施

请检查设备系统版本与hap版本是否匹配

### 参考信息

| 外设SDK名称 | 支持最小API | 对应OpenHarmony/HarmonyOS版本 |
| ------------ | ------------ | ------------ |
| 应用开发接口（ArkTS接口）| API10 | 4.0及以上 |
| USB DDK接口 | API10 | 4.0及以上 |
| HID DDK接口 | API11 | 4.1及以上 |
