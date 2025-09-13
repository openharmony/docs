# ArkUI Data Updates
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

When data, regardless of whether it is downloaded from the Internet or generated locally, needs to be sent to the UI thread for display, the annotations and the [\@Sendable decorator](../arkts-utils/arkts-sendable.md#sendable-decorator) in ArkUI cannot simultaneously decorate variables and objects. Therefore, it is necessary to use [makeObserved](../ui/state-management/arkts-new-makeObserved.md) to import observable Sendable data into ArkUI.

This example describes the following scenarios:
- When **makeObserved** is used with @Sendable data, it enables observability of changes that can trigger UI refreshes.
- Data is fetched from a child thread and used to replace the observable data in the UI thread entirely.
- The data fetched from the child thread is reprocessed with **makeObserved** to become observable.
- Only non-observable data is passed from the UI main thread back to the child thread. The return value of **makeObserved** cannot be directly passed to child threads.

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
<!-- @[define_sendable_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/SendableData.ets) -->

```ts
import { taskpool } from '@kit.ArkTS';
import { SendableData } from './SendableData';
import { UIUtils } from '@kit.ArkUI';

@Concurrent
function threadGetData(param: string): SendableData {
  // Process data in the child thread.
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
  // Use makeObserved to add observation to a regular object or a @Sendable object.
  @Local send: SendableData = UIUtils.makeObserved(new SendableData());

  build() {
    Column() {
      Text(this.send.name)
      Button("change name").onClick(() => {
        // Changes to properties are observable.
        this.send.name += "0";
      })

      Button("task").onClick(() => {
        // Enqueue the function to be executed in the task pool, waiting to be dispatched to a worker thread.
        // Data construction and processing can be done in the child thread, but observable data cannot be passed to the child thread (observable data can only be manipulated in the UI main thread).
        // Therefore, only the 'name' property of 'this.send' is passed to the child thread.
        taskpool.execute(threadGetData, this.send.name).then(val => {
          // Used together with @Local to observe changes to 'this.send'.
          this.send = UIUtils.makeObserved(val as SendableData);
        })
      })
    }
  }
}
```
<!-- @[update_arkui_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/MakeobservedSendable.ets) -->
