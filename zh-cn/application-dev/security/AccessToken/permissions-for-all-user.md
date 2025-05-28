# 开放权限（用户授权）

此列表内所有权限均为用户授权（user_grant）的开放权限，面向所有应用开放。

该类型权限不仅需要在安装包中申请权限，还需要在应用动态运行时，通过发送弹窗的方式请求用户授权。在用户手动允许授权后，应用才会真正获取相应权限，从而成功访问操作目标对象。

<!--Del-->
> **说明：**
> 权限级别为normal的权限，不涉及ACL使能字段。
<!--DelEnd-->

## 申请方式

以下权限的授权方式均为[user_grant（用户授权）](app-permission-mgmt-overview.md#user_grant用户授权)，申请方式请参考[声明权限](declare-permissions.md) &gt; [向用户申请授权](request-user-authorization.md) 。

## ohos.permission.ACCESS_BLUETOOTH

允许应用接入蓝牙并使用蓝牙能力，例如配对、连接外围设备等。

允许应用接入并使用蓝牙功能，如扫描发现外围设备与外围蓝牙设备配对、连接等，以及低功耗蓝牙的广播和扫描功能。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：10

## ohos.permission.MEDIA_LOCATION

允许应用访问用户媒体文件中的地理位置信息。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.APP_TRACKING_CONSENT

允许应用读取开放匿名设备标识符。

获取此权限，应用程序必须通过弹出显示询问是否允许APP跟踪窗口。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：9

## ohos.permission.ACTIVITY_MOTION

允许应用读取用户的运动状态。

该权限允许应用读取用户当前的运动状态。例如，判断用户是否处于运动中、记录用户行走步数。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.CAMERA

允许应用使用相机。

该权限允许应用使用相机。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：9

## ohos.permission.DISTRIBUTED_DATASYNC

允许不同设备间的数据交换。

该权限允许应用与远程设备交换用户数据（如图片、音乐、视频及应用数据等）。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.LOCATION_IN_BACKGROUND

允许应用在后台运行时获取设备位置信息。

应用在获取了位置权限{@code ohos.permission.LOCATION}后，如果需要在后台运行时获取设备位置信息，则需要申请该权限。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.LOCATION

允许应用获取设备位置信息。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.APPROXIMATELY_LOCATION

允许应用获取设备模糊位置信息。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：9

## ohos.permission.MICROPHONE

允许应用使用麦克风。

该权限允许应用使用麦克风。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：8

## ohos.permission.READ_CALENDAR

允许应用读取日历信息。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：8

## ohos.permission.WRITE_CALENDAR

允许应用添加、移除或更改日历活动。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：8

## ohos.permission.READ_HEALTH_DATA

允许应用读取用户的健康数据。

该权限允许应用读取用户的健康数据，如心率数据等。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.ACCESS_NEARLINK

允许应用接入星闪并使用星闪能力，例如配对、连接外围设备等。

允许接入并使用星闪功能，例如发现远端设备、向远端设备发起配对、连接远端设备，以及发送广播和扫描外围设备。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：12

## ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

允许应用访问公共目录下Download目录及子目录。

当前仅2in1设备和平板上的应用可申请此权限。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**变更信息**:从PKI网站同步过来，按照PKI网站权限内容进行修正

**起始版本**：11

## ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY

允许应用访问公共目录下的Documents目录。

当前仅2in1设备和平板上的应用可申请此权限。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**变更信息**:从PKI网站同步过来，按照PKI网站权限内容进行修正

**起始版本**：11

## ohos.permission.CUSTOM_SCREEN_CAPTURE

允许应用获取屏幕图像。

应用获取此权限后，可进行截屏、录屏等操作。当前仅平板、2in1设备应用可申请此权限。

**权限级别**：system_basic

**授权方式**：用户授权（user_grant）

**起始版本**：14

## ohos.permission.READ_MEDIA

允许应用读取用户外部存储中的媒体文件信息。

如果应用需要访问公共媒体文件（如视频、音频、图片等），需要申请此权限。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

## ohos.permission.WRITE_MEDIA

允许应用读写用户外部存储中的媒体文件信息。

如果应用需要读写公共媒体文件（如视频、音频、图片等），则需要申请该权限。

**权限级别**：normal

**授权方式**：用户授权（user_grant）

**起始版本**：7

