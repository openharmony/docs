# arkui子系统ChangeLog

## cl.arkui.1 状态变量数据类型声明使用限制。

所有的状态装饰器变量需要显式声明变量类型，不允许声明any。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample {
  // 错误写法: @State isLunar: any = false
  @State isLunar: boolean = false

  build() {
   ...
  }
}
```

**变更影响**

如果状态装饰器变量没有显式声明变量类型，声明any，编译拦截等级由WARN变成ERROR。

```ts
// ArkTS:ERROR Please define an explicit type, not any.
@State isLunar: any = false
```

**关键的接口/组件变更**

不涉及。

**适配指导**

状态装饰器变量声明具体的变量类型替代any。

## cl.arkui.2 自定义组件成员变量初始化的规则与约束。

不允许从父组件初始化`@LocalStorageLink`, `@LocalStorageProp`修饰的变量。

**示例：**

```ts
let NextID: number = 0;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Entry
@Component
struct LocalStorageComponent {
  build() {
    Column() {
      Child({
        /* ArkTS:ERROR Property 'simpleVarName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        simpleVarName: 1,
        /* ArkTS:ERROR Property 'objectName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        objectName: new ClassA(1)
      })
    }
  }
}

@Component
struct Child {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
  @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA(1);

  build() {
  }
}
```

**变更影响**

如果父组件初始化`@LocalStorageLink`, `@LocalStorageProp`修饰的变量，编译拦截等级由WARN变成ERROR。

**关键的接口/组件变更**

不涉及。

**适配指导**

构造子组件时，不对子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量进行赋值。

如果需要在父组件中修改子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量，则使用LocalStorage提供的API接口方法(比如set方法)赋值。

## cl.arkui.3 PromptAction模块中，文本提示框toast的bottom属性含义变更。

文本提示框toast的bottom属性值的含义，从文本提示框上边沿到屏幕下边沿，变更为文本提示框下边沿到屏幕下边沿。

**示例：**

```ts
import promptAction from '@ohos.promptAction';
@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
      .onClick(() => {
        try {
          promptAction.showToast({
            message: 'Message Info',
            duration: 2000
          });
        } catch (error) {
          console.error(`showToast args error code is ${error.code}, message is ${error.message}`);
        };
      })
    }
  }
}
```

**变更影响**

PromptAction模块中，文本提示框toast的bottom属性设置同样的数值，会由于编译器所使用的API版本是否为API version 10+而有所差异。

**关键的接口/组件变更**

不涉及。

**适配指导**

编译器采用API version 9或以往版本以保持之前的样式，或者采用API version 10及以上版本以采用新样式。

## cl.arkui.4 AlertDialog控件内容布局变更。

AlertDialog的内容属性部分会根据：1）有无标题title，2）是否为单行文本，条件不同而布局有所不同。

目前规格：仅无标题title的单行文本情况下为居中，其余情况文本左对齐。

**示例：**

```ts
// xxx.ets
@Entry
@Component
struct AlertDialogExample {
  build() {
    Column({ space: 5 }) {
      Button('one button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text'.repeat(20),
              autoCancel: true,
              alignment: DialogAlignment.Bottom,
              offset: { dx: 0, dy: -20 },
              gridCount: 3,
              confirm: {
                value: 'button',
                action: () => {
                  console.info('Button-clicking callback')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
        })
        .backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

**变更影响**

AlertDialog控件message属性对应的文本内容，布局效果变更。

**关键的接口/组件变更**

不涉及。

**适配指导**

无需主动适配，或者可以使用customDialog做相关实现。

## cl.arkui.5 popup避让行为优化。

变更前，popup发生避让优先在下方空间找位置，导致在上方空间充足也无法设置在上方显示。

目前规格：根据开发者设置，若设置在上方，优先在上方空间找位置；若设置在下方，优先在上下方空间找位置。

**变更影响**

使用bindpopup属性，气泡避让行为优化。

**关键的接口/组件变更**

不涉及。

**适配指导**

若发现使用场景中，使用bindpopup属性，气泡出现位置与之前发生上下位置变化，可通过调整placement恢复。