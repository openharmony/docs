# Troubleshooting Guide for Application Performance Optimization

## Overview

This document summarizes common performance optimization specifications during application development and provides examples of common positive and negative code to help developers solve most performance problems.

### Performance Specifications Overview
| &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;  &emsp;&emsp;  &emsp;&emsp; <br>Category<br>&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;  &emsp;&emsp;   |<br>High Frequency (Full Score: 5)<br>&emsp;&emsp;&emsp;&emsp;   | Specifications (Check Items)      | Practice Method               |            <br>Sample Code<br>&emsp;&emsp;&emsp;&emsp;                 |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------------------------:|:---------------------------------------------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------------------------------------------:|
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          5                          | You are not advised to perform time-consuming operations in life cycles such as aboutToAppear() and aboutToDisappear(). | Check all aboutToAppear and aboutToDisappear functions (or use Trace to check whether there are time-consuming operations). Change them to setTimeOut or execute them in TaskPool.                                         |       [Code Example](#You are not advised to perform time-consuming operations in lifecycles such as abouttoappearabouttodisappear.)       |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          5                          | Do not perform time-consuming operations (such as ArkUI API callback, network access callback, and await) in callback functions.           | Check all callback functions (or view them through Trace), especially ArkUI APIs and network callback functions. Check whether time-consuming operations are performed and whether the await operation is used. Change the await operation to setTimeOut or execute it in TaskPool.                     |            [Code Example] (# Do not perform time-consuming operations in the callback function. The arkui API calls back the network access callback await.)            |
| Response Delay &nbsp;/&nbsp;Completion Delay &nbsp;/&nbsp;Frame Rate                                                                                                                                    |                          5                          | LazyForEach is not used in the list scenario, component reuse is used, and list items are cached.           | Check the code that uses LazyForEach and check whether the component reuse (@Reusable) and cache list item (cacheCount) are used.                                                                                                          |                [Code Example] (#In the list scenario, the lazyforeach component is not used to reuse cache list items.)                |
| Completion Delay                                                                                                                                                                    |                          5                          | The web does not use pre-connection, and the engine is not initialized in advance.   | When an ability is created for an application, the kernel is initialized in advance in the OnCreate phase. It is recommended that the engine be initialized in setTimeOut.                                                                                                             |                     [Code Example] (#The web does not use the pre-connection and does not initialize the engine in advance.)                     |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          5                          | Do not print trace information and logs for high-frequency APIs.   | Check the API onTouch, onItemDragMove, onDragMove, onScroll, onMouse, onVisibleAreaChange, OnAreaChange, onActionUpdate, onFrame of the Animator, and aboutToReuse in the component reuse scenario. You are not advised to print traces and logs in the logs.         |                     [Code Example] (#Do not print traces and logs in high-frequency APIs.)                     |
| Completion Delay &nbsp;/&nbsp;Frame Rate                                                                                                                                                     |                          4                          | The if statement exists in the component reuse, but reuseId is not used.           | Check the customized components that use @Reusable. Check whether conditional rendering statements such as if/else or ForEach are used in build. If yes, use them together with reuseId.                                                                                       |                  [Code Example] (#The if statement exists in the component reuse, but reuseid is not used.)                  |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          4                          | The @Prop decorator is not recommended.          | Search for @Prop globally and replace it.                                                                                                                                          |                        [Code Example] (# The prop decorator is not recommended.)                       |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          3                          | Do not directly use resource information in the input parameters of the getXXXSync API of ResourceManager.          | Check the ResourceManager.getXXXSync API. When checking the input parameters, use the getStringSync($r('app.media.icon').id) format. If the format is not used, rectification is required.                                                | [Code Example](#Do not directly use resource information in the input parameters of the getxxxsync API of ResourceManager.) |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          3                          | Use @Builder to replace the customized component used for display (data is obtained from the parent component and no independent data processing is required).          | Review the user-defined component marked by @Component. If there is no independent lifecycle processing logic in the component, data is transferred by the parent component. It is recommended that @Builder be replaced.                                                          |            [Code Example] (# The customized component data used for display is obtained from the parent component. No independent data processing is performed. Use the builder to replace the data.)           |
| Response Delay &nbsp;/&nbsp;Completion Delay &nbsp;/&nbsp;Frame Rate                                                                                                                                    |                          3                          | The lifecycle without specific logic and ArkUI function callback are deleted. Redundant blocking logs are deleted.          | Check all lifecycle functions such as aboutToAppear and aboutToDisappear and check the callback function of ArkUI. If the function does not contain specific service logic, for example, only logs are printed, delete the function callback.                                       |             [Code Example] (# Delete the function callback of the lifecycle arkui without specific logic and delete redundant blocking logs.)             |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          3                          | Deleting a State Variable Decorator That Is Not Associated with a Component          | Check the global status variable decorator. If the variable is not associated with any component, delete the decorator.            |                      [Code Example](#Delete the state variable decorator that is not associated with any component.)                      |
| Frame rate                                                                                                                                                                      |                          2                          | 	Poor crypto-js performance          | Check the keyword buffer.from. You are advised to use the native cryptoFramework for encryption and replace buffer with base64helper to improve the performance by more than 10 times. The larger the data volume, the more obvious the performance.            |                        [Code Example] (#crypto-js Poor Performance)                       |
| Response Delay &nbsp;/&nbsp;Completion Delay                                                                                                                                                   |                          1                          | 	The Marquee component is not recommended.          | Check the Marquee keyword and use the TextOverflow.MARQUEE mode instead.            |                       [Code Example](#The marquee component is not recommended.)                      |
| Completion Delay                                                                                                                                                                    |                          1                          | 	Functions Cannot Be Used as Attributes of ArkUI Components and Input Parameters of Customized Components Reused by Components          | Check whether the attribute contains the xx() function and whether the function or method contains time-consuming operations. If yes, replace the function or method with a variable.           |              [Code Example] (# Functions cannot be used as the attributes of the arkui component and the input parameters of the customized component reused by the component.)             |
| Completion Delay                                                                                                                                                                    |                          1                          | 	The .linearGradient color gradient attribute is not recommended.          | Check the keyword linearGradient. You can use an image instead.           |                 [Code Example] (# The lineargradient color gradient attribute is not recommended.)                 |
| Completion Delay &nbsp;/&nbsp;Frame Rate                                                                                                                                                     |                          1                          | 	Do not perform time-consuming operations in the for/while loop.          | Check whether logs or trace information is recorded in the for/while loop.           |                    [Code Example] (# Do not perform time-consuming operations in the forwhile loop.)                   |
| Completion Delay &nbsp;/&nbsp;Frame Rate                                                                                                                                                     |                          1                          | 	You are not advised to set the initial value of a variable to undefined. You need to initialize the variable by default.          | For example, if number is set to 0 and string is set to an empty string, no extra empty check is required. Check whether variables in the class are initialized to undefined.           |                [Code Example] (#You are not advised to set the initial value of a variable to undefined. You need to initialize the variable by default.)                |

## Performance Optimization Specifications

### You are not advised to perform time-consuming operations during the lifecycle, such as aboutToAppear() and aboutToDisappear().
#### Type
Response Delay/Completion Delay
#### Solution
Check all aboutToAppear and aboutToDisappear functions (or use Trace to check whether there are time-consuming operations). Change them to setTimeOut or execute them in TaskPool.

#### Negative Examples
```typescript
@Entry
@Component
struct ViewA {
  @State private text: string = "";
  private count: number = 0;
  // Negative example: Perform time-consuming operations in the aboutToAppear API to block page drawing.
  aboutToAppear() {
    // Time-consuming operation
    this.computeTask();
    let context = context.resourceManager.getStringSync($r('app.string.startup_text'));
  }

  computeTask(): void {
    this.count = 0;
    while (this.count < LARGE_NUMBER) {
    this.count++;
  }
  let context = getContext(this) as Context;
  this.text = context.resourceManager.getStringSync($r('app.string.task_text'));
}
}
```
#### Positive Examples
```typescript
@Entry
@Component
struct ViewB {
  @State private text: string = "";
  private count: number = 0;
  private readonly DELAYED_TIME: number = 2000; //Timer set delay 2s

  // Positive example: Time-consuming computing tasks are processed asynchronously in the aboutToAppear API.
  aboutToAppear() {
    // Time-consuming operation
    this.computeTaskAsync(); // Asynchronous task
    let context = getContext(this) as Context;
    this.text = context.resourceManager.getStringSync($r('app.string.startup_text'));
  }

  computeTask(): void {
    this.count = 0;
    while (this.count < LARGE_NUMBER) {
    this.count++;
  }
  let context = getContext(this) as Context;
  this.text = context.resourceManager.getStringSync($r('app.string.task_text'));
}

// Asynchronous processing of the computing task
private computeTaskAsync(): void {
  setTimeout(() => {
  //SetTimeout is used to implement asynchronous delayed running.
  this.computeTask();
  }, DELAYED_TIME)
}
}
```
#### High Frequency & Benefit (Full Score: 5)
5

### Do not perform time-consuming operations (such as ArkUI API callback, network access callback, and await) in callback functions.
#### Type
Response Delay/Completion Delay
#### Solution
Check all callback functions (or view them through Trace), especially ArkUI APIs and network callback functions. Check whether time-consuming operations are performed and whether the await operation is used. Change the await operation to setTimeOut or execute it in TaskPool.
#### Negative Examples
```typescript
import http from '@ohos.net.http';

async aboutToAppear() {
  // ...
  const b = await http.createHttp();
}
```
#### Positive Examples
```typescript
aboutToAppear() {
  // ...
  //In the lifecycle, use TaskPool to load and parse network data.
  this.requestByTaskPool();
}

@Concurrent
getInfoFromHttp(): string[] {
  //Load data from the network.
  return http.request();
}

requestByTaskPool(): void {
  //Create a task item.
  let task: taskpool.Task = new taskpool.Task(this.getInfoFromHttp);
  try {
  //Execute the network loading function.
  taskpool.execute(task, taskpool.Priority.HIGH).then((res: string[]) => {
});
} catch (err) {
  logger.error(TAG, "failed, " + (err as BusinessError).toString());
}
}
```
#### High Frequency & Benefit (Full Score: 5)
5

### LazyForEach is not used in the list scenario, component reuse is used, and list items are cached.
#### Type
Response Delay/Completion Delay/Frame Rate
#### Solution
Check the code that uses LazyForEach and check whether the component reuse (@Reusable) and cache list item (cacheCount) are used.
#### Negative Examples
```typescript
struct GoodView {
  build() {
    Grid() {
      // LazyForEach+component reuse+cache list items are not used.
      ForEach(this.GoodDataOne, (item, index) => {
        GridItem() {
          Column() {
            Image(item.img)
              .height(item.hei)
              .width('100%')
              .objectFit(ImageFit.Fill)

            Text(item.introduce)
              .fontSize(14)
              .padding({ left: 5, right: 5 })
              .margin({ top: 5 })
            Row() {
              Row() {
                Text('￥')
                  .fontSize(10)
                  .fontColor(Color.Red)
                  .baselineOffset(-4)
                Text(item.price)
                  .fontSize(16)
                  .fontColor(Color.Red)
                Text(item.numb)
                  .fontSize(10)
                  .fontColor(Color.Gray)
                  .baselineOffset(-4)
                  .margin({ left: 5 })
              }

              Image($r('app.media.photo63'))
                .width(20)
                .height(10)
                .margin({ bottom: -8 })
            }
            .width('100%')
              .justifyContent(FlexAlign.SpaceBetween)
              .padding({ left: 5, right: 5 })
              .margin({ top: 15 })
          }
          .borderRadius(10)
            .backgroundColor(Color.White)
            .clip(true)
            .width('100%')
            .height(290)
        }
      }, (item) => JSON.stringify(item))
    }
  }
}
```
#### Positive Examples
```typescript
//Component reuse
@Reusable
@Component
struct GoodItems {
  @State img: Resource = $r("app.media.photo61");
  @State webImg?: string = '';
  @State hei: number = 0;
  @State introduce: string = '';
  @State price: string = '';
  @State numb: string = '';
  @LocalStorageLink('storageSimpleProp') simpleVarName: string = '';
  isOnclick: boolean = true;
  index: number = 0;
  controllerVideo: VideoController = new VideoController();

  aboutToReuse(params)
  {
    this.webImg = params.webImg;
    this.img = params.img;
    this.hei = params.hei;
    this.introduce = params.introduce;
    this.price = params.price;
    this.numb = params.numb;
  }

  build() {
    Grid(){
      //Lazy loading
      LazyForEach(this.GoodDataOne, (item, index) => {
        GridItem() {
          GoodItems({
            isOnclick:item.data.isOnclick,
            img:item.data.img,
            webImg:item.data.webImg,
            hei:item.data.hei,
            introduce:item.data.introduce,
            price:item.data.price,
            numb:item.data.numb,
            index:index
          })
            .reuseId(this.CombineStr(item.type))
        }
      }, (item) => JSON.stringify(item))
    }.cachedCount(2) //Cached list item.
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
5

### The web does not use pre-connection, and the engine is not initialized in advance.
#### Type
Completion Delay
#### Solution
When an ability is created for an application, the kernel is initialized in advance in the OnCreate phase. It is recommended that the engine be initialized in setTimeOut.
#### Negative Examples
```typescript
//The web component engine is not initialized, and pre-connection is used.
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }
}
controller: webview.WebviewController = new webview.WebviewController();
// ...
Web({ src: 'https://www.example.com', controller: this.controller })

```
#### Positive Examples
```typescript
export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info("EntryAbility onCreate")
    //Before the Web component is initialized, this API is used to load the dynamic library file of the Web engine to improve the startup performance.
    setTimeout(() => {
      //SetTimeout is used to implement delayed running.
      web_webview.WebviewController.initializeWebEngine()
    }, 200)
    console.info("EntryAbility onCreate done");
  }
}

controller: webview.WebviewController = new webview.WebviewController();
// ...
Web({ src: 'https://www.example.com', controller: this.controller })

```
#### High Frequency & Benefit (Full Score: 5)
5

### Do not print trace information and logs for high-frequency APIs.
#### Type
Response Delay/Completion Delay
#### Solution
Check API onTouch, onItemDragMove, onDragMove, onScroll, onMouse, onVisibleAreaChange, OnAreaChange,
It is not recommended that trace and logs be recorded in onActionUpdate, onFrame of animator, and aboutToReuse in component reuse scenarios.
#### Negative Examples
```typescript
@Component
struct CounterOfOnScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      ForEach(this.arr, (item: number) => {
        Text("ListItem" + item)
          .width("100%")
          .height("100%")
      }, (item: number) => item.toString())
    }
    .width('100%')
      .height('100%')
      .onScroll(() => {
        hitrace.startTrace("ScrollSlide", 1002);
        // Service logic
        // ...
        //You are not advised to print trace information and logs for high-frequency APIs.
        hitrace.finishTrace("ScrollSlide", 1002);
      })
  }
```
#### Positive Examples
```typescript
@Component
struct PositiveOfOnScroll {
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

  build() {
    Scroll() {
      List() {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text("TextItem" + item)
          }.width("100%")
           .height(100)
        }, (item: number) => item.toString())
      }
      .divider({ strokeWidth: 3, color: Color.Gray })
    }
      .width('100%')
      .height('100%')
      .onScroll(() => {
        // Service logic
        // ...
      })
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
4

### The if statement exists in the component reuse, but reuseId is not used.
#### Type
Completion Delay/Frame Rate
#### Solution
Check the customized components that use @Reusable. Check whether conditional rendering statements such as if/else or ForEach are used in build. If yes, use them together with reuseId.
#### Negative Examples
```typescript
@Component
@Reusable
export struct MockComplexSubBranch {
  @State alignStyle: FlexAlign = FlexAlign.Center;

  aboutToReuse(params: Record<string, number>): void { // cache reuse component, which updates the status variables of the component.
    this.alignStyle = params.alignStyle;
  }

  build() {
    Column() {
      Column({ space: 5 }) {
        Text('ComplexSubBranch not reusable')
          .fontSize($r('app.integer.font_size_9'))
          .fontColor($r('app.color.hint_txt_color'))
          .width($r('app.string.layout_90_percent'))
      }
    }
  }
}

import { MockComplexSubBranch } from './MockComplexSubBranch';

@Component
export struct WithoutReuseId {
  @State isAlignStyleStart: boolean = true;

  build() {
    Column() {
      Button("Change FlexAlign")
        .onClick(() => {
          this.isAlignStyleStart = !this.isAlignStyleStart;
        })
      Stack() {
        if (this.isAlignStyleStart) {
          MockComplexSubBranch ({ alignStyle: FlexAlign.Start}); //reuseId not used
        } else {
          MockComplexSubBranch({ alignStyle: FlexAlign.End });
        }
      }
    }
  }
}
```
#### Positive Examples
```typescript
@Component
@Reusable
//Add a reusable decorator to declare that the component can be reused.
export struct MockComplexSubBranch {
  @State alignStyle: FlexAlign = FlexAlign.Center;

  aboutToReuse(params: Record<string, number>): void {
    this.alignStyle = params.alignStyle;
  }

  build() {
    Column() {
      Column({ space: 5 }) {
        Text('ComplexSubBranch reusable')
          .fontSize($r('app.integer.font_size_9'))
          .fontColor($r('app.color.hint_txt_color'))
          .width($r('app.string.layout_90_percent'))
      }
    }
  }
}

import { MockComplexReusableSubBranch } from './MockComplexReusableSubBranch';

@Component
export struct WithReuseId {
  @State isAlignStyleStart: boolean = true;

  build() {
    Column() {
      Button("Change FlexAlign")
        .onClick(() => {
          this.isAlignStyleStart = !this.isAlignStyleStart;
        })
      Stack() {
        if (this.isAlignStyleStart) {
          The MockComplexSubBranch({ alignStyle: FlexAlign.Start }).reuseId("MockComplexSubBranchStart"); // is identified by reuseId.
        } else {
          MockComplexSubBranch({ alignStyle: FlexAlign.End }).reuseId("MockComplexSubBranchEnd");
        }
      }
    }
  }
}
```

#### High Frequency & Benefit (Full Score: 5)
4

### The @Prop decorator is not recommended.
#### Type
Response Delay/Completion Delay
#### Solution
Search for @Prop globally and replace it.
#### Negative Examples
```typescript
@Observed
class Book {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  The @Prop testNum: Book; // @Prop decorative state variable is deeply copied.

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent1 {
  @State testNum: Book[] = [new Book(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      //PropChild does not change the value of @Prop testNum: Book. Therefore, @ObjectLink is the optimal choice.
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```
#### Positive Examples
```typescript
@Observed
class Book {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct PropChild {
  The @ObjectLink testNum: Book; // @ObjectLink decorative state variable does not support deep copy.

  build() {
    Text(`PropChild testNum ${this.testNum.c}`)
  }
}

@Entry
@Component
struct Parent2 {
  @State testNum: Book[] = [new Book(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
      //When a subcomponent does not need to be changed locally, @ObjectLink is preferred because @Prop copies data in depth and has copy performance overhead. Therefore, @ObjectLink is a better choice than @Link and @Prop.
      PropChild({ testNum: this.testNum[0] })
    }
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
4

### Do not directly use resource information in the input parameters of the getXXXSync API of ResourceManager.
#### Type
Response Delay/Completion Delay
#### Solution
Check the ResourceManager.getXXXSync API. Use the getStringSync($r('app.media.icon').id) format to view input parameters,
If it is not used, rectification is required.

#### Negative Examples
```typescript
this.context.resourceManager.getStringSync($r('app.string.test'));
```
#### Positive Examples
```typescript
this.context.resourceManager.getStringSync($r('app.string.test').id);
```
#### High Frequency & Benefit (Full Score: 5)
3

### Use @Builder to replace the customized component used for display (data is obtained from the parent component and no independent data processing is required).
#### Type
Response Delay/Completion Delay
#### Solution
Review the user-defined component marked by @Component. If there is no independent lifecycle processing logic in the component, data is transferred by the parent component. It is recommended that @Builder be replaced.
#### Negative Examples
```typescript
@Entry
@Component
struct CEMineButtomView {
  build() {
    View();
  }
}

@Component
export struct ViewA {
  build() {
    Row() {
      Text ('- to the end -')
        .fontSize(12)
        .fontColor($r("app.color.color_1"))
    }.justifyContent(FlexAlign.Center)
     .width('100%')
     .height(51)
     .padding({ bottom: 21 })
  }
}
```
#### Positive Examples
```typescript
@Builder
function viewB() {
  Row() {
    Text ('- to the end -') .fontSize (12)
      .fontColor($r("app.color.color_1"))
  }
  .justifyContent(FlexAlign.Center)
    .width('100%')
    .height(51)
    .padding({ bottom: 21 })
}

@Entry
@Component
struct CEMineButtomView {
  build() {
    Column(){
      viewB()
    }.width('100%')
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
3

### The lifecycle without specific logic and ArkUI function callback are deleted. Redundant blocking logs are deleted.
#### Type
Response Delay/Completion Delay/Frame Rate
#### Solution
Check all lifecycle functions such as aboutToAppear and aboutToDisappear, and check the callback function of ArkUI. If the function does not contain specific service logic,
For example, if only logs are printed, delete the function callback.
#### Negative Examples
```typescript
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct ViewA {
  aboutToAppear(): void {
    hilog.info('Index.ets aboutToAppear') //Logs without specific service logic
  }

  aboutToDisappear(): void{
    hilog.info('Index.ets aboutToDisappear') //Log without specific service logic
  }

  /**
   * Pop-up Window Function
   */
  showToast() {
    promptAction.showToast({
      message: $r('app.string.water_mark_toast_message')
    })
  }

  build() {
    Column(){
      Text('Test')
        .onClick(() => {
          this.showToast(); //Method with service logic
        })
    }.width('100%')
  }
}
```
#### Positive Examples
```typescript
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct ViewB {
  /**
   * Pop-up Window Function
   */
  showToast() {
    promptAction.showToast({
      message: $r('app.string.water_mark_toast_message')
    })
  }

  build() {
    Column(){
      Text('Test')
        .onClick(() => {
          this.showToast(); //Method with service logic
        })
    }.width('100%')
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
3

### Deleting a State Variable Decorator That Is Not Associated with a Component
#### Type
Response Delay/Completion Delay
#### Solution
Check the global status variable decorator. If the variable is not associated with any component, delete the decorator.
#### Negative Examples
```typescript
@Component
struct ComponentA {
  @State message: string = 'Hello World';
  @State textColor: string | Color = '#007DFF';
  @State bgcolor: string | Color = '#ffffff'; //The variable bgcolor is not associated with any component.
  @State selectColor: string | Color = '#007DFF'; // The variable selectColor is not associated with any component.

  build() {
    Column(){
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .fontColor(this.textColor)
    }
  }
}
```
#### Positive Examples
```typescript
@Component
struct ComponentB {
  @State message: string = 'Hello World';
  @State textColor: string | Color = '#007DFF';
  bgcolor: string | Color = '#ffffff'; //The variable bgcolor has an associated component.
  selectColor: string | Color = '#007DFF'; //The variable selectColor has an associated component.

  build() {
    Column(){
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .fontColor(this.selectColor)
        .backgroundColor(this.bgcolor)
    }
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
2

### Poor crypto-js performance
#### Type
Frame rate
#### Solution
Check the keyword buffer.from. You are advised to use the native cryptoFramework for encryption and replace buffer with base64helper to improve performance by more than 10 times,
The larger the data volume, the more obvious.
#### Negative Examples
```typescript
new Uint8Array(buffer.from(str,'base64').buffer);
```
#### Positive Examples
```typescript
let that = new util.Base64Helper();
let result = that.decodeSync(str);
```
#### High Frequency & Benefit (Full Score: 5)
2

### The Marquee component is not recommended.
#### Type
Response Delay/Completion Delay
#### Solution
Check the Marquee keyword and use the TextOverflow.MARQUEE mode instead.
#### Negative Examples
```typescript
struct ViewA {
  build() {
    Column() {
      Marquee({
        start: this.start,
        step: this.step,
        loop: this.loop,
        fromStart: this.fromStart,
        src: this.src
      })
        .width(360)
        .height(80)
        .fontColor('#FFFFFF')
        .fontSize(48)
        .fontWeight(700)
        .backgroundColor('#182431')
        .margin({ bottom: 40 })
        .onStart(() => {
          console.info('Marquee animation complete onStart')
        })
        .onBounce(() => {
          console.info('Marquee animation complete onBounce')
        })
        .onFinish(() => {
          console.info('Marquee animation complete onFinish')
        })
    }.width("100%")
  }
}
```
#### Positive Examples
```typescript
struct ViewB {
  build(){
    Column(){
      Text(reply.user)
        .maxLines(1)
        .textOverflow ({ overflow:TextOverflow.MARQUEE }) //marquee mode
        .width("30%")
    }.width("100%")
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
1

### Functions Cannot Be Used as Attributes of ArkUI Components and Input Parameters of Customized Components Reused by Components
#### Type
Completion Delay
#### Solution
Check whether the attribute contains the xx() function and whether the function or method contains time-consuming operations. If yes, replace the function or method with a variable.
#### Negative Examples
```typescript
struct ViewA {
  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            //The sum parameter is obtained by a function. Each time a component is reused, the function is repeatedly called.
            ChildComponent({ desc: item, sum: this.count() })
          }.width('100%').height(100)
        }, (item: string) => item)
      }
    }
  }
}
```
#### Positive Examples
```typescript
struct ViewB {
  @State sum: number = 0;

  aboutToAppear(): void {
    this.sum = this.count();
  }

  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            ChildComponent({ desc: item, sum: this.sum })
          }.width('100%').height(100)
        }, (item: string) => item)
      }
    }
  }
}

