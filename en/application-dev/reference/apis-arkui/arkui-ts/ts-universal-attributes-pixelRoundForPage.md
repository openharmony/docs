# Page-Level Pixel Rounding
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Lichtschein-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

The goal of page-level pixel rounding is to set the pixel rounding mode as a context property of the page, enabling the configuration of pixel rounding at the page level.

>  **NOTE**
>
> - The initial APIs of this module are supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.
> - If pixel rounding [issues](ts-universal-attributes-pixelRoundForComponent.md#faqs) occur and cannot be resolved using [component-level pixel rounding](./ts-universal-attributes-pixelRoundForComponent.md), consider using the **PIXEL_ROUND_AFTER_MEASURE** mode.
> - In **PIXEL_ROUND_AFTER_MEASURE** mode, components perform rounding after size measurement is completed. As a result, the final size may be 1 px larger compared to the **PIXEL_ROUND_ON_LAYOUT_FINISH** mode.
> - The difference between page-level and component-level pixel rounding is: Page-level pixel rounding adjusts the rounding timing for the entire page, while component-level pixel rounding adjusts the rounding alignment method for specific components in specific directions.

## setPixelRoundMode

setPixelRoundMode(mode: PixelRoundMode): void

Sets the pixel rounding mode for this page.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type        | Mandatory  | Description  |
| -------- | ---------- | ---- | ---- |
| mode | [PixelRoundMode](./ts-appendix-enums.md#pixelroundmode18)| Yes   | Pixel rounding mode.<br>Default value: **PixelRoundMode.PIXEL_ROUND_ON_LAYOUT_FINISH**.|

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

onWindowStageCreate(windowStage: window.WindowStage) {
   windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext :UIContext = windowStage.getMainWindowSync().getUIContext();
      uiContext.setPixelRoundMode(PixelRoundMode.PIXEL_ROUND_AFTER_MEASURE);
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
```

## getPixelRoundMode

getPixelRoundMode(): PixelRoundMode

Obtains the pixel rounding mode for this page.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type        | Description  |
| ---------- | ---- |
| [PixelRoundMode](./ts-appendix-enums.md#pixelroundmode18)| Pixel rounding mode of the current page.|

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIContext } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      let uiContext: UIContext = windowStage.getMainWindowSync().getUIContext();
      console.info("pixelRoundMode : " + uiContext.getPixelRoundMode().valueOf());
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
    });
  }
```
