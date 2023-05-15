# 数据管理开发常见问题


## 关系型数据库rdb中如何进行加密

适用于：Openharmony 3.1 Beta5  API 9

**解决措施**

创建关系型数据库，可通过StoreConfig管理关系型数据库配置，其中encrypt属性指定数据库是否加密。

**参考链接**

[关系型数据库](../reference/apis/js-apis-data-relationalStore.md#storeconfig)

## 关系型数据库rdb中使用TRUNCATE TABLE语句无法清空表数据 

适用于：OpenHarmony SDK 3.2.9.2版本，API9

**问题现象**

通过TRUNCATE TABLE语句清空表数据时报错。

**解决措施**

关系型数据库rdb使用Sqlite数据库， 它不支持 TRUNCATE TABLE 语句，建议使用delete语句，如：DELETE FROM sqlite\_sequence WHERE name = 'table\_name' ，另外发生该错误会抛出空异常。



## 关系型数据库rdb支持哪些数据类型

适用于：OpenHarmony SDK 3.0版本以上，API 9 Stage模型

**解决措施**

关系型数据库rdb支持的数据类型有：number、string、boolean。其中number为数字类型，支持Double，Long，Float，Int，Int64，最大精度为十进制17位数字。

## 如何将PixelMap的数据存储到数据库中  

适用于：OpenHarmony 3.2 Beta5  API 9

**问题现象**

存储PixelMap的数据

**解决措施**

PixelMap应该被转换成相应的ArrayBuffer再放进数据库。

**参考链接**

[readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## 如何获取rdb关系型数据库文件 

适用于：OpenHarmony 3.2 Beta5  API 9

**问题现象**

关系型数据库的获取问题

**解决措施**

开发者可使用hdc命令拷贝文件，其中文件路径为： /data/app/el2/100/database/包名/entry/rdb/ ，然后拷贝该路径下的文件，拷贝完成后，可以通过SQLite工具打开该数据库文件。

示例：

```
 hdc file recv /data/app/el2/100/database/<bundleName>/entry/db/<tableName>  ./<path>
```

## 数据库在系统层面是否有锁机制，开发过程中是否需要关系数据库加锁问题 

适用于：OpenHarmony 3.2 Beta5  API 9

**问题现象**

关系型数据库的加锁疑问

**解决措施**

系统提供的分布式数据服务、关系型数据库和首选项均有锁机制，开发者无需关注。

## 在@ohos.data.storage轻量级存储中，调用put方法保存数据后，再重启应用后调用get方法为什么无法获取到保存的值

适用于：OpenHarmony 3.2 Beta5  API 9

**问题现象**

关系型数据库的保存以及重启时的调用

**解决措施**

在storage轻量级存储中，调用put方法，只是将数据保存在内存中，并不会持久化到硬盘中，在退出应用后会将内存中的数据清空。如果想持久化到硬盘中，则在调用put方法后需要再调用flush或flushSync接口才行。数据持久化后重启应用时就可以通过get方法获取到之前保存的数据。


## rdb关系型数据库中TEXT类型保存超长文本失败

适用于：OpenHarmony 3.2 Beta5  API 9

**问题现象**

API8版本rdb关系型数据库中TEXT类型保存超长文本失败

**解决措施**

API9版本之前对TEXT文本存储长度限制在1024字节，所以会存在超长文本保存失败的情况。

在API9的版本中已经放开了长度限制。

