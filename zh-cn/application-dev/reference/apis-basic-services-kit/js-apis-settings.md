# @ohos.settings (设置数据项名称)

本模块提供访问设置数据项的能力。

> **说明：**
>
>  - 本模块首批接口从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。 
> 
>  - 如果访问的数据项没有获取到值，表示当前系统应用没有将该数据项的值添加到数据库。

## 导入模块

```js
import settings from '@ohos.settings';
```
## domainName

提供查询的域名

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                          | 类型   | 可读 | 可写 | 说明                                                         |
|-----------------------------| ------ | ---- | ---- | ------------------------------------------------------------ |
| DEVICE_SHARED<sup>11+</sup> | string | 是   | 是   | 设备属性共享域                                          |
| USER_PROPERTY<sup>11+</sup> | string | 是   | 是   | 为用户属性域                                           |

## date(暂不支持)

提供设置时间和日期格式的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| DATE_FORMAT         | string | 是   | 是   | 日期格式。<br/>日期格式包括mm/dd/yyyy、dd/mm/yyyy和yyyy/mm/dd ，其中mm、dd和yyyy分别代表月份、日期和年份。 |
| TIME_FORMAT         | string | 是   | 是   | 时间是以12小时格式还是24小时格式显示。<br>值为 “12” 表示12小时格式；<br/>值为 ”24“ 表示24小时格式。 |
| AUTO_GAIN_TIME      | string | 是   | 是   | 是否自动从网络获取日期、时间和时区。 <br>值为true表示自动从网络获取信息；<br/>值为false表示不自动获取。 |
| AUTO_GAIN_TIME_ZONE | string | 是   | 是   | 是否自动从NITZ获取时区。 <br>值为true表示自动获取；<br/>值为false表示不自动获取。 |

## display(暂不支持)

提供设置显示效果的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                          | 类型   | 可读 | 可写 | 说明                                                                                                          |
| ----------------------------- | ------ | ---- | ---- |-------------------------------------------------------------------------------------------------------------|
| FONT_SCALE                    | string | 是   | 是   | 字体的比例因子，值为浮点数。（当前版本参数仅支持固定值查询）                                                                              |
| SCREEN_BRIGHTNESS_STATUS      | string | 是   | 是   | 屏幕亮度。该值的范围从0到255。                                                                                           |
| AUTO_SCREEN_BRIGHTNESS        | string | 是   | 是   | 是否启用屏幕亮度自动调整。<br/>值为AUTO_SCREEN_BRIGHTNESS_MODE，表示启用自动调整；<br/>值为MANUAL_SCREEN_BRIGHTNESS_MODE，表示不启用自动调整。    |
| AUTO_SCREEN_BRIGHTNESS_MODE   | number | 是   | 是   | 使用屏幕亮度自动调整时AUTO_SCREEN_BRIGHTNESS的值。                                                                        |
| MANUAL_SCREEN_BRIGHTNESS_MODE | number | 是   | 是   | 使用屏幕亮度手动调整时的AUTO_SCREEN_BRIGHTNESS值。                                                                        |
| SCREEN_OFF_TIMEOUT            | string | 是   | 是   | 设备在一段时间不活动后进入睡眠状态的等待时间（单位：ms）。                                                                              |
| DEFAULT_SCREEN_ROTATION       | string | 是   | 是   | 启用屏幕的自动旋转时，此属性无效；不启用自动旋转时，以下值可用：<br>值为0，表示屏幕旋转0度；<br>值为1，表示屏幕旋转90度；<br/>值为2，表示屏幕旋转180度；<br/>值为3，表示屏幕旋转270度。 |
| ANIMATOR_DURATION_SCALE       | string | 是   | 是   | 动画持续时间的比例因子。这会影响所有此类动画的开始延迟和持续时间。<br/>值为0，表示动画将立即结束，默认值为1。                                                  |
| TRANSITION_ANIMATION_SCALE    | string | 是   | 是   | 过渡动画的比例因子。<br/>值为0，表示禁用过渡动画。                                                                                |
| WINDOW_ANIMATION_SCALE        | string | 是   | 是   | 普通窗口动画的比例因子。<br/>值为0，表示禁用窗口动画。                                                                              |
| DISPLAY_INVERSION_STATUS      | string | 是   | 是   | 是否启用显示颜色反转。<br/>值为1，表示启用显示颜色反转；<br/>值为0，表示不启用显示颜色反转。                                                        |

