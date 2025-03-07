# oh_preferences_err_code.h


## 概述

声明首选项模块统一使用的错误码信息。

**引用文件：**&lt;database/preferences/oh_preferences_err_code.h&gt;

**库：** libohpreferences.so

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**起始版本：** 13

**相关模块：**[Preferences](_preferences.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) | 错误码信息。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Preferences_ErrCode](_preferences.md#oh_preferences_errcode) {<br/>PREFERENCES_OK = 0, PREFERENCES_ERROR_INVALID_PARAM = 401, PREFERENCES_ERROR_NOT_SUPPORTED = 801, PREFERENCES_ERROR_BASE = 15500000,<br/>PREFERENCES_ERROR_DELETE_FILE = 15500010, PREFERENCES_ERROR_STORAGE = 15500011, PREFERENCES_ERROR_MALLOC = 15500012, PREFERENCES_ERROR_KEY_NOT_FOUND= 15500013,<br/>PREFERENCES_ERROR_GET_DATAOBSMGRCLIENT = 15500019<br/>} | 错误码信息。  |
