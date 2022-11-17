# 文件管理

该模块提供文件存储管理能力，包括文件基本管理、文件目录管理、文件信息统计、文件流式读写等常用功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import fileio from '@ohos.fileio';
```


## 使用说明

使用该功能模块对文件/目录进行操作前，需要先获取其应用沙箱路径，获取方式及其接口用法请参考：

**Stage模型**

 ```js
import Ability from '@ohos.application.Ability';
class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let context = this.context;
        let pathDir = context.filesDir;
    }
}
 ```

 Stage模型context的具体获取方法参见[Stage模型](js-apis-ability-context.md#abilitycontext)。

**FA模型**

 ```js
 import featureAbility from '@ohos.ability.featureAbility';
 let context = featureAbility.getContext();
 context.getFilesDir().then((data) => {
      let pathDir = data;
 })
 ```
 
 FA模型context的具体获取方法参见[FA模型](js-apis-Context.md#Context模块)。

## fileio.stat

stat(path: string): Promise&lt;Stat&gt;

获取文件信息，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待获取文件的应用沙箱路径。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise对象。返回文件的具体信息。 |

**示例：**

  ```js
  let filePath = pathDir + "test.txt";
  fileio.stat(filePath).then(function(stat){
      console.info("getFileInfo succeed, the size of file is " + stat.size);
  }).catch(function(err){
      console.info("getFileInfo failed with error:"+ err);
  });
  ```


## fileio.stat

stat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

获取文件信息，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                               | 必填 | 说明                           |
| -------- | ---------------------------------- | ---- | ------------------------------ |
| path     | string                             | 是   | 待获取文件的应用沙箱路径。     |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | 是   | 异步获取文件的信息之后的回调。 |

**示例：**

  ```js
  fileio.stat(pathDir, function (err, stat) {
      // example code in Stat
  });
  ```


## fileio.statSync

statSync(path: string): Stat

以同步方法获取文件的信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待获取文件的应用沙箱路径。 |


**返回值：**

  | 类型            | 说明         |
  | ------------- | ---------- |
  | [Stat](#stat) | 表示文件的具体信息。 |

**示例：**

  ```js
  let stat = fileio.statSync(pathDir);
  // example code in Stat
  ```


## fileio.opendir

opendir(path: string): Promise&lt;Dir&gt;

打开文件目录，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | 是   | 待打开文件目录的应用沙箱路径。 |

**返回值：**

  | 类型                         | 说明       |
  | -------------------------- | -------- |
  | Promise&lt;[Dir](#dir)&gt; | Promise对象。返回Dir对象。 |

**示例：**

  ```js
  let dirPath = pathDir + "/testDir";
  fileio.opendir(dirPath).then(function(dir){
      console.info("opendir succeed");
  }).catch(function(err){
      console.info("opendir failed with error:"+ err);
  });
  ```


## fileio.opendir

opendir(path: string, callback: AsyncCallback&lt;Dir&gt;): void

打开文件目录，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                             | 必填 | 说明                           |
| -------- | -------------------------------- | ---- | ------------------------------ |
| path     | string                           | 是   | 待打开文件目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;[Dir](#dir)&gt; | 是   | 异步打开文件目录之后的回调。   |

**示例：**

  ```js
  fileio.opendir(pathDir, function (err, dir) { 
      // example code in Dir struct
      // use read/readSync/close
  });
  ```


## fileio.opendirSync

opendirSync(path: string): Dir

以同步方法打开文件目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO


**参数：**

| 参数名 | 类型   | 必填 | 说明                           |
| ------ | ------ | ---- | ------------------------------ |
| path   | string | 是   | 待打开文件目录的应用沙箱路径。 |

**返回值：**

  | 类型          | 说明       |
  | ----------- | -------- |
  | [Dir](#dir) | 返回Dir对象。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  // example code in Dir struct
  // use read/readSync/close
  ```


## fileio.access

access(path: string, mode?: number): Promise&lt;void&gt;

检查当前进程是否可访问某文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待访问文件的应用沙箱路径。                                   |
| mode   | number | 否   | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-&nbsp;0：确认文件是否存在。<br/>-&nbsp;1：确认当前进程是否具有可执行权限。<br/>-&nbsp;2：确认当前进程是否具有写权限。<br/>-&nbsp;4：确认当前进程是否具有读权限。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath).then(function() {
      console.info("access succeed");
  }).catch(function(err){
      console.info("access failed with error:"+ err);
  });
  ```


## fileio.access

access(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

检查当前进程是否可访问某文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | 是   | 待访问文件的应用沙箱路径。                                   |
| mode     | number                    | 否   | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-&nbsp;0：确认文件是否存在。<br/>-&nbsp;1：确认当前进程是否具有可执行权限。<br/>-&nbsp;2：确认当前进程是否具有写权限。<br/>-&nbsp;4：确认当前进程是否具有读权限。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步检查当前进程是否可访问某文件之后的回调。                 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.access(filePath, function (err) {
      // do something
  });
  ```


## fileio.accessSync

accessSync(path: string, mode?: number): void

以同步方法检查当前进程是否可访问某文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待访问文件的应用沙箱路径。                                   |
| mode   | number | 否   | 访问文件时的选项，可给定如下选项，以按位或的方式使用多个选项，默认给定0。<br/>确认当前进程是否具有对应权限：<br/>-&nbsp;0：确认文件是否存在。<br/>-&nbsp;1：确认当前进程是否具有可执行权限。<br/>-&nbsp;2：确认当前进程是否具有写权限。<br/>-&nbsp;4：确认当前进程是否具有读权限。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  try {
      fileio.accessSync(filePath);
  } catch(err) {
      console.info("accessSync failed with error:"+ err);
  }
  ```


## fileio.close<sup>7+</sup>

close(fd: number): Promise&lt;void&gt;

关闭文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待关闭文件的文件描述符。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd).then(function(){
      console.info("close file succeed");
  }).catch(function(err){
      console.info("close file failed with error:"+ err);
  });
  ```


## fileio.close<sup>7+</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

关闭文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明           |
  | -------- | ------------------------- | ---- | ------------ |
  | fd       | number                    | 是    | 待关闭文件的文件描述符。 |
  | callback | AsyncCallback&lt;void&gt; | 是    | 异步关闭文件之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.close(fd, function (err) {
      // do something
  });
  ```


## fileio.closeSync

closeSync(fd: number): void

以同步方法关闭文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待关闭文件的文件描述符。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.closeSync(fd);
  ```


## fileio.copyFile

copyFile(src: string | number, dest: string | number, mode?: number): Promise&lt;void&gt;

复制文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型                         | 必填   | 说明                                       |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string&nbsp;\|&nbsp;number | 是    | 待复制文件的路径或待复制文件的描述符。                      |
  | dest | string&nbsp;\|&nbsp;number | 是    | 目标文件路径或目标文件描述符。                          |
  | mode | number                     | 否    | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath).then(function(){
      console.info("copyFile succeed");
  }).catch(function(err){
      console.info("copyFile failed with error:"+ err);
  });
  ```


## fileio.copyFile

copyFile(src: string | number, dest: string | number, mode: number, callback: AsyncCallback&lt;void&gt;): void

复制文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                         | 必填   | 说明                                       |
  | -------- | -------------------------- | ---- | ---------------------------------------- |
  | src      | string&nbsp;\|&nbsp;number | 是    | 待复制文件的路径或待复制文件的描述符。                      |
  | dest     | string&nbsp;\|&nbsp;number | 是    | 目标文件路径或目标文件描述符。                          |
  | mode     | number                     | 否    | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |
  | callback | AsyncCallback&lt;void&gt;  | 是    | 异步复制文件之后的回调。                             |

**示例：**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFile(srcPath, dstPath, function (err) {
      // do something
  });
  ```


## fileio.copyFileSync

copyFileSync(src: string | number, dest: string | number, mode?: number): void

