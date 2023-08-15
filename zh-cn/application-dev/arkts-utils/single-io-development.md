# 单次I/O任务开发指导


Promise和async/await提供异步并发能力，适用于单次I/O任务的场景开发，本文以使用异步进行单次文件写入为例来提供指导。


1. 实现单次I/O任务逻辑。

   ```js
   import fs from '@ohos.file.fs';

   async function write(data: string, filePath: string) {
     let file = await fs.open(filePath, fs.OpenMode.READ_WRITE);
     fs.write(file.fd, data).then((writeLen) => {
       fs.close(file);
     }).catch((err) => {
       console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
     })
   }
   ```

2. 采用异步能力调用单次I/O任务。示例中的filePath的获取方式请参见[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。

   ```js
   let filePath = ...; // 应用文件路径
   write('Hello World!', filePath).then(() => {
     console.info('Succeeded in writing data.');
   })
   ```
