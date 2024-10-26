# IExecutor


## 概述

定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**起始版本：** 4.0

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetProperty](#getproperty) ([in] unsigned long[] templateIdList, [in] enum [GetPropertyType](_hdf_face_auth_v11.md#getpropertytype)[] propertyTypes, [out] struct [Property](_property_faceauth_v11.md) property) | 获得人脸执行器属性。  | 
| [SetCachedTemplates](#setcachedtemplates) ([in] unsigned long[] templateIdList) | 设置缓存模板。  | 
| [RegisterSaCommandCallback](#registersacommandcallback) ([in] [ISaCommandCallback](interface_i_sa_command_callback_faceauth_v11.md) callbackObj) | 注册sa命令回调。  | 


## 成员函数说明


### GetProperty()

```
IExecutor::GetProperty ([in] unsigned long[] templateIdList, [in] enum GetPropertyType[] propertyTypes, [out] struct Property property )
```
**描述**

获得人脸执行器属性。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 模板id列表。  | 
| propertyTypes | 人脸执行器属性类型。详细说明请参考[GetPropertyType](_hdf_face_auth_v11.md#getpropertytype)。  | 
| property | 人脸执行器属性。详细说明请参考[Property](_property_faceauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### RegisterSaCommandCallback()

```
IExecutor::RegisterSaCommandCallback ([in] ISaCommandCallback callbackObj)
```
**描述**

注册sa命令回调。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 表示sa命令回调。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### SetCachedTemplates()

```
IExecutor::SetCachedTemplates ([in] unsigned long[] templateIdList)
```
**描述**

设置缓存模板。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| templateIdList | 人脸缓存的模板列表。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
