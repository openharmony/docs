# ProgressButton


The **ProgressButton** component is a download button with progress indicator that shows the download progress.


> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import { ProgressButton } from '@kit.ArkUI'
```

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are supported.

## ProgressButton

ProgressButton({progress: number, content: string, progressButtonWidth?: Length, clickCallback: () =&gt; void, enable: boolean})

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| progress | number | Yes| \@Prop | Current download progress.|
| content | string | Yes| \@Prop | Button text.|
| progressButtonWidth | [Length](ts-types.md#length) | No| - | Width of the button.<br>Default value: **44**|
| clickCallback | () =&gt; void | Yes| - | Callback invoked when the button is clicked.|
| enable | boolean | Yes| \@Prop | Whether the button can be clicked.<br> **true**: The button can be clicked.<br> **false**: The button cannot be clicked.|

## Events
The [universal events](ts-universal-events-click.md) are supported.

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
  @State value: number = 0

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
