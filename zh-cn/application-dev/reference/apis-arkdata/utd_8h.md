# utd.h


## 概述

提供标准化数据类型描述相关接口和数据结构。

**引用文件：**&lt;database/udmf/utd.h&gt;

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：**[UDMF](_u_d_m_f.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Utd](_u_d_m_f.md#oh_utd) [OH_Utd](_u_d_m_f.md#oh_utd) | 统一数据类型描述符。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Utd](_u_d_m_f.md#oh_utd) \* [OH_Utd_Create](_u_d_m_f.md#oh_utd_create) (const char \*typeId) | 创建统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)指针及实例对象。 | 
| void [OH_Utd_Destroy](_u_d_m_f.md#oh_utd_destroy) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | 销毁统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)指针指向的实例对象。 | 
| const char \* [OH_Utd_GetTypeId](_u_d_m_f.md#oh_utd_gettypeid) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)中的类型ID。 | 
| const char \* [OH_Utd_GetDescription](_u_d_m_f.md#oh_utd_getdescription) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)中的描述信息。 | 
| const char \* [OH_Utd_GetReferenceUrl](_u_d_m_f.md#oh_utd_getreferenceurl) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)中的URL信息。 | 
| const char \* [OH_Utd_GetIconFile](_u_d_m_f.md#oh_utd_geticonfile) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)中的默认图标文件路径。 | 
| const char \*\* [OH_Utd_GetBelongingToTypes](_u_d_m_f.md#oh_utd_getbelongingtotypes) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)中的归属关系结果集。 | 
| const char \*\* [OH_Utd_GetFilenameExtensions](_u_d_m_f.md#oh_utd_getfilenameextensions) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | 获取统一数据类型[OH_Utd](_u_d_m_f.md#oh_utd)所关联的的文件名后缀结果集。 | 
| const char \*\* [OH_Utd_GetMimeTypes](_u_d_m_f.md#oh_utd_getmimetypes) ([OH_Utd](_u_d_m_f.md#oh_utd) \*pThis, unsigned int \*count) | 获取[OH_Utd](_u_d_m_f.md#oh_utd)所关联的MIME类型结果集。 | 
| const char \*\* [OH_Utd_GetTypesByFilenameExtension](_u_d_m_f.md#oh_utd_gettypesbyfilenameextension) (const char \*extension, unsigned int \*count) | 通过文件名后缀获取关联的统一标准数据描述类型结果集。 | 
| const char \*\* [OH_Utd_GetTypesByMimeType](_u_d_m_f.md#oh_utd_gettypesbymimetype) (const char \*mimeType, unsigned int \*count) | 通过MIME类型获取所关联的标准数据类型结果集。 | 
| bool [OH_Utd_BelongsTo](_u_d_m_f.md#oh_utd_belongsto) (const char \*srcTypeId, const char \*destTypeId) | 判断两个标准化数据描述类型是否存在归属关系。 | 
| bool [OH_Utd_IsLower](_u_d_m_f.md#oh_utd_islower) (const char \*srcTypeId, const char \*destTypeId) | 判断原标准化数据类型是否是目标标准化数据类型的低层级类型。 例如TYPE_SCRIPT为SOURCE_CODE的低层级类型，TYPE_SCRIPT和SOURCE_CODE为PLAIN_TEXT的低层级类型。 | 
| bool [OH_Utd_IsHigher](_u_d_m_f.md#oh_utd_ishigher) (const char \*srcTypeId, const char \*destTypeId) | 判断原标准化数据类型是否是目标标准化数据类型的高层级类型。 例如SOURCE_CODE为TYPE_SCRIPT的高层级类型，PLAIN_TEXT为SOURCE_CODE和TYPE_SCRIPT的高层级类型。 | 
| bool [OH_Utd_Equals](_u_d_m_f.md#oh_utd_equals) ([OH_Utd](_u_d_m_f.md#oh_utd) \*utd1, [OH_Utd](_u_d_m_f.md#oh_utd) \*utd2) | 判断两个标准化数据描述类型是否相等。 | 
| void [OH_Utd_DestroyStringList](_u_d_m_f.md#oh_utd_destroystringlist) (const char \*\*list, unsigned int count) | 销毁标准数据描述类型结果集字符串列表。 | 
