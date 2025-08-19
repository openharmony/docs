# Samples

为了方便开发者快速学习与了解、针对重点特性或功能进行开发，本页面对当前OpenHarmony所有的[Samples](https://gitcode.com/openharmony/applications_app_samples)资源汇总，如下所示：



## UI

### 声明式开发范式

#### ArkUI组件集合

##### 介绍

本示例为ArkUI中组件、通用、动画、全局方法的集合。
##### 使用
1.点击组件、通用、动画、全局方法四个按钮或左右滑动切换不同视图。

2.点击二级导航（如通用属性、通用事件等），若存在三级导航则展开三级导航（如Border 边框、点击事件等）；若不存在三级导航，则跳转至详情页面。

3.若存在三级导航（如Border 边框、点击事件等），点击跳转至详情页面。
##### 基本原理
示例使用 [Tabs容器组件](reference/apis-arkui/arkui-ts/ts-container-tabs.md) 搭建整体应用框架，每个 [TabContent内容视图](reference/apis-arkui/arkui-ts/ts-container-tabcontent.md) 使用 [List容器组件](reference/apis-arkui/arkui-ts/ts-container-list.md) 布局，在每个 [ListItem](reference/apis-arkui/arkui-ts/ts-container-listitem.md) 中使用 [循环渲染](ui/state-management/arkts-rendering-control-foreach.md) 加载此分类下分类导航数据，底部导航菜单使用 [TabContent中tabBar属性](reference/apis-arkui/arkui-ts/ts-container-tabcontent.md) 设置自定义样式 。
将组件库分成四大类：  
组件模块：  
1、空白与分隔：使用全局组件TitleBar，CommonItemSlider，CommonItemSelect，引入全局样式搭建分隔器组件页面。  
2、按钮与选择：使用全局组件TitleBar，引入全局样式搭建按钮，日期选择器，单选按钮，选择菜单，滑动条，切换按钮组件页面。  
3、信息展示与功效：使用全局组件TitleBar，引入全局样式搭建二维码组件页面。  
4、文本与输入：使用全局组件TitleBar，引入全局样式搭建行内文本，输入框，文本组件页面。  
5、辅助：使用全局组件TitleBar，引入全局样式搭建标记组件页面。  
通用模块：  
1、通用事件：用到全局组件TitleBar，全局样式实现点击事件组件页面。  
2、通用属性：使用全局组件TitleBar，全局样式实现组件页面，使用Math.trunc()方法将参数隐式转换成数字类型后，纯粹的去除小数部分。  
动画模块：
1、转场动画：用到全局组件TitleBar实现动画转场组件页面。  
全局方法模块：  
弹窗：使用全局组件TitleBar，全局样式实现弹窗组件页面。
##### 约束与限制
开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/ComponentCollection)

#### 横竖屏切换
##### 介绍
本示例展示如何使用媒体查询，通过[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md) 接口完成在不同设备上显示不同的界面效果。  
##### 使用
1.在竖屏设备上，首页展示新闻列表，点击新闻进入详情界面。

2.在横屏设备上，首页左侧展示新闻列表，右侧显示新闻详情，点击新闻右侧显示所点击的新闻的详情。
##### 基本原理
横竖屏切换功能接口封装在Index，获取监听句柄：通过mediaQuery.matchMediaSync('screen and (min-aspect-ratio: 1.5) or (orientation: landscape)')方法来获取有一个监听横竖屏的句柄，执行控制横竖屏切换效果的函数：调用this.listener.on('change', this.onLand.bind(this))函数来实现横竖屏下不同的功能或者页面效果;  

##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/MediaQuery)

#### 状态管理
##### 介绍
本示例通过使用[页面级的状态变量](ui/state-management/arkts-localstorage.md) 和[应用级的状态变量](ui/state-management/arkts-appstorage.md) 来实现应用的状态管理。展示内容包括修饰的对象类型、父子组件之间的状态同步、爷孙组件之间的状态同步以及兄弟组件之间的状态同步。
##### 使用
1.点击首页的切换按钮，可切换List和Grid布局。

2.点击食物单元，可跳转到食物详情页。
##### 基本原理
List布局：通过创建食物数据模型，ForEach循环渲染ListItem。

Grid布局：通过展示食物分类信息，创建Tabs页签展示不同分类的食物。

路由机制：通过@ohos.router接口、Navigator和页面间数据传递。
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：4.0.5.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/StateManagement)

#### 页面布局和连接
##### 介绍
本示例构建食物分类列表页面和食物详情页，包含：

1.[List](reference/apis-arkui/arkui-ts/ts-container-list.md)布局：创建食物数据模型，ForEach循环渲染ListItem。

2.[Grid](reference/apis-arkui/arkui-ts/ts-container-grid.md)布局：展示食物分类信息，创建Tabs页签展示不同分类的食物。

3.路由机制：[@ohos.router](reference/apis-arkui/js-apis-router.md)接口、[Navigator](reference/apis-arkui/arkui-ts/ts-container-navigator.md)和页面间数据传递。
##### 使用
1.点击首页的切换按钮，可切换List和Grid布局。

2.点击食物单元，可跳转到食物详情页。
##### 基本原理
List布局：通过创建食物数据模型，ForEach循环渲染ListItem。

Grid布局：通过展示食物分类信息，创建Tabs页签展示不同分类的食物。

路由机制：通过@ohos.router接口、Navigator和页面间数据传递。
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/UI/ArkTsComponentCollection/DefiningPageLayoutAndConnection)

## 基础特性

### 应用模型

#### Ability的启动模式
##### 介绍
本示例展示了在一个Stage模型中，实现standard、singleton、specified多种模式场景。
##### 使用
1、standard模式：

1）进入首页，点击番茄，会新建一个番茄的Ability，展示番茄的详情；

2）在番茄的详情界面，点击黄瓜，会新建一个黄瓜的Ability，展示黄瓜的详情；

3）使用aa工具查看Ability信息，此时存在以下Ability：1个番茄的Ability、1个黄瓜的Ability、1个首页的Ability；

2、singleton模式：

1）进入首页，点击冰淇凌，会新建一个冰淇凌的Ability，展示冰淇凌的详情；

2）在冰淇凌的详情界面，点击螃蟹，会复用冰淇凌的Ability，页面数据会刷新并展示螃蟹的详情；

3）使用aa工具查看Ability信息，此时存在以下Ability：1个冰淇凌的Ability、1个首页Ability；

3、specified模式：

1）进入首页，点击核桃，会新建一个核桃的Ability，展示核桃的详情；

2）在核桃的详情界面，点击蓝莓，会新建一个蓝莓的Ability，展示蓝莓的详情；

3）在蓝莓的详情界面，点击核桃，会复用已存在的核桃的Ability，实现specified模式下的单实例特性，页面数据会刷新并展示核桃的详情；

4）使用aa工具查看Ability信息，此时存在以下Ability：1个核桃的Ability、1个蓝莓的Ability、1个首页Ability；
##### 基本原理
本示例启动standard、singleton、specified三种模式的方法主要封装在Util当中。  
新建Ability：创建三个代表standard、singleton、specified模式的Ability，如工程目录中的SingletonAbility、SpecifiedAbility、StandardAbility，并在module.json文件中将launchType属性修改为对应的启动模式属性。  
启动指定Ability：通过Util中的startMode函数根据页面所传的abilityName，启动对应的ability并进入详情页面。  
specified多实例功能实现：specified模式则是根据MyAbilityStage中的onAcceptWant函数给用户返回一个ability标识，如果之前启动过标识的ability，不创建新的实例并拉回栈顶，否则创建新的实例并启动。
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/ApplicationModels/AbilityStartMode)

#### 自定义分享
##### 介绍
自定义分享主要是发送方将文本，链接，图片三种类型分享给三方应用,同时能够在三方应用中展示。本示例使用[数据请求](reference/apis-network-kit/js-apis-http.md) 实现网络资源的获取，使用[屏幕截屏](reference/apis-arkui/js-apis-screenshot-sys.md) 实现屏幕的截取，使用[文件管理](reference/apis-core-file-kit/js-apis-fileio.md) 实现对文件，文件目录的管理，使用[相册管理](reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md) 获取截取的图片，使用[弹窗](reference/apis-arkui/js-apis-promptAction.md) 进行信息的提示。
##### 使用
使用说明：

1.启动Share应用，首页展示分享跳转页面，点击分享按钮出现自定义分享弹窗（三方APP的）。

2.点击分享文本+链接，选择"Chat"图标，会拉起三方应用Chat ，此时选择聊天列表 中任意的朋友进行分享。

3.点击生成海报，此时第一层弹窗消失并出现新的弹窗，点击截图并分享，会出现小提示"截图成功，分享加载中..." ,稍后会拉起三方应用Chat ，此时选择聊天列表 中任意的朋友进行分享。

4.安装entry以及textShare两个module的hap包 ，点击分享文本+链接，选择"文本分享"图标，会拉起应用文本分享 ,此时选择"留在文本分享"可以进入文本页面 ,若选择"返回"，则会回到Share应用主页面。

5.安装entry以及textEdit两个module的hap包 ，点击分享文本+链接，选择"文本编辑"图标，会拉起应用文本编辑 ,此时选择"留在文本编辑"可以进入文本编辑页面 ,若选择"返回"，则会回到Share应用主页面。
##### 基本原理
本示例分为链接分享，应用内文件分享，其它应用分享三个模块：  
1、文本+链接分享模块：ButtonDialogBuilder方法展示自定义分享弹窗，@ohos.abilityAccessCtrl接口获取访问控制权限，@ohos.net.http接口获取网络资源。  
2、应用内文件分享模块：使用弹窗，屏幕截屏(截取屏幕)，文件管理(管理文件和文件目录)和媒体库管理(获取截取的图片)接口进行图片、链接，视频的分享。  
3、其他应用分享模块：使用弹窗，屏幕截屏(截取屏幕)，文件管理(管理文件和文件目录)和媒体库管理(获取截取的图片)API，把图片，链接，文件在其他应用内分享。  
本示例还包含文本分享应用及文本编辑应用：  
1、在Index.ets中加载TemplateBuilder自定义组件并显示分享信息,在加载Index页面中，如果是被分享方拉起，则加载TemplateBuilder自定义组件。若不是被分享拉起，则显示Ability设置内容。  
2、TemplateBuilder组件内容封装在TemplateBuilder.ets中，在TemplateBuilder组件中包含ShareExtAbility组件、“返回Share”和“留在文本分享/留在文本编辑”按钮，可选择返回Share应用或留在当前（文本分享/文本编辑）应用。  
##### 约束与限制
开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/CustomShare)

#### Stage模型
##### 介绍
[Stage模型](reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) 的设计，主要是为了解决FA模型无法解决的开发场景问题，基于应用的能力与系统总体功能和功耗的平衡、原生支持组件级的迁移和协同、支持多设备和多窗口形态的特点这三个出发点，从而让开发者更加方便地开发出分布式环境下的复杂应用。  
##### 使用
1.点击DataShareExtAbility按钮，跳转到DataShareExtAbility页面；

点击**+**，向rdb数据库中添加单个数据，界面显示添加的数据内容；

点击删除按钮删除指定数据；

点击数据列表，弹出dialog框，可对数据进行修改，点击确认按钮确认修改；

点击返回键，返回首页。

2.点击各个功能按钮测试各个接口。
##### 基本原理
本示例主要展示Stage模型与FA模型的区别，分别从AbilityContext、ServiceExtensionContext、 FormExtensionContext、DataShareExtensionAbility、FormExtension、Bundle、Window、abilityAccessCtrl等模块进行介绍。  
1、应用的能力与系统总体功能和功耗的平衡。  
2、原生支持组件级的迁移和协同。  
3、支持多设备和多窗口形态的特点。
##### 约束与限制
开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/StageModel)

### 网络与连接

#### 蓝牙
##### 介绍
本示例通过使用蓝牙低功耗心率服务，结合[bluetooth](reference/apis-connectivity-kit/js-apis-bluetooth.md) 来接收BLE心率设备发送的心率数据，并使用画布[Canvas](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md) 来绘制实时心率图来展示蓝牙相关API用法。
##### 使用
1.启动应用后，弹出是否允许应用访问位置信息，点击允许后开始操作。
2.点击界面中搜索设备，如未开启蓝牙会自动开启并搜索心率设备，如已开启直接搜索设备。
3.点击连接按钮可以连接到对应的蓝牙心率设备。
4.点击列表Item可以进入实时心率图查看页面。
5.点击实时心率图页断开连接可以断开与当前心率设备的连接。
##### 基本原理
1.首页扫描蓝牙心率设备：使用bluetooth 来实现蓝牙的开启和BLE的扫描，然后再使用一个List显示扫描到BLE心率设备，点击连接按钮可以连接上对应的心率设备。  
2.实时心率图页：使用bluetooth 来接收心率设备发送的心率数据，并使用画布Canvas 来绘制实时心率图，点击断开连接可以断开与当前心率设备的连接。
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Bluetooth)

#### Http
##### 介绍
本示例通过[@ohos.net.http](reference/apis-network-kit/js-apis-http.md) 等接口，实现了根据URL地址和相关配置项发起http请求的功能。
##### 使用
1.启动应用可配置网络请求，设置网址、请求方式、请求参数；

2.点击确认按钮，跳转请求结果页面；

3.点击返回按钮，返回配置页面；

4.支持将本示例中的http模块编译成tgz包。
##### 基本原理
本示例将发送http请求的接口封装在Http模块。  
发起请求：在MainPage.ets中通过TextInput组件获取参数，点击“确认”按钮后通过Http.request()方法调用http.createHttp().request()接口向指定的地址发送请求。
##### 约束与限制
开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Http)

#### RPC连接
##### 介绍
本示例使用[@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md) 相关接口，实现了一个前台选择商品和数目，后台计算总价的功能，使用rpc进行前台和后台的通信。
##### 使用
1.点击商品种类的空白方框，弹出商品选择列表，选择点击对应的商品，空白方框显示相应内容。

2.点击商品选择框后的 + 或 - 按钮，选择商品所对应的数量。

3.点击 Confirm an order 按钮，根据相应的菜品数量与单价，计算出总价并显示。
##### 基本原理
1.发送数据：在首页的sortString()中通过rpc.MessageSequence.create()创建MessageSequence对象，然后通过MessageSequence.writeStringArray()将 我们的处理过的购物数据写入MessageSequence对象中，通过rpc.RemoteObject.sendMessageRequest()将我们得出总价所需要的参数发送到进程中;

2.读取数据：处理MessageRequest请求的接口封装在ReceivedData里面，在这里接收传递来的数据，然后经过处理得出总价，并通过rpc.MessageParcel.writeInt()写入MessageParcel对象。  
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/RPC)

#### 网络管理-Socket连接（UDP）
##### 介绍
本示例主要使用面向非连接的协议UDP Socket，展示Socket在两端设备的连接验证、聊天通信方面的应用。
##### 使用
1.搭建服务器环境：修改服务器脚本中的服务端IP地址，与本机IP地址保持一致，修改完成后双击运行脚本（端口号不必修改，与客户端工程中的端口保持一致即可）。  
2.运行成功后为阻塞状态，等待客户端连接成功后会有相应提示。  
3.打开应用，点击用户选择框选择要登录的用户（不同客户端保持用户选择不一致），点击协议选择框选择通信协议（与运行的服务器一致），并输入另一个设备的IP地址(如果是TCP和TLS，则输入服务端IP地址)，点击登录按钮进入创建房间用户页面（两个设备都要依次执行此步骤）。  
4.在两台设备都成功连上服务器后，在其中一个设备上点击创建房间按钮，任意输入房间号，另一个设备会收到邀请进入房间的信息弹框，点击确定按钮后，两个设备进入聊天页面。
5.在其中一个设备上输入聊天信息并点击发送按钮后，另一个设备的聊天页面会收到该聊天消息。  
6.点击顶部标题栏左侧的返回图标按钮，则返回创建房间页面。  
7.以上运行完成后如需再次创建房间请重启客户端和服务端进行调试。  
##### 基本原理
1.UDP Socket：使用UDP Socket实现文本传输，无需搭建服务器，对端直接交流。  
2.TCP Socket：使用TCP Socket实现文本传输和公共通知事件转发，需要Python脚本搭建TCP服务器，公共通知用于来起音频通话应用。  
3.TLS Socket：使用TLS Socket实现文本传输，需要Python脚本搭建TLS服务器，服务器和客户端需要同一套证书文件。  
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Socket)

#### 网络管理-Socket连接
##### 介绍
本示例主要设计三种协议方式：UDP Socket、TCP Socket以及TLS Socket，展示在使用不同协议时，Socket在两端设备的连接验证、聊天通信方面的应用。
##### 使用
1.打开应用，点击用户文本框选择要登录的用户，并输入另一个设备的IP地址，点击确定按钮进入已登录的用户页面（两个设备都要依次执行此步骤）。

2.在其中一个设备上点击创建房间按钮，任意输入房间号，另一个设备会收到有房间号信息的弹框，点击确定按钮后，两个设备进入聊天页面。

3.在其中一个设备上输入聊天信息并点击发送按钮后，另一个设备的聊天页面会收到该聊天消息。

4.点击顶部标题栏右侧的退出图标按钮，则返回已登录的用户页面。

5.点击聊天页面中的昵称栏，会弹出一个菜单，选择离线选项后，两端设备的状态图标都会切换为离线图标，并且昵称栏都会变成灰色，此时任何一端发送消息另一端都接收不到消息。

6.当点击昵称栏再次切换为在线状态，则两端的己方账号状态会切换为在线图标，同时两端的昵称栏会显示蓝色，此时可正常收发消息。
##### 基本原理
本示例分为三个模块
1.输入对端IP模块:使用wifi.getIpInfo()方法获取IP地址，constructUDPSocketInstance方法创建一个UDPSocket对象。  
2.创建房间模块：点击创建房间按钮，弹出创建房间框，输入房间号，点击确定，进入聊天页面。
3.聊天模块：bindOption方法监听消息，设置在线与离线。  
##### 约束与限制
开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/StageSocket)

#### 上传和下载

##### 介绍

本示例使用[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)接口创建上传和下载任务，实现上传、下载功能，hfs作为服务器，实现了文件的上传和下载和任务的查询功能。

##### 使用
1.本示例功能需要先配置服务器环境后使用，具体配置见[上传下载服务配置](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad/environment)。

2.首页展示上传和下载两个入口组件，点击进入对应的页面，如果要使用后台下载任务，请开启后台任务开关。

3.上传页面：

​    点击 **+** ，**从相册选择**拉起图库选择照片，图片选择页面支持拍照，选择照片后点击**上传**进行上传。

​    可选的，点击缩略图，显示文件片段上传配置选项弹窗，可以配置上传起点和终点，取值为闭区间；起点默认为0，终点默认为文件结尾。点击**上传**进行选中文件片段以及后续文件全部内容上传。

​    点击**返回**键或片段上传配置选项弹窗外区域，取消片段上传。

​    在首页中打开后台任务开关后，上传页面开启的是后台上传任务，后台任务在应用退出到后台时可以在通知栏看到任务状态。

4.下载页面：

​    点击文件列表选择要下载的文件后，点击**下载**选择指定路径后开始下载。

​    点击**查看下载文件**进入下载文件页面，点击文件夹查看文件夹内的文件。

​    在首页中打开后台任务开关后，下载页面开启的是后台下载任务，后台任务在应用退出到后台时可以在通知栏看到任务状态。

​    前台下载时只支持单文件下载，后台下载时支持选择多个文件下载。
##### 基本原理

* 该示例分为两个模块：
  * 上传模块
    * 使用[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)中API 10接口agent.create创建上传任务，调用@ohos.request中的Task相关接口实现上传任务的创建、取消、进度加载，失败的任务会调用查询接口获取失败原因并打印在日志中，支持多个文件上传及片段上传。
    * 参考接口：[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)，[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)
  * 下载模块
    * 使用[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)中API 10接口agent.create创建上传任务，调用@ohos.request中的Task相关接口实现上传任务的创建、取消、进度加载，失败的任务会调用查询接口获取失败原因并打印在日志中，前台下载任务只支持单个文件下载，后台下载任务支持多文件下载。使用[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)完成指定路径的创建和查询已下载的文件。
    * 参考接口：[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)，[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/UploadAndDownLoad)

#### WebSocket

##### 介绍

本示例展示了[WebSocket](reference/apis-network-kit/js-apis-webSocket.md)的使用，包括客户端与服务端的连接和断开以及客户端数据的接收和发送。

##### 使用

1.输入服务器IP地址，点击**绑定服务器IP地址**按钮，即可绑定该IP并退出弹框，如果要解绑IP，重启应用即可。

2.点击顶部栏的**连接**按钮，按钮颜色从灰色变为绿色，即可与服务器建立WebSocket连接，并开始监听服务器发来的消息。

3.在底部消息输入框输入消息，点击**发送**按钮，即可收到来自服务端的消息回馈。

4.再次点击顶部栏的**连接**按钮，按钮颜色从绿色重新变成灰色，即可与服务器断开连接，接收不到服务器发来的消息。

5.重新连接需要退出应用重新绑定ip，再次点击连接才可以发送接收消息。

##### 基本原理

* 本示例分为两大模块
  * 客户端与服务端的连接和断开模块
    * BindServiceIP方法输入服务器IP地址，socket.connect方法绑定服务器，进入消息框页面，socket.on方法连接服务器，socket.off方法断开连接
    * 接口参考：[@ohos.prompt](reference/apis-arkui/js-apis-promptAction.md)，[@ohos.net.webSocket](reference/apis-network-kit/js-apis-webSocket.md)

  * 客户端数据的接收和发送模块
    * TopBar组件搭建通讯页面，socket.send方法发送信息数据。
    * 接口参考：[@ohos.prompt](reference/apis-arkui/js-apis-promptAction.md)，[@ohos.net.webSocket](reference/apis-network-kit/js-apis-webSocket.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/WebSocket)

#### VPN连接

##### 介绍

本示例使用@ohos.net.vpn接口演示了创建VPN隧道、建立VPN网络、VPN隧道保护、销毁VPN网络以及使用@ohos.net.vpnExtension接口创建三方VPN等功能。实现了使用VPN进行服务器连接，发送数据的功能。

##### 使用

1. 进入应用前请先安装[VPNFoundation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Connectivity/VPN/lib/VPNFoundation-1.0.0.hap)。

2. 进入应用后，主界面有启用VPN和停用VPN的选项,分别对应开启和关闭VPN功能。

3. 在主界面，可以点击启用VPN来创建VPN连接。

4. 在VPN启动界面，可以配置VPN服务器IP地址/隧道IP地址/使用VPN的应用程序。

5. 在VPN启动界面，点击创建对象可以创建VPN隧道，点击隧道保护可以开启隧道保护，点击启动VPN可以进行网络连接。

6. 在主界面，可以点击停用VPN来断开和关闭VPN连接。

7. 以上演示系统VPN，如果使用三方VPN，点击启动vpnExt按钮，弹窗提示VPN使用许可，同意后三方VPN启动并自动连接，尝试用浏览器等hap包访问百度。

##### 基本原理

本示例应用所演示的功能主要封装在StartVpn.ets和StopVpn.ets。
* 调用StartVpn.CreateTunnel()来创建VPN隧道。
* 调用StartVpn.SetupVpn()来建立VPN网络。
* 调用StopVpn.Destroy()来销毁VPN网络。
* 调用StartVpn.Protect()来开启VPN隧道保护。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.6.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/VPN)

### DFX

#### 应用故障恢复

##### 介绍

本示例展示了在应用中如何适配故障恢复相关接口。示例包括一下场景：单Ability自动恢复、多Ability自动恢复、多Ability主动恢复、Ability后台强制终止恢复。

##### 使用

一.单Ability自动恢复 \
点击首页点击``跳转到故障触发页面`` \
在故障触发页面点击按钮``点击``，再点击``保存当前Ability状态``以及``触发JsError``。 \
以上场景预期：\
能够回到``故障触发页面``页面，页面上的点击次数与触发保存状态时的一致。

二.多Ability自动恢复 \
点击首页点击跳转到``故障触发页面`` \
在``故障触发页面``点击``启动SecondAbility``
点击首页点击``跳转到故障触发页面`` \
在故障触发页面点击按钮``点击``，再点击``保存当前Ability状态``以及``触发JsError``。 \
以上场景预期：\
立即回到SecondAbility的故障触发页面，并恢复页面的点击次数信息。\
从任务管理中将EntryAbility切回前台，预期能回到故障触发页面，页面上的点击次数与触发保存状态时的一致。

三.多Ability主动恢复 \
点击首页点击跳转到``故障触发页面`` \
在``故障触发页面``点击``启动SecondAbility``
在SecondAbility的故障触发页面点击设置重启Ability。 \
在SecondAbility的故障触发页面点击``触发JsError``。 \
以上场景预期：\
重启时启动RecoveryAbility。

四.Ability后台强制终止恢复 \
点击首页点击跳转到``故障触发页面`` \
在``故障触发页面``点击``启动SecondAbility``
在SecondAbility的故障触发页面点击Counter，点击``保存当前Ability状态``,并切入后台 \
使用kill命令强制终止当前应用 \
以上场景预期：\
从任务管理中将EntryAbility切回前台，预期能回到故障触发页面，并恢复页面上的点击次数信息。\
从任务管理中将SecondAbility切回前台，预期能回到故障触发页面，并恢复页面上的点击次数信息。

为避免反复拉起，两次测试的间隔至少为60秒(自动拉起的间隔为60秒)。

##### 基本原理

* 使能应用恢复功能
    * 在``onCreate``中 调用[appRecovery](dfx/apprecovery-guidelines.md)接口使能功能
* 配置支持恢复的Ability
    * 在``Ability``的节点中增加``recoverable``的配置，并设置为``true``
* 实现恢复功能
    * 在``onSaveState``中保存用于恢复的数据
    * 在``onCreate``的``want``参数中恢复所需要的数据

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/AppRecovery)

#### Debug

##### 介绍

本示例通过使用[@ohos.hidebug](reference/apis-performance-analysis-kit/js-apis-hidebug.md) 接口来获取应用进程实际使用的物理内存大小、进程的共享脏内存大小、进程的私有脏内存大小等内存使用情况。

##### 使用

1.点击界面右上方Debug图标，弹出Debug信息界面，显示当前应用内存使用情况；

2.再次点击右上方Debug图标，Debug信息界面消失。

##### 基本原理

* 本实例获取Debug信息的功能结主要封装在Index。
    * 获取Debug信息：在Index页面中通过点击事件调用hidebug.getPss()、hidebug.getSharedDirty()、hidebug.getPrivateDirty()等方法能够获取应用进程实际使用的物理内存大小、进程的共享脏内存大小、进程的私有脏内存大小。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/Debug)

#### 测试打点

##### 介绍

本示例展示了在eTS中如何获取应用故障相关信息，测试打点包括应用打点与性能打点两部分，应用打点通过调用[@ohos.hiAppEvent](reference/apis-performance-analysis-kit/js-apis-hiappevent.md)接口来记录应用运行过程中发生的各种信息。

##### 使用

1.点击"事件写入"按钮，显示成功写入事件。

2.打开"禁用应用打点"开关，再次点击"事件写入"按钮，显示事件写入失败。

3.关闭"禁用应用打点"开关，再次点击"事件写入"按钮，显示事件写入成功。

##### 基本原理

* 该示例使用hiAppEvent接口中write方法将事件写入到当天的事件文件中，EventType方法枚举事件类型，configure方法去配置打点开关来实现测试打点。
* 接口参考：[@ohos.hiAppEvent](reference/apis-performance-analysis-kit/js-apis-hiappevent.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/DotTest)

#### 故障日志获取

##### 介绍

本示例使用了[@ohos.faultLogger](reference/apis-performance-analysis-kit/js-apis-faultLogger.md)接口，展示在eTS中如何获取js_crash故障、cpp_crash故障、freeze_crash故障等不同场景下应用故障相关信息。

##### 使用

1. 启动应用后，点击**构造异常**按钮，在弹窗中选择故障类型，点击确定可以构造异常场景;
2. 构造异常场景后，重新启动应用，点击下面不同的获取异常按钮可以获取到对应类型的异常日志并显示在页面文本框中。

##### 基本原理

+ 创造应用故障场景，故障类型枚举值参考[faultType](reference/apis-performance-analysis-kit/js-apis-faultLogger.md#faulttype)：
    + js_crash故障：通过数组访问越界构造;
    + cpp_crash故障：通过调用不存在的Api接口构造;
    + freeze_crash故障：通过代码产生死循环构造;
+ 获取上述异常故障日志,源码参考：
    + 获取异常故障日志：使用faultLogger.query接口获取异常日志信息。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/FaultLogger)

#### 日志打印

##### 介绍

本示例使用[hilog日志系统](reference/apis-performance-analysis-kit/js-apis-hilog.md) ，提供日志打印类，使应用/服务可以按照指定级别、标识和格式字符串输出日志内容，帮助开发者了解应用/服务的运行状态，更好地调试程序。

##### 使用

1.进入应用会自动生成一个空的日志文件。

2.点击log按钮即可输出日志，并将日志生成到日志文件当中。

##### 基本原理

+ 日志输出功能封装在Logger:
    + 日志输出：Logger类根据Configure的types参数将日志分为三个类型，其中file类型会将日志写入本地文件，console类型调用ConsoleLoggerStrategy类输出，hilog类型调用HilogLoggerStrategy类输出;
    + 日志文件写入本地：FileLoggerStrategy类使用[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md) 将日志写入本地文件中，本示例只是展示了文件写入文件操作的使用方法，在实战场景中，建议把耗时操作放入子线程中运行。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DFX/Logger)

### 数据管理

#### 首选项

##### 介绍

本示例使用[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md) 接口，展示了使用首选项持久化存储数据的功能。

##### 使用

1.点击顶部titleBar的右侧**切换**按钮，弹出主题菜单，选择任意主题则切换相应的主题界面；

2.退出应用再重新进入，显示上一次退出前的主题界面。

##### 基本原理

* 切换主题：在首页预先设置好几套主体数据，使用preferences.getPreferences获取使用Preferences对象，调用Preferences.get()
读取缓存中的参数，得到当前应该展示哪一套主体。每次点击切换按钮都会调用Preferences.put()来重新修改参数，然后使用
Preferences.flush()保存并刷新文件内容。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/Preferences)

#### 标准化数据定义与描述

##### 介绍

 本示例主要使用[@ohos.data.uniformTypeDescriptor](reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md) 展示了标准化数据定义与描述的功能。在新增预置媒体文件后，支持对媒体文件的utd标准类型获取、utd类型归属类型查询、获取文件对应的utd类型的默认图标、自定义数据类型等功能。 实现过程中还使用到[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md) 、[@ohos.router](reference/apis-arkui/js-apis-router.md)等接口。

##### 使用

1. 在主界面，点击“Please select a media file”进入选择媒体类型的主页面。

2. 在选择媒体类型界面，点击“下拉列表”，在展开的列表中可以选择一种媒体类型，如“Audios”，下面的列表中显示预置文件夹中所有归属于Audio的文件。

3. 在选择媒体类型界面，点击文件列表中某个文件，跳转到“显示文件信息”界面，该界面中显示文件归属类型的图标和文件名。

4. 在选择媒体类型界面，点击返回箭头图标，返回到“选择媒体类型”界面。

##### 基本原理

* 新增文件夹和媒体文件功能：

  * 使用fs.accessSync来检查文件或文件夹是否已存在。

  * 使用fs.mkdirSync创建文件夹，文件夹在应用的沙箱目录files下创建。

  * 遍历文件名数组precastFiles，使用fs.accessSync检查文件是否已存在。

  * 使用fs.openSync创建上一步检查结果为不存在的文件。
    
* 查找文件归属类型的功能：

  * 使用fs.listFileSync获取指定目录下的所有文件保存在数组中。

  * 遍历数组中每个文件，调用函数lastIndexOf获取文件后缀位置，再使用接口substring获取文件的后缀。

  * 使用getUniformDataTypeByFilenameExtension获取文件的utd。

  * 使用getTypeDescriptor获取标准化数据类型。

  * 使用接口belongsTo检查文件是否归属于选中的媒体类型，如果返回值为true，则将该文件名保存在显示数组中。

  * 通过标准化数据类型的属性iconFile，获取标准化数据类型的默认图标资源ID。

  * 上述接口的使用参考[@ohos.data.uniformTypeDescriptor](reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md)。

##### 约束与限制

开发语言：ArkTS

配套版本：API1版本SDK，版本号：4.1.6.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DataManagement/UDMF/UniformTypeDescriptor/UTDType)

### 设备管理

#### 设备管理合集（非系统特性）

##### 介绍

本示例集合设备管理相关（非系统特性）不需要复杂功能展示的模块，展示了各个模块的基础功能，包含：

- [@ohos.batteryInfo (电量信息)](reference/apis-basic-services-kit/js-apis-battery-info.md)
- [@ohos.charger (充电类型)](reference/apis-basic-services-kit/js-apis-charger-sys.md)
- [@ohos.deviceInfo (设备信息)](reference/apis-basic-services-kit/js-apis-device-info.md)
- [@ohos.power (系统电源管理)](reference/apis-basic-services-kit/js-apis-power.md)
- [@ohos.runningLock (Runninglock锁)](reference/apis-basic-services-kit/js-apis-runninglock.md)
- [@ohos.settings (设置数据项名称)](reference/apis-basic-services-kit/js-apis-settings.md)
- [@ohos.stationary (设备状态感知框架)](reference/apis-multimodalawareness-kit/js-apis-stationary.md)
- [@ohos.thermal (热管理)](reference/apis-basic-services-kit/js-apis-thermal.md)
- [@ohos.usbManager (USB管理)](reference/apis-basic-services-kit/js-apis-usbManager.md)
- [@ohos.multimodalInput.inputConsumer (组合按键)](reference/apis-input-kit/js-apis-inputconsumer-sys.md)
- [@ohos.multimodalInput.inputDevice (输入设备)](reference/apis-input-kit/js-apis-inputdevice.md)
- [@ohos.multimodalInput.inputEvent (输入事件)](reference/apis-input-kit/js-apis-inputevent.md)
- [@ohos.multimodalInput.inputEventClient (按键注入)](reference/apis-input-kit/js-apis-inputeventclient-sys.md)
- [@ohos.multimodalInput.inputMonitor (输入监听)](reference/apis-input-kit/js-apis-inputmonitor-sys.md)
- [@ohos.multimodalInput.keyCode (键值)](reference/apis-input-kit/js-apis-keycode.md)
- [@ohos.multimodalInput.keyEvent (按键输入事件)](reference/apis-input-kit/js-apis-keyevent.md)
- [@ohos.multimodalInput.mouseEvent (鼠标输入事件)](reference/apis-input-kit/js-apis-mouseevent.md)
- [@ohos.multimodalInput.pointer (鼠标指针)](reference/apis-input-kit/js-apis-pointer.md)
- [@ohos.multimodalInput.touchEvent (触摸输入事件)](reference/apis-input-kit/js-apis-touchevent.md)

##### 使用

1.首页展示语言基础类库各个子模块菜单，点击进入对应的模块页面。

2.各个子模块界面中点击功能按钮完成各个功能。

3.电量信息：进入电量信息页面，展示设备电量相关信息。

4.RunningLock锁：点击按钮分别实现设备支持的休眠锁类型、设置屏幕休眠时间功能、设置是否通过接近或者远离状态来控制亮灭屏的锁功能。

5.系统电源管理：点击按钮分别实现获取亮灭屏状态、获取电源模式功能。

6.设置数据项名称：点击按钮分别实现获取数据项uri、开关飞行模式、检查应用是否能以悬浮形式显示功能。

7.设备状态感知框架：点击按钮分别实现订阅设备状态服务、取消订阅设备状态服务、查询设备状态并显示功能。

8.热管理：进入热管理页面，展示当前设备热档位信息、设备过热时提示用户。

9.USB管理：打开监听开关后插入USB设备，会有提示并刷新设备列表，关闭监听后插入USB设备不会提示和自动刷新，下拉设备列表可以手动刷新设备列表。

##### 基本原理

1.首页菜单展示：使用一个module，menuitems完成菜单组件的实现，传入要展示的菜单的strarray类型的资源和菜单点击对应的组件即可。使用Navigation和NavRouter组件实现菜单点击进入功能界面，使用LocalStorage实现应用内Ability内数据共享，点击菜单时标记selectedLabel，在entry中的Capabilities组件中，通过selectedLabel显示对应的功能组件。

2.电量信息：使用[@ohos.batteryInfo.d.ts](reference/apis-basic-services-kit/js-apis-battery-info.md)
接口获取电池和充放电状态信息。

3.RunningLock锁：使用[@ohos.runningLock.d.ts](reference/apis-basic-services-kit/js-apis-runninglock.md)
实现对Runninglock锁的创建、查询、持锁、释放等操作。

4.系统电源管理：使用[@ohos.power.d.ts](reference/apis-basic-services-kit/js-apis-power.md)
实现获取亮灭屏状态、查询电源模式功能。

5.设置数据项名称：使用[@ohos.settings.d.ts](reference/apis-basic-services-kit/js-apis-settings.md)
实现获取获取数据项uri、开关飞行模式、检查应用是否能以悬浮窗形式显示功能。

6.设备状态感知框架：使用[@ohos.stationary.d.ts](reference/apis-multimodalawareness-kit/js-apis-stationary.md)
接口提供设备状态感知能力。

7.热管理：使用[@ohos.thermal.d.ts](reference/apis-basic-services-kit/js-apis-thermal.md)
提供热管理相关的接口，查询热档位以及注册温控等级回调。

8.USB管理：使用[@ohos.usbManager.d.ts](reference/apis-basic-services-kit/js-apis-usbManager.md)
实现usb设备列表的获取，使用[@ohos.commonEventManager.d.ts](reference/apis-basic-services-kit/js-apis-commonEventManager.md)
订阅USB设备插入和拔出监听。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/DeviceManagementCollection)

#### 位置信息

##### 介绍

本示例使用 [geolocation](reference/apis-location-kit/js-apis-geolocation.md) 实现获取当前位置的经纬度，然后通过 [http](reference/apis-network-kit/js-apis-http.md) 将经纬度作为请求参数，获取到该经纬度所在的城市。通过 [AlphabetIndexer](reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md) 容器组件实现按逻辑结构快速定位容器显示区域。

##### 使用