以同步方法复制文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型                         | 必填   | 说明                                       |
  | ---- | -------------------------- | ---- | ---------------------------------------- |
  | src  | string&nbsp;\|&nbsp;number | 是    | 待复制文件的路径或待复制文件的描述符。                      |
  | dest | string&nbsp;\|&nbsp;number | 是    | 目标文件路径或目标文件描述符。                          |
  | mode | number                     | 否    | mode提供覆盖文件的选项，当前仅支持0，且默认为0。<br/>0：完全覆盖目标文件，未覆盖部分将被裁切掉。 |

**示例：**

  ```js
  let srcPath = pathDir + "srcDir/test.txt";
  let dstPath = pathDir + "dstDir/test.txt";
  fileio.copyFileSync(srcPath, dstPath);
  ```


## fileio.mkdir

mkdir(path: string, mode?: number): Promise&lt;void&gt;

创建目录，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待创建目录的应用沙箱路径。                                   |
| mode   | number | 否   | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-&nbsp;0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath).then(function() {
      console.info("mkdir succeed");
  }).catch(function (error){
      console.info("mkdir failed with error:"+ error);
  });
  ```


## fileio.mkdir

mkdir(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

创建目录，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | 是   | 待创建目录的应用沙箱路径。                                   |
| mode     | number                    | 否   | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-&nbsp;0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步创建目录操作完成之后的回调。                             |

**示例：**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.mkdir(dirPath, function(err) {
    console.info("mkdir succeed");
  });
  ```


## fileio.mkdirSync

mkdirSync(path: string, mode?: number): void

以同步方法创建目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待创建目录的应用沙箱路径。                                   |
| mode   | number | 否   | 创建目录的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o775。<br/>-&nbsp;0o775：所有者具有读、写及可执行权限，其余用户具有读及可执行权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**示例：**

  ```js
  let dirPath = path + '/testDir';
  fileio.mkdirSync(dirPath);
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags?: number, mode?: number): Promise&lt;number&gt;

打开文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待打开文件的应用沙箱路径。                                   |
| flags  | number | 否   | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;0o0：只读打开。<br/>-&nbsp;0o1：只写打开。<br/>-&nbsp;0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数&nbsp;mode。<br/>-&nbsp;0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-&nbsp;0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-&nbsp;0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;0o200000：如果path不指向目录，则出错。<br/>-&nbsp;0o400000：如果path指向符号链接，则出错。<br/>-&nbsp;0o4010000：以同步IO的方式打开文件。 |
| mode   | number | 否   | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o666。<br/>-&nbsp;0o666：所有者具有读、写权限，所有用户组具有读、写权限，其余用户具有读、写权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**返回值：**

  | 类型                    | 说明          |
  | --------------------- | ----------- |
  | Promise&lt;number&gt; | Promise对象。返回打开文件的文件描述符。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0o1, 0o0200).then(function(number){
      console.info("open file succeed");
  }).catch(function(err){
      console.info("open file failed with error:"+ err);
  });
  ```


## fileio.open<sup>7+</sup>

open(path: string, flags: number, mode: number, callback: AsyncCallback&lt;number&gt;): void

打开文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                          | 是   | 待打开文件的应用沙箱路径。                                   |
| flags    | number                          | 否   | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;0o0：只读打开。<br/>-&nbsp;0o1：只写打开。<br/>-&nbsp;0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数&nbsp;mode。<br/>-&nbsp;0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-&nbsp;0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-&nbsp;0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;0o200000：如果path不指向目录，则出错。<br/>-&nbsp;0o400000：如果path指向符号链接，则出错。<br/>-&nbsp;0o4010000：以同步IO的方式打开文件。 |
| mode     | number                          | 否   | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o666。<br/>-&nbsp;0o666：所有者具有读、写权限，所有用户组具有读、写权限，其余用户具有读、写权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |
| callback | AsyncCallback&nbsp;&lt;void&gt; | 是   | 异步打开文件之后的回调。                                     |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.open(filePath, 0, function(err, fd) {
      // do something
  });
  ```


## fileio.openSync

openSync(path: string, flags?: number, mode?: number): number

以同步方法打开文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待打开文件的应用沙箱路径。                                   |
| flags  | number | 否   | 打开文件的选项，必须指定如下选项中的一个，默认以只读方式打开：<br/>-&nbsp;0o0：只读打开。<br/>-&nbsp;0o1：只写打开。<br/>-&nbsp;0o2：读写打开。<br/>同时，也可给定如下选项，以按位或的方式追加，默认不给定任何额外选项：<br/>-&nbsp;0o100：若文件不存在，则创建文件。使用该选项时必须指定第三个参数&nbsp;mode。<br/>-&nbsp;0o200：如果追加了0o100选项，且文件已经存在，则出错。<br/>-&nbsp;0o1000：如果文件存在且以只写或读写的方式打开文件，则将其长度裁剪为零。<br/>-&nbsp;0o2000：以追加方式打开，后续写将追加到文件末尾。<br/>-&nbsp;0o4000：如果path指向FIFO、块特殊文件或字符特殊文件，则本次打开及后续&nbsp;IO&nbsp;进行非阻塞操作。<br/>-&nbsp;0o200000：如果path不指向目录，则出错。<br/>-&nbsp;0o400000：如果path指向符号链接，则出错。<br/>-&nbsp;0o4010000：以同步IO的方式打开文件。 |
| mode   | number | 否   | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限，默认给定0o666。<br/>-&nbsp;0o666：所有者具有读、写权限，所有用户组具有读、写权限，其余用户具有读、写权限。<br/>-&nbsp;0o640：所有者具有读、写权限，所有用户组具有读权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。<br/>创建出的文件权限受umask影响，umask随进程启动确定，其修改当前不开放。 |

**返回值：**

  | 类型     | 说明          |
  | ------ | ----------- |
  | number | 打开文件的文件描述符。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o640);
  ```
  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o102, 0o666);
  fileio.writeSync(fd, 'hello world');
  let fd1 = fileio.openSync(filePath, 0o2002);
  fileio.writeSync(fd1, 'hello world');
  let num = fileio.readSync(fd1, new ArrayBuffer(4096), {position: 0});
  console.info("num == " + num);
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): Promise&lt;ReadOut&gt;

从文件读取数据，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名  | 类型        | 必填 | 说明                                                         |
| ------- | ----------- | ---- | ------------------------------------------------------------ |
| fd      | number      | 是   | 待读取文件的文件描述符。                                     |
| buffer  | ArrayBuffer | 是   | 用于保存读取到的文件数据的缓冲区。                           |
| options | Object      | 否   | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。 |

