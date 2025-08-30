# native_type.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## 概述

提供NativeModule公共的类型定义。

**引用文件：** <arkui/native_type.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ContextCallback](capi-arkui-nativemodule-arkui-contextcallback.md) | ArkUI_ContextCallback | 事件回调类型。 |
| [ArkUI_NumberValue](capi-arkui-nativemodule-arkui-numbervalue.md) | ArkUI_NumberValue | ArkUI在Native侧的数字类型定义。 |
| [ARKUI_TextPickerRangeContent](capi-arkui-nativemodule-arkui-textpickerrangecontent.md) | ARKUI_TextPickerRangeContent | 定义单列滑动数据选择器支持的图片资源结构体。 |
| [ARKUI_TextPickerCascadeRangeContent](capi-arkui-nativemodule-arkui-textpickercascaderangecontent.md) | ARKUI_TextPickerCascadeRangeContent | 定义多列联动滑动数据选择器的结构体。 |
| [ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md) | ArkUI_ColorStop | 定义渐变色结构。 |
| [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md) | ArkUI_Rect | 定义遮罩屏蔽区域的范围结构体。 |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | ArkUI_IntSize | 尺寸类型，用于描述组件的宽高。 |
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | ArkUI_IntOffset | 位置，用于描述组件的位置。 |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | ArkUI_Margin | 外边距属性，用于描述组件的外边距属性。 |
| [ArkUI_TranslationOptions](capi-arkui-nativemodule-arkui-translationoptions.md) | ArkUI_TranslationOptions | 定义组件转场时的平移效果对象。 |
| [ArkUI_ScaleOptions](capi-arkui-nativemodule-arkui-scaleoptions.md) | ArkUI_ScaleOptions | 定义组件转场时的缩放效果对象。 |
| [ArkUI_RotationOptions](capi-arkui-nativemodule-arkui-rotationoptions.md) | ArkUI_RotationOptions | 定义组件转场时的旋转效果对象。 |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md) | ArkUI_LayoutConstraint | 约束尺寸，组件布局时，进行尺寸范围限制。 |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md) | ArkUI_DrawContext | 定义组件绘制上下文类型结构。 |
| [ArkUI_Node*](capi-arkui-nativemodule-arkui-node8h.md) | ArkUI_NodeHandle | 定义ArkUI native组件实例对象指针定义。 |
| [ArkUI_NativeDialog*](capi-arkui-nativemodule-arkui-nativedialog8h.md) | ArkUI_NativeDialogHandle | 定义ArkUI在Native侧的自定义弹窗控制器对象指针。 |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) | ArkUI_WaterFlowSectionOption | 定义FlowItem分组配置信息。 |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md) | ArkUI_ListItemSwipeActionItem | 定义ListItemSwipeActionOption方法内Item的配置信息。 |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) | ArkUI_ListItemSwipeActionOption | 定义ListItemSwipeActionOption方法的配置信息。 |
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | 定义ArkUI native UI的上下文实例对象指针定义。 |
| [ArkUI_NodeContent*](capi-arkui-nativemodule-arkui-nodecontent8h.md) | ArkUI_NodeContentHandle | 定义ArkUI NodeContent实例在Native侧的实例对象指针定义。 |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md) | ArkUI_AlignmentRuleOption | 指定设置在相对容器中子组件的对齐规则。 |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md) | ArkUI_GuidelineOption | guideLine参数，用于定义guideline的id、方向和位置。 |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md) | ArkUI_BarrierOption | barrier参数，用于定义barrier的id、方向和生成时所依赖的组件。 |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md) | ArkUI_ImageAnimatorFrameInfo | 定义图片帧信息。 |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md) | ArkUI_ListChildrenMainSize | 定义List的ChildrenMainSize类信息。 |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption | 定义线性进度条样式。 |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md) | ArkUI_CustomProperty | 定义自定义属性的CustomProperty类信息。 |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) | ArkUI_HostWindowInfo | 定义窗口属性的HostWindowInfo类信息。 |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) | ArkUI_ActiveChildrenInfo | 定义ActiveChildrenInfo类信息。 |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md) | ArkUI_CrossLanguageOption | 定义跨语言配置项。 |
| [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md) | AbilityBase_Want | 声明want。 |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md) | ArkUI_EmbeddedComponentOption | 为EmbeddedComponent定义EmbeddedComponentOption。 |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md) | ArkUI_AccessibilityState | 定义组件无障碍状态。 |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md) | ArkUI_AccessibilityValue | 定义组件无障碍信息值。 |
| [ArkUI_SystemFontStyleEvent](capi-arkui-nativemodule-arkui-systemfontstyleevent.md) | ArkUI_SystemFontStyleEvent | 系统字体变更事件定义。 |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md) | ArkUI_CustomSpanMeasureInfo | 自定义段落组件的测量信息。 |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md) | ArkUI_CustomSpanMetrics | 自定义段落组件的度量指标。 |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md) | ArkUI_CustomSpanDrawInfo | 自定义段落组件的绘制信息。 |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md) | ArkUI_SwiperIndicator | 定义 Swiper 组件的导航指示器风格。 |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) | ArkUI_SwiperDigitIndicator | 定义 Swiper 组件的数字导航指示器风格。 |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md) | ArkUI_SwiperArrowStyle | 定义 Swiper 组件的导航箭头风格。 |
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) | ArkUI_StyledString_Descriptor | 定义文本组件支持的属性字符串的数据对象。 |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md) | ArkUI_SnapshotOptions | 定义截图的可选项。 |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md) | ArkUI_TextPickerRangeContentArray | 定义文本选择器的数据选择列表。 |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md) | ArkUI_TextCascadePickerRangeContentArray | 定义多列联动数据选择器的多列联动数据选择列表。 |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) | ArkUI_VisibleAreaEventOptions | 可见区域变化监听的参数。 |

### 枚举

