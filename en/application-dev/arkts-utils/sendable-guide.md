# Sendable Use Scenarios
Sendable objects can be passed by reference between concurrent instances. Compared with the serialization mode, the reference transfer mode is more efficient and does not lose the member methods carried in the class. Therefore, Sendable can solve the following problems:

- Transferring a large amount of data (for example, more than 100 KB) across concurrent instances

- Passing a class instance object carrying methods across concurrent instances

## Big data transmission across concurrent instances

The overhead of serialization across concurrent instances increases linearly with the data volume. When a large amount of data is transmitted (100 KB data takes about 1 ms to transmit), the overhead of data copy across concurrent instances is high, adversely affecting the parallelization performance. On the contrary, passing objects by reference improves performance.

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
  // Use TaskPool for data transfer.
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
            console.info(`Receive ACCELEROMETER data: {${data.data?.x}, ${data.data?.y}, ${data.data?.z}`);
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

```ts
// sendable.ets
// Assemble the data of a large size in a sendable class.
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


## Passing a class instance object carrying methods across concurrent instances

Methods will be lost during serialization of instance objects. In scenarios where instance methods must be called, use pass-by-reference. If data needs to be parsed during data processing, you can use the [ASON tool](ason-parsing-generation.md) to parse the data.


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
  console.info("SendableTestClass: name is: " + (obj as object)?.["name"]); // output: 'Alexa'
  console.info("SendableTestClass: age is: " + (obj as object)?.["age"]); // output: 23
  console.info("SendableTestClass: sex is: " + (obj as object)?.["sex"]); // output: 'female'
}
async function test() {
  // Use TaskPool for data transfer.
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

```ts
// sendable.ets
// Define a Test class to simulate the transfer of a class carrying methods.
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
