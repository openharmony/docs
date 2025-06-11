# 业务模块并发加载场景

在应用启动过程中，会有多个业务模块需要加载，例如地图类应用的定位、打车、导航等不同的模块，如果全部在UI主线程初始化，则会严重影响冷启动耗时。此时需要在不同子线程并行化加载这些业务模块，降低启动耗时。

通过使用ArkTS提供的TaskPool能力，可以将不同的业务初始化任务移到子线程中。业务模块可通过下沉C++实现为[NativeBinding对象](transferabled-object.md)或在ArkTS层定义为[Sendable对象](arkts-sendable.md)，从而将初始化的模块返回给UI主线程调用，实现如下。

1. 各业务功能（SDK）模块定义（这里以Sendable对象为例）。
   计算器业务模块定义如下：

   ```ts
   // sdk/Calculator.ets
   import { collections } from '@kit.ArkTS'
   
   @Sendable
   export class Calculator {
     history?: collections.Array<collections.Array<string>>
     totalCount: number = 0
   
     static init(): Calculator {
       let calc = new Calculator()
       calc.totalCount = 0
       calc.history = collections.Array.create(calc.totalCount, collections.Array.create(2, ""));
       return calc
     }
   
     add(a: number, b: number) {
       let result = a + b;
       this.newCalc(`${a} + ${b}`, `${result}`);
       return result
     }
   
     sub(a: number, b: number) {
       let result = a - b;
       this.newCalc(`${a} - ${b}`, `${result}`);
       return result
     }
   
     mul(a: number, b: number) {
       let result = a * b;
       this.newCalc(`${a} * ${b}`, `${result}`);
       return result
     }
   
     div(a: number, b: number) {
       let result = a / b;
       this.newCalc(`${a} / ${b}`, `${result}`);
       return result
     }
   
     getHistory(): collections.Array<collections.Array<string>> {
       return this.history!;
     }
   
     showHistory() {
       for (let i = 0; i < this.totalCount; i++) {
         console.info(`${i}: ${this.history![i][0]} = ${this.history![i][1]}`)
       }
     }
   
     private newCalc(opt: string, ret: string) {
       let newRecord = new collections.Array<string>(opt, ret)
       this.totalCount = this.history!.unshift(newRecord)
     }
   }
   ```
   <!-- @[define_calculator_module](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/sdk/Calculator.ets) -->

   定时器业务模块定义如下：

   ```ts
   // sdk/TimerSdk.ets
   @Sendable
   export class TimerSdk {
     static init(): TimerSdk {
       let timer = new TimerSdk()
       return timer
     }
   
     async Countdown(time: number) {
       return new Promise((resolve: (value: boolean) => void) => {
         setTimeout(() => {
           resolve(true)
         }, time)
       })
     }
   }
   ```
   <!-- @[define_timer_module](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/sdk/TimerSdk.ets) -->

2. 在UI主线程触发各业务模块分发到子线程，加载完成后在UI主线程使用，示例如下：

   ```ts
   // Index.ets
   import { Calculator } from '../sdk/Calculator'
   import { TimerSdk } from '../sdk/TimerSdk'
   import { taskpool } from '@kit.ArkTS';
   
   @Concurrent
   function initCalculator(): Calculator {
     return Calculator.init()
   }
   
   @Concurrent
   function initTimerSdk(): TimerSdk {
     return TimerSdk.init()
   }
   
   @Entry
   @Component
   struct Index {
     calc?: Calculator
     timer?: TimerSdk
   
     aboutToAppear(): void {
       taskpool.execute(initCalculator).then((ret) => {
         this.calc = ret as Calculator
       })
       taskpool.execute(initTimerSdk).then((ret) => {
         this.timer = ret as TimerSdk
       })
     }
   
     build() {
       Row() {
         Column() {
           Text("calculate add")
             .id('add')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               let result = this.calc?.add(1, 2)
               console.info(`Result is ${result}`)
             })
           Text("show history")
             .id('show')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               this.calc?.showHistory()
             })
           Text("countdown")
             .id('get')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .alignRules({
               center: { anchor: '__container__', align: VerticalAlign.Center },
               middle: { anchor: '__container__', align: HorizontalAlign.Center }
             })
             .onClick(async () => {
               console.info(`Timer start`)
               await this.timer?.Countdown(1000);
               console.info(`Timer end`)
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!-- @[distribute_child_thread](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/PracticalCases/entry/src/main/ets/managers/ConcurrentLoadingModulesGuide.ets) -->
