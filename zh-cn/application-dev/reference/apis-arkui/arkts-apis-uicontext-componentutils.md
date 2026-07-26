# Class (ComponentUtils)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

提供获取组件绘制区域坐标、大小、平移、缩放、旋转及仿射矩阵等属性信息的能力，适用于需要查询组件绘制区域信息的场景，帮助开发者获取组件布局结果。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Class首批接口从API version 10开始支持。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 以下API需先使用UIContext中的[getComponentUtils()](./arkts-apis-uicontext-uicontext.md#getcomponentutils)方法获取到ComponentUtils对象，再通过该对象调用对应方法。

## getRectangleById

getRectangleById(id: string): componentUtils.ComponentInfo

获取组件大小、位置、平移、缩放、旋转及仿射矩阵属性信息。

> **说明：**
>
> 该接口需要在目标组件布局完成以后获取目标组件区域大小信息，建议在[布局回调](./js-apis-arkui-inspector.md)中使用该接口。如果组件动态创建但未挂载到组件树，则无法通过该接口获取经过测量与布局后的组件信息。因为此时组件一般未经过UI框架的测量与布局，请确保组件已挂载到组件树后再尝试获取组件信息。
>
> 该接口返回的组件位置为布局位置，某些属性计算不支持，如位置设置类[offset](./arkui-ts/ts-universal-attributes-location.md#offset)、[markAnchor](./arkui-ts/ts-universal-attributes-location.md#markanchor)、[Edges](./arkui-ts/ts-types.md#edges12)和[LocalizedEdges](./arkui-ts/ts-types.md#localizededges12)类型的[position](./arkui-ts/ts-universal-attributes-location.md#position)，以及图形变换类[rotate](./arkui-ts/ts-universal-attributes-transformation.md#rotate)、[translate](./arkui-ts/ts-universal-attributes-transformation.md#translate)、[scale](./arkui-ts/ts-universal-attributes-transformation.md#scale)、[transform](./arkui-ts/ts-universal-attributes-transformation.md#transform)。可使用替代接口[getPositionToWindowWithTransform](./js-apis-arkui-frameNode.md#getpositiontowindowwithtransform12)，获取组件相对于窗口且带有绘制属性的位置偏移。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型     | 必填   | 说明        |
| ---- | ------ | ---- | --------- |
| id   | string | 是    | 组件唯一标识id，需确保该id对应的组件已挂载到组件树且完成布局。 |

**返回值：**

| 类型                                                         | 说明                                             |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [componentUtils.ComponentInfo](./js-apis-arkui-componentUtils.md#componentinfo) | 组件大小、位置、平移、缩放、旋转及仿射矩阵属性信息。 |

**错误码：**

以下错误码的详细介绍请参见[接口调用异常错误码](./errorcode-internal.md)。

| 错误码ID  | 错误信息                |
| ------ | ------------------- |
| 100001 | UI execution context not found. |

**示例：**

<!--code_no_check-->
```ts
import { ComponentUtils } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          this.message = 'Welcome';
          let componentUtils: ComponentUtils = this.getUIContext().getComponentUtils();
          let componentInfo = componentUtils.getRectangleById("HelloWorld");
          let width = componentInfo.size.width; // 获取组件的宽度
          let height = componentInfo.size.height; // 获取组件的高度
          let localOffsetX = componentInfo.localOffset.x; // 获取组件相对于父组件的x轴偏移
          let localOffsetY = componentInfo.localOffset.y; // 获取组件相对于父组件的y轴偏移
          console.info(`width: ${width}, height: ${height}, localOffsetX: ${localOffsetX}, localOffsetY: ${localOffsetY}`);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
