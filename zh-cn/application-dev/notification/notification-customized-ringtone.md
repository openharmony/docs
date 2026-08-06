# 为通知添加自定义铃声
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

从API version 12开始，应用发布通知时，可以使用自定义的通知铃声，该铃声的音频资源需要预置在应用中。从API version 24开始，系统增强了该字段的能力，应用可以使用非预置的音频资源作为通知铃声，比如从网络下载或者用户生成的音频资源。

## 接口说明

自定义铃声可通过[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1)携带sound字段来指定，不指定该字段默认为系统铃声。

- 资源文件：应用预置的音频文件，资源文件必须放在resources/rawfile目录下，使用时直接传入文件名。
- 沙箱文件：网络下载或者用户生成的音频文件，必须放在[沙箱文件目录](../file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)EL1区域的files目录或者其子目录下，传入格式为uri::{fileUri}，其中fileUri是通过[getUriFromPath](../reference/apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath)获取的路径。<br/>

支持m4a、aac、mp3、ogg、wav、flac、amr等格式。

**表1** 通知发布接口功能介绍

| 接口名 | 描述 |
| -------- | -------- |
| [publish(request: NotificationRequest): Promise\<void\>](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)       | 发布通知。  |

## 开发步骤

1. 导入模块。

    <!-- @[specified_customized_ringtone_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) --> 
    
    ``` TypeScript
    import { notificationManager } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { contextConstant, common } from '@kit.AbilityKit';
    import { fileIo as fs, fileUri } from '@kit.CoreFileKit';
    
    const TAG: string = '[SpecifiedCustomizedRingtone]';
    const DOMAIN_NUMBER: number = 0xFF00;
    const SOUND_FILE_NAME: string = 'ringtone_demo.mp3'; // 实际项目中请替换为自己的音频文件
    ```

2. 准备音频资源。

   场景一：使用应用预置的音频资源作为通知铃声。

   (1) 将音频资源放入项目的resources/rawfile目录下。<br/>
   (2) 创建发布通知的sound信息。
    <!-- @[specified_resources_rawfile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) -->
    
    ``` TypeScript
    let soundFile: string = SOUND_FILE_NAME; // 需要替换为resources/rawfile目录下对应的音频文件
    ```

   场景二：使用沙箱内音频资源作为通知铃声。

   (1) 生成沙箱内音频资源路径。
    <!-- @[specified_customized_ringtone_getAppContext](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) -->
    
    ``` TypeScript
    // 生成沙箱内音频资源路径
    const uiContext: UIContext = this.getUIContext();
    let context: Context | undefined = uiContext.getHostContext() as common.UIAbilityContext;
    if (!context) {
      hilog.error(DOMAIN_NUMBER, TAG, 'Context is not initialized.');
      return;
    }
    const applicationContext: common.ApplicationContext = context.getApplicationContext();
    applicationContext.area = contextConstant.AreaMode.EL1; // 必须在EL1沙箱下
    const sandboxDir: string = applicationContext.filesDir;
    let sandboxFilePath: string = sandboxDir + '/' + SOUND_FILE_NAME;
    ```

   (2) 将网络下载或者用户生成的音频资源放在[沙箱文件目录](../file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)EL1区域的files目录下或者其子目录下，下面示例展示了如何将resources/rawfile目录下的音频资源拷贝到指定沙箱目录。

    <!-- @[specified_customized_ringtone_copyToSandbox](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) -->
    
    ``` TypeScript
    // 拷贝resources/rawfile/目录下的音频文件到应用沙箱EL1的files目录下
    try {
      let rawFileData: Uint8Array = context.resourceManager.getRawFileContentSync(SOUND_FILE_NAME);
      if (!fs.accessSync(sandboxDir)) {
        fs.mkdirSync(sandboxDir, true);
      }
      const file = fs.openSync(sandboxFilePath, fs.OpenMode.CREATE | fs.OpenMode.WRITE_ONLY);
      fs.writeSync(file.fd, rawFileData.buffer);
      fs.closeSync(file);
      hilog.info(DOMAIN_NUMBER, TAG, 'copy file to sandbox success.');
    } catch (error) {
      hilog.error(DOMAIN_NUMBER, TAG, `copy file to sandbox error: ${JSON.stringify(error)}`);
      return;
    }
    ```

   (3) 创建发布通知的sound信息。

    <!-- @[specified_sandbox_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) --> 
    
    ``` TypeScript
    // 获取沙箱文件uri
    let sandboxFileUri: string = fileUri.getUriFromPath(sandboxFilePath)
    let soundFile: string = 'uri::' + sandboxFileUri; // 必须以uri::开头，且路径中不能包含'../'和'/..'
    ```
3. 发布携带自定义铃声的通知。

    <!-- @[specified_customized_ringtone_publish_notification](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Notification-Kit/Notification/entry/src/main/ets/filemanager/SpecifiedCustomizedRingtone.ets) --> 
    
    ``` TypeScript
    let notificationRequest: notificationManager.NotificationRequest = {
      id: 0,
      notificationSlotType: notificationManager.SlotType.SOCIAL_COMMUNICATION,
      content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
          title: 'title',
          text: 'text',
          additionalText: 'test_additionalText'
        }
      },
      sound: soundFile
    }
    
    notificationManager.publish(notificationRequest).then(() => {
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in publishing notification.');
    }).catch((err: BusinessError) => {
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
    });
    ```

## 约束限制

- 应用使用非预置的音频资源作为通知铃声，发布通知时，[NotificationRequest](../reference/apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1)携带sound字段指定的uri资源路径中不能包含"../"或者"/.."，并且必须以"uri::"开始。
- 应用使用非预置的音频资源作为通知铃声，音频资源必须放在应用沙箱EL1区域files目录下。