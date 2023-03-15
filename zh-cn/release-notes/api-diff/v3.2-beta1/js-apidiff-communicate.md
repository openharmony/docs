# 基础通信子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，基础通信子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.bluetooth | ProfileId | PROFILE_HID_HOST = 6 | 新增 |
| ohos.bluetooth | HidHostProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | HidHostProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | 新增 |
| ohos.bluetooth | HidHostProfile | disconnect(device: string): boolean; | 新增 |
| ohos.bluetooth | HidHostProfile | connect(device: string): boolean; | 新增 |