# BundleStatusCallback

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

应用包回调的信息，通过接口[innerBundleManager.on](js-apis-Bundle-InnerBundleManager.md)获取。

## BundleStatusCallback<sup>(deprecated)<sup>
> 从API version 9开始不再维护。

**系统API：** 此接口为系统接口，三方应用不支持调用。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework。

| 名称   | 类型                                          | 说明                                   |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | 获取应用安装时的信息。 |
| update | (bundleName : string, userId: number) => void | 获取应用更新时的信息。 |
| remove | (bundleName : string, userId: number) => void | 获取应用卸载时的信息。 |