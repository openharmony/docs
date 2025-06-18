# 数据管理开发常见问题


## 关系型数据库rdb中如何进行加密(API 9)

**解决措施**

创建关系型数据库，可通过StoreConfig管理关系型数据库配置，其中encrypt属性指定数据库是否加密。

**参考链接**

[关系型数据库](../reference/apis-arkdata/arkts-apis-data-relationalStore-i.md#storeconfig)


## 关系型数据库rdb中使用TRUNCATE TABLE语句无法清空表数据(API 9)

**问题现象**

通过TRUNCATE TABLE语句清空表数据时报错。

**解决措施**

关系型数据库rdb使用Sqlite数据库， 它不支持 TRUNCATE TABLE 语句，建议使用delete语句，如：DELETE FROM sqlite_sequence WHERE name = 'table_name' ，另外发生该错误会抛出空异常。


## 关系型数据库rdb支持哪些数据类型(API 9)

适用于Stage模型。

**解决措施**

关系型数据库rdb支持的数据类型有：number、string、boolean。其中number为数字类型，支持Double，Long，Float，Int，Int64，最大精度为十进制17位数字。


## 如何实现应用数据持久化存储(API 9)

**解决措施**

通过PersistentStorage类实现管理应用持久化数据，可以将特定标记的持久化数据链接到AppStorage中，并由AppStorage接口访问对应持久化数据。PersistentStorage持久化后的数据会生成本地xml文件保存，文件路径为/data/app/el2/100/base/&lt;bundleName&gt;/haps/&lt;hapName&gt;/files/persistent_storage。

示例：

```
AppStorage.Link('varA')
PersistentStorage.PersistProp("varA", "111");
@Entry
@Component
struct Index {
  @StorageLink('varA') varA: string = ''
  build() {
    Column() {
      Text('varA: ' + this.varA).fontSize(20)
      Button('Set').width(100).height(100).onClick(() => {
        this.varA += '333'
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

**参考链接**

[持久化数据管理\(OpenHarmony\)](../ui/state-management/arkts-persiststorage.md)


## 如何将PixelMap的数据存储到数据库中(API 9)

**解决措施**

PixelMap应该被转换成相应的ArrayBuffer再放进数据库。

**参考链接**

[readPixelsToBuffer](../reference/apis-image-kit/arkts-apis-image-PixelMap.md#readpixelstobuffer7-1)


## 如何获取rdb关系型数据库文件(API 9)

**问题现象**

关系型数据库的获取问题

**解决措施**

开发者可使用hdc命令拷贝文件，其中文件路径为： /data/app/el2/100/database/包名/entry/rdb/ ，然后拷贝该路径下的文件，拷贝完成后，可以通过SQLite工具打开该数据库文件。

示例：

```
 hdc file recv /data/app/el2/100/database/<bundleName>/entry/db/<tableName>  ./<path>
```


## 数据库在系统层面是否有锁机制，开发过程中是否需要关系数据库加锁问题(API 9)

**问题现象**

关系型数据库的加锁疑问

**解决措施**

系统提供的分布式数据服务、关系型数据库和首选项均有锁机制，开发者无需关注。


## 在\@ohos.data.storage轻量级存储中，调用put方法保存数据后，再重启应用后调用get方法为什么无法获取到保存的值(API 9)

**问题现象**

关系型数据库的保存以及重启时的调用

**解决措施**

在storage轻量级存储中，调用put方法，只是将数据保存在内存中，并不会持久化到硬盘中，在退出应用后会将内存中的数据清空。如果想持久化到硬盘中，则在调用put方法后需要再调用flush或flushSync接口才行。数据持久化后重启应用时就可以通过get方法获取到之前保存的数据。


## rdb关系型数据库中TEXT类型保存超长文本失败(API 9)

**问题现象**

API8版本rdb关系型数据库中TEXT类型保存超长文本失败

**解决措施**

API9版本之前对TEXT文本存储长度限制在1024字节，所以会存在超长文本保存失败的情况。

在API9的版本中已经放开了长度限制。


## Preferences.put缓存成功，但get的结果一直是undefined(API 9)

**问题现象**

使用首选项保存数据成功，但是获取数据为空。

**解决措施**

1. 使用put操作后，使用flush持久化数据，然后再使用get获取数据。

2. 由于flush操作是异步执行，将Storage实例通过异步线程回写入文件中, 所以需要等待flush操作执行完成后，再执行get操作。


## 使用RDB数据库时，能否指定内存数据库模式(API 9)

**解决措施**

RDB数据库底层使用的是SQLite，默认的内存数据库模式是文件，不支持修改。


## 关系型数据库rdb中，如何获取数据库大小

**解决措施**

可以使用[execute](../reference/apis-arkdata/arkts-apis-data-relationalStore-RdbStore.md#execute12)接口执行sql语句获取数据库大小，如：SELECT page_count * page_size AS size FROM pragma_page_count(), pragma_page_size()。
关系型数据库使用的是WAL模式，在查询前可以执行sql语句触发一次checkpoint刷新数据库文件大小，如：PRAGMA wal_checkpoint。


## 如何获取rdb关系型数据库路径

**解决措施**

1. 如果用户拥有root权限，则可以使用命令："find /data -name 数据库名字"进行查找；

2. 可以通过DevEco Studio的File Browser查找数据库文件路径。