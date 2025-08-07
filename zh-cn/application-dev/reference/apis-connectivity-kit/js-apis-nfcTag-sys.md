# @ohos.nfc.tag (标准NFC-Tag)（系统接口）

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @amunra03-->
<!--SE: @wenxiaolin-->
<!--TSE: @zs_111-->

本模块主要用于操作及管理NFC Tag，提供后台读卡和前台应用优先分发两种读卡模式。<br>后台读卡是指不需要打开应用程序，电子设备通过NFC读取标签卡片后，根据标签卡片的类型匹配到一个或多个应用程序。如果仅匹配到一个，则直接拉起应用程序的读卡页面；如果是多个则弹出应用选择器，让用户选择指定的读卡应用。<br>前台读卡是指提前打开应用程序，并进入对应的NFC读卡页面后读卡，只会把读到的标签卡片信息分发给前台应用程序。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。<br>当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.nfc.tag (标准NFC-Tag)](js-apis-nfcTag.md)。

## **导入模块**

```js
import { tag } from '@kit.ConnectivityKit';
```

## TagInfo

NFC服务在读取到标签时创建的对象，通过该对象属性，应用可以获取标签支持的技术类型，并使用匹配的技术类型来调用相应接口。

**系统能力：** SystemCapability.Communication.NFC.Tag

**需要权限：** ohos.permission.NFC_TAG

| **名称**                      | **类型**                                                      | **只读** | **可选** | **说明**                                                                                     |
| ----------------------------- | ------------------------------------------------------------- | -------- | -------- | -------------------------------------------------------------------------------------------- |
| extrasData<sup>9+</sup>       | [PacMap](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md#pacmap)[] | 是       | 否       | 标签所支持技术的扩展属性值。<br>**系统接口：** 此接口为系统接口。                            |
| tagRfDiscId<sup>9+</sup>      | number                                                        | 是       | 否       | 标签发现时分配的ID值。<br>**系统接口：** 此接口为系统接口。                                  |
| remoteTagService<sup>9+</sup> | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)               | 是       | 否       | NFC服务进程的远端对象，用于客户端和服务之间的接口通信。<br>**系统接口：** 此接口为系统接口。 |
