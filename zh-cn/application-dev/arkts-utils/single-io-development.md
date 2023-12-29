# 单次I/O任务开发指导 (Promise和async/await)


Promise和async/await提供异步并发能力，适用于单次I/O任务的场景开发，本文以使用异步进行单次文件写入为例来提供指导。


1. 实现单次I/O任务逻辑。

    ```ts
    import fs from '@ohos.file.fs';
    import { BusinessError } from '@ohos.base';
    import common from '@ohos.app.ability.common';

    async function write(data: string, file: fs.File): Promise<void> {
      fs.write(file.fd, data).then((writeLen: number) => {
        console.info('write data length is: ' + writeLen)
      }).catch((err: BusinessError) => {
        console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
      })
    }
    ```
2. 采用异步能力调用单次I/O任务。示例中的filePath的获取方式请参见[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。

    ```ts
    async function testFunc(): Promise<void>  {
      let context = getContext() as common.UIAbilityContext;
      let filePath: string = context.filesDir + "/test.txt"; // 应用文件路径
      let file: fs.File = await fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      write('Hello World!', file).then(() => {
        console.info('Succeeded in writing data.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
      })
      fs.close(file);
    }
    testFunc();
    ```
