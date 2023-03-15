# USB管理 changeLog

## cl.usb_manager.1 API错误信息返回方式变更

USB管理接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。从API9开始作出变更，选择通过抛出异常的方式返回错误信息。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

USB模块名由@ohos.usb.d.ts 变更为 @ohos.usbV9.d.ts，模块内所有接口均增加错误码处理。

**适配指导**

接口以getDevices为例，示例代码如下：

```ts
import usbV9 from '@ohos.usbV9'

try {
usbV9.getDevices(); // 如果给该接口传入不合适的参数，则会抛出异常
} catch (err) {
console.error("getDevices errCode:" + err.code + ",errMessage:" + err.message);
}
```