**返回值：**

  | 类型                                 | 说明     |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise对象。返回读取的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf).then(function(readOut){
      console.info("read file data succeed");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function(err){
      console.info("read file data failed with error:"+ err);
  });
  ```


## fileio.read

read(fd: number, buffer: ArrayBuffer, options: { offset?: number; length?: number; position?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

从文件读取数据，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                                       | 必填   | 说明                                       |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | 是    | 待读取文件的文件描述符。                             |
  | buffer   | ArrayBuffer                              | 是    | 用于保存读取到的文件数据的缓冲区。                        |
  | options  | Object                                   | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。  |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | 是    | 异步读取数据之后的回调。                             |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  fileio.read(fd, buf, function (err, readOut) {
      if (readOut) {
          console.info("read file data succeed");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


## fileio.readSync

readSync(fd: number, buffer: ArrayBuffer, options?: { offset?: number; length?: number; position?: number; }): number

以同步方法从文件读取数据。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型          | 必填   | 说明                                       |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | fd      | number      | 是    | 待读取文件的文件描述符。                             |
  | buffer  | ArrayBuffer | 是    | 用于保存读取到的文件数据的缓冲区。                        |
  | options | Object      | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。  |

**返回值：**

  | 类型     | 说明       |
  | ------ | -------- |
  | number | 实际读取的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o2);
  let buf = new ArrayBuffer(4096);
  let num = fileio.readSync(fd, buf);
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string): Promise&lt;void&gt;

删除目录，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待删除目录的应用沙箱路径。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath).then(function() {
      console.info("rmdir succeed");
  }).catch(function(err){
      console.info("rmdir failed with error:"+ err);
  });
  ```


## fileio.rmdir<sup>7+</sup>

rmdir(path: string, callback: AsyncCallback&lt;void&gt;): void

删除目录，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                       |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | 是   | 待删除目录的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步删除目录之后的回调。   |

**示例：**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdir(dirPath, function(err){
      // do something
      console.info("rmdir succeed");
  });
  ```


## fileio.rmdirSync<sup>7+</sup>

rmdirSync(path: string): void

以同步方法删除目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待删除目录的应用沙箱路径。 |

**示例：**

  ```js
  let dirPath = pathDir + '/testDir';
  fileio.rmdirSync(dirPath);
  ```


## fileio.unlink

unlink(path: string): Promise&lt;void&gt;

删除文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待删除文件的应用沙箱路径。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath).then(function(){
      console.info("remove file succeed");
  }).catch(function(error){
      console.info("remove file failed with error:"+ error);
  });
  ```


## fileio.unlink

unlink(path: string, callback: AsyncCallback&lt;void&gt;): void

删除文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                       |
| -------- | ------------------------- | ---- | -------------------------- |
| path     | string                    | 是   | 待删除文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步删除文件之后的回调。   |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlink(filePath, function(err) {
      console.info("remove file succeed");
  });
  ```


## fileio.unlinkSync

unlinkSync(path: string): void

以同步方法删除文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待删除文件的应用沙箱路径。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.unlinkSync(filePath);
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

将数据写入文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型                              | 必填   | 说明                                       |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | 是    | 待写入文件的文件描述符。                             |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | 是    | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options | Object                          | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。 |

**返回值：**

  | 类型                    | 说明       |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise对象。返回实际写入的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world").then(function(number){
       console.info("write data to file succeed and size is:"+ number);
  }).catch(function(err){
      console.info("write data to file failed with error:"+ err);
  });
  ```


## fileio.write

write(fd: number, buffer: ArrayBuffer | string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

将数据写入文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                              | 必填   | 说明                                       |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | 是    | 待写入文件的文件描述符。                             |
  | buffer   | ArrayBuffer&nbsp;\|&nbsp;string | 是    | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options  | Object                          | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。 |
  | callback | AsyncCallback&lt;number&gt;     | 是    | 异步将数据写入完成后执行的回调函数。                       |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  fileio.write(fd, "hello, world", function (err, bytesWritten) {
      if (bytesWritten) {
         console.info("write data to file succeed and size is:"+ bytesWritten);
      }
  });
  ```


## fileio.writeSync

writeSync(fd: number, buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

以同步方法将数据写入文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型                              | 必填   | 说明                                       |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd      | number                          | 是    | 待写入文件的文件描述符。                             |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | 是    | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options | Object                          | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。 |

**返回值：**

  | 类型     | 说明       |
  | ------ | -------- |
  | number | 实际写入的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath, 0o100 | 0o2, 0o666);
  let num = fileio.writeSync(fd, "hello, world");
  ```


## fileio.hash

hash(path: string, algorithm: string): Promise&lt;string&gt;

计算文件的哈希值，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| path      | string | 是   | 待计算哈希值文件的应用沙箱路径。                             |
| algorithm | string | 是   | 哈希计算采用的算法。可选&nbsp;"md5"、"sha1"&nbsp;或&nbsp;"sha256"。建议采用安全强度更高的&nbsp;"sha256"。 |

**返回值：**

  | 类型                    | 说明                         |
  | --------------------- | -------------------------- |
  | Promise&lt;string&gt; | Promise对象。返回文件的哈希值。表示为十六进制数字串，所有字母均大写。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256").then(function(str){
      console.info("calculate file hash succeed:"+ str);
  }).catch(function(err){
      console.info("calculate file hash failed with error:"+ err);
  });
  ```


## fileio.hash

hash(path: string, algorithm: string, callback: AsyncCallback&lt;string&gt;): void

计算文件的哈希值，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名    | 类型                        | 必填 | 说明                                                         |
| --------- | --------------------------- | ---- | ------------------------------------------------------------ |
| path      | string                      | 是   | 待计算哈希值文件的应用沙箱路径。                             |
| algorithm | string                      | 是   | 哈希计算采用的算法。可选&nbsp;"md5"、"sha1"&nbsp;或&nbsp;"sha256"。建议采用安全强度更高的&nbsp;"sha256"。 |
| callback  | AsyncCallback&lt;string&gt; | 是   | 异步计算文件哈希操作之后的回调函数（其中给定文件哈希值表示为十六进制数字串，所有字母均大写）。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.hash(filePath, "sha256", function(err, hashStr) {
      if (hashStr) {
          console.info("calculate file hash succeed:"+ hashStr);
      }
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number): Promise&lt;void&gt;

改变文件权限，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 所需变更权限的文件的应用沙箱路径。                               |
| mode   | number | 是   | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700).then(function() {
      console.info("chmod succeed");
  }).catch(function(err){
      console.info("chmod failed with error:"+ err);
  });
  ```


## fileio.chmod<sup>7+</sup>

chmod(path: string, mode: number, callback: AsyncCallback&lt;void&gt;): void

改变文件权限，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                    | 是   | 所需变更权限的文件的应用沙箱路径。                               |
| mode     | number                    | 是   | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步改变文件权限之后的回调。                                 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmod(filePath, 0o700, function (err) {
      // do something
  });
  ```


## fileio.chmodSync<sup>7+</sup>

chmodSync(path: string, mode: number): void

以同步方法改变文件权限。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 所需变更权限的文件的应用沙箱路径。                               |
| mode   | number | 是   | 改变文件权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.chmodSync(filePath, 0o700);
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number): Promise&lt;Stat&gt;

基于文件描述符获取文件状态信息，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待获取文件状态的文件描述符。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | Promise对象。返回表示文件状态的具体信息。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd).then(function(stat){
      console.info("fstat succeed, the size of file is "+ stat.size);
  }).catch(function(err){
      console.info("fstat failed with error:"+ err);
  });
  ```


## fileio.fstat<sup>7+</sup>

fstat(fd: number, callback: AsyncCallback&lt;Stat&gt;): void

基于文件描述符获取文件状态信息，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                                 | 必填   | 说明               |
  | -------- | ---------------------------------- | ---- | ---------------- |
  | fd       | number                             | 是    | 待获取文件状态的文件描述符。     |
  | callback | AsyncCallback&lt;[Stat](#stat)&gt; | 是    | 异步获取文件状态信息之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fstat(fd, function (err) {
      // do something
  });
  ```


## fileio.fstatSync<sup>7+</sup>

fstatSync(fd: number): Stat

以同步方法基于文件描述符获取文件状态信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待获取文件状态的文件描述符。 |

**返回值：**

  | 类型            | 说明         |
  | ------------- | ---------- |
  | [Stat](#stat) | 表示文件状态的具体信息。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fstatSync(fd);
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len?: number): Promise&lt;void&gt;

基于文件描述符截断文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明               |
  | ---- | ------ | ---- | ---------------- |
  | fd   | number | 是    | 待截断文件的文件描述符。     |
  | len  | number | 否    | 文件截断后的长度，以字节为单位。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。|

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.ftruncate(fd, 5).then(function(err) {    
      console.info("truncate file succeed");
  }).catch(function(err){
      console.info("truncate file failed with error:"+ err);
  });
  ```


## fileio.ftruncate<sup>7+</sup>

ftruncate(fd: number, len: number, callback: AsyncCallback&lt;void&gt;): void

