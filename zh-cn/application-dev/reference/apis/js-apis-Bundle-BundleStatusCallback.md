# BundleStatusCallback



> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API version 9开始不再支持。建议使用[bundleMonitor](js-apis-bundleMonitor.md)替代。


应用状态回调的信息，通过接口[innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md)获取。


## BundleStatusCallback<sup>(deprecated)<sup>
> 从API version 9开始不再支持。建议使用[bundleMonitor](js-apis-bundleMonitor.md)替代。

**系统API：** 此接口为系统接口，三方应用不支持调用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework。

| 监听类型   | 注册回调                                          | 说明                                   |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | 获取添加的launcherStatusCallback回调。 |
| update | (bundleName : string, userId: number) => void | 获取编辑的launcherStatusCallback回调。 |
| remove | (bundleName : string, userId: number) => void | 获取移除的launcherStatusCallback回调。 |



