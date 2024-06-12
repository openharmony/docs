# 拉起系统应用


本章节介绍拉起系统应用的方式，并对当前已支持的能力进行了汇总。

## 使用系统Picker实现资源访问

通过系统Picker组件，开发者无需申请权限，即可使用相机、文件管理、联系人等系统应用的一些常用功能。例如，一个音频播放器应用可以通过AudioViewPicker让用户选择音频文件，然后获取所选的音频文件路径进行播放。


### 运行机制

应用拉起系统Picker组件（文件选择器、照片选择器、联系人选择器等），由用户在Picker上选择对应的文件、照片、联系人等资源，应用即可获取到Picker的返回结果。

系统Picker由系统独立进程实现。


### 支持的系统Picker

目前支持的系统Picker有：

> **说明：**
> 
> 由于系统Picker已经获取了对应权限的预授权，开发者使用系统Picker时，无需再次申请权限也可临时受限访问对应的资源。例如，当应用需要读取用户图片时，可通过使用照片Picker，在用户选择所需要的图片资源后，直接返回该图片资源，而不需要授予应用读取图片文件的权限。


| Picker类型 | 适用场景 | 使用指导 |
| -------- | -------- |-------- |
| 文件Picker（DocumentViewPicker） | 用于访问、保存公共目录中文档类文件。 |- [选择文档类文件](../file-management/select-user-file.md#选择文档类文件) <br/> - [保存文档类文件](../file-management/save-user-file.md#保存文档类文件)|
| 音频Picker（AudioViewPicker） | 用于访问、保存用户公共目录的音频文件。 |- [选择音频类文件](../file-management/select-user-file.md#选择音频类文件) <br/> - [保存音频类文件](../file-management/save-user-file.md#保存音频类文件) |
| 照片Picker（PhotoViewPicker）| 用于访问、保存公共目录的图片或视频文件。 | - [选择媒体库资源](../media/medialibrary/photoAccessHelper-resource-guidelines.md#使用picker选择媒体库资源)<br/> - [保存图片或视频类文件](../file-management/save-user-file.md#保存图片或视频类文件)|
| 相机Picker （Camera Picker）| 用于拉起系统相机，进行拍照、录制。 |[cameraPicker.pick](../../reference/apis-camera-kit/js-apis-cameraPicker.md#pick) |
| 联系人Picker（Contacts Picker） | 用于拉起联系人应用，读取联系人数据人。 |[选择联系人](../contacts/contacts-intro.md#选择联系人) |
| 扫码Picker | 调用相机，实现默认界面扫描。 |  |
| 卡证识别Picker | 调用相机，识别各类证件并提取卡证信息。 |  |
| 文档扫描Picker | 调用相机，拍摄文档并转化为高清扫描件。 |  |



 
## 使用系统应用提供的接口

| 系统应用 | 主要功能 | 使用指导 |
| -------- | -------- |-------- |
| 电话 | 拨打电话 | 使用指导 |
| 短信 | 发送短信 | 使用指导 |
| 日历 | 创建日程 | 使用指导 |
| 钱包 | 单次支付、支付并签约 | 使用指导 |
| 应用市场 | 拉起应用详情页面安装应用 | 使用指导 |


> **说明：**
> 
> 拉起设置应用的页面，暂未实现，已有相关能力规划。


