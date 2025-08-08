# Using AVPlayer to Play DRM Content (ArkTS)

You can call the ArkTS APIs of DRM Kit and Media Kit to implement the playback of DRM-protected content using the AVPlayer.

## How to Develop

1. Import the DRM Kit and Media Kit modules.

   ```ts
   import { drm } from '@kit.DrmKit'
   import { media } from '@kit.MediaKit'
   ```

2. Import the BusinessError module to capture error codes from the DRM Kit APIs.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit'
   ```

3. Create an AVPlayer instance and set a DRM information listener.

   ```ts
   let playerHandle: media.AVPlayer = await media.createAVPlayer()
   playerHandle.on('mediaKeySystemInfoUpdate', async (mediaKeySystemInfo: drm.MediaKeySystemInfo[]) => {
     console.info('player has received drmInfo signal: ' + JSON.stringify(mediaKeySystemInfo))
     // Process DRM information.
     // Set a decryption session.
   })
   ```

4. Create MediaKeySystem and MediaKeySession instances based on the UUID in the DRM information.

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
     // Request and process the media key.
   }
   ```

5. Generate a media key request based on the PSSH information in the DRM information and process its response.

   ```ts
   let initData: Uint8Array = new Uint8Array(drmInfoArr[i].pssh);
   const optionsData: drm.OptionsData[] = [{
     name: "optionalDataName",
     value: "optionalDataValue"
   }]
   mediaKeySession.generateMediaKeyRequest("video/mp4", initData, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE, optionsData).then(async (licenseRequest) => {
     console.info("generateMediaKeyRequest success", licenseRequest.mediaKeyRequestType, licenseRequest.data, licenseRequest.defaultURL);
     // Send licenseRequest.data returned by the media key request to the DRM service through a network request to obtain a media key response and process the response.
     let licenseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
     mediaKeySession.processMediaKeyResponse(licenseResponse).then((mediaKeyId: Uint8Array) => {
       console.info("processMediaKeyResponse success");
     }).catch((err:BusinessError) =>{
       console.error("processMediaKeyResponse err end", err.code);
     });
   }).catch((err:BusinessError) =>{
     console.error("generateMediaKeyRequest err end", err.code);
   });
   ```

6. Set the decryption session after the media key response is successfully processed.

   ```ts
   let svp: boolean = mediaKeySession.requireSecureDecoderModule('video/avc');
   playerHandle.setDecryptionConfig(mediaKeySession, svp)
   ```

7. Destroy the AVPlayer instance and destroy the MediaKeySession and MediaKeySystem instances based on the released event.

   ```ts
   playerHandle.on('stateChange', async (state: string, reason: media.StateChangeReason) => {
     if (state == 'released') {
       mediaKeySession.destroy();
       mediaKeySystem.destroy();
     }
   }
   await this.playerHandle.release()
   ```
