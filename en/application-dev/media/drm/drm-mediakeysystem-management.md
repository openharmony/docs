# Media Key System Management (ArkTS)

Using the **MediaKeySystem** class of the DRM module, you can manage **MediaKeySystem** instances, generate media key system requests, process responses to these requests, create media key sessions, manage offline media keys, and obtain DRM statistics and device configuration information.

## How to Develop

Read [DRM](../../reference/apis-drm-kit/js-apis-drm.md) for the API reference.

1. Import the module.

   ```ts
   import drm from '@ohos.multimedia.drm';
   ```

2. Import the **BusinessError** module, which provides the error codes thrown by the APIs of the DRM module.

   ```ts
   import {BusinessError} from '@ohos.base';
   ```

3. Call **setConfigurationString** in the **MediaKeySystem** class to set a configuration item in the form of a string. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function setConfigurationString(configName: string, value: string): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationString(configName, value);
    } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationString ERROR: ${error}`);
    }
     return ;
   }
   ```

4. Call **getConfigurationString** in the **MediaKeySystem** class to obtain the value of a configuration item in the form of a string. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getConfigurationString(configName: string): string | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let configValue: string | undefined = undefined;
     try {
       configValue = mediaKeysystem.getConfigurationString(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationString ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

5. Call **setConfigurationByteArray** in the **MediaKeySystem** class to set a configuration item in the form of a byte array. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function setConfigurationByteArray(configName: string, value: Uint8Array): void {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     try {
       mediaKeysystem.setConfigurationByteArray(configName, value);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`setConfigurationByteArray ERROR: ${error}`);  
     }
     return;
   }
   ```

6. Call **getConfigurationByteArray** in the **MediaKeySystem** class to obtain the value of a configuration item in the form of a byte array. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getConfigurationByteArray(configName: string): Uint8Array | undefined {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let configValue: Uint8Array | undefined = undefined;
     try {
       configValue = mediaKeysystem.getConfigurationByteArray(configName);
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);  
     }
     return configValue;
   }
   ```

7. Call **getMetrics()** in the **MediaKeySystem** class to obtain the statistics information, including the number of current sessions, decryption times, and decryption failures, as well as the plug-in version. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

   ```ts
   function getStatistics(): drm.StatisticKeyValue[] {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let statisticKeyValue: drm.StatisticKeyValue[] = [];
     try {
       statisticKeyValue = mediaKeysystem.getStatistics();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getConfigurationByteArray ERROR: ${error}`);
     }
     return statisticKeyValue;
   }
   ```

8. Obtains the maximum content protection level.

   Call **getMaxContentProtectionLevel** in the **MediaKeySystem** class to obtain the maximum content protection level supported by the device. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

     ```ts
   function getMaxContentProtectionLevel(): drm.ContentProtectionLevel {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let contentProtectionLevel: drm.ContentProtectionLevel = drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_UNKNOWN;
     try {
       contentProtectionLevel = mediaKeysystem.getMaxContentProtectionLevel();
     } catch (err) {
       let error = err as BusinessError;
       console.error(`getMaxContentProtectionLevel ERROR: ${error}`);
     }
     return contentProtectionLevel;
   }
     ```

9. Generate a media key system request to obtain a provision request.

   Call **generateKeySystemRequest** method in the **MediaKeySystem** class to generate a media key system request. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

     ```ts
   async function generateKeySystemRequest(): Promise<drm.ProvisionRequest | undefined> {
     let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
     let provisionRequest: drm.ProvisionRequest | undefined = await mediaKeysystem.generateKeySystemRequest().catch((err: BusinessError) => {
        console.error(`generateKeySystemRequest: ERROR: ${err}`);
        return undefined;
      });
     return provisionRequest;
   }
     ```

10. Process the response to the media key system request.

    Call **processKeySystemResponse** in the **MediaKeySystem** class to process the response. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function processKeySystemResponse(response: Uint8Array): void {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      mediaKeysystem.processKeySystemResponse(response).then(() => {
        console.log("processKeySystemResponse");
      }).catch((err: BusinessError) => {
        console.error(`processKeySystemResponse: ERROR: ${err}`);
      });
    }
    ```