| 名称                                                                  | typedef关键字                      | 描述                                |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_Alignment](#arkui_alignment)                                 | ArkUI_Alignment                 | 定义布局对齐枚举值。                        |
| [ArkUI_ImageRepeat](#arkui_imagerepeat)                             | ArkUI_ImageRepeat               | 定义图片重复铺设枚举值。                      |
| [ArkUI_FontStyle](#arkui_fontstyle)                                 | ArkUI_FontStyle                 | 定义字体样式枚举值。                        |
| [ArkUI_FontWeight](#arkui_fontweight)                               | ArkUI_FontWeight                | 定义字体粗细/字重枚举值。                     |
| [ArkUI_TextAlignment](#arkui_textalignment)                         | ArkUI_TextAlignment             | 定义字体水平对齐样式枚举值。                    |
| [ArkUI_TextVerticalAlignment](#arkui_textverticalalignment)         | ArkUI_TextVerticalAlignment     | 定义文本垂直对齐样式枚举值。                    |
| [ArkUI_EnterKeyType](#arkui_enterkeytype)                           | ArkUI_EnterKeyType              | 定义单行文本输入法回车键类型枚举值。                |
| [ArkUI_TextInputType](#arkui_textinputtype)                         | ArkUI_TextInputType             | 定义单行文本输入法类型枚举值。                   |
| [ArkUI_TextAreaType](#arkui_textareatype)                           | ArkUI_TextAreaType              | 定义多行文本输入法类型枚举值。                   |
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle)                 | ArkUI_CancelButtonStyle         | 定义清除按钮样式枚举值。                      |
| [ArkUI_XComponentType](#arkui_xcomponenttype)                       | ArkUI_XComponentType            | 定义XComponent类型枚举值。                |
| [ArkUI_ProgressType](#arkui_progresstype)                           | ArkUI_ProgressType              | 定义进度条类型枚举值。                       |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype)               | ArkUI_TextDecorationType        | 定义装饰线类型枚举值。                       |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle)             | ArkUI_TextDecorationStyle       | 定义装饰线样式枚举值。                       |
| [ArkUI_TextCase](#arkui_textcase)                                   | ArkUI_TextCase                  | 定义文本大小写枚举值。                       |
| [ArkUI_CopyOptions](#arkui_copyoptions)                             | ArkUI_CopyOptions               | 定义文本复制粘贴模式枚举值。                    |
| [ArkUI_ShadowType](#arkui_shadowtype)                               | ArkUI_ShadowType                | 定义阴影类型枚举值。                        |
| [ArkUI_DatePickerMode](#arkui_datepickermode)                       | ArkUI_DatePickerMode            | 定义日期选择器列显示模式的枚举值。                 |
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype)             | ArkUI_TextPickerRangeType       | 定义滑动选择文本选择器输入类型。                  |
| [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate) | ArkUI_AccessibilityCheckedState | 定义无障碍复选框状态类型枚举值。                  |
| [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype)     | ArkUI_AccessibilityActionType   | 定义无障碍操作类型。                        |
| [ArkUI_EdgeEffect](#arkui_edgeeffect)                               | ArkUI_EdgeEffect                | 定义边缘滑动效果枚举值。                      |
| [ArkUI_EffectEdge](#arkui_effectedge)                               | ArkUI_EffectEdge                | 定义边缘效果生效边缘的方向枚举值。                 |
| [ArkUI_ScrollDirection](#arkui_scrolldirection)                     | ArkUI_ScrollDirection           | 定义Scroll组件排列方向枚举值。                |
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign)                     | ArkUI_ScrollSnapAlign           | 定义列表项滚动结束对齐效果枚举值。                 |
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode)           | ArkUI_ScrollBarDisplayMode      | 定义滚动条状态枚举值。                       |
| [ArkUI_Axis](#arkui_axis)                                           | ArkUI_Axis                      | 定义滚动方向和List组件排列方向枚举值。             |
| [ArkUI_StickyStyle](#arkui_stickystyle)                             | ArkUI_StickyStyle               | 定义列表是否吸顶和吸底枚举值。                   |
| [ArkUI_ContentClipMode](#arkui_contentclipmode)                     | ArkUI_ContentClipMode           | 定义滚动容器的内容层裁剪区域枚举值。                |
| [ArkUI_WaterFlowLayoutMode](#arkui_waterflowlayoutmode)             | ArkUI_WaterFlowLayoutMode       | 定义WaterFlow组件布局模式枚举值。             |
| [ArkUI_BorderStyle](#arkui_borderstyle)                             | ArkUI_BorderStyle               | 边框线条样式枚举值。                        |
| [ArkUI_HitTestMode](#arkui_hittestmode)                             | ArkUI_HitTestMode               | 触摸测试控制枚举值。                        |
| [ArkUI_ShadowStyle](#arkui_shadowstyle)                             | ArkUI_ShadowStyle               | 阴影效果枚举值。                          |
| [ArkUI_AnimationCurve](#arkui_animationcurve)                       | ArkUI_AnimationCurve            | 动画曲线枚举值。                          |
| [ArkUI_SwiperArrow](#arkui_swiperarrow)                             | ArkUI_SwiperArrow               | Swiper导航点箭头枚举值。                   |
| [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode)       | ArkUI_SwiperNestedScrollMode    | Swiper组件和父组件的嵌套滚动模式。              |
| [ArkUI_PageFlipMode](#arkui_pageflipmode)                           | ArkUI_PageFlipMode              | Swiper组件鼠标滚轮翻页模式。                 |
| [ArkUI_SwiperAnimationMode](#arkui_swiperanimationmode)             | ArkUI_SwiperAnimationMode       | Swiper组件跳转到目标index的动画模式。          |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode)                 | ArkUI_AccessibilityMode         | 定义无障碍辅助服务模式。                      |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions)                     | ArkUI_TextCopyOptions           | 定义组件支持设置文本是否可复制粘贴。                |
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)   | ArkUI_TextHeightAdaptivePolicy  | 定义文本自适应高度的方式。                     |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)                   | ArkUI_ScrollNestedMode          | 定义嵌套滚动选项。                         |
| [ArkUI_ScrollEdge](#arkui_scrolledge)                               | ArkUI_ScrollEdge                | 定义滚动到的边缘位置。                       |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment)                     | ArkUI_ScrollAlignment           | 滚动到具体item时的对齐方式。                  |
| [ArkUI_ScrollState](#arkui_scrollstate)                             | ArkUI_ScrollState               | 定义当前滚动状态。                         |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle)                   | ArkUI_SliderBlockStyle          | 定义滑块形状。                           |
| [ArkUI_SliderDirection](#arkui_sliderdirection)                     | ArkUI_SliderDirection           | 定义滑动条滑动方向。                        |
| [ArkUI_SliderStyle](#arkui_sliderstyle)                             | ArkUI_SliderStyle               | 定义滑块与滑轨显示样式。                      |
| [ArkUI_CheckboxShape](#arkui_checkboxshape)                         | ArkUI_CheckboxShape             | 定义CheckBox组件形状。                   |
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode)                 | ArkUI_AnimationPlayMode         | 定义动画播放模式。                         |
| [ArkUI_ImageSize](#arkui_imagesize)                                 | ArkUI_ImageSize                 | 定义图片宽高样式。                         |
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor)                         | ArkUI_AdaptiveColor             | 定义取色模式。                           |
| [ArkUI_ColorMode](#arkui_colormode)                                 | ArkUI_ColorMode                 | 定义深浅色模式。                          |
| [ArkUI_SystemColorMode](#arkui_systemcolormode)                     | ArkUI_SystemColorMode           | 定义系统深浅色模式。                        |
| [ArkUI_BlurStyle](#arkui_blurstyle)                                 | ArkUI_BlurStyle                 | 定义背景模糊样式。                         |
| [ArkUI_BlurStyleActivePolicy](#arkui_blurstyleactivepolicy)         | ArkUI_BlurStyleActivePolicy     | 定义背景模糊激活策略。                       |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment)                 | ArkUI_VerticalAlignment         | 定义垂直对齐方式。                         |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment)             | ArkUI_HorizontalAlignment       | 定义语言方向对齐方式。                       |
| [ArkUI_TextOverflow](#arkui_textoverflow)                           | ArkUI_TextOverflow              | 定义文本超长时的显示方式。                     |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)               | ArkUI_ImageSpanAlignment        | 定义图片基于文本的对齐方式。                    |
| [ArkUI_ObjectFit](#arkui_objectfit)                                 | ArkUI_ObjectFit                 | 定义image填充效果。ImageSpanAlignment    |
| [ArkUI_ImageInterpolation](#arkui_imageinterpolation)               | ArkUI_ImageInterpolation        | 定义图片插值效果。                         |
| [ArkUI_DynamicRangeMode](#arkui_dynamicrangemode)                   | ArkUI_DynamicRangeMode          | 定义图像动态范围模式（例如：SDR/HDR），用于控制图像的明暗与色彩显示范围。 |
| [ArkUI_ImageRotateOrientation](#arkui_imagerotateorientation)       | ArkUI_ImageRotateOrientation    | 定义图像旋转方向。                         |
| [ArkUI_BlendMode](#arkui_blendmode)                                 | ArkUI_BlendMode                 | 混合模式枚举值。                          |
| [ArkUI_Direction](#arkui_direction)                                 | ArkUI_Direction                 | 设置容器元素内主轴方向上的布局枚举值。               |
| [ArkUI_ItemAlignment](#arkui_itemalignment)                         | ArkUI_ItemAlignment             | 设置子组件在父容器交叉轴的对齐格式枚举值。             |
| [ArkUI_ColorStrategy](#arkui_colorstrategy)                         | ArkUI_ColorStrategy             | 前景色枚举值。                           |
| [ArkUI_FlexAlignment](#arkui_flexalignment)                         | ArkUI_FlexAlignment             | 定义垂直方向对齐方式。                       |
| [ArkUI_FlexDirection](#arkui_flexdirection)                         | ArkUI_FlexDirection             | 定义Flex容器的主轴方向。                    |
| [ArkUI_FlexWrap](#arkui_flexwrap)                                   | ArkUI_FlexWrap                  | 定义Flex行列布局模式模式。                   |
| [ArkUI_Visibility](#arkui_visibility)                               | ArkUI_Visibility                | 控制组件的显隐枚举值。                       |
| [ArkUI_CalendarAlignment](#arkui_calendaralignment)                 | ArkUI_CalendarAlignment         | 日历选择器与入口组件对齐方式。                   |
| [ArkUI_MaskType](#arkui_masktype)                                   | ArkUI_MaskType                  | 遮罩类型枚举。                           |
| [ArkUI_ClipType](#arkui_cliptype)                                   | ArkUI_ClipType                  | 裁剪类型枚举。                           |
| [ArkUI_ShapeType](#arkui_shapetype)                                 | ArkUI_ShapeType                 | 自定义形状。                            |
| [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection)     | ArkUI_LinearGradientDirection   | 定义渐变方向结构。                         |
| [ArkUI_WordBreak](#arkui_wordbreak)                                 | ArkUI_WordBreak                 | 定义文本断行规则。                         |
| [ArkUI_EllipsisMode](#arkui_ellipsismode)                           | ArkUI_EllipsisMode              | 定义文本省略位置。                         |
| [ArkUI_ImageRenderMode](#arkui_imagerendermode)                     | ArkUI_ImageRenderMode           | 定义图片渲染模式。                         |
| [ArkUI_TransitionEdge](#arkui_transitionedge)                       | ArkUI_TransitionEdge            | 定义转场从边缘滑入和滑出的效果。                  |
| [ArkUI_FinishCallbackType](#arkui_finishcallbacktype)               | ArkUI_FinishCallbackType        | 在动画中定义onFinish回调的类型。              |
| [ArkUI_ListItemAlignment](#arkui_listitemalignment)                 | ArkUI_ListItemAlignment         | 交叉轴方向的布局方式。                       |
| [ArkUI_BlendApplyType](#arkui_blendapplytype)                       | ArkUI_BlendApplyType            | 指定的混合模式应用于视图的内容选项.                |
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit)                   | ArkUI_LengthMetricUnit          | 定义组件的单位模式。                        |
| [ArkUI_TextInputContentType](#arkui_textinputcontenttype)           | ArkUI_TextInputContentType      | 定义自动填充类型。                         |
| [ArkUI_BarrierDirection](#arkui_barrierdirection)                   | ArkUI_BarrierDirection          | 定义屏障线的方向。                         |
| [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle)   | ArkUI_RelativeLayoutChainStyle  | 定义链的风格。                           |
| [ArkUI_TextInputStyle](#arkui_textinputstyle)                       | ArkUI_TextInputStyle            | 定义输入框风格。                          |
| [ArkUI_KeyboardAppearance](#arkui_keyboardappearance)               | ArkUI_KeyboardAppearance        | 定义输入框拉起的键盘样式。                     |
| [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype)           | ArkUI_TextDataDetectorType      | 定义文本识别的实体类型。                      |
| [ArkUI_ButtonType](#arkui_buttontype)                               | ArkUI_ButtonType                | 定义按钮样式枚举值。                        |
| [ArkUI_RenderFit](#arkui_renderfit)                                 | ArkUI_RenderFit   | 定义动画终态内容大小与位置的枚举值。 |
| [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype)             | ArkUI_SwiperIndicatorType       | 定义 Swiper 组件的导航指示器类型。             |
| [ArkUI_AnimationDirection](#arkui_animationdirection)               | ArkUI_AnimationDirection        | 动画播放模式。                           |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate)   | ArkUI_ListItemSwipeActionState  | 定义 Listitem 组件SwipeAction方法的显隐模式。 |
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect)     | ArkUI_ListItemSwipeEdgeEffect   | 定义 Listitem 组件SwipeAction方法的滚动模式。 |
| [ArkUI_AnimationStatus](#arkui_animationstatus)                     | ArkUI_AnimationStatus           | 定义帧动画的播放状态。                       |
| [ArkUI_AnimationFillMode](#arkui_animationfillmode)                 | ArkUI_AnimationFillMode         | 定义帧动画组件在动画开始前和结束后的状态。             |
| [ArkUI_ErrorCode](#arkui_errorcode)                                 | ArkUI_ErrorCode                 | 定义错误码枚举值。                         |
| [ArkUI_ScrollSource](#arkui_scrollsource)                           | ArkUI_ScrollSource              | 定义滚动来源枚举值。                        |
| [ArkUI_SafeAreaType](#arkui_safeareatype)                           | ArkUI_SafeAreaType              | 定义扩展安全区域的枚举值。                     |
| [ArkUI_SafeAreaEdge](#arkui_safeareaedge)                           | ArkUI_SafeAreaEdge              | 定义扩展安全区域的方向的枚举值。                  |
| [ArkUI_FocusMove](#arkui_focusmove)                                 | ArkUI_FocusMove                 | 定义焦点移动方向的枚举值。                     |
| [ArkUI_ListItemGroupArea](#arkui_listitemgrouparea)                 | ArkUI_ListItemGroupArea         | 定义 ListItemGroup 组件区域。            |
| [ArkUI_KeyboardAvoidMode](#arkui_keyboardavoidmode)                 | ArkUI_KeyboardAvoidMode         | 键盘避让模式。                           |
| [ArkUI_HoverModeAreaType](#arkui_hovermodeareatype)                 | ArkUI_HoverModeAreaType         | 悬停态显示区域。                          |
| [ArkUI_ExpandMode](#arkui_expandmode)                               | ArkUI_ExpandMode                | 定义子节点展开模式枚举值。                     |
| [ArkUI_NavDestinationState](#arkui_navdestinationstate)             | ArkUI_NavDestinationState       | 定义NavDestination组件的状态。            |
| [ArkUI_RouterPageState](#arkui_routerpagestate)                     | ArkUI_RouterPageState           | 定义Router Page的状态。                 |
| [ArkUI_UIState](#arkui_uistate)                                     | ArkUI_UIState                   | 组件的UI状态枚举，用于处理状态样式。               |
| [ArkUI_FocusWrapMode](#arkui_focuswrapmode)                         | ArkUI_FocusWrapMode             | 组件走焦换行规则。                         |
| [ArkUI_EdgeDirection](#arkui_edgedirection)                         | ArkUI_EdgeDirection             | 定义矩形边方向。                         |
| [ArkUI_CornerDirection](#arkui_cornerdirection)                     | ArkUI_CornerDirection           | 定义角度方向。                         |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()](#oh_arkui_layoutconstraint_create) | 创建约束尺寸。 |
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_copy) | 约束尺寸深拷贝。 |
| [void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_dispose) | 销毁约束尺寸指针。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxwidth) | 通过约束尺寸获取最大宽度，单位为px。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminwidth) | 通过约束尺寸获取最小宽度，单位为px。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxheight) | 通过约束尺寸获取最大高度，单位为px。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminheight) | 通过约束尺寸获取最小高度，单位为px。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferencewidth) | 通过约束尺寸获取宽度百分比基准，单位为px。 |
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferenceheight) | 通过约束尺寸获取高度百分比基准，单位为px。 |
| [void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxwidth) | 设置最大宽度。 |
| [void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminwidth) | 设置最小宽度。 |
| [void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxheight) | 设置最大高度。 |
| [void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminheight) | 设置最小高度。 |
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferencewidth) | 设置宽度百分比基准。 |
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferenceheight) | 设置高度百分比基准。 |
| [void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getcanvas) | 获取绘制canvas指针，可以转换为图形库的OH_Drawing_Canvas指针进行绘制。 |
| [ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getsize) | 获取可绘制区域大小。 |
| [ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()](#oh_arkui_waterflowsectionoption_create) | 创建FlowItem分组配置信息。 |
| [void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_dispose) | 销毁FlowItem分组配置信息指针。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)](#oh_arkui_waterflowsectionoption_setsize) | 设置FlowItem分组配置信息数组长度。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_getsize) | 获取FlowItem分组配置信息数组长度。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)](#oh_arkui_waterflowsectionoption_setitemcount) | 设置分组中FlowItem数量。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getitemcount) | 通过FlowItem分组配置信息获取对应索引下的FlowItem数量。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)](#oh_arkui_waterflowsectionoption_setcrosscount) | 设置布局栅格，纵向布局时为列数，横向布局时为行数。 |
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcrosscount) | 通过FlowItem分组配置信息获取对应索引下的布局栅格数。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)](#oh_arkui_waterflowsectionoption_setcolumngap) | 设置分组的列间距。 |
| [float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcolumngap) | 通过FlowItem分组配置信息获取对应索引下的分组的列间距。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)](#oh_arkui_waterflowsectionoption_setrowgap) | 设置分组的行间距。 |
| [float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getrowgap) | 通过FlowItem分组配置信息获取对应索引下的分组的行间距。 |
| [void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)](#oh_arkui_waterflowsectionoption_setmargin) | 设置分组的外边距。 |
| [ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getmargin) | 通过FlowItem分组配置信息获取对应索引下的分组的外边距。 |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption* option, int32_t index, float(\*callback)(int32_t itemIndex))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) | 通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。 |
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) | 通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。 |
| [ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)](#oh_arkui_guidelineoption_create) | 创建RelativeContainer容器内的辅助线信息。 |
| [void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)](#oh_arkui_guidelineoption_dispose) | 销毁辅助线信息。 |
| [void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)](#oh_arkui_guidelineoption_setid) | 设置辅助线的Id。 |
| [void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)](#oh_arkui_guidelineoption_setdirection) | 设置辅助线的方向。 |
| [void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionstart) | 设置距离容器左侧或者顶部的距离。 |
| [void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionend) | 设置距离容器右侧或者底部的距离。 |
| [const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getid) | 获取辅助线的Id。 |
| [ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getdirection) | 获取辅助线的方向。 |
| [float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionstart) | 获取距离容器左侧或者顶部的距离。 |
| [float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionend) | 获取距离容器右侧或者底部的距离。 |
| [ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)](#oh_arkui_barrieroption_create) | 创建RelativeContainer容器内的屏障信息。 |
| [void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)](#oh_arkui_barrieroption_dispose) | 销毁屏障信息。 |
| [void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setid) | 设置屏障的Id。 |
| [void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)](#oh_arkui_barrieroption_setdirection) | 设置屏障的方向。 |
| [void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setreferencedid) | 设置屏障的依赖的组件。 |
| [const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getid) | 获取屏障的Id。 |
| [ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getdirection) | 获取屏障的方向。 |
| [const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)](#oh_arkui_barrieroption_getreferencedid) | 获取屏障的依赖的组件。 |
| [int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getreferencedidsize) | 获取屏障的依赖的组件的个数。 |
| [ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()](#oh_arkui_alignmentruleoption_create) | 创建相对容器中子组件的对齐规则信息。 |
| [void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_dispose) | 销毁相对容器中子组件的对齐规则信息。 |
| [void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setstart) | 设置左对齐参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setend) | 设置右对齐参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setcenterhorizontal) | 设置横向居中对齐方式的参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_settop) | 设置顶部对齐的参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setbottom) | 设置底部对齐的参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setcentervertical) | 设置纵向居中对齐方式的参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)](#oh_arkui_alignmentruleoption_setbiashorizontal) | 设置组件在锚点约束下的水平方向上偏移参数。 |
| [void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)](#oh_arkui_alignmentruleoption_setbiasvertical) | 设置组件在锚点约束下的垂直方向上偏移参数。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartid) | 获取左对齐参数的Id。 |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartalignment) | 获取左对齐参数的对齐方式。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendid) | 获取右对齐参数。 |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendalignment) | 获取右对齐参数。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridhorizontal) | 获取横向居中对齐方式的参数。 |
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) | 获取横向居中对齐方式的参数。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopid) | 获取顶部对齐的参数。 |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopalignment) | 获取顶部对齐的参数。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomid) | 获取底部对齐的参数。 |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomalignment) | 获取底部对齐的参数。 |
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridvertical) | 获取纵向居中对齐方式的参数。 |
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) | 获取纵向居中对齐方式的参数。 |
| [float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiashorizontal) | 获取水平方向上的bias值。 |
| [float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiasvertical) | 获取垂直方向上的bias值。 |
| [ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type)](#oh_arkui_swiperindicator_create) | 创建 Swiper 组件的导航指示器。 |
| [void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_dispose) | 销毁Swiper组件的导航指示器指针。 |
| [void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setstartposition) | 设置导航点距离 Swiper 组件左边的距离。 |
| [float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getstartposition) | 获取导航点距离 Swiper 组件左边的距离。 |
| [void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_settopposition) | 设置导航点距离 Swiper 组件顶部的距离。 |
| [float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_gettopposition) | 获取导航点距离 Swiper 组件顶部的距离。 |
| [void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setendposition) | 设置导航点距离 Swiper 组件右边的距离。 |
| [float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getendposition) | 获取导航点距离 Swiper 组件右边的距离。 |
| [void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setbottomposition) | 设置导航点距离 Swiper 组件底部的距离。 |
| [float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getbottomposition) | 获取导航点距离 Swiper 组件底部的距离。 |
| [void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize)](#oh_arkui_swiperindicator_setignoresizeofbottom) | 设置OH_ArkUI_SwiperIndicator_SetBottomPosition是否忽略导航点大小。 |
| [int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getignoresizeofbottom) | 获取OH_ArkUI_SwiperIndicator_SetBottomPosition是否忽略导航点大小。 |
| [void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setitemwidth) | 设置 Swiper 组件圆点导航指示器的宽。 |
| [float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getitemwidth) | 获取 Swiper 组件圆点导航指示器的宽。 |
| [void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setitemheight) | 设置 Swiper 组件圆点导航指示器的高。 |
| [float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getitemheight) | 获取 Swiper 组件圆点导航指示器的高。 |
| [void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setselecteditemwidth) | 设置被选中的 Swiper 组件圆点导航指示器的宽。 |
| [float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselecteditemwidth) | 获取被选中 Swiper 组件圆点导航指示器的宽。 |
| [void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setselecteditemheight) | 设置被选中的 Swiper 组件圆点导航指示器的高。 |
| [float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselecteditemheight) | 获取被选中 Swiper 组件圆点导航指示器的高。 |
| [void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask)](#oh_arkui_swiperindicator_setmask) | 设置是否显示 Swiper 组件圆点导航指示器的蒙版样式。 |
| [int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getmask) | 获取是否显示 Swiper 组件圆点导航指示器的蒙版样式。 |
| [void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color)](#oh_arkui_swiperindicator_setcolor) | 设置 Swiper 组件圆点导航指示器的颜色。 |
| [uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getcolor) | 获取 Swiper 组件圆点导航指示器的颜色。 |
| [void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor)](#oh_arkui_swiperindicator_setselectedcolor) | 设置被选中 Swiper 组件圆点导航指示器的颜色。 |
| [uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselectedcolor) | 获取被选中 Swiper 组件圆点导航指示器的颜色。 |
| [int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount)](#oh_arkui_swiperindicator_setmaxdisplaycount) | 设置圆点导航点指示器样式下，导航点显示个数的最大值。 |
| [int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getmaxdisplaycount) | 获取圆点导航点指示器样式下，导航点显示个数的最大值。 |
| [ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create()](#oh_arkui_swiperdigitindicator_create) | 创建 Swiper 组件的数字导航指示器。 |
| [void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_destroy) | 销毁Swiper组件的数字导航指示器指针。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setstartposition) | 设置数字导航指示器距离 Swiper 组件左边的距离，在从右至左显示的语言模式下，设置其距离 Swiper 组件右边的距离。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getstartposition) | 获取数字导航指示器距离 Swiper 组件左边的距离，在从右至左显示的语言模式下，获取其距离 Swiper 组件右边的距离。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_settopposition) | 设置数字导航指示器距离 Swiper 组件顶部的距离。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_gettopposition) | 获取数字导航指示器距离 Swiper 组件顶部的距离。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setendposition) | 设置数字导航指示器距离 Swiper 组件右边的距离，在从右至左显示的语言模式下，设置其距离 Swiper 组件左边的距离。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getendposition) | 获取数字导航指示器距离 Swiper 组件右边的距离，在从右至左显示的语言模式下，获取其距离 Swiper 组件左边的距离。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setbottomposition) | 设置数字导航指示器距离 Swiper 组件底部的距离。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getbottomposition) | 获取数字导航指示器距离 Swiper 组件底部的距离。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color)](#oh_arkui_swiperdigitindicator_setfontcolor) | 设置 Swiper 组件数字导航指示器字体颜色。 |
| [uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontcolor) | 获取 Swiper 组件数字导航指示器字体颜色。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor)](#oh_arkui_swiperdigitindicator_setselectedfontcolor) | 设置被选中 Swiper 组件数字导航指示器字体颜色。 |
| [uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontcolor) | 获取被选中 Swiper 组件数字导航指示器字体颜色。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)](#oh_arkui_swiperdigitindicator_setfontsize) | 设置 Swiper 组件数字导航指示器字体大小。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontsize) | 获取 Swiper 组件数字导航指示器字体大小。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)](#oh_arkui_swiperdigitindicator_setselectedfontsize) | 设置被选中 Swiper 组件数字导航指示器字体大小。 |
| [float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontsize) | 获取被选中 Swiper 组件数字导航指示器字体大小。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)](#oh_arkui_swiperdigitindicator_setfontweight) | 设置 Swiper 组件数字导航指示器字体粗细属性。 |
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontweight) | 获取 Swiper 组件数字导航指示器字体粗细属性。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)](#oh_arkui_swiperdigitindicator_setselectedfontweight) | 设置被选中 Swiper 组件数字导航指示器字体粗细属性。 |
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontweight) | 获取被选中 Swiper 组件数字导航指示器字体粗细属性。 |
| [ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create()](#oh_arkui_swiperarrowstyle_create) | 创建 Swiper 组件的导航箭头。 |
| [void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_destroy) | 销毁 Swiper 组件的导航箭头指针。 |
| [void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showBackground)](#oh_arkui_swiperarrowstyle_setshowbackground) | 设置 Swiper 组件导航箭头底板是否显示。 |
| [int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getshowbackground) | 获取 Swiper 组件导航箭头底板是否显示。 |
| [void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle)](#oh_arkui_swiperarrowstyle_setshowsidebarmiddle) | 设置 Swiper 组件导航箭头显示位置。 |
| [int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getshowsidebarmiddle) | 获取 Swiper 组件导航箭头显示位置。 |
| [void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize)](#oh_arkui_swiperarrowstyle_setbackgroundsize) | 设置 Swiper 组件导航箭头底板大小。 |
| [float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getbackgroundsize) | 获取 Swiper 组件导航箭头底板大小。 |
| [void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t backgroundColor)](#oh_arkui_swiperarrowstyle_setbackgroundcolor) | 设置 Swiper 组件导航箭头底板颜色。 |
| [uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getbackgroundcolor) | 获取 Swiper 组件导航箭头底板颜色。 |
| [void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize)](#oh_arkui_swiperarrowstyle_setarrowsize) | 设置 Swiper 组件导航箭头大小。 |
| [float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getarrowsize) | 获取 Swiper 组件导航箭头大小。 |
| [void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor)](#oh_arkui_swiperarrowstyle_setarrowcolor) | 设置 Swiper 组件导航箭头颜色。 |
| [uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getarrowcolor) | 获取 Swiper 组件导航箭头颜色。 |
| [void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space)](#oh_arkui_swiperindicator_setspace) | 设置导航点间距。 |
| [float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getspace) | 获取导航点间距。 |
| [void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize)](#oh_arkui_swiperdigitindicator_setignoresizeofbottom) | 设置OH_ArkUI_SwiperDigitIndicator_SetBottomPosition是否忽略导航点大小。 |
| [int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getignoresizeofbottom) | 获取OH_ArkUI_SwiperDigitIndicator_SetBottomPosition是否忽略导航点大小。 |
| [ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()](#oh_arkui_listitemswipeactionitem_create) | 创建ListItemSwipeActionItem接口设置的配置项。 |
| [void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_dispose) | 销毁ListItemSwipeActionItem实例。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)](#oh_arkui_listitemswipeactionitem_setcontent) | 设置ListItemSwipeActionItem的布局内容。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)](#oh_arkui_listitemswipeactionitem_setactionareadistance) | 设置组件长距离滑动删除距离阈值。 |
| [float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_getactionareadistance) | 获取组件长距离滑动删除距离阈值。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonenteractionarea) | 设置滑动条目进入删除区域时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonenteractionareawithuserdata) | 设置滑动条目进入删除区域时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonaction) | 设置组件进入长距删除区后删除ListItem时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonactionwithuserdata) | 设置组件进入长距删除区后删除ListItem时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonexitactionarea) | 设置滑动条目退出删除区域时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonexitactionareawithuserdata) | 设置滑动条目退出删除区域时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem* item,void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState))](#oh_arkui_listitemswipeactionitem_setonstatechange) | 设置列表项滑动状态变化时候触发的事件。 |
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))](#oh_arkui_listitemswipeactionitem_setonstatechangewithuserdata) | 设置列表项滑动状态变化时候触发的事件。 |
| [ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()](#oh_arkui_listitemswipeactionoption_create) | 创建ListItemSwipeActionOption接口设置的配置项。 |
| [void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_dispose) | 销毁ListItemSwipeActionOption实例。 |
| [void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setstart) | 设置ListItemSwipeActionItem的左侧（垂直布局）或上方（横向布局）布局内容。 |
| [void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setend) | 设置ListItemSwipeActionItem的右侧（垂直布局）或下方（横向布局）布局内容。 |
| [void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeEdgeEffect edgeEffect)](#oh_arkui_listitemswipeactionoption_setedgeeffect) | 设置滑动效果。 |
| [int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_getedgeeffect) | 获取滑动效果。 |
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option, void (\*callback)(float offset))](#oh_arkui_listitemswipeactionoption_setonoffsetchange) | 滑动操作偏移量更改时调用的事件。 |
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData (ArkUI_ListItemSwipeActionOption* option, void* userData, void (\*callback)(float offset, void* userData))](#oh_arkui_listitemswipeactionoption_setonoffsetchangewithuserdata) | 滑动操作偏移量更改时调用的事件。 |
| [ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)](#oh_arkui_accessibilitystate_create) | 创建无障碍状态。 |
| [void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_dispose) | 销毁无障碍状态指针。 |
| [void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)](#oh_arkui_accessibilitystate_setdisabled) | 设置无障碍状态是否禁用。 |
| [int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isdisabled) | 获取无障碍状态是否禁用。 |
| [void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)](#oh_arkui_accessibilitystate_setselected) | 设置无障碍状态是否选中。 |
| [int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isselected) | 获取无障碍状态是否选中。 |
| [void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)](#oh_arkui_accessibilitystate_setcheckedstate) | 设置无障碍状态复选框状态。 |
| [int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_getcheckedstate) | 获取无障碍状态复选框状态。 |
| [ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)](#oh_arkui_accessibilityvalue_create) | 创建无障碍信息。 |
| [void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_dispose) | 销毁无障碍信息指针。 |
| [void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)](#oh_arkui_accessibilityvalue_setmin) | 设置无障碍最小值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmin) | 获取无障碍最小值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)](#oh_arkui_accessibilityvalue_setmax) | 设置无障碍最大值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmax) | 获取无障碍最大值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)](#oh_arkui_accessibilityvalue_setcurrent) | 设置无障碍当前值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getcurrent) | 获取无障碍当前值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)](#oh_arkui_accessibilityvalue_setrangemin) | 设置范围组件的无障碍最小值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemin) | 获取范围组件的无障碍最小值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)](#oh_arkui_accessibilityvalue_setrangemax) | 设置范围组件的无障碍最大值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemax) | 获取范围组件的无障碍最大值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)](#oh_arkui_accessibilityvalue_setrangecurrent) | 用于设置范围组件的无障碍当前值信息。 |
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangecurrent) | 用于获取范围组件的无障碍当前值信息。 |
| [void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)](#oh_arkui_accessibilityvalue_settext) | 设置无障碍文本描述信息。 |
| [const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_gettext) | 获取无障碍文本描述信息。 |
| [ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src)](#oh_arkui_imageanimatorframeinfo_createfromstring) | 使用图片路径创建帧图片信息，图片格式为svg，png和jpg。 |
| [ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(ArkUI_DrawableDescriptor* drawable)](#oh_arkui_imageanimatorframeinfo_createfromdrawabledescriptor) | 使用 DrawableDescriptor 对象创建帧图片信息，图片格式为Resource和PixelMap。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_dispose) | 销毁帧图片对象指针。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width)](#oh_arkui_imageanimatorframeinfo_setwidth) | 设置图片宽度。 |
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getwidth) | 获取图片宽度。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height)](#oh_arkui_imageanimatorframeinfo_setheight) | 设置图片高度。 |
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getheight) | 获取图片高度。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top)](#oh_arkui_imageanimatorframeinfo_settop) | 设置图片相对于组件左上角的纵向坐标。 |
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_gettop) | 获取图片相对于组件左上角的纵向坐标。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left)](#oh_arkui_imageanimatorframeinfo_setleft) | 设置图片相对于组件左上角的横向坐标。 |
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getleft) | 获取图片相对于组件左上角的横向坐标。 |
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration)](#oh_arkui_imageanimatorframeinfo_setduration) | 设置图片的播放时长。 |
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getduration) | 获取图片的播放时长。 |
| [ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()](#oh_arkui_listchildrenmainsizeoption_create) | 创建ListChildrenMainSize接口设置的配置项。 |
| [void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_dispose) | 销毁ListChildrenMainSize实例。 |
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)](#oh_arkui_listchildrenmainsizeoption_setdefaultmainsize) | 设置List组件的ChildrenMainSizeOption默认大小。 |
| [float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_getdefaultmainsize) | 获取List组件的ChildrenMainSizeOption默认大小。 |
| [void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)](#oh_arkui_listchildrenmainsizeoption_resize) | 重置List组件的ChildrenMainSizeOption的数组大小。 |
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)](#oh_arkui_listchildrenmainsizeoption_splice) | 对List组件的ChildrenMainSizeOption数组操作大小调整。 |
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)](#oh_arkui_listchildrenmainsizeoption_updatesize) | 更新List组件的ChildrenMainSizeOption数组的值。 |
| [float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)](#oh_arkui_listchildrenmainsizeoption_getmainsize) | 获取List组件的ChildrenMainSizeOption数组的值。 |
| [ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)](#oh_arkui_customspanmeasureinfo_create) | 创建自定义段落组件测量信息。 |
| [void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_dispose) | 销毁自定义段落组件测量信息。 |
| [float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_getfontsize) | 获取自定义段落组件的父节点Text的字体大小。 |
| [ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)](#oh_arkui_customspanmetrics_create) | 创建自定义段落组件度量信息。 |
| [void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)](#oh_arkui_customspanmetrics_dispose) | 销毁自定义段落组件度量信息。 |
| [int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)](#oh_arkui_customspanmetrics_setwidth) | 设置自定义段落组件的宽度。 |
| [int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)](#oh_arkui_customspanmetrics_setheight) | 设置自定义段落组件的高度。 |
| [ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)](#oh_arkui_customspandrawinfo_create) | 创建自定义段落组件绘制信息。 |
| [void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_dispose) | 销毁自定义段落组件绘制信息。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getxoffset) | 获取自定义段落组件相对于挂载组件的x轴偏移值。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinetop) | 获取自定义段落组件相对于挂载组件的上边距。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinebottom) | 获取自定义段落组件相对于挂载组件的下边距。 |
| [float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getbaseline) | 获取自定义段落组件相对于挂载组件的基线偏移量。 |
| [void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_destroy) | 销毁CustomProperty实例。 |
| [const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_getstringvalue) | 获取自定义属性value信息。 |
| [const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_getname) | 获取HostWindowInfo对象中的窗口名称。 |
| [void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_destroy) | 销毁HostWindowInfo对象。 |
| [void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_destroy) | 销毁ActiveChildrenInfo实例。 |
| [ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)](#oh_arkui_activechildreninfo_getnodebyindex) | 获取ActiveChildrenInfo结构体的下标为index的子节点。 |
| [int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_getcount) | 获取ActiveChildrenInfo结构体内的节点数量。 |
| [ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)](#oh_arkui_progresslinearstyleoption_create) | 创建线性进度条样式信息。 |
| [void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_destroy) | 销毁线性进度条样式信息。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setsmootheffectenabled) | 设置进度平滑动效的开关。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setscaneffectenabled) | 设置扫光效果的开关。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)](#oh_arkui_progresslinearstyleoption_setstrokewidth) | 设置进度条宽度。 |
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)](#oh_arkui_progresslinearstyleoption_setstrokeradius) | 设置进度条圆角半径。 |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getsmootheffectenabled) | 获取进度平滑动效的开关信息。 |
| [bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getscaneffectenabled) | 获取扫光效果的开关信息。 |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokewidth) | 获取进度条宽度。 |
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokeradius) | 获取进度条圆角半径值。 |
| [ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()](#oh_arkui_createsnapshotoptions) | 创建一个截图选项，当返回值不再使用时必须通过[OH_ArkUI_DestroySnapshotOptions()](#oh_arkui_destroysnapshotoptions)释放。 |
| [void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)](#oh_arkui_destroysnapshotoptions) | 销毁截图选项指针。 |
| [int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)](#oh_arkui_snapshotoptions_setscale) | 配置截图选项中的缩放属性。 |
| [ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)](#oh_arkui_crosslanguageoption_create) | 创建跨语言配置项实例。 |
| [void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_destroy) | 销毁跨语言配置项实例。 |
| [void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)](#oh_arkui_crosslanguageoption_setattributesettingstatus) | 设置配置项中是否允许跨语言修改属性。 |
| [bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_getattributesettingstatus) | 获取配置项中是否允许跨语言修改属性。 |
| [ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()](#oh_arkui_visibleareaeventoptions_create) | 创建可见区域变化监听的参数。 |
| [void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_dispose) | 销毁可见区域变化监听的参数。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)](#oh_arkui_visibleareaeventoptions_setratios) | 设置阈值数组。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)](#oh_arkui_visibleareaeventoptions_setexpectedupdateinterval) | 设置预期更新间隔，单位为ms。定义了开发者期望的更新间隔。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)](#oh_arkui_visibleareaeventoptions_getratios) | 获取阈值数组。 |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_getexpectedupdateinterval) | 获取预期更新间隔。 |
| [ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)](#oh_arkui_textpickerrangecontentarray_create) | 创建TextPickerRangeContent数组的对象。 |
| [void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)](#oh_arkui_textpickerrangecontentarray_seticonatindex) | 指定TextPickerRangeContent数组指定位置的icon数据。 |
| [void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textpickerrangecontentarray_settextatindex) | 指定TextPickerRangeContent数组指定位置的text数据。 |
| [void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)](#oh_arkui_textpickerrangecontentarray_destroy) | 删除TextPickerRangeContent数组对象。 |
| [ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)](#oh_arkui_textcascadepickerrangecontentarray_create) | 删除TextCascadePickerRangeContent数组对象。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_settextatindex) | 指定TextCascadePickerRangeContent数组指定位置的text数据。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_setchildatindex) | 指定TextCascadePickerRangeContent数组指定位置的child数据。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy (ArkUI_TextCascadePickerRangeContentArray* handle)](#oh_arkui_textcascadepickerrangecontentarray_destroy) | 删除TextCascadePickerRangeContent数组对象。 |
| [ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()](#oh_arkui_embeddedcomponentoption_create) | 创建EmbeddedComponent组件选项的对象。 |
| [void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)](#oh_arkui_embeddedcomponentoption_dispose) | 删除EmbeddedComponent组件选项的对象。 |
| [void OH_ArkUI_EmbeddedComponentOption_SetOnError (ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, const char* name, const char* message))](#oh_arkui_embeddedcomponentoption_setonerror) | 设置EmbeddedComponent组件的onError回调。EmbeddedComponent组件在运行过程中发生异常时触发本回调。 |
| [void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated (ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, AbilityBase_Want* want))](#oh_arkui_embeddedcomponentoption_setonterminated) | 设置EmbeddedComponent组件的onTerminated回调。EmbeddedComponent组件正常退出时触发本回调。 |

## 枚举类型说明

### ArkUI_Alignment

```
enum ArkUI_Alignment
```

**描述：**


定义布局对齐枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ALIGNMENT_TOP_START = 0 | 顶部起始。 |
| ARKUI_ALIGNMENT_TOP | 顶部居中。 |
| ARKUI_ALIGNMENT_TOP_END | 顶部尾端。 |
| ARKUI_ALIGNMENT_START | 起始端纵向居中。 |
| ARKUI_ALIGNMENT_CENTER | 横向和纵向居中。 |
| ARKUI_ALIGNMENT_END | 尾端纵向居中。 |
| ARKUI_ALIGNMENT_BOTTOM_START | 底部起始端。 |
| ARKUI_ALIGNMENT_BOTTOM | 底部横向居中。 |
| ARKUI_ALIGNMENT_BOTTOM_END | 底部尾端。 |

### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat
```

**描述：**


定义图片重复铺设枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMAGE_REPEAT_NONE = 0 | 不重复。 |
| ARKUI_IMAGE_REPEAT_X | 在X轴方向重复。 |
| ARKUI_IMAGE_REPEAT_Y | 在Y轴方向重复。 |
| ARKUI_IMAGE_REPEAT_XY | 在X轴和Y轴方向重复。 |

### ArkUI_FontStyle

```
enum ArkUI_FontStyle
```

**描述：**


定义字体样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FONT_STYLE_NORMAL = 0 | 标准字体样式。 |
| ARKUI_FONT_STYLE_ITALIC | 斜体字体样式。 |

### ArkUI_FontWeight

```
enum ArkUI_FontWeight
```

**描述：**


定义字体粗细/字重枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FONT_WEIGHT_W100 = 0 | 100 |
| ARKUI_FONT_WEIGHT_W200 | 200 |
| ARKUI_FONT_WEIGHT_W300 | 300 |
| ARKUI_FONT_WEIGHT_W400 | 400 |
| ARKUI_FONT_WEIGHT_W500 | 500 |
| ARKUI_FONT_WEIGHT_W600 | 600 |
| ARKUI_FONT_WEIGHT_W700 | 700 |
| ARKUI_FONT_WEIGHT_W800 | 800 |
| ARKUI_FONT_WEIGHT_W900 | 900 |
| ARKUI_FONT_WEIGHT_BOLD | 字体较粗。 |
| ARKUI_FONT_WEIGHT_NORMAL | 字体粗细正常。 |
| ARKUI_FONT_WEIGHT_BOLDER | 字体非常粗。 |
| ARKUI_FONT_WEIGHT_LIGHTER | 字体较细。 |
| ARKUI_FONT_WEIGHT_MEDIUM | 字体粗细适中。 |
| ARKUI_FONT_WEIGHT_REGULAR | 字体粗细正常。 |

### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```

**描述：**


定义字体水平对齐样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_ALIGNMENT_START = 0 | 水平对齐首部。 |
| ARKUI_TEXT_ALIGNMENT_CENTER | 水平居中对齐。 |
| ARKUI_TEXT_ALIGNMENT_END | 水平对齐尾部。 |
| ARKUI_TEXT_ALIGNMENT_JUSTIFY | 双端对齐。 |

### ArkUI_TextVerticalAlignment

```
enum ArkUI_TextVerticalAlignment
```

**描述：**


定义文本垂直对齐样式枚举值。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0 | 基线对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM | 底部对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER | 居中对齐。 |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP | 顶部对齐。 |

### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType
```

**描述：**


定义单行文本输入法回车键类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ENTER_KEY_TYPE_GO = 2 | 显示为开始样式。 |
| ARKUI_ENTER_KEY_TYPE_SEARCH = 3 | 显示为搜索样式。 |
| ARKUI_ENTER_KEY_TYPE_SEND | 显示为发送样式。 |
| ARKUI_ENTER_KEY_TYPE_NEXT | 显示为下一个样式。 |
| ARKUI_ENTER_KEY_TYPE_DONE | 显示为完成样式。 |
| ARKUI_ENTER_KEY_TYPE_PREVIOUS | 显示为上一个样式。 |
| ARKUI_ENTER_KEY_TYPE_NEW_LINE | 显示为换行样式。 |

### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```

**描述：**


定义单行文本输入法类型枚举值。

**起始版本：** 12

| 枚举项 | 描述                       |
| -- |--------------------------|
| ARKUI_TEXTINPUT_TYPE_NORMAL = 0 | 基本输入模式。                  |
| ARKUI_TEXTINPUT_TYPE_NUMBER = 2 | 纯数字模式。                   |
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3 | 电话号码输入模式。                |
| ARKUI_TEXTINPUT_TYPE_EMAIL = 5 | 邮箱地址输入模式。                |
| ARKUI_TEXTINPUT_TYPE_PASSWORD = 7 | 密码输入模式。                  |
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8 | 纯数字密码输入模式。               |
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9 | 锁屏应用密码输入模式。              |
| ARKUI_TEXTINPUT_TYPE_USER_NAME = 10 | 用户名输入模式。                 |
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11 | 新密码输入模式。                 |
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12 | 带小数点的数字输入模式。             |
| ARKUI_TEXTINPUT_TYPE_ONE_TIME_CODE = 14 | 验证码输入模式。<br>**起始版本：** 20 |

### ArkUI_TextAreaType

```
enum ArkUI_TextAreaType
```

**描述：**


定义多行文本输入法类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTAREA_TYPE_NORMAL = 0 | 基本输入模式。 |
| ARKUI_TEXTAREA_TYPE_NUMBER = 2 | 纯数字模式。 |
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3 | 电话号码输入模式。 |
| ARKUI_TEXTAREA_TYPE_EMAIL = 5 | 邮箱地址输入模式。 |
| ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14 | 验证码输入模式。<br>**起始版本：** 20 |

### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```

**描述：**


定义清除按钮样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0 | 清除按钮常显样式。 |
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE | 清除按钮常隐样式。 |
| ARKUI_CANCELBUTTON_STYLE_INPUT | 清除按钮输入样式。 |

### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```

**描述：**


定义XComponent类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_XCOMPONENT_TYPE_SURFACE = 0 | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容单独显示在屏幕上。 |
| ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容和XComponent组件内容合成后展示在屏幕上。 |

### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```

**描述：**


定义进度条类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_PROGRESS_TYPE_LINEAR = 0 | 线性样式。 |
| ARKUI_PROGRESS_TYPE_RING | 环形无刻度样式。 |
| ARKUI_PROGRESS_TYPE_ECLIPSE | 圆形样式。 |
| ARKUI_PROGRESS_TYPE_SCALE_RING | 环形有刻度样式。 |
| ARKUI_PROGRESS_TYPE_CAPSULE | 胶囊样式。 |

### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```

**描述：**


定义装饰线类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DECORATION_TYPE_NONE = 0 | 不使用装饰线。 |
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE | 文字下划线修饰。 |
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE | 文字上划线修饰。 |
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH | 穿过文本的修饰线。 |

### ArkUI_TextDecorationStyle

```
enum ArkUI_TextDecorationStyle
```

**描述：**


定义装饰线样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID = 0 | 单实线。 |
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE | 双实线。 |
| ARKUI_TEXT_DECORATION_STYLE_DOTTED | 点线。 |
| ARKUI_TEXT_DECORATION_STYLE_DASHED | 虚线。 |
| ARKUI_TEXT_DECORATION_STYLE_WAVY | 波浪线。 |

### ArkUI_TextCase

```
enum ArkUI_TextCase
```

**描述：**


定义文本大小写枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_CASE_NORMAL = 0 | 保持原有大小写。 |
| ARKUI_TEXT_CASE_LOWER | 文本全小写。 |
| ARKUI_TEXT_CASE_UPPER | 文本全大写。 |

### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions
```

**描述：**


定义文本复制粘贴模式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_COPY_OPTIONS_NONE = 0 | 不支持复制。 |
| ARKUI_COPY_OPTIONS_IN_APP | 支持应用内复制。 |
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE | 支持设备内复制。 |
| ARKUI_COPY_OPTIONS_CROSS_DEVICE | 支持跨设备复制。 |

### ArkUI_ShadowType

```
enum ArkUI_ShadowType
```

**描述：**


定义阴影类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SHADOW_TYPE_COLOR = 0 | 颜色。 |
| ARKUI_SHADOW_TYPE_BLUR | 模糊。 |

### ArkUI_DatePickerMode

```
enum ArkUI_DatePickerMode
```

**描述：**


定义日期选择器列显示模式的枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DATEPICKER_MODE_DATE = 0 | 默认值。日期列显示年、月、日三列。 |
| ARKUI_DATEPICKER_YEAR_AND_MONTH = 1 | 日期列显示年、月二列。 |
| ARKUI_DATEPICKER_MONTH_AND_DAY = 2 | 日期列显示月、日二列。 |

### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```

**描述：**


定义滑动选择文本选择器输入类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0 | 单列数据选择器。 |
| ARKUI_TEXTPICKER_RANGETYPE_MULTI | 多列数据选择器。 |
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT | 支持图片资源的单列数据选择器。 |
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT | 支持联动的多列数据选择器。 |

### ArkUI_AccessibilityCheckedState

```
enum ArkUI_AccessibilityCheckedState
```

**描述：**


定义无障碍复选框状态类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_UNCHECKED = 0 | 复选框未被选中。 |
| ARKUI_ACCESSIBILITY_CHECKED | 复选框被选中。 |

### ArkUI_AccessibilityActionType

```
enum ArkUI_AccessibilityActionType
```

**描述：**


定义无障碍操作类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_ACTION_CLICK = 1 << 0 | 点击操作。 |
| ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK = 1 << 1 | 长按操作。 |
| ARKUI_ACCESSIBILITY_ACTION_CUT = 1 << 2 | 剪切操作。 |
| ARKUI_ACCESSIBILITY_ACTION_COPY = 1 << 3 | 复制操作。 |
| ARKUI_ACCESSIBILITY_ACTION_PASTE = 1 << 4 | 粘贴操作。 |

### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect
```

**描述：**


定义边缘滑动效果枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_EDGE_EFFECT_SPRING = 0 | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。 |
| ARKUI_EDGE_EFFECT_FADE | 阴影效果，滑动到边缘后会有圆弧状的阴影。 |
| ARKUI_EDGE_EFFECT_NONE | 滑动到边缘后无效果。 |

### ArkUI_EffectEdge

```
enum ArkUI_EffectEdge
```

**描述：**


定义边缘效果生效边缘的方向枚举值。

**起始版本：** 18

| 枚举项 | 描述                    |
| -- |-----------------------|
| ARKUI_EFFECT_EDGE_START = 1 | 起始边生效。                |
| ARKUI_EFFECT_EDGE_END = 2 | 末尾边生效。                |

### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection
```

**描述：**


定义Scroll组件排列方向枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_DIRECTION_VERTICAL = 0 | 仅支持竖直方向滚动。 |
| ARKUI_SCROLL_DIRECTION_HORIZONTAL | 仅支持水平方向滚动。 |
| ARKUI_SCROLL_DIRECTION_NONE = 3 | 禁止滚动。 |
| ARKUI_SCROLL_DIRECTION_FREE = 4 | 自由滚动。<br>**起始版本：** 20 |

### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign
```

**描述：**


定义列表项滚动结束对齐效果枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE = 0 | 默认无项目滚动对齐效果。 |
| ARKUI_SCROLL_SNAP_ALIGN_START | 视图中的第一项将在列表的开头对齐。 |
| ARKUI_SCROLL_SNAP_ALIGN_CENTER | 视图中的中间项将在列表中心对齐。 |
| ARKUI_SCROLL_SNAP_ALIGN_END | 视图中的最后一项将在列表末尾对齐。 |

### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```

**描述：**


定义滚动条状态枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0 | 不显示。 |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO | 按需显示(触摸时显示，2s后消失)。 |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON | 常驻显示。 |

### ArkUI_Axis

```
enum ArkUI_Axis
```

**描述：**


定义滚动方向和List组件排列方向枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_AXIS_VERTICAL = 0 | 仅支持竖直方向滚动。 |
| ARKUI_AXIS_HORIZONTAL | 仅支持水平方向滚动。 |

### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle
```

**描述：**


定义列表是否吸顶和吸底枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_STICKY_STYLE_NONE = 0 | ListItemGroup的header不吸顶，footer不吸底。 |
| ARKUI_STICKY_STYLE_HEADER = 1 | ListItemGroup的header吸顶，footer不吸底。 |
| ARKUI_STICKY_STYLE_FOOTER = 2 | ListItemGroup的footer吸底，header不吸顶。 |
| ARKUI_STICKY_STYLE_BOTH = 3 | ListItemGroup的footer吸底，header吸顶。 |

### ArkUI_ContentClipMode

```
enum ArkUI_ContentClipMode
```

**描述：**


定义滚动容器的内容层裁剪区域枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0 | 按内容区裁剪。 |
| ARKUI_CONTENT_CLIP_MODE_BOUNDARY | 按组件区域裁剪。 |
| ARKUI_CONTENT_CLIP_MODE_SAFE_AREA | 按组件配置的SafeArea区域裁剪。 |

### ArkUI_WaterFlowLayoutMode

```
enum ArkUI_WaterFlowLayoutMode
```

**描述：**


定义WaterFlow组件布局模式枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0 | 从上到下布局。列数切换场景需要从第一个FlowItem开始布局到当前显示的FlowItem。 |
| ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW | 移动窗口布局。列数切换场景只重新布局当前显示范围到FlowItem，手指向下滑动再布局从上方进入显示范围的FlowItem。 |

### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle
```

**描述：**


边框线条样式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_BORDER_STYLE_SOLID = 0 | 显示为一条实线。 |
| ARKUI_BORDER_STYLE_DASHED | 显示为一系列短的方形虚线。 |
| ARKUI_BORDER_STYLE_DOTTED | 显示为一系列圆点。 |

### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode
```

**描述：**


触摸测试控制枚举值。

**起始版本：** 12

| 枚举项 | 描述                                                     |
| -- |--------------------------------------------------------|
| ARKUI_HIT_TEST_MODE_DEFAULT = 0 | 默认触摸测试效果。                                              |
| ARKUI_HIT_TEST_MODE_BLOCK | 自身响应触摸测试。                                              |
| ARKUI_HIT_TEST_MODE_TRANSPARENT | 自身和子节点都响应触摸测试。                                         |
| ARKUI_HIT_TEST_MODE_NONE | 自身不响应触摸测试。                                             |
| ARKUI_HIT_TEST_MODE_BLOCK_HIERARCHY | 阻止所有优先级较低的兄弟节点和父节点参与触摸测试，自身和子节点响应触摸测试。<br>**起始版本：** 20 |
| ARKUI_HIT_TEST_MODE_BLOCK_DESCENDANTS | 自身不响应触摸测试，并且所有的后代（孩子，孙子等）也不响应触摸测试。<br>**起始版本：** 20                     |

### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle
```

**描述：**


阴影效果枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0 | 超小阴影。 |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM | 小阴影。 |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD | 中阴影。 |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG | 大阴影。 |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM | 浮动小阴影。 |
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD | 浮动中阴影。 |

### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```

**描述：**


动画曲线枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CURVE_LINEAR = 0 | 动画从头到尾的速度都是相同。 |
| ARKUI_CURVE_EASE | 动画以低速开始，然后加快，在结束前变慢。 |
| ARKUI_CURVE_EASE_IN | 动画以低速开始。 |
| ARKUI_CURVE_EASE_OUT | 动画以低速结束。 |
| ARKUI_CURVE_EASE_IN_OUT | 动画以低速开始和结束。 |
| ARKUI_CURVE_FAST_OUT_SLOW_IN | 动画标准曲线。 |
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN | 动画减速曲线。 |
| ARKUI_CURVE_FAST_OUT_LINEAR_IN | 动画加速曲线。 |
| ARKUI_CURVE_EXTREME_DECELERATION | 动画急缓曲线。 |
| ARKUI_CURVE_SHARP | 动画锐利曲线。 |
| ARKUI_CURVE_RHYTHM | 动画节奏曲线。 |
| ARKUI_CURVE_SMOOTH | 动画平滑曲线。 |
| ARKUI_CURVE_FRICTION | 动画阻尼曲线。 |

### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow
```

**描述：**


Swiper导航点箭头枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SWIPER_ARROW_HIDE = 0 | 不显示swiper中导航点箭头。 |
| ARKUI_SWIPER_ARROW_SHOW | 显示swiper中导航点箭头。 |
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER | 在hover状态下显示swiper中导航点箭头。 |

### ArkUI_SwiperNestedScrollMode

```
enum ArkUI_SwiperNestedScrollMode
```

**描述：**


Swiper组件和父组件的嵌套滚动模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0 | Swiper只自身滚动，不与父组件联动。 |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST | Swiper自身先滚动，自身滚动到边缘以后父组件滚动。父组件滚动到边缘以后，如果父组件有边缘效果，则父组件触发边缘效果，否则Swiper触发边缘效果。 |

### ArkUI_PageFlipMode

```
enum ArkUI_PageFlipMode
```

**描述：**


Swiper组件鼠标滚轮翻页模式。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_PAGE_FLIP_MODE_CONTINUOUS = 0 | 鼠标滚轮连续滚动时翻多页，根据鼠标事件上报次数确定。 |
| ARKUI_PAGE_FLIP_MODE_SINGLE | 一次翻页动画结束前不响应其他鼠标滚轮事件。 |

### ArkUI_SwiperAnimationMode

```
enum ArkUI_SwiperAnimationMode
```

**描述：**


Swiper组件跳转到目标index的动画模式。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SWIPER_NO_ANIMATION = 0 | 无动画跳转到目标index。 |
| ARKUI_SWIPER_DEFAULT_ANIMATION = 1 | 做动画跳转到目标index。 |
| ARKUI_SWIPER_FAST_ANIMATION = 2 | 先无动画跳转到目标附近再做动画跳转到目标index。 |

### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```

**描述：**


定义无障碍辅助服务模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ACCESSIBILITY_MODE_AUTO = 0 | 根据组件不同会转换为“enabled”或者“disabled”。 |
| ARKUI_ACCESSIBILITY_MODE_ENABLED | 当前组件可被无障碍辅助服务所识别。 |
| ARKUI_ACCESSIBILITY_MODE_DISABLED | 当前组件不可被无障碍辅助服务所识别。 |
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS | 当前组件及其所有子组件不可被无障碍辅助服务所识别。 |

### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```

**描述：**


定义组件支持设置文本是否可复制粘贴。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_COPY_OPTIONS_NONE = 0 | 不支持复制。 |
| ARKUI_TEXT_COPY_OPTIONS_IN_APP | 支持应用内复制。 |
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE | 支持设备内复制。 |
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE | 支持跨设备复制。 |

### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```

**描述：**


定义文本自适应高度的方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0 | 设置文本高度自适应方式为以MaxLines优先。 |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST | 设置文本高度自适应方式为以缩小字体优先。 |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST | 设置文本高度自适应方式为以布局约束（高度）优先。 |

### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode
```

**描述：**


定义嵌套滚动选项。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0 | 只自身滚动，不与父组件联动。 |
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST | 自身先滚动，自身滚动到边缘以后父组件滚动。父组件滚动到边缘以后 |
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST | 父组件先滚动，父组件滚动到边缘以后自身滚动。 |
| ARKUI_SCROLL_NESTED_MODE_PARALLEL | 自身和父组件同时滚动，自身和父组件都到达边缘以后 |

### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge
```

**描述：**


定义滚动到的边缘位置。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_EDGE_TOP = 0 | 竖直方向上边缘。 |
| ARKUI_SCROLL_EDGE_BOTTOM | 竖直方向下边缘。 |
| ARKUI_SCROLL_EDGE_START | 水平方向起始位置。 |
| ARKUI_SCROLL_EDGE_END | 水平方向末尾位置。 |

### ArkUI_ScrollAlignment

```
enum ArkUI_ScrollAlignment
```

**描述：**


滚动到具体item时的对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_ALIGNMENT_START = 0 | 首部对齐。指定item首部与容器首部对齐。 |
| ARKUI_SCROLL_ALIGNMENT_CENTER | 居中对齐。指定item主轴方向居中对齐于容器。 |
| ARKUI_SCROLL_ALIGNMENT_END | 尾部对齐。指定item尾部与容器尾部对齐。 |
| ARKUI_SCROLL_ALIGNMENT_AUTO | 自动对齐。若指定item完全处于显示区，不做调整。否则依照滑动距离最短的原则，将指定item首部对齐或尾部对齐于容器,使指定item完全处于显示区。 |

### ArkUI_ScrollState

```
enum ArkUI_ScrollState
```

**描述：**


定义当前滚动状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_STATE_IDLE = 0 | 空闲状态。使用控制器提供的方法控制滚动时触发，拖动滚动条滚动时触发。 |
| ARKUI_SCROLL_STATE_SCROLL | 滚动状态。使用手指拖动容器滚动时触发。 |
| ARKUI_SCROLL_STATE_FLING | 惯性滚动状态。快速划动松手后进行惯性滚动和划动到边缘回弹时触发。 |

### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle
```

**描述：**


定义滑块形状。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0 | 使用默认滑块（圆形）。 |
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE | 使用图片资源作为滑块。 |
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE | 使用自定义形状作为滑块。 |

### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection
```

**描述：**


定义滑动条滑动方向。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SLIDER_DIRECTION_VERTICAL = 0 | 方向为纵向。 |
| ARKUI_SLIDER_DIRECTION_HORIZONTAL | 方向为横向。 |

### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle
```

**描述：**


定义滑块与滑轨显示样式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SLIDER_STYLE_OUT_SET = 0 | 滑块在滑轨上。 |
| ARKUI_SLIDER_STYLE_IN_SET | 滑块在滑轨内。 |
| ARKUI_SLIDER_STYLE_NONE | 无滑块。 |

### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```

**描述：**


定义CheckBox组件形状。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE = 0 | 圆形。 |
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE | 圆角方形。 |

### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode
```

**描述：**


定义动画播放模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0 | 动画正向播放。 |
| ARKUI_ANIMATION_PLAY_MODE_REVERSE | 动画反向播放。 |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE | 动画在奇数次（1、3、5...）正向播放，在偶数次（2、4、6...）反向播放。 |
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE | 动画在奇数次（1、3、5...）反向播放，在偶数次（2、4、6...）正向播放。 |

### ArkUI_ImageSize

```
enum ArkUI_ImageSize
```

**描述：**


定义图片宽高样式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMAGE_SIZE_AUTO = 0 | 保持原图的比例不变。 |
| ARKUI_IMAGE_SIZE_COVER | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |
| ARKUI_IMAGE_SIZE_CONTAIN | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 |

### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```

**描述：**


定义取色模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT = 0 | 不使用取色模糊。 |
| ARKUI_ADAPTIVE_COLOR_AVERAGE | 使用取色模糊。 |

### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```

**描述：**


定义深浅色模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_COLOR_MODE_SYSTEM = 0 | 跟随系统深浅色模式。 |
| ARKUI_COLOR_MODE_LIGHT | 固定使用浅色模式。 |
| ARKUI_COLOR_MODE_DARK | 固定使用深色模式。 |

### ArkUI_SystemColorMode

```
enum ArkUI_SystemColorMode
```

**描述：**


定义系统深浅色模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SYSTEM_COLOR_MODE_LIGHT = 0 | 浅色模式。 |
| ARKUI_SYSTEM_COLOR_MODE_DARK | 深色模式。 |

### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle
```

**描述：**


定义背景模糊样式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_BLUR_STYLE_THIN = 0 | 轻薄材质模糊。 |
| ARKUI_BLUR_STYLE_REGULAR | 普通厚度材质模糊。 |
| ARKUI_BLUR_STYLE_THICK | 厚材质模糊。 |
| ARKUI_BLUR_STYLE_BACKGROUND_THIN | 近距景深模糊。 |
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR | 中距景深模糊。 |
| ARKUI_BLUR_STYLE_BACKGROUND_THICK | 远距景深模糊。 |
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK | 超远距景深模糊。 |
| ARKUI_BLUR_STYLE_NONE | 关闭模糊。 |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN | 组件超轻薄材质模糊。 |
| ARKUI_BLUR_STYLE_COMPONENT_THIN | 组件轻薄材质模糊。 |
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR | 组件普通材质模糊。 |
| ARKUI_BLUR_STYLE_COMPONENT_THICK | 组件厚材质模糊。 |
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK | 组件超厚材质模糊。 |

### ArkUI_BlurStyleActivePolicy

```
enum ArkUI_BlurStyleActivePolicy
```

**描述：**


定义背景模糊激活策略。

**起始版本：** 19

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_FOLLOWS_WINDOW_ACTIVE_STATE = 0 | 模糊效果跟随窗口焦点状态变化，非焦点不模糊，焦点模糊。 |
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_ACTIVE | 一直有模糊效果。 |
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_INACTIVE | 一直无模糊效果。 |

### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```

**描述：**


定义垂直对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_VERTICAL_ALIGNMENT_TOP = 0 | 顶部对齐。 |
| ARKUI_VERTICAL_ALIGNMENT_CENTER | 居中对齐，默认对齐方式。 |
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM | 底部对齐。 |

### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment
```

**描述：**


定义语言方向对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_HORIZONTAL_ALIGNMENT_START = 0 | 按照语言方向起始端对齐。 |
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER | 居中对齐，默认对齐方式。 |
| ARKUI_HORIZONTAL_ALIGNMENT_END | 按照语言方向末端对齐。 |

### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```

**描述：**


定义文本超长时的显示方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_OVERFLOW_NONE = 0 | 文本超长时不裁剪显示。 |
| ARKUI_TEXT_OVERFLOW_CLIP | 文本超长时进行裁剪显示。 |
| ARKUI_TEXT_OVERFLOW_ELLIPSIS | 文本超长时显示不下的文本用省略号代替。 |
| ARKUI_TEXT_OVERFLOW_MARQUEE | 文本超长时以跑马灯的方式展示。 |

### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment
```

**描述：**


定义图片基于文本的对齐方式。

**起始版本：** 12

| 枚举项 | 描述                                 |
| -- |------------------------------------|
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0 | 图片下边沿与文本BaseLine对齐。                |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM | 图片下边沿与文本下边沿对齐。                     |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER | 图片中间与文本中间对齐。                       |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP | 图片上边沿与文本上边沿对齐。                     |
| ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH | 图片对齐方式跟随Text组件对齐方式。<br>**起始版本：** 20 |

### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```

**描述：**


定义image填充效果。ImageSpanAlignment

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_OBJECT_FIT_CONTAIN = 0 | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 |
| ARKUI_OBJECT_FIT_COVER | 保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 |
| ARKUI_OBJECT_FIT_AUTO | 自适应显示。 |
| ARKUI_OBJECT_FIT_FILL | 不保持宽高比进行放大缩小，使得图片充满显示边界。 |
| ARKUI_OBJECT_FIT_SCALE_DOWN | 保持宽高比显示，图片缩小或者保持不变。 |
| ARKUI_OBJECT_FIT_NONE | 保持原有尺寸显示。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START | 图片大小不变，在image组件中顶部起始端对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP | 图片大小不变，在image组件中顶部横向居中对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END | 图片大小不变，在image组件中顶部尾端对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START | 图片大小不变，在image组件中起始端纵向居中对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER | 图片大小不变，在image组件中横向和纵向居中对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END | 图片大小不变，在image组件中尾端纵向居中对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START | 图片大小不变，在image组件中底部起始端对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM | 图片大小不变，在image组件中底部横向居中对齐。 |
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END | 图片大小不变，在image组件中底部尾端对齐。 |
| ARKUI_OBJECT_FIT_NONE_MATRIX | 不改变图像原始大小，需要配合NODE_IMAGE_IMAGE_MATRIX使用。 |

### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation
```

**描述：**


定义图片插值效果。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMAGE_INTERPOLATION_NONE = 0 | 不使用图片插值。 |
| ARKUI_IMAGE_INTERPOLATION_LOW | 低图片插值。 |
| ARKUI_IMAGE_INTERPOLATION_MEDIUM | 中图片插值。 |
| ARKUI_IMAGE_INTERPOLATION_HIGH | 高图片插值，插值质量最高。 |

### ArkUI_DynamicRangeMode

```
enum ArkUI_DynamicRangeMode
```

**描述：**


定义图像动态范围模式（例如：SDR/HDR），用于控制图像的明暗与色彩显示范围。

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DYNAMIC_RANGE_MODE_HIGH = 0 | 高动态范围（High Dynamic Range，简称HDR），表示图片中显示亮度（brightness）的最小值和最大值的范围，范围越大图像的亮度表达更逼近真实环境，在太亮的环境下不会产生过曝（一片白），太暗的环境下产生过暗的效果（一片黑）。 |
| ARKUI_DYNAMIC_RANGE_MODE_CONSTRAINT | 受限的高动态范围，包含比SDR更丰富的亮度和色彩，但不是完整的HDR，一般用于需要兼容SDR的情况。 |
| ARKUI_DYNAMIC_RANGE_MODE_STANDARD | 标准动态范围（Standard Dynamic Range，简称SDR），表示亮度范围有限，一般在0~100尼特（亮度单位）左右，明暗对比度较小，暗部容易糊成黑，亮部容易爆白。 |

### ArkUI_ImageRotateOrientation

```
enum ArkUI_ImageRotateOrientation
```

**描述：**


定义图像旋转方向。

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ORIENTATION_AUTO = 0 | 读取图片携带的EXIF元数据作为显示方向，支持旋转和镜像。 |
| ARKUI_ORIENTATION_UP | 默认按照当前图片的像素数据进行显示，不做任何处理。 |
| ARKUI_ORIENTATION_RIGHT | 将当前图片顺时针旋转90度后显示。 |
| ARKUI_ORIENTATION_DOWN  | 将当前图片顺时针旋转180度后显示。 |
| ARKUI_ORIENTATION_LEFT | 将当前图片顺时针旋转270度后显示。 |
| ARKUI_ORIENTATION_UP_MIRRORED | 将当前图片水平翻转后显示。 |
| ARKUI_ORIENTATION_RIGHT_MIRRORED  | 将当前图片水平翻转再顺时针旋转90度后显示。 |
| ARKUI_ORIENTATION_DOWN_MIRRORED | 将当前图片垂直翻转后显示。 |
| ARKUI_ORIENTATION_LEFT_MIRRORED | 将当前图片水平翻转再顺时针旋转270度后显示。 |

### ArkUI_BlendMode

```
enum ArkUI_BlendMode
```

**描述：**


混合模式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_BLEND_MODE_NONE = 0 | 将上层图像直接覆盖到下层图像上，不进行任何混合操作。 |
| ARKUI_BLEND_MODE_CLEAR | 将源像素覆盖的目标像素清除为完全透明。 |
| ARKUI_BLEND_MODE_SRC | r = s，只显示源像素。 |
| ARKUI_BLEND_MODE_DST | r = d，只显示目标像素。 |
| ARKUI_BLEND_MODE_SRC_OVER | r = s + (1 - sa) * d，将源像素按照透明度进行混合，覆盖在目标像素上。 |
| ARKUI_BLEND_MODE_DST_OVER | r = d + (1 - da) * s，将目标像素按照透明度进行混合，覆盖在源像素上。 |
| ARKUI_BLEND_MODE_SRC_IN | r = s * da，只显示源像素中与目标像素重叠的部分。 |
| ARKUI_BLEND_MODE_DST_IN | r = d * sa，只显示目标像素中与源像素重叠的部分。 |
| ARKUI_BLEND_MODE_SRC_OUT | r = s * (1 - da)，只显示源像素中与目标像素不重叠的部分。 |
| ARKUI_BLEND_MODE_DST_OUT | r = d * (1 - sa)，只显示目标像素中与源像素不重叠的部分。 |
| ARKUI_BLEND_MODE_SRC_ATOP | r = s * da + d * (1 - sa)，在源像素和目标像素重叠的地方绘制源像素，在源像素和目标像素不重叠的地方绘制目标像素。 |
| ARKUI_BLEND_MODE_DST_ATOP | r = d * sa + s * (1 - da)，在源像素和目标像素重叠的地方绘制目标像素，在源像素和目标像素不重叠的地方绘制源像素。 |
| ARKUI_BLEND_MODE_XOR | r = s * (1 - da) + d * (1 - sa)，只显示源像素与目标像素不重叠的部分。 |
| ARKUI_BLEND_MODE_PLUS | r = min(s + d, 1)，将源像素值与目标像素值相加，并将结果作为新的像素值。 |
| ARKUI_BLEND_MODE_MODULATE | r = s * d，将源像素与目标像素进行乘法运算，并将结果作为新的像素值。 |
| ARKUI_BLEND_MODE_SCREEN | r = s + d - s * d，将两个图像的像素值相加，然后减去它们的乘积来实现混合。 |
| ARKUI_BLEND_MODE_OVERLAY | 根据目标像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。 |
| ARKUI_BLEND_MODE_DARKEN | rc = s + d - max(s * da, d * sa), ra = kSrcOver，当两个颜色重叠时，较暗的颜色会覆盖较亮的颜色。 |
| ARKUI_BLEND_MODE_LIGHTEN | rc = s + d - min(s * da, d * sa), ra = kSrcOver，将源图像和目标图像中的像素进行比较，选取两者中较亮的像素作为最终的混合结果。|
| ARKUI_BLEND_MODE_COLOR_DODGE | 使目标像素变得更亮来反映源像素。 |
| ARKUI_BLEND_MODE_COLOR_BURN | 使目标像素变得更暗来反映源像素。 |
| ARKUI_BLEND_MODE_HARD_LIGHT | 根据源像素的值来决定目标像素变得更亮或者更暗。根据源像素来决定使用MULTIPLY混合模式还是SCREEN混合模式。 |
| ARKUI_BLEND_MODE_SOFT_LIGHT | 根据源像素来决定使用LIGHTEN混合模式还是DARKEN混合模式。 |
| ARKUI_BLEND_MODE_DIFFERENCE | rc = s + d - 2 * (min(s * da, d * sa)), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生高对比度的效果。 |
| ARKUI_BLEND_MODE_EXCLUSION | rc = s + d - two(s * d), ra = kSrcOver，对比源像素和目标像素，亮度更高的像素减去亮度更低的像素，产生柔和的效果。 |
| ARKUI_BLEND_MODE_MULTIPLY | r = s * (1 - da) + d * (1 - sa) + s * d，将源图像与目标图像进行乘法混合，得到一张新的图像。 |
| ARKUI_BLEND_MODE_HUE | 保留源图像的亮度和饱和度，但会使用目标图像的色调来替换源图像的色调。 |
| ARKUI_BLEND_MODE_SATURATION | 保留目标像素的亮度和色调，但会使用源像素的饱和度来替换目标像素的饱和度。 |
| ARKUI_BLEND_MODE_COLOR | 保留源像素的饱和度和色调，但会使用目标像素的亮度来替换源像素的亮度。 |
| ARKUI_BLEND_MODE_LUMINOSITY | 保留目标像素的色调和饱和度，但会用源像素的亮度替换目标像素的亮度。 |

### ArkUI_Direction

```
enum ArkUI_Direction
```

**描述：**


设置容器元素内主轴方向上的布局枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DIRECTION_LTR = 0 | 元素从左到右布局。 |
| ARKUI_DIRECTION_RTL | 元素从右到左布局。 |
| ARKUI_DIRECTION_AUTO = 3 | 使用系统默认布局方向。 |

### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment
```

**描述：**


设置子组件在父容器交叉轴的对齐格式枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ITEM_ALIGNMENT_AUTO = 0 | 使用Flex容器中默认配置。 |
| ARKUI_ITEM_ALIGNMENT_START | 元素在Flex容器中，交叉轴方向首部对齐。 |
| ARKUI_ITEM_ALIGNMENT_CENTER | 元素在Flex容器中，交叉轴方向居中对齐。 |
| ARKUI_ITEM_ALIGNMENT_END | 元素在Flex容器中，交叉轴方向底部对齐。 |
| ARKUI_ITEM_ALIGNMENT_STRETCH | 元素在Flex容器中，交叉轴方向拉伸填充。 |
| ARKUI_ITEM_ALIGNMENT_BASELINE | 元素在Flex容器中，交叉轴方向文本基线对齐。 |

### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy
```

**描述：**


前景色枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_COLOR_STRATEGY_INVERT = 0 | 前景色为控件背景色的反色。 |
| ARKUI_COLOR_STRATEGY_AVERAGE | 控件背景阴影色为控件背景阴影区域的平均色。 |
| ARKUI_COLOR_STRATEGY_PRIMARY | 控件背景阴影色为控件背景阴影区域的主色。 |

### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment
```

**描述：**


定义垂直方向对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FLEX_ALIGNMENT_START = 1 | 主轴方向首端对齐。 |
| ARKUI_FLEX_ALIGNMENT_CENTER = 2 | 主轴方向中心对齐。 |
| ARKUI_FLEX_ALIGNMENT_END = 3 | 主轴方向尾部对齐。 |
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6 | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素行首对齐，最后的元素行尾对齐。 |
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7 | Flex主轴方向均匀分配弹性元素，相邻元素之间距离相同，第一个元素到行首的距离时相邻元素间距离的一半。 |
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8 | Flex主轴方向均匀分配弹性元素，相邻元素之间距离、第一个元素到行首的距离和最后的元素到行尾的距离均相等。 |

### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection
```

**描述：**


定义Flex容器的主轴方向。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FLEX_DIRECTION_ROW = 0 | 主轴与行方向一致。 |
| ARKUI_FLEX_DIRECTION_COLUMN | 主轴与列方向一致。 |
| ARKUI_FLEX_DIRECTION_ROW_REVERSE | 主轴与行方向相反。 |
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE | 主轴与列方向相反。 |

### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap
```

**描述：**


定义Flex行列布局模式模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FLEX_WRAP_NO_WRAP = 0 | 单行/单列布局，子项不能超出容器。 |
| ARKUI_FLEX_WRAP_WRAP | 多行/多列布局，子项允许超出容器。 |
| ARKUI_FLEX_WRAP_WRAP_REVERSE | 反向多行/多列布局，子项允许超出容器。 |

### ArkUI_Visibility

```
enum ArkUI_Visibility
```

**描述：**


控制组件的显隐枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_VISIBILITY_VISIBLE = 0 | 显示。 |
| ARKUI_VISIBILITY_HIDDEN | 隐藏，但参与布局进行占位。 |
| ARKUI_VISIBILITY_NONE | 隐藏，但不参与布局，不进行占位。 |

### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment
```

**描述：**


日历选择器与入口组件对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CALENDAR_ALIGNMENT_START = 0 | 选择器和入口组件左对齐方式。 |
| ARKUI_CALENDAR_ALIGNMENT_CENTER | 选择器和入口组件居中对齐方式。 |
| ARKUI_CALENDAR_ALIGNMENT_END | 选择器和入口组件右对齐方式。 |

### ArkUI_MaskType

```
enum ArkUI_MaskType
```

**描述：**


遮罩类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_MASK_TYPE_RECTANGLE = 0 | 矩形类型。 |
| ARKUI_MASK_TYPE_CIRCLE | 圆形类型。 |
| ARKUI_MASK_TYPE_ELLIPSE | 椭圆形类型。 |
| ARKUI_MASK_TYPE_PATH | 路径类型。 |
| ARKUI_MASK_TYPE_PROGRESS | 进度类型。 |

### ArkUI_ClipType

```
enum ArkUI_ClipType
```

**描述：**


裁剪类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CLIP_TYPE_RECTANGLE = 0 | 矩形类型。 |
| ARKUI_CLIP_TYPE_CIRCLE | 圆形类型。 |
| ARKUI_CLIP_TYPE_ELLIPSE | 椭圆形类型。 |
| ARKUI_CLIP_TYPE_PATH | 路径类型。 |

### ArkUI_ShapeType

```
enum ArkUI_ShapeType
```

**描述：**


自定义形状。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SHAPE_TYPE_RECTANGLE = 0 | 矩形类型。 |
| ARKUI_SHAPE_TYPE_CIRCLE | 圆形类型。 |
| ARKUI_SHAPE_TYPE_ELLIPSE | 椭圆形类型。 |
| ARKUI_SHAPE_TYPE_PATH | 路径类型。 |

### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection
```

**描述：**


定义渐变方向结构。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0 | 向左渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP | 向上渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT | 向右渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM | 向下渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP | 向左上渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM | 向左下渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP | 向右上渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM | 向右下渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE | 不渐变。 |
| ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM | 自定义渐变方向. |

### ArkUI_WordBreak

```
enum ArkUI_WordBreak
```

**描述：**


定义文本断行规则。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_WORD_BREAK_NORMAL = 0 | CJK(中文、日文、韩文)文本可以在任意2个字符间断行，而Non-CJK文本（如英文等）只能在空白符处断行。 |
| ARKUI_WORD_BREAK_BREAK_ALL | 对于Non-CJK的文本，可在任意2个字符间断行。CJK(中文、日文、韩文)文本可以在任意2个字符间断行。 |
| ARKUI_WORD_BREAK_BREAK_WORD | 对于Non-CJK的文本可在任意2个字符间断行，一行文本中有断行破发点（如空白符）时，优先按破发点换行。对于CJK的文本，换行效果与NORMAL效果保持一致。 |
| ARKUI_WORD_BREAK_HYPHENATION | 对于Non-CJK的文本，可以按照音节断行。对于CJK的文本，换行效果与NORMAL效果保持一致。<br>**起始版本：** 18 |

### ArkUI_EllipsisMode

```
enum ArkUI_EllipsisMode
```

**描述：**


定义文本省略位置。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ELLIPSIS_MODE_START = 0 | 省略行首内容。 |
| ARKUI_ELLIPSIS_MODE_CENTER | 省略行中内容。 |
| ARKUI_ELLIPSIS_MODE_END | 省略行末内容。 |

### ArkUI_ImageRenderMode

```
enum ArkUI_ImageRenderMode
```

**描述：**


定义图片渲染模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0 | 原色渲染模式。 |
| ARKUI_IMAGE_RENDER_MODE_TEMPLATE | 黑白渲染模式。 |

### ArkUI_TransitionEdge

```
enum ArkUI_TransitionEdge
```

**描述：**


定义转场从边缘滑入和滑出的效果。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TRANSITION_EDGE_TOP = 0 | 窗口的上边缘。 |
| ARKUI_TRANSITION_EDGE_BOTTOM | 窗口的下边缘。 |
| ARKUI_TRANSITION_EDGE_START | 窗口的左边缘。 |
| ARKUI_TRANSITION_EDGE_END | 窗口的右边缘。 |

### ArkUI_FinishCallbackType

```
enum ArkUI_FinishCallbackType
```

**描述：**


在动画中定义onFinish回调的类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FINISH_CALLBACK_REMOVED = 0 | 当整个动画结束并立即删除时，将触发回调。 |
| ARKUI_FINISH_CALLBACK_LOGICALLY | 当动画在逻辑上处于下降状态，但可能仍处于其长尾状态时，将触发回调。 |

### ArkUI_ListItemAlignment

```
enum ArkUI_ListItemAlignment
```

**描述：**


交叉轴方向的布局方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LIST_ITEM_ALIGNMENT_START = 0 | ListItem在List中，交叉轴方向首部对齐。 |
| ARKUI_LIST_ITEM_ALIGNMENT_CENTER | ListItem在List中，交叉轴方向居中对齐。 |
| ARKUI_LIST_ITEM_ALIGNMENT_END | ListItem在List中，交叉轴方向尾部对齐。 |

### ArkUI_BlendApplyType

```
enum ArkUI_BlendApplyType
```

**描述：**


指定的混合模式应用于视图的内容选项.

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| BLEND_APPLY_TYPE_FAST = 0 | 在目标图像上按顺序混合视图的内容. |
| BLEND_APPLY_TYPE_OFFSCREEN | 将此组件和子组件内容绘制到离屏画布上，然后整体进行混合. |

### ArkUI_LengthMetricUnit

```
enum ArkUI_LengthMetricUnit
```

**描述：**


定义组件的单位模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1 | 默认，字体类单位为FP，非字体类单位为VP。 |
| ARKUI_LENGTH_METRIC_UNIT_PX = 0 | 单位为PX。 |
| ARKUI_LENGTH_METRIC_UNIT_VP | 单位为VP。 |
| ARKUI_LENGTH_METRIC_UNIT_FP | 单位为FP。 |

### ArkUI_TextInputContentType

```
enum ArkUI_TextInputContentType
```

**描述：**


定义自动填充类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME = 0 | 【用户名】在已启用密码保险箱的情况下，支持用户名的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD | 【密码】在已启用密码保险箱的情况下，支持密码的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD | 【新密码】在已启用密码保险箱的情况下，支持自动生成新密码。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS | 【详细地址】在已启用情景化自动填充的情况下，支持详细地址的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER | 【门牌号】在已启用情景化自动填充的情况下，支持门牌号的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS | 【区/县】在已启用情景化自动填充的情况下，支持区/县的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS | 【市】在已启用情景化自动填充的情况下，支持市的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS | 【省】在已启用情景化自动填充的情况下，支持省的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS | 【国家】在已启用情景化自动填充的情况下，支持国家的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME | 【姓名】在已启用情景化自动填充的情况下，支持姓名的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME | 【姓氏】在已启用情景化自动填充的情况下，支持姓氏的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME | 【名字】在已启用情景化自动填充的情况下，支持名字的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER | 【手机号】在已启用情景化自动填充的情况下，支持手机号的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE | 【国家代码】在已启用情景化自动填充的情况下，支持国家代码的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER | 【包含国家代码的手机号】在已启用情景化自动填充的情况下，支持包含国家代码的手机号的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS | 【邮箱地址】在已启用情景化自动填充的情况下，支持邮箱地址的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER | 【银行卡号】在已启用情景化自动填充的情况下，支持银行卡号的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER | 【身份证号】在已启用情景化自动填充的情况下，支持身份证号的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME | 【昵称】在已启用情景化自动填充的情况下，支持昵称的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET | 【无街道地址】在已启用情景化自动填充的情况下，支持无街道地址的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS | 【标准地址】在已启用情景化自动填充的情况下，支持标准地址的自动保存和自动填充。 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSPORT_NUMBER | 【护照号】在已启用情景化自动填充的情况下，支持护照号的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_VALIDITY | 【护照有效期】在已启用情景化自动填充的情况下，支持护照有效期的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ISSUE_AT | 【护照签发地】在已启用情景化自动填充的情况下，支持护照签发地的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ORGANIZATION | 【发票抬头名称】在已启用情景化自动填充的情况下，支持发票抬头名称的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_TAX_ID | 【税号】在已启用情景化自动填充的情况下，支持税号的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ADDRESS_CITY_AND_STATE | 【所在地区】在已启用情景化自动填充的情况下，支持所在地区的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_FLIGHT_NUMBER | 【航班号】暂不支持自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_NUMBER | 【驾驶证号】暂不支持自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_FILE_NUMBER | 【驾驶证档案编号】暂不支持自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_PLATE | 【车牌号】在已启用情景化自动填充的情况下，支持车牌号的自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_ENGINE_NUMBER | 【行驶证发动机号】暂不支持自动保存和自动填充。<br>**起始版本：** 18 |
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_CHASSIS_NUMBER | 【车牌识别号】暂不支持自动保存和自动填充。<br>**起始版本：** 18 |

### ArkUI_BarrierDirection

```
enum ArkUI_BarrierDirection
```

**描述：**


定义屏障线的方向。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_BARRIER_DIRECTION_START = 0 | 屏障在其所有referencedId的最左侧。 |
| ARKUI_BARRIER_DIRECTION_END | 屏障在其所有referencedId的最右侧。 |
| ARKUI_BARRIER_DIRECTION_TOP | 屏障在其所有referencedId的最上方。 |
| ARKUI_BARRIER_DIRECTION_BOTTOM | 屏障在其所有referencedId的最下方。 |

### ArkUI_RelativeLayoutChainStyle

```
enum ArkUI_RelativeLayoutChainStyle
```

**描述：**


定义链的风格。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0 | 组件在约束锚点间均匀分布。 |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE | 除首尾2个子组件的其他组件在约束锚点间均匀分布。 |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED | 链内子组件无间隙。 |

### ArkUI_TextInputStyle

```
enum ArkUI_TextInputStyle
```

**描述：**


定义输入框风格。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTINPUT_STYLE_DEFAULT = 0 | 默认风格，光标宽1.5vp，光标高度与文本选中底板高度和字体大小相关。 |
| ARKUI_TEXTINPUT_STYLE_INLINE | 内联输入风格。文本选中底板高度与输入框高度相同。 |

### ArkUI_KeyboardAppearance

```
enum ArkUI_KeyboardAppearance
```

**描述：**


定义输入框拉起的键盘样式。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0 | 默认模式，不使用沉浸式样式。 |
| ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1 | 沉浸式模式，由系统决定采用的样式。 |
| ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2 | 浅色沉浸式样式。 |
| ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3 | 深色沉浸式样式。 |

### ArkUI_TextDataDetectorType

```
enum ArkUI_TextDataDetectorType
```

**描述：**


定义文本识别的实体类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER = 0 | 电话号码。 |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_URL | 链接。 |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL | 邮箱。 |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS | 地址。 |

### ArkUI_ButtonType

```
enum ArkUI_ButtonType
```

**描述：**


定义按钮样式枚举值。

**起始版本：** 12

| 枚举项 | 描述                      |
| -- |-------------------------|
| ARKUI_BUTTON_TYPE_NORMAL = 0 | 普通按钮，默认不带圆角。            |
| ARKUI_BUTTON_TYPE_CAPSULE | 胶囊型按钮，圆角默认为高度的一半。       |
| ARKUI_BUTTON_TYPE_CIRCLE | 圆形按钮。                   |
| ARKUI_BUTTON_ROUNDED_RECTANGLE = 8 | 圆角矩形按钮。<br>**起始版本：** 19 |

### ArkUI_RenderFit

```
enum ArkUI_RenderFit
```

**描述：**


定义动画终态内容大小与位置的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_RENDER_FIT_CENTER = 0 | 保持动画终态的内容大小，并且内容始终与组件保持中心对齐。 |
| ARKUI_RENDER_FIT_TOP | 保持动画终态的内容大小，并且内容始终与组件保持顶部中心对齐。 |
| ARKUI_RENDER_FIT_BOTTOM | 保持动画终态的内容大小，并且内容始终与组件保持底部中心对齐。 |
| ARKUI_RENDER_FIT_LEFT | 保持动画终态的内容大小，并且内容始终与组件保持左侧对齐。 |
| ARKUI_RENDER_FIT_RIGHT | 保持动画终态的内容大小，并且内容始终与组件保持右侧对齐。 |
| ARKUI_RENDER_FIT_TOP_LEFT | 保持动画终态的内容大小，并且内容始终与组件保持左上角对齐。 |
| ARKUI_RENDER_FIT_TOP_RIGHT | 保持动画终态的内容大小，并且内容始终与组件保持右上角对齐。 |
| ARKUI_RENDER_FIT_BOTTOM_LEFT | 保持动画终态的内容大小，并且内容始终与组件保持左下角对齐。 |
| ARKUI_RENDER_FIT_BOTTOM_RIGHT | 保持动画终态的内容大小，并且内容始终与组件保持右下角对齐。 |
| ARKUI_RENDER_FIT_RESIZE_FILL | 不考虑动画终态内容的宽高比，并且内容始终缩放到组件的大小。 |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内，且与组件保持中心对齐。 |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内。当组件宽方向有剩余时，内容与组件保持左侧对齐，当组件高方向有剩余时，内容与组件保持顶部对齐。 |
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内。当组件宽方向有剩余时，内容与组件保持右侧对齐，当组件高方向有剩余时，内容与组件保持底部对齐。 |
| ARKUI_RENDER_FIT_RESIZE_COVER | 保持动画终态内容的宽高比进行缩小或放大，使内容两边都大于或等于组件两边，且与组件保持中心对齐，显示内容的中间部分。 |
| ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT | 保持动画终态内容的宽高比进行缩小或放大，使内容的两边都恰好大于或等于组件两边。当内容宽方向有剩余时，内容与组件保持左侧对齐，显示内容的左侧部分。当内容高方向有剩余时，内容与组件保持顶部对齐，显示内容的顶侧部分。 |
| ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT | 保持动画终态内容的宽高比进行缩小或放大，使内容的两边都恰好大于或等于组件两边。当内容宽方向有剩余时，内容与组件保持右侧对齐，显示内容的右侧部分。当内容高方向有剩余时，内容与组件保持底部对齐，显示内容的底侧部分。 |

### ArkUI_SwiperIndicatorType

```
enum ArkUI_SwiperIndicatorType
```

**描述：**


定义 Swiper 组件的导航指示器类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SWIPER_INDICATOR_TYPE_DOT | 圆点指示器类型。 |
| ARKUI_SWIPER_INDICATOR_TYPE_DIGIT | 数字指示器类型。 |

### ArkUI_AnimationDirection

```
enum ArkUI_AnimationDirection
```

**描述：**


动画播放模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ANIMATION_DIRECTION_NORMAL = 0 | 动画正向循环播放。 |
| ARKUI_ANIMATION_DIRECTION_REVERSE | 动画反向循环播放。 |
| ARKUI_ANIMATION_DIRECTION_ALTERNATE | 动画交替循环播放，奇数次正向播放，偶数次反向播放。 |
| ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE | 动画反向交替循环播放，奇数次反向播放，偶数次正向播放。 |

### ArkUI_ListItemSwipeActionState

```
enum ArkUI_ListItemSwipeActionState
```

**描述：**


定义 Listitem 组件SwipeAction方法的显隐模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0 | 收起状态，当ListItem与主轴方向相反滑动时操作项处于隐藏状态。 |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED | 收起状态，当ListItem与主轴方向相反滑动时操作项处于显示状态。 |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING | 长距离状态，当ListItem进入长距删除区后删除ListItem的状态。 |

### ArkUI_ListItemSwipeEdgeEffect

```
enum ArkUI_ListItemSwipeEdgeEffect
```

**描述：**


定义 Listitem 组件SwipeAction方法的滚动模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0 | ListItem划动距离超过划出组件大小后可以继续划动。 |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE | ListItem划动距离不能超过划出组件大小。 |

### ArkUI_AnimationStatus

```
enum ArkUI_AnimationStatus
```

**描述：**


定义帧动画的播放状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ANIMATION_STATUS_INITIAL | 动画初始状态。 |
| ARKUI_ANIMATION_STATUS_RUNNING | 动画处于播放状态。 |
| ARKUI_ANIMATION_STATUS_PAUSED | 动画处于暂停状态。 |
| ARKUI_ANIMATION_STATUS_STOPPED | 动画处于停止状态。 |

### ArkUI_AnimationFillMode

```
enum ArkUI_AnimationFillMode
```

**描述：**


定义帧动画组件在动画开始前和结束后的状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ANIMATION_FILL_MODE_NONE | 动画未执行时不会将任何样式应用于目标，动画播放完成之后恢复初始默认状态。 |
| ARKUI_ANIMATION_FILL_MODE_FORWARDS | 目标将保留动画执行期间最后一个关键帧的状态。 |
| ARKUI_ANIMATION_FILL_MODE_BACKWARDS | 动画将在应用于目标时立即应用第一个关键帧中定义的值，并在delay期间保留此值。 |
| ARKUI_ANIMATION_FILL_MODE_BOTH | 动画将遵循Forwards和Backwards的规则，从而在两个方向上扩展动画属性。 |

### ArkUI_ErrorCode

```
enum ArkUI_ErrorCode
```

**描述：**


定义错误码枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ERROR_CODE_NO_ERROR = 0 | 无错误。 |
| ARKUI_ERROR_CODE_PARAM_INVALID = 401 | 参数错误。 |
| ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500 |  接口初始化错误。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001 |  出现内部错误，例如内部环境错误导致失败，或者由于内部执行失败导致操作失败。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501 |  当前XComponent状态异常，方法调用失败。错误码的详细介绍请参见[XComponent组件错误码](../apis-arkui/errorcode-xcomponent.md)。<br>**起始版本：** 19 |
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102 | 组件不支持特定的属性或者事件。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。 |
| ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103 | 对应的操作不支持ArkTS创建的节点。错误码的详细介绍请参见[自定义节点错误码](../apis-arkui/errorcode-node.md)。 |
| ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104 | 懒加载适配器未绑定到组件上。 |
| ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105 | 适配器已存在。 |
| ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106 | 对应节点已存在子节点，无法添加适配器。 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107 | 组件事件中参数长度超限。错误码的详细介绍请参见[106107-参数下标越界](../apis-arkui/errorcode-nodeadapter.md#106107-参数下标越界)。 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108 | 组件事件中不存在该数据。错误码的详细介绍请参见[106108-数据不存在](../apis-arkui/errorcode-nodeadapter.md#106108-数据不存在)。 |
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109 | 组件事件不支持返回值。错误码的详细介绍请参见[106109-不支持返回值](../apis-arkui/errorcode-nodeadapter.md#106109-不支持返回值)。 |
| ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110 | 暂不支持该事件类型。错误码的详细介绍请参见[106110-暂不支持该事件类型](../apis-arkui/errorcode-nodeadapter.md#106110-暂不支持该事件类型)。 |
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200 | 传入的索引值非法。<br/>错误码的详细介绍请参见[导航错误码](../apis-arkui/errorcode-router.md#106200-传入的索引值非法)。 |
| ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201 | 查询路由导航信息失败。<br/>错误码的详细介绍请参见[导航错误码](../apis-arkui/errorcode-router.md#106201-查询路由导航信息失败)。 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202 | 传入的buffer size异常。<br/>错误码的详细介绍请参见[导航错误码](../apis-arkui/errorcode-router.md#106202-传入的buffer-size异常)。 |
| ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203 |  传入的节点未挂载到组件树上。错误码的详细介绍请参见[自定义节点错误码](../apis-arkui/errorcode-node.md)。<br>**起始版本：** 16 |
| ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204 |  不支持在非UI线程操作传入的节点。错误码的详细介绍请参见[自定义节点错误码](../apis-arkui/errorcode-node.md#106204-不支持在非ui线程操作传入的节点)。<br>**起始版本：** 21 |
| ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401 |  当前节点不是自定义节点。错误码的详细介绍请参见[渲染节点错误码](../apis-arkui/errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_CHILD_EXISTED = 106402 |  当前节点已存在子节点。错误码的详细介绍请参见[渲染节点错误码](../apis-arkui/errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403 |  当前渲染节点存在父组件。错误码的详细介绍请参见[渲染节点错误码](../apis-arkui/errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404 |  未找到对应的渲染子节点。错误码的详细介绍请参见[渲染节点错误码](../apis-arkui/errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405 |  参数值超出范围。错误码的详细介绍请参见[渲染节点错误码](../apis-arkui/errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001 |  当前节点无法获得焦点。错误码的详细介绍请参见[焦点错误码](../apis-arkui/errorcode-focus.md#150001-节点无法获得焦点)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002 |  当前节点对应的祖先节点中存在无法获焦节点。错误码的详细介绍请参见[焦点错误码](../apis-arkui/errorcode-focus.md#150002-祖先节点无法获得焦点)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003 |  当前节点不存在。错误码的详细介绍请参见[焦点错误码](../apis-arkui/errorcode-focus.md#150003-节点不存在)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002 |  截图超时。错误码的详细介绍请参见[截图错误码](../apis-arkui/errorcode-snapshot.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001 | 非滚动类容器。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002 | 存储区大小不足。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。 |
| ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003 |  该事件不是克隆事件。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004 |  组件状态异常。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005 |  未命中可响应事件的组件。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006 |  接口不支持此输入事件类型。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101 |  无效的属性字符串。错误码的详细介绍请参见[属性字符串错误码](../apis-arkui/errorcode-styled-string.md)。<br>**起始版本：** 14 |
| ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001 |  无效的UIContext对象。错误码的详细介绍请参见[UI上下文错误码](../apis-arkui/errorcode-uicontext.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002 |  无效的回调函数。错误码的详细介绍请参见[UI上下文错误码](../apis-arkui/errorcode-uicontext.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102 |  不支持手势识别器类型。错误码的详细介绍请参见[交互事件错误码](../apis-arkui/errorcode-event.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004 |  当前阶段不允许该操作。错误码的详细介绍请参见[拖拽事件错误码](../apis-arkui/errorcode-drag-event.md)。<br>**起始版本：** 19 |

### ArkUI_ScrollSource

```
enum ArkUI_ScrollSource
```

**描述：**


定义滚动来源枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SCROLL_SOURCE_DRAG = 0 | 手指拖动。 |
| ARKUI_SCROLL_SOURCE_FLING | 手指拖动后的惯性滚动。 |
| ARKUI_SCROLL_SOURCE_EDGE_EFFECT | 在过界时执行EdgeEffect.Spring边缘特效。 |
| ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT | 除了拖动以外的其他用户输入，如鼠标滚轮、键盘事件等。 |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR | 拖动滚动条。 |
| ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING | 拖动滚动条后的惯性滚动。 |
| ARKUI_SCROLL_SOURCE_SCROLLER | 滚动控制器引起的无动画的滚动。 |
| ARKUI_SCROLL_SOURCE_ANIMATION | 滚动控制器引起的带动画的滚动。 |

### ArkUI_SafeAreaType

```
enum ArkUI_SafeAreaType
```

**描述：**


定义扩展安全区域的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SAFE_AREA_TYPE_SYSTEM = 1 | 系统默认非安全区域，包括状态栏、导航栏。 |
| ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 << 1 | 设备的非安全区域，例如刘海屏或挖孔屏区域。 |
| ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 << 2 | 软键盘区域。 |

### ArkUI_SafeAreaEdge

```
enum ArkUI_SafeAreaEdge
```

**描述：**


定义扩展安全区域的方向的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_SAFE_AREA_EDGE_TOP = 1 | 上方区域。 |
| ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | 下方区域。 |
| ARKUI_SAFE_AREA_EDGE_START = 1 << 2 | 前部区域。 |
| ARKUI_SAFE_AREA_EDGE_END = 1 << 3 | 尾部区域。 |

### ArkUI_FocusMove

```
enum ArkUI_FocusMove
```

**描述：**


定义焦点移动方向的枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FOCUS_MOVE_FORWARD = 0 | 向前移动焦点。 |
| ARKUI_FOCUS_MOVE_BACKWARD | 向后移动焦点。 |
| ARKUI_FOCUS_MOVE_UP | 向上移动焦点。 |
| ARKUI_FOCUS_MOVE_DOWN | 向下移动焦点。 |
| ARKUI_FOCUS_MOVE_LEFT | 向左移动焦点。 |
| ARKUI_FOCUS_MOVE_RIGHT | 向右移动焦点。 |

### ArkUI_ListItemGroupArea

```
enum ArkUI_ListItemGroupArea
```

**描述：**


定义 ListItemGroup 组件区域。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE = 0 | ListItemGroup区域外。 |
| ARKUI_LIST_ITEM_SWIPE_AREA_NONE | ListItemGroup没有header、footer和ListItem时的区域。 |
| ARKUI_LIST_ITEM_SWIPE_AREA_ITEM | ListItemGroup的ListItem区域。 |
| ARKUI_LIST_ITEM_SWIPE_AREA_HEADER | ListItemGroup的header区域。 |
| ARKUI_LIST_ITEM_SWIPE_AREA_FOOTER | ListItemGroup的footer区域。 |

### ArkUI_KeyboardAvoidMode

```
enum ArkUI_KeyboardAvoidMode
```

**描述：**


键盘避让模式。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_KEYBOARD_AVOID_MODE_DEFAULT = 0 | 默认避让软键盘并在到达极限高度之后进行高度压缩。 |
| ARKUI_KEYBOARD_AVOID_MODE_NONE | 不避让键盘。 |

### ArkUI_HoverModeAreaType

```
enum ArkUI_HoverModeAreaType
```

**描述：**


悬停态显示区域。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_HOVER_MODE_AREA_TYPE_TOP = 0 | 上半屏。 |
| ARKUI_HOVER_MODE_AREA_TYPE_BOTTOM | 下半屏。 |

### ArkUI_ExpandMode

```
enum ArkUI_ExpandMode
```

**描述：**


定义子节点展开模式枚举值。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_NOT_EXPAND = 0 | 不展开。 |
| ARKUI_EXPAND = 1 | 展开。 |
| ARKUI_LAZY_EXPAND = 2 | 懒展开，按需展开当前节点的子节点。 |

### ArkUI_NavDestinationState

```
enum ArkUI_NavDestinationState
```

**描述：**


定义NavDestination组件的状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_NAV_DESTINATION_STATE_ON_SHOW = 0 | NavDestination组件显示。 |
| ARKUI_NAV_DESTINATION_STATE_ON_HIDE = 1 | NavDestination组件隐藏。 |
| ARKUI_NAV_DESTINATION_STATE_ON_APPEAR = 2 | NavDestination从组件树上挂载。 |
| ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR = 3 | NavDestination从组件树上卸载。 |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW = 4 | NavDestination组件显示之前。 |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE = 5 | NavDestination组件隐藏之前。 |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR = 6 | NavDestination挂载到组件树之前。 |
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR = 7 | NavDestination从组件树上卸载之前。 |
| ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS = 100 | NavDestination从组件返回。 |

### ArkUI_RouterPageState

```
enum ArkUI_RouterPageState
```

**描述：**


定义Router Page的状态。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_APPEAR = 0 | Router Page即将创建。 |
| ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_DISAPPEAR = 1 | Router Page即将销毁。 |
| ARKUI_ROUTER_PAGE_STATE_ON_SHOW = 2 | Router Page显示。 |
| ARKUI_ROUTER_PAGE_STATE_ON_HIDE = 3 | Router Page隐藏。 |
| ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS = 4 | Router Page返回时。 |

### ArkUI_UIState

```
enum ArkUI_UIState
```

**描述：**


组件的UI状态枚举，用于处理状态样式。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| UI_STATE_NORMAL = 0 | 正常状态。 |
| UI_STATE_PRESSED = 1 << 0 | 按压状态。 |
| UI_STATE_FOCUSED = 1 << 1 | 获焦状态。 |
| UI_STATE_DISABLED = 1 << 2 | 禁用状态。 |
| UI_STATE_SELECTED = 1 << 3 | 选中状态，此状态仅由某些特定类型的组件支持，分别是Checkbox、Radio、Toggle、List、Grid和MenuItem。 |

### ArkUI_FocusWrapMode

```
enum ArkUI_FocusWrapMode
```

**描述：**


组件走焦换行规则。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_FOCUS_WRAP_MODE_DEFAULT = 0 | 默认规则，使用方向键走焦不换行。 |
| ARKUI_FOCUS_WRAP_WITH_ARROW = 1 | 使用方向键走焦自动换行。 |

### ArkUI_EdgeDirection

```
enum ArkUI_EdgeDirection
```

**描述：**


定义矩形边方向。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_EDGE_DIRECTION_ALL = 0 | 设置四个方向的内容。 |
| ARKUI_EDGE_DIRECTION_LEFT = 1 << 0 | 设置左侧方向内容。 |
| ARKUI_EDGE_DIRECTION_RIGHT = 1 << 1 | 设置右侧方向内容。 |
| ARKUI_EDGE_DIRECTION_TOP = 1 << 2 | 设置上侧方向内容。 |
| ARKUI_EDGE_DIRECTION_BOTTOM = 1 << 3 | 设置下侧方向内容。 |

### ArkUI_CornerDirection

```
enum ArkUI_CornerDirection
```

**描述：**


定义角度方向。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CORNER_DIRECTION_ALL = 0 | 设置四个角度方向的内容。 |
| ARKUI_CORNER_DIRECTION_TOP_LEFT = 1 << 0 | 设置左上侧方向内容。 |
| ARKUI_CORNER_DIRECTION_TOP_RIGHT = 1 << 1 | 设置右上侧方向内容。 |
| ARKUI_CORNER_DIRECTION_BOTTOM_LEFT = 1 << 2 | 设置左下侧方向内容。 |
| ARKUI_CORNER_DIRECTION_BOTTOM_RIGHT = 1 << 3 | 设置右下侧方向容。 |

## 函数说明

### OH_ArkUI_LayoutConstraint_Create()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()
```

**描述：**


创建约束尺寸。

**起始版本：** 12

**返回：**

| 类型                          | 说明 |
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | 创建约束尺寸的对象指针。 |

### OH_ArkUI_LayoutConstraint_Copy()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


约束尺寸深拷贝。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型                          | 说明 |
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | 新的约束尺寸指针。 |

### OH_ArkUI_LayoutConstraint_Dispose()

```
void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)
```

**描述：**


销毁约束尺寸指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型                          | 说明 |
|-----------------------------| -- |
| void* | 空指针。 |

### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取最大宽度，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 最大宽度。 |

### OH_ArkUI_LayoutConstraint_GetMinWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取最小宽度，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 最小宽度。 |

### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取最大高度，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 最大高度。 |

### OH_ArkUI_LayoutConstraint_GetMinHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取最小高度，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 最小高度。 |

### OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取宽度百分比基准，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 宽度百分比基准。 |

### OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)
```

**描述：**


通过约束尺寸获取高度百分比基准，单位为px。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 高度百分比基准。 |

### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```
void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置最大宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 最大宽度，单位为px。 |

### OH_ArkUI_LayoutConstraint_SetMinWidth()

```
void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置最小宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 最小宽度，单位为px。 |

### OH_ArkUI_LayoutConstraint_SetMaxHeight()

```
void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置最大高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 最大高度，单位为px。 |

### OH_ArkUI_LayoutConstraint_SetMinHeight()

```
void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置最小高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 最小高度，单位为px。 |

### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置宽度百分比基准。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 宽度百分比基准，单位为px。 |

### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**描述：**


设置高度百分比基准。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | 约束尺寸。 |
| int32_t value | 高度百分比基准，单位为px。 |

### OH_ArkUI_DrawContext_GetCanvas()

```
void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)
```

**描述：**


获取绘制canvas指针，可以转换为图形库的OH_Drawing_Canvas指针进行绘制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | 绘制上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 用于绘制的canvas指针。 |

### OH_ArkUI_DrawContext_GetSize()

```
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)
```

**描述：**


获取可绘制区域大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | 绘制上下文。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | 可绘制区域大小。 |

### OH_ArkUI_WaterFlowSectionOption_Create()

```
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
```

**描述：**


创建FlowItem分组配置信息。

**起始版本：** 12

**返回：**

| 类型                                | 说明 |
|-----------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* | FlowItem分组配置信息。 |

### OH_ArkUI_WaterFlowSectionOption_Dispose()

```
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
```

**描述：**


销毁FlowItem分组配置信息指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |

### OH_ArkUI_WaterFlowSectionOption_SetSize()

```
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option,int32_t size)
```

**描述：**


设置FlowItem分组配置信息数组长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t size | 数组长度。 |

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
```

**描述：**


获取FlowItem分组配置信息数组长度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 数组长度。如果返回-1，则返回失败。失败的原因可能是option参数异常，如空指针。 |

### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option,int32_t index, int32_t itemCount)
```

**描述：**


设置分组中FlowItem数量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
| int32_t itemCount | 分组中FlowItem数量。 |

### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的FlowItem数量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 分组中FlowItem数量。 |

### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option,int32_t index, int32_t crossCount)
```

**描述：**


设置布局栅格，纵向布局时为列数，横向布局时为行数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
| int32_t crossCount | 布局栅格数量。 |

### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的布局栅格数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 布局栅格数量。 |

### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option,int32_t index, float columnGap)
```

**描述：**


设置分组的列间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
| float columnGap | 列间距。 |

### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的分组的列间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 列间距。 |

### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option,int32_t index, float rowGap)
```

**描述：**


设置分组的行间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
| float rowGap | 行间距。 |

### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的分组的行间距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 行间距。 |

### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)
```

**描述：**


设置分组的外边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
| float marginTop | FlowItem上外边距。 |
| float marginRight | FlowItem右外边距。 |
| float marginBottom | FlowItem下外边距。 |
| float marginLeft | FlowItem左外边距。 |

### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**描述：**


通过FlowItem分组配置信息获取对应索引下的分组的外边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | 外边距。 |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option,int32_t index, float(*callback)(int32_t itemIndex))
```

**描述：**


通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。

**起始版本：** 12


**参数：**

| 参数项                                            | 描述 |
|------------------------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index                                  | 分组配置信息数组索引值。 |
| callback                                       | 根据index获取指定Item的主轴大小。itemIndex：FlowItem索引值。 |

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData,float (*callback)(int32_t itemIndex, void* userData))
```

**描述：**


通过FlowItem分组配置信息根据flowItemIndex获取指定Item的主轴大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | FlowItem分组配置信息。 |
| int32_t index | 分组配置信息数组索引值。 |
|  void* userData | FlowItem自定义数据。 |
| callback | 根据index获取指定Item的主轴大小。itemIndex：FlowItem索引值。 |

### OH_ArkUI_GuidelineOption_Create()

```
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)
```

**描述：**


创建RelativeContainer容器内的辅助线信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t size | 辅助线数量。 |

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* | 辅助线信息。 |

### OH_ArkUI_GuidelineOption_Dispose()

```
void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)
```

**描述：**


销毁辅助线信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |

### OH_ArkUI_GuidelineOption_SetId()

```
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)
```

**描述：**


设置辅助线的Id。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| const char* value | id，必须是唯一的并且不可与容器内组件重名。 |
| int32_t index | 辅助线索引值。 |

### OH_ArkUI_GuidelineOption_SetDirection()

```
void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)
```

**描述：**


设置辅助线的方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| [ArkUI_Axis](capi-native-type-h.md#arkui_axis) value | 方向。 |
| int32_t index | 辅助线索引值。 |

### OH_ArkUI_GuidelineOption_SetPositionStart()

```
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**描述：**


设置距离容器左侧或者顶部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| float value | 距离容器左侧或者顶部的距离。 |
| int32_t index | 辅助线索引值。 |

### OH_ArkUI_GuidelineOption_SetPositionEnd()

```
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**描述：**


设置距离容器右侧或者底部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| float value | 距离容器右侧或者底部的距离。 |
| int32_t index | 辅助线索引值。 |

### OH_ArkUI_GuidelineOption_GetId()

```
const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)
```

**描述：**


获取辅助线的Id。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | Id。 |

### OH_ArkUI_GuidelineOption_GetDirection()

```
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)
```

**描述：**


获取辅助线的方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_Axis](capi-native-type-h.md#arkui_axis) | 方向。 |

### OH_ArkUI_GuidelineOption_GetPositionStart()

```
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)
```

**描述：**


获取辅助线距离容器左侧或者顶部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 辅助线距离容器左侧或者顶部的距离。单位为vp。 |

### OH_ArkUI_GuidelineOption_GetPositionEnd()

```
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)
```

**描述：**


获取辅助线距离容器右侧或者底部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 辅助线距离容器右侧或者底部的距离。单位为vp。 |

### OH_ArkUI_BarrierOption_Create()

```
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)
```

**描述：**


创建RelativeContainer容器内的屏障信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t size | 屏障数量。 |

**返回：**

| 类型                       | 说明 |
|--------------------------| -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* | 屏障信息。 |

### OH_ArkUI_BarrierOption_Dispose()

```
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)
```

**描述：**


销毁屏障信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 屏障信息。 |

### OH_ArkUI_BarrierOption_SetId()

```
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**描述：**


设置屏障的Id。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 屏障信息。 |
| const char* value | id，必须是唯一的并且不可与容器内组件重名。 |
| int32_t index | 屏障索引值。 |

### OH_ArkUI_BarrierOption_SetDirection()

```
void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)
```

**描述：**


设置屏障的方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 屏障信息。 |
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) value | 方向。 |
| int32_t index | 屏障索引值。 |

### OH_ArkUI_BarrierOption_SetReferencedId()

```
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**描述：**


设置屏障的依赖的组件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 屏障信息。 |
| const char* value | 依赖的组件的Id。 |
| int32_t index | 屏障索引值。 |

### OH_ArkUI_BarrierOption_GetId()

```
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**描述：**


获取屏障的Id。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 屏障的Id。 |

### OH_ArkUI_BarrierOption_GetDirection()

```
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**描述：**


获取屏障的方向。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) | 屏障的方向。 |

### OH_ArkUI_BarrierOption_GetReferencedId()

```
const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)
```

**描述：**


获取屏障的依赖的组件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |
| int32_t referencedIndex | 依赖的组件Id索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 屏障的依赖的组件。 |

### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**描述：**


获取屏障的依赖的组件的个数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | 辅助线信息。 |
| int32_t index | 辅助线索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 屏障的依赖的组件的个数。 |

### OH_ArkUI_AlignmentRuleOption_Create()

```
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()
```

**描述：**


创建相对容器中子组件的对齐规则信息。

**起始版本：** 12

**返回：**

| 类型                             | 说明 |
|--------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* | 对齐规则信息。 |

### OH_ArkUI_AlignmentRuleOption_Dispose()

```
void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)
```

**描述：**


销毁相对容器中子组件的对齐规则信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

### OH_ArkUI_AlignmentRuleOption_SetStart()

```
void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**描述：**


设置左对齐参数。

**起始版本：** 12


**参数：**

| 参数项                                                                                       | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id                                                                            | 锚点的组件的id值。 |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment                         | 相对于锚点组件的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_SetEnd()

```
void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**描述：**


设置右对齐参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id | 锚点的组件的id值。 |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | 相对于锚点组件的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**描述：**


设置横向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id | 锚点的组件的id值。 |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | 相对于锚点组件的对齐方式 |

### OH_ArkUI_AlignmentRuleOption_SetTop()

```
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**描述：**


设置顶部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项                                                                                       | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id                                                                            | 锚点的组件的id值。 |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment                             | 相对于锚点组件的对齐方式 |

### OH_ArkUI_AlignmentRuleOption_SetBottom()

```
void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**描述：**


设置底部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id | 锚点的组件的id值。 |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | 相对于锚点组件的对齐方式 |

### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**描述：**


设置纵向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| const char* id | 锚点的组件的id值。 |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | 相对于锚点组件的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)
```

**描述：**


设置组件在锚点约束下的水平方向上偏移参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| float horizontal | 水平方向上的bias值。 |

### OH_ArkUI_AlignmentRuleOption_SetBiasVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)
```

**描述：**


设置组件在锚点约束下的垂直方向上偏移参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |
| float vertical | 垂直方向上的bias值。 |

### OH_ArkUI_AlignmentRuleOption_GetStartId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取左对齐参数的Id。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 锚点的组件的id值。 |

### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取左对齐参数的对齐方式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | 参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetEndId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取右对齐参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 右对齐参数id。 |

### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取右对齐参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | 右对齐参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取横向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 横向居中对齐方式的参数的id。 |

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取横向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | 横向居中对齐方式的参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetTopId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取顶部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 顶部对齐的参数id。 |

### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取顶部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | 顶部对齐的参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取底部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 底部对齐的参数的id。 |

### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取底部对齐的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | 底部对齐的参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取纵向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 纵向居中对齐方式的参数的id。 |

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取纵向居中对齐方式的参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | 纵向居中对齐方式的参数的对齐方式。 |

### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取水平方向上的bias值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 水平方向上的bias值。 |

### OH_ArkUI_AlignmentRuleOption_GetBiasVertical()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)
```

**描述：**


获取垂直方向上的bias值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | 相对容器中子组件的对齐规则信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 垂直方向上的bias值。 |

### OH_ArkUI_SwiperIndicator_Create()

```
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type)
```

**描述：**


创建 Swiper 组件的导航指示器。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicatorType](capi-native-type-h.md#arkui_swiperindicatortype) type | 导航指示器的类型。 |

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* | 导航指示器对象指针。 |

### OH_ArkUI_SwiperIndicator_Dispose()

```
void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator)
```

**描述：**


销毁Swiper组件的导航指示器指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

### OH_ArkUI_SwiperIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置导航点距离 Swiper 组件左边的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 导航点距离Swiper组件左边的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取导航点距离 Swiper 组件左边的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航点距离Swiper组件左边的距离。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置导航点距离 Swiper 组件顶部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 导航点距离Swiper组件顶部的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取导航点距离 Swiper 组件顶部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航点距离Swiper组件顶部的距离。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置导航点距离 Swiper 组件右边的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 导航点距离Swiper组件右边的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取导航点距离 Swiper 组件右边的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航点距离Swiper组件右边的距离。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置导航点距离 Swiper 组件底部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 导航点距离Swiper组件底部的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取导航点距离 Swiper 组件底部的距离。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航点距离Swiper组件底部的距离。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom()

```
void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize)
```

**描述：**


设置OH_ArkUI_SwiperIndicator_SetBottomPosition是否忽略导航点大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| int32_t ignoreSize | 是否忽略导航点大小。1表示忽略导航点大小，0表示不忽略，默认值0。 |

### OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom()

```
int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取OH_ArkUI_SwiperIndicator_SetBottomPosition是否忽略导航点大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 是否忽略导航点大小。 |

### OH_ArkUI_SwiperIndicator_SetItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置 Swiper 组件圆点导航指示器的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 圆点导航指示器的宽。默认值：12，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取 Swiper 组件圆点导航指示器的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 圆点导航指示器的宽。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置 Swiper 组件圆点导航指示器的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 圆点导航指示器的高。默认值：6，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取 Swiper 组件圆点导航指示器的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 圆点导航指示器的高。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetSelectedItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置被选中的 Swiper 组件圆点导航指示器的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 圆点导航指示器的宽。默认值：12，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetSelectedItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件圆点导航指示器的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 圆点导航指示器的宽。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetSelectedItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value)
```

**描述：**


设置被选中的 Swiper 组件圆点导航指示器的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float value | 圆点导航指示器的高。默认值：6，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetSelectedItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件圆点导航指示器的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 圆点导航指示器的高。单位：vp。 |

### OH_ArkUI_SwiperIndicator_SetMask()

```
void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask)
```

**描述：**


设置是否显示 Swiper 组件圆点导航指示器的蒙版样式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| int32_t mask | 是否显示蒙版样式，1 表示显示，0 表示不显示。 |

### OH_ArkUI_SwiperIndicator_GetMask()

```
int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取是否显示 Swiper 组件圆点导航指示器的蒙版样式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | mask 1 表示显示圆点导航指示器的蒙版样式，0 表示不显示。 |

### OH_ArkUI_SwiperIndicator_SetColor()

```
void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color)
```

**描述：**


设置 Swiper 组件圆点导航指示器的颜色。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| uint32_t color | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperIndicator_GetColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取 Swiper 组件圆点导航指示器的颜色。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperIndicator_SetSelectedColor()

```
void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor)
```

**描述：**


设置被选中 Swiper 组件圆点导航指示器的颜色。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| uint32_t selectedColor | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperIndicator_GetSelectedColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件圆点导航指示器的颜色。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperIndicator_SetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount)
```

**描述：**


设置圆点导航点指示器样式下，导航点显示个数的最大值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| int32_t maxDisplayCount | 导航点显示个数最大值，有效取值范围[6, 9]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 如果maxDisplayCount设置范围错误, 返回错误码。 |

### OH_ArkUI_SwiperIndicator_GetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取圆点导航点指示器样式下，导航点显示个数的最大值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 导航点显示个数最大值，有效取值范围[6, 9]。 |

### OH_ArkUI_SwiperDigitIndicator_Create()

```
ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create()
```

**描述：**


创建 Swiper 组件的数字导航指示器。

**起始版本：** 19

**返回：**

| 类型                               | 说明 |
|----------------------------------| -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) * | 数字导航指示器对象指针。 |

### OH_ArkUI_SwiperDigitIndicator_Destroy()

```
void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


销毁Swiper组件的数字导航指示器指针。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

### OH_ArkUI_SwiperDigitIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**描述：**


设置数字导航指示器距离 Swiper 组件左边的距离，在从右至左显示的语言模式下，设置其距离 Swiper 组件右边的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float value | 数字导航指示器距离Swiper组件左边的距离，在从右至左显示的语言模式下，其距离Swiper组件右边的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取数字导航指示器距离 Swiper 组件左边的距离，在从右至左显示的语言模式下，获取其距离 Swiper 组件右边的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 数字导航指示器距离Swiper组件左边的距离，在从右至左显示的语言模式下，其距离Swiper组件右边的距离。单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**描述：**


设置数字导航指示器距离 Swiper 组件顶部的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float value | 数字导航指示器距离Swiper组件顶部的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取数字导航指示器距离 Swiper 组件顶部的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 数字导航指示器距离Swiper组件顶部的距离。单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**描述：**


设置数字导航指示器距离 Swiper 组件右边的距离，在从右至左显示的语言模式下，设置其距离 Swiper 组件左边的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float value | 数字导航指示器距离Swiper组件右边的距离，在从右至左显示的语言模式下，其距离Swiper组件左边的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取数字导航指示器距离 Swiper 组件右边的距离，在从右至左显示的语言模式下，获取其距离 Swiper 组件左边的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 数字导航指示器距离Swiper组件右边的距离，在从右至左显示的语言模式下，其距离Swiper组件左边的距离。单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**描述：**


设置数字导航指示器距离 Swiper 组件底部的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float value | 数字导航指示器距离Swiper组件底部的距离。默认值：0，单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取数字导航指示器距离 Swiper 组件底部的距离。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 数字导航指示器距离Swiper组件底部的距离。单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_SetFontColor()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color)
```

**描述：**


设置 Swiper 组件数字导航指示器字体颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| uint32_t color | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。默认值：0xFF182431。 |

### OH_ArkUI_SwiperDigitIndicator_GetFontColor()

```
uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取 Swiper 组件数字导航指示器字体颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor)
```

**描述：**


设置被选中 Swiper 组件数字导航指示器字体颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| uint32_t selectedColor | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。默认值：0xFF182431。 |

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor()

```
uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件数字导航指示器字体颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 颜色类型，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperDigitIndicator_SetFontSize()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
```

**描述：**


设置 Swiper 组件数字导航指示器字体大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float size | 字体大小数值，单位为fp。 |

### OH_ArkUI_SwiperDigitIndicator_GetFontSize()

```
float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取 Swiper 组件数字导航指示器字体大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 字体大小数值，单位为fp。 |

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
```

**描述：**


设置被选中 Swiper 组件数字导航指示器字体大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |
| float size | 字体大小数值，单位为fp。 |

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize()

```
float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件数字导航指示器字体大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 字体大小数值，单位为fp。 |

### OH_ArkUI_SwiperDigitIndicator_SetFontWeight()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)
```

**描述：**


设置 Swiper 组件数字导航指示器字体粗细属性。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) *indicator | 数字导航指示器对象指针。 |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) fontWeight | 字体粗细样式[ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight)。 |

### OH_ArkUI_SwiperDigitIndicator_GetFontWeight()

```
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取 Swiper 组件数字导航指示器字体粗细属性。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) | 字体粗细样式[ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight)。 |

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)
```

**描述：**


设置被选中 Swiper 组件数字导航指示器字体粗细属性。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) *indicator | 数字导航指示器对象指针。 |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) selectedFontWeight | 字体粗细样式[ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight)。 |

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight()

