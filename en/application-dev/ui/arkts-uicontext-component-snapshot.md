# Using Component Snapshot (ComponentSnapshot)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=420a0e345618a384b19f5eff841d06e4f6f03cfe translatedAt=2026-08-04T06:39:49.760Z pushedAt=2026-08-04T08:39:59.624Z -->

## Overview

Component snapshot is the capability to generate a pixel map ([PixelMap](../reference/apis-image-kit/arkts-apis-image-PixelMap.md)) from the rendering result of a component node tree within an application. It supports two approaches:<br>Taking a snapshot of a component that is already attached to the UI tree<br>Taking a snapshot of an offline component implemented using **Builder** or **ComponentContent**.

> **NOTE**
>
> Component snapshot relies on UI context and must be called in an environment with a clear context. Therefore, preferably use the [ComponentSnapshot](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md) object returned by the **getComponentSnapshot** API of **UIContext**. Avoid using the **componentSnapshot** API imported directly from @kit.ArkUI.

### Taking a Snapshot of a Component Attached to the UI Tree

To take a snapshot of a component that is already attached to the UI tree, use [get](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#get12-1) or [getSync](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#getsync12). Pass the component ID (configured in advance using the **.id** universal attribute) to specify the component root node. The system only traverses components attached to the tree when searching for the component to take a snapshot; it does not search cached or off-screen components. The system uses the first found result, so the application must ensure the uniqueness of component IDs.

Starting from API version 15, if you already know the ID of the component (obtained via [getUniqueId](../reference/apis-arkui/js-apis-arkui-frameNode.md#getuniqueid12)), you can also use [getWithUniqueId](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#getwithuniqueid15) or [getSyncWithUniqueId](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#getsyncwithuniqueid15) to take a snapshot of the component directly, skipping the component search process.

The snapshot captures only the most recent frame. If you trigger a component update and immediately take a snapshot, the updated content will not be captured; the snapshot will return the previous frame's content.

> **NOTE**
>
> Avoid triggering updates of the component being snapped to prevent interference with the snapshot content.

### Taking a Snapshot of an Offline Component

Offline components are components that are encapsulated using **Builder** or **ComponentContent** but have not yet been attached to the tree. To take snapshots of them, use [createFromBuilder](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#createfrombuilder12-1). Since API version 18, you can also use [createFromComponent](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#createfromcomponent18) to take snapshots of offline components.

Since offline components do not participate in actual rendering, taking snapshots of them takes longer because the system must first perform offline construction, layout, and resource loading. Snapshots taken before these operations complete may return unexpected results. Therefore, it is usually necessary to set a sufficient delay to ensure the system completes these operations. For image resources, set the [syncLoad](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#syncload8) attribute of the **Image** component to **true** to force synchronous loading. This ensures images are loaded, downloaded, and decoded during offline component construction, allowing the image pixels to be correctly displayed during the snapshot process.

## Use Cases

The following use cases illustrate common usage methods of the component snapshot capability.

### Capturing Long Content (Scrolling Snapshot)

Long content is usually implemented using scrollable container components. When you take a snapshot, only the visible content within the container is captured, and content beyond the boundary is not included. If [LazyForEach](../reference/apis-arkui/arkui-ts/ts-rendering-control-lazyforeach.md) or [Repeat](../reference/apis-arkui/arkui-ts/ts-rendering-control-repeat.md) is used, content that exceeds the display range will not be built or captured by the system.

You can use scrollable container APIs to simulate user swiping for page-by-page snapshots, then stitch the **PixelMap** objects of each page by offset to generate a complete long image. The key points are simulating swiping, maintaining the relationship between displacement and pixel maps, and implementing **PixelMap** read and write operations.

**Step 1: Add a scroll controller and event listener.**

To simulate scrolling and listen to the specific [offset](../reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#offset) of component scrolling, you need to add a scroll controller and scroll listener to the [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) component (using the list as an example).

<!-- @[scroll_snapshot](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/ScrollSnapshot.ets) -->

``` TypeScript
// src/main/ets/view/ScrollSnapshot.ets
@Component
export struct ScrollSnapshot {
  private scroller: Scroller = new Scroller();
  private listComponentWidth: number = 0; // Component width. The default value is 0.
  private listComponentHeight: number = 0; // Component height. The default value is 0.
  // Current offset of the List component
  private curYOffset: number = 0;
  // Scroll distance per step
  private scrollHeight: number = 0;

  // ...
  build() {
    // ...
        Stack() {
          // ...
          // 1.1 Bind the scroll controller and configure a unique component ID using .id.
          List({ space: 12, scroller: this.scroller }) {
              LazyForEach(this.dataSource, (item: number) => {
              ListItem() {
                NewsItem({ index: item })
              }
            }, (item: number) => item.toString())
          }
          // ...
          .id(LIST_ID)
          // 1.2 Obtain the scroll offset through a callback.
          .onDidScroll(() => {
            this.curYOffset = this.scroller.currentOffset().yOffset;
          })
          .onAreaChange((oldValue, newValue) => {
            // 1.3 Obtain the width and height of the component.
            this.listComponentWidth = newValue.width as number;
            this.listComponentHeight = newValue.height as number;
            this.scrollHeight = this.listComponentHeight;
          })
          // ...
    }
  }
}
```

**Step 2: Implement recursive scrolling snapshot and caching.**

Implement a recursive method to scroll and snapshot in a loop, combined with animation effects during scrolling.

<!-- @[scroll_snapand_merge](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/ScrollSnapshot.ets) -->

``` TypeScript
/**
 * Recursively scroll, take snapshots, and merge all snapshots when scrolling ends.
 */
async scrollSnapAndMerge() {
  try {
    // Record the scroll offset.
    this.scrollYOffsets.push(this.curYOffset - this.yOffsetBefore);
    // Call the component snapshot API to obtain the List component's snapshot.
    const pixelMap = await this.getUIContext().getComponentSnapshot().get(LIST_ID);
    // Obtain the pixel bytes of the pixel map and save them in an array.
    let area: image.PositionArea =
      await ImageUtils.getSnapshotArea(pixelMap, this.scrollYOffsets, this.listComponentWidth,
        this.listComponentHeight)
    this.areaArray.push(area);

    // Check whether scrolling has reached the end and if the user has forced a stop.
    if (!this.scroller.isAtEnd() && !this.isClickStop) {
      // If scrolling is not at the end or stopped, play a scroll animation, wait for a period, then continue recursive snapshot taking.
      CommonUtils.scrollAnimation(this.scroller, 1000, this.scrollHeight);
      await CommonUtils.sleep(1500);
      await this.scrollSnapAndMerge();
    } else {
      // When scrolling ends, call mergeImage to stitch all saved pixel map data and return the long snapshot pixel map object.
      this.mergedImage =
        await ImageUtils.mergeImage(this.areaArray, this.scrollYOffsets[this.scrollYOffsets.length - 1],
          this.listComponentWidth, this.listComponentHeight);
    }
  } catch (err) {
    let error = err as BusinessError;
    Logger.error(TAG, `scrollSnapAndMerge err, errCode: ${error.code}, error message: ${error.message}`);
  }
}
```

<!-- @[scroll_animation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/common/CommonUtils.ets) -->

``` TypeScript
// src/main/ets/common/CommonUtils.ets
static scrollAnimation(scroller: Scroller, duration: number, scrollHeight: number): void {
  scroller.scrollTo({
    xOffset: 0,
    yOffset: (scroller.currentOffset().yOffset + scrollHeight),
    animation: {
      duration: duration,
      curve: Curve.Smooth,
      canOverScroll: false
    }
  });
}
```

**Step 3: Stitch the long snapshot.**

Use the image.[createPixelMapSync](../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createpixelmapsync12)() method to create a long screenshot **longPixelMap**, traverse the previously saved image segment data (**this.areaArray**), construct the **image.PositionArea** object **area**, and call the longPixelMap.[writePixelsSync](../reference/apis-image-kit/arkts-apis-image-PixelMap.md#writepixelssync12)(area) method to write these segments one by one to the correct positions to stitch a complete long screenshot.

<!-- @[merge_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/common/ImageUtils.ets) -->

``` TypeScript
static async mergeImage(areaArray: image.PositionArea[], lastOffsetY: number, listWidth: number,
  listHeight: number): Promise<PixelMap> {
  // Create a long snapshot pixel map object.
  let opts: image.InitializationOptions = {
    editable: true,
    pixelFormat: 4,
    size: {
      width: uiContext?.vp2px(listWidth) || 0,
      height: uiContext?.vp2px(lastOffsetY + listHeight) || 0
    }
  };
  let longPixelMap = image.createPixelMapSync(opts);
  let imgPosition: number = 0;

  for (let i = 0; i < areaArray.length; i++) {
    let readArea = areaArray[i];
    let area: image.PositionArea = {
      pixels: readArea.pixels,
      offset: 0,
      stride: readArea.stride,
      region: {
        size: {
          width: readArea.region.size.width,
          height: readArea.region.size.height
        },
        x: 0,
        y: imgPosition
      }
    }
    imgPosition += readArea.region.size.height;
    try {
      longPixelMap.writePixelsSync(area);
    } catch (err) {
      let error = err as BusinessError;
      Logger.error(TAG, `writePixelsSync err, code: ${error.code}, message: ${error.message}`);
    }
  }
  return longPixelMap;
}
```

**Step 4: Save the snapshot.**

Use the security component [SaveButton](../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md) to save the screenshot to the album.

<!-- @[save_button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/SnapshotPreview.ets) -->

``` TypeScript
// src/main/ets/view/SnapshotPreview.ets
SaveButton({
  icon: SaveIconStyle.FULL_FILLED,
  text: SaveDescription.SAVE_IMAGE,
  buttonType: ButtonType.Capsule
})
  // ···
  .onClick((event, result) => {
    this.saveSnapshot(result);
  })
```

<!-- @[save_snapshot1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/SnapshotPreview.ets) -->

``` TypeScript
async saveSnapshot(result: SaveButtonOnClickResult): Promise<void> {
  try {
    if (result === SaveButtonOnClickResult.SUCCESS) {
      const helper = photoAccessHelper.getPhotoAccessHelper(this.context);
      const uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'png');
      const file = await fileIo.open(uri, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
      try {
        const imagePackerApi: image.ImagePacker = image.createImagePacker();
        const packOpts: image.PackingOption = {
          format: 'image/png',
          quality: 100,
        };
        const data = await imagePackerApi.packToData(this.mergedImage, packOpts);
        fileIo.writeSync(file.fd, data);
        Logger.info(TAG, `Succeeded in packToFile`);
        this.getUIContext().getPromptAction().showToast({
          // Replace $r('app.string.save_album_success') with the actual resource file. In this example, the value in the resource file is "Saved to album."
          message: $r('app.string.save_album_success'),
          duration: 1800
        })
      } catch (error) {
        let businessError = error as BusinessError;
        Logger.error(TAG,
          `Failed to packToFile. Error code is ${businessError.code}, message is ${businessError.message}`);
      } finally {
        try {
          fileIo.closeSync(file.fd);
        } catch (err) {
          let error = err as BusinessError;
          Logger.error(TAG, `Failed to close file. Error code is ${error.code}, message is ${error.message}`);
        }
      }
    }
    // ...
  } catch (err) {
    let error = err as BusinessError;
    Logger.error(TAG, `saveSnapshot err, errCode: ${error.code}, error message: ${error.message}`);
  }
}
```

**Step 5: Release the pixel map after saving.**

When the **PixelMap** object is no longer in use, assign it to **undefined** in a timely manner, as in **this.mergedImage = undefined;**.

<!-- @[close_and_clean_snapshot](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/SnapshotPreview.ets) -->

``` TypeScript
closeSnapPopup(): void {
  // Close the popup.
  this.isShowPreview = false;
  // Release the pixel map object.
  this.mergedImage = undefined;
  // Reset related parameters.
  this.snapPopupWidth = 100;
  this.snapPopupHeight = 200;
  this.snapPopupPosition =
    PopupUtils.calcPopupCenter(this.screenWidth, this.screenHeight, this.snapPopupWidth, this.snapPopupHeight);
  this.isLargePreview = false;
}
```

### Encapsulating a Global Screenshot API

As mentioned earlier, snapshot APIs must be used where the UI context is clear. However, applications sometimes need to encapsulate a unified global snapshot API for different modules. For example, in the following example, the component built by **awardBuilder** has a fixed structure. **GlobalStaticSnapshot** provides a global method **getAwardSnapshot** that meets the needs of different modules to take snapshots of components in the same fixed mode, achieving the encapsulation of a global snapshot API. This functionality is supported since API version 18.

<!-- @[global_snapshot](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ComponentSnapshot/entry/src/main/ets/view/GlobalScreenshot.ets) -->

``` TypeScript
import { image } from '@kit.ImageKit';
import { ComponentContent } from '@kit.ArkUI';

export class Params {
  public text: string | undefined | null = '';

  constructor(text: string | undefined | null) {
    this.text = text;
  }
}

@Builder
function awardBuilder(params: Params) {
  Column() {
    Text(params.text)
      .fontSize(90)
      .fontWeight(FontWeight.Bold)
      .margin({ bottom: 36 })
      .width('100%')
      .height('100%')
  }.backgroundColor('#FFF0F0F0')
}

export class GlobalStaticSnapshot {
  /**
   * A static method to obtain a snapshot of a fixed object.
   */
  static async getAwardSnapshot(uiContext: UIContext, textParam: Params): Promise<image.PixelMap | undefined> {
    let resultPixmap: image.PixelMap | undefined = undefined
    let contentNode = new ComponentContent(uiContext, wrapBuilder(awardBuilder), textParam);
    await uiContext.getComponentSnapshot()
      .createFromComponent(contentNode, 320, true, { scale: 1, waitUntilRenderFinished: true })
      .then((pixmap: image.PixelMap) => {
        resultPixmap = pixmap;
      })
      .catch((err: Error) => {
        console.error(`error: ${err}`);
      })
    return resultPixmap;
  }
}
```

**Example**

See [Long Screenshot](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-long-snapshot-practice#section1566681910427).

## Best Practices for Component Screenshot

### Reasonably Controlling Snapshot Timing

When implementing snapshot functionality, note that the component rendering process is not completed in one go. When building and displaying components, the system goes through complex steps, such as measurement, layout, and command submission, before finally presenting them on the screen during a hardware refresh. Therefore, in specific scenarios, if the snapshot API is called immediately after component refresh, it may fail to capture the expected content or result in snapshot failure errors.

To ensure accurate snapshot results, it is recommended that you execute the snapshot operation after the component is fully rendered.

**Understanding the Component Drawing Status**

To ensure the snapshot content meets expectations, you should understand when the code modifies the UI state and allow time for the system to process it, which can usually be achieved by adding a delay.

Although you can use [ComponentObserver](../reference/apis-arkui/js-apis-arkui-inspector.md#componentobserver) in the Inspector to perceive component drawing (**draw**) and display notifications, note that the component drawing notification from **ComponentObserver** does not mean the system has actually executed the drawing commands, as this depends on the load of the graphics system service.

**Waiting for Drawing to Complete**

The main factor affecting the snapshot expectation is the time difference between the snapshot timing and the system service executing the drawing commands. When a snapshot call is initiated, all previously submitted drawing commands on the application side may not have been truly executed by the graphics service. To address this, you can specify **waitUntilRenderFinished** as **true** in the [SnapshotOptions](../reference/apis-arkui/js-apis-arkui-componentSnapshot.md#snapshotoptions12) parameter to ensure the system waits for all previous drawing commands to complete before executing the snapshot request, thereby capturing more complete content.

> **NOTE**
>
> It is recommended that the **waitUntilRenderFinished** parameter be always set to **true**.

**Understanding the Impact of Resource Loading on Snapshot**

Another common reason for unexpected snapshots is image resource loading. Image components support both online resource links and local resources, and most image resources are in compressed formats such as PNG and JPEG. These resources need to be decoded by the system into a pixel map format that can be submitted for drawing, a process that occurs on an asynchronous I/O thread by default. This can lead to unexpected snapshot behavior due to the uncertainty of the process duration.

The following optimization approaches can be taken:

1. Pre-parse images into PixelMap format and configure the PixelMap for the image component. This approach is recommended for optimization.

2. Set the [syncLoad](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#syncload8) attribute of the image component to **true** to force synchronous loading. This ensures that resources can be directly submitted when the component is built.

3. Specify the delay duration and set **checkImageStatus** to **true** to attempt to take a snapshot. If error 160001 is returned, retry with an increased delay.

### Timely Saving and Releasing Pixel Map Objects

To release resources promptly, assign the **PixelMap** object returned by the snapshot API to null when it is no longer in use.

### Appropriately Controlling Sampling Precision

Avoid capturing images that are excessively large, ideally not larger than the screen size. If the size of the image to capture exceeds device-specific underlying limits, the capture will fail. You can reduce sampling precision by controlling the **scale** parameter in **SnapshotOptions**, which significantly saves memory and improves snapshot efficiency.

### Using Other Capabilities for Self-Rendering Scenarios

Although snapshots can be taken by simply passing a component root node, this is not the recommended way when the child components include [Video](../reference/apis-arkui/arkui-ts/ts-media-components-video.md), [XComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md), or [Web](../reference/apis-arkweb/arkts-basic-components-web.md) components. It is recommended that you use the [image.createPixelMapFromSurface](../reference/apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmapfromsurface11) API.