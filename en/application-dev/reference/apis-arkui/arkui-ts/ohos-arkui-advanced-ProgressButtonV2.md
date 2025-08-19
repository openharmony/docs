# ProgressButtonV2


The **ProgressButtonV2** component is a download button with a progress indicator that shows the download progress.

This component is implemented based on [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2). Compared with [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), V2 offers a higher level of observation and management over data objects beyond the component level. You can now more easily manage download button data and states with greater flexibility, leading to faster UI updates.


> **NOTE**
>
> - This component is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.
> 
> - This component is not supported on wearables.


## Modules to Import

```
import { ColorMetrics, LengthMetrics, ProgressButtonV2,  ProgressButtonV2Color } from '@kit.ArkUI';
```

## ProgressButtonV2

ProgressButtonV2({progress: number, content: ResourceStr, progressButtonWidth?: LengthMetrics, onClicked: ClickCallback,
isEnabled: boolean, colorOptions?: ProgressButtonColorOptions, progressButtonRadius?: LengthMetrics})

The **ProgressButton** component is a download button with a progress indicator that shows the download progress.

**Decorator**: \@ComponentV2

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                               | Type                                                           | Mandatory| Decorator                 | Description                                                                               |
|-----------------------------------|---------------------------------------------------------------|----|------------------------|-----------------------------------------------------------------------------------|
| progress                          | number                                                        | Yes | \@Require <br>\@Param | Current download progress.<br>The value ranges from 0 to 100. Values less than 0 are adjusted to **0**, and values greater than 100 are capped at **100**.<br>Default value: **0**                                                                      |
| content                           | [ResourceStr](ts-types.md#resourcestr)                        | Yes | \@Require <br>\@Param | Button text.                                                                         |
| progressButtonWidth               | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | \@Param <br>\@Once  | Width of the button.<br>Default value: **44vp**                                                          |
| onClicked                         | [ClickCallback](#clickcallback)                               | Yes | \@Param                | Callback invoked when the button is clicked.                                                      |
| isEnabled                         | boolean                                                       | Yes | \@Param                | Whether the button can be clicked.<br> **true**: The button can be clicked.<br> **false**: The button cannot be clicked.|
| colorOptions                      | [ProgressButtonV2Color](#progressbuttonv2color)               | No | \@Param                | Color options for the button.<br>Default value: **undefined**                                                      |
| progressButtonRadius<sup>18+<sup> | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | \@Param                | Corner radius of the button. It cannot be set in percentage.<br>Value range: [0, height/2]<br>Default value: height/2<br>If an invalid value is set, the default value is used.  |

## Attributes
The [universal attributes](ts-component-general-attributes.md) are not supported.

## ClickCallback

type ClickCallback = () => void

Callback invoked when the button is clicked.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## ProgressButtonV2Color
Defines the color options for the download button.

**Decorator type**: @ObservedV2

### Properties

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Type          | Mandatory| Decorator  | Description                       |
|-----------------|--------------|----|---------|---------------------------|
| progressColor   | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | \@Trace | Color of the progress indicator.<br>Default value: **undefined** |
| borderColor     | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | \@Trace | Border color of the button.<br>Default value: **undefined**|
| textColor       | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | \@Trace | Text color of the button.<br>Default value: **undefined**|
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No | \@Trace | Background color of the button.<br>Default value: **undefined**|

### constructor
constructor(options: ProgressButtonV2ColorOptions);

A constructor used to create a **ProgressButtonV2Color** object.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                          | Mandatory| Description   |
|---------|------------------------------|----|-------|
| options | ProgressButtonV2ColorOptions | Yes | Color settings.|

## ProgressButtonV2ColorOptions

Provides options for customizing the color of the download button.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Type          | Mandatory| Description                       |
|-----------------|--------------|----|---------------------------|
| progressColor   | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)| No | Color of the progress indicator.<br>Default value: **undefined** |
| borderColor     | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)| No | Border color of the button.<br>Default value: **undefined**|
| textColor       | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)| No | Text color of the button.<br>Default value: **undefined**|
| backgroundColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)| No | Background color of the button.<br>Default value: **undefined**|

## Events
The [universal events](ts-component-general-events.md) are not supported.

## Example

This example demonstrates how to create a simple download button with a progress indicator that shows the loading status of a text file.
```ts
import { LengthMetrics, ProgressButtonV2 } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local progressIndex: number = 0;
  @Local textState: string = 'Download';
  @Local buttonWidth: LengthMetrics = LengthMetrics.vp(200);
  @Local isRunning: boolean = false;
  @Local enableState: boolean = true;

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButtonV2({
            progress: this.progressIndex,
            progressButtonWidth: this.buttonWidth,
            content: this.textState,
            isEnabled: this.enableState,
            onClicked: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = 'Continue';
              }
              this.isRunning = !this.isRunning;
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {

                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = 'Completed';
                      this.enableState = false;
                    }
                  }
                } else {
                  clearInterval(timer);
                }
              }, 20);
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 });
      }
    }
  }
}
```


![img.png](./figures/img.png)
