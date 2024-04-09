# 启动恢复开发常见问题


## 如何获取设备系统版本(API 9)

**解决措施**

可通过[deviceInfo](../reference/apis-basic-services-kit/js-apis-device-info.md)对象的osFullName属性获取设备系统版本。

**代码示例**

```
import deviceInfo from '@ohos.deviceInfo'
let v = deviceInfo.osFullName
```


## 设备如何获取UDID(API 9)

**解决措施**

- 方式一：通过命令行（hdc shell bm get --udid）查询。

- 方式二：在代码中获得，请参考文档[udid](../reference/apis-basic-services-kit/js-apis-device-info.md)。


## 如何获取设备信息(API 9)

可以使用deviceInfo模块获取设备信息，如设备型号等。

**参考链接**

[设备信息](../reference/apis-basic-services-kit/js-apis-device-info.md)


## 开发中如何实现App不被屏保中断(API 9)

**解决方案**

输入命令hdc shell "power-shell setmode 602" 可达到不息屏的效果。
