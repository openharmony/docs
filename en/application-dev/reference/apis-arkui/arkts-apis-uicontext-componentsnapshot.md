# Class (ComponentSnapshot)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->
Provides APIs for obtaining component snapshots, including snapshots of components that have been loaded and snapshots of components that have not been loaded yet.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - In the following API examples, you must first use [getComponentSnapshot()](./arkts-apis-uicontext-uicontext.md#getcomponentsnapshot12) in **UIContext** to obtain a **ComponentSnapshot** instance, and then call the APIs using the obtained instance.
>
> - Transformation properties such as scaling, translation, and rotation only apply to the child components of the target component. Applying these transformation properties directly to the target component itself has no effect; the snapshot will still display the component as it appears before any transformations are applied.

## get<sup>12+</sup>

get(id: string, callback: AsyncCallback<image.PixelMap>, options?: componentSnapshot.SnapshotOptions): void

Obtains the snapshot of a component that has been loaded. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| id       | string                                                       | Yes  | [ID](arkui-ts/ts-universal-attributes-component-id.md) of the target component.<br>Note: Off-screen or cached components not mounted in the component tree are not supported.|
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes  | Callback used to return the result.                                        |
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | No   | Custom settings of the snapshot.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();
  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.img')).autoResize(true).width(150).height(150).margin(5).id("root")
      }
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().get("root", (error: Error, pixmap: image.PixelMap) => {
            if (error) {
              console.error("error: " + JSON.stringify(error));
              return;
            }
            this.pixmap = pixmap;
          }, { scale: 2, waitUntilRenderFinished: true });
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## get<sup>12+</sup>

get(id: string, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

Obtains the snapshot of a component that has been loaded. This API uses a promise to return the result.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| id     | string | Yes  | [ID](arkui-ts/ts-universal-attributes-component-id.md) of the target component.<br>Note: Off-screen or cached components not mounted in the component tree are not supported.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | No   | Custom settings of the snapshot.|

**Return value**

| Type                                                        | Description            |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(150).height(150).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.icon')).autoResize(true).width(150).height(150).margin(5).id("root")
      }
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .get("root", { scale: 2, waitUntilRenderFinished: true })
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap;
            })
            .catch((err: Error) => {
              console.error("error: " + err);
            })
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder, callback: AsyncCallback<image.PixelMap>, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): void