```
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取被选中 Swiper 组件数字导航指示器字体粗细属性。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 数字导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) | 字体粗细样式[ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight)。 |

### OH_ArkUI_SwiperArrowStyle_Create()

```
ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create()
```

**描述：**


创建 Swiper 组件的导航箭头。

**起始版本：** 19

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md) * | 导航箭头对象指针。 |

### OH_ArkUI_SwiperArrowStyle_Destroy()

```
void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


销毁 Swiper 组件的导航箭头指针。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

### OH_ArkUI_SwiperArrowStyle_SetShowBackground()

```
void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showBackground)
```

**描述：**


设置 Swiper 组件导航箭头底板是否显示。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| int32_t showBackground | 导航箭头底板是否显示，0：不显示，1：显示，默认值：0。 |

### OH_ArkUI_SwiperArrowStyle_GetShowBackground()

```
int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头底板是否显示。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 导航箭头底板是否显示，0：不显示，1：显示。 |

### OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle()

```
void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle)
```

**描述：**


设置 Swiper 组件导航箭头显示位置。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| int32_t showSidebarMiddle | 导航箭头显示位置，0：显示在导航指示器两侧，1：显示在Swiper组件两侧，默认值：0。 |

### OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle()

```
int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头显示位置。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 导航箭头显示位置，0：显示在导航指示器两侧，1：显示在Swiper组件两侧。 |

