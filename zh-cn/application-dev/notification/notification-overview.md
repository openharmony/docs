# Notification Kit简介

(产品输出相关介绍)

 ![zh-cn_image_9](figures/zh-cn_image_9.png) 

## 业务流程
 ![zh-cn_image_10](figures/zh-cn_image_10.png) 

使用Noification Kit的主要业务流程如下：

    1.请求通知授权。

    2.应用发送通知到通知服务。

    3.将通知展示到通知中心。


## 通知样式
Notification Kit支持的通知样式：
| 类型 | 通知样式 | 规格描述 |
| ---- | --------| ------- |
| [文本](./text-notification.md)           | ![zh-cn_image_4](figures/zh-cn_image_4.png)   | 通知文本内容最多显示三行，超长后以“...”截断。 |
| [多行文本](./text-notification.md)       | ![zh-cn_image_5](figures/zh-cn_image_5.png)   | 适合于文本内容较长的通知，最多可显示三行内容，每行内容超长后以“...”截断。 |
| [通知大图标](../reference/apis/js-apis-inner-notification-notificationRequest.md)| ![zh-cn_image_1](figures/zh-cn_image_1.png) | 适合于有图片预览的通知。 |
| [通知角标](./notification-badge.md)      | ![zh-cn_image_6](figures/zh-cn_image_6.png)   | 以数字的形式展示在右上角。 |
| [进度条](./progress-bar-notification.md) | ![zh-cn_image](figures/zh-cn_imag.png)    | 适合进度类通知。 |

## 约束限制
- 单个应用已发布的通知在通知中心等系统入口的留存数量有限（当前规格最多24条）。
- 通知的长度不能超过200KB（跨进程序列化大小限制）。
- 系统所有应用发布新通知的频次累计不能超过每秒10条。

## 与相关Kit的关系
- Notification Kit创建的通知会即时显示在通知中心等系统入口，如果开发者希望在应用退到后台或进程终止后仍然有一些提醒用户的定时类通知，例如购物类应用抢购提醒等，可通过[`BackGroundTask Kit`](../kit-readme/Readme-BackgroundTasks-Kit.md)创建，目前支持基于倒计时、日历、闹钟等类型的通知提醒功能。
- 开发者可通过`Push Kit`远程推送用户通知到本地。
- 开发者可通过[`Ability Kit`](../kit-readme/Readme-Ability-Kit.md)设置用户点击通知后的行为意图。
