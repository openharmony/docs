# SharedArrayBuffer对象

SharedArrayBuffer内部包含一块Native内存，支持跨并发实例间共享，但是访问及修改需要采用Atomics类，防止数据竞争。SharedArrayBuffer可以用于多个并发实例间的状态共享或者数据共享。通信过程如下图所示：

![sharedarraybufer](figures/sharedarraybufer.png)


## 使用示例

这里提供了一个简单示例，使用TaskPool传递一个Int32Array对象，具体实现如下：

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function transferAtomics(arg1: Int32Array) {
  console.info("wait begin::");
  // 使用Atomics进行操作
  let res = Atomics.wait(arg1, 0, 0, 3000);
  return res;
}

// 定义可共享对象
let sab: SharedArrayBuffer = new SharedArrayBuffer(20);
let int32 = new Int32Array(sab);
let task: taskpool.Task = new taskpool.Task(transferAtomics, int32);
taskpool.execute(task).then((res) => {
  console.info("this res is: " + res);
});
setTimeout(() => {
  Atomics.notify(int32, 0, 1);
}, 1000);
```