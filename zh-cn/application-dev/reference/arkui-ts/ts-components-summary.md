# 组件导读


## 行列与分栏

- [Column](ts-container-column.md)

    沿垂直方向布局的容器组件。
- [ColumnSplit](ts-container-columnsplit.md)

    垂直方向分隔布局容器组件，将子组件纵向布局，并在每个子组件之间插入一根横向的分割线。
- [Row](ts-container-row.md)

    沿水平方向布局的容器组件。
- [RowSplit](ts-container-rowsplit.md)

    水平方向分隔布局容器组件，将子组件横向布局，并在每个子组件之间插入一根纵向的分割线。
- [SideBarContainer](ts-container-sidebarcontainer.md)

    提供侧边栏可以显示和隐藏的侧边栏容器组件，通过子组件定义侧边栏和内容区，第一个子组件表示侧边栏，第二个子组件表示内容区。


## 堆叠Flex与栅格

- [Stack](ts-container-stack.md) 

    堆叠容器组件，子组件按照顺序依次入栈，后一个子组件覆盖前一个子组件。
- [Flex](ts-container-flex.md)

    以弹性方式布局子组件的容器组件。
- [GridContainer](ts-container-gridcontainer.md)

    纵向排布栅格布局容器组件，仅在栅格布局场景中使用。
- [GridRow](ts-container-gridrow.md)

    栅格容器组件，仅可以和栅格子组件(GridCol)在栅格布局场景中使用。
- [GridCol](ts-container-gridcol.md)

    栅格子组件，必须作为栅格容器组件(GridRow)的子组件使用。
- [RelativeContainer](ts-container-relativecontainer.md)

    相对布局组件，用于复杂场景中元素对齐的布局。


## 列表与宫格

- [List](ts-container-list.md)

    列表包含一系列相同宽度的列表项，适合连续、多行呈现同类数据，例如图片和文本。
- [ListItem](ts-container-listitem.md)

    用来展示具体列表项，必须配合List来使用。
- [ListItemGroup](ts-container-listitemgroup.md)

    用来展示分组列表项的组件，必须配合List组件来使用。
- [Grid](ts-container-grid.md)

    网格容器组件，由“行”和“列”分割的单元格所组成，通过指定“项目”所在的单元格做出各种各样的布局。
- [GridItem](ts-container-griditem.md)

    网格容器中单项内容容器。


## 滚动与滑动

- [Scroll](ts-container-scroll.md) 

    可滚动的容器组件，当子组件的布局尺寸超过父组件的尺寸时，内容可以滚动。
- [Swiper](ts-container-swiper.md)

    滑块视图容器组件，提供子组件滑动轮播显示的能力。
- [WaterFlow](ts-container-waterflow.md)

    瀑布流容器组件，由“行”和“列”分割的单元格所组成，通过容器自身的排列规则，将不同大小的“项目”自上而下，如瀑布般紧密布局。
- [FlowItem](ts-container-flowitem.md)

    瀑布流组件WaterFlow的子组件，用来展示瀑布流具体item。


## 导航

- [Navigator](ts-container-navigator.md) 

    路由容器组件，提供路由跳转能力。    
- [Navigation](ts-basic-components-navigation.md)

    一般作为Page页面的根容器，通过属性设置来展示页面的标题栏、工具栏、导航栏等。
- [NavRouter](ts-basic-components-navrouter.md)

    导航组件，默认提供点击响应处理，不需要开发者自定义点击事件逻辑。
- [NavDestination](ts-basic-components-navdestination.md)

    作为NavRouter组件的子组件，用于显示导航内容区。
- [Stepper](ts-basic-components-stepper.md)

    步骤导航器组件，适用于引导用户按照步骤完成任务的导航场景。
- [StepperItem](ts-basic-components-stepperitem.md)

    Stepper组件的子组件。
- [Tabs](ts-container-tabs.md)

    通过页签进行内容视图切换的容器组件，每个页签对应一个内容视图。
- [TabContent](ts-container-tabcontent.md)

    仅在Tabs组件中使用，对应一个切换页签的内容视图。


## 按钮与选择

- [Button](ts-basic-components-button.md)

    按钮组件，可快速创建不同样式的按钮。
- [Toggle](ts-basic-components-toggle.md)

    组件提供勾选框样式、状态按钮样式及开关样式。
- [Checkbox](ts-basic-components-checkbox.md)

    提供多选框组件，通常用于某选项的打开或关闭。
- [CheckboxGroup](ts-basic-components-checkboxgroup.md)

    多选框群组，用于控制多选框全选或者不全选状态。
- [DatePicker](ts-basic-components-datepicker.md)

    选择日期的滑动选择器组件。
- [TextPicker](ts-basic-components-textpicker.md)

    滑动选择文本内容的组件。
- [TimePicker](ts-basic-components-timepicker.md)

    滑动选择时间的组件。
- [Radio](ts-basic-components-radio.md)

    单选框，提供相应的用户交互选择项。
- [Rating](ts-basic-components-rating.md)

    提供在给定范围内选择评分的组件。
- [Select](ts-basic-components-select.md)

    提供下拉选择菜单，可以让用户在多个选项之间选择。
