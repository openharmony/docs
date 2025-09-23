# native_type.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Designer: @piggyguy; @xiang-shouxing; @yangfan229-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

## Overview

Defines the common types for the native module.

**File to include**: <arkui/native_type.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_ContextCallback](capi-arkui-nativemodule-arkui-contextcallback.md) | ArkUI_ContextCallback | Defines event callback.|
| [ArkUI_NumberValue](capi-arkui-nativemodule-arkui-numbervalue.md) | ArkUI_NumberValue | Provides the number types of ArkUI on the native side.|
| [ARKUI_TextPickerRangeContent](capi-arkui-nativemodule-arkui-textpickerrangecontent.md) | ARKUI_TextPickerRangeContent | Defines the struct of the single-column text picker with image resources.|
| [ARKUI_TextPickerCascadeRangeContent](capi-arkui-nativemodule-arkui-textpickercascaderangecontent.md) | ARKUI_TextPickerCascadeRangeContent | Defines the struct of the interconnected multi-column text picker.|
| [ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md) | ArkUI_ColorStop | Defines a gradient color stop.|
| [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md) | ArkUI_Rect | Defines a mask area.|
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | ArkUI_IntSize | Describes the width and height of a component.|
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | ArkUI_IntOffset | Describes the position of a component.|
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | ArkUI_Margin | Describes the margins of a component.|
| [ArkUI_TranslationOptions](capi-arkui-nativemodule-arkui-translationoptions.md) | ArkUI_TranslationOptions | Defines the translation options for component transition.|
| [ArkUI_ScaleOptions](capi-arkui-nativemodule-arkui-scaleoptions.md) | ArkUI_ScaleOptions | Defines the scaling options for component transition.|
| [ArkUI_RotationOptions](capi-arkui-nativemodule-arkui-rotationoptions.md) | ArkUI_RotationOptions | Defines the rotation options for component transition.|
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md) | ArkUI_LayoutConstraint | Defines the size constraints of a component during component layout.|
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md) | ArkUI_DrawContext | Defines the component drawing context.|
| [ArkUI_Node*](capi-arkui-nativemodule-arkui-node8h.md) | ArkUI_NodeHandle | Defines the pointer to the ArkUI native component object.|
| [ArkUI_NativeDialog*](capi-arkui-nativemodule-arkui-nativedialog8h.md) | ArkUI_NativeDialogHandle | Defines the handle to the custom dialog box controller of ArkUI on the native side.|
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) | ArkUI_WaterFlowSectionOption | Defines the water flow section configuration.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md) | ArkUI_ListItemSwipeActionItem | Defines the item configuration for **ListItemSwipeActionOption**.|
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) | ArkUI_ListItemSwipeActionOption | Defines the configuration for **ListItemSwipeActionOption**.|
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | Defines the handle to the ArkUI native UI context.|
| [ArkUI_NodeContent*](capi-arkui-nativemodule-arkui-nodecontent8h.md) | ArkUI_NodeContentHandle | Defines the handle to the ArkUI NodeContent instance on the native side.|
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md) | ArkUI_AlignmentRuleOption | Defines the alignment rule in the relative container.|
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md) | ArkUI_GuidelineOption | Defines the ID, direction, and position of a guideline.|
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md) | ArkUI_BarrierOption | Defines the ID, direction, and referenced component of a barrier.|
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md) | ArkUI_ImageAnimatorFrameInfo | Defines the image frame information.|
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md) | ArkUI_ListChildrenMainSize | Defines the **ChildrenMainSize** information of the **List** component.|
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption | Defines a struct for the linear progress indicator style.|
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md) | ArkUI_CustomProperty | Defines a struct for the custom property information.|
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) | ArkUI_HostWindowInfo | Defines a struct for the host window information.|
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) | ArkUI_ActiveChildrenInfo | Defines a struct for active child node information.|
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md) | ArkUI_CrossLanguageOption | Defines cross-language configuration options.|
| [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md) | AbilityBase_Want | Declares Want objects.|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md) | ArkUI_EmbeddedComponentOption | Defines the** EmbeddedComponentOption** struct for the **EmbeddedComponent** component.|
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md) | ArkUI_AccessibilityState | Defines a struct for the component accessibility state.|
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md) | ArkUI_AccessibilityValue | Defines a struct for the component accessibility value.|
| [ArkUI_SystemFontStyleEvent](capi-arkui-nativemodule-arkui-systemfontstyleevent.md) | ArkUI_SystemFontStyleEvent | Defines a struct for the system font style event.|
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md) | ArkUI_CustomSpanMeasureInfo | Defines a struct for the measurement information of a custom span.|
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md) | ArkUI_CustomSpanMetrics | Defines a struct for the measurement metrics of a custom span.|
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md) | ArkUI_CustomSpanDrawInfo | Defines a struct for the drawing information of a custom span.|
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md) | ArkUI_SwiperIndicator | Defines the navigation indicator style of the **Swiper** component.|
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) | ArkUI_SwiperDigitIndicator | Defines the digit-style navigation indicator of the **Swiper** component.|
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md) | ArkUI_SwiperArrowStyle | Defines the arrow style for the **Swiper** component.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) | ArkUI_StyledString_Descriptor | Defines a struct for the styled string descriptor object supported by the text component.|
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md) | ArkUI_SnapshotOptions | Defines a struct for snapshot options.|
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md) | ArkUI_TextPickerRangeContentArray | Defines the data selection list for the text picker.|
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md) | ArkUI_TextCascadePickerRangeContentArray | Defines the content array for a multi-column cascading data picker.|
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) | ArkUI_VisibleAreaEventOptions | Returns the created instance of visible area change event parameters.|

### Enums