### OH_ArkUI_SwiperArrowStyle_SetBackgroundSize()

```
void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize)
```

**描述：**


设置 Swiper 组件导航箭头底板大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| float backgroundSize | 导航箭头底板大小，单位：vp。默认值：显示在导航指示器两侧24vp，显示在Swiper两侧32vp。 |

### OH_ArkUI_SwiperArrowStyle_GetBackgroundSize()

```
float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头底板大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航箭头底板大小，单位：vp。 |

### OH_ArkUI_SwiperArrowStyle_SetBackgroundColor()

```
void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t backgroundColor)
```

**描述：**


设置 Swiper 组件导航箭头底板颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| uint32_t backgroundColor | 导航箭头底板颜色，0xargb格式，形如 0xFFFF0000 表示红色。默认值：显示在导航指示器两侧为0x00000000，显示在Swiper两侧为0x19182431。 |

### OH_ArkUI_SwiperArrowStyle_GetBackgroundColor()

```
uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头底板颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 导航箭头底板颜色，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperArrowStyle_SetArrowSize()

```
void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize)
```

**描述：**


设置 Swiper 组件导航箭头大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| float arrowSize | 导航箭头大小，单位：vp。默认值：显示在导航指示器两侧18vp，显示在Swiper两侧24vp。显示导航箭头底板时，arrowSize固定为backgroundSize的3/4。 |

