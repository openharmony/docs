# BundleStatusCallback (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->

应用状态发生变化时回调的信息，通过接口[innerBundleManager.on](js-apis-Bundle-InnerBundleManager-sys.md#innerbundlemanagerondeprecated)获取。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 从API version 9开始，该模块不再维护，暂无替代接口。
> 
> 本模块为系统接口。

## BundleStatusCallback<sup>(deprecated)<sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，暂无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework

| 监听类型   | 注册回调                                          | 说明                                   |
| ------ | --------------------------------------------- | -------------------------------------- |
| add    | (bundleName : string, userId: number) => void | 获取应用安装时的信息。 |
| update | (bundleName : string, userId: number) => void | 获取应用更新时的信息。 |
| remove | (bundleName : string, userId: number) => void | 获取应用卸载时的信息。 |