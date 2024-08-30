# 系统能力SystemCapability列表

SysCap，全称SystemCapability，即系统能力，指操作系统中每一个相对独立的特性。

开发者使用某个接口进行开发前，建议先阅读[SysCap使用指南](syscap.md)，了解Syscap的定义和使用指导。再结合下文中的表格判断具体能力集是否支持某个设备，提高开发效率。

> **说明：**
>
> Default代表了一个功能比较全面的OpenHarmony设备，具有大部分的通用能力。在尚未明确设备具体能力集的情况下，可使用Default类型进行开发。

## SystemCapability.ArkUI.ArkUI.Full

ArkUI组件能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ArkUI.ArkUI.Napi

Napi功能

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ArkUI.ArkUI.Libuv

Libuv功能

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ArkUI.UiAppearance

外观配置功能

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Base

通用类型

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.BundleManager.BundleFramework

包管理服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.Overlay

包管理overlay能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.DistributedBundleFramework

分布式包管理服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.Zlib

Zlib压缩、解压缩工具

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.EGL

渲染Api与底层要换生平台窗口系统之间的接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.GLES2

用于渲染高级2D和3D图形

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.GLES3

用于渲染高级2D和3D图形

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.WebGL

WebGL1.0 标准api

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Window.SessionManager

窗口管理增强能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.WindowManager.WindowManager.Core

窗口管理基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Notification.CommonEvent

公共事件

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Notification.Notification

通知

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Notification.ReminderAgent

后台代理提醒

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Notification.Emitter

事件处理服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.IPC.Core

进程间通信

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.SoftBus.Core

软总线

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetManager.Core

网络管理基础服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetManager.Ethernet

以太网连接

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetManager.NetSharing

网络共享

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetManager.MDNS

mDNS服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetManager.Vpn

VPN

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.NetStack

基础网络协议栈能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Communication.WiFi.Core

WIFI基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.WiFi.STA

WIFI STA能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.WiFi.AP.Core

WIFI AP能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.WiFi.P2P

WIFI P2P能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Communication.Bluetooth.Core

蓝牙服务以及协议栈

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Location.Location.Core

位置服务基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Location.Location.Geocoder

地理编码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Location.Location.Geofence

地理围栏能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Location.Location.Gnss

GNSS硬件相关能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.Core

基本输入能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.InputDevice

输入设备管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.InputMonitor

输入事件监听者

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.InputConsumer

输入事件消费者

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.InputSimulator

输入事件模拟者

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.Pointer

鼠标指针管理模块

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MultimodalInput.Input.ShortKey

快捷键

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.BatteryManager.Extension

电池服务扩展能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.DisplayPowerManager

显示能效管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.ThermalManager

温控服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.PowerManager.Core

系统电源管理服务基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.BatteryManager.Core

电池服务基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.PowerManager.PowerManager.Extension

系统电源管理服务扩展能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.Core

媒体基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AudioPlayer

媒体音频播放引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AudioRecorder

媒体音频播录制引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.VideoPlayer

媒体视频播放引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.VideoRecorder

媒体视频录制引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.CodecBase

媒体编解码基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AudioCodec

媒体音频编解码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AudioDecoder

媒体音频解码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AudioEncoder

媒体音频编码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.VideoDecoder

媒体视频解码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.VideoEncoder

媒体视频编码能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.Spliter

媒体解封装能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.Muxer

媒体封装能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AVPlayer

媒体音视频播放引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AVRecorder

媒体音视频录制引擎能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AVMetadataExtractor

获取媒体云数据能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AVImageGenerator

获取视频缩略图能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.AVSession.Core

媒体会话基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.AVSession.Manager

媒体会话管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.AVSession.AVCast

媒体投播能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.AVSession.ExtendedDisplayDisplay

扩展媒体投屏能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是      | 是     | 否            |

## SystemCapability.Multimedia.Audio.Core

音频基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Renderer

音频输出能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Capturer

音频输入能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Device

音频设备管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Volume

音频音量管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Communication

音频通信能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Interrupt

音频焦点

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Tone

拨号和回铃音播放

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.PlaybackCapture

