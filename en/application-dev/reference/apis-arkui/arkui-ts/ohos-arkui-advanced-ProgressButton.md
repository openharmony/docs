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
The [universal attributes](ts-component-general-attributes.md) are not supported.

## ProgressButton

ProgressButton({progress: number, content: string, progressButtonWidth?: Length, clickCallback: () =&gt; void, enable: boolean})

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                               | Type                                                           | Mandatory| Decorator | Description                                                                                                                                  |
|-----------------------------------|---------------------------------------------------------------|----|--------|--------------------------------------------------------------------------------------------------------------------------------------|
| progress                          | number                                                        | Yes | \@Prop | Current download progress.<br>The value ranges from 0 to 100. Values less than 0 are adjusted to **0**, and values greater than 100 are capped at **100**.<br>Default value: **0**.           |
| content                           | string                                                        | Yes | \@Prop | Button text.<br>The default value is an empty string.<br>**NOTE**<br>The text is truncated with an ellipsis (...) if it exceeds the maximum display width of the component.                          |
| progressButtonWidth               | [Length](ts-types.md#length)                                  | No | -      | Button width, in vp.<br>The value must be greater than or equal to 44 vp.<br>The default value is **44vp**. Values less than the default value and invalid values are adjusted to the default value.                  |
| clickCallback                     | () =&gt; void                                                 | Yes | -      | Callback invoked when the button is clicked.                                                                      |
| enable                            | boolean                                                       | Yes | \@Prop | Whether the button can be clicked.<br> **true**: The button can be clicked.<br> **false**: The button cannot be clicked.                  |

## Events
The [universal events](ts-component-general-events.md) are not supported.

## Example

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