基于文件描述符截断文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明               |
  | -------- | ------------------------- | ---- | ---------------- |
  | fd       | number                    | 是    | 待截断文件的文件描述符。     |
  | len      | number                    | 否    | 文件截断后的长度，以字节为单位。 |
  | callback | AsyncCallback&lt;void&gt; | 是    | 回调函数，本调用无返回值。  |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncate(fd, 5, function(err){
      // do something
  });
  ```


## fileio.ftruncateSync<sup>7+</sup>

ftruncateSync(fd: number, len?: number): void

以同步方法基于文件描述符截断文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明               |
  | ---- | ------ | ---- | ---------------- |
  | fd   | number | 是    | 待截断文件的文件描述符。     |
  | len  | number | 否    | 文件截断后的长度，以字节为单位。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let len = 5;
  fileio.ftruncateSync(fd, len);
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len?: number): Promise&lt;void&gt;

基于文件路径截断文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                             |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | 是   | 待截断文件的应用沙箱路径。       |
| len    | number | 否   | 文件截断后的长度，以字节为单位。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len).then(function(){
      console.info("truncate file succeed");
  }).catch(function(err){
      console.info("truncate file failed with error:"+ err);
  });
  ```


## fileio.truncate<sup>7+</sup>

truncate(path: string, len: number, callback: AsyncCallback&lt;void&gt;): void

基于文件路径截断文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                             |
| -------- | ------------------------- | ---- | -------------------------------- |
| path     | string                    | 是   | 待截断文件的应用沙箱路径。       |
| len      | number                    | 否   | 文件截断后的长度，以字节为单位。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，本调用无返回值。   |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncate(filePath, len, function(err){
      // do something
  });
  ```


## fileio.truncateSync<sup>7+</sup>

truncateSync(path: string, len?: number): void

以同步方法基于文件路径截断文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                             |
| ------ | ------ | ---- | -------------------------------- |
| path   | string | 是   | 待截断文件的应用沙箱路径。       |
| len    | number | 否   | 文件截断后的长度，以字节为单位。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let len = 5;
  fileio.truncateSync(filePath, len);
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): Promise&lt;string&gt;

基于文本方式读取文件（即直接读取文件的文本内容），使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | 是   | 待读取文件的应用沙箱路径。                                   |
| options  | Object | 否   | 支持如下选项：<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

  | 类型                    | 说明         |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise对象。返回读取文件的内容。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.readText(filePath).then(function(str) {
      console.info("readText succeed:"+ str);
  }).catch(function(err){
      console.info("readText failed with error:"+ err);
  });
  ```


## fileio.readText<sup>7+</sup>

readText(filePath: string, options: { position?: number; length?: number; encoding?: string; }, callback: AsyncCallback&lt;string&gt;): void

基于文本方式读取文件（即直接读取文件的文本内容），使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                      | 是   | 待读取文件的应用沙箱路径。                                   |
| options  | Object                      | 否   | 支持如下选项：<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;encoding，string类型，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，返回读取文件的内容。                         |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.readText(filePath, { position: 1, encoding: 'UTF-8' }, function(err, str){
      // do something
  });
  ```


## fileio.readTextSync<sup>7+</sup>

readTextSync(filePath: string, options?: { position?: number; length?: number; encoding?: string; }): string

以同步方法基于文本方式读取文件（即直接读取文件的文本内容）。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filePath | string | 是   | 待读取文件的应用沙箱路径。                                   |
| options  | Object | 否   | 支持如下选项：<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读取。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;encoding，string类型，当数据是&nbsp;string&nbsp;类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'，仅支持&nbsp;'utf-8'。 |

**返回值：**

  | 类型   | 说明                 |
  | ------ | -------------------- |
  | string | 返回读取文件的内容。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let str = fileio.readTextSync(filePath, {position: 1, length: 3});
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string): Promise&lt;Stat&gt;

获取链接信息，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | 是   | 目标文件的应用沙箱路径。 |

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;[Stat](#stat)&gt; | promise对象，返回文件对象，表示文件的具体信息，详情见stat。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath).then(function(stat){
      console.info("get link status succeed, the size of file is" + stat.size);
  }).catch(function(err){
      console.info("get link status failed with error:"+ err);
  });
  ```


## fileio.lstat<sup>7+</sup>

lstat(path: string, callback: AsyncCallback&lt;Stat&gt;): void

获取链接信息，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                   |
| -------- | ---------------------------------- | ---- | -------------------------------------- |
| path     | string                             | 是   | 目标文件的应用沙箱路径。 |
| callback | AsyncCallback&lt;[Stat](#stat)&gt; | 是   | 回调函数，返回文件的具体信息。       |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.lstat(filePath, function (err, stat) {
      // do something
  });
  ```


## fileio.lstatSync<sup>7+</sup>

lstatSync(path: string): Stat

以同步方法获取链接信息。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| path   | string | 是   | 目标文件的应用沙箱路径。 |

**返回值：**

  | 类型            | 说明         |
  | ------------- | ---------- |
  | [Stat](#stat) | 表示文件的具体信息。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.lstatSync(filePath);
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string): Promise&lt;void&gt;

重命名文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名  | 类型   | 必填 | 说明                         |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | 是   | 目标文件的当前应用沙箱路径。 |
| newPath | String | 是   | 目标文件的新应用沙箱路径。   |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile).then(function() {
      console.info("rename succeed");
  }).catch(function(err){
      console.info("rename failed with error:"+ err);
  });
  ```


## fileio.rename<sup>7+</sup>

rename(oldPath: string, newPath: string, callback: AsyncCallback&lt;void&gt;): void

重命名文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                         |
| -------- | ------------------------- | ---- | ---------------------------- |
| oldPath  | string                    | 是   | 目标文件的当前应用沙箱路径。 |
| newPath  | String                    | 是   | 目标文件的新应用沙箱路径。   |
| Callback | AsyncCallback&lt;void&gt; | 是   | 异步重命名文件之后的回调。   |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.rename(srcFile, dstFile, function(err){
  });
  ```


## fileio.renameSync<sup>7+</sup>

renameSync(oldPath: string, newPath: string): void

以同步方法重命名文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名  | 类型   | 必填 | 说明                         |
| ------- | ------ | ---- | ---------------------------- |
| oldPath | string | 是   | 目标文件的当前应用沙箱路径。 |
| newPath | String | 是   | 目标文件的新应用沙箱路径。   |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/new.txt';
  fileio.renameSync(srcFile, dstFile);
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number): Promise&lt;void&gt;

同步文件数据，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待同步文件的文件描述符。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd).then(function(){
      console.info("sync data succeed");
  }).catch(function(err){
      console.info("sync data failed with error:"+ err);
  });
  ```


## fileio.fsync<sup>7+</sup>

fsync(fd: number, callback: AsyncCallback&lt;void&gt;): void

同步文件数据，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明              |
  | -------- | ------------------------- | ---- | --------------- |
  | fd       | number                    | 是    | 待同步文件的文件描述符。    |
  | Callback | AsyncCallback&lt;void&gt; | 是    | 异步将文件数据同步之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsync(fd, function(err){
      // do something
  });
  ```


## fileio.fsyncSync<sup>7+</sup>

fsyncSync(fd: number): void

以同步方法同步文件数据。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待同步文件的文件描述符。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fsyncSync(fd);
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number): Promise&lt;void&gt;

实现文件内容数据同步，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待同步文件的文件描述符。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync(fd).then(function(err) {
      console.info("sync data succeed");
  }).catch(function(err){
      console.info("sync data failed with error:"+ err);
  });
  ```


## fileio.fdatasync<sup>7+</sup>

fdatasync(fd: number, callback: AsyncCallback&lt;void&gt;): void

实现文件内容数据同步，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                              | 必填   | 说明                |
  | -------- | ------------------------------- | ---- | ----------------- |
  | fd       | number                          | 是    | 待同步文件的文件描述符。      |
  | callback | AsyncCallback&nbsp;&lt;void&gt; | 是    | 异步将文件内容数据同步之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdatasync (fd, function (err) {
      // do something
  });
  ```


## fileio.fdatasyncSync<sup>7+</sup>

fdatasyncSync(fd: number): void

以同步方法实现文件内容数据同步。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待同步文件的文件描述符。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.fdatasyncSync(fd);
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string): Promise&lt;void&gt;

基于文件路径创建符号链接，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名  | 类型   | 必填 | 说明                         |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | 是   | 目标文件的应用沙箱路径。     |
| srcPath | string | 是   | 符号链接文件的应用沙箱路径。 |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile).then(function() {
      console.info("symlink succeed");
  }).catch(function(err){
      console.info("symlink failed with error:"+ err);
  });
  ```


