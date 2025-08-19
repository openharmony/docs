# 模块描述
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：

- [AVSession](arkts-apis-avsession-AVSession.md) : 会话，可用于设置元数据、播放状态信息等操作。
- [AVSessionController](arkts-apis-avsession-AVSessionController.md): 会话控制器，可用于查看会话ID，完成对会话发送命令及事件，获取会话元数据、播放状态信息等操作。
- [AVCastController](arkts-apis-avsession-AVCastController.md): 投播控制器，可用于投播场景下，完成播放控制、远端播放状态监听、远端播放状态信息获取等操作。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```