### OH_ArkUI_SwiperArrowStyle_GetArrowSize()

```
float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航箭头大小，单位：vp。 |

### OH_ArkUI_SwiperArrowStyle_SetArrowColor()

```
void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor)
```

**描述：**


设置 Swiper 组件导航箭头颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |
| uint32_t arrowColor | 导航箭头颜色，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperArrowStyle_GetArrowColor()

```
uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle)
```

**描述：**


获取 Swiper 组件导航箭头颜色。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | 导航箭头对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 导航箭头颜色，0xargb格式，形如 0xFFFF0000 表示红色。 |

### OH_ArkUI_SwiperIndicator_SetSpace()

```
void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space)
```

**描述：**


设置导航点间距。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |
| float space | 导航点间距。默认值：8，单位：vp。 |

### OH_ArkUI_SwiperIndicator_GetSpace()

```
float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator)
```

**描述：**


获取导航点间距。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 导航点间距。单位：vp。 |

### OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom()

```
void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize)
```

**描述：**


设置OH_ArkUI_SwiperDigitIndicator_SetBottomPosition是否忽略导航点大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 导航指示器对象指针。 |
| int32_t ignoreSize | 是否忽略导航点大小。1表示忽略导航点大小，0表示不忽略，默认值0。 |

### OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom()

```
int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator)
```

**描述：**


获取OH_ArkUI_SwiperDigitIndicator_SetBottomPosition是否忽略导航点大小。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | 导航指示器对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 是否忽略导航点大小。 |

### OH_ArkUI_ListItemSwipeActionItem_Create()

```
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()
```

**描述：**


创建ListItemSwipeActionItem接口设置的配置项。

**起始版本：** 12

**返回：**

| 类型                                 | 说明 |
|------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* | ListItemSwipeActionItem配置项实例。 |

### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```
void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)
```

**描述：**


销毁ListItemSwipeActionItem实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | 要销毁的ListItemSwipeActionItem实例。 |

### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```
void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)
```

**描述：**


设置ListItemSwipeActionItem的布局内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | 布局信息。 |

### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)
```

