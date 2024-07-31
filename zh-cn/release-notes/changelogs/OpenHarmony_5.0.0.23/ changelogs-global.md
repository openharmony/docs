# Global变更说明

## cl.global.1 ohos.i18n部分接口入参类型校验失败错误码抛出变更

**访问级别**

公开接口

**变更原因**

401错误码包含了类型检查错误，原890001错误码不再使用，与其他接口保持一致

**变更影响**

该变更为非兼容性变更。
更改后应用开发者需要捕捉新的错误码，原错误码无法捕捉提供正确的处理日志。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

OH_Drawing_CanvasDrawVertices接口入参校验变化如下表格所示。
| 变更的接口 | 起始 API Level | 变更发生版本 | 适配指导 |
|--------|--------|--------|--------|
| getSystemCountries | 9 | 12 | 入参类型不匹配错误码由890001变更为401 |
| isSuggested | 9 | 12 | 入参类型不匹配错误码由890001变更为401 |
| getHolidayInfoItemArray | 11 | 12 | 入参类型不匹配错误码由890001变更为401 |
| isHoliday | 11 | 12 | 入参类型不匹配错误码由890001变更为401 |
| getRegionInfoArray | 10 | 12 | 入参类型不匹配错误码由890001变更为401 |
| removePreferredLanguage | 9 | 12 | 入参类型不匹配错误码由890001变更为401 |
| getDisplayCountry | 9 | 12 | 入参类型不匹配错误码由890001变更为401 |
| getDisplayLanguage | 11 | 12 | 入参类型不匹配错误码由890001变更为401 |
| getLanguageInfoArray | 11 | 12 | 入参类型不匹配错误码由890001变更为401 |
| setUsingLocalDigit | 10 | 12 | 入参类型不匹配错误码由890001变更为401 |