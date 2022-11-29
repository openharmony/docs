# Checkbox

提供多选框组件，通常用于某选项的打开或关闭。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Checkbox(options?:&nbsp;{name?: string,  group?: string })

**参数:**

| 参数名  | 参数类型 | 必填  | 参数描述 |
| --------| --------| ------ | -------- |
| name    | string | 否 | 多选框名称。 |
| group   | string | 否 | 多选框的群组名称。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：


| 名称          | 参数类型 | 描述 |
| ------------- | ------- | -------- |
| select        | boolean | 设置多选框是否选中。<br/>默认值：false |
| selectedColor | [ResourceColor](ts-types.md#resourcecolor) | 设置多选框选中状态颜色。 |

## 事件

支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称      | 功能描述 |
| ----------| -------- |
|onChange(callback: (value: boolean) => void) | 当选中状态发生变化时，触发该回调。（只有手动触发且Checkbox状态改变时才会触发onChange回调）<br>- value为true时，表示已选中。<br>- value为false时，表示未选中。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {

  build() {
    Row() {
      Checkbox({name: 'checkbox1',  group: 'checkboxGroup'})
        .select(true)
        .selectedColor(0xed6f21)
        .onChange((value: boolean) => {
          console.info('Checkbox1 change is'+ value)
        })
      Checkbox({name: 'checkbox2',  group: 'checkboxGroup'})
        .select(false)
        .selectedColor(0x39a2db)
        .onChange((value: boolean) => {
          console.info('Checkbox2 change is'+ value)
        })
    }
  }
}
```


![](figures/checkbox.gif)