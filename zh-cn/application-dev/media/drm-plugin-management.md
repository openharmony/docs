# 插件管理(ArkTS)

在开发一个支持数字版权保护功能的应用前，需要先查询设备是否支持DRM功能，不同的DRM方案支持的功能也有差异，需要查询设备支持哪些DRM方案，然后再创建具体的DRM对象。

在DRM Kit里DRM方案以插件形式存在，所以也叫DRM插件。

## 开发步骤

详细的API说明请参考[DRM API参考](../reference/apis/js-apis-drm.md)。

1. 导入drm接口，接口中提供了drm相关的属性和方法。

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. 通过isMediaKeySystemSupported方法，查询设备是否支持对应的插件类型。

   其中参数mimeType和level是可选参数。

   > **说明：**
   >
   > 如果查询为false，说明该设备不支持对应的DRM方案。

   ```ts
   function isMediaKeySystemSupported(uuid: string, mimeType: string, level: SecurityLevel): boolean {
     let isSupported = drm.isMediaKeySystemSupported(uuid, mimeType, level);
     return isSupported;
   }
   ```

3. 通过getMediaKeySystemName()方法，查询设备是否支持对应的插件类型；其中参数mimeType和level是可选的。

   > **说明：**
   >
   > 如果获取失败或者结果为空，说明该设备不支持DRM能力。

   ```ts
   function getMediaKeySystemName(): string[] {
     let keySystemName = drm.getMediaKeySystemName();
     return keySystemName;
   }
   ```

4. 通过drm的createMediaKeySystem(uuid: string)方法，创建MediaKeySystem实例，同步返回结果，创建失败，不可继续后续操作。

   > **说明：**
   >
   > 如果如果创建失败则返回undefined，说明该设备不支持DRM能力。

   ```ts
   function createMediaKeySystem(uuid: string): MediaKeySystem {
     let mediaKeySystem = drm.createMediaKeySystem(uuid);
     if (mediaKeySystem === undefined) {
       return undefined;
     }
   }
   ```
