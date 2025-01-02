# HuksParamSetApi


## 概述

描述HUKS参数集的能力，支持HUKS密钥管理接口的使用，包括初始化参数集、添加参数、构造参数集、释放参数集等HUKS参数集生命周期管理函数， 还包括获取参数、复制参数集、查询参数集、检查是否有效等函数。

**系统能力：** SystemCapability.Security.Huks

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_huks_param.h](native__huks__param_8h.md) | 提供参数集构造、使用和销毁的API。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitParamSet](#oh_huks_initparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 初始化参数集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AddParams](#oh_huks_addparams) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](_o_h___huks___param.md) \*params, uint32_t paramCnt) | 添加参数到参数集里面。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_BuildParamSet](#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 构造正式的参数集。  | 
| void [OH_Huks_FreeParamSet](#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 销毁参数集。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CopyParamSet](#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*\*paramSet) | 复制参数集（深拷贝）。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetParam](#oh_huks_getparam) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](_o_h___huks___param.md) \*\*param) | 从参数集中获取参数。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FreshParamSet](#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, bool isCopy) | 刷新参数集内[OH_Huks_Blob](_o_h___huks___blob.md)类型的数据。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetTagValid](#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | 检查参数集中的参数是否有效、是否有重复。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsParamSetValid](#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, uint32_t size) | 检查参数集大小是否有效。  | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_CheckParamMatch](#oh_huks_checkparammatch) (const struct [OH_Huks_Param](_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](_o_h___huks___param.md) \*param) | 比较两个参数是否相同。 | 
| void [OH_Huks_FreeKeyAliasSet](#oh_huks_freekeyaliasset) (struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*keyAliasSet) | 销毁参数集。  | 


## 函数说明


### OH_Huks_AddParams()

```
struct OH_Huks_Result OH_Huks_AddParams (struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Param * params, uint32_t paramCnt )
```
**描述**
添加参数到参数集里面。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向要被添加参数的参数集的指针。  | 
| params | 指向要添加的参数数组的指针。  | 
| paramCnt | 待添加参数数组的参数个数。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示添加成功，其他时为错误。


### OH_Huks_BuildParamSet()

```
struct OH_Huks_Result OH_Huks_BuildParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**描述**
构造正式的参数集。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向要被正式构造的参数集的指针地址。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示构建成功，其他时为错误。


### OH_Huks_CheckParamMatch()

```
struct OH_Huks_Result OH_Huks_CheckParamMatch (const struct OH_Huks_Param * baseParam, const struct OH_Huks_Param * param )
```
**描述**
比较两个参数是否相同

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| baseParam | 指向被比较的参数的指针。  | 
| param | 指向比较的参数的指针。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示相同，其他时为不同或者错误。


### OH_Huks_CopyParamSet()

```
struct OH_Huks_Result OH_Huks_CopyParamSet (const struct OH_Huks_ParamSet * fromParamSet, uint32_t fromParamSetSize, struct OH_Huks_ParamSet ** paramSet )
```
**描述**
复制参数集（深拷贝）。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fromParamSet | 指向要被复制的参数集的指针。  | 
| fromParamSetSize | 被复制的参数集占用内存的大小。  | 
| paramSet | 指向生成新的参数集的指针地址。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示复制成功，其他时为错误。


### OH_Huks_FreeKeyAliasSet()

```
void OH_Huks_FreeKeyAliasSet (struct OH_Huks_KeyAliasSet * keyAliasSet)
```
**描述**
销毁参数集。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyAliasSet | 指向要被销毁的参数集的指针地址。  | 


### OH_Huks_FreeParamSet()

```
void OH_Huks_FreeParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**描述**
销毁参数集。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向要被销毁的参数集的指针地址。  | 


### OH_Huks_FreshParamSet()

```
struct OH_Huks_Result OH_Huks_FreshParamSet (struct OH_Huks_ParamSet * paramSet, bool isCopy )
```
**描述**
刷新参数集内**[OH_Huks_Blob](_o_h___huks___blob.md)**类型的数据。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向参数集的指针。  | 
| isCopy | 如果为true，刷新[OH_Huks_Blob](_o_h___huks___blob.md)类型数据的地址并复制到参数集。否则，只会刷新[OH_Huks_Blob](_o_h___huks___blob.md)类型数据的地址。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示成功，其他时为错误。


### OH_Huks_GetParam()

```
struct OH_Huks_Result OH_Huks_GetParam (const struct OH_Huks_ParamSet * paramSet, uint32_t tag, struct OH_Huks_Param ** param )
```
**描述**
从参数集中获取参数。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向参数集的指针。  | 
| tag | 要获取的对应参数的值。  | 
| param | 指向获取到的参数的指针地址。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示获取成功，其他时为错误。


### OH_Huks_InitParamSet()

```
struct OH_Huks_Result OH_Huks_InitParamSet (struct OH_Huks_ParamSet ** paramSet)
```
**描述**
初始化参数集。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向要初始化的参数集的指针地址。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示初始化成功，其他时为错误。


### OH_Huks_IsParamSetTagValid()

```
struct OH_Huks_Result OH_Huks_IsParamSetTagValid (const struct OH_Huks_ParamSet * paramSet)
```
**描述**
检查参数集中的参数是否有效、是否有重复。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向参数集的指针。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示有效，其他时为无效或重复的。


### OH_Huks_IsParamSetValid()

```
struct OH_Huks_Result OH_Huks_IsParamSetValid (const struct OH_Huks_ParamSet * paramSet, uint32_t size )
```
**描述**
检查参数集大小是否有效。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| paramSet | 指向参数集的指针。  | 
| size | 参数集占用的内存大小。  | 

**返回：**

返回[OH_Huks_ErrCode#OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode)时表示有效，其他时为无效或者错误。