1. 进入主页，点击国内热门城市，配送地址会更新为选择的城市。点击右边字母索引条，可快速定位到想要选择的城市区域，点击该城市后若该城市还细化到区，继续点击该城市的区，配送地址会更新为城市/区，若未细化到区，则只选择城市。
2. 若测试机支持GPS，点击国内热门城市上面的定位图标，应用会获取本机所在经纬度，然后根据经纬度获取所在城市，定位图标后的城市会进行刷新，当前城市数据为模拟数据。

##### 基本原理

+ 本示例展示获取定位的功能在页面中直接调用，使用geolocation.on方法获取当前位置的经纬度，然后监听经纬度变化发送request请求获取对应城市信息。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Location)

#### 屏幕探测

##### 介绍

本示例实时监测连接的屏幕数量状态，支持创建至多5个虚拟屏幕，点击对应的屏幕矩形能显示该屏幕的相关属性。

##### 使用

1.第一步：进入开始界面

2.第二步：点击右下方的“+”按钮，添加虚拟屏幕，连续点击后，至多创建5个虚拟屏幕。

3.第三步：点击右下方的“-”按钮，移除虚拟屏幕，连续点击删除全部的虚拟屏幕后，再次点击会提示告警信息。

4.第四步：点击屏幕矩形，展示相关屏幕的属性（首字母为R的为真实屏幕，首字母为V的为虚拟屏幕）

##### 基本原理

* 真实屏幕模块
  * 首字母显示为R，且不能进行删除，点击跳转屏幕属性页面展示真实屏幕属性
  * 接口参考：[@ohos.display](reference/apis-arkui/js-apis-display.md)，[@ohos.router](reference/apis-arkui/js-apis-system-router.md)

* 新增和删除虚拟屏幕模块
  * getAllDisplay获取当前所有的display对象，getDefaultDisplay获取当前默认的display对象,push方法新增虚拟屏幕，增加超过5个虚拟屏幕时，给出警告，pop方法删除虚拟屏幕，全部删除虚拟屏幕后，点击给出警告，点击虚拟屏幕展示虚拟屏幕属性
  * 接口参考：[@ohos.display](reference/apis-arkui/js-apis-display.md)，[@ohos.router](reference/apis-arkui/js-apis-system-router.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/ScreenDetector)

#### 振动

##### 介绍

本示例模拟倒计时场景，通过[@ohos.vibrator](reference/apis-sensor-service-kit/js-apis-vibrator.md) 等接口来实现振动。

##### 使用

1.点击倒计时文本，弹出时间选择框，选择任意时间，点击**确认**，倒计时文本显示选择的时间。

2.点击**start**，开始倒计时，圆形进度条和文本开始变化；倒计时结束，开始振动，进度条恢复初始状态并且弹出振动提示框，按照描述进行选择。

3.点击**reset**，可以结束倒计时并使文本和进度条恢复初始状态。

##### 基本原理

* 本示例实现振动的方法主要封装在TextTimerComponent中。
    * 设置倒计时间：Timepicker文件中通过TextPicker组件来设置倒计的时间，并将设定的时间数据双向绑定到TextTimerComponent组件当中。
    * 启动倒计时：点击start按钮通过setInterval执行倒计时，每隔一段时间Process组件的进度值会被此代码this.progressValue += TOTAL / this.duration进行处理同步刷新。
    * 触发振动：当时间为0的时候，则执行vibrator.vibrate()方法去触发振动效果。
    * 初始化时间：点击reset按钮会将Process组件的value以及时间进行初始化，并清除定时器。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/BasicVibration)

#### 自定义振动

##### 介绍

本示例使用[Vibrator模块](reference/apis-sensor-service-kit/js-apis-vibrator.md)展示了振感定制化的基本功能，包括振感与音效、视频协同振动等。

##### 使用

1. 在"我的"界面中包含开发信息及基本设置，点击振动强度设置，可选择振动强度等级，本步骤可选，默认为低强度模式；
2. 在"发现"界面，振效库中罗列了不同体验场景，可点击各条目享受音效与振动的协同感受；
3. 在"发现"界面，触感效果视频可体验视频与振动的协同，点击视频预览图片进入全屏播放界面；
4. "显示更多"中罗列了当前的振感视频列表。

##### 基本原理

+ 振动强度设置：可以选择振动的强度等级；
+ 振效库：点击振效库中各项，会调用媒体库AVPlayer播放音效，并同时调用vibrator模块startVibration接口启动振动;
+ 振感视频：使用Video控件全屏播放视频，在开始播放同时调用vibrator模块startVibration接口启动振动；
+ 自定义振动：使用[Vibrator模块](reference/apis-sensor-service-kit/js-apis-vibrator.md)的startVibration方法播放应用内置的振动资源文件;

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/CustomHaptic)

### 设备信息统计

#### 设备使用信息统计

##### 介绍

本示例使用[bundleState](reference/apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md)相关接口完成设备中应用时长的统计功能。

##### 使用

1.顶部的数据面板展示了最常用的五个应用的使用时间占比情况。

2.中部的竖向滑动栏展示了每个应用的使用总时长和最后一次使用的时间。

3.底部的横向滑动栏展示了不常用应用列表。

##### 基本原理

* 该示例使用bundleState接口中isIdleState方法判断指定bundleName的应用当前是否是空闲状态来分类不常用应用列表，queryBundleStateInfos方法通过指定起始和结束时间查询应用使用时长统计信息来获得每个应用的使用总时长。
* 接口参考：[@ohos.bundleState](reference/apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceUsageStatistics/DeviceUsageStatistics)

### 文件管理

#### 应用接入数据备份恢复

##### 介绍

本示例主要给备份流程提供应用，用于生成数据和显示数据。应用接入数据备份恢复需要通过配置BackupExtensionAbility实现。BackupExtensionAbility，是[Stage模型](application-models/stage-model-development-overview.md)中扩展组件[ExtensionAbility](application-models/extensionability-overview.md)的派生类。开发者可以通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复，备份哪些文件等。

##### 使用

1. 点击按钮“生成文件数据”，应用会随机生成2个到10个txt文件，大小在1Byte到1024Byte之间，用于校验备份和恢复的数据为同一数据。
2. 本应用仅适用于生成和显示数据，具体的备份和恢复的操作目前需要使用hdc shell命令操作。
3. 具体操作方面，进入应用点击按钮生成文件数据后，进入hdc shell，使用backup_tool backup --isLocal=true --bundle com.samples.backupextension  --pathCapFile /data/backup/tmp命令进行备份。然后可以把应用删掉，重新安装应用后进入hdc shell，使用backup_tool restore --bundle com.samples.backupextension --pathCapFile /data/backup/tmp，提示成功后，重新打开应用可以看到备份的文件显示在列表里。

##### 基本原理

1. 在应用配置文件`module.json5`中注册`extensionAbilities`相关配置
2. 新增元数据资源配置文件
3. 使用应用生成数据
4. 备份与恢复操作

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileBackupExtension)

#### 文件管理

##### 介绍

本示例主要展示了文件管理相关的功能，使用[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md) 、[@ohos.file.fileAccess](reference/apis-core-file-kit/js-apis-fileAccess-sys.md)、[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md) 、[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)。

等接口，实现了增添文件、删除文件、查找指定类型文件文件、复制并移动文件和预览图片、监听文件的功能。

##### 使用

1. 在主界面，可以点击图片、视频、文档、音频等按钮进入对应目录的文件列表浏览界面；
2. 在文件列表浏览界面，点击“+”按钮，可以添加文件；
3. 在文件列表浏览界面，长按列表项会出现删除图片，点击删除图标可以删除文件；
4. 在图片文件列表界面，点击图片可以进入图片预览界面。
5. 在主页点击“我的手机”，进入应用沙箱目录下。
6. 在主页点击“监听文件”，进入文件监听页面。

##### 基本原理

* 增添文件、删除文件、查找指定类型文件文件和预览图片的功能接口封装在MediaLibraryManager。
* MyPhone模块中的文件增删、复制移动、查找功能封装在FileSystem。
* 在Library模块中通过封装FileManager向外提供功能接口，如MediaLibraryManager.getPixelMapByFileAsset()。
* 监听文件模块中的文件增删、查找、修改、监听功能封装在MyWatcher


##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/FileManagement/FileManager)

#### 选择并查看文档与媒体文件

##### 介绍

应用使用[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)、[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)、[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md) 等接口，实现了picker拉起文档编辑保存、拉起系统相册图片查看、拉起视频并播放的功能。

##### 使用

1. 在首页，应用展示出最近打开过的文档信息，点击信息可以进入对应文档的查看界面。通过点击右上方的三个按钮，可以分别实现新建文档、选择图片或视频并打开预览、选择文档并打开的功能。
2. 在查看文档界面，点击右上方左一按钮，可以实现当前文档另存为的功能；点击右上方中间的按钮，开启文档的编辑功能，textArea变成可编辑状态，用户输入数据后点击右上方第三个按钮，可以将当前文档内容进行保存操作。
3. 在查看图片界面，picker拉起系统相册的图片，用户至多可选择三张图片查看，点击图片可以切换所显示的图片名及大小信息。
4. 在查看视频界面，picker拉起系统相册的视频，用户至多可选择三个视频查看，点击视频播放并且可以显示的视频名及大小信息。

##### 基本原理

- 拉起picker选择文件、拉起picker保存文件、拉起picker选择图片或视频的功能封装在Index.ets
  * 使用mediaLiabrary.getMediaLibrary来获取媒体库的实例，用于访问和修改用户等个人媒体数据信息（如视频、图片、文档等）；使用media.getFileAssets来获取文件资源；使用来fetchFileResult.getFirstObject获取文件检索结果中的头一个文件资产，接口参考：[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)
  * 使用new picker.DocumentViewPicker来创建文件picker实例，使用documentPicker.select来拉起picker选择文件，使用documentPicker.save来拉起picker保存文件，接口参考：[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)
  * 使用new picker.PhotoViewPicker来创建图库picker实例，使用photoPicker.select来拉起picker选择图片或视频，接口参考：[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)

- 编辑文件并保存的功能封装在EditFile.ets
  * 使用fs.mkdirSync、fs.openSync、fs.writeSync、fs.readSync、fs.closeSync分别用来来创建文件夹、打开文件、写文件、读文件、关闭文件，接口参考：[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)

- 拉起图片或视频并查看的功能封装在ViewMedia.ets
  * 使用new picker.PhotoViewPicker来创建图库picker实例，使用photoPicker.save来拉起picker保存图片或视频，接口参考：[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)
  * 使用mediaLiabrary.getMediaLibrary来获取媒体库的实例，用于访问和修改用户等个人媒体数据信息（如视频、图片、文档等），然后使用media.getFileAssets来获取文件资源再使用fileAsset.displayName来获取图片或视频的名称，接口参考：[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)


##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/FileManagement/FileShare/Picker)

#### 为应用之间分享和文件访问提供统一的入口能力

##### 介绍

本示例主要展示了沙箱文件分享相关的功能，使用 [@ohos.file.fileuri](reference/apis-core-file-kit/js-apis-file-fileuri.md) 、[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)、[@ohos.ability.wantConstant](reference/apis-ability-kit/js-apis-ability-wantConstant.md)、[@ohos.application.Want](reference/apis-ability-kit/js-apis-app-ability-want.md) 等接口，实现了获取文件uri、创建沙箱文件、提供want中操作want常数和解释Flags说、应用组件间的信息传递的功能。

##### 使用

1. 因本应用的功能依赖Picker应用，在使用本应用之前首先应安装[Picker](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/FileManagement/FileShare/Picker)应用;
2. 在主界面，可以点击沙箱文件夹列出文件夹中的文件，同时也可以直接点击沙箱目录下的文件进入文件分享界面；
3. 点击沙箱文件，进入文件分享界面，点击分享图标，文件将以picker方式打开文件，点击编辑图标，文件进入可编辑模式，在textArea中输入内容，然后点击保存，文件内容更新，返回沙箱应用首页，文件修改成功。

##### 基本原理

* 增添文件、查找指定类型文件、获取文件uri、传递want信息启动ability的功能接口封装在fileFs.ts

  * 使用fs.mkdirSync、fs.openSync、fs.writeSync、fs.readSync、fs.closeSync分别用来来创建文件夹、打开文件、写文件、读文件、关闭文件，接口参考：[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)

  * 使用fileUri.getUriFromPath来获取文件uri，接口参考：[@ohos.file.fileuri](reference/apis-core-file-kit/js-apis-file-fileuri.md) 

  * 分享文件至picker应用打开并编辑：

    调用 implicitStartAbility 方法传递want参数启动新的ability，接口参考：[@ohos.ability.wantConstant](reference/apis-ability-kit/js-apis-ability-wantConstant.md)、[@ohos.application.Want](reference/apis-ability-kit/js-apis-app-ability-want.md)


##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileShare/SandboxShare)

#### 媒体管理合集

##### 介绍

本示例主要展示网络流播放能力、音视频播控能力、音量调节能力。

##### 使用

1. 启动应用，点击音频或视频可以查看本地音视频资源。若本地没有音视频资源，可以push视频到本地媒体库路径，视频路径(storage/media/100/local/files/Videos)  音频路径(storage/media/100/local/files/Audios)，需要先hdc进入storage/media/100/local/files路径下查看是否有Videos/Audios文件夹，没有则需要mkdir Videos/Audios创建文件夹后push音视频资源。
2. 进入首页，可以通过输入网络地址或点击音频，视频进行播放音视频。
3. 音视频播放后，对于播控按键显示，点击播放、暂停可以播放、暂停音视频，点击循环图标可以在单曲循环和列表循环进行切换。
4. 点击下一曲、上一曲可以切换音视频，拖动seek可以跳到指定位置播放，点击详细信息可以查看当前音视频信息，视频点击倍速可以开启倍速播放。
5. 音视频列表左滑可以开启重命名、删除图标，点击对应图标可以进行音视频的重命名和删除。

##### 基本原理

* 获取音频模块
  * 使用媒体库接口进行音视频的扫描，获取音视频详细信息，重命名和删除操作，使用PixelMap方法读取或写入图像数据以及获取图像信息。
  * 接口参考：[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)，[@ohos.prompt](reference/apis-arkui/js-apis-prompt.md)

* 音频，视频操作模块
  * 使用媒体服务进行音视频播放，暂停，seek等操作，其中AudioPlayer方法播放音频，VideoPlayer方法播放视频。
  * 接口参考：[@ohos.multimedia.media](reference/apis-arkui/js-apis-display.md)，[@ohos.multimedia.audio](reference/apis-audio-kit/arkts-apis-audio.md)

* 设备适配模块
  * 使用屏幕管理接口获取设备宽度进行适配。
  * 接口参考：[@ohos.display](reference/apis-arkui/js-apis-display.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/FileManagement/MediaCollections)

#### 相册

##### 介绍

本示例主要展示了相册相关的功能，使用[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md) 接口，实现了查看系统相册、创建用户相册、查看相册照片、用户相册文件添加和删除、以及预览图片、最近删除、收藏夹操作等功能。

##### 使用

1. 主界面：查询显示所有照片、系统相册（相机/视频/截屏录屏/我的收藏/最近删除）、用户相册
2. 主界面点击“+”，创建用户相册
3. 创建用户相册时添加图片到用户相册
4. 长按相册，删除相册
5. 长按相册，重命名相册（不可重名）
6. 长按相册，相册多选，批量删除
7. 点击相册，查看相册中的图片列表
8. 点击图片，查看单个图片大图
9. 点击心形图标，收藏图片
10. 点击心形图标，取消收藏
11. 大图界面，重命名文件（可重名）
12. 大图界面，删除文件（移动到最近删除相册）
13. 从最近删除恢复照片
14. 点击视频，查看视频并播放
15. 点击图片页面右上角叹号，查看图片详情
16. 长按图片批量操作：多选/全选、删除、恢复
17. 相册内图片列表界面点击“+”，从已有相册添加照片
18. 长按图片列表图片，更多菜单，从图片选择添加到已有相册
19. 在相册图片列表界面，长按图片，选择图片，点击更多，可以将图片加入到其他相册（可多选）
20. 在用户相册图片列表界面，长按图片，选择图片，点击更多，可以将图片从当前相册移除（可多选）
21. 在用户相册图片列表界面，长按图片，选择图片，点击更多，可以查看图片详情（可多选）

##### 基本原理

在base模块中通过封装photoAccessHelper向外提供功能接口。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/FileManagement/Photos)

### IDL

#### Ability与ServiceExtensionAbility通信

##### 介绍

本示例展示通过[IDL的方式](IDL/idl-guidelines.md#ts开发步骤) 和 [@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md) 等接口实现了Ability与ServiceExtensionAbility之间的通信。

##### 使用

1.启动应用后，首页展示城市的天气信息，当前温度每隔5S会刷新一次。

##### 基本原理

* Ability与ServiceExtensionAbility通信的方法主要封装在idl_weather_service_proxy、idl_weather_service_stub、HomeFeature、ServiceExtAbility中。
    * 建立服务器连接：通过HomeFeature中的this.context.connectAbility(want, this.options)方法来建立服务器连接；
    * 接收服务端实例并发送请求：连接成功时new IdlWeatherServiceProxy(proxy)来接收服务端实例，通过[@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md) 接口来执行new rpc.MessageOption(0)、 new rpc.MessageParcel()、 new rpc.MessageParcel()获取 MessageParcel对象和请求的模式，调用idl_weather_service_proxy中的this.proxy.sendRequest()来发送请求；
    * 接收远程请求处理数据：在idl_weather_service_stub中接收远程请求并通过ServiceExtAbility中的updateWeather()函数来处理数据进行返回；
    * 获取数据：最后将获得的数据渲染到页面中去；
    * 断开连接：可以通过HomeFeature中的this.context.disconnectAbility(this.connection)方法来断开服务器连接，这里的this.connection是建立连接之后的返回值。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/IDL/AbilityConnectServiceExtension)

### 国际化

#### 国际化

##### 介绍

本示例主要展示了国际化模块的相关功能，使用[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n.md) 接口，实现简单日历展示、字符类型判断、文本断点处理功能。

##### 使用

1. 在主界面，可以点击日历、字符文本处理按钮进入对应功能界面；
2. 在日历界面，点击“<” “>”按钮，可以查看上/下月公历信息；
3. 在字符、文本处理界面，上方输入框输入一个字符，点击字符类型判断可以查看当前输入的字符类型，下方输入框输入长文本，点击文本断点可以查看文本断点结果，断点处用红色/标记；

##### 基本原理

1. 日历功能使用[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n.md)模块中Calendar实现，全部逻辑处于Calendar。
2. 字符类型判断功能使用[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n.md)模块中Unicode实现，全部逻辑处于TextProcessing。
3. 文本断点功能使用[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n.md)模块中breakIterator实现，全部逻辑处于TextProcessing。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/International/International)

### 媒体

#### 音视频录制

##### 介绍

本示例主要使用@ohos.multimedia.media中的AVRecorder接口实现了录制功能；另外辅助使用@ohos.multimedia.medialibrary接口，实现了创建录制文件功能，接口使用以及权限获取详见媒体库管理。使用@ohos.multimedia.camera接口，实现了相机预览及出流功能，接口使用以及权限获取详见[相机管理](reference/apis-camera-kit/arkts-apis-camera.md)。

##### 使用

1. 在主界面，可以点击视频录制、音频录制进入对应功能界面；
2. 点击视频录制页面，进入页面呈现摄像头预览画面，用户可以通过点击左上角的设置图标进行视频分辨率参数设置，点击”开始“”暂停“”恢复“”停止“等对应图标按钮进行视频录控相关操作。
3. 点击音频录制页面，用户可以通过点击左上角的设置图标进行音频采样率参数设置，点击”开始“”暂停“”恢复“”停止“等对应图标按钮进行音频录控相关操作。

##### 基本原理

* 录控功能接口调用实现参考工程目录中的音频录制页面和视频录制页面
  * 调用create()、prepare()、getInputSurface()、start()、pause()、resume()、stop()、reset()、release()接口实现录制器的创建、准备、录控操作、重置、销毁实例等功能；
  * 视频录制调用Camera接口实现相机出流功能配合视频录制功能，相机的实现方法参考自相机接口[@ohos.multimedia.camera](reference/apis-camera-kit/arkts-apis-camera.md)
* 调用MediaLibrary实现创建录制，实现方法参考@ohos.multimedia.medialibrary接口说明

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.10.8

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVRecorder)

#### 媒体会话——控制方（仅对系统应用开放）

##### 介绍

本示例主要展示了媒体会话（媒体控制方）的相关功能，使用[@ohos.multimedia.avsession](reference/apis-avsession-kit/arkts-apis-avsession.md)等接口实现媒体提供方与媒体控制方自定义信息的交互功能。

##### 使用

1. 打开媒体控制方示例应用，可以看到音乐应用的历史记录。
2. 点击播放按钮，应用的播放状态发生变化。
3. 点击暂停按钮，应用的播放状态开始变化。
4. 点击上一首按钮，界面展示播放列表中的上一首歌曲的信息。
5. 点击下一首按钮，界面展示播放列表中的下一首歌曲的信息。
6. 点击歌词按钮，界面中出现歌词。
7. 点击播放列表按钮，界面中出现播放列表。
8. 点击播放列表中的歌曲，媒体提供方切换到对应的歌曲。

##### 基本原理

* 界面相关的实现都封装在pages/Index.ets下
    * 使用`@StorageLink`来设置与逻辑代码同步更新的变量，当逻辑代码中对应的变量更新时，界面会同步的刷新。
    * 通过引入逻辑代码对应的类，创建出对象，实现对onClick事件的响应

* 逻辑相关的实现都封装在feature/MediaController.ets下

  应用的初始化相关操作

    * 链接变量

      通过`AppStorage.SetAndLink()`将逻辑代码中的变量与界面代码中使用`@StorageLink`声明的变量连接起来，通过`set()`与`get()`操作来修改或获取变量的值
    * 获取当前设备中会话并创建Controller

      通过接口`getAllSessionDescriptors()`获取当前设备中的媒体会话；  
      通过接口`createController()`创建媒体会话对应的控制器；  
      通过接口`getHistoricalSessionDescriptors()`获取当前设备中的媒体会话历史记录；  
      通过接口`on(metadataChange | playbackStateChange | queueItemsChange | queueTitleChange | sessionEvent)`开启对媒体提供方发送事件的监听，对媒体提供方的事件进行处理；

  应用在运行中相关的操作

    * 发送基础控制命令到媒体提供方

      基础控制命令可以通过接口`sendControlCommand()`发送。本示例中，从媒体控制方到媒体提供方的基础控制命令主要包括`play, pause, playPrevious, playNext`

    * 获取自定义会话数据

      媒体控制方可以使用接口`sendCommonCommand()`发送自定义控制命令，当媒体会话提供方接收到命令后，会通过接口`dispatchSessionEvent()`与接口`setExtras()`将歌词信息发送给媒体会话控制方。（此部分请参见媒体会话提供方Sample）

    * 获取当前会话信息
      通过接口`getAVQueueItems()`获取当前歌曲列表信息；  
      通过接口`getAVQueueTitle()`获取当前歌曲列表名称信息；  
      通过接口`getAVPlaybackState()`获取当前歌曲播放状态信息；  
      通过接口`getAVMetadata()`获取当前歌曲媒体会话元数据信息；  

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/AVSession/MediaController)

#### 媒体会话——提供方

##### 介绍

本示例主要展示了媒体会话（媒体提供方）的相关功能，使用[@ohos.multimedia.avsession](reference/apis-avsession-kit/arkts-apis-avsession.md)等接口实现媒体提供方与媒体控制方自定义信息的交互功能。

##### 使用

1. 打开媒体提供方示例应用。
2. 点击播放按钮，应用的播放状态发生变化，歌词开始更新。
3. 点击暂停按钮，应用的播放状态开始变化，歌词停止更新。
4. 点击上一首按钮，应用界面展示播放列表中的上一首歌曲的信息。
5. 点击下一首按钮，应用界面展示播放列表中的下一首歌曲的信息。

##### 基本原理

* 界面相关的实现都封装在pages/Index.ets下
  * 使用`@StorageLink`来设置与逻辑代码同步更新的变量，当逻辑代码中对应的变量更新时，界面会同步的刷新。

  * 通过引入逻辑代码对应的类，创建出对象，实现对onClick事件的响应

* 逻辑相关的实现都封装在feature/ProviderFeature.ets下

  应用的初始化相关操作

  * 链接变量

    通过`AppStorage.SetAndLink()`将逻辑代码中的变量与界面代码中使用`@StorageLink`声明的变量连接起来，通过`set()`与`get()`操作来修改或获取变量的值

  * 创建并设置媒体会话

    通过接口`createAVSession()`创建媒体会话；  
    通过接口`activate()`激活媒体会话；  
    通过接口`setAVQueueItems()`设置播放列表，设置后媒体控制方可以读取使用该信息；  
    通过接口`setAVQueueTitle()`设置播放列表标题，设置后媒体控制方可以读取使用该信息；  
    通过接口`setAVMetadata()`设置当前媒体的元数据，设置后媒体控制方可以读取使用此信息；  
    通过接口`on()`开启对媒体控制方控制命令的监听，对媒体控制方的命令进行处理；  

  应用在运行中相关的操作

  * 切换歌曲

    在切换歌曲时，除了需要设置媒体提供方自身的状态，还需要使用接口`setAVPlaybackState()`与接口`setAVMetadata()`将当前播放状态与元数据同步给媒体控制方。

  * 发送自定义数据包

    媒体提供方可以使用接口`dispatchSessionEvent()`与接口`setExtras()`来发送自定义数据包。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVSession/MediaProvider)

#### 音频管理

##### 介绍

本示例主要展示了音频的相关功能，使用[@ohos.multimedia.audio](reference/apis-audio-kit/arkts-apis-audio.md)等接口实现音频的发声设备的切换与查询、音频焦点、音效的查询与设置以及音频录制等功能。

##### 使用

注意：6，7，8是连续的串行操作，不是并行的

1. 弹出麦克风权限访问提示框，点击“允许”
2. 在主界面点击“发声设备查询与选择”按钮，进入发声设备查询与选择页面
3. 在发声设备查询与选择页面界面，展示当前发声设备类型名称
4. 在发声设备查询与选择页面界面，当设备存在“插入耳机”、“拔掉耳机”、“连接蓝牙”、“断开蓝牙”等操作行为时，当前发声设备类型名称会随之切换
5. 在发声设备查询与选择页面界面，点击“返回”按钮，回到主页
6. 在主界面点击“音频焦点”按钮，进入音频焦点页面
7. 在音频焦点页面，点击音乐播放器，音乐开始播放
8. 在音频焦点页面，点击铃声播放器，铃声开始播放，同时音乐被暂停
9. 在音频焦点页面，点击铃声播放器，停止铃声播放，音乐恢复播放
10. 在音频焦点页面，点击“返回”按钮，回到主页
11. 在主界面点击“音效管理”按钮，进入预置音效查询页面
12. 在预置音效查询页面，选择内容类型和场景后，点击“查询”按钮，预置音效模式会显示在下方查询结果中
13. 在预置音效查询页面，重新修改内容类型和场景，查询结果会重置
14. 在预置音效查询页面，点击右下方”实时音效设置“按钮，进入实时音效设置页面
15. 在实时音效设置页面，选择内容类型和场景后，点击播放按钮，音频流开始播放，同时内容类型和场景选择框被置灰
16. 在实时音效设置页面，点击”查询“按钮，当前音频流音效模式会显示在下方的查询结果中
17. 在实时音效设置页面，点击暂停按钮，音频流暂停，内容类型和场景选择框使能
18. 在实时音效设置页面，修改内容类型与场景选择，查询结果被重置
19. 在实时音效设置页面，再次点击播放按钮，音频流开始播放，点击”查询“按钮，结果显示在查询结果内
20. 在实时音效设置页面，在”音频流音效模式设置“选择框中选择另一种与上次查询结果不同的音效模式，可以听到音频流出现变化
21. 在实时音效设置页面，再次点击”查询“按钮，查询结果与上一步设置的模式相同
22. 在实时音效设置页面，点击左上方返回图标，回到主页
23. 在实时音效设置页面，点击左下方”预置音效查询“按钮，回到预置音效查询页面
24. 在主界面点击“音频录制”，进入音频录制界面，音频录制界面默认是普通录制界面
25. 在普通录制界面，点击录制按钮，开始录制，录音时间开始计时，5s内不允许结束
26. 在普通录制界面，点击暂停按钮，暂停录制，录音时间也停止计时
27. 在普通录制界面，点击继续按钮，继续录制，录音时间继续计时
28. 在普通录制界面，点击停止录制按钮，停止录制，也可以不停止录制，应用设置了30s的超时后，自动停止录制
29. 停止录制后，会生成录制结果，界面上有一个录制成功的音频播放器，点击播放可听到录制的音频
30. 点击并行录制按钮，可切换到并行录制界面
31. 在并行录制界面中，点击音乐播放器，播放音乐
32. 在并行录制界面中，点击录制按钮，开始录制，同时开启麦克风录制和屏幕录制，5s内不允许结束
33. 在并行录制界面中，点击停止录制按钮，停止录制，或者超时30s会自动停止录制，停止后按钮点成不可点击状态
34. 在并行录制界面中，录制停止后，会生成两个音频播放器，一个是麦克风的录音结果，一个是屏幕录制的结果，点击进行播放，暂停，播放结束自动停止
35. 点击返回按钮回到主页

##### 基本原理

* 发声设备查询与切换功能都封装在PreferOutputDevice。
* 音频焦点功能都封装Focus。
* 预置音效查询功能都封装在PresetEffect。
* 音频录制-普通录制功能都封装在NormalCapturer。
* 音频录制-并行录制功能都封装在ParallelCapturer。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Audio)

#### 拼图

##### 介绍

该示例通过[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)和[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)接口实现获取图片，以及图片裁剪分割的功能。

##### 使用

1. 使用预置相机拍照后启动应用，应用首页会读取设备内的图片文件并展示获取到的第一个图片，没有图片时图片位置显示空白；
2. 点击Start开始后，时间开始倒计时，在规定时间内未完成拼图则游戏结束。在游戏中，玩家点击Restart进行游戏重置；
3. 点击开始游戏后，玩家可以根据上方的大图，点击灰格周围的图片移动，点击后图片和灰格交换位置,最终拼成完整的图片；
4. 不在游戏中时，玩家可以点击上方大图，选择自定义图片来进行拼图游戏。

##### 基本原理

+ 游戏中图片裁剪分割的效果实现在ImageModel中:
  + 获取本地图片：首先使用getMediaLibrary获取媒体库实例，然后使用getFileAssets方法获取文件资源，最后使用getAllObject获取检索结果中的所有文件资产方便展示；
  + 裁剪图片准备：裁剪图片需要使用[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)接口，裁剪前需要申请图片编辑权限，使用[requestPermissionsFromUser](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)申请;
  + 图片编辑：首先使用createImagePacker创建ImagePacker实例，然后使用fileAsset.open打开文件，调用createImageSource接口创建ImageSource实例方便操作图片，接下来使用getImageInfo方法获取图片大小便于分割，最后使用createPixelMap方法传入每一份的尺寸参数完成图片裁剪。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.18

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/GamePuzzle)

#### 图片编辑

##### 介绍

本示例使用 [TextArea](reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md) 实现多文本输入，使用 [@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md) 依赖系统的图库引用，实现在相册中获取图片，使用 [@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md) 生成pixelMap，使用pixelMap的scale()，crop()，rotate()接口实现对图片的缩放，裁剪，旋转功能。 使用[@ohos.effectKit](reference/apis-arkgraphics2d/js-apis-effectKit.md) 生成effectKit,使用effectKit.getHighestSaturationColor() 接口实现对图片的高亮调节。添加文字/贴纸，利用组件的组合编辑素材大小和位置，再使用OffscreenCanvasRenderingContext2D进行离屏绘制保存。

##### 使用

1. 发表评价页面点击添加图片/照片，页面跳转到图片选择页面；
2. 进入图片选择页面后，选择需要显示的图片；
3. 选中图片后，页面会跳转到发表评价页面，点击图片跳转到图片编辑删除页面，点击编辑进入到编辑功能页；
4. 调整菜单有裁剪、缩放、旋转、调色功能；
5. 标记菜单有添加文字、添加贴纸功能；
6. 编辑完成后，点击撤回按钮图片会还原到上一个编辑状态；
7. 图片编辑完成后，点击保存，页面会跳转到发表评价页面，显示相关照片；
8. 点击返回按钮，退出应用。

##### 基本原理

+ 图片选择功能在GetPictures中实现:
    + 图片选择：首先使用startAbilityForResult()启动系统图库应用，然后将选择的图片用select数组保存路径，展示到页面便于选择，选择完跳转到首页，点击一张图片，进入到编辑删除界面。
+ 图片编辑功能在EditImage中实现:
    + 图片编辑：图片编辑权限需要使用[requestPermissionsFromUser](reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)
    申请
    ，首先根据选择图片获取到的uri打开图片文件，fileAsset.open选择‘rw'读写模式，然后使用image.createImageSource创建ImageSource实例，接下来使用createPixelMap创建PixelMap对象，便于处理图片，最后使用crop对图像进行裁剪处理，使用scale对图像进行缩放处理，rotate进行旋转处理。亮度调节使用effectKit.getHighestSaturationColor()
    接口实现对图片的高亮调节。添加文字/贴纸，编辑模式下，使用组件组合（Image、Shape、Text）进行交互完成素材大小和位置选择；编辑确认后，再使用OffscreenCanvasRenderingContext2D进行离屏绘制，保存为新的pixelMap。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Image)

#### 图片显示

##### 介绍

本示例使用 [TextArea](reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md) 组件实现多文本输入，使用 [mediaLibrary](reference/apis-arkui/js-apis-mediaquery.md) 实现从相册选择图片展示在商品评价页面。

##### 使用

1.点击添加图片/照片，页面跳转到图片选择页面。

2.进入图片选择页面后，选择需要显示的图片，选择的图片数量会显示在右上方，选择的图片会显示在下方。最多选择6张图片。

3.选定图片后点击下一步，页面会跳转回主页面，图片显示在主页。若不确定选择，点击添加图片/照片进行重新选择。

4.图片选择后，点击文本输入框，可以对商品进行评价。

5.点击返回按钮，退出应用。

##### 基本原理

* 本示例分为三个模块：
  * 发表评价页面模块：
    * 使用scroll，TextArea，Grid等组件开发发表评价页面
    * 参考接口：[@ohos.router](reference/apis-arkui/js-apis-router.md)

  * 选择图片/照片模块
    * 调用依赖中ChoicePhotos方法打开相册，mediaquery媒体查询相册，getMediaLibrary获取媒体库的实例，访问用户等个人媒体数据信息并选中图片
    * 参考接口：[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.promptAction](reference/apis-arkui/js-apis-promptAction.md)，[@ohos.mediaquery](reference/apis-arkui/js-apis-system-mediaquery.md)，[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)，[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)
  
  * 提交模块
    * 选中图片后点击下一步按钮，回到发表评价页面，点击提交按钮进行提交
    * 参考接口：[@ohos.router](reference/apis-arkui/js-apis-router.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/ImageShow)

#### 二维码扫描

##### 介绍

本示例使用[相册管理](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)、[相机管理](reference/apis-camera-kit/arkts-apis-camera.md)、[图片处理](reference/apis-image-kit/arkts-apis-image.md)、[文件管理](reference/apis-core-file-kit/js-apis-fileio.md)展示二维码扫描功能，包括相机扫描解析二维码和从相册中选择二维码图片解析。

##### 使用

1. 启动应用，授予权限。
2. 自动识别二维码图片。
3. 点击右上角图片图标，在相册中选择对应的二维码图片，会返回首页展示结果。

##### 基本原理

