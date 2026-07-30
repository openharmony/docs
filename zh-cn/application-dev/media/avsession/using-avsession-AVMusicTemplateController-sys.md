# 音频模板概述（仅对系统应用开放）
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

从API version 23开始，支持通过创建音频模板控制器，实现对接入音频模板的其他媒体应用提供统一的UI界面管理（播放列表、收藏列表、媒体详情等）以及媒体播控操作（播放、暂停、搜索、收藏等）的功能。该文档介绍音频模板系统接口能力及开发基本流程，包括监听媒体应用接入音频模板、查询媒体应用业务数据、给媒体应用下发操作指令等，媒体应用接入请参考文档[使用音频模板](using-avsession-AVMusicTemplate.md)。

音频模板同时支持音频和视频内容，且两者的接入方式相同。本文档以音频场景为例进行说明。

> **说明：**
>
> 本功能仅支持在API version 23及以上版本的Car设备工程中使用。创建工程时，请在Device type中选择“Car”。

## 基本概念

音频模板（AVMusicTemplate）：用于描述音频模板相关能力的类，包含标识当前媒体会话的ID（sessionId）、会话标签（sessionTag）等属性，以及与播控中心（系统应用）进行数据交互的操作方法。媒体应用可通过音频模板向播控中心上报媒体相关信息，以及响应播控中心的操作指令。

音频模板控制器（AVMusicTemplateController）：用于描述音频模板控制器相关能力的类，包含标识媒体会话的ID（sessionId）和音频模板控制器是否已销毁（isDestroy）等属性，以及与媒体应用进行数据交互的操作方法。对于已接入音频模板的媒体应用，播控中心可通过音频模板控制器获取媒体应用数据进行页面展示，以及将用户指令下发给媒体应用。

## 接口说明

详细的API说明请参考[AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md)。

## 开发步骤

音频模板系统的开发基本步骤如下所示：

