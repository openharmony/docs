# ArkUI Data Updates

When data downloaded from the Internet or generated locally needs to be sent to the UI thread for display, the ArkUI annotation and [\@Sendable decorator](../arkts-utils/arkts-sendable.md#sendable-decorator) cannot modify variables and objects at the same time, in this scenario, you need to use [makeObserved](../quick-start/arkts-new-makeObserved.md) to import the observable Sendable shared data to ArkUI.

This example describes the following scenarios:
- **makeObserved** has the observation capability after data of the @Sendable type is passed in, and the change of the data can trigger UI re-rendering.
- Obtain an entire data from the subthread and replace the entire observable data of the UI thread.
- Re-execute **makeObserved** from the data obtained from the subthread to change the data to observable data.
- When data is passed from the main thread to a subthread, only unobservable data is passed. The return value of **makeObserved** cannot be directly passed to a subthread.

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

```ts
import { taskpool } from '@kit.ArkTS';
import { SendableData } from './SendableData';
import { UIUtils } from '@kit.ArkUI';

@Concurrent
function threadGetData(param: string): SendableData {
  // Process data in the subthread.
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
  // Use makeObserved to add the observation capability to a common object or a @Sendable decorated object.
  @Local send: SendableData = UIUtils.makeObserved(new SendableData());

  build() {
    Column() {
      Text(this.send.name)
      Button("change name").onClick(() => {
        // Change of the attribute can be observed.
        this.send.name += "0";
      })

      Button("task").onClick(() => {
        // Places a function to be executed in the internal queue of the task pool. The function will be distributed to the worker thread for execution.
        **NOTE**<br>Data can be constructed and processed in subthreads. However, observable data can be processded only in the main thread.
        // Therefore, only the'name' attribute of'this.send' is transferred to the subthread.
        taskpool.execute(threadGetData, this.send.name).then(val => {
          // Used together with @Local to observe the change of this.send.
          this.send = UIUtils.makeObserved(val as SendableData);
        })
      })
    }
  }
}
```
