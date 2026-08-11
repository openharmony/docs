# 数据对象状态管理常见问题
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zany_pink-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan12-->
<!--Adviser: @zhang_yixin13-->

大型应用中需要封装大量的数据对象，数据对象内部状态变量的使用极大地影响开发者的开发效率，本文将介绍数据对象状态管理的常见问题及解决方案。

在状态管理中，类会被一层“代理”包装。当修改类的成员变量时，代理会拦截该操作并完成两项任务：

- 同步更新数据源：确保原始数据被正确修改；
- 触发UI刷新：通知所有依赖此变量的组件重新渲染。

开发者可以通过[getTarget接口](./arkts-new-getTarget.md)获取原始对象，并使用下面的方法可以判断对象是否被状态管理包装。当表达式结果为false时，表示value是状态管理包装过的对象；否则，表示value不是状态管理包装过的对象。

``` ts
UIUtils.getTarget(value) === value
```

## 类的构造函数中通过捕获this修改变量无法观察

当在构造函数中初始化修改`isSuccess`的[箭头函数](../../quick-start/arkts-language-guide-functions.md#闭包与箭头函数)时，`TestModel`实例尚未被代理封装，`this`指向`TestModel`实例本身。因此，后续触发`query`事件时，状态管理无法观测到变化。

当开发者将修改`isSuccess`的箭头函数放在`query`中时，已完成`TestModel`对象初始化和代理封装。通过`this.viewModel.query()`调用`query`时，`query`函数中的`this`指向`viewModel`代理对象，对代理对象成员属性`isSuccess`的更改能够被观测到，因此触发`query`事件可以被状态管理观测到变化。

【反例】
<!-- @[state_problem_this_unable_observe_opposite](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/StateProblemThisUnableObserveOpposite.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  @State viewModel: TestModel = new TestModel();

  build() {
    Row() {
      Column() {
        Text(this.viewModel.isSuccess ? 'success' : 'failed')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            this.viewModel.query();
          })
      }.width('100%')
    }.height('100%')
  }
}

export class TestModel {
  public isSuccess: boolean = false;
  public model: Model

  constructor() {
    this.model = new Model(() => {
      // 此时TestModel实例尚未被代理封装，this指向TestModel实例本身
      // this.isSuccess的修改无法触发Index中Text的UI刷新
      this.isSuccess = true;
      hilog.info(0xFF00, 'testTag', '%{public}s', `this.isSuccess: ${this.isSuccess}`);
    })
  }

  query() {
    this.model.query();
  }
}

export class Model {
  public callback: () => void

  constructor(cb: () => void) {
    this.callback = cb;
  }

  query() {
    this.callback();
  }
}
```

上述示例代码中，状态变量的修改在构造函数内。界面刚开始时显示“failed”，点击后日志打印“this.isSuccess: true”，表明修改成功，但界面仍然显示“failed”，这说明UI未刷新。

【正例】
<!-- @[state_problem_this_unable_observe_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/StateProblemThisUnableObservePositive.ets) -->  

``` TypeScript
@Entry
@Component
struct Index {
  @State viewModel: TestModel = new TestModel();

  build() {
    Row() {
      Column() {
        Text(this.viewModel.isSuccess ? 'success' : 'failed')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            this.viewModel.query();
          })
      }.width('100%')
    }.height('100%')
  }
}

export class TestModel {
  public isSuccess: boolean = false;
  public model: Model = new Model(() => {
  })

  // 状态变量的修改放在类的普通方法中
  query() {
    this.model.callback = () => {
      this.isSuccess = true;
    }
    this.model.query();
  }
}

export class Model {
  public callback: () => void

  constructor(cb: () => void) {
    this.callback = cb;
  }

  query() {
    this.callback();
  }
}
```

上文示例代码将状态变量的修改放在类的普通方法中，界面开始时显示“failed”，点击后显示“success”。

## 使用箭头函数改变状态变量未生效

在箭头函数中改变状态变量不会触发UI刷新，这是因为箭头函数体内的`this`对象是定义该函数时所在的作用域指向的对象，而不是调用时所在的作用域指向的对象。所以在该场景下，`changeCoverUrl`的`this`指向`PlayDetailViewModel`，而不是状态变量本身。

【反例】
<!-- @[play_detail_opposite_model](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/playDetailPageOpposite/PlayDetailViewModel.ets) --> 

``` TypeScript
export default class PlayDetailViewModel {
  public coverUrl: string = '#00ff00';
  public changeCoverUrl = () => {
    this.coverUrl = '#00F5FF';
  }
}
```

<!-- @[state_problem_arrow_function_opposite](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/playDetailPageOpposite/PlayDetailPage.ets) -->  

``` TypeScript
import PlayDetailViewModel from './PlayDetailViewModel';

@Entry
@Component
struct PlayDetailPage {
  @State vm: PlayDetailViewModel = new PlayDetailViewModel();

