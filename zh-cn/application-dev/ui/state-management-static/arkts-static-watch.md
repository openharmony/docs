# \@Watch装饰器：状态变量更改通知

\@Watch应用于对状态变量的监听。如果开发者需要关注某个状态变量的值是否改变，可以使用\@Watch为状态变量设置回调方法。

\@Watch提供了状态变量的监听能力，仅能监听可以观察到的变化。

## 概述

\@Watch用于监听状态变量的变化，当状态变量变化时，\@Watch装饰的回调方法将被调用。\@Watch在ArkUI框架内部使用严格相等（===）判断数值是否更新。当判断结果为false（即不相等）时，会触发\@Watch的回调。

在静态语言上下文中使用时，需要导入装饰器：

```ts
import { Watch } from '@ohos.arkui.stateManagement';
```

## 装饰器说明

| \@Watch补充变量装饰器 | 说明                                       |
| -------------- | ---------------------------------------- |
| 装饰器参数          | 必填。常量字符串，字符串需要有引号。是`(string) => void`类型的自定义组件成员方法的方法名。 |
| 可装饰的变量类型    | 可装饰状态变量，即被状态装饰器装饰的变量。不支持装饰常规变量。               |
| 装饰器的顺序         | 装饰器顺序不影响实际功能，开发者可以根据自己的需要决定装饰器顺序的先后。建议\@State、 \@PropRef、 \@Link等装饰器在\@Watch装饰器之前，以保持整体风格的一致。 |
| \@Watch触发时机 | 使用\@Watch来监听状态变量变化时，回调触发时间是变量真正变化、被赋值的时间。 |

## 语法说明

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| (propertyName: string) => void | 该方法是自定义组件的成员方法，propertyName入参为回调该方法的状态变量的变量名。 <br/>在多个状态变量绑定同一个\@Watch的回调方法时，可以通过propertyName进行不同的逻辑处理。 |

## 观察变化和行为表现

1. 当观察到状态变量变化时，对应的\@Watch回调方法将被触发。

2. \@Watch回调方法在状态变量变化之后同步执行。

3. 如果在\@Watch的方法里更改了其他状态变量，也会引起状态变更和\@Watch回调方法的执行。

4. 在状态变量初始化时，\@Watch装饰的方法不会被调用，即认为初始化不是状态变量的改变。在后续状态变量改变时，调用\@Watch回调方法。

## 限制条件

- 当\@Watch的回调方法中直接或间接地修改了监听的状态变量时，可能会引起该回调方法的无限循环。为防止该现象的发生，建议开发者不要在\@Watch的回调方法中修改当前监听的状态变量。

- \@Watch装饰器的参数是必选项，且参数必须为string类型，否则编译期会报错。

  ```ts
  // 错误写法，未传参数
  @State @Watch() num: number = 10;
  // 错误写法，参数类型不匹配
  @State @Watch(change) num: number = 10;
  
  // 正确写法
  @State @Watch('change') num: number = 10;
  change(propertyName: string) {}
  ```

- \@Watch装饰器的参数必须与回调方法名保持一致，否则编译期会报错。

  ```ts
  // 错误写法，没有对应名称的回调方法，编译报错
  @State @Watch('change') num: number = 10;
  onChange(propertyName: string) {}
  
  // 正确写法
  @State @Watch('change') num: number = 10;
  change(propertyName: string) {}
  ```

- \@Watch仅能装饰状态变量，不能装饰常规变量，否则编译期会报错。

  ```ts
  //错误写法
  @Watch('change') num: number = 10;
  change(propertyName: string ) {}
  
  // 正确写法
  @State @Watch('change') num: number = 10;
  change(propertyName: string) {}
  ```

## 使用场景

### \@Watch和自定义组件更新

```ts
import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
import { State, Watch, PropRef } from '@ohos.arkui.stateManagement';

@Component
struct TotalView {
  @PropRef @Watch('onCountUpdated') count: number = 0;
  @State total: number = 0;
  // @Watch 回调
  onCountUpdated(propName: string): void {
    this.total += this.count;
  }

  build() {
    Text(`Total: ${this.total}`)
  }
}

@Entry
@Component
struct CountModifier {
  @State count: number = 0;

  build() {
    Column() {
      Button('add to basket')
        .onClick((e: ClickEvent) => {
          this.count++;
        })
      TotalView({ count: this.count })
    }
  }
}
```

在上述示例中：

1. 在自定义组件`CountModifier`中定义`@State`状态变量`count`。在自定义组件`TotalView`中定义`@PropRef`状态变量`count`，接收自定义组件`CountModifier`中的状态变量`count`并监听其数值变化。同时，在自定义组件`TotalView`中定义`@State`状态变量`total`。

2. 在自定义组件`CountModifier`中点击按钮触发`count`自增，自定义组件`TotalView`中监听到`count`的变化，调用对应的回调方法。

3. 回调方法中更新`@State`状态变量`total`的数值，触发绑定该变量的UI组件刷新。

### 通过propertyName判断具体属性变化

当\@Watch装饰interface类型，或被`@Observed/@Track`装饰的class类型时，interface或class中不同的成员属性的修改，会将其具体的属性名传入回调方法，而非状态变量名。详细见以下示例代码：

```ts
import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
import { State, Watch } from '@ohos.arkui.stateManagement';
import hilog from '@ohos.hilog';

interface Info {
  name: string;
  age: number;
}

@Entry
@Component
struct Index {
  @State @Watch('changeProperty') info: Info = {name: 'Tom', age: 20} as Info;
  // @Watch 回调
  changeProperty(propertyName: string): void {
    hilog.info(0, 'Index', `${propertyName} has changed`);
  }

  build() {
    Column() {
      Text(`Info name: ${this.info.name}`).fontSize(30)
      Text(`Info age: ${this.info.age}`).fontSize(30)
      Button('change info name')
        .onClick((e: ClickEvent) => {
          this.info.name = 'Jerry';
        })
      Button('change info age')
        .onClick((e: ClickEvent) => {
          this.info.age = 18;
        })
    }
  }
}
```

在上述示例中：

1. 依次点击“change info name”按钮和“change info age”按钮，触发“changeProperty”回调函数。

2. 观察日志依次显示：

   ```
   name has changed
   age has changed
   ```

3. 通过日志可以看出，被监听的状态变量的属性发生变化时，触发回调方法能够准确传入对应修改的属性名，而非状态变量名“info”。 