# Graphics Subsystem Changelog

## cl.blendMode.1 blendMode Changed

**Access Level**

Public API

**Reason for Change**

The API behavior fails to meet the requirements of third-party applications in multiple scenarios.  

**Change Impact**

This change is a non-compatible change.
1. The enumerated values of **blendMode** are changed. Specifically, **NORMAL** is changed to **NONE**, **SOURCE_IN** is changed to **SRC_IN**, and **DESTINATION_IN** is changed to **DST_IN**.
2. The API behavior is changed. Before the change, the API blends the component background with the subnode content. After the change, the API blends the component content (including the subnode content) with the content of the canvas (possibly offscreen canvas).

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.3

**Key API/Component Changes**

The enumerated values and behavior of **blendMode** are changed.

**Adaptation Guide**

1. Change the enumerated values in your code. Specifically, change **NORMAL** to **NONE**, **SOURCE_IN** to **SRC_IN**, and **DESTINATION_IN** to **DST_IN**.
2. The API behavior is changed. Before the change, the API provides two offscreen operations, which are used to the component background and subnode content, respectively. After the change, the API supports only one offscreen operation, which must be triggered by calling **BlendApplyType.OFFSCREEN**. If you want to retain the original behavior, call **BlendApplyType.OFFSCREEN** twice to trigger two offscreen operations to draw the component background and subnode content.<br>
  The sample code is as follows:

  ```ts
  // In the .ets file that uses the new API, you can call BlendApplyType.OFFSCREEN twice to trigger two offscreen operations.
  @Entry
  @Component
  struct Index {
    build() {
      Column() {
        // The second offscreen operation is used to draw the subnode content.
        Text("test")
          .fontSize(144)
          .fontWeight(FontWeight.Bold)
          .fontColor('#ffff0101')
          .blendMode(BlendMode.SRC_IN, BlendApplyType.OFFSCREEN)
      }
     // The first offscreen operation is used to draw the component background.
      .blendMode(BlendMode.SRC_OVER, BlendApplyType.OFFSCREEN)
      .height('100%')
      .width('100%')
      .backgroundColor('#ff08ff00')
    }
  }
  
  // In the .ets file that uses the original API, two offscreen operations are triggered by default.
  @Entry
  @Component
  struct Index {
    build() {
      Column() {
        // The second offscreen operation is used to draw the subnode content.
        Text("test")
          .fontSize(144)
          .fontWeight(FontWeight.Bold)
          .fontColor('#ffff0101')
      }
      // The first offscreen operation is used to draw the component background.
      .blendMode(BlendMode.SRC_IN)
      .height('100%')
      .width('100%')
      .backgroundColor('#ff08ff00')
    }
  }
  ```