  build() {
    Stack() {
      Text(this.vm.coverUrl)
        .width(100)
        .height(100)
        .backgroundColor(this.vm.coverUrl)
      Row() {
        Button('Change Color')
          .onClick(() => {
            this.vm.changeCoverUrl();
          })
      }
    }
    .width('100%')
    .height('100%')
    .alignContent(Alignment.Top)
  }
}
```

解决方案：将状态变量的代理对象传入箭头函数，调用代理的属性赋值。

【正例】

<!-- @[play_detail_positive_model](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/playDetailPagePositive/PlayDetailViewModel.ets) --> 

``` TypeScript
export default class PlayDetailViewModel {
  public coverUrl: string = '#00ff00';
  public changeCoverUrl = (model: PlayDetailViewModel) => {
    model.coverUrl = '#00F5FF';
  }
}
```

<!-- @[state_problem_arrow_function_positive](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/state/playDetailPagePositive/PlayDetailPage.ets) -->

``` TypeScript
import PlayDetailViewModel from './PlayDetailViewModel';

@Entry
@Component
struct PlayDetailPage {
  @State vm: PlayDetailViewModel = new PlayDetailViewModel();

  build() {
    Stack() {
      Text(this.vm.coverUrl)
        .width(100)
        .height(100)
        .backgroundColor(this.vm.coverUrl)
      Row() {
        Button('Change Color')
          .onClick(() => {
            let self = this.vm;
            this.vm.changeCoverUrl(self);
          })
      }
    }
    .width('100%')
    .height('100%')
    .alignContent(Alignment.Top)
  }
}
```

## 冗余刷新

### 使用简单属性数组导致冗余刷新

在开发过程中，我们经常会需要设置多个组件的同一种属性，比如Text组件的内容、组件的宽度、高度等样式信息等。将这些属性保存在一个数组中，配合[ForEach](../rendering-control/arkts-rendering-control-foreach.md)进行使用是一种简单且方便的方法。但这种使用方式会导致属性元素的冗余刷新，修改数组中一个属性元素，数组中所有元素绑定的组件都会被刷新。

【反例】

<!-- @[TextComponent1_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArray.ets) -->   

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Entry
@Component
struct Index {
  @State items: string[] = [];
  @State ids: string[] = [];
  @State age: number[] = [];
  @State gender: string[] = [];

  aboutToAppear() {
    this.items.push('Head');
    this.items.push('List');
    for (let i = 0; i < 20; i++) {
      this.ids.push('id: ' + Math.floor(Math.random() * 1000));
      this.age.push(Math.floor(Math.random() * 100 % 40));
      this.gender.push(Math.floor(Math.random() * 100) % 2 == 0 ? 'Male' : 'Female');
    }
  }

  isRenderText(index: number): number {
    // 日志打印，观察使用简单属性数组导致冗余刷新
    hilog.info(DOMAIN_NUMBER, TAG, `index ${index} is rendered`);
    return 1;
  }

  build() {
    Row() {
      Column() {
        ForEach(this.items, (item: string) => {
          if (item == 'Head') {
            Text('Personal Info')
              .fontSize(40)
          } else if (item == 'List') {
            List() {
              ForEach(this.ids, (id: string, index) => {
                ListItem() {
                  Row() {
                    Text(id)
                      .fontSize(20)
                      .margin({
                        left: 30,
                        right: 5
                      })
                    Text('age: ' + this.age[index as number])
                      .fontSize(20)
                      .margin({
                        left: 5,
                        right: 5
                      })
                      .position({ x: 100 })
                      .opacity(this.isRenderText(index))
                      .onClick(() => {
                        this.age[index]++;
                      })
                    Text('gender: ' + this.gender[index as number])
                      .margin({
                        left: 5,
                        right: 5
                      })
                      .position({ x: 180 })
                      .fontSize(20)
                  }
                }
                .margin({
                  top: 5,
                  bottom: 5
                })
              })
            }
          }
        })
      }
    }
  }
}
```


上述代码运行效果如下。

![properly-use-state-management-to-develop-1](figures/properly-use-state-management-to-develop-1.gif)

页面内通过ForEach显示了20条信息，当点击某一条信息中age的Text组件时，可以通过日志发现其他的19条信息中age的Text组件也进行了刷新(这体现在日志上，所有的age的Text组件都打出了日志)，但实际上其他19条信息的age的数值并没有改变，也就是说其他19个Text组件并不需要刷新。

这是因为当前状态管理的一个特性。假设存在一个被[@State](./arkts-state.md)修饰的number类型的数组Num[]，其中有20个元素，值分别为0到19。这20个元素分别绑定了一个Text组件，当改变其中一个元素，例如第0号元素的值从0改成1，除了0号元素绑定的Text组件会刷新之外，其他的19个Text组件也会刷新，即使1到19号元素的值并没有改变。

这个特性普遍地出现在简单类型数组的场景中，当数组中的元素够多时，会对UI的刷新性能有很大的负面影响。这种“不需要刷新的组件被刷新”的现象即是“冗余刷新”，当“冗余刷新”的节点过多时，UI的刷新效率会大幅度降低，因此需要减少“冗余刷新”，也就是做到**精准控制组件的更新范围**。

为了减少由简单的属性相关的数组引起的“冗余刷新”，需要将属性数组转变为对象数组，配合自定义组件，实现精准控制更新范围。

【正例】

