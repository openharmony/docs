# DRM Plug-in Management (ArkTS)

Before developing an application that supports digital rights protection, check whether the device supports a specific DRM scheme and if yes, create the corresponding DRM object.

In DRM Kit, the DRM scheme exists as a plug-in.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the DRM module. The module provides DRM-related attributes and methods.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. Call **isMediaKeySystemSupported** to check whether the device supports a certain type of DRM plug-in.

   > **NOTE**
   >
   > The value **false** means that the device does not support the specified DRM scheme.

   ```ts
   function isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean {
     let isSupported = drm.isMediaKeySystemSupported(name);
     isSupported = drm.isMediaKeySystemSupported(name, mimeType);
     isSupported = drm.isMediaKeySystemSupported(name, mimeType, level);
     return isSupported;
   }
   ```

3. Call **createMediaKeySystem(name: string)** to create a **MediaKeySystem** instance. The result is returned synchronously. If the instance fails to be created, subsequent operations cannot be performed.

   > **NOTE**
   >
   > If the creation fails, **undefined** is returned, indicating that the device does not support the DRM capability.

   ```ts
   function createMediaKeySystem(name: string): MediaKeySystem {
     let mediaKeySystem = drm.createMediaKeySystem(name);
     if (mediaKeySystem === undefined) {
       return undefined;
     }
   }
   ```
