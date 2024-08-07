# uds.h


## 概述

提供标准化数据结构相关接口函数、结构体定义。

**引用文件：**&lt;database/udmf/uds.h&gt;

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：**[UDMF](_u_d_m_f.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) | 描述纯文本类型数据的统一数据结构。 | 
| typedef struct [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) | 描述超链接类型的统一数据结构。 | 
| typedef struct [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) | 描述超文本标记语言类型的统一数据结构。 | 
| typedef struct [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) | 描述桌面图标类型的统一数据结构。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \* [OH_UdsPlainText_Create](_u_d_m_f.md#oh_udsplaintext_create) () | 创建纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)指针及实例对象。 | 
| void [OH_UdsPlainText_Destroy](_u_d_m_f.md#oh_udsplaintext_destroy) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis) | 销毁纯文本类型数据[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)指针指向的实例对象。 | 
| const char \* [OH_UdsPlainText_GetType](_u_d_m_f.md#oh_udsplaintext_gettype) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)中获取类型ID。 | 
| const char \* [OH_UdsPlainText_GetContent](_u_d_m_f.md#oh_udsplaintext_getcontent) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)中获取纯文本内容信息。 | 
| const char \* [OH_UdsPlainText_GetAbstract](_u_d_m_f.md#oh_udsplaintext_getabstract) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis) | 从纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)中获取纯文本摘要信息。 | 
| int [OH_UdsPlainText_SetContent](_u_d_m_f.md#oh_udsplaintext_setcontent) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis, const char \*content) | 设置纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)中的纯文本内容参数。 | 
| int [OH_UdsPlainText_SetAbstract](_u_d_m_f.md#oh_udsplaintext_setabstract) ([OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext) \*pThis, const char \*abstract) | 设置纯文本类型[OH_UdsPlainText](_u_d_m_f.md#oh_udsplaintext)中的纯文本摘要参数。 | 
| [OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \* [OH_UdsHyperlink_Create](_u_d_m_f.md#oh_udshyperlink_create) () | 创建超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)指针及实例对象。 | 
| void [OH_UdsHyperlink_Destroy](_u_d_m_f.md#oh_udshyperlink_destroy) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis) | 销毁超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)指针指向的实例对象。 | 
| const char \* [OH_UdsHyperlink_GetType](_u_d_m_f.md#oh_udshyperlink_gettype) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)中获取类型ID。 | 
| const char \* [OH_UdsHyperlink_GetUrl](_u_d_m_f.md#oh_udshyperlink_geturl) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)中获取URL参数。 | 
| const char \* [OH_UdsHyperlink_GetDescription](_u_d_m_f.md#oh_udshyperlink_getdescription) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis) | 从超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)中获取描述参数。 | 
| int [OH_UdsHyperlink_SetUrl](_u_d_m_f.md#oh_udshyperlink_seturl) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis, const char \*url) | 设置超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)实例中URL参数。 | 
| int [OH_UdsHyperlink_SetDescription](_u_d_m_f.md#oh_udshyperlink_setdescription) ([OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink) \*pThis, const char \*description) | 设置超链接类型[OH_UdsHyperlink](_u_d_m_f.md#oh_udshyperlink)实例中描述参数。 | 
| [OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \* [OH_UdsHtml_Create](_u_d_m_f.md#oh_udshtml_create) () | 创建超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)指针及实例对象。 | 
| void [OH_UdsHtml_Destroy](_u_d_m_f.md#oh_udshtml_destroy) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis) | 销毁超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)指针指向的实例对象。 | 
| const char \* [OH_UdsHtml_GetType](_u_d_m_f.md#oh_udshtml_gettype) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)对象中类型ID。 | 
| const char \* [OH_UdsHtml_GetContent](_u_d_m_f.md#oh_udshtml_getcontent) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)对象中HTML格式内容参数。 | 
| const char \* [OH_UdsHtml_GetPlainContent](_u_d_m_f.md#oh_udshtml_getplaincontent) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis) | 获取超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)对象中的纯文本内容参数。 | 
| int [OH_UdsHtml_SetContent](_u_d_m_f.md#oh_udshtml_setcontent) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis, const char \*content) | 设置超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)中的HTML格式内容参数。 | 
| int [OH_UdsHtml_SetPlainContent](_u_d_m_f.md#oh_udshtml_setplaincontent) ([OH_UdsHtml](_u_d_m_f.md#oh_udshtml) \*pThis, const char \*plainContent) | 设置超文本标记语言类型[OH_UdsHtml](_u_d_m_f.md#oh_udshtml)中的纯文本内容参数。 | 
| [OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \* [OH_UdsAppItem_Create](_u_d_m_f.md#oh_udsappitem_create) () | 创建桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)指针及实例对象。 | 
| void [OH_UdsAppItem_Destroy](_u_d_m_f.md#oh_udsappitem_destroy) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 销毁桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)指针指向的实例对象。 | 
| const char \* [OH_UdsAppItem_GetType](_u_d_m_f.md#oh_udsappitem_gettype) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例获取类型ID。 | 
| const char \* [OH_UdsAppItem_GetId](_u_d_m_f.md#oh_udsappitem_getid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中获取应用ID。 | 
| const char \* [OH_UdsAppItem_GetName](_u_d_m_f.md#oh_udsappitem_getname) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中获取应用名称。 | 
| const char \* [OH_UdsAppItem_GetIconId](_u_d_m_f.md#oh_udsappitem_geticonid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中获取图片ID。 | 
| const char \* [OH_UdsAppItem_GetLabelId](_u_d_m_f.md#oh_udsappitem_getlabelid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中获取标签ID。 | 
| const char \* [OH_UdsAppItem_GetBundleName](_u_d_m_f.md#oh_udsappitem_getbundlename) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中获取bundle名称。 | 
| const char \* [OH_UdsAppItem_GetAbilityName](_u_d_m_f.md#oh_udsappitem_getabilityname) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis) | 从桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)实例中ability名称。 | 
| int [OH_UdsAppItem_SetId](_u_d_m_f.md#oh_udsappitem_setid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*appId) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的应用ID。 | 
| int [OH_UdsAppItem_SetName](_u_d_m_f.md#oh_udsappitem_setname) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*appName) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的应用名称。 | 
| int [OH_UdsAppItem_SetIconId](_u_d_m_f.md#oh_udsappitem_seticonid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*appIconId) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的图片ID。 | 
| int [OH_UdsAppItem_SetLabelId](_u_d_m_f.md#oh_udsappitem_setlabelid) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*appLabelId) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的标签ID。 | 
| int [OH_UdsAppItem_SetBundleName](_u_d_m_f.md#oh_udsappitem_setbundlename) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*bundleName) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的bundle名称。 | 
| int [OH_UdsAppItem_SetAbilityName](_u_d_m_f.md#oh_udsappitem_setabilityname) ([OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem) \*pThis, const char \*abilityName) | 设置桌面图标类型[OH_UdsAppItem](_u_d_m_f.md#oh_udsappitem)对象的ability名称。 | 
