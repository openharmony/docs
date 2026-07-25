# Media Library Kit术语
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda; @yixiaoff-->
<!--Designer: @guxinggang; @liweilu1-->
<!--Tester: @wangbeibei; @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## D

### DataSharePredicates；数据共享谓词

  用于构建数据查询条件的工具类。在媒体库查询中，通过设置查询条件（如equalTo、between等）来检索特定的媒体资源或相册对象，支持灵活的数据筛选和过滤。

## F

### FetchOptions；检索选项

  用于配置媒体资源或相册查询参数的对象。包含检索列（fetchColumns）和查询条件（predicates），用于指定查询时返回的资源属性和筛选条件，提高查询效率和精准度。

### FetchResult；检索结果

  媒体资源或相册查询操作返回的结果集对象。提供对查询结果的遍历和访问能力，可通过getFirstObject、getAllObjects等方法获取查询到的媒体资产或相册对象，查询完成后需要调用close方法释放资源。

## M

### Media Library Kit；媒体文件管理服务

  提供了管理相册和媒体文件的能力，包括图片和视频，帮助应用快速构建图片视频展示和播放能力。

### MediaAlbumChangeRequest；媒体相册变更请求

  用于创建和修改相册属性的请求对象。支持创建用户相册、重命名相册、添加或移除相册中的媒体资源等变更操作，需通过PhotoAccessHelper.applyChanges接口提交变更请求才能生效。

### MediaAssetChangeRequest；媒体资产变更请求

  用于创建和修改媒体资源属性的请求对象。支持创建图片或视频资源、重命名媒体资源、设置收藏状态、删除资产等变更操作，可通过addResource接口添加资源内容，需通过PhotoAccessHelper.applyChanges接口提交变更请求。

### MediaAssetManager；媒体资产管理器

  用于请求和管理媒体资源数据的核心组件。支持请求图片数据、请求动态照片对象、加载应用沙箱的动态照片等功能，提供高质量模式和快速模式两种资源交付策略，用于高效获取媒体资源内容。

### MovingPhoto；动态照片

  结合了静态图片和短视频的特殊照片形式。包含图片和视频两部分内容，可以显示一小段时间的动态画面和声音，用于捕捉精彩的动态瞬间，提升创作空间，同时提高拍照容错率。

### MovingPhotoView；动态照片视图

  用于播放和展示动态照片的UI组件。支持长按触发播放、静音设置、视频显示模式配置等功能，通过MovingPhotoViewController控制器控制播放状态，适用于社交类、图库类应用中动态照片的播放展示。

### MovingPhotoViewController；动态照片控制器

  用于控制MovingPhotoView组件播放状态的控制器对象。提供startPlayback和stopPlayback方法控制动态照片的播放和停止，与MovingPhotoView组件配合使用实现动态照片的交互播放功能。

## P

### PhotoAccessHelper；相册管理模块

  提供访问和管理相册及媒体资源的核心接口模块。通过getPhotoAccessHelper接口获取实例，支持获取媒体资源、获取相册、创建和修改资产、监听资源变更等功能，是Media Library Kit的主要开发接口。

### PhotoAsset；照片资产

  表示单个图片或视频媒体资源的对象。包含媒体资源的基本信息（如URI、显示名称、标题等属性），支持获取缩略图、读取资源数据、修改属性等操作，是媒体库中媒体资源的基本操作单元。

### PhotoViewPicker；图片选择器

  用于拉起系统图库让用户选择媒体资源的系统组件。支持配置可选的媒体文件类型、最大选择数目、是否支持拍照等参数，用户选择后返回PhotoSelectResult结果集，提供安全的媒体资源选择方式，无需申请权限。

### Picker；选择器

  系统提供的用于用户交互选择资源的组件工具。包括PhotoViewPicker（图片选择器）、AudioViewPicker（音频选择器）等，通过拉起系统界面让用户自主选择待分享或待操作的资源，实现安全的资源访问，应用无需申请敏感权限。

## T


### Thumbnail；缩略图

  媒体资源的缩小版本图片。用于在相册展示、编辑预览等场景中快速呈现图片或视频的预览内容，通过PhotoAsset.getThumbnail接口按指定尺寸获取，常用于UI界面展示以提高性能和响应速度。
