# Using the Audio Template

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=0a01984e064addd1496bb377cb750acc6d67693d translatedAt=2026-08-10T03:48:05.691Z pushedAt=2026-08-10T07:51:07.497Z -->

Starting from API version 23, media applications can integrate with the playback control center through the audio template capability. This capability provides a unified user interface and playback control experience for audio and video content, reducing application-side development effort. This section describes the audio template APIs and the basic development workflow, including integrating with the playback control center, reporting media information (such as the title, author, and playback state), and responding to playback control commands (such as play, pause, search, and favorite) issued by the playback control center.

The audio template supports both audio and video content. Because the integration workflow is the same, this topic uses audio as an example.

> **NOTE**
>
> This feature is only supported in Car device projects running API version 23 or later. When creating a project, select **Car** as the device type.

## Fundamental Concepts

Audio template (`AVMusicTemplate`): A class that encapsulates interactions between a media application and the playback control center. It includes properties such as the current media session ID (`sessionId`) and session tag (`sessionTag`), and provides methods for exchanging data with the playback control center. Media applications use this class to report media information and respond to playback control commands.

## Available APIs

For detailed API descriptions, see [AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md).

## How to Develop

The basic steps for a media application to access the audio template are as follows:

1. When the process starts, call [createAVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-f.md#avmusictemplatecreateavmusictemplate) to create an audio template instance and initialize the audio template. Create only one `AVMusicTemplate` instance for each media application.

   The following example shows only how to create an `AVMusicTemplate` instance. In a production application, use the APIs provided by [@ohos.backgroundTaskManager (Background Task Management)](../../reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md) to ensure that the `AVMusicTemplate` instance remains alive while the application is performing background playback. Otherwise, the instance may be reclaimed by the system, causing background audio playback to be interrupted.

   <!-- @[ability_create_template](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/entryability/EntryAbility.ets) -->

   ``` TypeScript
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { TemplateManager } from '../manager/TemplateManager';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       console.info('onCreate');
       TemplateManager.getInstance().createTemplate();
     }
   
     // ...
     onForeground(): void {
       console.info('onForeground');
       this.startTemplateControllerAbility();
     }
   
     private startTemplateControllerAbility() {
       let want: Want = {
         bundleName: 'com.example.templatecontroller',
         abilityName: 'EntryAbility',
         parameters: {
           bundleName: 'com.example.templateprovider'
         }
       }
       this.context.startAbility(want).then(() => {
         console.info('startTemplateControllerAbility: startAbility success');
       }).catch((e: BusinessError) => {
         console.error(`startTemplateControllerAbility: startAbility: errCode: ${e?.code}}`);
       });
     }
   }
   ```

   <!-- @[manager_create_template](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/manager/TemplateManager.ets) -->

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   // ...
   
   export class TemplateManager {
     private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
     private static sInstance: TemplateManager;
     // ...
   
     private constructor() {
     }
   
     /**
      * Obtain the template controller instance.
      *
      * @returns Template controller instance.
      */
     public static getInstance(): TemplateManager {
       if (!TemplateManager.sInstance) {
         TemplateManager.sInstance = new TemplateManager();
       }
       return TemplateManager.sInstance;
     };
   
     /**
      * Create the audio template.
      */
     public createTemplate() {
       if (this.template) {
         console.warn('createTemplate: template not undefined');
         return
       }
       try {
         this.template = avMusicTemplate.createAVMusicTemplate(avMusicTemplate.AVMusicTemplateType.DEFAULT);
         console.info('createTemplate: success');
         // ...
       } catch (e) {
         console.error(`createTemplate, errCode: ${e?.code}`);
       }
     }
     // ...
   }
   ```

2. Register event listeners so that your application can provide data to the audio template when requested. For details about the listener APIs, see [AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md).

   To display the main audio template interface, register both of the following callbacks:

   - [onQueryMainTabs](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#onquerymaintabs): Registers a callback for querying the main tabs. Return the collection of tab data to display on the main interface. The `tabId` for **Home** must be `"minePage"`.

   - [onQueryMediaTabContent](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#onquerymediatabcontent): Registers the listener for querying media tab content events. Provides page display content data based on the `tabId`.

   <!-- @[template_register_listener](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/manager/TemplateManager.ets) -->

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   // ...
   
   export class TemplateManager {
     private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
     // ...
     private queryMainTabsEvent: avMusicTemplate.QueryMainTabsEvent = async () => {
       return this.handlePromiseReturnFunc(() => this.getMainTabs(), 'queryMainTabsEvent');
     };
     private queryMediaTabContentEvent: avMusicTemplate.QueryMediaTabContentEvent = async (tabId: string) => {
       return this.handlePromiseReturnFunc(() => this.createMediaTabContent(), 'queryMediaTabContentEvent');
     };
     // ...
   
     /**
      * Register the listener.
      */
     private registerListener() {
       this.template?.onQueryMainTabs(this.queryMainTabsEvent);
       this.template?.onQueryMediaTabContent(this.queryMediaTabContentEvent);
       // ...
     };
   
     // ...
     /**
      * Simulate obtaining all tabs on the main screen.
      *
      * @returns Promise that returns an array of MediaTab objects.
      */
     private async getMainTabs(): Promise<avMusicTemplate.MediaTab[]> {
       let homeTab: avMusicTemplate.MediaTab = {
         tabId: 'home',
         tabName: 'Home'
       };
       let mineTab: avMusicTemplate.MediaTab = {
         tabId: 'mine',
         tabName: 'My'
       };
       let mainTabs: avMusicTemplate.MediaTab[] = [homeTab, mineTab];
       return mainTabs;
     };
   
     /**
      * Simulates obtaining tab content.
      *
      * @returns Tab content.
      */
     private async createMediaTabContent(): Promise<avMusicTemplate.MediaTabContent> {
       let compilation: avMusicTemplate.Compilation = await this.createCompilation();
       let mediaTabContent: avMusicTemplate.MediaTabContent = {
         errorCode: 0,
         tabId: 'tabId',
         compilations: [compilation]
       }
       return mediaTabContent;
     };
   
     /**
      * Simulates obtaining collection data.
      *
      * @returns Collection.
      */
     private async createCompilation(): Promise<avMusicTemplate.Compilation> {
       let mediaEntity: avMusicTemplate.MediaEntity = await this.createMediaEntity();
       let compilation: avMusicTemplate.Compilation = {
         errorCode: 0,
         id: '',
         title: '',
         hasMoreData: false,
         totalSize: 1,
         memberMediaType: avMusicTemplate.EntityType.SINGLE,
         topElements: [mediaEntity],
       }
       return compilation;
     };
   
     /**
      * Simulates obtaining media data.
      *
      * @returns Media data.
      */
     private async createMediaEntity(): Promise<avMusicTemplate.MediaEntity> {
       let mediaEntity: avMusicTemplate.MediaEntity = {
         mediaId: 'mediaId',
         mediaType: avMusicTemplate.EntityType.SINGLE,
         parentId: 'parentId',
         parentMediaType: avMusicTemplate.EntityType.SINGLE,
         title: 'title',
         imageUrl: 'imageUrl',
         playState: avMusicTemplate.PlaybackState.PLAYBACK_STATE_PREPARE
       };
       return mediaEntity;
     };
   
     // ...
     private async handlePromiseReturnFunc<T>(func: () => Promise<T>, errFunc: string): Promise<T> {
       try {
         return await func();
       } catch (e) {
         const msg = `Failed to ${errFunc}. Code: ${e?.code}`;
         console.error(msg);
         throw e instanceof Error ? e : new Error(e?.message ?? msg);
       }
     }
   }
   ```

