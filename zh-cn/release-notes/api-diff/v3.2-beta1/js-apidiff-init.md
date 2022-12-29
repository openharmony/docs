# 启动恢复子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，启动恢复子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.systemCapability | systemCapability | querySystemCapabilities(callback: AsyncCallback\<string>): void;<br>querySystemCapabilities(): Promise\<string>; | 新增 |
