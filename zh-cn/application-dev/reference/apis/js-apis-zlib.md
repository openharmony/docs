# Zip模块(JS端SDK接口)

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用限制

无。
## 导入模块

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile
zipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

压缩接口（Promise形式）。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 描述                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md) |
| outFile | string              | 是   | 指定的压缩结果的文件路径（文件的扩展名zip）                  |
| options | [Options](#options) | 否   | 压缩的可选参数                                               |

**返回值：**

| 类型           | 说明                                                 |
| -------------- | ---------------------------------------------------- |
| Promise\<void> | ERROR_CODE_OK：压缩成功   ERROR_CODE_ERRNO：压缩失败 |

**示例1：**

```javascript

//【压缩文件 例子1】 
import zlib from '@ohos.zlib'
var inFile = "/xxx/filename.xxx";
var outFile = "/xxx/xxx.zip";
var options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile, outFile, options).then((data) => {
    console.log("zipFile result：" + data);
}).catch((err)=>{
    console.log("catch((err)=>" + err);
});

```

**示例2：**

```
// 【压缩文件夹 例子2】
import zlib from '@ohos.zlib'
var inFile = "/xxx/xxx";
var outFile = "/xxx/xxx.zip";
var options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};

zlib.zipFile(inFile , outFile, options).then((data) => {
    console.log("zipFile result：" + data);
}).catch((err)=>{
    console.log("catch((err)=>" + err);
});
```

## zlib.unzipFile

unzipFile(inFile:string, outFile:string, options: Options): Promise&lt;void&gt;

解压文件，解压完成返回执行结果（Promise形式）。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 参数名  | 类型                | 必填 | 描述                                                         |
| ------- | ------------------- | ---- | ------------------------------------------------------------ |
| inFile  | string              | 是   | 指定压缩的文件夹路径或者文件路径，对应的路径参考[FA模型](js-apis-Context.md)，[stage模型](js-apis-application-context.md) |
| outFile | string              | 是   | 指定的解压文件路径                                           |
| options | [Options](#options) | 否   | 解压的可选参数                                               |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | ERROR_CODE_OK：解压成功   ERROR_CODE_ERRNO：解压失败返回执行结果。 |

**示例：**

```javascript
// 【解压例子1】 
import zlib from '@ohos.zlib'
var inFile = "/xx/xxx.zip";
var outFile = "/xxx";

let options = {
  level: zlib.CompressLevel.COMPRESS_LEVEL_DEFAULT_COMPRESSION,
  memLevel: zlib.MemLevel.MEM_LEVEL_DEFAULT,
  strategy: zlib.CompressStrategy.COMPRESS_STRATEGY_DEFAULT_STRATEGY
};
zlib.unzipFile(inFile, outFile, options).then((data) => {
    console.log("unzipFile result：" + data);
}).catch((err)=>{
    console.log("catch((err)=>" + err);
})
	
```

## Options

**系统能力：** SystemCapability.BundleManager.Zlib

| 参数名   | 类型             | 必填 | 说明                                                      |
| -------- | ---------------- | ---- | --------------------------------------------------------- |
| level    | CompressLeve     | 否   | [参考zip.CompressLevel枚举定义](#zip.CompressLevel)       |
| memLevel | MemLevel         | 否   | [参考zip.MemLevel枚举定义](#zip.MemLevel)                 |
| strategy | CompressStrategy | 否   | [参考zip.CompressStrategy枚举定义](#zip.CompressStrategy) |

## zip.MemLevel

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称              | 值   | 说明                             |
| ----------------- | ---- | -------------------------------- |
| MEM_LEVEL_MIN     | 1    | zip 接口在压缩过程中最小使用内存 |
| MEM_LEVEL_MAX     | 9    | zip 接口在压缩过程中最大使用内存 |
| MEM_LEVEL_DEFAULT | 8    | zip 接口在压缩过程中默认使用内存 |

## zip.CompressLevel

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称                               | 值   | 说明              |
| ---------------------------------- | ---- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION      | 0    | 压缩率为0压缩等级 |
| COMPRESS_LEVEL_BEST_SPEED          | 1    | 最佳速度压缩等级  |
| COMPRESS_LEVEL_BEST_COMPRESSION    | 9    | 最佳压缩等级      |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION | -1   | 默认压缩等级      |

## zip.CompressStrategy

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称                               | 值   | 说明                     |
| ---------------------------------- | ---- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY | 0    | 常规数据策略             |
| COMPRESS_STRATEGY_FILTERED         | 1    | 过滤器产生的数据压缩策略 |
| COMPRESS_STRATEGY_HUFFMAN_ONLY     | 2    | 霍夫曼编码格式压缩策略   |
| COMPRESS_STRATEGY_RLE              | 3    | 游标编码压缩策略         |
| COMPRESS_STRATEGY_FIXED            | 4    | 固定的压缩策略           |

## zip.ErrorCode

**系统能力：** SystemCapability.BundleManager.Zlib

| 名称             | 值   | 说明         |
| ---------------- | ---- | ------------ |
| ERROR_CODE_OK    | 0    | 函数调用成功 |
| ERROR_CODE_ERRNO | -1   | 函数调用失败 |
