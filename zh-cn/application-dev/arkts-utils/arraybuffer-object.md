# ArrayBuffer对象
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArrayBuffer包含两部分：底层存储数据的Native内存区域，以及封装操作的JS对象壳。JS对象壳分配在虚拟机的本地堆（LocalHeap）中。跨线程传递时，JS对象壳需要序列化和反序列化拷贝传递，而Native内存区域可以通过拷贝或转移的方式传递。

Native内存使用拷贝方式（递归遍历）传输时，传输后两个线程可以独立访问ArrayBuffer。此方式需要重建JS壳和拷贝Native内存，传输效率较低。通信过程如下图所示：

![copy_transfer](figures/copy_transfer.png)

Native内存使用转移方式传输时，传输后原线程将无法使用此ArrayBuffer对象。跨线程时只需重建JS壳，Native内存无需拷贝，从而提高效率。通信过程如下图所示：

![transfer](figures/transfer.png)

ArrayBuffer常用于表示图片等二进制资源，在应用开发中，处理图片（如调整亮度、饱和度、大小等）会比较耗时，为了避免长时间阻塞UI主线程，可以将图片传递到子线程中进行处理。采用转移方式传递ArrayBuffer可提高传输性能，但原线程将无法再访问该ArrayBuffer对象。如果两个线程都需要访问该对象，只能采用拷贝方式。反之，建议采用转移方式以提升性能。

以下将通过具体的代码案例分别介绍拷贝和转移两种方式，实现图片跨ArkTS线程传输。

## ArrayBuffer拷贝传输方式

在ArkTS中，TaskPool传递ArrayBuffer数据时，默认采用转移方式。通过调用[setTransferList()](../reference/apis-arkts/js-apis-taskpool.md#settransferlist10)接口，可以指定部分数据的传递方式为转移方式，其他部分数据可以切换为拷贝方式。

首先，实现一个处理ArrayBuffer的接口，该接口在Task中执行。

然后，通过拷贝方式将ArrayBuffer数据传递到Task中，并进行处理。

最后，UI主线程接收到Task执行完毕后返回的ArrayBuffer数据，进行拼接并展示。

<!-- @[copy_arraybuffer_transfer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/CommunicationObjects/entry/src/main/ets/managers/ArrayBufferObject.ets) --> 

``` TypeScript
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

// 在Task执行的处理函数，用于处理ArrayBuffer数据
@Concurrent
function adjustImageValue(arrayBuffer: ArrayBuffer): ArrayBuffer {
  // 对arrayBuffer进行操作，返回值默认转移
  return arrayBuffer;
}

/*
 * 创建一个Task，用于将ArrayBuffer传入Task执行
 * isParamsByCopy用于控制ArrayBuffer是“拷贝”还是“转移”传递
 */
function createImageTask(arrayBuffer: ArrayBuffer, isParamsByCopy: boolean): taskpool.Task {
  let task: taskpool.Task = new taskpool.Task(adjustImageValue, arrayBuffer);
  if (isParamsByCopy) {
    // 传递空数组[]，全部arrayBuffer参数传递均采用拷贝方式
    try {
      task.setTransferList([]);
    } catch (err) {
      hilog.error(0x0000, 'testTag', 'Failed to set transferList. Cause: %{public}s', JSON.stringify(err));
    }
  }
  return task;
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          // 创建待处理的ArrayBuffer，并按taskNum进行切分
          let taskNum = 4;
          let arrayBuffer = new ArrayBuffer(1024 * 1024);
          let taskPoolGroup = new taskpool.TaskGroup();
          // 创建taskNum个Task
          for (let i: number = 0; i < taskNum; i++) {
            let arrayBufferSlice: ArrayBuffer =
              arrayBuffer.slice(arrayBuffer.byteLength / taskNum * i, arrayBuffer.byteLength / taskNum * (i + 1));
            // isParamsByCopy为true时，就可以实现拷贝方式的传输
            taskPoolGroup.addTask(createImageTask(arrayBufferSlice, true));
          }
          // 执行Task，UI主线程接收处理完成后的结果
          taskpool.execute(taskPoolGroup).then((data) => {
            // 将各Task返回的ArrayBuffer数据（即data，此处data为包含4组arrayBufferSlice的长度为4的数组）进行拼接等后续处理，此处不再列举具体操作
            // ...
          }).catch((e: BusinessError) => {
            this.message = 'fail';
               console.error(`taskpool: execute task: code: ${e.code}, message: ${e.message}`);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## ArrayBuffer转移传输方式

在TaskPool中，传递ArrayBuffer数据时，默认使用转移方式，原线程将无法再使用已传输给子线程的ArrayBuffer。 在上文示例的基础上去除task.setTransferList接口调用，即在createImageTask的第二个参数传入false，就可以实现转移方式的传输。