## general(暂不支持)

提供设置设备常规信息的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                             | 类型   | 可读 | 可写 | 说明                                                         |
| -------------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| SETUP_WIZARD_FINISHED            | string | 是   | 是   | 是否已运行启动向导。<br>值为0，表示启动向导尚未运行；<br/>值不是0，表示启动向导已运行。 |
| END_BUTTON_ACTION                | string | 是   | 是   | 在用户不在呼叫中时，用户按下呼叫结束按钮会发生的情况。<br/>值为0，表示没有任何反应；<br/>值为1，表示显示主屏幕；<br/>值为2，表示设备进入睡眠状态，屏幕锁定；<br/>值为3，表示显示主屏幕。如果用户已在主屏幕上，设备将进入睡眠状态。 |
| ACCELEROMETER_ROTATION_STATUS    | string | 是   | 是   | 是否使用加速计更改屏幕方向，即是否启用自动旋转。<br>值为1，表示启用加速度计；<br/>值为0，表示不启用加速计。 |
| DEVICE_PROVISION_STATUS          | string | 是   | 是   | 是否预配设备。<br>在具有单个系统用户的多用户设备上，当值为true时，屏幕可能会被锁定。此外，其他功能无法在系统用户上启动，除非它们被标记为在屏幕锁定上显示。 |
| HDC_STATUS                       | string | 是   | 是   | 是否启用USB设备上的硬盘控制器（HDC）。<br>值为true，表示启用HDC；<br/>值为false，表示不启用HDC。 |
| BOOT_COUNTING                    | string | 是   | 是   | 设备开机后的启动操作数。                                     |
| CONTACT_METADATA_SYNC_STATUS     | string | 是   | 是   | 是否启用联系人元数据同步。<br>值为true，表示启用同步；<br/>值为false，表示不启用同步。 |
| DEVICE_NAME                      | string | 是   | 是   | 设备名称。                                                   |
| USB_STORAGE_STATUS               | string | 是   | 是   | 是否启用USB大容量存储。<br>值为true，表示启用USB大容量存储；<br/>值为false，表示不启用USB大容量存储。 |
| DEBUGGER_WAITING                 | string | 是   | 是   | 设备在启动应用程序进行调试时是否等待调试器进行调试。<br>值为1，表示设备等待调试器；<br/>值为0，表示系统不会等待调试器，因此应用程序会正常运行。 |
| DEBUG_APP_PACKAGE                | string | 是   | 是   | 要调试的应用程序的bundle name。                              |
| ACCESSIBILITY_STATUS             | string | 是   | 是   | 是否启用辅助功能。<br>值为1，表示启用辅助功能；<br/>值为0，表示不启用辅助功能。 |
| ACTIVATED_ACCESSIBILITY_SERVICES | string | 是   | 是   | 已激活的辅助功能的列表。                                     |
| GEOLOCATION_ORIGINS_ALLOWED      | string | 是   | 是   | 浏览器可以使用的默认地理位置。多个地理位置由空格分隔。       |
| SKIP_USE_HINTS                   | string | 是   | 是   | 应用程序是否应在首次启动时尝试跳过所有介绍性提示。这适用于临时用户或熟悉环境的用户。<br>值为1，表示应用程序将尝试在第一次启动时跳过所有介绍性提示；<br/>值为0，表示应用程序不会在首次启动时跳过介绍性提示。 |
| TOUCH_EXPLORATION_STATUS         | string | 是   | 是   | 是否启用触摸浏览。<br>值为1，表示启用触摸浏览；<br/>值为0，表示不启用触摸浏览。 |

## input(暂不支持)

