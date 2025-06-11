# ArkUI数据更新场景

当需要网络下载或者本地生成的数据需要发送到UI线程进行展示时，由于ArkUI的标注和[\@Sendable装饰器](../arkts-utils/arkts-sendable.md#sendable装饰器)不能同时修饰变量和对象，因此需要使用[makeObserved](../ui/state-management/arkts-new-makeObserved.md)在ArkUI中导入可观察的Sendable共享数据。

本示例说明以下场景：
- makeObserved在传入@Sendable类型的数据后有观察能力，且其变化可以触发UI刷新。
- 从子线程获取数据，然后整体替换UI线程的可观察数据。
- 从子线程获取的数据重新执行makeObserved，将数据变为可观察数据。
- 将数据从UI主线程传递回子线程时，只传递不可观察的数据。makeObserved的返回值不能直接传给子线程。

```ts
// SendableData.ets
@Sendable
export class SendableData {
  name: string = 'Tom';
  age: number = 20;
  gender: number = 1;
  likes: number = 1;
  follow: boolean = false;
}
```
<!-- @[define_sendable_class](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/SendableData.ets) -->

```ts
import { taskpool } from '@kit.ArkTS';
import { SendableData } from './SendableData';
import { UIUtils } from '@kit.ArkUI';

@Concurrent
function threadGetData(param: string): SendableData {
  // 在子线程处理数据
  let ret = new SendableData();
  console.info(`Concurrent threadGetData, param ${param}`);
  ret.name = param + "-o";
  ret.age = Math.floor(Math.random() * 40);
  ret.likes = Math.floor(Math.random() * 100);
  return ret;
}

@Entry
@ComponentV2
struct Index {
  // 通过makeObserved给普通对象或是Sendable对象添加可观察能力
  @Local send: SendableData = UIUtils.makeObserved(new SendableData());

  build() {
    Column() {
      Text(this.send.name)
      Button("change name").onClick(() => {
        // 可以观察到属性的改变
        this.send.name += "0";
      })

      Button("task").onClick(() => {
        // 将待执行的函数放入taskpool内部任务队列等待，等待分发到工作线程执行。
        // 因为数据的构建和处理可以在子线程中完成，但有观察能力的数据不能传给子线程，只有在UI主线程里才可以操作可观察的数据。
        // 所以这里只是将`this.send`的属性`name`传给子线程操作。
        taskpool.execute(threadGetData, this.send.name).then(val => {
          // 和@Local一起使用，可以观察this.send的变化
          this.send = UIUtils.makeObserved(val as SendableData);
        })
      })
    }
  }
}
```
<!-- @[update_arkui_data](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/MakeobservedSendable.ets) -->