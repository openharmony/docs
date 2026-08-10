# Sendable使用场景
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
Sendable对象在不同并发实例间默认采用引用传递，这种方式比序列化更高效，且不会丢失类成员方法。因此，Sendable能够解决两个关键场景的问题：

- 跨并发实例传输大数据（例如达到100KB以上的数据）。

- 跨并发实例传递带方法的class实例对象。

## 跨并发实例传输大数据场景

由于跨并发实例序列化的开销随数据量线性增长，因此当传输数据量较大时（100KB的数据传输耗时约为1ms），跨并发实例的拷贝开销会影响应用性能。使用引用传递方式传输对象可提升性能。

**示例：**
<!-- @[across_concurrent_instance_transfer_large_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/SendableScenarios/bigdata/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { taskpool } from '@kit.ArkTS';
import { TestTypeA, TestTypeB, Test } from './sendable';
import { BusinessError, emitter } from '@kit.BasicServicesKit';

// 在并发函数中模拟数据处理
@Concurrent
async function taskFunc(obj: Test) {
  console.info(`test task res1 is: ${obj.data1.name} res2 is: ${obj.data2.name}`);
}

async function test() {
  // 使用taskpool传递数据
  let a: TestTypeA = new TestTypeA('testTypeA');
  let b: TestTypeB = new TestTypeB('testTypeB');
  let obj: Test = new Test(a, b);
  let task: taskpool.Task = new taskpool.Task(taskFunc, obj);
  await taskpool.execute(task);
}

@Concurrent
function sensorListener() {
  // 监听逻辑
  // ...
  console.info('Monitoring logic');
}

@Entry
@Component
struct Index {
  @State listenerTask: string = 'Listener task';
  @State dataProcessingTask: string = 'Data processing task';

  build() {
    Column() {
      Text(this.listenerTask)
        .id('Listener task')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          let sensorTask = new taskpool.LongTask(sensorListener);
          // ...
          taskpool.execute(sensorTask).then(() => {
            this.listenerTask = 'success';
            console.info('Add listener of ACCELEROMETER success');
          }).catch((e: BusinessError) => {
            // Process error
            this.listenerTask = 'failed';
          })
        })
      Text(this.dataProcessingTask)
        .id('Data processing task')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          test().then(() => {
            this.dataProcessingTask = 'success';
          }).catch((e: BusinessError) => {
            this.dataProcessingTask = 'failed';
            console.error('taskpool execute failed. Code: ' + e.code + ', message: ' + e.message);
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```


<!-- @[across_concurrent_instance_transfer_large_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/SendableScenarios/bigdata/src/main/ets/pages/sendable.ets) -->  

``` TypeScript
// 将数据量较大的数据在Sendable class中组装
@Sendable
export class TestTypeA {
  public name: string = 'A';
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class TestTypeB {
  public name: string = 'B';
  constructor(name: string) {
    this.name = name;
  }
}

@Sendable
export class Test {
  public data1: TestTypeA;
  public data2: TestTypeB;
  constructor(arg1: TestTypeA, arg2: TestTypeB) {
    this.data1 = arg1;
    this.data2 = arg2;
  }
}
```



## 跨并发实例传递带方法的class实例对象

在序列化传输实例对象时，会丢失方法。因此，若需调用实例方法，应使用引用传递。处理数据时，若需解析数据，可使用[ASON工具](ason-parsing-generation.md)。

**示例：**
<!-- @[across_concurrent_instance_pass_class_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/SendableScenarios/crossconcurrency/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { taskpool, ArkTSUtils } from '@kit.ArkTS';
import { SendableTestClass, ISendable } from './sendable';

// 在并发函数中模拟数据处理
@Concurrent
async function taskFunc(sendableObj: SendableTestClass) {
  console.info(`SendableTestClass: name is: ${sendableObj.printName()}, age is: ${sendableObj.printAge()}, sex is: ${sendableObj.printSex()}`);
  sendableObj.setAge(28);
  console.info(`SendableTestClass: age is: ${sendableObj.printAge()}`);

  // 解析sendableObj.arr数据生成JSON字符串
  let str = ArkTSUtils.ASON.stringify(sendableObj.arr);
  console.info(`SendableTestClass: str is: ${str}`);

  // 解析该数据并生成ISendable数据
  let jsonStr = '{"name": "Alexa", "age": 23, "sex": "female"}';
  let obj = ArkTSUtils.ASON.parse(jsonStr) as ISendable;
  console.info(`SendableTestClass: type is: ${typeof obj}`);
  console.info(`SendableTestClass: name is: ${(obj as object)?.['name']}`); // 输出: 'Alexa'
  console.info(`SendableTestClass: age is: ${(obj as object)?.['age']}`); // 输出: 23
  console.info(`SendableTestClass: sex is: ${(obj as object)?.['sex']}`); // 输出: 'female'
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
          await test();
          this.message = 'success';
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

<!-- @[across_concurrent_instance_pass_class_method](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/SendableScenarios/crossconcurrency/src/main/ets/pages/sendable.ets) --> 

``` TypeScript
// 定义模拟类Test，模仿开发过程中需传递带方法的class
import { lang, collections } from '@kit.ArkTS'

export type ISendable = lang.ISendable;

@Sendable
export class SendableTestClass {
  public name: string = 'John';
  public age: number = 20;
  public sex: string = 'man';
  public arr: collections.Array<number> = new collections.Array<number>(1, 2, 3);

  constructor() {
  }

  setAge(age: number): void {
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
