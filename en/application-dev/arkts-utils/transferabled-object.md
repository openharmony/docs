# Transferable Object (NativeBinding Object)


A Transferable object (also called NativeBinding object) is a JS object that is bound to a C++ object and provides main functions by C++. During cross-thread transmission, the same C++ object can be directly reused. Compared with the JS object copy mode, the transmission efficiency is higher. Therefore, NativeBinding objects that can be shared or transferred are also called Transferable objects.


## Sharing Mode

If the C++ implementation can ensure thread security, the C++ part of the NativeBinding object can support shared transmission. In this case, after the NativeBinding object is transferred across threads, you only need to create a JS shell again to bridge the object to the same C++ object. The following figure shows the communication process.


![nativeBinding](figures/nativeBinding.png)


A common shared NativeBinding object includes a context, and the context object includes context information of an application component. The context object provides a manner of accessing a system service and a resource, so that the application component can interact with the system. For details about how to obtain context information, see [Context (Stage Model)](../application-models/application-context-stage.md).

For details, see [Using TaskPool for Frequent Database Operations](./batch-database-operations-guide.md#using-taskpool-for-frequent-database-operations).


## Transfer Mode

If the C++ implementation contains data and thread security cannot be ensured, the C++ part of the NativeBinding object needs to be transferred in transfer mode. In this case, after the NativeBinding object is transferred across threads, you only need to create a JS shell again to bridge the object to the C++ object. However, the binding relationship of the original object needs to be removed. The following figure shows the communication process.

![nativeBinding_transfer](figures/nativeBinding_transfer.png)

Common NativeBinding objects include PixelMap. The [PixelMap object](../reference/apis-image-kit/js-apis-image.md#imagecreatepixelmap8) can be used to read or write image data and obtain image information. It is usually used to display images in applications or systems.

### Samples

An example of passing a PixelMap object across threads is provided to help you better understand. Obtain the image resources in the rawfile folder, create a PixelMap object in the subthread, and transfer the object to the main thread. The implementation is as follows:

```ts
// Index.ets
import { taskpool } from '@kit.ArkTS';
import { loadPixelMap } from './pixelMapTest';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  @State pixelMap: PixelMap | undefined = undefined;

  private loadImageFromThread(): void {
    const resourceMgr = getContext(this).resourceManager;
    // startIcon.png is copied from the media directory to the rawfile folder. You need to replace it. Otherwise, the image source fails to be created and subsequent operations cannot be performed.
    resourceMgr.getRawFd('startIcon.png').then(rawFileDescriptor => {
      taskpool.execute(loadPixelMap, rawFileDescriptor).then(pixelMap => {
        if (pixelMap) {
          this.pixelMap = pixelMap as PixelMap;
          console.log('Succeeded in creating pixelMap.');
          // The main thread releases the pixelMap. Because setTransferDetached has been called when the child thread returns pixelMap, the pixelMap can be released immediately.
          this.pixelMap.release();
        } else {
          console.error('Failed to create pixelMap.');
        }
      }).catch((e: BusinessError) => {
        console.error('taskpool execute loadPixelMap failed. Code: ' + e.code + ', message: ' + e.message);
      });
    });
  }

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: 'container', align: VerticalAlign.Center },
          middle: { anchor: 'container', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          this.loadImageFromThread();
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

```ts
// pixelMapTest.ets
import { image } from '@kit.ImageKit';

@Concurrent
export async function loadPixelMap(rawFileDescriptor: number): Promise<PixelMap> {
  // Create an ImageSource instance.
  const imageSource = image.createImageSource(rawFileDescriptor);
  // Create a pixelMap.
  const pixelMap = imageSource.createPixelMapSync();
  // Release the ImageSource instance.
  imageSource.release();
  // Disconnect the reference of the original thread after the cross-thread transfer of the pixelMap is complete.
  pixelMap.setTransferDetached(true);
  // Return the pixelMap to the main thread.
  return pixelMap;
}
```
