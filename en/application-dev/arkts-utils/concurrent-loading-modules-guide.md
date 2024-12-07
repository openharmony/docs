# Concurrent Loading of Service Modules

During app startup, multiple service modules need to be loaded. For example, if different modules of a map app, such as positioning, taxi hailing, and navigation, are all initialized in the UI main thread, the cold start time will be greatly affected. In this case, the functions of these modules need to be loaded in different sub-threads in parallel to reduce the startup time.

The TaskPool capability provided by ArkTS can be used to move different service initialization tasks to subthreads. Service modules can be implemented as [NativeBinding object](transferabled-object.md) by sinking C++, or [Sendable object](arkts-sendable.md) can be defined at the ArkTS layer. The initialized module can be returned to the UI main thread for calling. The implementation is as follows:

1. Definition of each service function (SDK) module (The Sendable object is used as an example.)
   The calculator service module is defined as follows:

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

   The timer service module is defined as follows:

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

2. The UI main thread triggers the distribution of each service module to the sub-thread. After the loading is complete, the UI main thread uses the service module.

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