提供设置有关输入法信息的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                                 | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| DEFAULT_INPUT_METHOD                 | string | 是   | 是   | 默认输入法及其ID。                                           |
| ACTIVATED_INPUT_METHOD_SUB_MODE      | string | 是   | 是   | 默认输入法键盘类型及其ID。                                   |
| ACTIVATED_INPUT_METHODS              | string | 是   | 是   | 已激活的输入法的列表。<br>该列表是一个字符串，由已激活的输入法的ID和输入法键盘类型组成。输入法ID后添加冒号':'连接，输入法的键盘类型后添加分号';'连接。用ima代表输入法ID，keyboardType代表键盘类型，示例格式是ima0:keyboardType0;keyboardType1;ima1:ima2:keyboardTypes0。 |
| SELECTOR_VISIBILITY_FOR_INPUT_METHOD | string | 是   | 是   | 输入法选择器是否可见。<br>值为1，表示输入法选择器可见；<br/>值为0，表示输入法选择器不可见。 |
| AUTO_CAPS_TEXT_INPUT                 | string | 是   | 是   | 是否为文本编辑器启用自动大写。<br>值为0，表示不启用自动大写；<br/>值为1，表示启用自动大写。 |
| AUTO_PUNCTUATE_TEXT_INPUT            | string | 是   | 是   | 是否为文本编辑器启用自动标点符号。自动标点符号使文本编辑器能够将两个空格转换为句点'.'和空格。<br>值为0，表示不启用自动标点符号；<br/>值为1，表示启用自动标点符号。 |
| AUTO_REPLACE_TEXT_INPUT              | string | 是   | 是   | 是否为文本编辑器启用自动更正。自动更正使文本编辑器能够更正拼写错误。<br>值为0，表示不启用自动更正；<br/>值为1，表示启用自动更正。 |
| SHOW_PASSWORD_TEXT_INPUT             | string | 是   | 是   | 是否在文本编辑器中启用密码显示。密码显示使文本编辑器能够在用户键入密码字符时显示密码字符。<br>值为0，表示不启用密码显示；<br/>值为1，表示启用密码显示。 |

## network(暂不支持)

提供设置网络信息的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                     | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| DATA_ROAMING_STATUS      | string | 是   | 是   | 是否启用数据漫游。<br>值为true，表示启用数据漫游；<br/>值为false，表示不启用数据漫游。 |
| HTTP_PROXY_CFG           | string | 是   | 是   | 全局 HTTP 代理的主机名和端口号。主机名和端口号由冒号':'分隔。 |
| NETWORK_PREFERENCE_USAGE | string | 是   | 是   | 要使用的网络的用户首选项。                                   |

## phone(暂不支持)

提供设置来电和去电接听方式的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称               | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| RTT_CALLING_STATUS | string | 是   | 是   | 是否启用实时文本 (RTT) 呼叫。启用，来电和去电在设备和运营商支持时作为 RTT 呼叫应答。 <br> 值为1，表示启用RTT 呼叫； <br/> 值为0，表示不启用 RTT 呼叫。 |

## sound(暂不支持)

提供设置声音效果的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                         | 类型   | 可读 | 可写 | 说明                                                         |
| ---------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| VIBRATE_WHILE_RINGING        | string | 是   | 是   | 设备在来电响铃时是否振动。此属性将由电话和设置应用程序使用。 该值是布尔类型，仅影响设备因来电而响铃的情况，不影响任何其他应用程序或场景。 |
| DEFAULT_ALARM_ALERT          | string | 是   | 是   | 系统默认告警的存储区域。                                     |
| DTMF_TONE_TYPE_WHILE_DIALING | string | 是   | 是   | 拨号时播放的双音多频 (DTMF) 音的类型。 <br>值为0表示常规的短音效，<br/>值为1表示长音效。 |
| DTMF_TONE_WHILE_DIALING      | string | 是   | 是   | 拨号时是否播放 DTMF 音。<br>值为1，表示播放 DTMF 音；<br/>值为0，表示不播放。 |
| AFFECTED_MODE_RINGER_STREAMS | string | 是   | 是   | 哪些音频流受振铃模式和请勿打扰 (DND) 模式更改的影响。希望特定的音频流受到振铃模式和 DDN 模式变化的影响，请将对应比特位设置为1。 |
| AFFECTED_MUTE_STREAMS        | string | 是   | 是   | 受静音模式影响的音频流。希望特定音频流在静音模式下保持静音，请将相应位设置为1。 |
| DEFAULT_NOTIFICATION_SOUND   | string | 是   | 是   | 系统默认通知音的存储区域。                                   |
| DEFAULT_RINGTONE             | string | 是   | 是   | 系统默认铃声的存储区域。                                     |
| SOUND_EFFECTS_STATUS         | string | 是   | 是   | 声音功能是否可用。<br>值为0表示不可用； <br/>值为1表示可用   |
| VIBRATE_STATUS               | string | 是   | 是   | 设备是否为事件振动。该参数在系统内部使用。 <br>值为1，表示设备会因事件而振动； <br/>值为0，表示设备不因事件振动。 |
| HAPTIC_FEEDBACK_STATUS       | string | 是   | 是   | 设备是否启用触觉反馈。<br/>值为true，表示启用触觉反馈；<br/>值为false，表示不启用触觉反馈。 |

