# 常见问题

## 编译或运行时无法找到头文件

### 问题现象

编译或运行时提示“usb/usb_ddk_api.h not found”、"hid/hid_ddk_api.h not found" 等。

### 解决措施

- 编译时报错：请确认OpenHarmony版本，是否为最新版本。

- 运行时报错：请确认设备的版本是否为<!--RP1-->4.1 Release<!--RP1End-->及以上。

## 安装HAP时提示版本不匹配

### 问题现象

安装HAP时提示 “compileSdkVersion and releaseType of the app do not match the apiVersion and releaseType on the device”。 

### 解决措施

请根据[参考信息](#参考信息)提供的对应关系，检查设备系统版本是否匹配。

### 参考信息

| 接口类型 | 支持的最小API | 对应OpenHarmony版本 |
| ------------ | ------------ | ------------ |
| 应用开发接口（ArkTS接口）| API10 | <!--RP2-->4.0 Release<!--RP2End-->及以上 |
| USB DDK接口 | API10 | <!--RP3-->4.0 Release<!--RP3End-->及以上 |
| HID DDK接口 | API11 | <!--RP4-->4.1 Release<!--RP4End-->及以上 |


## 安装HAP时提示解析本地so文件失败

### 问题现象

安装HAP时提示"code:9568347 error: install parse native so failed"。

### 解决措施

根据[应用调试](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs-V5/faqs-app-debugging-14-V5)中提供的解决方法，在`build-profile.json5`中的`buildOption/externalNativeOptions`内手动配置`abiFilters`的值。
