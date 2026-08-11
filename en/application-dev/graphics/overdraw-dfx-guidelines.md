# Overdraw Debugging

<!-- md-trans-meta sourceCommit=b6a9d350d597e5a7ebd15d61bba2ace5e5dcfa1c translatedAt=2026-08-03T11:21:23.250Z pushedAt=2026-08-04T07:13:28.746Z -->

When an app page layout is deeply nested, the drawing instructions of some components may be partially or completely covered by those of other components during rendering, resulting in redundant consumption of CPU, GPU, and other computing resources. This situation, where pixels on a screen are drawn multiple times, is called overdraw. You can use the overdraw debugging commands provided by the system to identify the locations and hierarchy of components that cause overdraw, thereby reducing the rendering load of the app.

This topic describes how to use the overdraw debugging feature and how to reduce overdraw.

## Enabling or Disabling Overdraw Debugging

You can use the shell commands to enable or disable the overdraw debugging feature.

- Prerequisites: Developer mode is enabled.

- Enable overdraw debugging.

  ```
  param set debug.graphic.overdraw true
  ```

  ![](figures/overdraw-enable.png)

- Disable overdraw debugging.

  ```
  param set debug.graphic.overdraw false
  ```

  ![](figures/overdraw-disable.png)

- Check whether overdraw debugging is enabled.

  The value **true** means that the feature is enabled, and **false** means the opposite.

  ```
  param get debug.graphic.overdraw
  ```

  ![](figures/overdraw-check.png)

## Analyzing Overdrawn Components

After you enable overdraw debugging and open an application UI, overdrawn pixels are highlighted by boxes with different colors. A deeper color represents a higher level of overdraw. The mapping is as follows:

- Original color: No overdraw.

- Blue-purple: Overdraw occurs once.

- Green: Overdraw occurs twice.

- Light red: Overdraw occurs three times.

- Dark red: Overdraw occurs four times or more.

The following is a sample application with redundant background color nesting.

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Column() {
          Column() {
            Column() {
              Column() {
                Text("Hello World")
              }
              .width('80%')
              .height('80%')
              .backgroundColor(Color.White)
            }
            .width('80%')
            .height('80%')
            .backgroundColor(Color.White)
          }
          .width('80%')
          .height('80%')
          .backgroundColor(Color.White)
        }
        .width('80%')
        .height('80%')
        .backgroundColor(Color.White)
      }
      .width('80%')
    }
    .height('80%')
  }
}
```

![Application UI with overdraw debugging enabled](figures/overdraw-demo-enable.png)

The figure above shows the UI when the overdraw debugging feature is enabled.

From the **Text** component **Hello World**, the **Column** components from inside to outside are displayed in dark red, light red, green, blue-purple, and original color. This indicates that the background of each **Column** component is rendered multiple times as the nesting depth increases.

The system UI (such as the status bar and sidebar) is also displayed in a different color. This is a normal phenomenon.

## Reducing Overdraw

The debugging feature helps you find overdraw problems on the application UI. To reduce overdraw, you are advised to use the following methods:

- Use the visibility control or the if-else statement to reduce redundant components.

- Reduce drawing instructions on components that are completely blocked, such as the background color and component content.

- Use the flattened layout to reduce the nesting depth. For example, combine layout components with similar sizes and functions into one component.