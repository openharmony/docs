# 概述


为了支持多设备，应用需要能够在不同的设备上运行，控件作为应用的基础组成部分，需要支持不同的设备，且在视觉、交互、动效等表现形式上针对设备进行必要的调整，达到最佳体验。因此，同一控件在不同的设备上会呈现出不同的形态，称为多态控件。

多态控件应该具备以下特点：

- 覆盖默认设备、平板，兼顾智慧屏、车机、智能穿戴等终端。(OH3.2后续版本支持)

- 场景一致性。在对应的使用场景下，其交互、视觉、动效要保持一致，在设计上属性参数保持一致或差异化。

- 针对设备做优化。多态控件在不同的设备上的呈现应该是该设备下的最佳效果，因此在保证一致性的同时，还需要针对设备的特点进行优化。

## 控件的状态

- 控件的状态是一种视觉呈现，用于展示控件当前处于何种交互阶段。不同控件的相同状态应该保持一致的视觉风格，且应该清晰可见。

- 应用可能部署在不同设备上供用户使用，有些设备会支持多种输入方式。例如平板可以连接蓝牙键盘和鼠标来做文字编辑工作，此时控件需要同时满足键盘和鼠标交互，需要支持获焦态和悬停态，如果控件没有支持这两种状态，在使用键盘走焦时或鼠标悬停时，控件就无法通过呈现出相应的状态为用户提供正确的视觉引导。OpenHarmony默认提供多种交互方式的控件实现，方便开发者支持多种输入方式和交互归一。

常见的状态类型：


  |![1_zh-cn_image_0000001568212890.png](figures/1_zh-cn_image_0000001568212890.png) | ![1_zh-cn_image_0000001568293053.png](figures/1_zh-cn_image_0000001568293053.png) | ![1_zh-cn_image_0000001568212892.png](figures/1_zh-cn_image_0000001568212892.png) |
| -------- | -------- | -------- |
|**正常态** <br/>表明当前控件可交互。|**不可用态** <br/>表明当前控件不可交互。 | **点击态** <br/>表明当前控件当前处于点击状态。<br/>手指或鼠标按下且未释放。  | 
 | ![1_zh-cn_image_0000001568212893.png](figures/1_zh-cn_image_0000001568212893.png) |  ![1_zh-cn_image_0000001568212894.png](figures/1_zh-cn_image_0000001568212894.png)  |  ![1_zh-cn_image_0000001568212895.png](figures/1_zh-cn_image_0000001568212895.png) |
|**获焦态** <br/>表明当前控件处于焦点状态。操作：<br/>-&nbsp;键盘或遥控器通过方向键将焦点从一个控件移动到另一个控件。 <br/>-&nbsp;通过语音操作，使得控件获得焦点。| **激活态** <br/>表明当前控件处于激活状态。用于有多个元素可获焦的控件。<br/>操作：焦点处在页签控件的某个页签上时，该页签获焦。点击此页签，该页签被激活 | **悬停态** <br/> 表明当前控件属于鼠标悬停的状态。<br/> 操作：将鼠标悬停在控件之上。| 


# 控件概览

## 导航类

  |![底部页签](figures/底部页签.png) | ![子页签超出屏幕](figures/子页签超出屏幕.png) | ![标题栏-普通](figures/标题栏-普通.png) |
| -------- | -------- | -------- |
|[底部页签](multimodal-bottom-tab.md) | [子页签](multimodal-subtab.md) | [标题栏](multimodal-title-bar.md) | 
 | ![标题栏-普通备份](figures/标题栏-普通备份.png)|  ![步骤导航器-默认](figures/步骤导航器-默认.png) |  ![2_zh-cn_image_0000001568412869.png](figures/2_zh-cn_image_0000001568412869.png) |
|[侧边导航栏](multimodal-sidebar.md) | [导航点](multimodal-swiper.md) | [步骤导航器](multimodal-stepper.md) | 


## 展示类

  |![1_zh-cn_image_0000001568093257.png](figures/1_zh-cn_image_0000001568093257.png) | ![1_zh-cn_image_0000001568212898.png](figures/1_zh-cn_image_0000001568212898.png)| ![1_zh-cn_image_0000001568212899.png](figures/1_zh-cn_image_0000001568212899.png) |
