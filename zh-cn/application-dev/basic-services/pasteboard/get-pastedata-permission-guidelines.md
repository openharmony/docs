# 申请访问剪贴板权限
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

## 概述

API version 12及之后，系统为提升用户隐私安全保护能力，剪贴板读取接口增加权限管控。

涉及接口如下：

| 名称 | 说明                                                                                                                                        |
| -------- |----------------------------------------------------------------------------------------------------------------------------------------|
| [getData(callback: AsyncCallback&lt;PasteData&gt;): void](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9) | 读取系统剪贴板内容，使用callback异步回调。 |
| [getData(): Promise&lt;PasteData&gt;](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9-1) | 读取系统剪贴板内容，使用Promise异步回调。 |
| [getDataSync(): PasteData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdatasync11) | 读取系统剪贴板内容, 此接口为同步接口。 |
| [getUnifiedData(): Promise\<unifiedDataChannel.UnifiedData\>](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddata12) | 从系统剪贴板中读取统一数据对象的数据。 |
| [getUnifiedDataSync(): unifiedDataChannel.UnifiedData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getunifieddatasync12) | 从系统剪贴板中读取统一数据对象的数据，此接口为同步接口。 |
| [OH_UdmfData* OH_Pasteboard_GetData (OH_Pasteboard *pasteboard, int *status)](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_getdata) | 获取剪贴板中的数据。 |
| [getDataWithProgress(params: GetDataParams): Promise\<PasteData\>](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getdatawithprogress15) | 获取剪贴板的内容和进度，使用Promise异步回调，不支持对文件夹的拷贝。 |
| [OH_UdmfData* OH_Pasteboard_GetDataWithProgress(OH_Pasteboard* pasteboard, Pasteboard_GetDataParams* params, int* status)](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_getdatawithprogress) | 获取剪贴板的数据以及粘贴进度，不支持对文件夹的拷贝。 |

**说明：** 申请访问剪贴板权限前，需提前判断剪贴板上的内容是否包含应用所需数据，包括不限于hasData检查是否有数据、hasDataType/getMimeTypes检查是否有应用所需类型、getChangeCount检查数据是否改变，详见[剪贴板弹窗适配优化](#剪贴板弹窗适配优化)。

## 访问剪贴板内容

剪贴板为应用提供如下两种访问内容的方式。

- 使用安全控件

    使用[安全控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

    已经使用了安全控件的应用无需做任何适配就可以访问剪贴板内容。

- 申请ohos.permission.READ_PASTEBOARD权限

    ohos.permission.READ_PASTEBOARD是受限的user_grant（用户授权）权限，使用自定义控件的应用可以通过申请ohos.permission.READ_PASTEBOARD权限，在用户授权的场景下访问剪贴板内容。

    权限申请步骤：
    <!--RP1-->
    1.通过[ACL方式](../../security/AccessToken/declare-permissions-in-acl.md)，申请高级别权限。
    
    2.在module.json5配置文件中[声明权限](../../security/AccessToken/declare-permissions.md)。
    
    3.通过弹窗[向用户申请权限](../../security/AccessToken/request-user-authorization.md)。
    <!--RP1End-->

## 剪贴板弹窗适配优化

应用申请剪贴板权限需要提前判断剪贴板上的内容是否包含所需数据，避免出现无效弹框。

- 使用[hasData](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#hasdata9)判断剪贴板是否有数据，无数据则不访问剪贴板。

- 使用[hasDataType](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#hasdatatype11)/[getMimeTypes](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getmimetypes14)判断是否包含应用当前场景支持处理的数据类型，如果没有对应的数据类型，则不访问剪贴板。

- 使用[getChangeCount](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#getchangecount18)获取剪贴板的内容变化次数，与上次读取剪贴板时查询的变化次数比较是否一致，一致则剪贴板内容无变化，不访问剪贴板。

- 使用[detectPatterns](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#detectpatterns13)判断是否包含应用自身口令的格式，如果格式不匹配，则不访问剪贴板。应用读取口令后如果确认是应用自身的口令，建议应用使用[cleardata](../../reference/apis-basic-services-kit/js-apis-pasteboard.md#cleardata9)清除剪贴板口令内容。
