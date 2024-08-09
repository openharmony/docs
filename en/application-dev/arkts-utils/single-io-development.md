# Single I/O Task Development (Promise and Async/Await)


Asynchronous concurrency provided by Promise and async/await is applicable to the development of a single I/O task. The following example uses the asynchronous concurrency capability to write data to a file.


1. Implement the logic of a single I/O task.

    ```ts
    import { fileIo } from '@kit.CoreFileKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { common } from '@kit.AbilityKit'

    async function write(data: string, file: fileIo.File): Promise<void> {
      fileIo.write(file.fd, data).then((writeLen: number) => {
        console.info('write data length is: ' + writeLen)
      }).catch((err: BusinessError) => {
        console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
      })
    }
    ```
2. Use the asynchronous concurrency capability to invoke the single I/O task. For details about how to obtain **filePath** in the example, see [Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths).

    ```ts
    async function testFunc(): Promise<boolean>  {
      let context = getContext() as common.UIAbilityContext;
      let filePath: string = context.filesDir + "/test.txt"; // Application file path
      let file: fileIo.File = await fileIo.open(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
      write('Hello World!', file).then(() => {
        console.info('Succeeded in writing data.');
        fileIo.close(file);
      }).catch((err: BusinessError) => {
        console.error(`Failed to write data. Code is ${err.code}, message is ${err.message}`);
        fileIo.close(file);
      })
    
      let result = await fileIo.access(filePath, fileIo.AccessModeType.EXIST);
      if (!result) {
        return false;
      }
      return true;
    }

    @Entry
    @Component
    struct Index {
      @State message: string = 'Hello World';
      build() {
        Row() {
          Column() {
            Text(this.message)
              .fontSize(50)
              .fontWeight(FontWeight.Bold)
              .onClick(async () => {
                let res = await testFunc();
                console.info("res is: " + res);
              })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```
