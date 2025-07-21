# ArrayBuffer对象

ArrayBuffer包含两部分：底层存储数据的Native内存区域，以及封装操作的JS对象壳。JS对象壳分配在虚拟机的本地堆（LocalHeap）中。跨线程传递时，JS对象壳需要序列化和反序列化拷贝传递，而Native内存区域可以通过拷贝或转移的方式传递。

Native内存使用拷贝方式（递归遍历）传输时，传输后两个线程可以独立访问ArrayBuffer。此方式需要重建JS壳和拷贝Native内存，传输效率较低。通信过程如下图所示：

![copy_transfer](figures/copy_transfer.png)

Native内存使用转移方式传输时，传输后原线程将无法使用此ArrayBuffer对象。跨线程时只需重建JS壳，Native内存无需拷贝，从而提高效率。通信过程如下图所示

![transfer](figures/transfer.png)

ArrayBuffer可以用来表示图片等资源，在应用开发中，处理图片（如调整亮度、饱和度、大小等）会比较耗时，为了避免长时间阻塞UI主线程，可以将图片传递到子线程中进行处理。采用转移方式传递ArrayBuffer可提高传输性能，但原线程将无法再访问该ArrayBuffer对象。如果两个线程都需要访问该对象，只能采用拷贝方式。反之，建议采用转移方式以提升性能。

以下将通过具体的代码案例分别介绍拷贝和转移两种方式，实现图片跨ArkTS线程传输。

## ArrayBuffer拷贝传输方式

在ArkTS中，TaskPool传递ArrayBuffer数据时，默认采用转移方式。通过调用setTransferList()接口，可以指定部分数据的传递方式为转移方式，其他部分数据可以切换为拷贝方式。

首先，实现一个处理ArrayBuffer的接口，该接口在Task中执行。

然后，通过拷贝方式将ArrayBuffer数据传递到Task中，并进行处理。

最后，UI主线程接收到Task执行完毕后返回的ArrayBuffer数据，进行拼接并展示。

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

@Concurrent
function adjustImageValue(arrayBuffer: ArrayBuffer): ArrayBuffer {
  // 对arrayBuffer进行操作，返回值默认转移
  return arrayBuffer;
}

function createImageTask(arrayBuffer: ArrayBuffer, isParamsByTransfer: boolean): taskpool.Task {
  let task: taskpool.Task = new taskpool.Task(adjustImageValue, arrayBuffer);
  // 是否使用转移方式
  if (!isParamsByTransfer) {
    // 传递空数组[]，全部arrayBuffer参数传递均采用拷贝方式
    task.setTransferList([]);
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
          let taskNum = 4;
          let arrayBuffer = new ArrayBuffer(1024 * 1024);
          let taskPoolGroup = new taskpool.TaskGroup();
          // 创建taskNum个Task
          for (let i: number = 0; i < taskNum; i++) {
            let arrayBufferSlice: ArrayBuffer = arrayBuffer.slice(arrayBuffer.byteLength / taskNum * i, arrayBuffer.byteLength / taskNum * (i + 1));
            // 使用拷贝方式传入ArrayBuffer，所以isParamsByTransfer为false
            taskPoolGroup.addTask(createImageTask(arrayBufferSlice, false));
          }
          // 执行Task
          taskpool.execute(taskPoolGroup).then((data) => {
            // 返回结果，对数组拼接，获得最终结果
          }).catch((e: BusinessError) => {
            console.error(e.message);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[copy_arraybuffer_transfer](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/CommunicationObjects/entry/src/main/ets/managers/ArrayBufferObject.ets) -->

## ArrayBuffer转移传输方式

在TaskPool中，传递ArrayBuffer数据时，默认使用转移方式，原线程将无法再使用已传输给子线程的ArrayBuffer。 在上文示例的基础上去除task.setTransferList接口调用，即在createImageTask的第二个参数传入true，就可以实现转移方式的传输。