+ 相机功能在CameraServices中
    + 获取相机实例：首先使用getCameraManager方法获取相机管理器，然后使用getSupportedCameras方法得到设备列表；
    + 打开相机：使用createCameraInput方法创建CameraInput实例，调用open方法打开相机；
    + 获取相机输出流：使用getSupportedOutputCapability查询相机设备在模式下支持的输出能力，然后使用createPreviewOutput创建相机输出流，使用[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image-ImageReceiver.md#getreceivingsurfaceid9)接口的createPhotoOutput方法创建相片输出流；
    + 获取相片输出：首先使用createCaptureSession方法创建**捕获会话**的实例，然后使用beginConfig方法配置会话，接下来使用addInput方法添加一个摄像头输入流，使用addOutput添加一个摄像头和相机照片的输出流，使用commitConfig方法提交会话配置后，调用start方法开始捕获相片输出。
+ 二维码解析功能在QRCodeParser中
    + 拍照获取图片：使用[cameraService.imageReceiver.on](reference/apis-image-kit/arkts-apis-image-ImageReceiver.md#on9)接收图片时注册回调，然后调用readNextImage获取处理图片的操作，然后使用getComponent方法根据图像的组件类型从图像中获取组件缓存，然后将获取到的ArrayBuffer写入指定文件中，返回文件uri，然后通过[ImageBitmap](reference/apis-arkui/arkui-ts/ts-components-canvas-imagebitmap.md)将uri转化为ImageBitMap格式，具体文件写入方式参考[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)。
    + 打开相册选取图片：首先需要使用[startAbilityForResult](reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilityforresult)启动相册，将选到的图片通过ImageBitmap转化为ImageBitmap格式。
    + 图片解析：使用[CanvasRenderingContext2D](reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md)的getImageData方法创建ImageData对象将相册中获取到的图片转化为util8格式的图片，然后调用jsQR库解析图片中的二维码。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/QRCodeScan)

#### 录音机

##### 介绍

本示例使用[audio](reference/apis-audio-kit/arkts-apis-audio.md)相关接口实现音频录制和播放的功能，使用[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md)实现音频文件的管理。

##### 使用

1.启动应用，点击首页底部**录制**按钮跳转到录制界面开始录制音频，录制过程中可以点击右下角的**暂停**按钮暂停录制，点击顶部**返回键**或红色的**停止**按钮停止录音并返回首页，首页中展示录制好的音频文件。

2.点击**音频文件**可以播放该文件，播放界面可以点击按钮进行暂停和继续播放。

3.长按音频文件进入多选状态，可以选择音频文件，选择后可以点击底部的按钮进行重命名和删除操作。

4.左滑音频文件，可以滑出重命名和删除按钮，点击可以对该音频文件进行重命名和删除操作。

##### 基本原理

* 本示例分为三个模块：
    * 录音页面模块
        * 使用FileAsset提供封装文件属性的方法，createAudioPlayer同步方式创建音频播放实例实现录音，暂停录音功能
        * 参考接口：[audio](reference/apis-audio-kit/arkts-apis-audio.md)，[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md)，[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.window](reference/apis-arkui/arkts-apis-window.md)，[@ohos.promptAction](reference/apis-arkui/js-apis-promptAction.md)，[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)

    * 录音列表模块
        * getMediaLibraryAPI访问媒体数据信息，renameCallBack，renameDialogController方法对录音进行重命名，deleteFile，deleteDialogShow方法删除某条录音。
        * 参考接口：[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md)，[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.window](reference/apis-arkui/arkts-apis-window.md)，[@ohos.promptAction](reference/apis-arkui/js-apis-promptAction.md)，[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)

    * 播放模块
        * createAudioPlayer方法创建音频播放实例，onPageShow方法播放音频，onPageHide方法暂停播放音频。
        * 参考接口：[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md)，[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.5.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Recorder)

#### 视频播放

##### 介绍

视频播放的主要工作是将视频数据转码并输出到设备进行播放，同时管理播放任务。本文将对视频播放全流程、视频切换、视频循环播放等场景开发进行介绍说明。 本示例主要展示了播放本地视频和网络视频相关功能,使用 [@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media-e.md#bufferinginfotype8),[@ohos.resourceManager](reference/apis-localization-kit/js-apis-resource-manager.md),[@ohos.wifiManager](reference/apis-connectivity-kit/js-apis-wifiManager.md)等接口,实现了视频播放、暂停、调节倍速、切换视频的功能。

##### 使用

1.点击视频界面，唤起视频操作面板，再次点击操作面板消失，如果不做任何操作操作界面会5s自动消失;

2.点击暂停/播放按钮，控制视频暂停播放;

3.滑动视频进度条，视频跳转到指定位置,在视频中间会出现时间进度方便用户查看视频进度;

4.点击倍速，可以选择1.0、1.25、1.75、2.0进行倍速调节;

5.点击下方视频名称，可以选择视频进行切换。注意：network是网络视频，检测到没有连接网络会退出应用，有网络能在本地视频和网络视频进行切换;

6.点击左上角退出箭头，退出应用。

##### 基本原理

+ 视频倍速切换、暂停、播放、切换视频、视频跳转的功能接口都封装在AvPlayManager.ts;
+ 使用media.createAVPlayer()来获取AVPlayer对象;
+ 倍速切换：选择不同的倍速时调用avPlayer.setSpeed(speed: PlaybackSpeed);
+ 暂停、播放：点击暂停、播放时调用avPlayer.pause()、avPlayer.play();
+ 切换视频：在切换视频前要先调用avPlayer.reset()重置资源，再通过avPlayer.fdSrc为fdSrc赋值触发initialized状态机上报;
+ 视频跳转：在拖动滑动条时调用avPlayer.seek()

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoPlay)

#### 媒体库视频

##### 介绍

本示例使用[Video组件](reference/apis-arkui/arkui-ts/ts-media-components-video.md)展示了视频组件的基本功能，包括视频组件化，全屏化，窗口化，上下轮播视频等。

##### 使用

1. 进入首页点击播放按键；
2. 点击视频播放按钮，视频开始播放,再次点击视频进入视频全屏页；
3. 首页下滑500vp后，视频小窗口化；
4. 点击直播按钮进入直播页，上下滑动视频。

##### 基本原理

  + 视频播放：start方法视频开始播放；
  + 全屏播放：再次点击视频进入全屏播放页面，使用setCurrentTime参数设定当前播放时间，pause方法停止播放;
  + 小窗口播放：记录当前播放时间，小窗口页面渲染之前设置视频当前播放时间，页面滚动到固定距离开始展示组件；
  + 直播：使用[http](reference/apis-network-kit/js-apis-http.md)接口的request方法获取直播数据;

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VideoShow)

#### 音频通话示例

##### 介绍

本示例主要展示了音频通话相关的功能，使用[@ohos.multimedia.audio](reference/apis-audio-kit/arkts-apis-audio.md) 、[@ohos.net.socket](reference/apis-network-kit/js-apis-socket.md) 等接口，实现音频录制和渲染，音频数据网络传输等功能。

##### 使用

1.语音通话需要运行服务端代码模拟启动流媒体服务端，连接成功后服务端会在终端打印client连接数：

2.服务端和两台设备在局域网内组成socket网络，运行时需要注意修改ip地址：

- 服务端地址在socket.js
- 客户端地址在BufferModel.ets，将serverIp替换为服务端IP地址即可

3.仅体验语音通话功能时，可以两台设备都手动启动语音通话应用，分别点击接听按钮进入通话页面

4.体验场景所有功能时，需要两台设备启动[聊天应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/StageSocket),通过左下方语音按钮发起语音通话

5.一方发起语音通话请求，对方选择同意或拒绝

6.对方同意后，进行通话

7.通话页或请求通话页可以选择关闭麦克风或扬声器

8.对方拒接或同意后挂断，则返回聊天页面

##### 基本原理

+ TCP socket模拟音频流网络传输：

    + 使用@ohos.net.socket 的constructTCPSocketInstance创建TCP socket连接，模拟实现音频流网络传输
    + 3s一次检查网络状态和尝试连接，实现网络异常时的处理逻辑
+ 音频录制：
    + 使用@ohos.multimedia.audio.AudioCapturer完成音频采集 [具体使用参考](media/audio/using-audiocapturer-for-recording.md)
+ 音频播放：
    + 使用@ohos.multimedia.audio.AudioRenderer完成音频播放 [具体使用参考](media/audio/using-audiorenderer-for-playback.md)
+ 麦克风与扬声器以及通话场景控制：
    + 使用@ohos.multimedia.audio.AudioManager的setAudioScene接口切换通话场景
    + 使用@ohos.multimedia.audio.AudioVolumeGroupManager的setMicrophoneMute接口切换麦克风
    + 使用@ohos.multimedia.audio.AudioRoutingManager的setCommunicationDevice接口切换扬声器

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/VoiceCallDemo)

#### 相机示例

##### 介绍

本示例主要展示了相机的相关功能，利用相关接口实现了相机的预览、拍照、录像、前后置摄像头切换进行拍照、录像，以及闪光灯、变焦、对焦、曝光等控制类功能。

##### 使用

(因RK3568设备硬件能力，现仅支持验证1、2、3、9、10、13)

1. 弹出是否允许应用使用相机？点击“允许”。弹出是否允许应用使用麦克风？点击“允许”。弹出是否允许应用访问文件？点击“允许”。

2. 进入预览界面，预览正常，滑动变焦按钮，同一画面远近变焦效果明显。

3. 进入预览界面，预览正常，点击画面模糊处，点击处画面会变得清晰，对焦效果明显。

4. 进入预览界面，预览正常，上下滑动屏幕，屏幕场景亮度发生变化，曝光效果明显。

5. 进入预览界面，预览正常，点击闪光灯按钮，打开闪光灯，闪光灯正常打开。

6. 进入预览界面，预览正常，点击闪光灯按钮，关闭闪光灯，闪光灯关闭。

7. 进入预览界面，预览正常，进入拍照模式，点击拍照按钮，拍照正常。点击左下角生成的缩略图能够跳转到图库，打开图片显示正常。

8. 进入预览界面，预览正常，切换到录像模式，点击开始录像，再点击停止录像按钮，录像成功。点击左下角生成的缩略图能够跳转到图库，播放录像文件正常。

9. 进入预览界面，预览正常，切换到前置摄像头，点击拍照按钮，拍照正常。点击左下角生成的照片缩略图能够跳转到图库，打开图片显示正常。

10. 进入预览界面，预览正常，切换到前置摄像头，切换到录像模式，点击开始录像，再点击停止录像按钮，录像成功。点击左下角生成的缩略图能够跳转到图库，播放录像文件正常。

11. 点击设置按钮，会弹出设置页面，仅验证UI。

##### 基本原理

  * 拍照功能相关接口封装在StartPhoto接口中，主要包含以下流程：
    * 调用SessionStop关闭session。
    * 调用SessionBegin做session的一个预置动作。
    * 调用CreatePhotoOutput创建相机输出。
    * 调用OH_CaptureSession_AddPhotoOutput将hotoOutput添加至session中。
    * 调用SessionCommitConfig提交session。然后调用SessionStart开启session。
    * 调用调用TakePicture接口开启拍照动作。

  * 录像功能相关接口封装在StartVideo接口中，主要包含以下流程：
    * 调用SessionStop关闭session。
    * 调用SessionBegin做session的一个预置动作。
    * 调用OH_CaptureSession_RemovePhotoOutput移除相机拍照输出。
    * 调用CreatePhotoOutput创建相机输出。
    * 调用AddPhotoOutput将相机输出添加至session中。然后CreateVideoOutput创建录像输出。
    * 调用AddVideoOutput将录像输出添加至session中。然后SessionCommitConfig、SessionStart对session进行提交和开启。
    * 调用VideoOutputRegisterCallback对VideoOutput注册回调。

  * 变焦功能相关接口封装在setZoomRatioFn接口中，主要包含以下流程：
    * 调用OH_CaptureSession_GetZoomRatioRange获取支持的变焦范围。
    * 调用OH_CaptureSession_SetZoomRatio设置变焦。
    * 调用OH_CaptureSession_GetZoomRatio获取当前设备的变焦值。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.15

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/Camera)

#### 音振协同

##### 介绍

本示例主要展示了音频播放和振动效果相互协同的能力，使用[@ohos.multimedia.audioHaptic](reference/apis-audio-kit/js-apis-audioHaptic.md)等接口完成播放音频同时伴随振动的功能，可用于同时需要声音与振动的场景。

##### 使用

注意：当选择任意一种类型开始播放时，其它按钮均不可点击

1. 在主界面点击“音振协同”按钮，进入音振协同播放类型选择页面。

2. 在音振协同播放类型选择页面，展示音振协同播放类型。

3. 在音振协同播放类型选择页面，点击通知类型播放器，通知类型开始播放并振动。

4. 在音振协同播放类型选择页面，点击铃声类型播放器，铃声类型开始播放并振动。

5. 在音振协同播放类型选择页面，点击闹钟类型播放器，闹钟类型开始播放并振动。

6. 在音振协同播放类型选择页面，点击“音频静音”（未点击振动静音），选择铃声类型播放器进行播放，铃声类型开始音频静音同时振动播放，直至播放自动结束，恢复暂停状态。

7. 在音振协同播放类型选择页面，点击“振动静音”（未点击音频静音），选择铃声类型播放器进行播放，铃声类型开始无振动同时有声播放，直至播放自动结束，恢复暂停状态。

8. 在音振协同播放类型选择页面，点击“振动静音”，点击“音频静音”，选择铃声类型播放器进行播放，铃声类型开始无振动同时无声播放，直至播放自动结束，恢复暂停状态。

9. 振协同播放选择页面，点击“返回”按钮，可返回主页。

##### 基本原理

* 音振协同功能的具体实现：
    * 使用audioHaptic.getAudioHapticManager()接口获取音振管理器。
    * 使用audioHapticManager.registerSource(audioUri, hapticUri)接口注册音频和振动资源的Uri，返回注册资源的source id。
    * 使用使用audioHapticManager.setStreamUsage()接口给指定source id设置音频使用类型。
    * 使用audioHapticManager.createPlayer(id, options)创建不同类型资源的音振播放器。
    * 使用audioHapticManager.setStreamUsage(id, streamUsage)分别设置通知类型、铃声类型和闹钟类型的使用类型。
    * 对每个player对象都监听AudioHapticPlayer.on('endOfStream'),收到回调时,说明当前类型资源播放结束，恢复暂停播放状态，据此更新UI状态。
    * 使用audioHapticManager.start()方法进行对指定类型音频开始播放处理。
    * 使用audioHapticManager.stop()进行指定类型音频的停止播放处理。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.6.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AudioHaptic)

#### 视频播放

##### 介绍

本示例主要展示了网络视频播放的相关功能。使用[@ohos.multimedia.avsession](reference/apis-avsession-kit/arkts-apis-avsession.md)等接口实现视频播放的功能。

##### 使用

1. 点击播放按钮，视频开始播放。

2. 点击暂停按钮，视频暂停播放。

3. 点击上一个按钮，界面展示播放列表中的上一个视频的信息。

4. 点击下一下按钮，界面展示播放列表中的下一个视频的信息。

##### 基本原理

* 界面相关的实现都封装在pages/Index.ets下：
    * 使用`@State`来设置与逻辑代码同步更新的变量，当逻辑代码中对应的变量更新时，界面会同步的刷新。

    * 通过引入逻辑代码对应的类，创建出对象，实现对onClick事件的响应，关键代码段：
      ```js
      
      import media from '@ohos.multimedia.media';     // 引入
      
      this.avPlayer = await media.createAVPlayer();  // 创建对象
      
      this.controller = await this.session.getController();  // 通过类的对象来调用逻辑代码

      ```

* 逻辑相关的实现都封装在common/MediaController.ets下：

  应用的初始化相关操作

    * 链接变量

      使用`@State`来设置与逻辑代码同步更新，关键代码段：

      ```ets
      @State session: avSession.AVSession = null;
      @State controller: avSession.AVSessionController = null;
      private avPlayer: media.AVPlayer;
      @State @Watch('playInfoUpdated') currentPlayInfo: avSession.AVMediaDescription = undefined;
      this.currentPlayInfo = temp;
      this.avPlayer = await this.audioUtils.init();
      ```

    * 获取当前设备中会话并创建Controller

      通过接口`audioUtils.init()`获取当前设备中的媒体会话；

      通过接口`session.getController()`创建媒体会话对应的控制器；

      通过接口`on(play | pause | stop | playNext | playPrevious | seek)`开启对远程以及播控中心提供方发送事件的监听，对事件进行处理；

  应用在运行中相关的操作

    * 从远程以及播控中心获取基础控制命令

      基础控制命令可以通过监听事件`setListenerForMesFromController()`。本示例中，从媒体控制方到媒体提供方的基础控制命令主要包括`play, pause, playPrevious, playNext`。发送命令的参考代码如下：
      ```ets
      let command : AVSessionManager.AVControlCommand = {
        command : 'play',
        parameter : undefined
      } // 构造AVControlCommand参数
      async setListenerForMesFromController(); // 媒体会话控制器与媒体会话一一对应
      ```

    * 获取自定义会话数据（以获取视频为例）

      > 说明：
      > 
      > 本示例中，用户点击“下一个视频”的命令，会在将视频信息更新。

      视频使用接口`switchToNextByLoopMode()`更新视频信息，示例代码如下：
      ```ets
      this.currentIndex = this.currentIndex  === this.songList.length - 1 ? 0 : this.currentIndex + 1;
      this.updateCurrentPlayInfo(this.songList[this.currentIndex], this.audioType);
      ```

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.6.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVSession/VideoPlayer)

### Native

#### 获取Rawfile资源

##### 介绍

本示例中主要介绍开发者如何使用Native Rawfile接口操作Rawfile目录和文件。功能包括文件列表遍历、文件打开、搜索、读取和关闭Rawfile。

##### 使用

应用界面中展示了Rawfile相关的接口调用，包括获取resources/rawfile目录下的文件及目录结构、对应的rawfile文件内容、对应rawfile文件的descriptor。其中使用到的功能包括文件列表遍历、文件打开、搜索、读取和关闭Rawfile。

##### 基本原理

通过在IDE中创建Native c++ 工程，在c++代码中定义对外接口为getFileList、getRawFileContent、getRawFileDescriptor，映射C++接口分别为GetFileList、GetRawFileContent、GetRawFileDescriptor。
通过获取Js的资源对象，并转为Native的资源对象，即可调用资源的Native接口，获取rawfile列表、rawfile文件内容以及rawfile描述符{fd, offset, length}。
在Js侧导入"libentry.so"，通过getContext().resourceManager获取资源管理对象。调用src/main/cpp/types/libentry/index.d.ts中声明的接口，传入js的资源对象和相关参数获取对于rawfile相关资源信息。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkRawfile)

#### Native XComponent

##### 介绍

本示例中主要介绍开发者如何使用Native XComponent接口来获取NativeWindow实例、获取布局/事件信息、注册事件回调并通过OpenGL/EGL实现在页面上绘制形状。功能主要包括点击按钮绘制一个五角星，并可以通过点击XComponent区域改变五角星的颜色。

##### 使用

1. 安装编译生成的hap包，并打开应用。

2. 点击页面底部“Draw Star”按钮，页面将绘制一个五角星。

3. 点击XComponent组件区域（页面中灰色区域）改变五角星颜色。

##### 基本原理

通过在IDE中创建Native c++ 工程，在c++代码中定义对外接口为drawPattern，在js侧调用该接口可在页面上绘制出一个三角形。

在XComponent的OnSurfaceCreated回调中获取NativeWindow实例并初始化EGL环境。调用OH_NativeXComponent_GetXComponentSize接口获取XComponent的宽高，并以此为输入调用EGL相关的绘制接口在NativeWindow上绘制出一个五角星。在DispatchTouchEvent回调中再次调用EGL相关的绘制接口在NativeWindow上绘制出一个大小相同、颜色不同的五角星，以达到点击后改变颜色的目的。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkXComponent)

#### OpenGL三棱椎

##### 介绍

本示例展示了XComponent相关控件的使用，及采用OpenGL (OpenGL ES)相关标准API绘制3D图形（三棱锥，3D渲染的光源用的是简单的线性光源）。此外，可在屏幕触摸滑动，以使三棱锥进行旋转，其中主要采用了napi接口来更新3D图形的旋转角度。

##### 使用

应用界面中展示了XComponent相关控件的使用，及采用OpenGL (OpenGL ES)相关标准API绘制3D图形（三棱锥，3D渲染的光源用的是简单的线性光源）。此外，可在屏幕触摸滑动，以使三棱锥进行旋转，其中主要采用了napi接口来更新3D图形的旋转角度。

##### 基本原理

通过在IDE中创建Native C++工程，在C++代码中定义接口为Init和Update用于3D图形绘制环境的初始化和图形渲染更新，并映射NAPI相关接口UpdateAngle。ArkTS侧主要利用XComponent控件实现Index.ets，C++侧主要采用OpenGL ES相关标准API实现三棱锥的绘制流程相关代码，并可与ArkTS进行交互。

应用启动时，NAPI模块也相应进行初始化，此时可通过C++侧的OH_NativeXComponent_GetXComponentId()接口，获取到当前XComponent控件的控件指针，并给到C++侧三棱锥绘制相关的Init和Update函数，实现3D图形显示。同时，为实现三棱锥的触摸屏滑动旋转效果，在C++代码中映射的NAPI接口UpdateAngle给到ArkTS侧调用。ArkTS侧需在导入NAPI模块"libtetrahedron_napi.so"正确的前提下，通过调用src/main/cpp/type/libentry/tetrahedron_napi.d.ts中声明的UpdateAngle接口更新三棱锥旋转角度。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkOpenGL)

#### 音频管理

##### 介绍

本示例主要展示了音频低时延录制和播放的相关功能：<br>
    1. [低时延录制](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/using-ohaudio-for-recording.md)。<br>
    2. [低时延播放](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/using-ohaudio-for-playback.md)。

##### 使用

1. 弹出麦克风权限访问提示框，点击“允许”，如果点击"禁止"则不可进行录制，需要用户去设置页面给应用授权后方可正常录制。

2. 在主界面点击“录制和播放”，进入音频录制界面，音频录制界面默认是普通录制界面，打开低时延录制开关可进行低时延录制。

3. 点击录制按钮，开始录制，开始录制后低时延录制开关变为不可点击状态，录音时间开始计时，5s内不允许结束，30s后会自动结束录制。

4. 点击暂停按钮，暂停录制，录音时间也停止计时。

5. 点击继续按钮，继续录制，录音时间继续计时。

6. 停止录制后，会生成录制结果，界面上有一个低时延播放开关和录制成功的音频播放器。点击低时延播放开关可打开低时延播放功能，点击播放可听到录制的音频，播放未结束之前低时延播放开关为不可点击状态。

7. 点击返回按钮回到主页。

##### 基本原理

音频录制和播放使用到了OHAudio开发音频录制功能。OHAudio是OpenHarmony在API version 10中引入的一套全新Naitve API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。

相关API使用可参考以下开发文档：
  * [低时延录制开发指导文档](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/using-ohaudio-for-recording.md)
  * [低时延播放开发指导文档](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/media/audio/using-ohaudio-for-playback.md)
  * [低时延录制开发示例](https://gitcode.com/openharmony/multimedia_audio_framework/blob/master/frameworks/native/ohaudio/test/example/oh_audio_capturer_test.cpp)
  * [低时延播放开发示例](https://gitcode.com/openharmony/multimedia_audio_framework/blob/master/frameworks/native/ohaudio/test/example/oh_audio_renderer_test.cpp)

##### 约束与限制

开发语言：ArkTS

配套版本：API12版本SDK，版本号：5.0.0.20

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/OHAudio)

#### Native Drawing

##### 介绍

本示例中主要介绍开发者在利用Native XComponent来获取NativeWindow实例、获取布局/事件信息、注册事件回调并通过Drawing API实现在页面上绘制形状。功能主要包括点击按钮绘制一个五角星和“Hello World Drawing”文字。

##### 使用

1.安装编译生成的hap包，并打开应用。

2.点击页面底部“Draw Path”按钮，页面将绘制一个五角星。

3.点击页面底部“Draw Text”按钮，页面将绘制“Hello World Drawing”。

##### 基本原理

通过在IDE中创建Native c++ 工程，在c++代码中定义对外接口为drawPattern和drawText，在js侧调用该接口可在页面上绘制出一个五角星和“Hello World Drawing”文字。

在XComponent的OnSurfaceCreated回调中获取NativeWindow实例并初始化NativeWindow环境。调用OH_NativeXComponent_GetXComponentSize接口获取XComponent的宽高，并以此为输入调用Drawing相关的绘制接口在NativeWindow上绘制出一个五角星和文字。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.13

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkDrawing)

#### Native Window

##### 介绍

本示例中主要介绍开发者在利用[Native XComponent](reference/apis-arkui/capi-native-interface-xcomponent-h.md)来获取[NativeWindow](reference/apis-arkgraphics2d/capi-nativewindow.md)实例，通过数据填充改变矩形框颜色。并提供从[NativeImage](reference/apis-arkgraphics2d/capi-oh-nativeimage.md)中获取NativeWindow进行buffer轮转的案例，通过NativeWindow生产buffer来触发NativeImage的可用帧回调。

##### 使用

1. 安装编译生成的hap包，并打开应用。

2. 点击页面底部“Chaneg Color”按钮，矩形框填充区域将改变颜色，黄蓝切换。

3. 点击页面底部“produce buffer”按钮，NativeWindow将生产数据并发送给NativeImage，页面展示了生产buffer的次数。

4. 点击页面底部“update available buffer count”按钮，将展示NativeImage收到的可用帧回调次数。

##### 基本原理

1. 通过在IDE中创建Native c++ 工程，在c++代码中定义对外接口为DrawColor，在js侧调用该接口可改变窗口颜色。
2. 从NativeImage中创建NativeWindow，在c++代码中定义对外接口为ProduceBuffer，js调用该接口后，NativeWindow会生产buffer并将该buffer flush给NativeImage。
3. NativeImage将收到可用帧的回调，js侧调用GetAvailableCount接口，可以获取回调触发次数，并展示在界面上；正常情况下FlushBuffer的次数和可用帧回调触发次数一致。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.3.3

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeWindow)

#### XComponent3D

##### 介绍

基于XComponent组件调用Native API来创建EGL/GLES环境，从而使用标准OpenGL ES进行图形渲染。本项目实现了两个示例：

1. 使用OpenGL实现2D的图形绘制和动画。

2. 使用OpenGL实现了在主页面绘制两个立方体，光源可以在当前场景中移动，并实现了光照效果。

##### 使用

1. 安装编译生成的hap包，进入主页面（在主页面，默认展示的是3D图形绘制效果）。

2. 点击DrawTransform可以切换展示2D图形绘制效果。

3. 点击DrawCube可以切换展示3D图形绘制效果。

##### 基本原理

* 在主页面显示了一个XComponent控件，默认显示立方体。通过用户点击，触发ChangeShape事件，opengl_draw收到事件，完成绘制内容变更。首页启动时，会触发一个定时器，每40ms触发一次，当opengl_draw收到事件时，进行动画更新。

* 在XComponent初始化完成时，OnSurfaceCreated回调里面，会自动开始图形绘制。源码参考[opengl_draw.cpp](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Native/XComponent3D/entry/src/main/cpp/opengl_draw.cpp) 。在opengl_draw.cpp里面Init方法会创建EglWindow和EGLSurface，然后创建上下文EGLContext，完成baseShape的初始化，默认使用Cube进行初始化。

* 绘制2D图形：rectangle.cpp的Init方法，完成Shader的初始化。Update方法主要是绘制两个图形，一个进行旋转，一个进行缩放。

* 绘制3D物体：cube.cpp的Init方法，完成Shader的初始化，相机的初始化。Update方法绘制了两个立方体，一个在屏幕中间，另一个会围绕中间的物体进行圆周运动。并且设置运动的物体为发光源，在中间物体展示不同角度的光照效果。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.13

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/XComponent3D)

### 通知

#### 公共事件的订阅和发布

##### 介绍

本示例主要展示了公共事件相关的功能，实现了一个检测用户部分行为的应用。具体而言实现了如下几点功能：

1.通过订阅系统公共事件，实现对用户操作行为（亮灭屏、锁屏和解锁屏幕、断联网）的监测；

2.通过在用户主动停止监测行为时发布自定义有序公共事件，实现对用户主动触发监听行为的持久化记录；

3.通过在用户设置对某一事件的监听状态时发布粘性事件，记录下本次应用运行期间允许监听的事件列表，同时在应用退出时将临时允许的修改为不允许。

##### 使用

1.安装编译生成的hap包，依赖包hap，桌面上显示应用图标，点击图标即可进入应用。

2.进入应用显示菜单页，可选择“进入”，“历史”，“设置”及“关于”几个选项。

3.点击“进入”后跳转至主页面，点击主页面“开始监控”按钮，将开始监听系统公共事件，并进行计时，此时按钮内容变更为“停止监听”；点击停止监听按钮，页面上将显示本次监听时长及监听期间收到的干扰信息汇总，并在页面右下角显示“查看详情”按钮，点击按钮将跳转至详情页，显示监听期间收到的干扰信息，应用当前仅监听了亮灭屏、锁屏和解锁屏幕、断联网等用户可操作的系统公共事件，后续可根据需求快速扩展。

4.返回至应用菜单页面，点击“历史”可查看用户操作监听的历史记录，当前支持每次运行期间最多存储10条历史记录，超过10条后将删除历史数据。

5.返回至应用菜单页面，点击“设置”可进行具体系统事件的监听配置，应用提供了“一直”、“仅本次”及“从不”三个选项，其中“仅本次”选项是指本次应用运行期间将监听特定系统公共事件，应用退出后该选项将自动调整为“从不”。

6.在设置页面，点击“自定义事件定向订阅”进入订阅页面，

7.返回至应用菜单页面，点击“关于”可查看应用版本信息及本示例的说明。

##### 基本原理

* 该示例entry部分分为五个模块：
  * 进入模块
    * 使用到应用文上下文，createSubscriber方法创建订阅者，getCurrentTime获取获取自Unix纪元以来经过的时间进行对用户操作行为的监测功能页面开发。
    * 参考接口：[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.commonEventManager](reference/apis-basic-services-kit/js-apis-commonEventManager.md)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)，[@ohos.commonEvent](reference/apis-basic-services-kit/js-apis-commonEvent.md)，[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.systemTime](reference/apis-basic-services-kit/js-apis-system-timer-sys.md)
  
  * 历史模块
    * 使用到应用文上下文，getPreferences方法获取Preferences实例，组件Header进行历史页面开发。
    * 参考接口：[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)
  
  * 设置模块
    * 本模块分为三个事件，分别为记录联网事件，记录灭屏事件，记录亮屏事件，进行锁屏事件、进行解锁屏幕事件，每一个事件都可进行一直，仅本次和从不的单项选择，使用到应用文上下文吗，CommonEvent.publish发布公共事件，getPreferences方法获取Preferences实例进行功能页面开发。
    * 参考接口：[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)，[@ohos.commonEvent](reference/apis-basic-services-kit/js-apis-commonEvent.md),[@ohos.router](reference/apis-arkui/js-apis-router.md)，[@ohos.commonEvent](reference/apis-basic-services-kit/js-apis-commonEvent.md)
  
  * 关于模块
    * 该模块开发主要介绍了本示例的功能作用以及说明了什么情况下不能使用。

  - 设置中订阅事件模块
    - 本模块主要支持指定应用订阅自定义事件。subScribeInfo新增可选属性publisherBundleName,创建订阅对象时可指定PublisherBundlerName，事件发布时，获取订阅者信息，增加校验bundleName是否等于publisherBundlerName，相等则加入事件回调方，达成只接收指定发布方发布的事件的效果。
    - 参考接口：[@ohos.commonEventManager](reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md)，[@ohos.hilog](reference/apis-performance-analysis-kit/js-apis-hilog.md)，[@ohos.app.form.formInfo](reference/apis-form-kit/js-apis-app-form-formInfo.md)，[@ohos.app.form.formBindingData](reference/apis-form-kit/js-apis-app-form-formBindingData.md)，[@ohos.app.form.FormExtensionAbility](reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomCommonEvent)

#### 自定义Emitter

##### 介绍

本示例使用[Emitter](reference/apis-basic-services-kit/js-apis-emitter.md)实现事件的订阅和发布，使用[自定义弹窗](reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md)设置广告信息。

##### 使用

1. 进入首页后弹出广告弹窗，点击即可关闭。
2. 点击商品列表中的一个商品可以跳转到商品详情页。
3. 在商品详情页点击首页可以返回到商品列表页，点击购物车可以跳转到购物车页面，点击加入购物车可以在购物车页面添加一条商品信息，点击立即购买可以增加一次已购物数量显示在购物车页面。
4. 在购物车页面点击购物车列表内商品的减号图标，可以将此商品信息从购物车列表内删除，点击清空购买数量可以将已购物数量清空、显示为0。

##### 基本原理

+ 订阅事件通知在CustomEmitter中实现
  + 广告弹窗：使用Emitter的事件单次订阅emitter.once(eventId,call)，eventId为number类型，单次订阅CustomDialogController弹窗事件，弹窗触发后自动取消订阅。
  + 关闭广告弹窗：使用Emitter的事件单次订阅emitter.once(eventId,call)，eventId为string类型，单次订阅CustomDialogController弹窗事件，弹窗关闭后自动取消订阅。
  + 购物车添加商品：使用Emitter.on持续订阅商品添加事件，eventId为number类型，添加商品时更新购物车商品列表。
  + 购物车删除商品：使用Emitter.on持续订阅商品删除事件，eventId为string类型，删除商品时更新购物车商品列表。
  + 购物数量：使用Emitter.getListenerCount获取购买事件订阅者数量，进入购物车页面显示数量结果，清空时取消订阅，结果为0。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomEmitter)

#### 自定义通知

##### 介绍

本示例使用[@ohos.notificationManager](reference/apis-notification-kit/js-apis-notificationManager.md) 等接口，展示了如何初始化不同类型通知的通知内容以及通知的发布、取消及桌面角标的设置，通知类型包括基本类型、长文本类型、多行文本类型、图片类型、带按钮的通知、点击可跳转到应用的通知。

##### 使用

1.启动应用后，弹出是否允许发送通知的弹窗，点击允许后开始操作；

2.点击界面中对应的按钮发布不同类型的通知，下拉状态栏，在通知栏可以看到发布的通知；

3.打开提示音和震动效果开关后，再点击对应按钮发布不同类型的通知，在通知的同时会伴有提示音或震动效果；

4.点击消息列表Tab页，可以查看到刚才发送的消息，消息右边会显示数量，点击相应的消息可进行消息读取，取消相应通知；

5.回到仿桌面，可以看到角标数量，对应消息数量（使用前需安装并启动[仿桌面应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/Launcher)）；

6.点击取消所有通知，可以取消本应用发布的所有通知；

##### 基本原理

* 允许发送通知、发送通知、取消通知的功能接口封装在NotificationUtil
    * 允许发送通知：在进入Index.ets前
    通过notificationUtil.enableNotification()调用notification.requestEnableNotification()接口向用户请求发送通知；
    * 发送通知：通过publishNotification()封装发布通知的接口；
    * 取消通知：Index.ets 页面中通过点击事件调用cancelAllNotifications()取消所有的通知或者通过cancelNotificationById()取消指定id的通知；

* 获取应用所有消息通知、取消相关类型通知，角标管理接口封装在NotificationManagementUtil
    * 获取应用所有消息通知：在constructor()
    构造函数中调用@ohos.notificationManager中的getActiveNotifications接口获取所有通知及相应类型通知数量，通过封装getAllNotifications()
    对外提供接口获取当前消息及消息数量。
    * 取消相关类型通知：通过cancelNotificationType()封装取消相关通知类型的接口；
    * 角标管理接口：通过setBadgeNumber()封装设置应用角标数量的接口，通过getBadgeNumber()封装获取当前应用角标数量的接口。
    * 添加一条通知：通过addNotification()封装接口添加一条通知到消息管理器，当发送通知的时候进行调用。

* NotificationOperations向外提供接口，在页面中调用它们来实现功能
    * 发布通知：
    页面中通过点击事件调用NotificationOperations中封装的对应的方法，然后从NotificationContentUtil中获取对应的主体内容content，
    将content传递给NotificationRequestUtil得到完整的发布信息，最后调用NotificationUtil.publishNotification()发布内容；

* 播放提示音、马达震动的功能在NotificationUtil调用发布通知的接口处进行判断是否开启
    * 发布通知：
    通过publishNotification()封装发布通知的接口的同时，根据NotificationUtil类中对应变量的值判断是否开启了提示音或马达，若已开启，则执行对应代码段；
    * 控制提示音或马达的开关，
    通过调用NotificationUtil类两个方法对NotificationUtil类中对应变量进行更改，开启为true，关闭为false；

* 自动化测试，对应用接口或系统接口进行单元测试，并且对基于UI操作进行UI自动化测试
    * 模拟点击：在Index.test.ets的beforeAll中调用startAbility()拉起应用并进入首页，
    然后通过Driver的assertComponentExist、findComponent和findWindow等获取到对应组件的位置，
    最后通过click()模拟出人工点击对应组件的效果；
    * 模拟各种操作流程：在Index.test.ets
    的每个it里面，按一定逻辑顺序排好点击组件的顺序，从而模拟出人为操作的过程，最终，所有的it组成了整一个应用的自动化测试。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotification)

#### 自定义通知角标

##### 介绍

本示例主要展示了设定应用的桌面图标角标的功能，使用[@ohos.notificationManager](reference/apis-notification-kit/js-apis-notificationManager.md) 接口，进行桌面角标的设置，通知的发送，获取等。

##### 使用

1. 在使用本应用时，需安装并启动[仿桌面应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/Launcher)；
2. 在主界面，可以看到当前应用的所有消息通知；
3. 点击右下角Tab页签进入通知发送页面，点击对应的通知即可发送相应类型的通知，点击几次发送几条；
4. 点击左下角Tab页签进入消息列表，可以查看刚才发送的消息，消息右边会显示消息数量，点击相应的消息可进行消息读取，取消相应通知；
5. 回到仿桌面，可以看到角标数量，对应消息数量。

##### 基本原理

* 允许发送通知，发送通知的功能接口封装在NotificationUtil
    * 允许发送通知：
      前通过notificationUtil.enableNotification()调用notification.requestEnableNotification()接口向用户请求发送通知；
    * 发送通知：通过publishNotification()封装发布通知的接口；

* 获取应用所有消息通知、取消相关类型通知，角标管理接口封装在NotificationManagementUtil
    * 获取应用所有消息通知：在constructor()构造函数中调用@ohos.notificationManager中的getActiveNotifications接口获取所有通知及相应类型通知数量，通过封装getAllNotifications()对外提供接口获取当前消息及消息数量。
    * 取消相关类型通知：通过cancelNotificationType()封装取消相关通知类型的接口；
    * 角标管理接口：通过setBadgeNumber()封装设置应用角标数量的接口，通过getBadgeNumber()封装获取当前应用角标数量的接口。
    * 添加一条通知：通过addNotification()封装接口添加一条通知到消息管理器，当发送通知的时候进行调用。

* NotificationOperations向外提供接口，在页面中调用它们来实现功能
    * 发布通知：
      页面中进入发送通知Tab页签，通过点击事件调用NotificationOperations中封装的对应的方法，然后从NotificationContentUtil中获取对应的主体内容content，将
      content传递给NotificationRequestUtil得到完整的发布信息，最后调用NotificationUtil.publishNotification()发布内容，并调用NotificationManagementUtil的addNotification()添加一条消息；

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationBadge)

#### 自定义通知推送

##### 介绍

本示例主要展示了通知过滤回调管理的功能，使用[@ohos.notificationManager](reference/apis-notification-kit/js-apis-notificationManager.md) 接口，进行通知监听回调，决定应用通知是否发送。

##### 使用

1. 在使用本应用时，需安装[自定义通知角标应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Notification/CustomNotificationBadge)；
2. 在主界面，进行通知过滤的开启及关闭；
3. 开启通知过滤后，可以选择允许通知的类型，去勾选后，相应类型的通知将不会发送出现通知栏；
4. 打开自定义通知角标应用应用，进行通知的发送，查看是否发送成功；
5. 发送通知的应用必须为普通应用才能进行通知过滤，系统应用默认所有通知都能发送。

##### 基本原理

* 允许通知过滤、指定通知类型过滤的功能接口封装在NotificationFilterUtil
    * 允许通知过滤：
      页面中通过Toggle状态改变事件调用setNotificationEnableFilter()接口开启通知监听并设置通知过滤回调管理；
    * 指定类型通知过滤：
      页面中，开启通知过滤后，勾选或取消勾选指定通知类型调用接口setContentTypeEnable()接口设置通知类型是否允许发送；

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Notification/CustomNotificationPush)

### 资源

#### 资源管理器

##### 介绍

本工程使用[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md) 接口中的AbilityContext类，获取资源管理器resourceManager，使用[@ohos.resourceManager.d.ts](reference/apis-localization-kit/js-apis-resource-manager.md) 中的接口，展示了格式化字符串查询、基于指定屏幕分辨率查询媒体资源、获取系统资源管理对象等基础功能，以及展示了资源静态overlay以及运行时overlay的特性功能。

##### 使用

此界面为主页面，其中展示了资源管理API各类接口的调用以及特性Overlay场景功能。其作用有：

1、点击资源API调用示例按钮，可跳转到资源API示例页面

2、点击Overlay使用示例，可以跳转到Overlay的使用示例界面。

