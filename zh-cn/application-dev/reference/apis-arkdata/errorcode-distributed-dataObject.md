# 分布式数据对象错误码
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @lvcong_oh-->
<!--SE: @hollokin; @yuchaozhng-->
<!--TSE: @lj_liujing; @yippo; @logic42-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 15400001 创建内存数据库失败

**错误信息**

Failed to create the in-memory database.

**错误描述**

创建内存数据库失败。

**可能原因**

已有其他分布式数据对象设置了相同的sessionId。

**处理步骤**

使用[genSessionId](../../reference/apis-arkdata/js-apis-data-distributedobject.md#distributeddataobjectgensessionid)生成随机的sessionId，避免和其他分布式数据对象使用相同的sessionId。

## 15400002 参数错误

**错误信息**

Parameter error.

**错误描述**

1. assetKey无效。例如：""（空字符串）。

2. uri无效。例如：""（空字符串）。

3. uris无效。例如uris数组长度超过50。

**可能原因**

1.分布式对象中资产类型对应的属性名无效，例如：null（不存在）、undefined（未定义）或''（空字符串）。

2.待设置的资产需要的分布式路径uri无效，例如：null（不存在）、undefined（未定义）或''（空字符串）。

3.待设置的资产存放的分布式路径数组为空或数组内元素数量大于50个。

4.待设置的资产存放的分布式路径数组中存在某个或多个uri无效，例如：null（不存在）、undefined（未定义）或''（空字符串）。

**处理步骤**

1.传入正确的属性名，例如:'file'（文件）。

2.传入正确的分布式路径uri，例如:"file://docs/storage/Users/username/tmp.txt"。

3.传入正确的分布式路径数组uris，数量为有效范围内的个数，例如:["file://docs/storage/Users/username/tmp.txt"，"file://com.example.demo/data/storage/el2/base/files/test.txt"]。

4.确保分布式路径数组uris内每个uri的路径为正确的分布式路径。

## 15400003 已设置分布式对象的sessionId

**错误信息**

The sessionId of the distributed object has been set.

**错误描述**

已设置分布式对象的sessionId。

**可能原因**

当前分布式数据对象已经设置sessionId。

**处理步骤**

使用[setSessionId](js-apis-data-distributedobject.md#setsessionid9-2)取消已设置的sessionId，再进行设置资产或资产数组。