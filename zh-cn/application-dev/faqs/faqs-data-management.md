# 数据管理开发常见问题

## 如何将PixelMap的数据存储到数据库中。 

适用于：OpenHarmony SDK 3.2.3.5版本

PixelMap应该被转换成相应的ArrayBuffer再放进数据库。

参考文档：[readPixelsToBuffer](../reference/apis/js-apis-image.md#readpixelstobuffer7-1)

## 如何获取rdb关系型数据库文件

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

开发者可使用hdc_std命令拷贝文件，其中文件路径为： /data/app/el2/100/database/包名/entry/db/ ，然后拷贝该路径下后缀为 .db、.db-shm、.db-wal的文件，拷贝完成后，可以通过SQLite工具打开该数据库文件。

示例：

```shell
 hdc_std file recv /data/app/el2/100/database/com.xxxx.xxxx/entry/db/test.db ./test.db
```