| Name                                                                 | typedef Keyword                     | Description                               |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_Alignment](#arkui_alignment)                                 | ArkUI_Alignment                 | Enumerates the alignment modes.                       |
| [ArkUI_ImageRepeat](#arkui_imagerepeat)                             | ArkUI_ImageRepeat               | Enumerates the image repeat patterns.                     |
| [ArkUI_FontStyle](#arkui_fontstyle)                                 | ArkUI_FontStyle                 | Enumerates the font styles.                       |
| [ArkUI_FontWeight](#arkui_fontweight)                               | ArkUI_FontWeight                | Enumerates the font weights.                    |
| [ArkUI_TextAlignment](#arkui_textalignment)                         | ArkUI_TextAlignment             | Enumerates text alignment modes.                   |
| [ArkUI_TextVerticalAlignment](#arkui_textverticalalignment)         | ArkUI_TextVerticalAlignment     | Enumerates text vertical alignment styles.                   |
| [ArkUI_EnterKeyType](#arkui_enterkeytype)                           | ArkUI_EnterKeyType              | Enumerates the types of the Enter key for a single-line text box.               |
| [ArkUI_TextInputType](#arkui_textinputtype)                         | ArkUI_TextInputType             | Enumerates the text input types.                  |
| [ArkUI_TextAreaType](#arkui_textareatype)                           | ArkUI_TextAreaType              | Enumerates the text box types.                  |
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle)                 | ArkUI_CancelButtonStyle         | Enumerates the styles of the Cancel button.                     |
| [ArkUI_XComponentType](#arkui_xcomponenttype)                       | ArkUI_XComponentType            | Enumerates the types of the **XComponent** component.               |
| [ArkUI_ProgressType](#arkui_progresstype)                           | ArkUI_ProgressType              | Enumerates the styles of the progress indicator.                      |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype)               | ArkUI_TextDecorationType        | Enumerates the text decoration types.                      |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle)             | ArkUI_TextDecorationStyle       | Enumerates the text decoration styles.                      |
| [ArkUI_TextCase](#arkui_textcase)                                   | ArkUI_TextCase                  | Enumerates the text cases.                      |
| [ArkUI_CopyOptions](#arkui_copyoptions)                             | ArkUI_CopyOptions               | Enumerates the text copy and paste modes.                   |
| [ArkUI_ShadowType](#arkui_shadowtype)                               | ArkUI_ShadowType                | Enumerates shadow types.                       |
| [ArkUI_DatePickerMode](#arkui_datepickermode)                       | ArkUI_DatePickerMode            | Enumerates the column display modes of the date picker.                |
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype)             | ArkUI_TextPickerRangeType       | Enumerates the types of the text picker.                 |
| [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate) | ArkUI_AccessibilityCheckedState | Enumerates the accessibility check box states.                 |
| [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype)     | ArkUI_AccessibilityActionType   | Enumerates the accessibility action types.                       |
| [ArkUI_EdgeEffect](#arkui_edgeeffect)                               | ArkUI_EdgeEffect                | Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached.                     |
| [ArkUI_EffectEdge](#arkui_effectedge)                               | ArkUI_EffectEdge                | Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.                |
| [ArkUI_ScrollDirection](#arkui_scrolldirection)                     | ArkUI_ScrollDirection           | Enumerates the scroll directions of scrollable components.               |
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign)                     | ArkUI_ScrollSnapAlign           | Enumerates the alignment modes of list items when scrolling ends.                |
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode)           | ArkUI_ScrollBarDisplayMode      | Enumerates the scrollbar display modes.                      |
| [ArkUI_Axis](#arkui_axis)                                           | ArkUI_Axis                      | Enumerates the scroll directions.            |
| [ArkUI_StickyStyle](#arkui_stickystyle)                             | ArkUI_StickyStyle               | Enumerates the modes for pinning the header to the top or the footer to the bottom.                  |
| [ArkUI_ContentClipMode](#arkui_contentclipmode)                     | ArkUI_ContentClipMode           | Enumerates the content clipping modes of scrollable components.               |
| [ArkUI_WaterFlowLayoutMode](#arkui_waterflowlayoutmode)             | ArkUI_WaterFlowLayoutMode       | Enumerates the layout modes of the WaterFlow component.            |
| [ArkUI_BorderStyle](#arkui_borderstyle)                             | ArkUI_BorderStyle               | Enumerates the border styles.                       |
| [ArkUI_HitTestMode](#arkui_hittestmode)                             | ArkUI_HitTestMode               | Enumerates the hit test modes.                       |
| [ArkUI_ShadowStyle](#arkui_shadowstyle)                             | ArkUI_ShadowStyle               | Enumerates shadow styles.                         |
| [ArkUI_AnimationCurve](#arkui_animationcurve)                       | ArkUI_AnimationCurve            | Enumerates the animation curves.                         |
| [ArkUI_SwiperArrow](#arkui_swiperarrow)                             | ArkUI_SwiperArrow               | Enumerates arrow styles of the navigation indicator.                  |
| [ArkUI_SwiperNestedScrollMode](#arkui_swipernestedscrollmode)       | ArkUI_SwiperNestedScrollMode    | Enumerates the nested scrolling modes of the **Swiper** component and its parent container.             |
| [ArkUI_PageFlipMode](#arkui_pageflipmode)                           | ArkUI_PageFlipMode              | Enumerates the page flipping modes using the mouse wheel for the <b>Swiper</b> component.                |
| [ArkUI_SwiperAnimationMode](#arkui_swiperanimationmode)             | ArkUI_SwiperAnimationMode       | Enumerates the animation modes for the **Swiper** component when jumping to the page with the specified index.         |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode)                 | ArkUI_AccessibilityMode         | Enumerates the accessibility modes.                     |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions)                     | ArkUI_TextCopyOptions           | Enumerates copy options, which define whether copy and paste is allowed for text content.               |
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)   | ArkUI_TextHeightAdaptivePolicy  | Defines how the adaptive height is determined for the text.                    |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)                   | ArkUI_ScrollNestedMode          | Enumerates nested scrolling options.                        |
| [ArkUI_ScrollEdge](#arkui_scrolledge)                               | ArkUI_ScrollEdge                | Enumerates the edges to which the component scrolls.                      |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment)                     | ArkUI_ScrollAlignment           | Defines how the list item to scroll to is aligned with the container.                 |
| [ArkUI_ScrollState](#arkui_scrollstate)                             | ArkUI_ScrollState               | Enumerates the scrolling states.                        |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle)                   | ArkUI_SliderBlockStyle          | Enumerates the styles of the slider in the block direction.                          |
| [ArkUI_SliderDirection](#arkui_sliderdirection)                     | ArkUI_SliderDirection           | Enumerates the scroll directions of the slider.                       |
| [ArkUI_SliderStyle](#arkui_sliderstyle)                             | ArkUI_SliderStyle               | Enumerates the slider styles.                     |
| [ArkUI_CheckboxShape](#arkui_checkboxshape)                         | ArkUI_CheckboxShape             | Enumerates the shapes of the check box.                  |
| [ArkUI_AnimationPlayMode](#arkui_animationplaymode)                 | ArkUI_AnimationPlayMode         | Enumerates the animation playback modes.                        |
| [ArkUI_ImageSize](#arkui_imagesize)                                 | ArkUI_ImageSize                 | Defines the image size.                        |
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor)                         | ArkUI_AdaptiveColor             | Enumerates the adaptive color modes.                          |
| [ArkUI_ColorMode](#arkui_colormode)                                 | ArkUI_ColorMode                 | Enumerates the color modes.                         |
| [ArkUI_SystemColorMode](#arkui_systemcolormode)                     | ArkUI_SystemColorMode           | Enumerates the system color modes.                       |
| [ArkUI_BlurStyle](#arkui_blurstyle)                                 | ArkUI_BlurStyle                 | Enumerates the blur styles.                        |
| [ArkUI_BlurStyleActivePolicy](#arkui_blurstyleactivepolicy)         | ArkUI_BlurStyleActivePolicy     | Enumerates the activation policies for the background blur effect.                      |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment)                 | ArkUI_VerticalAlignment         | Enumerates the vertical alignment modes.                        |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment)             | ArkUI_HorizontalAlignment       | Enumerates the alignment mode in the horizontal direction.                      |
| [ArkUI_TextOverflow](#arkui_textoverflow)                           | ArkUI_TextOverflow              | Enumerates the display modes when the text is too long.                    |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)               | ArkUI_ImageSpanAlignment        | Enumerates the alignment mode of the image with the text.                   |
| [ArkUI_ObjectFit](#arkui_objectfit)                                 | ArkUI_ObjectFit                 | Enumerates the image filling effects.ImageSpanAlignment    |
| [ArkUI_ImageInterpolation](#arkui_imageinterpolation)               | ArkUI_ImageInterpolation        | Enumerates the image interpolation effects.                        |
| [ArkUI_DynamicRangeMode](#arkui_dynamicrangemode)                   | ArkUI_DynamicRangeMode          | Defines the image dynamic range mode (for example, SDR/HDR), which is used to control the brightness and color display range of the image.|
| [ArkUI_ImageRotateOrientation](#arkui_imagerotateorientation)       | ArkUI_ImageRotateOrientation    | Defines the image rotation direction.                        |
| [ArkUI_BlendMode](#arkui_blendmode)                                 | ArkUI_BlendMode                 | Enumerates the blend modes.                         |
| [ArkUI_Direction](#arkui_direction)                                 | ArkUI_Direction                 | Enumerates the modes in which components are laid out along the main axis of the container.              |
| [ArkUI_ItemAlignment](#arkui_itemalignment)                         | ArkUI_ItemAlignment             | Enumerates the modes in which components are laid out along the cross axis of the container.            |
| [ArkUI_ColorStrategy](#arkui_colorstrategy)                         | ArkUI_ColorStrategy             | Enumerates the foreground colors.                          |
| [ArkUI_FlexAlignment](#arkui_flexalignment)                         | ArkUI_FlexAlignment             | Enumerates the vertical alignment modes.                      |
| [ArkUI_FlexDirection](#arkui_flexdirection)                         | ArkUI_FlexDirection             | Enumerates the directions of the main axis in the flex container.                   |
| [ArkUI_FlexWrap](#arkui_flexwrap)                                   | ArkUI_FlexWrap                  | Defines whether the flex container has a single line or multiple lines.                  |
| [ArkUI_Visibility](#arkui_visibility)                               | ArkUI_Visibility                | Enumerates the visibility values.                      |
| [ArkUI_CalendarAlignment](#arkui_calendaralignment)                 | ArkUI_CalendarAlignment         | Enumerates the alignment modes between the calendar picker and the entry component.                  |
| [ArkUI_MaskType](#arkui_masktype)                                   | ArkUI_MaskType                  | Enumerates the mask types.                          |
| [ArkUI_ClipType](#arkui_cliptype)                                   | ArkUI_ClipType                  | Enumerates the clipping region types.                          |
| [ArkUI_ShapeType](#arkui_shapetype)                                 | ArkUI_ShapeType                 | Enumerates custom shape types.                           |
| [ArkUI_LinearGradientDirection](#arkui_lineargradientdirection)     | ArkUI_LinearGradientDirection   | Enumerates the gradient directions.                        |
| [ArkUI_WordBreak](#arkui_wordbreak)                                 | ArkUI_WordBreak                 | Enumerates the word break rules.                        |
| [ArkUI_EllipsisMode](#arkui_ellipsismode)                           | ArkUI_EllipsisMode              | Enumerates the ellipsis positions.                        |
| [ArkUI_ImageRenderMode](#arkui_imagerendermode)                     | ArkUI_ImageRenderMode           | Enumerates the image rendering modes.                        |
| [ArkUI_TransitionEdge](#arkui_transitionedge)                       | ArkUI_TransitionEdge            | Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.                 |
| [ArkUI_FinishCallbackType](#arkui_finishcallbacktype)               | ArkUI_FinishCallbackType        | Enumerates the animation **onFinish** callback types.             |
| [ArkUI_ListItemAlignment](#arkui_listitemalignment)                 | ArkUI_ListItemAlignment         | Enumerates the alignment modes of items along the cross axis.                      |
| [ArkUI_BlendApplyType](#arkui_blendapplytype)                       | ArkUI_BlendApplyType            | Defines how the specified blend mode is applied.               |
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit)                   | ArkUI_LengthMetricUnit          | Enumerates the component units.                       |
| [ArkUI_TextInputContentType](#arkui_textinputcontenttype)           | ArkUI_TextInputContentType      | Enumerates the autofill types.                        |
| [ArkUI_BarrierDirection](#arkui_barrierdirection)                   | ArkUI_BarrierDirection          | Enumerates the barrier directions.                        |
| [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle)   | ArkUI_RelativeLayoutChainStyle  | Enumerates the chain styles.                          |
| [ArkUI_TextInputStyle](#arkui_textinputstyle)                       | ArkUI_TextInputStyle            | Enumerates the text input styles.                         |
| [ArkUI_KeyboardAppearance](#arkui_keyboardappearance)               | ArkUI_KeyboardAppearance        | Enumerates the appearance modes of the keyboard when the text box is focused.                    |
| [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype)           | ArkUI_TextDataDetectorType      | Enumerates the entity types of text recognition.                     |
| [ArkUI_ButtonType](#arkui_buttontype)                               | ArkUI_ButtonType                | Enumerates the button types.                       |
| [ArkUI_RenderFit](#arkui_renderfit)                                 | ArkUI_RenderFit   | Enumerates the sizing and positioning behaviors of animated content in its final state.|
| [ArkUI_SwiperIndicatorType](#arkui_swiperindicatortype)             | ArkUI_SwiperIndicatorType       | Enumerates the navigation indicator types of the **Swiper** component.            |
| [ArkUI_AnimationDirection](#arkui_animationdirection)               | ArkUI_AnimationDirection        | Enumerates the animation playback modes.                          |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate)   | ArkUI_ListItemSwipeActionState  | Enumerates the swipe action item states of list items.|
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect)     | ArkUI_ListItemSwipeEdgeEffect   | Enumerates the swipe action item edge effects of list items.|
| [ArkUI_ListItemSwipeActionDirection](#arkui_listitemswipeactiondirection) | ArkUI_ListItemSwipeActionDirection | Defines the swipe-out direction of the Listitem component.|
| [ArkUI_AnimationStatus](#arkui_animationstatus)                     | ArkUI_AnimationStatus           | Enumerates the playback states of the frame-by-frame animation.                      |
| [ArkUI_AnimationFillMode](#arkui_animationfillmode)                 | ArkUI_AnimationFillMode         | Enumerates the states before and after execution of the frame-by-frame animation.            |
| [ArkUI_ErrorCode](#arkui_errorcode)                                 | ArkUI_ErrorCode                 | Enumerates the error codes.                        |
| [ArkUI_ScrollSource](#arkui_scrollsource)                           | ArkUI_ScrollSource              | Enumerates scroll sources.                       |
| [ArkUI_SafeAreaType](#arkui_safeareatype)                           | ArkUI_SafeAreaType              | Enumerates the types of expanded safe areas.                    |
| [ArkUI_SafeAreaEdge](#arkui_safeareaedge)                           | ArkUI_SafeAreaEdge              | Enumerates the edges for expanding the safe area.                 |
| [ArkUI_FocusMove](#arkui_focusmove)                                 | ArkUI_FocusMove                 | Enumerates the focus movement directions.                    |
| [ArkUI_ListItemGroupArea](#arkui_listitemgrouparea)                 | ArkUI_ListItemGroupArea         | Enumerates areas of the **ListItemGroup** component.           |
| [ArkUI_KeyboardAvoidMode](#arkui_keyboardavoidmode)                 | ArkUI_KeyboardAvoidMode         | Enumerates the soft keyboard avoidance modes.                          |
| [ArkUI_HoverModeAreaType](#arkui_hovermodeareatype)                 | ArkUI_HoverModeAreaType         | Enumerates the types of display areas for the hover mode.                         |
| [ArkUI_ExpandMode](#arkui_expandmode)                               | ArkUI_ExpandMode                | Enumerates the expansion mode of child nodes.                    |
| [ArkUI_NavDestinationState](#arkui_navdestinationstate)             | ArkUI_NavDestinationState       | Enumerates the **NavDestination** component states.           |
| [ArkUI_RouterPageState](#arkui_routerpagestate)                     | ArkUI_RouterPageState           | Enumerates the states of a page during routing.                |
| [ArkUI_UIState](#arkui_uistate)                                     | ArkUI_UIState                   | Enumerates the UI states of a component, used for handling state-specific styles.              |
| [ArkUI_FocusWrapMode](#arkui_focuswrapmode)                         | ArkUI_FocusWrapMode             | Enumerates the focus wrap mode of components.                        |
| [ArkUI_EdgeDirection](#arkui_edgedirection)                         | ArkUI_EdgeDirection             | Defines the direction of a rectangle edge.                        |
| [ArkUI_CornerDirection](#arkui_cornerdirection)                     | ArkUI_CornerDirection           | Defines the angle direction.                        |

### Functions

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()](#oh_arkui_layoutconstraint_create) | Creates a size constraint.|
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_copy) | Performs a deep copy of a size constraint.|
| [void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_dispose) | Disposes of the pointer to a size constraint.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxwidth) | Obtains the maximum width for a size constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminwidth) | Obtains the minimum width for a size constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxheight) | Obtains the maximum height for a size constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminheight) | Obtains the minimum height for a size constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferencewidth) | Obtains the width percentage reference for a size constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferenceheight) | Obtains the height percentage reference for a size constraint, in px.|
| [void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxwidth) | Sets the maximum width.|
| [void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminwidth) | Sets the minimum width.|
| [void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxheight) | Sets the maximum height.|
| [void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminheight) | Sets the minimum height.|
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferencewidth) | Sets the width percentage reference.|
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferenceheight) | Sets the height percentage reference.|
| [void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getcanvas) | Obtains the pointer to a canvas for drawing, which can be converted into the **OH_Drawing_Canvas** in the **Drawing** module.|
| [ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getsize) | Obtains the size of a drawing area.|
| [ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()](#oh_arkui_waterflowsectionoption_create) | Creates a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_dispose) | Disposes of the pointer to a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)](#oh_arkui_waterflowsectionoption_setsize) | Sets the array length for a water flow section configuration.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_getsize) | Obtains the array length for a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)](#oh_arkui_waterflowsectionoption_setitemcount) | Sets the number of items in a water flow section.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getitemcount) | Obtains the number of items in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)](#oh_arkui_waterflowsectionoption_setcrosscount) | Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcrosscount) | Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.|
| [void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)](#oh_arkui_waterflowsectionoption_setcolumngap) | Sets the gap between columns in the specified water flow section.|
| [float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcolumngap) | Obtains the gap between columns in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)](#oh_arkui_waterflowsectionoption_setrowgap) | Sets the gap between rows in the specified water flow section.|
| [float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getrowgap) | Obtains the gap between rows in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)](#oh_arkui_waterflowsectionoption_setmargin) | Sets the margins for the specified water flow section.|
| [ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getmargin) | Obtains the margins of the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption* option, int32_t index, float(\*callback)(int32_t itemIndex))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) | Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) | Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.|
| [ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)](#oh_arkui_guidelineoption_create) | Creates a guideline configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)](#oh_arkui_guidelineoption_dispose) | Disposes of a guideline configuration.|
| [void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)](#oh_arkui_guidelineoption_setid) | Sets the ID of a guideline.|
| [void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)](#oh_arkui_guidelineoption_setdirection) | Sets the direction of a guideline.|
| [void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionstart) | Sets the distance between a guideline and the left or top of the container.|
| [void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionend) | Sets the distance between a guideline and the right or bottom of the container.|
| [const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getid) | Obtains the ID of a guideline.|
| [ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getdirection) | Obtains the direction of a guideline.|
| [float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionstart) | Obtains the distance between a guideline and the left or top of the container.|
| [float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionend) | Obtains the distance between a guideline and the right or bottom of the container.|
| [ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)](#oh_arkui_barrieroption_create) | Creates a barrier configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)](#oh_arkui_barrieroption_dispose) | Disposes of a barrier configuration.|
| [void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setid) | Sets the ID of a barrier.|
| [void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)](#oh_arkui_barrieroption_setdirection) | Sets the direction of a barrier.|
| [void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setreferencedid) | Sets the referenced components of a barrier.|
| [const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getid) | Obtains the ID of a barrier.|
| [ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getdirection) | Obtains the direction of a barrier.|
| [const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)](#oh_arkui_barrieroption_getreferencedid) | Obtains the referenced components of a barrier.|
| [int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getreferencedidsize) | Obtains the number of referenced components of a barrier.|
| [ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()](#oh_arkui_alignmentruleoption_create) | Creates an alignment rule configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_dispose) | Disposes of an alignment rule configuration of this **RelativeContainer** component.|
| [void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setstart) | Sets the left alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setend) | Sets the right alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setcenterhorizontal) | Sets the horizontal center alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_settop) | Sets the top alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setbottom) | Sets the bottom alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setcentervertical) | Sets the vertical center alignment parameters.|
| [void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)](#oh_arkui_alignmentruleoption_setbiashorizontal) | Sets the bias value of the component in the horizontal direction under the anchor constraints.|
| [void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)](#oh_arkui_alignmentruleoption_setbiasvertical) | Sets the bias value of the component in the vertical direction under the anchor constraints.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartid) | Obtains the ID in the left alignment parameters.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartalignment) | Obtains the alignment mode in left alignment parameters.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendid) | Obtains the alignment mode in the right alignment parameters.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendalignment) | Obtains the alignment mode in the right alignment parameters.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridhorizontal) | Obtains the alignment mode in horizontal center alignment parameters.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) | Obtains the alignment mode in horizontal center alignment parameters.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopid) | Obtains the alignment mode in top alignment parameters.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopalignment) | Obtains the alignment mode in top alignment parameters.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomid) | Obtains the alignment mode in bottom alignment parameters.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomalignment) | Obtains the alignment mode in bottom alignment parameters.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridvertical) | Obtains the ID in vertical center alignment parameters.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) | Obtains the ID in vertical center alignment parameters.|
| [float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiashorizontal) | Obtains the bias value in the horizontal direction.|
| [float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiasvertical) | Obtains the bias value in the vertical direction.|
| [ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type)](#oh_arkui_swiperindicator_create) | Creates a navigation indicator for this **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_dispose) | Disposes of the navigation indicator of this **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setstartposition) | Sets the distance between a navigation indicator and the left edge of the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getstartposition) | Obtains the distance between a navigation indicator and the left edge of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_settopposition) | Sets the distance between the navigation indicator and the top edge of the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_gettopposition) | Obtains the distance between the navigation indicator and the top edge of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setendposition) | Sets the distance between the navigation indicator and the right edge of the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getendposition) | Obtains the distance between a navigation indicator and the right edge of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setbottomposition) | Sets the distance between the navigation indicator and the bottom edge of the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getbottomposition) | Obtains the distance between the navigation indicator and the bottom edge of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize)](#oh_arkui_swiperindicator_setignoresizeofbottom) | Sets whether the **OH_ArkUI_SwiperIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.|
| [int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getignoresizeofbottom) | Checks whether the **OH_ArkUI_SwiperIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.|
| [void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setitemwidth) | Sets the width of a dot-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getitemwidth) | Obtains the width of a dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setitemheight) | Sets the height of a dot-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getitemheight) | Obtains the height of a dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setselecteditemwidth) | Sets the width of the selected dot-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselecteditemwidth) | Obtains the width of the selected dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value)](#oh_arkui_swiperindicator_setselecteditemheight) | Sets the height of the selected dot-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselecteditemheight) | Obtains the height of the selected dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask)](#oh_arkui_swiperindicator_setmask) | Sets whether to enable the mask for a dot-style navigation indicator for the **Swiper** component.|
| [int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getmask) | Obtains whether the mask is enabled for a dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color)](#oh_arkui_swiperindicator_setcolor) | Sets the color of a dot-style navigation indicator for the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getcolor) | Obtains the color of a dot-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor)](#oh_arkui_swiperindicator_setselectedcolor) | Sets the color of the selected dot-style navigation indicator for the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getselectedcolor) | Obtains the color of the selected dot-style navigation indicator of the **Swiper** component.|
| [int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount)](#oh_arkui_swiperindicator_setmaxdisplaycount) | Sets the maximum number of dots for the dot-style navigation indicator.|
| [int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getmaxdisplaycount) | Obtains the maximum number of dots for the dot-style navigation indicator.|
| [ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create()](#oh_arkui_swiperdigitindicator_create) | Creates a digit-style navigation indicator for this **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_destroy) | Disposes of the digit-style navigation indicator of this **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setstartposition) | Sets the start position of the digit-style navigation indicator for the **Swiper** component. This determines the distance from the left edge of the **Swiper** component. For right-to-left scripts, this determines the distance from the right edge.|
| [float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getstartposition) | Obtains the start position of the digit-style navigation indicator for the **Swiper** component. This indicates the distance from the left edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the right edge.|
| [void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_settopposition) | Sets the distance from the digit-style navigation indicator to the top of the **Swiper** component.|
| [float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_gettopposition) | Obtains the distance from the digit-style navigation indicator to the top of the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setendposition) | Sets the end position of the digit-style navigation indicator for the **Swiper** component. This determines the distance from the right edge of the **Swiper** component. For right-to-left scripts, this determines the distance from the left edge.|
| [float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getendposition) | Obtains the end position of the digit-style navigation indicator for the **Swiper** component. This indicates the distance from the right edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the left edge.|
| [void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value)](#oh_arkui_swiperdigitindicator_setbottomposition) | Sets the distance from the digit-style navigation indicator to the bottom of the **Swiper** component.|
| [float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getbottomposition) | Obtains the distance from the digit-style navigation indicator to the bottom of the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color)](#oh_arkui_swiperdigitindicator_setfontcolor) | Sets the font color of the digit-style navigation indicator for the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontcolor) | Obtains the font color of the digit-style navigation indicator for the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor)](#oh_arkui_swiperdigitindicator_setselectedfontcolor) | Sets the font color of the selected digit-style navigation indicator for the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontcolor) | Obtains the font color of the selected digit-style navigation indicator for the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)](#oh_arkui_swiperdigitindicator_setfontsize) | Sets the font size of the digit-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontsize) | Obtains the font size of the digit-style navigation indicator for the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)](#oh_arkui_swiperdigitindicator_setselectedfontsize) | Sets the font size of the selected digit-style navigation indicator for the **Swiper** component.|
| [float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontsize) | Obtains the font size of the selected digit-style navigation indicator for the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)](#oh_arkui_swiperdigitindicator_setfontweight) | Sets the font weight of the digit-style navigation indicator for the **Swiper** component.|
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontweight) | Obtains the font weight of the digit-style navigation indicator for the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)](#oh_arkui_swiperdigitindicator_setselectedfontweight) | Sets the font weight of the selected digit-style navigation indicator for the **Swiper** component.|
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontweight) | Obtains the font weight of the selected digit-style navigation indicator for the **Swiper** component.|
| [ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create()](#oh_arkui_swiperarrowstyle_create) | Creates an arrow style for the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_destroy) | Disposes of the arrow of the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showBackground)](#oh_arkui_swiperarrowstyle_setshowbackground) | Sets whether to display the background of the arrow for the **Swiper** component.|
| [int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getshowbackground) | Checks whether the background of the arrow is displayed for the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle)](#oh_arkui_swiperarrowstyle_setshowsidebarmiddle) | Sets the position of the arrow for the **Swiper** component.|
| [int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getshowsidebarmiddle) | Obtains the position of the arrow for the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize)](#oh_arkui_swiperarrowstyle_setbackgroundsize) | Sets the background size for the arrow of the **Swiper** component.|
| [float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getbackgroundsize) | Obtains the background size of the arrow of the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t backgroundColor)](#oh_arkui_swiperarrowstyle_setbackgroundcolor) | Sets the background color for the arrow of the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getbackgroundcolor) | Obtains the background color for the arrow of the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize)](#oh_arkui_swiperarrowstyle_setarrowsize) | Sets the size for the arrow of the **Swiper** component.|
| [float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getarrowsize) | Obtains the size of the arrow of the **Swiper** component.|
| [void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor)](#oh_arkui_swiperarrowstyle_setarrowcolor) | Sets the color for the arrow of the **Swiper** component.|
| [uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle)](#oh_arkui_swiperarrowstyle_getarrowcolor) | Obtains the color of the arrow of the **Swiper** component.|
| [void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space)](#oh_arkui_swiperindicator_setspace) | Sets the spacing between navigation points.|
| [float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator)](#oh_arkui_swiperindicator_getspace) | Obtains the spacing between navigation points.|
| [void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize)](#oh_arkui_swiperdigitindicator_setignoresizeofbottom) | Sets whether the **OH_ArkUI_SwiperDigitIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.|
| [int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getignoresizeofbottom) | Checks whether the **OH_ArkUI_SwiperDigitIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.|
| [ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()](#oh_arkui_listitemswipeactionitem_create) | Creates a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_dispose) | Disposes of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)](#oh_arkui_listitemswipeactionitem_setcontent) | Sets the layout content for a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)](#oh_arkui_listitemswipeactionitem_setactionareadistance) | Sets the swipe distance threshold for deleting the list item.|
| [float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_getactionareadistance) | Obtains the swipe distance threshold for deleting the list item.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonenteractionarea) | Sets the callback invoked each time the list item enters the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonenteractionareawithuserdata) | Sets the callback invoked each time the list item enters the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonaction) | Sets the callback invoked when the list item is deleted while in the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonactionwithuserdata) | Sets the callback invoked when the list item is deleted while in the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonexitactionarea) | Sets the callback invoked each time the list item exits the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonexitactionareawithuserdata) | Sets the callback invoked each time the list item exits the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem* item,void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState))](#oh_arkui_listitemswipeactionitem_setonstatechange) | Sets the callback invoked when the swipe state of the list item changes.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))](#oh_arkui_listitemswipeactionitem_setonstatechangewithuserdata) | Sets the callback invoked when the swipe state of the list item changes.|
| [ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()](#oh_arkui_listitemswipeactionoption_create) | Creates a **ListItemSwipeActionOption** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_dispose) | Disposes of a **ListItemSwipeActionOption** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setstart) | Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setend) | Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeEdgeEffect edgeEffect)](#oh_arkui_listitemswipeactionoption_setedgeeffect) | Sets the edge effect used when the boundary of the scrolling area is reached.|
| [int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_getedgeeffect) | Obtains the edge effect used when the boundary of the scrolling area is reached.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option, void (\*callback)(float offset))](#oh_arkui_listitemswipeactionoption_setonoffsetchange) | Sets the callback invoked when the scroll offset changes.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData (ArkUI_ListItemSwipeActionOption* option, void* userData, void (\*callback)(float offset, void* userData))](#oh_arkui_listitemswipeactionoption_setonoffsetchangewithuserdata) | Sets the callback invoked when the scroll offset changes.|
| [int32_t OH_ArkUI_ListItemSwipeAction_Expand(ArkUI_NodeHandle node, ArkUI_ListItemSwipeActionDirection direction)](#oh_arkui_listitemswipeaction_expand) |  Expands the menu of a specified list item.|
| [int32_t OH_ArkUI_ListItemSwipeAction_Collapse(ArkUI_NodeHandle node)](#oh_arkui_listitemswipeaction_collapse) |  Collapses the menu of a specified list item.|
| [ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)](#oh_arkui_accessibilitystate_create) | Creates an accessibility state.|
| [void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_dispose) | Disposes of the pointer to an accessibility state.|
| [void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)](#oh_arkui_accessibilitystate_setdisabled) | Sets whether an accessibility state is disabled.|
| [int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isdisabled) | Obtains whether an accessibility state is disabled.|
| [void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)](#oh_arkui_accessibilitystate_setselected) | Sets whether an accessibility state is selected.|
| [int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isselected) | Obtains whether an accessibility state is selected.|
| [void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)](#oh_arkui_accessibilitystate_setcheckedstate) | Sets the check box state of an accessibility state.|
| [int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_getcheckedstate) | Obtains the check box state of an accessibility state.|
| [ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)](#oh_arkui_accessibilityvalue_create) | Creates an **AccessibilityValue** instance.|
| [void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_dispose) | Disposes of the pointer to an **AccessibilityValue** instance.|
| [void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)](#oh_arkui_accessibilityvalue_setmin) | Sets the minimum accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmin) | Obtains the minimum accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)](#oh_arkui_accessibilityvalue_setmax) | Sets the maximum accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmax) | Obtains the maximum accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)](#oh_arkui_accessibilityvalue_setcurrent) | Sets the current accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getcurrent) | Obtains the current accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)](#oh_arkui_accessibilityvalue_setrangemin) | Sets the minimum value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemin) | Obtains the minimum value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)](#oh_arkui_accessibilityvalue_setrangemax) | Sets the maximum value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemax) | Obtains the maximum value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)](#oh_arkui_accessibilityvalue_setrangecurrent) | Sets the current value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangecurrent) | Obtains the current value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)](#oh_arkui_accessibilityvalue_settext) | Sets the text description of an **AccessibilityValue** instance.|
| [const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_gettext) | Obtains the text description of an **AccessibilityValue** instance.|
| [ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src)](#oh_arkui_imageanimatorframeinfo_createfromstring) | Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG.|
| [ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(ArkUI_DrawableDescriptor* drawable)](#oh_arkui_imageanimatorframeinfo_createfromdrawabledescriptor) | Creates an image frame information object based on a **DrawableDescriptor** object, with the image format being Resource or PixelMap.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_dispose) | Disposes of the pointer to an image frame information object.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width)](#oh_arkui_imageanimatorframeinfo_setwidth) | Sets the image width.|
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getwidth) | Obtains the image width.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height)](#oh_arkui_imageanimatorframeinfo_setheight) | Sets the image height.|
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getheight) | Obtains the image height.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top)](#oh_arkui_imageanimatorframeinfo_settop) | Sets the vertical coordinate of an image relative to the upper left corner of the component.|
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_gettop) | Obtains the vertical coordinate of an image relative to the upper left corner of the component.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left)](#oh_arkui_imageanimatorframeinfo_setleft) | Sets the horizontal coordinate of an image relative to the upper left corner of the component.|
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getleft) | Obtains the horizontal coordinate of an image relative to the upper left corner of the component.|
| [void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration)](#oh_arkui_imageanimatorframeinfo_setduration) | Sets the playback duration of an image.|
| [int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo)](#oh_arkui_imageanimatorframeinfo_getduration) | Obtains the playback duration of an image.|
| [ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()](#oh_arkui_listchildrenmainsizeoption_create) | Creates a **ListChildrenMainSize** instance.|
| [void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_dispose) | Destroys a ListChildrenMainSize instance.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)](#oh_arkui_listchildrenmainsizeoption_setdefaultmainsize) | Sets the default size in a **ListChildrenMainSize** instance.|
| [float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_getdefaultmainsize) | Obtains the default size in a **ListChildrenMainSize** instance.|
| [void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)](#oh_arkui_listchildrenmainsizeoption_resize) | Resets the array size in a **ListChildrenMainSize** instance.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)](#oh_arkui_listchildrenmainsizeoption_splice) | Changes the content of a **ChildrenMainSizeOption** array.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)](#oh_arkui_listchildrenmainsizeoption_updatesize) | Updates the values in a **ChildrenMainSizeOption** array of a **List** component.|
| [float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)](#oh_arkui_listchildrenmainsizeoption_getmainsize) | Obtains the value of the **ChildrenMainSizeOption** array of the **List** component.|
| [ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)](#oh_arkui_customspanmeasureinfo_create) | Creates measurement information for this custom span.|
| [void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_dispose) | Disposes of measurement information of a custom span.|
| [float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_getfontsize) | Obtains the font size of the parent text node of a custom span.|
| [ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)](#oh_arkui_customspanmetrics_create) | Creates measurement metrics for this custom span.|
| [void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)](#oh_arkui_customspanmetrics_dispose) | Disposes of measurement metrics of this custom span.|
| [int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)](#oh_arkui_customspanmetrics_setwidth) | Sets the width for a custom span.|
| [int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)](#oh_arkui_customspanmetrics_setheight) | Sets the height for a custom span.|
| [ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)](#oh_arkui_customspandrawinfo_create) | Creates drawing information for this custom span.|
| [void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_dispose) | Disposes of drawing information for this custom span.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getxoffset) | Obtains the x-axis offset of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinetop) | Obtains the top margin of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinebottom) | Obtains the bottom margin of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getbaseline) | Obtains the baseline offset of the custom span relative to the mounted component.|
| [void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_destroy) | Destroys a **CustomProperty** instance.|
| [const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_getstringvalue) | Obtains the value of a custom property.|
| [const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_getname) | Obtains the window name from a **HostWindowInfo** object.|
| [void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_destroy) | Destroys n **HostWindowInfo** object.|
| [void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_destroy) | Destroys an **ActiveChildrenInfo** instance.|
| [ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)](#oh_arkui_activechildreninfo_getnodebyindex) | Obtains the child node at the specified index in the specified **ActiveChildrenInfo** instance.|
| [int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_getcount) | Obtains the number of nodes in the specified **ActiveChildrenInfo** instance.|
| [ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)](#oh_arkui_progresslinearstyleoption_create) | Creates a **ProgressLinearStyleOption** instance.|
| [void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_destroy) | Destroys a **ProgressLinearStyleOption** instance.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setsmootheffectenabled) | Sets whether to enable the smooth progress effect.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setscaneffectenabled) | Sets whether to enable the scan effect.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)](#oh_arkui_progresslinearstyleoption_setstrokewidth) | Sets the width of the progress indicator.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)](#oh_arkui_progresslinearstyleoption_setstrokeradius) | Sets the corner radius of the progress indicator.|
| [bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getsmootheffectenabled) | Obtains the enabled status of the smooth progress effect.|
| [bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getscaneffectenabled) | Obtains the enabled status of the scan effect.|
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokewidth) | Obtains the stroke width of the progress indicator.|
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokeradius) | Obtains the corner radius of the progress indicator.|
| [ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()](#oh_arkui_createsnapshotoptions) | Creates a snapshot option. The snapshot option must be destroyed by calling [OH_ArkUI_DestroySnapshotOptions()](#oh_arkui_destroysnapshotoptions) when the return value is no longer used.|
| [void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)](#oh_arkui_destroysnapshotoptions) | Destroys a snapshot options object.|
| [int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)](#oh_arkui_snapshotoptions_setscale) | Sets the scale property in the snapshot options.|
| [ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)](#oh_arkui_crosslanguageoption_create) | Creates an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_destroy) | Destroys an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)](#oh_arkui_crosslanguageoption_setattributesettingstatus) | Sets whether cross-language attribute setting is allowed in the configuration option.|
| [bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_getattributesettingstatus) | Checks whether cross-language attribute setting is allowed in the configuration option.|
| [ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()](#oh_arkui_visibleareaeventoptions_create) | Creates an instance of visible area change event parameters.|
| [void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_dispose) | Disposes of an instance of visible area change event parameters.|
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)](#oh_arkui_visibleareaeventoptions_setratios) | Sets the threshold ratios for visible area changes.|
| [int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)](#oh_arkui_visibleareaeventoptions_setexpectedupdateinterval) | Sets the expected update interval for visible area changes.  |
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)](#oh_arkui_visibleareaeventoptions_getratios) | Obtains the threshold ratios for visible area changes.|
| [int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)](#oh_arkui_visibleareaeventoptions_getexpectedupdateinterval) | Obtains the expected update interval for visible area changes.|
| [ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)](#oh_arkui_textpickerrangecontentarray_create) | Creates a **TextPickerRangeContent** array object.|
| [void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)](#oh_arkui_textpickerrangecontentarray_seticonatindex) | Sets the icon data at the specified position in the **TextPickerRangeContent** array.|
| [void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textpickerrangecontentarray_settextatindex) | Sets the text data at the specified position in the **TextPickerRangeContent** array.|
| [void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)](#oh_arkui_textpickerrangecontentarray_destroy) | Destroys a **TextPickerRangeContent** array object.|
| [ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)](#oh_arkui_textcascadepickerrangecontentarray_create) | Destroys a **TextCascadePickerRangeContent** array object.|
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_settextatindex) | Sets the text data at the specified position in the **TextCascadePickerRangeContent** array.|
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_setchildatindex) | Sets the child data at the specified position in the **TextCascadePickerRangeContent** array.|
| [void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy (ArkUI_TextCascadePickerRangeContentArray* handle)](#oh_arkui_textcascadepickerrangecontentarray_destroy) | Destroys a **TextCascadePickerRangeContent** array object.|
| [ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()](#oh_arkui_embeddedcomponentoption_create) | Creates an **EmbeddedComponent** option object.|
| [void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)](#oh_arkui_embeddedcomponentoption_dispose) | Disposes of an **EmbeddedComponent** option object.|
| [void OH_ArkUI_EmbeddedComponentOption_SetOnError (ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, const char* name, const char* message))](#oh_arkui_embeddedcomponentoption_setonerror) | Sets the **onError** callback for the **EmbeddedComponent** component. This callback is triggered when an error occurs during the running of the **EmbeddedComponent** component.|
| [void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated (ArkUI_EmbeddedComponentOption* option, void (\*callback)(int32_t code, AbilityBase_Want* want))](#oh_arkui_embeddedcomponentoption_setonterminated) | Sets the **onTerminated** callback for the **EmbeddedComponent** component. This callback is triggered when the **EmbeddedComponent** component exits properly.|

## Enum Description

### ArkUI_Alignment

```
enum ArkUI_Alignment
```

**Description**


Enumerates the alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ALIGNMENT_TOP_START = 0 | Top start.|
| ARKUI_ALIGNMENT_TOP | Top center.|
| ARKUI_ALIGNMENT_TOP_END | Top end.|
| ARKUI_ALIGNMENT_START | Vertically centered start.|
| ARKUI_ALIGNMENT_CENTER | Horizontally and vertically centered.|
| ARKUI_ALIGNMENT_END | Vertically centered end.|
| ARKUI_ALIGNMENT_BOTTOM_START | Bottom start.|
| ARKUI_ALIGNMENT_BOTTOM | Horizontally centered on the bottom.|
| ARKUI_ALIGNMENT_BOTTOM_END | Bottom end.|

### ArkUI_ImageRepeat

```
enum ArkUI_ImageRepeat
```

**Description**


Enumerates the image repeat patterns.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_IMAGE_REPEAT_NONE = 0 | The image is not repeatedly drawn.|
| ARKUI_IMAGE_REPEAT_X | The image is repeatedly drawn only along the x-axis.|
| ARKUI_IMAGE_REPEAT_Y | The image is repeatedly drawn only along the y-axis.|
| ARKUI_IMAGE_REPEAT_XY | The image is repeatedly drawn along both axes.|

### ArkUI_FontStyle

```
enum ArkUI_FontStyle
```

**Description**


Enumerates the font styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FONT_STYLE_NORMAL = 0 | Standard font style.|
| ARKUI_FONT_STYLE_ITALIC | Italic font style.|

### ArkUI_FontWeight

```
enum ArkUI_FontWeight
```

**Description**


Enumerates the font weights.

**Since**: 12

| Value| Description|
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
| ARKUI_FONT_WEIGHT_BOLD | The font weight is bold.|
| ARKUI_FONT_WEIGHT_NORMAL | The font weight is normal.|
| ARKUI_FONT_WEIGHT_BOLDER | The font weight is bolder.|
| ARKUI_FONT_WEIGHT_LIGHTER | The font weight is lighter.|
| ARKUI_FONT_WEIGHT_MEDIUM | The font weight is medium.|
| ARKUI_FONT_WEIGHT_REGULAR | The font weight is normal.|

### ArkUI_TextAlignment

```
enum ArkUI_TextAlignment
```

**Description**


Enumerates the text alignment mode.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_ALIGNMENT_START = 0 | Aligned with the start.|
| ARKUI_TEXT_ALIGNMENT_CENTER | Horizontally centered.|
| ARKUI_TEXT_ALIGNMENT_END | Aligned with the end.|
| ARKUI_TEXT_ALIGNMENT_JUSTIFY | Aligned with both margins.|

### ArkUI_TextVerticalAlignment

```
enum ArkUI_TextVerticalAlignment
```

**Description**


Enumerates text vertical alignment styles.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0 | Aligned to the baseline.|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM | Bottom aligned.|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER | The list item is centered along|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP | Top aligned.|

### ArkUI_TextContentAlign

```
enum ArkUI_TextContentAlign
```

**Description**


Defines the enumerated values of the vertical alignment style of a text content area.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_TEXT_CONTENT_ALIGN_TOP = 0 | Top aligned.|
| ARKUI_TEXT_CONTENT_ALIGN_CENTER = 1 | The list item is centered along|
| ARKUI_TEXT_CONTENT_ALIGN_BOTTOM = 2 | Bottom aligned.|

### ArkUI_EnterKeyType

```
enum ArkUI_EnterKeyType
```

**Description**


Enumerates the types of the Enter key for a single-line text box.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ENTER_KEY_TYPE_GO = 2 | The Enter key is labeled "Go."|
| ARKUI_ENTER_KEY_TYPE_SEARCH = 3 | The Enter key is labeled "Search."|
| ARKUI_ENTER_KEY_TYPE_SEND | The Enter key is labeled "Send."|
| ARKUI_ENTER_KEY_TYPE_NEXT | The Enter key is labeled "Next."|
| ARKUI_ENTER_KEY_TYPE_DONE | The Enter key is labeled "Done."|
| ARKUI_ENTER_KEY_TYPE_PREVIOUS | The Enter key is labeled "Previous."|
| ARKUI_ENTER_KEY_TYPE_NEW_LINE | The Enter key is labeled "Return."|

### ArkUI_TextInputType

```
enum ArkUI_TextInputType
```

**Description**


Enumerates the text input types.

**Since**: 12

| Value| Description                      |
| -- |--------------------------|
| ARKUI_TEXTINPUT_TYPE_NORMAL = 0 | Normal input mode.                 |
| ARKUI_TEXTINPUT_TYPE_NUMBER = 2 | Number input mode.                  |
| ARKUI_TEXTINPUT_TYPE_PHONE_NUMBER = 3 | Phone number input mode.               |
| ARKUI_TEXTINPUT_TYPE_EMAIL = 5 | Email address input mode.               |
| ARKUI_TEXTINPUT_TYPE_PASSWORD = 7 | Password input mode.                 |
| ARKUI_TEXTINPUT_TYPE_NUMBER_PASSWORD = 8 | Numeric password input mode.              |
| ARKUI_TEXTINPUT_TYPE_SCREEN_LOCK_PASSWORD = 9 | Lock screen password input mode.             |
| ARKUI_TEXTINPUT_TYPE_USER_NAME = 10 | Username input mode.                |
| ARKUI_TEXTINPUT_TYPE_NEW_PASSWORD = 11 | New password input mode.                |
| ARKUI_TEXTINPUT_TYPE_NUMBER_DECIMAL = 12 | Number input mode with a decimal point.            |
| ARKUI_TEXTINPUT_TYPE_ONE_TIME_CODE = 14 | Verification code input mode.<br>**Since**: 20|

### ArkUI_TextAreaType

```
enum ArkUI_TextAreaType
```

**Description**


Enumerates the text box types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXTAREA_TYPE_NORMAL = 0 | Normal input mode.|
| ARKUI_TEXTAREA_TYPE_NUMBER = 2 | Number input mode.|
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3 | Phone number input mode.|
| ARKUI_TEXTAREA_TYPE_EMAIL = 5 | Email address input mode.|
| ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14 | Verification code input mode.<br>**Since**: 20|

### ArkUI_CancelButtonStyle

```
enum ArkUI_CancelButtonStyle
```

**Description**


Enumerates the styles of the Cancel button.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0 | The Cancel button is always displayed.|
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE | The Cancel button is always hidden.|
| ARKUI_CANCELBUTTON_STYLE_INPUT | The Cancel button is displayed when there is text input.|

### ArkUI_XComponentType

```
enum ArkUI_XComponentType
```

**Description**


Enumerates the types of the **XComponent** component.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_XCOMPONENT_TYPE_SURFACE = 0 | The custom content of EGL/OpenGL ES and media data is displayed individually on the screen.|
| ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 | The custom content of EGL/OpenGL ES and media data is grouped and displayed together with content of the component.|

### ArkUI_ProgressType

```
enum ArkUI_ProgressType
```

**Description**


Enumerates the styles of the progress indicator.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_PROGRESS_TYPE_LINEAR = 0 | Linear type.|
| ARKUI_PROGRESS_TYPE_RING | Ring style without scale marks.|
| ARKUI_PROGRESS_TYPE_ECLIPSE | Eclipse style.|
| ARKUI_PROGRESS_TYPE_SCALE_RING | Ring style with scale marks.|
| ARKUI_PROGRESS_TYPE_CAPSULE | Capsule style.|

### ArkUI_TextDecorationType

```
enum ArkUI_TextDecorationType
```

**Description**


Enumerates the text decoration types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DECORATION_TYPE_NONE = 0 | No text decoration.|
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE | Line under the text.|
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE | Line over the text.|
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH | Line through the text.|

### ArkUI_TextDecorationStyle

```
enum ArkUI_TextDecorationStyle
```

**Description**


Enumerates the text decoration styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID = 0 | Single solid line.|
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE | Double solid line.|
| ARKUI_TEXT_DECORATION_STYLE_DOTTED | Dotted line.|
| ARKUI_TEXT_DECORATION_STYLE_DASHED | Dashed style.|
| ARKUI_TEXT_DECORATION_STYLE_WAVY | Wavy line.|

### ArkUI_TextCase

```
enum ArkUI_TextCase
```

**Description**


Enumerates the text cases.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_CASE_NORMAL = 0 | The original case of the text is retained.|
| ARKUI_TEXT_CASE_LOWER | All letters in the text are in lowercase.|
| ARKUI_TEXT_CASE_UPPER | All letters in the text are in uppercase.|

### ArkUI_CopyOptions

```
enum ArkUI_CopyOptions
```

**Description**


Enumerates the text copy and paste modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_COPY_OPTIONS_NONE = 0 | Copy is not allowed.|
| ARKUI_COPY_OPTIONS_IN_APP | Intra-application copy is allowed.|
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE | Intra-device copy is allowed.|
| ARKUI_COPY_OPTIONS_CROSS_DEVICE | Cross-device copy is allowed.|

### ArkUI_ShadowType

```
enum ArkUI_ShadowType
```

**Description**


Enumerates shadow types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SHADOW_TYPE_COLOR = 0 | Color.|
| ARKUI_SHADOW_TYPE_BLUR | Blur.|

### ArkUI_DatePickerMode

```
enum ArkUI_DatePickerMode
```

**Description**


Enumerates the column display modes of the date picker.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_DATEPICKER_MODE_DATE = 0 | Default value. The date displays three columns: year, month, and day.|
| ARKUI_DATEPICKER_YEAR_AND_MONTH = 1 | The date displays two columns: year and month.|
| ARKUI_DATEPICKER_MONTH_AND_DAY = 2 | The date displays two columns: month and day.|

### ArkUI_TextPickerRangeType

```
enum ArkUI_TextPickerRangeType
```

**Description**


Enumerates the types of the text picker.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0 | Single-column text picker.|
| ARKUI_TEXTPICKER_RANGETYPE_MULTI | Multi-column text picker.|
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT | Single-column text picker with image resources.|
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT | Interconnected multi-column text picker.|

### ArkUI_AccessibilityCheckedState

```
enum ArkUI_AccessibilityCheckedState
```

**Description**


Enumerates the accessibility check box states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_UNCHECKED = 0 | The check box is not selected.|
| ARKUI_ACCESSIBILITY_CHECKED | The check box is selected.|

### ArkUI_AccessibilityActionType

```
enum ArkUI_AccessibilityActionType
```

**Description**


Enumerates the accessibility action types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_ACTION_CLICK = 1 << 0 | Tapping|
| ARKUI_ACCESSIBILITY_ACTION_LONG_CLICK = 1 << 1 | Long press|
| ARKUI_ACCESSIBILITY_ACTION_CUT = 1 << 2 | Cut.|
| ARKUI_ACCESSIBILITY_ACTION_COPY = 1 << 3 | Copy.|
| ARKUI_ACCESSIBILITY_ACTION_PASTE = 1 << 4 | Paste.|

### ArkUI_EdgeEffect

```
enum ArkUI_EdgeEffect
```

**Description**


Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_EDGE_EFFECT_SPRING = 0 | Spring effect. When at one of the edges, the component can move beyond the bounds based on the initial speed or through touches, and produces a bounce effect when the user releases their finger.|
| ARKUI_EDGE_EFFECT_FADE | Fade effect. When at one of the edges, the component produces a fade effect.|
| ARKUI_EDGE_EFFECT_NONE | No effect when the component is at one of the edges.|

### ArkUI_EffectEdge

```
enum ArkUI_EffectEdge
```

**Description**


Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.

**Since**: 18

| Value| Description                   |
| -- |-----------------------|
| ARKUI_EFFECT_EDGE_START = 1 | Start edge.               |
| ARKUI_EFFECT_EDGE_END = 2 | End edge.               |

### ArkUI_ScrollDirection

```
enum ArkUI_ScrollDirection
```

**Description**


Enumerates the scroll directions of scrollable components.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_DIRECTION_VERTICAL = 0 | Vertical scrolling only.|
| ARKUI_SCROLL_DIRECTION_HORIZONTAL | Horizontal scrolling only.|
| ARKUI_SCROLL_DIRECTION_NONE = 3 | Scrolling disabled.|
| ARKUI_SCROLL_DIRECTION_FREE = 4 | Free scrolling in both directions.<br>**Since**: 20|

### ArkUI_ScrollSnapAlign

```
enum ArkUI_ScrollSnapAlign
```

**Description**


Enumerates the alignment modes of list items when scrolling ends.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE = 0 | No alignment. This is the default value.|
| ARKUI_SCROLL_SNAP_ALIGN_START | The first item in the view is aligned at the start of the list.|
| ARKUI_SCROLL_SNAP_ALIGN_CENTER | The middle items in the view are aligned in the center of the list.|
| ARKUI_SCROLL_SNAP_ALIGN_END | The last item in the view is aligned at the end of the list.|

### ArkUI_ScrollBarDisplayMode

```
enum ArkUI_ScrollBarDisplayMode
```

**Description**


Enumerates the scrollbar display modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0 | Not displayed.|
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO | Displayed when the screen is touched and hidden after 2s.|
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON | Always displayed.|

### ArkUI_Axis

```
enum ArkUI_Axis
```

**Description**


Enumerates the scroll directions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_AXIS_VERTICAL = 0 | Only vertical scrolling is supported.|
| ARKUI_AXIS_HORIZONTAL | Only horizontal scrolling is supported.|

### ArkUI_StickyStyle

```
enum ArkUI_StickyStyle
```

**Description**


Enumerates the modes for pinning the header to the top or the footer to the bottom.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_STICKY_STYLE_NONE = 0 | In the list item group, the header is not pinned to the top, and the footer is not pinned to the bottom.|
| ARKUI_STICKY_STYLE_HEADER = 1 | In the list item group, the header is pinned to the top, and the footer is not pinned to the bottom.|
| ARKUI_STICKY_STYLE_FOOTER = 2 | In the list item group, the footer is pinned to the bottom, and the header is not pinned to the top.|
| ARKUI_STICKY_STYLE_BOTH = 3 | In the list item group, the footer is pinned to the bottom, and the header is pinned to the top.|

### ArkUI_ContentClipMode

```
enum ArkUI_ContentClipMode
```

**Description**


Enumerates the content clipping modes of scrollable components.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0 | Clip to the content area only.|
| ARKUI_CONTENT_CLIP_MODE_BOUNDARY | Clip to the component's boundary area.|
| ARKUI_CONTENT_CLIP_MODE_SAFE_AREA | Clip to the safe area configured for the component.|

### ArkUI_WaterFlowLayoutMode

```
enum ArkUI_WaterFlowLayoutMode
```

**Description**


Enumerates the layout modes of the WaterFlow component.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0 | Layout from top to bottom. In scenarios where column switching occurs, the layout starts from the first water flow item to the currently displayed water flow item.|
| ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW | Sliding window layout. In scenarios where column switching occurs, only the range of water flow items currently on display is re-laid out. As the user scrolls down with their finger, water flow items that enter the display range from above are subsequently laid out.|

### ArkUI_BorderStyle

```
enum ArkUI_BorderStyle
```

**Description**


Enumerates the border styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BORDER_STYLE_SOLID = 0 | Solid border.|
| ARKUI_BORDER_STYLE_DASHED | Dashed border.|
| ARKUI_BORDER_STYLE_DOTTED | Dotted border.|

### ArkUI_HitTestMode

```
enum ArkUI_HitTestMode
```

**Description**


Enumerates the hit test modes.

**Since**: 12

| Value| Description                                                    |
| -- |--------------------------------------------------------|
| ARKUI_HIT_TEST_MODE_DEFAULT = 0 | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test.                                             |
| ARKUI_HIT_TEST_MODE_BLOCK | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test.                                             |
| ARKUI_HIT_TEST_MODE_TRANSPARENT | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test.                                        |
| ARKUI_HIT_TEST_MODE_NONE | The node does not respond to the hit test of a touch event.                                            |
| ARKUI_HIT_TEST_MODE_BLOCK_HIERARCHY | The node and its child nodes participate in hit tests, while blocking hit tests for all sibling nodes and parent nodes with lower priority.<br>**Since**: 20|
| ARKUI_HIT_TEST_MODE_BLOCK_DESCENDANTS | The node does not respond to hit tests, and none of its descendants (including children and grandchildren) participate in hit tests either.<br>**Since**: 20                    |

### ArkUI_ShadowStyle

```
enum ArkUI_ShadowStyle
```

**Description**


Enumerates shadow styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_XS = 0 | Mini shadow.|
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_SM | Small shadow.|
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_MD | Medium shadow.|
| ARKUI_SHADOW_STYLE_OUTER_DEFAULT_LG | Large shadow.|
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_SM | Floating small shadow.|
| ARKUI_SHADOW_STYLE_OUTER_FLOATING_MD | Floating medium shadow.|

### ArkUI_AnimationCurve

```
enum ArkUI_AnimationCurve
```

**Description**


Enumerates the animation curves.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_CURVE_LINEAR = 0 | The animation speed keeps unchanged.|
| ARKUI_CURVE_EASE | The animation starts slowly, accelerates, and then slows down towards the end.|
| ARKUI_CURVE_EASE_IN | The animation starts at a low speed and then picks up speed until the end.|
| ARKUI_CURVE_EASE_OUT | The animation ends at a low speed.|
| ARKUI_CURVE_EASE_IN_OUT | The animation starts and ends at a low speed.|
| ARKUI_CURVE_FAST_OUT_SLOW_IN | The animation uses the standard curve|
| ARKUI_CURVE_LINEAR_OUT_SLOW_IN | The animation uses the deceleration curve.|
| ARKUI_CURVE_FAST_OUT_LINEAR_IN | The animation uses the acceleration curve.|
| ARKUI_CURVE_EXTREME_DECELERATION | The animation uses the extreme deceleration curve.|
| ARKUI_CURVE_SHARP | The animation uses the sharp curve.|
| ARKUI_CURVE_RHYTHM | The animation uses the rhythm curve.|
| ARKUI_CURVE_SMOOTH | The animation uses the smooth curve.|
| ARKUI_CURVE_FRICTION | The animation uses the friction curve|

### ArkUI_SwiperArrow

```
enum ArkUI_SwiperArrow
```

**Description**


Enumerates arrow styles of the navigation indicator.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SWIPER_ARROW_HIDE = 0 | The arrow is not displayed for the navigation indicator.|
| ARKUI_SWIPER_ARROW_SHOW | The arrow is displayed for the navigation indicator.|
| ARKUI_SWIPER_ARROW_SHOW_ON_HOVER | The arrow is displayed only when the mouse pointer hovers over the navigation indicator.|

### ArkUI_SwiperNestedScrollMode

```
enum ArkUI_SwiperNestedScrollMode
```

**Description**


Enumerates the nested scrolling mode of the **Swiper** component and its parent container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_ONLY = 0 | The scrolling is contained within the **Swiper** component, and no scroll chaining occurs, that is, the parent container does not scroll when the component scrolling reaches the boundary.|
| ARKUI_SWIPER_NESTED_SRCOLL_SELF_FIRST | The **Swiper** component scrolls first, and when it hits the boundary, the parent container scrolls. When the parent container hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent container, the edge effect of the child component is displayed instead.|

### ArkUI_PageFlipMode

```
enum ArkUI_PageFlipMode
```

**Description**


Enumerates the page flipping modes using the mouse wheel for the <b>Swiper</b> component.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_PAGE_FLIP_MODE_CONTINUOUS = 0 | When the mouse wheel is scrolled continuously, multiple pages are flipped, which is determined by the number of times that mouse events are reported.|
| ARKUI_PAGE_FLIP_MODE_SINGLE | The system does not respond to other mouse wheel events until the page flipping animation ends.|

### ArkUI_SwiperAnimationMode

```
enum ArkUI_SwiperAnimationMode
```

**Description**


Enumerates the animation modes for the **Swiper** component when jumping to the page with the specified index.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_SWIPER_NO_ANIMATION = 0 | Jumps to the target page without any animation.|
| ARKUI_SWIPER_DEFAULT_ANIMATION = 1 | Animates smoothly to the target page.|
| ARKUI_SWIPER_FAST_ANIMATION = 2 | First jumps to a position near the target page without animation, then animates to the target page.|

### ArkUI_AccessibilityMode

```
enum ArkUI_AccessibilityMode
```

**Description**


Enumerates the accessibility modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_MODE_AUTO = 0 | The mode is automatically set to enabled or disabled based on the component.|
| ARKUI_ACCESSIBILITY_MODE_ENABLED | The component can be identified by the accessibility service.|
| ARKUI_ACCESSIBILITY_MODE_DISABLED | The component cannot be identified by the accessibility service.|
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS | The component and all its child components cannot be identified by the accessibility service.|

### ArkUI_TextCopyOptions

```
enum ArkUI_TextCopyOptions
```

**Description**


Enumerates copy options, which define whether copy and paste is allowed for text content.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_COPY_OPTIONS_NONE = 0 | Copy is not allowed.|
| ARKUI_TEXT_COPY_OPTIONS_IN_APP | Intra-application copy is allowed.|
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE | Intra-device copy is allowed.|
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE | Cross-device copy is allowed.|

### ArkUI_TextHeightAdaptivePolicy

```
enum ArkUI_TextHeightAdaptivePolicy
```

**Description**


Defines how the adaptive height is determined for the text.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0 | Prioritize the **maxLines** settings.|
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST | Prioritize the **minFontSize** settings.|
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST | Prioritize the layout constraint settings in terms of height.|

### ArkUI_ScrollNestedMode

```
enum ArkUI_ScrollNestedMode
```

**Description**


Enumerates the nested scrolling modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0 | The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component does not scroll when the component scrolling reaches the boundary.|
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST | The component scrolls first, and when it hits the boundary, the parent component scrolls. When the parent component hits the boundary, its edge effect is displayed.|
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST | The parent component scrolls first, and when it hits the boundary, the component scrolls.|
| ARKUI_SCROLL_NESTED_MODE_PARALLEL | The component and its parent component scroll at the same time. When both the component and its parent component hit the boundary, the edge effect of the component is displayed.|

### ArkUI_ScrollEdge

```
enum ArkUI_ScrollEdge
```

**Description**


Enumerates the edges to which the component scrolls.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_EDGE_TOP = 0 | Top edge in the vertical direction.|
| ARKUI_SCROLL_EDGE_BOTTOM | Bottom edge in the vertical direction.|
| ARKUI_SCROLL_EDGE_START | Start position in the horizontal direction.|
| ARKUI_SCROLL_EDGE_END | End position in the horizontal direction.|

### ArkUI_ScrollAlignment

```
enum ArkUI_ScrollAlignment
```

**Description**


Defines how the list item to scroll to is aligned with the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_ALIGNMENT_START = 0 | The start edge of the list item is flush with the start edge of the container.|
| ARKUI_SCROLL_ALIGNMENT_CENTER | The list item is centered along the main axis of the container.|
| ARKUI_SCROLL_ALIGNMENT_END | The end edge of the list item is flush with the end edge of the container.|
| ARKUI_SCROLL_ALIGNMENT_AUTO | The list item is automatically aligned. If the item is fully contained within the display area, no adjustment is performed. Otherwise, the item is aligned so that its start or end edge is flush with the start or end edge of the container, whichever requires a shorter scrolling distance.|

### ArkUI_ScrollState

```
enum ArkUI_ScrollState
```

**Description**


Enumerates the scrolling states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_STATE_IDLE = 0 | Idle. The container enters this state when an API in the controller is used to scroll the container or when the scrollbar is dragged.|
| ARKUI_SCROLL_STATE_SCROLL | Scrolling. The container enters this state when the user drags the container to scroll.|
| ARKUI_SCROLL_STATE_FLING | Inertial scrolling. The container enters this state when inertial scrolling occurs or when the container bounces back after being released from a fling.|

### ArkUI_SliderBlockStyle

```
enum ArkUI_SliderBlockStyle
```

**Description**


Enumerates the styles of the slider in the block direction.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0 | Round slider.|
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE | Slider with an image background.|
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE | Slider in a custom shape.|

### ArkUI_SliderDirection

```
enum ArkUI_SliderDirection
```

**Description**


Enumerates the scroll directions of the slider.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_DIRECTION_VERTICAL = 0 | Vertical direction.|
| ARKUI_SLIDER_DIRECTION_HORIZONTAL | Horizontal direction.|

### ArkUI_SliderStyle

```
enum ArkUI_SliderStyle
```

**Description**


Enumerates the slider styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_STYLE_OUT_SET = 0 | The slider is on the slider rail.|
| ARKUI_SLIDER_STYLE_IN_SET | The slider is in the slider rail.|
| ARKUI_SLIDER_STYLE_NONE | There is no thumb.|

### ArkUI_CheckboxShape

```
enum ArkUI_CheckboxShape
```

**Description**


Enumerates the shapes of the check box.

**Since**: 12

| Value| Description|
| -- | -- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE = 0 | Circle.|
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE | Rounded square.|

### ArkUI_AnimationPlayMode

```
enum ArkUI_AnimationPlayMode
```

**Description**


Enumerates the animation playback modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ANIMATION_PLAY_MODE_NORMAL = 0 | The animation is played forwards.|
| ARKUI_ANIMATION_PLAY_MODE_REVERSE | The animation is played backwards.|
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE | The animation is played forwards for an odd number of times (1, 3, 5...) and backwards for an even number of times (2, 4, 6...).|
| ARKUI_ANIMATION_PLAY_MODE_ALTERNATE_REVERSE | The animation is played backwards for an odd number of times (1, 3, 5...) and forwards for an even number of times (2, 4, 6...).|

### ArkUI_ImageSize

```
enum ArkUI_ImageSize
```

**Description**


Defines the image size.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_IMAGE_SIZE_AUTO = 0 | The original image aspect ratio is retained.|
| ARKUI_IMAGE_SIZE_COVER | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries.|
| ARKUI_IMAGE_SIZE_CONTAIN | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries.|

### ArkUI_AdaptiveColor

```
enum ArkUI_AdaptiveColor
```

**Description**


Enumerates the adaptive color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT = 0 | Adaptive color mode is not used.|
| ARKUI_ADAPTIVE_COLOR_AVERAGE | Adaptive color mode is used.|

### ArkUI_ColorMode

```
enum ArkUI_ColorMode
```

**Description**


Enumerates the color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_COLOR_MODE_SYSTEM = 0 | Following the system color mode.|
| ARKUI_COLOR_MODE_LIGHT | Light color mode.|
| ARKUI_COLOR_MODE_DARK | Dark color mode.|

### ArkUI_SystemColorMode

```
enum ArkUI_SystemColorMode
```

**Description**


Enumerates the system color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SYSTEM_COLOR_MODE_LIGHT = 0 | Light mode.|
| ARKUI_SYSTEM_COLOR_MODE_DARK | Dark mode.|

### ArkUI_BlurStyle

```
enum ArkUI_BlurStyle
```

**Description**


Enumerates the blur styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BLUR_STYLE_THIN = 0 | Thin material.|
| ARKUI_BLUR_STYLE_REGULAR | Regular material.|
| ARKUI_BLUR_STYLE_THICK | Thick material.|
| ARKUI_BLUR_STYLE_BACKGROUND_THIN | Material that creates the minimum depth of field effect.|
| ARKUI_BLUR_STYLE_BACKGROUND_REGULAR | Material that creates a medium shallow depth of field effect.|
| ARKUI_BLUR_STYLE_BACKGROUND_THICK | Material that creates a high shallow depth of field effect.|
| ARKUI_BLUR_STYLE_BACKGROUND_ULTRA_THICK | Material that creates the maximum depth of field effect.|
| ARKUI_BLUR_STYLE_NONE | No blur.|
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THIN | Component ultra-thin material.|
| ARKUI_BLUR_STYLE_COMPONENT_THIN | Component thin material.|
| ARKUI_BLUR_STYLE_COMPONENT_REGULAR | Component regular material.|
| ARKUI_BLUR_STYLE_COMPONENT_THICK | Component thick material.|
| ARKUI_BLUR_STYLE_COMPONENT_ULTRA_THICK | Component ultra-thick material.|

### ArkUI_BlurStyleActivePolicy

```
enum ArkUI_BlurStyleActivePolicy
```

**Description**


Enumerates the activation policies for the background blur effect.

**Since**: 19

| Value| Description|
| -- | -- |
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_FOLLOWS_WINDOW_ACTIVE_STATE = 0 | The blur effect changes according to the window's focus state; it is inactive when the window is not in focus and active when the window is in focus.|
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_ACTIVE | The blur effect is always active.|
| ARKUI_BLUR_STYLE_ACTIVE_POLICY_ALWAYS_INACTIVE | The blur effect is always inactive.|

### ArkUI_VerticalAlignment

```
enum ArkUI_VerticalAlignment
```

**Description**


Enumerates the vertical alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_VERTICAL_ALIGNMENT_TOP = 0 | Top aligned.|
| ARKUI_VERTICAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode.|
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM | Bottom aligned.|

### ArkUI_HorizontalAlignment

```
enum ArkUI_HorizontalAlignment
```

**Description**


Enumerates the alignment mode in the horizontal direction.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_HORIZONTAL_ALIGNMENT_START = 0 | Aligned with the start edge in the same direction as the language in use.|
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER | Aligned with the center. This is the default alignment mode.|
| ARKUI_HORIZONTAL_ALIGNMENT_END | Aligned with the end edge in the same direction as the language in use.|

### ArkUI_TextOverflow

```
enum ArkUI_TextOverflow
```

**Description**


Enumerates the display modes when the text is too long.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_OVERFLOW_NONE = 0 | Extra-long text is not clipped.|
| ARKUI_TEXT_OVERFLOW_CLIP | Extra-long text is clipped.|
| ARKUI_TEXT_OVERFLOW_ELLIPSIS | An ellipsis (...) is used to represent text overflow.|
| ARKUI_TEXT_OVERFLOW_MARQUEE | Text continuously scrolls when text overflow occurs.|

### ArkUI_ImageSpanAlignment

```
enum ArkUI_ImageSpanAlignment
```

**Description**


Enumerates the alignment mode of the image with the text.

**Since**: 12

| Value| Description                                |
| -- |------------------------------------|
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0 | The image is bottom aligned with the text baseline.               |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM | The image is bottom aligned with the text.                    |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER | The image is centered aligned with the text.                      |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP | The image is top aligned with the text.                    |
| ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH | The image alignment mode follows the text component's alignment mode.<br>**Since**: 20|

### ArkUI_ObjectFit

```
enum ArkUI_ObjectFit
```

**Description**


Enumerates the image filling effects.ImageSpanAlignment

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_OBJECT_FIT_CONTAIN = 0 | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries.|
| ARKUI_OBJECT_FIT_COVER | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries.|
| ARKUI_OBJECT_FIT_AUTO | The image is scaled automatically to fit the display area.|
| ARKUI_OBJECT_FIT_FILL | The image is scaled to fill the display area, and its aspect ratio is not retained.|
| ARKUI_OBJECT_FIT_SCALE_DOWN | The image is displayed with its aspect ratio retained, in a size smaller than or equal to the original size.|
| ARKUI_OBJECT_FIT_NONE | The original size is retained.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_START | Not resized, the image is aligned with the start edge of the top of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP | Not resized, the image is horizontally centered at the top of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_TOP_END | Not resized, the image is aligned with the end edge at the top of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_START | Not resized, the image is vertically centered on the start edge of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_CENTER | Not resized, the image is horizontally and vertically centered in the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_END | Not resized, the image is vertically centered on the end edge of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_START | Not resized, the image is aligned with the start edge at the bottom of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM | Not resized, the image is horizontally centered at the bottom of the container.|
| ARKUI_OBJECT_FIT_NONE_AND_ALIGN_BOTTOM_END | Not resized, the image is aligned with the end edge at the bottom of the container.|
| ARKUI_OBJECT_FIT_NONE_MATRIX | Keeps the original image size. This function must be used together with NODE_IMAGE_IMAGE_MATRIX.|

### ArkUI_ImageInterpolation

```
enum ArkUI_ImageInterpolation
```

**Description**


Enumerates the image interpolation effects.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_IMAGE_INTERPOLATION_NONE = 0 | No image interpolation.|
| ARKUI_IMAGE_INTERPOLATION_LOW | Low quality interpolation.|
| ARKUI_IMAGE_INTERPOLATION_MEDIUM | Medium quality interpolation.|
| ARKUI_IMAGE_INTERPOLATION_HIGH | High quality interpolation. This mode produces scaled images of the highest possible quality.|

### ArkUI_DynamicRangeMode

```
enum ArkUI_DynamicRangeMode
```

**Description**


Defines the dynamic range mode (SDR/HDR) of an image, which is used to control the display range of the image brightness and color.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_DYNAMIC_RANGE_MODE_HIGH = 0 | High dynamic range (HDR), which indicates the range of the minimum and maximum brightness values displayed in an image. The larger the range, the closer the image brightness is to the real environment. In a very bright environment, overexposure (all white) does not occur. In a very dark environment, the effect of overdarkness (all black) does not occur.|
| ARKUI_DYNAMIC_RANGE_MODE_CONSTRAINT | Limited high dynamic range, which contains richer brightness and color than SDR but is not complete HDR. It is generally used in scenarios where SDR compatibility is required.|
| ARKUI_DYNAMIC_RANGE_MODE_STANDARD | Standard dynamic range (SDR), which indicates a limited brightness range, usually 0–100 nits (brightness unit). The contrast between bright and dark parts is small. Dark parts tend to be blurred into black, and bright parts tend to be overexposed into white.|

### ArkUI_ImageRotateOrientation

```
enum ArkUI_ImageRotateOrientation
```

**Description**


Defines the image rotation direction.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_ORIENTATION_AUTO = 0 | Reads the EXIF metadata carried by an image as the display direction, and supports rotation and mirroring.|
| ARKUI_ORIENTATION_UP | By default, the image is displayed based on the pixel data without any processing.|
| ARKUI_ORIENTATION_RIGHT | Rotates the image clockwise by 90 degrees and then displays it.|
| ARKUI_ORIENTATION_DOWN  | Rotates the image clockwise by 180 degrees and then displays it.|
| ARKUI_ORIENTATION_LEFT | Rotates the current image by 270 degrees clockwise and displays it.|
| ARKUI_ORIENTATION_UP_MIRRORED | Flips the current image horizontally and displays it.|
| ARKUI_ORIENTATION_RIGHT_MIRRORED  | Flips the current image horizontally and rotates it by 90 degrees clockwise and displays it.|
| ARKUI_ORIENTATION_DOWN_MIRRORED | Flips the current image vertically and displays it.|
| ARKUI_ORIENTATION_LEFT_MIRRORED | Flips the current image horizontally and rotates it by 270 degrees clockwise and displays it.|

### ArkUI_BlendMode

```
enum ArkUI_BlendMode
```

**Description**


Enumerates the blend modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BLEND_MODE_NONE = 0 | The top image is superimposed on the bottom image without any blending.|
| ARKUI_BLEND_MODE_CLEAR | The target pixels covered by the source pixels are erased by being turned to completely transparent.|
| ARKUI_BLEND_MODE_SRC | r = s: Only the source pixels are displayed.|
| ARKUI_BLEND_MODE_DST | r = d: Only the target pixels are displayed.|
| ARKUI_BLEND_MODE_SRC_OVER | r = s + (1 - sa) * d: The source pixels are blended based on opacity and cover the target pixels.|
| ARKUI_BLEND_MODE_DST_OVER | r = d + (1 - da) * s: The target pixels are blended based on opacity and cover on the source pixels.|
| ARKUI_BLEND_MODE_SRC_IN | r = s * da: Only the part of the source pixels that overlap with the target pixels is displayed.|
| ARKUI_BLEND_MODE_DST_IN | r = d * sa: Only the part of the target pixels that overlap with the source pixels is displayed.|
| ARKUI_BLEND_MODE_SRC_OUT | r = s * (1 - da): Only the part of the source pixels that do not overlap with the target pixels is displayed.|
| ARKUI_BLEND_MODE_DST_OUT | r = d * (1 - sa): Only the part of the target pixels that do not overlap with the source pixels is displayed.|
| ARKUI_BLEND_MODE_SRC_ATOP | r = s * da + d * (1 - sa): The part of the source pixels that overlap with the target pixels is displayed and the part of the target pixels that do not overlap with the source pixels are displayed.|
| ARKUI_BLEND_MODE_DST_ATOP | r = d * sa + s * (1 - da): The part of the target pixels that overlap with the source pixels and the part of the source pixels that do not overlap with the target pixels are displayed.|
| ARKUI_BLEND_MODE_XOR | r = s * (1 - da) + d * (1 - sa): Only the non-overlapping part between the source pixels and the target pixels is displayed.|
| ARKUI_BLEND_MODE_PLUS | r = min(s + d, 1): New pixels resulting from adding the source pixels to the target pixels are displayed.|
| ARKUI_BLEND_MODE_MODULATE | r = s * d: New pixels resulting from multiplying the source pixels with the target pixels are displayed.|
| ARKUI_BLEND_MODE_SCREEN | r = s + d - s * d: Pixels are blended by adding the source pixels to the target pixels and subtracting the product of their multiplication.|
| ARKUI_BLEND_MODE_OVERLAY | The MULTIPLY or SCREEN mode is used based on the target pixels.|
| ARKUI_BLEND_MODE_DARKEN | rc = s + d - max(s * da, d * sa), ra = kSrcOver: When two colors overlap, whichever is darker is used.|
| ARKUI_BLEND_MODE_LIGHTEN | rc = s + d - min(s * da, d * sa), ra = kSrcOver: Compares the pixels in the source image and destination image, and selects the brighter pixel as the final blending result.|
| ARKUI_BLEND_MODE_COLOR_DODGE | The colors of the target pixels are lightened to reflect the source pixels.|
| ARKUI_BLEND_MODE_COLOR_BURN | The colors of the target pixels are darkened to reflect the source pixels.|
| ARKUI_BLEND_MODE_HARD_LIGHT | The MULTIPLY or SCREEN mode is used, depending on the source pixels.|
| ARKUI_BLEND_MODE_SOFT_LIGHT | The LIGHTEN or DARKEN mode is used, depending on the source pixels.|
| ARKUI_BLEND_MODE_DIFFERENCE | rc = s + d - 2 * (min(s * da, d * sa)), ra = kSrcOver: The final pixel is the result of subtracting the darker of the two pixels (source and target) from the lighter one.|
| ARKUI_BLEND_MODE_EXCLUSION | rc = s + d - two(s * d), ra = kSrcOver: The final pixel is similar to <b>DIFFERENCE</b>, but with less contrast.|
| ARKUI_BLEND_MODE_MULTIPLY | r = s * (1 - da) + d * (1 - sa) + s * d: The final pixel is the result of multiplying the source pixel by the target pixel.|
| ARKUI_BLEND_MODE_HUE | The resultant image is created with the luminance and saturation of the source image and the hue of the target image.|
| ARKUI_BLEND_MODE_SATURATION | The resultant image is created with the luminance and hue of the target image and the saturation of the source image.|
| ARKUI_BLEND_MODE_COLOR | The resultant image is created with the saturation and hue of the source image and the luminance of the target image.|
| ARKUI_BLEND_MODE_LUMINOSITY | The resultant image is created with the saturation and hue of the target image and the luminance of the source image.|

### ArkUI_Direction

```
enum ArkUI_Direction
```

**Description**


Enumerates the modes in which components are laid out along the main axis of the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DIRECTION_LTR = 0 | Components are arranged from left to right.|
| ARKUI_DIRECTION_RTL | Components are arranged from right to left.|
| ARKUI_DIRECTION_AUTO = 3 | The default layout direction is used.|

### ArkUI_ItemAlignment

```
enum ArkUI_ItemAlignment
```

**Description**


Enumerates the modes in which components are laid out along the cross axis of the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ITEM_ALIGNMENT_AUTO = 0 | The default configuration of the flex container is used.|
| ARKUI_ITEM_ALIGNMENT_START | The items in the flex container are aligned with the cross-start edge.|
| ARKUI_ITEM_ALIGNMENT_CENTER | The items in the flex container are centered along the cross axis.|
| ARKUI_ITEM_ALIGNMENT_END | The items in the flex container are aligned with the cross-end edge.|
| ARKUI_ITEM_ALIGNMENT_STRETCH | The items in the flex container are stretched and padded along the cross axis.|
| ARKUI_ITEM_ALIGNMENT_BASELINE | The items in the flex container are aligned in such a manner that their text baselines are aligned along the cross axis.|

### ArkUI_ColorStrategy

```
enum ArkUI_ColorStrategy
```

**Description**


Enumerates the foreground colors.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_COLOR_STRATEGY_INVERT = 0 | The foreground colors are the inverse of the component background colors.|
| ARKUI_COLOR_STRATEGY_AVERAGE | The shadow colors of the component are the average color obtained from the component background shadow area.|
| ARKUI_COLOR_STRATEGY_PRIMARY | The shadow colors of the component are the primary color obtained from the component background shadow area.|

### ArkUI_FlexAlignment

```
enum ArkUI_FlexAlignment
```

**Description**


Enumerates the vertical alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_ALIGNMENT_START = 1 | The child components are aligned with the start edge of the main axis.|
| ARKUI_FLEX_ALIGNMENT_CENTER = 2 | The child components are aligned in the center of the main axis.|
| ARKUI_FLEX_ALIGNMENT_END = 3 | The child components are aligned with the end edge of the main axis.|
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6 | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The first component is aligned with the main-start, and the last component is aligned with the main-end.|
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7 | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The space between the first component and main-start, and that between the last component and cross-main are both half the size of the space between two adjacent components.|
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8 | The child components are evenly distributed along the main axis. The space between the first component and main-start, the space between the last component and main-end, and the space between any two adjacent components are the same.|

### ArkUI_FlexDirection

```
enum ArkUI_FlexDirection
```

**Description**


Enumerates the directions of the main axis in the flex container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_DIRECTION_ROW = 0 | The child components are arranged in the same direction as the main axis runs along the rows.|
| ARKUI_FLEX_DIRECTION_COLUMN | The child components are arranged in the same direction as the main axis runs down the columns.|
| ARKUI_FLEX_DIRECTION_ROW_REVERSE | The child components are arranged opposite to the **ROW** direction.|
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE | The child components are arranged opposite to the **COLUMN** direction.|

### ArkUI_FlexWrap

```
enum ArkUI_FlexWrap
```

**Description**


Defines whether the flex container has a single line or multiple lines.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_WRAP_NO_WRAP = 0 | The child components in the flex container are arranged in a single line, and they cannot overflow.|
| ARKUI_FLEX_WRAP_WRAP | The child components in the flex container are arranged in multiple lines, and they may overflow.|
| ARKUI_FLEX_WRAP_WRAP_REVERSE | The child components in the flex container are reversely arranged in multiple lines, and they may overflow.|

### ArkUI_Visibility

```
enum ArkUI_Visibility
```

**Description**


Enumerates the visibility values.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_VISIBILITY_VISIBLE = 0 | The component is visible.|
| ARKUI_VISIBILITY_HIDDEN | The component is hidden, and a placeholder is used for it in the layout.|
| ARKUI_VISIBILITY_NONE | The component is hidden. It is not involved in the layout, and no placeholder is used for it.|

### ArkUI_CalendarAlignment

```
enum ArkUI_CalendarAlignment
```

**Description**


Enumerates the alignment modes between the calendar picker and the entry component.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_CALENDAR_ALIGNMENT_START = 0 | Left aligned.|
| ARKUI_CALENDAR_ALIGNMENT_CENTER | Center aligned.|
| ARKUI_CALENDAR_ALIGNMENT_END | Right aligned.|

### ArkUI_MaskType

```
enum ArkUI_MaskType
```

**Description**


Enumerates the mask types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_MASK_TYPE_RECTANGLE = 0 | Rectangle.|
| ARKUI_MASK_TYPE_CIRCLE | Circle.|
| ARKUI_MASK_TYPE_ELLIPSE | Ellipse.|
| ARKUI_MASK_TYPE_PATH | Path.|
| ARKUI_MASK_TYPE_PROGRESS | Progress indicator.|

### ArkUI_ClipType

```
enum ArkUI_ClipType
```

**Description**


Enumerates the clipping region types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_CLIP_TYPE_RECTANGLE = 0 | Rectangle.|
| ARKUI_CLIP_TYPE_CIRCLE | Circle.|
| ARKUI_CLIP_TYPE_ELLIPSE | Ellipse.|
| ARKUI_CLIP_TYPE_PATH | Path.|

### ArkUI_ShapeType

```
enum ArkUI_ShapeType
```

**Description**


Enumerates custom shape types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SHAPE_TYPE_RECTANGLE = 0 | Rectangle.|
| ARKUI_SHAPE_TYPE_CIRCLE | Circle.|
| ARKUI_SHAPE_TYPE_ELLIPSE | Ellipse.|
| ARKUI_SHAPE_TYPE_PATH | Path.|

### ArkUI_LinearGradientDirection

```
enum ArkUI_LinearGradientDirection
```

**Description**


Enumerates the gradient directions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT = 0 | From right to left.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_TOP | From bottom to top.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT | From left to right.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_BOTTOM | From top to bottom.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_TOP | From lower right to upper left.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_LEFT_BOTTOM | From upper right to lower left.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_TOP | From lower left to upper right.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_RIGHT_BOTTOM | From upper left to lower right.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_NONE | No gradient.|
| ARKUI_LINEAR_GRADIENT_DIRECTION_CUSTOM | Custom direction.|

### ArkUI_WordBreak

```
enum ArkUI_WordBreak
```

**Description**


Enumerates the word break rules.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_WORD_BREAK_NORMAL = 0 | Word breaks can occur between any two characters for Chinese, Japanese, and Korean (CJK) text, but can occur only at a space character for non-CJK text (such as English).|
| ARKUI_WORD_BREAK_BREAK_ALL | Word breaks can occur between any two characters for non-CJK text. CJK text behavior is the same as for **NORMAL**.|
| ARKUI_WORD_BREAK_BREAK_WORD | This option has the same effect as **BREAK_ALL** for non-CJK text, except that if it preferentially wraps lines at appropriate characters (for example, spaces) whenever possible. CJK text behavior is the same as for **NORMAL**.|
| ARKUI_WORD_BREAK_HYPHENATION | Line breaks can occur between any two syllabic units for non-CJK text. CJK text behavior is the same as for **NORMAL**.<br>**Since**: 18|

### ArkUI_EllipsisMode

```
enum ArkUI_EllipsisMode
```

**Description**


Enumerates the ellipsis positions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ELLIPSIS_MODE_START = 0 | An ellipsis is used at the start of the line of text.|
| ARKUI_ELLIPSIS_MODE_CENTER | An ellipsis is used at the center of the line of text.|
| ARKUI_ELLIPSIS_MODE_END | An ellipsis is used at the end of the line of text.|

### ArkUI_ImageRenderMode

```
enum ArkUI_ImageRenderMode
```

**Description**


Enumerates the image rendering modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_IMAGE_RENDER_MODE_ORIGINAL = 0 | Render image pixels as they are in the original source image.|
| ARKUI_IMAGE_RENDER_MODE_TEMPLATE | Render image pixels to create a monochrome template image.|

### ArkUI_TransitionEdge

```
enum ArkUI_TransitionEdge
```

**Description**


Enumerates the slide-in and slide-out positions of the component from the screen edge during transition.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TRANSITION_EDGE_TOP = 0 | Top edge of the window.|
| ARKUI_TRANSITION_EDGE_BOTTOM | Bottom edge of the window.|
| ARKUI_TRANSITION_EDGE_START | Left edge of the window.|
| ARKUI_TRANSITION_EDGE_END | Right edge of the window.|

### ArkUI_FinishCallbackType

```
enum ArkUI_FinishCallbackType
```

**Description**


Enumerates the animation **onFinish** callback types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FINISH_CALLBACK_REMOVED = 0 | The callback is invoked when the entire animation is removed once it has finished.|
| ARKUI_FINISH_CALLBACK_LOGICALLY | The callback is invoked when the animation logically enters the falling state, though it may still be in its long tail state.|

### ArkUI_ListItemAlignment

```
enum ArkUI_ListItemAlignment
```

**Description**


Enumerates the alignment modes of items along the cross axis.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_ALIGNMENT_START = 0 | The list items are packed toward the start edge of the **List** component along the cross axis.|
| ARKUI_LIST_ITEM_ALIGNMENT_CENTER | The list items are centered in the **List** component along the cross axis.|
| ARKUI_LIST_ITEM_ALIGNMENT_END | The list items are packed toward the end edge of the **List** component along the cross axis.|

### ArkUI_BlendApplyType

```
enum ArkUI_BlendApplyType
```

**Description**


Defines how the specified blend mode is applied.

**Since**: 12

| Value| Description|
| -- | -- |
| BLEND_APPLY_TYPE_FAST = 0 | The content of the view is blended in sequence on the target image.|
| BLEND_APPLY_TYPE_OFFSCREEN | The content of the component and its child components are drawn on the offscreen canvas, and then blended with the existing content on the canvas. |

### ArkUI_LengthMetricUnit

```
enum ArkUI_LengthMetricUnit
```

**Description**


Enumerates the component units.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1 | Default, which is fp for fonts and vp for non-fonts.|
| ARKUI_LENGTH_METRIC_UNIT_PX = 0 | px.|
| ARKUI_LENGTH_METRIC_UNIT_VP | vp.|
| ARKUI_LENGTH_METRIC_UNIT_FP | fp.|

### ArkUI_TextInputContentType

```
enum ArkUI_TextInputContentType
```

**Description**


Enumerates the autofill types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXTINPUT_CONTENT_TYPE_USER_NAME = 0 | Username. Password Vault, when enabled, can automatically save and fill in usernames.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSWORD | Password. Password Vault, when enabled, can automatically save and fill in passwords.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_NEW_PASSWORD | New password. Password Vault, when enabled, can automatically generate a new password.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_STREET_ADDRESS | Full street address. The scenario-based autofill feature, when enabled, can automatically save and fill in full street addresses.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_HOUSE_NUMBER | House number. The scenario-based autofill feature, when enabled, can automatically save and fill in house numbers.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_DISTRICT_ADDRESS | District and county. The scenario-based autofill feature, when enabled, can automatically save and fill in districts and counties.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_CITY_ADDRESS | City. The scenario-based autofill feature, when enabled, can automatically save and fill in cities.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PROVINCE_ADDRESS | Province. The scenario-based autofill feature, when enabled, can automatically save and fill in provinces.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_COUNTRY_ADDRESS | Country. The scenario-based autofill feature, when enabled, can automatically save and fill in countries.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FULL_NAME | Full name. The scenario-based autofill feature, when enabled, can automatically save and fill in full names.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_LAST_NAME | Last name. The scenario-based autofill feature, when enabled, can automatically save and fill in last names.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PERSON_FIRST_NAME | First name. The scenario-based autofill feature, when enabled, can automatically save and fill in first names.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_NUMBER | Phone number. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PHONE_COUNTRY_CODE | Country code. The scenario-based autofill feature, when enabled, can automatically save and fill in country codes.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_FULL_PHONE_NUMBER | Phone number with country code. The scenario-based autofill feature, when enabled, can automatically save and fill in phone numbers with country codes.|
| ARKUI_TEXTINPUT_CONTENT_EMAIL_ADDRESS | Email address. The scenario-based autofill feature, when enabled, can automatically save and fill in email addresses.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_BANK_CARD_NUMBER | Bank card number. The scenario-based autofill feature, when enabled, can automatically save and fill in bank card numbers.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_ID_CARD_NUMBER | ID card number. The scenario-based autofill feature, when enabled, can automatically save and fill in ID card numbers.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_NICKNAME | Nickname. The scenario-based autofill feature, when enabled, can automatically save and fill in nicknames.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_DETAIL_INFO_WITHOUT_STREET | Address information without street address. The scenario-based autofill feature, when enabled, can automatically save and fill in address information without street addresses.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_FORMAT_ADDRESS | Standard address. The scenario-based autofill feature, when enabled, can automatically save and fill in standard addresses.|
| ARKUI_TEXTINPUT_CONTENT_TYPE_PASSPORT_NUMBER | Passport number. The scenario-based autofill feature, when enabled, can automatically save and fill in passport numbers.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_VALIDITY | Passport validity period. The scenario-based autofill feature, when enabled, can automatically save and fill in passport validity periods.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_ISSUE_AT | Passport place of issue. The scenario-based autofill feature, when enabled, can automatically save and fill in the place of issue for passports.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_ORGANIZATION | Invoice title. The scenario-based autofill feature, when enabled, can automatically save and fill in invoice titles.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_TAX_ID | Tax ID. The scenario-based autofill feature, when enabled, can automatically save and fill in tax IDs.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_ADDRESS_CITY_AND_STATE | Location. The scenario-based autofill feature, when enabled, can automatically save and fill in locations.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_FLIGHT_NUMBER | Flight number. Currently not supported for automatic saving and auto-filling.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_NUMBER | Driver's license number. Currently not supported for automatic saving and auto-filling.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_FILE_NUMBER | Driver's license file number. Currently not supported for automatic saving and auto-filling.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_PLATE | License plate number. The scenario-based autofill feature, when enabled, can automatically save and fill in license plate numbers.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_ENGINE_NUMBER | Vehicle registration engine number. Currently not supported for automatic saving and auto-filling.<br>**Since**: 18|
| ARKUI_TEXTINPUT_CONTENT_TYPE_LICENSE_CHASSIS_NUMBER | Chassis number. Currently not supported for automatic saving and auto-filling.<br>**Since**: 18|

### ArkUI_BarrierDirection

```
enum ArkUI_BarrierDirection
```

**Description**


Enumerates the barrier directions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BARRIER_DIRECTION_START = 0 | The barrier is on the left side of all the referenced components specified by referencedId.|
| ARKUI_BARRIER_DIRECTION_END | The barrier is on the right side of all the referenced components specified by referencedId.|
| ARKUI_BARRIER_DIRECTION_TOP | The barrier is at the top of all the referenced components specified by referencedId.|
| ARKUI_BARRIER_DIRECTION_BOTTOM | The barrier is at the bottom of all the referenced components specified by referencedId.|

### ArkUI_RelativeLayoutChainStyle

```
enum ArkUI_RelativeLayoutChainStyle
```

**Description**


Enumerates the chain styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0 | Child components are evenly distributed among constraint anchors.|
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE | All child components except the first and last ones are evenly distributed among constraint anchors.|
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED | There is no gap between child components in the chain.|

### ArkUI_TextInputStyle

```
enum ArkUI_TextInputStyle
```

**Description**


Enumerates the text input styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXTINPUT_STYLE_DEFAULT = 0 | Default style. The caret width is fixed at 1.5 vp, and the caret height is subject to the background height and font size of the selected text.|
| ARKUI_TEXTINPUT_STYLE_INLINE | Inline input style. The background height of the selected text is the same as the height of the text box.|

### ArkUI_KeyboardAppearance

```
enum ArkUI_KeyboardAppearance
```

**Description**


Enumerates the appearance modes of the keyboard when the text box is focused.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_KEYBOARD_APPEARANCE_NONE_IMMERSIVE = 0 | Default appearance mode, not using the immersive style.|
| ARKUI_KEYBOARD_APPEARANCE_IMMERSIVE = 1 | Immersive style, following the system color mode.|
| ARKUI_KEYBOARD_APPEARANCE_LIGHT_IMMERSIVE = 2 | Immersive style in light mode.|
| ARKUI_KEYBOARD_APPEARANCE_DARK_IMMERSIVE = 3 | Immersive style in dark mode.|

### ArkUI_TextDataDetectorType

```
enum ArkUI_TextDataDetectorType
```

**Description**


Enumerates the entity types of text recognition.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DATA_DETECTOR_TYPE_PHONE_NUMBER = 0 | Phone number.|
| ARKUI_TEXT_DATA_DETECTOR_TYPE_URL | URL.|
| ARKUI_TEXT_DATA_DETECTOR_TYPE_EMAIL | Email address.|
| ARKUI_TEXT_DATA_DETECTOR_TYPE_ADDRESS | Address.|

### ArkUI_ButtonType

```
enum ArkUI_ButtonType
```

**Description**


Enumerates the button types.

**Since**: 12

| Value| Description                     |
| -- |-------------------------|
| ARKUI_BUTTON_TYPE_NORMAL = 0 | Normal button (without rounded corners by default).           |
| ARKUI_BUTTON_TYPE_CAPSULE | Capsule-type button (the round corner is half of the height by default).      |
| ARKUI_BUTTON_TYPE_CIRCLE | Circle button.                  |
| ARKUI_BUTTON_ROUNDED_RECTANGLE = 8 | Rounded rectangle button<br>**Since**: 19|

### ArkUI_RenderFit

```
enum ArkUI_RenderFit
```

**Description**


Enumerates the sizing and positioning behaviors of animated content in its final state.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_RENDER_FIT_CENTER = 0 | The component's content stays at the final size and always aligned with the center of the component.|
| ARKUI_RENDER_FIT_TOP | The component's content stays at the final size and always aligned with the top center of the component.|
| ARKUI_RENDER_FIT_BOTTOM | The component's content stays at the final size and always aligned with the bottom center of the component.|
| ARKUI_RENDER_FIT_LEFT | The component's content stays at the final size and always aligned with the left of the component.|
| ARKUI_RENDER_FIT_RIGHT | The component's content stays at the final size and always aligned with the right of the component.|
| ARKUI_RENDER_FIT_TOP_LEFT | The component's content stays at the final size and always aligned with the upper left corner of the component.|
| ARKUI_RENDER_FIT_TOP_RIGHT | The component's content stays at the final size and always aligned with the upper right corner of the component.|
| ARKUI_RENDER_FIT_BOTTOM_LEFT | The component's content stays at the final size and always aligned with the lower left corner of the component.|
| ARKUI_RENDER_FIT_BOTTOM_RIGHT | The component's content stays at the final size and always aligned with the lower right corner of the component.|
| ARKUI_RENDER_FIT_RESIZE_FILL | The component's content is always resized to fill the component's content box, without considering its aspect ratio in the final state.|
| ARKUI_RENDER_FIT_RESIZE_CONTAIN | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. It is always aligned with the center of the component.|
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_TOP_LEFT | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is left-aligned with the component. When there is remaining space in the height direction of the component, the content is top-aligned with the component.|
| ARKUI_RENDER_FIT_RESIZE_CONTAIN_BOTTOM_RIGHT | While maintaining its aspect ratio in the final state, the component's content is scaled to fit within the component's content box. When there is remaining space in the width direction of the component, the content is right-aligned with the component. When there is remaining space in the height direction of the component, the content is bottom-aligned with the component.|
| ARKUI_RENDER_FIT_RESIZE_COVER | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. It is always aligned with the center of the component, so that its middle part is displayed.|
| ARKUI_RENDER_FIT_RESIZE_COVER_TOP_LEFT | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is left-aligned with the component, so that its left part is displayed. When there is remaining space in the height direction, the content is top-aligned with the component, so that its top part is displayed.|
| ARKUI_RENDER_FIT_RESIZE_COVER_BOTTOM_RIGHT | While maintaining its aspect ratio in the final state, the component's content is scaled to cover the component's entire content box. When there is remaining space in the width direction, the content is right-aligned with the component, so that its right part is displayed. When there is remaining space in the height direction, the content is bottom-aligned with the component, so that its bottom part is displayed.|

### ArkUI_SwiperIndicatorType

```
enum ArkUI_SwiperIndicatorType
```

**Description**


Enumerates the navigation indicator types of the **Swiper** component.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SWIPER_INDICATOR_TYPE_DOT | Dot type.|
| ARKUI_SWIPER_INDICATOR_TYPE_DIGIT | Digit type.|

### ArkUI_AnimationDirection

```
enum ArkUI_AnimationDirection
```

**Description**


Enumerates the animation playback modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ANIMATION_DIRECTION_NORMAL = 0 | The animation plays in forward loop mode.|
| ARKUI_ANIMATION_DIRECTION_REVERSE | The animation plays in reverse loop mode.|
| ARKUI_ANIMATION_DIRECTION_ALTERNATE | The animation plays in alternating loop mode. When the animation is played for an odd number of times, the playback is in forward direction. When the animation is played for an even number of times, the playback is in reverse direction.|
| ARKUI_ANIMATION_DIRECTION_ALTERNATE_REVERSE | The animation plays in reverse alternating loop mode. When the animation is played for an odd number of times, the playback is in reverse direction. When the animation is played for an even number of times, the playback is in forward direction.|

### ArkUI_ListItemSwipeActionState

```
enum ArkUI_ListItemSwipeActionState
```

**Description**


Enumerates the swipe action item states of list items.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0 | Collapsed state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is hidden.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED | Expanded state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is shown.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING | In-action state. The list item is in this state when it enters the delete area.|

### ArkUI_ListItemSwipeEdgeEffect

```
enum ArkUI_ListItemSwipeEdgeEffect
```

**Description**


Enumerates the swipe action item edge effects of list items.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0 | When the list item scrolls to the edge of the list, it can continue to scroll for a distance.|
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE | The list item cannot scroll beyond the edge of the list.|

### ArkUI_ListItemSwipeActionDirection

```
enum ArkUI_ListItemSwipeActionDirection
```

**Description**

Defines the direction in which the menu of ListItem is displayed.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_START = 0 | When the list is vertical, the value indicates the left side of ListItem in LTR mode and the right side of ListItem in RTL mode. When the list is horizontal, the value indicates the top side of ListItem.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_END = 1 | When the list is vertical, the value indicates the right side of ListItem in LTR mode and the left side of ListItem in RTL mode. When the list is horizontal, the value indicates the bottom side of ListItem.|

### ArkUI_AnimationStatus

```
enum ArkUI_AnimationStatus
```

**Description**


Enumerates the playback states of the frame-by-frame animation.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ANIMATION_STATUS_INITIAL | The animation is in the initial state.|
| ARKUI_ANIMATION_STATUS_RUNNING | The animation is being played.|
| ARKUI_ANIMATION_STATUS_PAUSED | The animation is paused.|
| ARKUI_ANIMATION_STATUS_STOPPED | The animation is stopped.|

### ArkUI_AnimationFillMode

```
enum ArkUI_AnimationFillMode
```

**Description**


Enumerates the states before and after execution of the frame-by-frame animation.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ANIMATION_FILL_MODE_NONE | Before execution, the animation does not apply any styles to the target component. After execution, the animation restores the target component to its default state.|
| ARKUI_ANIMATION_FILL_MODE_FORWARDS | The target component retains the state set by the last keyframe encountered during execution of the animation.|
| ARKUI_ANIMATION_FILL_MODE_BACKWARDS | The animation applies the values defined in the first relevant keyframe once it is applied to the target component, and retains the values during the period set by **delay**.|
| ARKUI_ANIMATION_FILL_MODE_BOTH | The animation follows the rules for both **Forwards** and **Backwards**, extending the animation attributes in both directions.|

### ArkUI_ErrorCode

```
enum ArkUI_ErrorCode
```

**Description**


Enumerates the error codes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ERROR_CODE_NO_ERROR = 0 | No error.|
| ARKUI_ERROR_CODE_PARAM_INVALID = 401 | Parameter error.|
| ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500 |  API initialization error.<br>**Since**: 18|
| ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001 |  Internal error, such as failure due to internal environment issues or operation failure caused by internal execution errors.<br>**Since**: 15|
| ARKUI_ERROR_CODE_PARAM_ERROR = 100023 |  Parameter error. For details about the error codes, see [Custom Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 21|
| ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501 |  The **XComponent** is in an invalid or unsupported state. For details about the error codes, see [XComponent Error Codes](../apis-arkui/errorcode-xcomponent.md).<br>**Since**: 19|
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102 | The component does not support specific attributes or events. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103 | The specific operation is not allowed on the node created by ArkTS. For details about the error codes, see [Custom Node Error Codes](../apis-arkui/errorcode-node.md).|
| ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104 | The adapter for lazy loading is not bound to the component.|
| ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105 | The adapter already exists.|
| ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106 | Failed to add the adapter because the corresponding node already has a subnode.|
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107 | The parameter length in the parameter event exceeds the limit. For details about the error code, see [106107 Index Out of Range](../apis-arkui/errorcode-nodeadapter.md#106107-index-out-of-range).|
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108 | The data does not exist in the component event. For details about the error code, see [106108 Data Not Found](../apis-arkui/errorcode-nodeadapter.md#106108-data-not-found).|
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109 | The component event does not support return values. For details about the error code, see [106109 Return Value Not Supported](../apis-arkui/errorcode-nodeadapter.md#106109-return-value-not-supported).|
| ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110 | This event type is not supported. For details about the error code, see [106110-Event Type Not Supported](../apis-arkui/errorcode-nodeadapter.md#106110-event-type-not-supported).|
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200 | Invalid index.<br>For details about the error code, see [Router Error Codes](../apis-arkui/errorcode-router.md#106200-invalid-index-value).|
| ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201 | Failed to obtain the route navigation information.<br>For details about the error code, see [Router Error Codes](../apis-arkui/errorcode-router.md#106201-failed-to-obtain-route-navigation-information).|
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202 | Invalid buffer size.<br>For details about the error code, see [Router Error Codes](../apis-arkui/errorcode-router.md#106202-invalid-buffer-size).|
| ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203 |  The passed node is not mounted to the component tree. For details about the error codes, see [Custom Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 16|
| ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204 |  Operations on the provided node are not supported on non-UI threads. For details about the error code, see [Custom Node Error Codes](../apis-arkui/errorcode-node.md#106204-operations-on-the-provided-node-not-supported-on-non-ui-threads).<br>**Since**: 21|
| ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401 |  The current node is not a custom node. For details about the error codes, see [Render Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_CHILD_EXISTED = 106402 |  The current node already has child nodes. For details about the error codes, see [Render Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403 |  The current render node has a parent component. For details about the error codes, see [Render Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404 |  Corresponding render child node not found. For details about the error codes, see [Render Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405 |  The parameter value is out of range. For details about the error codes, see [Render Node Error Codes](../apis-arkui/errorcode-node.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001 |  The current node is not focusable. For details about the error code, see [Focus Error Codes](../apis-arkui/errorcode-focus.md#150001-component-not-focusable).<br>**Since**: 15|
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002 |  An ancestor of the current node is not focusable. For details about the error code, see [Focus Error Codes](../apis-arkui/errorcode-focus.md#150002-ancestor-component-not-focusable).<br>**Since**: 15|
| ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003 |  The current node does not exist. For details about the error code, see [Focus Error Codes](../apis-arkui/errorcode-focus.md#150003-component-does-not-exist).<br>**Since**: 15|
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002 |  Snapshot timed out. For details about the error codes, see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001 | The component is not a scrollable container. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002 | The buffer is not large enough. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003 |  The event is not a cloned event. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004 |  The component status is abnormal. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005 |  No component hit to respond to the event. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006 |  Input event type not supported.<br>**Since**: 20|
| ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101 |  Invalid styled string. For details about the error codes, see [Styled String Error Codes](../apis-arkui/errorcode-styled-string.md).<br>**Since**: 14|
| ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001 |  Invalid UIContext object. For details about the error codes, see [UI Context Error Codes](../apis-arkui/errorcode-uicontext.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002 |  Invalid callback function. For details about the error codes, see [UI Context Error Codes](../apis-arkui/errorcode-uicontext.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102 |  The gesture recognizer type is not supported. For details about the error codes, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004 |  The operation is not allowed in the current phase. For details about the error codes, see [Drag Event Error Codes](../apis-arkui/errorcode-drag-event.md).<br>**Since**: 19|

### ArkUI_ScrollSource

```
enum ArkUI_ScrollSource
```

**Description**


Enumerates scroll sources.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_SOURCE_DRAG = 0 | Finger dragging.|
| ARKUI_SCROLL_SOURCE_FLING | Inertia scrolling after finger dragging.|
| ARKUI_SCROLL_SOURCE_EDGE_EFFECT | Cross-boundary bouncing.|
| ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT | User input other than dragging, such as mouse wheel and keyboard events.|
| ARKUI_SCROLL_SOURCE_SCROLL_BAR | Scrollbar dragging.|
| ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING | Inertial scrolling after scrollbar dragging.|
| ARKUI_SCROLL_SOURCE_SCROLLER | Scrolling by the scroll controller (without animation).|
| ARKUI_SCROLL_SOURCE_ANIMATION | Scrolling by the scroll controller (with animation).|

### ArkUI_SafeAreaType

```
enum ArkUI_SafeAreaType
```

**Description**


Enumerates the types of expanded safe areas.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SAFE_AREA_TYPE_SYSTEM = 1 | Default non-safe area of the system, including the status bar and navigation bar.|
| ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 << 1 | Non-safe area of the device, for example, the notch area.|
| ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 << 2 | Soft keyboard area.|

### ArkUI_SafeAreaEdge

```
enum ArkUI_SafeAreaEdge
```

**Description**


Enumerates the edges for expanding the safe area.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SAFE_AREA_EDGE_TOP = 1 | Top edge.|
| ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | Bottom edge.|
| ARKUI_SAFE_AREA_EDGE_START = 1 << 2 | Start edge.|
| ARKUI_SAFE_AREA_EDGE_END = 1 << 3 | End edge.|

### ArkUI_FocusMove

```
enum ArkUI_FocusMove
```

**Description**


Enumerates the focus movement directions.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_FOCUS_MOVE_FORWARD = 0 | Move focus forward.|
| ARKUI_FOCUS_MOVE_BACKWARD | Move focus backward.|
| ARKUI_FOCUS_MOVE_UP | Move focus up.|
| ARKUI_FOCUS_MOVE_DOWN | Move focus down.|
| ARKUI_FOCUS_MOVE_LEFT | Move focus left.|
| ARKUI_FOCUS_MOVE_RIGHT | Move focus right.|

### ArkUI_ListItemGroupArea

```
enum ArkUI_ListItemGroupArea
```

**Description**


Enumerates areas of the **ListItemGroup** component.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE = 0 | Outside the area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_NONE | Area when the **ListItemGroup** component does not have the header, footer, or list item.|
| ARKUI_LIST_ITEM_SWIPE_AREA_ITEM | List item area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_HEADER | Header area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_FOOTER | Footer area of the **ListItemGroup** component.|

### ArkUI_KeyboardAvoidMode

```
enum ArkUI_KeyboardAvoidMode
```

**Description**


Enumerates the soft keyboard avoidance modes.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_KEYBOARD_AVOID_MODE_DEFAULT = 0 | Automatically avoids the soft keyboard and compresses the height when reaching the maximum limit.|
| ARKUI_KEYBOARD_AVOID_MODE_NONE | The layout is not adjusted to avoid the keyboard.|

### ArkUI_HoverModeAreaType

```
enum ArkUI_HoverModeAreaType
```

**Description**


Enumerates the types of display areas for the hover mode.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_HOVER_MODE_AREA_TYPE_TOP = 0 | Upper half screen.|
| ARKUI_HOVER_MODE_AREA_TYPE_BOTTOM | Lower half screen.|

### ArkUI_ExpandMode

```
enum ArkUI_ExpandMode
```

**Description**


Enumerates the expansion mode of child nodes.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_NOT_EXPAND = 0 | Child nodes are not expanded.|
| ARKUI_EXPAND = 1 | Child nodes are expanded immediately upon rendering.|
| ARKUI_LAZY_EXPAND = 2 | Child nodes are only expanded when needed or requested.|

### ArkUI_NavDestinationState

```
enum ArkUI_NavDestinationState
```

**Description**


Enumerates the **NavDestination** component states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_NAV_DESTINATION_STATE_ON_SHOW = 0 | The **NavDestination** component is displayed.|
| ARKUI_NAV_DESTINATION_STATE_ON_HIDE = 1 | The **NavDestination** component is hidden.|
| ARKUI_NAV_DESTINATION_STATE_ON_APPEAR = 2 | The **NavDestination** component is mounted to the component tree.|
| ARKUI_NAV_DESTINATION_STATE_ON_DISAPPEAR = 3 | The **NavDestination** component is unmounted from the component tree.|
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_SHOW = 4 | The **NavDestination** is about to be displayed.|
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_HIDE = 5 | The **NavDestination** is about to be hidden.|
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_APPEAR = 6 | The **NavDestination** is about to be mounted to the component tree.|
| ARKUI_NAV_DESTINATION_STATE_ON_WILL_DISAPPEAR = 7 | The **NavDestination** component is about to be unmounted from the component tree.|
| ARKUI_NAV_DESTINATION_STATE_ON_BACK_PRESS = 100 | The back button is pressed for the **NavDestination** component.|

### ArkUI_RouterPageState

```
enum ArkUI_RouterPageState
```

**Description**


Enumerates the states of a page during routing.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_APPEAR = 0 | The page is about to be displayed.|
| ARKUI_ROUTER_PAGE_STATE_ABOUT_TO_DISAPPEAR = 1 | The page is about to be destroyed.|
| ARKUI_ROUTER_PAGE_STATE_ON_SHOW = 2 | The page is displayed.|
| ARKUI_ROUTER_PAGE_STATE_ON_HIDE = 3 | The page is hidden.|
| ARKUI_ROUTER_PAGE_STATE_ON_BACK_PRESS = 4 | The back button is pressed for the page.|

### ArkUI_UIState

```
enum ArkUI_UIState
```

**Description**


Enumerates the UI states of a component, used for handling state-specific styles.

**Since**: 20

| Value| Description|
| -- | -- |
| UI_STATE_NORMAL = 0 | Normal state.|
| UI_STATE_PRESSED = 1 << 0 | Pressed state.|
| UI_STATE_FOCUSED = 1 << 1 | Focused state.|
| UI_STATE_DISABLED = 1 << 2 | Disabled state.|
| UI_STATE_SELECTED = 1 << 3 | Selected state. This state is supported only by specific component types: **Checkbox**, **Radio**, **Toggle**, **List**, **Grid**, and **MenuItem**.|

### ArkUI_FocusWrapMode

```
enum ArkUI_FocusWrapMode
```

**Description**


Enumerates the focus wrap mode of components.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_FOCUS_WRAP_MODE_DEFAULT = 0 | Default mode, where focus does not wrap when arrow keys are used.|
| ARKUI_FOCUS_WRAP_WITH_ARROW = 1 | Auto mode, where focus wraps automatically when arrow keys are used.|

### ArkUI_EdgeDirection

```
enum ArkUI_EdgeDirection
```

**Description**


Defines the direction of a rectangle.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_EDGE_DIRECTION_ALL = 0 | All four edges.|
| ARKUI_EDGE_DIRECTION_LEFT = 1 << 0 | Left edge.|
| ARKUI_EDGE_DIRECTION_RIGHT = 1 << 1 | Right edge.|
| ARKUI_EDGE_DIRECTION_TOP = 1 << 2 | Top edge.|
| ARKUI_EDGE_DIRECTION_BOTTOM = 1 << 3 | Bottom edge.|

### ArkUI_CornerDirection

```
enum ArkUI_CornerDirection
```

**Description**


Defines the angle direction.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_CORNER_DIRECTION_ALL = 0 | All four corners.|
| ARKUI_CORNER_DIRECTION_TOP_LEFT = 1 << 0 | Upper left corner.|
| ARKUI_CORNER_DIRECTION_TOP_RIGHT = 1 << 1 | Upper right corner.|
| ARKUI_CORNER_DIRECTION_BOTTOM_LEFT = 1 << 2 | Lower left corner.|
| ARKUI_CORNER_DIRECTION_BOTTOM_RIGHT = 1 << 3 | Lower right corner.|

## Function Description

### OH_ArkUI_LayoutConstraint_Create()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()
```

**Description**


Creates a size constraint.

**Since**: 12

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | Pointer to the object of the constraint size.|

### OH_ArkUI_LayoutConstraint_Copy()

```
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Performs a deep copy of a size constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | Pointer to the new size constraint.|

### OH_ArkUI_LayoutConstraint_Dispose()

```
void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)
```

**Description**


Disposes of the pointer to a size constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| void* | Null pointer.|

### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the maximum width for a size constraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum width.|

### OH_ArkUI_LayoutConstraint_GetMinWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the minimum width for a size contraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum Width|

### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the maximum height for a size constraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum height.|

### OH_ArkUI_LayoutConstraint_GetMinHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the minimum height for a size constraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum height.|

### OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the width percentage reference for a size constraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Width percentage reference.|

### OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight()

```
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the height percentage reference for a size constraint, in px.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Height percentage reference.|

### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```
void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the maximum width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Maximum width, in pixels.|

### OH_ArkUI_LayoutConstraint_SetMinWidth()

```
void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the minimum width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Minimum width, in px.|

### OH_ArkUI_LayoutConstraint_SetMaxHeight()

```
void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the maximum height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Maximum height, in px.|

### OH_ArkUI_LayoutConstraint_SetMinHeight()

```
void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the minimum height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Minimum height, in px.|

### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the width percentage reference.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Width percentage reference, in px.|

### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the height percentage reference.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Size constraint.|
| int32_t value | Height percentage reference, in px.|

### OH_ArkUI_DrawContext_GetCanvas()

```
void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)
```

**Description**


Obtains the pointer to a canvas for drawing, which can be converted into the **OH_Drawing_Canvas** in the **Drawing** module.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | Drawing context.|

**Returns**

| Type| Description|
| -- | -- |
| void* | Pointer to the canvas for drawing.|

### OH_ArkUI_DrawContext_GetSize()

```
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)
```

**Description**


Obtains the size of a drawing area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | Drawing context.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | Size of the drawing area.|

### OH_ArkUI_WaterFlowSectionOption_Create()

```
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
```

**Description**


Creates a water flow section configuration.

**Since**: 12

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* | Pointer to a water flow section configuration.|

### OH_ArkUI_WaterFlowSectionOption_Dispose()

```
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
```

**Description**


Disposes of the pointer to a water flow section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|

### OH_ArkUI_WaterFlowSectionOption_SetSize()

```
void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option,int32_t size)
```

**Description**


Sets the array length for a water flow section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t size | Size of the array.|

### OH_ArkUI_WaterFlowSectionOption_GetSize()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
```

**Description**


Obtains the array length for a water flow section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Size of the array. If **-1** is returned, an error code indicating failure is returned. The possible cause is that the **option** parameter is abnormal, for example, a null pointer.|

### OH_ArkUI_WaterFlowSectionOption_SetItemCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option,int32_t index, int32_t itemCount)
```

**Description**


Sets the number of items in a water flow section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
| int32_t itemCount | Number of items in the water flow section.|

### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the number of items in the water flow section that matches the specified index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of items in the water flow section.|

### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```
void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option,int32_t index, int32_t crossCount)
```

**Description**


Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
| int32_t crossCount | Number of columns or rows, depending on the layout direction.|

### OH_ArkUI_WaterFlowSectionOption_GetCrossCount()

```
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of columns or rows, depending on the layout direction.|

### OH_ArkUI_WaterFlowSectionOption_SetColumnGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option,int32_t index, float columnGap)
```

**Description**


Sets the gap between columns in the specified water flow section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
| float columnGap | Gap between columns.|

### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the gap between columns in the water flow section that matches the specified index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| float | Gap between columns.|

### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option,int32_t index, float rowGap)
```

**Description**


Sets the gap between rows in the specified water flow section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
| float rowGap | Gap between rows.|

### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the gap between rows in the water flow section that matches the specified index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| float | Gap between rows.|

### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)
```

**Description**


Sets the margins for the specified water flow section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
| float marginTop | Top margin of the water flow section.|
| float marginRight | Right margin of the water flow section.|
| float marginBottom | Bottom margin of the water flow section.|
| float marginLeft | Left margin of the water flow section.|

### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the margins of the water flow section that matches the specified index.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | Margins.|

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option,int32_t index, float(*callback)(int32_t itemIndex))
```

**Description**


Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.

**Since**: 12


**Parameters**

| Name                                           | Description|
|------------------------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index                                  | Index of the target water flow section.|
| callback                                       | Callback used to return the result. **itemIndex**: index of the target water flow section.|

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData,float (*callback)(int32_t itemIndex, void* userData))
```

**Description**


Obtains the main axis size of a specified item based on **flowItemIndex** through a water flow section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the target water flow section.|
|  void* userData | Custom data of the water flow item.|
| callback | Callback used to return the result. **itemIndex**: index of the target water flow section.|

### OH_ArkUI_GuidelineOption_Create()

```
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)
```

**Description**


Creates a guideline configuration for this **RelativeContainer** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Number of guidelines.|

**Returns**

| Type                        | Description|
|----------------------------| -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* | Pointer to a guideline configuration.|

### OH_ArkUI_GuidelineOption_Dispose()

```
void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)
```

**Description**


Disposes of a guideline configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|

### OH_ArkUI_GuidelineOption_SetId()

```
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)
```

**Description**


Sets the ID of a guideline.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| const char* value | ID, which must be unique and cannot be the same as the name of any component in the container.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_SetDirection()

```
void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)
```

**Description**


Sets the direction of a guideline.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| [ArkUI_Axis](capi-native-type-h.md#arkui_axis) value | Direction. |
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_SetPositionStart()

```
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**


Sets the distance between a guideline and the left or top of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| float value | Distance between the guideline and the left or top of the container.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_SetPositionEnd()

```
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**


Sets the distance between a guideline and the right or bottom of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| float value | Distance between the guideline and the right or bottom of the container.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_GetId()

```
const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the ID of a guideline.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | ID of the guideline.|

### OH_ArkUI_GuidelineOption_GetDirection()

```
ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the direction of a guideline.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_Axis](capi-native-type-h.md#arkui_axis) | Direction. |

### OH_ArkUI_GuidelineOption_GetPositionStart()

```
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the distance between a guide line and the left or top of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the guideline and the left or top of the container.|

### OH_ArkUI_GuidelineOption_GetPositionEnd()

```
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the distance between a guideline and the right or bottom of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the guideline and the right or bottom of the container.|

### OH_ArkUI_BarrierOption_Create()

```
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)
```

**Description**


Creates a barrier configuration for this **RelativeContainer** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Number of barriers.|

**Returns**

| Type                      | Description|
|--------------------------| -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* | Returns the barrier configuration.|

### OH_ArkUI_BarrierOption_Dispose()

```
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)
```

**Description**


Disposes of a barrier configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Returns the barrier configuration.|

### OH_ArkUI_BarrierOption_SetId()

```
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**


Sets the ID of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Returns the barrier configuration.|
| const char* value | ID, which must be unique and cannot be the same as the name of any component in the container.|
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_SetDirection()

```
void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)
```

**Description**


Sets the direction of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Returns the barrier configuration.|
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) value | Direction. |
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_SetReferencedId()

```
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**


Sets the referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Returns the barrier configuration.|
| const char* value | Referenced component IDs.|
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_GetId()

```
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the ID of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID of the barrier.|

### OH_ArkUI_BarrierOption_GetDirection()

```
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the direction of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) | Returns the direction of the barrier.|

### OH_ArkUI_BarrierOption_GetReferencedId()

```
const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)
```

**Description**


Obtains the referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|
| int32_t referencedIndex | Index of the referenced component ID.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Referenced components of the barrier.|

### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the number of referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of referenced components of the barrier.|

### OH_ArkUI_AlignmentRuleOption_Create()

```
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()
```

**Description**


Creates an alignment rule configuration for this **RelativeContainer** component.

**Since**: 12

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* | Alignment rule information.|

### OH_ArkUI_AlignmentRuleOption_Dispose()

```
void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)
```

**Description**


Disposes of an alignment rule configuration of this **RelativeContainer** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

### OH_ArkUI_AlignmentRuleOption_SetStart()

```
void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the left alignment parameters.

**Since**: 12


**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id                                                                            | ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment                         | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetEnd()

```
void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the right alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the horizontal center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetTop()

```
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the top alignment parameters.

**Since**: 12


**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id                                                                            | ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment                             | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetBottom()

```
void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the bottom alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the vertical center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)
```

**Description**


Sets the bias value of the component in the horizontal direction under the anchor constraints.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| float horizontal | Bias value in the horizontal direction.|

### OH_ArkUI_AlignmentRuleOption_SetBiasVertical()

```
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)
```

**Description**


Sets the bias value of the component in the vertical direction under the anchor constraints.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| float vertical | Returns the bias value in the vertical direction.|

### OH_ArkUI_AlignmentRuleOption_GetStartId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID in the left alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | ID of the component that functions as the anchor point.|

### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in left alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Returns the alignment mode in left alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetEndId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in the right alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID in the right alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in the right alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Returns the alignment mode in the right alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in horizontal center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID in horizontal center alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in horizontal center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Returns the alignment mode in horizontal center alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetTopId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in top alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID in top alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in top alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Returns the alignment mode in top alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in bottom alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID in bottom alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the alignment mode in bottom alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Returns the alignment mode in bottom alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID in vertical center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the ID in vertical center alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID in vertical center alignment parameters.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Returns the vertical center alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the bias value in the horizontal direction.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| float | Bias value in the horizontal direction.|

### OH_ArkUI_AlignmentRuleOption_GetBiasVertical()

```
float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the bias value in the vertical direction.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the bias value in the vertical direction.|

### OH_ArkUI_SwiperIndicator_Create()

```
ArkUI_SwiperIndicator* OH_ArkUI_SwiperIndicator_Create(ArkUI_SwiperIndicatorType type)
```

**Description**


Creates a navigation indicator for the Swiper component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicatorType](capi-native-type-h.md#arkui_swiperindicatortype) type | Type of the navigation indicator.|

**Returns**

| Type                        | Description|
|----------------------------| -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* | Pointer to the navigation indicator.|

### OH_ArkUI_SwiperIndicator_Dispose()

```
void OH_ArkUI_SwiperIndicator_Dispose(ArkUI_SwiperIndicator* indicator)
```

**Description**


Disposes of the navigation indicator of this **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

### OH_ArkUI_SwiperIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperIndicator_SetStartPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the distance between the navigation indicator and the left edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Returns the distance between the navigation indicator and the left edge of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperIndicator_GetStartPosition(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the distance between a navigation indicator and the left edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the navigation indicator and the left edge of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperIndicator_SetTopPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the distance between the navigation indicator and the top edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Distance between a navigation indicator and the top edge of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperIndicator_GetTopPosition(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the distance between the navigation indicator and the top edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between a navigation indicator and the top edge of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperIndicator_SetEndPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the distance between the navigation indicator and the right edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Distance between the navigation indicator and the right edge of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperIndicator_GetEndPosition(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the distance between a navigation indicator and the right edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the navigation indicator and the right edge of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperIndicator_SetBottomPosition(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the distance between the navigation indicator and the bottom edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Distance between a navigation indicator and the bottom edge of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperIndicator_GetBottomPosition(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the distance between the navigation indicator and the bottom edge of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between a navigation indicator and the bottom edge of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom()

```
void OH_ArkUI_SwiperIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator, int32_t ignoreSize)
```

**Description**


Sets whether the **OH_ArkUI_SwiperIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| int32_t ignoreSize | Whether to ignore the indicator size when positioning the indicator. The value **1** means to ignore the indicator size when positioning the indicator, and **0** means the opposite. Default value: **0**.|

### OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom()

```
int32_t OH_ArkUI_SwiperIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperIndicator* indicator)
```

**Description**


Checks whether the **OH_ArkUI_SwiperIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Whether to ignore the indicator size when positioning the indicator.|

### OH_ArkUI_SwiperIndicator_SetItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetItemWidth(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the width of a dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Width of the dot-style navigation indicator. Default value: **12**, in vp.|

### OH_ArkUI_SwiperIndicator_GetItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetItemWidth(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the width of a dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Width of the dot-style navigation indicator. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetItemHeight(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the height of a dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Height of the dot-style navigation indicator. Default value: **6**, in vp.|

### OH_ArkUI_SwiperIndicator_GetItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetItemHeight(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the height of a dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Height of the dot-style navigation indicator. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetSelectedItemWidth()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemWidth(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the width of the selected dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Width of the dot-style navigation indicator. Default value: **12**, in vp.|

### OH_ArkUI_SwiperIndicator_GetSelectedItemWidth()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemWidth(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the width of the selected dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Width of the dot-style navigation indicator. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetSelectedItemHeight()

```
void OH_ArkUI_SwiperIndicator_SetSelectedItemHeight(ArkUI_SwiperIndicator* indicator, float value)
```

**Description**


Sets the height of the selected dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float value | Height of the dot-style navigation indicator. Default value: **6**, in vp.|

### OH_ArkUI_SwiperIndicator_GetSelectedItemHeight()

```
float OH_ArkUI_SwiperIndicator_GetSelectedItemHeight(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the height of the selected dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Height of the dot-style navigation indicator. Unit: vp.|

### OH_ArkUI_SwiperIndicator_SetMask()

```
void OH_ArkUI_SwiperIndicator_SetMask(ArkUI_SwiperIndicator* indicator, int32_t mask)
```

**Description**


Sets whether to enable the mask for a dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| int32_t mask | Whether to enable the mask. The value **1** means to enable the mask, and **0** means the opposite.|

### OH_ArkUI_SwiperIndicator_GetMask()

```
int32_t OH_ArkUI_SwiperIndicator_GetMask(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains whether the mask is enabled for a dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **1** if the mask is enabled; returns **0** otherwise.|

### OH_ArkUI_SwiperIndicator_SetColor()

```
void OH_ArkUI_SwiperIndicator_SetColor(ArkUI_SwiperIndicator* indicator, uint32_t color)
```

**Description**


Sets the color of a dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| uint32_t color | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperIndicator_GetColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetColor(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the color of a dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperIndicator_SetSelectedColor()

```
void OH_ArkUI_SwiperIndicator_SetSelectedColor(ArkUI_SwiperIndicator* indicator, uint32_t selectedColor)
```

**Description**


Sets the color of the selected dot-style navigation indicator for the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| uint32_t selectedColor | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperIndicator_GetSelectedColor()

```
uint32_t OH_ArkUI_SwiperIndicator_GetSelectedColor(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the color of the selected dot-style navigation indicator of the **Swiper** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperIndicator_SetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_SetMaxDisplayCount(ArkUI_SwiperIndicator* indicator, int32_t maxDisplayCount)
```

**Description**


Sets the maximum number of dots for the dot-style navigation indicator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| int32_t maxDisplayCount | Maximum number of navigation dots that can be displayed. The value range is [6, 9].|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if **maxDisplayCount** is set to an invalid value.|

### OH_ArkUI_SwiperIndicator_GetMaxDisplayCount()

```
int32_t OH_ArkUI_SwiperIndicator_GetMaxDisplayCount(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the maximum number of dots for the dot-style navigation indicator.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum number of navigation dots that can be displayed. The value range is [6, 9].|

### OH_ArkUI_SwiperDigitIndicator_Create()

```
ArkUI_SwiperDigitIndicator *OH_ArkUI_SwiperDigitIndicator_Create()
```

**Description**


Creates a digit-style navigation indicator for this **Swiper** component.

**Since**: 19

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) * | Pointer to the digit-style navigation indicator.|

### OH_ArkUI_SwiperDigitIndicator_Destroy()

```
void OH_ArkUI_SwiperDigitIndicator_Destroy(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Disposes of the digit-style navigation indicator of this **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

### OH_ArkUI_SwiperDigitIndicator_SetStartPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetStartPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**Description**


Sets the start position of the digit-style navigation indicator for the **Swiper** component. This determines the distance from the left edge of the **Swiper** component. For right-to-left scripts, this determines the distance from the right edge.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float value | Distance from the left edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the right edge. Default value: **0**, in vp.|

### OH_ArkUI_SwiperDigitIndicator_GetStartPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetStartPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the start position of the digit-style navigation indicator for the **Swiper** component. This indicates the distance from the left edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the right edge.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance from the left edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the right edge. Unit: vp.|

### OH_ArkUI_SwiperDigitIndicator_SetTopPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetTopPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**Description**


Sets the distance from the digit-style navigation indicator to the top of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float value | Distance from the digit-style navigation indicator to the top of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperDigitIndicator_GetTopPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetTopPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the distance from the digit-style navigation indicator to the top of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance from the digit-style navigation indicator to the top of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperDigitIndicator_SetEndPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetEndPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**Description**


Sets the end position of the digit-style navigation indicator for the **Swiper** component. This determines the distance from the right edge of the **Swiper** component. For right-to-left scripts, this determines the distance from the left edge.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float value | Distance from the right edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the left edge. Default value: **0**, in vp.|

### OH_ArkUI_SwiperDigitIndicator_GetEndPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetEndPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the end position of the digit-style navigation indicator for the **Swiper** component. This indicates the distance from the right edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the left edge.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance from the right edge of the **Swiper** component. For right-to-left scripts, this indicates the distance from the left edge. Unit: vp.|

### OH_ArkUI_SwiperDigitIndicator_SetBottomPosition()

```
void OH_ArkUI_SwiperDigitIndicator_SetBottomPosition(ArkUI_SwiperDigitIndicator* indicator, float value)
```

**Description**


Sets the distance from the digit-style navigation indicator to the bottom of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float value | Distance from the digit-style navigation indicator to the bottom of the **Swiper** component. Default value: **0**, in vp.|

### OH_ArkUI_SwiperDigitIndicator_GetBottomPosition()

```
float OH_ArkUI_SwiperDigitIndicator_GetBottomPosition(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the distance from the digit-style navigation indicator to the bottom of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance from the digit-style navigation indicator to the bottom of the **Swiper** component. Unit: vp.|

### OH_ArkUI_SwiperDigitIndicator_SetFontColor()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t color)
```

**Description**


Sets the font color of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| uint32_t color | Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red. Default value: **0xFF182431**.|

### OH_ArkUI_SwiperDigitIndicator_GetFontColor()

```
uint32_t OH_ArkUI_SwiperDigitIndicator_GetFontColor(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font color of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator, uint32_t selectedColor)
```

**Description**


Sets the font color of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| uint32_t selectedColor | Returns the color, in 0xARGB format. For example, 0xFFFF0000 indicates red. Default value: **0xFF182431**.|

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor()

```
uint32_t OH_ArkUI_SwiperDigitIndicator_GetSelectedFontColor(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font color of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Color, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperDigitIndicator_SetFontSize()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
```

**Description**


Sets the font size of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float size | Font size, in fp.|

### OH_ArkUI_SwiperDigitIndicator_GetFontSize()

```
float OH_ArkUI_SwiperDigitIndicator_GetFontSize(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font size of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Font size, in fp.|

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator, float size)
```

**Description**


Sets the font size of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|
| float size | Font size, in fp.|

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize()

```
float OH_ArkUI_SwiperDigitIndicator_GetSelectedFontSize(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font size of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Font size, in fp.|

### OH_ArkUI_SwiperDigitIndicator_SetFontWeight()

```
void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)
```

**Description**


Sets the font weight of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) *indicator | Pointer to the digit-style navigation indicator.|
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) fontWeight | Font weight, specified using [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight).|

### OH_ArkUI_SwiperDigitIndicator_GetFontWeight()

```
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font weight of the digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) | Font weight, specified using [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight).|

### OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight()

```
void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)
```

**Description**


Sets the font weight of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md) *indicator | Pointer to the digit-style navigation indicator.|
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) selectedFontWeight | Font weight, specified using [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight).|

### OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight()

```
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font weight of the selected digit-style navigation indicator for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) | Font weight, specified using [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight).|

### OH_ArkUI_SwiperArrowStyle_Create()

```
ArkUI_SwiperArrowStyle *OH_ArkUI_SwiperArrowStyle_Create()
```

**Description**


Creates an arrow style for the **Swiper** component.

**Since**: 19

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md) * | Pointer to the arrow object.|

### OH_ArkUI_SwiperArrowStyle_Destroy()

```
void OH_ArkUI_SwiperArrowStyle_Destroy(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Disposes of the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

### OH_ArkUI_SwiperArrowStyle_SetShowBackground()

```
void OH_ArkUI_SwiperArrowStyle_SetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showBackground)
```

**Description**


Sets whether to display the background of the arrow for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| int32_t showBackground | Whether to show the arrow background. The value **1** means to show the background, and **0** means the opposite. The default value is **0**.|

### OH_ArkUI_SwiperArrowStyle_GetShowBackground()

```
int32_t OH_ArkUI_SwiperArrowStyle_GetShowBackground(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Checks whether the background of the arrow is displayed for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns whether the arrow background is displayed. The value **1** means that the background is displayed, and **0** means the opposite.|

### OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle()

```
void OH_ArkUI_SwiperArrowStyle_SetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle, int32_t showSidebarMiddle)
```

**Description**


Sets the position of the arrow for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| int32_t showSidebarMiddle | Position of the arrow. **0**: The arrow is displayed on both sides of the navigation indicator. **1**: The arrow is displayed on both sides of the **Swiper** component. The default value is **0**.|

### OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle()

```
int32_t OH_ArkUI_SwiperArrowStyle_GetShowSidebarMiddle(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Obtains the position of the arrow for the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the position of the arrow. **0**: The arrow is displayed on both sides of the navigation indicator. **1**: The arrow is displayed on both sides of the **Swiper** component.|

### OH_ArkUI_SwiperArrowStyle_SetBackgroundSize()

```
void OH_ArkUI_SwiperArrowStyle_SetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle, float backgroundSize)
```

**Description**


Sets the background size for the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| float backgroundSize | Background size of the arrow, in vp. Default value: 24 vp when displayed on both sides of the navigation indicator and 32 vp when displayed on both sides of the **Swiper** component.|

### OH_ArkUI_SwiperArrowStyle_GetBackgroundSize()

```
float OH_ArkUI_SwiperArrowStyle_GetBackgroundSize(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Obtains the background size of the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Background size of the arrow, in vp.|

### OH_ArkUI_SwiperArrowStyle_SetBackgroundColor()

```
void OH_ArkUI_SwiperArrowStyle_SetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t backgroundColor)
```

**Description**


Sets the background color for the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| uint32_t backgroundColor | Background color of the arrow, in 0xARGB format. For example, 0xFFFF0000 indicates red. Default value: **0x00000000** when displayed on both sides of the navigation indicator and **0x19182431** when displayed on both sides of the **Swiper** component.|

### OH_ArkUI_SwiperArrowStyle_GetBackgroundColor()

```
uint32_t OH_ArkUI_SwiperArrowStyle_GetBackgroundColor(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Obtains the background color for the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Background color of the arrow, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperArrowStyle_SetArrowSize()

```
void OH_ArkUI_SwiperArrowStyle_SetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle, float arrowSize)
```

**Description**


Sets the size for the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| float arrowSize | Size of the arrow, in vp. Default value: 18 vp when displayed on both sides of the navigation indicator and 24 vp when displayed on both sides of the **Swiper** component. When the arrow background is displayed, the value of **arrowSize** is fixed at 3/4 of the value of **backgroundSize**.|

### OH_ArkUI_SwiperArrowStyle_GetArrowSize()

```
float OH_ArkUI_SwiperArrowStyle_GetArrowSize(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Obtains the size of the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| float | Size of the arrow, in vp.|

### OH_ArkUI_SwiperArrowStyle_SetArrowColor()

```
void OH_ArkUI_SwiperArrowStyle_SetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle, uint32_t arrowColor)
```

**Description**


Sets the color for the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|
| uint32_t arrowColor | Color of the arrow, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperArrowStyle_GetArrowColor()

```
uint32_t OH_ArkUI_SwiperArrowStyle_GetArrowColor(ArkUI_SwiperArrowStyle* arrowStyle)
```

**Description**


Obtains the color of the arrow of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperArrowStyle](capi-arkui-nativemodule-arkui-swiperarrowstyle.md)* arrowStyle | Pointer to the arrow object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Color of the arrow, in 0xARGB format. For example, 0xFFFF0000 indicates red.|

### OH_ArkUI_SwiperIndicator_SetSpace()

```
void OH_ArkUI_SwiperIndicator_SetSpace(ArkUI_SwiperIndicator* indicator, float space)
```

**Description**


Sets the spacing between navigation points.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|
| float space | Spacing between navigation points. Default value: **8**, in vp.|

### OH_ArkUI_SwiperIndicator_GetSpace()

```
float OH_ArkUI_SwiperIndicator_GetSpace(ArkUI_SwiperIndicator* indicator)
```

**Description**


Obtains the spacing between navigation points.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperIndicator](capi-arkui-nativemodule-arkui-swiperindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| float | Spacing between navigation points. Unit: vp.|

### OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom()

```
void OH_ArkUI_SwiperDigitIndicator_SetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator, int32_t ignoreSize)
```

**Description**


Sets whether the **OH_ArkUI_SwiperDigitIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the navigation indicator.|
| int32_t ignoreSize | Whether to ignore the indicator size when positioning the indicator. The value **1** means to ignore the indicator size when positioning the indicator, and **0** means the opposite. Default value: **0**.|

### OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom()

```
int32_t OH_ArkUI_SwiperDigitIndicator_GetIgnoreSizeOfBottom(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Checks whether the **OH_ArkUI_SwiperDigitIndicator_SetBottomPosition** API ignores the indicator size when positioning the indicator.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Whether to ignore the indicator size when positioning the indicator.|

### OH_ArkUI_ListItemSwipeActionItem_Create()

```
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()
```

**Description**


Creates a **ListItemSwipeActionItem** instance.

**Since**: 12

**Returns**

| Type                                | Description|
|------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* | Returns the created **ListItemSwipeActionItem** instance.|

### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```
void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Disposes of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | **ListItemSwipeActionItem** instance to dispose of.|

### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```
void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)
```

**Description**


Sets the layout content for a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Layout information.|

### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)
```

**Description**


Swipe distance threshold for deleting the list item.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| float distance | Returns the swipe distance threshold for deleting the list item.|

### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Obtains the swipe distance threshold for deleting the list item.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the swipe distance threshold for deleting the list item. Return **0** if an error occurs.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked each time the list item enters the delete area.

**Since**: 12


**Parameters**

| Name                                    | Description|
|-----------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| callback                                | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked each time the list item enters the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| void* userData | Custom data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked when the list item is deleted while in the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked when the list item is deleted while in the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| void* userData | Custom data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked each time the list item exits the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked each time the list item exits the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| void* userData | Custom data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange(ArkUI_ListItemSwipeActionItem* item,void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState))
```

**Description**


Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
| callback | Callback event. **swipeActionState**: new state after the state change.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))
```

**Description**


Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Target **ListItemSwipeActionItem** instance.|
|  void* userData | Custom data.|
| callback | Callback event. **swipeActionState**: new state after the state change.|

### OH_ArkUI_ListItemSwipeActionOption_Create()

```
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()
```

**Description**


Creates a **ListItemSwipeActionOption** instance.

**Since**: 12

**Returns**

| Type                                  | Description|
|--------------------------------------| -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* | Created **ListItemSwipeActionOption** instance.|

### OH_ArkUI_ListItemSwipeActionOption_Dispose()

```
void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)
```

**Description**


Disposes of a **ListItemSwipeActionOption** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | **ListItemSwipeActionOption** instance to dispose of.|

### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```
void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Layout information.|

### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Layout information.|

### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeEdgeEffect edgeEffect)
```

**Description**


Sets the edge effect used when the boundary of the scrolling area is reached.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeEdgeEffect](capi-native-type-h.md#arkui_listitemswipeedgeeffect) edgeEffect | Edge effect.|

### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)
```

**Description**


Obtains the edge effect used when the boundary of the scrolling area is reached.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Edge effect. The default return value is **ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING**.|

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option,void (*callback)(float offset))
```

**Description**


Sets the callback invoked when the scroll offset changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|
| callback | Callback event. **offset**: scroll offset.|

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData()

```
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData(ArkUI_ListItemSwipeActionOption* option,void* userData, void (*callback)(float offset, void* userData))
```

**Description**


Sets the callback invoked when the scroll offset changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Target **ListItemSwipeActionItem** instance.|
|  void* userData | Custom data.|
| callback | Callback event. **offset**: scroll offset.|

### OH_ArkUI_ListItemSwipeAction_Expand()

```
int32_t OH_ArkUI_ListItemSwipeAction_Expand(ArkUI_NodeHandle node, ArkUI_ListItemSwipeActionDirection direction)
```

**Description**

Expands the menu of a specified ListItem.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| node | ListItem node object.|
| [ArkUI_ListItemSwipeActionDirection](#arkui_listitemswipeactiondirection) direction | Expansion direction of the menu of a specified ListItem.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         [ARKUI_ERROR_CODE_PARAM_ERROR](capi-native-type-h.md#arkui_errorcode) The node object type is incorrect.<br>         [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-native-type-h.md#arkui_errorcode) The node passed is not mounted to the component tree.|

> **NOTE**
>
> - If the NODE_LIST_CACHED_COUNT attribute of the List component is set to display preloaded ListItem, the ListItem that has been preloaded outside the List display area can be expanded. Otherwise, the node outside the List display area cannot be expanded.

### OH_ArkUI_ListItemSwipeAction_Collapse()

```
int32_t OH_ArkUI_ListItemSwipeAction_Collapse(ArkUI_NodeHandle node)
```

**Description**

Collapses the menu of a specified ListItem.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| node | ListItem node object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         [ARKUI_ERROR_CODE_PARAM_ERROR](capi-native-type-h.md#arkui_errorcode) The type of the node object passed is incorrect.<br>         [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-native-type-h.md#arkui_errorcode) The node passed is not mounted to the component tree.|

### OH_ArkUI_AccessibilityState_Create()

```
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)
```

**Description**


Creates an accessibility state.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* | Returns the pointer to the created accessibility state object. If a null pointer is returned, the creation fails. A possible cause is that the application address space is full.|

### OH_ArkUI_AccessibilityState_Dispose()

```
void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)
```

**Description**


Disposes of the pointer to an accessibility state.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|

### OH_ArkUI_AccessibilityState_SetDisabled()

```
void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)
```

**Description**


Sets whether an accessibility state is disabled.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|
| int32_t isDisabled | Whether the accessibility state is disabled. The value **1** means that the accessibility state is disabled, and **0** means the opposite. The default value is **0**.|

### OH_ArkUI_AccessibilityState_IsDisabled()

```
int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)
```

**Description**


Obtains whether an accessibility state is disabled.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Whether the accessibility state is disabled. The value **1** means that the accessibility state is disabled, and **0** means the opposite. The default value is **0**.<br>         If the value of **state** is null, the default value is returned.|

### OH_ArkUI_AccessibilityState_SetSelected()

```
void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)
```

**Description**


Sets whether an accessibility state is selected.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|
| int32_t isSelected | Whether the accessibility state is selected. The value **1** means that the accessibility state is selected, and **0** means the opposite. The default value is **0**.|

### OH_ArkUI_AccessibilityState_IsSelected()

```
int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)
```

**Description**


Obtains whether an accessibility state is selected.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Whether the accessibility state is selected. The value **1** means that the accessibility state is selected, and **0** means the opposite. The default value is **0**.<br>         If the value of **state** is null, the default value is returned.|

### OH_ArkUI_AccessibilityState_SetCheckedState()

```
void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)
```

**Description**


Sets the check box state of an accessibility state.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|
| int32_t checkedState | Check box status. The parameter type is [ArkUI_AccessibilityCheckedState](capi-native-type-h.md#arkui_accessibilitycheckedstate). The default value is **ARKUI_ACCESSIBILITY_UNCHECKED**.|

### OH_ArkUI_AccessibilityState_GetCheckedState()

```
int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)
```

**Description**


Obtains the check box state of an accessibility state.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* state | Pointer to the created accessibility state object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Check box status. The parameter type is [ArkUI_AccessibilityCheckedState](capi-native-type-h.md#arkui_accessibilitycheckedstate). The default value is **ARKUI_ACCESSIBILITY_UNCHECKED**.<br>         If a parameter error occurs, the default value is returned.|

### OH_ArkUI_AccessibilityValue_Create()

```
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)
```

**Description**


Creates an **AccessibilityValue** instance.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* | Returns the pointer to the created **AccessibilityValue** instance.|

### OH_ArkUI_AccessibilityValue_Dispose()

```
void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)
```

**Description**


Disposes of the pointer to an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name                                                                                   | Description|
|----------------------------------------------------------------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|

### OH_ArkUI_AccessibilityValue_SetMin()

```
void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)
```

**Description**


Sets the minimum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|
| int32_t min | Minimum value based on the range component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetMin()

```
int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the minimum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetMax()

```
void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)
```

**Description**


Sets the maximum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|
| int32_t max | Maximum value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetMax()

```
int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the maximum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetCurrent()

```
void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)
```

**Description**


Sets the current accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|
| int32_t current | Current value based on the range component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetCurrent()

```
int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the current accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Current value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetRangeMin()

```
void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)
```

**Description**


Sets the minimum value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to set the minimum value.|
| int32_t rangeMin | Minimum value based on the range component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetRangeMin()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the minimum value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to obtain the minimum value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetRangeMax()

```
void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)
```

**Description**


Sets the maximum value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to set the maximum value.|
| int32_t rangeMax | Maximum value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetRangeMax()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the maximum value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to obtain the minimum value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetRangeCurrent()

```
void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)
```

**Description**


Sets the current value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to set the current value.|
| int32_t rangeCurrent | Current value based on the range component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetRangeCurrent()

```
int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the current value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to obtain the current value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Current value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetText()

```
void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)
```

**Description**


Sets the text description of an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|
| const char* text | Text description. The default value is an empty string.|

### OH_ArkUI_AccessibilityValue_GetText()

```
const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the text description of an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Returns the pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Text description. The default value is an empty string.<br>         If a parameter error occurs, a null pointer is returned.|

### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromString(char* src)
```

**Description**


Creates an image frame information object based on an image path, with the image format being SVG, PNG, or JPG.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char* src | Image path.|

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* | Pointer to the image frame information object.|

### OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor()

```
ArkUI_ImageAnimatorFrameInfo* OH_ArkUI_ImageAnimatorFrameInfo_CreateFromDrawableDescriptor(ArkUI_DrawableDescriptor* drawable)
```

**Description**


Creates an image frame information object based on a **DrawableDescriptor** object, with the image format being Resource or PixelMap.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawableDescriptor](capi-arkui-nativemodule-arkui-drawabledescriptor.md)* drawable | Pointer to an **ArkUI_DrawableDescriptor** object created using Resource or PixelMap.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* | Pointer to the image frame information object.|

### OH_ArkUI_ImageAnimatorFrameInfo_Dispose()

```
void OH_ArkUI_ImageAnimatorFrameInfo_Dispose(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Disposes of the pointer to an image frame information object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

### OH_ArkUI_ImageAnimatorFrameInfo_SetWidth()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t width)
```

**Description**


Sets the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|
| int32_t width | Image width, in px.|

### OH_ArkUI_ImageAnimatorFrameInfo_GetWidth()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetWidth(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Obtains the image width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the image width, in PX. If **imageInfo** is a null pointer, **0** is returned.|

### OH_ArkUI_ImageAnimatorFrameInfo_SetHeight()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t height)
```

**Description**


Sets the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|
| int32_t height | Image height, in px.|

### OH_ArkUI_ImageAnimatorFrameInfo_GetHeight()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetHeight(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Obtains the image height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the image height, in PX. If **imageInfo** is a null pointer, **0** is returned.|

### OH_ArkUI_ImageAnimatorFrameInfo_SetTop()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t top)
```

**Description**


Sets the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|
| int32_t top | Vertical coordinate of the image relative to the upper left corner of the component, in px.|

### OH_ArkUI_ImageAnimatorFrameInfo_GetTop()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetTop(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Obtains the vertical coordinate of an image relative to the upper left corner of the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the vertical coordinate of the image relative to the upper left corner of the component, in px. If **imageInfo** is a null pointer, **0** is returned.|

### OH_ArkUI_ImageAnimatorFrameInfo_SetLeft()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t left)
```

**Description**


Sets the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|
| int32_t left | Horizontal coordinate of the image relative to the upper left corner of the component, in px.|

### OH_ArkUI_ImageAnimatorFrameInfo_GetLeft()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetLeft(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Obtains the horizontal coordinate of an image relative to the upper left corner of the component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the horizontal coordinate of the image relative to the upper left corner of the component, in px. If **imageInfo** is a null pointer, **0** is returned.|

### OH_ArkUI_ImageAnimatorFrameInfo_SetDuration()

```
void OH_ArkUI_ImageAnimatorFrameInfo_SetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo, int32_t duration)
```

**Description**


Sets the playback duration of an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|
| int32_t duration | Playback duration of an image, in milliseconds.|

### OH_ArkUI_ImageAnimatorFrameInfo_GetDuration()

```
int32_t OH_ArkUI_ImageAnimatorFrameInfo_GetDuration(ArkUI_ImageAnimatorFrameInfo* imageInfo)
```

**Description**


Obtains the playback duration of an image.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ImageAnimatorFrameInfo](capi-arkui-nativemodule-arkui-imageanimatorframeinfo.md)* imageInfo | Pointer to the image frame information object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the playback duration of the image, in milliseconds. If **imageInfo** is a null pointer, **0** is returned.|

### OH_ArkUI_ListChildrenMainSizeOption_Create()

```
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()
```

**Description**


Creates a **ListChildrenMainSize** instance.

**Since**: 12

**Returns**

| Type                             | Description|
|---------------------------------| -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* | Created **ListChildrenMainSize** instance.|

### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```
void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)
```

**Description**


Disposes of a **ListChildrenMainSize** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance to dispose of.|

### OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)
```

**Description**


Sets the default size in a **ListChildrenMainSize** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|
| float defaultMainSize | Default size to set, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)
```

**Description**


Obtains the default size in a **ListChildrenMainSize** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Default size, in vp. The default value is **0**. If **option** is a null pointer, **-1** is returned.|

### OH_ArkUI_ListChildrenMainSizeOption_Resize()

```
void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)
```

**Description**


Resets the array size in a **ListChildrenMainSize** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|
| int32_t totalSize | Array size.|

### OH_ArkUI_ListChildrenMainSizeOption_Splice()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)
```

**Description**


Changes the content of a **ChildrenMainSizeOption** array.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|
| int32_t index | Index at which to start changing the values in the array.|
| int32_t deleteCount | Number of elements in the array to remove from the position specified by **index**.|
| int32_t addCount | Number of elements to add to the array from the position specified by **index**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_UpdateSize()

```
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)
```

**Description**


Updates the values in a **ChildrenMainSizeOption** array of a **List** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|
| int32_t index | Index at which to start changing the values in the array.|
| float mainSize | New size value to set at the specified index.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_GetMainSize()

```
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)
```

**Description**


Obtains the value of the **ChildrenMainSizeOption** array of the **List** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | **ListChildrenMainSize** instance.|
| int32_t index | Index of the value to be obtained.|

**Returns**

| Type| Description|
| -- | -- |
| float | Value at the specified index. If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_CustomSpanMeasureInfo_Create()

```
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)
```

**Description**


Creates measurement information for this custom span.

**Since**: 12

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* | Returns a **CustomSpanMeasureInfo** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanMeasureInfo_Dispose()

```
void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)
```

**Description**


Disposes of measurement information of a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info |  Pointer to the measurement information of a custom span.|

### OH_ArkUI_CustomSpanMeasureInfo_GetFontSize()

```
float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)
```

**Description**


Obtains the font size of the parent text node of a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* info |  Pointer to the measurement information of a custom span.|

**Returns**

| Type| Description|
| -- | -- |
| float | Font size of the parent text node. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanMetrics_Create()

```
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)
```

**Description**


Creates measurement metrics for this custom span.

**Since**: 12

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* | Returns a **CustomSpanMetrics** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanMetrics_Dispose()

```
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)
```

**Description**


Disposes of measurement metrics of this custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Returns a **CustomSpanMetrics** instance.|

### OH_ArkUI_CustomSpanMetrics_SetWidth()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)
```

**Description**


Sets the width for a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Returns a **CustomSpanMetrics** instance.|
| float width | Width, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanMetrics_SetHeight()

```
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)
```

**Description**


Sets the height for a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Returns a **CustomSpanMetrics** instance.|
| float height | Height, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_Create()

```
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)
```

**Description**


Creates drawing information for this custom span.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* | Returns a **CustomSpanDrawInfo** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanDrawInfo_Dispose()

```
void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)
```

**Description**


Disposes of drawing information for this custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  Pointer to the drawing information of a custom span.|

### OH_ArkUI_CustomSpanDrawInfo_GetXOffset()

```
float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)
```

**Description**


Obtains the x-axis offset of the custom span relative to the mounted component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  Pointer to the drawing information of a custom span.|

**Returns**

| Type| Description|
| -- | -- |
| float | Returns the x-axis offset. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetLineTop()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)
```

**Description**


Obtains the top margin of the custom span relative to the mounted component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  Pointer to the drawing information of a custom span.|

**Returns**

| Type| Description|
| -- | -- |
| float | Top margin. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetLineBottom()

```
float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)
```

**Description**


Obtains the bottom margin of the custom span relative to the mounted component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  Pointer to the drawing information of a custom span.|

**Returns**

| Type| Description|
| -- | -- |
| float | Bottom margin. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetBaseline()

```
float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)
```

**Description**


Obtains the baseline offset of the custom span relative to the mounted component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* info |  Pointer to the drawing information of a custom span.|

**Returns**

| Type| Description|
| -- | -- |
| float | Baseline offset. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomProperty_Destroy()

```
void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)
```

**Description**


Destroys a **CustomProperty** instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | **CustomProperty** instance to destroy.|

### OH_ArkUI_CustomProperty_GetStringValue()

```
const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)
```

**Description**


Obtains the value of a custom property.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | Pointer to the custom property object.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Value of the custom property.|

### OH_ArkUI_HostWindowInfo_GetName()

```
const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)
```

**Description**


Obtains the window name from a **HostWindowInfo** object.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | **HostWindowInfo** object.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Returns the window name obtained from the **HostWindowInfo** object.|

### OH_ArkUI_HostWindowInfo_Destroy()

```
void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)
```

**Description**


Destroys n **HostWindowInfo** object.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | **HostWindowInfo** object to be destroyed.|

### OH_ArkUI_ActiveChildrenInfo_Destroy()

```
void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)
```

**Description**


Destroys an **ActiveChildrenInfo** instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | **ActiveChildrenInfo** instance to destroy.|

### OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex()

```
ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)
```

**Description**


Obtains the child node at the specified index in the specified **ActiveChildrenInfo** instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | **ActiveChildrenInfo** instance from which to obtain the information.|
| int32_t index | Index of the target child node.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Handle to the child node at the specified index, or **nullptr** if an error occurs.|

### OH_ArkUI_ActiveChildrenInfo_GetCount()

```
int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)
```

**Description**


Obtains the number of nodes in the specified **ActiveChildrenInfo** instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | **ActiveChildrenInfo** instance from which to obtain the information.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of child nodes. The default value is **0**.|

### OH_ArkUI_ProgressLinearStyleOption_Create()

```
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
```

**Description**


Creates a **ProgressLinearStyleOption** instance.

**Since**: 15

**Returns**

| Type                                  | Description|
|--------------------------------------| -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* | Returns the **ProgressLinearStyleOption** instance created.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_ProgressLinearStyleOption_Destroy()

```
void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)
```

**Description**


Destroys a **ProgressLinearStyleOption** instance.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|

### OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled()

```
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**


Sets whether to enable the smooth progress effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| bool enabled | Whether to enable the smooth effect. When this effect is enabled, the progress changes smoothly from the current value to the target value. When this effect is disabled, the progress changes abruptly to the target value. The default value is **true**.|

### OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled()

```
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**


Sets whether to enable the scan effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| bool enabled | Whether to enable the scan effect. The default value is **false**.|

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth()

```
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)
```

**Description**


Sets the width of the progress indicator.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| float strokeWidth | Stroke width of the progress indicator, in vp. Percentage values are not supported. The default value is **4.0vp**.|

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius()

```
void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)
```

**Description**


Sets the corner radius of the progress indicator.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| float strokeRadius | Corner radius of the progress indicator, in vp. The value range is [0, strokeWidth/2]. Default value: **strokeWidth/2**.|

### OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled()

```
bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**Description**


Obtains the enabled status of the smooth progress effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns the enabled status of the smooth progress effect.|

### OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled()

```
bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)
```

**Description**


Obtains the enabled status of the scan effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns the enabled status of the scan effect.|

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth()

```
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)
```

**Description**


Obtains the stroke width of the progress indicator.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Stroke width of the progress indicator, in vp.|

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius()

```
float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)
```

**Description**


Obtains the corner radius of the progress indicator.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Corner radius of the progress indicator, in vp.|

### OH_ArkUI_CreateSnapshotOptions()

```
ArkUI_SnapshotOptions* OH_ArkUI_CreateSnapshotOptions()
```

**Description**


Creates a snapshot option. The snapshot option must be destroyed by calling [OH_ArkUI_DestroySnapshotOptions()](#oh_arkui_destroysnapshotoptions) when it is no longer used.

**Since**: 15

**Returns**

| Type                        | Description|
|----------------------------| -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* | Pointer to the created snapshot options object. If a null pointer is returned, creation failed, possibly due to insufficient memory.|

### OH_ArkUI_DestroySnapshotOptions()

```
void OH_ArkUI_DestroySnapshotOptions(ArkUI_SnapshotOptions* snapshotOptions)
```

**Description**


Destroys a snapshot options object.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | Screenshot options.|

### OH_ArkUI_SnapshotOptions_SetScale()

```
int32_t OH_ArkUI_SnapshotOptions_SetScale(ArkUI_SnapshotOptions* snapshotOptions, float scale)
```

**Description**


Sets the scale property in the snapshot options.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SnapshotOptions](capi-arkui-nativemodule-arkui-snapshotoptions.md)* snapshotOptions | Screenshot options.|
| float scale | Scale factor.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CrossLanguageOption_Create()

```
ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)
```

**Description**


Creates an instance of the cross-language configuration option.

**Since**: 15

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* | Returns the pointer to the **ArkUI_CrossLanguageOption** instance created. If a null pointer is returned, creation failed, possibly due to insufficient memory.|

### OH_ArkUI_CrossLanguageOption_Destroy()

```
void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)
```

**Description**


Destroys an instance of the cross-language configuration option.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Cross-language configuration option instance to be destroyed.|

### OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus()

```
void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)
```

**Description**


Sets whether cross-language attribute setting is allowed in the configuration option.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance.|
| bool enabled | Whether cross-language attribute setting is allowed. The default value is **false**.|

### OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus()

```
bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)
```

**Description**


Checks whether cross-language attribute setting is allowed in the configuration option.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether cross-language attribute setting is allowed.|

### OH_ArkUI_VisibleAreaEventOptions_Create()

```
ArkUI_VisibleAreaEventOptions* OH_ArkUI_VisibleAreaEventOptions_Create()
```

**Description**


Creates an instance of visible area change event parameters.

**Since**: 17

**Returns**

| Type                                | Description|
|------------------------------------| -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* | Returns the created instance of visible area change event parameters.|

### OH_ArkUI_VisibleAreaEventOptions_Dispose()

```
void OH_ArkUI_VisibleAreaEventOptions_Dispose(ArkUI_VisibleAreaEventOptions* option)
```

**Description**


Disposes of an instance of visible area change event parameters.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | Instance of visible area change event parameters to be destroyed.|

### OH_ArkUI_VisibleAreaEventOptions_SetRatios()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_SetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t size)
```

**Description**


Sets the threshold ratios for visible area changes.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | Pointer to the instance of visible area change event parameters.|
| float* value | Array of threshold ratios. Each element represents a ratio of the component's visible area (that is, the area of the component that is visible on screen; only the area within the parent component is counted) to the component's total area. The value range of the threshold is [0.0, 1.0]. If the threshold set exceeds this range, the value **0.0** or **1.0** will be used.|
| int32_t size | Size of the array of threshold ratios.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_SetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions *option, int32_t value)
```

**Description**


Sets the expected update interval for visible area changes.  

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md) *option | Pointer to the instance of visible area change event parameters.|
| int32_t value | Expected update interval, in ms. Default value: **1000**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_VisibleAreaEventOptions_GetRatios()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_GetRatios(ArkUI_VisibleAreaEventOptions* option, float* value, int32_t* size)
```

**Description**


Obtains the threshold ratios for visible area changes.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | Pointer to the instance of visible area change event parameters.|
| float* value | Array of threshold ratios.|
| int32_t* size | Size of the array of threshold ratios.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the provided buffer size is insufficient.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval()

```
int32_t OH_ArkUI_VisibleAreaEventOptions_GetExpectedUpdateInterval(ArkUI_VisibleAreaEventOptions* option)
```

**Description**


Obtains the expected update interval for visible area changes.

**Since**: 17


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_VisibleAreaEventOptions](capi-arkui-nativemodule-arkui-visibleareaeventoptions.md)* option | Pointer to the instance of visible area change event parameters.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Expected update interval, in ms. Default value: **1000**.|

### OH_ArkUI_TextPickerRangeContentArray_Create()

```
ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)
```

**Description**


Creates a **TextPickerRangeContent** array object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| int32_t length | Length of the **TextPickerRangeContent** array.|

**Returns**

| Type                                    | Description|
|----------------------------------------| -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* | Returns a pointer to an empty **TextPickerRangeContent** array.|

### OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex()

```
void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)
```

**Description**


Sets the icon data at the specified position in the **TextPickerRangeContent** array.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | Pointer to the **TextPickerRangeContent** array.|
| char* icon | Pointer to the icon image address.|
| int32_t index | Position in the array, starting from 0.|

### OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex()

```
void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)
```

**Description**


Sets the text data at the specified position in the **TextPickerRangeContent** array.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | Pointer to the **TextPickerRangeContent** array.|
| char* text | Pointer to the text content.|
| int32_t index | Position in the array, starting from 0.|

### OH_ArkUI_TextPickerRangeContentArray_Destroy()

```
void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)
```

**Description**


Destroys a **TextPickerRangeContent** array object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | Pointer to the **TextPickerRangeContent** array.|

### OH_ArkUI_TextCascadePickerRangeContentArray_Create()

```
ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)
```

**Description**


Destroys a **TextCascadePickerRangeContent** array object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| int32_t length | Length of the **TextPickerRangeContent** array.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* | Returns a pointer to an empty **TextCascadePickerRangeContent** array.|

### OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)
```

**Description**


Sets the text data at the specified position in the **TextCascadePickerRangeContent** array.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | Pointer to the **TextCascadePickerRangeContent** array.|
| char* text | Pointer to the text content.|
| int32_t index | Position in the array, starting from 0.|

### OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)
```

**Description**


Sets the child data at the specified position in the **TextCascadePickerRangeContent** array.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | Pointer to the **TextCascadePickerRangeContent** array.|
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* child | Pointer to the child node array.|
| int32_t index | Position in the array, starting from 0.|

### OH_ArkUI_TextCascadePickerRangeContentArray_Destroy()

```
void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy(ArkUI_TextCascadePickerRangeContentArray* handle)
```

**Description**


Destroys a **TextCascadePickerRangeContent** array object.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | Pointer to the **TextCascadePickerRangeContent** array.|

### OH_ArkUI_EmbeddedComponentOption_Create()

```
ArkUI_EmbeddedComponentOption* OH_ArkUI_EmbeddedComponentOption_Create()
```

**Description**


Creates an **EmbeddedComponent** option object.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* | Pointer to the **EmbeddedComponent** option object.|

### OH_ArkUI_EmbeddedComponentOption_Dispose()

```
void OH_ArkUI_EmbeddedComponentOption_Dispose(ArkUI_EmbeddedComponentOption* option)
```

**Description**


Disposes of an **EmbeddedComponent** option object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | Pointer to the target **EmbeddedComponent** option object.|

### OH_ArkUI_EmbeddedComponentOption_SetOnError()

```
void OH_ArkUI_EmbeddedComponentOption_SetOnError(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, const char* name, const char* message))
```

**Description**


Sets the **onError** callback for the **EmbeddedComponent** component. This callback is triggered when an error occurs during the running of the **EmbeddedComponent** component.

**Since**: 20


**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | Pointer to the **EmbeddedComponent** option object.|
| void (\*callback)(int32_t code, const char* name, const char* message) | Callback function defined by the developer.<br>- code: result code returned when the API fails to be called. For details about the error codes, see UIExtension Error Codes.<br>- name: name returned when the API fails to be called.<br>- message: details returned when the API fails to be called.|


### OH_ArkUI_EmbeddedComponentOption_SetOnTerminated()

```
void OH_ArkUI_EmbeddedComponentOption_SetOnTerminated(ArkUI_EmbeddedComponentOption* option, void (*callback)(int32_t code, AbilityBase_Want* want))
```

**Description**


Sets the **onTerminated** callback for the **EmbeddedComponent** component. This callback is triggered when the **EmbeddedComponent** component exits properly.

**Since**: 20


**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_EmbeddedComponentOption](capi-arkui-nativemodule-arkui-embeddedcomponentoption.md)* option | Pointer to the **EmbeddedComponent** option object.|
| void (\*callback)(int32_t code, [AbilityBase_Want](capi-arkui-nativemodule-abilitybase-want.md)* want) | Callback function defined by the developer.<br>- code: result code returned when the EmbeddedUIExtensionAbility is exited. If the ability is exited by calling terminateSelfWithResult, the result code is the value set for the ability. If the ability is exited by calling terminateSelf, the result code is the default value 0.<br>- want: data returned when the EmbeddedUIExtensionAbility is exited.  |
