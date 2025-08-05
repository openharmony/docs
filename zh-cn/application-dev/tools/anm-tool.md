# anm工具
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--SE: @dongqingran; @wulong158-->
<!--TSE: @wanghong1997-->

Advanced Notification Manager（通知管理工具，简称anm）是实现通知打印、设置通知参数等功能的工具，为开发者提供基本的通知调试和测试能力，例如打印已发布通知详细信息、设置通知缓存个数、使能通知等。

## 环境要求

在使用本工具前，开发者需要先获取<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->，执行hdc shell。

当前工具仅支持在eng版本中使用，在user版本中使用会出现报错`/bin/sh: anm: inaccessible or not found.`。

## anm工具命令列表

| 命令 | 描述 |
| ---- | --- |
| help | 帮助命令，用于显示anm相关的帮助信息。 |
| dump | 打印命令，用于打印通知相关信息。 |
| setting | 设置命令，用于设置通知参数。 |

## 帮助命令（help）

  ```bash
  # 显示anm相关的帮助信息
  anm help
  ```

## 打印命令（dump）

  ```bash
  # 打印通知相关信息
  anm dump [<options>]
  ```

  **打印命令参数列表**

  | 参数             | 参数说明                           |
  | ---------------- | ---------------------------------- |
  | -A/--active      | 打印所有活跃的通知信息。             |
  | -R/--recent      | 打印最近的通知信息。                 |
  | -D/--distributed | 打印来自其他设备的分布式通知信息。   |
  | -b/--bundle      | 可选参数，设置指定的Bundle名称打印。 |
  | -u/--user-id     | 可选参数，设置指定的用户ID打印。     |
  | -h/--help        | 帮助信息。                           |

  **示例**：

  ```bash
  # 打印活跃的通知信息
  anm dump -A
  ```
  
## 设置命令（setting）

  ```bash
  # 设置通知参数
  anm setting [<options>]
  ```

  **设置命令参数列表**

  | 参数                     | 参数说明                             |
  | ------------------------ | ------------------------------------ |
  | -c/--recent-count        | 设置保存在内存中的最近通知的最大个数。 |
  | -e/--enable-notification | 设置通知使能开关。                     |
  | -k/--collaboration-switch        | 设置通知是否支持跨设备协同至指定类型设备。<br/>```anm setting -k <deviceType>:<status>```<br/>**说明：** 从API version 18开始，新增支持该命令参数。<br/>deviceType表示需要指定的设备类型。取值范围包括：wearable（智能穿戴设备）、litewearable（轻量级智能穿戴设备）、headset（可穿戴式音频设备）。<br/>status表示需要指定的跨设备协同开关状态。取值为0表示开关为关闭状态，取值为1表示开关为打开状态。
  | -b/--collaboration-switch-bundle | 设置指定应用的通知是否支持跨设备协同至指定类型设备。<br/>```anm setting -b <deviceType>:<bundleName>:<uid>:<status>```<br/>**说明：** 从API version 18开始，新增支持该命令参数。<br/>deviceType表示需要指定的设备类型。取值范围包括：wearable（智能穿戴设备）、litewearable（轻量级智能穿戴设备）、headset（可穿戴式音频设备）。<br/>status表示需要指定的跨设备协同开关状态。取值为0表示开关为关闭状态，取值为1表示开关为打开状态。|
  | -o/--collaboration-switch-slot   | 设置指定渠道的通知是否支持通知跨设备协同至指定类型设备。<br/>```anm setting -o <deviceType>:<slotType>:<status>```<br/>**说明：** 从API version 18开始，新增支持该命令参数。<br/>deviceType表示需要指定的设备类型。取值范围包括：wearable（智能穿戴设备）、litewearable（轻量级智能穿戴设备）、headset（可穿戴式音频设备）。<br/>slotType表示需要指定的通知渠道类型。 取值范围参考[SlotType](../reference/apis-notification-kit/js-apis-notificationManager.md#slottype)。<br/>status表示需要指定的跨设备协同开关状态。取值为0表示开关为关闭状态，取值为1表示开关为打开状态。|
  | -h/--help                | 帮助信息。                             |

  **示例**：

  ```bash
  # 设置保存在内存中的最近通知的最大数为100个
  anm setting -c 100

  # 设置通知跨设备协同至wearable类型设备的开关为打开状态
  anm setting -k wearable:1

  # 设置包名为example，uid为10100的应用通知跨设备协同至litewearable类型设备的开关为关闭状态
  anm setting -b litewearable:example:10100:0

  # 设置渠道类型为0的通知跨设备协同至headset类型设备的开关为打开状态
  anm setting -o headset:0:1
  ```
