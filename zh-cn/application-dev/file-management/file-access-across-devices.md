# 跨设备文件访问

分布式文件系统为应用提供了跨设备文件访问的能力，开发者在多个设备安装同一应用时，通过[基础文件接口](app-file-access.md)，可跨设备读写其他设备该应用分布式文件路径（/data/storage/el2/distributedfiles/）下的文件。例如：多设备数据流转的场景，设备组网互联之后，设备A上的应用可访问设备B同应用分布式路径下的文件，当期望应用文件被其他设备访问时，只需将文件移动到分布式文件路径即可。

## 开发步骤

1. 完成分布式组网。
   首先将需要进行跨设备访问的设备连接到同一局域网中，同帐号认证完成组网。

2. 访问跨设备文件。
   同一应用不同设备之间实现跨设备文件访问，只需要将对应的文件放在应用沙箱的分布式文件路径即可。

   设备A上在分布式路径下创建测试文件，并写入内容。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

   ```ts
   import fs from '@ohos.file.fs';
   
   let context = ...; // 获取设备A的UIAbilityContext信息
   let pathDir = context.distributedFilesDir;
   // 获取分布式目录的文件路径
   let filePath = pathDir + '/test.txt';
   
   try {
     // 在分布式目录下创建文件
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
     console.info('Succeeded in createing.');
     // 向文件中写入内容
     fs.writeSync(file.fd, 'content');
     // 关闭文件
     fs.closeSync(file.fd);
   } catch (err) {
     console.error(`Failed to openSync / writeSync / closeSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```

   设备B上在分布式路径下读取测试文件。

   ```ts
   import fs from '@ohos.file.fs';
   
   let context = ...; // 获取设备B的UIAbilityContext信息
   let pathDir = context.distributedFilesDir;
   // 获取分布式目录的文件路径
   let filePath = pathDir + '/test.txt';
   
   try {
     // 打开分布式目录下的文件
     let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
     // 定义接收读取数据的缓存
     let buffer = new ArrayBuffer(4096);
     // 读取文件的内容，返回值是读取到的字节个数
     let num = fs.readSync(file.fd, buffer, {
       offset: 0
     });
     // 打印读取到的文件数据
     console.info('read result: ' + String.fromCharCode.apply(null, new Uint8Array(buffer.slice(0, num))));
   } catch (err) {
     console.error(`Failed to openSync / readSync. Code: ${err.code}, message: ${err.message}`);
   }
   ```