## TTS(暂不支持)

提供设置文本到语音 (TTS) 转换信息的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                | 类型   | 可读 | 可写 | 说明                                                         |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| DEFAULT_TTS_PITCH   | string | 是   | 是   | 文本转语音 (TTS) 引擎的默认音高。<br>其中100=1x，该值设置为200，表示频率是正常声音频率的两倍。 |
| DEFAULT_TTS_RATE    | string | 是   | 是   | TTS 引擎的默认语速。<br>其中100=1x。                         |
| DEFAULT_TTS_SYNTH   | string | 是   | 是   | 默认TTS引擎。                                                |
| ENABLED_TTS_PLUGINS | string | 是   | 是   | 用于TTS的已激活插件包列表， 多个插件包以空格分隔。           |


## wireless(暂不支持)

提供设置无线网络信息的数据项。

### 属性

**系统能力：** SystemCapability.Applications.Settings.Core

| 名称                              | 类型   | 可读 | 可写 | 说明                                                         |
| --------------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| BLUETOOTH_DISCOVER_ABILITY_STATUS | string | 是   | 是   | 设备是否可以被其他设备通过蓝牙发现或连接。<br>值为0表示设备不可以被连接或发现；<br/>值为1表示设备可以被连接但不可以被发现；<br/>值为2表示设备可以被连接和发现。 |
| BLUETOOTH_DISCOVER_TIMEOUT        | string | 是   | 是   | 可以通过蓝牙发现设备的持续时间（以秒为单位）。<br>这段时间之后，设备不可以被蓝牙搜寻到。 |
| AIRPLANE_MODE_RADIOS              | string | 是   | 是   | 启用飞行模式时要禁用的无线电信号列表。 <br>多个无线电信号用逗号 (,) 分隔。取值包括以下常量：BLUETOOTH_RADIO、 CELL_RADIO、 NFC_RADIO、 WIFI_RADIO。 |
| BLUETOOTH_RADIO                   | string | 是   | 否   | 常量，作为AIRPLANE_MODE_RADIOS的取值时表示蓝牙在飞行模式下禁用。 |
| CELL_RADIO                        | string | 是   | 否   | 常量，作为AIRPLANE_MODE_RADIOS的取值时表示蜂窝无线电在飞行模式下禁用。 |
| NFC_RADIO                         | string | 是   | 否   | 常量，作为AIRPLANE_MODE_RADIOS的取值时表示NFC在飞行模式下禁用。 |
| WIFI_RADIO                        | string | 是   | 否   | 常量，作为AIRPLANE_MODE_RADIOS的取值时表示Wi-Fi在飞行模式下禁用。 |
| BLUETOOTH_STATUS                  | string | 是   | 是   | 蓝牙是否可用。 <br>值为true表示蓝牙可用；<br/>值为false表示蓝牙不可用。 |
| OWNER_LOCKDOWN_WIFI_CFG           | string | 是   | 是   | 是否应锁定由设备所有者的应用程序创建的Wi-Fi配置。<br>值为true表示Wi-Fi配置应该被锁定；<br/>值为false表示不应该被锁定。 |
| WIFI_DHCP_MAX_RETRY_COUNT         | string | 是   | 是   | 尝试从DHCP服务器获取 IP 地址的最大次数。                     |
| WIFI_TO_MOBILE_DATA_AWAKE_TIMEOUT | string | 是   | 是   | Wi-Fi连接断开后等待移动数据连接建立时保持唤醒锁的最长时间。  |
| WIFI_STATUS                       | string | 是   | 是   | Wi-Fi是否可用。<br>值为true表示Wi-Fi可用；<br/>值为false表示Wi-Fi不可用。 |
| WIFI_WATCHDOG_STATUS              | string | 是   | 是   | Wi-Fi的WatchDog是否可用。 <br>值为true表示可用；<br/>值为false表示不可用。 |