系统音录制能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Camera.Core

相机基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Drm.Core

媒体数字版权管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Image.Core

图片基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Image.ImageSource

图片源解码解析能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Image.ImagePacker

图片打包能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Image.ImageReceiver

图片接收能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.MediaLibrary.Core

媒体库基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.MediaLibrary.DistributedCore

媒体库分布式能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.SystemSound.Core

系统声音管理，如铃声，通知，闹钟等

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Telephony.CoreService

蜂窝核心服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Telephony.CallManager

通话管理服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Telephony.CellularCall

蜂窝通话服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Telephony.CellularData

蜂窝数据服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Telephony.SmsMms

短彩信服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Telephony.StateRegistry

蜂窝网络状态注册服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Global.I18n

国际化

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Global.ResourceManager

资源管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Customization.ConfigPolicy

定制框架

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Customization.CustomConfig

定制配置

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Customization.EnterpriseDeviceManager

企业设备管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BarrierFree.Accessibility.Core

无障碍基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BarrierFree.Accessibility.Vision

无障碍视觉辅助能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BarrierFree.Accessibility.Hearing

无障碍听觉辅助能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.WorkScheduler

延迟任务调度

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

长时任务管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

短时任务管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.UsageStatistics.App

应用使用信息统计

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.UsageStatistics.AppGroup

应用使用活跃分组

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Utils.Lang

TS/JS语言基础库

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiLog

流水日志

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiTrace

分布式追踪

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.Hiview.FaultLogger

事件打点

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.Hiview.LogLibrary

日志文件管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiChecker

检测模式

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiDumper

系统信息导出

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiAppEvent

应用事件打点

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiSysEvent

系统事件打点

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.HiviewDFX.HiProfiler.HiDebug

调试调优

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Update.UpdateService

升级服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedHardware.DeviceManager

分布式设备管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.DeviceAuth

设备互信认证

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.DataTransitManager

数据传输管控策略库

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.DeviceSecurityLevel

设备安全等级管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.Huks.Core

设备密钥管理-基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Security.Huks.Extension

设备密钥管理扩展能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.Asset

关键资产存储能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.AccessToken

访问控制

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Account.OsAccount

系统账号

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Account.AppAccount

应用账号

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.UserIAM.UserAuth.Core

统一用户认证

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.UserIAM.UserAuth.PinAuth

口令认证

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.InputMethodFramework

输入法框架

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.Pasteboard

剪贴板服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.Time

时间时区定时

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.Wallpaper

壁纸框架

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.ScreenLock

锁屏服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.Upload

上传服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.MiscServices.Download

下载服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.StorageService.Backup

备份恢复

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.StorageService.SpatialStatistics

空间统计

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.StorageService.Volume

卷管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.StorageService.Encryption

文件加密能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.File.FileIO

基础文件IO接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.File.Environment

环境相关接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.File.DistributedFile

分布式文件扩展接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.AppFileService

应用文件服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.UserFileService

用户文件服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.UserFileManager.Core

公共用户文件管理基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.PhotoAccessHelper.Core

公共目录图片视频管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.DistributedFileService.CloudSyncManager

云文件同步管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

云文件同步能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.USB.USBManager

USB服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Sensors.Sensor

传感器服务订阅

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Sensors.MiscDevice

小器件-振感

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Startup.SystemInfo

系统基本信息

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.RelationalStore.Core

关系型数据库基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.CommonType

分布式数据管理公共类型

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.KVStore.Core

Key-Value型数据库基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.KVStore.DistributedKVStore

分布式Key-Value型数据库

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.DataObject.DistributedObject

分布式对象

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.Preferences.Core

偏好型数据存储基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.DataShare.Core

跨进程数据共享基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.DataShare.Consumer

跨进程数据共享，数据消费者

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.DataShare.Provider

跨进程数据共享，数据生产者

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.CloudSync.Config

配置端云同步状态

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.CloudSync.Client

数据侧手动调用的端云同步接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.CloudSync.Server

云空间服务所需实现的接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityBase

组件运行基础数据定义，主要包括组件通信数据的载体want、系统配置定义等

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityRuntime.Core

