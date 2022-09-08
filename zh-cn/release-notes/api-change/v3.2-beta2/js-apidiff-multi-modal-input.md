# 多模输入子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，多模输入子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimodalInput.inputMonitor | inputMonitor | off(type: "mouse", receiver?: Callback\<MouseEvent>):void; | 新增 |
| ohos.multimodalInput.inputMonitor | inputMonitor | on(type: "mouse", receiver: Callback\<MouseEvent>):void; | 新增 |