##### 基本原理

此页面展示静态overlay功能，功能使用如下：

1、静态overlay是默认使能的，当前显示的是静态overlay中的字符串和图标。

2、点击Disable可以触发去使能，重启应用可以恢复显示应用的字符串和图标。

3、点击enable可以触发使能，重启应用可以再次显示overlay中的字符串和图标。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Resource/ResourceManager)

### 安全

#### 应用账号管理

##### 介绍

本示例选择应用进行注册/登录，并设置账号相关信息，简要说明应用账号管理相关功能。

##### 使用

1.首页面选择想要进入的应用，首次进入该应用需要进行注册，如已注册账号则直接登录。

2.注册页面可设置账号名、邮箱、个性签名、密码（带*号为必填信息），注册完成后返回登录页面使用注册的账号进行登录。

3.登录后进入账号详情界面，点击**修改信息**按钮可跳转至账号信息修改页面重新设置账号信息。

4.点击**切换应用**按钮则退出该账号并返回首页面。重新选择想要进入的应用。

5.点击**删除账号**按钮则会删除该账号所有相关信息。

##### 基本原理

* 本示例分为音乐，视频，地图三个模块
  * 音乐模块
    * 使用Navigation,Button，Text,TextInput组件开发注册，登录，修改信息和切换应用页面， createAppAccountManager方法创建应用账号管理器对象
    * 接口参考：[@ohos.account.appAccount](reference/apis-basic-services-kit/js-apis-appAccount.md#appaccountcreateappaccountmanager)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)，[@ohos.router](reference/apis-arkui/js-apis-system-router.md)

  * 视频模块
    * 使用Navigation,Button，Text,TextInput组件开发注册，登录，修改信息和切换应用页面，createAppAccountManager方法创建应用账号管理器对象
    * 接口参考：[@ohos.account.appAccount](reference/apis-basic-services-kit/js-apis-appAccount.md#appaccountcreateappaccountmanager)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)，[@ohos.router](reference/apis-arkui/js-apis-system-router.md)

  * 地图模块
    * 使用Navigation,Button，Text,TextInput组件开发注册，登录，修改信息和切换应用页面，createAppAccountManager方法创建应用账号管理器对象
    * 接口参考：[@ohos.account.appAccount](reference/apis-basic-services-kit/js-apis-appAccount.md#appaccountcreateappaccountmanager)，[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)，[@ohos.router](reference/apis-arkui/js-apis-system-router.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/AppAccountManager)

#### 证书算法库框架

##### 介绍

本示例使用了[@ohos.security.cert](reference/apis-device-certificate-kit/js-apis-cert.md)相关接口实现了对签名数据进行校验的功能。

实现场景如下：

1）使用**正确**的原始数据和签名数据进行签名校验场景：模拟服务端通过客户端证书获取公钥，利用公钥对签名数据进行校验，验证客户端身份和原始数据完整性。

2）使用**错误**的原始数据或签名数据进行签名校验场景：模拟攻击者修改原始数据或签名数据，服务端在利用公钥进行签名校验时，攻击者身份不可信或原始数据不完整，验证失败。

##### 使用

1、点击**数据展示**按钮，页面文本框中分别显示正确的证书、原始和签名数据内容。

2、点击**签名校验**按钮，页面弹出弹窗，提示**校验通过**。

3、点击**修改原始数据**按钮，页面显示修改后的原始数据和正确的证书、签名数据；点击签名校验按钮，页面弹出弹窗，提示**校验失败**。

4、点击**修改签名数据**按钮，页面显示修改后的签名数据和正确的证书、原始数据；点击签名校验按钮，页面弹出弹窗，提示**校验失败**。

5、点击**数据展示**按钮，页面恢复正确证书、原始和签名数据的展示；点击**签名校验**按钮，页面弹出弹窗，提示**校验通过**。

##### 基本原理

* 使用证书公钥实现签名校验的功能接口Verify封装在CertFrameworkModel中
    * 获取证书公钥：首先调用[cert.createX509Cert](reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509cert)接口生成证书对象certObject，使用certObject对象的[getPublicKey](reference/apis-device-certificate-kit/js-apis-cert.md#getpublickey)能力获取公钥pubKey；然后调用[cryptoFramework.createAsyKeyGenerator](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateasykeygenerator)接口创建密钥生成器keyGenerator，使用keyGenerator的[convertKey](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey)能力将公钥pubKey转换为正确的格式。
    * 使用公钥校验签名：首先调用[cryptoFramework.createVerify](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreateverify)接口创建验签对象verifier，使用公钥pubKey对验签对象verifier进行初始化[verifier.init](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#init-6)；然后使用验签对象verifier的[verify](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify)能力对签名进行校验。

##### 约束与限制

##### 介绍

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/CertificateFramework)

#### 加解密

##### 介绍

本示例使用[cipher](reference/apis-crypto-architecture-kit/js-apis-system-cipher.md)相关接口实现了字符串加解密算法，包括RSA加密算法与AES加密算法。

##### 使用

1.点击主页面的**加密**按钮，在加密界面中点击**Encryption Algorithm**下拉选择加密算法，在输入框中输入待加密的内容，点击**加密**
按钮，下方文本框中显示加密后内容。

2.点击**重置**按钮，清除文本框中内容。

3.点击主页面的**解密**按钮，在解密界面中点击**Decrypt Algorithm**下拉选择解密算法，在输入框中输入待解密的内容，点击**解密**
按钮，下方文本框中显示解密后内容。

4.点击**重置**按钮，清除文本框中内容。

##### 基本原理

* 本示例分成加密与解密两个模块
  * 加密模块
    * 使用到rsaEncrypt(RSA算法加密)与aesEncrypt(AES算法加密)两种加密方法进行加密操作。
    * 接口参考：[@system.cipher](reference/apis-crypto-architecture-kit/js-apis-system-cipher.md)，[@ohos.prompt](reference/apis-arkui/js-apis-promptAction.md)，[@system.router](reference/apis-arkui/js-apis-system-router.md)

  * 解密模块
    * 使用到rsaDecrypt(RSA算法解密)与aesDecrypt(AES算法解密)两种解密方法进行解密操作。
    * 接口参考：[@system.cipher](reference/apis-crypto-architecture-kit/js-apis-system-cipher.md)，[@ohos.prompt](reference/apis-arkui/js-apis-promptAction.md)，[@system.router](reference/apis-arkui/js-apis-system-router.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Cipher)

#### 通用密钥库系统（cryptoFramework）

##### 介绍

本示例使用[@ohos.security.cryptoFramework](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md) 相关接口实现了对文本文件的加解密、签名验签操作。

实现场景如下：

1）软件需要加密存储本地文本文件，需要调用加解密算法库框架选择密钥文本文件，对本地文本文件进行加密，其中密钥文本文件可由加解密算法库生成。

2）软件需要解密存储本地文本文件，需要调用加解密算法库框架选择密钥文本文件，对本地文本文件进行解密，其中密钥文本文件可由加解密算法库生成。

3）软件需要对存储本地文本文件签名，调用加解密算法库框架选择密钥文本文件，对本地文本文件进行完整性签名，其中密钥文本文件可由加解密算法库生成。

4）软件需要验证存储本地文本文件的签名完整性，需要调用加解密算法库框架选择密钥文本文件与签名文件，对文件进行验签，其中密钥文本文件可由加解密算法库生成。

##### 使用

1.点击主页面tab栏的**加密**，在加密界面点击**打开文件**，通过文件选择器选择文本文件，选择完毕自动返回加密界面，
其内容显示在**文件内容**文本框中，
点击**选择密钥**，选择密钥文件，如果没有密钥文件，可以通过在加密界面点击**随机生成AES密钥**，生成并通过文件选择器保存密钥文件。
选择完文本文件和密钥文件后，点击**加密**按钮，完成加密，并通过文件选择器保存密文文件。
下方**加密内容**文本框中显示加密后的消息内容。

2.点击主页面tab栏的**解密**，在解密界面点击**打开文件**，通过文件选择器选择文本文件，选择完毕自动返回解密界面，
其内容显示在**文件内容**文本框中，
点击**选择密钥**，选择和**加密相同**的密钥文件。
选择完文本文件和密钥文件后，点击**解密**按钮，完成解密，并通过文件选择器保存明文文件。
下方**解密内容**文本框中显示解密后的消息内容。

3.点击主页面tab栏的**签名**，在签名界面点击**打开文件**，通过文件选择器选择文本文件，选择完毕自动返回签名界面，
其内容显示在**文件内容**文本框中，
点击**选择密钥**，选择密钥文件，如果没有密钥文件，可以通过在签名界面点击**随机生成RSA密钥**，生成并通过文件选择器保存密钥文件，注意RSA密钥生成耗时较长。
选择完文本文件和密钥文件后，点击**签名**按钮，完成完整性签名，并通过文件选择器保存签名文件。

4.点击主页面tab栏的**验签**，在验签界面点击**打开文件**，通过文件选择器选择文本文件，选择完毕自动返回验签界面，
其内容显示在**文件内容**文本框中，
点击**选择密钥**，选择和签名一致的密钥文件。点击**选择签名文件**，通过文件选择器选择签名时保存的签名文件，
选择完文本文件、密钥文件和签名文件后，点击**验签**按钮，完成验签。

##### 基本原理

* 进行对文本文件进行加解密、签名验签的功能接口封装在CryptoOperation中

* 对文本文件加密：
  文件中依次点击打开文件、选择密钥，通过filePicker选择明文文本文件和密钥文件，点击加密按钮，调用加密函数实现对文本内容进行加密，并将密文文件通过filePicker保存。
  需要生成密钥文本文件时，可以点击随机生成AES密钥，通过调用[cryptoFramework.symKeyGenerator](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#symkeygenerator)
  生成用于加密的AES密钥，并通过filePicker保存密钥文本文件。
  对消息加密的过程中采用[cryptoFramework.Cipher](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cipher)
  完成加密操作。
* 对文本文件解密：
  文件中依次点击打开文件、选择密钥，通过filePicker选择密文文本文件和密钥文件，点击解密按钮，调用解密函数实现对文本内容进行解密，并将明文文件通过filePicker保存。
  对消息解密的过程中采用[cryptoFramework.Cipher](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cipher)
  完成解密操作。
* 对文本文件签名：
  文件中依次点击打开文件、选择密钥，通过filePicker选择待签名文本文件和密钥文件，点击签名按钮，调用签名函数实现对文本内容进行加密，并将签名文件通过filePicker保存。
  需要生成密钥文本文件时，可以点击随机生成RSA密钥，通过调用[cryptoFramework.asyKeyGenerator](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#asykeygenerator)
  生成用于签名的RSA密钥，并通过filePicker保存密钥文本文件。
  对消息签名的过程中采用[cryptoFramework.Sign](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#sign)
  完成加密操作。
* 对文本文件验签：
  文件中依次点击打开文件、选择密钥、选择签名文件，通过filePicker选择密文文本文件、密钥文件和签名文件，点击验签按钮，调用验签函数实现对文本内容进行验签，并显示验签结果。
  对消息验签的过程中采用[cryptoFramework.Verify](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#verify)
  完成验签操作。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CryptoFramework)

#### 通用密钥库系统（huks）

##### 介绍

本示例使用[@ohos.security.huks](reference/apis-universal-keystore-kit/js-apis-huks.md)相关接口实现了对任意输入内容进行加密和解密的功能。

实现场景如下：

1）使用新密钥进行消息加解密传输：使用HUKS的生成密钥接口在本地生成一个新密钥，模拟设备对发送的消息进行加密和对接收的消息进行解密场景。

2）使用旧密钥进行消息加解密传输：使用HUKS的导入密钥接口导入一个旧密钥，模拟在旧设备上对发送的消息进行加密，在新设备上对接收的消息进行解密的场景。

##### 使用

1.点击主页面的**新密钥**按钮，在新密钥界面的输入框中输入待发送的消息内容，点击**发送消息**
按钮，下方文本框中显示加密后的消息内容，然后点击**接收消息**按钮，下方文本框中显示解密后的消息内容。

2.点击主页面的**旧密钥**按钮，在旧密钥界面的输入框中输入待发送的消息内容，点击**发送消息**
按钮，下方文本框中显示加密后的消息内容，首先点击**导入密钥**按钮，弹窗提示导入密钥成功，然后点击**接收消息**按钮，下方文本框中显示解密后的消息内容。

3.点击主页面的**低安访问控制**按钮，在新密钥界面的输入框中输入待保存的密码内容，点击**保存密码**
按钮，下方文本框中显示加密后的密码内容，录入锁屏密码， 然后点击**读取密码**按钮，在输入PIN码（锁屏密码，需要预先录入）之后，下方文本框中显示解密后的消息内容。

##### 基本原理

* 使用新密钥、旧密钥与低安访问控制进行消息的加密和解密的功能接口封装在HuksModel中
    * 使用新密钥加密：在NewKey.ets文件中通过HuksModel.encryptData方式调用加密函数实现对发送的消息内容进行加密，设置好生成密钥和解密密钥的密钥属性信息，加密前会先调用生成密钥接口
      [huks.generateKeyItem](reference/apis-universal-keystore-kit/js-apis-huks.md#huksgeneratekeyitem9-1)
      生成用于加密的AES密钥，对消息加密的过程中采用三段式接口[huks.initSession,huks.updateSession,huks.finishSession](reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9-1)
      完成加密操作。
    * 使用新密钥解密：NewKey.ets文件中通过HuksModel.decryptData方式调用解密函数实现对发送消息的解密，设置好解密密钥的密钥属性信息，使用加密时的密钥对消息进行解密，仍然是采用三段式接口完成解密操作，解密动作完成后调用删除密钥接口
      [huks.deleteKeyItem](reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9-1)清除本地保存的密钥。
    * 使用旧密钥加密：在OldKey.ets文件中通过HuksModel.encryptDataUserOldKey方式调用加密函数对发送的消息内容进行加密，设置好加密密钥的密钥属性信息，采用三段式接口使用本地已保存的旧密钥完成加密操作。
    * 使用旧密钥解密：在OldKey.ets文件中通过HuksModel.decryptDataUserOldKey方式调用解密函数对发送的消息内容进行解密，首先模拟在新设备上导入旧设备的加密密钥，同样采用三段式接口完成解密操作，解密完成后删除密钥。
    * 使用低安访问控制管理密码：在MinAccessControl.ets文件中通过 huksModel.encryptDataUseSm2 方式生成SM2密钥并调用加密函数对发送的消息内容进行加密，设置好加密密钥的密钥属性信息，采用两段式接口使用本地已保存的旧密钥完成加密操作。读取密码时（需先设定系统锁屏密码）调用IAM的PIN码（锁屏密码）接口进行验证。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/Huks)

#### 支付

##### 介绍

本示例主要展示了加解密算法库框架的相关功能，使用[@ohos.security.cryptoFramework](reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md) 接口，利用RSA非对称加密、ECC数字签名模拟选购支付功能。

##### 使用

1. 在选购首页，点击任意商品进入对支付主面；
2. 在支付主面，点击立即支付按钮，弹出密码输入框；
3. 输入密码满6位后得到支付结果，支付成功会进入支付成功界面，3s后自动回到选购首页；

##### 基本原理

1. 选购页面通过商家云获取商品信息，选定商品通过商家云生成订单。
2. 商家云通过RSA非对称加密，使用支付云公钥，将商品信息传输给支付云SDK。
3. 支付云通过支付云私钥解密获得消息后生成订单明文orderString返回商家云。
4. 商家云通过ECC进行数字签名，添加到明文orderString后，形成完整的orderString返回给选购端。
5. 支付SDK通过RSA非对称加密，使用支付SDK公钥，将支付账号密码信息传输给支付云SDK，并携带完整的orderString。
6. 支付云通过支付SDK私钥解密账号密码信息，并通过商家云公钥进行验签。

- 商家云可用接口封装在cloud模块MerchantServer，提供商品获取，生成订单功能
- 支付云可用接口封装在cloud模块PayServer，提供生成支付订单，支付转账功能
- 支付SDK为单独feature，需要支付时拉起此hap,提供输入密码进行支付功能。逻辑位于PaySDK模块index

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/PaySecurely)

#### 证书管理

##### 介绍

本示例使用了[@ohos.security.certManager](reference/apis-device-certificate-kit/js-apis-certManager.md)相关接口实现了对签名数据进行校验的功能。

##### 使用

1. 点击**安装**按钮，页面弹出弹窗，提示**安装成功**。
2. 点击**数据展示**按钮，页面文本框中分别显示正确的证书、原始数据内容。
3. 点击**数据展示**按钮，页面文本框中分别显示正确的证书、原始数据内容。
4. 点击**修改原始数据**按钮，页面显示修改后的原始数据和正确的证书、签名数据；点击校验按钮，页面弹出弹窗，提示**校验失败**。
5. 点击**修改签名数据**按钮，页面显示修改后的签名数据和正确的证书、原始数据；点击校验按钮，页面弹出弹窗，提示**校验失败**。
6. 点击**校验**按钮，页面弹出弹窗，提示**校验通过**。

##### 基本原理

* 签名校验的功能接口Verify封装在Model中
    * 安装私有凭据：调用[certificateManager.installPrivateCertificate](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerinstallprivatecertificate)接口安装证书，并获取返回结果cmResult。
    * 使用凭据进行签名、验签的初始化操作：调用[certificateManager.init](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerinit)接口进行初始化，并获取返回结果signHandle。
    * 填充源数据：调用[certificateManager.update](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerupdate)接口填充源数据。
    * 完成签名的操作：调用[certificateManager.finish](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerfinish)接口完成签名，并获取签名结果signResult。
    * 完成验签的操作：同上，再依次调用[certificateManager.init](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerinit)接口，[certificateManager.update](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerupdate)接口，[certificateManager.finish](reference/apis-device-certificate-kit/js-apis-certManager.md#certificatemanagerfinish-1)接口完成验签操作，最终获取验签结果verifyResult。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.5.3

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Security/CertManager)

#### DLPManager

##### 介绍

本示例主要展示了DLP文件管理相关的功能，使用[@ohos.dlpPermission](reference/apis-data-protection-kit/js-apis-dlppermission.md)、[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)、[@ohos.file.fileAccess](reference/apis-core-file-kit/js-apis-fileAccess-sys.md)、[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)、[@ohos.app.ability.Want](reference/apis-ability-kit/js-apis-app-ability-want.md)等接口，实现了生成和打开DLP文件、查看原始应用沙箱目录的原始文件打开列表、编辑保存文件、拉取文件夹、查看文件权限和监听DLP文件的功能。

##### 使用

1. 进入界面，显示原始应用沙箱目录获取原始文件打开列表。
2. 点击右上角的图标，可以设置沙箱保留信息。
3. 点击右下角的加号图标，可以跳转进入文件夹。
4. 点击某个文件，可以显示其文件内容。
5. 在文件显示页面，可以点击下面的编辑图标对文件内容进行编辑，编辑后点击保存图标进行保存；点击更多可以文件另存为，查看权限。

##### 基本原理

* 获取DLP文件和普通文件列表的功能：
    * 在Index页面中通过onPageShow()调用fs.listFile()、fs.stat()等方法能够查看应用沙箱路径下的原始文件列表，获取列表信息。
    * 通过context.startAbility(want)对DLP文件进行生成和打开，通过dlpPermission的接口查看DLP文件的权限。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.3.3

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/DLPManager)

### 任务管理

#### 长时任务

##### 介绍

本示例展示后台任务的长时任务。通过使用[@ohos.resourceschedule.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)实现后台播放音乐时避免进入挂起（Suspend）状态。

##### 使用

1.进入应用，点击播放，退出音乐界面推送至后台执行，当任务在后台开始执行时下拉菜单栏会有通知提醒；

2.再次进入应用，音乐播放进度条显示正常；

3.点击暂停播放，取消长时任务。

##### 基本原理

* 该示例使用startBackgroundRunning方法向系统申请长时任务，stopBackgroundRunning方法向系统申请取消长时任务，getWantAgent方法创建一个WantAgent，createAudioPlayer方法创建一个视频播放实例，createAVSession方法创建一个会话对象，fileIo.open方法打开文件等接口实现后台音乐播放。
* 接口参考：[@ohos.resourceschedule.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)，[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，[@ohos.multimedia.avsession](reference/apis-avsession-kit/arkts-apis-avsession.md)，[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md)，[@ohos.app.ability.wantAgent](reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ContinuousTask)

#### 小鸟避障游戏

##### 介绍

本示例使用[@ohos.app.ability.ServiceExtensionAbility](reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md)的ServiceExtension接口验证提供的Stage模型， [Canvas组件](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md)绘制小游戏，[@ohos.resourceschedule.usageStatistics](reference/apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)的queryBundleStatsInfos接口通过指定起始和结束时间查询应用使用时长统计信息来统计展示游戏在线时长，[@ohos.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)的requestSuspendDelay接口申请后台应用延迟挂起来验证短时任务API能否正常执行，[@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md)提供进程间通信能力，[@ohos.wantAgent](reference/apis-ability-kit/js-apis-wantAgent.md)验证系统能力。

##### 使用

1.点击**ConnectService**按钮，创建一个ServiceAbility并连接。

2.点击**DisconenctService**按钮，断开ServiceAbility。

3.点击**set game alarm**按钮，利用闹钟提醒代理API，验证游戏进程在收到闹铃通知时不被拉起。

4.点击**set game calendar**按钮，利用日历提醒代理API，验证游戏进程在收到日历通知时不被拉起。

5.点击**start game**按钮，选择对应的游戏难度1-5关玩游戏，游戏玩的过程中会利用后台信息统计API统计展示游戏在线时长。

6.点**home**按钮后，应用生命周期为onInactive, 在此回调中起一个短时任务，验证短时任务API能否正常执行。

##### 基本原理

* 该示例使用ServiceExtension接口验证提供的Stage模型，Canvas组件绘制小游戏，queryBundleStatsInfos接口通过指定起始和结束时间查询应用使用时长统计信息来统计展示游戏在线时长，requestSuspendDelay接口申请后台应用延迟挂起来验证短时任务API能否正常执行，rpc接口提供进程间通信能力，wantAgent接口验证系统能力。

* 接口参考[@ohos.resourceschedule.usageStatistics](reference/apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md)，[@ohos.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)，[@ohos.wantAgent](reference/apis-ability-kit/js-apis-wantAgent.md)，[@ohos.app.ability.ServiceExtensionAbility](reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md)，[@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/TaskManagement/Flybird)

#### 后台代理提醒

##### 介绍

本示例使用 [Tabs组件](reference/apis-arkui/arkui-ts/ts-container-tabs.md) 进行应用布局，使用 [Canvas组件](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md) 绘制时钟、倒计时，使用 [后台代理提醒](reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md) 发布后台代理提醒，使用 [振动](reference/apis-sensor-service-kit/js-apis-vibrator.md) 设置振动效果。保证应用被冻结或退出时，计时和弹出提醒的功能可以被后台系统服务代理。

##### 使用

1.点击**闹钟**、**日历**、**计时器**三个按钮切换不同视图。

2.1.点击闹钟页面右上角**+**按钮选择闹钟提醒时间添加闹钟提醒。

2.2.点击闹钟列表中可设置闹钟重复日期、延迟次数、延迟时长、是否震动、响铃音乐。

2.3.点击闹钟列表右侧开关按钮，可关闭或打开当前提醒。

2.4.右滑当前闹钟列表可选择删除当前提醒。

3.1.点击点击日历页面右上角**+**按钮选择日期提醒时间添加日期提醒。

3.2.点击日期列表中可设置日历提醒当天具体提醒时间、是否振动、是否响铃。

3.3.点击日历列表右侧开关按钮，可关闭或打开当前提醒。

3.4.右滑当前日历列表可选择删除当前提醒。

4.1.滑动计时器时间选项设置计时器时间。

4.2.点击**开始**按钮，开始当前计时器并设置倒计时后台提醒。

4.3.点击**重置**按钮，取消当前计时器提醒并重新设置计时器。

4.4.点击**暂停**按钮，暂停当前计时器提醒与倒计时；再次点击按钮恢复计时器提醒与计时器计时。

##### 基本原理

* 该示例分为闹钟，日历，计时器三个模块 
  * 闹钟模块
    * 使用Canvas组件绘制一个闹钟，SlotType方法获取对应的系统能力内容类型，addNotificationSlot方法添加一个NotificationSlot，ReminderRequestAlarm方法获取闹钟实例对象，用于设置提醒的时间，ReminderType方法设置提醒的类型，ActionButtonType方法设置按钮的类型，VibratorStopMode方法停止的振动。
    * 接口参考：[@ohos.notification](reference/apis-notification-kit/js-apis-notification.md)，[@ohos.reminderAgent](reference/apis-backgroundtasks-kit/js-apis-reminderAgent.md)，[@ohos.vibrator](reference/apis-sensor-service-kit/js-apis-vibrator.md)

  * 日历模块
    * 使用SlotType方法获取对应的系统能力内容类型，ReminderRequestCalendar方法获取日历实例对象，用于设置提醒的时间，ReminderType方法设置提醒的类型，ActionButtonType方法设置按钮的类型，VibratorStopMode方法停止的振动。
    * 接口参考：[@ohos.notification](reference/apis-notification-kit/js-apis-notification.md)，[@ohos.reminderAgent](reference/apis-backgroundtasks-kit/js-apis-reminderAgent.md)，[@ohos.vibrator](reference/apis-sensor-service-kit/js-apis-vibrator.md)

  * 计时器模块
    * 使用SlotType方法获取对应的系统能力内容类型，addNotificationSlot方法添加一个NotificationSlot，ReminderRequestTimer方法获取倒计时实例对象，用于设置提醒的时间，ReminderType方法设置提醒的类型，ActionButtonType方法设置按钮的类型，VibratorStopMode方法停止的振动。
    * 接口参考：[@ohos.notification](reference/apis-notification-kit/js-apis-notification.md)，[@ohos.reminderAgent](reference/apis-backgroundtasks-kit/js-apis-reminderAgent.md)，[@ohos.vibrator](reference/apis-sensor-service-kit/js-apis-vibrator.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ReminderAgentManager)

#### 短时任务

##### 介绍

本示例主要展示后台任务中的短时任务。

通过[@ohos.resourceschedule.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md) ，[@ohos.app.ability.quickFixManager](reference/apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md) 等接口实现应用热更新的方式去展现短时任务机制。

##### 使用

1.安装本应用之前，先编译好未签名的应用包，然后在终端执行工程里的脚本b_sign_hap_release.bat去生成签名的应用包，再将此签名应用包进行安装即可；

2.进入应用，点击检查更新按钮，点击弹出框更新按钮会进行下载补丁包；

3.将应用退出到后台后关闭；

4.再次进入应用，页面版本信息由3.1.7.5更新为3.2.8.3；

##### 基本原理

* 该示例使用cancelSuspendDelay方法取消延迟挂起，applyQuickFix方法快速修复补丁，createHttp方法创建一个HTTP请求，openSync方法同步打开文件，writeSync方法同步将数据写入文件，closeSync方法同步关闭文件流等接口实现应用热更新的方式去展现短时任务机制。

* 接口参考：[@ohos.backgroundTaskManager](reference/apis-backgroundtasks-kit/js-apis-backgroundTaskManager.md)，[@ohos.app.ability.quickFixManager](reference/apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md)，[@ohos.net.http](reference/apis-network-kit/js-apis-http.md)，[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/TaskManagement/TransientTask)

#### 任务延时调度

##### 介绍

本示例使用[@ohos.WorkSchedulerExtensionAbility](reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) 、[@ohos.net.http](reference/apis-network-kit/js-apis-http.md) 、[@ohos.notification](reference/apis-notification-kit/js-apis-notification.md) 、[@ohos.bundle](reference/apis-ability-kit/js-apis-Bundle.md) 、[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md) 等接口，实现了设置后台任务、下载更新包 、保存更新包、发送通知 、安装更新包实现升级的功能。

##### 使用

1. 安装本应用之前，先编译好未签名的应用包，然后在终端执行工程里的脚本，目录为：WorkScheduler/signTool/b_sign_hap_release.bat；
2. 未连接wifi状态下进入应用；
3. 进入首页后连接wifi；
4. 后台判断版本号后会下载新的升级包，并在页面中给出弹窗询问是否安装，点击“确定”按钮；
5. 应用会安装已经下载的升级包，实现版本更新，安装后会回到设备桌面，此时点击应用图标，可以看到版本已经是新版本了。
6. 运行自动化测试用例时，必须使用命令行装包，不能使用ide自动装包，安装自动化测试包之前，先编译好未签名的测试包，
然后在终端执行工程里的脚本，目录为：WorkScheduler/signTool/a_sign_hap_release.bat；
7. 运行自动化测试应用时需要使用如下命令：
```
hdc shell aa test -b ohos.samples.workschedulerextensionability -m entry_test -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest -s timeout 150000
```

##### 基本原理

* 设置延时任务、下载更新包、保存更新包、发送通知、安装更新包的功能接口都封装在WorkSchedulerSystem中
  * 设置延时任务：在运行示例时会通过WorkSchedulerSystem.startUpdateSample()方法调用workScheduler.startWork()建立任务；
  * 下载更新包：当任务条件满足后，会通过WorkSchedulerSystem.getNewHap()方法调用http.createHttp().request()接口下载需要的文件；
  * 保存更新包：通过WorkSchedulerSystem.saveFile()来实现，受限调用fileio.openSync()创建文件，然后调用fileio.writeSync()将下载的内容写入指定文件内；
  * 发送通知：通过WorkSchedulerSystem.publishNotification()方法，调用Notification.publish()接口发送指定内容的信息；
  * 接收通知：通过WorkSchedulerSystem.handleNotification()方法调用Notification.subscribe()接口获取信息，根据信息内容决定是否提示用户升级；
  * 安装更新包：通过WorkSchedulerSystem.installBundle()方法实现，首先调用bundle.getBundleInstaller()获取Installer对象，然后调用bundleInstall.install()接口实现装包，完成升级。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/TaskManagement/WorkScheduler)

### 电话服务

#### 拨打电话

##### 介绍

本示例使用[call](reference/apis-telephony-kit/js-apis-call.md)相关接口实现了拨打电话并显示电话相关信息的功能。主要展示拨打电话功能，dial方法拨打电话，可设置通话参数，hasCall方法判断是否存在通话，getCallState方法获取当前通话状态，isEmergencyPhoneNumber方法判断是否是紧急电话号码，formatPhoneNumber方法格式化电话号码，formatPhoneNumberToE164方法将电话号码格式化为E.164表示形式。

##### 使用

1.输入电话号码后，点击**电话**按钮，进行拨打电话。

2.拨打电话后文本框会显示拨打是否成功，是否存在通话，通话状态，是否紧急号码，格式化后的电话号码。

##### 基本原理

* 该示例展示拨打电话功能，dial方法拨打电话，可设置通话参数，hasCall方法判断是否存在通话，getCallState方法获取当前通话状态，isEmergencyPhoneNumber方法判断是否是紧急电话号码，formatPhoneNumber方法格式化电话号码，formatPhoneNumberToE164方法将电话号码格式化为E.164表示形式。
* 接口参考：[@ohos.telephony.call](reference/apis-telephony-kit/js-apis-call.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Telephony/Call)

#### 联系人

##### 介绍

本示例使用[@ohos.contact](reference/apis-contacts-kit/js-apis-contact.md) 接口，实现了对联系人的增删查改功能。

##### 使用

1.点击 **+** 按钮，跳转添加联系人界面，输入联系人信息，点击 **√**，确认添加联系人，并返回首页；
2.点击联系人列表跳转页面查看详细信息，并且可以编辑或删除联系人信息；
3.在搜索栏输入号码或邮箱可查询对应的联系人。

##### 基本原理

* 本示例的主要逻辑功能和源码在下列相关类中：
  * 查询所有联系人：调用contact.queryContacts()查询所有的联系人；
  * 新建联系人：检验数据格式后通过contact.addContact()创建新的联系人；
  * 搜索联系人：调用contact.queryContactsByPhoneNumber()通过电话号码查询联系人或者调用contact.queryContactsByEmail()通过邮箱查询联系人；
  * 删除联系人：调用contact.deleteContact()删除指定的联系人；
  * 修改联系人：页面调用contact.updateContact()。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Contact)

#### 短信服务

##### 介绍

本示例使用[@ohos.telephony.sms](reference/apis-telephony-kit/js-apis-sms.md) 接口展示了电话服务中发送短信的功能。

##### 使用

1. 首页点击**创建联系人**，弹框输入联系人姓名和电话，点击确定按钮后，联系人列表中添加该联系人;
2. 点击**管理**，该按钮变成**取消**，联系人列表出现删除x按钮，点击x按钮可删除联系人，点击**取消**，按钮变成**管理**;
3. 联系人列表中每个联系人右侧有**发送短信**图标按钮，点击该图标按钮跳转到发送短信页面;
4. 发送短信页面，输入短信点击向上箭头的**发送**按钮，可以发送短信;
5. 需授予短信发送权限且插入SIM卡才可成功发送短信，有预置短信内容，每次退出应用数据会清空，未添加存储功能，发送短信为默认卡发送。

##### 基本原理

+ 发送短信功能在SmsModel中:
    + 发送短信：发送短信首先需要使用createMessage方法创建短信实例，然后获取基本参数，getDefaultSmsSlotId可以获取发短信默认卡槽id，getSmscAddr获取短信发送地址，然后调用sms.sendMessage方法发送短信。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Telephony/Message)

#### 蜂窝数据

##### 介绍

本示例使用 [SystemCapability.Telephony.CellularData系统能力](reference/apis-telephony-kit/js-apis-telephony-data.md) 获取SIM卡信息及网络信息。使用 [@Builder](ui/state-management/arkts-builder.md) 在一个自定义组件内快速生成多个布局内容。通过获取SIM卡相关信息，展示打开本应用时网络信息。

##### 使用

1.默认移动数据的SIM卡背景色显示为蓝色。
2.若已经开启移动数据，则显示开启，否则显示为关闭。
3.若已经开启漫游服务，则显示开启，否则显示为关闭。
4.显示打开本应用时数据流类型及连接状态。

##### 基本原理

* 该示例使用蜂窝数据接口，getDefaultCellularDataSlotId方法获取默认移动数据的SIM卡，isCellularDataEnabled方法检查蜂窝数据业务是否启用，isCellularDataRoamingEnabled方法检查蜂窝数据业务是否启用漫游，getCellularDataFlowType方法获取蜂窝数据业务的上下行状态，getCellularDataState方法获取分组交换域（PS域）的连接状态等方法获取SIM卡相关信息，展示打开本应用时网络信息。
* 接口参考：[@ohos.telephony.data](reference/apis-telephony-kit/js-apis-telephony-data.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/MobileNetwork)

#### 事件订阅

##### 介绍

本示例通过[@ohos.telephony.radio](reference/apis-telephony-kit/js-apis-radio.md)，[@ohos.telephony.call](reference/apis-telephony-kit/js-apis-call.md)，[@ohos.telephony.data](reference/apis-telephony-kit/js-apis-telephony-data.md)，[@ohos.telephony.observer](reference/apis-telephony-kit/js-apis-observer.md)订阅网络状态、信号状态、通话状态、蜂窝数据、sim状态等事件，并获取状态变化返回的结果。

##### 使用

1.打开应用，开启所有订阅事件开关。
2.开关一次网络，触发网络状态变化。
3.拨打一次电话，触发通话状态变化。
4.插拔一次sim卡，触发sim卡状态变化和信号状态变化。
5.点击**查看详情**按钮，跳转详情页，显示监听到的数据结果。

##### 基本原理

* 该示例使用NetworkState方法获取网络注册状态，SignalInformation方法获取网络信号强度信息，RadioTechnology方法获取无线接入技术，CallState方法获取通话状态码，DataConnectState方法描述蜂窝数据链路连接状态，DataFlowType方法描述蜂窝数据流类型，SimStateData方法获取SIM卡类型和状态等方法提供订阅管理功能。
* 接口参考：[@ohos.telephony.radio](reference/apis-telephony-kit/js-apis-radio.md)，[@ohos.telephony.call](reference/apis-telephony-kit/js-apis-call.md)，[@ohos.telephony.data](reference/apis-telephony-kit/js-apis-telephony-data.md)，[@ohos.telephony.observer](reference/apis-telephony-kit/js-apis-observer.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/Observer)

#### 网络搜索

##### 介绍

本示例通过[@ohos.telephony.sim](reference/apis-telephony-kit/js-apis-sim.md) 、[@ohos.telephony.radio](reference/apis-telephony-kit/js-apis-radio.md) 等接口来展示电话服务中网络搜索功能，包含无线接入技术、网络状态、选网模式、ISO国家码、信号强度信息列表及Radio是否打开。

##### 使用

1.点击**SIM1 status**，弹出面板显示卡1的无线接入技术、注册网络信号强度信息列表、选网模式、ISO国家码，
再次点击面板消失， 点击**SIM2 status**显示同理；
2.**NetworkState**显示网络状态相关信息；
3.**IsRadioOn**显示Radio是否打开，true为打开，false为关闭。

##### 基本原理

* 网络搜索功能的实现主要封装在RadioStatus:
    * 获取网络状态以及服务商名称：打开应用触发RadioStatus中的getNetworkState()函数调用radio.getNetworkState()方法来获取网络状态，getRadioOn()函数调用radio.isRadioOn()方法判断指定卡槽位的Radio是否打开，RadioStatus中的getSimSpn()函数调用sim.getSimSpn(slotId)方法来获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。
    * 显示SIM卡信息：点击SIM status，弹出面板显示卡1的无线接入技术、注册网络信号强度信息列表、选网模式、ISO国家码。
    * 获取无线接入技术：RadioStatus中的getRadioTech(this.slotId)函数来调用radio.getRadioTech(slotId)方法来获取当前接入的CS域和PS域无线接入技术，
    * 获取指定SIM卡网络强度信息：getSignalInformation(this.slotId)函数来调用radio.getSignalInformation(slotId)方法来获取指定SIM卡槽对应的注册网络信号强度信息列表。
    * 获取选网模式：getNetworkSelectionMode(this.slotId)函数来调用radio.getNetworkSelectionMode(slotId)方法来获取当前选网模式。
    * 获取ISO国家码：getISOCountryCodeForNetwork(this.slotId)函数来调用radio.getISOCountryCodeForNetwork(slotId)方法来获取注册网络所在国家的ISO国家码。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/RadioTech)

#### SIM卡管理

##### 介绍

本示例使用[sim](reference/apis-telephony-kit/js-apis-sim.md)相关接口，展示了电话服务中SIM卡相关功能，包含SIM卡的服务提供商、ISO国家码、归属PLMN号信息，以及默认语音卡功能。

##### 使用

1.若SIM卡槽1插入SIM卡则SIM卡1区域显示为蓝色，否则默认为白色。
2.点击SIM卡1区域，弹窗显示SIM卡1的相关信息，再次点击面板消失。
3.默认拨号的SIM卡其按钮背景色为蓝色，目前只展示默认拨号的SIM卡，更改默认拨号卡功能暂不支持。
4.呼叫转移界面功能暂不支持，故点击按钮无实际操作。

##### 基本原理

* 该示例主要通过hasSimCard方法获取指定卡槽SIM卡是否插卡，getSimState方法获取指定卡槽的SIM卡状态，SimState方法判断SIM卡状态，isSimActive方法获取指定卡槽SIM卡是否激活，getSimSpn方法获取指定卡槽SIM卡的服务提供商名称，getISOCountryCodeForSim方法获取指定卡槽SIM卡的ISO国家码，getSimOperatorNumeric方法获取指定卡槽SIM卡的归属PLMN号，getDefaultVoiceSlotId方法获取默认语音业务的卡槽ID等开发电话服务的相关功能。
* 接口参考：[@ohos.telephony.sim](reference/apis-telephony-kit/js-apis-sim.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Telephony/SimManager)

### Web

#### 浏览器

##### 介绍

本示例使用[@ohos.systemparameter](reference/apis-basic-services-kit/js-apis-system-parameter-sys.md)接口和[Web组件](reference/apis-arkweb/arkts-basic-components-web.md)展示了一个浏览器的基本功能,展示网页，根据页面历史栈前进回退等。

##### 使用

1. 连接Wifi，启动应用，展示默认页面内容;
2. 点击默认页面的图标跳转到对应网页，或者在输入框输入网址，点击右侧跳转按钮跳转到对应网页;
3. 点击输入框左侧向右向左按钮进行页面的前进后退;
4. 点击主页图标回到主页，点击加号按钮新建一个页面。

##### 基本原理

+ Web展示与历史栈操作功能在Browser中:
  + 加载网页及刷新：使用WebController提供的loadUrl可以加载目标网址内容，使用refresh方法刷新页面;
  + 页面前进后退功能：页面在前进或者后退前使用accessForward/accessBackward查询是否有历史记录,然后调用forward/backward进行前进/后退操作。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/Browser)

#### JS注入与执行

##### 介绍

本示例基于H5游戏，通过arkui的[Button](reference/apis-arkui/arkui-ts/ts-basic-components-button.md)实现对游戏实现基本控制，展示[@ohos.web.webview](reference/apis-arkweb/arkts-apis-webview.md)的JS注入与执行能力，及native应用与H5的通信能力。

##### 使用

1. 设备连接热点，可访问互联网。
2. 打开应用，通过界面中按钮进行游戏控制。

##### 基本原理

* 本示例分成一个模块
  * 通过button实现对游戏的基本控制，WebviewController方法控制Web组件各种行为，使用webview注入JS与执行能力。
  * 接口参考：[@ohos.window](reference/apis-arkui/arkts-apis-window.md)，[@ohos.web.webview](reference/apis-arkweb/arkts-apis-webview.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Web/RunJsInWeb)

### 窗口管理

#### 窗口

##### 介绍

本实例使用[窗口管理](reference/apis-arkui/arkts-apis-window.md)，展示了在应用主窗口中创建和拉起子窗口，并对子窗口设置窗口相关属性，以及设置窗口规避区域、窗口沉浸式和小窗口等功能。

##### 使用

1. 启动应用,首页展示窗口沉浸式以及设置状态栏和任务栏属性,点击窗口视频跳转到播放页。
2. 点击视频屏幕可以拉起小窗口播放视频，小窗口可以拖拽，再次点击视频可以关闭小窗口。
3. 点击全屏播放并切换窗口方向按钮可以全屏播放视频并且改变窗口方向。
4. 点击视频屏幕拉起小窗口播放视频, 界面显示小窗口状态为“获焦状态”; 再次点击视频关闭小窗口, 界面显示小窗口状态为“失焦状态”
5. 点击视频屏幕拉起小窗口视频，再点击小窗口中的“拉起悬浮应用”按钮，成功拉起WindowRatio悬浮应用

##### 基本原理

* 本示例主要分为三个模块
  * 首页入口模块
    * 使用WindowStage实例化一个窗口，引入WindowManger方法设置一个主窗口与子窗口
    * 接口参考：[@ohos.window](reference/apis-arkui/arkts-apis-window.md)，[@ohos.events.emitter](reference/apis-basic-services-kit/js-apis-emitter.md)，[@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)，[@ohos.router](reference/apis-arkui/js-apis-router.md)

  * 窗口视频模块
    * 这里用到依赖window-components中WindowComponent方法来进行视频的播放

  * 全屏播放窗口并切换窗口方向模块
    * 通过EventPriority方法表示事件被发送的优先级，emitter.emit方法发送指定的事件进行全屏播放和切换窗口方向
    * 参考接口：[@ohos.events.emitter](reference/apis-basic-services-kit/js-apis-emitter.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowManage)

#### 悬浮窗

##### 介绍

本示例使用[@ohos.window](reference/apis-arkui/arkts-apis-window.md)，主要展示了在子窗口中以悬浮窗模式拉起悬浮应用，并对新的应用设置窗口缩放比例，窗口以设置的比例进行缩放，并在界面显示窗口当前的宽度和高度。

##### 使用

1. 安装[WindowRatio](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowRatio)工程hap包(即本示例)和[WindowManage](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowManage)工程hap包
2. 打开WindowManage应用sample，点击**窗口预览**进入视频播放页面，点击主窗口后拉起子窗口。
3. 点击**拉起悬浮应用**按钮后，将以悬浮窗模式拉起应用WindowRatio 。
4. 点击悬浮应用中的下拉框，选择窗口缩放比例，点击**确定**按钮，以新的宽度/比例计算得到窗口宽高，监听到窗口缩放比例发生变化，窗口以设置的比例改变大小，窗口监听到大小发生变化，在页面上显示当前窗口的宽度和高度。另外，窗口不具备记忆之前位置大小的能力，当前sample所调用的接口展示结果不居中，若要使得窗口居中，则需调用resize接口指定成想要的大小。

##### 基本原理

- 设置窗口缩放比例的功能接口封装在Index:  
  - 使用windows.setAspectRatio来设置窗口缩放比例;
- 设置以悬浮窗模式显示窗口和设置监听窗口大小接口的功能封装在MainAbility;
  - 使用windows.setWindowMode来设置窗口为悬浮窗模式;
  - 使用windows.on('windowSizeChange', (data))来监听窗口大小信息；

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowRatio)



