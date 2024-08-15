# @ohos.multimedia.media (media service) (system interface)
The media subsystem provides a set of simple and easy-to-understand interfaces for developers to access the system and use the media resources of the system.

> **NOTICE:**
>
> - The first batch of interfaces of this module are supported since API version 6. For new interfaces in later versions, the start version of the interfaces is marked with the upper corner.
> - The current page contains only the system interface of this module. For other public interfaces, see

## Importing a module

```ts
import {media} from '@kit.MediaKit';
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(callback: AsyncCallback\<VideoRecorder>): void

Create a video recording instance in asynchronous mode. Obtain the return value by registering a callback function.
Only one recording instance can be created for a device.

**System capability:** SystemCapability.Multimedia.Media.VideoRecorder

**System interface:** This interface is a system interface.

**Parameters:**

| Parameter name | Type | Mandatory | Description |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback| is a | callback function. The VideoRecorder instance is returned asynchronously. If the operation fails, null is returned. Can be used to record video media.|

**Error code:**

For details about the following error codes, see

| Error code ID | Error information |
| -------- | ------------------------------ |
| 5400101 | No memory. Return by callback. |

**Example:** 

```ts
import {BusinessError} from '@kit.BasicServicesKit';

let videoRecorder: media.VideoRecorder;
media.createVideoRecorder((error: BusinessError, video: media.VideoRecorder) => {
  if (video != null) {
    videoRecorder = video;
    console.info('video createVideoRecorder success');
  } else {
    console.error(`video createVideoRecorder fail, error message:${error.message}`);
  }
});
```