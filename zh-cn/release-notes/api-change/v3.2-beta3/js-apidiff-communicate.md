# 基础通信子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，基础通信子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.wifi | wifi | function off(type: "deviceConfigChange", callback?: Callback\<number>): void; | 新增 |
| ohos.wifi | wifi | function on(type: "deviceConfigChange", callback: Callback\<number>): void;  | 新增 |
| ohos.wifi | wifi | function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | 废弃 |
| ohos.wifi | wifi | function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;     | 废弃 |