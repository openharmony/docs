# Audio Kit简介（删除标签）

api-info==10

## 概述

声明输入类型的音频流相关接口,

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

## 汇总

Section存在自身的起始版本，以自身起始版本为主，api-info==11

**起始版本：** 11

### subsection本身无起始版本，继承section的起始版本

subsection本身无起始版本，继承section的起始版本，api-info==11

### 函数

subSection存在自身的起始版本，以自身起始版本为主，api-info==12

**起始版本：** 12

 **1、删除链接** 
- 默认支持拖出能力的组件（可从组件上拖出数据）：Search、TextInput、TextArea、RichEditor、Text、Image、<!--Del-->[FormComponent](audio-playback-overview.md)、UIExtensionComponent<!--DelEnd-->Hyperlink
- 设置列表中ListItem/ListItemGroup的预加载数量，只在LazyForEach中生效，其中ListItemGroup将作为一个整体进行计算，ListItemGroup中的所有ListItem会一次性全部加载出来。<!--Del-->具体使用可参考[减少应用白块说明](audio-playback-overview.md#如何选择音频播放开发方式)。<!--DelEnd-->

 **2、删除一段话** 

第一种：
1. 通过DocumentViewPicker接口选择或保存文件，返回选择或保存的文件uri。
2. 通过AudioViewPicker接口选择或保存文件，返回选择或保存的文件uri。
3. 通过PhotoViewPicker.save接口保存文件，返回保存的文件uri。
<!--Del-->
4. 通过fileAccess模块获取文档类目录下的文件得到对应文件的FileInfo对象，此对象中就包含对应文件或者目录的uri属性，此模块中的接口为系统接口，使用此模块需要注意应用是否为系统应用。支持获取文件uri的目录有：
   - 外部存储目录
   - Docs目录
   - Download目录
   - Desktop目录
   - Documents目录
   - Share共享盘目录
<!--DelEnd-->

第二种：
1. 通过DocumentViewPicker接口选择或保存文件，返回选择或保存的文件uri。
2. 通过AudioViewPicker接口选择或保存文件，返回选择或保存的文件uri。
3. 通过PhotoViewPicker.save接口保存文件，返回保存的文件uri。
4. 通过fileAccess模块获取文档类目录下的文件得到对应文件的FileInfo对象，此对象中就包含对应文件或者目录的uri属性，此模块中的接口为系统接口，使用此模块需要注意应用是否为系统应用。支持获取文件uri的目录有：
   <!--Del-->
   - 外部存储目录
   - Docs目录
   <!--DelEnd-->
   - Download目录
   - Desktop目录
   - Documents目录
   - Share共享盘目录

第三种：
1. 通过DocumentViewPicker接口选择或保存文件，返回选择或保存的文件uri。
2. 通过AudioViewPicker接口选择或保存文件，返回选择或保存的文件uri。
3. 通过PhotoViewPicker.save接口保存文件，返回保存的文件uri。<!--Del-->
4. 通过fileAccess模块获取文档类目录下的文件得到对应文件的FileInfo对象，此对象中就包含对应文件或者目录的uri属性，此模块中的接口为系统接口，使用此模块需要注意应用是否为系统应用。支持获取文件uri的目录有：
   - 外部存储目录
   - Docs目录
   - Download目录
   - Desktop目录
   - Documents目录
   - Share共享盘目录<!--DelEnd-->

第四种：
- 卡片提供方：提供卡片显示内容的应用，控制卡片的显示内容、控件布局以及控件点击事件。
- 卡片管理服务：用于管理系统中所添加卡片的常驻代理服务，提供formProvider<!--Del-->和formHost的<!--DelEnd-->接口能力，同时提供卡片对象的管理与使用以及卡片周期性刷新等能力。<!--Del-->
- 卡片渲染服务：用于管理卡片渲染实例，渲染实例与卡片使用方上的卡片组件一一绑定。卡片渲染服务运行卡片页面代码widgets.abc进行渲染，并将渲染后的数据发送至卡片使用方对应的卡片组件。<!--DelEnd-->

第五种：
- 卡片提供方：提供卡片显示内容的应用，控制卡片的显示内容、控件布局以及控件点击事件。
- 卡片管理服务：用于管理系统中所添加卡片的常驻代理服务，提供formProvider<!--Del-->和formHost的<!--DelEnd-->接口能力，同时提供卡片对象的管理与使用以及卡片周期性刷新等能力。<!--Del-->
- 卡片渲染服务：用于管理卡片渲染实例，渲染实例与卡片使用方上的卡片组件一一绑定。卡片渲染服务运行卡片页面代码widgets.abc进行渲染，并将渲染后的数据发送至卡片使用方对应的卡片组件。
<!--DelEnd-->

 **3、删除section和subsection** 

第一种：删除subsection

## 收藏夹
收藏夹属于系统相册，对图片或视频设置收藏时会自动将其加入到收藏夹中，取消收藏则会从收藏夹中移除。

<!--Del-->
### 收藏图片和视频（仅向系统应用开放）
通过MediaAssetChangeRequest.setFavorit和PhotoAccessHelper.applyChanges接口将图片或视频设置为收藏。
**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面将以收藏一张图片为例。

**开发步骤**

1. 获取指定媒体资源。
2. 调用MediaAssetChangeRequest.setFavorite接口将图片设置为收藏。
3. 调用PhotoAccessHelper.applyChanges接口提交收藏图片的变更请求。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    let favoriteState = true;
    assetChangeRequest.setFavorite(favoriteState);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```
<!--DelEnd-->

第二种：删除section

# 用户相册资源使用指导

photoAccessHelper提供用户相册相关的接口，供开发者创建、删除用户相册，往用户相册中添加和删除图片和视频资源等。

> **说明：**
>
> 在进行功能开发前，请开发者查阅开发准备，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用开发准备中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分photoAccessHelper的接口调用都是异步的。以下异步调用的API示例均采用Promise函数，更多方式可以查阅API参考。
如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

<!--Del-->
## 创建用户相册（仅向系统应用开放）

通过MediaAlbumChangeRequest.createAlbumRequest和PhotoAccessHelper.applyChanges接口创建用户相册。

待创建的相册名参数规格为：

- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'。

下面以创建一个用户相册为例。
<!--DelEnd-->

**4、表格**

第一种：删除行
| 任务 | 简介 | 相关指导 |
| -------- | -------- | -------- |
| 应用组件开发 | 本章节介绍了如何使用Stage模型的UIAbility组件和ExtensionAbility组件开发应用。 | -&nbsp;应用/组件级配置<br/>-&nbsp;UIAbility组件<br/>-&nbsp;ExtensionAbility组件<br/>-&nbsp;AbilityStage组件容器<br/>-&nbsp;应用上下文Context<br/>-&nbsp;组件启动规则 |
| 了解进程模型 | 本章节介绍了Stage模型的进程模型以及几种常用的进程间通信方式。 | 进程模型概述|
| 了解线程模型 | 本章节介绍了Stage模型的线程模型以及几种常用的线程间通信方式。 | 线程模型概述 |<!--Del-->
| 任务管理 | 本章节介绍了Stage模型中任务管理的基本概念和典型场景。 | -&nbsp;任务管理场景介绍<br/>-&nbsp;任务管理与启动模式<br/>-&nbsp;页面栈和任务链 |<!--DelEnd-->
| 应用配置文件 | 本章节介绍Stage模型中应用配置文件的开发要求。 | Stage模型应用配置文件 |

第二种：删除整个表格
<!--Del-->
| 任务 | 简介 | 相关指导 |
| -------- | -------- | -------- |
| 应用组件开发 | 本章节介绍了如何使用Stage模型的UIAbility组件和ExtensionAbility组件开发应用。 | -&nbsp;应用/组件级配置<br/>-&nbsp;UIAbility组件<br/>-&nbsp;ExtensionAbility组件<br/>-&nbsp;AbilityStage组件容器<br/>-&nbsp;应用上下文Context<br/>-&nbsp;组件启动规则 |
| 了解进程模型 | 本章节介绍了Stage模型的进程模型以及几种常用的进程间通信方式。 | 进程模型概述|
| 了解线程模型 | 本章节介绍了Stage模型的线程模型以及几种常用的线程间通信方式。 | 线程模型概述|
| 任务管理 | 本章节介绍了Stage模型中任务管理的基本概念和典型场景。 | -&nbsp;任务管理场景介绍<br/>-&nbsp;任务管理与启动模式<br/>-&nbsp;页面栈和任务链 |
| 应用配置文件 | 本章节介绍Stage模型中应用配置文件的开发要求。 | Stage模型应用配置文件 |
<!--DelEnd-->

第三种：删除某一列
| <!--DelCol1-->任务 | 简介 | <!--DelCol3-->相关指导 |
| -------- | -------- | -------- |
| 应用组件开发 | 本章节介绍了如何使用Stage模型的UIAbility组件和ExtensionAbility组件开发应用。 | -&nbsp;应用/组件级配置<br/>-&nbsp;UIAbility组件<br/>-&nbsp;ExtensionAbility组件<br/>-&nbsp;AbilityStage组件容器<br/>-&nbsp;应用上下文Context<br/>-&nbsp;组件启动规则 |
| 了解进程模型 | 本章节介绍了Stage模型的进程模型以及几种常用的进程间通信方式。 | 进程模型概述|
| 了解线程模型 | 本章节介绍了Stage模型的线程模型以及几种常用的线程间通信方式。 | 线程模型概述|
| 任务管理 | 本章节介绍了Stage模型中任务管理的基本概念和典型场景。 | -&nbsp;任务管理场景介绍<br/>-&nbsp;任务管理与启动模式<br/>-&nbsp;页面栈和任务链 |
| 应用配置文件 | 本章节介绍Stage模型中应用配置文件的开发要求。 | Stage模型应用配置文件 |

**5、相关实例**
## 相关实例

针对Audio Kit开发，有以下相关实例可供参考：

- 音频管理（ArkTS）（API10）

**6、说明**
>**说明**
>
> 说明第一行
>
> <!--Del-->说明第二行<!--DelEnd-->
>
> 说明第三行
>
> <!--Del-->说明第四行<!--DelEnd-->