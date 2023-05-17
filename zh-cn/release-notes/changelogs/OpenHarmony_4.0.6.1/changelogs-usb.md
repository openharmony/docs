# USB服务子系统ChangeLog

## cl.usb_manager.1  sdk接口删除

基于此前版本开发的应用，需修改导入的包名，否则会影响原有业务逻辑。

**关键接口/组件变更**

@ohos.usbV9.d.ts文件已删除，由@ohos.usbManager.d.ts替代。

|         新包名        |     旧包名    |    已删除包名    |
| -------------------- | ------------- | --------------- |
| ohos.usbManager.d.ts | ohos.usb.d.ts | ohos.usbV9.d.ts |

后续需要import @ohos.usbManager才能使用USB服务的接口：

  ```ts
  import usbManager from '@ohos.usbManager';
  ```

**适配指导**

请参考各接口的[API文档](../../../application-dev/reference/apis/js-apis-usbManager.md)
