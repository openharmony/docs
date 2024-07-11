# 单次I/O任务开发指导 (Promise和async/await)


Promise和async/await提供异步并发能力，适用于单次I/O任务的场景开发，本文以使用异步进行单次文件写入为例来提供指导。


1. 实现单次I/O任务逻辑。

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
2. 采用异步能力调用单次I/O任务。示例中的filePath的获取方式请参见[获取应用文件路径](../application-models/application-context-stage.md#获取应用文件路径)。

    ```ts
    async function testFunc(): Promise<boolean>  {
      let context = getContext() as common.UIAbilityContext;
      let filePath: string = context.filesDir + "/test.txt"; // 应用文件路径
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
