# IFaceAuthInterface


## 概述

定义获取人脸认证驱动执行器列表的接口。

**起始版本：** 4.0

**相关模块：**[HdfFaceAuth](_hdf_face_auth_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetExecutorListV1_1](#getexecutorlistv1_1) ([out] [IExecutor](interface_i_executor_faceauth_v11.md)[] executorList) | 获得驱动的执行器列表。  | 


## 成员函数说明


### GetExecutorListV1_1()

```
IFaceAuthInterface::GetExecutorListV1_1 ([out] IExecutor[] executorList)
```
**描述**

获得驱动的执行器列表。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executorList | 执行器对象列表。详细说明请参考[IExecutor](interface_i_executor_faceauth_v11.md)。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
