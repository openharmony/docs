# mutableBuilder：实现全局@Builder动态更新
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @zhangwenhan-->
<!--Adviser: @zhang_yixin13-->

 当在一个自定义组件内使用多个全局[\@Builder](./arkts-builder.md)函数实现UI的不同效果时，代码维护将变得非常困难，且页面不够整洁。此时，可以使用[wrapBuilder](./arkts-wrapBuilder.md)封装全局@Builder。但是wrapBuilder不支持动态切换@Builder，引入[mutableBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-mutableBuilder.md)实现全局@Builder的动态切换。

> **说明：**
>
> 从API version 22开始，开发者可以使用mutableBuilder实现全局@Builder的动态切换。
>
> 从API version 22开始，mutableBuilder支持在原子化服务中使用。

## wrapBuilder不支持动态全局@Builder
当前wrapBuilder不支持二次赋值， 更改\@Builder，UI不会发生变化。
```ts
class TextContent {
  text: string = '';
}

@Builder
function textBuilder(p: TextContent) {
  Text(p.text)
}

@Builder
function buttonBuilder(p: TextContent) {
  Button(p.text)
}

@Entry
@Component
struct Index {
  @State message: string = 'init';
  @State text: WrappedBuilder<[TextContent]> = wrapBuilder(textBuilder); // 使用textBuilder初始化

  build() {
    Column() {
      this.text.builder({ text: this.message })
      Button().onClick(() => {
        this.text = wrapBuilder(buttonBuilder); // 点击Button，将textBuilder替换为buttonBuilder进行二次赋值
      })
    }
  }
}
```
在上述代码中，使用`textBuilder`初始化wrapBuilder，点击Button的onClick事件，使用`buttonBuilder`再次初始化wrapBuilder，不会触发对应的@Builder的更新。