## fileio.symlink<sup>7+</sup>

symlink(target: string, srcPath: string, callback: AsyncCallback&lt;void&gt;): void

基于文件路径创建符号链接，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                             |
| -------- | ------------------------- | ---- | -------------------------------- |
| target   | string                    | 是   | 目标文件的应用沙箱路径。         |
| srcPath  | string                    | 是   | 符号链接文件的应用沙箱路径。     |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步创建符号链接信息之后的回调。 |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlink(srcFile, dstFile, function (err) {
      // do something
  });
  ```


## fileio.symlinkSync<sup>7+</sup>

symlinkSync(target: string, srcPath: string): void

以同步的方法基于文件路径创建符号链接。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名  | 类型   | 必填 | 说明                         |
| ------- | ------ | ---- | ---------------------------- |
| target  | string | 是   | 目标文件的应用沙箱路径。     |
| srcPath | string | 是   | 符号链接文件的应用沙箱路径。 |

**示例：**

  ```js
  let srcFile = pathDir + "/test.txt";
  let dstFile = pathDir + '/test';
  fileio.symlinkSync(srcFile, dstFile);
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number): Promise&lt;void&gt;

基于文件路径改变文件所有者，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待改变文件的应用沙箱路径。 |
| uid    | number | 是   | 新的UID（UserID）。        |
| gid    | number | 是   | 新的GID（GroupID）。       |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.chown(filePath, stat.uid, stat.gid).then(function(){
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
  });
  ```


## fileio.chown<sup>7+</sup>

chown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

基于文件路径改变文件所有者，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                           |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | 是   | 待改变文件的应用沙箱路径。     |
| uid      | number                    | 是   | 新的UID。                      |
| gid      | number                    | 是   | 新的GID。                      |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步改变文件所有者之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chown(filePath, stat.uid, stat.gid, function (err){
      // do something
  });
  ```


## fileio.chownSync<sup>7+</sup>

chownSync(path: string, uid: number, gid: number): void

以同步的方法基于文件路径改变文件所有者。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待改变文件的应用沙箱路径。 |
| uid    | number | 是   | 新的UID。                  |
| gid    | number | 是   | 新的GID。                  |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath)
  fileio.chownSync(filePath, stat.uid, stat.gid);
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string): Promise&lt;string&gt;

创建临时目录，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名    | 类型     | 必填   | 说明                          |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | 是    | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |

**返回值：**

  | 类型                   | 说明         |
  | --------------------- | ---------- |
  | Promise&lt;string&gt; | Promise对象。返回生成的唯一目录路径。 |

**示例：**

  ```js
  fileio.mkdtemp(pathDir + "/XXXXXX").then(function(pathDir){
      console.info("mkdtemp succeed:"+ pathDir);
  }).catch(function(err){
      console.info("mkdtemp failed with error:"+ err);
  });
  ```


## fileio.mkdtemp<sup>7+</sup>

mkdtemp(prefix: string, callback: AsyncCallback&lt;string&gt;): void

创建临时目录，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                          | 必填   | 说明                          |
  | -------- | --------------------------- | ---- | --------------------------- |
  | prefix   | string                      | 是    | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |
  | callback | AsyncCallback&lt;string&gt; | 是    | 异步创建临时目录之后的回调。              |

**示例：**

  ```js
  fileio.mkdtemp(pathDir + "/XXXXXX", function (err, res) {
      // do something
  });
  ```


## fileio.mkdtempSync<sup>7+</sup>

mkdtempSync(prefix: string): string

以同步的方法创建临时目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名    | 类型     | 必填   | 说明                          |
  | ------ | ------ | ---- | --------------------------- |
  | prefix | string | 是    | 用随机产生的字符串替换以“XXXXXX”结尾目录路径。 |

**返回值：**

  | 类型    | 说明         |
  | ------ | ---------- |
  | string | 产生的唯一目录路径。 |

**示例：**

  ```js
  let res = fileio.mkdtempSync(pathDir + "/XXXXXX");
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number): Promise&lt;void&gt;

基于文件描述符改变文件权限，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明                                       |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | 是    | 待改变文件的文件描述符。                             |
  | mode | number | 是    | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**返回值：**

  | 类型                 | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
  fileio.fchmod(fd, mode).then(function() {
      console.info("chmod succeed");
  }).catch(function(err){
      console.info("chmod failed with error:"+ err);
  });
  ```


## fileio.fchmod<sup>7+</sup>

fchmod(fd: number, mode: number, callback: AsyncCallback&lt;void&gt;): void

基于文件描述符改变文件权限，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                              | 必填   | 说明                                       |
  | -------- | ------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                          | 是    | 待改变文件的文件描述符。                             |
  | mode     | number                          | 是    | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |
  | callback | AsyncCallback&nbsp;&lt;void&gt; | 是    | 异步改变文件权限之后的回调。                           |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
  fileio.fchmod(fd, mode, function (err) {
      // do something
  });
  ```


## fileio.fchmodSync<sup>7+</sup>

fchmodSync(fd: number, mode: number): void

以同步方法基于文件描述符改变文件权限。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明                                       |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | 是    | 待改变文件的文件描述符。                             |
  | mode | number | 是    | 若创建文件，则指定文件的权限，可给定如下权限，以按位或的方式追加权限。<br/>-&nbsp;0o700：所有者具有读、写及可执行权限。<br/>-&nbsp;0o400：所有者具有读权限。<br/>-&nbsp;0o200：所有者具有写权限。<br/>-&nbsp;0o100：所有者具有可执行权限。<br/>-&nbsp;0o070：所有用户组具有读、写及可执行权限。<br/>-&nbsp;0o040：所有用户组具有读权限。<br/>-&nbsp;0o020：所有用户组具有写权限。<br/>-&nbsp;0o010：所有用户组具有可执行权限。<br/>-&nbsp;0o007：其余用户具有读、写及可执行权限。<br/>-&nbsp;0o004：其余用户具有读权限。<br/>-&nbsp;0o002：其余用户具有写权限。<br/>-&nbsp;0o001：其余用户具有可执行权限。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let mode = 0o700;
   fileio.fchmodSync(fd, mode);
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string): Promise&lt;Stream&gt;

基于文件路径打开文件流，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待打开文件的应用沙箱路径。                                   |
| mode   | string | 是   | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

  | 类型                                | 说明        |
  | --------------------------------- | --------- |
  | Promise&lt;[Stream](#stream)&gt; | Promise对象。返回文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+").then(function(stream){
      console.info("createStream succeed");
  }).catch(function(err){
      console.info("createStream failed with error:"+ err);
  });
  ```


## fileio.createStream<sup>7+</sup>

createStream(path: string, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

基于文件路径打开文件流，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                  | 是   | 待打开文件的应用沙箱路径。                                   |
| mode     | string                                  | 是   | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |
| callback | AsyncCallback&lt;[Stream](#stream)&gt; | 是   | 异步打开文件流之后的回调。                                   |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  fileio.createStream(filePath, "r+", function(err, stream){
      // do something
  });
  ```


## fileio.createStreamSync<sup>7+</sup>

createStreamSync(path: string, mode: string): Stream

以同步方法基于文件路径打开文件流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 是   | 待打开文件的应用沙箱路径。                                   |
| mode   | string | 是   | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

  | 类型                | 说明        |
  | ------------------ | --------- |
  | [Stream](#stream) | 返回文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string): Promise&lt;Stream&gt;

基于文件描述符打开文件流，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明                                       |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | 是    | 待打开文件的文件描述符。                             |
  | mode | string | 是    | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

  | 类型                               | 说明        |
  | --------------------------------- | --------- |
  | Promise&lt;[Stream](#stream)&gt; | Promise对象。返回文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+").then(function(stream){
      console.info("openStream succeed");
  }).catch(function(err){
      console.info("openStream failed with error:"+ err);
  });
  ```


## fileio.fdopenStream<sup>7+</sup>

fdopenStream(fd: number, mode: string, callback: AsyncCallback&lt;Stream&gt;): void

