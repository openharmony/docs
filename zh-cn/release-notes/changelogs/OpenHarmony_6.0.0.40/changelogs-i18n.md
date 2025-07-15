# 全球化子系统Changelog

## cl.global.1 泰国、沙特阿拉伯、阿富汗和伊朗的默认历法变更

**访问级别**

公开接口

**变更原因**

泰国、沙特阿拉伯、阿富汗和伊朗的默认历法配置错误。

**变更影响**

此变更不涉及应用适配。

变更前：泰国的默认历法为佛历，沙特阿拉伯的默认历法为伊斯兰历，阿富汗和伊朗的默认历法为波斯历。例如，创建[intl.DateTimeFormat](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#datetimeformat)时，传入地区为泰国，则调用[format](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#formatdeprecated)接口时，会使用佛历显示日期。
  
变更后：泰国、沙特阿拉伯、阿富汗和伊朗的默认历法均为公历。例如，创建[intl.DateTimeFormat](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#datetimeformat)时，传入地区为泰国，则调用[format](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#formatdeprecated)接口时，会使用公历显示日期。
  
**起始API Level**

API 8

**变更发生版本**

从OpenHarmony SDK 6.0.0.40开始。

**变更的接口/组件**

| 文件 | 接口 |
| ---- | --- |
| @ohos.intl.d.ts | [intl.DateTimeFormat.prototype.format](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#formatdeprecated) |
| @ohos.intl.d.ts | [intl.DateTimeFormat.prototype.formatRange](../../../application-dev/reference/apis-localization-kit/js-apis-intl.md#formatrangedeprecated) |
| @ohos.i18n.d.ts | [i18n.Calendar.prototype.getDisplayName](../../../application-dev/reference/apis-localization-kit/js-apis-i18n.md#getdisplayname8) |
| @ohos.i18n.d.ts | [i18n.Calendar.prototype.get](../../../application-dev/reference/apis-localization-kit/js-apis-i18n.md#get8) |

**适配指导**

仅改变接口内部使用的历法，无需开发者进行适配。
