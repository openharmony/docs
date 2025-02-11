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