11. Obtain the status of the device certificate.

    Call **getCertificateStatus** in the **MediaKeySystem** class to obtain the device certificate status. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getCertificateStatus(): drm.CertificateStatus {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let certificateStatus: drm.CertificateStatus = drm.CertificateStatus.CERT_STATUS_PROVISIONED;
      try {
        certificateStatus = mediaKeysystem.getCertificateStatus();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return certificateStatus;
    }
    ```

12. Create a DRM session.

    Call **createMediaKeySession** in the **MediaKeySystem** class to create a session based on the given content protection level. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function createMediaKeySession(level: drm.ContentProtectionLevel): drm.MediaKeySession | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession | undefined = undefined;
      try {
        mediaKeySession = mediaKeysystem.createMediaKeySession(level);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

13. Create a DRM session.

    Call **createMediaKeySession** in the **MediaKeySystem** class to create a session. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function createMediaKeySession(): drm.MediaKeySession | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let mediaKeySession: drm.MediaKeySession | undefined = undefined;
      try {
        mediaKeySession = mediaKeysystem.createMediaKeySession();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getCertificateStatus ERROR: ${error}`);
      }
      return mediaKeySession;
    }
    ```

14. Obtain the IDs of offline media keys.

    Call **getOfflineMediaKeyIds** in the **MediaKeySystem** class to obtain the IDs of offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getOfflineMediaKeyIds(): Uint8Array[] | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let offlineMediaKeyIds: Uint8Array[] | undefined = undefined;
      try {
        offlineMediaKeyIds = mediaKeysystem.getOfflineMediaKeyIds();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
      }
      return offlineMediaKeyIds;
    }
    ```

15. Obtain the status of the offline media keys.

    Call **getOfflineMediaKeyStatus** in the **MediaKeySystem** class to obtain the status of the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function getOfflineMediaKeyStatus(mediakeyId: Uint8Array): drm.OfflineMediaKeyStatus | undefined {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      let offlineMediaKeyStatus: drm.OfflineMediaKeyStatus | undefined = undefined;
      try {
        offlineMediaKeyStatus = mediaKeysystem.getOfflineMediaKeyStatus(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
      }
      return offlineMediaKeyStatus;
    }
    ```

16. Clear the offline media keys.

    Call **clearOfflineMediaKeys** in the **MediaKeySystem** class to clear the offline media keys. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function clearOfflineMediaKeys(mediakeyId: Uint8Array): void {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      try {
        mediaKeysystem.clearOfflineMediaKeys(mediakeyId);
      } catch (err) {
        let error = err as BusinessError;
        console.error(`clearOfflineMediaKeys ERROR: ${error}`);
      }
      return;
    }
    ```

17. Destroy this **MediaKeySystem** instance.

    Call **destroy** in the **MediaKeySystem** class to destroy this **MediaKeySystem** instance. If the call fails, an error code is returned. For details about the error code types, see [DrmErrorCode](../../reference/apis-drm-kit/js-apis-drm.md#drmerrorcode).

    ```ts
    function destroy(mediaKeySystem: drm.MediaKeySystem): void {
      let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
      try {
        mediaKeysystem.destroy();
      } catch (err) {
        let error = err as BusinessError;
        console.error(`mediaKeysystem destroy ERROR: ${error}`);
      }
      return;
    }
    ```

18. Listen for the media key system status.

    You can listen for the following events: device certificate request events.

    To listen for key request events, register the **keySystemRequired** callback function. This event can be listened for when a **MediaKeySystem** instance is created. If this event callback is returned, a media key system request starts. You can use **off** to deregister the callback function when listening is no longer required.

    ```ts
    function onRegisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
        console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
      });
    }
    ```

    ```ts
    function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
      mediaKeysystem.off('keySystemRequired');
    }
    ```