- [Slider](ts-basic-components-slider.md)

    滑动条组件，通常用于快速调节设置值，如音量调节、亮度调节等应用场景。
- [Counter](ts-container-counter.md)

    计数器组件，提供相应的增加或者减少的计数操作。


## 文本与输入

- [Text](ts-basic-components-text.md)

    显示一段文本的组件。
- [Span](ts-basic-components-span.md)

    作为Text组件的子组件，用于显示行内文本片段的组件。
- [Search](ts-basic-components-search.md)

    搜索框组件，适用于浏览器的搜索内容输入框等应用场景。
- [TextArea](ts-basic-components-textarea.md)

    多行文本输入框组件，当输入的文本内容超过组件宽度时会自动换行显示。
- [TextInput](ts-basic-components-textinput.md)

    单行文本输入框组件。
- [PatternLock](ts-basic-components-patternlock.md)

    图案密码锁组件，以九宫格图案的方式输入密码，用于密码验证场景。手指在PatternLock组件区域按下时开始进入输入状态，手指离开屏幕时结束输入状态完成密码输入。
- [RichText](ts-basic-components-richtext.md)

    富文本组件，解析并显示HTML格式文本。


## 图片视频与媒体

- [Image](ts-basic-components-image.md)

    图片组件，支持本地图片和网络图片的渲染展示。
- [ImageAnimator](ts-basic-components-imageanimator.md)

    提供逐帧播放图片能力的帧动画组件，可以配置需要播放的图片列表，每张图片可以配置时长。
- [Video](ts-media-components-video.md)

    用于播放视频文件并控制其播放状态的组件。
- [PluginComponent](ts-basic-components-plugincomponent.md)

    提供外部应用组件嵌入式显示功能，即外部应用提供的UI可在本应用内显示。
- [XComponent](ts-basic-components-xcomponent.md)

    用于EGL/OpenGLES和媒体数据写入。


## 信息展示

- [DataPanel](ts-basic-components-datapanel.md)

    数据面板组件，用于将多个数据占比情况使用占比图进行展示。
- [Gauge](ts-basic-components-gauge.md)

    数据量规图表组件，用于将数据展示为环形图表。
- [LoadingProgress](ts-basic-components-loadingprogress.md)

    用于显示加载动效的组件。
- [Marquee](ts-basic-components-marquee.md)

    跑马灯组件，用于滚动展示一段单行文本，仅当文本内容宽度超过跑马灯组件宽度时滚动。
- [Progress](ts-basic-components-progress.md)

    进度条组件，用于显示内容加载或操作处理等进度。
- [QRCode](ts-basic-components-qrcode.md)

    用于显示单个二维码的组件。
- [TextClock](ts-basic-components-textclock.md)

    通过文本将当前系统时间显示在设备上。支持不同时区的时间显示，最高精度到秒级。
- [TextTimer](ts-basic-components-texttimer.md)

    通过文本显示计时信息并控制其计时器状态的组件。


## 空白与分隔

- [Blank](ts-basic-components-blank.md)

    空白填充组件，在容器主轴方向上，空白填充组件具有自动填充容器空余部分的能力。仅当父组件为Row/Column时生效。
- [Divider](ts-basic-components-divider.md)

    分隔器组件，分隔不同内容块/内容元素。


## 画布与图形绘制

- [Canvas](ts-components-canvas-canvas.md)

    提供画布组件，用于自定义绘制图形。
- [Circle](ts-drawing-components-circle.md)

    用于绘制圆形的组件。 
- [Ellipse](ts-drawing-components-ellipse.md)

    椭圆绘制组件。
- [Line](ts-drawing-components-line.md)

    直线绘制组件。
- [Polyline](ts-drawing-components-polyline.md)

    折线绘制组件。
- [Polygon](ts-drawing-components-polygon.md)

    多边形绘制组件。
- [Path](ts-drawing-components-path.md)

    路径绘制组件，根据绘制路径生成封闭的自定义形状。
- [Rect](ts-drawing-components-rect.md)

    矩形绘制组件。
- [Shape](ts-drawing-components-shape.md)

    作为绘制组件的父组件，实现类似SVG的效果，父组件中会描述所有绘制组件均支持的通用属性。


## 网络

- [Web](ts-basic-components-web.md)

    提供具有网页显示能力的Web组件。


## 其他

- [ScrollBar](ts-basic-components-scrollbar.md)

    滚动条组件，用于配合可滚动组件使用，如List、Grid、Scroll等。
- [Badge](ts-container-badge.md)

    可以附加在单个组件上用于信息标记的容器组件。
- [AlphabetIndexer](ts-container-alphabet-indexer.md)

    可以与容器组件联动用于按逻辑结构快速定位容器显示区域的索引条组件。
- [Panel](ts-container-panel.md)

    可滑动面板，提供一种轻量的内容展示窗口，方便在不同尺寸中切换。
- [Refresh](ts-container-refresh.md)

    可以进行页面下拉操作并显示刷新动效的容器组件。 
- [AbilityComponent](ts-container-ability-component.md)

    独立显示Ability的容器组件。
- [RemoteWindow](ts-basic-components-remotewindow.md)

    远程控制窗口组件，可以通过此组件控制应用窗口，提供启动退出过程中控件动画和应用窗口联动动画的能力。