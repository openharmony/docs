# ProgressButton


The **ProgressButton** component is a download button with a progress indicator that shows the download progress.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { ProgressButton } from '@kit.ArkUI'
```

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.

## ProgressButton

ProgressButton({progress: number, content: string, progressButtonWidth?: Length, clickCallback: () =&gt; void, enable: boolean})

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                               | Type                                                           | Mandatory| Decorator | Description                                                                             |
|-----------------------------------|---------------------------------------------------------------|----|--------|---------------------------------------------------------------------------------|
| progress                          | number                                                        | Yes | \@Prop | Current download progress.                                                                    |
| content                           | string                                                        | Yes | \@Prop | Button text.                                                                       |
| progressButtonWidth               | [Length](ts-types.md#length)                                  | No | -      | Width of the button.<br>Default value: **44**                                                           |
| clickCallback                     | () =&gt; void                                                 | Yes | -      | Callback invoked when the button is clicked.                                                                     |
| enable                            | boolean                                                       | Yes | \@Prop | Whether the button can be clicked.<br> **true**: The button can be clicked.<br> **false**: The button cannot be clicked.                 |
| colorOptions<sup>16+<sup>         | [ProgressButtonColorOptions](#progressbuttoncoloroptions16)   | No | \@Prop | Color options of the button.                                                                     |
| progressButtonRadius<sup>16+<sup> | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No | \@Prop | Corner radius of the button. It cannot be set in percentage.<br>Value range: [0, height/2]<br>Default value: height/2<br>If an invalid value is set, the default value is used.|

## ProgressButtonColorOptions<sup>16+<sup>

Defines the color options for the download button.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Attributes             | Type                                    | Mandatory| Description     |
|-----------------|----------------------------------------|----|---------|
| progressColor   | [ResourceStr](ts-types.md#resourcestr) | No | Color of the progress indicator. |
| borderColor     | [ResourceStr](ts-types.md#resourcestr) | No | Border color of the button.|
| textColor       | [ResourceStr](ts-types.md#resourcestr) | No | Text color of the button.|
| backgroundColor | [ResourceStr](ts-types.md#resourcestr) | No | Background color of the button. |

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

### Example 1: Creating a Download Button with a Progress Indicator
This example demonstrates how to create a simple download button with a progress indicator that shows the loading status of a text file.
```ts
import { ProgressButton } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State progressIndex: number = 0
  @State textState: string = 'Download'
  @State ButtonWidth: number = 200
  @State isRunning: boolean = false
  @State enableState: boolean = true

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButton({
            progress: this.progressIndex,
            progressButtonWidth: this.ButtonWidth,
            content: this.textState,
            enable: this.enableState,
            clickCallback: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = 'Continue'
              }
              this.isRunning = !this.isRunning
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {

                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = 'Completed'
                      this.enableState = false
                    }
                  }
                } else {
                  clearInterval(timer)
                }
              }, 20)
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 })
      }
    }
  }
}
```


![img.png](./figures/img.png)

### Example 2: Implementing a Download Button with Custom Colors
This example shows how to implement a download button with custom colors.
```ts
import { ProgressButton } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State progressIndex: number = 0
  @State textState: string = 'Download'
  @State ButtonWidth: number = 200
  @State isRunning: boolean = false
  @State enableState: boolean = true

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButton({
            // Set the color options of the download button.
            colorOptions: {
              progressColor: Color.Orange,
              borderColor: Color.Black,
              textColor: Color.Blue,
              backgroundColor: Color.Pink
            },
            progress: this.progressIndex,
            progressButtonWidth: this.ButtonWidth,
            content: this.textState,
            enable: this.enableState,
            clickCallback: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = 'Continue'
              }
              this.isRunning = !this.isRunning
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {
                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = 'Completed'
                      this.enableState = false
                    }
                  }
                } else {
                  clearInterval(timer)
                }
              }, 20)
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 })
      }
    }
  }
}
```
![en-us_image_progressbutton_example02](figures/en-us_image_progressbutton_example02.png)

### Example 3: Implementing a Download Button with Custom Corner Radius
This example shows how to implement a download button with custom corner radius.
```ts
import { ProgressButton, LengthMetrics } from '@kit.ArkUI'

@Entry
@Component
struct Index {
  @State progressIndex: number = 0
  @State textState: string = 'Download'
  @State ButtonWidth: number = 200
  @State isRunning: boolean = false
  @State enableState: boolean = true

  build() {
    Column() {
      Scroll() {
        Column({ space: 20 }) {
          ProgressButton({
            progressButtonRadius: LengthMetrics.vp (8), // Set the custom corner radius to 8 vp.
            progress: this.progressIndex,
            progressButtonWidth: this.ButtonWidth,
            content: this.textState,
            enable: this.enableState,
            clickCallback: () => {
              if (this.textState && !this.isRunning && this.progressIndex < 100) {
                this.textState = 'Continue'
              }
              this.isRunning = !this.isRunning
              let timer = setInterval(() => {
                if (this.isRunning) {
                  if (this.progressIndex === 100) {
                  } else {
                    this.progressIndex++
                    if (this.progressIndex === 100) {
                      this.textState = 'Completed'
                      this.enableState = false
                    }
                  }
                } else {
                  clearInterval(timer)
                }
              }, 20)
            }
          })
        }.alignItems(HorizontalAlign.Center).width('100%').margin({ top: 20 })
      }
    }
  }
}
```
![en-us_image_progressbutton_example03](figures/en-us_image_progressbutton_example03.png)
