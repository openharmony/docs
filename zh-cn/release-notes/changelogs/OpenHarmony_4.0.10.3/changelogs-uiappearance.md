# arkui子系统ChangeLog

## cl.arkui.1 用户界面外观服务接口行为变更。

4.0.10.3版本开始，系统接口setDarkMode和getDarkMode返回信息的方式和内容发生变更，需要根据适配指导进行适配。

**变更影响**

基于此前版本开发的系统应用，对返回值的处理需适配新的方式，否则会影响原有业务逻辑。

**关键的接口/组件变更**

涉及接口如下：
- setDarkMode接口在Callback调用方式下，异常情况的处理由只抛出错误码ID变更为抛出错误码ID和错误码信息；
- setDarkMode接口在Promise调用方式下，异常情况的处理由只抛出错误信息变更为抛出错误码ID和错误码信息；
- setDarkMode接口在Callback调用方式下，正常情况的第一个参数由返回0变更为返回null；
- getDarkMode接口在异常情况下由直接返回2变更为抛出异常，需要通过错误码ID和错误码信息判断报错类型。

**说明**：异常情况指参数错误、未配置权限及内部执行出错等未预期的行为，正常情况指未产生错误的预期行为。

**适配指导**

请参考[ @ohos.uiAppearance(用户界面外观)](../../../application-dev/reference/apis/js-apis-uiappearance.md)接口的API参考。
