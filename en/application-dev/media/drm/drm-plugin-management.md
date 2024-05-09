# DRM Plug-in Management (ArkTS)

Before developing an application that supports digital rights protection, check whether the device supports a specific DRM scheme and if yes, create the corresponding DRM object.

In DRM Kit, the DRM scheme exists as a plug-in.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the DRM module. The module provides DRM-related attributes and methods.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```
2. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the DRM module.

   ```ts
   import {BusinessError} from '@ohos.base';
   ```
3. Call **isMediaKeySystemSupported** to check whether the device supports a certain type of DRM plug-in.

   > **NOTE**
   >
   > The value **false** means that the device does not support the specified DRM scheme.

   ```ts
   function isMediaKeySystemSupported(name: string, mimeType: string, level: drm.ContentProtectionLevel): boolean {
     let isSupported = drm.isMediaKeySystemSupported(name);
     isSupported = drm.isMediaKeySystemSupported(name, mimeType);
     isSupported = drm.isMediaKeySystemSupported(name, mimeType, level);
     return isSupported;
   }
   ```

4. Call **createMediaKeySystem(name: string)** to create a **MediaKeySystem** instance. The result is returned synchronously. If the instance fails to be created, subsequent operations cannot be performed.

   > **NOTE**
   >
   > If the creation fails, **undefined** is returned, indicating that the device does not support the DRM capability.

   ```ts
   function createMediaKeySystem(name: string): drm.MediaKeySystem {
     let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem(name);
     return mediaKeySystem;
   }
   ```

5. Call **getMediaKeySystems** to obtain the names and UUIDs of the DRM plug-ins supported by the device.

   > **NOTE**
   >
   > If the size of the array is null, no supported plug-in exists on the device.

   ```ts
   function getMediaKeySystems(): drm.MediaKeySystemDescription[]{
    let description : drm.MediaKeySystemDescription[] = [];
    try {
      description = drm.getMediaKeySystems();
    } catch (err) {
      let error = err as BusinessError;
      console.error(`getMediaKeySystems ERROR: ${error}`)
    }
    return description;
   }
   ```
