# makeObserved API: Changing Unobservable Data to Observable Data

To change the unobservable data to observable data, you can use the [makeObserved](../../reference/apis-arkui/js-apis-StateManagement.md#makeobserved) API.


**makeObserved** can be used when \@Trace cannot be used. Before reading this topic, you are advised to read [\@Trace](./arkts-new-observedV2-and-trace.md).

>**NOTE**
>
>The **makeObserved** API in UIUtils is supported since API version 12.

## Overview

- The state management framework provides [@ObservedV2 and @Trace](./arkts-new-observedV2-and-trace.md) decorators to observe class property changes. The **makeObserved** API is mainly used in scenarios where @ObservedV2 or @Trace cannot be used. For example:

  - Object in a third-party package defined by class is unobservable. You cannot manually add the @Trace tag to the attributes to be observed in the class, so **makeObserved** can be used to make this object observable.

  - The member property of the current class cannot be modified. This is because @Trace will dynamically change the class property when it observes. But this behavior is not allowed in the @Sendable decorated class, therefore, you can use **makeObserved** instead.

  - Anonymous object returned by API or JSON.parse does not have a class declaration. In this scenario, you cannot use @Trace to mark that the current attribute, therefore, **makeObserved** can be used instead.


- To use the **makeObserved** API, you need to import UIUtils.
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```

## Constraints

- The parameters of **makeObserved** support only non-null object types.
  - Undefined and null: not supported. The parameters itself is returned and no processing is performed.
  - Non-object type: An error is reported during compilation.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  let res1 = UIUtils.makeObserved(2); // Invalid input parameter. An error is reported during compilation.
  let res2 = UIUtils.makeObserved(undefined); // Invalid input parameter. The parameter itself is returned, that is, res2 = = = undefined.
  let res3 = UIUtils.makeObserved(null); // Invalid input parameter. The parameter itself is returned, that is, res3 === null.

  class Info {
    id: number = 0;
  }
  let rawInfo: Info = UIUtils.makeObserved(new Info()); // Correct usage.
  ```

- Instances of classes decorated by [@ObservedV2](./arkts-new-observedV2-and-trace.md) and [@Observed](./arkts-observed-and-objectlink.md) and proxy data that has been encapsulated by **makeObserved** cannot be passed in and are directly returned without processing to prevent dual proxies.
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  @ObservedV2
  class Info {
    @Trace id: number = 0;
  }
  // Incorrect usage: If makeObserved finds that the input instance is an instance of a class decorated by @ObservedV2, makeObserved returns the input object itself.
  let observedInfo: Info = UIUtils.makeObserved(new Info());

  class Info2 {
    id: number = 0;
  }
  // Correct usage. The input object is neither an instance of the class decorated by @ObservedV2 or @Observed nor the proxy data encapsulated by makeObserved.
  // Return observable data.
  let observedInfo1: Info2 = UIUtils.makeObserved(new Info2());
  // Incorrect usage. The input object is the proxy data encapsulated by makeObserved, which is not processed this time.
  let observedInfo2: Info2 = UIUtils.makeObserved(observedInfo1);
  ```
- **makeObserved** can be used in custom components decorated by @Component, but cannot be used together with the state variable decorator in state management V1. If they are used together, a runtime exception is thrown.
  ```ts
  // Incorrect usage. An exception occurs during running.
  @State message: Info = UIUtils.makeObserved(new Info(20));
  ```
  The following **message2** does not throw an exception because **this.message** is decorated by @State and its implementation is the same as @Observed, while the input parameter of **UIUtils.makeObserved** is the @Observed decorated class, which is returned directly. Therefore, the initial value of **message2** is not the return value of **makeObserved**, but a variable decorated by @State.
  ```ts
  import { UIUtils } from '@kit.ArkUI';
  class Person {
    age: number = 10;
  }
  class Info {
    id: number = 0;
    person: Person = new Person();
  }
  @Entry
  @Component
  struct Index {
    @State message: Info = new Info();
    @State message2: Info = UIUtils.makeObserved(this.message); // An exception does not throw.
    build() {
      Column() {
        Text(`${this.message2.person.age}`)
          .onClick(() => {
            // The UI is not re-rendered because only the changes at the first layer can be observed by the @State.
            this.message2.person.age++;
          })
      }
    }
  }
  ```
### makeObserved Is Used Only for Input Parameters and Return Value Still Has Observation Capability

 - **message** is decorated by @Local and has the capability of observing its own value changes. Its initial value is the return value of **makeObserved**, which supports in-depth observation.
 - Click **change id** to re-render the UI.
 - Click **change Info** to set **this.message** to unobservable data. Click **change id** again, UI cannot be re-rendered.
 - Click **change Info1** to set **this.message** to observable data. Click **change id** again, UI can be re-rendered.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  class Info {
    id: number = 0;
    constructor(id: number) {
      this.id = id;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local message: Info = UIUtils.makeObserved(new Info(20));
    build() {
      Column() {
        Button(`change id`).onClick(() => {
          this.message.id++;
        })
        Button(`change Info ${this.message.id}`).onClick(() => {
          this.message = new Info(30);
        })
        Button(`change Info1 ${this.message.id}`).onClick(() => {
          this.message = UIUtils.makeObserved(new Info(30));
        })
      }
    }
  }
  ```

## Supported Types and Observed Changes

### Supported Types

- Classes that are not decorated by @Observed or @ObserveV2.
- Array, Map, Set, and Date types.
- collections.Array, collections.Set, and collections.Map.
- Object returned by JSON.parse.
- @Sendable decorated class.

### Observed Changes

- When an instance of the built-in type or collections type is passed by **makeObserved**, you can observe the changes.

  | Type | APIs that Can Observe Changes                                             |
  | ----- | ------------------------------------------------------------ |
  | Array | push, pop, shift, unshift, splice, copyWithin, fill, reverse, sort|
  | collections.Array | push, pop, shift, unshift, splice, fill, reverse, sort, shrinkTo, extendTo|
  | Map/collections.Map   | set, clear, delete                                |
  | Set/collections.Set   | add, clear, delete                                |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds|

## Use Scenarios

### Using makeObserved and @Sendable Decorated Class Together

[@Sendable](../../arkts-utils/arkts-sendable.md) is used to process concurrent tasks in application scenarios. The **makeObserved** and @Sendable are used together to meet the requirements of big data processing in the sub-thread and **ViewModel** display and data observation in the UI thread in common application development. For details about @Sendable, see [Multithreaded Concurrency Overview (TaskPool and Worker)](../../arkts-utils/multi-thread-concurrency-overview.md).

This section describes the following scenarios:
- **makeObserved** has the observation capability after data of the @Sendable type is passed in, and the change of the data can trigger UI re-rendering.
- Obtain an entire data from the subthread and replace the entire observable data of the UI thread.
- Re-execute **makeObserved** from the data obtained from the subthread to change the data to observable data.
- When data is passed from the main thread to a subthread, only unobservable data is passed. The return value of **makeObserved** cannot be directly passed to a subthread.

Example:

```ts
// SendableData.ets
@Sendable
export class SendableData  {
  name: string = 'Tom';
  age: number = 20;
  gender: number = 1;
  // Other attributes are omitted here.
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
struct ObservedSendableTest {
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
        taskpool.execute(threadGetData, this.send.name).then(val => {
          // Used together with @Local to observe the change of this.send.
          this.send = UIUtils.makeObserved(val as SendableData);
        })
      })
    }
  }
}
```
**NOTE**<br>Data can be constructed and processed in subthreads. However, observable data can be processed only in the main thread. Therefore, in the preceding example, only the **name** attribute of **this.send** is passed to the subthread.

### Using makeObserved and collections.Array/collections.Set/collections.Map Together
**collections** provide ArkTS container sets for high-performance data passing in concurrent scenarios. For details, see [@arkts.collections (ArkTS Collections)](../../reference/apis-arkts/js-apis-arkts-collections.md).
makeObserved can be used to import an observable **colletions** container to ArkUI. However, makeObserved cannot be used together with the state variable decorators of V1, such as @State and @Prop. Otherwise, a runtime exception will be thrown.

#### collections.Array
The following APIs can trigger UI re-rendering:
- Changing the array length: push, pop, shift, unshift, splice, shrinkTo and extendTo
- Changing the array items: sort and fill.

Other APIs do not change the original array. Therefore, the UI re-rendering is not triggered.

```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

@Sendable
class Info {
  id: number = 0;
  name: string = 'cc';

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct Index {
  scroller: Scroller = new Scroller();
  @Local arrCollect: collections.Array<Info> =
    UIUtils.makeObserved(new collections.Array<Info>(new Info(1), new Info(2)));

  build() {
    Column() {
      // The ForEach API supports only Array<any>. collections.Array<any> is not supported.
      // However, the array APIs used for ForEach implementation are provided in collections.Array. Therefore, you can assert an Array type using the as keyword.
      // The assertion does not change the original data type.
      ForEach(this.arrCollect as object as Array<Info>, (item: Info) => {
        Text(`${item.id}`).onClick(() => {
          item.id++;
        })
      }, (item: Info, index) => item.id.toString() + index.toString())
      Divider()
        .color('blue')
      if (this.arrCollect.length > 0) {
        Text(`the first one ${this.arrCollect[this.arrCollect.length - this.arrCollect.length].id}`)
        Text(`the last one ${this.arrCollect[this.arrCollect.length - 1].id}`)
      }
      Divider()
        .color('blue')

      /****************************APIs for Changing the Data Length**************************/
      Scroll(this.scroller) {
        Column({space: 10}) {
          // push: adds a new element.
          Button('push').onClick(() => {
            this.arrCollect.push(new Info(30));
          })
          // pop: deletes the last element.
          Button('pop').onClick(() => {
            this.arrCollect.pop();
          })
          // shift: deletes the first element.
          Button('shift').onClick(() => {
            this.arrCollect.shift();
          })
          // unshift: inserts a new item at the beginning of the array.
          Button('unshift').onClick(() => {
            this.arrCollect.unshift(new Info(50));
          })
          // splice: deletes an element from the specified position of the array.
          Button('splice').onClick(() => {
            this.arrCollect.splice(1);
          })

          // shrinkTo: shrinks the array length to a specified length.
          Button('shrinkTo').onClick(() => {
            this.arrCollect.shrinkTo(1);
          })
          // extendTo: extends the array length to a specified length.
          Button('extendTo').onClick(() => {
            this.arrCollect.extendTo(6, new Info(20));
          })

          Divider()
            .color('blue')

          /****************************************APIs for Changing the Array Item*****************/
          // sort: arranging the Array item in descending order.
          Button('sort').onClick(() => {
            this.arrCollect.sort((a: Info, b: Info) => b.id - a.id);
          })
          // fill: fills in the specified part with a value.
          Button('fill').onClick(() => {
            this.arrCollect.fill(new Info(5), 0, 2);
          })

          /*****************************APIs for Not Changing the Array Item***************************/
          // slice: returns a new array. The original array is copied using Array.slice(start,end), which does not change the original array. Therefore, directly invoking slice does not trigger UI re-rendering.
          // You can construct a case to assign the return data of the shallow copy to this.arrCollect. Note that makeObserved must be called here. Otherwise, the observation capability will be lost after this.arr is assigned a value by a common variable.
          Button('slice').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.slice(0, 1));
          })
          // map: The principle is the same as above.
          Button('map').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.map((value) => {
              value.id += 10;
              return value;
            }))
          })
          // filter: The principle is the same as above.
          Button('filter').onClick(() => {
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.filter((value: Info) => value.id % 2 === 0));
          })

          // concat: The principle is the same as above.
          Button('concat').onClick(() => {
            let array1 = new collections.Array(new Info(100))
            this.arrCollect = UIUtils.makeObserved(this.arrCollect.concat(array1));
          })
        }.height('200%')
      }.height('60%')
    }
    .height('100%')
    .width('100%')
  }
}
```
#### collections.Map

The following APIs can trigger UI re-rendering: set, clear, and delete.
```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

@Sendable
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct CollectionMap {
  mapCollect: collections.Map<string, Info> = UIUtils.makeObserved(new collections.Map<string, Info>([['a', new Info(10)], ['b', new Info(20)]]));

  build() {
    Column() {
      // this.mapCollect.keys() returns an iterator which is not supported by Foreach. Therefore, Array.from is used to generate data in shallow copy mode.
      ForEach(Array.from(this.mapCollect.keys()), (item: string) => {
        Text(`${this.mapCollect.get(item)?.id}`).onClick(() => {
          let value: Info|undefined = this.mapCollect.get(item);
          if (value) {
            value.id++;
          }
        })
      }, (item: string, index) => item + index.toString())

      // set c
      Button('set c').onClick(() => {
        this.mapCollect.set('c', new Info(30));
      })
      // delete c
      Button('delete c').onClick(() => {
        if (this.mapCollect.has('c')) {
          this.mapCollect.delete('c');
        }
      })
      // clear
      Button('clear').onClick(() => {
        this.mapCollect.clear();
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

#### collections.Set
The following APIs can trigger UI re-rendering: add, clear, and delete.

```ts
import { collections } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';
@Sendable
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@ComponentV2
struct Index {
  set: collections.Set<Info> = UIUtils.makeObserved(new collections.Set<Info>([new Info(10), new Info(20)]));

  build() {
    Column() {
      // ForEach does not support iterators. Therefore, Array.from is used to generate data in shallow copy mode.
      // However, the new array generated by shallow copy does not have the observation capability. To ensure that the data can be observed when the ForEach component accesses the item, makeObserved needs to be called again.
      ForEach((UIUtils.makeObserved(Array.from(this.set.values()))), (item: Info) => {
        Text(`${item.id}`).onClick(() => {
          item.id++;
        })
      }, (item: Info, index) => item.id + index.toString())

      // add
      Button('add').onClick(() => {
        this.set.add(new Info(30));
        console.log('size:' + this.set.size);
      })
      // delete
      Button('delete').onClick(() => {
        let iterator = this.set.keys();
        this.set.delete(iterator.next().value);
      })
      // clear
      Button('clear').onClick(() => {
        this.set.clear();
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

### Input Parameter of makeObserved Is the Return Value of JSON.parse
**JSON.parse** returns an object which cannot be decorated by @Trace. You can use **makeObserved** to make it observable.

```ts
import { JSON } from '@kit.ArkTS';
import { UIUtils } from '@kit.ArkUI';

class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}

let test: Record<string, number> = { "a": 123 };
let testJsonStr :string = JSON.stringify(test);
let test2: Record<string, Info> = { "a": new Info(20) };
let test2JsonStr: string = JSON.stringify(test2);

@Entry
@ComponentV2
struct Index {
  message: Record<string, number> = UIUtils.makeObserved<Record<string, number>>(JSON.parse(testJsonStr) as Record<string, number>);
  message2: Record<string, Info> = UIUtils.makeObserved<Record<string, Info>>(JSON.parse(test2JsonStr) as Record<string, Info>);

  build() {
    Column() {
      Text(`${this.message.a}`)
        .fontSize(50)
        .onClick(() => {
          this.message.a++;
        })
      Text(`${this.message2.a.id}`)
        .fontSize(50)
        .onClick(() => {
          this.message2.a.id++;
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### Using makeObserved and Decorators of V2 Together
**makeObserved** can be used with the decorators of V2. For @Monitor and @Computed, the class instance decorated by @Observed or ObservedV2 passed by makeObserved returns itself. Therefore, @Monitor or @Computed cannot be defined in a class but in a custom component.

Example:
```ts
import { UIUtils } from '@kit.ArkUI';

class Info {
  id: number = 0;
  age: number = 20;

  constructor(id: number) {
    this.id = id;
  }
}

@Entry
@ComponentV2
struct Index {
  @Local message: Info = UIUtils.makeObserved(new Info(20));

  @Monitor('message.id')
  onStrChange(monitor: IMonitor) {
    console.log(`name change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  @Computed
  get ageId() {
    console.info("---------Computed----------");
    return this.message.id + ' ' + this.message.age;
  }

  build() {
    Column() {
      Text(`id: ${this.message.id}`)
        .fontSize(50)
        .onClick(() => {
          this.message.id++;
        })

      Text(`age: ${this.message.age}`)
        .fontSize(50)
        .onClick(() => {
          this.message.age++;
        })

      Text(`Computed age+id: ${this.ageId}`)
        .fontSize(50)

      Button('change Info').onClick(() => {
        this.message = UIUtils.makeObserved(new Info(200));
      })

      Child({message: this.message})
    }
    .height('100%')
    .width('100%')
  }
}

@ComponentV2
struct Child {
  @Param @Require message: Info;
  build() {
    Text(`Child id: ${this.message.id}`)
  }
}
```

### Using makeObserved in @Component
**makeObserved** cannot be used with the state variable decorator of V1, but can be used in custom components decorated by @Component.

```ts
import { UIUtils } from '@kit.ArkUI';
class Info {
  id: number = 0;

  constructor(id: number) {
    this.id = id;
  }
}


@Entry
@Component
struct Index {
  // Using makeObserved together with @State, a runtime exception is thrown.
  message: Info = UIUtils.makeObserved(new Info(20));

  build() {
    RelativeContainer() {
      Text(`${this.message.id}`)
        .onClick(() => {
          this.message.id++;
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## FAQs
### Original Object Can Be Assigned Value Using getTarget but Fails to Trigger UI Re-render
[getTarget](./arkts-new-getTarget.md) can be used to obtain the original object before adding a proxy in the state management.

The observation object encapsulated by **makeObserved** can obtain its original object through **getTarget**. The value changes to the original object do not trigger UI re-rendering.

Example:
1. Click the first **Text** component and obtain its original object through **getTarget**. In this case, modifying the attributes of the original object does not trigger UI re-rendering, but a value is assigned to the data.
2. Click the second **Text** component. If the **this.observedObj** attribute is modified, the UI is re-rendered and the value of **Text** is **21**.

```ts
import { UIUtils } from '@kit.ArkUI';
class Info {
  id: number = 0;
}

@Entry
@Component
struct Index {
  observedObj: Info = UIUtils.makeObserved(new Info());
  build() {
    Column() {
      Text(`${this.observedObj.id}`)
        .fontSize(50)
        .onClick(() => {
          // Use getTarget to obtain the original object and assign this.observedObj to unobservable data.
          let rawObj: Info= UIUtils.getTarget(this.observedObj);
          // The UI is not re-rendered, but a value is assigned to the data.
          rawObj.id = 20;
        })

      Text(`${this.observedObj.id}`)
        .fontSize(50)
        .onClick(() => {
          // Triggers UI re-rendering. The value of Text is 21.
          this.observedObj.id++;
        })
    }
  }
}
```
