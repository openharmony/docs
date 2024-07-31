# Global变更说明

## cl.global.1 ohos.i18n部分接口入参类型校验失败错误码抛出变更

**变更原因**

401错误码是通用的参数类型检查错误码，原890001错误码不再在参数类型检查场景抛出

**变更影响**

该变更为不兼容变更。

变更前：参数类型错误抛出890001

变更后：参数类型错误抛出401

更改后应用开发者需要捕捉新的错误码进行错误处理。
当前IDE已有编译阶段参数类型检查，如果使用IDE进行编译，基本无影响。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

ohos.i18n 发生变化的接口如下表格所示。
| 变更的接口 | 访问级别 | 起始 API Level | 变更发生版本 |
|--------|--------|--------|--------|
| getSystemCountries | 公开接口 | 9 | 12 |
| isSuggested | 公开接口 | 9 | 12 |
| getHolidayInfoItemArray | 公开接口 | 11 | 12 |
| isHoliday | 公开接口 | 11 | 12 |
| getDisplayCountry | 公开接口 | 9 | 12 |
| getDisplayLanguage | 公开接口 | 11 | 12 |
| getLanguageInfoArray | 系统接口 | 11 | 12 |
| getRegionInfoArray | 系统接口 | 10 | 12 |
| setUsingLocalDigit | 系统接口 | 10 | 12 |
| removePreferredLanguage | 系统接口 | 9 | 12 |

**适配指导**

入参类型不匹配错误码由890001变更为401，异常处理使用新错误码
