# Media Key System Management (ArkTS)

Using the **MediaKeySystem** class of the DRM module, you can manage **MediaKeySystem** instances, generate media key system requests, process responses to these requests, create media key sessions, manage offline media keys, and obtain DRM statistics and device configuration information.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the module.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. Call **setConfigurationString** in the **MediaKeySystem** class to set a configuration item in the form of a string. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function setConfigurationString(configName: string, value: string): void {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationString(configName, value);
    } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationString ERROR: ${error}`);
    }
     return ;
   }
   ```

3. Call **getConfigurationString** in the **MediaKeySystem** class to obtain the value of a configuration item in the form of a string. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getConfigurationString(configName: string): string {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       let configValue: string = mediaKeysystem.getConfigurationString(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationString ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

4. Call **setConfigurationByteArray** in the **MediaKeySystem** class to set a configuration item in the form of a byte array. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function setConfigurationByteArray(configName: string, value: Uint8Array): void {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationByteArray(configName, value);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationByteArray ERROR: ${error}`);  
     }
     return;
   }
   ```

5. Call **getConfigurationByteArray** in the **MediaKeySystem** class to obtain the value of a configuration item in the form of a byte array. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getConfigurationByteArray(configName: string): Uint8Array {
     let mediaKeysystem: drm.mediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       let configValue: Uint8Array = mediaKeysystem.getConfigurationByteArray(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

6. Call **getMetrics()** in the **MediaKeySystem** class to obtain the statistics information, including the number of current sessions, decryption times, and decryption failures, as well as the plug-in version. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getStatistics(): StatisticKeyValue[] {
     try {
       let statisticKeyValue: StatisticKeyValue[] = mediaKeysystem.getStatistics();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);
     }
     return statisticKeyValue;
   }
   ```

7. Obtains the maximum content protection level.

   Call **getMaxContentProtectionLevel** in the **MediaKeySystem** class to obtain the maximum content protection level supported by the device. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

     ```ts
   function getMaxContentProtectionLevel(): ContentProtectionLevel {
     try {
       let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeysystem.getMaxContentProtectionLevel();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);
     }
     return contentProtectionLevel;
   }
     ```

8. Generate a media key system request to obtain a provision request.

   Call **generateKeySystemRequest** method in the **MediaKeySystem** class to generate a media key system request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

     ```ts
   function generateKeySystemRequest(): Promise<ProvisionRequest> {
     generateKeySystemRequest().then((ProvisionRequest: drm.ProvisionRequest) => {
       console.log("generateKeySystemRequest");
     }).catch((err: BusinessError) => {
       console.error(`generateKeySystemRequest: ERROR: ${err}`);
     });
     return provisionRequest;
   }
     ```

9. Process the response to the media key system request.

   Call **processKeySystemResponse** in the **MediaKeySystem** class to process the response. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

     ```ts
   function processKeySystemResponse(response: Uint8Array): Promise<void> {
     processKeySystemResponse(response).then(() => {
       console.log("processKeySystemResponse");
     }).catch((err: BusinessError) => {
       console.error(`processKeySystemResponse: ERROR: ${err}`);
     });
     return;
   }
     ```

10. Obtain the status of the device certificate.

    Call **getCertificateStatus** in the **MediaKeySystem** class to obtain the device certificate status. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getCertificateStatus(): CertificateStatus {
      try {
        let certificateStatus: drm.CertificateStatus = mediaKeysystem.getCertificateStatus();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return certificateStatus;
    }
    ```

11. Create a DRM session.

    Call **createMediaKeySession** in the **MediaKeySystem** class to create a session based on the given content protection level. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function createMediaKeySession(level: ContentProtectionLevel): MediaKeySession {
      try {
        let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession(drm.level.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

12. Create a DRM session.

    Call **createMediaKeySession** in the **MediaKeySystem** class to create a session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function createMediaKeySession(): MediaKeySession {
      try {
        let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

13. Obtain the IDs of offline media keys.

    Call **getOfflineMediaKeyIds** in the **MediaKeySystem** class to obtain the IDs of offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getOfflineMediaKeyIds(): Uint8Array[] {
      try {
        let offlineMediaKeyIds: Uint8Array[] = mediaKeysystem.getOfflineMediaKeyIds();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
      }
      return offlineMediaKeyIds;
    }
    ```

14. Obtain the status of the offline media keys.

    Call **getOfflineMediaKeyStatus** in the **MediaKeySystem** class to obtain the status of the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getOfflineMediaKeyStatus(mediakeyId: Uint8Array): OfflineMediaKeyStatus {
      try {
        let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus = mediaKeysystem.getOfflineMediaKeyStatus(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
      }
      return offlineMediaKeyStatus;
    }
    ```

15. Clear the offline media keys.

    Call **clearOfflineMediaKeys** in the **MediaKeySystem** class to clear the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function clearOfflineMediaKeys(mediakeyId: Uint8Array): void {
      try {
        mediaKeysystem.clearOfflineMediaKeys(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`clearOfflineMediaKeys ERROR: ${error}`);
      }
      return;
    }
    ```

16. Destroy this **MediaKeySystem** instance.

    Call **destroy** in the **MediaKeySystem** class to destroy this **MediaKeySystem** instance. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function destroy(mediaKeySyste: MediaKeySyste): void {
      try {
        mediaKeysystem.destroy();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`mediaKeysystem destroy ERROR: ${error}`);
      }
      return;
    }
    ```

17. Listen for the media key system status.

    You can listen for the following events: device certificate request events.

    To listen for key request events, register the **keySystemRequired** callback function. This event can be listened for when a **MediaKeySystem** instance is created. If this event callback is returned, a media key system request starts. You can use **off** to deregister the callback function when listening is no longer required.

    ```ts
    function onRegisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.on('keySystemRequired', (eventInfo: EventInfo) => {
        console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
      });
    }
    ```

    ```ts
    function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.off('keySystemRequired');
    }
    ```