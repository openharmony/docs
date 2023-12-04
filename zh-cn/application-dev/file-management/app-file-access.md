# 应用文件访问

应用需要对应用文件目录下的应用文件进行查看、创建、读写、删除、移动、复制、获取属性等访问操作，下文介绍具体方法。

## 接口说明

开发者通过基础文件操作接口（[ohos.file.fs](../reference/apis/js-apis-file-fs.md)）实现应用文件访问能力，主要功能如下表所示。

**表1** 基础文件操作接口功能

| 接口名 | 功能 | 接口类型 | 支持同步 | 支持异步 | 
| -------- | -------- | -------- | -------- | -------- |
| access | 检查文件是否存在 | 方法 | √ | √ | 
| close | 关闭文件 | 方法 | √ | √ | 
| copyFile | 复制文件 | 方法 | √ | √ | 
| createStream | 基于文件路径打开文件流 | 方法 | √ | √ | 
| listFile | 列出文件夹下所有文件名 | 方法 | √ | √ | 
| mkdir | 创建目录 | 方法 | √ | √ | 
| moveFile | 移动文件 | 方法 | √ | √ | 
| open | 打开文件 | 方法 | √ | √ | 
| read | 从文件读取数据 | 方法 | √ | √ | 
| rename | 重命名文件或文件夹 | 方法 | √ | √ | 
| rmdir | 删除整个目录 | 方法 | √ | √ | 
| stat | 获取文件详细属性信息 | 方法 | √ | √ | 
| unlink | 删除单个文件 | 方法 | √ | √ | 
| write | 将数据写入文件 | 方法 | √ | √ | 
| Stream.close | 关闭文件流 | 方法 | √ | √ | 
| Stream.flush | 刷新文件流 | 方法 | √ | √ | 
| Stream.write | 将数据写入流文件 | 方法 | √ | √ | 
| Stream.read | 从流文件读取数据 | 方法 | √ | √ | 
| File.fd | 获取文件描述符 | 属性 | - | - | 
| OpenMode | 设置文件打开标签 | 属性 | - | - | 
| Filter | 设置文件过滤配置项 | 类型 | - | - | 

## 开发示例

在对应用文件开始访问前，开发者需要[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。以从UIAbilityContext获取HAP级别的文件路径为例进行说明，UIAbilityContext的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

下面介绍几种常用操作示例。

### 新建并读写一个文件

以下示例代码演示了如何新建一个文件并对其读写。

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';
import buffer from '@ohos.buffer';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function createFile(): void {
    // 新建并打开文件
  let file = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // 写入一段内容至文件
  let writeLen = fs.writeSync(file.fd, "Try to write str.");
  console.info("The length of str is: " + writeLen);
  // 从文件读取一段内容
  let arrayBuffer = new ArrayBuffer(1024);
  class Option {
    public offset: number = 0;
    public length: number = 0;
  }
  let option = new Option();
  option.length = arrayBuffer.byteLength;
  let readLen = fs.readSync(file.fd, arrayBuffer, option);
  let buf = buffer.from(arrayBuffer, 0, readLen);
  console.info("the content of file: " + buf.toString());
  // 关闭文件
  fs.closeSync(file);
}
```

### 读取文件内容并写入到另一个文件

以下示例代码演示了如何从一个文件读写内容到另一个文件。

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

function readWriteFile(): void {
  // 打开文件
  let srcFile = fs.openSync(filesDir + '/test.txt', fs.OpenMode.READ_WRITE);
  let destFile = fs.openSync(filesDir + '/destFile.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  // 读取源文件内容并写入至目的文件
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  class Option {
    public offset: number = 0;
    public length: number = bufSize;
  }
  let option = new Option();
  option.offset = readSize;
  let readLen = fs.readSync(srcFile.fd, buf, option);
  while (readLen > 0) {
    readSize += readLen;
    fs.writeSync(destFile.fd, buf);
    option.offset = readSize;
    readLen = fs.readSync(srcFile.fd, buf, option);
  }
  // 关闭文件
  fs.closeSync(srcFile);
  fs.closeSync(destFile);
}
```

> **说明：**
>
> 使用读写接口时，需注意可选项参数offset的设置。对于已存在且读写过的文件，文件偏移指针默认在上次读写操作的终止位置。

### 以流的形式读写文件

以下示例代码演示了如何使用流接口进行文件读写：

```ts
// pages/xxx.ets
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

async function readWriteFileWithStream(): Promise<void> {
  // 打开文件流
  let inputStream = fs.createStreamSync(filesDir + '/test.txt', 'r+');
  let outputStream = fs.createStreamSync(filesDir + '/destFile.txt', "w+");
  // 以流的形式读取源文件内容并写入目的文件
  let bufSize = 4096;
  let readSize = 0;
  let buf = new ArrayBuffer(bufSize);
  class Option {
    public offset: number = 0;
    public length: number = bufSize;
  }
  let option = new Option();
  option.offset = readSize;
  let readLen = await inputStream.read(buf, option);
  readSize += readLen;
  while (readLen > 0) {
    await outputStream.write(buf);
    option.offset = readSize;
    readLen = await inputStream.read(buf, option);
    readSize += readLen;
  }
  // 关闭文件流
  inputStream.closeSync();
  outputStream.closeSync();
}
```

> **说明：**
>
> 使用流接口时，需注意流的及时关闭。同时流的异步接口应严格遵循异步接口使用规范，避免同步、异步接口混用。流接口不支持并发读写。

### 查看文件列表

以下示例代码演示了如何查看文件列表：

```ts
import fs, { Filter } from '@ohos.file.fs';
import common from '@ohos.app.ability.common';

// 获取应用文件路径
let context = getContext(this) as common.UIAbilityContext;
let filesDir = context.filesDir;

// 查看文件列表
function getListFile(): void {
  class ListFileOption {
    public recursion: boolean = false;
    public listNum: number = 0;
    public filter: Filter = {};
  }
  let option = new ListFileOption();
  option.filter.suffix = ['.png', '.jpg', '.txt'];          // 匹配文件后缀名为'.png','.jpg','.txt'
  option.filter.displayName = ['test*'];                    // 匹配文件全名以'test'开头
  option.filter.fileSizeOver = 0;                           // 匹配文件大小大于等于0
  option.filter.lastModifiedAfter = new Date(0).getTime();  // 匹配文件最近修改时间在1970年1月1日之后
  let files = fs.listFileSync(filesDir, option);
  for (let i = 0; i < files.length; i++) {
    console.info(`The name of file: ${files[i]}`);
  }
}
```
