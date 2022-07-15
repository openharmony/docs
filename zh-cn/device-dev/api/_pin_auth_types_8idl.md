# PinAuthTypes.idl


## **概述**

**所属模块:**

[HdfPinAuth](_hdf_pin_auth.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [ExecutorInfo](_executor_info.md) | 执行器信息。&nbsp;[更多...](_executor_info.md) | 
| [TemplateInfo](_template_info.md) | 凭据模版信息。&nbsp;[更多...](_template_info.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [AuthType](_hdf_face_auth.md#authtype)&nbsp;:&nbsp;int&nbsp;{&nbsp;[PIN](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168)&nbsp;=&nbsp;1,&nbsp;[FACE](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691)&nbsp;=&nbsp;2,&nbsp;[FINGERPRINT](_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a)&nbsp;=&nbsp;4&nbsp;} | 枚举用户认证凭据类型。&nbsp;[更多...](_hdf_face_auth.md#authtype) | 
| [ExecutorRole](_hdf_face_auth.md#executorrole)&nbsp;:&nbsp;int&nbsp;{&nbsp;[COLLECTOR](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec)&nbsp;=&nbsp;1,&nbsp;[VERIFIER](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4)&nbsp;=&nbsp;2,&nbsp;[ALL_IN_ONE](_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器角色。&nbsp;[更多...](_hdf_face_auth.md#executorrole) | 
| [ExecutorSecureLevel](_hdf_face_auth.md#executorsecurelevel)&nbsp;:&nbsp;int&nbsp;{&nbsp;[ESL0](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638)&nbsp;=&nbsp;0,&nbsp;[ESL1](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3)&nbsp;=&nbsp;1,&nbsp;[ESL2](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f)&nbsp;=&nbsp;2,&nbsp;[ESL3](_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9)&nbsp;=&nbsp;3&nbsp;} | 枚举执行器安全等级。&nbsp;[更多...](_hdf_face_auth.md#executorsecurelevel) | 
| [CommandId](_hdf_face_auth.md#commandid)&nbsp;:&nbsp;int&nbsp;{&nbsp;[DEFAULT](_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6)&nbsp;=&nbsp;0&nbsp;} | 枚举口令认证功能相关操作命令。&nbsp;[更多...](_hdf_face_auth.md#commandid) | 
| [FaceTipsCode](_hdf_face_auth.md#facetipscode)&nbsp;:&nbsp;int&nbsp;{&nbsp;&nbsp;&nbsp;[FACE_AUTH_TIP_TOO_BRIGHT](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc)&nbsp;=&nbsp;1,&nbsp;[FACE_AUTH_TIP_TOO_DARK](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe)&nbsp;=&nbsp;2,&nbsp;[FACE_AUTH_TIP_TOO_CLOSE](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17)&nbsp;=&nbsp;3,&nbsp;[FACE_AUTH_TIP_TOO_FAR](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e)&nbsp;=&nbsp;4,&nbsp;&nbsp;&nbsp;[FACE_AUTH_TIP_TOO_HIGH](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b)&nbsp;=&nbsp;5,&nbsp;[FACE_AUTH_TIP_TOO_LOW](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8)&nbsp;=&nbsp;6,&nbsp;[FACE_AUTH_TIP_TOO_RIGHT](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810)&nbsp;=&nbsp;7,&nbsp;[FACE_AUTH_TIP_TOO_LEFT](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572)&nbsp;=&nbsp;8,&nbsp;&nbsp;&nbsp;[FACE_AUTH_TIP_TOO_MUCH_MOTION](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd)&nbsp;=&nbsp;9,&nbsp;[FACE_AUTH_TIP_POOR_GAZE](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7)&nbsp;=&nbsp;10,&nbsp;[FACE_AUTH_TIP_NOT_DETECTED](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8)&nbsp;=&nbsp;11,&nbsp;[VENDOR_FACE_AUTH_TIP_BEGIN](_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab)&nbsp;=&nbsp;10000&nbsp;} | 枚举提示信息编码。&nbsp;[更多...](_hdf_face_auth.md#facetipscode) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.pin_auth.v1_0 | 口令认证接口的包路径 | 


## **详细描述**

定义口令认证驱动的枚举类和数据结构。

**Since：**

3.2