## settings.setValue<sup>10+</sup>

setValue(context: Context, name: string, value: string, callback: AsyncCallback\<boolean>): void

将数据项名称及数据项的值保存到数据库中，使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**： ohos.permission.MANAGE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                 | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string                  | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value    | string                  | 是   | 数据项值。取值范围随业务变动。                               |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回true表示操作成功，否则操作失败。               |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故setValue方法将更新该数据项的值）
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', (status) => {
  console.log('Callback return whether value is set.');
});
```

## settings.setValue<sup>10+</sup>

setValue(context: Context, name: string, value: string): Promise\<boolean>

将数据项名称及数据项的值保存到数据库中。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**： ohos.permission.MANAGE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name    | string  | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value   | string  | 是   | 数据项值。取值范围随业务变动。                               |

**返回值**：

| 类型              | 说明                                               |
| ----------------- | -------------------------------------------------- |
| Promise\<boolean> | Promise对象。返回true表示操作成功，否则返回false。 |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故setValue方法将更新该数据项的值）
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100').then((status) => {
  console.log('Callback return whether value is set.');
});
```

## settings.setValue<sup>11+</sup>

setValue(context: Context, name: string, value: string, domainName: string): Promise\<boolean>

将数据项名称及数据项的值保存到数据库中。使用 Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**：  
写入DEVICE_SHARED、USER_PROPRERTY域  
需要权限ohos.permission.MANAGE_SETTINGS，仅系统应用可用。  
写入USER_SECURITY域  
需要权限ohos.permission.MANAGE_SECURE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                                                                                                                                                                                                                                  |
| -------- | ---------------------- | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context  | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。                                                                                                                                                                |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。                                                                                                                                                                                                      |
| value    | string                 | 是   | 数据项值。取值范围随业务变动。                                                                                                                                                                                                                                                     |
|domainName| string                 | 是   | 指定要设置的域名                <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;表示设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放） |

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象。返回true表示操作成功，否则返回false。 |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故setValue方法将更新该数据项的值）
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', settings.domainName.DEVICE_SHARED).then((status) => {
  console.log(`callback:return whether value is set.`)
});
```

## settings.getValue<sup>10+</sup>

getValue(context: Context, name: string, callback: AsyncCallback\<string>): void

获取数据库中指定数据项的值。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| callback | AsyncCallback\<string> | 是   | 使用callback方式获取数据项的值。                             |

**示例**：

```js
import settings from '@ohos.settings';
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, (err, value) => {
  if (err) {
    console.error(`Failed to get the setting. ${err.message} `);
    return;
  }
  console.log(`callback:value -> ${value}`)
});
```

## settings.getValue<sup>10+</sup>

getValue(context: Context, name: string): Promise\<string>

获取数据库中指定数据项的值。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name    | string  | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象。返回获得的数据项的值。 |

**示例**：

```js
import settings from '@ohos.settings';
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS).then((value) => {
  console.log(`promise:value -> ${value}`)
});
```

## settings.getValue<sup>11+</sup>

getValue(context: Context, name: string, domainName: string): Promise\<string>;

获取数据库中指定数据项的值。使用 Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**：   
读取USER_SECURITY域  
需要权限ohos.permission.MANAGE_SECURE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
|domainName| string                 | 是   | 指定要设置的域名                <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放）|

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象。返回获得的数据项的值。 |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故getValue方法将更新该数据项的值）
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, settings.domainName.DEVICE_SHARED).then((value) => {
  console.log(`Promise:value -> ${value}`);
});
```

## settings.getValueSync<sup>10+</sup>

getValueSync(context: Context, name: string, defValue: string): string;

获取数据项的值。此方法相较getValue为同步方法。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型    | 必填 | 说明                                                         |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| context  | Context | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string  | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| defValue | string  | 是   | 默认值。由开发者设置，当未从数据库中查询到该数据时，表示返回该默认值。 |

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| string | 返回数据项的值。 |

**示例**：

