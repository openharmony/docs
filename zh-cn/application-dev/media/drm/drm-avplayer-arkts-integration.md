# 基于AVPlayer播放DRM节目(ArkTS)

开发者可以调用DRM Kit和Media Kit的ArkTS接口实现AVPlayer播放器，完成DRM节目播放。

## 开发步骤

1. 导入DRM Kit和Media Kit接口。

   ```ts
   import { drm } from '@kit.DrmKit'
   import { media } from '@kit.MediaKit'
   ```

2. 导入BusinessError模块抛出Drm Kit接口的错误码。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit'
   ```

3. 创建AVPlayer实例并设置DRM信息监听事件。

   ```ts
   let playerHandle: media.AVPlayer = await media.createAVPlayer()
   playerHandle.on('mediaKeySystemInfoUpdate', async (mediaKeySystemInfo: drm.MediaKeySystemInfo[]) => {
     console.info('player has received drmInfo signal: ' + JSON.stringify(mediaKeySystemInfo))
     // 处理DRM信息
     // 设置解密session
   })
   ```

4. 根据DRM信息中的uuid创建MediaKeySystem和MediaKeySession实例。

   ```ts
   let mediaKeySystem: drm.MediaKeySystem
   let mediaKeySession: drm.MediaKeySession
   let drmInfoArr: drm.MediaKeySystemInfo[] = mediaKeySystemInfo
   for (let i = 0; i < drmInfoArr.length; i++) {
     console.info('drmInfoArr - uuid: ' + drmInfoArr[i].uuid)
     console.info('drmInfoArr - pssh: ' + drmInfoArr[i].pssh)
     let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
     let solutionName: string = "com.clearplay.drm"
     for (let item of description) {
       if (drmInfoArr[i].uuid == item.uuid) {
         solutionName = item.name
         }
       }
       let isSupported: boolean = drm.isMediaKeySystemSupported(solutionName, "video/mp4");
       if (isSupported) {
         mediaKeySystem = drm.createMediaKeySystem(solutionName);
         mediaKeySession = mediaKeySystem.createMediaKeySession();
     }
     // 媒体密钥请求与处理
   }
   ```

5. 根据DRM信息中的pssh信息生成媒体密钥请求并处理媒体密钥响应。

   ```ts
   let initData: Uint8Array = new Uint8Array(drmInfoArr[i].pssh);
   const optionsData: drm.OptionsData[] = [{
     name: "optionalDataName",
     value: "optionalDataValue"
   }]
   mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionsData).then(async (licenseRequest) => {
     console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
     // 将媒体密钥请求返回的licenseRequest.data通过网络请求发送给DRM服务获取媒体密钥响应，并处理。
     let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
       console.info("processMediaKeyResponse success");
     }).catch((err:BusinessError) =>{
       console.info("processMediaKeyResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.info("generateMediaKeyRequest err end", err.code);
   });
   ```

6. 在处理媒体密钥响应成功后设置解密session

   ```ts
   let svp: boolean = mediaKeySession.requireSecureDecoderModule('video/avc');
   playerHandle.setDecryptionConfig(mediaKeySession, svp)
   ```

7. 销毁AVPlayer实例并根据released事件监听销毁MediaKeySession和MediaKeySystem实例

   ```ts
   playerHandle.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
     if (state == 'released') {
       mediaKeySession.destroy();
       mediaKeySystem.destroy();
     }
   }
   await this.playerHandle.release()
   ```