<!-- @[Information_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayUpdate.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class InfoList extends Array<Info> {
};

@Observed
class Info {
  public ids: number;
  public age: number;
  public gender: string;

  constructor() {
    this.ids = Math.floor(Math.random() * 1000);
    this.age = Math.floor(Math.random() * 100 % 40);
    this.gender = Math.floor(Math.random() * 100) % 2 == 0 ? 'Male' : 'Female';
  }
}

@Component
struct Information {
  @ObjectLink info: Info;
  @State index: number = 0;

  isRenderText(index: number): number {
    hilog.info(DOMAIN_NUMBER, TAG, `index ${index} is rendered`);
    return 1;
  }

  build() {
    Row() {
      Text('id: ' + this.info.ids)
        .fontSize(20)
        .margin({
          left: 30,
          right: 5
        })
      Text('age: ' + this.info.age)
        .fontSize(20)
        .margin({
          left: 5,
          right: 5
        })
        .position({ x: 100 })
        .opacity(this.isRenderText(this.index))
        .onClick(() => {
          this.info.age++;
        })
      Text('gender: ' + this.info.gender)
        .margin({
          left: 5,
          right: 5
        })
        .position({ x: 180 })
        .fontSize(20)
    }
  }
}

@Entry
@Component
struct Page {
  @State infoList: InfoList = new InfoList();
  @State items: string[] = [];

  aboutToAppear() {
    this.items.push('Head');
    this.items.push('List');
    for (let i = 0; i < 20; i++) {
      this.infoList.push(new Info()); // 使用对象数组代替了原有的多个属性数组
    }
  }

  build() {
    Row() {
      Column() {
        ForEach(this.items, (item: string) => {
          if (item == 'Head') {
            Text('Personal Info')
              .fontSize(40)
          } else if (item == 'List') {
            List() {
              ForEach(this.infoList, (info: Info, index) => {
                ListItem() {
                  Information({
                    info: info,
                    index: index
                  })
                }
                .margin({
                  top: 5,
                  bottom: 5
                })
              })
            }
          }
        })
      }
    }
  }
}
```

上述代码的运行效果如下。

![properly-use-state-management-to-develop-2](figures/properly-use-state-management-to-develop-2.gif)

修改后的代码使用对象数组代替了原有的多个属性数组，能够避免数组的“冗余刷新”的情况。这是因为对于数组来说，对象内的变化是无法感知的，数组只能观测数组项层级的变化，例如新增数据项，修改数据项（普通数组是直接修改数据项的值，在对象数组的场景下是整个对象被重新赋值，改变某个数据项对象中的属性不会被观测到）、删除数据项等。这意味着当改变对象内的某个属性时，对于数组来说，对象是没有变化的，也就不会去刷新。在当前状态管理的观测能力中，除了数组嵌套对象的场景外，对象嵌套对象的场景也是无法观测到变化的，这一部分内容将在[使用多属性类对象导致冗余刷新](#使用多属性类对象导致冗余刷新)中讲到。同时修改代码时使用了自定义组件与ForEach的结合，这一部分内容将在[ForEach和对象数组结合使用导致UI不刷新](./arkts-state-management-faq-inner-component.md#foreach和对象数组结合使用导致ui不刷新)讲到。

### 使用多属性类对象导致冗余刷新

> **说明：**
>
> 从API version 11开始，推荐优先使用[@Track装饰器](arkts-track.md)解决该场景的问题。

在开发过程中，我们有时会定义一个大的对象，其中包含了很多样式相关的属性，并且在父子组件间传递这个对象，将其中的属性绑定在组件上。这种使用方式会导致类属性的冗余刷新，修改一个类属性，类内所有属性绑定的组件都会被刷新。

【反例】

<!-- @[StateArrayBig_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayBig.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class UiStyle {
  public translateX: number = 0;
  public translateY: number = 0;
  public scaleX: number = 0.3;
  public scaleY: number = 0.3;
  public width: number = 336;
  public height: number = 178;
  public posX: number = 10;
  public posY: number = 50;
  public alpha: number = 0.5;
  public borderRadius: number = 24;
  public imageWidth: number = 78;
  public imageHeight: number = 78;
  public translateImageX: number = 0;
  public translateImageY: number = 0;
  public fontSize: number = 20;
}

@Component
struct SpecialImage {
  @ObjectLink uiStyle: UiStyle;

  private isRenderSpecialImage(): number { // 显示组件是否渲染的函数
    hilog.info(DOMAIN_NUMBER, TAG, 'SpecialImage is rendered');
    return 1;
  }

  build() {
    Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
      .width(this.uiStyle.imageWidth)
      .height(this.uiStyle.imageHeight)
      .margin({ top: 20 })
      .translate({
        x: this.uiStyle.translateImageX,
        y: this.uiStyle.translateImageY
      })
      .opacity(this.isRenderSpecialImage()) // 如果Image重新渲染，该函数将被调用
  }
}

@Component
struct PageChild {
  @ObjectLink uiStyle: UiStyle;

  // 下面的函数用于显示组件是否被渲染
  private isRenderColumn(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Column is rendered');
    return 1;
  }

  private isRenderStack(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Stack is rendered');
    return 1;
  }

  private isRenderImage(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Image is rendered');
    return 1;
  }

  private isRenderText(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Text is rendered');
    return 1;
  }

  build() {
    Column() {
      SpecialImage({
        uiStyle: this.uiStyle
      })
      Stack() {
        Column() {
          Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
            .opacity(this.uiStyle.alpha)
            .scale({
              x: this.uiStyle.scaleX,
              y: this.uiStyle.scaleY
            })
            .padding(this.isRenderImage())
            .width(300)
            .height(300)
        }
        .width('100%')
        .position({ y: -80 })

        Stack() {
          Text('Hello World')
            .fontColor('#182431')
            .fontWeight(FontWeight.Medium)
            .fontSize(this.uiStyle.fontSize)
            .opacity(this.isRenderText())
            .margin({ top: 12 })
        }
        .opacity(this.isRenderStack())
        .position({
          x: this.uiStyle.posX,
          y: this.uiStyle.posY
        })
        .width('100%')
        .height('100%')
      }
      .margin({ top: 50 })
      .borderRadius(this.uiStyle.borderRadius)
      .opacity(this.isRenderStack())
      .backgroundColor('#FFFFFF')
      .width(this.uiStyle.width)
      .height(this.uiStyle.height)
      .translate({
        x: this.uiStyle.translateX,
        y: this.uiStyle.translateY
      })

      Column() {
        Button('Move')
          .width(312)
          .fontSize(20)
          .backgroundColor('#FF007DFF')
          .margin({ bottom: 10 })
          .onClick(() => {
            this.getUIContext().animateTo({
              duration: 500
            }, () => {
              this.uiStyle.translateY = (this.uiStyle.translateY + 180) % 250;
            });
          })
        Button('Scale')
          .borderRadius(20)
          .backgroundColor('#FF007DFF')
          .fontSize(20)
          .width(312)
          .onClick(() => {
            this.uiStyle.scaleX = (this.uiStyle.scaleX + 0.6) % 0.8;
          })
      }
      .position({
        y: 666
      })
      .height('100%')
      .width('100%')

    }
    .opacity(this.isRenderColumn())
    .width('100%')
    .height('100%')

  }
}

@Entry
@Component
struct Page {
  @State uiStyle: UiStyle = new UiStyle();

  build() {
    Stack() {
      PageChild({
        uiStyle: this.uiStyle
      })
    }
    .backgroundColor('#F1F3F5')
  }
}
```



上述代码的运行效果如下。

![properly-use-state-management-to-develop-3](figures/properly-use-state-management-to-develop-3.gif)

优化前点击move按钮的脏节点更新[耗时](../ui-inspector-profiler.md#trace调试能力)如下图：

![img](figures/properly-use-state-management-to-develop-11.PNG)

在上面的示例中，UiStyle定义了多个属性，并且这些属性分别被多个组件关联。当点击任意一个按钮更改其中的某些属性时，会导致所有这些关联uiStyle的组件进行刷新，虽然它们其实并不需要进行刷新（因为组件的属性都没有改变）。通过定义的一系列isRender函数，可以观察到这些组件的刷新。当点击“move”按钮进行平移动画时，由于translateY的值的多次改变，会导致每一次都存在“冗余刷新”的问题，这对应用的性能有着很大的负面影响。

这是因为当前状态管理的一个刷新机制，假设定义了一个有20个属性的类，创建类的对象实例，将20个属性绑定到组件上，这时修改其中的某个属性，除了这个属性关联的组件会刷新之外，其他的19个属性关联的组件也都会刷新，即使这些属性本身并没有发生变化。

这个机制会导致在使用一个复杂大对象与多个组件关联时，刷新性能的下降。对此，推荐将一个复杂大对象拆分成多个小对象的集合，在保留原有代码结构的基础上，减少“冗余刷新”，实现精准控制组件的更新范围。

【正例】

<!-- @[StateArrayPrecise_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayPrecise.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class NeedRenderImage { // 在同一组件中使用的属性可以划分为相同的类
  public translateImageX: number = 0;
  public translateImageY: number = 0;
  public imageWidth: number = 78;
  public imageHeight: number = 78;
}

@Observed
class NeedRenderScale { // 在一起使用的属性可以划分为相同的类
  public scaleX: number = 0.3;
  public scaleY: number = 0.3;
}

@Observed
class NeedRenderAlpha { // 在不同地方使用的属性可以划分为相同的类
  public alpha: number = 0.5;
}

@Observed
class NeedRenderSize { // 在一起使用的属性可以划分为相同的类
  public width: number = 336;
  public height: number = 178;
}

@Observed
class NeedRenderPos { // 在一起使用的属性可以划分为相同的类
  public posX: number = 10;
  public posY: number = 50;
}

@Observed
class NeedRenderBorderRadius { // 在不同地方使用的属性可以划分为相同的类
  public borderRadius: number = 24;
}

@Observed
class NeedRenderFontSize { // 在不同地方使用的属性可以划分为相同的类
  public fontSize: number = 20;
}

@Observed
class NeedRenderTranslate { // 在一起使用的属性可以划分为相同的类
  public translateX: number = 0;
  public translateY: number = 0;
}

@Observed
class UiStyle {
  // 使用NeedRenderxxx类
  public needRenderTranslate: NeedRenderTranslate = new NeedRenderTranslate();
  public needRenderFontSize: NeedRenderFontSize = new NeedRenderFontSize();
  public needRenderBorderRadius: NeedRenderBorderRadius = new NeedRenderBorderRadius();
  public needRenderPos: NeedRenderPos = new NeedRenderPos();
  public needRenderSize: NeedRenderSize = new NeedRenderSize();
  public needRenderAlpha: NeedRenderAlpha = new NeedRenderAlpha();
  public needRenderScale: NeedRenderScale = new NeedRenderScale();
  public needRenderImage: NeedRenderImage = new NeedRenderImage();
}

@Component
struct SpecialImage {
  @ObjectLink uiStyle: UiStyle;
  @ObjectLink needRenderImage: NeedRenderImage; // 从其父组件接收新类

  private isRenderSpecialImage(): number { // 显示组件是否渲染的函数
    hilog.info(DOMAIN_NUMBER, TAG, 'SpecialImage is rendered');
    return 1;
  }

  build() {
    Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
      .width(this.needRenderImage.imageWidth) // 使用this.needRenderImage.xxx
      .height(this.needRenderImage.imageHeight)
      .margin({ top: 20 })
      .translate({
        x: this.needRenderImage.translateImageX,
        y: this.needRenderImage.translateImageY
      })
      .opacity(this.isRenderSpecialImage()) // 如果Image重新渲染，该函数将被调用
  }
}

@Component
struct PageChild {
  @ObjectLink uiStyle: UiStyle;
  @ObjectLink needRenderTranslate: NeedRenderTranslate; // 从其父组件接收新定义的NeedRenderxxx类的实例
  @ObjectLink needRenderFontSize: NeedRenderFontSize;
  @ObjectLink needRenderBorderRadius: NeedRenderBorderRadius;
  @ObjectLink needRenderPos: NeedRenderPos;
  @ObjectLink needRenderSize: NeedRenderSize;
  @ObjectLink needRenderAlpha: NeedRenderAlpha;
  @ObjectLink needRenderScale: NeedRenderScale;

  // 下面的函数用于显示组件是否被渲染
  private isRenderColumn(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Column is rendered');
    return 1;
  }

  private isRenderStack(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Stack is rendered');
    return 1;
  }

  private isRenderImage(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Image is rendered');
    return 1;
  }

  private isRenderText(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Text is rendered');
    return 1;
  }

  build() {
    Column() {
      SpecialImage({
        uiStyle: this.uiStyle,
        needRenderImage: this.uiStyle.needRenderImage // 传递给子组件
      })
      Stack() {
        Column() {
          Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
            .opacity(this.needRenderAlpha.alpha)
            .scale({
              x: this.needRenderScale.scaleX, // 使用this.needRenderXxx.xxx
              y: this.needRenderScale.scaleY
            })
            .padding(this.isRenderImage())
            .width(300)
            .height(300)
        }
        .width('100%')
        .position({ y: -80 })

        Stack() {
          Text('Hello World')
            .fontColor('#182431')
            .fontWeight(FontWeight.Medium)
            .fontSize(this.needRenderFontSize.fontSize)
            .opacity(this.isRenderText())
            .margin({ top: 12 })
        }
        .opacity(this.isRenderStack())
        .position({
          x: this.needRenderPos.posX,
          y: this.needRenderPos.posY
        })
        .width('100%')
        .height('100%')
      }
      .margin({ top: 50 })
      .borderRadius(this.needRenderBorderRadius.borderRadius)
      .opacity(this.isRenderStack())
      .backgroundColor('#FFFFFF')
      .width(this.needRenderSize.width)
      .height(this.needRenderSize.height)
      .translate({
        x: this.needRenderTranslate.translateX,
        y: this.needRenderTranslate.translateY
      })

      Column() {
        Button('Move')
          .width(312)
          .fontSize(20)
          .backgroundColor('#FF007DFF')
          .margin({ bottom: 10 })
          .onClick(() => {
            this.getUIContext().animateTo({
              duration: 500
            }, () => {
              this.needRenderTranslate.translateY = (this.needRenderTranslate.translateY + 180) % 250;
            });
          })
        Button('Scale')
          .borderRadius(20)
          .backgroundColor('#FF007DFF')
          .fontSize(20)
          .width(312)
          .margin({ bottom: 10 })
          .onClick(() => {
            this.needRenderScale.scaleX = (this.needRenderScale.scaleX + 0.6) % 0.8;
          })
        Button('Change Image')
          .borderRadius(20)
          .backgroundColor('#FF007DFF')
          .fontSize(20)
          .width(312)
          .onClick(() => { // 在父组件中，仍使用 this.uiStyle.needRenderXxx.xxx 更改属性
            this.uiStyle.needRenderImage.imageWidth = (this.uiStyle.needRenderImage.imageWidth + 30) % 160;
            this.uiStyle.needRenderImage.imageHeight = (this.uiStyle.needRenderImage.imageHeight + 30) % 160;
          })
      }
      .position({
        y: 616
      })
      .height('100%')
      .width('100%')
    }
    .opacity(this.isRenderColumn())
    .width('100%')
    .height('100%')
  }
}

@Entry
@Component
struct Page {
  @State uiStyle: UiStyle = new UiStyle();

  build() {
    Stack() {
      PageChild({
        uiStyle: this.uiStyle,
        needRenderTranslate: this.uiStyle.needRenderTranslate, // 传递needRenderxxx类给子组件
        needRenderFontSize: this.uiStyle.needRenderFontSize,
        needRenderBorderRadius: this.uiStyle.needRenderBorderRadius,
        needRenderPos: this.uiStyle.needRenderPos,
        needRenderSize: this.uiStyle.needRenderSize,
        needRenderAlpha: this.uiStyle.needRenderAlpha,
        needRenderScale: this.uiStyle.needRenderScale
      })
    }
    .backgroundColor('#F1F3F5')
  }
}
```



上述代码的运行效果如下。![properly-use-state-management-to-develop-4](figures/properly-use-state-management-to-develop-4.gif)

优化后点击move按钮的脏节点更新耗时如下图：

![img](figures/properly-use-state-management-to-develop-12.PNG)

修改后的代码将原来的大类中的十五个属性拆成了八个小类，并且在绑定的组件上也做了相应的适配。属性拆分遵循以下几点原则：

- 只作用在同一个组件上的多个属性可以被拆分进同一个新类，即示例中的NeedRenderImage。适用于组件经常被不关联的属性改变而引起刷新的场景，这个时候就要考虑拆分属性，或者重新考虑ViewModel设计是否合理。
- 经常被同时使用的属性可以被拆分进同一个新类，即示例中的NeedRenderScale、NeedRenderTranslate、NeedRenderPos、NeedRenderSize。适用于属性经常成对出现，或者被作用在同一个样式上的情况，例如.translate、.position、.scale等（这些样式通常会接收一个对象作为参数）。
- 可能被用在多个组件上或相对较独立的属性应该被单独拆分进一个新类，即示例中的NeedRenderAlpha，NeedRenderBorderRadius、NeedRenderFontSize。适用于一个属性作用在多个组件上或者与其他属性没有联系的情况，例如.opacity、.borderRadius等（这些样式通常相对独立）。

属性拆分的原理和属性合并类似，都是在嵌套场景下，状态管理无法观测二层以上的属性变化，所以不会因为二层的数据变化导致一层关联的其他属性被刷新，同时利用[@Observed](./arkts-observed-and-objectlink.md)和[@ObjectLink](./arkts-observed-and-objectlink.md)在父子节点间传递二层的对象，从而在子组件中正常的观测二层的数据变化，实现精准刷新。<!--Del-->关于属性拆分的详细内容，可以查看[精准控制组件的更新范围](../../performance/precisely-control-render-scope.md)。<!--DelEnd-->

[\@Track](./arkts-track.md)是类属性装饰器。当一个类对象是状态变量时，\@Track装饰的属性发生变化，只会触发该属性关联的UI更新，所以使用@Track装饰器则无需做属性拆分，也能达到同样控制组件更新范围的作用。

<!-- @[StateArrayTrack_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayTrack.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class UiStyle {
  @Track public translateX: number = 0;
  @Track public translateY: number = 0;
  @Track public scaleX: number = 0.3;
  @Track public scaleY: number = 0.3;
  @Track public width: number = 336;
  @Track public height: number = 178;
  @Track public posX: number = 10;
  @Track public posY: number = 50;
  @Track public alpha: number = 0.5;
  @Track public borderRadius: number = 24;
  @Track public imageWidth: number = 78;
  @Track public imageHeight: number = 78;
  @Track public translateImageX: number = 0;
  @Track public translateImageY: number = 0;
  @Track public fontSize: number = 20;
}

@Component
struct SpecialImage {
  @ObjectLink uiStyle: UiStyle;

  private isRenderSpecialImage(): number { // 显示组件是否渲染的函数
    hilog.info(DOMAIN_NUMBER, TAG, 'SpecialImage is rendered');
    return 1;
  }

  build() {
    Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
      .width(this.uiStyle.imageWidth)
      .height(this.uiStyle.imageHeight)
      .margin({ top: 20 })
      .translate({
        x: this.uiStyle.translateImageX,
        y: this.uiStyle.translateImageY
      })
      .opacity(this.isRenderSpecialImage()) // 如果Image重新渲染，该函数将被调用
  }
}

@Component
struct PageChild {
  @ObjectLink uiStyle: UiStyle;

  // 下面的函数用于显示组件是否被渲染
  private isRenderColumn(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Column is rendered');
    return 1;
  }

  private isRenderStack(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Stack is rendered');
    return 1;
  }

  private isRenderImage(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Image is rendered');
    return 1;
  }

  private isRenderText(): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Text is rendered');
    return 1;
  }

  build() {
    Column() {
      SpecialImage({
        uiStyle: this.uiStyle
      })
      Stack() {
        Column() {
          Image($r('app.media.icon')) // 此处'app.media.icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
            .opacity(this.uiStyle.alpha)
            .scale({
              x: this.uiStyle.scaleX,
              y: this.uiStyle.scaleY
            })
            .padding(this.isRenderImage())
            .width(300)
            .height(300)
        }
        .width('100%')
        .position({ y: -80 })

        Stack() {
          Text('Hello World')
            .fontColor('#182431')
            .fontWeight(FontWeight.Medium)
            .fontSize(this.uiStyle.fontSize)
            .opacity(this.isRenderText())
            .margin({ top: 12 })
        }
        .opacity(this.isRenderStack())
        .position({
          x: this.uiStyle.posX,
          y: this.uiStyle.posY
        })
        .width('100%')
        .height('100%')
      }
      .margin({ top: 50 })
      .borderRadius(this.uiStyle.borderRadius)
      .opacity(this.isRenderStack())
      .backgroundColor('#FFFFFF')
      .width(this.uiStyle.width)
      .height(this.uiStyle.height)
      .translate({
        x: this.uiStyle.translateX,
        y: this.uiStyle.translateY
      })

      Column() {
        Button('Move')
          .width(312)
          .fontSize(20)
          .backgroundColor('#FF007DFF')
          .margin({ bottom: 10 })
          .onClick(() => {
            this.getUIContext().animateTo({
              duration: 500
            }, () => {
              this.uiStyle.translateY = (this.uiStyle.translateY + 180) % 250;
            });
          })
        Button('Scale')
          .borderRadius(20)
          .backgroundColor('#FF007DFF')
          .fontSize(20)
          .width(312)
          .onClick(() => {
            this.uiStyle.scaleX = (this.uiStyle.scaleX + 0.6) % 0.8;
          })
      }
      .position({
        y: 666
      })
      .height('100%')
      .width('100%')

    }
    .opacity(this.isRenderColumn())
    .width('100%')
    .height('100%')

  }
}

@Entry
@Component
struct Page {
  @State uiStyle: UiStyle = new UiStyle();

  build() {
    Stack() {
      PageChild({
        uiStyle: this.uiStyle
      })
    }
    .backgroundColor('#F1F3F5')
  }
}
```



## 数据重置导致UI不刷新

在开发过程中，会有“重置数据”的场景，将一个新创建的对象赋值给原有的状态变量，实现数据的刷新。如果不注意新创建对象的类型，可能会出现UI不刷新的现象。

【反例】

<!-- @[StateArrayObserve_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayObserved.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class Child {
  public count: number;

  constructor(count: number) {
    this.count = count;
  }
}

@Observed
class ChildList extends Array<Child> {
}

@Observed
class Ancestor {
  public childList: ChildList;

  constructor(childList: ChildList) {
    this.childList = childList;
  }

  public loadData() {
    // 这里创建的Child[]类型的数组tempList并没有能被观测的能力
    let tempList = [new Child(1), new Child(2), new Child(3), new Child(4), new Child(5)];
    this.childList = tempList;
  }

  public clearData() {
    this.childList = [];
  }
}

@Component
struct CompChild {
  @Link childList: ChildList;
  @ObjectLink child: Child;

  build() {
    Row() {
      Text(this.child.count + '')
        .height(70)
        .fontSize(20)
        .borderRadius({
          topLeft: 6,
          topRight: 6
        })
        .margin({ left: 50 })
      Button('X')
        .backgroundColor(Color.Red)
        .onClick(() => {
          let index = this.childList.findIndex((item) => {
            return item.count === this.child.count;
          });
          if (index !== -1) {
            this.childList.splice(index, 1);
          }
        })
        .margin({
          left: 200,
          right: 30
        })
    }
    .margin({
      top: 15,
      left: 15,
      right: 10,
      bottom: 15
    })
    .borderRadius(6)
    .backgroundColor(Color.Grey)
  }
}

@Component
struct CompList {
  @ObjectLink @Watch('changeChildList') childList: ChildList;

  changeChildList() {
    hilog.info(DOMAIN_NUMBER, TAG, 'CompList ChildList change');
  }

  isRenderCompChild(index: number): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Comp Child is render' + index);
    return 1;
  }

  build() {
    Column() {
      List() {
        ForEach(this.childList, (item: Child, index) => {
          ListItem() {
            CompChild({
              childList: this.childList,
              child: item
            })
              .opacity(this.isRenderCompChild(index))
          }
        })
      }
      .height('70%')
    }
  }
}

@Component
struct CompAncestor {
  @ObjectLink ancestor: Ancestor;

  build() {
    Column() {
      CompList({ childList: this.ancestor.childList })
      Row() {
        // 点击Button对ancestor执行清空数据
        Button('Clear')
          .onClick(() => {
            this.ancestor.clearData();
          })
          .width(100)
          .margin({ right: 50 })
        Button('Recover')
          .onClick(() => {
            this.ancestor.loadData();
          })
          .width(100)
      }
    }
  }
}

@Entry
@Component
struct Page {
  @State childList: ChildList = [new Child(1), new Child(2), new Child(3), new Child(4), new Child(5)];
  @State ancestor: Ancestor = new Ancestor(this.childList);

  build() {
    Column() {
      CompAncestor({ ancestor: this.ancestor })
    }
  }
}
```



上述代码运行效果如下。

![properly-use-state-management-to-develop-5](figures/properly-use-state-management-to-develop-5.gif)

上述代码维护了一个ChildList类型的数据源，点击"X"按钮删除一些数据后再点击Recover进行恢复ChildList，发现再次点击"X"按钮进行删除时，UI并没有刷新，同时也没有打印出“CompList ChildList change”的日志。

代码中对数据源childList重新赋值时，是通过Ancestor对象的方法loadData。

<!-- @[StateArrayLoadDate_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayLoadDate.ets) --> 

``` TypeScript
public loadData() {
  let tempList = [new Child(1), new Child(2), new Child(3), new Child(4), new Child(5)];
  this.childList = tempList;
}
```


在loadData方法中，创建了一个临时的Child类型的数组tempList，并且将Ancestor对象的成员变量的childList指向了tempList。但是这里创建的Child[]类型的数组tempList其实并没有能被观测的能力（也就说它的变化无法主动触发UI刷新）。当它被赋值给childList之后，触发了ForEach的刷新，使得界面完成了重建，但是再次点击删除时，由于此时的childList已经指向了新的tempList代表的数组，并且这个数组并没有被观测的能力，是个静态的量，所以它的更改不会被观测到，也就不会引起UI的刷新。实际上这个时候childList里的数据已经减少了，只是UI没有刷新。

有些开发者会注意到，在Page中初始化定义childList的时候，也是以这样一种方法去进行初始化的。

<!-- @[StateArrayInit_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayInit.ets) --> 

``` TypeScript
@State childList: ChildList = [new Child(1), new Child(2), new Child(3), new Child(4), new Child(5)];
@State ancestor: Ancestor = new Ancestor(this.childList);
```


但是由于这里的childList实际上是被@State装饰了，根据当前状态管理的观测能力，尽管右边赋值的是一个Child[]类型的数据，它并没有被@Observed装饰，这里的childList却依然具备了被观测的能力，所以能够正常的触发UI的刷新。当去掉childList的@State的装饰器后，不去重置数据源，也无法通过点击“X”按钮触发刷新。

因此，需要将具有观测能力的类对象绑定组件，来确保当改变这些类对象的内容时，UI能够正常地刷新。

【正例】

<!-- @[StateArrayNo_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayNo.ets) -->  

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN_NUMBER: number = 0XFF00;
const TAG: string = '[Sample_StateManagement]';

@Observed
class Child {
  public count: number;

  constructor(count: number) {
    this.count = count;
  }
}

@Observed
class ChildList extends Array<Child> {
}

@Observed
class Ancestor {
  public childList: ChildList;

  constructor(childList: ChildList) {
    this.childList = childList;
  }

  public loadData() {
    // 临时的数组tempList修改为具有被观测能力的ChildList类
    let tempList = new ChildList();
    for (let i = 1; i < 6; i++) {
      tempList.push(new Child(i));
    }
    this.childList = tempList;
  }

  public clearData() {
    this.childList = [];
  }
}

@Component
struct CompChild {
  @Link childList: ChildList;
  @ObjectLink child: Child;

  build() {
    Row() {
      Text(this.child.count + '')
        .height(70)
        .fontSize(20)
        .borderRadius({
          topLeft: 6,
          topRight: 6
        })
        .margin({ left: 50 })
      Button('X')
        .backgroundColor(Color.Red)
        .onClick(() => {
          let index = this.childList.findIndex((item) => {
            return item.count === this.child.count;
          });
          if (index !== -1) {
            this.childList.splice(index, 1);
          }
        })
        .margin({
          left: 200,
          right: 30
        })
    }
    .margin({
      top: 15,
      left: 15,
      right: 10,
      bottom: 15
    })
    .borderRadius(6)
    .backgroundColor(Color.Grey)
  }
}

@Component
struct CompList {
  @ObjectLink @Watch('changeChildList') childList: ChildList;

  changeChildList() {
    hilog.info(DOMAIN_NUMBER, TAG, 'CompList ChildList change');
  }

  isRenderCompChild(index: number): number {
    hilog.info(DOMAIN_NUMBER, TAG, 'Comp Child is render' + index);
    return 1;
  }

  build() {
    Column() {
      List() {
        ForEach(this.childList, (item: Child, index) => {
          ListItem() {
            CompChild({
              childList: this.childList,
              child: item
            })
              .opacity(this.isRenderCompChild(index))
          }
        })
      }
      .height('70%')
    }
  }
}

@Component
struct CompAncestor {
  @ObjectLink ancestor: Ancestor;

  build() {
    Column() {
      CompList({ childList: this.ancestor.childList })
      Row() {
        Button('Clear')
          .onClick(() => {
            this.ancestor.clearData();
          })
          .width(100)
          .margin({ right: 50 })
        Button('Recover')
          .onClick(() => {
            this.ancestor.loadData();
          })
          .width(100)
      }
    }
  }
}

@Entry
@Component
struct Page {
  @State childList: ChildList = [new Child(1), new Child(2), new Child(3), new Child(4), new Child(5)];
  @State ancestor: Ancestor = new Ancestor(this.childList);

  build() {
    Column() {
      CompAncestor({ ancestor: this.ancestor })
    }
  }
}
```



上述代码运行效果如下。

![properly-use-state-management-to-develop-6](figures/properly-use-state-management-to-develop-6.gif)

核心的修改点是将原本Child[]类型的tempList修改为具有被观测能力的ChildList类。

<!-- @[StateArrayNo2_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/statemanagementproject/entry/src/main/ets/pages/statemanagementguide/StateArrayNo2.ets) --> 

``` TypeScript
public loadData() {
  let tempList = new ChildList();
  for (let i = 1; i < 6; i++) {
    tempList.push(new Child(i));
  }
  this.childList = tempList;
}
```


ChildList类型在定义的时候使用了@Observed进行装饰，所以用new创建的对象tempList具有被观测的能力，因此在点击“X”按钮删除其中一条内容时，变量childList就能够观测到变化，所以触发了ForEach的刷新，最终UI渲染刷新。