# 文本滑动选择器弹窗

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

根据指定的选择范围创建文本选择器，展示在弹窗上。

## 权限列表

无

## TextPickerDialog.show

show(options: TextPickerDialogOptions)

定义文本滑动选择器弹窗并弹出。

- TextPickerDialogOptions参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | range | string[] | 是 | - | 选择器的数据选择范围。 |
  | selected | number | 否 | 第一个元素 | 选中项在数组中的index值。 |
  | defaultPickerItemHeight | number | 否 | - | 默认Picker内容项元素高度。 |
  | onAccept | (value: TextPickerResult) => void | 否 | - | 点击弹窗中确定按钮时触发。 |
  | onCancel | () => void | 否 | - | 点击弹窗中取消按钮时触发。 |
  | onChange | (value: TextPickerResult) => void | 否 | - | 滑动选择器，当前选择项改变时触发。 |

- TextPickerResult对象说明
  | 名称 | 参数类型 | 描述 | 
  | -------- | -------- | -------- |
  | value | string | 选中项文本。 | 
  | index | number | 选中项在数组中的index值。 | 

## 示例

```ts
// xxx.ets
@Entry
@Component
struct TextPickerDialogExample {
  @State select: number = 1
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']

  build() {
    Flex({direction: FlexDirection.Column, alignItems: ItemAlign.Center,
      justifyContent: FlexAlign.Center }) {
      Button("TextPickerDialog").onClick(() => {
        TextPickerDialog.show({
          range: this.fruits,
          selected: this.select,
          onAccept: (value: TextPickerResult) => {
            console.info("TextPickerDialog:onAccept()" + JSON.stringify(value))
            this.select = value.index
          },
          onCancel: () => {
            console.info("TextPickerDialog:onCancel()")
          },
          onChange: (value: TextPickerResult) => {
            console.info("TextPickerDialog:onChange()" + JSON.stringify(value))
          }
        })
      })
    }
  }
}
```