为了解决这一问题，引入mutableBuilder作为动态全局\@Builder封装函数。mutableBuilder返回MutableBuilder对象，用于[全局\@Builder](arkts-builder.md#全局自定义构建函数)的动态刷新。 

## 接口说明

mutableBuilder是一个模板函数，返回一个[MutableBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-mutableBuilder.md#mutablebuilder-2)对象。相比[WrappedBuilder](../../reference/apis-arkui/arkui-ts/ts-universal-wrapBuilder.md#wrappedbuilder)，MutableBuilder可以实现动态切换全局@Builder。
```ts
declare function mutableBuilder<Args extends Object[]>(builder: BuilderCallback): MutableBuilder<Args>;
```
同时`MutableBuilder`对象是一个模板类，继承自[WrappedBuilder](./arkts-wrapBuilder.md#接口说明)。

```ts
declare class MutableBuilder<Args extends Object[]> extends WrappedBuilder<Args> {
}
```

> **说明：**
>
> 模板参数`Args extends Object[]`需要匹配\@Builder函数参数的类型。

使用方法：

```ts
let builderVar: MutableBuilder<[string, number]> = mutableBuilder(MyBuilder);
let builderArr: MutableBuilder<[string, number]>[] = [mutableBuilder(MyBuilder)]; // mutableBuilder支持放入数组中
```



## 限制条件

1. mutableBuilder方法只能传入[全局\@Builder](arkts-builder.md#全局自定义构建函数)方法，传入局部@Builder方法编译时报错。

   ```ts
   class TextContent {
     text: string = '';
   }
   
   @Builder
   function globalBuilder(p: TextContent) {
     Text(p.text)
   }
   
   @ComponentV2
   struct MyApp {
     @Local message: string = 'init';
     // 正确用法，使用全局@Builder
     @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
     // 错误用法，使用局部@Builder，编译报错
     @Local localBuilderObject: MutableBuilder<[TextContent]> = mutableBuilder(this.localBuilder);
     
     @Builder
     localBuilder(p: TextContent) {
       Text(p.text)
     }
     build() {
       Column() {
         this.switchingBuilder.builder({ text: this.message })
       }
     }
   }
   ```

2. MutableBuilder对象的builder属性方法仅限在自定义组件内部使用，在自定义组件外面使用会导致程序运行时崩溃。

   ```ts
   class TextContent {
     text: string = '';
   }
   
   @Builder
   function globalBuilder(p: TextContent) {
     Text(p.text)
   }
   
   // 错误用法，MutableBuilder对象的builder属性方法在自定义组件外面使用，运行时崩溃
   let outSideBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
   outSideBuilder.builder({ text: 'message' });
   
   @ComponentV2
   struct MyApp {
     @Local message: string = 'init';
     @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(globalBuilder);
     build() {
       Column() {
         // 正确用法，MutableBuilder对象的builder属性方法在自定义组件中使用
         this.switchingBuilder.builder({ text: this.message })
       }
     }
   }
   ```

3. 不建议与wrapBuilder混合使用，因为mutableBuilder创建的对象类型是MutableBuilder类型，会导致不符合预期的更新。

   如下为不推荐的用法：

   ```ts
   // 在实例化MutableBuilder对象时，建议使用mutableBuilder(builderName)方法
   @State switchingBuilder: MutableBuilder<[MutableBinding]> = mutableBuilder(textBuilder);
   // 不支持将MutableBuilder类型的变量赋值为undefined或null，会导致运行时crash
   @State switchingBuilder: MutableBuilder<[MutableBinding]> | undefined | null = null; 
   Button(`MutableBuilder`).onClick(() => {
     // 不建议将wrapBuilder创建的对象赋值给MutableBuilder类型的对象，赋值后会将textBuilder动态切换成buttonBuilder
     this.switchingBuilder = wrapBuilder(buttonBuilder);  
   })
   ```

   如下为推荐用法：

   ```ts
   // 在实例化MutableBuilder对象时，建议使用mutableBuilder(builderName)方法
   @State switchingBuilder: MutableBuilder<[MutableBinding]> = mutableBuilder(textBuilder);
   
   Button(`MutableBuilder`).onClick(() => {
      // 赋值会将textBuilder动态切换成buttonBuilder
     this.switchingBuilder = mutableBuilder(buttonBuilder); // 推荐用法
   })
   ```

## 动态更改全局@Builder实例
使用\@Builder装饰器装饰的方法`textBuilder`作为mutableBuilder的参数，然后将mutableBuilder的返回值赋值给变量`switchingBuilder`，在Button的点击事件中，使用\@Builder装饰器装饰的方法`buttonBuilder`作为mutableBuilder的参数，将mutableBuilder的返回值再次赋值给变量`switchingBuilder`，可实现`textBuilder` 更新为`buttonBuilder`，以解决wrapBuilder不支持二次赋值的问题。

<!-- @[mutable_builder_dynamic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/mutableBuilder/entry/src/main/ets/pages/MutableBuilderDynamic.ets) --> 

``` TypeScript
class TextContent {
  public text: string = '';
}

@Builder
function textBuilder(p: TextContent) {
  Text(p.text).margin(20)
}

@Builder
function buttonBuilder(p: TextContent) {
  Button(p.text).margin(20)
}

let counter: number = 1;
@Entry
@ComponentV2
struct MyApp {
  @Local message: string = 'init';
  @Local switchingBuilder: MutableBuilder<[TextContent]> = mutableBuilder(textBuilder);
  build() {
    Column() {
      this.switchingBuilder.builder({ text: this.message })
      Button('Click to change')
      .onClick(() => {
        counter++; // 每次点击按钮修改counter来动态改变全局@Builder
        if(counter % 2 === 0) {
          this.message += 'B';
          this.switchingBuilder = mutableBuilder(buttonBuilder); // textBuilder--->buttonBuilder
        } else {
          this.message += 'T';
          this.switchingBuilder = mutableBuilder(textBuilder); // buttonBuilder--->textBuilder
        }
      })
    }.position({x: 120, y: 60})
  }
}
```
点击Button，可将`textBuilder`动态更改为`buttonBuilder`，如下图所示：

![arkts-mutableBuilder-dynamic-demo1](figures/mutableBuilder-dynamic-demo1.gif)


## 使用mutableBuilder显示弹出菜单

由于MutableBuilder继承自WrappedBuilder，故mutableBuilder对应的@Builder具有跟WrappedBuilder同等能力，如下示例，mutableBuilder对应的@Builder方法可作为bindMenu入参，支持点击弹出菜单。

<!-- @[mutable_builder_context_menu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/mutableBuilder/entry/src/main/ets/pages/MutableBuilderContextMenu.ets) --> 

``` TypeScript
@Builder
function overBuilder() {
  Row() {
    Text('全局 Builder')
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
  }
}

@Entry
@Component
struct Index {
  @State arr: number[] = [1,2,3,4,5];

  mutableBuilderMenu: MutableBuilder<[]> = mutableBuilder<[]>(overBuilder);
  build() {
    Column() {
      List({ space: 10 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text(`${item}`)
            .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          // 使用mutableBuilder显示弹出菜单
          .bindMenu(this.mutableBuilderMenu.builder)
        }, (item: number) => JSON.stringify(item))
      }
    }
  }
}
```

## 观察mutableBuilder中@Builder的变化

 mutableBuilder对应的@Builder函数中可使用[MutableBinding](../../reference/apis-arkui/js-apis-stateManagement.md#mutablebindingt20)进行包裹来观察状态变量的变化，同时可通过[@Monitor](./arkts-new-monitor.md)或[addMonitor](./arkts-new-addMonitor-clearMonitor.md)监听mutableBuilder中@Builder的变化。

<!-- @[mutable_builder_binding](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/mutableBuilder/entry/src/main/ets/pages/MutableBuilderBinding.ets) --> 

``` TypeScript
import { UIUtils, MutableBinding } from '@kit.ArkUI';

@Builder
function textBuilder(p: MutableBinding<string>) {
  Text(p.value)
    .margin(20)
    .onClick(() => {
      p.value += 't';
    })
}

@Builder
function buttonBuilder(p: MutableBinding<string>) {
  Button(p.value)
    .margin(20)
    .onClick(() => {
      p.value += 'b';
    })
}

let counter: number = 1;

@Entry
@ComponentV2
struct MyApp {
  @Local message: string = 'init';
  @Local switchingBuilder: MutableBuilder<[MutableBinding<string>]> = mutableBuilder(textBuilder);

  @Monitor('switchingBuilder') variableChange(m: IMonitor): void {
    console.info(`Builder changed. is buttonBuilder: ${m.value<MutableBuilder<[MutableBinding<string>]>>()?.now.builder === buttonBuilder}`);
  }

  build() {
    Column() {
      this.switchingBuilder.builder(UIUtils.makeBinding(()=> this.message, txt => this.message = txt))
      Button('Click to change')
        .onClick(() => {
          counter++;
          if(counter % 2 === 0) {
            this.message += 'B';
            this.switchingBuilder = mutableBuilder(buttonBuilder); // textBuilder--->buttonBuilder，@Monitor会触发回调
          } else {
            this.message += 'T';
            this.switchingBuilder = mutableBuilder(textBuilder); // buttonBuilder--->textBuilder，@Monitor会触发回调
          }
        })
    }.position({x: 120, y: 60})
  }
}
```
点击`Click to change`按钮，可将`textBuilder`动态切换为`buttonBuilder`，`this.message`将自动加`B`，界面会显示`initB`按钮。点击`initB`按钮，`buttonBuilder`中的`p.value`将自动加`b`，如下图所示：

![arkts-mutableBuilder-dynamic-demo2](figures/mutableBuilder-dynamic-demo2.gif)

点击`Click to change`按钮将`textBuilder`动态切换为`buttonBuilder`时，@Monitor将监听到全局@Builder的变化，并打印日志`Builder changed. is buttonBuilder: true`。

