# 统一数据管理框架错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 20400001 设置已存在

**错误信息**

Settings already exist.

**错误描述**

应用程序设置拖拽通道数据可使用的范围时，将要设置的信息在数据库中已存在。

**可能原因**

调用[setAppShareOptions](js-apis-data-unifiedDataChannel-sys.md#unifieddatachannelsetappshareoptions12)重复设置拖拽通道数据可使用的范围时，系统会产生此错误码。

**处理步骤**

先调用[removeAppShareOptions](js-apis-data-unifiedDataChannel-sys.md#unifieddatachannelremoveappshareoptions12)清除当前拖拽通道数据可使用的范围后，再调用[setAppShareOptions](js-apis-data-unifiedDataChannel-sys.md#unifieddatachannelsetappshareoptions12)重新设置。