| -------- | -------- | -------- |
|[分隔器](multimodal-divider.md) |[气泡提示](multimodal-bubble.md) |[进度条](multimodal-progress-bar.md) | 
|![1_zh-cn_image_0000001517133790.png](figures/1_zh-cn_image_0000001517133790.png)| ![1_zh-cn_image_0000001568093233.png](figures/1_zh-cn_image_0000001568093233.png) |![1_zh-cn_image_0000001577319197.png](figures/1_zh-cn_image_0000001577319197.png) | 
|[新事件标记](multimodal-badge.md) | [即时反馈](multimodal-instant-tip.md) |[数据可视化](multimodal-data-panel.md) | 
| ![文本_sub_1](figures/文本_sub_1.png) |  |  |
| [文本](multimodal-text.md) |  |  |


## 操作类

  |![2_zh-cn_image_0000001568212961.png](figures/2_zh-cn_image_0000001568212961.png) | ![1_zh-cn_image_0000001517452952.png](figures/1_zh-cn_image_0000001517452952.png)| ![1_zh-cn_image_0000001568293089.png](figures/1_zh-cn_image_0000001568293089.png)|
| -------- | -------- | -------- |
|[按钮](multimodal-button.md) |[下拉按钮](multimodal-drop-down-menu.md) |[状态按钮](multimodal-state-button.md) | 
|![1_zh-cn_image_0000001517133794.png](figures/1_zh-cn_image_0000001517133794.png) |![1_zh-cn_image_0000001517133814.png](figures/1_zh-cn_image_0000001517133814.png) |![2_zh-cn_image_0000001517612920.png](figures/2_zh-cn_image_0000001517612920.png) |
|[索引条](multimodal-index-bar.md) | [滚动条](multimodal-scrollbar.md) |[下拉刷新](multimodal-pull-to-refresh.md) | 
|![1_zh-cn_image_0000001568212945.png](figures/1_zh-cn_image_0000001568212945.png) |  |  | 
|[菜单](multimodal-menu.md) |  |  | 


## 输入类

  |![1_zh-cn_image_0000001517452972.png](figures/1_zh-cn_image_0000001517452972.png) | ![1_zh-cn_image_0000001568093217.png](figures/1_zh-cn_image_0000001568093217.png) |
| -------- | -------- |
|[文本框](multimodal-text-box.md) |[搜索框](multimodal-search-box.md) |  | 

## 选择类

  |![1_zh-cn_image_0000001517133818.png](figures/1_zh-cn_image_0000001517133818.png) |![1_zh-cn_image_0000001517293384.png](figures/1_zh-cn_image_0000001517293384.png) |![1_zh-cn_image_0000001568093265.png](figures/1_zh-cn_image_0000001568093265.png) |
| -------- | -------- | -------- |
| [勾选](multimodal-tick-box.md) | [开关](multimodal-toggle.md) | [单选框](multimodal-radio-button.md) | 
|![1_zh-cn_image_0000001517133778.png](figures/1_zh-cn_image_0000001517133778.png) | ![1_zh-cn_image_0000001517452964.png](figures/1_zh-cn_image_0000001517452964.png)|![3_zh-cn_image_0000001517133822.png](figures/3_zh-cn_image_0000001517133822.png) |
| [多选](multimodal-check-box.md) |[评分条](multimodal-rating-bar.md) | [滑动条](multimodal-slider.md) | 
|![1_zh-cn_image_0000001517293372.png](figures/1_zh-cn_image_0000001517293372.png) | | |
|[滑动选择器](multimodal-picker.md) |  |  | 


## 容器类

  |![2_zh-cn_image_0000001568212941.png](figures/2_zh-cn_image_0000001568212941.png) |![1_zh-cn_image_0000001568412877.png](figures/1_zh-cn_image_0000001568412877.png) |
| -------- | -------- | 
|[可滑动面板](multimodal-slidable-panel.md) | [弹出框](multimodal-dialog.md) |  | 