# 数据共享错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 15700010 创建DataShareHelper异常

**错误信息**

The DataShareHelper is not initialized successfully.

**错误描述**

创建DataShareHelper工具类异常时，系统会产生此错误码。

**可能原因**

1. 创建DataShareHelper时，接口createDataHelper的入参uri不正确。
2. 创建DataShareHelper时，接口createDataHelper的入参context不正确。
3. 创建DataShareHelper时，客户端从后台拉起DataShareExtension时，未配置后台拉起权限。

**处理步骤**

1. 咨询DataShare服务端提供者，获取正确的uri路径。
2. DataShare仅支持Stage模型，检查context是否为Stage模型的context。
3. 检查客户端是否有数据的读或者写权限，具体步骤如下：
    (1) 找到数据提供者包名，在uri的path里面找，例如：uri = "datashareproxy://com.acts.ohos.data.datasharetest/test"。
    (2) 根据包名找到配置，例如：bm dump --bundle-name com.acts.ohos.data.datasharetest，在里面找到DataShareExtension的配置，确认数据访问者是否有readPermission或writePermission中配置的权限。

## 15700011 uri不存在

**错误信息**

The URI does not exist.

**错误描述**

添加/删除模板异常或者开启/关闭静默访问传入的uri格式或者路径错误时，系统会产生此错误码。

**可能原因**

1. 入参uri路径不正确。
2. 入参uri格式不正确。

**处理步骤**

咨询DataShare服务端提供者，获取正确的uri路径。

## 15700012 数据区不存在

**错误信息**

The data area does not exist.

**错误描述**

数据更新异常时，系统会产生此错误码。

**可能原因**

数据更新异常时，接口publish的入参bundleName不正确。

**处理步骤**

咨询DataShare服务端提供者，获取正确的bundleName。

## 15700013 DataShareHelper实例被关闭

**错误信息**

The DataShareHelper instance is already closed.

**错误描述**

DataShareHelper实例被关闭后，继续使用该实例会产生此错误码。

**可能原因**

调用close接口关闭了DataShareHelper实例后，继续使用该实例。

**处理步骤**

重新创建DataShareHelper实例，再进行使用。