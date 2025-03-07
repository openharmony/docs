# udmf_err_code.h


## 概述

声明统一数据管理框架错误码信息。

**引用文件：**&lt;database/udmf/udmf_err_code.h&gt;

**库：** libudmf.so

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**起始版本：** 12

**相关模块：**[UDMF](_u_d_m_f.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode) [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode) | 错误码信息。 | 
| typedef enum [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus) [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus) | 异步获取数据时的状态码枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode-1) { UDMF_E_OK = 0, UDMF_ERR = 20400000, UDMF_E_INVALID_PARAM = (UDMF_ERR + 1) } | 错误码信息。 | 
| [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus-1) {<br/>UDMF_FINISHED = 0, UDMF_PROCESSING, UDMF_CANCELED, UDMF_INNER_ERROR = 200,<br/>UDMF_INVALID_PARAMETERS, UDMF_DATA_NOT_FOUND, UDMF_SYNC_FAILED, UDMF_COPY_FILE_FAILED<br/>} | 异步获取数据时的状态码枚举。 | 
