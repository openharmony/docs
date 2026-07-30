# 使用音频模板
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

从API version 23开始，支持媒体应用通过音频模板接入播控中心（系统应用），实现音视频在播控中心进行统一的界面显示和播控管理，减少应用侧开发工作量。该文档介绍音频模板接口能力及开发基本流程，包括通过音频模板接入播控中心、上报媒体相关信息（标题、作者、播放状态等）至播控中心、响应播控中心下发的操作（播放、暂停、搜索、收藏）指令等。

音频模板同时支持音频和视频内容，且两者的接入方式相同。本文档以音频场景为例进行说明。

> **说明：**
>
> 本功能仅支持在API version 23及以上版本的Car设备工程中使用。创建工程时，请在Device type中选择“Car”。

## 基本概念

音频模板（AVMusicTemplate）：用于描述音频模板相关能力的类，包含标识当前媒体会话的ID（sessionId）、会话标签（sessionTag）等属性，以及与播控中心进行数据交互的操作方法。媒体应用可通过音频模板向播控中心上报媒体相关信息，以及响应播控中心的操作指令。

## 接口说明

详细的API说明请参考[AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md)。

## 开发步骤

媒体应用接入音频模板的基本步骤如下所示：

1. 在进程启动时，调用接口[createAVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-f.md#avmusictemplatecreateavmusictemplate)创建音频模板实例（每个媒体应用创建一个音频模板实例，无需重复创建）并初始化音频模板。

   以下示例代码仅展示创建AVMusicTemplate对象的接口调用，应用在真正使用时，需要参考接口[@ohos.backgroundTaskManager (后台任务管理)](../../reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)确保AVMusicTemplate对象实例在应用后台播放业务活动期间一直存在，避免被系统回收、释放，导致后台发声时被系统管控。

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
      * 获取模板控制器实例。
      *
      * @returns 模板控制器实例。
      */
     public static getInstance(): TemplateManager {
       if (!TemplateManager.sInstance) {
         TemplateManager.sInstance = new TemplateManager();
       }
       return TemplateManager.sInstance;
     };
   
     /**
      * 创建音频模板。
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
   
2. 注册事件监听，在监听到事件后可提供应用数据给音频模板使用。监听接口详情请查看[AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md)。

   音频模板主界面显示需要同时注册如下两个接口：

   - [onQueryMainTabs](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#onquerymaintabs)：注册查询主标签事件监听。提供主界面展示的TAB数据集合，并规定“我的主页”的tabId为"minePage"。
   - [onQueryMediaTabContent](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#onquerymediatabcontent)：注册查询媒体标签内容事件监听。根据tabId提供页面展示内容数据。
   
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
      * 注册监听。
      */
     private registerListener() {
       this.template?.onQueryMainTabs(this.queryMainTabsEvent);
       this.template?.onQueryMediaTabContent(this.queryMediaTabContentEvent);
       // ...
     };
   
     // ...
     /**
      * 模拟获取主界面的所有TAB。
      *
      * @returns Promise类型MediaTab数组。
      */
     private async getMainTabs(): Promise<avMusicTemplate.MediaTab[]> {
       let homeTab: avMusicTemplate.MediaTab = {
         tabId: 'home',
         tabName: '首页'
       };
       let mineTab: avMusicTemplate.MediaTab = {
         tabId: 'mine',
         tabName: '我的'
       };
       let mainTabs: avMusicTemplate.MediaTab[] = [homeTab, mineTab];
       return mainTabs;
     };
   
     /**
      * 模拟获取TAB内容。
      *
      * @returns 标签页内容。
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
      * 模拟获取合集数据。
      *
      * @returns 合集。
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
      * 模拟获取媒体数据。
      *
      * @returns 媒体数据。
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

3. 在音频模板无法直接感知的场景（登录、下载等），需要媒体应用主动向音频模板同步数据。同步接口详情请查看[AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md)。

   例如，扫码登录成功的场景。当用户在音频模板界面扫码登录时，由于登录状态只有媒体应用能感知，所以需要调用接口[setUserInfo](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md#setuserinfo)给音频模板同步数据。
   
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
      * 模拟登录状态改变。
      *
      * @param isLogin 是否登录。
      */
     public setLoginState(isLogin: boolean) {
       this.isLogin = isLogin;
       this.setUserInfo();
     }
   
     /**
      * 用户信息发生变化后通知界面刷新用户信息，如登陆账号后。
      */
     public setUserInfo() {
       let userInfo: avMusicTemplate.UserInfo = {
         userInfoId: this.isLogin ? 'userInfoId' : '',
         nickName: this.isLogin ? '昵称' : '',
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
   
4. 媒体应用启动时注册的事件监听需要在应用退出时注销，以释放资源。注销接口详情请查看[AVMusicTemplate](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplate.md)。

   <!-- @[unregister_listener](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/TemplateProvider/entry/src/main/ets/manager/TemplateManager.ets) -->
   
   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';
   // ...
   
   export class TemplateManager {
     private template: avMusicTemplate.AVMusicTemplate | undefined = undefined;
     // ...
   
     /**
      * 注销监听。
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