```js
import settings from '@ohos.settings';

// 获取数据项亮度的值（该数据项在数据库中已存在）
const context: Context =  getContext(this);
let value = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
```

## settings.getValueSync<sup>11+</sup>

getValueSync(context: Context, name: string, defValue: string, domainName: string): string;

获取数据项的值。此方法相较getValue为同步方法。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**：   
读取USER_SECURITY域  
需要权限ohos.permission.MANAGE_SECURE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名        | 类型                   | 必填 | 说明                                                         |
|------------| ---------------------- | ---- | ------------------------------------------------------------ |
| context    | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name       | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| defValue   | string                 | 是   | 数据项值。取值范围随业务变动。                   |
| domainName | string                 | 是   | 指定要设置的域名               <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放）|


**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| string           | 返回数据项的值                       |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在）
const context: Context =  getContext(this);
let value = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100',  settings.domainName.DEVICE_SHARED);
```

## settings.setValueSync<sup>10+</sup>

setValueSync(context: Context, name: string, value: string): boolean

设置数据项的值。此方法相较setValue为同步方法。

如果数据库中已经存在该数据项，则setValueSync方法将更新该数据项的值；如果数据库中尚未存在该数据项，则setValueSync方法将向数据库中插入该数据项。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**： ohos.permission.MANAGE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名  | 类型    | 必填 | 说明                                                         |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name    | string  | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value   | string  | 是   | 数据项的具体数值。取值范围随业务变动。                       |

**返回值**：

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回设置数据项的值是否成功的结果。true表示设置成功，false表示设置失败。 |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故setValueSync方法将更新该数据项的值）
const context: Context =  getContext(this);
let ret = settings.setValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100');
```

## settings.setValueSync<sup>11+</sup>

setValueSync(context: Context, name: string, value: string, domainName: string): boolean

设置数据项的值。此方法相较setValue为同步方法。

如果数据库中已经存在该数据项，则setValueSync方法将更新该数据项的值；如果数据库中尚未存在该数据项，则setValueSync方法将向数据库中插入该数据项。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**需要权限**：  
写入DEVICE_SHARED、USER_PROPRERTY域  
需要权限ohos.permission.MANAGE_SETTINGS，仅系统应用可用。  
写入USER_SECURITY域  
需要权限ohos.permission.MANAGE_SECURE_SETTINGS，仅系统应用可用。

**参数**：

| 参数名     | 类型                   | 必填 | 说明                                                         |
|---------| ---------------------- | ---- | ------------------------------------------------------------ |
| context | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name    | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value   | string                 | 是   | 数据项值。取值范围随业务变动。                   |
| domainName | string                 | 是   | 指定要设置的域名                <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放）|

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| boolean          | 返回设置数据项的值是否成功发结果。返回true表示设置成功，false表示设置失败。 |

**示例**：

```js
import settings from '@ohos.settings';

// 更新数据项亮度的值（该数据项在数据库中已存在，故setValueSync方法将更新该数据项的值）
const context: Context =  getContext(this);
let ret = settings.setValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', settings.domainName.DEVICE_SHARED);
```

## settings.registerKeyObserver<sup>11+</sup>

registerKeyObserver(context: Context, name: string, domainName: string, observer:AsyncCallback\<void>): boolean

用于在指定上下文中注册一个观察者，以便于在指定域名中观察指定的域名。当该键值发生变化时，将调用注册的回调函数，如果成功注册则返回true，否则返回false。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
|domainName| string                 | 是   | 指定要设置的域名               <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放）|
|observer  |  AsyncCallback\<void>  | 是   | 使用collback方式获取数据项的值。                   |

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| boolean | 返回设置数据项的值是否成功的结果，true表示设置成功，false表示设置失败。 |

**示例**：

```js
import settings from '@ohos.settings';

const context: Context =  getContext(this);
settings.registerKeyObserver(context, settings.display.SCREEN_BRIGHTNESS_STATUS, settings.domainName.DEVICE_SHARED, (err, val) => {
  if (err) {
    console.error(`Failed to get the setting. ${err.message} `);
    return;
  }
  console.log(`callback:value -> ${JSON.stringify(val)}`)
  let value:string = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
  console.log(`Promise:value -> ${value}`);
});
```

## settings.unregisterKeyObserver<sup>11+</sup>