Captures a snapshot of an offscreen-rendered component created from a [CustomBuilder](arkui-ts/ts-types.md#custombuilder8). This API uses a callback to return the result.
> **NOTE**
>
> Due to the need to wait for the component to be built and rendered, there is a delay of not more than 500 ms in the callback for off-screen snapshot capturing. Therefore, this API is not recommended for performance-sensitive scenarios.
>
> If a component is on a time-consuming task, for example, an [Image](arkui-ts/ts-basic-components-image.md) or [Web](../apis-arkweb/arkts-basic-components-web.md) component that is loading online images, its loading may be still in progress when this API is called. In this case, the output snapshot does not represent the component in the way it looks when the loading is successfully completed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| builder  | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8)         | Yes  | Builder of the custom component.<br>Note: The global builder is not supported.<br>If the root component of the builder has a width or height of zero, the snapshot operation will fail with error code 100001.     |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes  | Callback used to return the result. The coordinates and size of the offscreen component's drawing area can be obtained through the callback.|
| delay   | number | No   | Delay time for triggering the screenshot command. When the layout includes an image component, it is necessary to set a delay time to allow the system to decode the image resources. The decoding time is subject to the resource size. In light of this, whenever possible, use pixel map resources that do not require decoding.<br> When pixel map resources are used or when **syncload** to **true** for the **Image** component, you can set **delay** to **0** to forcibly capture snapshots without waiting. This delay time does not refer to the time from the API call to the return: As the system needs to temporarily construct the passed-in **builder** offscreen, the return time is usually longer than this delay.<br>Note: In the **builder** passed in, state variables should not be used to control the construction of child components. If they are used, they should not change when the API is called, so as to avoid unexpected snapshot results.<br> Default value: **300**<br> Unit: ms<br> Value range: [0, +∞). If the value is less than 0, the default value is used.|
| checkImageStatus  | boolean | No   | Whether to verify the image decoding status before taking a snapshot. If the value is **true**, the system checks whether all **Image** components have been decoded before taking the snapshot. If the check is not completed, the system aborts the snapshot and returns an exception.<br>Default value: **false**.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12) | No   | Custom settings of the snapshot.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();
  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }

  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot().createFromBuilder(() => {
            this.RandomBuilder()
          },
            (error: Error, pixmap: image.PixelMap) => {
              if (error) {
                console.error("error: " + JSON.stringify(error));
                return;
              }
              this.pixmap = pixmap;
            }, 320, true, { scale: 2, waitUntilRenderFinished: true });
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```

## createFromBuilder<sup>12+</sup>

createFromBuilder(builder: CustomBuilder, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

Captures a snapshot of an offscreen-rendered component created from a [CustomBuilder](arkui-ts/ts-types.md#custombuilder8). This API uses a callback to return the result.

> **NOTE**
>
> Due to the need to wait for the component to be built and rendered, there is a delay of not more than 500 ms in the callback for off-screen snapshot capturing. Therefore, this API is not recommended for performance-sensitive scenarios.
>
> If a component is on a time-consuming task, for example, an [Image](arkui-ts/ts-basic-components-image.md) or [Web](../apis-arkweb/arkts-basic-components-web.md) component that is loading online images, its loading may be still in progress when this API is called. In this case, the output snapshot does not represent the component in the way it looks when the loading is successfully completed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                | Mandatory| Description                                                   |
| ------- | ---------------------------------------------------- | ---- | ------------------------------------------------------- |
| builder | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) | Yes  | Builder of the custom component.<br>Note: The global builder is not supported.<br>If the root component of the builder has a width or height of zero, the snapshot operation will fail with error code 100001.|
| delay   | number | No   | Delay time for triggering the screenshot command. When the layout includes an image component, it is necessary to set a delay time to allow the system to decode the image resources. The decoding time is subject to the resource size. In light of this, whenever possible, use pixel map resources that do not require decoding.<br> When pixel map resources are used or when **syncload** to **true** for the **Image** component, you can set **delay** to **0** to forcibly capture snapshots without waiting. This delay time does not refer to the time from the API call to the return: As the system needs to temporarily construct the passed-in **builder** offscreen, the return time is usually longer than this delay.<br>Note: In the **builder** passed in, state variables should not be used to control the construction of child components. If they are used, they should not change when the API is called, so as to avoid unexpected snapshot results.<br> Default value: **300**<br> Unit: ms<br> Value range: [0, +∞). If the value is less than 0, the default value is used.|
| checkImageStatus  | boolean | No   | Whether to verify the image decoding status before taking a snapshot. If the value is **true**, the system checks whether all **Image** components have been decoded before taking the snapshot. If the check is not completed, the system aborts the snapshot and returns an exception.<br>Default value: **false**.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)           | No   | Custom settings of the snapshot.|

**Return value**

| Type                                                        | Description            |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct ComponentSnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;
  uiContext: UIContext = this.getUIContext();
  @Builder
  RandomBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }
    .width(100)
    .id("builder")
  }
  build() {
    Column() {
      Button("click to generate UI snapshot")
        .onClick(() => {
          this.uiContext.getComponentSnapshot()
            .createFromBuilder(() => {
              this.RandomBuilder()
            }, 320, true, { scale: 2, waitUntilRenderFinished: true })
            .then((pixmap: image.PixelMap) => {
              this.pixmap = pixmap;
            })
            .catch((err: Error) => {
              console.error("error: " + err);
            })
        })
      Image(this.pixmap)
        .margin(10)
        .height(200)
        .width(200)
        .border({ color: Color.Black, width: 2 })
    }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
  }
}
```

## getSync<sup>12+</sup>

getSync(id: string, options?: componentSnapshot.SnapshotOptions): image.PixelMap

Obtains the snapshot of a component that has been loaded. This API synchronously waits for the snapshot to complete and returns a [PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) object.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| id   | string | Yes   | [ID](arkui-ts/ts-universal-attributes-component-id.md) of the target component.<br>Note: Off-screen or cached components not mounted in the component tree are not supported.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | No   | Custom settings of the snapshot.|

**Return value**

| Type                           | Description      |
| ----------------------------- | -------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID | Error Message               |
| ------ | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001 | Invalid ID. |
| 160002 | Timeout. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