基于文件描述符打开文件流，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                                       | 必填   | 说明                                       |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | fd       | number                                   | 是    | 待打开文件的文件描述符。                             |
  | mode     | string                                   | 是    | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |
  | callback | AsyncCallback&nbsp;&lt;[Stream](#stream)&gt; | 是    | 异步打开文件流之后的回调。                            |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  fileio.fdopenStream(fd, "r+", function (err, stream) {
      // do something
  });
  ```


## fileio.fdopenStreamSync<sup>7+</sup>

fdopenStreamSync(fd: number, mode: string): Stream

以同步方法基于文件描述符打开文件流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明                                       |
  | ---- | ------ | ---- | ---------------------------------------- |
  | fd   | number | 是    | 待打开文件的文件描述符。                             |
  | mode | string | 是    | -&nbsp;r：打开只读文件，该文件必须存在。<br/>-&nbsp;r+：打开可读写的文件，该文件必须存在。<br/>-&nbsp;w：打开只写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;w+：打开可读写文件，若文件存在则文件长度清0，即该文件内容会消失。若文件不存在则建立该文件。<br/>-&nbsp;a：以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。<br/>-&nbsp;a+：以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 |

**返回值：**

  | 类型                | 说明        |
  | ------------------ | --------- |
  | [Stream](#stream) | 返回文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let ss = fileio.fdopenStreamSync(fd, "r+");
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number): Promise&lt;void&gt;

基于文件描述符改变文件所有者，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待改变文件的文件描述符。 |
  | uid  | number | 是    | 文件所有者的UID。   |
  | gid  | number | 是    | 文件所有组的GID。   |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid).then(function() {
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
  });
  ```


## fileio.fchown<sup>7+</sup>

fchown(fd: number, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

基于文件描述符改变文件所有者，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明              |
  | -------- | ------------------------- | ---- | --------------- |
  | fd       | number                    | 是    | 待改变文件的文件描述符。    |
  | uid      | number                    | 是    | 文件所有者的UID。      |
  | gid      | number                    | 是    | 文件所有组的GID。      |
  | callback | AsyncCallback&lt;void&gt; | 是    | 异步改变文件所有者之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchown(fd, stat.uid, stat.gid, function (err){
      // do something
  });
  ```


## fileio.fchownSync<sup>7+</sup>

fchownSync(fd: number, uid: number, gid: number): void

以同步方法基于文件描述符改变文件所有者。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名  | 类型     | 必填   | 说明           |
  | ---- | ------ | ---- | ------------ |
  | fd   | number | 是    | 待改变文件的文件描述符。 |
  | uid  | number | 是    | 文件所有者的UID。   |
  | gid  | number | 是    | 文件所有组的GID。   |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let fd = fileio.openSync(filePath);
  let stat = fileio.statSync(filePath);
  fileio.fchownSync(fd, stat.uid, stat.gid);
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number): Promise&lt;void&gt;

基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是符号链接所指向的实际文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待打开文件的应用沙箱路径。 |
| uid    | number | 是   | 新的UID。                  |
| gid    | number | 是   | 新的GID。                  |

**返回值：**

  | 类型                  | 说明                           |
  | ------------------- | ---------------------------- |
  | Promise&lt;void&gt; | Promise对象。无返回值。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid).then(function() {
      console.info("chown succeed");
  }).catch(function(err){
      console.info("chown failed with error:"+ err);
  });
  ```


## fileio.lchown<sup>7+</sup>

lchown(path: string, uid: number, gid: number, callback: AsyncCallback&lt;void&gt;): void

基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是更改符号链接所指向的实际文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                      | 必填 | 说明                           |
| -------- | ------------------------- | ---- | ------------------------------ |
| path     | string                    | 是   | 待打开文件的应用沙箱路径。     |
| uid      | number                    | 是   | 新的UID。                      |
| gid      | number                    | 是   | 新的GID。                      |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步改变文件所有者之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchown(filePath, stat.uid, stat.gid, function (err){
      // do something
  });
  ```


## fileio.lchownSync<sup>7+</sup>

lchownSync(path: string, uid: number, gid: number): void

以同步方法基于文件路径改变文件所有者，更改符号链接本身的所有者，而不是更改符号链接所指向的实际文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| path   | string | 是   | 待打开文件的应用沙箱路径。 |
| uid    | number | 是   | 新的UID。                  |
| gid    | number | 是   | 新的GID。                  |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let stat = fileio.statSync(filePath);
  fileio.lchownSync(filePath, stat.uid, stat.gid);
  ```


## fileio.createWatcher<sup>7+</sup>

createWatcher(filename: string, events: number, callback: AsyncCallback&lt;number&gt;): Watcher

监听文件或者目录的变化，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| filePath | string                            | 是   | 待监视文件的应用沙箱路径。                                   |
| events   | Number                            | 是   | -&nbsp;1:&nbsp;监听文件或者目录是否发生重命名。<br/>-&nbsp;2：监听文件或者目录内容的是否修改。<br/>-&nbsp;3：两者都有。 |
| callback | AsyncCallback&lt;number&nbsp;&gt; | 是   | 每发生变化一次，调用一次此函数。                             |

**返回值：**

  | 类型                  | 说明         |
  | -------------------- | ---------- |
  | [Watcher](#watcher7) | Promise对象。返回文件变化监听的实例。 |

**示例：**

  ```js
  let filePath = pathDir +"/test.txt";
  fileio.createWatcher(filePath, 1, function(number){
     console.info("Monitoring times: "+number);
  });
  
  ```


## Readout

仅用于read方法，获取文件的读取结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.File.FileIO。

| 名称        | 参数类型       | 可读   | 可写   | 说明                |
| --------- | ---------- | ---- | ---- | ----------------- |
| bytesRead | number     | 是    | 是    | 实际读取长度。           |
| offset    | number     | 是    | 是    | 读取数据相对于缓冲区首地址的偏移。 |
| buffer    | ArrayBufer | 是    | 是    | 保存读取数据的缓冲区。       |


## Stat

文件具体信息，在调用Stat的方法前，需要先通过[stat()](#fileiostat)方法（同步或异步）来构建一个Stat实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.File.FileIO。

### 属性

| 名称     | 参数类型   | 可读   | 可写   | 说明                                       |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| dev    | number | 是    | 否    | 标识包含该文件的主设备号。                            |
| ino    | number | 是    | 否    | 标识该文件。通常同设备上的不同文件的INO不同。                 |
| mode   | number | 是    | 否    | 表示文件类型及权限，其首&nbsp;4&nbsp;位表示文件类型，后&nbsp;12&nbsp;位表示权限。各特征位的含义如下：<br/>-&nbsp;0o170000：可用于获取文件类型的掩码。<br/>-&nbsp;0o140000：文件是套接字。<br/>-&nbsp;0o120000：文件是符号链接。<br/>-&nbsp;0o100000：文件是一般文件。<br/>-&nbsp;0o060000：文件属于块设备。<br/>-&nbsp;0o040000：文件是目录。<br/>-&nbsp;0o020000：文件是字符设备。<br/>-&nbsp;0o010000：文件是具名管道，即FIFO。<br/>-&nbsp;0o0700：可用于获取用户权限的掩码。<br/>-&nbsp;0o0400：用户读，对于普通文件，所有者可读取文件；对于目录，所有者可读取目录项。<br/>-&nbsp;0o0200：用户写，对于普通文件，所有者可写入文件；对于目录，所有者可创建/删除目录项。<br/>-&nbsp;0o0100：用户执行，对于普通文件，所有者可执行文件；对于目录，所有者可在目录中搜索给定路径名。<br/>-&nbsp;0o0070：可用于获取用户组权限的掩码。<br/>-&nbsp;0o0040：用户组读，对于普通文件，所有用户组可读取文件；对于目录，所有用户组可读取目录项。<br/>-&nbsp;0o0020：用户组写，对于普通文件，所有用户组可写入文件；对于目录，所有用户组可创建/删除目录项。<br/>-&nbsp;0o0010：用户组执行，对于普通文件，所有用户组可执行文件；对于目录，所有用户组是否可在目录中搜索给定路径名。<br/>-&nbsp;0o0007：可用于获取其他用户权限的掩码。<br/>-&nbsp;0o0004：其他读，对于普通文件，其余用户可读取文件；对于目录，其他用户组可读取目录项。<br/>-&nbsp;0o0002：其他写，对于普通文件，其余用户可写入文件；对于目录，其他用户组可创建/删除目录项。<br/>-&nbsp;0o0001：其他执行，对于普通文件，其余用户可执行文件；对于目录，其他用户组可在目录中搜索给定路径名。 |
| nlink  | number | 是    | 否    | 文件的硬链接数。                                 |
| uid    | number | 是    | 否    | 文件所有者的ID。                                |
| gid    | number | 是    | 否    | 文件所有组的ID。                                |
| rdev   | number | 是    | 否    | 标识包含该文件的从设备号。                            |
| size   | number | 是    | 否    | 文件的大小，以字节为单位。仅对普通文件有效。                   |
| blocks | number | 是    | 否    | 文件占用的块数，计算时块大小按512B计算。                   |
| atime  | number | 是    | 否    | 上次访问该文件的时间，表示距1970年1月1日0时0分0秒的秒数。        |
| mtime  | number | 是    | 否    | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。        |
| ctime  | number | 是    | 否    | 最近改变文件状态的时间，表示距1970年1月1日0时0分0秒的秒数。       |


### isBlockDevice

isBlockDevice(): boolean

用于判断文件是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明               |
  | ------- | ---------------- |
  | boolean | 表示文件是否是块特殊设备。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let isBLockDevice = fileio.statSync(filePath).isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

用于判断文件是否是字符特殊文件。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明                |
  | ------- | ----------------- |
  | boolean | 表示文件是否是字符特殊设备。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let isCharacterDevice = fileio.statSync(filePath).isCharacterDevice();
  ```


### isDirectory

isDirectory(): boolean

用于判断文件是否是目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明            |
  | ------- | ------------- |
  | boolean | 表示文件是否是目录。 |

**示例：**

  ```js
  let dirPath = pathDir + "/test";
  let isDirectory = fileio.statSync(dirPath).isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

用于判断文件是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明                    |
  | ------- | --------------------- |
  | boolean | 表示文件是否是&nbsp;FIFO。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let isFIFO = fileio.statSync(filePath).isFIFO(); 
  ```


### isFile

isFile(): boolean

用于判断文件是否是普通文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明              |
  | ------- | --------------- |
  | boolean | 表示文件是否是普通文件。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let isFile = fileio.statSync(filePath).isFile();
  ```


### isSocket

isSocket(): boolean

用于判断文件是否是套接字。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明             |
  | ------- | -------------- |
  | boolean | 表示文件是否是套接字。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let isSocket = fileio.statSync(filePath).isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

用于判断文件是否是符号链接。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明              |
  | ------- | --------------- |
  | boolean | 表示文件是否是符号链接。 |

**示例：**

  ```js
  let filePath = pathDir + "/test";
  let isSymbolicLink = fileio.statSync(filePath).isSymbolicLink(); 
  ```


## Watcher<sup>7+</sup>

Watcher是文件变化监听的实例，调用Watcher.stop()方法（同步或异步）来停止文件监听。


### stop<sup>7+</sup>

stop(): Promise&lt;void&gt;

关闭watcher监听，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  let filePath = path + "/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, function(number){
      console.info("Monitoring times: "+number);
  });
  watcher.stop().then(function(){
       console.info("close watcher succeed");
  });
  ```


### stop<sup>7+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

关闭watcher监听，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明                     |
  | -------- | ------------------------- | ---- | ---------------------- |
  | callback | AsyncCallback&lt;void&gt; | 是    | 以异步方法关闭watcher监听之后的回调。 |

**示例：**

  ```js
  let filePath = path +"/test.txt";
  let watcher = fileio.createWatcher(filePath, 1, function(number){
      console.info("Monitoring times: "+number);
  });
  watcher.stop(function(){
      console.info("close watcher succeed");
  })
  ```


## Stream

文件流，在调用Stream的方法前，需要先通过createStream()方法（同步或异步）来构建一个Stream实例。


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

关闭文件流，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型                  | 说明            |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise对象。返回表示异步关闭文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.close().then(function(){
      console.info("close fileStream succeed");
  }).catch(function(err){
      console.info("close fileStream  failed with error:"+ err);
  });
  ```


### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

异步关闭文件流，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明            |
  | -------- | ------------------------- | ---- | ------------- |
  | callback | AsyncCallback&lt;void&gt; | 是    | 异步关闭文件流之后的回调。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.close(function (err) {
      // do something
  });
  ```


### closeSync

closeSync(): void

同步关闭文件流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.closeSync();
  ```


### flush<sup>7+</sup>

flush(): Promise&lt;void&gt;

刷新文件流，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型                  | 说明            |
  | ------------------- | ------------- |
  | Promise&lt;void&gt; | Promise对象。返回表示异步刷新文件流的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flush().then(function (){
      console.info("flush succeed");
  }).catch(function(err){
      console.info("flush failed with error:"+ err);
  });
  ```


### flush<sup>7+</sup>

flush(callback: AsyncCallback&lt;void&gt;): void

异步刷新文件流，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                        | 必填   | 说明             |
  | -------- | ------------------------- | ---- | -------------- |
  | callback | AsyncCallback&lt;void&gt; | 是    | 异步刷新文件流后的回调函数。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flush(function (err) {
      // do something
  });
  ```


### flushSync<sup>7+</sup>

flushSync(): void

同步刷新文件流。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.flushSync();
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): Promise&lt;number&gt;

