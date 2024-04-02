# 全球化子系统ChangeLog

## cl.global.1 国际化模块接口支持错误码

全球化子系统国际化组件在如下场景中提供的接口修改为支持错误码。从API9开始作以下变更：
 - 获取国家、语言的本地化显示
 - 获取系统支持的语言列表、语言支持的地区列表
 - 判断语言与地区是否匹配
 - 获取、设置系统语言、系统国家或地区、系统区域
 - 获取、设置系统24小时制
 - 获取、添加、移除系统偏好语言
 - 获取、设置本地化数字

开发者需要根据以下说明对应用进行适配。

**变更影响**

上述接口修改为System类的静态方法，调用时需要在模块名后加上类名。
设置类接口，返回值由boolean类型修改为void类型。例如，setSystemLanguage接口。
接口调用失败时会根据失败原因抛出相应的错误码。例如，当应用未正确配置权限时，抛出201错误码。

**关键的接口/组件变更**

 - 涉及接口
   - getDisplayCountry(country: string, locale: string, sentenceCase?: boolean): string;
   - getDisplayLanguage(language: string, locale: string, sentenceCase?: boolean): string;
   - getSystemLanguages(): Array<string>;
   - getSystemCountries(language: string): Array<string>;
   - isSuggested(language: string, region?: string): boolean;
   - getSystemLanguage(): string;
   - setSystemLanguage(language: string): void;
   - getSystemRegion(): string;
   - setSystemRegion(region: string): void;
   - getSystemLocale(): string;
   - setSystemLocale(locale: string): void;
   - is24HourClock(): boolean;
   - set24HourClock(option: boolean): void;
   - addPreferredLanguage(language: string, index?: number): void;
   - removePreferredLanguage(index: number): void;
   - getPreferredLanguageList(): Array<string>;
   - getFirstPreferredLanguage(): string;
   - getAppPreferredLanguage(): string;
   - setUsingLocalDigit(flag: boolean): void;
   - getUsingLocalDigit(): boolean;

**适配指导**

使用try-catch块捕获接口抛出的日常。
```
import I18n from '@ohos.i18n'

try {
  I18n.System.setSystemLanguage('zh');
} catch(error) {
  console.error(`call System.setSystemLanguage failed, error code: ${error.code}, message: ${error.message}.`)
}
```