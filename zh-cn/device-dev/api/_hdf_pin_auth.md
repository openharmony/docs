# HdfPinAuth


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [IExecutor.idl](pin__auth_2_i_executor_8idl.md) | 定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。 | 
| [IExecutorCallback.idl](pin__auth_2_i_executor_callback_8idl.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。 | 
| [IPinAuthInterface.idl](_i_pin_auth_interface_8idl.md) | 定义获取口令认证驱动的执行器列表接口，用于从口令认证驱动获取执行器对象列表。 | 
| [PinAuthTypes.idl](_pin_auth_types_8idl.md) | 定义口令认证驱动的枚举类和数据结构。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IExecutor](interface_pin_i_executor.md) | 定义执行器标准API接口。接口可用于获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。[更多...](interface_pin_i_executor.md) | 
| [IExecutorCallback](interface_i_executor_callback.md) | 定义异步API接口回调，用于返回异步接口的请求处理结果和信息。使用细节见[IExecutor](interface_i_executor.md)。&nbsp;[更多...](interface_i_executor_callback.md) | 
| [IPinAuthInterface](interface_i_pin_auth_interface.md) | 定义获取口令认证驱动的执行器列表接口。&nbsp;[更多...](interface_i_pin_auth_interface.md) | 
| [ExecutorInfo](_executor_info.md) | 执行器信息。&nbsp;[更多...](_executor_info.md) | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。&nbsp;[更多...](_template_info.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[PIN](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168)&nbsp;=&nbsp;1,&nbsp;[FACE](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691)&nbsp;=&nbsp;2,&nbsp;[FINGERPRINT](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a)&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](#authtype) | 
| [ExecutorRole](#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[COLLECTOR](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec)&nbsp;=&nbsp;1,&nbsp;[VERIFIER](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4)&nbsp;=&nbsp;2,&nbsp;[ALL_IN_ONE](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](#executorrole) | 
| [ExecutorSecureLevel](#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ESL0](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638)&nbsp;=&nbsp;0,&nbsp;[ESL1](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3)&nbsp;=&nbsp;1,&nbsp;[ESL2](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f)&nbsp;=&nbsp;2,&nbsp;[ESL3](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](#executorsecurelevel) | 
| [CommandId](#commandid)&nbsp;:&nbsp;int&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295254320.xml#xref679966451083931,link:zh-cn_topic_0000001295254320.xml#gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6](#gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6)&nbsp;=&nbsp;0&nbsp;} | 枚举口令认证相关功能操作命令。&nbsp;[更多...](#commandid) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.pin_auth.v1_0 | 口令认证接口的包路径 | 


## **详细描述**

提供口令认证驱动的标准API接口。

口令认证驱动为口令认证服务提供统一的访问接口。获取口令认证驱动代理后，口令认证服务可以调用相关接口获取执行器，获取口令认证执行器后， 口令认证服务可以调用相关接口获取执行器信息，获取凭据模版信息，注册口令，认证口令，删除口令等。

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

枚举口令认证相关功能操作命令。

  | 枚举值 | 描述 | 
| -------- | -------- |
| DEFAULT | 默认无效操作命令。 | 


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