@Entry
@Component
struct SnapshotExample {
  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        Image($r('app.media.img')).autoResize(true).width(200).height(200).margin(5).id("root")
      }
      Button("click to generate UI snapshot")
        .onClick(() => {
          try {
            let pixelmap = this.getUIContext().getComponentSnapshot().getSync("root", { scale: 2, waitUntilRenderFinished: true });
            this.pixmap = pixelmap;
          } catch (error) {
            console.error("getSync errorCode: " + error.code + " message: " + error.message);
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## getWithUniqueId<sup>15+</sup>

getWithUniqueId(uniqueId: number, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

Obtains the snapshot of a component that has been loaded based on the provided [uniqueId](js-apis-arkui-frameNode.md#getuniqueid12). This API uses a promise to return the result.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| uniqueId   | number | Yes   | [Unique ID](js-apis-arkui-frameNode.md#getuniqueid12) of the target component.<br>Note: Off-screen or cached components not mounted in the component tree are not supported.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | No   | Custom settings of the snapshot.|

**Return value**

| Type                                                        | Description            |
| ------------------------------------------------------------ | ---------------- |
| Promise&lt;image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Invalid ID.                                                  |

**Example**

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public node: FrameNode | null = null;

  public imageNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.node = new FrameNode(uiContext);
    this.node.commonAttribute.width('100%').height('100%');

    let image = typeNode.createNode(uiContext, 'Image');
    image.initialize($r('app.media.img')).width('100%').height('100%').autoResize(true);
    this.imageNode = image;

    this.node.appendChild(image);
    return this.node;
  }
}

@Entry
@Component
struct SnapshotExample {
  private myNodeController: MyNodeController = new MyNodeController();

  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        NodeContainer(this.myNodeController).width(200).height(200).margin(5)
      }
      Button("UniqueId get snapshot")
        .onClick(() => {
          try {
            this.getUIContext()
              .getComponentSnapshot()
              .getWithUniqueId(this.myNodeController.imageNode?.getUniqueId(), { scale: 2, waitUntilRenderFinished: true })
              .then((pixmap: image.PixelMap) => {
                this.pixmap = pixmap;
              })
              .catch((err: Error) => {
                console.log("error: " + err);
              })
          } catch (error) {
            console.error("UniqueId get snapshot Error: " + JSON.stringify(error));
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## getSyncWithUniqueId<sup>15+</sup>

getSyncWithUniqueId(uniqueId: number, options?: componentSnapshot.SnapshotOptions): image.PixelMap

Obtains the snapshot of a component that has been loaded based on the provided [uniqueId](js-apis-arkui-frameNode.md#getuniqueid12). This API synchronously waits for the snapshot to complete and returns a [PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) object.

> **NOTE**
>
> The snapshot captures content rendered in the last frame. If this API is called when the component triggers an update, the re-rendered content will not be included in the obtained snapshot.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory  | Description                                      |
| ---- | ------ | ---- | ---------------------------------------- |
| uniqueId   | number | Yes   | [Unique ID](js-apis-arkui-frameNode.md#getuniqueid12) of the target component.<br>Note: Off-screen or cached components not mounted in the component tree are not supported.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12)            | No   | Custom settings of the snapshot.|

**Return value**

| Type                           | Description      |
| ----------------------------- | -------- |
| image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID | Error Message               |
| ------ | ------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001 | Invalid ID. |
| 160002 | Timeout. |

**Example**

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { UIContext } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public node: FrameNode | null = null;

  public imageNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.node = new FrameNode(uiContext);
    this.node.commonAttribute.width('100%').height('100%');

    let image = typeNode.createNode(uiContext, 'Image');
    image.initialize($r('app.media.img')).width('100%').height('100%').autoResize(true);
    this.imageNode = image;

    this.node.appendChild(image);
    return this.node;
  }
}

@Entry
@Component
struct SnapshotExample {
  private myNodeController: MyNodeController = new MyNodeController();

  @State pixmap: image.PixelMap | undefined = undefined;

  build() {
    Column() {
      Row() {
        Image(this.pixmap).width(200).height(200).border({ color: Color.Black, width: 2 }).margin(5)
        NodeContainer(this.myNodeController).width(200).height(200).margin(5)
      }
      Button("UniqueId getSync snapshot")
        .onClick(() => {
          try {
            this.pixmap = this.getUIContext()
              .getComponentSnapshot()
              .getSyncWithUniqueId(this.myNodeController.imageNode?.getUniqueId(), { scale: 2, waitUntilRenderFinished: true });
          } catch (error) {
            console.error("UniqueId getSync snapshot Error: " + JSON.stringify(error));
          }
        }).margin(10)
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
  }
}
```

## createFromComponent<sup>18+</sup>

createFromComponent\<T extends Object>(content: ComponentContent\<T>, delay?: number, checkImageStatus?: boolean, options?: componentSnapshot.SnapshotOptions): Promise<image.PixelMap>

Takes a snapshot of the provided **content** object. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| content  | [ComponentContent\<T>](./js-apis-arkui-ComponentContent.md)         | Yes  | Component content to be captured. This is the content currently displayed in the **UIContext**.     |
| delay   | number | No   | Delay time for triggering the screenshot command. When the layout includes an image component, it is necessary to set a delay time to allow the system to decode the image resources. The decoding time is subject to the resource size. In light of this, whenever possible, use pixel map resources that do not require decoding.<br> When pixel map resources are used or when **syncload** to **true** for the **Image** component, you can set **delay** to **0** to forcibly capture snapshots without waiting. This delay time does not refer to the time from the API call to the return: As the system needs to temporarily construct the passed-in **builder** offscreen, the return time is usually longer than this delay.<br>Note: In the **builder** passed in, state variables should not be used to control the construction of child components. If they are used, they should not change when the API is called, so as to avoid unexpected snapshot results.<br> Value range: [0, +∞). If the value is less than 0, the default value is used.<br>Default value: **300**<br> Unit: ms|
| checkImageStatus  | boolean | No   | Whether to verify the image decoding status before taking a snapshot. If the value is **true**, the system checks whether all **Image** components have been decoded before taking the snapshot. If the check is not completed, the system aborts the snapshot and returns an exception.<br>Default value: **false**.|
| options       | [componentSnapshot.SnapshotOptions](js-apis-arkui-componentSnapshot.md#snapshotoptions12) | No   | Custom settings of the snapshot. You can specify the scale ratio for the pixelmap during rendering and whether to force the system to complete all rendering commands before taking the snapshot.|

**Return value**

| Type                           | Description      |
| ----------------------------- | -------- |
| Promise<image.[PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)>  | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Snapshot Error Codes](errorcode-snapshot.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | The builder is not a valid build function.                   |
| 160001   | An image component in builder is not ready for taking a snapshot. The check for the ready state is required when the checkImageStatus option is enabled. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { ComponentContent } from '@kit.ArkUI';

class Params {
  text: string | undefined | null  = "";

  constructor(text: string | undefined | null ) {
    this.text = text;
  }
}

@Builder
function buildText(params: Params) {
  ReusableChildComponent({ text: params.text })
}

@Component
struct ReusableChildComponent {
  @Prop text: string | undefined | null  = "";

  aboutToReuse(params: Record<string, object>) {
    console.log("ReusableChildComponent Reusable " + JSON.stringify(params));
  }

  aboutToRecycle(): void {
    console.log("ReusableChildComponent aboutToRecycle " + this.text);
  }

  build() {
    Column() {
      Text(this.text)
        .fontSize(90)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 36 })
        .width('100%')
        .height('100%')
    }.backgroundColor('#FFF0F0F0')
  }
}

@Entry
@Component
struct Index {
  @State pixmap: image.PixelMap | undefined = undefined;
  @State message: string | undefined | null = "hello";
  uiContext: UIContext = this.getUIContext();

  build() {
    Row() {
      Column() {
        Button("Create Component Snapshot")
          .onClick(() => {
            let uiContext = this.getUIContext();
            let contentNode = new ComponentContent(uiContext, wrapBuilder(buildText), new Params(this.message));
            this.uiContext.getComponentSnapshot()
              .createFromComponent(contentNode
                , 320, true, { scale: 2, waitUntilRenderFinished: true })
              .then((pixmap: image.PixelMap) => {
                this.pixmap = pixmap;
              })
              .catch((err: Error) => {
                console.error("error: " + err);
              })
          })
        Image(this.pixmap)
          .margin(10)
          .height(200)
          .width(200)
          .border({ color: Color.Black, width: 2 })
      }.width('100%').margin({ left: 10, top: 5, bottom: 5 }).height(300)
    }
    .width('100%')
    .height('100%')
  }
}
```
