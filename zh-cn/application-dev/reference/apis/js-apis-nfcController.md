# 标准NFC-Tag

本模块主要用于操作及管理NFC Tag。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## **导入模块**

```
import tag from '@ohos.nfc.tag';
```


## tag.getNfcATag

getNfcATag(tagInfo: TagInfo): NfcATag

获取NFC A类型Tag对象，通过该对象访问NfcA技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| NfcATag | NFC A类型Tag对象 |

## tag.getNfcBTag

getNfcBTag(tagInfo: TagInfo): NfcBTag

获取NFC B类型Tag对象，通过该对象访问NfcB技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| NfcBTag  | NFC B类型Tag对象 |

## tag.getNfcFTag

getNfcFTag(tagInfo: TagInfo): NfcFTag

获取NFC F类型Tag对象，通过该对象访问NfcF技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| NfcFTag  | NFC F类型Tag对象 |

## tag.getNfcVTag

getNfcVTag(tagInfo: TagInfo): NfcVTag

获取NFC V类型Tag对象，通过该对象访问NfcV技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| NfcVTag  | NFC V类型Tag对象 |