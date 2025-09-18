# Interface (AtomicServiceBar)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

Provides attributes for configuring the menu bar of an atomic service.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this interface are supported since API version 11.
>
> - In the following API examples, you must first use [getAtomicServiceBar](arkts-apis-uicontext-uicontext.md#getatomicservicebar11) in **UIContext** to obtain an **AtomicServiceBar** instance, and then call the APIs using the obtained instance.
>
> - Since API version 12, the atomic service menu bar style is changed, and the following APIs are obsolete:

## setVisible<sup>11+</sup>

setVisible(visible: boolean): void

Sets whether the atomic service menu bar is visible.
> **NOTE**
>
> The atomic service menu bar is hidden by default and replaced with a floating button since API version 12; it cannot be changed to visible using this API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| visible | boolean | Yes| Whether the atomic service menu bar is visible. The value **true** means the atomic service menu bar is visible, and **false** means the opposite.|


**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
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

Sets the background color of the atomic service menu bar.
> **NOTE**
>
> The background of the atomic service menu bar is hidden by default since API version 12; its color cannot be set using this API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| color | Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | Yes| Background color of the atomic service menu bar. The value **undefined** means to use the default color. A number value indicates a HEX color in RGB or ARGB format, for example, **0xffffff**. A string value indicates a color in RGB or ARGB format, for example, **'#ffffff'**.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
        atomicServiceBar.setBackgroundColor(0x88888888);
      } else {
        hilog.error(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setTitleContent<sup>11+</sup>

setTitleContent(content:string): void

Sets the title content of the atomic service menu bar.
> **NOTE**
>
> The title of the atomic service menu bar is hidden by default since API version 12; its content cannot be set using this API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name|Type|Mandatory|Description|
| ------- | ------- | ------- | ------- |
| content | string | Yes| Title content of the atomic service menu bar.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
        atomicServiceBar.setTitleContent('text2');
      } else {
        hilog.info(0x0000, 'testTag', 'Get AtomicServiceBar failed.');
      }
    });
  }
}
```

## setTitleFontStyle<sup>11+</sup>

setTitleFontStyle(font:FontStyle):void

Sets the font style of the atomic service menu bar.
> **NOTE**
>
> The title of the atomic service menu bar is hidden by default since API version 12; its font style cannot be set using this API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| font | [FontStyle](arkui-ts/ts-appendix-enums.md#fontstyle) | Yes| Font style of the atomic service menu bar.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
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

Sets the color of the atomic service icon.
> **NOTE**
>
> The atomic service menu bar is hidden by default and replaced with a floating button since API version 12; the icon color cannot be changed using this API.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| color | Nullable\<[Color](arkui-ts/ts-appendix-enums.md#color) \| number \| string> | Yes| Color of the atomic service icon. The value **undefined** means to use the default color. A number value indicates a HEX color in RGB or ARGB format, for example, **0xffffff**. A string value indicates a color in RGB or ARGB format, for example, **'#ffffff'**.|


**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { UIContext, AtomicServiceBar, window } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Main window is created, set main page for this ability
    hilog.info(0x0000, 'testTag', 'Ability onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      let atomicServiceBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
      if (atomicServiceBar != undefined) {
        hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully.');
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

Obtains the layout information of the atomic service menu bar relative to the window.
> **NOTE**
>
> The layout information includes the left and right margins of the atomic service menu bar.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description           |
| ----------------- | ------------- |
| [Frame](./js-apis-arkui-graphics.md#frame) | Size and position of the atomic service menu bar.|

**Example**

```ts
import { AtomicServiceBar } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';
@Entry
@Component
struct Index {
  build() {
    Button("getBarRect")
      .onClick(() => {
        let uiContext: UIContext = this.getUIContext();
        let currentBar: Nullable<AtomicServiceBar> = uiContext.getAtomicServiceBar();
        if (currentBar != undefined) {
          let rect = currentBar.getBarRect();
          hilog.info(0x0000, 'testTag', 'Get AtomServiceBar Successfully. x:' +
            rect.x + ' y:' + rect.y + ' width:' + rect.width + ' height:' + rect.height);
        } else {
          hilog.info(0x0000, 'testTag', 'Get AtomServiceBar failed.');
        }
      })
  }
}
```
