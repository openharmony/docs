# 自定义属性设置

当开发者希望在组件上设置自定义的属性时，可以使用自定义属性设置功能，在组件上设置自定义的属性。而这些自定义属性可以在其对应的FrameNode上获取，从而实现更自由的组件管理。

>  **说明：**
>
>  从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## customProperty

customProperty(name: string, value: Optional\<Object>): T

设置组件的自定义属性。[自定义组件](../../../ui/state-management/arkts-create-custom-components.md)不支持设置自定义属性。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                         |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name  | string | 是   | 自定义属性的名称。 |
| value  | Optional\<Object> | 是   | 自定义属性的值。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| T | 返回当前组件。 |


## Optional<sup>12+</sup>

Optional\<T>

定义可选类型，其值可以是undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

## 示例

在Column组件上设置自定义属性，并在其对应的FrameNode上获取所设置的自定义属性。

```ts
// xxx.ets
import { FrameNode, UIContext } from '@kit.ArkUI';

@Entry
@Component
struct CustomPropertyExample {
  build() {
    Column() {
      Text('text')
      Button('print').onClick(() => {
        const uiContext: UIContext = this.getUIContext();
        if (uiContext) {
          const node: FrameNode | null = uiContext.getFrameNodeById("Test_Column") || null;
          if (node) {
            for (let i = 1; i < 4; i++) {
              const key = 'customProperty' + i;
              const property = node.getCustomProperty(key);
              console.log(key, JSON.stringify(property));
            }
          }
        }
      })
    }
    .id('Test_Column')
    .customProperty('customProperty1', {
      'number': 10,
      'string': 'this is a string',
      'bool': true,
      'object': {
        'name': 'name',
        'value': 100
      }
    })
    .customProperty('customProperty2', {})
    .customProperty('customProperty2', undefined)
    .width('100%')
    .height('100%')
  }
}
```
