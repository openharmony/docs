# @ohos.ability.wantConstant    
wantConstant模块提供want中操作want常数和解释Flags说明的能力。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wantConstant from '@ohos.ability.wantConstant'    
```  
    
## Action<sup>(deprecated)</sup>    
want操作的常数。用于表示要执行的通用操作。    
从API version 6 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_HOME<sup>(deprecated)</sup> | ohos.want.action.home | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示返回原点的操作。    |  
| ACTION_DIAL<sup>(deprecated)</sup> | ohos.want.action.dial | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动显示小键盘的页面功能的操作  |  
| ACTION_SEARCH<sup>(deprecated)</sup> | ohos.want.action.search | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动页面搜索功能的操作。 |  
| ACTION_WIRELESS_SETTINGS<sup>(deprecated)</sup> | ohos.settings.wireless | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动提供无线网络设置的页面功能的操作，例如，Wi-Fi选项。 |  
| ACTION_MANAGE_APPLICATIONS_SETTINGS<sup>(deprecated)</sup> | ohos.settings.manage.applications | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动管理已安装应用程序的页面功能的操作。  |  
| ACTION_APPLICATION_DETAILS_SETTINGS<sup>(deprecated)</sup> | ohos.settings.application.details | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动显示指定应用程序详细信息的页面功能的操作。 |  
| ACTION_SET_ALARM<sup>(deprecated)</sup> | ohos.want.action.setAlarm | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动页面功能以设置闹钟的操作。  |  
| ACTION_SHOW_ALARMS<sup>(deprecated)</sup> | ohos.want.action.showAlarms | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动显示所有警报的页面功能的操作时钟。 |  
| ACTION_SNOOZE_ALARM<sup>(deprecated)</sup> | ohos.want.action.snoozeAlarm | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动用于使闹钟睡眠的页面功能的操作。  |  
| ACTION_DISMISS_ALARM<sup>(deprecated)</sup> | ohos.want.action.dismissAlarm | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动删除闹钟的页面功能的操作。  |  
| ACTION_DISMISS_TIMER<sup>(deprecated)</sup> | ohos.want.action.dismissTimer | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动页面功能以关闭计时器的操作。 |  
| ACTION_SEND_SMS<sup>(deprecated)</sup> | ohos.want.action.sendSms | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动发送sms的页面功能的操作。 |  
| ACTION_CHOOSE<sup>(deprecated)</sup> | ohos.want.action.choose | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示启动页面功能以打开联系人或图片的操作。  |  
| ACTION_IMAGE_CAPTURE<sup>(deprecated)</sup> | ohos.want.action.imageCapture | 从API version 8 开始支持，从API version 9 开始废弃。<br>指示启动页面拍照功能的操作。 |  
| ACTION_VIDEO_CAPTURE<sup>(deprecated)</sup> | ohos.want.action.videoCapture | 从API version 8 开始支持，从API version 9 开始废弃。<br> 指示启动页面功能以拍摄视频的操作。   |  
| ACTION_SELECT<sup>(deprecated)</sup> | ohos.want.action.select | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示显示应用程序选择对话框的操作。 |  
| ACTION_SEND_DATA<sup>(deprecated)</sup> | ohos.want.action.sendData | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示发送单个数据记录的操作。  |  
| ACTION_SEND_MULTIPLE_DATA<sup>(deprecated)</sup> | ohos.want.action.sendMultipleData | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示发送多个数据记录的操作。  |  
| ACTION_SCAN_MEDIA_FILE<sup>(deprecated)</sup> | ohos.want.action.scanMediaFile | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示请求媒体扫描仪扫描文件并将文件添加到媒体库的操作。 |  
| ACTION_VIEW_DATA<sup>(deprecated)</sup> | ohos.want.action.viewData | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示查看数据的操作。 |  
| ACTION_EDIT_DATA<sup>(deprecated)</sup> | ohos.want.action.editData | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示编辑数据的操作。    |  
| INTENT_PARAMS_INTENT<sup>(deprecated)</sup> | ability.want.params.INTENT | 从API version 6 开始支持，从API version 9 开始废弃。<br> 指示用行为选择器来展示选择的操作。。 |  
| INTENT_PARAMS_TITLE<sup>(deprecated)</sup> | ability.want.params.TITLE | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示与行为选择器一起使用时的字符序列对话框标题。  |  
| ACTION_FILE_SELECT<sup>(deprecated)</sup> | ohos.action.fileSelect | 从API version 7 开始支持，从API version 9 开始废弃。<br>指示选择文件的操作。  |  
| PARAMS_STREAM<sup>(deprecated)</sup> | ability.params.stream | 从API version 7 开始支持，从API version 9 开始废弃。<br>指示发送数据时与目标关联的数据流的URI。对应的value必须是string类型的数组。  |  
| ACTION_APP_ACCOUNT_OAUTH<sup>(deprecated)</sup> | ohos.account.appAccount.action.oauth | 从API version 8 开始支持，从API version 9 开始废弃。<br>指示提供oauth服务的操作。  |  
    
## Entity<sup>(deprecated)</sup>    
want实体的常数。用于表示目标Ability额外的类别信息。    
从API version 6 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ENTITY_DEFAULT<sup>(deprecated)</sup> | entity.system.default | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示默认实体，如果未指定实体，则使用该实体。 |  
| ENTITY_HOME<sup>(deprecated)</sup> | entity.system.home | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示主屏幕实体。 |  
| ENTITY_VOICE<sup>(deprecated)</sup> | entity.system.voice | 从API version 6 开始支持，从API version 9 开始废弃。<br>表示语音交互实体。  |  
| ENTITY_BROWSABLE<sup>(deprecated)</sup> | entity.system.browsable | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示浏览器类别。 |  
| ENTITY_VIDEO<sup>(deprecated)</sup> | entity.system.video | 从API version 6 开始支持，从API version 9 开始废弃。<br> 指示视频类别。    |  
    
## Flags<sup>(deprecated)</sup>    
Flags说明。用于表示处理Want的方式。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantConstant/wantConstant#Flags替代。    
    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLAG_AUTH_READ_URI_PERMISSION<sup>(deprecated)</sup> | 0x00000001 | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantConstant/wantConstant.Flags#FLAG_AUTH_READ_URI_PERMISSION替代。<br>指示对URI执行读取操作的授权。 |  
| FLAG_AUTH_WRITE_URI_PERMISSION<sup>(deprecated)</sup> | 0x00000002 | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantConstant/wantConstant.Flags#FLAG_AUTH_WRITE_URI_PERMISSION替代。<br>指示对URI执行写入操作的授权。 |  
| FLAG_ABILITY_FORWARD_RESULT<sup>(deprecated)</sup> | 0x00000004 | 从API version 6 开始支持，从API version 9 开始废弃。<br>将结果返回给元能力。 |  
| FLAG_ABILITY_CONTINUATION<sup>(deprecated)</sup> | 0x00000008 | 从API version 6 开始支持，从API version 9 开始废弃。<br>确定是否可以将本地设备上的功能迁移到远程设备。 |  
| FLAG_NOT_OHOS_COMPONENT<sup>(deprecated)</sup> | 0x00000010 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指定组件是否属于OHOS。 |  
| FLAG_ABILITY_FORM_ENABLED<sup>(deprecated)</sup> | 0x00000020 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指定是否启动某个能力。 |  
| FLAG_ABILITYSLICE_MULTI_DEVICE<sup>(deprecated)</sup> | 0x00000100 | 从API version 6 开始支持，从API version 9 开始废弃。<br>支持分布式调度系统中的多设备启动。 |  
| FLAG_START_FOREGROUND_ABILITY<sup>(deprecated)</sup> | 0x00000200 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示无论主机应用程序是否已启动，都将启动使用服务模板的功能。 |  
| FLAG_INSTALL_ON_DEMAND<sup>(deprecated)</sup> | 0x00000800 | 从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.app.ability.wantConstant/wantConstant.Flags#FLAG_INSTALL_ON_DEMAND替代。<br>如果未安装指定的功能，请安装该功能。 |  
| FLAG_INSTALL_WITH_BACKGROUND_MODE<sup>(deprecated)</sup> | 0x80000000 | 从API version 6 开始支持，从API version 9 开始废弃。<br>如果未安装，使用后台模式安装该功能。 |  
| FLAG_ABILITY_CLEAR_MISSION<sup>(deprecated)</sup> | 0x00008000 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示清除其他任务的操作。可以为传递给 **FeatureAbility** 中[startAbility](js-apis-ability-featureAbility.md#startability)方法的**Want**设置此标志，并且必须与**flag_ABILITY_NEW_MISSION**一起使用。 |  
| FLAG_ABILITY_NEW_MISSION<sup>(deprecated)</sup> | 0x10000000 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示在历史任务堆栈上创建任务的操作。  |  
| FLAG_ABILITY_MISSION_TOP<sup>(deprecated)</sup> | 0x20000000 | 从API version 6 开始支持，从API version 9 开始废弃。<br>指示如果启动能力的现有实例已位于任务堆栈的顶部，则将重用该实例。否则，将创建一个新的能力实例。 |  