```
#### High Frequency & Benefit (Full Score: 5)
1

### The .linearGradient color gradient attribute is not recommended.
#### Type
Completion Delay
#### Solution
Check the keyword linearGradient. You can use an image instead.
#### Negative Examples
```typescript
Row()
  .linearGradient({
    angle: 90,
    colors: [[0xff0000, 0.0], [0x0000ff, 0.3], [0xffff00, 1.0]]
  })
```
#### Positive Examples
```typescript
Image($r('app.media.gradient_color'))
```
#### High Frequency & Benefit (Full Score: 5)
1

### Do not perform time-consuming operations in the for/while loop.
#### Type
Completion Delay/Frame Rate
#### Solution
Check whether logs or trace information is recorded in the for/while loop.
#### Negative Examples
```typescript
@Component
struct ViewA {
  @State message: string = "";

  build() {
    Column() {
      Button ('Click to print log').onClick () => {
        for (let i = 0; i < 10; i++) {
          console.info(this.message);
        }
      })
    }
  }
}
```
#### Positive Examples
```typescript
@Component
struct ViewB {
  @State message: string = "";

  build() {
    Column() {
      Button ('Click to print log').onClick () => {
        let logMessage: string = this.message;
        for (let i = 0; i < 10; i++) {
          console.info(logMessage); // Assign a value to the status variable before invoking the interface. Otherwise, the performance will be optimized.
        }
      })
    }
  }
}
```
#### High Frequency & Benefit (Full Score: 5)
1

### You are not advised to set the initial value of a variable to undefined. You need to initialize the variable by default.
#### Type
Completion Delay
#### Solution
For example, if number is set to 0 and string is set to an empty string, no extra empty check is required.
Check whether variables in the class are initialized to undefined.
#### Negative Examples
```typescript
@State channels?: Channels[] = undefined;
```
#### Positive Examples
```typescript
@State channels?: Channels[] = [];
```
#### High Frequency & Benefit (Full Score: 5)
1

<!--no_check-->