1. 创建音频模板控制器（为每个接入音频模板的媒体应用创建一个音频模板控制器，不需要重复创建），监听音频模板创建和销毁状态，同步创建和销毁音频模板控制器。需要用到如下接口：

   - [createAVMusicTemplateController](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplatecreateavmusictemplatecontroller)：创建音频模板控制器。需要sessionId参数。
   - [getAllAVMusicTemplateDescriptors](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplategetallavmusictemplatedescriptors)：获取所有的音频模板描述。由于媒体应用创建音频模板可能发生在进程启动之前，所以无法通过音频模板创建事件获取sessionId。可在进程启动后，通过该方法获取sessionId。
   - [onAVMusicTemplateCreate](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplateonavmusictemplatecreate)：监听音频模板创建事件。
   - [onAVMusicTemplateDestroy](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md#avmusictemplateonavmusictemplatedestroy)：监听音频模板销毁事件。

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
      * 通过getAllAVMusicTemplateDescriptors创建模板。
      */
     public createAvMusicTemplateController(bundleName: string) {
       if (this.isStringEmpty(bundleName)) {
         console.warn(TAG, 'createAvMusicTemplateController: bundleName is empty');
         return;
       }
       this.currentBundleName = bundleName;
       try {
         // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
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
      * 注册模板监听。
      */
     public registerAVMusicTemplateListener() {
       try {
         // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
         avMusicTemplate.onAVMusicTemplateCreate(this.templateCreateCallback);

         // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
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
      * 注销监听。
      */
     public unregisterListener() {
       // 注销用户信息改变的监听。
       this.controller?.offUserInfoChange();
   
       // 注销对话框命令改变的监听。
       this.controller?.offDialogCommandChange();
   
       // 注销当前单曲改变的监听。
       this.controller?.offCurrentSingleChange();
   
       // 注销媒体实体改变的监听。
       this.controller?.offMediaEntitiesChange();
   
       // 注销标签页内容改变的监听。
       this.controller?.offTabContentChange();
   
       // 注销播放列表改变的监听。
       this.controller?.offPlaylistChange();
   
       // 注销下载媒体状态改变的监听。
       this.controller?.offDownloadMediaEntityStatusChange();
   
       // 注销自定义元素改变的监听。
       this.controller?.offCustomElementsChange();
   
       // 注销设置改变的监听。
       this.controller?.offSettingsChange();
   
       // 注销上报执行动作的监听。
       this.controller?.offReportExecuteAction();
   
       // 注销通知媒体中心拉起指定三方应用界面的信息的监听。
       this.controller?.offExtensionAbilityChange();
     }

     /**
      * 销毁控制器。
      */
     public destroyController() {
       console.info(TAG, 'destroyController')
       this.controller?.destroy();
       this.controller = undefined;
       this.currentBundleName = undefined;
     }

     /**
      * 反注册模板监听。
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

2. 音频模板系统可查询媒体应用提供的数据，用于界面展示。查询接口详情请查看[AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md)。

   例如，实现音频模板系统主界面显示需要先调用接口[queryMainTabs](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#querymaintabs)获取媒体应用主标签数据，再调用接口[queryMediaTabContent](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#querymediatabcontent)获取媒体应用标签页内容。

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

     /**
      * 查询主标签。
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
      * 模拟查询媒体标签页内容。
      *
      * @param tabId 标签页ID。
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

3. 下发媒体操作指令。音频模板系统根据操作下发指令给媒体应用。下发指令接口详情请查看[AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md)。

   例如，搜播需要调用接口[playForSearch](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#playforsearch)下发搜播指令给媒体应用（该接口支持音视频，示例仅以音频为例）。视频需将参数实体类SearchPlayInfo的成员变量更换为SearchPlayVideoInfo类型的videoInfo。

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;

     /**
      * 模拟搜播。
      *
      * @returns Promise类型操作结果。
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
         musicInfo: searchPlayMusicInfo
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

4. 在不能实时获取数据的场景下（登录、下载等），音频模板系统需要注册监听，接受媒体应用主动同步过来的数据。监听接口详情请查看[AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md)。

   例如，在登录导致用户信息变化的场景下，需要注册监听[onUserInfoChange](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md#onuserinfochange)。因为用户在音频模板系统界面扫码登录时，登录状态仅媒体应用可感知。

      ``` TypeScript
      import { avMusicTemplate } from '@kit.AVSessionKit';

      const TAG: string = 'ControllerManager';

      export class ControllerManager {
        private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
        private userInfoChangeCallback: Callback<avMusicTemplate.UserInfo> = (userInfo: avMusicTemplate.UserInfo) => {
          console.info(TAG, 'userInfoChangeCallback');
        };
      
        private registerListener() {
          // 注册用户信息改变的监听。
          this.controller?.onUserInfoChange(this.userInfoChangeCallback);
        }
      }
      ```

5. 在音频模板系统应用退出时及时取消事件监听，并释放资源。注销音频模板接口详情请查看[@ohos.multimedia.avMusicTemplate(音频模板)(系统接口)](../../reference/apis-avsession-kit/js-apis-avMusicTemplate-sys.md)，注销事件监听接口详情请查看[AVMusicTemplateController](../../reference/apis-avsession-kit/arkts-apis-avMusicTemplate-AVMusicTemplateController.md)。

   ``` TypeScript
   import { avMusicTemplate } from '@kit.AVSessionKit';

   const TAG: string = 'ControllerManager';

   export class ControllerManager {
     private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
     private currentBundleName: string | undefined = undefined;

     /**
      * 注销监听。
      */
     public unregisterListener() {
       // 注销用户信息改变的监听。
       this.controller?.offUserInfoChange();
   
       // 注销对话框命令改变的监听。
       this.controller?.offDialogCommandChange();
   
       // 注销当前单曲改变的监听。
       this.controller?.offCurrentSingleChange();
   
       // 注销媒体实体改变的监听。
       this.controller?.offMediaEntitiesChange();
   
       // 注销标签页内容改变的监听。
       this.controller?.offTabContentChange();
   
       // 注销播放列表改变的监听。
       this.controller?.offPlaylistChange();
   
       // 注销下载媒体状态改变的监听。
       this.controller?.offDownloadMediaEntityStatusChange();
   
       // 注销自定义元素改变的监听。
       this.controller?.offCustomElementsChange();
   
       // 注销设置改变的监听。
       this.controller?.offSettingsChange();
   
       // 注销上报执行动作的监听。
       this.controller?.offReportExecuteAction();
   
       // 注销通知媒体中心拉起指定三方应用界面的信息的监听。
       this.controller?.offExtensionAbilityChange();
     }

     /**
      * 销毁控制器。
      */
     public destroyController() {
       console.info(TAG, 'destroyController')
       this.controller?.destroy();
       this.controller = undefined;
       this.currentBundleName = undefined;
     }

     /**
      * 反注册模板监听。
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