**描述：**


设置组件长距离滑动删除距离阈值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| float distance | 组件长距离滑动删除距离阈值。 |

### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)
```

**描述：**


获取组件长距离滑动删除距离阈值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 组件长距离滑动删除距离阈值。异常时返回值：0。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**描述：**


设置滑动条目进入删除区域时调用的事件。

**起始版本：** 12


**参数：**

| 参数项                                     | 描述 |
|-----------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| callback                                | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**描述：**


设置滑动条目进入删除区域时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| void* userData | 用户自定义数据。 |
| callback | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**描述：**


设置组件进入长距删除区后删除ListItem时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| callback | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**描述：**


设置组件进入长距删除区后删除ListItem时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| void* userData | 用户自定义数据。 |
| callback | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**描述：**


设置滑动条目退出删除区域时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| callback | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**描述：**


设置滑动条目退出删除区域时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| void* userData | 用户自定义数据。 |
| callback | 回调事件。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange(ArkUI_ListItemSwipeActionItem* item,void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState))
```

**描述：**


设置列表项滑动状态变化时候触发的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
| callback | 回调事件。swipeActionState 变化后的状态。 |

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))
```

**描述：**


设置列表项滑动状态变化时候触发的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | ListItemSwipeActionItem实例。 |
|  void* userData | 用户自定义数据。 |
| callback | 回调事件。swipeActionState 变化后的状态。 |

### OH_ArkUI_ListItemSwipeActionOption_Create()

```
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()
```

**描述：**


创建ListItemSwipeActionOption接口设置的配置项。

**起始版本：** 12

**返回：**

| 类型                                   | 说明 |
|--------------------------------------| -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* | ListItemSwipeActionOption配置项实例。 |

### OH_ArkUI_ListItemSwipeActionOption_Dispose()

```
void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)
```

**描述：**


销毁ListItemSwipeActionOption实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | 要销毁的ListItemSwipeActionOption实例。 |

### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```
void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)
```

**描述：**


设置ListItemSwipeActionItem的左侧（垂直布局）或上方（横向布局）布局内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | 布局信息。 |

### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeActionItem* item)
```

