# Use Scenarios of Sendable
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
Sendable objects are passed by reference across concurrent instances by default. This approach is more efficient than serialization and does not lose class member methods. Therefore, Sendable is particularly useful in two scenarios:

- Transmitting a large amount of data (for example, data exceeding 100 KB) across concurrent instances

- Passing class instances carrying methods across concurrent instances

## Transmitting Large Data Across Concurrent Instances

Serialization overhead increases linearly with the amount of data. When transmitting large data volumes (100 KB taking approximately 1 ms), the copying overhead can significantly impact application performance. On the contrary, passing objects by reference can greatly enhance performance.

**Example**

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { testTypeA, testTypeB, Test } from './sendable';
import { BusinessError, emitter } from '@kit.BasicServicesKit';
 
// Simulate data processing in a concurrent function.
@Concurrent
async function taskFunc(obj: Test) {
  console.info("test task res1 is: " + obj.data1.name + " res2 is: " + obj.data2.name);
}
 
async function test() {
  // Use TaskPool to pass data.
  let a: testTypeA = new testTypeA("testTypeA");
  let b: testTypeB = new testTypeB("testTypeB");
  let obj: Test = new Test(a, b);
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
}
 
@Concurrent
function SensorListener() {
  // Listening logic
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
<!-- @[across_concurrent_instance_transfer_large_data ](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/bigdata/src/main/ets/pages/Index.ets) -->

```ts
// sendable.ets
// Assemble large data in a Sendable class.
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
<!-- @[across_concurrent_instance_transfer_large_data ](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/bigdata/src/main/ets/pages/sendable.ets) -->


## Passing Class Instances Carrying Methods Across Concurrent Instances

Methods are lost during serialization of instance objects. Therefore, in scenarios where instance methods must be called, passing objects by reference is essential. If data parsing is required during processing, use the [ASON utility](ason-parsing-generation.md).

**Example**

```ts
// Index.ets
import { taskpool, ArkTSUtils } from '@kit.ArkTS';
import { SendableTestClass, ISendable } from './sendable';
 
// Simulate data processing in a concurrent function.
@Concurrent
async function taskFunc(sendableObj: SendableTestClass) {
  console.info("SendableTestClass: name is: " + sendableObj.printName() + ", age is: " + sendableObj.printAge() + ", sex is: " + sendableObj.printSex());
  sendableObj.setAge(28);
  console.info("SendableTestClass: age is: " + sendableObj.printAge());
 
  // Parse the sendableObj.arr data to generate a JSON string.
  let str = ArkTSUtils.ASON.stringify(sendableObj.arr);
  console.info("SendableTestClass: str is: " + str);
 
  // Parse the data and generate ISendable data.
  let jsonStr = '{"name": "Alexa", "age": 23, "sex": "female"}';
  let obj = ArkTSUtils.ASON.parse(jsonStr) as ISendable;
  console.info("SendableTestClass: type is: " + typeof obj);
  console.info("SendableTestClass: name is: " + (obj as object)?.["name"]); // Output: 'Alexa'
  console.info("SendableTestClass: age is: " + (obj as object)?.["age"]); // Output: 23
  console.info("SendableTestClass: sex is: " + (obj as object)?.["sex"]); // Output: 'female'
}
async function test() {
  // Use TaskPool to pass data.
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
<!-- @[across_concurrent_instance_pass_class_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/crossconcurrency/src/main/ets/pages/Index.ets) -->

```ts
// sendable.ets
// Define the SendableTestClass to simulate the operation of passing a class instance carrying methods.
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
<!-- @[across_concurrent_instance_pass_class_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableScenarios/crossconcurrency/src/main/ets/pages/sendable.ets) -->