将数据写入流文件，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型                              | 必填   | 说明                                       |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | 是    | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options | Object                          | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。  |

**返回值：**

  | 类型                    | 说明       |
  | --------------------- | -------- |
  | Promise&lt;number&gt; | Promise对象。返回实际写入的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.write("hello, world",{offset: 1,length: 5,position: 5,encoding :'utf-8'}).then(function (number){
      console.info("write succeed and size is:"+ number);
  }).catch(function(err){
      console.info("write failed with error:"+ err);
  });
  ```


### write<sup>7+</sup>

write(buffer: ArrayBuffer | string, options: { offset?: number; length?: number; position?: number; encoding?: string; }, callback: AsyncCallback&lt;number&gt;): void

将数据写入流文件，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名   | 类型                            | 必填 | 说明                                                         |
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | buffer   | ArrayBuffer&nbsp;\|&nbsp;string | 是   | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options  | Object                          | 否   | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。 |
  | callback | AsyncCallback&lt;number&gt;     | 是   | 异步写入完成后执行的回调函数。                               |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath, "r+");
  ss.write("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'}, function (err, bytesWritten) {
      if (bytesWritten) {
         // do something
         console.info("write succeed and size is:"+ bytesWritten);
      }
  });
  ```


### writeSync<sup>7+</sup>

writeSync(buffer: ArrayBuffer | string, options?: { offset?: number; length?: number; position?: number; encoding?: string; }): number

以同步方法将数据写入流文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型                              | 必填   | 说明                                       |
  | ------- | ------------------------------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer&nbsp;\|&nbsp;string | 是    | 待写入文件的数据，可来自缓冲区或字符串。                     |
  | options | Object                          | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示期望写入数据的位置相对于数据首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望写入数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望写入文件的位置。可选，默认从当前位置开始写。<br/>-&nbsp;encoding，string类型，当数据是string类型时有效，表示数据的编码方式，默认&nbsp;'utf-8'。仅支持&nbsp;'utf-8'。<br/>约束：offset+length<=buffer.size。  |

**返回值：**

  | 类型     | 说明       |
  | ------ | -------- |
  | number | 实际写入的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss= fileio.createStreamSync(filePath,"r+");
  let num = ss.writeSync("hello, world", {offset: 1, length: 5, position: 5, encoding :'utf-8'});
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): Promise&lt;ReadOut&gt;

