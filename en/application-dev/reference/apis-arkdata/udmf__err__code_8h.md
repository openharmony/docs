# udmf_err_code.h


## Overview

Declares the error codes used in the UDMF.

**File to include**: &lt;database/udmf/udmf_err_code.h&gt;

**Library**: libudmf.so

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Since**: 12

**Related module**: [UDMF](_u_d_m_f.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode) [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode) | Defines an enum for error codes.| 
| typedef enum [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus) [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus) | Defines an enum for the status codes returned when data is obtained asynchronously.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Udmf_ErrCode](_u_d_m_f.md#udmf_errcode-1) { UDMF_E_OK = 0, UDMF_ERR = 20400000, UDMF_E_INVALID_PARAM = (UDMF_ERR + 1) } | Enumerates the error codes.| 
| [Udmf_ListenerStatus](_u_d_m_f.md#udmf_listenerstatus-1) {<br>UDMF_FINISHED = 0, UDMF_PROCESSING, UDMF_CANCELED, UDMF_INNER_ERROR = 200,<br>UDMF_INVALID_PARAMETERS, UDMF_DATA_NOT_FOUND, UDMF_SYNC_FAILED, UDMF_COPY_FILE_FAILED<br>} | Enumerates the status codes returned when data is obtained asynchronously.| 
