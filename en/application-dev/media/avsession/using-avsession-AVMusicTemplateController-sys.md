# Audio Template Overview (for System Applications Only)

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ee34ce1eff50a8cf8b3b2ed4ccfabed4f0b661c translatedAt=2026-08-15T01:57:14.696Z pushedAt=2026-08-15T09:02:13.350Z -->

Starting from API version 23, you can create an audio template controller to provide unified UI management (playlists, favorites, media details, etc.) and media playback control operations (play, pause, search, favorites, etc.) for other media apps that have connected to the audio template. This document describes the system API capabilities of the audio template and the basic development process, including listening for media apps connecting to the audio template, querying media app service data, and sending operation commands to media apps. For details about how a media app connects to the audio template, see [Using the Audio Template](using-avsession-AVMusicTemplate.md).

The audio template supports both audio and video content. Because the integration workflow is the same, this topic uses audio as an example.

> **NOTE**
>
> This feature is only supported in Car device projects running API version 23 or later. When creating a project, select **Car** as the device type.

## Fundamental Concepts

Audio template (`AVMusicTemplate`): A class that describes audio template capabilities. It includes properties such as the current media session ID (`sessionId`) and session tag (`sessionTag`), and provides methods for exchanging data with the playback control center (system app). Media apps use the audio template to report media-related information to the playback control center and respond to playback control commands.

Audio template controller (`AVMusicTemplateController`): A class that describes audio template controller capabilities. It includes properties such as the media session ID (`sessionId`) and whether the audio template controller has been destroyed (`isDestroy`), and provides methods for exchanging data with media apps. For media apps that have connected to the audio template, the playback control center can obtain media app data through the audio template controller for page display and send user commands to the media app.

## Available APIs

For detailed API descriptions, see [AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md).

## How to Develop

The basic development steps for the audio template system are as follows:

1. Create an audio template controller (create one for each media app that accesses the audio template; do not create duplicates), listen for audio template creation and destruction states, and synchronously create and destroy the audio template controller. The following APIs are required:

   - [createAVMusicTemplateController](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplatecreateavmusictemplatecontroller): Creates an audio template controller. Requires the sessionId parameter.

   - [getAllAVMusicTemplateDescriptors](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplategetallavmusictemplatedescriptors): Obtains all audio template descriptors. Since a media app may create an audio template before the process starts, the sessionId cannot be obtained through the audio template creation event. You can obtain the sessionId through this method after the process starts.

   - [onAVMusicTemplateCreate](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplateonavmusictemplatecreate): Listens for audio template creation events.

   - [onAVMusicTemplateDestroy](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplateonavmusictemplatedestroy): Listens for audio template destruction events.

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
     private currentBundleName: string | undefined = undefined;
     private templateCreateCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
       (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
         if (this.isInvalid(descriptor)) {
           console.warn(TAG, 'templateCreateCallback: descriptor is invalid');
           return;
         }
         console.info(TAG, `templateCreateCallback, bundleName: ${descriptor.bundleName}`);
         this.createController(descriptor.sessionId, descriptor.bundleName);
       };
     private templateDestroyCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
       (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
         if (this.isInvalid(descriptor)) {
           console.warn(TAG, 'templateDestroyCallback: descriptor is invalid');
           return;
         }
         if (this.isStringEmpty(this.currentBundleName)) {
           console.warn(TAG, 'templateDestroyCallback: current bundleName is empty');
           return;
         }
         if (this.currentBundleName !== descriptor.bundleName) {
           console.warn(TAG, 'templateDestroyCallback: not current bundleName');
           return;
         }
         this.unregisterListener();
         this.destroyController();
       };

     /**
      * Create an audio template controller based on bundleName.
      */
     public createAvMusicTemplateController(bundleName: string) {
       if (this.isStringEmpty(bundleName)) {
         console.warn(TAG, 'createAvMusicTemplateController: bundleName is empty');
         return;
       }
       this.currentBundleName = bundleName;
       try {
         // This method requires the permission ohos.permission.MANAGE_MEDIA_RESOURCES.
         let descriptors: avMusicTemplate.AVMusicTemplateDescriptor[] = avMusicTemplate.getAllAVMusicTemplateDescriptors();
         if (this.isEmptyArray(descriptors)) {
           console.info(TAG, 'createAvMusicTemplateController: descriptors is empty');
           return;
         }
         for (let descriptor of descriptors) {
           if (descriptor === null || descriptor === undefined) {
             console.warn(TAG, 'createAvMusicTemplateController: descriptor is invalid continue');
             continue;
           }
           if (this.currentBundleName === descriptor.bundleName) {
             this.createController(descriptor.sessionId, descriptor.bundleName);
             return;
           }
         }
       } catch (e) {
         console.error(TAG, `getAllAVMusicTemplateDescriptors failed, errCode: ${e?.code}`);
       }
     };

     private isInvalid<T>(obj: T): boolean {
       return obj === undefined || obj === null;
     }

     private isStringEmpty(str: string | undefined): boolean {
       return str === undefined || str === null || str.trim().length === 0;
     }

     private isEmptyArray<T>(array: T[]): boolean {
       return this.isInvalid(array) || array.length <= 0;
     }

     /**
      * Register template listeners.
      */
     public registerAVMusicTemplateListener() {
       try {
         // This method requires the permission ohos.permission.MANAGE_MEDIA_RESOURCES.
         avMusicTemplate.onAVMusicTemplateCreate(this.templateCreateCallback);

         // This method requires the permission ohos.permission.MANAGE_MEDIA_RESOURCES.
         avMusicTemplate.onAVMusicTemplateDestroy(this.templateDestroyCallback);
       } catch (e) {
         console.error(TAG, `registerAVMusicTemplateListener: errCode: ${e?.code}`);
       }
     }

     private createController(sessionId: string, bundleName: string) {
       if (this.currentBundleName === null || this.currentBundleName === undefined) {
         console.warn(TAG, 'createController: currentBundleName is invalid');
         return;
       }
       if (sessionId === null || sessionId === undefined) {
         console.warn(TAG, 'createController: sessionId is invalid');
         return;
       }
       if (bundleName === null || bundleName === undefined) {
         console.warn(TAG, 'createController: bundleName is invalid');
         return;
       }
       if (this.currentBundleName !== bundleName) {
         console.warn(TAG, 'createController: not current bundleName');
         return;
       }
       if (this.controller != undefined) {
         console.warn(TAG, 'createController: controller not undefined');
         return;
       }
       try {
         this.controller = avMusicTemplate.createAVMusicTemplateController(sessionId);
         console.info(TAG, `createController success, bundleName: ${this.currentBundleName}`);
       } catch (e) {
         console.error(TAG, `createController: errCode: ${e?.code}`);
       }
     }

     /**
      * Unregister listeners.
      */
     public unregisterListener() {
       // Unregister the listener for user information changes.
       this.controller?.offUserInfoChange();
   
       // Unregister the listener for dialog command changes.
       this.controller?.offDialogCommandChange();
   
       // Unregister the listener for current single track changes.
       this.controller?.offCurrentSingleChange();
   
       // Unregister the listener for media entity changes.
       this.controller?.offMediaEntitiesChange();
   
       // Unregister the listener for tab content changes.
       this.controller?.offTabContentChange();
   
       // Unregister the listener for playlist changes.
       this.controller?.offPlaylistChange();
   
       // Unregister the listener for download media entity status changes.
       this.controller?.offDownloadMediaEntityStatusChange();
   
       // Unregister the listener for custom element changes.
       this.controller?.offCustomElementsChange();
   
       // Unregister the listener for settings changes.
       this.controller?.offSettingsChange();
   
       // Unregister the listener for report execute action.
       this.controller?.offReportExecuteAction();
   
       // Unregister the listener for the information about the media center launching a specified third-party app interface.
       this.controller?.offExtensionAbilityChange();
     }

     /**
      * Destroy the controller.
      */
     public destroyController() {
       console.info(TAG, 'destroyController')
       this.controller?.destroy();
       this.controller = undefined;
       this.currentBundleName = undefined;
     }

     /**
      * Unregister the template listener.
      */
     public unregisterAVMusicTemplateListener() {
       try {
         avMusicTemplate.offAVMusicTemplateCreate();
         avMusicTemplate.offAVMusicTemplateDestroy();
       } catch (e) {
         console.error(TAG, `unregisterAVMusicTemplateListener: errCode: ${e?.code}`);
       }
     }
   }
   ```

2. The audio template system can query data provided by the media application for UI display. For details about the query APIs, see [AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md).

   For example, to display the main screen of the audio template system, you need to first call [queryMainTabs](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#querymaintabs) to obtain the main tab data of the media application, and then call [queryMediaTabContent](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#querymediatabcontent) to obtain the media application tab content.

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

     /**
      * Query the main tab.
      */
     public async queryMainTabs(): Promise<avMusicTemplate.MediaTab[]> {
       let tabs: avMusicTemplate.MediaTab[] = [];
       if (!this.controller) {
         console.info(TAG, 'queryMainTabs: controller is undefined')
         return tabs;
       }
       try {
         console.info(TAG, 'queryMainTabs')
         tabs = await this.controller.queryMainTabs();
       } catch (e) {
         console.error(TAG, `queryMainTabs failed, errCode: ${e?.code}`)
       }
       return tabs;
     }

     /**
      * Simulate querying media tab content.
      *
      * @param tabId Tab ID.
      */
     public async queryMediaTabContent(tabId: string): Promise<avMusicTemplate.MediaTabContent | undefined> {
       try {
         let tabContent: avMusicTemplate.MediaTabContent | undefined = await this.controller?.queryMediaTabContent(tabId);
         if (tabContent?.errorCode != 0) {
           console.warn(TAG, 'queryMediaTabContent fail')
           return undefined;
         }
         console.info(TAG, 'queryMediaTabContent success')
         return tabContent;
       } catch (e) {
         console.error(TAG, `queryMediaTabContent failed, errCode: ${e?.code}`)
         return undefined;
       }
     }
   }
   ```