unregisterKeyObserver(context: Context, name: string, domainName: string): boolean

同步方法，进行注销指定域名下对指定键的监视器。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | 是   | 应用上下文（仅支持UIAbilityContext和ExtensionContext）。<br />Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-application-context.md)。 |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value    | string                 | 是   | 数据项值。取值范围随业务变动。                   |
|domainName| string                 | 是   | 指定要设置的域名               <br> - domainName为domainName.DEVICE_SHARED,<br>&nbsp;&nbsp;&nbsp;设备属性共享域。<br>- domainName为domainName.USER_PROPRERTY,<br>&nbsp;&nbsp;&nbsp;表示为用户属性域。 <br> - domainName为domainName.USER_SECURITY,<br>&nbsp;&nbsp;&nbsp;表示为用户安全属性域（仅对系统应用开放）|

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| boolean | 返回设置数据项的值是否成功的结果，true表示设置成功，false表示设置失败。 |

**示例**：

```js
import settings from '@ohos.settings';

const context: Context =  getContext(this);
let ret = settings.setValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS,  settings.domainName.DEVICE_SHARED);
```

## settings.enableAirplaneMode(暂不支持)

enableAirplaneMode(enable: boolean, callback: AsyncCallback\<void>): void

启用或禁用飞行模式。使用callback异步回调。

此接口暂不支持。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型                 | 必填 | 说明                                            |
| -------- | -------------------- | ---- | ----------------------------------------------- |
| enable   | boolean              | 是   | 是否开启飞行模式。true表示开启，false表示禁用。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。                                      |

**示例**：

```js
let isEnabled :boolean = true;
settings.enableAirplaneMode(isEnabled, (err:Error) => {
    if (err) {
        console.log('Failed to enable AirplaneMode.');
        return;
    }
    console.log('Return true if enable.');
})
```

## settings.enableAirplaneMode(暂不支持)

enableAirplaneMode(enable: boolean): Promise\<void>

启用或禁用飞行模式。使用Promise异步回调。

此接口暂不支持。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名 | 类型    | 必填 | 说明                                            |
| ------ | ------- | ---- | ----------------------------------------------- |
| enable | boolean | 是   | 是否开启飞行模式。true表示开启，false表示禁用。 |

**返回值**：

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例**：

```js
let isEnabled :boolean = true;
settings.enableAirplaneMode(isEnabled).then(() => {
  console.log('Succeeded in enabling AirplaneMode.');
}).catch((err:Error) => {
  console.log(`Failed to enable AirplaneMode. Cause: ${err}`);
})
```

## settings.canShowFloating(暂不支持)

canShowFloating(callback: AsyncCallback\<boolean>): void

检查应用是否能够以悬浮窗形式显示。使用callback异步回调。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。<br/>返回true，表示应用能够以悬浮窗形式显示；返回false，则表示不能。 |

**示例**：

```js
settings.canShowFloating((err:Error, status: boolean) => {
  if (err) {
    console.error(`Failed to Checks whether a specified application can show as float window ${err.message} `);
    return;
  }
  console.log('Checks whether a specified application can show as float window.');
});
```

## settings.canShowFloating(暂不支持)

canShowFloating(): Promise\<boolean>

检查应用是否能够以悬浮窗形式显示。使用Promise异步回调。

**系统能力**：SystemCapability.Applications.Settings.Core

**返回值**：

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象。<br/>返回true，表示应用能够以悬浮窗形式显示；返回false，则表示不能。 |

**示例**：

```js
settings.canShowFloating().then((status:boolean) => {
    console.log('Checks whether a specified application can show as float window.');
});
```

## settings.getUriSync<sup>8+</sup>(暂不支持)

getUriSync(name: string): string

获取数据项的URI。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |

**返回值**：

| 类型   | 说明          |
| ------ | ------------- |
| string | 数据项的URI。 |

**示例**：

```js
// 获取数据项的URI
let uriVar:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
```

## settings.getURI<sup>(deprecated)</sup>(暂不支持)

getURI(name: string, callback: AsyncCallback\<object>): void

获取数据项的URI。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，此接口不再提供代替接口。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| name     | string                 | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| callback | AsyncCallback\<object> | 是   | 回调函数。获取数据项的URI。                                  |

