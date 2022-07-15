# HdfUserAuth


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [IUserAuthInterface.idl](_i_user_auth_interface_8idl.md) | 声明用户认证驱动的API接口。接口可用于注册执行器，管理用户认证凭据，完成PIN码和生物特征认证。 | 
| [UserAuthTypes.idl](_user_auth_types_8idl.md) | 定义用户认证驱动的枚举类和数据结构。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IUserAuthInterface](interface_i_user_auth_interface.md) | 声明用户认证驱动的API接口。&nbsp;[更多...](interface_i_user_auth_interface.md) | 
| [ExecutorRegisterInfo](_executor_register_info.md) | 执行器注册信息。&nbsp;[更多...](_executor_register_info.md) | 
| [ExecutorInfo](_executor_info.md) | 执行器信息。&nbsp;[更多...](_executor_info.md) | 
| [ScheduleInfo](_schedule_info.md) | 调度信息。&nbsp;[更多...](_schedule_info.md) | 
| [AuthSolution](_auth_solution.md) | 认证方案。&nbsp;[更多...](_auth_solution.md) | 
| [ExecutorSendMsg](_executor_send_msg.md) | 执行器发送的消息。&nbsp;[更多...](_executor_send_msg.md) | 
| [AuthResultInfo](_auth_result_info.md) | 用户身份认证结果信息。&nbsp;[更多...](_auth_result_info.md) | 
| [IdentifyResultInfo](_identify_result_info.md) | 用户身份识别结果信息。&nbsp;[更多...](_identify_result_info.md) | 
| [EnrollParam](_enroll_param.md) | 注册认证凭据参数。&nbsp;[更多...](_enroll_param.md) | 
| [CredentialInfo](_credential_info.md) | 认证凭据信息。&nbsp;[更多...](_credential_info.md) | 
| [EnrolledInfo](_enrolled_info.md) | 注册信息。&nbsp;[更多...](_enrolled_info.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref2099463766083931,link:zh-cn_topic_0000001295573820.xml#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168](#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref1101090273083931,link:zh-cn_topic_0000001295573820.xml#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691](#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref2144839375083931,link:zh-cn_topic_0000001295573820.xml#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a](#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a)&nbsp;=&nbsp;4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref258518135083931,link:zh-cn_topic_0000001295573820.xml#gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a](#gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a)&nbsp;=&nbsp;0&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](#authtype) | 
| [ExecutorRole](#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref1855863902083931,link:zh-cn_topic_0000001295573820.xml#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec](#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref1503416700083931,link:zh-cn_topic_0000001295573820.xml#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4](#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref902051378083931,link:zh-cn_topic_0000001295573820.xml#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4](#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](#executorrole) | 
| [ExecutorSecureLevel](#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref984255741083931,link:zh-cn_topic_0000001295573820.xml#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638](#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref1990347701083931,link:zh-cn_topic_0000001295573820.xml#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3](#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref849727353083931,link:zh-cn_topic_0000001295573820.xml#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f](#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295573820.xml#xref1372842813083931,link:zh-cn_topic_0000001295573820.xml#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9](#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](#executorsecurelevel) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.user_auth.v1_0 | 用户认证接口的包路径 | 


## **详细描述**

提供用户认证驱动的标准API接口。

用户认证驱动为用户认证服务提供统一的访问接口。获取用户认证驱动代理后，用户认证服务可以调用相关接口注册执行器，管理用户认证凭据， 完成PIN码和生物特征。

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
| ALL | 表示包含所有认证凭据类型。 | 


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
