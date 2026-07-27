# Interface (AtomicServiceBar)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

AtomicServiceBar提供对原子化服务menuBar的属性设置能力，支持设置menuBar的可见性、背景颜色、标题内容、标题字体样式、图标颜色，以及获取menuBar的布局信息和监听布局变化。适用于需要在原子化服务中自定义menuBar外观和行为的场景。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Interface首批接口从API version 11开始支持。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 以下接口需要先使用UIContext中的[getAtomicServiceBar](arkts-apis-uicontext-uicontext.md#getatomicservicebar11)方法获取到AtomicServiceBar对象，再通过该对象调用对应方法。
>
> - 从API version 12开始原子化服务menuBar样式变更，setVisible、setBackgroundColor、setTitleContent、setTitleFontStyle、setIconColor接口的设置参数将被忽略，具体说明见各接口。

## setVisible<sup>11+</sup>

setVisible(visible: boolean): void

通过该方法设置原子化服务menuBar是否可见。

> **说明：**
>
> 从API version 12开始，原子化服务menuBar默认隐藏并以悬浮按钮替代。**在原子化服务中调用setVisible()时，visible参数将被忽略，无法实现menuBar的显示或隐藏。**

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| visible | boolean | 是 | 原子化服务menuBar是否可见。true表示设置menuBar可见，false表示设置menuBar不可见。从API version 12开始，在原子化服务中该参数将被忽略。|


**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err) {
        hilog.info(0x0000, 'testTag', 'LoadContent failed.');
        return;
      }
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully.');
        atomicServiceBar.setVisible(false);
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setBackgroundColor<sup>11+</sup>

setBackgroundColor(color:Nullable<Color | number | string>): void

通过该方法设置原子化服务menuBar的背景颜色。

> **说明：**
>
> 从API version 12开始，原子化服务menuBar背景默认隐藏。**在原子化服务中调用setBackgroundColor()时，color参数将被忽略，无法设置menuBar的背景颜色。**

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| color | Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 原子化服务menuBar的背景颜色，undefined代表使用默认颜色。number为HEX格式颜色，支持rgb或者argb，示例：0xffffff。string为rgb或者argb格式颜色，示例：'#ffffff'。从API version 12开始，在原子化服务中该参数将被忽略。|

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err) {
        hilog.info(0x0000, 'testTag', 'LoadContent failed.');
        return;
      }
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully.');
        atomicServiceBar.setBackgroundColor(0x88888888);
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setTitleContent<sup>11+</sup>

setTitleContent(content: string): void

通过该方法设置原子化服务menuBar的标题内容。

> **说明：**
>
> 从API version 12开始，原子化服务menuBar标题默认隐藏。**在原子化服务中调用setTitleContent()时，content参数将被忽略，无法设置menuBar的标题内容。**

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| content | string | 是 | 原子化服务menuBar中的标题内容。从API version 12开始，在原子化服务中该参数将被忽略。|

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err) {
        hilog.info(0x0000, 'testTag', 'LoadContent failed.');
        return;
      }
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully.');
        atomicServiceBar.setTitleContent('text2');
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setTitleFontStyle<sup>11+</sup>

setTitleFontStyle(font: FontStyle): void

通过该方法设置原子化服务menuBar标题的字体样式。

> **说明：**
>
> 从API version 12开始，原子化服务menuBar标题默认隐藏。**在原子化服务中调用setTitleFontStyle()时，font参数将被忽略，无法设置menuBar标题的字体样式，例如斜体显示。**

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------ |
| font | [FontStyle](arkui-ts/ts-appendix-enums.md#fontstyle) | 是 | 原子化服务menuBar标题中的字体样式。从API version 12开始，在原子化服务中该参数将被忽略。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err) {
        hilog.info(0x0000, 'testTag', 'LoadContent failed.');
        return;
      }
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully.');
        atomicServiceBar.setTitleFontStyle(FontStyle.Normal);
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setIconColor<sup>11+</sup>

setIconColor(color:Nullable<Color | number | string>): void

通过该方法设置原子化服务menuBar图标的颜色。

> **说明：**
>
> 从API version 12开始，原子化服务menuBar默认隐藏并以悬浮按钮替代。**在原子化服务中调用setIconColor()时，color参数将被忽略，无法设置menuBar图标颜色。**

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| color | Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | 是 | 原子化服务menuBar图标的颜色，undefined代表使用默认颜色。number为HEX格式颜色，支持rgb或者argb，示例：0xffffff。string为rgb或者argb格式颜色，示例：'#ffffff'。从API version 12开始，在原子化服务中该参数将被忽略。 |


**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err) {
        hilog.info(0x0000, 'testTag', 'LoadContent failed.');
        return;
      }
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully.');
        atomicServiceBar.setIconColor(0x12345678);
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## getBarRect<sup>15+</sup>

getBarRect(): Frame

获取原子化服务menuBar相对窗口的布局信息。

> **说明：**
>
> 布局信息反映的menuBar位置已考虑其左右margin的影响。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明            |
| ----------------- | ------------- |
| [Frame](js-apis-arkui-graphics.md#frame) | 原子化服务menuBar的大小和位置。 |

**示例：**

```ts
import { AtomicServiceBar, UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  build() {
    Button('getBarRect')
      .onClick(() => {
        let uiContext: UIContext = this.getUIContext();
        let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
        if (atomicServiceBar != undefined) {
          let rect = atomicServiceBar.getBarRect();
          hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar Successfully. x:'
            + rect.x + ' y:' + rect.y + ' width:' + rect.width + ' height:' + rect.height);
        } else {
          hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
        }
      })
  }
}
```

## onBarRectChange

onBarRectChange(callback: Callback\<Frame\>): void

当原子化服务menuBar（即AtomicServiceMenuBar，右上角菜单功能胶囊）的大小或位置发生变化时，触发注册的回调，返回menuBar最新的布局信息。该布局信息包含了menuBar的大小和位置，其中位置已考虑左右margin的影响。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| callback | [Callback](../apis-basic-services-kit/js-apis-base.md#callback)\<[Frame](js-apis-arkui-graphics.md#frame)> | 是 | AtomicServiceMenuBar布局变化时的回调，返回变化后的布局信息。 |

**示例：**

```ts
import { AtomicServiceBar, UIContext, Frame } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  aboutToAppear(): void {
    let uiContext: UIContext = this.getUIContext();
    let currentBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
    if (currentBar != undefined) {
      currentBar.onBarRectChange((rect: Frame) => {
        hilog.info(0x0000, 'testTag', 'trigger onBarRectChange callback success. X: %{public}d, Y: %{public}d, Width: %{public}d, height: %{public}d.', rect.x, rect.y, rect.width, rect.height);
      });
    } else {
      hilog.info(0x0000, 'testTag', 'set onBarRectChange callback failed.');
    }
  }
  build() {
    Text('hello world')
  }
}
```