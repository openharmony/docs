# 数据管理开发常见问题

## 如何将PixelMap的数据存储到数据库中

适用于：OpenHarmony SDK 3.2.3.5版本

PixelMap应该被转换成相应的ArrayBuffer再放进数据库。

参考文档：[readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## 如何获取rdb关系型数据库文件

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

开发者可使用hdc_std命令拷贝文件，其中文件路径为： /data/app/el2/100/database/包名/entry/db/ ，然后拷贝该路径下后缀为 .db、.db-shm、.db-wal的文件，拷贝完成后，可以通过SQLite工具打开该数据库文件。

示例：

```
 hdc_std file recv /data/app/el2/100/database/com.xxxx.xxxx/entry/db/test.db ./test.db
```

## 数据库在系统层面是否有锁机制，开发过程中是否需要关系数据库加锁问题

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

系统提供的分布式数据服务、关系型数据库和首选项均有锁机制，开发者无需关注。

## 数据库中加事务与不加事务的区别？

适用于：所有版本

在rdb中进行数据操作时，有可能会导致操作失败，出现意料之外的情况。当对数据库进行大量操作时，此种情况会导致部分数据操作失败，部分操作成功，导致部分数据丢失，可能会导致应用程序发生异常甚至崩溃。加事务后，则会将某一批操作组合成一个整体，要么同时成功，要么同时失败，则不会导致强关联的数据部分缺失的情况出现。

## 关系型数据库rdb支持哪些数据类型?

适用于：OpenHarmony SDK 3.0版本以上，API9 Stage模型

关系型数据库rdb支持的数据类型有：number、string、boolean。其中number为数组类型，支持Double，Long，Float，Int，Int64，最大精度为十进制17位数字。

## 如何查看数据库db文件

适用于：OpenHarmony SDK 3.2.6.5版本，API9 Stage模型

1. 执行 hdc_std shell 命令进入系统

2. 找到绝对路径：/data/app/el2/&lt;userId默认是100&gt;/database/&lt;bundleName&gt;
   或找到沙箱路径：

   a. 执行 ps -ef | grep hapName 命令找到对应应用的进程ID，

   b. 数据库沙箱路径为：/proc/&lt;应用进程ID&gt;/root/data/storage/el2/database/。

3. 在数据库的绝对路径或者沙箱路径下执行 find ./ -name "\*.db" 即可找到数据库文件。

## 如何存储长文本数据

适用于：OpenHarmony SDK 3.2.5.5版本，API 9

- 首选项Preferences数据中的Value为string类型时最大支持8192字节。

- 分布式数据管理KV数据模型Value最大支持4M。

参考文档：[首选项概述](../database/database-preference-overview.md)、[分布式数据服务概述](../database/database-mdds-overview.md)

## Stage模型数据共享DataShare开发

适用于：OpenHarmony SDK 3.2.5.5版本，API 9

Stage模型DataShare不可与FA模型DataAbility混用，连接的服务端应用需使用DataShareExtensionAbility实现。

参考文档：[数据共享开发指导](../database/database-datashare-guidelines.md)