## 语言基础类库

#### 多线程任务

##### 介绍

本示例通过[@ohos.taskpool](reference/apis-arkts/js-apis-taskpool.md) 和[@ohos.worker](reference/apis-arkts/js-apis-worker.md) 接口，展示了如何启动worker线程和taskpool线程。

##### 使用

1. 在主界面，可以点击**字符串排序**和**拷贝文件**按钮进入对应的界面；

2. 点击**字符串排序**按钮进入多线程界面：

   worker：

   1. 选择**Worker**页签，输入待排序的字符串，并以逗号分割。

   2. 点击**字符串排序**按钮，会将排序前的字符串发送给worker线程，在worker线程实现字符串排序，然后将排序后的字符串发送给主线程，主线程中显示排序后的字符串。

   3. 点击**清除**按钮，清除字符串。

   taskpool：

   1. 选择**TaskPool**页签，输入待排序的字符串，并以逗号分割。

   2. 选择**添加至任务组**按钮，将当前字符串的排序任务添加至任务组。

   3. 点击**立即执行**按钮，如之前有添加至任务组操作则任务组执行完成后将排序后的字符串显示出来；如没有上述操作则执行当前任务完成，将排序后的字符串显示出来。

   4. 点击**超时3s执行**按钮，任务延迟3s后执行，执行完成后将排序后的字符串显示出来。

   5. 点击**函数任务**按钮，直接调用执行操作，执行完成后将排序后的字符串显示出来。需要注意的是，通过**函数任务**创建的task任务不支持取消。

   6. 点击**取消任务**按钮，会取消最后一个未执行的task任务。需要注意的是，只有当任务数大于最大线程数且任务未开始执行时才可以取消成功。

   7. 点击**清除**按钮，清除字符串。

3. 点击**拷贝文件**按钮进入文件拷贝界面：

   选择需要拷贝的文件，然后点击**拷贝文件**按钮，文件拷贝成功，触发事件日志显示沙箱下文件个数以及显示部分拷贝成功的文件名。

##### 基本原理

* worker页签的实现在字符串排序页面调用:
  * 字符串排序：通过调用executeWorkerFunc()创建一个worker线程，把待排序字符串发送给worker线程，等worker线程排序完成后再把结果返回。
  * 清除：把字符串输入框和结果都清除。

* taskpool页签的实现在字符串排序页面调用:
  * 立即执行：如没有添加至任务组操作，通过调用executeImmediately()创建一个task任务，这个任务是立即执行字符串排序；如先进行了添加至任务组操作，则通过调用executeImmediately()将任务组执行完毕。
  * 超时3s执行：通过调用executeDelay()创建一个task任务，这个任务是延迟3s后执行字符串排序。
  * 函数任务：调用executeFunc()接口，不创建task任务，直接调用taskpool.execute()执行字符串排序。
  * 取消任务：调用cancelTask()接口，取消最后一个未执行的task任务。
  * 清除：把字符串输入框和结果都清除。
  * 添加至任务组：调用addTask()接口，将当前任务添加至任务组。

* 批量拷贝文件的功能封装在MyWorker:
  * 拷贝文件：调用MyWorker.WorkToCopyFiles()，在WorkToCopyFiles方法中向worker03线程发消息，并在worker03线程中批量拷贝，拷贝完成后将结果返回。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.2


#### 语言基础类库

##### 介绍

本示例集合语言基础类库的各个子模块，展示了各个模块的基础功能，包含：

- [@ohos.buffer (Buffer)](reference/apis-arkts/js-apis-buffer.md)
- [@ohos.convertxml (xml转换JavaScript)](reference/apis-arkts/js-apis-convertxml.md)
- [@ohos.process (获取进程相关的信息)](reference/apis-arkts/js-apis-process.md)
- [@ohos.taskpool (启动任务池)](reference/apis-arkts/js-apis-taskpool.md)
- [@ohos.uri (URI字符串解析)](reference/apis-arkts/js-apis-uri.md)
- [@ohos.url (URL字符串解析)](reference/apis-arkts/js-apis-url.md)
- [@ohos.util (util工具函数)](reference/apis-arkts/js-apis-util.md)
- [@ohos.util.ArrayList (线性容器ArrayList)](reference/apis-arkts/js-apis-arraylist.md)
- [@ohos.util.Deque (线性容器Deque)](reference/apis-arkts/js-apis-deque.md)
- [@ohos.util.HashMap (非线性容器HashMap)](reference/apis-arkts/js-apis-hashmap.md)
- [@ohos.util.HashSet (非线性容器HashSet)](reference/apis-arkts/js-apis-hashset.md)
- [@ohos.util.LightWeightMap (非线性容器LightWeightMap)](reference/apis-arkts/js-apis-lightweightmap.md)
- [@ohos.util.LightWeightSet (非线性容器LightWeightSet)](reference/apis-arkts/js-apis-lightweightset.md)
- [@ohos.util.LinkedList (线性容器LinkedList)](reference/apis-arkts/js-apis-linkedlist.md)
- [@ohos.util.List (线性容器List)](reference/apis-arkts/js-apis-list.md)
- [@ohos.util.PlainArray (非线性容器PlainArray)](reference/apis-arkts/js-apis-plainarray.md)
- [@ohos.util.Queue (线性容器Queue)](reference/apis-arkts/js-apis-queue.md)
- [@ohos.util.Stack (线性容器Stack)](reference/apis-arkts/js-apis-stack.md)
- [@ohos.util.TreeMap (非线性容器TreeMap)](reference/apis-arkts/js-apis-treemap.md)
- [@ohos.util.TreeSet (非线性容器TreeSet)](reference/apis-arkts/js-apis-treeset.md)
- [@ohos.util.Vector (线性容器Vector)](reference/apis-arkts/js-apis-vector.md)
- [@ohos.xml (xml解析与生成)](reference/apis-arkts/js-apis-xml.md)

##### 使用

1. 首页展示语言基础类库各个子模块菜单，点击进入对应的模块页面。
2. 各个子模块界面中点击功能按钮完成各个功能。
3. Util中有二级菜单，点击进入对应的二级界面，包含：
   * StringCode：字符串编解码，点击功能按钮完成各个功能。
   * RationnalNumber：有理数比较，点击功能按钮完成各个功能。
   * LRUCache：LRU缓冲区，点击功能按钮完成各个功能。
   * ScopeHelper：范围判断，点击功能按钮完成各个功能。
   * Base64Helper：Base64编解码，点击功能按钮完成各个功能。
   * TypeCheck：类型检查，点击功能按钮完成各个功能。
4. TaskPool界面中，点击Execute task执行任务，点击Cancel task取消任务。
5. ArrayList界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
6. Deque界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
7. HashMap界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
8. HashSet界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
9. LightWeightMap界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
10. LightWeightSet界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
11. LinkedList界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
12. List界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
13. PlainArray界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
14. Queue界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
15. Stack界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
16. TreeMap界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
17. TreeSet界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。
18. Vector界面中，点击+号添加数据后展示数据，点击删除按钮删除对应的一条数据。

##### 基本原理

1. 首页菜单展示：使用一个module，menuitems完成菜单组件的实现，传入要展示的菜单的strarray类型的资源和菜单点击对应的组件即可。使用Navigation和NavRouter组件实现菜单点击进入功能界面，使用LocalStorage实现应用内Ability内数据共享，点击菜单时标记selectedLabel，在entry中的Capabilities组件中，通过selectedLabel显示对应的功能组件。
2. Xml & ConvertXml：使用[xml](reference/apis-arkts/js-apis-xml.md) 和[convertxml](reference/apis-arkts/js-apis-convertxml.md) 实现xml的解析和生成以及xml转换为js对象，点击按钮实现对应的功能。
3. Process：使用[process](reference/apis-arkts/js-apis-process.md) 实现获取进程相关信息的功能，点击按钮实现对应的功能。
4. TaskPool：使用[taskpool](reference/apis-arkts/js-apis-taskpool.md) 实现创建后台任务（Task），并对所创建的任务进行如任务执行、任务取消的操作。
5. Url：使用[URL](reference/apis-arkts/js-apis-url.md) 对URL字符串的查找参数进行了增删改查的一系列操作，使得读者对URL的结构用途更加明了，点击按钮实现对应的功能。
6. Util，使用util中不同的功能函数实现以下功能：
   * StringCode：字符串编解码。
   * RationnalNumber：有理数比较。
   * LRUCache：LRU缓冲区。
   * ScopeHelper：范围判断。
   * Base64Helper：Base64编解码。
   * TypeCheck：类型检查。
7. ArrayList：展示线性容器ArrayList的数据类型的使用，包括添加、删除。
8. Deque：展示线性容器Deque的数据类型的使用，包括头部插入、头部删除、尾部删除。
9. HashMap：展示非线性容器HashMap的数据类型的使用，包括添加键值对、删除键值对。
10. HashSet：展示非线性容器HashSet的数据类型的使用，包括添加、删除。
11. LightWeightMap：展示非线性容器LightWeightMap的数据类型的使用，包括添加键值对、删除键值对。
12. LightWeightSet：展示非线性容器LightWeightSet的数据类型的使用，包括添加、删除。
13. LinkedList：展示线性容器LinkedList的数据类型的使用，包括尾部添加、头部删除、尾部删除。
14. List：展示线性容器List的数据类型的使用，包括添加、删除。
15. PlainArray：展示非线性容器PlainArray的数据类型的使用，包括添加、删除。
16. Queue：展示线性容器Queue的数据类型的使用，包括尾部添加、头部删除。
17. Stack：展示线性容器Stack的数据类型的使用，包括尾部添加、尾部删除。
18. TreeMap：展示非线性容器TreeMap的数据类型的使用，包括添加键值对、删除键值对。
19. TreeSet：展示非线性容器TreeSet的数据类型的使用，包括添加、删除。
20. Vector：展示线性容器Vector的数据类型的使用，包括添加、删除。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.3

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/LanguageBaseClassLibrary/LanguageBaseClassLibrary)

#### 压缩与解压

##### 介绍

本示例通过[@ohos.zlib](reference/apis-basic-services-kit/js-apis-zlib.md) 和[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md) 接口，实现添加文件、解压和压缩文件场景。

##### 使用

1. 点击屏幕右上角 **+** 按钮，弹出创建文件窗口；
2. 输入文件名称、文件内容，并点击 **确定** 按钮来创建文件；
3. 文件创建成功后，文件名称自动追加.txt后缀并在主页面列表会显示，同时文件的物理地址为/data/app/el2/100/base/ohos.samples.ziplib/haps/entry/files/，点击 **压缩** 按钮，提示“文件压缩成功”，并会在文件列表创建一个相同名称的.zip文件；
4. 点击压缩文件后的 **解压** 按钮，提示“文件解压成功”，并会再次在文件列表创建一个同名文件夹。

##### 基本原理

* 添加文件、解压和压缩文件的接口都在首页调用:
  * 添加文件：通过调用fileio.openSync()创建文件并调用fileio.writeSync()向文件中写入内容；
  * 压缩文件：通过调用zlib.zipFile()压缩文件；
  * 解压文件：通过zlib.unzipFile解压文件。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/LanguageBaseClassLibrary/ZipLib)



## Performance

### ArkRuntime

#### N-Body模拟程序

##### 介绍

本示例使用[@ohos.taskpool](reference/apis-arkts/js-apis-taskpool.md)和[@ohos.worker](reference/apis-arkts/js-apis-worker.md) 接口，使用ArkTS编程语言开发了业界编程语言基准测试项目[Benchmarks Game](https://gitcode.com/link?target=https%3A//salsa.debian.org/benchmarksgame-team/benchmarksgame)中的[N体问题模拟程序](https://gitcode.com/link?target=https%3A//benchmarksgame-team.pages.debian.net/benchmarksgame/description/nbody.html%23nbody)，实现类木星体轨道计算。

##### 使用

1.点击按钮Calculate By TaskPool，会从任务池创建一个任务，进行N-Body计算。

2.点击按钮Calculate By Worker，会创建一个Worker，进行N-Body计算。

##### 基本原理

- 使用TaskPool开启子线程运行，计算500万次时间推移天体运行轨道:
  - 通过调用computeNBodyByTaskPool()创建一个task任务，并向taskpool线程池派发子线程任务。
  - 等待子线程执行任务computeTask()，计算完成后再把结果返回主线程。
- 使用Worker开启子线程运行，计算5000万次时间推计算移天体运行轨道  
  - 通过调用computeNBodyByWorker()创建一个worker线程，把要计算的时间推移量发送给worker线程。
  - 等待worker线程调用computeTask()计算完成后再把结果返回主线程。
- computeTask()完成具体计算任务  
  - offsetMomentum() 建立孤立系统的动量守恒。
  - advance() 更新天体在按指定的时间变化后的位置信息。
  - energy() 判断系统计算前后机械能守恒。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Performance/ArkRuntime/NBody)

#### 性能示例

##### 介绍

本示例集成了条件渲染、动态加载以及HiDumper等场景来介绍如何提升应用性能。

##### 使用

1. 点击性能示例主页的**HiDumper**按钮，进入**HiDumper查看组件信息**场景页。

2. 点击HiDumper查看组件信息场景页的**查看应用组件树**进入场景页。

3. 点击HiDumper查看组件信息场景页的**查看if/else组件**按钮，在场景中点击**显隐切换**按钮，查看图片显示隐藏。

4. 点击HiDumper查看组件信息场景页的**查看visibility属性**按钮，在场景中依次点击**Visible**、**Hidden**、**Visible**、**None**，查看图片显示和隐藏。

##### 基本原理

* HiDumper场景模块

  * 查看应用组件树
    * 在页面上添加Grid，每个GridItem嵌套多个Stack，然后通过HiDumper抓取组件树信息。
    
  * 查看if/else组件
    * 在页面上添加**显隐切换**按钮，添加一张图片，点击按钮后通过HiDumper抓取组件树信息。
    
  * 查看visibility属性
    * 在页面上添加**Visible**、**Hidden**、**None**按钮，添加一张图片，点击按钮后通过HiDumper抓取组件树信息。

* Navigation常规加载页面模块

  * 在Navigation组件加载内容页时，使用`import`常规加载子页面。

* Navigation动态加载页面模块

  * 在Navigation组件加载内容页时，使用`await import`实现动态按需加载。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary)

#### 性能示例（renderGroup接口）

##### 介绍

本示例使用renderGroup接口实现了在单一页面上存在大量应用动效的组件时，使用renderGroup方法来解决卡顿问题，从而提升绘制能力。

##### 使用

1. 点击性能示例主页面的**RenderGroup**按钮，在场景界面中点击**正例场景示例**，进入正例场景页，可以点击renderGroup开关按钮，可以通过Profiler分析性能数据。  

2. 点击性能示例主页面的**RenderGroup**按钮，在场景界面中点击**反例场景示例**，进入反例场景页，可以点击renderGroup开关按钮，可以通过Profiler分析性能数据。

##### 基本原理

首次绘制组件时，若组件被标记为启用renderGroup状态，将对组件和其子组件进行离屏绘制，将绘制结果进行缓存。以后当需要重新绘制组件时，就会优先使用缓存而不必重新绘制了，从而降低绘制负载，优化渲染性能。
* 本示例分成正例场景与反例场景两个模块  
  
  * 正例场景  
    
    * 在ProfitScene的IconItem上添加动画，在IconView上使用到renderGroup接口(renderGroup(value: boolean): T)得到收益。
  
  * 反例场景  
    
    * 在IconView的Image上添加动画，在NonIconView上使用到renderGroup接口(renderGroup(value: boolean): T)得到负收益。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Performance/renderGroup)

## 工程

### 应用程序包

#### 多HAP

##### 介绍

本示例使用应用上下文Context接口 [@ohos.app.ability.common](reference/apis-ability-kit/js-apis-app-ability-common.md)和媒体服务接口[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，展示多HAP开发，简单介绍了多HAP的使用场景，应用包含了一个entry HAP和两个feature HAP，两个feature HAP分别提供了音频和视频播放组件，entry中使用了音频和视频播放组件。 三个模块需要安装三个hap包，最终会在设备上安装一个主entry的hap包。

##### 使用

1.第一步：选择entry模块，运行生成entry模块的hap包

2.第二步：安装audioFeature和videoFeature的hap包：打开cmd执行hdc install hdc-path。例如audioFeature模块中hdc-path为：绝对路径/audioFeature/build/default/outputs/default/entry/audioFeature-entry-default-signed.hap

3.第三步：安装完三个模块hap包后重新运行entry模块

4.第四步：安装应用，点击桌面MultiHap图标，进入应用：点击audio，进入audio播放页面，点击PlayAudio按钮，播放音频

5.第五步：点击video，进入video播放页面，可点击播放按钮播放视频

##### 基本原理

* 新创建两个Module作为将被跳转的hap，分别命名为videoFeature，audioFeature。
    * 配置每个hap的type：把entry文件夹下的module.json5中"type": "entry",videoFeature和audioFeature文件夹下的module.json5中"type": "feature"；
    * 使用Want跳转到其他的Ability：在entry模块的index.ets中通过common.UIAbilityContext()配置Want，作为多hap间信息传递的载体，用于应用组件间的信息传递；
    * want的配置：通过指定bundleName和abilityName可以唯一确定一个Ability。
    * 新hap的跳转：在entry模块index.ets首页中，在按钮.onclick()事件内，通过Want配置显式拉起一个新的指定的Ability。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Project/ApplicationHap/MultiHap)

### 资源配置

#### 应用主题切换

##### 介绍

本示例使用[@ohos.application.abilityManager](reference/apis-ability-kit/js-apis-application-abilityManager-sys.md) 能力，对Ability状态进行修改：其中AbilityManager.updateConfiguration()通过修改colorMode属性来更新配置系统主题颜色，展示多种应用主题切换。通过创建 base 同级资源文件夹 dark 和 light 完成深色浅色主题相关资源配置，实现深色浅色主题切换，在 ThemeConst 文件中配置自定义主题文件，通过控制变量实现多主题切换。

##### 使用

1. 点击头部切换主题按钮，选择想要切换的主题。
2. 系统深浅模式切换，应用主题自动跟随切换深浅模式。

##### 基本原理

* 三种模式资源统一放在ThemeConst内，在ThemeGet中定义全局变量theme控制主题模式(0:黑夜 1：白天 3：自定义主题)，步骤如下，
  * 1）整理主题资源：例如创建系统主题dark,light和自定义主题custom相关目录，并完善需要切换的资源比如icon、color等，系统主题下的相同资源，资源名称必须相同，比如dark下title.icon和light下title.icon
  * 2）定义资源池函数引用需要切换的主题资源，需要主题切换的资源通过getTheme(this.theme).资源名，实现组件对资源的动态引用和动态渲染。
  * 3）定义全局变量@storagelink('theme')
  * 4）定义事件修改变量theme的值，如果是系统主题（dark，light），调用AbilityManager.updateConfiguration()，通过修改colorMode属性来更新配置系统主题颜色（0：深夜 1：白天）
  * 5）自定义主题无须修改系统配置，只需修改theme全局变量的值，全局变量会通过@storagelink双向绑定机制，自动重新渲染绑定了theme值的组件

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ResourceAllocation/ApplicationThemeSwitch)

### 测试框架

##### 介绍

本示例展示[测试框架](https://gitcode.com/openharmony/testfwk_arkxtest)的使用示例，主要介绍了 jsunit单元测试框架和uitestUI测试框架的使用示例。

##### 使用

- 将jsunit或uitest目录下的项目工程整体导入到DevEco Studio开发工具中。
- 查看ohostest目录下的测试代码实现。
- 在DevEco Studio中执行测试用例代码查看执行效果，执行方式请[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-openharmony-test-framework-0000001263160453)。

##### 基本原理

1. jsunit单元测试框架示例内容
2. uitestUI测试框架示例内容

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Project/Test)

### 流水线预测试工具

##### 介绍

本示例主要展示了流水线预测试工具的使用示例，主要介绍了自动化构建及测试的实现原理。

##### 使用

1. 打开浏览器访问127.0.0.1:3000/swagger。

2. 在`/sn`下点击`Try it out`，再点击`Execute`，即可获得`/sn`接口返回的连接开发板的sn号。

3. 在`/hap-build/{PRId}`下点击`Try it out`，输入想要构建、测试的PRId，再点击`Execute`等待构建、测试任务结束可以看到接口返回构建和测试的结果，同时在PR下方的评论区也会有评论。

##### 基本原理

1. 执行hdc命令`hdc list targets`获取当前连接开发板sn号，[源码参考](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/Project/HapBuild/ci/src/app.controller.ts)。

2. 使用gitee官方web hook读取PR修改文件列表并将修改写入本地sample仓中，再根据修改文件路径找出对应的项目，使用[编译工具](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Project/HapBuild/compile-tool)中`compile-ohpm-ci.sh`脚本编译项目中的`entry`及`ohostest`包。

3. [InstallAndTestSpecial_ci.py](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/Project/HapBuild/test-tool/InstallAndTestSpecial_ci.py)脚本来安装entry包、ohosTest测试包以及拉起自动化测试用例。

##### 约束与限制

开发语言：TypeScript

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Project/HapBuild)

## 行业解决方案

### 游戏

#### 分布式五子棋

##### 介绍

本示例使用使用分布式设备管理能力[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)、分布式数据管理[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)等接口，结合[Canvas组件](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md) 实现棋盘、棋子的绘制，使用[分布式数据管理](reference/apis-arkdata/js-apis-distributed-data.md) 实现两台设备间数据的同步。

##### 使用

1.启动应用，同一个网络下两台设备都确认权限后，一台设备退出。点击右上角流转按钮，选择需要拉起的远程设备，点击后拉起远程设备，第一次拉起设备时，若未进行认证，输入认证码进行认证，认证成功后拉起远程设备。

2.游戏过程中，本地设备的用户可以重开，悔棋，远程设备无此功能。下子时，在棋盘某位置点击第一次时预下子，若确定下在该位置，继续点击该位置，若不确定，点击其他位置即可。若远程设备因特殊原因退出或者掉线，本地设备可重新拉起远程设备，拉起后，本地设备点击棋盘任意位置，数据会同步到远程设备，继续进行未完成的游戏。

##### 基本原理

* 管理分布式设备（节点）  
  1、创建设备管理对象，并指定参数kvstore应用包deviceManager.createDeviceManager("ohos.samples.distributeddatagobang", (error, value) => {})。  
  2、获取可信设备列表"this.deviceManager.getTrustedDeviceListSync()"。  
  3、监听设备状态"this.deviceManager.on('deviceStateChange', (data) => {})"。
* 分布式数据管理  
  1、页面初始化时获取此应用所需能力，引入@ohos.data.distributedData初始化分布式数据库，并使用kvstore.on对数据change进行监听，通过appstorge判断获取相应的key判断是否是分布式节点。  
  2、如果是分布式节点，如果数据发生变化处理数据，使用this.kvManager.getKVStore()通过指定Options和storeId，创建并获取KVStore数据库。以及添加键值对到数据库this.kvStore.put(key, value)。    
  3、页面通过kvStore对象进行增删改查会触发其他已连接设备的kvStore.on监听。  
* 游戏规则编写  
  1、init()函数初始化游戏规则，通过canvas组件绘制棋盘背景和棋子，游戏状态为开始，共计回合为0，并生成棋盘。
  2、触发onClick函数，每click一次，清除一次canvas，数组中添加当前棋子，重绘。
  3、当在A盘，且步长是偶数，表示B下的棋子会在A盘显示，绘制确定好的棋子，例如：this.deviceFlag === 'A' && this.distributedData.step % 2 === 0;
  4、当在B盘，且步长是奇数，表示A下的棋子会在B盘显示，绘制确定好的棋子，例如：this.deviceFlag === 'B' && this.distributedData.step % 2 !== 0;
  5、如果A盘重开(isRestart=true)，那B盘就要清空棋子;不重开(isRestart=false)时，B盘正常显示。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/DistributedDataGobang)

#### 游戏2048

##### 介绍

本示例使用用户首选项[ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md) 以及屏幕属性[@ohos.display](reference/apis-arkui/js-apis-display.md#displaygetdefaultdisplaydeprecated) 等接口，结合[Grid](reference/apis-arkui/arkui-ts/ts-container-grid.md)组件，实现了2048小游戏功能。

##### 使用

1.启动应用，同一个网络下两台设备都确认权限后，一台设备退出。点击右上角流转按钮，选择需要拉起的远程设备，点击后拉起远程设备，第一次拉起设备时，若未进行认证，输入认证码进行认证，认证成功后拉起远程设备。

2.游戏过程中，本地设备的用户可以重开，悔棋，远程设备无此功能。下子时，在棋盘某位置点击第一次时预下子，若确定下在该位置，继续点击该位置，若不确定，点击其他位置即可。若远程设备因特殊原因退出或者掉线，本地设备可重新拉起远程设备，拉起后，本地设备点击棋盘任意位置，数据会同步到远程设备，继续进行未完成的游戏。

##### 基本原理

* 管理分布式设备（节点）  
  1、创建设备管理对象，并指定参数kvstore应用包deviceManager.createDeviceManager("ohos.samples.distributeddatagobang", (error, value) => {})。  
  2、获取可信设备列表"this.deviceManager.getTrustedDeviceListSync()"。  
  3、监听设备状态"this.deviceManager.on('deviceStateChange', (data) => {})"。
* 分布式数据管理  
  1、页面初始化时获取此应用所需能力，引入@ohos.data.distributedData初始化分布式数据库，并使用kvstore.on对数据change进行监听，通过appstorge判断获取相应的key判断是否是分布式节点。  
  2、如果是分布式节点，如果数据发生变化处理数据，使用this.kvManager.getKVStore()通过指定Options和storeId，创建并获取KVStore数据库。以及添加键值对到数据库this.kvStore.put(key, value)。    
  3、页面通过kvStore对象进行增删改查会触发其他已连接设备的kvStore.on监听。  
* 游戏规则编写  
  1、init()函数初始化游戏规则，通过canvas组件绘制棋盘背景和棋子，游戏状态为开始，共计回合为0，并生成棋盘。
  2、触发onClick函数，每click一次，清除一次canvas，数组中添加当前棋子，重绘。
  3、当在A盘，且步长是偶数，表示B下的棋子会在A盘显示，绘制确定好的棋子，例如：this.deviceFlag === 'A' && this.distributedData.step % 2 === 0;
  4、当在B盘，且步长是奇数，表示A下的棋子会在B盘显示，绘制确定好的棋子，例如：this.deviceFlag === 'B' && this.distributedData.step % 2 !== 0;
  5、如果A盘重开(isRestart=true)，那B盘就要清空棋子;不重开(isRestart=false)时，B盘正常显示。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Game2048)

#### Lottie动画

##### 介绍

本示例展示了lottie对动画的操作功能。引入[Lottie模块](https://gitcode.com/openharmony-tpc/lottieETS)，实现控制动画的播放、暂停、倍速播放、播放顺序、播放到指定帧停止或从指定帧开始播放、侦听事件等功能，动画资源路径必须是json格式。

##### 使用

1. 进入页面默认开始2016动画，点击**请选择**进行选择动画资源;
2. 上面部分播放暂停是对两个动画进行控制，下面部分播放暂停功能是对grunt动画控制;
3. 点击销毁动画功能之后需要重新选择动画资源才可以进行其余功能操作。

##### 基本原理

* 页面中使用了Lottie对象控制动画的一系列操作:
    * 初始化动画：在canvas的onReady里使用loadAnimation加载动画，须提前声明Animator(‘__lottie_ets’)对象，并在Canvas完成布局后调用；
    * Lottie动画操作：lottie.play播放动画，lottie.pause暂停播放，lottie.setDirection设置播放顺序

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Game/Lottie)

### 即时通信

#### 聊天实例应用

##### 介绍

本示例使用图片处理能力接口[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)以及文件存储管理能力接口[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md) 。展示一个仿聊天类应用，使用静态布局搭建了不同的页面。为了优化内存与性能体验，在部分list场景使用了懒加载。

##### 使用

1. 应用包含“聊天”、”通讯录“、”发现“、”我“四个主页面，使用Tabs组件实现模块的切换，“聊天”和“通讯录”模块使用了LazyForEach懒加载功能。

2. 二级及以上页面左上角都有一个返回按钮。

3. 聊天内容页面的下方输入框点击可以输入内容，表情的图标点击可以发送图片。

4. “发现”页面的“朋友圈”点击会进入“朋友圈”页面。

##### 基本原理

懒加载：开发框架提供数据懒加载（LazyForEach组件）从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。

多线程：开发框架提供[多线程并发能力](performance/multi_thread_capability.md)，允许在同一时间段内同时执行多段代码，进行大量或调度点较分散的任务开发和处理。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/IM/Chat)

### 输入法

#### 自绘编辑框

##### 介绍

本示例通过输入法框架实现自绘编辑框，可以绑定输入法应用，从输入法应用输入内容，显示和隐藏输入法。

##### 使用

1. 点击编辑框可以绑定并拉起输入法，可以从输入法键盘输入内容到编辑框。