3. Issue media operation commands. The audio template system sends commands to the media application based on the operation. For details about the command issuing APIs, see [AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md).

   For example, for search and play, call [playForSearch](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#playforsearch) to issue a search-and-play command to the media application. (This API supports both audio and video, but the example uses audio only.) For video, replace the member variable of the parameter entity class `SearchPlayInfo` with `videoInfo` of the `SearchPlayVideoInfo` type.

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

     /**
     * Simulate search and play.
     *
     * @returns Operation result of the Promise type.
     */
     public async playForSearch(): Promise<boolean> {
       let command: avMusicTemplate.SearchPlayInfoType = avMusicTemplate.SearchPlayInfoType.PLAY_MUSIC;
       let searchPlayMusicItems: avMusicTemplate.SearchPlayMusicItem[] = [{
         entityId: 'entityId',
         entityName: 'entityName'
       }];
       let searchPlayMusicInfo: avMusicTemplate.SearchPlayMusicInfo = {
         items: searchPlayMusicItems,
         displayName: 'displayName',
         description: 'description'
       };
       let searchPlayInfo: avMusicTemplate.SearchPlayInfo = {
         musicInfo: searchPlayMusicInfo,
         videoInfo: undefined
       };
       try {
         let operResult: avMusicTemplate.OperResult | undefined =
           await this.controller?.playForSearch(command, searchPlayInfo);
         if (operResult?.errorCode != 0) {
           console.warn(TAG, 'playForSearch fail')
           return false;
         }
         console.info(TAG, 'playForSearch success')
         return true;
       } catch (e) {
         console.error(TAG, `playForSearch failed, errCode: ${e?.code}`)
         return false;
       }
     };
   }
   ```

4. In scenarios where data cannot be obtained in real time (such as login or download), the audio template system must register a listener to receive data actively synchronized by the media application. For details about the listener APIs, see [AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md).

   For example, in a scenario where login causes user information changes, register the listener [onUserInfoChange](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#onuserinfochange). This is because when a user logs in by scanning a QR code on the audio template system UI, only the media application can detect the login state.

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   
   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
     private userInfoChangeCallback: Callback<avMusicTemplate.UserInfo> = (userInfo: avMusicTemplate.UserInfo) => {
       console.info(TAG, 'userInfoChangeCallback');
     };

     private createController(sessionId: string) {
       if (sessionId === null || sessionId === undefined) {
         console.warn(TAG, 'createController: sessionId is invalid');
         return;
       }
       if (this.controller != undefined) {
         console.warn(TAG, 'createController: controller not undefined');
         return;
       }
       try {
         this.controller = avMusicTemplate.createAVMusicTemplateController(sessionId);
         this.registerListener();
       } catch (e) {
         console.error(TAG, `Failed to createAVMusicTemplateController. Code: ${e?.code}`);
       }
     }
      
     private registerListener() {
       // Register the listener for user information changes.
       this.controller?.onUserInfoChange(this.userInfoChangeCallback);
     }
   }
   ```

5. When the audio template system app exits, promptly cancel event listeners and release resources. For details about unregistering the audio template API, see [@ohos.multimedia.avMusicTemplate (Audio Template) (System API)](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md). For details about unregistering the event listener API, see [AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md).

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
     private currentBundleName: string | undefined = undefined;

     /**
      * Unregister the listener.
      */
     public unregisterListener() {
       // ...
     }

     /**
      * Destroy the controller.
      */
     public destroyController() {
       console.info(TAG, 'destroyController')
       this.controller?.destroy();
       this.controller = undefined;
       this.currentBundleName = undefined;
     }

     /**
      * Unregister the template listener.
      */
     public unregisterAVMusicTemplateListener() {
       try {
         avMusicTemplate.offAVMusicTemplateCreate();
         avMusicTemplate.offAVMusicTemplateDestroy();
       } catch (e) {
         console.error(TAG, `unregisterAVMusicTemplateListener: errCode: ${e?.code}`);
       }
     }
   }
   ```