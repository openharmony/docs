# 全球化子系统ChangeLog

## cl.global.1 国际化模块系统接口添加运行时鉴权

全球化子系统国际化组件在如下场景中提供的系统接口添加运行时鉴权。从API9开始作以下变更：
 - 设置系统语言、系统国家或地区、系统区域
 - 设置系统24小时制
 - 添加、移除系统偏好语言
 - 设置本地化数字

开发者需要根据以下说明对应用进行适配。

**变更影响**

上述场景涉及的国际化系统接口添加运行时鉴权，只有具有UPDATE_CONFIGURATION权限的系统应用可以正常调用。

**关键的接口/组件变更**

 - 涉及接口
   - setSystemLanguage(language: string): void;
   - setSystemRegion(region: string): void;
   - setSystemLocale(locale: string): void;
   - set24HourClock(option: boolean): void;
   - addPreferredLanguage(language: string, index?: number): void;
   - removePreferredLanguage(index: number): void;
   - setUsingLocalDigit(flag: boolean): void;

**适配指导**

确保应用为系统应用，非系统应用禁止调用上述接口。
当前权限不足或非系统应用调用该接口时会抛出异常，可以通过try-catch来捕获异常。

```js
import I18n from '@ohos.i18n'

try {
  I18n.System.setSystemLanguage('zh');
} catch(error) {
  console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
}
```


## cl.resourceManager.1  资源获取rawfile文件描述符接口含义变更

相较于之前的版本，在4.0.2.2 版本中，新增不解压特性，rawfile文件描述符接口返回值的含义发生了变化。接口用于返回获取的rawfile文件的descriptor：RawFileDescriptor {fd，offset, length}，由于不解压特性变更，返回值没发生变化，但返回值的含义发生了变化, 变化如下：

**新增不解压特性前**：

fd: 访问rawfile文件的文件描述符；

offset: 访问rawfile文件的偏移量，此时为0；

length: 访问rawfile文件的大小。

**新增不解压特性后**：

fd: 访问rawfile文件所在hap的文件描述符；

offset: 访问rawfile文件相对于hap的偏移量；

length: 访问rawfile文件的大小。

**变更影响**

之前只通过fd可以访问到rawfile文件，在4.0.2.2 及以上版本需要通过{fd, offset, length}三个参数才能访问到。

**关键接口/组件变更**

| **涉及接口**                            | 
| ----------------                         | 
| getRawFd(path: string, callback: AsyncCallback\<RawFileDescriptor>): void   | 
| getRawFd(path: string): Promise\<RawFileDescriptor>  |
| getRawFileDescriptor(path: string, callback: AsyncCallback\<RawFileDescriptor>): void|
| getRawFileDescriptor(path: string): Promise\<RawFileDescriptor>|
||

**示例代码**

以调用接口getRawFd为例：
```
try {
    this.context.resourceManager.getRawFd("test.ogg", (error, value) => {
        if (error != null) {
            console.log(`callback getRawFd failed error code: ${error.code}, message: ${error.message}.`);
        } else {
            let fileDescriptor = {
                fd = value.fd,
                offset = value.offset,
                length = value.length
            }
            this.avPlayer.fdSrc(fileDescriptor); // 以音频播放为例，调用fdSrc时需要传fileDescriptor，不能仅传fd。
        }
    });
  } catch (error) {
      console.error(`callback getRawFd failed, error code: ${error.code}, message: ${error.message}.`)
  };
```


## cl.resourceManager.2  getStringSync、getStringByNameSync新增接口

相较于之前的版本，在4.0.6.2 版本中，为扩展getStringSync、getStringByNameSync接口字符串匹配功能，新增了接口以及相应的错误码。

| 包名  | 新增接口  |
| --------------- | ---------------------------------------------------- |
| ohos.resourceManager.d.ts | getStringSync(resId: number, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringSync(resource: Resource, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringByNameSync(resName: string, ...args: Array<string \| number>): string; |

**变更影响**

之前只能直接获取resources中的string资源的value值，在4.0.6.2 及以上版本中可用通过参数格式化string资源的value值，扩展了格式化字符串的查询能力。

新增错误码：

9001007 根据当前id获取的资源格式化失败

9001008 根据当前名称获取的资源格式化失败

**示例代码**

以调用接口getStringSync为例，变更前只支持示例1，变更后示例1、示例2都支持。
```
示例1：
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
示例2：
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 787, 98.78);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
```

**适配指导**
请参考接口说明：

[新增接口参考](../../../application-dev/reference/apis/js-apis-resource-manager.md)

[新增错误码参考](../../../application-dev/reference/errorcodes/errorcode-resource-manager.md)