2. 可以点击**attach**/**dettach**、**show**/**hide**、**on**/**off**按钮来绑定/解绑、显示/隐藏、开启监听/关闭监听。

3. 输入光标信息后点击**updateCursor**向输入法应用发送光标信息，发送成功会右toast提示。

4. 输入选中文本的开始和结束位置，点击**changeSelection**可以选中文本。

5. 选择文本输入类型和Enter键类型后，点击**updateAttribute**可以更新拉起的输入法的输入类型和Enter键类型，依赖输入法应用是否适配。

##### 基本原理

* 自绘编辑框
  * 使用输入法框架实现组件绑定输入法应用，监听输入法事件，显示和隐藏输入法，发送光标和编辑框属性到输入法应用功能。
  * 参考接口：[@ohos.inputMethod](reference/apis-ime-kit/js-apis-inputmethod.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/CustomInputText)

#### 轻量级输入法

##### 介绍

本示例使用@ohos.application.InputMethodExtensionAbility系统权限的系统接口，展示一个轻量级的输入法应用，支持在运行OpenHarmony OS的智能终端上。

##### 使用

1. 点击编辑框可以绑定并拉起输入法，可以从输入法键盘输入内容到编辑框。

##### 基本原理

* 参考接口：@ohos.application.InputMethodExtensionAbility

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/KikaInput)

#### Kika输入法应用

##### 介绍

本示例使用[inputMethodEngine](reference/apis-ime-kit/js-apis-inputmethodengine.md)实现一个轻量级输入法应用kikaInput，支持在运行OpenHarmony OS的智能终端上。

##### 使用

1.使用hdc shell aa start ability -a InputMethod -b cn.openharmony.inputmethodchoosedialog命令拉起切换输入法弹窗，点击kikainput切换输入法到当前应用。

2.点击应用中的编辑框，拉起输入法键盘。

3.点击键盘可以在编辑框中输入内容，点击回退键可以删除文本。

4.点击左上角的键盘图标可以进入二级菜单，当前只有编辑菜单。

5.点击编辑可以进入编辑状态，点击方向键可以移动光标。

6.编辑状态点击选择按钮，进入选择状态，点击方向键可以选中文本。

##### 基本原理

* 该示例分为两个模块：
  * 键盘布局
    * 在Index中完成键盘的总体布局。在components中自定不同的按键组件。
    * 参考接口：[ArkTs声明式开发范式](ui/Readme-CN.md)
  * 输入法控制
    * 使用[@ohos.request](reference/apis-basic-services-kit/js-apis-request.md)中API 10接口agent.create创建上传任务，调用@ohos.request中的Task相关接口实现上传任务的创建、取消、进度加载，前台任务只支持单文件下载，后台任务支持多文件下载。使用[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)完成指定路径的创建和查询已下载的文件。
    * 参考接口：[@ohos.inputMethodEngine](reference/apis-ime-kit/js-apis-inputmethodengine.md)
##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/InputMethod/KikaInputMethod)

### 媒体

#### 相机和媒体库

##### 介绍

本示例使用权限管理能力[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)、相机模块能力接口[@ohos.multimedia.camera](reference/apis-camera-kit/arkts-apis-camera.md)、图片处理接口[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)、用户数据管理接口[@ohos.filemanagement.userFileManager](reference/apis-core-file-kit/js-apis-userFileManager-sys.md)、设备信息能力接口[@ohos.deviceInfo](reference/apis-basic-services-kit/js-apis-device-info.md)、文件存储管理能力接口[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md)、弹窗能力接口[@ohos.prompt](reference/apis-arkui/js-apis-prompt.md)，展示如何在eTS中调用相机拍照和录像，以及如何使用媒体库接口进行媒体文件的增、删、改、查操作。

##### 使用

1.启动应用，在权限弹窗中授权后返回应用，首页显示当前设备的相册信息，首页监听相册变化会刷新相册列表。

2.点击 **+** 按钮，弹出相机、录音、文本文件三个图标。

3.点击**相机**图标，进入相机界面，默认是拍照模式，点击底部拍照按钮可以拍照，拍照完成会在底部左侧显示照片预览图。点击**录像**切换到录像模式，点击底部按钮开始录像，点击结束按钮结束录像，结束录像后底部左侧显示视频图标。点击系统**Back**键或界面顶部**返回**按钮返回首页。

4.点击**录音**图标进入录音界面，点击右侧**开始**按钮开始录音，按钮变为暂停按钮，点击可以暂停和继续录音，点击左侧**结束**按钮结束录音返回首页。

5.点击**文本**图标进入文本编辑界面，输入文本内容后点击**Save**按钮，会创建并写入文本文件，完成后返回首页。

6.点击相册进入文件列表界面，展示相册内的文件，列表中有**删除**和**重命名**按钮，点击可以删除文件和重命名文件。

7.安装视频播放VideoPlayer应用后，点击视频文件可以调起视频播放界面播放该视频。

##### 基本原理

* 布局原理：定义@ObjectLink 装饰的数组变量album存放资源文件，使用list()组件中ListItem()循环数组展示，加号Button()，点击后触发 animateTo({ duration: 500, curve: Curve.Ease })控制动画展示。
* 获取资源文件：通过引入媒体库实例（入口）接口@ohos.multimedia.medialibrary，例如通过this.getFileAssetsFromType(mediaLibrary.MediaType.FILE)获取FILE类型的文件资源，并通过albums.push()添加至album数组中。  
* 展示系统资源文件：当album内的值被修改时，只会让用 @ObjectLink 装饰的变量album所在的组件被刷新，当前组件不会刷新。
* 录音功能：通过引入音视频接口@ohos.multimedia.media，例如通过media.createAudioRecorder()创建音频录制的实例来控制音频的录制，通过this.audioRecorder.on('prepare', () => {this.audioRecorder.start()})异步方式开始音频录制。
* 拍照录像功能：通过引入相机模块接口@ohos.multimedia.camera，例如通过this.cameraManager.createCaptureSession()创建相机入口的实例来控制拍照和录像，通过this.captureSession.start()开始会话工作。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Media/MultiMedia)

### 电商

#### 购物示例应用

##### 介绍

本示例使用延迟任务回调能力接口[@ohos.WorkSchedulerExtensionAbility](reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) 、通知管理的能力接口[@ohos.notification](reference/apis-notification-kit/js-apis-notification.md) 、HTTP数据请求能力接口[@ohos.net.http](reference/apis-network-kit/js-apis-http.md) 、媒体查询接口[@system.mediaquery](reference/apis-arkui/js-apis-system-mediaquery.md) 、管理窗口能力接口[@ohos.window](reference/apis-arkui/arkts-apis-window.md) 。实现在进场时加载进场动画，使用[Tabs容器](reference/apis-arkui/arkui-ts/ts-container-tabs.md) 实现通过页签进行内容视图切换。使用[自定义弹窗](reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md) 设置位置信息。使用[Swiper](reference/apis-arkui/arkui-ts/ts-container-swiper.md) 组件实现页面展示图轮播。使用[Grid](reference/apis-arkui/arkui-ts/ts-container-list.md) 容器组件设置展示的商品信息。

##### 使用

1、启动应用进入进场动画，然后进入首页的时候会有升级弹窗的提示，判断应用需不需要升级，整个应用分四部分，首页、新品、购物车、我的。可以点击进行切换。

2、“首页”页面具有扫一扫功能、搜索框、轮播图、tabs、商品列表。

3、“首页”页面的扫一扫点击可以进行二维码扫描，点击商品可以跳转到详情页。

4、“商品详情页”上部分是视频，点击视频进行播放，也可以点击进入全屏模式，向下滑动详情页视频可以变成小窗口模式。点击右侧悬浮的直播按钮，可进入直播页面，直播页面可进行视频播放。

5.“商品详情页”有个分享功能，点击可进行分享。点击选择收货地址可弹出选择地址的选项，可进行选择地址。

6.断开网络链接，“商品详情页”中点击降价通知后，重新连接网络后通知栏有降价通知。

7.新品、购物车、我的目前是静态页面。

##### 基本原理

1.应用创建时进行必要的权限判断：在app.json5文件中对```"requestPermission"```对象进行权限匹配。如果有如果权限列表中有-1，说明用户拒绝了授权。

2.配置Module信息

3.Navigation的使用

4.动态加载的使用

5.hsp包的创建与使用

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Shopping/OrangeShopping)

### 工具

#### ArkTS时钟

##### 介绍

本示例通过添加setInterval定时器启动时钟，使用[Canvas组件](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md)绘制时钟，通过[CanvasRenderingContext2D](reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md) 来画表盘背景、时针、分针、秒针、圆心以及表盘下方文本，结合[@ohos.display](reference/apis-arkui/js-apis-display.md) 接口来实现一个简单的时钟应用。

##### 使用

1.界面通过setInterval实现周期性实时刷新时间，使用Canvas绘制时钟，指针旋转角度通过计算得出。

##### 基本原理

* 本示例展示简单时钟的方法主要封装在Index中。
    * 设置表盘大小：通过Index中的display.getDefaultDisplay()方法来获取设备宽高计算表盘大小；
    * 获取当前时间：调用updateTime函数，执行new Date().getHours()、new Date().getMinutes()、new Date().getSeconds()获取当前时间。
    * 绘制表盘内容：通过[CanvasRenderingContext2D](reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md) 来画表盘背景、时针、分针、秒针、圆心以及表盘下方文本；
    * 启动时钟：添加setInterval定时器，每隔1s执行一次updateTime函数。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/ArkTSClock)

#### 翻页时钟

##### 介绍

本示例集中展示了时钟、闹钟、倒计时、设置屏幕亮度相关的场景，
1、使用[@ohos.reminderAgentManager](reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md)完成闹钟的相关功能，
2、使用animateTo完成翻页时钟动画，使用[@ohos.runningLock](reference/apis-basic-services-kit/js-apis-runninglock.md)完成屏幕常亮功能，
3、设置屏幕亮度，使用[@ohos.brightness](reference/apis-basic-services-kit/js-apis-brightness-sys.md)系统能力调节屏幕亮度，
4、后台消息提醒，使用[@ohos.notificationManager](reference/apis-notification-kit/js-apis-notificationManager.md)系统能力做后台代理提醒。
5、需要系统存储信息，使用用户首选项接口[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md)。

##### 使用

1.主页面有四个底部标签栏，时钟页面展示了数字翻页时钟功能。

2.闹钟功能点击**+**号可以创建一个闹钟，等闹钟时间到了会进行提醒。

3.倒计时功能。

4.设置里边实现的功能有全屏、调节屏幕亮度和不熄屏。

##### 基本原理

* 在entry/pages/index.ets中通过tabArray.TabType.num的值来加载每个TabContent()的资源，num:[0,1,2,3]分别加载翻页时钟，闹钟，倒计时，设置组件。
* 页面编写步骤：  
  1、定义以下四个页面组件 FlipClock()//翻转时钟 AlarmClock()// 闹钟CountDown()// 倒计时Setting()//设置  
  2、使用tabs()标签，将四个组件封装。
* 组件逻辑实现  
  1、时钟： 通过aboutToAppear()中new date()获取当前时间，通过获取date的时、分、秒，10位数通过math.floor()取整，个位数通过对10取余，从而实现对时间格式化，使用box标签，对获取到的数据进行渲染。  
  2、闹钟：   
   * a) 使用自定义对话控制器CustomDialogController，定义时间选择器，使用data.preferences存储设置的闹钟，并使用reminderAgentManager将其添加到系统中。
  import data_preferences from '@ohos.data.preferences'
  import reminderAgentManager from '@ohos.reminderAgentManager'  
  *  b) 页面从data.preferences获取添加的闹钟数据，通过Scroll()标签渲染，在标签row内，设置delete按钮，如果删除就调用以下函数取消系统时钟
  import reminderAgentManager from '@ohos.reminderAgentManager'
  reminderAgentManager.cancelReminder  
  3、倒计时  
  * a) 使用aboutToAppear()初始化界面布局，通过this.listener.on('change', portraitFunc)添加监听，  
  * b) 点击开始按钮触发以下函数开始计时，并修改按钮的样式为暂停，并将running=true，触发canvas样式
  * c) 点击暂停按钮，时间暂停，并将按钮样式修改为开始  
  * d) 点击reset计时重置，将所有数据初始化  

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/FlipClock)

#### JS时钟

##### 介绍

本示例使用JS语言编写示例，设置一个定时器（timer），捕捉用户动作，当用户离开首页时（onHide事件）定时器注销（clearInverval）定时器，当用户回到小程序首页时（onShow事件），重新设置一个定时器（timer）setInterval，使用[transform](reference/apis-arkui/arkui-js/js-components-svg-animatetransform.md)设置平移/旋转/缩放的属性，实现一个简单时钟应用。

##### 使用

1.安装hap包。

2.在桌面上找到hap包打开。

3.展示时钟页面。

##### 基本原理

1、在首页设置一个定时器（timer），定时调用接口从index.js刷新最新消息通知，更新首页通知列表;

2、捕捉用户动作，当用户离开首页时（onHide事件）定时器注销（clearInverval）定时器;

3、当用户回到小程序首页时（onShow事件），重新设置一个定时器（timer）setInterval，定时从index.js刷新最新消息通知。  

4、实现动画样式：通过transform设置平移/旋转/缩放的属性。时钟的指针使用rotate设置x轴和y轴两个维度参数，rotate可以传入具体角度值。指针旋转角度通过计算得出。  
例如："transform : rotate\(\{\{ second \* 6 \}\}deg\)", 秒针1秒转动6度。

##### 约束与限制

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/JsClock)

#### 图案密码锁组件

##### 介绍

本示例使用用户首选项接口[@ohos.data.preferences](reference/apis-arkdata/js-apis-data-preferences.md) 异步获取用户设定过的密码，以宫格图案的方式输入密码，用于密码验证。手指触碰图案密码锁时开始进入输入状态，手指离开屏幕时结束输入状态并向应用返回输入的密码。展示图案密码锁组件的使用，实现了密码设置、验证和重置功能。

##### 使用

1.首次进入时需要设置密码，需要两次输入密码相同后点击**设置密码**进行设置，如果第二次输入密码和第一次输入密码不同，会提示重新输入。

2.设置密码后，需要输入密码解锁，退出应用后重新进入应用，需要再次输入密码验证，密码验证成功进入主页。

3.设置密码后，在输入密码界面有**重置密码**按钮，点击后需要输入旧密码，旧密码验证成功后开始设置新的密码。  

##### 基本原理

* 在pages/Home.ets中定义密码锁组件，通过定义两个变量isHasPass：是否已经设过密码;isReset：是否需要重置密码;
* 密码验证分为几种情况：
  1. 首次进入页面， 通过aboutToAppear()初始化调用preferences.getPreferences()获取密码，此时defaultPassword='null'，isHassPass=false，需设置密码并确认密码；
  2. 已经设过密码： 通过aboutToAppear()初始化调用preferences.getPreferences()获取密码，此时defaultPassword='oldPassword'，isHassPass=true，页面渲染重置密码text()。
     需输入密码和defaultPassword比较，正确后跳转相应页面，若失败提示密码错误，需重新输入密码。
  3. 点击重置密码，此时组件清除旧密码，即defaultPassword='null'，此时无密码，走首次无密码流程。
* 在pages/index.ets中定义密码通过后的首页页面。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Tools/PatternLock)



## 关键特性

### 分布式

#### ArkTS分布式计算器

##### 介绍

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)、媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)，实现设备之间的kvStore对象的数据传输交互。通过StartAbility实现远端应用的拉起以及DistributedDataKit分布式数据框架实现异端应用的数据同步，实现一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个设备的计算器应用，两个计算器应用进行协同计算。

##### 使用

1.点击桌面应用图标，启动应用。

2.点击应用右上角按钮，或者在界面任意位置滑动（上下左右滑动皆可）即可弹出设备选择框。

3.在设备选择框中点击对端设备名称，拉起对端应用。

4.对端应用启动后，可在任意一端中操作应用，两端应用可实现数据实时同步。

5.在设备选择框中选中本机即可关闭对端应用。

##### 基本原理

在分布式计算器应用中，分布式设备管理包含了分布式设备搜索、分布式设备列表弹窗、远端设备拉起三部分。  
首先在分布式组网内搜索设备，然后把设备展示到分布式设备列表弹窗中，最后根据用户的选择拉起远端设备。
#### 分布式设备搜索
通过SUBSCRIBE_ID搜索分布式组网内的远端设备，详见startDeviceDiscovery(){}模块。
#### 分布式设备列表弹窗
使用@CustomDialog装饰器来装饰分布式设备列表弹窗。
#### 远端设备拉起
通过startAbility(deviceId)方法拉起远端设备的包。
#### 分布式数据管理
(1) 管理分布式数据库  
创建一个KVManager对象实例，用于管理分布式数据库对象。通过distributedData.createKVManager(config)，并通过指定Options和storeId，创建并获取KVStore数据库，并通过Promise方式返回，此方法为异步方法，例如this.kvManager.getKVStore(STORE_ID, options).then((store) => {})。
(2) 订阅分布式数据变化  
通过订阅分布式数据库所有（本地及远端）数据变化实现数据协同。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedCalc)

#### ArkTS分布式音乐播放

##### 介绍

本示例使用与用户进行交互的Ability的能力接口[@ohos.ability.featureAbility](reference/apis-ability-kit/js-apis-ability-featureAbility.md)、文件存储管理能力接口[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md)、屏幕属性接口[@ohos.display](reference/apis-arkui/js-apis-display.md)、媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)、分布式数据管理接口[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)，实现设备之间的kvStore对象的数据传输交互。通过AudioPlayer实现音频播放能力，调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增/删/改/查等各项操作。

##### 使用

1.**音乐播放**，点击**播放**、**暂停**、上**一曲**、下**一曲**按钮可以对音乐进行操作。

2.**跨设备分享**，组网并且双端均已授权条件下，点击**分享**按钮，选择设备，拉起对端设备上的音乐，并将本端的播放状态同步到对端上。

3.**跨设备停止分享**，分享成功前提条件下，点击**停止分享**按钮，将对端设备拉起的音乐应用停止退出。

##### 基本原理

在分布式音乐播放器中，分布式设备管理包含了分布式设备搜索、分布式设备列表弹窗、远端设备拉起三部分。  
首先在分布式组网内搜索设备，然后把设备展示到分布式设备列表弹窗中，最后根据用户的选择拉起远端设备。
#### 分布式设备搜索
通过SUBSCRIBE_ID搜索分布式组网内的远端设备，详见registerDeviceListCallback(callback) {}模块。
#### 分布式设备列表弹窗
使用@CustomDialog弹出分布式设备列表弹窗，参考首页。
#### 远端设备拉起
通过startAbility(deviceId)方法拉起远端设备的包。
#### 分布式数据管理
(1) 管理分布式数据库  
创建一个KVManager对象实例，用于管理分布式数据库对象。通过distributedData.createKVManager(config)，并通过指定Options和storeId，创建并获取KVStore数据库，并通过Promise方式返回，此方法为异步方法，例如this.kvManager.getKVStore(STORE_ID, options).then((store) => {})  
(2) 订阅分布式数据变化  
通过订阅分布式数据库所有（本地及远端）数据变化实现数据协同。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/ArkTSDistributedMusicPlayer)

#### JS分布式计算器

##### 介绍

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)、媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)，实现设备之间的kvStore对象的数据传输交互。通过StartAbility实现远端应用的拉起以及DistributedDataKit分布式数据框架实现异端应用的数据同步，实现一个简单的计算器应用，可以进行简单的数值计算，支持远程拉起另一个设备的计算器应用，两个计算器应用进行协同计算。

##### 使用

1.点击桌面应用图标，启动应用。

2.点击应用右上角按钮，或者在界面任意位置滑动（上下左右滑动皆可）即可弹出设备选择框。

3.在设备选择框中点击对端设备名称，拉起对端应用。

4.对端应用启动后，可在任意一端中操作应用，两端应用可实现数据实时同步。

5.在设备选择框中选中本机即可关闭对端应用。

##### 基本原理

在分布式计算器应用中，分布式设备管理包含了分布式设备搜索、分布式设备列表弹窗、远端设备拉起三部分。  
首先在分布式组网内搜索设备，然后把设备展示到分布式设备列表弹窗中，最后根据用户的选择拉起远端设备。
#### 分布式设备搜索
通过SUBSCRIBE_ID搜索分布式组网内的远端设备，详见startDeviceDiscovery(){}模块
#### 分布式设备列表弹窗
使用calc-select-device-dialog渲染分布式设备列表弹窗
#### 远端设备拉起
selectDevice()发起远程设备调用，featureAbility.startAbility()方法拉起远端设备的包，调用dataChange(key, value)改变kvstore的值。
#### 分布式数据管理
(1) 管理分布式数据库  
创建一个KVManager对象实例，用于管理分布式数据库对象。通过distributedData.createKVManager(config)，并通过指定Options和storeId，创建并获取KVStore数据库，并通过Promise方式返回，此方法为异步方法，例如this.kvManager.getKVStore(STORE_ID, options).then((store) => {})。  
(2) 订阅分布式数据变化  
通过订阅分布式数据库所有（本地及远端）数据变化实现数据协同。

##### 约束与限制

开发语言：JS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributeCalc)

#### 分布式账号

##### 介绍

本示例主要展示了分布式账号相关的功能，使用[@ohos.account.distributedAccount](reference/apis-basic-services-kit/js-apis-distributed-account.md)、[@ohos.account.osAccount](reference/apis-basic-services-kit/js-apis-osAccount.md)等接口，实现了绑定分布式账号、解绑分布式账号、更新分布式账号信息和管理分布式账号的功能。

##### 使用

1. 首次进入应用会根据分布式账号绑定状态进行页面跳转，若账号已绑定，则直接跳转至账号列表界面；若账号未绑定，则需要在首页进行绑定；
1. 首页输入分布式账号名（必填）、昵称，选择头像（需先使用hdc命令将图片推到storage/media/100/local/files/Pictures/路径下并重启），选择绑定的系统账号，点击**绑定**，绑定成功跳转至账号列表界面；
2. 在账号列表界面，可对所有可解绑分布式账号进行管理，点击选择分布式账号，跳转至对应的账号信息界面；
3. 在账号信息界面，点击**解绑**，可解绑该分布式账号；
3. 在账号解绑之后，可对分布式账号信息进行更新，在首页直接进行输入后点击绑定即可。

##### 基本原理

* 绑定、解绑、查询、更新分布式账号的功能接口封装在DistributedAccountModel：
    * 使用distributedAccount.getDistributedAccountAbility()获取分布式账号单实例对象accountAbility;
    * 绑定、解绑和更新分布式账号：使用accountAbility.setOsAccountDistributedInfoByLocalId();
    * 查询分布式账号信息：使用accountAbility.getOsAccountDistributedInfo()和accountAbility.getOsAccountDistributedInfoByLocalId;

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DistributedAppDev/DistributedAccount)

#### 设备管理

##### 介绍

本示例主要展示了设备管理相关的功能，使用[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md) 等接口，实现了包括获取本机设备信息，获取授信设备列表，根据过滤条件扫描设备，设备认证，设备状态订阅，导入凭据，控制设备是否允许被发现等功能。

##### 使用

1. 进入应用会自动获取本机设备信息，并且注册设备状态监听，在有设备上下线的时候，刷新可信设备列表
2. 在主界面，可以点击允许被发现开关控制本机是否允许被发现；
3. 在主界面，可以点击刷新，刷新可信设备列表，点击已认证，解除认证关系；
4. 在主界面，可以点击过滤条件，选择对应的过滤条件，在发现设备时进行过滤；
5. 在主界面，可以点击发现，发现周边的设备，并点击发现的设备，进行PIN码认证；

##### 基本原理

获取本机设备信息，获取授信设备列表，根据过滤条件扫描设备，设备认证，设备状态订阅，控制设备是否允许被发现等功能，接口封装在RemoteDeviceModel：

    * 使用RemoteDeviceModel.createDeviceManager()来获取DeviceManager对象；
    * 获取本机设备信息：调用RemoteDeviceModel.getLocalDeviceInfo()来获取本机设备信息；
    * 注册设备状态监听：调用RemoteDeviceModel.registerDeviceStateListener()，来注册设备状态监听;
    * 获取可信设备列表：调用RemoteDeviceModel.getTrustedDeviceList()来获取可信设备列表;
    * 发布设备：调用RemoteDeviceModel.setIsSupportRange()设置是否上报距离，然后调用deviceManager.publishDeviceDiscovery()发布设备;
    * 停止发布设备：调用RemoteDeviceModel.unAuthenticateDevice()停止发布;
    * 发现和停止发现设备：调用RemoteDeviceModel.startDeviceDiscovery()发现设备，调用RemoteDeviceModel.stopDeviceDiscovery()停止发现设备;
    * 认证和取消认证设备：调用RemoteDeviceModel.authenticateDevice()认证，调用RemoteDeviceModel.unAuthenticateDevice()取消认证设备;

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DistributedAppDev/DistributedAuthentication)

#### 分布式备忘录

##### 介绍

本示例使用分布式数据管理接口[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)、权限管理能力[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)、分布式数据对象接口[@ohos.data.distributedDataObject](reference/apis-arkdata/js-apis-data-distributedobject.md)以及分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)，实现设备之间的distributedDataObject对象的数据传输交互，展示在eTS中如何使用分布式数据对象实现一个简单的分布式备忘录。

##### 使用

1.  启动应用，选择允许授权后，选择不同的分布式对象进入，如选择distributiedNote，则进入笔记界面：
   1. 点击右上角按钮可以连接组网设备，选择设备后进行连接，连接成功后两个设备上首页状态均显示绿色，每次连接其他设备，界面会清空备忘录内容。
   2. 点击**添加**按钮进入添加界面，可以编辑标题、内容、标记颜色，点击**提交**按钮添加备忘录。
   3. 点击**清除**按钮清除所有备忘录内容。
   4. 点击已经添加的备忘录可以进入编辑界面更新备忘录内容，编辑完成后点击**提交**按钮更新备忘录。
   5. 两台设备连接成功后步骤2、3、4的操作会同步到另一台设备上。
2. 如选择distributiedCanvas，则进入画布界面：
   1. 点击右上角按钮可以连接组网设备，选择设备后进行连接，连接成功后两个设备上首页状态均显示绿色。
   2. 点击ellipse或者rect按钮，则进行绘制对应的图形。
   3. 点击delete，则删除所有绘制的图形。
   4. 两台设备连接成功后步骤2、3的操作会同步到另一台设备上。
   5. 点击back按钮，则回退到选择分布式对象的首页。

##### 基本原理

在分布式笔记应用中，分布式设备管理包含了分布式设备搜索、分布式设备列表弹窗、远端设备拉起三部分。  
首先在分布式组网内搜索设备，然后把设备展示到分布式设备列表弹窗中，最后根据用户的选择拉起远端设备。
#### 分布式设备搜索
通过SUBSCRIBE_ID搜索分布式组网内的设备，详见startDeviceDiscovery(){}模块。
#### 分布式设备列表弹窗
使用@CustomDialog装饰器来装饰分布式设备列表弹窗。
#### 远端设备拉起
通过startAbility(deviceId)方法拉起远端设备的包。  
#### 分布式数据管理
(1) 管理分布式数据库  
创建一个distributedObject分布式数据对象实例，用于管理分布式数据对象。详见distributedObject.createDistributedObject()。  
(2) 订阅分布式数据变化  
通过this.distributedObject.on('status', this.statusCallback)监听分布式数据对象的变更。
#### 笔记
(1)UIAbility拉起弹框请求用户授权:在onCreate()时通过abilityAccessCtrl.createAtManager.requestPermissionsFromUser(this.context, ['ohos.permission.DISTRIBUTED_DATASYNC']).then((data)=> {})获取不同设备间的数据交换权限。   
(2)将sessionID存在应用全局的UI状态存储AppStorage内：在onCreate(want, launchParam) {}时拿到sessionId并存储在AppStorage内，并把同时把sessionId绑定到@StorageLink上实现双向数据绑定。  
(3)对笔记内容进行存储在dataArray:note[]中：通过this.noteDataSource['dataArray'] = this.globalObject.distributedObject.documents。  
(4)笔记内容更新：通过绑定Button的onClick事件指定this.globalObject.update(index, this.note.title, this.note.content, this.note.mark)进行笔记内容和状态更新。    
(5)实现分布式数据自动同步：通过this.globalObject.distributedObject.setSessionId(this.sessionId)，从而实现当可信组网中有多个设备时，多个设备间的对象如果设置为同一个sessionId的笔记数据自动同步，并将其封装在share()函数内。    
(6)在首页的onPageShow()钩子中，调用share()实现首页在分布式设备上同步渲染组件。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedNote)

#### 分布式关系型数据库

##### 介绍

本示例使用[@ohos.data.relationalStore](reference/apis-arkdata/arkts-apis-data-relationalStore.md) 接口和[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md) 接口展示了在eTS中分布式关系型数据库的使用，在增、删、改、查的基本操作外，还包括分布式数据库的数据同步同能。

##### 使用

1. 启动应用后点击“**+**”按钮可以添加联系人;
2. 点击联系人可以进入编辑界面编辑联系人信息;
3. 长按联系人进入多选状态，底部有“**全选**”、“**取消**”、“**删除**”、“**退出**”按钮，点击退出可以退出多选状态;
4. 点击右上角更多按钮，点击“**连接设备**”，选择要同步数据的设备，连接成功后可以开始将本端数据同步到对端;
5. 点击右上角更多按钮，点击“**设置**”可以进入设置界面设置数据同步方式，包括自动同步和手动同步。

##### 基本原理

+ 数据库的增、删、改、查操作都在RdbModel中，:
    + 数据库操作：使用[@ohos.data.relationalStore](reference/apis-arkdata/arkts-apis-data-relationalStore.md) 接口的getRdbStore获得一个相关的操作型关系数据库RdbStore，通过这个RdbStore调用相关接口进行增删改查，RdbStore.insert数据插入,RdbStore.delete数据删除，RdbStore.update更新数据，RdbStore.query根据条件查询数据;
    + 数据同步：RdbStore.on注册数据库观察者，使用RdbStore.obtainDistributedTableName根据本地表名获取指定远程设备的分布式表名，数据发生变动时通过RdbStore.sync同步数据，不需要用时删除指定观察者使用RdbStore.off。
+ 连接设备管理在RemoteDeviceModel中:
    + 设备同步：设备同步数据需要[ohos.permission.DISTRIBUTED_DATASYNC](security/AccessToken/permissions-for-all-user.md#ohospermissiondistributed_datasync) 权限，在页面渲染前申请权限,使用[@ohos.distributedDeviceManager](reference/apis-distributedservice-kit/js-apis-distributedDeviceManager.md) 接口，首先通过createDeviceManager创建设备管理器实例，然后通过getTrustedDeviceListSync同步获取所有可信设备列表；
    + 设备连接：首先通过on方法注册设备状态，例如发现设备，设备连接失败，然后通过startDeviceDiscovery方法发现周边设备，然后选择连接设备，再启动连接设备的应用。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedRdb)

#### JS分布式音乐播放

##### 介绍

本示例使用与用户进行交互的Ability的能力接口[@ohos.ability.featureAbility](reference/apis-ability-kit/js-apis-ability-featureAbility.md)、文件存储管理能力接口[@ohos.fileio](reference/apis-core-file-kit/js-apis-fileio.md)、屏幕属性接口[@ohos.display](reference/apis-arkui/js-apis-display.md)、媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)、分布式数据管理接口[@ohos.data.distributedData](reference/apis-arkdata/js-apis-distributed-data.md)、音视频相关媒体业务能力接口[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)、分布式设备管理能力接口(设备管理)[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md)，实现设备之间的kvStore对象的数据传输交互。通过AudioPlayer实现音频播放能力，调用分布式数据各个接口，应用程序可将数据保存到分布式数据库中，并可对分布式数据库中的数据进行增/删/改/查等各项操作。

##### 使用

1.**音乐播放**，点击**播放**、**暂停**、上**一曲**、下**一曲**按钮可以对音乐进行操作。

2.**跨设备迁移播放**，组网条件下，点击**流转**按钮，选择设备，拉起对端设备上的音乐，本端退出。

##### 基本原理

在分布式音乐播放器中，分布式设备管理包含了分布式设备搜索、分布式设备列表弹窗、远端设备拉起三部分。  
首先在分布式组网内搜索设备，然后把设备展示到分布式设备列表弹窗中，最后根据用户的选择拉起远端设备。
###### 分布式设备搜索
通过SUBSCRIBE_ID搜索分布式组网内的远端设备，详见registerDeviceListCallback_(callback) {}模块。
###### 分布式设备列表弹窗
使用continueAbilityDialog弹出分布式设备列表弹窗，参考首页。
###### 远端设备拉起
通过startAbility(deviceId)方法拉起远端设备的包。

##### 约束与限制

开发语言：JS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/JsDistributedMusicPlayer)

#### 分布式数据管理

##### 介绍

本示例展示了在eTS中分布式数据管理的使用，包括KVManager对象实例的创建和KVStore数据流转的使用。

通过设备管理接口[@ohos.distributedHardware.deviceManager](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md) ，实现设备之间的kvStore对象的数据传输交互，该对象拥有以下能力[详见](reference/apis-distributedservice-kit/js-apis-device-manager-sys.md) ;
1、注册和解除注册设备上下线变化监听
2、发现周边不可信设备
3、认证和取消认证设备
4、查询可信设备列表
5、查询本地设备信息，包括设备名称，设备类型和设备标识
6、发布设备发现

##### 使用

1.两台设备组网。

2.在一台界面中点击右上角的流转按钮，在弹窗中选择对端设备拉起对端设备上的应用。

3.拉起对端设备后，在界面中点击"+"按钮新增笔记卡片，点击每个卡片右上角的"X"按钮可以删除此卡片，可以看到对端设备和当前设备界面数据保持一致。

4.操作对端设备，当前设备界面也会保持和对端设备界面显示一致。

##### 基本原理

1、页面初始化时获取此应用所需能力：引入@ohos.data.distributedKVStore初始化kvstore数据库并对使用kvstore.on数据change进行监听，通过appstorge判断获取相应的key判断是否是分布式节点。
2、如果是分布式节点，如果数据发生变化，处理数据并使用.noteDataSource()进行reload数据。  
3、页面通过kvStore对象进行增删改查会触发其他已连接设备的kvStore.on监听。


##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/Kvstore)

#### 分布式文件管理

##### 介绍

本示例使用分布式能力实现了一个分布式的文件管理，可以进行文件的跨设备拷贝。

##### 使用

1. 两台设备A、B组网成功。

2. A设备上长按列表出现复选框，选择文件(夹)后点击下方的“复制”按钮。

3. B设备上进入要复制的文件夹目录，点击右上角的“粘贴”图标。

4. A设备上的文件成功拷贝至B设备。

##### 基本原理

本示例用到了文件管理接口[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)。

分布式数据对象接口[@ohos.data.distributedDataObject](reference/apis-arkdata/js-apis-data-distributedobject.md)。

允许系统应用获取分布式设备的认证组网能力：[ohos.permission.ACCESS_SERVICE_DM](security/AccessToken/permissions-for-system-apps.md#ohospermissionACCESS_SERVICE_DM)

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.3.3

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedFilemanager)

#### 跨端迁移随手记

##### 介绍

本示例主要展示了应用数据跨端迁移的能力，通过跨端迁移的能力实现了一个简单的随手记应用，可以响应系统迁移事件，控制应用的迁移能力、是否迁移页面栈以及迁移后是否退出源端等。同时实现了数据迁移以及ArkUI控件的迁移。

本示例使用了权限管理接口[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)、分布式数据对象接口[@ohos.data.distributedDataObject](reference/apis-arkdata/js-apis-data-distributedobject.md)、基础文件操作接口[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md) 、相册管理模块接口[@ohos.file.photoAccessHelper](reference/apis-core-file-kit/js-apis-fileAccess-sys.md)、图片处理接口[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)等接口，通过分布式数据对象以及分布式文件两种方式实现了图片数据的流转迁移。

##### 使用

1. 启动应用，进入欢迎页，点击允许授权。

2. 进入主页，点击右上角设置图标进入迁移设置页面，可以设置当前应用是否具备迁移能力、是否迁移页面栈以及迁移后是否退出源端。

3. 进入主页，可以点击笔记页、待办事项、图片墙等按钮进入对应页面。

4. 在笔记页，可以编辑笔记标题、笔记内容、选择图片，在打开迁移能力和迁移页面栈的情况下，所编辑的内容和选择的图片可以同步迁移到对端设备。

5. 在待办事项页，勾选多选框，在打开迁移能力和迁移页面栈的情况下，可以迁移当前的勾选状态。

6. 在图片墙页，滑动页面到某个位置，在打开迁移能力和迁移页面栈的情况下，可以迁移当前的瀑布流控件索引位置。

##### 基本原理

* 在跨端迁移随手记应用里，迁移设置的功能在Setting.ets和entryability中的onContinue()实现：

  * 通过[UIAbilityContext](reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)的[setMissionContinueState](reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#setmissioncontinuestate10)可以设置当前应用任务流转的状态，控制当前应用是否具有迁移能力。

  * 通过设置wantConstant.Params.SUPPORT_CONTINUE_PAGE_STACK_KEY和wantConstant.Params.SUPPORT_CONTINUE_SOURCE_EXIT_KEY的值可以控制当前应用是否迁移页面栈以及迁移后源端是否退出。

* 笔记页通过分布式数据对象和分布式文件在Notes.ets中实现大文件（100KB以上）数据的迁移。通过分布式文件的[跨设备文件访问](https://gitcode.com/openharmony/docs/blob/master/zh-cn/application-dev/file-management/file-access-across-devices.md)实现了图片的迁移。

* 从图库中选择图片，使用选择器接口[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)的PhotoViewPicker图库选择器对象选择一张图片并通过writeSrcToDistributedFile(this.uris)将选择的图片的uri写入分布式文件路径filePath。接口参考：[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)

* 使用getImage()方法获取从图库中选择的图片资源PixelMap类型，首先使用photoAccessHelper.getPhotoAccessHelper(context)获取相册管理模块的实例，使用phAccessHelper.getAssets()获取图片资源,使用photoAsset.getThumbnail()获取所选的图片的PixelMap类型数据。接口参考：[ohos.file.photoAccessHelper](reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md) 

* 在对端设备上迁移显示笔记页内容时，在aboutToAppear()钩子中调用readFromDistributedFile()读取分布式路径里存储的图片文件。首先以同步方法fs.accessSync(filePath)检查分布式路径下文件是否存在，通过image.createImageSource(filePath)传入的uri创建ImageSource实例imageSourceApi,通过imageSourceApi.createPixelMap()来创建PixelMap 并负责流转后展示。接口参考：[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.5.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/DistributedAppDev/DistributedJotNote)

### 一次开发多端部署

#### ArkTS多设备自适应能力

##### 介绍

本示例是[《一次开发，多端部署》](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)的配套示例代码，展示了[页面开发的一多能力](key-features/multi-device-app-dev/layout-intro.md)，包括自适应布局、响应式布局、典型布局场景以及资源文件使用。

| 名称         | 简介                                                         |
| ------------ | ------------------------------------------------------------ |
| 自适应布局   | 当外部容器大小发生变化时，元素可以**根据相对关系自动变化**以适应外部容器变化的布局能力。 |
| 响应式布局   | 当外部容器大小发生变化时，元素可以**根据断点或特定的媒体特征（如屏幕方向、窗口宽高等）自动变化**以适应外部容器变化的布局能力。 |
| 典型布局场景 | 应用开发中的典型场景，包括运行横幅、网格、侧边栏等。         |
| 资源文件使用 | 根据当前的设备特征（如设备类型、屏幕密度等）或应用场景（如语言、国家、地区等），从resources目录下不同的资源限定词目录中获取相应的资源值。 |

##### 使用

1. 启动应用，首页展示了自适应布局、响应式布局、典型布局场景和资源文件使用四个按钮。

2. 点击"自适应布局"进入新页面，分别展示拉伸能力、缩放能力、隐藏能力、折行能力、均分能力、占比能力和延伸能力共7种自适应布局能力。

3. 点击"响应式布局"进入新页面，分别展示断点、媒体查询和栅格布局3种响应式布局能力。

4. 点击"典型布局场景"进入新页面，展示了如何通过自适应布局能力和响应式布局能力，实现应用开发中的典型场景。

5. 点击"资源文件使用"进入新页面，展示字符串和图片资源的使用。

##### 基本原理

* 该示例使用了路由跳转接口，实现了各个不同布局之间的页面跳转，通过MediaQueryListener方法查询媒体，matchMediaSync方法设置媒体查询的查询条件。
* 接口参考：[@ohos.router](reference/apis-arkui/js-apis-system-router.md)，[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AdaptiveCapabilities)

#### 一多应用市场首页

##### 介绍

本示例使用媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)，结合[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，展示应用市场首页，页面中包括Tab栏、运营横幅、精品应用、精品游戏等。

##### 使用

1. 启动应用，可以查看本应用在全屏状态下的显示效果。

2. 在应用顶部，下滑出现窗口操作按钮。（建议通过外接鼠标操作，接入鼠标只需要将鼠标移动至顶部即可出现窗口）

3. 点击悬浮图标，将应用悬浮在其它界面上显示。

4. 拖动应用悬浮窗口的边框，改变窗口尺寸，触发应用刷新，即可查看应用在不同窗口下的显示效果。

5. 改变窗口尺寸的过程中，窗口尺寸可能超出屏幕尺寸。此时在屏幕中只能看到应用部分区域的显示，但可以通过移动窗口位置，查看应用其它区域的显示。

##### 基本原理

本示例介绍如何使用自适应布局能力和响应式布局能力适配不同尺寸窗口，将页面分拆为5个部分。   
##### 底部/侧边导航栏
1、在sm和md断点下，导航栏在底部；在lg断点下，导航栏在左侧。   
2、通过Tab组件的barPosition和vertical属性控制TabBar的位置在主轴方向起始或结尾位置和水平或垂直方向，同时还可以通过barWidth和barHeight属性控制TabBar的尺寸。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/AppMarket)

#### 健康饮食

##### 介绍

本示例使用了路由跳转[@ohos.router](reference/apis-arkui/js-apis-system-router.md)，比如点击食物，可以跳转至相应的食物详情页面，通过[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)，使用其中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，使用[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)的MediaQueryListener方法查询媒体，matchMediaSync方法设置媒体查询的查询条件，[@ohos.curves](reference/apis-arkui/js-apis-curve.md)的cubicBezierCurve方法构造三阶贝塞尔曲线对象。

##### 使用

1. 本应用一共有“启动动画页面”、“首页”和“食物详情”三个主页面；
2. 启动应用，进入“启动动画页面”，动画播放完成自动进入主页；
3. 首页，使用Tabs组件把首页分为两个页签：“主页”页签和“记录”页签。“主页”页签展示所有食物，支持通过Tab子页签展示的食物分类网格布局和字母排序列表两种方式查看，点击食物项可进入相应的食物详情页面，查看食物详情。食物“记录”页签，展示饮食记录，通过卡片展示不同时间段的饮食信息，卡片信息包含有食物的种类、重量、卡路里值以及用餐时间；以柱状图的形式展示每一餐所有食物的热量值和包含的营养元素含量；可以在卡片里面通过使用加减按钮来修改食物的重量，同时会重新统计相应用餐时间的总热量值、总蛋白质、总脂肪和总碳水值，并且柱状图的数据会及时更新;
5. 食物详情页面，使用滑动组件展示食物的详细信息，包括使用画布组件展示单位重量的食物各个营养元素的的占比,使用进度条组件展示当前食物是否为高热食物，以及展示单位重量的食物所包含的热量、脂肪、蛋白质、碳水以及维他命C值；并且点击记录按钮可以弹出记录饮食的弹窗，包括记录食物的种类、重量以及用餐时间，可以通过点击完成添加饮食，同时添加的饮食信息会在“记录”Tab页签做展示。

##### 基本原理

* 本实例使用了路由跳转，比如点击食物，可以跳转至相应的食物详情页面，通过一次开发多端部署，使用其中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，使用MediaQueryListener方法查询媒体，matchMediaSync方法设置媒体查询的查询条件，cubicBezierCurve方法构造三阶贝塞尔曲线对象。
* 接口参考：[@ohos.router](reference/apis-arkui/js-apis-system-router.md)，[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)，[@ohos.curves](reference/apis-arkui/js-apis-curve.md)，[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/HealthyDiet)

#### JS多设备自适应能力

##### 介绍

此Demo展示在JS中的多设备自适应能力，包括资源限定词、原子布局和响应式布局。 

##### 使用

1.本示例中的资源限定词和响应式布局针对常见设备类型做了适配，可以在预览器中开启"Multi-profile preview"进行多设备预览。

2.本示例中的原子布局提供了滑动条（slider），通过拖动滑动条更改父容器尺寸可以更直观的查看原子布局的效果。为了突出重点以及易于理解，此部分的代码做了一定精简，建议通过IDE预置的MatePadPro预览器查看此部分效果。

3.启动应用，首页展示了**资源限定词**、**原子布局**和**响应式布局**三个按钮。

4.点击**资源限定词**进入新界面，展示字符串和图片资源的使用。

5.点击**原子布局**进入新界面，分别展示原子布局的拉伸能力、缩放能力、隐藏能力、折行能力、均分能力、占比能力、延伸能力。

6.点击**响应式布局**进入新界面，展示媒体查询、栅格布局、典型场景三类响应式布局能力。

##### 基本原理

1、index下定义三个box，分别资源限定词resourceQualifier、原子布局atomicLayoutCapability、响应式布局responsiveLayout，并通过onclick路由到各自的组件。  
2、资源限定词组件： 在MainAbility.resource下定义需要访问的资源，在资源限定词resourceQualifier组件中，使用$r('')即可实现不同形态和规格访问到不同的资源。  
3、原子布局atomicLayoutCapability组件：该布局下，通过slide滑动控制样式的展示比率rate,例如下面这个样例。  
4、响应式布局responsiveLayout ：该布局下需要相对应的媒体资源，比如sm、md、lg，然后监听媒体的变化，从而对资源进行响应式的调整。 例如栅格布局。本案例定义了xs、sm、md、lg下的栅格宽度，根据系统的规格自动选择相应的属性。  
5、使用mediaQuery对规格进行监听，判断当前系统的横竖屏，从而加载相应的资源。  

##### 约束与限制

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/JsAdaptiveCapabilities)

#### 一多分栏控件

##### 介绍

本示例分别展示了多场景下，一多分栏控件的响应式变化效果。分别用到了[SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)组件与[Navigation](reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)组件，对应使用场景如下：

- A+B+C：即SideBarContainer组件组合Navigation组件
  1. 预览器窗口宽度>840vp时，显示A、B、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=840vp并且>600vp时，显示B、C两列，放大缩小时，优先变化C列
  3. 预览器窗口宽度<=600vp并且>360vp时，仅显示C列
- A+C：SideBarContainer组件
  1. 预览器窗口宽度>600vp时，显示A、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=600vp并且>360vp时，仅显示C三列
- B+C：Navigation组件
  1. 预览器窗口宽度>600vp时，显示B、C三列，放大缩小时，优先变化C列
  2. 预览器窗口宽度<=600并且>360vp时，仅显示C三列

##### 使用

1.在预览器中查看页面效果

2.在预览器中开启窗口拖拽模式，拖动窗口变化，可以查看组件的响应式变化

##### 基本原理

* [SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)组件，自动隐藏侧边栏的功能是由minContentWidth与minSideBarWidth属性实现的。当设置[SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)组件组件的显示类型为SideBarContainerType.Embed,并且窗口宽度达到minContentWidth + minSideBarWidth的边界值时，侧边栏自动隐藏。

* [Navigation](reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)组件，自动隐藏侧边栏的功能是由minContentWidth属性实现的。当[Navigation](reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)的内容区域达到minContentWidth设置的值时，navBar自动隐藏。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MultiColumns)

#### 一多导航栏

##### 介绍

本示例展示了导航组件在不同设备形态下的样式。

- 在sm设备上，以tabs形式展示，内容、导航为上下样式布局，通过点击底部tabs切换内容；
- 在md/lg设备上，以[SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)形式展示，内容、导航为左右布局，通过点击侧边一二级菜单进行内容切换。

本示例使用[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev) 中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，主要通过组件提供窗口断点事件，保证应用在不同设备或不同窗口尺寸下可以正常显示。

##### 使用

1. 打开首页，在IDE编辑器中打开预览器查看预览效果。
2. 在预览器中开启窗口拖拽模式，拖动窗口变化，可以查看组件的响应式变化。
3. 手动自由拖拽窗口，将应用窗口在sm/md/lg三种设备形态下进行切换并查看预览效果。
4. 在sm/lg窗口下，点击左上角图标进行侧边栏样式切换。

##### 基本原理

本示例介绍如何使用自适应布局能力和响应式布局能力适配不同尺寸窗口,将页面分拆为2部分。

**整体布局:**

1.通过GridRow组件提供的断点事件，获取到当前窗口的断点，通过visibility属性将[Tabs](reference/apis-arkui/arkui-ts/ts-container-tabs.md)组件与[SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)组件分别在sm/(md、lg)
形态下展示/隐藏。

2.同时通过断点，对组件设置不同的样式属性，以最优的效果展示。

**侧边栏SideBar/底部TabsController:**

1.侧边栏内容布局通过Flex容器分别在sm/(md、lg)形态下进行横竖展示。

2.内容区域通过不同的窗口断点进行选择显隐。

3.md、lg形态侧边栏一级菜单对应sm形态最外层的TabsController组件、二级菜单对应里层的TabsController组件。

4.侧边栏同时存在两种形态list/tabs，通过侧边栏左上角图标切换，list模式下内容区域较小，根据窗口断点只显示图标/图标+文字，tabs模式下内容区域较大，显示图标+文字。

**内容区域:**

1.Swiper组件通过获取窗口断点，设置displayCount属性，在不同窗口下显示不同数量的图片。

2.Gird组件通过获取窗口断点，设置columnsTemplate与rowsTemplate属性，在不同窗口下显示不同数量的Item。

3.内容浏览的连续性，进行窗口切换时，内容区域的浏览进度可以保持，不会进行重新刷新。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.2

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MultiNavBar)

#### 一多音乐专辑主页

##### 介绍

本示例使用媒体查询接口[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)，[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示，展示音乐专辑主页。

- 头部返回栏: 因元素单一、位置固定在顶部，因此适合采用自适应拉伸，充分利用顶部区域。
- 专辑封面: 使用栅格组件控制占比，在小尺寸屏幕下封面图与歌单描述在同一行。
- 歌曲列表: 使用栅格组件控制宽度，在小尺寸屏幕下宽度为屏幕的100%，中尺寸屏幕下宽度为屏幕的50%，大尺寸屏幕下宽度为屏幕的75%。
- 播放器: 采用自适应拉伸，充分使用底部区域。

##### 使用

1.启动应用，查看本应用在全屏状态下的效果。

2.在应用顶部，下滑出现窗口操作按钮。（建议通过外接鼠标操作，接入鼠标只需要将鼠标移动至顶部即可出现窗口）

3.点击悬浮图标，将应用悬浮在其他界面上显示。

4.拖动应用悬浮窗口的四个顶角，改变窗口尺寸，触发应用显示刷新。改变窗口尺寸的过程中，窗口尺寸可能超出屏幕尺寸，此时在屏幕中只能看到应用部分区域的显示。可以通过移动窗口位置，查看应用其它区域的显示。

##### 基本原理

本示例介绍如何使用自适应布局能力和响应式布局能力适配不同尺寸窗口，将页面分拆为4个部分。
###### 标题栏
由于在不同断点下，标题栏始终只显示“返回按钮”、“歌单”以及“更多按钮”，但“歌单”与“更多按钮”之间的间距不同。  
通过栅格实现：将标题栏划分为“返回按钮及歌单”和“更多按钮”两部分，这两部分在不同断点下占据的列数不同。
###### 歌单封面
通过栅格实现歌单封面，它由封面图片、歌单介绍及常用操作三部分组成这三部分的布局在md和lg断点下完全相同，但在sm断点下有较大差异。  
1、在sm断点下，封面图片和歌单介绍占满12列，常用操作此时会自动换行显示。  
2、在lg和md断点下，封面图片，歌单和常用操作各占一行中显示。
###### 歌单列表
通过List组件的lanes属性实现：在不同断点下，歌单列表的样式一致，但sm和md断点下是歌单列表是单列显示，lg断点下是双列显示。  
###### 播放控制栏
通过Blank组件实现拉伸能力：在不同断点下，播放控制栏显示的内容完全一致，唯一的区别是歌曲信息与播放控制按钮之间的间距有差异。
###### 总体运行效果
通过在首页Column()中引用上述各组件后，可实现首页的组件整合渲染，即可完成整体页面开发。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/MusicAlbum)

#### 一多设置典型页面

##### 介绍

本示例使用[Navigation组件](reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md)，实现小窗口单栏显示、大窗口双栏显示的效果，结合[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，保证应用在不同设备或不同窗口尺寸下可以正常显示。 实现单/双栏的显示效果、 实现点击跳转或刷新、 实现多级跳转。展示设置应用的典型页面，其在小窗口和大窗口有不同的显示效果，体现一次开发、多端部署的能力。

##### 使用

1. 启动应用，查看应用在全屏状态下的显示效果。
2. 依次点击`WLAN` -> `更多WLAN设置`，查看应用的显示效果。
3. 依次点击`更多连接`->`NFC`，查看应用的显示效果。
4. 在应用顶部，下滑出现窗口操作按钮。（建议通过外接鼠标操作，接入鼠标只需要将鼠标移动至顶部即可出现窗口）
5. 点击悬浮图标，将应用悬浮在桌面上显示。
6. 拖动应用悬浮窗口改变窗口尺寸，触发应用显示刷新。改变窗口尺寸的过程中，窗口尺寸可能超出屏幕尺寸，此时在屏幕中只能看到应用部分区域的显示。可以通过移动窗口位置，查看应用其它区域的显示。
7. 重复步骤2和3，查看应用在不同窗口尺寸下的显示效果。

##### 基本原理

本示例介绍如何实现不同断点下存在单栏和双栏设计的场景，主要有以下三方面：
###### 实现单/双栏的显示效果
通过Navigation组件实现单/双栏展示，由Navbar(设置主页面)和Content(跳转子页面)两部分区域组成，Navigation组件支持Stack、Split以及Auto三种模式。    
1、stack模式：导航栏与内容区独立显示，相当于多个页面。展示效果：从Navbar(设置主页面)跳转到Content1(WLAN页面)跳转到Content2(更多WLAN模式)。  
2、Split模式：导航栏与内容区分两栏显示。展示效果：Navbar+Content1。  
3、auto模式：Navigation组件可以根据应用窗口尺寸，自动选择合适的模式：窗口宽度小于520vp时，采用Stack模式显示；窗口宽度大于等于520vp时，采用Split模式显示。当窗口尺寸发生改变时，Navigation组件也会自动在Stack模式和Split模式之间切换。

###### 实现点击跳转或刷新
Navigation组件通常搭配NavRouter组件以及NavDestination组件一起使用：
* NavRouter组件用于控制Navigation组件Content区域的显示和刷新逻辑：其必须包含两个孩子节点。  
1、容器类组件-直接控制NavRouter的显示效果。  
2、NavDestination组件：刷新Navigation组件Content区域的显示。  
3、NavRouter组件通过onStateChange回调事件，用于通知开发者NavRouter的状态：用户点击NavRouter，激活NavRouter并加载对应的NavDestination子组件时，回调onStateChange(true)；  
4、NavRouter对应的NavDestination子组件不再显示时，回调onStateChange(false)。
* NavDestination组件用于实际刷新Navigation组件Content区域的显示。
* 例如：在本示例中wlan功能项为NavRouter的第一个孩子节点，跳转的子页面WLAN为NavRouter的第二个孩子节点。

###### 实现多级跳转
Navigation组件支持自动切换单栏和双栏的显示效果，同时可以根据当前状态自动添加返回键及响应系统的返回键事件。  
1、通过激活SettingList中的WLANSettingItem，可以加载及显示WlanSetting。  
2、激活WlanSetting中的WlanMoreSettingItem，可以加载及显示WlanMoreSetting。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Settings)

#### 一多天气

##### 介绍

本示例使用[SideBarContainer](reference/apis-arkui/arkui-ts/ts-container-sidebarcontainer.md)实现侧边栏功能，[栅格容器组件](reference/apis-arkui/arkui-ts/ts-container-gridrow.md)实现界面内容的分割和展示，[Canvas组件](reference/apis-arkui/arkui-ts/ts-components-canvas-canvas.md)和[CanvasRenderingContext2D](reference/apis-arkui/arkui-ts/ts-canvasrenderingcontext2d.md) 完成空气质量和日出月落图的曲线绘制，再结合[一次开发，多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)的指导中响应式布局的栅格断点系统实现在不同尺寸窗口界面上不同的显示效果。展示一个天气应用界面，包括首页、城市管理、添加城市、更新时间弹窗，体现一次开发，多端部署的能力。

##### 使用

1.启动应用后，首页展示已添加城市的天气信息，默认展示2个城市，左右滑动可以切换城市，在LG设备上，默认显示侧边栏，侧边栏显示时，右侧内容区占2/3，侧边栏隐藏时，内容区自动铺满界面。

2.在支持窗口自由拖拽的设备上，拖拽窗口大小，可以分别实现拖动到最大窗口侧边栏显示（点击侧边栏控制按钮可以隐藏和显示侧边栏），拖动窗口缩小到MD大小时侧边栏和侧边栏控制按钮隐藏。

3.在支持窗口自由拖拽的设备上，拖拽窗口大小，天气内容区跟随窗口大小会自动换行显示。

4.点击右上角菜单按钮，在菜单中点击**更新时间**，弹出更新时间弹窗，没有功能，此处只做展示，在平板设备上显示2列，在小屏设备上显示一列。

5.点击右上角菜单按钮，在菜单中点击**管理城市**，进入管理城市界面，展示已添加的城市，在平板设备上显示2列，在小屏设备上显示一列。

6.点击管理城市界面的**添加城市**，进入添加城市界面，已添加的城市不可点击，未添加的城市点击可以添加并返回管理城市界面显示。

##### 基本原理

1、home.ets中引入SideContent()和homeContent()。  
2、定义showSideBar来判断是否展示侧边栏，定义mediaquery.MediaQueryListener媒体监听器smListener、mdListener、lgListener。  
3、在aboutToAppear调用mediaquery对界面进行监听。     
4、监听到当前屏幕大小，调用this.isBreakpoint断点，对curBp、showSideBar进行赋值。 

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Weather)

#### 一多音乐典型场景

##### 介绍

本示例使用[一次开发多端部署](https://gitcode.com/openharmony/docs/tree/master/zh-cn/application-dev/key-features/multi-device-app-dev)中介绍的自适应布局能力和响应式布局能力进行多设备（或多窗口尺寸）适配，展示了一个典型音乐场景示例。通过使用Grid组件提供窗口断点事件，保证音乐应用在不同设备或不同窗口尺寸下可以正常显示。

##### 使用

1. 打开首页，在IDE编辑器中打开预览器查看预览效果。

2. 在预览器中开启窗口拖拽模式，拖动窗口变化，可以查看组件的响应式变化。

3. 手动自由拖拽窗口，将应用窗口在sm/md/lg三种设备形态下进行切换并查看预览效果。

##### 基本原理

**标题栏**

不同容器尺寸下，元素位置不固定，采用[GridRow](reference/apis-arkui/arkui-ts/ts-container-gridrow.md)组件进行栅格布局。在sm/md断点下，标题栏所有元素占两行，在lg断点下，所有元素只占一行。

**轮播图**

使用[Swiper](reference/apis-arkui/arkui-ts/ts-container-swiper.md)组件，通过动态设置[displaycount](reference/apis-arkui/arkui-ts/ts-container-swiper.md#属性)属性，显示图片数量根据[窗口断点](reference/apis-arkui/arkui-ts/ts-container-gridrow.md#gridrowdirection枚举说明)进行自适应变化。在sm断点下显示一张图片，在md断点下显示两张图片，lg断点下通过if关键字切换成[Row](reference/apis-arkui/arkui-ts/ts-container-row.md)容器进行布局。

**音乐分类**

使用List组件的自带延伸布局能力，元素随容器组件尺寸变化显示或隐藏。

**歌单列表/我的歌单**

使用[Grid](reference/apis-arkui/arkui-ts/ts-container-grid.md)组件进行响应式布局，元素数量根据[窗口断点](reference/apis-arkui/arkui-ts/ts-container-gridrow.md#gridrowdirection枚举说明)进行自适应变化。 

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/MultiDeviceAppDev/Weather)

### 卡片

#### JS多设备自适应服务卡片

##### 介绍

本示例使用卡片扩展模块接口[@ohos.app.form.FormExtensionAbility](reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) 、卡片信息和状态等相关类型和枚举接口[@ohos.app.form.formInfo](reference/apis-form-kit/js-apis-app-form-formInfo.md) 、卡片数据绑定的能力接口[@ohos.app.form.formBindingData](reference/apis-form-kit/js-apis-app-form-formBindingData.md) 。展示Js工程中服务卡片的布局和使用，其中卡片内容显示使用了一次开发，多端部署的能力实现多设备自适应。

##### 使用

长按示例应用，等待出现服务卡片字样，点击后可左右滑动选择需要的卡片尺寸，添加到屏幕。

##### 基本原理

1、在module.json5文件添加拓展能力，类型为卡片，并设置卡片入口srcEntrance和卡片元数据metadata。例如："metadata": [
{
"name": "ohos.extension.form",
"resource": "$profile:form_config"
}。  
2、初始化卡片：通过实现@ohos.app.form.FormExtensionAbility卡片操作类，在卡片对象首次被创建时，初始化卡片绑定数据为空，并将卡片状态设置为就绪状态READY。 例如：onCreate(){
formBindingData.createFormBindingData({}) onAcquireFormState(want) {
return formInfo.FormState.READY }。   
3、配置卡片：用js编写相应的卡片，将卡片配置到resources/base/profile/form_config。 

##### 约束与限制

开发语言：JS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/AdaptiveServiceWidget)

#### ArkTS卡片

##### ArkTS卡片计算器

##### 介绍

本示例展示了使用ArkTS卡片开发的计算器模型。部分设备的桌面不支持卡片，可以通过自己的开发卡片使用方，进行卡片的创建、更新和删除等操作。

##### 使用

1.部分设备的桌面不支持卡片，可以通过自己的开发卡片使用方，进行卡片的创建、更新和删除等操作。

##### 基本原理

不涉及

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/Calculator)

##### ArkTS卡片Canvas小游戏

##### 介绍

本示例展示了如何通过ArkTS卡片的Canvas自定义绘制能力实现一个简单的五子棋游戏卡片。

- 使用Canvas绘制棋盘和黑白棋子的落子。
- 通过卡片支持的[点击事件](reference/apis-arkui/arkui-ts/ts-universal-events-click.md)进行交互，让用户在棋盘上进行黑白棋子的对局。
- 通过TS的逻辑代码实现五子棋输赢判定、回退等逻辑计算，整个游戏过程无需拉起FormExtensionAbility。

##### 使用

1.部分设备的桌面不支持卡片，可以通过自己开发的卡片使用方，进行卡片的创建、更新和删除等操作。

2.安装应用，并在桌面上长按本应用的桌面图标，长按后弹出选项列表。

3.点击弹出列表中的**服务卡片**选项进入卡片预览界面。

4.点击正下方的**添加到桌面**按钮，卡片就会出现在桌面上。

5.卡片添加到桌面后就可以在桌面进行五子棋游戏，包含黑白棋子的落子、重新开始、悔棋等操作。

##### 基本原理

- 界面绘制：通过Canvas画布组件进行绘制，在Canvas组件收到onReady回调时取出context的width和height作为画布的大小。
- 逻辑处理：通过注册Canvas画布onClick点击事件，并取出回调中的ClickEvent入参，这个对象中包含了点击的x轴和y轴坐标，通过坐标信息进行点击位子匹配就可以实现黑白棋子的落子。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/CanvasGame)

##### ArkTS音乐卡片

##### 介绍

本示例展示了如何通过ArkTS卡片实现一个简单的音乐卡片。

##### 使用

1.安装应用，并在桌面上长按本应用的桌面图标，长按后弹出选项列表。

2.点击弹出列表中的服务卡片选项进入卡片添加界面。

3.点击正下方的添加到桌面按钮，卡片就会出现在桌面上。

##### 基本原理

不涉及。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/ArkTSCard/MusicControl)

#### Stage模型卡片

##### 介绍

本示例使用卡片扩展模块接口[@ohos.app.form.FormExtensionAbility](reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) 、卡片信息和状态等相关类型和枚举接口[@ohos.app.form.formInfo](reference/apis-form-kit/js-apis-app-form-formInfo.md) 、卡片提供方相关接口的能力接口[@ohos.app.form.formProvider](reference/apis-form-kit/js-apis-app-form-formProvider.md) 、应用组件间的信息传递接口[@ohos.app.ability.Want](reference/apis-ability-kit/js-apis-app-ability-want.md) 。展示了Stage模型卡片提供方的创建与使用。

##### 使用

1.部分设备的桌面不支持卡片，可以通过自己的开发卡片使用方，进行卡片的创建、更新和删除等操作。

2.卡片的样式如"添加卡片"所示。当卡片更新时，卡片上的温度和时间会产生变化。

3.安装[卡片应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Widget/FormExtAbility/processProxyForm)或[formProvider应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Widget/FormExtAbility/persistentProxyForm)，长按卡片应用图标或formProvider应用图标弹出菜单，点击"服务卡片"选项可以添加服务卡片至桌面（第3张，第4张卡片为formProvider应用卡片；第5张，第6张为卡片应用卡片）；

4.长按数据卡片弹出菜单，点击"移除"可以将已添加至桌面的数据卡片从桌面上移除；

5.点击打开卡片应用图标或formProvider应用图标，点击"修改订阅条件"按键，界面将跳转至修改订阅条件界面，对应选择想要发布的数据完成对订阅条件的修改，离开页面或退出应用后再次打开修改订阅条件页面，页面单选框会显示当前订阅的城市；

6.在卡片应用或formProvider应用应用中点击"发布数据"按键，界面将跳转至数据发布界面，对应选择想要发布的数据并点击"发布数据"完成数据发布(若选择发布的城市与当前订阅城市不一致，则不能将数据更新至卡片)；

##### 基本原理
1、在module.json5文件添加拓展能力，类型为卡片，并设置卡片入口srcEntrance和卡片元数据metadata。
2、初始化卡片：通过实现@ohos.app.form.FormExtensionAbility卡片操作类，在卡片对象首次被创建时，初始化卡片绑定数据为空，并将卡片状态设置为就绪状态READY。
3、配置卡片：用js编写相应的卡片，将卡片配置到resources/base/profile/form_config。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.7

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Widget/FormExtAbility)

#### Stage模型卡片小游戏

##### 介绍

本示例展示了如何通过Stage模型实现一个简单的游戏卡片。

- 通过卡片支持的[点击事件](reference/apis-arkui/js-service-widget-ui/js-service-widget-common-events.md)进行交互，让用户通过点击的先后顺序把一个乱序的成语排列成正确的成语。
- 使用了C++和TS的混合编程方式，将获取随机数的能力下沉到C++实现，并通过[NAPI](napi/napi-guidelines.md)的能力将C++实现的能力暴露到TS中。
- 用到了卡片扩展模块接口，[@ohos.app.form.FormExtensionAbility](reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) 。

##### 使用

1.部分设备的桌面不支持卡片，可以通过自己的开发卡片使用方，进行卡片的创建、更新和删除等操作。

2.安装应用，并在桌面上长按本应用的桌面图标，长按后弹出选项列表。

3.点击弹出列表中的**服务卡片**选项进入卡片添加界面。

4.点击正下方的**添加到桌面**按钮，卡片就会出现在桌面上。

##### 基本原理

1、在module.json5文件添加拓展能力，类型为卡片，并设置卡片入口srcEntrance和卡片元数据metadata。 
2、配置卡片：用js编写相应的卡片，将卡片配置到resources/base/profile/form_config。  
3、定义小游戏逻辑：实现FormExtensionAbility中addform时初始化数据(本sample中使用的是mock数据)，并将数据存储到dataStore，通过调用c++随机数，将成语顺序打乱显示，
4、监听卡片变化：通过onformEvent()监听卡片事件，更新已选择的成语数据，并随机替换成语待选列表的已被选掉的word。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/FormGame)

#### 应用主动添加数据代理卡片到桌面

##### 介绍

本示例主要展示了使用[@ohos.app.form.formBindingData](reference/apis-form-kit/js-apis-app-form-formBindingData.md)、[@ohos.app.form.formProvider](reference/apis-form-kit/js-apis-app-form-formProvider.md)等接口，实现了在com.ohos.hag.famanager应用上，主动添加数据代理卡片到桌面的功能。

##### 使用

1. 点击桌面上AppStore应用图标，打开com.ohos.hag.famanager应用。

2. 点击按钮<添加ArkTs卡片到桌面>或<添加Js卡片到桌面>按钮，AppStore应用自动切到后台并且开始将数据代理卡片添加到桌面。

3. 桌面切到前台显示后，刷新组件并将添加的数据代理卡片显示到页面上。

##### 基本原理

- 发布ArkTs数据代理卡片到桌面
  - 使用requestPublishForm接口，将应用内的ArkTs数据代理卡片主动添加到桌面上，接口参考：[@ohos.app.form.formProvider](reference/apis-form-kit/js-apis-app-form-formProvider.md)
- 发布Js数据代理卡片到桌面
  - 使用requestPublishForm接口，将应用内的Js数据代理卡片主动添加到桌面上，接口参考：[@ohos.app.form.formProvider](reference/apis-form-kit/js-apis-app-form-formProvider.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.8.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Widget/RequestAddForm)



## 系统特性

### 应用模型

#### EnterpriseAdminExtensionAbility的创建与使用

##### 介绍

本示例通过[@ohos.enterprise.EnterpriseAdminExtensionAbility](reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)接口实现了系统管理状态变化通知功能，[@ohos.enterprise.adminManager](reference/apis-mdm-kit/js-apis-enterprise-adminManager-sys.md)接口中enableAdmin方法去激活当前用户下的指定设备管理员应用，disableSuperAdmin方法去根据bundleName将管理员用户下的超级管理员应用去激活，subscribeManagedEvent方法去指定设备管理员应用订阅系统管理事件，unsubscribeManagedEvent方法去指定设备管理员应用取消订阅系统管理事件来实现应用激活、去激活、应用安装、卸载事件。

##### 使用

1.启动应用后，点击激活设备管理器，会显示激活成功。由企业管理员或者员工部署MDM应用，激活设备管理器，系统通知MDM应用已激活DeviceAdmin权限。MDM应用可在onAdminEnable回调函数中进行初始化策略设置。

2.点击去激活设备管理器，会显示去激活成功。系统或者员工去激活设备管理器，应用可以通知企业管理员设备已脱管。

3.点击订阅应用安装卸载事件，会显示订阅成功。企业应用管理场景下，企业管理员订阅应用安装卸载事件，端侧应用安装和卸载事件通知MDM应用，MDM应用可以在回调函数中进行事件上报，通知企业管理员。

4.点击取消订阅应用安装卸载事件，会显示取消订阅成功。企业应用管理场景下，企业管理员取消订阅应用安装卸载事件。

##### 基本原理

* 该示例通过EnterpriseAdminExtensionAbility接口实现了系统管理状态变化通知功能，adminManager接口中enableAdmin方法去激活当前用户下的指定设备管理员应用，disableSuperAdmin方法去根据bundleName将管理员用户下的超级管理员应用去激活，subscribeManagedEvent方法去指定设备管理员应用订阅系统管理事件，unsubscribeManagedEvent方法去指定设备管理员应用取消订阅系统管理事件来实现应用激活、去激活、应用安装、卸载事件。
* 接口参考：[@ohos.enterprise.EnterpriseAdminExtensionAbility](reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)，[@ohos.enterprise.adminManager](reference/apis-mdm-kit/js-apis-enterprise-adminManager-sys.md)，[@ohos.app.ability.Want](reference/apis-ability-kit/js-apis-app-ability-want.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/EnterpriseAdminExtensionAbility)

#### 仿桌面应用

##### 介绍

本示例使用[@ohos.bundle.launcherBundleManager](reference/apis-ability-kit/js-apis-launcherBundleManager-sys.md)模块接口，获取所有应用信息和给定包名获取应用信息，实现桌面展示所有安装的应用。使用[@ohos.bundle](reference/apis-ability-kit/js-apis-Bundle-sys.md)的getBundleInstaller接口获取到，调用uninstall接口实现应用卸载功能。使用[@ohos.app.form.formHost](reference/apis-form-kit/js-apis-app-form-formHost-sys.md)接口，获取应用卡片信息，使用FormComponent组件展示卡片内容，从而实现添加卡片到桌面的功能。使用关系型数据库[@ohos.data.relationalStore](reference/apis-arkdata/arkts-apis-data-relationalStore.md)接口，实现桌面数据持久化存储，存储应用的位置信息，卡片信息。使用[@ohos.application.missionManager](reference/apis-ability-kit/js-apis-application-missionManager-sys.md)接口，获取最近任务信息，并实现加锁、解锁、清理后台任务的功能。使用[@ohos.app.ability.ServiceExtensionAbility](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)的startRecentAbility接口，拉起最近任务至前台显示，若应用Ability未启动时，则拉起新创建的应用Ability显示到前台。实现了一个简单桌面应用，概括为以下几点：

1.展示了系统安装的应用，实现点击启动、应用上滑弹出卡片、卡片添加到桌面、卡片移除功能。

2.实现桌面数据持久化存储，应用支持卸载、监听应用卸载和安装并显示。

3.实现最近任务管理功能，包括任务卡片加锁、解锁、清理和清理所有任务功能。

4.通过点击应用图标或点击由长按图标弹出的菜单栏中的打开按钮的方式打开应用，是以打开最近任务方式拉起应用Ability。

##### 使用

1.安装编译的hap包，使用hdc shell aa start -b ohos.samples.launcher -a MainAbility命令启动应用，应用启动后显示系统安装的应用。

2.点击应用主界面上的应用图标可以启动应用，长按弹出菜单，点击打开可以正常启动应用。

3.图库等支持卡片的应用，长按菜单中有服务卡片，点击进入卡片预览界面，在卡片预览界面点击**添加到桌面**，返回到桌面并且卡片成功添加到桌面。

4.上滑图库等支持卡片的应用，可以弹出默认上滑卡片，点击上滑卡片右上角的**+**图标，可以添加卡片到桌面。

5.应用在桌面界面，使用hdc install安装一个应用，桌面可以监听到应用安装，并显示新安装的应用到桌面上。

6.应用在桌面界面，使用hdc uninstall 卸载第5步安装的应用，桌面可以监听到卸载，并移除桌面上的应用。

7.在桌面空白处上滑，可以进入最近任务管理界面，下滑任务卡片可以加锁/解锁，上滑卡片可以清理该后台任务，点击垃圾桶可以清除所有后台任务（加锁的应用不会被清理掉）。

##### 基本原理

* 获取应用功能模块
  * 使用launcherBundleManager模块接口（系统能力：SystemCapability.BundleManager.BundleFramework），获取所有应用信息和给定包名获取应用信息，实现桌面展示所有安装的应用。使用on接口监听应用的安装和卸载从而实现应用安装和卸载刷新桌面。
  * 接口参考：[@ohos.bundle.launcherBundleManager](reference/apis-ability-kit/js-apis-launcherBundleManager-sys.md)

* 应用卸载功能模块
  * 使用bundle模块的getBundleInstaller接口获取到BundleInstaller（系统能力：SystemCapability.BundleManager.BundleFramework），调用uninstall接口实现应用卸载功能。
  * 接口参考：[@ohos.bundle](reference/apis-ability-kit/js-apis-Bundle-sys.md)
  
* 添加卡片功能模块
  * 使用formHost接口（系统能力：SystemCapability.Ability.Form），获取应用卡片信息，使用FormComponent组件展示卡片内容，从而实现添加卡片到桌面的功能。
  * 接口参考：[@ohos.app.form.formHost](reference/apis-form-kit/js-apis-app-form-formHost-sys.md)

* 桌面数据持久化存储功能模块
  * 使用关系型数据库rdb接口（系统能力：SystemCapability.DistributedDataManager.RelationalStore.Core），实现桌面数据持久化存储，存储应用的位置信息，卡片信息。
  * 接口参考：[@ohos.data.relationalStore](reference/apis-arkdata/arkts-apis-data-relationalStore.md)

* 加锁、解锁、清理后台任务功能模块
  * 使用missionManager模块接口（系统能力：SystemCapability.Ability.AbilityRuntime.Mission），获取最近任务信息，并实现加锁、解锁、清理后台任务的功能。
  * 接口参考：[@ohos.application.missionManager](reference/apis-ability-kit/js-apis-application-missionManager-sys.md)

* 点击桌面应用拉起最近任务至前台功能模块
  * 使用ServiceExtensionContext模块的startRecentAbility接口（系统能力：SystemCapability.Ability.AbilityRuntime.Core），拉起最近任务至前台显示，若应用Ability未启动时，则拉起新创建的应用Ability显示到前台。
  * 接口参考：[@ohos.app.ability.ServiceExtensionAbility](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/Launcher)

#### 系统任务管理

##### 介绍

本示例通过调用系统任务管理的能力，使用[@ohos.application.missionManager](reference/apis-ability-kit/js-apis-application-missionManager-sys.md) 、[@ohos.multimedia.image](reference/apis-image-kit/arkts-apis-image.md) 等接口完成对系统任务执行锁定、解锁、清理、切换到前台等操作。

##### 使用

1.下拉“**获取系统任务信息**”，获取当前系统任务的包名、运行状态、锁定状态、任务是否支持迁移、任务快照等信息列表，且最多可获取10条任务；

2.左滑任务列表，点击“**锁定**”，即可锁定指定的任务；

3.若当前任务已锁定，可点击“**解锁**”，即可解锁指定的任务；

4.点击“**删除**”，即可删除指定的任务；

5.点击“**移动**”，即可将指定的任务移动到前台执行。

##### 基本原理

* 任务执行锁定、解锁、清理、切换到前台等操作的功能结构主要封装在Index、MissionInfoComponent
    * 获取任务信息：在Index页面中通过missionManager.getMissionInfos()方法来获取所有的mission；
    * 执行或者解锁锁定任务：在MissionInfoComponent组件当中可以通过missionManager.lockMission(missionId)方法来锁定指定的mission，而missionManager.unlockMission(missionId)用来解锁mission;
    * 移动指定的任务：将指定的任务移动到前台执行可以使用missionManager.moveMissionToFront(missionId)方法；
    * 删除指定的任务：删除指定的任务可以通过missionManager.clearMission(missionId)方法实现。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/MissionManager)

#### 静态订阅

##### 介绍

本示例主要展示了静态订阅的创建与使用，以及静态订阅的使能和去使能。通过[CommonEventManager](reference/apis-basic-services-kit/js-apis-commonEventManager.md)发布自定义事件，使能和去使能静态订阅。通过[StaticSubscriberExtensionAbility](reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)、[NotificationManager](reference/apis-notification-kit/js-apis-notificationManager.md)静态订阅已发布的自定义事件，订阅后即可自动收到该事件，收到该事件后，发送通知将自定义事件数据显示在通知栏。

##### 使用

1. 在entry/src/main/resources/base/profile/subscribe.json中添加需要订阅的目标事件。

2. 修改系统配置文件/system/etc/app/install_list_capability.json，将应用的包名添加至该json文件中。

3. 本示例编译后共有两个hap包，包括静态订阅hap包和自定义事件发布hap包，需要全部安装。静态订阅hap包需要签名成系统应用并安装才可实现对目标事件的静态订阅，安装后即默认订阅了目标事件；自定义事件发布hap包直接安装即可，发布事件后即可被静态订阅方收到。

4. 点击关闭静态订阅按钮将不再进行静态订阅，不会收到相关通知，点击开启静态订阅会重新恢复。

##### 基本原理

* 通过CommonEventManager.publish方法发布自定义事件，该自定义事件为数据传输事件。

* 接口参考：[@ohos.commonEventManager](reference/apis-basic-services-kit/js-apis-commonEventManager.md)

* 通过CommonEventManager.setStaticSubscriberState方法为当前应用设置静态订阅事件使能或去使能状态。

* 接口参考：[@ohos.commonEventManager](reference/apis-basic-services-kit/js-apis-commonEventManager.md)

* 通过StaticSubscriberExtensionAbility接口静态订阅已发布的自定义事件，订阅后即可自动收到该事件，收到该事件后，setNotificationEnable，ContentType方法发送通知将自定义事件数据显示在通知栏。

* 接口参考：[@ohos.application.StaticSubscriberExtensionAbility](reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)，[@ohos.notificationManager](reference/apis-notification-kit/js-apis-notificationManager.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/StaticSubscriber)

#### 测试依赖

##### 跨任务链返回

##### 介绍

本示例为一个仿桌面应用测试demo，使用[@ohos.app.ability.ServiceExtensionAbility](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)接口中ServiceExtensionContext类的startRecentAbility能力（系统能力：SystemCapability.Ability.AbilityRuntime.Core），实现了跨任务链返回的功能。

##### 使用

1.基于CrossChainBack工程（com.acts.abilityabacktoabilityb），对该工程编译产生的hap包进行手动签名。（仅CrossChainBack工程可实现跨任务链返回功能）。

2.安装签名成功后的hap包，启动仿桌面（Launcher）。

3.点击应用主界面上的应用图标，可以启动应用。

4.长按应用图标弹出菜单，点击打开，可以正常启动应用。

5.本应用包含：EntryAbility页面（页面中显示有"EntryAbility"文本）和SecondAbility页面（页面中显示有"SecondAbility"文本）。

6.在EntryAbility页面上点击StartSecondAbility按钮，打开SecondAbility，此时点击返回键，回到EntryAbility页面而不是桌面。

##### 基本原理

- 拉起任务至前台显示的功能接口封装在LauncherAbilityManager。
  - 跨任务链返回：在ServiceExtensionAbility，使用ServiceExtensionContext.startRecentAbility(),将Want中将"ABILITY_BACK_TO_OTHER_MISSION_STACK"(返回当前任务链字段)设置为"true",以实现返回至打开ServiceExtensionAbility的ability的功能。
  - 接口参考：[@ohos.app.ability.wantConstant](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.wantConstant.d.ts)、[@ohos.app.ability.ServiceExtensionAbility](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.app.ability.ServiceExtensionAbility.d.ts)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/TestRely/LauncherTest/CrossChainBack)

##### 启动上一次的组件实例

##### 介绍

本示例为一个仿桌面应用测试demo，测试的功能为：点击仿桌面应用上的应用图标，若应用未启动则启动应用，若应用已经被启动并创建多个实例则启动上一次拉起的实例。

##### 使用

1.基于StartRecentAbility工程（com.acts.startrecentability），对该工程编译产生的hap包进行手动签名。（仅StartRecentAbility工程可实现启动上一次的组件实例功能）。

2.安装签名成功后的hap包，启动仿桌面（Launcher）。

3.点击应用主界面上的应用图标，可以启动应用。

4.长按应用图标弹出菜单，点击打开，可以正常启动应用。

5.打开EntryAbility页面，页面中会有时间戳显示，点击"StartEntryAbility"按钮，新建一个EntryAbility实例，会有一个新的时间戳显示，此时点击home键回到桌面，点击应用图标打开应用，会看到时间戳显示为第二个时间戳。

6.打开EntryAbility页面，会有时间戳显示，点击"startSingletonAbility"按钮，打开单实例的SecondAbility（页面中显示"SingletonAbility"），当打开SecondAbility后，点击home键回到桌面，点击应用图标打开应用，显示为EntryAbility且时间戳内容未改变。

##### 基本原理

- 应用启动的功能接口封装在LauncherAbilityManager：
  - 启动上次打开的的组件实例：拉起上次打开的任务至前台显示，若应用Ability未启动时，则拉起新创建的应用Ability显示到前台。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/ApplicationModels/TestRely/LauncherTest/StartRecentAbility)

### 网络与连接

#### 蓝牙

##### 介绍

本示例通过[@ohos.bluetooth](reference/apis-connectivity-kit/js-apis-bluetooth.md) 接口实现蓝牙设备发现、配对、取消配对功能。

##### 使用

1.启动应用，若蓝牙本来就打开的，系统会直接搜索周围可配对的设备，若蓝牙未打开，打开开关。

2.搜索到附近的设备后，选择需要配对的设备，点击该设备，会跳出匹配弹窗，若确定匹配，点击**匹配**按钮，否则点击**取消**按钮。

3.匹配后，若想删除匹配的设备，点击已配对的设备列表中的设备，会跳出断开连接弹窗，若确定删除该设备，点击**确定**，否则点击**取消**。

##### 基本原理

* 蓝牙设备发现、配对、取消配对等操作的功能结构主要封装在Index、PinDialog：
    * 启动和关闭蓝牙：在Index页面中通过Toggle组件的onChange函数来控制蓝牙的开关，开关打开的情况下会执行initBluetooth函数，关闭的情况下执行bluetooth.disableBluetooth()方法来断开蓝牙；
    * 验证蓝牙是否处于连接状态：蓝牙打开的时候通过bluetooth.on('stateChange')方法来监听蓝牙连接状态改变事件，确认已打开，则执行foundDevices()函数来查找设备接口，确认已关闭则执行bluetooth.stopBluetoothDiscovery()方法来停止查询接口。
    * 发现设备：在foundDevices()函数中通过bluetooth.on('bluetoothDeviceFind')方法来监听设备发现事件，并且通过bluetooth.getPairedDevices()方法来更新已配对蓝牙地址，然后通过bluetooth.startBluetoothDiscovery()方法开启蓝牙扫描，去发现远端设备，并且通过bluetooth.setBluetoothScanMode()方法来被远端设备发现。
    * 蓝牙配对：通过bluetooth.on('pinRequired')方法来监听远端蓝牙设备的配对请求事件，点击配对执行bluetooth.setDevicePairingConfirmation(this.data.deviceId, true)方法，点击取消执行bluetooth.setDevicePairingConfirmation(this.data.deviceId, false)方法。
    * 取消配对：最后通过bluetooth.cancelPairedDevice()来断开指定的远端设备连接。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.12.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Connectivity/Bluetooth)

#### WLAN

##### 介绍

本示例通过[@ohos.wifiManager](reference/apis-connectivity-kit/js-apis-wifiManager-sys.md) 相关API实现wlan激活和关闭、扫描和连接WIFI等功能。

##### 使用

1. 启动应用后会判断WLAN是否激活，如果是激活状态，会扫描并展示可用WiFi列表，同时获取已连接WiFi信息并展示；

2. 点击界面的Switch开关可以禁用和激活WLAN，界面会监听WLAN状态扫描可用WiFi列表，也会监听WiFi连接状态展示已连接WiFi；

3. 点击可用WLAN列表中的WLAN信息，可以连接WiFi，如果是加密类型，会弹窗输入密码后连接；

4. 点击首页右上角的**关于**图标，进入关于界面，展示获取的IP信息、国家码和支持WLAN相关特性信息。

##### 基本原理

* wlan激活和关闭功能：点击首页的切换按钮，如果是打开，使用wifi.enableWifi()开启wifi；如果是关闭，则使用wifi.disconnect()断开wifi，然后使用wifi.disableWifi()关闭wifi，

* wifi的连接、扫描、获取详细信息等功能封装在WifiModel模块中。
  * wifi的连接功能：点击wifi列表中加密的wifi，并在弹窗中输入密码后，通过WifiModule.connectNetwork()调用wifi.connectToDevice()连接wifi。
  * wifi的扫描功能：进入后就会间歇性的调用wifi.scan()开启扫描，然后通过WifiModel模块中的getScanInfos()调用wifi.getScanResults()来获取扫描的结果。
  * 获取wifi的详细信息：通过WiFiModel中的getIpInfo()、getCountryCode()、getFeatureSupport()分别调用wifi.getIpInfo()、wifi.getCountryCode()、wifi.isFeatureSupported()来获取对应信息。

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Connectivity/Wlan)

### 数据管理

#### 跨应用数据共享

##### 介绍

本示例使用数据共享扩展能力[@ohos.data.DataShareResultSet](reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)，关系型数据库[@ohos.data.relationalStore](reference/apis-arkdata/js-apis-data-dataShare-sys.md)，[@ohos.data.rdb](reference/apis-arkdata/js-apis-data-rdb.md)实现了一个跨应用数据共享实例，分为联系人（数据提供方）和联系人助手（数据使用方）两部分：联系人支持联系人数据的增、删、改、查等功能；联系人助手支持同步联系人数据，当联系人与联系人助手数据不一致时，支持合并重复数据。

##### 使用

1. 联系人应用，首页中点击**+**按钮可以添加联系人，在首页展示联系人列表。
2. 联系人应用首页点击搜索框可以搜索联系人，点击联系人进入详情页，详情页提供编辑和删除功能入口。
3. 联系人助手应用，点击同步联系人可以同步联系人应用的数据到联系人助手，同步后可以点击联系人进入详情页，详情页提供编辑和删除功能。
4. 联系人助手首页点击**+**按钮，可以新增联系人。
5. 联系人助手设置页面可以设置同步策略，根据不同的同步策略，每次点击首页的同步联系人按钮会同步一次联系人数据，默认使用联系人覆盖联系人助手策略。

##### 基本原理

* 使用DataShareExtensionAbility实现数据共享，关系型数据库实现数据的增、删、改、查接口，DataShare管理和访问数据库数据变化。
* 接口参考：[@ohos.data.DataShareResultSet](reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)，[@ohos.data.relationalStore](reference/apis-arkdata/js-apis-data-dataShare-sys.md)，[@ohos.data.rdb](reference/apis-arkdata/js-apis-data-rdb.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DataManagement/CrossAppDataShare)

### 设备管理

#### 设备管理合集(系统特性)

##### 介绍

本示例集合设备管理相关(系统特性)不需要复杂功能展示的模块，展示了各个模块的基础功能，包含：

- [@ohos.batteryStatistics (耗电统计)](reference/apis-basic-services-kit/js-apis-batteryStatistics-sys.md)
- [@ohos.brightness (屏幕亮度)](reference/apis-basic-services-kit/js-apis-brightness-sys.md)
- [@ohos.power (系统电源管理)](reference/apis-basic-services-kit/js-apis-power-sys.md)
- [@ohos.settings (设置数据项名称)](reference/apis-basic-services-kit/js-apis-settings.md)
- [@ohos.systemCapability (系统能力)](reference/apis-basic-services-kit/js-apis-system-capability-sys.md)
- [@ohos.systemParameterEnhance (系统参数)](reference/apis-basic-services-kit/js-apis-system-parameterEnhance-sys.md)
- [@ohos.batteryInfo (电量信息)](reference/apis-basic-services-kit/js-apis-battery-info-sys.md)
- [@ohos.deviceInfo (设备信息)](reference/apis-basic-services-kit/js-apis-device-info.md)
- [@ohos.multimodalInput.inputConsumer (组合按键)](reference/apis-input-kit/js-apis-inputconsumer-sys.md)
- [@ohos.multimodalInput.inputDevice (输入设备)](reference/apis-input-kit/js-apis-inputdevice.md)
- [@ohos.multimodalInput.inputEvent (输入事件)](reference/apis-input-kit/js-apis-inputevent.md)
- [@ohos.multimodalInput.inputEventClient (按键注入)](reference/apis-input-kit/js-apis-inputeventclient-sys.md)
- [@ohos.multimodalInput.inputMonitor (输入监听)](reference/apis-input-kit/js-apis-inputmonitor-sys.md)
- [@ohos.multimodalInput.keyCode (键值)](reference/apis-input-kit/js-apis-keycode.md)
- [@ohos.multimodalInput.keyEvent (按键输入事件)](reference/apis-input-kit/js-apis-keyevent.md)
- [@ohos.multimodalInput.mouseEvent (鼠标输入事件)](reference/apis-input-kit/js-apis-mouseevent.md)
- [@ohos.multimodalInput.pointer (鼠标指针)](reference/apis-input-kit/js-apis-pointer.md)
- [@ohos.multimodalInput.touchEvent (触摸输入事件)](reference/apis-input-kit/js-apis-touchevent.md)

##### 使用

1.首页展示语言基础类库各个子模块菜单，点击进入对应的模块页面。

2.各个子模块界面中点击功能按钮完成各个功能。

3.耗电统计：进入耗电统计页面，展示软硬件耗电排行。

4.屏幕亮度：获取当前屏幕亮度，设置屏幕亮度。

5.系统电源管理：点击按钮分别实现休眠、关机、重启、设置电源模式功能。

6.设置数据项名称：将数据项名称及数据项的值保存到数据库中。

7.系统能力：获取系统能力集合的字符串并显示。

8.系统参数：点击按钮分别实现设置一个系统参数、获取并展示系统参数功能。

9.电量信息：进入设备电量信息页面，页面主要显示电量信息，包括：当前设备是否支持电池或电池是否在位的查询、剩余电池电量百分比、充电状态、电池健康状态、充电器类型、电池电压、电池技术型号、电池温度、电量等级等信息。

10.设备基础信息：打开设备信息管理页面，展示基础信息。

11.组合按键：进入组合按键管理页面，包括显示组合按键信息，组合按键的订阅状态，在订阅状态下，组合按键被触发时显示组合按键的信息。

12.输入设备：进入设备输入管理页面，展示设备输入列表，可以查看输入设备详情，同时可以监听设备的热插拔状态。

13.输入事件：进入全屏监听页面，实现启动或取消全屏输入事件，在启动全屏输入事件监听时，可以查看当前触屏的详细信息，模拟注入返回事件，实现返回能力。

14.输入按键事件：进入输入按键事件管理页面，显示由外部设备如软键盘输入触发的消息。

15.鼠标指针：进入鼠标管理页面，实现鼠标状态、鼠标指针信息、设置鼠标速度和显示样式，启动鼠标事件监听时，可以查看鼠标在界面上操作的详细信息。

##### 基本原理

1.首页菜单展示：使用一个module，menuitems完成菜单组件的实现，传入要展示的菜单的strarray类型的资源和菜单点击对应的组件即可。使用Navigation和NavRouter组件实现菜单点击进入功能界面，使用LocalStorage实现应用内Ability内数据共享，点击菜单时标记selectedLabel，在entry中的Capabilities组件中，通过selectedLabel显示对应的功能组件。

2.耗电统计：使用[@ohos.batteryStatistics.d.ts](reference/apis-basic-services-kit/js-apis-batteryStatistics-sys.md)
接口获取硬件和应用的耗电量与百分比，使用[@ohos.bundle.bundleManager.d.ts](reference/apis-ability-kit/js-apis-bundleManager.md)
接口获取系统已安装应用信息。

3.屏幕亮度：使用[@ohos.brightness.d.ts](reference/apis-basic-services-kit/js-apis-brightness-sys.md)
实现屏幕亮度控制。

4.系统电源管理：使用[@ohos.power.d.ts](reference/apis-basic-services-kit/js-apis-power-sys.md)
实现休眠、关机、重启、设置电源模式功能。

5.设置数据项名称：使用[@ohos.settings.d.ts](reference/apis-basic-services-kit/js-apis-settings.md)
实现将数据项名称及数据项的值保存到数据库中。

6.系统能力：使用[@ohos.systemCapability.d.ts](reference/apis-basic-services-kit/js-apis-system-capability-sys.md)
实现获取系统能力集合的字符串并显示。

7.系统参数：使用[@ohos.systemParameterEnhance.d.ts](reference/apis-basic-services-kit/js-apis-system-parameterEnhance-sys.md)
实现设置一个系统参数、获取并展示系统参数功能。

8.电量信息：使用[@ohos.batteryInfo.d.ts](reference/apis-basic-services-kit/js-apis-battery-info-sys.md)接口获取电池和充放电状态信息

9.设备信息：使用[@ohos.deviceInfo](reference/apis-basic-services-kit/js-apis-device-info.md)获取设备相关信息。

10.组合按键：使用[@ohos.multimodalInput.inputConsumer](reference/apis-input-kit/js-apis-inputconsumer-sys.md) 订阅组合按键，当组合按键被触发时展示组合按键回调信息。

11.输入设备：使用[@ohos.multimodalInput.inputDevice](reference/apis-input-kit/js-apis-inputdevice.md) 获取输入设备列表，并显示输入设备信息，实现设备的热插拔监听。

12.输入事件：使用[@ohos.multimodalInput.inputMonitor](reference/apis-input-kit/js-apis-inputmonitor-sys.md)开启监听全局触屏事件，当触发触屏事件时显示触屏详情，使用[@ohos.multimodalInput.inputEventClient](reference/apis-input-kit/js-apis-inputeventclient-sys.md)模拟返回按键进行按键注入，实现返回功能，在column组件中添加[@ohos.multimodalInput.touchEvent](reference/apis-input-kit/js-apis-touchevent.md)触摸事件，模拟按键被按下效果。

13.鼠标指针：使用[@ohos.multimodalInput.mouseEvent](reference/apis-input-kit/js-apis-mouseevent.md)监听鼠标事件，并显示鼠标操作回调信息，使用[@ohos.multimodalInput.pointer](reference/apis-input-kit/js-apis-pointer.md)实现鼠标指针的显示或隐藏状态，设置鼠标移动速度和显示样式。

14.输入按键事件：使用 [@ohos.multimodalInput.keyEvent (按键输入事件)](reference/apis-input-kit/js-apis-keyevent.md)监听按键输入的信息。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/DeviceManagementCollection)

#### 屏幕属性

##### 介绍

本示例主要展示了屏幕管理相关的功能，使用[@ohos.display](reference/apis-arkui/js-apis-display.md)、[@ohos.screen](reference/apis-arkui/js-apis-screen-sys.md)接口，[@ohos.display](reference/apis-arkui/js-apis-display.md)接口提供获取默认display对象、获取所有display对象，开启监听、关闭监听功能；[@ohos.screen](reference/apis-arkui/js-apis-screen-sys.md)接口提供创建虚拟屏幕、销毁虚拟屏幕、扩展屏幕、镜像屏幕等功能。

##### 使用

1.点击主页面前一个矩形，弹窗显示默认设备ID、设备名称、启用状态、设备状态、设备刷新率、屏幕旋转角度、设备宽度、设备高度、屏幕密度、屏幕方向、逻辑密度、缩放因子、xDPI(x方向中每英寸屏幕的确切物理像素值)、yDPI(y方向中每英寸屏幕的确切物理像素值)，点击任意区域关闭弹窗，点击第二个矩形，弹窗显示所有屏幕信息。

2.点击**增加屏幕**按钮，监听到屏幕增加，增加矩形代表新增屏幕（因界面空间有效，增加超过一个屏幕，页面总共只显示两个矩形）。

3.点击**移除屏幕**按钮，监听到屏幕销毁，减少矩形代表移除屏幕。

##### 基本原理

- 增加屏幕、移除屏幕的功能接口封装在DisplayModel:
  - 使用screen.createVirtualScreen来创建虚拟屏幕;
  - 使用screen.destroyVirtualScreen来销毁虚拟屏幕;
- 获取Display对象显示屏幕所有属性信息的功能封装在ShowInfo:
  - 使用display.Display来显示默认屏幕信息;
  - 使用display.Display[]来显示所有屏幕信息;；

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/Screen)

#### 存储空间统计

##### 介绍

本示例使用[DataPanel组件](reference/apis-arkui/arkui-ts/ts-basic-components-datapanel.md)展示不同种类的应用存储信息，通过[@ohos.bundle.bundleManager](reference/apis-ability-kit/js-apis-Bundle-sys.md)模块来获取不同应用的包名与应用名等信息，使用应用空间统计[@ohos.file.storageStatistics](reference/apis-core-file-kit/js-apis-file-storage-statistics.md)来查询当前设备的存储使用情况，使用卷管理[@ohos.file.volumeManager](reference/apis-core-file-kit/js-apis-file-volumemanager-sys.md)来查询可用卷存储使用情况。实现了查看当前设备存储空间信息、所有安装的应用的存储信息、所有可用卷的存储信息的功能。

##### 使用

1. 主页面会展示当前设备存储使用的详细信息。

2. 点击“应用”，可以查看当前安装的所有应用的存储使用情况。

3. 当有可用的卷时，点击“查看可用卷信息”查看当前设备所有的可用卷的存储使用情况。

##### 基本原理

* 本示例使用DataPanel组件展示不同种类的应用存储信息，通过 Bundle模块来获取不同应用的包名与应用名等信息，使用应用空间统计来查询当前设备的存储使用情况，使用卷管理来查询可用卷存储使用情况。
* 接口参考：[DataPanel组件](reference/apis-arkui/arkui-ts/ts-basic-components-datapanel.md)，[@ohos.bundle.bundleManager](reference/apis-ability-kit/js-apis-Bundle-sys.md)，[@ohos.file.storageStatistics](reference/apis-core-file-kit/js-apis-file-storage-statistics.md)，[@ohos.file.volumeManager](reference/apis-core-file-kit/js-apis-file-volumemanager-sys.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.6

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/StorageStatistic)

#### 多模输入

##### 介绍

本示例使用[鼠标指针](reference/apis-input-kit/js-apis-pointer.md)，展示了多模输入鼠标外设的五种场景：鼠标样式资源切换、设置鼠标大小及颜色、设置鼠标动画光标样式、通过switch开关切换鼠标滚轮在非激活悬停窗口的滚动操作使能状态、通过switch开关切换鼠标主次键等功能。

##### 使用

1.启动应用,首页展示鼠标外设的各种设置项。

2.选择主按钮中的下拉框可以切换鼠标主次键。

3.点击当悬停在非活动窗口上方时对其进行滚动右侧switch开关，可以切换鼠标滚轮在非激活悬停窗口的滚动操作使能状态。

4.鼠标指针大小中的滑动条可以设置鼠标指针大小。

5.点击鼠标指针颜色中的单选框，可以设置鼠标颜色。

6.点击鼠标指针动画样式中的静态或动态单选框，可以设置鼠标静态或动画光标样式。

##### 基本原理

* 本示例主要分为一个模块，
  * 鼠标外设模块
    * 主要展示了鼠标外设的五种功能设置场景
    * 接口参考：[@ohos.multimodalInput.pointer](reference/apis-input-kit/js-apis-pointer.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.11.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/DeviceManagement/Mouse)

### 国际化

#### 国际化

##### 介绍

本示例展示如何使用媒体查询，[@ohos.intl](reference/apis-localization-kit/js-apis-intl.md)模块包含国际化能力基础接口，[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n-sys.md)模块包含国际化能力增强接口，资源管理模块，根据当前configuration（语言，区域，横竖屏，mccmnc）和device capability（设备类型，分辨率）提供获取应用资源信息读取接口。三个结合一起实现语言地区设置、时区设置和国际化资源管理相关功能。

##### 使用

1.启动应用，进入应用，首页分为三个按钮，点击**语言和地区**可以进入界面设置系统语言和地区。

2.点击**日期和时间**，可以进入界面设置系统时间和时区。

3.点击**区域格式示例**进入界面展示当前区域，当前系统语言下的时间、数字、货币、百分比、单复数、屏幕方向等信息的格式化显示。

##### 基本原理

* 本示例分为三个模块：
  * 语言和地区模块
    * 使用i18n接口中getDisplayCountry方法获取指定国家的本地化显示文本，getSystemRegion方法获取系统地区，getSystemLocale方法设置系统Locale，getSystemLanguage方法获取系统支持的语言列表，getPreferredLanguageList方法获取系统偏好语言列表，removePreferredLanguage方法删除系统偏好语言列表中指定位置的偏好语言。
    * 接口参考：[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n-sys.md)，[@ohos.intl](reference/apis-localization-kit/js-apis-intl.md)
    
  * 日期和时间模块
    * 使用i18n接口中is24HourClock方法判断系统时间是否为24小时制，getTimeZone方法获取日历对象的时区，set24HourClock方法修改系统时间的24小时制设置，setTime方法设置系统时间，setDate方法设置系统日期，getTimezone方法获取系统时区。
    * 接口参考：[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n-sys.md)，[@ohos.systemTime](reference/apis-basic-services-kit/js-apis-system-timer-sys.md)

  * 区域格式示例模块
    * 使用i18n接口中is24HourClock方法判断系统时间是否为24小时制，NumberFormat方法创建一个NumberFormat对象，getResourceManager方法获取当前应用的资源管理对。
    * 接口参考：[@ohos.i18n](reference/apis-localization-kit/js-apis-i18n-sys.md)，[@ohos.intl](reference/apis-localization-kit/js-apis-intl.md)，[@ohos.resourceManager](reference/apis-localization-kit/js-apis-resource-manager.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.7.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Internationalnation/International)

### 媒体

#### 相机和媒体库

##### 介绍

本示例使用[@ohos.multimedia.camera](reference/apis-basic-services-kit/js-apis-settings-sys.md)接口实现相机示例的主要功能：拍照、录像、参数配置等。使用[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md) 接口实现对媒体文件的存储。同时支持拍照角度旋转以及录制分辨率选择。

##### 使用

1.启动应用，在权限弹窗中授权后返回应用，进入相机界面。

2.相机界面默认是拍照模式，点击底部拍照按钮可以拍照，拍照完成会在底部左侧显示照片预览图。

3.点击**录像**或者左滑切换到录像模式，点击底部按钮开始录像，点击结束按钮结束录像，结束录像后底部左侧显示视频图标。

4.点击系统**Back**键或界面顶部**返回**按钮退出应用。

5.点击顶部右侧按钮进入设置界面，点击拍照旋转角度，选择0，90，180，270四个角度其中一个，返回至界面再次拍照，照片角度根据选择角度旋转。

6.点击顶部右侧按钮进入设置界面，点击录像分辨率，选择1920x1080，1280x720，800x600三个分辨率其中一个，返回至界面再次录像，视频分辨率根据选择分辨率设置。

7.返回相机界面点击底部左侧预览图可进入相册应用，可以在其中查看照片和录制的视频

##### 基本原理

1.使用@ohos.multimedia.camera接口实现相机示例的主要功能：拍照、录像、参数配置等。
2.使用@ohos.multimedia.mediaLibrary接口实现对媒体文件的存储。
3.通过跳转至相册来访问设备上的照片和录制视频。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.9.1

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Camera)

#### 录屏示例

##### 介绍

本示例使用[@ohos.screen](reference/apis-arkui/js-apis-screen-sys.md)管理屏幕的一些基础能力，包括获取屏幕对象，监听屏幕变化，创建和销毁虚拟屏幕等。[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)和[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)完成视频编码并保存到文件中。[@ohos.display](reference/apis-arkui/js-apis-display.md)捕捉屏幕显示图像帧，展示设备屏幕（含音频）录制功能。屏幕录制的主要工作是通过创建一个虚拟屏，捕获屏幕显示图形帧，完成视频编码并保存到文件中，帮助OEM设备厂家系统应用实现屏幕录制功能，也可以通过此应用抓取屏幕帧用于问题复现录制。

##### 使用

1.启动应用，首次启动需要用户授予“**访问媒体和文件**”和“**麦克风**”的权限

2.点击**启动**按钮，启动屏幕录制。

3.启动录制后会弹出一个透明录制悬浮控件，并显示录制时间计时，此时可以操作屏幕，操作过程屏幕显示会被录制下来。

4.需要停止录屏时，点击悬浮半透明的红色按钮，屏幕录制停止。

5.打开图库应用，在图库中可以看到最新录屏的媒体文件，点击后可支持录屏回放。

##### 基本原理

* 该示例通过Screen方法获取屏幕实例，createVirtualScreen方法创建一个虚拟屏，getAllScreens方法获取获取所有的屏幕，makeMirror方法将屏幕设置为镜像模式，setVirtualScreenSurface方法设置虚拟屏幕的surface，display接口捕获屏幕显示图形帧，media，mediaLibrary接口完成视频编码并保存到文件中，帮助OEM设备厂家系统应用实现屏幕录制功能。
* 接口参考：[@ohos.screen](reference/apis-arkui/js-apis-screen-sys.md)，[@ohos.multimedia.media](reference/apis-media-kit/arkts-apis-media.md)，[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md)，[@ohos.display](reference/apis-arkui/js-apis-display.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/ScreenRecorder)

#### 截屏

##### 介绍

本示例使用[screenshot](reference/apis-arkui/js-apis-screenshot-sys.md)模块实现屏幕截图 ，使用[window](reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9)模块实现隐私窗口切换，使用[display](reference/apis-arkui/js-apis-display-sys.md#displayhasprivatewindow9)模块查询当前隐私窗口。展示全屏截图和屏幕局部截图。

##### 使用

1. 点击右上角图标打开弹窗，选择截屏，展示全屏截图；选择局部截屏，选择截屏区域，点击右下角完成，展示局部截屏；
2. 点击滑块切换窗口隐私模式，隐私模式下截屏会弹出提示，拒绝截屏。

##### 基本原理

* 本示例通过screenshot接口实现屏幕截图 ，通过window接口实现隐私窗口切换，通过display接口查询当前隐私窗口。
* 接口参考：[@ohos.screenshot](reference/apis-arkui/js-apis-screenshot-sys.md)，[@ohos.window](reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9)，[@ohos.display](reference/apis-arkui/js-apis-display-sys.md#displayhasprivatewindow9)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Screenshot)

#### 音频管理（仅对系统应用开放）

##### 介绍

本示例主要演示了设备外放音频、普通耳机播放音频、支持空间音频和头动追踪的耳机播放音频三种音频播放方式。使用[@ohos.multimedia.audio.d.ts](https://gitcode.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.audio.d.ts)等接口完成相关功能。

##### 使用

1. 启动应用，在主页卡片中选择空间音频卡片，进入空间音频演示。

2. 在上部的两个音乐播放器分别可以播放2.0和5.1的音源，体现了音频框架对多声道播放的支持。

3. 下方的空间音频UX，具体的界面会随音频播放的设备而变化：外放及普通耳机只会启用关闭模式；支持空间音频和头动追踪的耳机会使三个按钮全部可选。

4. 点击三个按钮，分别会启用“关闭空间音频”，“启用空间音频固定模式”，“启用空间音频头动追踪模式”。

5. 当前版本对是否支持空间音频的判断仍简单，即当前发声设备具备不为空的mac地址就会显示三态按钮UX。

##### 基本原理

* 播放立体声多声道音频文件、调用空间音频API查询设置开关状态功能实现：
    * 在createAudioRenderer(options: AudioRendererOptions)入参AudioRendererOptions中增加AudioChannelLayout字段指明音频文件声道布局，以辅助多声道音频文件播放。
    * 使用isSpatializationSupported(), isHeadTrackingSupported(), isSpatializationSupportedForDevice(AudioDeviceDescriptor), isHeadTrackingSupportedForDevice(AudioDeviceDescriptor)四个接口查询系统和设备是否支持空间音频和头动跟踪，根据查询结果设置用户UX界面状态:只有系统和设备全都支持某功能，其按钮状态才不会被置灰。
    * 使用isSpatializationEnabled(), isHeadTrackingEnabled()在每次UX界面出现时查询当前空间音频和头动跟踪是否开启，同步在其他app对开关状态的改动。
    * 使用setSpatializationEnabled(enable: boolean), setHeadTrackingEnabled(enable: boolean)，在点击UX按钮时设置空间音频和头动跟踪状态。

##### 约束与限制

开发语言：ArkTS

配套版本：API11版本SDK，版本号：4.1.6.5

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Media/Audio)

### 安全

#### 访问权限控制

##### 介绍

本示例使用[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)接口中abilityAccessCtrl方法获取访问控制模块对象，GrantStatus.PERMISSION_GRANTED方法表示已授权状态，[@ohos.bundle.bundleManager](reference/apis-ability-kit/js-apis-bundleManager.md)接口中getApplicationInfo方法根据包名获取ApplicationInfo等展示应用申请权限场景

##### 使用

1.打开应用，页面出现弹窗，点击 **取消** 按钮。

2.页面跳转显示 **检测权限** 按钮，点击检测权限，出现提示信息“权限未授予”。

3.关闭应用再次打开，页面出现弹窗，点击 **确认** 按钮。

4.页面跳转显示 **检测权限** 按钮，点击**检测权限** 按钮，出现提示信息“权限已授予”。

5.关闭应用再次打开，页面不出现弹窗，点击 **检测权限** 按钮，点击检测权限，出现提示信息“权限已授予”。

##### 基本原理

* 该示例使用abilityAccessCtrl接口中abilityAccessCtrl方法获取访问控制模块对象，GrantStatus.PERMISSION_GRANTED方法表示已授权状态，bundleManager接口中getApplicationInfo方法根据包名获取ApplicationInfo等展示应用申请权限场景
* 接口参考：[@ohos.abilityAccessCtrl](reference/apis-ability-kit/js-apis-abilityAccessCtrl.md)，[@ohos.bundle.bundleManager](reference/apis-ability-kit/js-apis-bundleManager.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/AbilityAccessCtrl)

#### 安全控件类型的UI控件（仅对系统应用开放）

##### 介绍

本示例提供了安全控件类型的UI控件，支撑应用开发者集成安全控件做临时授权场景，当用户实际点击了某种类型的安全控件时，会对应用进行相应的临时授权，减少权限弹窗对用户的干扰，同时提供更小的授权范围。

##### 使用

1. 在主界面，点击“LocationButton安全控件”按钮，进入“LocationButton安全控件”界面，点击“当前位置”按钮，成功获取当前定位信息，并显示在方框中。

2. 在主界面，点击“PasteButton安全控件”按钮，进入“PasteButton安全控件”界面，点击”复制“按钮，复制下方“天天开心”文本，点击“粘贴”按钮，获取剪贴板内容并显示在其下方框中。

3. 在主界面，点击“SaveButton安全控件”按钮，进入“SaveButton安全控件”界面，点击“下载”按钮，将当前页面中的图片保存到本地图库中。

##### 基本原理

* 本示例分为Location安全控件模块，剪贴板安全控件模块，媒体库安全控件模块

  * Location安全控件模块
  
    * 使用SecLocationButton组件开发获取定位信息功能，在其点击回调onclick事件中调用geoLocationManager.getCurrentLocation()得到当前定位信息经纬度。
    * 接口参考：[@ohos.geoLocationManager](reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)

  * 剪贴板安全控件模块
  
    * 使用SecPasteButton组件开发获取剪贴板信息功能，在其点击回调onclick事件中调用ystemPasteboard.setData()将文本复制到剪贴板中，systemPasteboard.getData()得到剪贴板内容。
    * 接口参考：[@ohos.pasteboard](reference/apis-basic-services-kit/js-apis-pasteboard.md#getdata9)

  * 媒体库安全控件模块
  
    * 使用SecSaveButton组件开发保存图片到媒体库功能，在其点击回调onclick事件中调用photoAccessHelper.getPhotoAccessHelper()得到媒体库图片管理器helper；helper.createAsset()得到保存到媒体库图片的uri，resourceManager.getMediaContent()得到存放在Resources/base/media文件下的banner.png图片内容；fs.open()和fs.write()将图片内容通过得到的uri写到媒体库中，最后fs.close()关闭文件。
    * 接口参考：[@ohos.file.photoAccessHelper](reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md)，[@ohos.file.fs](reference/apis-core-file-kit/js-apis-file-fs.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.15

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/AuthorizedButton)

#### DLP

##### 介绍

本示例是一个安全类App，使用[@ohos.dlpPermission](reference/apis-data-protection-kit/js-apis-dlppermission.md) 接口展示了普通文件加密受限的过程。

##### 使用

1. 启动应用后点击“**+**”按钮可以添加一个普通文件。

2. 长按点击加密按钮，出现加密权限弹窗，选择需要设置的权限并点击确定。

3. 点击加密文件，跳转到文本编辑应用，如果设置的权限是只读权限，页面置灰，不可编辑。

4. 长按点击删除按钮，删除文件。

##### 基本原理

* 文件的添加和文件列表的获取分别在Index和MediaFileUri中，具体实现为:

  * 文件的添加：首先通过[@ohos.file.picker](reference/apis-core-file-kit/js-apis-file-picker.md)接口的DocumentSaveOptions()自定一个参数，然后通过new picker.DocumentViewPicker()拉起文件管理应用去新建一个普通文件。

  * 文件列表的获取：首先使用[@ohos.file.fileAccess](reference/apis-core-file-kit/js-apis-fileAccess-sys.md) 接口的createFileAccessHelper()方法来创建连接指定wants的helper对象，然后通过getRoots()来获取helper对象连接的文件管理服务类的设备根节点信息，并获取到目录url，最后通过getFileInfoFromUri()得到文件的信息。

* 文件的加密操作在DlpManager中，，具体实现为:

  * 使用dlpPermission接口的generateDLPFile获得一个相关的操作型关系数据库RdbStore，将明文文件加密生成权限受控文件。

##### 约束与限制

开发语言：ArkTS

配套版本：API10版本SDK，版本号：4.0.10.10

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/Security/DLP)

### 窗口管理

#### 窗口扩展应用

##### 介绍

本示例通过 [窗口扩展能力](reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md) 设置不同Ability，使用 [AbilityComponent](reference/apis-arkui/arkui-ts/ts-container-ability-component-sys.md) 组件加载各个Ability。仿设置应用，实现点击设置菜单栏，跳转或加载详情页面。

##### 使用

1.竖屏模式下点击左侧设置菜单栏，跳转详情页面。

2.横屏模式下点击左侧设置菜单栏，右侧显示详情页面。

##### 基本原理

* 本示例通过窗口扩展能力设置不同Ability，使用AbilityComponent组件加载各个Ability，matchMediaSync方法设置媒体查询的查询条件，RemoteObject方法实现远程对象。
* 接口参考：[@ohos.application.WindowExtensionAbility](reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md)，[AbilityComponent](reference/apis-arkui/arkui-ts/ts-container-ability-component-sys.md)，[@ohos.rpc](reference/apis-ipc-kit/js-apis-rpc.md)，[@ohos.mediaquery](reference/apis-arkui/js-apis-mediaquery.md)

##### 约束与限制

开发语言：ArkTS

配套版本：API9版本SDK，版本号：3.2.11.9

[示例链接](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowExtAbility)
