# Single I/O Task Development (Promise and Async/Await)


Asynchronous concurrency provided by Promise and async/await is applicable to the development of a single I/O task. The following example uses the asynchronous concurrency capability to write data to a file.


1. Implement the logic of a single I/O task.

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
2. Use the asynchronous concurrency capability to invoke the single I/O task. For details about how to obtain **filePath** in the example, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

    ```ts
    async function testFunc(): Promise<void>  {
      let context = getContext() as common.UIAbilityContext;
      let filePath: string = context.filesDir + "/test.txt"; // Application file path
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
