# SharedArrayBuffer Object

A SharedArrayBuffer object contains a block of native memory, and its JS object wrapper is allocated in the local heap of the virtual machine. It allows sharing across concurrent instances but requires the use of the Atomics class to manage access and modifications, thereby preventing data races. It is suitable for sharing state or data among multiple concurrent instances. The following figure shows the communication process.

![sharedarraybufer](figures/sharedarraybufer.png)


## Usage Example

The following is a simple example of using TaskPool to pass an Int32Array object:

```ts
import { taskpool } from '@kit.ArkTS';

@Concurrent
function transferAtomics(arg1: Int32Array) {
  console.info("wait begin::");
  // Use Atomics to perform operations.
  let res = Atomics.wait(arg1, 0, 0, 3000);
  return res;
}

// Define an object that can be shared.
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
