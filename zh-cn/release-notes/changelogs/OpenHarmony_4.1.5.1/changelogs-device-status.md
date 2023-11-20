# 综合传感处理平台子系统变更说明

## c1.device_status.1 键鼠穿越功能模块接口废弃

**访问级别**

系统接口

**废弃原因**

键鼠穿越模块接口增加权限，新开放的接口包含旧的系统级接口完整功能，接口更加标准并且原子化，符合社区API规范。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**废弃的接口**

**适配指导**

建议使用新模块的接口进行开发，参见[@ohos.distributedDeviceManager](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-distributedDeviceManager.md)。
