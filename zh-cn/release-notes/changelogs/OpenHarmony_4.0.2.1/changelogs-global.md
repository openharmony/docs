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