组件运行核心基础功能模块，包括应用初始化、无界面组件运行等

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityRuntime.FAModel

FA模型

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityRuntime.AbilityCore

通用组件（有界面）

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityRuntime.Mission

任务管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityTools.AbilityAssistant

命令行工具

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.Form

卡片管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.DistributedAbilityManager

分布式流转管理（continuationManager）接口定义，支持打开互联面板、更新流转状态

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Applications.CalendarData

日历日程管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Applications.ContactsData

联系人数据库

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Applications.Contacts

联系人

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 否      | 否            |

## SystemCapability.Applications.Settings.Core

设置API

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Test.UiTest

UI测试框架

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Web.Webview.Core

Webview组件

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Advertising.OAID

OAID管理服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Advertising.Ads

广告服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CertificateManager

证书管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework

加解密算法库框架-加解密算法库框架基础

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Security.CryptoFramework.Key

加解密算法库框架-密钥基础类型

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Key.SymKey

加解密算法库框架-对称密钥

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Key.AsymKey

加解密算法库框架-非对称密钥

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Signature

加解密算法库框架-签名验签

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Cipher

加解密算法库框架-对称、非对称加解密

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.KeyAgreement

加解密算法库框架-密钥协商

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.MessageDigest

加解密算法库框架-消息摘要

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Security.CryptoFramework.Mac

加解密算法库框架-消息验证码

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Kdf

加解密算法库框架-密钥派生

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Security.CryptoFramework.Rand

加解密算法库框架-随机数

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Security.Cert

证书算法库框架-证书能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.Core

包管理核心业务，包含包信息查询、安装卸载的基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.FreeInstall

包管理提供的免安装能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.Resource

包管理提供的获取图标和label的能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.DefaultApp

包管理提供的默认应用管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.Launcher

包管理提供给Launcher的查询能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.BundleManager.BundleFramework.AppControl

包管理提供的拦截能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Ability.AbilityRuntime.QuickFix

快速修复

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.ColorManager.Core

广色域管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

能效资源申请接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.XTS.DeviceAttest

设备证明

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Request.FileTransferAgent

应用与服务器间文件传输代理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ResourceSchedule.DeviceStandby

系统灭屏待机续航所需实现的接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.DistributedDataManager.UDMF.Core

分布式数据管理--统一数据管理框架（UDMF）基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.AVScreenCapture

录屏能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Media.SoundPool

音频池能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Audio.Spatialization

空间音频管理能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.AudioHaptic.Core

音振协同播放能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ArkUi.Graphics3D

3D能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphics.Drawing

自绘制能力的接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.NativeDrawing

提供native层2D绘制能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Developtools.Syscap

系统能力编解码

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Resourceschedule.Ffrt.Core

并发编程框架

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.NativeWindow

提供本地窗口，供开发者自绘制（2D&3D）

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.NativeBuffer

提供图形Buffer(独立于本地窗口)

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.NativeImage

提供输出到OpenGLES纹理的Surface

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.NativeVsync

提供系统垂直同步信号

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Vulkan

显示能效管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Multimedia.Image.ImageCreator

图像创建能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.Graphic.Graphic2D.WebGL2

WebGL2.0 标准api

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 否            |

## SystemCapability.ArkUI.ArkUI.Lite

轻量ArkUI组件

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 是       | 是      | 是            |

## SystemCapability.Location.Location.Lite

轻量位置服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.PowerManager.BatteryManager.Lite

轻量电池服务

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.FileManagement.File.FileIO.Lite

轻量级基础文件IO接口

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.Startup.SystemInfo.Lite

轻量级系统基本信息

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.PowerManager.DisplayPowerManager.Lite

轻设备系统显示能效管理

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.DistributedDataManager.Preferences.Core.Lite

轻量级偏好型数据存储基础能力

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.Sensors.Sensor.Lite

轻量级传感器服务订阅

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |

## SystemCapability.Sensors.MiscDevice.Lite

轻量级小器件-振感

| Default | Tablet | LiteWearable |
|---------|--------|--------------|
| 否       | 否      | 是            |