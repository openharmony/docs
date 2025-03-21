# oh_pasteboard_err_code.h

## 概述

声明剪贴板框架错误码信息。 

**库：** libpasteboard.so

**引用文件：** <database/pasteboard/oh_pasteboard_err_code.h>

**系统能力：** SystemCapability.MiscServices.Pasteboard

**起始版本：** 13

**相关模块：**[Pasteboard](_pasteboard.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) | 错误码信息。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [PASTEBOARD_ErrCode](_pasteboard.md#pasteboard_errcode) {<br/>[ERR_OK] = 0, [ERR_PERMISSION_ERROR]) = 201, [ERR_INVALID_PARAMETER] = 401, [ERR_DEVICE_NOT_SUPPORTED] = 801,<br/>[ERR_INNER_ERROR] = 12900000, [ERR_BUSY] = 12900003, [ERR_PASTEBOARD_COPY_FILE_ERROR] = 12900007, [ERR_PASTEBOARD_PROGRESS_START_ERROR] = 12900008, [ERR_PASTEBOARD_PROGRESS_ABNORMAL] = 12900009, [ERR_PASTEBOARD_GET_DATA_FAILED] = 12900010, [ERR_BUSY_PROCESSING] = 27787277, [ERR_COPY_FORBIDDEN] = 27787278<br/>} | 错误码信息。  |
