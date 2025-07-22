# 组件双向绑定（ArkTS1.2）

\$$函数为系统组件提供ArkTS变量的双向绑定能力，使得ArkTS变量和系统组件的内部状态保持同步。

双向绑定语法详见[\$$()双向绑定函数](../../ui/state-management/arkts-two-way-sync1.2.md)。

>**说明：**
>
>从API version 20开始，该接口仅支持在ArkTS1.2上使用。
>
>

## 导入模块

```ts
import { $$ } from '@ohos.arkui.component';
```

##  \$$()<sup>20+</sup>

 \$$\<T\>(value: T): Bindable\<T\>

将支持双向绑定的组件属性转换成Bindable的绑定对象。

 **系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ---------------------- |
| value | T | 是   | 支持双向绑定的属性。 |

**返回值：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| [Bindable\<T\>](#Bindable\<T\><sup>20+</sup>)  | 将支持双向绑定的属性转成绑定对象。 |

**示例：**

```ts
import { Text, Entry, Column, Component, $$, TextInput } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct MyStateSample {
  @State stateVar: string = "";

  build() {
    Column() {
      Text('展示$$ （）双向绑定')
      Text(this.stateVar)
      TextInput({ text: $$(this.stateVar), placeholder: 'input your word...' })
    }.width(`100%`).height(`100%`)
  }
}
```
##  Bindable\<T\><sup>20+</sup>

\$$()双向绑定函数的返回值类型。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|名称   |类型    |只读   |可选    |说明      |
|--------|------------|------------|-----------|--------------|
|value        | T   |是   |否   |支持双向绑定的值。         |
|onChange         | Callback\<T\>   |是   |否   |定义可绑定属性的回调，该属性将在属性更改时调用。             |