**描述：**


设置ListItemSwipeActionItem的右侧（垂直布局）或下方（横向布局）布局内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | 布局信息。 |

### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeEdgeEffect edgeEffect)
```

**描述：**


设置滑动效果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |
| [ArkUI_ListItemSwipeEdgeEffect](capi-native-type-h.md#arkui_listitemswipeedgeeffect) edgeEffect | 滑动效果。 |

### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)
```

**描述：**


获取滑动效果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 滑动效果。默认返回值：ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING。 |

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option,void (*callback)(float offset))
```

**描述：**


滑动操作偏移量更改时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |
| callback | 回调事件。offset 滑动偏移量。 |

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData(ArkUI_ListItemSwipeActionOption* option,void* userData, void (*callback)(float offset, void* userData))
```

**描述：**


滑动操作偏移量更改时调用的事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | ListItemSwipeActionItem实例。 |
|  void* userData | 用户自定义数据。 |
| callback | 回调事件。offset 滑动偏移量。 |

### OH_ArkUI_AccessibilityState_Create()

```
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)
```

**描述：**


创建无障碍状态。

**起始版本：** 12

**返回：**

| 类型                            | 说明 |
|-------------------------------| -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* | 无障碍状态对象指针。如果对象返回空指针，表示创建失败，失败的可能原因是应用地址空间满。 |

### OH_ArkUI_AccessibilityState_Dispose()

```
void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)
```

**描述：**


销毁无障碍状态指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |

### OH_ArkUI_AccessibilityState_SetDisabled()

```
void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)
```

**描述：**


设置无障碍状态是否禁用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |
| int32_t isDisabled | 无障碍状态是否禁用， 1表示禁用，0表示不禁用，默认为0。 |

### OH_ArkUI_AccessibilityState_IsDisabled()

```
int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)
```

**描述：**


获取无障碍状态是否禁用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 是否禁用， 1表示禁用，0表示未禁用，默认为0;<br>         若state为空，返回默认值。 |

### OH_ArkUI_AccessibilityState_SetSelected()

```
void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)
```

**描述：**


设置无障碍状态是否选中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |
| int32_t isSelected | 是否被选中， 1表示选中，0表示未选中，默认为0。 |

### OH_ArkUI_AccessibilityState_IsSelected()

```
int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)
```

**描述：**


获取无障碍状态是否选中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 是否被选中， 1表示选中，0表示未选中，默认为0;<br>         若state为空，返回默认值。 |

### OH_ArkUI_AccessibilityState_SetCheckedState()

```
void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)
```

**描述：**