从流文件读取数据，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型          | 必填   | 说明                                       |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | 是    | 用于读取文件的缓冲区。                              |
  | options | Object      | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。  |

**返回值：**

  | 类型                                 | 说明     |
  | ---------------------------------- | ------ |
  | Promise&lt;[ReadOut](#readout)&gt; | Promise对象。返回读取的结果。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.read(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5}).then(function (readOut){
      console.info("read data succeed");
      console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
  }).catch(function(err){
      console.info("read data failed with error:"+ err);
  });
  ```


### read<sup>7+</sup>

read(buffer: ArrayBuffer, options: { position?: number; offset?: number; length?: number; }, callback: AsyncCallback&lt;ReadOut&gt;): void

从流文件读取数据，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                                       | 必填   | 说明                                       |
  | -------- | ---------------------------------------- | ---- | ---------------------------------------- |
  | buffer   | ArrayBuffer                              | 是    | 用于读取文件的缓冲区。                              |
  | options  | Object                                   | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。  |
  | callback | AsyncCallback&lt;[ReadOut](#readout)&gt; | 是    | 异步从流文件读取数据之后的回调。                         |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  ss.read(new ArrayBuffer(4096),{offset: 1, length: 5, position: 5},function (err, readOut) {
      if (readOut) {
          console.info("read data succeed");
          console.log(String.fromCharCode.apply(null, new Uint8Array(readOut.buffer)));
      }
  });
  ```


### readSync<sup>7+</sup>

readSync(buffer: ArrayBuffer, options?: { position?: number; offset?: number; length?: number; }): number

以同步方法从流文件读取数据。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名     | 类型          | 必填   | 说明                                       |
  | ------- | ----------- | ---- | ---------------------------------------- |
  | buffer  | ArrayBuffer | 是    | 用于读取文件的缓冲区。                              |
  | options | Object      | 否    | 支持如下选项：<br/>-&nbsp;offset，number类型，表示将数据读取到缓冲区的位置，即相对于缓冲区首地址的偏移。可选，默认为0。<br/>-&nbsp;length，number类型，表示期望读取数据的长度。可选，默认缓冲区长度减去偏移长度。<br/>-&nbsp;position，number类型，表示期望读取文件的位置。可选，默认从当前位置开始读。<br/>约束：offset+length<=buffer.size。  |

**返回值：**

  | 类型     | 说明       |
  | ------ | -------- |
  | number | 实际读取的长度。 |

**示例：**

  ```js
  let filePath = pathDir + "/test.txt";
  let ss = fileio.createStreamSync(filePath, "r+");
  let num = ss.readSync(new ArrayBuffer(4096), {offset: 1, length: 5, position: 5});
  ```


## Dir

管理目录，在调用Dir的方法前，需要先通过opendir方法（同步或异步）来构建一个Dir实例。


### read

read(): Promise&lt;Dirent&gt;

读取下一个目录项，使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型                               | 说明            |
  | -------------------------------- | ------------- |
  | Promise&lt;[Dirent](#dirent)&gt; | Promise对象。返回表示异步读取目录项的结果。 |

**示例：**

  ```js
  dir.read().then(function (dirent){
      console.log("read succeed, the name of dirent is " + dirent.name);
  }).catch(function(err){
      console.info("read failed with error:"+ err);
  });
  ```


### read

read(callback: AsyncCallback&lt;Dirent&gt;): void

读取下一个目录项，使用callback异步回调。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**参数：**

  | 参数名      | 类型                                     | 必填   | 说明               |
  | -------- | -------------------------------------- | ---- | ---------------- |
  | callback | AsyncCallback&lt;[Dirent](#dirent)&gt; | 是    | 异步读取下一个目录项之后的回调。 |

**示例：**

  ```js
  dir.read(function (err, dirent) {
      if (dirent) {
          // do something
          console.log("read succeed, the name of file is " + dirent.name);
      }
  });
  ```


### readSync

readSync(): Dirent

同步读取下一个目录项。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型                | 说明       |
  | ----------------- | -------- |
  | [Dirent](#dirent) | 表示一个目录项。 |

**示例：**

  ```js
  let dirent = dir.readSync();
  ```


### close<sup>7+</sup>

close(): Promise&lt;void&gt;

异步关闭目录，使用promise形式返回结果。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  dir.close().then(function(err){
      console.info("close dir successfully");
  });
  ```


  ### close<sup>7+</sup>

close(callback: AsyncCallback&lt;void&gt;): void

异步关闭目录，使用callback形式返回结果。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  dir.close(function(err){
      console.info("close dir successfully");
  });
  ```


### closeSync

closeSync(): void

用于关闭目录。目录被关闭后，Dir中持有的文件描述将被释放，后续将无法从Dir中读取目录项。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**示例：**

  ```js
  dir.closeSync();
  ```


## Dirent

在调用Dirent的方法前，需要先通过[dir.read()](#read)方法（同步或异步）来构建一个Dirent实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.File.FileIO。

### 属性

| 名称   | 参数类型   | 可读   | 可写   | 说明      |
| ---- | ------ | ---- | ---- | ------- |
| name | string | 是    | 否    | 目录项的名称。 |


### isBlockDevice

isBlockDevice(): boolean

用于判断当前目录项是否是块特殊文件。一个块特殊文件只能以块为粒度进行访问，且访问的时候带缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明               |
  | ------- | ---------------- |
  | boolean | 表示当前目录项是否是块特殊设备。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isBLockDevice = dir.readSync().isBlockDevice();
  ```


### isCharacterDevice

isCharacterDevice(): boolean

用于判断当前目录项是否是字符特殊设备。一个字符特殊设备可进行随机访问，且访问的时候不带缓存。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明                |
  | ------- | ----------------- |
  | boolean | 表示当前目录项是否是字符特殊设备。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isCharacterDevice = dir.readSync().isCharacterDevice(); 
  ```


### isDirectory

isDirectory(): boolean

用于判断当前目录项是否是目录。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明            |
  | ------- | ------------- |
  | boolean | 表示当前目录项是否是目录。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isDirectory = dir.readSync().isDirectory(); 
  ```


### isFIFO

isFIFO(): boolean

用于判断当前目录项是否是命名管道（有时也称为FIFO）。命名管道通常用于进程间通信。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明              |
  | ------- | --------------- |
  | boolean | 表示当前目录项是否是FIFO。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isFIFO = dir.readSync().isFIFO(); 
  ```


### isFile

isFile(): boolean

用于判断当前目录项是否是普通文件。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明              |
  | ------- | --------------- |
  | boolean | 表示当前目录项是否是普通文件。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isFile = dir.readSync().isFile(); 
  ```


### isSocket

isSocket(): boolean

用于判断当前目录项是否是套接字。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明             |
  | ------- | -------------- |
  | boolean | 表示当前目录项是否是套接字。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isSocket = dir.readSync().isSocket(); 
  ```


### isSymbolicLink

isSymbolicLink(): boolean

用于判断当前目录项是否是符号链接。

**系统能力**：SystemCapability.FileManagement.File.FileIO

**返回值：**

  | 类型      | 说明              |
  | ------- | --------------- |
  | boolean | 表示当前目录项是否是符号链接。 |

**示例：**

  ```js
  let dir = fileio.opendirSync(pathDir);
  let isSymbolicLink = dir.readSync().isSymbolicLink();
  ```

## Filter<sup>9+</sup>

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.File.FileIO

文件过滤器配置项。

| 名称        | 参数类型       | 说明                |
| ----------- | --------------- | ------------------ |
| suffix | Array&lt;string&gt;     | 文件后缀名，各个关键词OR关系。           |
| displayName    | Array&lt;string&gt;     | 文件名模糊匹配，各个关键词OR关系。 |
| mimeType    | Array&lt;string&gt; | mime类型匹配，各个关键词OR关系。       |
| fileSizeOver    | number | 文件大小匹配，大于等于指定大小的文件。       |
| lastModifiedAfter    | Date | 修改时间匹配，在指定时间点后的文件。       |
| excludeMedia    | Boolean | 是否排除Media中已有的文件。       |
