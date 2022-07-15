# HdfFaceAuth


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [FaceAuthTypes.idl](_face_auth_types_8idl.md) | 定义人脸认证驱动的枚举类和数据结构。 | 
| [IExecutor.idl](face__auth_2_i_executor_8idl.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 | 
| [IExecutorCallback.idl](face__auth_2_i_executor_callback_8idl.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。 | 
| [IFaceAuthInterface.idl](_i_face_auth_interface_8idl.md) | 定义获取人脸认证驱动的执行器列表接口，用于从人脸认证驱动获取执行器对象列表。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [ExecutorInfo](_executor_info.md) | 执行器信息。&nbsp;[更多...](_executor_info.md) | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。&nbsp;[更多...](_template_info.md) | 
| [IExecutor](interface_i_executor.md) | 定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。&nbsp;[更多...](interface_i_executor.md) | 
| [IExecutorCallback](interface_i_executor_callback.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。使用细节见[IExecutor](interface_i_executor.md)。&nbsp;[更多...](interface_i_executor_callback.md) | 
| [IFaceAuthInterface](interface_i_face_auth_interface.md) | 定义获取人脸认证驱动的执行器列表接口。&nbsp;[更多...](interface_i_face_auth_interface.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[PIN](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168)&nbsp;=&nbsp;1,&nbsp;[FACE](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691)&nbsp;=&nbsp;2,&nbsp;[FINGERPRINT](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a)&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](#authtype) | 
| [ExecutorRole](#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[COLLECTOR](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec)&nbsp;=&nbsp;1,&nbsp;[VERIFIER](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4)&nbsp;=&nbsp;2,&nbsp;[ALL_IN_ONE](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](#executorrole) | 
| [ExecutorSecureLevel](#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ESL0](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638)&nbsp;=&nbsp;0,&nbsp;[ESL1](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3)&nbsp;=&nbsp;1,&nbsp;[ESL2](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f)&nbsp;=&nbsp;2,&nbsp;[ESL3](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](#executorsecurelevel) | 
| [CommandId](#commandid)&nbsp;:&nbsp;int&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref313653401083931,link:#entry1378875880083931p0](#entry1378875880083931p0)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref148718194083931,link:#entry1786148552083931p0](#entry1786148552083931p0)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref2084154321083931,link:#entry1330595345083931p0](#entry1330595345083931p0)&nbsp;=&nbsp;10000&nbsp;} | 枚举人脸认证功能相关操作命令。&nbsp;[更多...](#commandid) | 
| [FaceTipsCode](#facetipscode)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1058539048083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc](#ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref2091712261083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe](#ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref2114375419083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17](#ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17)&nbsp;=&nbsp;3,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref640599540083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e](#ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e)&nbsp;=&nbsp;4,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref716207804083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b](#ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b)&nbsp;=&nbsp;5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1534653669083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8](#ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8)&nbsp;=&nbsp;6,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref840994427083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810](#ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810)&nbsp;=&nbsp;7,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref480644543083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572](#ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572)&nbsp;=&nbsp;8,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1440203875083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd](#ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd)&nbsp;=&nbsp;9,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1366149389083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7](#ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7)&nbsp;=&nbsp;10,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1532937057083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8](#ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8)&nbsp;=&nbsp;11,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295414192.xml#xref1048618882083931,link:zh-cn_topic_0000001295414192.xml#ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab](#ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab)&nbsp;=&nbsp;10000&nbsp;} | 枚举提示信息编码。&nbsp;[更多...](#facetipscode) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.face_auth.v1_0 | 人脸认证接口的包路径 | 


## **详细描述**

提供人脸认证驱动的标准API接口。

人脸认证驱动为人脸认证服务提供统一的访问接口。获取人脸认证驱动代理后，人脸认证服务可以调用相关接口获取执行器，获取人脸认证执行器后， 人脸认证服务可以调用相关接口获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**Since：**

3.2


## **枚举类型说明**


### AuthType

  
```
enum AuthType : int
```

**描述：**

枚举用户认证凭据类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| PIN | 认证凭据类型为口令。 | 
| FACE | 认证凭据类型为人脸。 | 
| FINGERPRINT | 认证凭据类型为指纹。 | 


### CommandId

  
```
enum CommandId : int
```

**描述：**

枚举人脸认证功能相关操作命令。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LOCK_TEMPLATE | 锁定人脸模版。 | 
| UNLOCK_TEMPLATE | 解锁人脸模版。 | 
| VENDOR_COMMAND_BEGIN | 用于厂商自定义操作指令。 | 


### ExecutorRole

  
```
enum ExecutorRole : int
```

**描述：**

枚举执行器角色。

  | 枚举值 | 描述 | 
| -------- | -------- |
| COLLECTOR | 执行器角色为采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。 | 
| VERIFIER | 执行器角色为认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。 | 
| ALL_IN_ONE | 执行器角色为全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。 | 


### ExecutorSecureLevel

  
```
enum ExecutorSecureLevel : int
```

**描述：**

枚举执行器安全等级。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ESL0 | 执行器安全级别为0，关键操作在无访问控制执行环境中完成。 | 
| ESL1 | 执行器安全级别为1，关键操作在有访问控制的执行环境中完成。 | 
| ESL2 | 执行器安全级别为2，关键操作在可信执行环境中完成。 | 
| ESL3 | 执行器安全级别为3，关键操作在高安环境如独立安全芯片中完成。 | 


### FaceTipsCode

  
```
enum FaceTipsCode : int
```

**描述：**

枚举提示信息编码。

  | 枚举值 | 描述 | 
| -------- | -------- |
| FACE_AUTH_TIP_TOO_BRIGHT | 获取的人脸图像由于光照度高而过亮。 | 
| FACE_AUTH_TIP_TOO_DARK | 获取的人脸图像由于光照度低而过暗。 | 
| FACE_AUTH_TIP_TOO_CLOSE | 人脸离设备过近。 | 
| FACE_AUTH_TIP_TOO_FAR | 人脸离设备过远。 | 
| FACE_AUTH_TIP_TOO_HIGH | 设备过高，只拍到人脸的上半部分。 | 
| FACE_AUTH_TIP_TOO_LOW | 设备过低，只拍到人脸的下半部分。 | 
| FACE_AUTH_TIP_TOO_RIGHT | 设备偏右，只拍到人脸的右侧部分。 | 
| FACE_AUTH_TIP_TOO_LEFT | 设备偏左，只拍到人脸的左侧部分。 | 
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 人脸信息采集过程中，人脸移动过多。 | 
| FACE_AUTH_TIP_POOR_GAZE | 用户未注视设备。 | 
| FACE_AUTH_TIP_NOT_DETECTED | 未检测到人脸。 | 
| VENDOR_FACE_AUTH_TIP_BEGIN | 用于厂商自定义提示信息。 | 
