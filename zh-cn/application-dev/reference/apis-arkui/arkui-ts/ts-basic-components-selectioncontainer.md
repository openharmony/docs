# SelectionContainer
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiangyuan6-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

SelectionContainer组件用于为多个文本节点提供跨节点文本选中、复制及菜单扩展能力，支持统一配置选中文本的手柄颜色和底板颜色，支持灵活的文本拼接策略，支持自定义选择菜单和扩展菜单选项。适用于需要跨多个Text组件实现文本连续选中、统一复制、样式自定义及菜单扩展的场景，解决了多Text组件场景下文本选择体验割裂的问题，提升了用户在复杂文本布局中的交互体验。

> **说明：**
>
> - 本组件中选中文本相关回调返回的文本内容，按照[Text](ts-basic-components-text.md)组件的从上到下显示顺序进行拼接。
> - 本模块接口仅可在Stage模型下使用。
> - 本组件默认布局走[Stack](ts-container-stack.md)，如有其他容器布局需求请在SelectionContainer内放置一个容器组件。
> - SelectionContainer内跨节点选中文本时不显示放大镜，也不支持[getMagnifier](../../apis-arkui/arkts-apis-uicontext-uicontext.md#getmagnifier22)主动设置放大镜。
> - 仅Text组件中的文本内容参与跨节点选中与文本拼接。

**起始版本：** 26.0.0

## 子组件

可以包含子组件。

## 接口

SelectionContainer(value?: SelectionContainerOptions)

创建一个SelectionContainer组件。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| value | [SelectionContainerOptions](#selectioncontaineroptions) | 否 | 组件初始化配置项。 |

## 属性

支持[通用属性](ts-component-general-attributes.md)。

> **说明：**
>
> - 不支持[隐私遮罩](ts-universal-attributes-obscured.md)。
> - 不支持[图形变换](ts-universal-attributes-transformation.md)，跨节点场景中Text子组件不支持图形变换。

### copyOption

copyOption(value: Optional\<CopyOptions>)

设置组件的复制粘贴配置项。未通过该接口设置时，默认为CopyOptions.InApp。

> **说明：**
>
> Text子组件已显式设置[copyOption](ts-basic-components-text.md#copyoption9)时，优先使用Text子组件的配置；未设置时，使用SelectionContainer的配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| value | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[CopyOptions](ts-appendix-enums.md#copyoptions9)> | 是 | 复制粘贴配置项，用于设置文本的可复制范围。具体说明请参考CopyOptions枚举。 |

### caretColor

caretColor(color: Optional\<ResourceColor>)

设置选中文本手柄颜色。未通过该接口设置时，默认手柄颜色为'#007DFF'（蓝色）。

> **说明：**
>
> - 该属性在跨节点场景中用于各Text子组件选中文本手柄颜色。
> - 在跨节点场景中Text子组件[caretColor](ts-basic-components-text.md#caretcolor14)设置无效，始终使用SelectionContainer的配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| color | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[ResourceColor](ts-types.md#resourcecolor)> | 是 | 手柄颜色。 |

### selectedBackgroundColor

selectedBackgroundColor(color: Optional\<ResourceColor>)

设置选中文本底板颜色。未通过该接口设置时，默认选中文本底板颜色为'#007DFF'（蓝色），如果未设置不透明度，默认为20%不透明度。

> **说明：**
>
> - 该属性在跨节点场景中用于各Text子组件选中区域的高亮颜色。
> - Text子组件已显式设置[selectedBackgroundColor](ts-basic-components-text.md#selectedbackgroundcolor14)时，优先使用Text子组件的配置；未设置时，使用SelectionContainer的配置。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| color | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[ResourceColor](ts-types.md#resourcecolor)> | 是 | 选中文本底板颜色。 |

### enableHapticFeedback

enableHapticFeedback(isEnabled: Optional\<boolean>)

设置是否开启触控反馈。未通过该接口设置时，默认开启。

开启触控反馈时，需要在工程的[module.json5配置文件](../../../quick-start/module-configuration-file.md)中配置requestPermissions字段开启振动权限，配置如下：

```json
"requestPermissions": [
  {
    "name": "ohos.permission.VIBRATE"
  }
]
```

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| isEnabled | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是 | 是否开启触控反馈。<br>true表示开启触控反馈，false表示不开启触控反馈。 |

### textJoinStyle

textJoinStyle(style: Optional\<SelectionContainerTextJoinStyle>)

设置SelectionContainer内聚合文本的拼接方式。未通过该接口设置时，默认为SelectionContainerTextJoinStyle.NEWLINE，表示不同文本节点之间使用换行符\n拼接。

> **说明：**
>
> - 该配置会影响[onWillCopy](#onwillcopy)、[onCopy](#oncopy)、[bindSelectionMenu](#bindselectionmenu)相关回调中返回的文本内容。
> - 该配置也会影响系统内置菜单项中依赖文本拼接结果的逻辑。例如，选择两个Text节点中的文本时，若配置为SelectionContainerTextJoinStyle.NEWLINE，执行复制后两段文本之间会插入换行符；若配置为SelectionContainerTextJoinStyle.DIRECT，执行复制后两段文本会直接拼接。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| style | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[SelectionContainerTextJoinStyle](#selectioncontainertextjoinstyle)> | 是 | 聚合文本拼接方式。 |

### bindSelectionMenu

bindSelectionMenu(spanType: Optional\<TextSpanType>, content: Optional\<CustomBuilder>, responseType: Optional\<TextResponseType>, options?: Optional\<SelectionContainerMenuOptions>)

设置自定义选择菜单。未通过该接口设置时，默认spanType为TextSpanType.TEXT，responseType为TextResponseType.LONG_PRESS。

> **说明：**
>
> - bindSelectionMenu的长按响应时长为600ms，[bindContextMenu](ts-universal-attributes-menu.md#bindcontextmenu8)的长按响应时长为800ms，当两者同时绑定且触发方式均为长按时，优先响应bindSelectionMenu。
> - 自定义菜单过长时，建议内部嵌套使用[Scroll](ts-container-scroll.md)组件，避免键盘被遮挡。
> - 选区跨越不可复制Text时，菜单仅基于实际选中的可复制文本进行显示和处理。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| spanType | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[TextSpanType](ts-basic-components-text.md#textspantype11枚举说明)> | 是 | 选择菜单类型。用于指定选择菜单作用的文本类型范围，不同类型对应不同的菜单行为。各枚举值的含义及适用场景详见[TextSpanType](ts-basic-components-text.md#textspantype11枚举说明)。 |
| content | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[CustomBuilder](ts-types.md#custombuilder8)> | 是 | 选择菜单内容。 |
| responseType | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[TextResponseType](ts-basic-components-text.md#textresponsetype11枚举说明)> | 是 | 选择菜单响应类型。 |
| options | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[SelectionContainerMenuOptions](#selectioncontainermenuoptions)> | 否 | 选择菜单选项，用于配置菜单出现、消失、显示、隐藏等事件的回调。当需要监听这些菜单事件时传入此参数，不传入时默认不监听菜单事件。 |

### editMenuOptions

editMenuOptions(editMenu: Optional\<SelectionContainerEditMenuOptions>)

设置选中文本后的编辑菜单选项，包括菜单文本、图标和回调等。

> **说明：**
>
> 当同时为当前场景设置了[bindSelectionMenu](#bindselectionmenu)和editMenuOptions时，优先使用bindSelectionMenu，editMenuOptions不生效。bindSelectionMenu用于完全自定义菜单风格和触发条件，由开发者定义所有菜单项；editMenuOptions用于在系统默认菜单基础上添加扩展项，触发条件不变。建议根据自定义程度需求选择。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| editMenu | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[SelectionContainerEditMenuOptions](#selectioncontainereditmenuoptions)> | 是 | 自定义编辑菜单配置。 |

## 事件

支持[通用事件](ts-component-general-events.md)。

> **说明：**
>
> 不支持[拖拽事件](ts-universal-events-drag-drop.md)。

### onTextSelectionChange

onTextSelectionChange(callback: Optional\<Callback\<Array\<string>>>)

SelectionContainer中选中文本发生变化时触发该回调。使用callback异步回调。

> **说明：**
>
> - 回调参数数组中各项顺序与Text组件视觉顺序一致。
> - 数组中的每一项对应一个Text子组件的选中文本。
> - 仅包含有选中文本的Text子组件，不包含未选中Text子组件，也不包含不可复制Text的空字符串占位。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| callback | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[Callback](ts-types.md#callback12)\<Array\<string>>> | 是 | 选中文本变化回调。 |

### onWillCopy

onWillCopy(callback: Optional\<Callback\<string, boolean>>)

在进行复制操作前，触发该回调。使用callback异步回调。

> **说明：**
>
> - 回调参数为按Text组件视觉顺序拼接后的选中文本，拼接方式由[textJoinStyle](#textjoinstyle)配置决定。
> - 返回false时，会阻止本次跨节点复制及容器级[onCopy](#oncopy)回调触发，但不会影响各Text子组件已独立处理完成的复制事件逻辑。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| callback | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[Callback](ts-types.md#callback12)\<string, boolean>> | 是 | 复制前检查回调，返回true表示允许复制，返回false表示不允许复制。 |

### onCopy

onCopy(callback: Optional\<Callback\<string>>)

长按文本内部区域弹出选择菜单后，点击选择菜单的复制按钮，触发该回调。仅支持复制文本。使用callback异步回调。

> **说明：**
>
> - 回调参数为按Text组件视觉顺序拼接后的选中文本，拼接方式由[textJoinStyle](#textjoinstyle)配置决定。
> - 仅当容器级[onWillCopy](#onwillcopy)返回true时，该回调才会触发。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| callback | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[Callback](ts-types.md#callback12)\<string>> | 是 | 复制回调。 |

## SelectionContainerTextJoinStyle

文本聚合拼接方式。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| ---- | -- | ---- |
| NEWLINE | 0 | 不同文本节点之间使用换行符`\n`拼接。 |
| DIRECT | 1 | 不同文本节点之间直接拼接，不添加分隔符。 |

## SelectionContainerMenuOptions

配置选择菜单中的选项。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| onAppear | [Callback](ts-types.md#callback12)\<string> | 否 | 是 | 选择菜单出现时触发。回调参数为按Text组件视觉顺序拼接后的选中文本，拼接方式由textJoinStyle配置决定。默认值为空，不触发该回调。 |
| onDisappear | [Callback](ts-types.md#callback12)\<void> | 否 | 是 | 选择菜单消失时触发。默认值为空，不触发该回调。 |
| onMenuShow | [Callback](ts-types.md#callback12)\<string> | 否 | 是 | 选择菜单显示时触发。回调参数为按Text组件视觉顺序拼接后的选中文本，拼接方式由textJoinStyle配置决定。默认值为空，不触发该回调。 |
| onMenuHide | [Callback](ts-types.md#callback12)\<string> | 否 | 是 | 选择菜单隐藏时触发。回调参数为按Text组件视觉顺序拼接后的选中文本，拼接方式由textJoinStyle配置决定。默认值为空，不触发该回调。 |

## OnMenuItemClickWithTextCallback

type OnMenuItemClickWithTextCallback = (menuItem: TextMenuItem, value: string) => boolean

点击菜单项时触发，可拦截系统默认菜单项（如复制、粘贴菜单项）的执行行为。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ---- | ---- | ---- |
| menuItem | [TextMenuItem](ts-text-common.md#textmenuitem12对象说明) | 是 | 当前点击的菜单项。 |
| value | string | 是 | 选中文本内容。 |

**返回值：**

| 类型 | 说明 |
| ---- | ---- |
| boolean | 菜单项点击事件的处理结果。返回true表示事件已处理，返回false表示未处理。 |

## SelectionContainerEditMenuOptions

SelectionContainer自定义编辑菜单选项。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| onCreateMenu | [OnCreateMenuCallback](ts-text-common.md#oncreatemenucallback) | 否 | 是 | 每次菜单显示前触发，传入默认菜单项并返回处理后的菜单项。默认值为空，不触发该回调。 |
| onMenuItemClick | [OnMenuItemClickWithTextCallback](#onmenuitemclickwithtextcallback) | 否 | 是 | 点击菜单项时触发，可拦截系统默认菜单执行行为。默认值为空，不触发该回调。 |
| onPrepareMenu | [OnPrepareMenuCallback](ts-text-common.md#onpreparemenucallback20) | 否 | 是 | 文本选中内容变化后、菜单显示前触发，可在该回调中调整菜单数据。默认值为空，不触发该回调。 |

## SelectionContainerController

SelectionContainer组件的控制器。

**起始版本：** 26.0.0

### closeSelectionMenu

closeSelectionMenu(): void

关闭SelectionContainer的自定义或默认选择菜单。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### clearTextSelection

clearTextSelection(): void

清除SelectionContainer当前的文本选中状态；若选择菜单正在显示，会同时关闭选择菜单。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## SelectionContainerOptions

组件初始化配置项。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| controller | [SelectionContainerController](#selectioncontainercontroller) | 否 | 否 | SelectionContainer控制器。 |

## 示例

### 示例1（跨节点选中文本并复制）

该示例通过[SelectionContainer](#接口)、[copyOption](#copyoption)、[textJoinStyle](#textjoinstyle)、[onTextSelectionChange](#ontextselectionchange)、[onWillCopy](#onwillcopy)、[onCopy](#oncopy)接口展示跨多个Text组件选中文本、拼接选中文本并处理复制回调的能力。

从API版本26.0.0开始，新增SelectionContainer组件和copyOption等接口。

```ts
import {
  SelectionContainer,
  SelectionContainerAttribute,
  SelectionContainerTextJoinStyle
} from '@kit.ArkUI';

@Entry
@Component
struct SelectionContainerExample1 {
  @State selectedParts: string[] = [];
  @State copiedText: string = '';

  build() {
    Column({ space: 12 }) {
      Text('请长按下方区域并跨节点选择文本')
        .fontSize(16)

      SelectionContainer() {
        Column({ space: 8 }) {
          Text('第一段文本：SelectionContainer支持跨多个Text组件进行选中。')
            .fontSize(18)
            .copyOption(CopyOptions.InApp)
          Text('第二段文本：选中结果会按照Text组件的视觉顺序进行拼接。')
            .fontSize(18)
            .copyOption(CopyOptions.InApp)
          Text('第三段文本：可以监听选中变化、复制前校验和复制完成事件。')
            .fontSize(18)
            .copyOption(CopyOptions.InApp)
        }
      }
      .copyOption(CopyOptions.InApp)
      .textJoinStyle(SelectionContainerTextJoinStyle.NEWLINE)
      .caretColor(Color.Red)
      .selectedBackgroundColor('#33007DFF')
      .onTextSelectionChange((value: Array<string>) => {
        this.selectedParts = value;
        console.info(`选中文本变化：${JSON.stringify(value)}`);
      })
      .onWillCopy((value: string) => {
        this.copiedText = `准备复制：${value}`;
        console.info(`准备复制文本：${value}`);
        return true;
      })
      .onCopy((value: string) => {
        this.copiedText = `复制成功：${value}`;
        console.info(`复制成功文本：${value}`);
      })
      .border({ width: 1, color: '#DCDCDC' })
      .padding(12)
      .width('100%')

      Text(`选中内容：${this.selectedParts.join(' | ')}`)
        .fontSize(14)
        .fontColor('#666666')

      Text(this.copiedText)
        .fontSize(14)
        .fontColor('#666666')
    }
    .width('100%')
    .padding(16)
  }
}
```

![selectionContainerDemo](figures/selectionContainerDemo.png)

### 示例2（绑定自定义选择菜单）

该示例通过[bindSelectionMenu](#bindselectionmenu)接口实现了跨节点选中文本时绑定自定义菜单的功能。

从API版本26.0.0开始，新增bindSelectionMenu属性。

```ts
import {
  SelectionContainer,
  SelectionContainerAttribute,
  SelectionContainerMenuOptions,
  SelectionContainerTextJoinStyle
} from '@kit.ArkUI';

@Entry
@Component
struct SelectionContainerExample2 {
  @State selectedText: string = '';
  @State menuLog: string = '';

  build() {
    Column({ space: 12 }) {
      Text('请长按下方区域选择文本，体验自定义菜单')
        .fontSize(16)

      SelectionContainer() {
        Column({ space: 8 }) {
          Text('第一段文本：SelectionContainer支持自定义选择菜单。')
            .fontSize(18)
          Text('第二段文本：通过bindSelectionMenu绑定完整自定义菜单。')
            .fontSize(18)
        }
      }
      .copyOption(CopyOptions.InApp)
      .textJoinStyle(SelectionContainerTextJoinStyle.DIRECT)
      .bindSelectionMenu(
        TextSpanType.TEXT,
        this.menuBuilder,
        TextResponseType.LONG_PRESS,
        {
          onAppear: (text: string) => {
            this.menuLog = `菜单出现：${text}`;
            console.info(`菜单出现：${text}`);
          },
          onDisappear: () => {
            this.menuLog = '菜单消失';
            console.info('菜单消失');
          },
          onMenuShow: (text: string) => {
            this.menuLog = `菜单显示：${text}`;
            console.info(`菜单显示：${text}`);
          },
          onMenuHide: (text: string) => {
            this.menuLog = `菜单隐藏：${text}`;
            console.info(`菜单隐藏：${text}`);
          }
        } as SelectionContainerMenuOptions
      )
      .onTextSelectionChange((value: Array<string>) => {
        this.selectedText = `选中：${value.join(' | ')}`;
        console.info(`选中变化：${JSON.stringify(value)}`);
      })
      .border({ width: 1, color: '#DCDCDC' })
      .padding(12)
      .width('100%')
    }
    .width('100%')
    .padding(16)
  }

  @Builder
  menuBuilder() {
    Column() {
      Menu() {
        MenuItemGroup() {
          MenuItem({ content: '自定义复制', labelInfo: '' })
            .onClick(() => {
              console.info('自定义复制被点击');
            })
          MenuItem({ content: '自定义分享', labelInfo: '' })
            .onClick(() => {
              console.info('自定义分享被点击');
            })
          MenuItem({ content: '自定义翻译', labelInfo: '' })
            .onClick(() => {
              console.info('自定义翻译被点击');
            })
        }
      }
      .radius($r('sys.float.ohos_id_corner_radius_card'))
      .clip(true)
      .backgroundColor('#F0F0F0')
    }
  }
}
```

![selectionContainerBindMenu](figures/selectionContainerBindMenu.png)

### 示例3（扩展菜单选项）

该示例通过[editMenuOptions](#editmenuoptions)接口实现了去除系统菜单中的翻译和搜索菜单项，并添加5个自定义菜单项的功能。同时在[onMenuItemClick](#onmenuitemclickwithtextcallback)回调中展示拦截系统复制操作（return true）和不拦截全选操作（return false）的差异。

从API版本26.0.0开始，新增editMenuOptions属性。

```ts
import {
  OnMenuItemClickWithTextCallback,
  SelectionContainer,
  SelectionContainerAttribute,
  SelectionContainerEditMenuOptions,
  SelectionContainerTextJoinStyle
} from '@kit.ArkUI';

@Entry
@Component
struct SelectionContainerExample3 {
  @State selectedText: string = '';
  @State menuClickLog: string = '';
  onCreateMenu = (menuItems: Array<TextMenuItem>) => {
    let targetIndex = menuItems.findIndex(item => item.id.equals(TextMenuItemId.TRANSLATE));
    if (targetIndex !== -1) {
      menuItems.splice(targetIndex, 1);
    }
    targetIndex = menuItems.findIndex(item => item.id.equals(TextMenuItemId.SEARCH));
    if (targetIndex !== -1) {
      menuItems.splice(targetIndex, 1);
    }
    let customItem1: TextMenuItem = {
      content: '标注',
      id: TextMenuItemId.of('highlight'),
    };
    let customItem2: TextMenuItem = {
      content: '收藏',
      id: TextMenuItemId.of('bookmark'),
    };
    let customItem3: TextMenuItem = {
      content: '批注',
      id: TextMenuItemId.of('comment'),
    };
    let customItem4: TextMenuItem = {
      content: '导出',
      id: TextMenuItemId.of('export'),
    };
    // $r('app.media.startIcon')需要替换为开发者所需的图像资源文件。
    let customItem5: TextMenuItem = {
      content: '推送',
      icon: $r('app.media.startIcon'),
      id: TextMenuItemId.of('push'),
    };
    menuItems.push(customItem1);
    menuItems.push(customItem2);
    menuItems.push(customItem3);
    menuItems.push(customItem4);
    menuItems.push(customItem5);
    return menuItems;
  }
  onMenuItemClick: OnMenuItemClickWithTextCallback = (menuItem: TextMenuItem, text: string) => {
    this.menuClickLog = `点击菜单项：${menuItem.content}，文本：${text}`;
    console.info(`点击菜单项：${menuItem.content}，文本：${text}`);
    if (menuItem.id.equals(TextMenuItemId.COPY)) {
      this.selectedText = `已复制：${text}`;
      console.info(`拦截系统复制操作，return true：${text}`);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.SELECT_ALL)) {
      this.selectedText = `全选操作：${text}`;
      console.info(`不拦截全选操作，return false：执行系统默认行为`);
      return false;
    }
    if (menuItem.id.equals(TextMenuItemId.of('highlight'))) {
      this.selectedText = `已标注：${text}`;
      console.info(`点击自定义菜单项：标注，文本：${text}`);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.of('bookmark'))) {
      this.selectedText = `已收藏：${text}`;
      console.info(`点击自定义菜单项：收藏，文本：${text}`);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.of('comment'))) {
      this.selectedText = `已批注：${text}`;
      console.info(`点击自定义菜单项：批注，文本：${text}`);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.of('export'))) {
      this.selectedText = `已导出：${text}`;
      console.info(`点击自定义菜单项：导出，文本：${text}`);
      return true;
    }
    if (menuItem.id.equals(TextMenuItemId.of('push'))) {
      this.selectedText = `已推送：${text}`;
      console.info(`点击自定义菜单项：推送，文本：${text}`);
      return true;
    }
    return false;
  }
  @State editMenuOptions: SelectionContainerEditMenuOptions = {
    onCreateMenu: this.onCreateMenu,
    onMenuItemClick: this.onMenuItemClick
  };

  build() {
    Column({ space: 12 }) {
      Text('请长按下方区域选择文本，体验扩展菜单')
        .fontSize(16)

      SelectionContainer() {
        Column({ space: 8 }) {
          Text('第一段文本：SelectionContainer支持扩展菜单选项。')
            .fontSize(18)
          Text('第二段文本：可以去除系统菜单项并添加自定义菜单项。')
            .fontSize(18)
        }
      }
      .copyOption(CopyOptions.InApp)
      .textJoinStyle(SelectionContainerTextJoinStyle.DIRECT)
      .editMenuOptions(this.editMenuOptions)
      .onTextSelectionChange((value: Array<string>) => {
        this.selectedText = `选中：${value.join(' | ')}`;
        console.info(`选中变化：${JSON.stringify(value)}`);
      })
      .border({ width: 1, color: '#DCDCDC' })
      .padding(12)
      .width('100%')

      Text(this.selectedText)
        .fontSize(14)
        .fontColor('#666666')

      Text(this.menuClickLog)
        .fontSize(14)
        .fontColor('#999999')
    }
    .width('100%')
    .padding(16)
  }
}
```

![selectionContainerEditMenu](figures/selectionContainerEditMenu.png)

### 示例4（通过控制器关闭选择菜单与清除文本选中）

该示例通过[SelectionContainer](#接口)传入[SelectionContainerController](#selectioncontainercontroller)，调用[closeSelectionMenu](#closeselectionmenu)和[clearTextSelection](#cleartextselection)接口展示关闭选择菜单和清除选中文本的能力。

从API版本26.0.0开始，新增[SelectionContainerController](#selectioncontainercontroller)和[SelectionContainerOptions](#selectioncontaineroptions)接口。

```ts
import {
  SelectionContainer,
  SelectionContainerController,
  SelectionContainerAttribute
} from '@kit.ArkUI';

@Entry
@Component
struct SelectionContainerControllerExample {
  private controller: SelectionContainerController = new SelectionContainerController();

  build() {
    Column({ space: 12 }) {
      Text('请长按下方区域跨节点选中文本，再点击按钮关闭选择菜单或清除选中文本')
        .fontSize(16)

      SelectionContainer({ controller: this.controller }) {
        Column({ space: 8 }) {
          Text('第一段文本：SelectionContainer支持跨多个Text组件进行选中。')
            .fontSize(18)
            .copyOption(CopyOptions.InApp)
          Text('第二段文本：选中后可通过控制器关闭选择菜单或清除选中文本。')
            .fontSize(18)
            .copyOption(CopyOptions.InApp)
        }
      }
      .copyOption(CopyOptions.InApp)
      .border({ width: 1, color: '#DCDCDC' })
      .padding(12)
      .width('100%')

      Row({ space: 12 }) {
        Button('关闭选择菜单')
          .onClick(() => {
            this.controller.closeSelectionMenu();
          })
        Button('清除文本选中')
          .onClick(() => {
            this.controller.clearTextSelection();
          })
      }
    }
    .width('100%')
    .padding(16)
  }
}
```

![selectionContainerController](figures/selectionContainerController.gif)