设置无障碍状态复选框状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |
| int32_t checkedState | 复选框状态，参数类型[ArkUI_AccessibilityCheckedState](capi-native-type-h.md#arkui_accessibilitycheckedstate), 默认值：ARKUI_ACCESSIBILITY_UNCHECKED。 |

### OH_ArkUI_AccessibilityState_GetCheckedState()

```
int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)
```

**描述：**


获取无障碍状态复选框状态。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | 无障碍状态对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 复选框状态，参数类型[ArkUI_AccessibilityCheckedState](capi-native-type-h.md#arkui_accessibilitycheckedstate), 默认值：ARKUI_ACCESSIBILITY_UNCHECKED;<br>         若函数参数异常，返回默认值。 |

### OH_ArkUI_AccessibilityValue_Create()

```
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)
```

**描述：**


创建无障碍信息。

**起始版本：** 12

**返回：**

| 类型                            | 说明 |
|-------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* | 无障碍信息对象指针。 |

### OH_ArkUI_AccessibilityValue_Dispose()

```
void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)
```

**描述：**


销毁无障碍信息指针。

**起始版本：** 12


**参数：**

| 参数项                                                                                    | 描述 |
|----------------------------------------------------------------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |

### OH_ArkUI_AccessibilityValue_SetMin()

```
void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)
```

**描述：**


设置无障碍最小值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |
| int32_t min | 基于范围组件的最小值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetMin()

```
int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)
```

**描述：**


获取无障碍最小值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的最小值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetMax()

```
void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)
```

**描述：**


设置无障碍最大值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |
| int32_t max | 基于范围组件的最大值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetMax()

```
int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)
```

**描述：**


获取无障碍最大值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的最大值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetCurrent()

```
void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)
```

**描述：**


设置无障碍当前值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |
| int32_t current | 基于范围组件的当前值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetCurrent()

```
int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)
```

**描述：**


获取无障碍当前值信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的当前值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetRangeMin()

```
void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)
```

**描述：**


设置范围组件的无障碍最小值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要设置最小值的范围组件无障碍信息对象指针。 |
| int32_t rangeMin | 基于范围组件的最小值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetRangeMin()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)
```

**描述：**


获取范围组件的无障碍最小值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要获取最小值的范围组件无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的最小值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetRangeMax()

```
void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)
```

**描述：**


设置范围组件的无障碍最大值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要设置最大值的范围组件无障碍信息对象指针。 |
| int32_t rangeMax | 基于范围组件的最大值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetRangeMax()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)
```

**描述：**


获取范围组件的无障碍最大值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要获取最小值的范围组件无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的最大值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetRangeCurrent()

```
void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)
```

**描述：**


用于设置范围组件的无障碍当前值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要设置当前值的范围组件无障碍信息对象指针。 |
| int32_t rangeCurrent | 基于范围组件的当前值, 默认为-1。 |

### OH_ArkUI_AccessibilityValue_GetRangeCurrent()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)
```

**描述：**


用于获取范围组件的无障碍当前值信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 需要获取当前值的范围组件无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 基于范围组件的当前值, 默认为-1;<br>         若函数参数异常，返回-1。 |

### OH_ArkUI_AccessibilityValue_SetText()

```
void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)
```

**描述：**


设置无障碍文本描述信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |
| const char* text | 组件的文本描述信息, 默认为空字符串。 |

### OH_ArkUI_AccessibilityValue_GetText()

```
const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)
```

**描述：**


获取无障碍文本描述信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | 无障碍信息对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 组件的文本描述信息, 默认为空字符串;<br>         若函数参数异常，返回空指针。 |

### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src)
```

**描述：**


使用图片路径创建帧图片信息，图片格式为svg，png和jpg。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* src | 图片路径。 |

**返回：**

| 类型                                | 说明 |
|-----------------------------------| -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* | 帧图片对象指针。 |

### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(ArkUI_DrawableDescriptor* drawable)
```

**描述：**


使用 DrawableDescriptor 对象创建帧图片信息，图片格式为Resource和PixelMap。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawable | 使用Resource或PixelMap创建的ArkUI_DrawableDescriptor对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* | 帧图片对象指针。 |

### OH_ArkUI_ImageAnimatorFrameInfo_Dispose()

```
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


销毁帧图片对象指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

### OH_ArkUI_ImageAnimatorFrameInfo_SetWidth()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width)
```

**描述：**


设置图片宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |
| int32_t width | 图片宽度，单位为PX。 |

### OH_ArkUI_ImageAnimatorFrameInfo_GetWidth()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


获取图片宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 图片宽度，单位为PX，imageInfo为空指针时返回0。 |

### OH_ArkUI_ImageAnimatorFrameInfo_SetHeight()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height)
```

**描述：**


设置图片高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |
| int32_t height | 图片高度，单位为PX。 |

### OH_ArkUI_ImageAnimatorFrameInfo_GetHeight()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


获取图片高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 图片高度，单位为PX，imageInfo为空指针时返回0。 |

### OH_ArkUI_ImageAnimatorFrameInfo_SetTop()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top)
```

**描述：**


设置图片相对于组件左上角的纵向坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |
| int32_t top | 图片相对于组件左上角的纵向坐标，单位为PX。 |

### OH_ArkUI_ImageAnimatorFrameInfo_GetTop()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


获取图片相对于组件左上角的纵向坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 图片相对于组件左上角的纵向坐标，单位为PX，imageInfo为空指针时返回0。 |

### OH_ArkUI_ImageAnimatorFrameInfo_SetLeft()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left)
```

**描述：**


设置图片相对于组件左上角的横向坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |
| int32_t left | 图片相对于组件左上角的横向坐标，单位为PX。 |

### OH_ArkUI_ImageAnimatorFrameInfo_GetLeft()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


获取图片相对于组件左上角的横向坐标。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 图片相对于组件左上角的横向坐标，单位为PX，imageInfo为空指针时返回0。 |

### OH_ArkUI_ImageAnimatorFrameInfo_SetDuration()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration)
```

**描述：**


设置图片的播放时长。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |
| int32_t duration | 图片的播放时长，单位为毫秒。 |

### OH_ArkUI_ImageAnimatorFrameInfo_GetDuration()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**描述：**


获取图片的播放时长。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | 帧图片对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 图片的播放时长，单位为毫秒，imageInfo为空指针时返回0。 |

### OH_ArkUI_ListChildrenMainSizeOption_Create()

```
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()
```

**描述：**


创建ListChildrenMainSize接口设置的配置项。

**起始版本：** 12

**返回：**

| 类型                              | 说明 |
|---------------------------------| -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* | ListChildrenMainSize配置项实例。 |

### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```
void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)
```

**描述：**


销毁ListChildrenMainSize实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | 要销毁的ListChildrenMainSize实例。 |

### OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)
```

**描述：**


设置List组件的ChildrenMainSizeOption默认大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |
| float defaultMainSize | List下的ListItem的默认大小，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)
```

**描述：**


获取List组件的ChildrenMainSizeOption默认大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | List下的ListItem的默认大小，默认为0，单位为vp，option为空指针时返回-1。 |

### OH_ArkUI_ListChildrenMainSizeOption_Resize()

```
void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)
```

**描述：**


重置List组件的ChildrenMainSizeOption的数组大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |
| int32_t totalSize | 数组大小。 |

### OH_ArkUI_ListChildrenMainSizeOption_Splice()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)
```

**描述：**


对List组件的ChildrenMainSizeOption数组操作大小调整。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |
| int32_t index | 要修改MainSize的数组起始位置。 |
| int32_t deleteCount | 要删除的MainSize数组从index开始的数量。 |
| int32_t addCount | 要添加的MainSize数组从index开始的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ListChildrenMainSizeOption_UpdateSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)
```

**描述：**


更新List组件的ChildrenMainSizeOption数组的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |
| int32_t index | 要修改MainSize的数组起始位置。 |
| float mainSize | 实际修改的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。 |

### OH_ArkUI_ListChildrenMainSizeOption_GetMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)
```

**描述：**


获取List组件的ChildrenMainSizeOption数组的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | ListChildrenMainSize实例。 |
| int32_t index | 要获取的值的下标位置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 数组具体位置的值。若函数参数异常，返回-1。 |

### OH_ArkUI_CustomSpanMeasureInfo_Create()

```
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)
```

**描述：**


创建自定义段落组件测量信息。

**起始版本：** 12

**返回：**

| 类型                               | 说明 |
|----------------------------------| -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* | CustomSpanMeasureInfo实例。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanMeasureInfo_Dispose()

```
void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)
```

**描述：**


销毁自定义段落组件测量信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info |  自定义段落组件测量信息指针。 |

### OH_ArkUI_CustomSpanMeasureInfo_GetFontSize()

```
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)
```

**描述：**


获取自定义段落组件的父节点Text的字体大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info |  自定义段落组件测量信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 父节点Text的字体大小。若函数参数异常，返回0.0f。<br> 异常返回原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanMetrics_Create()

```
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)
```

**描述：**


创建自定义段落组件度量信息。

**起始版本：** 12

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* | CustomSpanMetrics实例。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanMetrics_Dispose()

```
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)
```

**描述：**


销毁自定义段落组件度量信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | CustomSpanMetrics实例。 |

### OH_ArkUI_CustomSpanMetrics_SetWidth()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)
```

**描述：**


设置自定义段落组件的宽度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | CustomSpanMetrics实例。 |
| float width | 宽度大小，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanMetrics_SetHeight()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)
```

**描述：**


设置自定义段落组件的高度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | CustomSpanMetrics实例。 |
| float height | 高度大小，单位为vp。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_Create()

```
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)
```

**描述：**


创建自定义段落组件绘制信息。

**起始版本：** 12

**返回：**

| 类型                            | 说明 |
|-------------------------------| -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* | CustomSpanDrawInfo实例。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_CustomSpanDrawInfo_Dispose()

```
void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)
```

**描述：**


销毁自定义段落组件绘制信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  自定义段落组件绘制信息指针。 |

### OH_ArkUI_CustomSpanDrawInfo_GetXOffset()

```
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)
```

**描述：**


获取自定义段落组件相对于挂载组件的x轴偏移值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  自定义段落组件绘制信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | x轴偏移值。若函数参数异常，返回0.0f。<br> 异常返回原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetLineTop()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)
```

**描述：**


获取自定义段落组件相对于挂载组件的上边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  自定义段落组件绘制信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 上边距值。若函数参数异常，返回0.0f。<br> 异常返回原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetLineBottom()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)
```

**描述：**


获取自定义段落组件相对于挂载组件的下边距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  自定义段落组件绘制信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 下边距值。若函数参数异常，返回0.0f。<br> 异常返回原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomSpanDrawInfo_GetBaseline()

```
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)
```

**描述：**


获取自定义段落组件相对于挂载组件的基线偏移量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  自定义段落组件绘制信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 基线偏移量值。若函数参数异常，返回0.0f。<br> 异常返回原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CustomProperty_Destroy()

```
void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)
```

**描述：**


销毁CustomProperty实例。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | 要销毁的CustomProperty实例。 |

### OH_ArkUI_CustomProperty_GetStringValue()

```
const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)
```

**描述：**


获取自定义属性value信息。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | 自定义属性对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 自定义属性value信息。 |

### OH_ArkUI_HostWindowInfo_GetName()

```
const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)
```

**描述：**


获取HostWindowInfo对象中的窗口名称。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | HostWindowInfo对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | HostWindowInfo对象中的窗口名称。 |

### OH_ArkUI_HostWindowInfo_Destroy()

```
void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)
```

**描述：**


销毁HostWindowInfo对象。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | 要销毁的HostWindowInfo对象。 |

### OH_ArkUI_ActiveChildrenInfo_Destroy()

```
void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)
```

**描述：**


销毁ActiveChildrenInfo实例。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | 要销毁的ActiveChildrenInfo实例。 |

### OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex()

```
ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)
```

**描述：**


获取ActiveChildrenInfo结构体的下标为index的子节点。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | 要获取信息的ActiveChildrenInfo实例。 |
| int32_t index | 子节点的下标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | 下标对应的子节点指针，异常时返回nullptr。 |

### OH_ArkUI_ActiveChildrenInfo_GetCount()

```
int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)
```

**描述：**


获取ActiveChildrenInfo结构体内的节点数量。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | 要获取信息的ActiveChildrenInfo实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 子节点数量，默认值0. |

### OH_ArkUI_ProgressLinearStyleOption_Create()

```
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
```

**描述：**


创建线性进度条样式信息。

**起始版本：** 15

**返回：**

| 类型                                   | 说明 |
|--------------------------------------| -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* | ProgressLinearStyleOption实例。<br> 如果返回空指针，可能是因为内存不足。 |

### OH_ArkUI_ProgressLinearStyleOption_Destroy()

```
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)
```

**描述：**


销毁线性进度条样式信息。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |

### OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled()

```
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**描述：**


设置进度平滑动效的开关。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |
| bool enabled | 进度平滑动效的开关。开启平滑动效后设置进度，进度会从当前值渐变至设定值，否则进度从当前值突变至设定值。默认值：true。 |

### OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled()

```
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**描述：**


设置扫光效果的开关。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |
| bool enabled | 扫光效果的开关。默认值：false。 |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth()

```
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)
```

**描述：**


设置进度条宽度。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |
| float strokeWidth | 进度条宽度值（不支持百分比设置），单位为vp，默认值：4.0vp。 |

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius()

```
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)
```

**描述：**


设置进度条圆角半径。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |
| float strokeRadius | 进度条圆角半径值，单位为vp，取值范围[0, strokeWidth/2]。默认值：strokeWidth/2。 |

### OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled()

```
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**描述：**


获取进度平滑动效的开关信息。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否开启平滑动效。 |

### OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled()

```
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**描述：**


获取扫光效果的开关信息。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否开启扫光效果。 |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth()

```
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)
```

**描述：**


获取进度条宽度。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 进度条宽度值，单位为vp。 |

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius()

```
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)
```

**描述：**


获取进度条圆角半径值。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | 线性进度条样式信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 进度条圆角半径值，单位为vp。 |

### OH_ArkUI_CreateSnapshotOptions()

```
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()
```

**描述：**


创建一个截图选项，当返回值不再使用时必须通过[OH_ArkUI_DestroySnapshotOptions()](#oh_arkui_destroysnapshotoptions)释放。

**起始版本：** 15

**返回：**

| 类型                         | 说明 |
|----------------------------| -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* | 返回指向创建的截图选项对象的指针。如果对象返回空指针，则表示创建失败，失败的原因可能是地址空间已满。 |

### OH_ArkUI_DestroySnapshotOptions()

```
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
```

**描述：**


销毁截图选项指针。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项。 |

### OH_ArkUI_SnapshotOptions_SetScale()

```
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
```

**描述：**


配置截图选项中的缩放属性。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | 截图选项。 |
| float scale | 缩放值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_CrossLanguageOption_Create()

```
ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)
```

**描述：**


创建跨语言配置项实例。

**起始版本：** 15

**返回：**

| 类型                             | 说明 |
|--------------------------------| -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* | 返回跨语言实例。如果对象返回空指针，则表示创建失败，失败的原因可能是地址空间已满。 |

### OH_ArkUI_CrossLanguageOption_Destroy()

```
void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)
```

**描述：**


销毁跨语言配置项实例。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | 要销毁的跨语言配置项实例。 |

### OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus()

```
void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)
```

**描述：**


设置配置项中是否允许跨语言修改属性。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | 跨语言配置项实例。 |
| bool enabled | 是否允许跨语言修改属性。默认值：false。 |

### OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus()

```
bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)
```

**描述：**


获取配置项中是否允许跨语言修改属性。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | 跨语言配置项实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 是否允许跨语言修改属性。 |

### OH_ArkUI_VisibleAreaEventOptions_Create()

```
ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()
```

**描述：**


创建可见区域变化监听的参数。

**起始版本：** 17

**返回：**

| 类型                                 | 说明 |
|------------------------------------| -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* | 可见区域变化监听的参数。 |

### OH_ArkUI_VisibleAreaEventOptions_Dispose()

```
void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)
```

**描述：**


销毁可见区域变化监听的参数。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 需要销毁的实例。 |

### OH_ArkUI_VisibleAreaEventOptions_SetRatios()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)
```

**描述：**


设置阈值数组。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |
| float* value | 阈值数组。其中每个元素代表组件可见面积（即组件在屏幕显示区的面积，只计算父组件内的面积，超出父组件部分不会计算）与组件自身面积的比值。每个阈值的取值范围为[0.0, 1.0]，如果开发者设置的阈值超出该范围，则会实际取值0.0或1.0。 |
| int32_t size | 阈值数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)
```

**描述：**


设置预期更新间隔，单位为ms。定义了开发者期望的更新间隔。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) *option | 可见区域变化监听的参数实例。 |
| int32_t value | 预期更新间隔，单位为ms。定义了开发者期望的更新间隔。默认值：1000。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_GetRatios()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)
```

**描述：**


获取阈值数组。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |
| float* value | 阈值数组。 |
| int32_t* size | 阈值数组大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 错误码。<br>         [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) 成功。<br>         [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) 函数参数异常。<br>         [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) 数组大小不够。<br>         异常原因：传入参数验证失败，参数不能为空。 |

### OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)
```

**描述：**


获取预期更新间隔。

**起始版本：** 17


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | 可见区域变化监听的参数实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 预期更新间隔，单位为ms。定义了开发者期望的更新间隔。默认值：1000。 |

### OH_ArkUI_TextPickerRangeContentArray_Create()

```
ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)
```

**描述：**


创建TextPickerRangeContent数组的对象。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t length | 指定TextPickerRangeContent数组的长度。 |

**返回：**

| 类型                                     | 说明 |
|----------------------------------------| -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* | 返回指向TextPickerRangeContent空数组的指针。 |

### OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex()

```
void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)
```

**描述：**


指定TextPickerRangeContent数组指定位置的icon数据。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向TextPickerRangeContent数组的指针。 |
| char* icon | 图片地址。 |
| int32_t index | 数组位置，从0开始。 |

### OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex()

```
void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)
```

**描述：**


指定TextPickerRangeContent数组指定位置的text数据。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向TextPickerRangeContent数组的指针。 |
| char* text | 文本内容。 |
| int32_t index | 数组位置，从0开始。 |

### OH_ArkUI_TextPickerRangeContentArray_Destroy()

```
void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)
```

**描述：**


删除TextPickerRangeContent数组对象。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向TextPickerRangeContent数组的指针。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_Create()

```
ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)
```

**描述：**


删除TextCascadePickerRangeContent数组对象。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t length | 指向TextPickerRangeContent数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* | 返回指向TextCascadePickerRangeContent空数组的指针。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)
```

**描述：**


指定TextCascadePickerRangeContent数组指定位置的text数据。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向TextCascadePickerRangeContentHandle的指针。 |
| char* text | 文本内容。 |
| int32_t index | 数组位置，从0开始。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)
```

**描述：**


指定TextCascadePickerRangeContent数组指定位置的child数据。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向TextCascadePickerRangeContentHandle的指针。 |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* child | 子节点数组指针。 |
| int32_t index | 数组位置，从0开始。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_Destroy()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy(ArkUI_TextCascadePickerRangeContentArray* handle)
```

**描述：**


删除TextCascadePickerRangeContent数组对象。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向TextCascadePickerRangeContentHandle的指针。 |

### OH_ArkUI_EmbeddedComponentOption_Create()

```
ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()
```

**描述：**


创建EmbeddedComponent组件选项的对象。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* | 返回指向EmbeddedComponent组件选项的对象的指针。 |

### OH_ArkUI_EmbeddedComponentOption_Dispose()

```
void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)
```

**描述：**


删除EmbeddedComponent组件选项的对象。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | 要销毁的EmbeddedComponent组件选项的对象的指针。 |

### OH_ArkUI_EmbeddedComponentOption_SetOnError()

```
void OH_ArkUI_EmbeddedComponentOption_SetOnError(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, const char* name, const char* message))
```

**描述：**


设置EmbeddedComponent组件的onError回调。EmbeddedComponent组件在运行过程中发生异常时触发本回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述                           |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | EmbeddedComponent组件选项的对象的指针。 |
| void (\*callback)(int32_t code, const char* name, const char* message) | 开发者自定义回调函数。<br>- code：接口调用失败返回的错误码信息。错误码的详细介绍请参考[UIExtension错误码](errorcode-uiextension.md)。<br>- name：接口调用失败返回的名称信息。<br>- message：接口调用失败返回的详细信息。 |


### OH_ArkUI_EmbeddedComponentOption_SetOnTerminated()

```
void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, AbilityBase_Want* want))
```

**描述：**


设置EmbeddedComponent组件的onTerminated回调。EmbeddedComponent组件正常退出时触发本回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述                           |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | EmbeddedComponent组件选项的对象的指针。 |
| void (\*callback)(int32_t code, [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md)* want) | 开发者自定义回调函数。<br>- code：被拉起EmbeddedUIExtensionAbility退出时返回的结果码。若Ability通过调用terminateSelfWithResult退出，结果码为Ability设置的值。若Ability通过调用terminateSelf退出，结果码为默认值"0"。<br>- want：被拉起EmbeddedUIExtensionAbility退出时返回的数据。   |


