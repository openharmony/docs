# IExecutorCallback


## **概述**

定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_executor.md)。

**Since：**

3.2

**Version:**

1.0

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnResult](#onresult)&nbsp;([in]&nbsp;int&nbsp;result,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo) | 定义操作结果回调函数。 | 
| [OnAcquireInfo](#onacquireinfo)&nbsp;([in]&nbsp;int&nbsp;acquire,&nbsp;[in]&nbsp;unsigned&nbsp;char[]&nbsp;extraInfo) | 定义操作过程信息反馈回调函数。 | 


## **成员函数说明**


### OnAcquireInfo()

  
```
IExecutorCallback::OnAcquireInfo ([in] int acquire, [in] unsigned char[] extraInfo )
```

**描述：**

定义操作过程信息反馈回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| acquire | 提示信息编码[FaceTipsCode](_hdf_face_auth.md#facetipscode)。 | 
| extraInfo | 其他相关信息，用于支持信息扩展。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。


### OnResult()

  
```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```

**描述：**

定义操作请求处理结果回调函数。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| result | 操作请求处理结果。 | 
| extraInfo | 其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。 | 

**返回：**

0 表示操作成功。

非0 表示操作失败。
