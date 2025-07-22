# Sendable使用场景
Sendable对象在不同并发实例间默认的传递方式为引用传递，相比序列化方式更高效，同时不会丢失class上携带的成员方法。因此，Sendable可以解决两个关键场景的问题：

- 跨并发实例传输大数据（例如达到100KB以上的数据）。

- 跨并发实例传递带方法的class实例对象。

## 跨并发实例传输大数据场景

由于跨并发实例序列化的开销随数据量线性增长，因此当传输数据量较大时（100KB的数据传输耗时约为1ms），跨并发实例的拷贝开销会影响应用性能。使用引用传递方式传输对象可提升性能。

**示例：**

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { testTypeA, testTypeB, Test } from './sendable';
import { BusinessError, emitter } from '@kit.BasicServicesKit';
 
// 在并发函数中模拟数据处理
@Concurrent
async function taskFunc(obj: Test) {
  console.info("test task res1 is: " + obj.data1.name + " res2 is: " + obj.data2.name);
}
 
async function test() {
  // 使用taskpool传递数据
  let a: testTypeA = new testTypeA("testTypeA");
  let b: testTypeB = new testTypeB("testTypeB");
  let obj: Test = new Test(a, b);
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
}
 
@Concurrent
function SensorListener() {
  // 监听逻辑
  // ...
}
 
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text("Listener task")
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          let sensorTask = new taskpool.LongTask(SensorListener);
          emitter.on({ eventId: 0 }, (data) => {
            // Do something here
            console.info(`Receive ACCELEROMETER data: {${data.data?.x}, ${data.data?.y}, ${data.data?.z}}`);
          });
          taskpool.execute(sensorTask).then(() => {
            console.info("Add listener of ACCELEROMETER success");
          }).catch((e: BusinessError) => {
            // Process error
          })
        })
      Text("Data processing task")
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          test();
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[across_concurrent_instance_transfer_large_data ](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/bigdata/src/main/ets/pages/Index.ets) -->

```ts
// sendable.ets
// 将数据量较大的数据在Sendable class中组装
@Sendable
export class testTypeA {
  name: string = "A";
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class testTypeB {
  name: string = "B";
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class Test {
  data1: testTypeA;
  data2: testTypeB;
  constructor(arg1: testTypeA, arg2: testTypeB) {
    this.data1 = arg1;
    this.data2 = arg2;
  }
}
```
<!-- @[across_concurrent_instance_transfer_large_data ](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/bigdata/src/main/ets/pages/sendable.ets) -->


## 跨并发实例传递带方法的class实例对象

由于序列化传输实例对象时会丢失方法，因此在需要调用实例方法时，需使用引用传递方式。在数据处理过程中有需要解析的数据，可使用[ASON工具](ason-parsing-generation.md)解析。

**示例：**

```ts
// Index.ets
import { taskpool, ArkTSUtils } from '@kit.ArkTS';
import { SendableTestClass, ISendable } from './sendable';
 
// 在并发函数中模拟数据处理
@Concurrent
async function taskFunc(sendableObj: SendableTestClass) {
  console.info("SendableTestClass: name is: " + sendableObj.printName() + ", age is: " + sendableObj.printAge() + ", sex is: " + sendableObj.printSex());
  sendableObj.setAge(28);
  console.info("SendableTestClass: age is: " + sendableObj.printAge());
 
  // 解析sendableObj.arr数据生成JSON字符串
  let str = ArkTSUtils.ASON.stringify(sendableObj.arr);
  console.info("SendableTestClass: str is: " + str);
 
  // 解析该数据并生成ISendable数据
  let jsonStr = '{"name": "Alexa", "age": 23, "sex": "female"}';
  let obj = ArkTSUtils.ASON.parse(jsonStr) as ISendable;
  console.info("SendableTestClass: type is: " + typeof obj);
  console.info("SendableTestClass: name is: " + (obj as object)?.["name"]); // 输出: 'Alexa'
  console.info("SendableTestClass: age is: " + (obj as object)?.["age"]); // 输出: 23
  console.info("SendableTestClass: sex is: " + (obj as object)?.["sex"]); // 输出: 'female'
}
async function test() {
  // 使用taskpool传递数据
  let obj: SendableTestClass = new SendableTestClass();
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
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
          test();
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
<!-- @[across_concurrent_instance_pass_class_method](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/crossconcurrency/src/main/ets/pages/Index.ets) -->

```ts
// sendable.ets
// 定义模拟类Test，模仿开发过程中需传递带方法的class
import { lang, collections } from '@kit.ArkTS'

export type ISendable = lang.ISendable;

@Sendable
export class SendableTestClass {
  name: string = 'John';
  age: number = 20;
  sex: string = "man";
  arr: collections.Array<number> = new collections.Array<number>(1, 2, 3);
  constructor() {
  }
  setAge(age: number) : void {
    this.age = age;
  }

  printName(): string {
    return this.name;
  }

  printAge(): number {
    return this.age;
  }

  printSex(): string {
    return this.sex;
  }
}
```
<!-- @[across_concurrent_instance_pass_class_method](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/crossconcurrency/src/main/ets/pages/sendable.ets) -->