3. In scenarios where the audio template cannot directly detect application state changes, such as user sign-in or download status, the media application must proactively synchronize the corresponding data with the audio template. For details about the sync APIs, see [AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md).

   For example, after a user signs in by scanning a QR code from the audio template interface, only the media application is aware of the updated sign-in state. In this case, call [setUserInfo](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#setuserinfo) to synchronize the user information with the audio template.

   <!-- @[set_user_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/manager/TemplateManager.ets) -->

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   // ...
   
   export class TemplateManager {
     private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
     // ...
     private isLogin: boolean = false;
     // ...
   
     /**
      * Simulates a login state change.
      *
      * @param isLogin Whether the user is logged in.
      */
     public setLoginState(isLogin: boolean) {
       this.isLogin = isLogin;
       this.setUserInfo();
     }
   
     /**
      * Notifies the UI to refresh user information after it changes, for example, after logging in to an account.
      */
     public setUserInfo() {
       let userInfo: avMusicTemplate.UserInfo = {
         userInfoId: this.isLogin ? 'userInfoId' : '',
         nickName: this.isLogin ? 'Nickname' : '',
         profilePicUrl: this.isLogin ? 'profilePicUrl' : '',
         tips: this.isLogin ? 'tips' : '',
         isLogin: this.isLogin,
         isVip: false
       };
       this.template?.setUserInfo(userInfo);
     };
     // ...
   }
   ```

4. The event listeners registered when the media application starts must be unregistered when the application exits to release resources. For details, see [AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md).

   <!-- @[unregister_listener](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/manager/TemplateManager.ets) -->

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   // ...
   
   export class TemplateManager {
     private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
     // ...
   
     /**
      * Unregisters the listener.
      */
     public unregisterListener() {
       this.template?.offQueryMainTabs();
       this.template?.offQueryMediaTabContent();
       this.template?.offQueryMediaEntity();
       this.template?.offQueryCompilation();
       this.template?.offQueryPlaylist();
       this.template?.offQueryCurrentSingle();
       this.template?.offQueryCompilationByKeyword();
       this.template?.offQueryMediaEntityByKeyword();
       this.template?.offQueryRecommendMediaEntityList();
       this.template?.offQueryHotWords();
       this.template?.offQuerySearchHistory();
       this.template?.offClearSearchHistory();
       this.template?.offLogin();
       this.template?.offRequestDialogInfo();
       this.template?.offHandleMemberPurchase();
       this.template?.offQueryMemberPurchase();
       this.template?.offQueryCustomContent();
       this.template?.offDownloadMediaEntity();
       this.template?.offSettingsChange();
       this.template?.offProblemAndAdvice();
       this.template?.offPlayForSearch();
       this.template?.offExecuteAction();
       this.template?.offPlayMediaEntity();
       this.template?.offFavoriteMediaEntity();
       this.template?.destroy();
       this.template = undefined;
     };
     // ...
   }
   ```