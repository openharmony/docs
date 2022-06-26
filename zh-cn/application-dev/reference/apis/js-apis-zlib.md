# Zip模块(JS端SDK接口)

## 导入模块

```javascript
import zlib from '@ohos.zlib';
```

## zlib.zipFile

zipFile(inFile:string, outFile:string, options: Options): Promise\<void>

压缩接口（Promise形式）。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 名称    | 类型                                | 必填 | 描述                                        |
| ------- | ----------------------------------- | ---- | ------------------------------------------- |
| inFile  | string                              | 是   | 指定压缩的文件夹路径或者文件路径            |
| outFile | string                              | 是   | 指定的压缩结果的文件路径（文件的扩展名zip） |
| options | [Options](#options对象可选参数说明) | 否   | 压缩的可选参数                              |

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

unzipFile(inFile:string, outFile:string, options: Options): Promise\<void>

解压文件，解压完成返回执行结果（Promise形式）。

**系统能力：** SystemCapability.BundleManager.Zlib

**参数：**

| 名称    | 类型                                | 必填 | 描述                                |
| ------- | ----------------------------------- | ---- | ----------------------------------- |
| inFile  | string                              | 是   | 指定解压的文件路径（文件扩展名zip） |
| outFile | string                              | 是   | 指定的解压文件路径                  |
| options | [Options](#options对象可选参数说明) | 否   | 解压的可选参数                      |

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

## Options对象可选参数说明

| 参数                        | 说明                                                         |
| --------------------------- | ------------------------------------------------------------ |
| level?: CompressLeve        | [参考zip.CompressLevel枚举定义](#zip.CompressLevel压缩等级可选参数说明) |
| memLevel?: MemLevel         | [参考zip.MemLevel枚举定义](#zip.MemLevel可选参数说明)        |
| strategy?: CompressStrategy | [参考zip.CompressStrategy枚举定义](#zip.CompressStrategy压缩策略可选参数说明) |

## zip.MemLevel可选参数说明

| 参数                        | 说明                                                         |
| ----------------- | -------------------------------- |
| MEM_LEVEL_MIN     | zip 接口在压缩过程中最小使用内存 |
| MEM_LEVEL_MAX     | zip 接口在压缩过程中最大使用内存 |
| MEM_LEVEL_DEFAULT | zip 接口在压缩过程中默认使用内存 |

## zip.CompressLevel压缩等级可选参数说明

| 参数                                    | 描述              |
| --------------------------------------- | ----------------- |
| COMPRESS_LEVEL_NO_COMPRESSION : 0       | 压缩率为0压缩等级 |
| COMPRESS_LEVEL_BEST_SPEED : 1           | 最佳速度压缩等级  |
| COMPRESS_LEVEL_BEST_COMPRESSION :9      | 最佳压缩等级      |
| COMPRESS_LEVEL_DEFAULT_COMPRESSION ：-1 | 默认压缩等级      |

## zip.CompressStrategy压缩策略可选参数说明

| 参数                                   | 描述                     |
| -------------------------------------- | ------------------------ |
| COMPRESS_STRATEGY_DEFAULT_STRATEGY : 0 | 常规数据策略             |
| COMPRESS_STRATEGY_FILTERED : 1         | 过滤器产生的数据压缩策略 |
| COMPRESS_STRATEGY_HUFFMAN_ONLY : 2     | 霍夫曼编码格式压缩策略   |
| COMPRESS_STRATEGY_RLE : 3              | 游标编码压缩策略         |
| COMPRESS_STRATEGY_FIXED : 4            | 固定的压缩策略           |

## zip.ErrorCode接口返回值参数说明

| 参数                 | 描述         |
| -------------------- | ------------ |
| ERROR_CODE_OK: 0     | 函数调用成功 |
| ERROR_CODE_ERRNO:- 1 | 函数调用失败 |