**示例**：

```js
settings.getURI(settings.display.SCREEN_BRIGHTNESS_STATUS, (uri:string) => {
    console.log(`callback:uri -> ${JSON.stringify(uri)}`)
})
```

## settings.getURI<sup>(deprecated)</sup>(暂不支持)

getURI(name: string): Promise\<object>

获取数据项的URI。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，此接口不再提供代替接口。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |

**返回值**：

| 类型             | 说明                                 |
| ---------------- | ------------------------------------ |
| Promise\<object> | Promise对象。返回获取的数据项的URI。 |

**示例**：

```js
settings.getURI(settings.display.SCREEN_BRIGHTNESS_STATUS).then((uri:string) => {
    console.log(`promise:uri -> ${JSON.stringify(uri)}`)
})
```



## settings.getValue<sup>(deprecated)</sup>

getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void

获取数据库中指定数据项的值。使用callback异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getValue()](#settingsgetvalue10)。

**模型约束**：此接口仅可在FA模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| callback          | AsyncCallback\<object>                                       | 是   | 使用callback方式获取数据项的值。                             |

**示例**：

```js
import featureAbility from '@ohos.ability.featureAbility';

let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
settings.getValue(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, (err:Error, value:string) => {
    if (err) {
        console.error(`Failed to get the setting. ${err.message} `);
        return;
    }
    console.log(`callback:value -> ${JSON.stringify(value)}`)
});
```

## settings.getValue<sup>(deprecated)</sup>

getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>

获取数据库中指定数据项的值。使用Promise异步回调。

> **说明：**
>
> 从 API version 7开始支持，从API version 9开始废弃，推荐使用[getValue()](#settingsgetvalue10-1)。

**模型约束**：此接口仅可在FA模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br> - 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |

**返回值**：

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<object> | Promise对象。返回获得的数据项的值。 |

**示例**：

```js
import featureAbility from '@ohos.ability.featureAbility';

let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
settings.getValue(helper, settings.display.SCREEN_BRIGHTNESS_STATUS).then((value:string) => {
    console.log(`promise:value -> ${JSON.stringify(value)}`)
});
```

## settings.getValueSync<sup>(deprecated)</sup>

getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string

获取数据项的值。此方法相较getValue为同步方法。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃，推荐使用[getValueSync()](#settingsgetvaluesync10)。

**模型约束**：此接口仅可在FA模型下使用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| defValue          | string                                                       | 是   | 默认值。由开发者设置，当未从数据库中查询到该数据时，表示返回该默认值。 |

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| string | 返回数据项的值。 |

**示例**：

```js
import featureAbility from '@ohos.ability.featureAbility';

//获取数据项亮度的值（该数据项在数据库中已存在）
let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
let value:string = settings.getValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
```

## settings.setValueSync<sup>(deprecated)</sup>

setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean

设置数据项的值。此方法相较setValue为同步方法。

如果数据库中已经存在该数据项，则setValueSync方法将更新该数据项的值；如果数据库中尚未存在该数据项，则setValueSync方法将向数据库中插入该数据项。

> **说明：**
>
> 从 API version 8开始支持，从API version 9开始废弃，推荐使用[setValueSync()](#settingssetvaluesync10)。

**模型约束**：此接口仅可在FA模型下使用。

**需要权限**：ohos.permission.MANAGE_SETTINGS，仅系统应用可用。

**系统能力**：SystemCapability.Applications.Settings.Core

**参数**：

| 参数名            | 类型                                                         | 必填 | 说明                                                         |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | 是   | 数据管理辅助类。                                             |
| name              | string                                                       | 是   | 数据项的名称。数据项名称分为以下两种：<br>- 上述任意一个数据库中已存在的数据项。<br>- 开发者自行添加的数据项。 |
| value             | string                                                       | 是   | 数据项的具体数值。取值范围随业务变动。                       |

**返回值**：

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回设置数据项的值是否成功的结果。true表示设置成功，false表示设置失败。 |

**示例**：

```js
import featureAbility from '@ohos.ability.featureAbility';

//更新数据项亮度的值（该数据项在数据库中已存在，故setValueSync方法将更新该数据项的值）
let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
let ret:string = settings.setValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '100');
```