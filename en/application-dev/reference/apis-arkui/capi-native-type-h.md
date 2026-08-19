# native_type.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

## Overview

Defines the common types for the native module.

**File to include**: <arkui/native_type.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 12

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**Sample**: <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_Node](capi-arkui-nativemodule-arkui-node-descriptor.md) | ArkUI_Node | Defines an ArkUI native component object.|
| [ArkUI_ContextCallback](capi-arkui-nativemodule-arkui-contextcallback.md) | ArkUI_ContextCallback | Defines an event callback.|
| [ArkUI_NumberValue](capi-arkui-nativemodule-arkui-numbervalue.md) | ArkUI_NumberValue | Defines the number type of ArkUI on the native side.|
| [ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md) | ArkUI_ColorStop | Defines a gradient color stop.|
| [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md) | ArkUI_Rect | Defines a mask area.|
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | ArkUI_IntSize | Describes the width and height of a component.|
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | ArkUI_IntOffset | Defines the offset of the current component relative to its parent component.|
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | ArkUI_Margin | Describes the margins of a component.|
| [ArkUI_NativeDialog](capi-arkui-nativemodule-arkui-nativedialog.md) | ArkUI_NativeDialog | Defines a custom dialog box controller object for ArkUI on the native side.|
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md) | ArkUI_LayoutConstraint | Defines layout constraints for a component.|
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md) | ArkUI_DrawContext | Defines the component drawing context.|
| [ArkUI_Node*](capi-arkui-nativemodule-arkui-node8h.md) | ArkUI_NodeHandle | Defines the pointer to an ArkUI native component object.|
| [ArkUI_NativeDialog*](capi-arkui-nativemodule-arkui-nativedialog8h.md) | ArkUI_NativeDialogHandle | Defines the handle to the custom dialog box controller of ArkUI on the native side.|
| [ArkUI_GestureCollectInterceptInfo](capi-arkui-nativemodule-arkui-gesturecollectinterceptinfo.md) | ArkUI_GestureCollectInterceptInfo | Defines gesture collection interception information.|
| [ArkUI_GridItemSize](capi-arkui-nativemodule-arkui-griditemsize.md) | ArkUI_GridItemSize | Defines the return value for the **onGetIrregularSizeByIndex** callback in **Grid** layout options.|
| [ArkUI_GridItemRect](capi-arkui-nativemodule-arkui-griditemrect.md) | ArkUI_GridItemRect | Defines the return value for the **onGetRectByIndex** callback in **Grid** layout options.|
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md) | ArkUI_GridLayoutOptions | Defines the **Grid** layout options.|
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md) | ArkUI_WaterFlowSectionOption | Defines the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md) | ArkUI_ListItemSwipeActionItem | Defines the item configuration for **ListItemSwipeActionOption**.|
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) | ArkUI_ListItemSwipeActionOption | Defines the configuration for **ListItemSwipeActionOption**.|
| [ArkUI_Context](capi-arkui-nativemodule-arkui-context.md) | ArkUI_Context | Defines a context object of the ArkUI native UI.|
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | Defines the pointer to the ArkUI native UI context.|
| [ArkUI_NodeContent*](capi-arkui-nativemodule-arkui-nodecontent8h.md) | ArkUI_NodeContentHandle | Defines the pointer to the ArkUI **NodeContent** instance on the native side.|
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md) | ArkUI_AlignmentRuleOption | Defines the alignment rule in the relative container.|
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md) | ArkUI_GuidelineOption | Defines the ID, direction, and position of a guideline (a guideline in the **RelativeContainer** component).|
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md) | ArkUI_BarrierOption | Defines the ID, direction, and referenced component of a barrier.|
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md) | ArkUI_ListChildrenMainSize | Defines the **ChildrenMainSize** information of the **List** component.|
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md) | ArkUI_ProgressLinearStyleOption | Defines a linear progress indicator style.|
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md) | ArkUI_CustomProperty | Defines custom property information.|
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) | ArkUI_HostWindowInfo | Defines host window information.|
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) | ArkUI_ActiveChildrenInfo | Defines active child node information.|
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md) | ArkUI_CrossLanguageOption | Defines a cross-language configuration option.|
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md) | ArkUI_AccessibilityState | Defines a component accessibility state.|
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md) | ArkUI_AccessibilityValue | Defines a component accessibility value.|
| [ArkUI_SystemFontStyleEvent](capi-arkui-nativemodule-arkui-systemfontstyleevent.md) | ArkUI_SystemFontStyleEvent | Defines a system font style event.|
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md) | ArkUI_CustomSpanMeasureInfo | Defines the measurement information of a custom span.|
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md) | ArkUI_CustomSpanMetrics | Defines the measurement metrics of a custom span.|
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md) | ArkUI_CustomSpanDrawInfo | Defines the drawing information of a custom span.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) | ArkUI_StyledString_Descriptor | Defines the styled string descriptor object supported by the text component.|
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)| ArkUI_SelectionOptions | Defines options of the selection operation.|
|[ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)|ArkUI_PositionEdges|Provides position parameters relative to the boundaries of the container's content area.|
|[ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)|ArkUI_PixelRoundPolicy|Defines a component pixel rounding policy.|
|[ArkUI_ContentTransitionEffect](capi-arkui-nativemodule-arkui-contenttransitioneffect.md)|ArkUI_ContentTransitionEffect|Defines the content transition effect.|
|[ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)|ArkUI_ShowCounterConfig|Defines the text input character counter configuration.|
|[ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)|ArkUI_TextContentBaseController|Defines the basic controller for text.|
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md) | ArkUI_TextMenuItem | Defines a text menu item.|
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md) | ArkUI_TextMenuItemArray | Defines a text menu item array.|
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md) | ArkUI_TextEditMenuOptions | Defines a text menu extension.|
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md) | ArkUI_TextSelectionMenuOptions | Defines custom text selection menu options.|
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md) | ArkUI_SelectedDragPreviewStyle | Defines the drag preview style of the selected text.|
| [ArkUI_TextMarqueeOptions](capi-arkui-nativemodule-arkui-textmarqueeoptions.md) | ArkUI_TextMarqueeOptions | Defines marquee options for text.|
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | OH_ArkUI_DecorationStyleOptions | Defines decoration style options.|
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) | OH_ArkUI_TextDataDetectorConfig | Defines the configuration of text entity recognition.|
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | OH_ArkUI_TextEditorSelectionMenuOptions | Defines the text selection menu options of the text editor.|
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | OH_ArkUI_TextEditorPlaceholderOptions | Defines the hint text options when no content is entered in the text editor.|
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | OH_ArkUI_TextEditorStyledStringController | Defines the styled string controller of the text editor.|
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | OH_ArkUI_TextEditorParagraphStyle | Defines the paragraph style of the text editor.|
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | OH_ArkUI_TextEditorTextStyle | Defines the text style of the text editor.|
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md) | OH_ArkUI_FontWeightConfigs | Defines the font weight configuration of text. [OH_ArkUI_FontWeightConfigs_Create](#oh_arkui_fontweightconfigs_create) can be used to create a text font weight configuration object. [OH_ArkUI_FontWeightConfigs_Destroy](#oh_arkui_fontweightconfigs_destroy) can be used to destroy the text font weight configuration object. [OH_ArkUI_FontWeightConfigs_SetEnableVariableFontWeight](#oh_arkui_fontweightconfigs_setenablevariablefontweight) can be used to set whether to enable variable font weight adjustment after the object is created. [OH_ArkUI_FontWeightConfigs_GetEnableVariableFontWeight](#oh_arkui_fontweightconfigs_getenablevariablefontweight) can be used to check whether variable font weight adjustment is enabled after the object is created. [OH_ArkUI_FontWeightConfigs_SetEnableDeviceFontWeightCategory](#oh_arkui_fontweightconfigs_setenabledevicefontweightcategory) can be used to set whether the text font weight is updated with the font weight level of the device after the object is created. [OH_ArkUI_FontWeightConfigs_GetEnableDeviceFontWeightCategory](#oh_arkui_fontweightconfigs_getenabledevicefontweightcategory) can be used to check whether the text font weight is updated with the font weight level of the device after the object is created.|
| [OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md) | OH_ArkUI_FontConfigs | Defines the font configuration of text. [OH_ArkUI_FontConfigs_Create](#oh_arkui_fontconfigs_create) can be used to create a text font configuration object. [OH_ArkUI_FontConfigs_Destroy](#oh_arkui_fontconfigs_destroy) can be used to destroy the text font configuration object. [OH_ArkUI_FontConfigs_SetFontWeightConfigs](#oh_arkui_fontconfigs_setfontweightconfigs) can be used to set the text font weight after the object is created. [OH_ArkUI_FontConfigs_GetFontWeightConfigs](#oh_arkui_fontconfigs_getfontweightconfigs) can be used to view the text font weight after the object is created.|
| [OH_ArkUI_TextController](capi-arkui-nativemodule-oh-arkui-textcontroller.md) | OH_ArkUI_TextController | Defines a text component controller. [OH_ArkUI_TextController_Create](#oh_arkui_textcontroller_create) can be used to create a text component controller object, and [OH_ArkUI_TextController_Destroy](#oh_arkui_textcontroller_destroy) can be used to destroy the text component controller object. After the object is created, [OH_ArkUI_TextController_SetStyledString](#oh_arkui_textcontroller_setstyledstring) can be used to set a styled string for the text component.|
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) | OH_ArkUI_LinearGradientOptions | Defines the options for a linear gradient effect.|
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) | OH_ArkUI_RadialGradientOptions | Defines the options for a radial gradient effect.|

### Enums

| Name                                                                 | typedef Keyword                     | Description                               |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_Alignment](#arkui_alignment)                                 | ArkUI_Alignment                 | Enumerates the alignment modes.                       |
| [ArkUI_FontStyle](#arkui_fontstyle)                                 | ArkUI_FontStyle                 | Enumerates the font styles.                       |
| [ArkUI_FontWeight](#arkui_fontweight)                               | ArkUI_FontWeight                | Enumerates the font weights.                    |
| [ArkUI_TextAlignment](#arkui_textalignment)                         | ArkUI_TextAlignment             | Enumerates text alignment modes.                   |
| [ArkUI_TextVerticalAlignment](#arkui_textverticalalignment)         | ArkUI_TextVerticalAlignment     | Enumerates text vertical alignment styles.                   |
| [ArkUI_EnterKeyType](#arkui_enterkeytype)                           | ArkUI_EnterKeyType              | Enumerates the types of the Enter key for a single-line text box.               |
| [ArkUI_TextInputType](#arkui_textinputtype)                         | ArkUI_TextInputType             | Enumerates the input method type of a single-line text.                  |
| [ArkUI_TextAreaType](#arkui_textareatype)                           | ArkUI_TextAreaType              | Enumerates the input method types of a multi-line text.                  |
| [ArkUI_CancelButtonStyle](#arkui_cancelbuttonstyle)                 | ArkUI_CancelButtonStyle         | Enumerates the styles of the Cancel button.                     |
| [ArkUI_ProgressType](#arkui_progresstype)                           | ArkUI_ProgressType              | Enumerates the styles of the progress indicator.                      |
| [ArkUI_TextDecorationType](#arkui_textdecorationtype)               | ArkUI_TextDecorationType        | Enumerates the text decoration types.                      |
| [ArkUI_TextDecorationStyle](#arkui_textdecorationstyle)             | ArkUI_TextDecorationStyle       | Enumerates the text decoration styles.                      |
| [ArkUI_TextCase](#arkui_textcase)                                   | ArkUI_TextCase                  | Enumerates the text cases.                      |
| [ArkUI_CopyOptions](#arkui_copyoptions)                             | ArkUI_CopyOptions               | Enumerates the text copy and paste modes.                   |
| [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate) | ArkUI_AccessibilityCheckedState | Enumerates the accessibility check box states.                 |
| [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype)     | ArkUI_AccessibilityActionType   | Enumerates the accessibility action types.                       |
| [ArkUI_EdgeEffect](#arkui_edgeeffect)                               | ArkUI_EdgeEffect                | Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached.                     |
| [ArkUI_BarState](#arkui_barstate)                               | ArkUI_BarState                | Enumerates the text control scrollbar states.                     |
| [ArkUI_EffectEdge](#arkui_effectedge)                               | ArkUI_EffectEdge                | Enumerates the edges for which the effect takes effect when the boundary of the scrollable content is reached.                |
| [ArkUI_ScrollDirection](#arkui_scrolldirection)                     | ArkUI_ScrollDirection           | Enumerates the scrolling directions of the [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md) component.               |
| [ArkUI_ScrollSnapAlign](#arkui_scrollsnapalign)                     | ArkUI_ScrollSnapAlign           | Enumerates the alignment modes of list items when scrolling ends.                |
| [ArkUI_ScrollBarDisplayMode](#arkui_scrollbardisplaymode)           | ArkUI_ScrollBarDisplayMode      | Enumerates the scrollbar display modes.                      |
| [ArkUI_Axis](#arkui_axis)                                           | ArkUI_Axis                      | Enumerates the scroll directions.            |
| [ArkUI_StickyStyle](#arkui_stickystyle)                             | ArkUI_StickyStyle               | Enumerates the modes for pinning the header to the top or the footer to the bottom.                  |
| [ArkUI_ContentClipMode](#arkui_contentclipmode)                     | ArkUI_ContentClipMode           | Enumerates the content clipping modes of scrollable components.               |
| [ArkUI_WaterFlowLayoutMode](#arkui_waterflowlayoutmode)             | ArkUI_WaterFlowLayoutMode       | Enumerates the layout modes of the [WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md) component.            |
| [ArkUI_BorderStyle](#arkui_borderstyle)                             | ArkUI_BorderStyle               | Enumerates the border styles.                       |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode)                 | ArkUI_AccessibilityMode         | Enumerates the accessibility modes.                     |
| [ArkUI_TextCopyOptions](#arkui_textcopyoptions)                     | ArkUI_TextCopyOptions           | Enumerates copy options, which define whether copy and paste is allowed for text content.               |
| [ArkUI_TextHeightAdaptivePolicy](#arkui_textheightadaptivepolicy)   | ArkUI_TextHeightAdaptivePolicy  | Defines how the adaptive height is determined for the text.                    |
| [ArkUI_ScrollNestedMode](#arkui_scrollnestedmode)                   | ArkUI_ScrollNestedMode          | Enumerates nested scrolling modes.                        |
| [ArkUI_ScrollEdge](#arkui_scrolledge)                               | ArkUI_ScrollEdge                | Enumerates the edges to which the component scrolls.                      |
| [ArkUI_ScrollAlignment](#arkui_scrollalignment)                     | ArkUI_ScrollAlignment           | Defines how the list item to scroll to is aligned with the container.                 |
| [ArkUI_ScrollState](#arkui_scrollstate)                             | ArkUI_ScrollState               | Enumerates the scrolling states.                        |
| [ArkUI_SliderBlockStyle](#arkui_sliderblockstyle)                   | ArkUI_SliderBlockStyle          | Enumerates the styles of the slider in the block direction.                          |
| [ArkUI_SliderDirection](#arkui_sliderdirection)                     | ArkUI_SliderDirection           | Enumerates the scroll directions of the slider.                       |
| [ArkUI_SliderStyle](#arkui_sliderstyle)                             | ArkUI_SliderStyle               | Enumerates the slider styles.                     |
| [ArkUI_CheckboxShape](#arkui_checkboxshape)                         | ArkUI_CheckboxShape             | Enumerates the shapes of the check box.                  |
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor)                         | ArkUI_AdaptiveColor             | Enumerates the adaptive color modes.                          |
| [ArkUI_ColorMode](#arkui_colormode)                                 | ArkUI_ColorMode                 | Enumerates the color modes.                         |
| [ArkUI_SystemColorMode](#arkui_systemcolormode)                     | ArkUI_SystemColorMode           | Enumerates the system color modes.                       |
| [ArkUI_VerticalAlignment](#arkui_verticalalignment)                 | ArkUI_VerticalAlignment         | Enumerates the vertical alignment modes.                        |
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment)             | ArkUI_HorizontalAlignment       | Enumerates the alignment mode in the horizontal direction.                      |
| [ArkUI_TextOverflow](#arkui_textoverflow)                           | ArkUI_TextOverflow              | Enumerates the display modes when the text is too long.                    |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment)               | ArkUI_ImageSpanAlignment        | Enumerates the alignment mode of the image with the text.                   |
| [ArkUI_Direction](#arkui_direction)                                 | ArkUI_Direction                 | Enumerates the modes in which components are laid out along the main axis of the container.              |
| [ArkUI_ItemAlignment](#arkui_itemalignment)                         | ArkUI_ItemAlignment             | Enumerates the modes in which components are laid out along the cross axis of the container.            |
| [ArkUI_FlexAlignment](#arkui_flexalignment)                         | ArkUI_FlexAlignment             | Enumerates the vertical alignment modes.                      |
| [ArkUI_FlexDirection](#arkui_flexdirection)                         | ArkUI_FlexDirection             | Enumerates the directions of the main axis in the flex container.                   |
| [ArkUI_FlexWrap](#arkui_flexwrap)                                   | ArkUI_FlexWrap                  | Defines whether the flex container has a single line or multiple lines.                  |
| [ArkUI_WordBreak](#arkui_wordbreak)                                 | ArkUI_WordBreak                 | Enumerates the word break rules.                        |
| [ArkUI_EllipsisMode](#arkui_ellipsismode)                           | ArkUI_EllipsisMode              | Enumerates the ellipsis positions.                        |
| [ArkUI_ListItemAlignment](#arkui_listitemalignment)                 | ArkUI_ListItemAlignment         | Enumerates the alignment modes of items along the cross axis.                      |
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit)                   | ArkUI_LengthMetricUnit          | Enumerates the component units.                       |
| [ArkUI_TextInputContentType](#arkui_textinputcontenttype)           | ArkUI_TextInputContentType      | Enumerates the autofill types.                        |
| [ArkUI_BarrierDirection](#arkui_barrierdirection)                   | ArkUI_BarrierDirection          | Enumerates the barrier directions.                        |
| [ArkUI_RelativeLayoutChainStyle](#arkui_relativelayoutchainstyle)   | ArkUI_RelativeLayoutChainStyle  | Enumerates the chain styles.                          |
| [ArkUI_TextInputStyle](#arkui_textinputstyle)                       | ArkUI_TextInputStyle            | Enumerates the text input styles.                         |
| [ArkUI_KeyboardAppearance](#arkui_keyboardappearance)               | ArkUI_KeyboardAppearance        | Enumerates the appearance modes of the keyboard when the text box is focused.                    |
| [ArkUI_TextDataDetectorType](#arkui_textdatadetectortype)           | ArkUI_TextDataDetectorType      | Enumerates the entity types of text recognition.                     |
| [ArkUI_ButtonType](#arkui_buttontype)                               | ArkUI_ButtonType                | Enumerates the button types.                       |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate)   | ArkUI_ListItemSwipeActionState  | Enumerates the item states of [swipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the [Listitem](./arkui-ts/ts-container-listitem.md#listitem10) component.|
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect)     | ArkUI_ListItemSwipeEdgeEffect   | Enumerates the item edge effects of [swipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the [Listitem](./arkui-ts/ts-container-listitem.md#listitem10) component.|
| [ArkUI_ListItemSwipeActionDirection](#arkui_listitemswipeactiondirection) | ArkUI_ListItemSwipeActionDirection | Enumerates the swipe action menu display directions for the **ListItem** component.|
| [ArkUI_ErrorCode](#arkui_errorcode)                                 | ArkUI_ErrorCode                 | Enumerates the error codes.                        |
| [ArkUI_ScrollSource](#arkui_scrollsource)                           | ArkUI_ScrollSource              | Enumerates scroll sources.                       |
| [ArkUI_SafeAreaType](#arkui_safeareatype)                           | ArkUI_SafeAreaType              | Enumerates the types of expanded safe areas.                    |
| [ArkUI_SafeAreaEdge](#arkui_safeareaedge)                           | ArkUI_SafeAreaEdge              | Enumerates the edges for expanding the safe area.                 |
| [ArkUI_ListItemGroupArea](#arkui_listitemgrouparea)                 | ArkUI_ListItemGroupArea         | Enumerates areas of the **ListItemGroup** component.           |
| [ArkUI_KeyboardAvoidMode](#arkui_keyboardavoidmode)                 | ArkUI_KeyboardAvoidMode         | Enumerates the soft keyboard avoidance modes.                          |
| [ArkUI_HoverModeAreaType](#arkui_hovermodeareatype)                 | ArkUI_HoverModeAreaType         | Enumerates the types of display areas for the hover mode.                         |
| [ArkUI_ExpandMode](#arkui_expandmode)                               | ArkUI_ExpandMode                | Enumerates the expansion mode of child nodes.                    |
| [ArkUI_FocusWrapMode](#arkui_focuswrapmode)                         | ArkUI_FocusWrapMode             | Enumerates the focus wrap mode of components.                        |
| [ArkUI_ItemFillPolicy](#arkui_itemfillpolicy)                         | ArkUI_ItemFillPolicy             | Enumerates preset column layouts for different responsive breakpoints.                        |
| [ArkUI_EdgeDirection](#arkui_edgedirection)                         | ArkUI_EdgeDirection             | Enumerates rectangle edge directions.                        |
| [ArkUI_CornerDirection](#arkui_cornerdirection)                     | ArkUI_CornerDirection           | Enumerates corner directions.                        |
| [ArkUI_LayoutPolicy](#arkui_layoutpolicy)                         | ArkUI_LayoutPolicy             | Enumerates layout policies.                        |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) | ArkUI_PixelRoundCalcPolicy | Enumerates pixel rounding calculation policies.|
| [ArkUI_GridItemStyle](#arkui_griditemstyle)                         | ArkUI_GridItemStyle             | Enumerates styles of grid items.                        |
| [ArkUI_MenuPolicy](#arkui_menupolicy)                               | ArkUI_MenuPolicy                | Enumerates menu display policies.                            |
| [ArkUI_TextMenuItemId](#arkui_textmenuitemid) | ArkUI_TextMenuItemId | Enumerates the IDs of text menu items.|
| [ArkUI_TextSpanType](#arkui_textspantype) | ArkUI_TextSpanType | Enumerates the text recognition types of a custom text selection menu.|
| [ArkUI_TextResponseType](#arkui_textresponsetype) | ArkUI_TextResponseType | Enumerates the response types of a custom text selection menu.|
| [ArkUI_LayoutSafeAreaType](#arkui_layoutsafeareatype)               | ArkUI_LayoutSafeAreaType         | Enumerates the types of expanded safe areas.                        |
| [ArkUI_LayoutSafeAreaEdge](#arkui_layoutsafeareaedge)               | ArkUI_LayoutSafeAreaEdge         | Enumerates the edges for expanding the safe area.                        |
| [ArkUI_LocalizedAlignment](#arkui_localizedalignment)               | ArkUI_LocalizedAlignment         | Defines the alignment rules of child components in the **Stack** container.                        |
| [ArkUI_RenderStrategy](#arkui_renderstrategy)                       | ArkUI_RenderStrategy             | Defines rendering strategies for drawing rounded corners.               |
| [ArkUI_MarqueeStartPolicy](#arkui_marqueestartpolicy)| ArkUI_MarqueeStartPolicy| Defines the start policy of a marquee.|
| [ArkUI_MarqueeUpdatePolicy](#arkui_marqueeupdatepolicy)| ArkUI_MarqueeUpdatePolicy| Defines the update policy of a marquee.|
| [OH_ArkUI_HapticFeedbackMode](#oh_arkui_hapticfeedbackmode) | OH_ArkUI_HapticFeedbackMode | Enumerates vibration effect types.|
| [OH_ArkUI_TextEditorSpanType](#oh_arkui_texteditorspantype) | OH_ArkUI_TextEditorSpanType | Enumerates the span types of a custom text selection menu.|
| [OH_ArkUI_TextEditorResponseType](#oh_arkui_texteditorresponsetype) | OH_ArkUI_TextEditorResponseType | Enumerates the response types of a custom text selection menu.|
| [OH_ArkUI_TextMenuType](#oh_arkui_textmenutype) | OH_ArkUI_TextMenuType | Enumerates text menu types.|
| [OH_ArkUI_LineBreakStrategy](#oh_arkui_linebreakstrategy) | OH_ArkUI_LineBreakStrategy | Enumerates line break policies.|
| [ArkUI_RawInputEventType](#arkui_rawinputeventtype) | ArkUI_RawInputEventType | Enumerates the types of raw input events.|
| [OH_ArkUI_CrossLanguageOperatingStatus](#oh_arkui_crosslanguageoperatingstatus) | OH_ArkUI_CrossLanguageOperatingStatus | Enumerates the node tree operation states of cross-language configuration options.|
| [OH_ArkUI_NodeMountPolicy](#oh_arkui_nodemountpolicy) | OH_ArkUI_NodeMountPolicy | Enumerates the child node mounting policy types.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()](#oh_arkui_layoutconstraint_create) | - | Creates layout constraints.|
| [ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_copy) | - | Performs a deep copy of a layout constraint.|
| [void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_dispose) | - | Disposes of a layout constraint pointer.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxwidth) | - | Obtains the maximum width using a layout constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminwidth) | - | Obtains the minimum width using a layout constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getmaxheight) | - | Obtains the maximum height using a layout constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getminheight) | - | Obtains the minimum height using a layout constraint, in px.|
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferencewidth) | - | Obtains the width percentage reference using a layout constraint.|
| [int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)](#oh_arkui_layoutconstraint_getpercentreferenceheight) | - | Obtains the height percentage reference using a layout constraint.|
| [void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxwidth) | - | Sets the maximum width.|
| [void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminwidth) | - | Sets the minimum width.|
| [void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setmaxheight) | - | Sets the maximum height.|
| [void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setminheight) | - | Sets the minimum height.|
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferencewidth) | - | Sets the width percentage reference.|
| [void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)](#oh_arkui_layoutconstraint_setpercentreferenceheight) | - | Sets the height percentage reference.|
| [void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getcanvas) | - | Obtains the pointer to a canvas for drawing, which can be converted into the **OH_Drawing_Canvas** in the **Drawing** module.|
| [ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)](#oh_arkui_drawcontext_getsize) | - | Obtains the size of a drawing area.|
| [ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()](#oh_arkui_waterflowsectionoption_create) | - | Creates a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_dispose) | - | Disposes of the pointer to a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_SetSize(ArkUI_WaterFlowSectionOption* option, int32_t size)](#oh_arkui_waterflowsectionoption_setsize) | - | Sets the array length for a water flow section configuration.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)](#oh_arkui_waterflowsectionoption_getsize) | - | Obtains the array length for a water flow section configuration.|
| [void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t itemCount)](#oh_arkui_waterflowsectionoption_setitemcount) | - | Sets the number of items in a water flow section.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getitemcount) | - | Obtains the number of items in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index, int32_t crossCount)](#oh_arkui_waterflowsectionoption_setcrosscount) | - | Sets the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow.|
| [int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcrosscount) | - | Obtains the number of columns (in a vertical layout) or rows (in a horizontal layout) of a water flow section.|
| [void OH_ArkUI_WaterFlowSectionOption_SetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float columnGap)](#oh_arkui_waterflowsectionoption_setcolumngap) | - | Sets the gap between columns in the specified water flow section.|
| [float OH_ArkUI_WaterFlowSectionOption_GetColumnGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getcolumngap) | - | Obtains the gap between columns in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index, float rowGap)](#oh_arkui_waterflowsectionoption_setrowgap) | - | Sets the gap between rows in the specified water flow section.|
| [float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getrowgap) | - | Obtains the gap between rows in the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)](#oh_arkui_waterflowsectionoption_setmargin) | - | Sets the margins for the specified water flow section.|
| [ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)](#oh_arkui_waterflowsectionoption_getmargin) | - | Obtains the margins of the water flow section that matches the specified index.|
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex (ArkUI_WaterFlowSectionOption* option, int32_t index, float(\*callback)(int32_t itemIndex))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) | - | Obtains the main axis size of a specified water flow item based on **itemIndex** in the water flow section configuration. To use custom data in the callback, call [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata).|
| [void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData (ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData, float (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata) | - | Obtains the main axis size of a specified water flow item based on **itemIndex** in the water flow section configuration. The difference between this API and [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) is that this API allows you to pass custom data (**userData**) and receive the data in the callback function.|
| [ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)](#oh_arkui_guidelineoption_create) | - | Creates a guideline configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_GuidelineOption_Dispose(ArkUI_GuidelineOption* guideline)](#oh_arkui_guidelineoption_dispose) | - | Disposes of a guideline configuration.|
| [void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)](#oh_arkui_guidelineoption_setid) | - | Sets the ID of a guideline.|
| [void OH_ArkUI_GuidelineOption_SetDirection(ArkUI_GuidelineOption* guideline, ArkUI_Axis value, int32_t index)](#oh_arkui_guidelineoption_setdirection) | - | Sets the direction of a guideline.|
| [void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionstart) | - | Sets the distance between a guideline and the left or top of the container.|
| [void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)](#oh_arkui_guidelineoption_setpositionend) | - | Sets the distance between a guideline and the right or bottom of the container.|
| [const char* OH_ArkUI_GuidelineOption_GetId(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getid) | - | Obtains the ID of a guideline.|
| [ArkUI_Axis OH_ArkUI_GuidelineOption_GetDirection(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getdirection) | - | Obtains the direction of a guideline.|
| [float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionstart) | - | Obtains the distance between a guideline and the left or top of the container.|
| [float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)](#oh_arkui_guidelineoption_getpositionend) | - | Obtains the distance between a guideline and the right or bottom of the container.|
| [ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)](#oh_arkui_barrieroption_create) | - | Creates a barrier configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)](#oh_arkui_barrieroption_dispose) | - | Disposes of a barrier configuration.|
| [void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setid) | - | Sets the ID of a barrier.|
| [void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)](#oh_arkui_barrieroption_setdirection) | - | Sets the direction of a barrier.|
| [void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)](#oh_arkui_barrieroption_setreferencedid) | - | Sets the referenced components of a barrier.|
| [const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getid) | - | Obtains the ID of a barrier.|
| [ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getdirection) | - | Obtains the direction of a barrier.|
| [const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)](#oh_arkui_barrieroption_getreferencedid) | - | Obtains the referenced components of a barrier.|
| [int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)](#oh_arkui_barrieroption_getreferencedidsize) | - | Obtains the number of referenced components of a barrier.|
| [ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()](#oh_arkui_alignmentruleoption_create) | - | Creates an alignment rule configuration for this **RelativeContainer** component.|
| [void OH_ArkUI_AlignmentRuleOption_Dispose(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_dispose) | - | Disposes of an alignment rule configuration of this **RelativeContainer** component.|
| [void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setstart) | - | Sets the left alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setend) | - | Sets the right alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)](#oh_arkui_alignmentruleoption_setcenterhorizontal) | - | Sets the horizontal center alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_settop) | - | Sets the top alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setbottom) | - | Sets the bottom alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)](#oh_arkui_alignmentruleoption_setcentervertical) | - | Sets the vertical center alignment mode of a relative layout.|
| [void OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal(ArkUI_AlignmentRuleOption* option, float horizontal)](#oh_arkui_alignmentruleoption_setbiashorizontal) | - | Sets the bias value of the component in the horizontal direction under the anchor constraints.|
| [void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)](#oh_arkui_alignmentruleoption_setbiasvertical) | - | Sets the bias value of the component in the vertical direction under the anchor constraints.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartid) | - | Obtains the ID of the left alignment anchor component.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getstartalignment) | - | Obtains the left alignment mode.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendid) | - | Obtains the ID of the right alignment anchor component.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getendalignment) | - | Obtains the right alignment mode.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridhorizontal) | - | Obtains the ID of the horizontal center alignment anchor component.|
| [ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmenthorizontal) | - | Obtains the horizontal center alignment mode.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopid) | - | Obtains the ID of the top alignment anchor component.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_gettopalignment) | - | Obtains the top alignment mode.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomid) | - | Obtains the ID of the bottom alignment anchor component.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbottomalignment) | - | Obtains the bottom alignment mode.|
| [const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteridvertical) | - | Obtains the ID of the vertical center alignment anchor component.|
| [ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getcenteralignmentvertical) | - | Obtains the vertical center alignment mode.|
| [float OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiashorizontal) | - | Obtains the bias value in the horizontal direction.|
| [float OH_ArkUI_AlignmentRuleOption_GetBiasVertical(ArkUI_AlignmentRuleOption* option)](#oh_arkui_alignmentruleoption_getbiasvertical) | - | Obtains the bias value in the vertical direction.|
| [void OH_ArkUI_SwiperDigitIndicator_SetFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight fontWeight)](#oh_arkui_swiperdigitindicator_setfontweight) | - | Sets the font weight of the digit-style navigation indicator for the **Swiper** component.|
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getfontweight) | - | Obtains the font weight of the digit-style navigation indicator of the **Swiper** component.|
| [void OH_ArkUI_SwiperDigitIndicator_SetSelectedFontWeight(ArkUI_SwiperDigitIndicator *indicator, ArkUI_FontWeight selectedFontWeight)](#oh_arkui_swiperdigitindicator_setselectedfontweight) | - | Sets the font weight of the selected digit-style navigation indicator for the **Swiper** component.|
| [ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)](#oh_arkui_swiperdigitindicator_getselectedfontweight) | - | Obtains the font weight of the selected digit-style navigation indicator of the **Swiper** component.|
| [ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()](#oh_arkui_listitemswipeactionitem_create) | - | Creates a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_dispose) | - | Disposes of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)](#oh_arkui_listitemswipeactionitem_setcontent) | - | Sets the layout content for a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)](#oh_arkui_listitemswipeactionitem_setactionareadistance) | - | Sets the swipe distance threshold for deleting the list item.|
| [float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionitem_getactionareadistance) | - | Obtains the swipe distance threshold for deleting the list item.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonenteractionarea) | - | Sets the callback invoked each time the list item enters the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonenteractionareawithuserdata) | - | Sets the callback invoked each time the list item enters the delete area. User-defined data will be passed to the callback event.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonaction) | - | Sets the callback invoked when the list item is deleted while in the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonactionwithuserdata) | - | Sets the callback invoked when the list item is deleted while in the delete area. User-defined data will be passed to the callback event.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (\*callback)())](#oh_arkui_listitemswipeactionitem_setonexitactionarea) | - | Sets the callback invoked each time the list item exits the delete area.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(void* userData))](#oh_arkui_listitemswipeactionitem_setonexitactionareawithuserdata) | - | Sets the callback invoked each time the list item exits the delete area. User-defined data will be passed to the callback event.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange (ArkUI_ListItemSwipeActionItem* item,void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState))](#oh_arkui_listitemswipeactionitem_setonstatechange) | - | Sets the callback invoked when the swipe state of the list item changes.|
| [void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData (ArkUI_ListItemSwipeActionItem* item,void* userData, void (\*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))](#oh_arkui_listitemswipeactionitem_setonstatechangewithuserdata) | - | Sets the callback invoked when the swipe state of the list item changes. User-defined data will be passed to the callback event.|
| [ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()](#oh_arkui_listitemswipeactionoption_create) | - | Creates a **ListItemSwipeActionOption** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_dispose) | - | Disposes of a **ListItemSwipeActionOption** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setstart) | - | Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)](#oh_arkui_listitemswipeactionoption_setend) | - | Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeEdgeEffect edgeEffect)](#oh_arkui_listitemswipeactionoption_setedgeeffect) | - | Sets the effect used when the scroll boundary is reached.|
| [int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)](#oh_arkui_listitemswipeactionoption_getedgeeffect) | - | Obtains the effect used when the scroll boundary is reached.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option, void (\*callback)(float offset))](#oh_arkui_listitemswipeactionoption_setonoffsetchange) | - | Sets the callback invoked when the scroll offset changes.|
| [void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData (ArkUI_ListItemSwipeActionOption* option, void* userData, void (\*callback)(float offset, void* userData))](#oh_arkui_listitemswipeactionoption_setonoffsetchangewithuserdata) | - | Sets the callback invoked when the scroll offset changes. User-defined data will be passed to the callback event.|
| [int32_t OH_ArkUI_ListItemSwipeAction_Expand(ArkUI_NodeHandle node, ArkUI_ListItemSwipeActionDirection direction)](#oh_arkui_listitemswipeaction_expand) | - |  Expands the swipe action menu for the specified list item.|
| [int32_t OH_ArkUI_ListItemSwipeAction_Collapse(ArkUI_NodeHandle node)](#oh_arkui_listitemswipeaction_collapse) | - |  Collapses the swipe action menu for the specified list item.|
| [ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)](#oh_arkui_accessibilitystate_create) | - | Creates an accessibility state.|
| [void OH_ArkUI_AccessibilityState_Dispose(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_dispose) | - | Disposes of the pointer to an accessibility state.|
| [void OH_ArkUI_AccessibilityState_SetDisabled(ArkUI_AccessibilityState* state, int32_t isDisabled)](#oh_arkui_accessibilitystate_setdisabled) | - | Sets whether an accessibility state is disabled.|
| [int32_t OH_ArkUI_AccessibilityState_IsDisabled(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isdisabled) | - | Obtains whether an accessibility state is disabled.|
| [void OH_ArkUI_AccessibilityState_SetSelected(ArkUI_AccessibilityState* state, int32_t isSelected)](#oh_arkui_accessibilitystate_setselected) | - | Sets whether an accessibility state is selected.|
| [int32_t OH_ArkUI_AccessibilityState_IsSelected(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_isselected) | - | Obtains whether an accessibility state is selected.|
| [void OH_ArkUI_AccessibilityState_SetCheckedState(ArkUI_AccessibilityState* state, int32_t checkedState)](#oh_arkui_accessibilitystate_setcheckedstate) | - | Sets the check box state of an accessibility state.|
| [int32_t OH_ArkUI_AccessibilityState_GetCheckedState(ArkUI_AccessibilityState* state)](#oh_arkui_accessibilitystate_getcheckedstate) | - | Obtains the check box state of an accessibility state.|
| [ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)](#oh_arkui_accessibilityvalue_create) | - | Creates an **AccessibilityValue** instance.|
| [void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_dispose) | - | Disposes of the pointer to an **AccessibilityValue** instance.|
| [void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)](#oh_arkui_accessibilityvalue_setmin) | - | Sets the minimum accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmin) | - | Obtains the minimum accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)](#oh_arkui_accessibilityvalue_setmax) | - | Sets the maximum accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getmax) | - | Obtains the maximum accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)](#oh_arkui_accessibilityvalue_setcurrent) | - | Sets the current accessibility value.|
| [int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getcurrent) | - | Obtains the current accessibility value.|
| [void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)](#oh_arkui_accessibilityvalue_setrangemin) | - | Sets the minimum value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMin(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemin) | - | Obtains the minimum value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetRangeMax(ArkUI_AccessibilityValue* value, int32_t rangeMax)](#oh_arkui_accessibilityvalue_setrangemax) | - | Sets the maximum value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeMax(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangemax) | - | Obtains the maximum value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)](#oh_arkui_accessibilityvalue_setrangecurrent) | - | Sets the current value for accessibility information of the range-based component.|
| [int32_t OH_ArkUI_AccessibilityValue_GetRangeCurrent(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_getrangecurrent) | - | Obtains the current value for accessibility information of the range-based component.|
| [void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)](#oh_arkui_accessibilityvalue_settext) | - | Sets the text description of an **AccessibilityValue** instance.|
| [const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)](#oh_arkui_accessibilityvalue_gettext) | - | Obtains the text description of an **AccessibilityValue** instance.|
| [ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()](#oh_arkui_listchildrenmainsizeoption_create) | - | Creates a **ListChildrenMainSize** instance.|
| [void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_dispose) | - | Disposes of a **ListChildrenMainSize** instance.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)](#oh_arkui_listchildrenmainsizeoption_setdefaultmainsize) | - | Sets the default size of the list item in the **List** component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.|
| [float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)](#oh_arkui_listchildrenmainsizeoption_getdefaultmainsize) | - | Obtains the default size of the list item in the **List** component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.|
| [void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)](#oh_arkui_listchildrenmainsizeoption_resize) | - | Adjusts the capacity of the children item size array in the **List** component along the main axis.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)](#oh_arkui_listchildrenmainsizeoption_splice) | - | Adjusts the children item size array in the **List** component along the main axis.|
| [int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)](#oh_arkui_listchildrenmainsizeoption_updatesize) | - | Updates the size at the specified index in the child item size array of the **List** component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.|
| [float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)](#oh_arkui_listchildrenmainsizeoption_getmainsize) | - | Obtains the size at the specified index in the child item size array of the **List** component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.|
| [ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)](#oh_arkui_customspanmeasureinfo_create) | - | Creates measurement information for this custom span.|
| [void OH_ArkUI_CustomSpanMeasureInfo_Dispose(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_dispose) | - | Disposes of measurement information of a custom span.|
| [float OH_ArkUI_CustomSpanMeasureInfo_GetFontSize(ArkUI_CustomSpanMeasureInfo* info)](#oh_arkui_customspanmeasureinfo_getfontsize) | - | Obtains the font size of the parent text node of a custom span.|
| [ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)](#oh_arkui_customspanmetrics_create) | - | Creates measurement metrics for this custom span.|
| [void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)](#oh_arkui_customspanmetrics_dispose) | - | Disposes of measurement metrics of this custom span.|
| [int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)](#oh_arkui_customspanmetrics_setwidth) | - | Sets the width for a custom span.|
| [int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)](#oh_arkui_customspanmetrics_setheight) | - | Sets the height for a custom span.|
| [ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)](#oh_arkui_customspandrawinfo_create) | - | Creates drawing information for this custom span.|
| [void OH_ArkUI_CustomSpanDrawInfo_Dispose(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_dispose) | - | Disposes of drawing information for this custom span.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetXOffset(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getxoffset) | - | Obtains the x-axis offset of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineTop(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinetop) | - | Obtains the top margin of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetLineBottom(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getlinebottom) | - | Obtains the bottom margin of the custom span relative to the mounted component.|
| [float OH_ArkUI_CustomSpanDrawInfo_GetBaseline(ArkUI_CustomSpanDrawInfo* info)](#oh_arkui_customspandrawinfo_getbaseline) | - | Obtains the baseline offset of the custom span relative to the mounted component.|
| [void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_destroy) | - | Destroys a **CustomProperty** instance.|
| [const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_getstringvalue) | - | Obtains the value of a custom property.|
| [const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_getname) | - | Obtains the window name from a **HostWindowInfo** object.|
| [void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_destroy) | - | Destroys a **HostWindowInfo** object.|
| [void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_destroy) | - | Destroys an **ActiveChildrenInfo** instance.|
| [ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)](#oh_arkui_activechildreninfo_getnodebyindex) | - | Obtains the child node at the specified index in the specified **ActiveChildrenInfo** instance.|
| [int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_getcount) | - | Obtains the number of nodes in the specified **ActiveChildrenInfo** instance.|
| [ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)](#oh_arkui_progresslinearstyleoption_create) | - | Creates a **ProgressLinearStyleOption** instance.|
| [void OH_ArkUI_ProgressLinearStyleOption_Destroy(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_destroy) | - | Destroys a **ProgressLinearStyleOption** instance.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setsmootheffectenabled) | - | Sets whether to enable the smooth progress effect.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)](#oh_arkui_progresslinearstyleoption_setscaneffectenabled) | - | Sets whether to enable the scan effect.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth(ArkUI_ProgressLinearStyleOption* option, float strokeWidth)](#oh_arkui_progresslinearstyleoption_setstrokewidth) | - | Sets the width of the progress indicator.|
| [void OH_ArkUI_ProgressLinearStyleOption_SetStrokeRadius(ArkUI_ProgressLinearStyleOption* option, float strokeRadius)](#oh_arkui_progresslinearstyleoption_setstrokeradius) | - | Sets the corner radius of the progress indicator.|
| [bool OH_ArkUI_ProgressLinearStyleOption_GetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getsmootheffectenabled) | - | Obtains the enabled status of the smooth progress effect.|
| [bool OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getscaneffectenabled) | - | Obtains the enabled status of the scan effect.|
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokewidth) | - | Obtains the stroke width of the progress indicator.|
| [float OH_ArkUI_ProgressLinearStyleOption_GetStrokeRadius(ArkUI_ProgressLinearStyleOption* option)](#oh_arkui_progresslinearstyleoption_getstrokeradius) | - | Obtains the corner radius of the progress indicator.|
| [ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)](#oh_arkui_crosslanguageoption_create) | - | Creates an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_destroy) | - | Destroys an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)](#oh_arkui_crosslanguageoption_setattributesettingstatus) | - | Sets whether cross-language attribute setting is allowed in the configuration option.|
| [bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_getattributesettingstatus) | - | Checks whether cross-language attribute setting is allowed in the configuration option.|
| [void OH_ArkUI_CrossLanguageOption_SetTreeOperatingStatus(ArkUI_CrossLanguageOption* option, OH_ArkUI_CrossLanguageOperatingStatus status)](#oh_arkui_crosslanguageoption_settreeoperatingstatus) | - | Sets the node tree operation state of a cross-language configuration option.|
| [OH_ArkUI_CrossLanguageOperatingStatus OH_ArkUI_CrossLanguageOption_GetTreeOperatingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_gettreeoperatingstatus) | - | Obtains the node tree operation state of a cross-language configuration option.|
| [ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Create()](#oh_arkui_positionedges_create) | - | Creates a **PositionEdges** object.|
| [ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Copy(const ArkUI_PositionEdges* edges)](#oh_arkui_positionedges_copy) | - | Deeply copies a **PositionEdges** attribute object.|
| [void OH_ArkUI_PositionEdges_Dispose(ArkUI_PositionEdges* edges)](#oh_arkui_positionedges_dispose) | - | Disposes of the **PositionEdges** object.|
| [void OH_ArkUI_PositionEdges_SetTop(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_settop) | - | Sets the value of the **PositionEdges** object in the top direction.|
| [int32_t OH_ArkUI_PositionEdges_GetTop(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_gettop) | - | Obtains the value of the **PositionEdges** object in the top direction.|
| [void OH_ArkUI_PositionEdges_SetLeft(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setleft) | - | Sets the value of the **PositionEdges** object in the left direction.|
| [int32_t OH_ArkUI_PositionEdges_GetLeft(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getleft) | - | Obtains the value of the **PositionEdges** object in the left direction.|
| [void OH_ArkUI_PositionEdges_SetBottom(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setbottom) | - | Sets the value of the **PositionEdges** object in the bottom direction.|
| [int32_t OH_ArkUI_PositionEdges_GetBottom(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getbottom) | - | Obtains the value of the **PositionEdges** object in the bottom direction.|
| [void OH_ArkUI_PositionEdges_SetRight(ArkUI_PositionEdges* edges, float value)](#oh_arkui_positionedges_setright) | - | Sets the value of the **PositionEdges** object in the right direction.|
| [int32_t OH_ArkUI_PositionEdges_GetRight(ArkUI_PositionEdges* edges, float* value)](#oh_arkui_positionedges_getright) | - | Obtains the value of the **PositionEdges** object in the right direction.|
| [ArkUI_PixelRoundPolicy* OH_ArkUI_PixelRoundPolicy_Create()](#oh_arkui_pixelroundpolicy_create) | - | Creates a **PixelRoundPolicy** attribute object.|
| [void OH_ArkUI_PixelRoundPolicy_Dispose(ArkUI_PixelRoundPolicy* policy)](#oh_arkui_pixelroundpolicy_dispose) | - | Disposes of the **PixelRoundPolicy** object.|
| [void OH_ArkUI_PixelRoundPolicy_SetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_settop) | - | Sets the top edge pixel rounding policy for the **PixelRoundPolicy** object.|
| [int32_t OH_ArkUI_PixelRoundPolicy_GetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_gettop) | - | Obtains the top edge pixel rounding policy from the **PixelRoundPolicy** object.|
| [void OH_ArkUI_PixelRoundPolicy_SetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setstart) | - | Sets the start edge pixel rounding policy for the **PixelRoundPolicy** object.|
| [int32_t OH_ArkUI_PixelRoundPolicy_GetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getstart) | - | Obtains the start edge pixel rounding policy from the **PixelRoundPolicy** object. |
| [void OH_ArkUI_PixelRoundPolicy_SetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setbottom) | - | Sets the bottom edge pixel rounding policy for the **PixelRoundPolicy** object.|
| [int32_t OH_ArkUI_PixelRoundPolicy_GetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getbottom) | - | Obtains the bottom edge pixel rounding policy from the **PixelRoundPolicy** object.|
| [void OH_ArkUI_PixelRoundPolicy_SetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)](#oh_arkui_pixelroundpolicy_setend) | - | Sets the end edge pixel rounding policy for the **PixelRoundPolicy** object.|
| [int32_t OH_ArkUI_PixelRoundPolicy_GetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)](#oh_arkui_pixelroundpolicy_getend) | - | Obtains the end edge pixel rounding policy from the **PixelRoundPolicy** object.|
| [ArkUI_ContentTransitionEffect* OH_ArkUI_ContentTransitionEffect_Create(int32_t type)](#oh_arkui_contenttransitioneffect_create) | - | Creates a **ContentTransitionEffect** attribute object.|
| [ArkUI_GridLayoutOptions* OH_ArkUI_GridLayoutOptions_Create()](#oh_arkui_gridlayoutoptions_create) | - | Creates **Grid** layout options.|
| [void OH_ArkUI_GridLayoutOptions_Dispose(ArkUI_GridLayoutOptions* option)](#oh_arkui_gridlayoutoptions_dispose) | - | Disposes of the **Grid** layout option.|
| [int32_t OH_ArkUI_GridLayoutOptions_SetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t size)](#oh_arkui_gridlayoutoptions_setirregularindexes) | - | Sets the irregular grid item index array for the grid layout.|
| [int32_t OH_ArkUI_GridLayoutOptions_GetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t* size)](#oh_arkui_gridlayoutoptions_getirregularindexes) | - | Obtains the irregular grid item index array for the grid layout. When **OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback** is not set, the grid item specified in this parameter occupies an entire row of the grid that scrolls vertically or an entire column of the grid that scrolls horizontally.|
| [void OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemSize(\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_gridlayoutoptions_registergetirregularsizebyindexcallback) | - | Registers a callback to obtain the row and column span for the grid item at the specified index.|
| [void OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemRect (\*callback)(int32_t itemIndex, void* userData))](#oh_arkui_gridlayoutoptions_registergetrectbyindexcallback) | - | Registers a callback to obtain the starting row, starting column, row span, and column span for the grid item at the specified index.|
| [ArkUI_SelectionOptions OH_ArkUI_SelectionOptions_Create()](#oh_arkui_selectionoptions_create) | - | Creates a selection option.|
| [void OH_ArkUI_SelectionOptions_Dispose(ArkUI_SelectionOptions* options)](#oh_arkui_selectionoptions_dispose) | - | Releases a selection option object.|
| [void OH_ArkUI_SelectionOptions_SetMenuPolicy(ArkUI_SelectionOptions* options, ArkUI_MenuPolicy menuPolicy)](#oh_arkui_selectionoptions_setmenupolicy) | - | Sets the menu pop-up policy for selection options.|
| [ArkUI_MenuPolicy OH_ArkUI_SelectionOptions_GetMenuPolicy(ArkUI_SelectionOptions* options)](#oh_arkui_selectionoptions_getmenupolicy) | - | Obtains the menu pop-up policy for selection options.|
| [ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()](#oh_arkui_textcontentbasecontroller_create) | - | Creates a basic controller object for text content.|
| [void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_dispose) | - | Destroys a basic controller object for text content.|
| [void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)](#oh_arkui_textcontentbasecontroller_deletebackward) | - | Deletes the character before the cursor in editing state; deletes the last character of the text box component in other states.|
| [void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)](#oh_arkui_textcontentbasecontroller_scrolltovisible) | - | Passes the start and end indexes to the bound text box component, and scrolls the text within the range to the visible area.|
| [ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()](#oh_arkui_textmenuitem_create) | - | Creates a text menu item object.|
| [void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)](#oh_arkui_textmenuitem_dispose) | - | Releases a text menu item object.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetContent(ArkUI_TextMenuItem* item, const char* content)](#oh_arkui_textmenuitem_setcontent) | - | Sets the title of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetContent(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textmenuitem_getcontent) | - | Obtains the title of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetIcon(ArkUI_TextMenuItem* item, const char* icon)](#oh_arkui_textmenuitem_seticon) | - | Sets the icon path of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetIcon(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textmenuitem_geticon) | - | Obtains the icon path of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetLabelInfo(ArkUI_TextMenuItem* item, const char* labelInfo)](#oh_arkui_textmenuitem_setlabelinfo) | - | Sets the shortcut hint for a text menu item, for example, the shortcut hint for the **Copy** menu item can be set to **Ctrl+C**.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetLabelInfo(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textmenuitem_getlabelinfo) | - | Obtains the shortcut hint for a text menu item, for example, the shortcut hint for the **Copy** menu item is typically **Ctrl+C**.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetId(ArkUI_TextMenuItem* item, int32_t id)](#oh_arkui_textmenuitem_setid) | - | Sets the ID of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetId(const ArkUI_TextMenuItem* item, int32_t* id)](#oh_arkui_textmenuitem_getid) | - | Obtains the ID of a text menu item.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetSize(ArkUI_TextMenuItemArray* items, int32_t* size)](#oh_arkui_textmenuitemarray_getsize) | - | Obtains the size of the text menu item array.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetItem(ArkUI_TextMenuItemArray* items, int32_t index, ArkUI_TextMenuItem** item)](#oh_arkui_textmenuitemarray_getitem) | - | Obtains the text menu item at a specified index from the text menu item array.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Insert(ArkUI_TextMenuItemArray* items, ArkUI_TextMenuItem* item, int32_t index)](#oh_arkui_textmenuitemarray_insert) | - | Inserts a text menu item at a specified index into the text menu item array.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Erase(ArkUI_TextMenuItemArray* items, int32_t index)](#oh_arkui_textmenuitemarray_erase) | - | Deletes the text menu item at a specified index from the text menu item array.|
| [ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Clear(ArkUI_TextMenuItemArray* items)](#oh_arkui_textmenuitemarray_clear) | - | Clears all text menu items in the text menu item array.|
| [ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()](#oh_arkui_texteditmenuoptions_create) | - | Creates a text menu extension object.|
| [void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)](#oh_arkui_texteditmenuoptions_dispose) | - | Releases a text menu extension object.|
| [typedef void (\*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textcreatemenucallback) | ArkUI_TextCreateMenuCallback | Callback for the text menu creation event. This callback is triggered when a text menu is created, allowing you to set menu data in it.|
| [typedef void (\*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)](#arkui_textpreparemenucallback) | ArkUI_TextPrepareMenuCallback | Callback for the text menu preparation event. This callback is called when the text selection area changes and before the menu is displayed, allowing you to set menu data in it.|
| [typedef bool (\*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item,int32_t start, int32_t end, void* userData)](#arkui_textmenuitemclickcallback) | ArkUI_TextMenuItemClickCallback | Callback for the text menu item click event. This callback is called when a menu item is clicked. You can intercept the default processing behavior in this callback.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnCreateMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextCreateMenuCallback cb)](#oh_arkui_texteditmenuoptions_registeroncreatemenucallback) | - | Registers the callback for creating text menus.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnPrepareMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextPrepareMenuCallback cb)](#oh_arkui_texteditmenuoptions_registeronpreparemenucallback) | - | Registers the callback for preparing text menus.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnMenuItemClickCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextMenuItemClickCallback cb)](#oh_arkui_texteditmenuoptions_registeronmenuitemclickcallback) | - | Registers the callback for text menu item clicks.|
| [ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create()](#oh_arkui_textselectionmenuoptions_create) | - | Creates a custom text selection menu object.|
| [void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)](#oh_arkui_textselectionmenuoptions_dispose) | - | Releases a custom text selection menu object.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType textSpanType)](#oh_arkui_textselectionmenuoptions_setspantype) | - | Sets the text recognition type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType* spanType)](#oh_arkui_textselectionmenuoptions_getspantype) | - | Obtains the text recognition type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle node)](#oh_arkui_textselectionmenuoptions_setcontentnode) | - | Sets the content node of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle* node)](#oh_arkui_textselectionmenuoptions_getcontentnode) | - | Obtains the content node of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType responseType)](#oh_arkui_textselectionmenuoptions_setresponsetype) | - | Sets the response type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType* responseType)](#oh_arkui_textselectionmenuoptions_getresponsetype) | - | Obtains the response type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (\*callback)(int32_t start, int32_t end, void* userData))](#oh_arkui_textselectionmenuoptions_registeronmenushowcallback) | - | Registers the callback for the event of showing a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (\*callback)(int32_t start, int32_t end, void* userData))](#oh_arkui_textselectionmenuoptions_registeronmenuhidecallback) | - | Registers the callback for the event of hiding a custom text selection menu.|
| [ArkUI_TextMarqueeOptions* OH_ArkUI_TextMarqueeOptions_Create()](#oh_arkui_textmarqueeoptions_create) | - | Creates text marquee options.|
| [void OH_ArkUI_TextMarqueeOptions_Dispose(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_dispose) | - | Destroys the pointer to the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetStart(ArkUI_TextMarqueeOptions* option, bool start)](#oh_arkui_textmarqueeoptions_setstart) | - | Sets whether to play the text marquee option.|
| [bool OH_ArkUI_TextMarqueeOptions_GetStart(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getstart) | - | Obtains whether the text marquee option is played.|
| [void OH_ArkUI_TextMarqueeOptions_SetStep(ArkUI_TextMarqueeOptions* option, float step)](#oh_arkui_textmarqueeoptions_setstep) | - | Sets the step of the text marquee option.|
| [float OH_ArkUI_TextMarqueeOptions_GetStep(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getstep) | - | Obtains the step of the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetSpacing(ArkUI_TextMarqueeOptions* option, float spacing)](#oh_arkui_textmarqueeoptions_setspacing) | - | Sets the distance between the start and end items of the text marquee option.|
| [float OH_ArkUI_TextMarqueeOptions_GetSpacing(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getspacing) | - | Obtains the distance between the start and end items of the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetLoop(ArkUI_TextMarqueeOptions* option, int32_t loop)](#oh_arkui_textmarqueeoptions_setloop) | - | Sets the number of repetitions for looping the text marquee option. The value **0** or negative value indicates infinite looping.|
| [int32_t OH_ArkUI_TextMarqueeOptions_GetLoop(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getloop) | - | Obtains the number of repetitions for looping the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetFromStart(ArkUI_TextMarqueeOptions* option, bool fromStart)](#oh_arkui_textmarqueeoptions_setfromstart) | - | Sets the scrolling direction for looping the text marquee option.|
| [bool OH_ArkUI_TextMarqueeOptions_GetFromStart(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getfromstart) | - | Obtains the scrolling direction for looping the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetDelay(ArkUI_TextMarqueeOptions* option, int32_t delay)](#oh_arkui_textmarqueeoptions_setdelay) | - | Sets the delay of each loop for the text marquee option.|
| [int32_t OH_ArkUI_TextMarqueeOptions_GetDelay(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getdelay) | - | Obtains the delay of each loop for the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetFadeout(ArkUI_TextMarqueeOptions* option, bool fadeout)](#oh_arkui_textmarqueeoptions_setfadeout) | - | Sets whether the text marquee option supports a fade-out effect when the text is too long. When supported, if the text content exceeds the display range, the edges of the partially visible text will have a fade-out effect applied. If both ends have partially visible text, both ends will have the fade-out effect applied. When the fade-out effect is enabled, the **NODE_CLIP** attribute in [ArkUI_NodeAttributeType](./capi-native-node-h.md#arkui_nodeattributetype) is automatically locked to **true** and cannot be set to **false**.|
| [bool OH_ArkUI_TextMarqueeOptions_GetFadeout(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getfadeout) | - | Obtains whether the text marquee option supports a fade-out effect when the text is too long.|
| [void OH_ArkUI_TextMarqueeOptions_SetStartPolicy(ArkUI_TextMarqueeOptions* option, ArkUI_MarqueeStartPolicy startPolicy)](#oh_arkui_textmarqueeoptions_setstartpolicy) | - | Sets the startup policy of the text marquee option.|
| [ArkUI_MarqueeStartPolicy OH_ArkUI_TextMarqueeOptions_GetStartPolicy(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getstartpolicy) | - | Obtains the startup policy of the text marquee option.|
| [void OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy(ArkUI_TextMarqueeOptions* option, ArkUI_MarqueeUpdatePolicy updatePolicy)](#oh_arkui_textmarqueeoptions_setupdatepolicy) | - | Sets the update policy of the text marquee option.|
| [ArkUI_MarqueeUpdatePolicy OH_ArkUI_TextMarqueeOptions_GetUpdatePolicy(ArkUI_TextMarqueeOptions* option)](#oh_arkui_textmarqueeoptions_getupdatepolicy) | - | Obtains the update policy of the text marquee option.|
| [ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorBackground* background)](#oh_arkui_pickerindicatorstyle_configurebackground) | - | Sets the background style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_BACKGROUND](capi-picker-h.md#arkui_pickerindicatortype).|
| [ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorDivider* divider)](#oh_arkui_pickerindicatorstyle_configuredivider) | - | Sets the divider style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_DIVIDER](capi-picker-h.md#arkui_pickerindicatortype).|
| [OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()](#oh_arkui_decorationstyleoptions_create) | - | Creates a decorative line style object. When the object is no longer used, call [OH_ArkUI_DecorationStyleOptions_Destroy](capi-native-type-h.md#oh_arkui_decorationstyleoptions_destroy) to destroy it.|
| [void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)](#oh_arkui_decorationstyleoptions_destroy) | - | Destroys the decorative line style object.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType type)](#oh_arkui_decorationstyleoptions_settextdecorationtype) | - | Sets the decoration type of the decorative line style.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType* type)](#oh_arkui_decorationstyleoptions_gettextdecorationtype) | - | Obtains the decoration type of the decorative line style.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t color)](#oh_arkui_decorationstyleoptions_setcolor) | - | Sets the color of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t* color)](#oh_arkui_decorationstyleoptions_getcolor) | - | Obtains the color of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle style)](#oh_arkui_decorationstyleoptions_settextdecorationstyle) | - | Sets the style of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle* style)](#oh_arkui_decorationstyleoptions_gettextdecorationstyle) | - | Obtains the style of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float thicknessScale)](#oh_arkui_decorationstyleoptions_setthicknessscale) | - | Sets the scale factor of the decorative line thickness.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float* thicknessScale)](#oh_arkui_decorationstyleoptions_getthicknessscale) | - | Obtains the scale factor of the decorative line thickness.|
| [OH_ArkUI_TextDataDetectorConfig* OH_ArkUI_TextDataDetectorConfig_Create()](#oh_arkui_textdatadetectorconfig_create) | - | Creates a text entity recognition configuration object. When the object is no longer used, call [OH_ArkUI_TextDataDetectorConfig_Destroy](capi-native-type-h.md#oh_arkui_textdatadetectorconfig_destroy) to destroy it.|
| [void OH_ArkUI_TextDataDetectorConfig_Destroy(OH_ArkUI_TextDataDetectorConfig* config)](#oh_arkui_textdatadetectorconfig_destroy) | - | Destroys the text entity recognition configuration object.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetTypes(OH_ArkUI_TextDataDetectorConfig* config, const ArkUI_TextDataDetectorType* types, int32_t length)](#oh_arkui_textdatadetectorconfig_settypes) | - | Sets the types of the text entity recognition configuration.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetTypes(OH_ArkUI_TextDataDetectorConfig* config, ArkUI_TextDataDetectorType* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textdatadetectorconfig_gettypes) | - | Obtains the types of the text entity recognition configuration.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback(OH_ArkUI_TextDataDetectorConfig* config, void* userData, void (\*callback)(const char* result, int32_t length, void* userData))](#oh_arkui_textdatadetectorconfig_registerondetectresultupdatecallback) | - | Sets the callback for text entity recognition result updates.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t color)](#oh_arkui_textdatadetectorconfig_setcolor) | - | Sets the color of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t* color)](#oh_arkui_textdatadetectorconfig_getcolor) | - | Obtains the color of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)](#oh_arkui_textdatadetectorconfig_setdecorationstyleoptions) | - | Sets the decoration style of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)](#oh_arkui_textdatadetectorconfig_getdecorationstyleoptions) | - | Obtains the decoration style of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool enablePreviewMenu)](#oh_arkui_textdatadetectorconfig_setenablepreviewmenu) | - | Sets whether to display the preview menu when the recognized content is long-pressed.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool* enablePreviewMenu)](#oh_arkui_textdatadetectorconfig_getenablepreviewmenu) | - | Obtains whether the preview menu is displayed when the recognized content is long-pressed.|
| [OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()](#oh_arkui_texteditorplaceholderoptions_create) | - | Creates an option object for the placeholder text used when there is no input. When the object is no longer used, call [OH_ArkUI_TextEditorPlaceholderOptions_Destroy](capi-native-type-h.md#oh_arkui_texteditorplaceholderoptions_destroy) to destroy it.|
| [void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)](#oh_arkui_texteditorplaceholderoptions_destroy) | - | Destroys the option object for the placeholder text used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetValue(OH_ArkUI_TextEditorPlaceholderOptions* options, const char* value)](#oh_arkui_texteditorplaceholderoptions_setvalue) | - | Sets the text for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetValue(OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditorplaceholderoptions_getvalue) | - | Obtains the text for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontSize(OH_ArkUI_TextEditorPlaceholderOptions* options, float fontSize)](#oh_arkui_texteditorplaceholderoptions_setfontsize) | - | Sets the font size for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontSize(OH_ArkUI_TextEditorPlaceholderOptions* options, float* fontSize)](#oh_arkui_texteditorplaceholderoptions_getfontsize) | - | Obtains the font size for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontWeight(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontWeight)](#oh_arkui_texteditorplaceholderoptions_setfontweight) | - | Sets the font weight for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontWeight(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t* fontWeight)](#oh_arkui_texteditorplaceholderoptions_getfontweight) | - | Obtains the font weight for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontFamily(OH_ArkUI_TextEditorPlaceholderOptions* options, const char* fontFamily)](#oh_arkui_texteditorplaceholderoptions_setfontfamily) | - | Sets the font family for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontFamily(OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditorplaceholderoptions_getfontfamily) | - | Obtains the font family for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontStyle(OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle fontStyle)](#oh_arkui_texteditorplaceholderoptions_setfontstyle) | - | Sets the font style for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontStyle(OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle* fontStyle)](#oh_arkui_texteditorplaceholderoptions_getfontstyle) | - | Obtains the font style for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontColor(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontColor)](#oh_arkui_texteditorplaceholderoptions_setfontcolor) | - | Sets the font color for the placeholder text options used when there is no input.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontColor(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t* fontColor)](#oh_arkui_texteditorplaceholderoptions_getfontcolor) | - | Obtains the font color for the placeholder text options used when there is no input.|
| [OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()](#oh_arkui_texteditorstyledstringcontroller_create) | - | Creates a styled string controller object for the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorStyledStringController_Destroy](capi-native-type-h.md#oh_arkui_texteditorstyledstringcontroller_destroy) to destroy it.|
| [void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_destroy) | - | Destroys the styled string controller object.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t caretOffset)](#oh_arkui_texteditorstyledstringcontroller_setcaretoffset) | - | Sets the caret offset using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t* caretOffset)](#oh_arkui_texteditorstyledstringcontroller_getcaretoffset) | - | Obtains the caret offset using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetSelection(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t start, uint32_t end, ArkUI_MenuPolicy menuPolicy)](#oh_arkui_texteditorstyledstringcontroller_setselection) | - | Sets the selected area using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_IsEditing(OH_ArkUI_TextEditorStyledStringController* controller, bool* isEditing)](#oh_arkui_texteditorstyledstringcontroller_isediting) | - | Obtains the editing status of the text editor using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_StopEditing(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_stopediting) | - | Exits the editing status of the text editor using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetPreviewText(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* offset, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditorstyledstringcontroller_getpreviewtext) | - | Obtains the preview text using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretRect(OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_Rect* rect)](#oh_arkui_texteditorstyledstringcontroller_getcaretrect) | - | Obtains the caret-selected rectangle using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_DeleteBackward(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_deletebackward) | - | Deletes characters using the styled string controller. If no content is selected, one character before the current caret position is deleted. If content is selected, the selected content is deleted.|
| [OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()](#oh_arkui_texteditorparagraphstyle_create) | - | Creates a paragraph style object for the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorParagraphStyle_Destroy](capi-native-type-h.md#oh_arkui_texteditorparagraphstyle_destroy) to destroy it.|
| [void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)](#oh_arkui_texteditorparagraphstyle_destroy) | - | Destroys the paragraph style object.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment align)](#oh_arkui_texteditorparagraphstyle_settextalign) | - | Sets the text alignment mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment* align)](#oh_arkui_texteditorparagraphstyle_gettextalign) | - | Obtains the text alignment mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginPixelMap(OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative* pixelmap)](#oh_arkui_texteditorparagraphstyle_setleadingmarginpixelmap) | - | Sets the PixelMap for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginPixelMap(OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative** pixelmap)](#oh_arkui_texteditorparagraphstyle_getleadingmarginpixelmap) | - | Obtains the PixelMap for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t width)](#oh_arkui_texteditorparagraphstyle_setleadingmarginwidth) | - | Sets the width for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* width)](#oh_arkui_texteditorparagraphstyle_getleadingmarginwidth) | - | Obtains the width for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t height)](#oh_arkui_texteditorparagraphstyle_setleadingmarginheight) | - | Sets the height for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* height)](#oh_arkui_texteditorparagraphstyle_getleadingmarginheight) | - | Obtains the height for paragraph indentation in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_WordBreak wordBreak)](#oh_arkui_texteditorparagraphstyle_setwordbreak) | - | Sets the word breaking mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_WordBreak* wordBreak)](#oh_arkui_texteditorparagraphstyle_getwordbreak) | - | Obtains the word breaking mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style, OH_ArkUI_LineBreakStrategy lineBreakStrategy)](#oh_arkui_texteditorparagraphstyle_setlinebreakstrategy) | - | Sets the line breaking strategy in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style, OH_ArkUI_LineBreakStrategy* lineBreakStrategy)](#oh_arkui_texteditorparagraphstyle_getlinebreakstrategy) | - | Obtains the line breaking strategy in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t paragraphSpacing)](#oh_arkui_texteditorparagraphstyle_setparagraphspacing) | - | Sets the paragraph spacing in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* paragraphSpacing)](#oh_arkui_texteditorparagraphstyle_getparagraphspacing) | - | Obtains the paragraph spacing in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextVerticalAlignment verticalAlignment)](#oh_arkui_texteditorparagraphstyle_settextverticalalign) | - | Sets the text vertical alignment mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextVerticalAlignment* verticalAlignment)](#oh_arkui_texteditorparagraphstyle_gettextverticalalign) | - | Obtains the text vertical alignment mode in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextDirection textDirection)](#oh_arkui_texteditorparagraphstyle_settextdirection) | - | Sets the text direction in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextDirection* textDirection)](#oh_arkui_texteditorparagraphstyle_gettextdirection) | - | Obtains the text direction in the paragraph style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingParagraphStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorParagraphStyle* style)](#oh_arkui_texteditorstyledstringcontroller_settypingparagraphstyle) | - | Sets the typing paragraph style using the styled string controller.|
| [OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()](#oh_arkui_texteditortextstyle_create) | - | Creates a text style object. When the object is no longer used, call [OH_ArkUI_TextEditorTextStyle_Destroy](capi-native-type-h.md#oh_arkui_texteditortextstyle_destroy) to destroy it.|
| [void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)](#oh_arkui_texteditortextstyle_destroy) | - | Destroys the text style object.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t color)](#oh_arkui_texteditortextstyle_setfontcolor) | - | Sets the font color of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t* color)](#oh_arkui_texteditortextstyle_getfontcolor) | - | Obtains the font color of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontSize(OH_ArkUI_TextEditorTextStyle* style, float size)](#oh_arkui_texteditortextstyle_setfontsize) | - | Sets the font size of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontSize(OH_ArkUI_TextEditorTextStyle* style, float* size)](#oh_arkui_texteditortextstyle_getfontsize) | - | Obtains the font size of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontStyle(OH_ArkUI_TextEditorTextStyle* style, ArkUI_FontStyle fontStyle)](#oh_arkui_texteditortextstyle_setfontstyle) | - | Sets the font style of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontStyle(OH_ArkUI_TextEditorTextStyle* style, ArkUI_FontStyle* fontStyle)](#oh_arkui_texteditortextstyle_getfontstyle) | - | Obtains the font style of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t fontWeight)](#oh_arkui_texteditortextstyle_setfontweight) | - | Sets the font weight of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t* fontWeight)](#oh_arkui_texteditortextstyle_getfontweight) | - | Obtains the font weight of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFamily(OH_ArkUI_TextEditorTextStyle* style, const char* fontFamily)](#oh_arkui_texteditortextstyle_setfontfamily) | - | Sets the font family of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFamily(OH_ArkUI_TextEditorTextStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditortextstyle_getfontfamily) | - | Obtains the font family of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetDecoration(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_DecorationStyleOptions* options)](#oh_arkui_texteditortextstyle_setdecoration) | - | Sets the text decoration options of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetDecoration(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_DecorationStyleOptions* options)](#oh_arkui_texteditortextstyle_getdecoration) | - | Obtains the text decoration options of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextShadows(OH_ArkUI_TextEditorTextStyle* style, const OH_ArkUI_ShadowOptions** options, int32_t length)](#oh_arkui_texteditortextstyle_settextshadows) | - | Sets the text shadow options of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextShadows(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)](#oh_arkui_texteditortextstyle_gettextshadows) | - | Obtains the text shadow options of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t lineHeight)](#oh_arkui_texteditortextstyle_setlineheight) | - | Sets the line height of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t* lineHeight)](#oh_arkui_texteditortextstyle_getlineheight) | - | Obtains the line height of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style, int32_t letterSpacing)](#oh_arkui_texteditortextstyle_setletterspacing) | - | Sets the letter spacing of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style, int32_t* letterSpacing)](#oh_arkui_texteditortextstyle_getletterspacing) | - | Obtains the letter spacing of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFeature(OH_ArkUI_TextEditorTextStyle* style, const char* fontFeature)](#oh_arkui_texteditortextstyle_setfontfeature) | - | Sets the font feature of the text style, such as monospaced digits.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFeature(OH_ArkUI_TextEditorTextStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditortextstyle_getfontfeature) | - | Obtains the font feature of the text style, such as monospaced digits.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool halfLeading)](#oh_arkui_texteditortextstyle_sethalfleading) | - | Sets whether to evenly distribute the line spacing to the top and bottom of each line in the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool* halfLeading)](#oh_arkui_texteditortextstyle_gethalfleading) | - | Obtains whether the line spacing is evenly distributed to the top and bottom of each line in the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t color)](#oh_arkui_texteditortextstyle_settextbackgroundcolor) | - | Sets the text background color of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t* color)](#oh_arkui_texteditortextstyle_gettextbackgroundcolor) | - | Obtains the text background color of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style, float topLeft, float topRight, float bottomLeft, float bottomRight)](#oh_arkui_texteditortextstyle_settextbackgroundradius) | - | Sets the radius of the rounded corner of the text background of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)](#oh_arkui_texteditortextstyle_gettextbackgroundradius) | - | Obtains the radius of the rounded corner of the text background of the text style.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)](#oh_arkui_texteditorstyledstringcontroller_settypingstyle) | - | Sets the typing style using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetTypingStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)](#oh_arkui_texteditorstyledstringcontroller_gettypingstyle) | - | Obtains the typing style using the styled string controller.|
| [OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()](#oh_arkui_texteditorselectionmenuoptions_create) | - | Creates a text selection menu option object of the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](capi-native-type-h.md#oh_arkui_texteditorselectionmenuoptions_destroy) to destroy it.|
| [void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)](#oh_arkui_texteditorselectionmenuoptions_destroy) | - | Destroys the text selection menu option object of the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetSpanType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType textEditorSpanType)](#oh_arkui_texteditorselectionmenuoptions_setspantype) | - | Sets the span type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetSpanType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType* textEditorSpanType)](#oh_arkui_texteditorselectionmenuoptions_getspantype) | - | Obtains the span type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options, ArkUI_NodeHandle node)](#oh_arkui_texteditorselectionmenuoptions_setcontentnode) | - | Sets the content node of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options, ArkUI_NodeHandle* node)](#oh_arkui_texteditorselectionmenuoptions_getcontentnode) | - | Obtains the content node of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetResponseType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType responseType)](#oh_arkui_texteditorselectionmenuoptions_setresponsetype) | - | Sets the response type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetResponseType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType* responseType)](#oh_arkui_texteditorselectionmenuoptions_getresponsetype) | - | Obtains the response type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextMenuType menuType)](#oh_arkui_texteditorselectionmenuoptions_setmenutype) | - | Sets the type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextMenuType* menuType)](#oh_arkui_texteditorselectionmenuoptions_getmenutype) | - | Obtains the type of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuShowCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (\*callback)(int32_t start, int32_t end, void* callbackUserData))](#oh_arkui_texteditorselectionmenuoptions_registeronmenushowcallback) | - | Sets the callback triggered when the text selection menu is displayed.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuHideCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (\*callback)(int32_t start, int32_t end, void* callbackUserData))](#oh_arkui_texteditorselectionmenuoptions_registeronmenuhidecallback) | - | Sets the callback triggered when the text selection menu is hidden.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuAppearCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (\*callback)(int32_t start, int32_t end, void* callbackUserData))](#oh_arkui_texteditorselectionmenuoptions_registeronmenuappearcallback) | - | Sets the callback triggered when the text selection menu appears.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuDisappearCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (\*callback)(void* callbackUserData))](#oh_arkui_texteditorselectionmenuoptions_registeronmenudisappearcallback) | - | Sets the callback triggered when the text selection menu disappears.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetHapticFeedbackMode(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode mode)](#oh_arkui_texteditorselectionmenuoptions_sethapticfeedbackmode) | - | Sets the haptic feedback mode of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetHapticFeedbackMode(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode* mode)](#oh_arkui_texteditorselectionmenuoptions_gethapticfeedbackmode) | - | Obtains the haptic feedback mode of the text selection menu in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_CloseSelectionMenu(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_closeselectionmenu) | - | Closes the text selection menu of the styled string controller in the text editor.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetSelection(const OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* start, uint32_t* end)](#oh_arkui_texteditorstyledstringcontroller_getselection) | - | Obtains the selected area using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledString(const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_texteditorstyledstringcontroller_setstyledstring) | - | Sets the styled string displayed using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetStyledString(const OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_texteditorstyledstringcontroller_getstyledstring) | - | Obtains the styled string displayed using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledPlaceholder(const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_texteditorstyledstringcontroller_setstyledplaceholder) | - | Sets the placeholder text in the styled string style using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_ScrollToVisible(const OH_ArkUI_TextEditorStyledStringController* controller, int32_t start, int32_t end)](#oh_arkui_texteditorstyledstringcontroller_scrolltovisible) | -    | Scrolls the content within the range from the specified start index to the end index to the visible area using the styled string controller.|
| [OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontWeightConfigs_Create()](#oh_arkui_fontweightconfigs_create) | - | Creates a text font weight configuration object.|
| [void OH_ArkUI_FontWeightConfigs_Destroy(OH_ArkUI_FontWeightConfigs* option)](#oh_arkui_fontweightconfigs_destroy) | - | Destroys the text font weight configuration object.|
| [void OH_ArkUI_FontWeightConfigs_SetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option, bool enable)](#oh_arkui_fontweightconfigs_setenablevariablefontweight) | - | Sets whether to enable variable font weight adjustment.|
| [bool OH_ArkUI_FontWeightConfigs_GetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option)](#oh_arkui_fontweightconfigs_getenablevariablefontweight) | - | Obtains whether variable font weight adjustment is enabled for the text font weight configuration object.|
| [void OH_ArkUI_FontWeightConfigs_SetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option, bool enable)](#oh_arkui_fontweightconfigs_setenabledevicefontweightcategory) | - | Sets whether to automatically update the text font weight when the font weight level of the device changes.|
| [bool OH_ArkUI_FontWeightConfigs_GetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option)](#oh_arkui_fontweightconfigs_getenabledevicefontweightcategory) | - | Obtains whether the text font weight is updated along with the font weight level of the device.|
| [OH_ArkUI_FontConfigs* OH_ArkUI_FontConfigs_Create()](#oh_arkui_fontconfigs_create) | - | Creates a text font configuration object.|
| [void OH_ArkUI_FontConfigs_Destroy(OH_ArkUI_FontConfigs* option)](#oh_arkui_fontconfigs_destroy) | - | Destroys the text font configuration object.|
| [void OH_ArkUI_FontConfigs_SetFontWeightConfigs(OH_ArkUI_FontConfigs* option, OH_ArkUI_FontWeightConfigs* fontWeightConfigs)](#oh_arkui_fontconfigs_setfontweightconfigs) | - | Sets the text font weight configurations for the text font configuration object.|
| [OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontConfigs_GetFontWeightConfigs(OH_ArkUI_FontConfigs* option)](#oh_arkui_fontconfigs_getfontweightconfigs) | - | Obtains the text font weight configurations of the text font configuration object.|
| [OH_ArkUI_TextController* OH_ArkUI_TextController_Create()](#oh_arkui_textcontroller_create) | - | Creates a text component controller object.|
| [void OH_ArkUI_TextController_Destroy(OH_ArkUI_TextController* controller)](#oh_arkui_textcontroller_destroy) | - | Destroys the text component controller object.|
| [ArkUI_ErrorCode OH_ArkUI_TextController_SetStyledString(OH_ArkUI_TextController* controller, ArkUI_StyledString_Descriptor* descriptor)](#oh_arkui_textcontroller_setstyledstring) | - | Sets a styled string for the text component.|
| [OH_ArkUI_LinearGradientOptions* OH_ArkUI_LinearGradientOptions_Create()](#oh_arkui_lineargradientoptions_create) | - | Creates an object for linear gradient effect options.|
| [void OH_ArkUI_LinearGradientOptions_Destroy(OH_ArkUI_LinearGradientOptions* options)](#oh_arkui_lineargradientoptions_destroy) | - | Destroys the object for linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetAngle(OH_ArkUI_LinearGradientOptions* options, float angle)](#oh_arkui_lineargradientoptions_setangle) | - | Sets the angle in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetAngle(const OH_ArkUI_LinearGradientOptions* options, float* angle)](#oh_arkui_lineargradientoptions_getangle) | - | Obtains the angle in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetDirection(OH_ArkUI_LinearGradientOptions* options, ArkUI_LinearGradientDirection direction)](#oh_arkui_lineargradientoptions_setdirection) | - | Sets the direction in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetDirection(const OH_ArkUI_LinearGradientOptions* options, ArkUI_LinearGradientDirection* direction)](#oh_arkui_lineargradientoptions_getdirection) | - | Obtains the direction in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetRepeating(OH_ArkUI_LinearGradientOptions* options, bool repeating)](#oh_arkui_lineargradientoptions_setrepeating) | - | Sets whether the color is repeated in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetRepeating(const OH_ArkUI_LinearGradientOptions* options, bool* repeating)](#oh_arkui_lineargradientoptions_getrepeating) | - | Obtains whether the color is repeated in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetColorStop(OH_ArkUI_LinearGradientOptions* options, const uint32_t* colors, const float* stops, int32_t colorsAndStopsSize)](#oh_arkui_lineargradientoptions_setcolorstop) | - | Sets the color stop in linear gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetColorStop(const OH_ArkUI_LinearGradientOptions* options, uint32_t* colors, float* stops, int32_t colorsAndStopsSize, int32_t* writeLength)](#oh_arkui_lineargradientoptions_getcolorstop) | - | Obtains the color stop in linear gradient effect options.|
| [OH_ArkUI_RadialGradientOptions* OH_ArkUI_RadialGradientOptions_Create()](#oh_arkui_radialgradientoptions_create) | - | Creates an object for radial gradient effect options.|
| [void OH_ArkUI_RadialGradientOptions_Destroy(OH_ArkUI_RadialGradientOptions* options)](#oh_arkui_radialgradientoptions_destroy) | - | Destroys the object for radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetCenterX(OH_ArkUI_RadialGradientOptions* options, float centerX)](#oh_arkui_radialgradientoptions_setcenterx) | - | Sets the X coordinate of the center point in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetCenterX(const OH_ArkUI_RadialGradientOptions* options, float* centerX)](#oh_arkui_radialgradientoptions_getcenterx) | - | Obtains the X coordinate of the center point in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetCenterY(OH_ArkUI_RadialGradientOptions* options, float centerY)](#oh_arkui_radialgradientoptions_setcentery) | - | Sets the Y coordinate of the center point in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetCenterY(const OH_ArkUI_RadialGradientOptions* options, float* centerY)](#oh_arkui_radialgradientoptions_getcentery) | - | Obtains the Y coordinate of the center point in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetRadius(OH_ArkUI_RadialGradientOptions* options, float radius)](#oh_arkui_radialgradientoptions_setradius) | - | Sets the radius in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetRadius(const OH_ArkUI_RadialGradientOptions* options, float* radius)](#oh_arkui_radialgradientoptions_getradius) | - | Obtains the radius in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetRepeating(OH_ArkUI_RadialGradientOptions* options, bool repeating)](#oh_arkui_radialgradientoptions_setrepeating) | - | Sets whether the color is repeated in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetRepeating(const OH_ArkUI_RadialGradientOptions* options, bool* repeating)](#oh_arkui_radialgradientoptions_getrepeating) | - | Obtains whether the color is repeated in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetColorStop(OH_ArkUI_RadialGradientOptions* options, const uint32_t* colors, const float* stops, int32_t colorsAndStopsSize)](#oh_arkui_radialgradientoptions_setcolorstop) | - | Sets the color stop in radial gradient effect options.|
| [ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetColorStop(const OH_ArkUI_RadialGradientOptions* options, uint32_t* colors, float* stops, int32_t colorsAndStopsSize, int32_t* writeLength)](#oh_arkui_radialgradientoptions_getcolorstop) | - | Obtains the color stop in radial gradient effect options.|

## Enum Description

### ArkUI_Alignment

```c
enum ArkUI_Alignment
```

**Description**


Enumerates the alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ALIGNMENT_TOP_START = 0 | Top start. This is the default value.|
| ARKUI_ALIGNMENT_TOP = 1 | Top center.|
| ARKUI_ALIGNMENT_TOP_END = 2 | Top end.|
| ARKUI_ALIGNMENT_START = 3 | Vertically centered start.|
| ARKUI_ALIGNMENT_CENTER = 4 | Horizontally and vertically centered.|
| ARKUI_ALIGNMENT_END = 5 | Vertically centered end.|
| ARKUI_ALIGNMENT_BOTTOM_START = 6 | Bottom start.|
| ARKUI_ALIGNMENT_BOTTOM = 7 | Horizontally centered on the bottom.|
| ARKUI_ALIGNMENT_BOTTOM_END = 8 | Bottom end.|

### ArkUI_FontStyle

```c
enum ArkUI_FontStyle
```

**Description**


Enumerates the font styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FONT_STYLE_NORMAL = 0 | Standard font style.|
| ARKUI_FONT_STYLE_ITALIC = 1 | Italic font style.|

### ArkUI_FontWeight

```c
enum ArkUI_FontWeight
```

**Description**


Enumerates the font weights.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FONT_WEIGHT_W100 = 0 | 100 |
| ARKUI_FONT_WEIGHT_W200 = 1 | 200 |
| ARKUI_FONT_WEIGHT_W300 = 2 | 300 |
| ARKUI_FONT_WEIGHT_W400 = 3 | 400 |
| ARKUI_FONT_WEIGHT_W500 = 4 | 500 |
| ARKUI_FONT_WEIGHT_W600 = 5 | 600 |
| ARKUI_FONT_WEIGHT_W700 = 6 | 700 |
| ARKUI_FONT_WEIGHT_W800 = 7 | 800 |
| ARKUI_FONT_WEIGHT_W900 = 8 | 900 |
| ARKUI_FONT_WEIGHT_BOLD = 9 | The font weight is bold.|
| ARKUI_FONT_WEIGHT_NORMAL = 10 | The font weight is normal.|
| ARKUI_FONT_WEIGHT_BOLDER = 11 | The font weight is bolder.|
| ARKUI_FONT_WEIGHT_LIGHTER = 12 | The font weight is lighter.|
| ARKUI_FONT_WEIGHT_MEDIUM = 13 | The font weight is medium.|
| ARKUI_FONT_WEIGHT_REGULAR = 14 | The font weight is normal.|

### ArkUI_TextAlignment

```c
enum ArkUI_TextAlignment
```

**Description**


Enumerates text alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_ALIGNMENT_START = 0 | Aligned with the start.|
| ARKUI_TEXT_ALIGNMENT_CENTER = 1 | Horizontally centered.|
| ARKUI_TEXT_ALIGNMENT_END = 2 | Aligned with the end.|
| ARKUI_TEXT_ALIGNMENT_JUSTIFY = 3 | Aligned with both margins.|
| ARKUI_TEXT_ALIGNMENT_LEFT_TO_RIGHT = 4 | Aligned from left to right.<br>**Since**: 23|
| ARKUI_TEXT_ALIGNMENT_RIGHT_TO_LEFT = 5 | Aligned from right to left.<br>**Since**: 23|

### ArkUI_TextVerticalAlignment

```c
enum ArkUI_TextVerticalAlignment
```

**Description**


Enumerates text vertical alignment styles.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE = 0 | Aligned to the baseline.|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_BOTTOM = 1 | Bottom aligned.|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_CENTER = 2 | The list item is centered along|
| ARKUI_TEXT_VERTICAL_ALIGNMENT_TOP = 3 | Top aligned.|

### ArkUI_TextContentAlign

```c
enum ArkUI_TextContentAlign
```

**Description**


Enumerates vertical alignment styles in the text content area.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_TEXT_CONTENT_ALIGN_TOP = 0 | Top aligned.|
| ARKUI_TEXT_CONTENT_ALIGN_CENTER = 1 | The list item is centered along|
| ARKUI_TEXT_CONTENT_ALIGN_BOTTOM = 2 | Bottom aligned.|

### ArkUI_TextDirection

``` c
enum ArkUI_TextDirection
```

**Description**


Enumerates the text layout directions.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DIRECTION_LTR = 0 | From left to right.|
| ARKUI_TEXT_DIRECTION_RTL = 1 | From right to left.|
| ARKUI_TEXT_DIRECTION_DEFAULT = 2 | Follow the component layout.|
| ARKUI_TEXT_DIRECTION_AUTO = 3 | Follow the writing direction of the content. For example, for right-to-left (RTL) languages (such as Tibetan and Uyghur), the text is laid out from right to left. For left-to-right (LTR) languages (such as Chinese and English), the text is laid out from left to right.|

### ArkUI_EnterKeyType

```c
enum ArkUI_EnterKeyType
```

**Description**


Enumerates the types of the Enter key for a single-line text box.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ENTER_KEY_TYPE_GO = 2 | The Enter key is labeled "Go."|
| ARKUI_ENTER_KEY_TYPE_SEARCH = 3 | The Enter key is labeled "Search."|
| ARKUI_ENTER_KEY_TYPE_SEND = 4 | The Enter key is labeled "Send."|
| ARKUI_ENTER_KEY_TYPE_NEXT = 5 | The Enter key is labeled "Next."|
| ARKUI_ENTER_KEY_TYPE_DONE = 6 | The Enter key is labeled "Done."|
| ARKUI_ENTER_KEY_TYPE_PREVIOUS = 7 | The Enter key is labeled "Previous."|
| ARKUI_ENTER_KEY_TYPE_NEW_LINE = 8 | The Enter key is labeled "Return."|

### ArkUI_TextInputType

```c
enum ArkUI_TextInputType
```

**Description**


Enumerates the input method type of a single-line text.

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

```c
enum ArkUI_TextAreaType
```

**Description**


Enumerates the input method types of a multi-line text.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXTAREA_TYPE_NORMAL = 0 | Normal input mode.|
| ARKUI_TEXTAREA_TYPE_NUMBER = 2 | Number input mode.|
| ARKUI_TEXTAREA_TYPE_PHONE_NUMBER = 3 | Phone number input mode.|
| ARKUI_TEXTAREA_TYPE_EMAIL = 5 | Email address input mode.|
| ARKUI_TEXTAREA_TYPE_ONE_TIME_CODE = 14 | Verification code input mode.<br>**Since**: 20|

### ArkUI_CancelButtonStyle

```c
enum ArkUI_CancelButtonStyle
```

**Description**


Enumerates the styles of the Cancel button.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_CANCELBUTTON_STYLE_CONSTANT = 0 | The Cancel button is always displayed.|
| ARKUI_CANCELBUTTON_STYLE_INVISIBLE = 1 | The Cancel button is always hidden.|
| ARKUI_CANCELBUTTON_STYLE_INPUT = 2 | The Cancel button is displayed when there is text input.|

### ArkUI_ProgressType

```c
enum ArkUI_ProgressType
```

**Description**


Enumerates the styles of the progress indicator.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_PROGRESS_TYPE_LINEAR = 0 | Linear type.|
| ARKUI_PROGRESS_TYPE_RING = 1 | Ring style without scale marks.|
| ARKUI_PROGRESS_TYPE_ECLIPSE = 2 | Eclipse style.|
| ARKUI_PROGRESS_TYPE_SCALE_RING = 3 | Ring style with scale marks.|
| ARKUI_PROGRESS_TYPE_CAPSULE = 4 | Capsule style.|

### ArkUI_TextDecorationType

```c
enum ArkUI_TextDecorationType
```

**Description**


Enumerates the text decoration types.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DECORATION_TYPE_NONE = 0 | No text decoration.|
| ARKUI_TEXT_DECORATION_TYPE_UNDERLINE = 1 | Line under the text.|
| ARKUI_TEXT_DECORATION_TYPE_OVERLINE = 2 | Line over the text.|
| ARKUI_TEXT_DECORATION_TYPE_LINE_THROUGH = 3 | Line through the text.|

### ArkUI_TextDecorationStyle

```c
enum ArkUI_TextDecorationStyle
```

**Description**


Enumerates the text decoration styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_DECORATION_STYLE_SOLID = 0 | Single solid line.|
| ARKUI_TEXT_DECORATION_STYLE_DOUBLE = 1 | Double solid line.|
| ARKUI_TEXT_DECORATION_STYLE_DOTTED = 2 | Dotted line.|
| ARKUI_TEXT_DECORATION_STYLE_DASHED = 3 | Dashed style.|
| ARKUI_TEXT_DECORATION_STYLE_WAVY = 4 | Wavy line.|

### ArkUI_TextCase

```c
enum ArkUI_TextCase
```

**Description**


Enumerates the text cases.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_CASE_NORMAL = 0 | The original case of the text is retained.|
| ARKUI_TEXT_CASE_LOWER = 1 | All letters in the text are in lowercase.|
| ARKUI_TEXT_CASE_UPPER = 2 | All letters in the text are in uppercase.|

### ArkUI_CopyOptions

```c
enum ArkUI_CopyOptions
```

**Description**


Enumerates the text copy and paste modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_COPY_OPTIONS_NONE = 0 | Copy is not allowed.|
| ARKUI_COPY_OPTIONS_IN_APP = 1 | Intra-application copy is allowed.|
| ARKUI_COPY_OPTIONS_LOCAL_DEVICE = 2 | Intra-device copy is allowed.|
| ARKUI_COPY_OPTIONS_CROSS_DEVICE = 3 | Cross-device copy is allowed.|

### ArkUI_AccessibilityCheckedState

```c
enum ArkUI_AccessibilityCheckedState
```

**Description**


Enumerates the accessibility check box states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_UNCHECKED = 0 | The check box is not selected.|
| ARKUI_ACCESSIBILITY_CHECKED = 1 | The check box is selected.|

### ArkUI_AccessibilityActionType

```c
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

```c
enum ArkUI_EdgeEffect
```

**Description**


Enumerates the effects used at the edges of the component when the boundary of the scrollable content is reached. The default value is **ARKUI_EDGE_EFFECT_NONE** for the **Grid**, **Scroll**, and **WaterFlow** components, and **ARKUI_EDGE_EFFECT_SPRING** for the **List** component.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_EDGE_EFFECT_SPRING = 0 | Spring effect. When at one of the edges, the component can move beyond the bounds based on the initial speed or through touches, and produces a bounce effect when the user releases their finger.|
| ARKUI_EDGE_EFFECT_FADE = 1 | Fade effect. When at one of the edges, the component produces a fade effect.|
| ARKUI_EDGE_EFFECT_NONE = 2 | No effect when the component is at one of the edges.|

### ArkUI_BarState

```c
enum ArkUI_BarState
```

**Description**


Enumerates the text control scrollbar states.

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_BAR_STATE_OFF = 0 | Not displayed.|
| ARKUI_BAR_STATE_AUTO = 1 | Displayed on demand (The scrollbar is displayed when being touched and disappears 2 seconds later.)|
| ARKUI_BAR_STATE_ON = 2 | Always displayed.|

### ArkUI_EffectEdge

```c
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

```c
enum ArkUI_ScrollDirection
```

**Description**


Enumerates the scrolling directions of the [Scroll](../apis-arkui/arkui-ts/ts-container-scroll.md) component.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_DIRECTION_VERTICAL = 0 | Vertical scrolling only.|
| ARKUI_SCROLL_DIRECTION_HORIZONTAL = 1 | Horizontal scrolling only.|
| ARKUI_SCROLL_DIRECTION_NONE = 3 | Scrolling disabled.|
| ARKUI_SCROLL_DIRECTION_FREE = 4 | Free scrolling in both directions.<br>**Since**: 20|

### ArkUI_ScrollSnapAlign

```c
enum ArkUI_ScrollSnapAlign
```

**Description**


Enumerates the alignment modes of list items when scrolling ends.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_SNAP_ALIGN_NONE = 0 | No alignment mode.|
| ARKUI_SCROLL_SNAP_ALIGN_START = 1 | The first item in the view is aligned at the start of the list.|
| ARKUI_SCROLL_SNAP_ALIGN_CENTER = 2 | The middle items in the view are aligned in the center of the list.|
| ARKUI_SCROLL_SNAP_ALIGN_END = 3 | The last item in the view is aligned at the end of the list.|

### ArkUI_ScrollBarDisplayMode

```c
enum ArkUI_ScrollBarDisplayMode
```

**Description**


Enumerates the scrollbar display modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_BAR_DISPLAY_MODE_OFF = 0 | Not displayed.|
| ARKUI_SCROLL_BAR_DISPLAY_MODE_AUTO = 1 | Displayed when the screen is touched and hidden after 2s.|
| ARKUI_SCROLL_BAR_DISPLAY_MODE_ON = 2 | Always displayed.|

### ArkUI_Axis

```c
enum ArkUI_Axis
```

**Description**


Enumerates scroll directions and [List](./arkui-ts/ts-container-list.md) component arrangement directions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_AXIS_VERTICAL = 0 | Vertical scrolling only. This is the default value.|
| ARKUI_AXIS_HORIZONTAL = 1 | Horizontal scrolling only.|

### ArkUI_StickyStyle

```c
enum ArkUI_StickyStyle
```

**Description**


Enumerates the modes for pinning the header to the top or the footer to the bottom.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_STICKY_STYLE_NONE = 0 | [header](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) and [footer](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) of [ListItemGroup](./arkui-ts/ts-container-listitemgroup.md) are not pinned to the top and bottom, respectively.|
| ARKUI_STICKY_STYLE_HEADER = 1 | [header](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) of [ListItemGroup](./arkui-ts/ts-container-listitemgroup.md) is pinned to the top, and [footer](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) is not pinned to the bottom.|
| ARKUI_STICKY_STYLE_FOOTER = 2 | [header](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) of [ListItemGroup](./arkui-ts/ts-container-listitemgroup.md) is not pinned to the top, and [footer](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) is pinned to the bottom.|
| ARKUI_STICKY_STYLE_BOTH = 3 | [header](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) of [ListItemGroup](./arkui-ts/ts-container-listitemgroup.md) is pinned to the top, and [footer](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions) is pinned to the bottom.|

### ArkUI_ContentClipMode

```c
enum ArkUI_ContentClipMode
```

**Description**


Enumerates the content clipping modes of scrollable components.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_CONTENT_CLIP_MODE_CONTENT_ONLY = 0 | Clip to the content area only.|
| ARKUI_CONTENT_CLIP_MODE_BOUNDARY = 1 | Clip to the component's boundary area.|
| ARKUI_CONTENT_CLIP_MODE_SAFE_AREA = 2 | Clip to the [safe area](./arkui-ts/ts-universal-attributes-expand-safe-area.md) configured for the component.|

### ArkUI_WaterFlowLayoutMode

```c
enum ArkUI_WaterFlowLayoutMode
```

**Description**


Enumerates the layout modes of the [WaterFlow](../apis-arkui/arkui-ts/ts-container-waterflow.md) component.

**Since**: 18

| Value| Description|
| -- | -- |
| ARKUI_WATER_FLOW_LAYOUT_MODE_ALWAYS_TOP_DOWN = 0 | Layout from top to bottom. In scenarios where column switching occurs, the layout starts from the first [water flow item](../apis-arkui/arkui-ts/ts-container-flowitem.md) to the currently displayed [water flow item](../apis-arkui/arkui-ts/ts-container-flowitem.md).|
| ARKUI_WATER_FLOW_LAYOUT_MODE_SLIDING_WINDOW = 1 | Sliding window layout. In scenarios where column switching occurs, only the range of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) currently on display is re-laid out. As the user scrolls down with their finger, [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) that enter the display range from above are subsequently laid out.|

### ArkUI_BorderStyle

```c
enum ArkUI_BorderStyle
```

**Description**


Enumerates the border styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BORDER_STYLE_SOLID = 0 | Solid border. This is the default value.|
| ARKUI_BORDER_STYLE_DASHED = 1 | Dashed border.|
| ARKUI_BORDER_STYLE_DOTTED = 2 | Dotted border.|

### ArkUI_AccessibilityMode

```c
enum ArkUI_AccessibilityMode
```

**Description**


Enumerates the accessibility modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ACCESSIBILITY_MODE_AUTO = 0 | The mode is automatically set to enabled or disabled based on the component.|
| ARKUI_ACCESSIBILITY_MODE_ENABLED = 1 | The component can be identified by the accessibility service.|
| ARKUI_ACCESSIBILITY_MODE_DISABLED = 2 | The component cannot be identified by the accessibility service.|
| ARKUI_ACCESSIBILITY_MODE_DISABLED_FOR_DESCENDANTS = 3 | The component and all its child components cannot be identified by the accessibility service.|

### ArkUI_TextCopyOptions

```c
enum ArkUI_TextCopyOptions
```

**Description**


Enumerates copy options, which define whether copy and paste is allowed for text content.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_COPY_OPTIONS_NONE = 0 | Copy is not allowed.|
| ARKUI_TEXT_COPY_OPTIONS_IN_APP = 1 | Intra-application copy is allowed.|
| ARKUI_TEXT_COPY_OPTIONS_LOCAL_DEVICE = 2 | Intra-device copy is allowed.|
| ARKUI_TEXT_COPY_OPTIONS_CROSS_DEVICE = 3 | Cross-device copy is allowed.|

### ArkUI_TextHeightAdaptivePolicy

```c
enum ArkUI_TextHeightAdaptivePolicy
```

**Description**


Defines how the adaptive height is determined for the text.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MAX_LINES_FIRST = 0 | Prioritize the **maxLines** settings.|
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_MIN_FONT_SIZE_FIRST = 1 | Prioritize the **minFontSize** settings.|
| ARKUI_TEXT_HEIGHT_ADAPTIVE_POLICY_LAYOUT_CONSTRAINT_FIRST = 2 | Prioritize the layout constraint settings in terms of height.|

### ArkUI_ScrollNestedMode

```c
enum ArkUI_ScrollNestedMode
```

**Description**


Enumerates nested scrolling modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_NESTED_MODE_SELF_ONLY = 0 | The scrolling is contained within the component, and no scroll chaining occurs, that is, the parent component does not scroll when the component scrolling reaches the boundary.|
| ARKUI_SCROLL_NESTED_MODE_SELF_FIRST = 1 | The component scrolls first, and when it hits the boundary, the parent component scrolls. When the parent component hits the boundary, its edge effect is displayed. If no edge effect is specified for the parent component, the edge effect of the child component is displayed instead.|
| ARKUI_SCROLL_NESTED_MODE_PARENT_FIRST = 2 | The parent component scrolls first, and when it hits the boundary, the component scrolls. When the component hits the boundary, its edge effect is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead.|
| ARKUI_SCROLL_NESTED_MODE_PARALLEL = 3 | The component and its parent component scroll at the same time. When both the component and its parent component hit the boundary, the edge effect of the component is displayed. If no edge effect is specified for the component, the edge effect of the parent component is displayed instead.|

### ArkUI_ScrollEdge

```c
enum ArkUI_ScrollEdge
```

**Description**


Enumerates the edges to which the component scrolls.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_EDGE_TOP = 0 | Top edge in the vertical direction.|
| ARKUI_SCROLL_EDGE_BOTTOM = 1 | Bottom edge in the vertical direction.|
| ARKUI_SCROLL_EDGE_START = 2 | Start position in the horizontal direction.|
| ARKUI_SCROLL_EDGE_END = 3 | End position in the horizontal direction.|

### ArkUI_ScrollAlignment

```c
enum ArkUI_ScrollAlignment
```

**Description**


Defines how the list item to scroll to is aligned with the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_ALIGNMENT_START = 0 | The start edge of the list item is flush with the start edge of the container.|
| ARKUI_SCROLL_ALIGNMENT_CENTER = 1 | The list item is centered along the main axis of the container.|
| ARKUI_SCROLL_ALIGNMENT_END = 2 | The end edge of the list item is flush with the end edge of the container.|
| ARKUI_SCROLL_ALIGNMENT_AUTO = 3 | The list item is automatically aligned. If the item is fully contained within the display area, no adjustment is performed. Otherwise, the item is aligned so that its start or end edge is flush with the start or end edge of the container, whichever requires a shorter scrolling distance.|

### ArkUI_ScrollState

```c
enum ArkUI_ScrollState
```

**Description**


Enumerates the scrolling states.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_STATE_IDLE = 0 | Idle. The container enters this state when an API in the controller is used to scroll the container or when the scrollbar is dragged.|
| ARKUI_SCROLL_STATE_SCROLL = 1 | Scrolling. The container enters this state when the user drags the container to scroll.|
| ARKUI_SCROLL_STATE_FLING = 2 | Inertial scrolling. The container enters this state when inertial scrolling occurs or when the container bounces back after being released from a fling.|

### ArkUI_SliderBlockStyle

```c
enum ArkUI_SliderBlockStyle
```

**Description**


Enumerates the styles of the slider in the block direction.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_BLOCK_STYLE_DEFAULT = 0 | Round slider.|
| ARKUI_SLIDER_BLOCK_STYLE_IMAGE = 1 | Slider with an image background.|
| ARKUI_SLIDER_BLOCK_STYLE_SHAPE = 2 | Slider in a custom shape.|

### ArkUI_SliderDirection

```c
enum ArkUI_SliderDirection
```

**Description**


Enumerates the scroll directions of the slider.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_DIRECTION_VERTICAL = 0 | Vertical direction.|
| ARKUI_SLIDER_DIRECTION_HORIZONTAL = 1 | Horizontal direction.|

### ArkUI_SliderStyle

```c
enum ArkUI_SliderStyle
```

**Description**


Enumerates the slider styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SLIDER_STYLE_OUT_SET = 0 | The slider is on the slider rail.|
| ARKUI_SLIDER_STYLE_IN_SET = 1 | The slider is in the slider rail.|
| ARKUI_SLIDER_STYLE_NONE = 2 | There is no thumb.|

### ArkUI_CheckboxShape

```c
enum ArkUI_CheckboxShape
```

**Description**


Enumerates the shapes of the check box.

**Since**: 12

| Value| Description|
| -- | -- |
| ArkUI_CHECKBOX_SHAPE_CIRCLE = 0 | Circle.|
| ArkUI_CHECKBOX_SHAPE_ROUNDED_SQUARE = 1 | Rounded square.|

### ArkUI_AdaptiveColor

```c
enum ArkUI_AdaptiveColor
```

**Description**


Enumerates the adaptive color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ADAPTIVE_COLOR_DEFAULT = 0 | Adaptive color mode is not used.|
| ARKUI_ADAPTIVE_COLOR_AVERAGE = 1 | Adaptive color mode is used.|

### ArkUI_ColorMode

```c
enum ArkUI_ColorMode
```

**Description**


Enumerates the color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_COLOR_MODE_SYSTEM = 0 | Following the system color mode.|
| ARKUI_COLOR_MODE_LIGHT = 1 | Light color mode.|
| ARKUI_COLOR_MODE_DARK = 2 | Dark color mode.|

### ArkUI_SystemColorMode

```c
enum ArkUI_SystemColorMode
```

**Description**


Enumerates the system color modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SYSTEM_COLOR_MODE_LIGHT = 0 | Light mode.|
| ARKUI_SYSTEM_COLOR_MODE_DARK = 1 | Dark mode.|

### ArkUI_VerticalAlignment

```c
enum ArkUI_VerticalAlignment
```

**Description**


Enumerates the vertical alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_VERTICAL_ALIGNMENT_TOP = 0 | Top aligned.|
| ARKUI_VERTICAL_ALIGNMENT_CENTER = 1 | Aligned with the center. This is the default alignment mode.|
| ARKUI_VERTICAL_ALIGNMENT_BOTTOM = 2 | Bottom aligned.|

### ArkUI_HorizontalAlignment

```c
enum ArkUI_HorizontalAlignment
```

**Description**


Enumerates the alignment mode in the horizontal direction.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_HORIZONTAL_ALIGNMENT_START = 0 | Aligned with the start edge in the same direction as the language in use.|
| ARKUI_HORIZONTAL_ALIGNMENT_CENTER = 1 | Aligned with the center. This is the default alignment mode.|
| ARKUI_HORIZONTAL_ALIGNMENT_END = 2 | Aligned with the end edge in the same direction as the language in use.|

### ArkUI_TextOverflow

```c
enum ArkUI_TextOverflow
```

**Description**


Enumerates the display modes when the text is too long.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_TEXT_OVERFLOW_NONE = 0 | Extra-long text is not clipped.|
| ARKUI_TEXT_OVERFLOW_CLIP = 1 | Extra-long text is clipped.|
| ARKUI_TEXT_OVERFLOW_ELLIPSIS = 2 | An ellipsis (...) is used to represent text overflow.|
| ARKUI_TEXT_OVERFLOW_MARQUEE = 3 | Text continuously scrolls when text overflow occurs.|

### ArkUI_ImageSpanAlignment

```c
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

### ArkUI_Direction

```c
enum ArkUI_Direction
```

**Description**


Enumerates the modes in which components are laid out along the main axis of the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_DIRECTION_LTR = 0 | Components are arranged from left to right. This is the default value.|
| ARKUI_DIRECTION_RTL = 1 | Components are arranged from right to left.|
| ARKUI_DIRECTION_AUTO = 3 | The system layout direction is used.|

### ArkUI_ItemAlignment

```c
enum ArkUI_ItemAlignment
```

**Description**


Enumerates the modes in which components are laid out along the cross axis of the container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ITEM_ALIGNMENT_AUTO = 0 | The default configuration in the [Flex](..//apis-arkui/arkui-ts/ts-container-flex.md) container is used. This is the default value.|
| ARKUI_ITEM_ALIGNMENT_START = 1 | The items in the flex container are aligned with the cross-start edge.|
| ARKUI_ITEM_ALIGNMENT_CENTER = 2 | The items in the flex container are centered along the cross axis.|
| ARKUI_ITEM_ALIGNMENT_END = 3 | The items in the flex container are aligned with the cross-end edge.|
| ARKUI_ITEM_ALIGNMENT_STRETCH = 4 | The items in the flex container are stretched and padded along the cross axis.|
| ARKUI_ITEM_ALIGNMENT_BASELINE = 5 | The items in the flex container are aligned in such a manner that their text baselines are aligned along the cross axis.|

### ArkUI_FlexAlignment

```c
enum ArkUI_FlexAlignment
```

**Description**


Enumerates the vertical alignment modes.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_ALIGNMENT_START = 1 | The child components are aligned with the start edge of the main axis. This is the default value.|
| ARKUI_FLEX_ALIGNMENT_CENTER = 2 | The child components are aligned in the center of the main axis.|
| ARKUI_FLEX_ALIGNMENT_END = 3 | The child components are aligned with the end edge of the main axis.|
| ARKUI_FLEX_ALIGNMENT_SPACE_BETWEEN = 6 | The child components are evenly distributed along the main axis in [Flex](..//apis-arkui/arkui-ts/ts-container-flex.md). The space between any two adjacent components is the same. The first component is aligned with the main-start, and the last component is aligned with the main-end.|
| ARKUI_FLEX_ALIGNMENT_SPACE_AROUND = 7 | The child components are evenly distributed along the main axis. The space between any two adjacent components is the same. The space between the first component and main-start, and that between the last component and cross-main are both half the size of the space between two adjacent components.|
| ARKUI_FLEX_ALIGNMENT_SPACE_EVENLY = 8 | The child components are evenly distributed along the main axis. The space between the first component and main-start, the space between the last component and main-end, and the space between any two adjacent components are the same.|

### ArkUI_FlexDirection

```c
enum ArkUI_FlexDirection
```

**Description**


Enumerates the directions of the main axis in the [Flex](..//apis-arkui/arkui-ts/ts-container-flex.md) container.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_DIRECTION_ROW = 0 | The child components are arranged in the same direction as the main axis runs down the rows. This is the default value.|
| ARKUI_FLEX_DIRECTION_COLUMN = 1 | The child components are arranged in the same direction as the main axis runs down the columns.|
| ARKUI_FLEX_DIRECTION_ROW_REVERSE = 2 | The child components are arranged opposite to the **ROW** direction.|
| ARKUI_FLEX_DIRECTION_COLUMN_REVERSE = 3 | The child components are arranged opposite to the **COLUMN** direction.|

### ArkUI_FlexWrap

```c
enum ArkUI_FlexWrap
```

**Description**


Defines whether the flex container has a single line or multiple lines.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_FLEX_WRAP_NO_WRAP = 0 | The child components in the flex container are arranged in a single line, and they cannot overflow. This is the default value.|
| ARKUI_FLEX_WRAP_WRAP = 1 | The child components in the flex container are arranged in multiple lines, and they may overflow.|
| ARKUI_FLEX_WRAP_WRAP_REVERSE = 2 | The child components in the flex container are reversely arranged in multiple lines, and they may overflow.|

### ArkUI_WordBreak

```c
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

```c
enum ArkUI_EllipsisMode
```

**Description**


Enumerates the ellipsis positions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_ELLIPSIS_MODE_START = 0 | An ellipsis is used at the start of the line of text. This applies to single-line text scenarios.|
| ARKUI_ELLIPSIS_MODE_CENTER = 1 | An ellipsis is used at the center of the line of text. This applies to single-line text scenarios.|
| ARKUI_ELLIPSIS_MODE_END = 2 | An ellipsis is used at the end of the line of text. This applies to single-line and multi-line text scenarios.|
| ARKUI_ELLIPSIS_MODE_MULTILINE_START = 3 | An ellipsis is used at the start of the line of text. This applies to single-line and multi-line text scenarios.<br>**Since**: 24|
| ARKUI_ELLIPSIS_MODE_MULTILINE_CENTER = 4 | An ellipsis is used at the center of the line of text. This applies to single-line and multi-line text scenarios.<br>**Since**: 24|

### ArkUI_ListItemAlignment

```c
enum ArkUI_ListItemAlignment
```

**Description**


Enumerates the alignment modes of items along the cross axis. The default value is **ARKUI_LIST_ITEM_ALIGNMENT_START**.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_ALIGNMENT_START = 0 | The [list items](./arkui-ts/ts-container-listitem.md#listitem10) are packed toward the start edge of the **List** component along the cross axis.|
| ARKUI_LIST_ITEM_ALIGNMENT_CENTER = 1 | The list items are centered in the **List** component along the cross axis.|
| ARKUI_LIST_ITEM_ALIGNMENT_END = 2 | The list items are packed toward the end edge of the **List** component along the cross axis.|

### ArkUI_LengthMetricUnit

```c
enum ArkUI_LengthMetricUnit
```

**Description**


Enumerates the component units.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LENGTH_METRIC_UNIT_DEFAULT = -1 | Default, which is fp for fonts and vp for non-fonts.|
| ARKUI_LENGTH_METRIC_UNIT_PX = 0 | The unit is px.|
| ARKUI_LENGTH_METRIC_UNIT_VP = 1 | The unit is vp.|
| ARKUI_LENGTH_METRIC_UNIT_FP = 2 | The unit is fp.|

### ArkUI_TextInputContentType

```c
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

```c
enum ArkUI_BarrierDirection
```

**Description**


Enumerates the barrier directions.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_BARRIER_DIRECTION_START = 0 | The barrier is on the left side of all the referenced components specified by [referencedId](..//apis-arkui/arkui-ts/ts-container-relativecontainer.md#barrierstyle12). This is the default value.|
| ARKUI_BARRIER_DIRECTION_END = 1 | The barrier is on the right side of all the referenced components specified by referencedId.|
| ARKUI_BARRIER_DIRECTION_TOP = 2 | The barrier is at the top of all the referenced components specified by referencedId.|
| ARKUI_BARRIER_DIRECTION_BOTTOM = 3 | The barrier is at the bottom of all the referenced components specified by referencedId.|

### ArkUI_RelativeLayoutChainStyle

```c
enum ArkUI_RelativeLayoutChainStyle
```

**Description**


Enumerates the chain styles.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD = 0 | Child components are evenly distributed among constraint anchors. This is the default value.|
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_SPREAD_INSIDE = 1 | All child components except the first and last ones are evenly distributed among constraint anchors.|
| ARKUI_RELATIVE_LAYOUT_CHAIN_STYLE_PACKED = 2 | There is no gap between child components in the chain.|

### ArkUI_TextInputStyle

```c
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

```c
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

```c
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

```c
enum ArkUI_ButtonType
```

**Description**


Enumerates the button types.

**Since**: 12

| Value| Description                     |
| -- |-------------------------|
| ARKUI_BUTTON_TYPE_NORMAL = 0 | Normal button (without rounded corners by default).           |
| ARKUI_BUTTON_TYPE_CAPSULE = 1 | Capsule-type button (the round corner is half of the height by default).      |
| ARKUI_BUTTON_TYPE_CIRCLE = 2 | Circle button.                  |
| ARKUI_BUTTON_ROUNDED_RECTANGLE = 8 | Rounded rectangle button<br>**Since**: 19|

### ArkUI_ListItemSwipeActionState

```c
enum ArkUI_ListItemSwipeActionState
```

**Description**


Enumerates the item states of [SwipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the [Listitem](./arkui-ts/ts-container-listitem.md#listitem10) component. The default value is **ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED**.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_COLLAPSED = 0 | Collapsed state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is hidden.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_EXPANDED = 1 | Expanded state. When the list item is swiped in the opposite direction of the main axis, the swipe action item is shown.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_STATE_ACTIONING = 2 | In-action state. The list item is in this state when it enters the delete area.|

### ArkUI_ListItemSwipeEdgeEffect

```c
enum ArkUI_ListItemSwipeEdgeEffect
```

**Description**


Enumerates the item edge effects of [swipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the **Listitem** component. The default value is **ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING**.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING = 0 | When the list item scrolls to the edge of the list, it can continue to scroll for a distance.|
| ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_NONE = 1 | The list item cannot scroll beyond the edge of the list.|

### ArkUI_ListItemSwipeActionDirection

```c
enum ArkUI_ListItemSwipeActionDirection
```

**Description**

Enumerates the swipe action menu display directions for **ListItem** components.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_START = 0 | For vertical lists: left side in LTR mode, right side in RTL mode. For horizontal lists: top side.|
| ARKUI_LIST_ITEM_SWIPE_ACTION_DIRECTION_END = 1 | For vertical lists: right side in LTR mode, left side in RTL mode. For horizontal lists: bottom side.|

### ArkUI_CrownSensitivity

```c
enum ArkUI_CrownSensitivity
```

**Description**


Enumerates crown sensitivity levels.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| ARKUI_CROWN_SENSITIVITY_LOW = 0 | Low sensitivity.|
| ARKUI_CROWN_SENSITIVITY_MEDIUM = 1 | Medium sensitivity.|
| ARKUI_CROWN_SENSITIVITY_HIGH = 2 | High sensitivity.|

### ArkUI_ErrorCode

```c
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
| ARKUI_ERROR_CODE_PARAM_ERROR = 100023 |  Parameter error. For details about the error code, see [100023 Parameter Error](../apis-arkui/errorcode-node.md#100023-parameter-error).<br>**Since**: 21|
| ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501 |  The **XComponent** is in an invalid or unsupported state. For details, see [XComponent Error Codes](../apis-arkui/errorcode-xcomponent.md).<br>**Since**: 19|
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102 | The component does not support specific attributes or events. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103 | The corresponding operations cannot be performed on the node created by ArkTS. For details about the error code, see [106103 Operation Not Allowed on Nodes Created by ArkTS](../apis-arkui/errorcode-node.md#106103-operation-not-allowed-on-nodes-created-by-arkts).|
| ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104 | The adapter for lazy loading is not bound to the component. For details about the error code, see [106104 Adapter Not Bound](../apis-arkui/errorcode-nodeadapter.md#106104-adapter-not-bound).|
| ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105 | The adapter already exists. For details about the error code, see [106105 Adapter Already Exists](../apis-arkui/errorcode-nodeadapter.md#106105-adapter-already-exists).|
| ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106 | Failed to add the adapter because the corresponding node already has a subnode. For details about the error code, see [106106 Child Node Exists](../apis-arkui/errorcode-nodeadapter.md#106106-child-node-exists).|
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107 | The parameter length in the parameter event exceeds the limit. For details about the error code, see [106107 Index Out of Range](../apis-arkui/errorcode-nodeadapter.md#106107-index-out-of-range).|
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108 | The data does not exist in the component event. For details about the error code, see [106108 Data Not Found](../apis-arkui/errorcode-nodeadapter.md#106108-data-not-found).|
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109 | The component event does not support return values. For details about the error code, see [106109 Return Value Not Supported](../apis-arkui/errorcode-nodeadapter.md#106109-return-value-not-supported).|
| ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110 | This event type is not supported. For details about the error code, see [106110 Unsupported Event Type](../apis-arkui/errorcode-nodeadapter.md#106110-unsupported-event-type).<br>**Since**: 21|
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200 | Invalid index.<br>For details about the error code, see [106200 Invalid Index Value](../apis-arkui/errorcode-router.md#106200-invalid-index-value).|
| ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201 | Failed to obtain the route navigation information.<br>For details about the error code, see [106201 Failed to Obtain Route Navigation Information](../apis-arkui/errorcode-router.md#106201-failed-to-obtain-route-navigation-information).|
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202 | The passed buffer size is invalid (the data is too large).<br>For details about the error code, see [106202 Invalid Buffer Size](../apis-arkui/errorcode-router.md#106202-invalid-buffer-size).|
| ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203 |  The passed node is not mounted to the component tree. For details about the error code, see [106203 Passed Node Not Mounted to Component Tree](../apis-arkui/errorcode-node.md#106203-passed-node-not-mounted-to-component-tree).<br>**Since**: 15|
| ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204 |  Operations on the provided node are not supported on non-UI threads. For details about the error code, see [106204 Operations on the Provided Node Not Supported on Non-UI Threads](../apis-arkui/errorcode-node.md#106204-operations-on-the-provided-node-not-supported-on-non-ui-threads).<br>**Since**: 22|
| ARKUI_ERROR_CODE_FORCE_DARK_CONFIG_INVALID = 106205 |  The input parameter for the color inversion capability is incorrect. For details about the error code, see [106205 Invalid Input Parameter for the Color Inversion Capability](../apis-arkui/errorcode-force-dark.md#106205-invalid-input-parameter-for-the-color-inversion-capability).<br>**Since**: 20|
| ARKUI_ERROR_CODE_NODE_IS_ADOPTED = 106206 |  The node has been accepted as an auxiliary node. For details about the error code, see [106206 The Node Has Been Accepted as an Auxiliary Node](../apis-arkui/errorcode-adopt.md#106206-the-node-has-been-accepted-as-an-auxiliary-node).<br>**Since**: 22|
| ARKUI_ERROR_CODE_NODE_HAS_PARENT = 106207 |  The accepted node already has a parent node. For details about the error code, see [106207 The Auxiliary Node to Accept Has a Parent Node](../apis-arkui/errorcode-adopt.md#106207-the-auxiliary-node-to-accept-has-a-parent-node).<br>**Since**: 22|
| ARKUI_ERROR_CODE_NODE_CAN_NOT_BE_ADOPTED = 106208 |  The node cannot be accepted as an auxiliary node. For details about the error code, see [106208 The Node Cannot Be Accepted as an Auxiliary Node](../apis-arkui/errorcode-adopt.md#106208-the-node-cannot-be-accepted-as-an-auxiliary-node).<br>**Since**: 22|
| ARKUI_ERROR_CODE_NODE_CAN_NOT_ADOPT_TO = 106209 |  The node cannot accept other nodes. For details about the error code, see [106209 The Node Cannot Accept Other Nodes](../apis-arkui/errorcode-adopt.md#106209-the-node-cannot-accept-other-nodes).<br>**Since**: 22|
| ARKUI_ERROR_CODE_NODE_IS_NOT_IN_ADOPTED_CHILDREN = 106210 |  The node is not an auxiliary node accepted by the target node. For details about the error code, see [106210 The Node Is Not an Affiliated Node Accepted by the Target Node](../apis-arkui/errorcode-adopt.md#106210-the-node-is-not-an-affiliated-node-accepted-by-the-target-node).<br>**Since**: 22|
| ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401 |  The current node is not a custom node. For details, see [Render Node Error Codes](../apis-arkui/errorcode-node-render.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_CHILD_EXISTED = 106402 |  The current node already has child nodes. For details, see [Render Node Error Codes](../apis-arkui/errorcode-node-render.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403 |  The current render node has a parent component. For details, see [Render Node Error Codes](../apis-arkui/errorcode-node-render.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404 |  Corresponding render child node not found. For details, see [Render Node Error Codes](../apis-arkui/errorcode-node-render.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405 |  The parameter value is out of range. For details, see [Render Node Error Codes](../apis-arkui/errorcode-node-render.md).<br>**Since**: 20|
| ARKUI_ERROR_CODE_RENDER_IS_FROM_FRAME_NODE = 106406 |  The current render node is obtained from a [FrameNode](js-apis-arkui-frameNode.md). For details about the error code, see [106406 Current Render Node Is Obtained from FrameNode](../apis-arkui/errorcode-node-render.md#106406-current-render-node-is-obtained-from-framenode).<br>**Since**: 22|
| ARKUI_ERROR_CODE_RENDER_HAS_INVALID_FRAME_NODE = 106407 |  The current render node is obtained from a [FrameNode](js-apis-arkui-frameNode.md) and the [FrameNode](js-apis-arkui-frameNode.md) has not been adopted as an affiliated node or has been disposed of. For details about the error code, see [106407 Current Render Node Is Obtained from FrameNode and the FrameNode Is Disposed or No Longer Adopted](../apis-arkui/errorcode-node-render.md#106407-current-render-node-is-obtained-from-framenode-and-the-framenode-is-disposed-or-no-longer-adopted).<br>**Since**: 22|
| ARKUI_ERROR_CODE_RENDER_NOT_ADOPTED_NODE = 106408 |  The current node is not in the adopted state. For details about the error code, see [106408 Current Node Is Not in Adopted State](../apis-arkui/errorcode-node-render.md#106408-current-node-is-not-in-adopted-state).<br>**Since**: 22|
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001 |  The current node is not focusable. For details about the error code, see [150001 Component Not Focusable](../apis-arkui/errorcode-focus.md#150001-component-not-focusable).<br>**Since**: 15|
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002 |  An ancestor of the current node is not focusable. For details about the error code, see [150002 Ancestor Component Not Focusable](../apis-arkui/errorcode-focus.md#150002-ancestor-component-not-focusable).<br>**Since**: 15|
| ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003 |  The current node does not exist. For details about the error code, see [150003 Component Does Not Exist](../apis-arkui/errorcode-focus.md#150003-component-does-not-exist).<br>**Since**: 15|
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002 |  Snapshot timed out. For details, see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_MODE_NOT_SUPPORTED = 160003 | The provided color space or dynamic range mode is not supported. For details, see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).<br>**Since**: 23|
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_AUTO_NOT_SUPPORTED = 160004 | The **isAuto** setting of the color space or dynamic range mode is not supported for offscreen node snapshots. For details, see [Snapshot Error Codes](../apis-arkui/errorcode-snapshot.md).<br>**Since**: 23|
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001 | The component is not a scrollable container. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002 | The buffer is not large enough. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).|
| ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003 |  The event is not a cloned event. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004 |  The component status is abnormal. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005 |  No component hit to respond to the event. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 15|
| ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006 |  Input event type not supported.<br>**Since**: 20|
| ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101 |  Invalid styled string. For details, see [Styled String Error Codes](../apis-arkui/errorcode-styled-string.md).<br>**Since**: 14|
| ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001 |  Invalid UIContext object. For details, see [UI Context Error Codes](../apis-arkui/errorcode-uicontext.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002 |  Invalid callback function. For details, see [UI Context Error Codes](../apis-arkui/errorcode-uicontext.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102 |  The gesture recognizer type is not supported. For details, see [Interaction Event Error Codes](../apis-arkui/errorcode-event.md).<br>**Since**: 18|
| ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004 |  The operation is not allowed in the current phase. For details, see [Drag Event Error Codes](../apis-arkui/errorcode-drag-event.md).<br>**Since**: 19|

### ArkUI_ScrollSource

```c
enum ArkUI_ScrollSource
```

**Description**


Enumerates scroll sources.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_SOURCE_DRAG = 0 | Finger dragging.|
| ARKUI_SCROLL_SOURCE_FLING = 1 | Inertia scrolling after finger dragging.|
| ARKUI_SCROLL_SOURCE_EDGE_EFFECT = 2 | [EdgeEffect.Spring](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect) for boundary crossing.|
| ARKUI_SCROLL_SOURCE_OTHER_USER_INPUT = 3 | User input other than dragging, such as mouse wheel and keyboard events.|
| ARKUI_SCROLL_SOURCE_SCROLL_BAR = 4 | Scrollbar dragging.|
| ARKUI_SCROLL_SOURCE_SCROLL_BAR_FLING = 5 | Inertial scrolling after scrollbar dragging.|
| ARKUI_SCROLL_SOURCE_SCROLLER = 6 | Scrolling by the scroll controller (without animation).|
| ARKUI_SCROLL_SOURCE_ANIMATION = 7 | Scrolling by the scroll controller (with animation).|

### ArkUI_SafeAreaType

```c
enum ArkUI_SafeAreaType
```

**Description**


Enumerates the types of expanded safe areas.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SAFE_AREA_TYPE_SYSTEM = 1 | Default non-safe area of the system, including the status bar and navigation bar. This is the default value.|
| ARKUI_SAFE_AREA_TYPE_CUTOUT = 1 << 1 | Non-safe area of the device, for example, the notch area.|
| ARKUI_SAFE_AREA_TYPE_KEYBOARD = 1 << 2 | Soft keyboard area.|

### ArkUI_SafeAreaEdge

```c
enum ArkUI_SafeAreaEdge
```

**Description**


Enumerates the edges for expanding the safe area.

**Since**: 12

| Value| Description|
| -- | -- |
| ARKUI_SAFE_AREA_EDGE_TOP = 1 | Top edge. This is the default value.|
| ARKUI_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | Bottom edge.|
| ARKUI_SAFE_AREA_EDGE_START = 1 << 2 | Start edge.|
| ARKUI_SAFE_AREA_EDGE_END = 1 << 3 | End edge.|

### ArkUI_ListItemGroupArea

```c
enum ArkUI_ListItemGroupArea
```

**Description**


Enumerates the areas in the [ListItemGroup](./arkui-ts/ts-container-listitemgroup.md) component. The default value is **ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE**.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_LIST_ITEM_GROUP_AREA_OUTSIDE = 0 | Outside the area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_NONE = 1 | Area without the [header](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions), [footer](./arkui-ts/ts-container-listitemgroup.md#listitemgroupoptions), and [ListItem](./arkui-ts/ts-container-listitem.md#listitem10) in the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_ITEM = 2 | List item area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_HEADER = 3 | Header area of the **ListItemGroup** component.|
| ARKUI_LIST_ITEM_SWIPE_AREA_FOOTER = 4 | Footer area of the **ListItemGroup** component.|

### ArkUI_KeyboardAvoidMode

```c
enum ArkUI_KeyboardAvoidMode
```

**Description**


Enumerates the soft keyboard avoidance modes.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_KEYBOARD_AVOID_MODE_DEFAULT = 0 | Automatically avoids the soft keyboard and compresses the height when reaching the maximum limit.|
| ARKUI_KEYBOARD_AVOID_MODE_NONE = 1 | The layout is not adjusted to avoid the keyboard.|

### ArkUI_HoverModeAreaType

```c
enum ArkUI_HoverModeAreaType
```

**Description**


Enumerates the types of display areas for the hover mode.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_HOVER_MODE_AREA_TYPE_TOP = 0 | Upper half screen.|
| ARKUI_HOVER_MODE_AREA_TYPE_BOTTOM = 1 | Lower half screen.|

### ArkUI_ExpandMode

```c
enum ArkUI_ExpandMode
```

**Description**


Enumerates the expansion mode of child nodes.

**Since**: 15

| Value| Description|
| -- | -- |
| ARKUI_NOT_EXPAND = 0 | Child nodes are not expanded.|
| ARKUI_EXPAND = 1 | Child nodes are expanded immediately upon rendering.|
| ARKUI_LAZY_EXPAND = 2 | Lazy expansion, indicating that child nodes are only expanded when needed. For details about the node expansion conditions, see [LazyForEach: Lazy Data Loading](../../ui/rendering-control/arkts-rendering-control-lazyforeach.md).|

### ArkUI_FocusWrapMode

```c
enum ArkUI_FocusWrapMode
```

**Description**


Enumerates the focus wrap mode of components. The default value is **ARKUI_FOCUS_WRAP_MODE_DEFAULT** for the **Grid** and **List** components.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_FOCUS_WRAP_MODE_DEFAULT = 0 | Default mode, where focus does not wrap when arrow keys are used.|
| ARKUI_FOCUS_WRAP_WITH_ARROW = 1 | Auto mode, where focus wraps automatically when arrow keys are used.|

### ArkUI_ItemFillPolicy

```c
enum ArkUI_ItemFillPolicy
```

**Description**


Enumerates column count policies for different [responsive breakpoints](../../ui/arkts-layout-development-grid-layout.md#breakpoints).

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_ITEMFILLPOLICY_NONE = -1 | No responsive breakpoint policy is set.|
| ARKUI_ITEMFILLPOLICY_DEFAULT = 0 | **List** or **Swiper** component: 1 column (SM or smaller), 2 columns (MD), 3 columns (LG or larger).<br> **Grid** or **WaterFlow** component: 2 columns (SM or smaller), 3 columns (MD), 5 columns (LG or larger).|
| ARKUI_ITEMFILLPOLICY_SM1MD2LG3 = 1 | 1 column (SM or smaller), 2 columns (MD), 3 columns (LG or larger).|
| ARKUI_ITEMFILLPOLICY_SM2MD3LG5 = 2 | 2 columns (SM or smaller), 3 columns (MD), 5 columns (LG or larger).|

### ArkUI_ScrollSnapAnimationSpeed

```c
enum ArkUI_ScrollSnapAnimationSpeed
```

**Description**


Enumerates scroll snap animation speeds for list components.

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_SCROLL_SNAP_ANIMATION_NORMAL = 0 | Normal scroll snap animation speed.|
| ARKUI_SCROLL_SNAP_ANIMATION_SLOW = 1 | Slow scroll snap animation speed.|

### ArkUI_EdgeDirection

```c
enum ArkUI_EdgeDirection
```

**Description**


Enumerates rectangle edge directions.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_EDGE_DIRECTION_ALL = 0 | All four edges.|
| ARKUI_EDGE_DIRECTION_LEFT = 1 << 0 | Left edge.|
| ARKUI_EDGE_DIRECTION_RIGHT = 1 << 1 | Right edge.|
| ARKUI_EDGE_DIRECTION_TOP = 1 << 2 | Top edge.|
| ARKUI_EDGE_DIRECTION_BOTTOM = 1 << 3 | Bottom edge.|

### ArkUI_CornerDirection

```c
enum ArkUI_CornerDirection
```

**Description**


Enumerates corner directions.

**Since**: 20

| Value| Description|
| -- | -- |
| ARKUI_CORNER_DIRECTION_ALL = 0 | All four corners.|
| ARKUI_CORNER_DIRECTION_TOP_LEFT = 1 << 0 | Upper left corner.|
| ARKUI_CORNER_DIRECTION_TOP_RIGHT = 1 << 1 | Upper right corner.|
| ARKUI_CORNER_DIRECTION_BOTTOM_LEFT = 1 << 2 | Lower left corner.|
| ARKUI_CORNER_DIRECTION_BOTTOM_RIGHT = 1 << 3 | Lower right corner.|

### ArkUI_LayoutPolicy

```c
enum ArkUI_LayoutPolicy
```

**Description**

Enumerates layout policies.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_LAYOUTPOLICY_MATCHPARENT = 0 | The component size matches parent container dimensions.|
| ARKUI_LAYOUTPOLICY_WRAPCONTENT = 1 | The component size wraps its content, constrained by parent container bounds.|
| ARKUI_LAYOUTPOLICY_FIXATIDEALSIZE = 2 | The component size wraps its content, unconstrained by parent container bounds.|

### ArkUI_PixelRoundCalcPolicy

```c
enum ArkUI_PixelRoundCalcPolicy
```

**Description**

Enumerates pixel rounding calculation policies.

**Since**: 21

| Value| Description|
| -- | -- |
| ARKUI_PIXELROUNDCALCPOLICY_NOFORCEROUND = 0 | No forced rounding calculation.|
| ARKUI_PIXELROUNDCALCPOLICY_FORCECEIL = 1 | Round-up calculation.|
| ARKUI_PIXELROUNDCALCPOLICY_FORCEFLOOR = 2 | Round-down calculation.|

### ArkUI_GridItemAlignment

```c
enum ArkUI_GridItemAlignment
```
**Description**

Enumerates the alignment modes of the [GridItem](../apis-arkui/arkui-ts/ts-container-griditem.md) component.

**Since**: 22

| Value| Description|
| -- | -- |
| GRID_ITEM_ALIGNMENT_DEFAULT = 0 | Use the default alignment mode of the grid.|
| GRID_ITEM_ALIGNMENT_STRETCH  = 1  | Use the height of the tallest grid item in a row as the height for all other grid items in that row.|


### ArkUI_GridItemStyle

```c
enum ArkUI_GridItemStyle
```

**Description**


Enumerates styles of grid items.

**Since**: 22

| Value| Description|
| -- | -- |
| GRID_ITEM_STYLE_NONE  = 0 | No style.|
| GRID_ITEM_STYLE_PLAIN  = 1  | Hover or press style.|

### ArkUI_MenuPolicy

```c
enum ArkUI_MenuPolicy
```

**Description**

Enumerates menu display policies.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_MENU_POLICY_DEFAULT  = 0 | Whether the menu is displayed depends on the underlying default logic.|
| ARKUI_MENU_POLICY_HIDE = 1 | The menu is not popped up.|
| ARKUI_MENU_POLICY_SHOW = 2 | The menu is popped up.|

### ArkUI_TextMenuItemId

```c
enum ArkUI_TextMenuItemId
```

**Description**

Enumerates the IDs of text menu items.

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_TEXT_MENU_ITEM_ID_CUT = 0 | Clip.|
| ARKUI_TEXT_MENU_ITEM_ID_COPY = 1 | Copy.|
| ARKUI_TEXT_MENU_ITEM_ID_PASTE = 2 | Paste.|
| ARKUI_TEXT_MENU_ITEM_ID_SELECT_ALL = 3 | Select all.|
| ARKUI_TEXT_MENU_ITEM_ID_COLLABORATION_SERVICE = 4 | Collaboration service. For example, cross-device interaction, including cross-device camera access.|
| ARKUI_TEXT_MENU_ITEM_ID_CAMERA_INPUT = 5 | Camera input.|
| ARKUI_TEXT_MENU_ITEM_ID_AI_WRITER = 6 | AI-assisted writing. This menu item requires the large language model. If no large language model is available, this menu item does not take effect.|
| ARKUI_TEXT_MENU_ITEM_ID_TRANSLATE = 7 | Translate. The translation service is provided for the selected text.|
| ARKUI_TEXT_MENU_ITEM_ID_SEARCH = 8 | Search. This menu item launches a browser to search for the selected text.|
| ARKUI_TEXT_MENU_ITEM_ID_SHARE = 9 | Share. This menu item launches a window for sharing the selected text.|
| ARKUI_TEXT_MENU_ITEM_ID_URL = 10 | Open a link. This menu item provides the redirection service for the selected URL, launching a browser search or application page.|
| ARKUI_TEXT_MENU_ITEM_ID_EMAIL = 11 | New Email. This menu item provides the redirection service for the selected email address, launching the email application.|
| ARKUI_TEXT_MENU_ITEM_ID_PHONE_NUMBER = 12 | Call. This menu item provides the redirection service for the selected phone number, launching the phone dialer page.|
| ARKUI_TEXT_MENU_ITEM_ID_ADDRESS = 13 | Navigate. This menu item provides the redirection service for the selected address, launching the map application.|
| ARKUI_TEXT_MENU_ITEM_ID_DATA_TIME = 14 | New event. This menu item provides the redirection service for the selected date and time, launching the page for creating a calendar event.|
| ARKUI_TEXT_MENU_ITEM_ID_ASK_AI = 15 | Ask AI. This menu item provides the AI query capability for the selected text.|
| ARKUI_TEXT_MENU_ITEM_ID_AUTO_FILL = 16 | Autofill. For example, the account and password can be automatically filled.<br>**Since**: 24|
| ARKUI_TEXT_MENU_ITEM_ID_PASSWORD_VAULT = 17 | Password vault.<br>**Since**: 24|
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_BEGIN = 10000 | Start ID of a custom menu item. In addition to the built-in menu item IDs, you can also customize menu item IDs.|
| ARKUI_TEXT_MENU_ITEM_ID_APP_RESERVED_END = 20000 | End ID of a custom menu item. In addition to the built-in menu item IDs, you can also customize menu item IDs.|

### ArkUI_TextSpanType

```c
enum ArkUI_TextSpanType
```

**Description**

Enumerates the recognition types of a custom text selection menu.

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_TEXT_SPAN_TYPE_TEXT = 0 | Text.|
| ARKUI_TEXT_SPAN_TYPE_IMAGE = 1 | Image.|
| ARKUI_TEXT_SPAN_TYPE_MIXED = 2 | Mixed text and image.|
| ARKUI_TEXT_SPAN_TYPE_DEFAULT = 3 | If this type and other types are set, the menu corresponding to the type of the selected text is displayed after the text is selected. If this type is set but other types are not set, the menu corresponding to this type is displayed after the text is selected. For example, if there are two menus whose recognition types are **ARKUI_TEXT_SPAN_TYPE_TEXT** and **ARKUI_TEXT_SPAN_TYPE_DEFAULT** respectively, the menu corresponding to **ARKUI_TEXT_SPAN_TYPE_TEXT** is displayed when the text is selected, and the menu corresponding to **ARKUI_TEXT_SPAN_TYPE_DEFAULT** is displayed when the image is selected.|

### ArkUI_TextResponseType

```c
enum ArkUI_TextResponseType
```

**Description**

Enumerates the response types of a custom text selection menu.

**Since**: 22

| Value| Description|
| -- | -- |
| ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK = 0 | The menu is displayed when the component is right-clicked.|
| ARKUI_TEXT_RESPONSE_TYPE_LONG_PRESS = 1 | The menu is displayed when the component is long-pressed.|
| ARKUI_TEXT_RESPONSE_TYPE_SELECT = 2 | The menu is displayed when the component is selected.|
| ARKUI_TEXT_RESPONSE_TYPE_DEFAULT = 3 | If this type and other types are set, the menu corresponding to the type is displayed when the operation of another type is triggered. If this type is set but other types are not set, the menu corresponding to this type is displayed when an operation of another type is triggered. For example, if there are two menus whose response types are **ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK** and **ARKUI_TEXT_RESPONSE_TYPE_DEFAULT** respectively, the menu corresponding to **ARKUI_TEXT_RESPONSE_TYPE_RIGHT_CLICK** is displayed when you right-click the menu, and the menu corresponding to **ARKUI_TEXT_RESPONSE_TYPE_DEFAULT** is displayed when you hold down the right mouse button.|

### ArkUI_MarqueeStartPolicy
```c
enum ArkUI_MarqueeStartPolicy
```

**Description**

Defines the start policy of a marquee.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_MARQUEESTARTPOLICY_DEFAULT = 0 | The marquee scrolls continuously by default.|
| ARKUI_MARQUEESTARTPOLICY_ONFOCUS = 1 | The marquee scrolls when the focus is obtained or the mouse pointer is hovered over.|

### ArkUI_MarqueeUpdatePolicy
```c
enum ArkUI_MarqueeUpdatePolicy
```

**Description**

Defines the update policy of a marquee.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_MARQUEEUPDATEPOLICY_DEFAULT = 0 | After the marquee attributes are updated, the marquee scrolls from the start position.|
| ARKUI_MARQUEEUPDATEPOLICY_PRESERVEPOSITION = 1 | After the marquee attributes are updated, the marquee scrolls from the current position.|

### ArkUI_LayoutSafeAreaType

```c
enum ArkUI_LayoutSafeAreaType
```

**Description**


Enumerates the types of expanded safe areas.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_LAYOUT_SAFE_AREA_TYPE_SYSTEM = 1 | Default non-safe area of the system, including the status bar and navigation bar.|

### ArkUI_LayoutSafeAreaEdge

```c
enum ArkUI_LayoutSafeAreaEdge
```

**Description**


Enumerates the edges for expanding the safe area.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP = 1 | Top edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM = 1 << 1 | Bottom edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_START = 1 << 2 | Start edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_END = 1 << 3 | End edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_TOP \| ARKUI_LAYOUT_SAFE_AREA_EDGE_BOTTOM = 3 | Vertical edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL = ARKUI_LAYOUT_SAFE_AREA_EDGE_START \| ARKUI_LAYOUT_SAFE_AREA_EDGE_END = 12 | Horizontal edge.|
| ARKUI_LAYOUT_SAFE_AREA_EDGE_ALL = ARKUI_LAYOUT_SAFE_AREA_EDGE_VERTICAL \| ARKUI_LAYOUT_SAFE_AREA_EDGE_HORIZONTAL = 15 | All edges.|

### ArkUI_LocalizedAlignment

```c
enum ArkUI_LocalizedAlignment
```

**Description**


Defines the alignment rules of child components in a **Stack** container.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_LOCALIZED_ALIGNMENT_TOP_START = 0 | Top start.|
| ARKUI_LOCALIZED_ALIGNMENT_TOP = 1 | Top center.|
| ARKUI_LOCALIZED_ALIGNMENT_TOP_END = 2 | Top end.|
| ARKUI_LOCALIZED_ALIGNMENT_START = 3 | Vertically centered start.|
| ARKUI_LOCALIZED_ALIGNMENT_CENTER = 4 | Horizontally and vertically centered.|
| ARKUI_LOCALIZED_ALIGNMENT_END = 5 | Vertically centered end.|
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_START = 6 | Bottom start.|
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM = 7 | Horizontally centered on the bottom.|
| ARKUI_LOCALIZED_ALIGNMENT_BOTTOM_END = 8 | Bottom end.|

### ArkUI_RenderStrategy

```c
enum ArkUI_RenderStrategy
```

**Description**


Enumerates strategies for drawing rounded corners.

**Since**: 23

| Value| Description|
| -- | -- |
| ARKUI_RENDERSTRATEGY_FAST  = 0 | Online drawing mode.|
| ARKUI_RENDERSTRATEGY_OFFSCREEN = 1 | Off-screen drawing mode.|

### OH_ArkUI_HapticFeedbackMode

```c
enum OH_ArkUI_HapticFeedbackMode
```

**Description**

Enumerates vibration effect types.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_DISABLED = 0 | No vibration.|
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_ENABLED = 1 | Vibration.|
| OH_ARKUI_HAPTIC_FEEDBACK_MODE_AUTO = 2 | System vibration.|

### OH_ArkUI_TextEditorSpanType

```c
enum OH_ArkUI_TextEditorSpanType
```

**Description**

Enumerates the span types of a custom text selection menu.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_TEXT = 0 | Text span.|
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_IMAGE = 1 | Image span.|
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_MIXED = 2 | Mixed span.|
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_BUILDER = 3 | Custom layout span.|
| OH_ARKUI_TEXT_EDITOR_SPAN_TYPE_DEFAULT = 4 | Default span.|

### OH_ArkUI_TextEditorResponseType

```c
enum OH_ArkUI_TextEditorResponseType
```

**Description**

Enumerates the response types of a custom text selection menu.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_RIGHT_CLICK = 0 | The menu is displayed when the component is right-clicked.|
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_LONG_PRESS = 1 | The menu is displayed when the component is long-pressed.|
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_SELECT = 2 | The menu is displayed when the component is selected.|
| OH_ARKUI_TEXT_EDITOR_RESPONSE_TYPE_DEFAULT = 3 | Default response type.|

### OH_ArkUI_TextMenuType

```c
enum OH_ArkUI_TextMenuType
```

**Description**

Enumerates text menu types.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_ARKUI_TEXT_EDITOR_SELECTION_MENU = 0 | Text selection menu.|
| OH_ARKUI_TEXT_EDITOR_PREVIEW_MENU = 1 | Preview menu.|

### OH_ArkUI_LineBreakStrategy

```c
enum OH_ArkUI_LineBreakStrategy
```

**Description**

Enumerates line break policies.

**Since**: 24

| Value| Description|
| -- | -- |
| OH_ARKUI_LINE_BREAK_STRATEGY_GREEDY = 0 | Greedy mode.<br>Places as many words on a line as possible and moves to the next line only if no more words can fit into the same line.|
| OH_ARKUI_LINE_BREAK_STRATEGY_HIGH_QUALITY = 1 | High-quality mode.<br>Fills in lines as much as possible on the basis of **BALANCED**, which may results in a large blank area on the last line.|
| OH_ARKUI_LINE_BREAK_STRATEGY_BALANCE = 2 | Balance mode.<br>Without splitting words, the width of each line in a paragraph is the same as much as possible.|

### ArkUI_RawInputEventType

```c
enum ArkUI_RawInputEventType
```

**Description**

Enumerates the types of raw input events.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| ARKUI_RAW_INPUT_EVENT_TYPE_TOUCH = 0 | Touch event.|
| ARKUI_RAW_INPUT_EVENT_TYPE_MOUSE = 1 | Mouse event.|

### OH_ArkUI_CrossLanguageOperatingStatus

```c
enum OH_ArkUI_CrossLanguageOperatingStatus
```

**Description**

Enumerates the node tree operation states of cross-language configuration options.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| OH_ARKUI_TREE_OPERATING_STATUS_UNDEFINED = 0 | Undefined, which is the initial value of the node tree operation state. Nodes in this state do not support cross-language node tree operations.|
| OH_ARKUI_TREE_OPERATING_STATUS_ENABLE = 1 | Enabled, which indicates that when the configuration option is applied to a node, the node tree operation state of the node will be enabled.|
| OH_ARKUI_TREE_OPERATING_STATUS_DISABLE = 2 | Disabled, which indicates that when the configuration option is applied to a node, the node tree operation state of the node will be disabled.|

### OH_ArkUI_NodeMountPolicy

```c
enum OH_ArkUI_NodeMountPolicy
```
**Description**

Enumerates the child node mounting policy types.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| OH_ARKUI_NODE_MOUNT_POLICY_SINGLE_IF_RENDER_NODE = 0 | If a [RenderNode](./js-apis-arkui-renderNode.md) needs to be mounted as a child node, this RenderNode must be the only child node.|
| OH_ARKUI_NODE_MOUNT_POLICY_MIXED = 1 | Multiple [typeNodes](./js-apis-arkui-frameNode.md#typenode12) and RenderNodes can be mounted at the same time.|

## Function Description

### OH_ArkUI_LayoutConstraint_Create()

```c
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Create()
```

**Description**


Creates layout constraints.

**Since**: 12

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | Pointer to the created layout constraint.|

### OH_ArkUI_LayoutConstraint_Copy()

```c
ArkUI_LayoutConstraint* OH_ArkUI_LayoutConstraint_Copy(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Performs a deep copy of a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* | Pointer to the new layout constraint.|

### OH_ArkUI_LayoutConstraint_Dispose()

```c
void* OH_ArkUI_LayoutConstraint_Dispose(ArkUI_LayoutConstraint* Constraint)
```

**Description**


Disposes of a layout constraint pointer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type                         | Description|
|-----------------------------| -- |
| void* | Null pointer.|

### OH_ArkUI_LayoutConstraint_GetMaxWidth()

```c
int32_t OH_ArkUI_LayoutConstraint_GetMaxWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the maximum width using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum width, in pixels.|

### OH_ArkUI_LayoutConstraint_GetMinWidth()

```c
int32_t OH_ArkUI_LayoutConstraint_GetMinWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the minimum width using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum width, in px.|

### OH_ArkUI_LayoutConstraint_GetMaxHeight()

```c
int32_t OH_ArkUI_LayoutConstraint_GetMaxHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the maximum height using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum height, in px.|

### OH_ArkUI_LayoutConstraint_GetMinHeight()

```c
int32_t OH_ArkUI_LayoutConstraint_GetMinHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the minimum height using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum height, in px.|

### OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth()

```c
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceWidth(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the width percentage reference using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Width percentage reference.|

### OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight()

```c
int32_t OH_ArkUI_LayoutConstraint_GetPercentReferenceHeight(const ArkUI_LayoutConstraint* Constraint)
```

**Description**


Obtains the height percentage reference using a layout constraint.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Height percentage reference.|

### OH_ArkUI_LayoutConstraint_SetMaxWidth()

```c
void OH_ArkUI_LayoutConstraint_SetMaxWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the maximum width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Maximum width, in px. The value range is [0, +∞).|

### OH_ArkUI_LayoutConstraint_SetMinWidth()

```c
void OH_ArkUI_LayoutConstraint_SetMinWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the minimum width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Minimum width, in px. The value range is [0, +∞).|

### OH_ArkUI_LayoutConstraint_SetMaxHeight()

```c
void OH_ArkUI_LayoutConstraint_SetMaxHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the maximum height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Maximum height, in px. The value range is [0, +∞).|

### OH_ArkUI_LayoutConstraint_SetMinHeight()

```c
void OH_ArkUI_LayoutConstraint_SetMinHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the minimum height.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Minimum height, in px. The value range is [0, +∞).|

### OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth()

```c
void OH_ArkUI_LayoutConstraint_SetPercentReferenceWidth(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the width percentage reference.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Width percentage reference. The value range is [0, +∞).|

### OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight()

```c
void OH_ArkUI_LayoutConstraint_SetPercentReferenceHeight(ArkUI_LayoutConstraint* Constraint, int32_t value)
```

**Description**


Sets the height percentage reference.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md)* Constraint | Pointer to the layout constraint.|
| int32_t value | Height percentage reference. The value range is [0, +∞).|

### OH_ArkUI_DrawContext_GetCanvas()

```c
void* OH_ArkUI_DrawContext_GetCanvas(ArkUI_DrawContext* context)
```

**Description**


Obtains the pointer to the canvas for drawing, which can be converted into the [OH_Drawing_Canvas](../apis-arkgraphics2d/capi-drawing-oh-drawing-canvas.md) pointer of the graphics library for drawing.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | Pointer to the drawing context.|

**Returns**

| Type| Description|
| -- | -- |
| void* | Pointer to the canvas for drawing.|

### OH_ArkUI_DrawContext_GetSize()

```c
ArkUI_IntSize OH_ArkUI_DrawContext_GetSize(ArkUI_DrawContext* context)
```

**Description**


Obtains the size of a drawing area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md)* context | Pointer to the drawing context.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | Size of the drawing area.|

### OH_ArkUI_WaterFlowSectionOption_Create()

```c
ArkUI_WaterFlowSectionOption* OH_ArkUI_WaterFlowSectionOption_Create()
```

**Description**


Creates the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since**: 12

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|

### OH_ArkUI_WaterFlowSectionOption_Dispose()

```c
void OH_ArkUI_WaterFlowSectionOption_Dispose(ArkUI_WaterFlowSectionOption* option)
```

**Description**


Disposes of the pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|

### OH_ArkUI_WaterFlowSectionOption_SetSize()

```c
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

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetSize(ArkUI_WaterFlowSectionOption* option)
```

**Description**


Obtains the length of the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration array.

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

```c
void OH_ArkUI_WaterFlowSectionOption_SetItemCount(ArkUI_WaterFlowSectionOption* option,int32_t index, int32_t itemCount)
```

**Description**


Sets the number of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) in the section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|
| int32_t itemCount | Number of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) in the section.|

### OH_ArkUI_WaterFlowSectionOption_GetItemCount()

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetItemCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the number of [water flow items](../apis-arkui/arkui-ts/ts-container-flowitem.md) at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of items in the water flow section.|

### OH_ArkUI_WaterFlowSectionOption_SetCrossCount()

```c
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

```c
int32_t OH_ArkUI_WaterFlowSectionOption_GetCrossCount(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the number of layout grids at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

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

```c
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
| float columnGap | Gap between columns. Unit: vp.|

### OH_ArkUI_WaterFlowSectionOption_GetColumnGap()

```c
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
| float | Gap between columns. Unit: vp.|

### OH_ArkUI_WaterFlowSectionOption_SetRowGap()

```c
void OH_ArkUI_WaterFlowSectionOption_SetRowGap(ArkUI_WaterFlowSectionOption* option,int32_t index, float rowGap)
```

**Description**


Sets the gap between rows in the **FlowItem** section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to a water flow section configuration.|
| int32_t index | Index of the **FlowItem** section configuration array.|
| float rowGap | Gap between rows. Unit: vp.|

### OH_ArkUI_WaterFlowSectionOption_GetRowGap()

```c
float OH_ArkUI_WaterFlowSectionOption_GetRowGap(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the gap between rows in the section at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| float | Gap between rows. Unit: vp.|

### OH_ArkUI_WaterFlowSectionOption_SetMargin()

```c
void OH_ArkUI_WaterFlowSectionOption_SetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index,float marginTop, float marginRight, float marginBottom, float marginLeft)
```

**Description**


Sets the margins for the specified water flow section.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|
| float marginTop | Top margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md).|
| float marginRight | Right margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md).|
| float marginBottom | Bottom margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md).|
| float marginLeft | Left margin of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md).|

### OH_ArkUI_WaterFlowSectionOption_GetMargin()

```c
ArkUI_Margin OH_ArkUI_WaterFlowSectionOption_GetMargin(ArkUI_WaterFlowSectionOption* option, int32_t index)
```

**Description**


Obtains the top margin of the section at the corresponding index based on the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_Margin](capi-arkui-nativemodule-arkui-margin.md) | Margins. Unit: vp.|

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex(ArkUI_WaterFlowSectionOption* option,int32_t index, float(*callback)(int32_t itemIndex))
```

**Description**


Obtains the main axis size of a specified water flow item based on **itemIndex** in the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. To use custom data in the callback, call [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindexwithuserdata).

**Since**: 12


**Parameters**

| Name                                           | Description|
|------------------------------------------------| -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index                                  | Index of the target water flow section.|
| callback                                       | Callback used to return the result. **itemIndex** indicates the index of [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md).|

### OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData()

```c
void OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndexWithUserData(ArkUI_WaterFlowSectionOption* option, int32_t index, void* userData,float (*callback)(int32_t itemIndex, void* userData))
```

**Description**


Obtains the main axis size of a specified water flow item based on **itemIndex** in the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration. The difference between this API and [OH_ArkUI_WaterFlowSectionOption_RegisterGetItemMainSizeCallbackByIndex](#oh_arkui_waterflowsectionoption_registergetitemmainsizecallbackbyindex) is that this API allows you to pass custom data (**userData**) and receive the data in the callback function.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_WaterFlowSectionOption](capi-arkui-nativemodule-arkui-waterflowsectionoption.md)* option | Pointer to the [FlowItem](../apis-arkui/arkui-ts/ts-container-flowitem.md) section configuration.|
| int32_t index | Index of the target water flow section.|
|  void* userData |Pointer to user-defined data, which will be passed back to the user in the callback.|
| callback | Callback used to return the result. **itemIndex**: index of the [water flow item](../apis-arkui/arkui-ts/ts-container-flowitem.md); **userData**: user-defined data.|

### OH_ArkUI_GuidelineOption_Create()

```c
ArkUI_GuidelineOption* OH_ArkUI_GuidelineOption_Create(int32_t size)
```

**Description**


Creates guideline options in [RelativeContainer](..//apis-arkui/arkui-ts/ts-container-relativecontainer.md).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Number of guidelines. The value range is [0, +∞).|

**Returns**

| Type                        | Description|
|----------------------------| -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* | Pointer to a guideline configuration.|

### OH_ArkUI_GuidelineOption_Dispose()

```c
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

```c
void OH_ArkUI_GuidelineOption_SetId(ArkUI_GuidelineOption* guideline, const char* value, int32_t index)
```

**Description**


Sets the ID of a guideline.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| const char* value | Pointer to the ID, which must be unique and cannot be the same as the name of any component in the container.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_SetDirection()

```c
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

```c
void OH_ArkUI_GuidelineOption_SetPositionStart(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**


Sets the distance between a guideline and the left or top of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| float value | Distance between a guideline and the left or top edge of the container, in vp.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_SetPositionEnd()

```c
void OH_ArkUI_GuidelineOption_SetPositionEnd(ArkUI_GuidelineOption* guideline, float value, int32_t index)
```

**Description**


Sets the distance between a guideline and the right or bottom of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| float value | Distance between a guideline and the right or bottom edge of the container, in vp.|
| int32_t index | Index of the guideline.|

### OH_ArkUI_GuidelineOption_GetId()

```c
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
| const char* | Pointer to the ID of the guideline.|

### OH_ArkUI_GuidelineOption_GetDirection()

```c
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

```c
float OH_ArkUI_GuidelineOption_GetPositionStart(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the distance between the guideline and the left or top of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the guideline and the left or top of the container. The unit is vp.|

### OH_ArkUI_GuidelineOption_GetPositionEnd()

```c
float OH_ArkUI_GuidelineOption_GetPositionEnd(ArkUI_GuidelineOption* guideline, int32_t index)
```

**Description**


Obtains the distance between the guideline and the right or bottom of the container.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GuidelineOption](capi-arkui-nativemodule-arkui-guidelineoption.md)* guideline | Pointer to a guideline configuration.|
| int32_t index | Index of the guideline.|

**Returns**

| Type| Description|
| -- | -- |
| float | Distance between the guideline and the right or bottom of the container. The unit is vp.|

### OH_ArkUI_BarrierOption_Create()

```c
ArkUI_BarrierOption* OH_ArkUI_BarrierOption_Create(int32_t size)
```

**Description**


Creates a barrier configuration for this **RelativeContainer** component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Number of barriers. The value range is [0, +∞).|

**Returns**

| Type                      | Description|
|--------------------------| -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* | Pointer to the barrier configuration.|

### OH_ArkUI_BarrierOption_Dispose()

```c
void OH_ArkUI_BarrierOption_Dispose(ArkUI_BarrierOption* barrierStyle)
```

**Description**


Disposes of a barrier configuration.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|

### OH_ArkUI_BarrierOption_SetId()

```c
void OH_ArkUI_BarrierOption_SetId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**


Sets the ID of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| const char* value | Pointer to the ID, which must be unique and cannot be the same as the name of any component in the container.|
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_SetDirection()

```c
void OH_ArkUI_BarrierOption_SetDirection(ArkUI_BarrierOption* barrierStyle, ArkUI_BarrierDirection value, int32_t index)
```

**Description**


Sets the direction of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) value | Direction. |
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_SetReferencedId()

```c
void OH_ArkUI_BarrierOption_SetReferencedId(ArkUI_BarrierOption* barrierStyle, const char* value, int32_t index)
```

**Description**


Sets the referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| const char* value | Pointer to the referenced component IDs.|
| int32_t index | Index of the barrier.|

### OH_ArkUI_BarrierOption_GetId()

```c
const char* OH_ArkUI_BarrierOption_GetId(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the ID of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| int32_t index | Index of the barrier.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the barrier.|

### OH_ArkUI_BarrierOption_GetDirection()

```c
ArkUI_BarrierDirection OH_ArkUI_BarrierOption_GetDirection(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the direction of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| int32_t index | Index of the barrier.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_BarrierDirection](capi-native-type-h.md#arkui_barrierdirection) | Direction of the barrier.|

### OH_ArkUI_BarrierOption_GetReferencedId()

```c
const char* OH_ArkUI_BarrierOption_GetReferencedId(ArkUI_BarrierOption* barrierStyle, int32_t index , int32_t referencedIndex)
```

**Description**


Obtains the referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| int32_t index | Index of the barrier.|
| int32_t referencedIndex | Index of the referenced component ID.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the referenced components of the barrier.|

### OH_ArkUI_BarrierOption_GetReferencedIdSize()

```c
int32_t OH_ArkUI_BarrierOption_GetReferencedIdSize(ArkUI_BarrierOption* barrierStyle, int32_t index)
```

**Description**


Obtains the number of referenced components of a barrier.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_BarrierOption](capi-arkui-nativemodule-arkui-barrieroption.md)* barrierStyle | Pointer to the barrier configuration.|
| int32_t index | Index of the barrier.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of referenced components of the barrier.|

### OH_ArkUI_AlignmentRuleOption_Create()

```c
ArkUI_AlignmentRuleOption* OH_ArkUI_AlignmentRuleOption_Create()
```

**Description**


Creates an alignment rule configuration for this **RelativeContainer** component.

**Since**: 12

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* | Pointer to the alignment rule information.|

### OH_ArkUI_AlignmentRuleOption_Dispose()

```c
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

```c
void OH_ArkUI_AlignmentRuleOption_SetStart(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the left alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id                                                                            | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment                         | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetEnd()

```c
void OH_ArkUI_AlignmentRuleOption_SetEnd(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the right alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal()

```c
void OH_ArkUI_AlignmentRuleOption_SetCenterHorizontal(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_HorizontalAlignment alignment)
```

**Description**


Sets the horizontal center alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_HorizontalAlignment](#arkui_horizontalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetTop()

```c
void OH_ArkUI_AlignmentRuleOption_SetTop(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the top alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name                                                                                      | Description|
|-------------------------------------------------------------------------------------------| -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id                                                                            | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment                             | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetBottom()

```c
void OH_ArkUI_AlignmentRuleOption_SetBottom(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the bottom alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetCenterVertical()

```c
void OH_ArkUI_AlignmentRuleOption_SetCenterVertical(ArkUI_AlignmentRuleOption* option, const char* id, ArkUI_VerticalAlignment alignment)
```

**Description**


Sets the vertical center alignment mode of a relative layout.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| const char* id | Pointer to the ID of the component that functions as the anchor point.|
| [ArkUI_VerticalAlignment](#arkui_verticalalignment) alignment | Alignment mode relative to the anchor component.|

### OH_ArkUI_AlignmentRuleOption_SetBiasHorizontal()

```c
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

```c
void OH_ArkUI_AlignmentRuleOption_SetBiasVertical(ArkUI_AlignmentRuleOption* option, float vertical)
```

**Description**


Sets the bias value of the component in the vertical direction under the anchor constraints.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|
| float vertical | Bias value in the vertical direction.|

### OH_ArkUI_AlignmentRuleOption_GetStartId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetStartId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the left alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the left alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetStartAlignment()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetStartAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the left alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Alignment mode in left alignment parameters.|

### OH_ArkUI_AlignmentRuleOption_GetEndId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetEndId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the right alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the right alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetEndAlignment()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetEndAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the right alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Right alignment mode.|

### OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the horizontal center alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the horizontal center alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal()

```c
ArkUI_HorizontalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentHorizontal(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the horizontal center alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_HorizontalAlignment](capi-native-type-h.md#arkui_horizontalalignment) | Horizontal center alignment mode.|

### OH_ArkUI_AlignmentRuleOption_GetTopId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetTopId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the top alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the top alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetTopAlignment()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetTopAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the top alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Top alignment mode.|

### OH_ArkUI_AlignmentRuleOption_GetBottomId()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetBottomId(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the bottom alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the bottom alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetBottomAlignment()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetBottomAlignment(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the bottom alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Bottom alignment mode.|

### OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical()

```c
const char* OH_ArkUI_AlignmentRuleOption_GetCenterIdVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the ID of the vertical center alignment anchor component.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the ID of the vertical center alignment anchor component.|

### OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical()

```c
ArkUI_VerticalAlignment OH_ArkUI_AlignmentRuleOption_GetCenterAlignmentVertical(ArkUI_AlignmentRuleOption* option)
```

**Description**


Obtains the vertical center alignment mode.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AlignmentRuleOption](capi-arkui-nativemodule-arkui-alignmentruleoption.md)* option | Pointer to an alignment rule configuration.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_VerticalAlignment](capi-native-type-h.md#arkui_verticalalignment) | Vertical center alignment mode.|

### OH_ArkUI_AlignmentRuleOption_GetBiasHorizontal()

```c
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

```c
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
| float | Bias value in the vertical direction.|

### OH_ArkUI_SwiperDigitIndicator_SetFontWeight()

```c
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

```c
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font weight of the digit-style navigation indicator of the **Swiper** component.

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

```c
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

```c
ArkUI_FontWeight OH_ArkUI_SwiperDigitIndicator_GetSelectedFontWeight(ArkUI_SwiperDigitIndicator* indicator)
```

**Description**


Obtains the font weight of the selected digit-style navigation indicator of the **Swiper** component.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SwiperDigitIndicator](capi-arkui-nativemodule-arkui-swiperdigitindicator.md)* indicator | Pointer to the digit-style navigation indicator.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight) | Font weight, specified using [ArkUI_FontWeight](capi-native-type-h.md#arkui_fontweight).|

### OH_ArkUI_ListItemSwipeActionItem_Create()

```c
ArkUI_ListItemSwipeActionItem* OH_ArkUI_ListItemSwipeActionItem_Create()
```

**Description**


Creates a **ListItemSwipeActionItem** instance.

**Since**: 12

**Returns**

| Type                                | Description|
|------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* | Pointer to the **ListItemSwipeActionItem** instance.|

### OH_ArkUI_ListItemSwipeActionItem_Dispose()

```c
void OH_ArkUI_ListItemSwipeActionItem_Dispose(ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Disposes of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance to dispose of.|

### OH_ArkUI_ListItemSwipeActionItem_SetContent()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetContent(ArkUI_ListItemSwipeActionItem* item, ArkUI_NodeHandle node)
```

**Description**


Sets the layout content for a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Layout information.|

### OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item, float distance)
```

**Description**


Sets the swipe distance threshold for deleting the list item.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| float distance | Swipe distance threshold for deleting the list item, in vp.|

### OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance()

```c
float OH_ArkUI_ListItemSwipeActionItem_GetActionAreaDistance(ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Obtains the swipe distance threshold for deleting the list item.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Swipe distance threshold for deleting the list item, in vp. The value **0** is returned if an exception occurs.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked each time the list item enters the delete area.

**Since**: 12


**Parameters**

| Name                                    | Description|
|-----------------------------------------| -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| callback                                | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnEnterActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked each time the list item enters the delete area. User-defined data will be passed to the callback event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| void* userData | Pointer to the user-defined data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnAction()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnAction(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked when the [list item](./arkui-ts/ts-container-listitem.md) is deleted while in the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnActionWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked when the list item is deleted while in the delete area. User-defined data will be passed to the callback event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| void* userData | Pointer to the user-defined data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionArea(ArkUI_ListItemSwipeActionItem* item, void (*callback)())
```

**Description**


Sets the callback invoked each time the list item exits the delete area.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnExitActionAreaWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(void* userData))
```

**Description**


Sets the callback invoked each time the list item exits the delete area. User-defined data will be passed to the callback event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| void* userData | Pointer to the user-defined data.|
| callback | Callback event.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChange(ArkUI_ListItemSwipeActionItem* item,void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState))
```

**Description**


Sets the callback invoked when the swipe state of the list item changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
| callback | Callback event. The input parameter is **swipeActionState**, indicating the swipe state of the list item.|

### OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData()

```c
void OH_ArkUI_ListItemSwipeActionItem_SetOnStateChangeWithUserData(ArkUI_ListItemSwipeActionItem* item,void* userData, void (*callback)(ArkUI_ListItemSwipeActionState swipeActionState, void* userData))
```

**Description**


Sets the callback invoked when the swipe state of the list item changes. User-defined data will be passed to the callback event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the **ListItemSwipeActionItem** instance.|
|  void* userData | Pointer to the user-defined data.|
| callback | Callback event. The input parameter is **swipeActionState**, indicating the swipe state of the list item.|

### OH_ArkUI_ListItemSwipeActionOption_Create()

```c
ArkUI_ListItemSwipeActionOption* OH_ArkUI_ListItemSwipeActionOption_Create()
```

**Description**


Creates a **ListItemSwipeActionOption** instance.

**Since**: 12

**Returns**

| Type                                  | Description|
|--------------------------------------| -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* | Pointer to the **ListItemSwipeActionOption** instance.|

### OH_ArkUI_ListItemSwipeActionOption_Dispose()

```c
void OH_ArkUI_ListItemSwipeActionOption_Dispose(ArkUI_ListItemSwipeActionOption* option)
```

**Description**


Disposes of a **ListItemSwipeActionOption** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance to dispose of.|

### OH_ArkUI_ListItemSwipeActionOption_SetStart()

```c
void OH_ArkUI_ListItemSwipeActionOption_SetStart(ArkUI_ListItemSwipeActionOption* option, ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Sets the layout content for the left edge (for a vertical layout) or top edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the layout information.|

### OH_ArkUI_ListItemSwipeActionOption_SetEnd()

```c
void OH_ArkUI_ListItemSwipeActionOption_SetEnd(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeActionItem* item)
```

**Description**


Sets the layout content for the right edge (for a vertical layout) or bottom edge (for a horizontal layout) of a **ListItemSwipeActionItem** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md)* item | Pointer to the layout information.|

### OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect()

```c
void OH_ArkUI_ListItemSwipeActionOption_SetEdgeEffect(ArkUI_ListItemSwipeActionOption* option,ArkUI_ListItemSwipeEdgeEffect edgeEffect)
```

**Description**


Sets the effect used when the scroll boundary is reached.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|
| [ArkUI_ListItemSwipeEdgeEffect](capi-native-type-h.md#arkui_listitemswipeedgeeffect) edgeEffect | Effect used when the boundary of the scrolling area is reached.|

### OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect()

```c
int32_t OH_ArkUI_ListItemSwipeActionOption_GetEdgeEffect(ArkUI_ListItemSwipeActionOption* option)
```

**Description**


Obtains the effect used when the scroll boundary is reached.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Effect used when the boundary of the scrolling area is reached. The default return value is [ARKUI_LIST_ITEM_SWIPE_EDGE_EFFECT_SPRING](#arkui_listitemswipeedgeeffect).|

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange()

```c
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChange(ArkUI_ListItemSwipeActionOption* option,void (*callback)(float offset))
```

**Description**


Sets the callback invoked when the scroll offset changes.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|
| callback | Callback event. **offset**: scroll offset, in vp.|

### OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData()

```c
void OH_ArkUI_ListItemSwipeActionOption_SetOnOffsetChangeWithUserData(ArkUI_ListItemSwipeActionOption* option,void* userData, void (*callback)(float offset, void* userData))
```

**Description**


Sets the callback invoked when the scroll offset changes. User-defined data will be passed to the callback event.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionItem** instance.|
|  void* userData | Pointer to the user-defined data.|
| callback | Callback event. **offset**: scroll offset, in vp.|

### OH_ArkUI_ListItemSwipeAction_Expand()

```c
int32_t OH_ArkUI_ListItemSwipeAction_Expand(ArkUI_NodeHandle node, ArkUI_ListItemSwipeActionDirection direction)
```

**Description**

Expands the swipe action menu for the specified list item.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | **ListItem** node object.|
| [ArkUI_ListItemSwipeActionDirection](#arkui_listitemswipeactiondirection) direction | Swipe action menu display direction for the **ListItem** component.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_PARAM_ERROR](capi-native-type-h.md#arkui_errorcode) if the node object type is incorrect.<br>         Returns [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-native-type-h.md#arkui_errorcode) if the passed node is not mounted to the component tree when the API is called.|

> **NOTE**
>
> - If the **List** component's **NODE_LIST_CACHED_COUNT** attribute is configured to preload **ListItem** child components, swipe action menus can be expanded for preloaded **ListItem** child components outside the visible area. Otherwise, child components outside the visible area cannot be expanded.

### OH_ArkUI_ListItemSwipeAction_Collapse()

```c
int32_t OH_ArkUI_ListItemSwipeAction_Collapse(ArkUI_NodeHandle node)
```

**Description**

Collapses the swipe action menu for the specified list item.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | **ListItem** node object.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_PARAM_ERROR](capi-native-type-h.md#arkui_errorcode) if the node object type is incorrect.<br>         Returns [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-native-type-h.md#arkui_errorcode) if the passed node is not mounted to the component tree when the API is called.|

### OH_ArkUI_AccessibilityState_Create()

```c
ArkUI_AccessibilityState* OH_ArkUI_AccessibilityState_Create(void)
```

**Description**


Creates an accessibility state.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md)* | Pointer to the created accessibility state object. If a null pointer is returned, the creation fails. A possible cause is that the application address space is full.|

### OH_ArkUI_AccessibilityState_Dispose()

```c
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

```c
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

```c
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

```c
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

```c
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

```c
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

```c
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

```c
ArkUI_AccessibilityValue* OH_ArkUI_AccessibilityValue_Create(void)
```

**Description**


Creates an **AccessibilityValue** instance.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* | Pointer to the created **AccessibilityValue** instance.|

### OH_ArkUI_AccessibilityValue_Dispose()

```c
void OH_ArkUI_AccessibilityValue_Dispose(ArkUI_AccessibilityValue* value)
```

**Description**


Disposes of the pointer to an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name                                                                                   | Description|
|----------------------------------------------------------------------------------------| -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|

### OH_ArkUI_AccessibilityValue_SetMin()

```c
void OH_ArkUI_AccessibilityValue_SetMin(ArkUI_AccessibilityValue* value, int32_t min)
```

**Description**


Sets the minimum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|
| int32_t min | Minimum value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetMin()

```c
int32_t OH_ArkUI_AccessibilityValue_GetMin(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the minimum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Minimum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetMax()

```c
void OH_ArkUI_AccessibilityValue_SetMax(ArkUI_AccessibilityValue* value, int32_t max)
```

**Description**


Sets the maximum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|
| int32_t max | Maximum value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetMax()

```c
int32_t OH_ArkUI_AccessibilityValue_GetMax(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the maximum accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Maximum value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetCurrent()

```c
void OH_ArkUI_AccessibilityValue_SetCurrent(ArkUI_AccessibilityValue* value, int32_t current)
```

**Description**


Sets the current accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|
| int32_t current | Current value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetCurrent()

```c
int32_t OH_ArkUI_AccessibilityValue_GetCurrent(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the current accessibility value.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Current value for the range-based component. The default value is **-1**.<br>         If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_AccessibilityValue_SetRangeMin()

```c
void OH_ArkUI_AccessibilityValue_SetRangeMin(ArkUI_AccessibilityValue* value, int32_t rangeMin)
```

**Description**


Sets the minimum value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to set the minimum value.|
| int32_t rangeMin | Minimum value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetRangeMin()

```c
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

```c
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

```c
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

```c
void OH_ArkUI_AccessibilityValue_SetRangeCurrent(ArkUI_AccessibilityValue* value, int32_t rangeCurrent)
```

**Description**


Sets the current value for accessibility information of the range-based component.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the accessibility information object of the range-based component for which you want to set the current value.|
| int32_t rangeCurrent | Current value for the range-based component. The default value is **-1**.|

### OH_ArkUI_AccessibilityValue_GetRangeCurrent()

```c
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

```c
void OH_ArkUI_AccessibilityValue_SetText(ArkUI_AccessibilityValue* value, const char* text)
```

**Description**


Sets the text description of an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|
| const char* text | Pointer to the text description. The default value is an empty string.|

### OH_ArkUI_AccessibilityValue_GetText()

```c
const char* OH_ArkUI_AccessibilityValue_GetText(ArkUI_AccessibilityValue* value)
```

**Description**


Obtains the text description of an **AccessibilityValue** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md)* value | Pointer to the created **AccessibilityValue** instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the text description. The default value is an empty string.<br>         If a parameter error occurs, a null pointer is returned.|

### OH_ArkUI_ListChildrenMainSizeOption_Create()

```c
ArkUI_ListChildrenMainSize* OH_ArkUI_ListChildrenMainSizeOption_Create()
```

**Description**


Creates a **ListChildrenMainSize** instance.

**Since**: 12

**Returns**

| Type                             | Description|
|---------------------------------| -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* | Pointer to the created **ListChildrenMainSize** instance.|

### OH_ArkUI_ListChildrenMainSizeOption_Dispose()

```c
void OH_ArkUI_ListChildrenMainSizeOption_Dispose(ArkUI_ListChildrenMainSize* option)
```

**Description**


Disposes of a **ListChildrenMainSize** instance.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance to dispose of.|

### OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize()

```c
int32_t OH_ArkUI_ListChildrenMainSizeOption_SetDefaultMainSize(ArkUI_ListChildrenMainSize* option, float defaultMainSize)
```

**Description**


Sets the default size of the list item in the [List](./arkui-ts/ts-container-list.md) component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|
| float defaultMainSize | Default size of the list item along the main axis, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize()

```c
float OH_ArkUI_ListChildrenMainSizeOption_GetDefaultMainSize(ArkUI_ListChildrenMainSize* option)
```

**Description**


Obtains the default size of the list item in the [List](./arkui-ts/ts-container-list.md) component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|

**Returns**

| Type| Description|
| -- | -- |
| float | Default size of the list item along the main axis. The default value is **0**. The unit is [vp](../apis-arkui/arkui-ts/ts-types.md#vp10). If **option** is a null pointer, **-1** is returned.|

### OH_ArkUI_ListChildrenMainSizeOption_Resize()

```c
void OH_ArkUI_ListChildrenMainSizeOption_Resize(ArkUI_ListChildrenMainSize* option, int32_t totalSize)
```

**Description**


Adjusts the capacity of the children item size array in the [List](./arkui-ts/ts-container-list.md) component along the main axis.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|
| int32_t totalSize | Capacity of the target array.|

### OH_ArkUI_ListChildrenMainSizeOption_Splice()

```c
int32_t OH_ArkUI_ListChildrenMainSizeOption_Splice(ArkUI_ListChildrenMainSize* option, int32_t index, int32_t deleteCount, int32_t addCount)
```

**Description**


Adjusts the children item size array in the [List](./arkui-ts/ts-container-list.md) component along the main axis.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|
| int32_t index | Start index.|
| int32_t deleteCount | Number of elements to be deleted from the start position.|
| int32_t addCount | Number of elements to be added from the start position.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_UpdateSize()

```c
int32_t OH_ArkUI_ListChildrenMainSizeOption_UpdateSize(ArkUI_ListChildrenMainSize* option, int32_t index, float mainSize)
```

**Description**


Updates the size at the specified index in the children item size array of the [List](./arkui-ts/ts-container-list.md) component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|
| int32_t index | Array index of the target element.|
| float mainSize | Size of the main axis, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ListChildrenMainSizeOption_GetMainSize()

```c
float OH_ArkUI_ListChildrenMainSizeOption_GetMainSize(ArkUI_ListChildrenMainSize* option, int32_t index)
```

**Description**


Obtains the size at the specified index in the children item size array of the [List](./arkui-ts/ts-container-list.md) component along the main axis. The vertical axis indicates the height, and the horizontal axis indicates the width.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ListChildrenMainSize](capi-arkui-nativemodule-arkui-listchildrenmainsize.md)* option | Pointer to the **ListChildrenMainSize** instance.|
| int32_t index | Array index of the target element.|

**Returns**

| Type| Description|
| -- | -- |
| float | Value at the specified index. If a parameter error occurs, **-1** is returned.|

### OH_ArkUI_CustomSpanMeasureInfo_Create()

```c
ArkUI_CustomSpanMeasureInfo* OH_ArkUI_CustomSpanMeasureInfo_Create(void)
```

**Description**


Creates measurement information for this custom span.

**Since**: 12

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [ArkUI_CustomSpanMeasureInfo](capi-arkui-nativemodule-arkui-customspanmeasureinfo.md)* | Pointer to the **CustomSpanMeasureInfo** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanMeasureInfo_Dispose()

```c
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

```c
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
| float | Font size of the parent node text, in fp. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanMetrics_Create()

```c
ArkUI_CustomSpanMetrics* OH_ArkUI_CustomSpanMetrics_Create(void)
```

**Description**


Creates measurement metrics for this custom span.

**Since**: 12

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* | Pointer to the **CustomSpanMetrics** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanMetrics_Dispose()

```c
void OH_ArkUI_CustomSpanMetrics_Dispose(ArkUI_CustomSpanMetrics* metrics)
```

**Description**


Disposes of measurement metrics of this custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Pointer to the **CustomSpanMetrics** instance.|

### OH_ArkUI_CustomSpanMetrics_SetWidth()

```c
int32_t OH_ArkUI_CustomSpanMetrics_SetWidth(ArkUI_CustomSpanMetrics* metrics, float width)
```

**Description**


Sets the width for a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Pointer to the **CustomSpanMetrics** instance.|
| float width | Width, in vp. The default value is **0.0f**. The negative value has the same effect as the default value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanMetrics_SetHeight()

```c
int32_t OH_ArkUI_CustomSpanMetrics_SetHeight(ArkUI_CustomSpanMetrics* metrics, float height)
```

**Description**


Sets the height for a custom span.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomSpanMetrics](capi-arkui-nativemodule-arkui-customspanmetrics.md)* metrics | Pointer to the **CustomSpanMetrics** instance.|
| float height | Height, in vp. The default value is **0.0f**. The negative value has the same effect as the default value.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_Create()

```c
ArkUI_CustomSpanDrawInfo* OH_ArkUI_CustomSpanDrawInfo_Create(void)
```

**Description**


Creates drawing information for this custom span.

**Since**: 12

**Returns**

| Type                           | Description|
|-------------------------------| -- |
| [ArkUI_CustomSpanDrawInfo](capi-arkui-nativemodule-arkui-customspandrawinfo.md)* | Pointer to the **CustomSpanDrawInfo** instance.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_CustomSpanDrawInfo_Dispose()

```c
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

```c
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
| float | X-axis offset, in px. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetLineTop()

```c
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
| float | Top margin, in px. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetLineBottom()

```c
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
| float | Bottom margin, in px. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomSpanDrawInfo_GetBaseline()

```c
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
| float | Baseline offset, in px. If a parameter error occurs, **0.0f** is returned.<br> A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_CustomProperty_Destroy()

```c
void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)
```

**Description**


Destroys an [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | Pointer to the instance to be destroyed.|

### OH_ArkUI_CustomProperty_GetStringValue()

```c
const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)
```

**Description**


Obtains the value of a custom property object.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md)* handle | Pointer to the custom property object.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the value of a custom property object.|

### OH_ArkUI_HostWindowInfo_GetName()

```c
const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)
```

**Description**


Obtains the window name in an [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) object.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | Pointer to the **HostWindowInfo** object.|

**Returns**

| Type| Description|
| -- | -- |
| const char* | Pointer to the window name in the [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) object.|

### OH_ArkUI_HostWindowInfo_Destroy()

```c
void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)
```

**Description**


Destroys an [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) object.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md)* info | Pointer to the [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) object to be destroyed.|

### OH_ArkUI_ActiveChildrenInfo_Destroy()

```c
void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)
```

**Description**


Destroys an [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | Pointer to the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance to be destroyed.|

### OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex()

```c
ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)
```

**Description**


Obtains the child node at the specified index in an [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | Pointer to the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance from which the information is to be obtained.|
| int32_t index | Index of the target child node.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) | Handle to the child node at the specified index, or **nullptr** if an error occurs.|

### OH_ArkUI_ActiveChildrenInfo_GetCount()

```c
int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)
```

**Description**


Obtains the number of nodes in an [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | Pointer to the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance from which the information is to be obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of child nodes. The default value is **0**.|

### OH_ArkUI_ProgressLinearStyleOption_Create()

```c
ArkUI_ProgressLinearStyleOption* OH_ArkUI_ProgressLinearStyleOption_Create(void)
```

**Description**


Creates a **ProgressLinearStyleOption** instance.

**Since**: 15

**Returns**

| Type                                  | Description|
|--------------------------------------| -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* | Pointer to the **ProgressLinearStyleOption** instance created.<br> If a null pointer is returned, the memory may be insufficient.|

### OH_ArkUI_ProgressLinearStyleOption_Destroy()

```c
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

```c
void OH_ArkUI_ProgressLinearStyleOption_SetSmoothEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**


Sets whether to enable the smooth progress effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| bool enabled | Whether to enable the smooth effect. When this effect is enabled, the progress changes smoothly from the current value to the target value. When this effect is disabled, the progress changes abruptly to the target value.<br>**true**: The smooth effect is enabled.<br>**false**: The smooth effect is disabled.<br>The default value is **true**.|

### OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled()

```c
void OH_ArkUI_ProgressLinearStyleOption_SetScanEffectEnabled(ArkUI_ProgressLinearStyleOption* option, bool enabled)
```

**Description**


Sets whether to enable the scan effect.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ProgressLinearStyleOption](capi-arkui-nativemodule-arkui-progresslinearstyleoption.md)* option | Pointer to a **ProgressLinearStyleOption** instance.|
| bool enabled | Whether to enable the scan effect.<br>**true**: The scan effect is enabled.<br>**false**: The scan effect is disabled.<br>The default value is **false**.|

### OH_ArkUI_ProgressLinearStyleOption_SetStrokeWidth()

```c
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

```c
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

```c
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
| bool | Whether the smooth effect is enabled.<br>**true**: The smooth effect is enabled.<br>**false**: The smooth effect is disabled.<br>The default value is **true**.|

### OH_ArkUI_ProgressLinearStyleOption_GetScanEffectEnabled()

```c
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
| bool | Whether the scan effect is enabled.<br>**true**: The scan effect is enabled.<br>**false**: The scan effect is disabled.<br>The default value is **false**.|

### OH_ArkUI_ProgressLinearStyleOption_GetStrokeWidth()

```c
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

```c
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

### OH_ArkUI_CrossLanguageOption_Create()

```c
ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)
```

**Description**


Creates an instance of the cross-language configuration option.

**Since**: 15

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* | Pointer to the **ArkUI_CrossLanguageOption** instance created. If a null pointer is returned, creation failed, possibly due to insufficient memory.|

### OH_ArkUI_CrossLanguageOption_Destroy()

```c
void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)
```

**Description**


Destroys an instance of the cross-language configuration option.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance to be destroyed.|

### OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus()

```c
void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)
```

**Description**


Sets whether cross-language attribute setting is allowed in the configuration option.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance.|
| bool enabled | Whether cross-language attribute setting is allowed. **true** means that cross-language attribute setting is allowed, and **false** means the opposite. The default value is **false**.|

### OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus()

```c
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
| bool | Whether cross-language attribute setting is allowed. **true** means that cross-language attribute setting is allowed, and **false** means the opposite.|

### OH_ArkUI_CrossLanguageOption_SetTreeOperatingStatus()

```c
void OH_ArkUI_CrossLanguageOption_SetTreeOperatingStatus(ArkUI_CrossLanguageOption* option, OH_ArkUI_CrossLanguageOperatingStatus status)
```

**Description**

Sets the node tree operation state of a cross-language configuration option.

**Since**: 26.0.0


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance.|
| [OH_ArkUI_CrossLanguageOperatingStatus](#oh_arkui_crosslanguageoperatingstatus) status | Node tree operation state to be set. Default value: **OH_ARKUI_TREE_OPERATING_STATUS_UNDEFINED**.|

### OH_ArkUI_CrossLanguageOption_GetTreeOperatingStatus()

```c
OH_ArkUI_CrossLanguageOperatingStatus OH_ArkUI_CrossLanguageOption_GetTreeOperatingStatus(ArkUI_CrossLanguageOption* option)
```

**Description**

Obtains the node tree operation state of a cross-language configuration option.

**Since**: 26.0.0


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md)* option | Pointer to the cross-language configuration option instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_CrossLanguageOperatingStatus](#oh_arkui_crosslanguageoperatingstatus) | Node tree operation state of a cross-language configuration option.|

### OH_ArkUI_PositionEdges_Create()

```c
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Create()
```

**Description**

Creates a **PositionEdges** object.

**Since**: 21

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* | Pointer to the **PositionEdges** object.|


### OH_ArkUI_PositionEdges_Copy()

```c
ArkUI_PositionEdges* OH_ArkUI_PositionEdges_Copy(const ArkUI_PositionEdges* edges)
```

**Description**

Deeply copies a **PositionEdges** attribute object.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* | Pointer to the new **PositionEdges** object.|

### OH_ArkUI_PositionEdges_Dispose()

```c
void OH_ArkUI_PositionEdges_Dispose(ArkUI_PositionEdges* edges)
```

**Description**

Disposes of the **PositionEdges** object.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|

### OH_ArkUI_PositionEdges_SetTop()

```c
void OH_ArkUI_PositionEdges_SetTop(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the top direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float value|Value of the **PositionEdges** object in the corresponding direction, in vp.|

### OH_ArkUI_PositionEdges_GetTop()

```c
int32_t OH_ArkUI_PositionEdges_GetTop(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the top direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float* value|Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PositionEdges_SetLeft()

```c
void OH_ArkUI_PositionEdges_SetLeft(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the left direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float value|Value of the **PositionEdges** object in the corresponding direction, in vp.|

### OH_ArkUI_PositionEdges_GetLeft()

```c
int32_t OH_ArkUI_PositionEdges_GetLeft(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the left direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float* value|Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|


### OH_ArkUI_PositionEdges_SetBottom()

```c
void OH_ArkUI_PositionEdges_SetBottom(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the bottom direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float value|Value of the **PositionEdges** object in the corresponding direction, in vp.|

### OH_ArkUI_PositionEdges_GetBottom()

```c
int32_t OH_ArkUI_PositionEdges_GetBottom(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the bottom direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float* value|Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PositionEdges_SetRight()

```c
void OH_ArkUI_PositionEdges_SetRight(ArkUI_PositionEdges* edges, float value)
```

**Description**

Sets the value of the **PositionEdges** object in the right direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float value|Value of the **PositionEdges** object in the corresponding direction, in vp.|

### OH_ArkUI_PositionEdges_GetRight()

```c
int32_t OH_ArkUI_PositionEdges_GetRight(ArkUI_PositionEdges* edges, float* value)
```

**Description**

Obtains the value of the **PositionEdges** object in the right direction.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| [ArkUI_PositionEdges](capi-arkui-nativemodule-arkui-positionedges.md)* edges | Pointer to the **PositionEdges** object.|
|float* value|Pointer to the value of the **PositionEdges** object in the corresponding direction, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PixelRoundPolicy_Create()

```c
ArkUI_PixelRoundPolicy* OH_ArkUI_PixelRoundPolicy_Create()
```

**Description**

Creates a **PixelRoundPolicy** attribute object.

**Since**: 21

**Returns**

| Type                                                        | Description                            |
| ------------------------------------------------------------ | -------------------------------- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* | Pointer to the **PixelRoundPolicy** object.|

### OH_ArkUI_PixelRoundPolicy_Dispose()

```c
void OH_ArkUI_PixelRoundPolicy_Dispose(ArkUI_PixelRoundPolicy* policy)
```

**Description**

Disposes of the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                    |
| ------------------------------------------------------------ | ---------------------------------------- |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the target **PixelRoundPolicy** object.|

### OH_ArkUI_PixelRoundPolicy_SetTop()

```c
void OH_ArkUI_PixelRoundPolicy_SetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the top edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy.|

### OH_ArkUI_PixelRoundPolicy_GetTop()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetTop(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the top edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy.|

**Returns**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PixelRoundPolicy_SetStart()

```c
void OH_ArkUI_PixelRoundPolicy_SetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the start edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy.|

### OH_ArkUI_PixelRoundPolicy_GetStart()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetStart(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the start edge pixel rounding policy from the **PixelRoundPolicy** object. 

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy.|

**Returns**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PixelRoundPolicy_SetBottom()

```c
void OH_ArkUI_PixelRoundPolicy_SetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the bottom edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy.|

### OH_ArkUI_PixelRoundPolicy_GetBottom()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetBottom(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the bottom edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy.|

**Returns**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PixelRoundPolicy_SetEnd()

```c
void OH_ArkUI_PixelRoundPolicy_SetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy value)
```

**Description**

Sets the end edge pixel rounding policy for the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy) value | Specific pixel rounding policy.|

### OH_ArkUI_PixelRoundPolicy_GetEnd()

```c
int32_t OH_ArkUI_PixelRoundPolicy_GetEnd(ArkUI_PixelRoundPolicy* policy, ArkUI_PixelRoundCalcPolicy* value)
```

**Description**

Obtains the end edge pixel rounding policy from the **PixelRoundPolicy** object.

**Since**: 21

**Parameters**

| Name                                                      | Description                                |
| ------------------------------------------------------------ | ------------------------------------ |
| [ArkUI_PixelRoundPolicy](capi-arkui-nativemodule-arkui-pixelroundpolicy.md)* policy | Pointer to the **PixelRoundPolicy** object.    |
| [ArkUI_PixelRoundCalcPolicy](#arkui_pixelroundcalcpolicy)* value | Pointer to the specific pixel rounding policy.|

**Returns**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_ContentTransitionEffect_Create()

```c
ArkUI_ContentTransitionEffect* OH_ArkUI_ContentTransitionEffect_Create(int32_t type)
```

**Description**

Creates a **ContentTransitionEffect** attribute object.

**Since**: 21

**Parameters**

| Name| Description                          |
| -- |------------------------------|
| int32_t type | Transition animation type. **0**: No transition animation. **1**: Fade-in and fade-out transition animation.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ContentTransitionEffect](capi-arkui-nativemodule-arkui-contenttransitioneffect.md)* | Pointer to the **ContentTransitionEffect** object.|

### OH_ArkUI_GridLayoutOptions_Create()

```c
ArkUI_GridLayoutOptions* OH_ArkUI_GridLayoutOptions_Create()
```

**Description**

Creates **Grid** layout options.

**Since**: 22

**Returns**

| Type                               | Description|
|-----------------------------------| -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* | Pointer to the **Grid** layout option.|

### OH_ArkUI_GridLayoutOptions_Dispose()

```c
void OH_ArkUI_GridLayoutOptions_Dispose(ArkUI_GridLayoutOptions* option)
```

**Description**

Disposes of the **Grid** layout option.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option.|


### OH_ArkUI_GridLayoutOptions_SetIrregularIndexes()

```c
int32_t OH_ArkUI_GridLayoutOptions_SetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t size)
```

**Description**

Sets the irregular grid item index array for the grid layout.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option.|
| uint32_t* irregularIndexes |  Pointer to the **GridItem** index array.|
| int32_t size | Size of the **GridItem** index array.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_GridLayoutOptions_GetIrregularIndexes()

```c
int32_t OH_ArkUI_GridLayoutOptions_GetIrregularIndexes(ArkUI_GridLayoutOptions* option, uint32_t* irregularIndexes, int32_t* size)
```

**Description**

Obtains the irregular grid item index array for the grid layout. When **OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback** is not set, the grid item specified in this parameter occupies an entire row of the grid that scrolls vertically or an entire column of the grid that scrolls horizontally.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option.|
| uint32_t* irregularIndexes |  Pointer to the **GridItem** index array.|
| int32_t size | Size of the **GridItem** index array.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the buffer size is insufficient.<br>         A possible cause is that mandatory parameters are left unspecified.|

### OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback()

```c
void OH_ArkUI_GridLayoutOptions_RegisterGetIrregularSizeByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemSize (*callback)(int32_t itemIndex, void* userData))
```

**Description**

Registers a callback to obtain the row and column span for the grid item at the specified index.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option.|
| void* userData | Pointer to the user-defined data.|
| ArkUI_GridItemSize (\*callback)(int32_t itemIndex, void* userData) | Callback that returns the row and column span for the grid item at the specified index.<br> **itemIndex**: grid item index, which must be within the range set by [OH_ArkUI_GridLayoutOptions_SetIrregularIndexes](capi-native-type-h.md#oh_arkui_gridlayoutoptions_setirregularindexes).|

### OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback()

```c
void OH_ArkUI_GridLayoutOptions_RegisterGetRectByIndexCallback(ArkUI_GridLayoutOptions* option, void* userData, ArkUI_GridItemRect (*callback)(int32_t itemIndex, void* userData))
```

**Description**

Registers a callback to obtain the starting row, starting column, row span, and column span for the grid item at the specified index.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_GridLayoutOptions](capi-arkui-nativemodule-arkui-gridlayoutoptions.md)* option | Pointer to the **Grid** layout option.|
| void* userData | Pointer to the user-defined data.|
| ArkUI_GridItemRect (\*callback)(int32_t itemIndex, void* userData) | Callback that returns the starting row, starting column, row span, and column span for the grid item at the specified index.<br>   **itemIndex**: grid item index.|
### OH_ArkUI_ShowCounterConfig_Create()

```c
ArkUI_ShowCounterConfig* OH_ArkUI_ShowCounterConfig_Create()
```

**Description**


Creates a text input counter configuration object.

**Since**: 22


**Returns**

| Type                        | Description|
|----------------------------| -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* | Pointer to the text input counter configuration object.|

### OH_ArkUI_ShowCounterConfig_Dispose()

```c
void OH_ArkUI_ShowCounterConfig_Dispose(ArkUI_ShowCounterConfig* config)
```

**Description**


Disposes of the text input counter configuration object.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object to be disposed of.|

### OH_ArkUI_ShowCounterConfig_SetCounterTextColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**Description**


Sets the text color of the counter when the text input has not reached the maximum character limit.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object.|
| uint32_t color | Counter text color in 0xARGB format.|

### OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor()

```c
void OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config, uint32_t color)
```

**Description**


Sets the text color of the counter when the text input exceeds the maximum character limit.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object.|
| uint32_t color | Counter text color in 0xARGB format.|

### OH_ArkUI_ShowCounterConfig_GetCounterTextColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextColor(ArkUI_ShowCounterConfig* config)
```

**Description**


Obtains the text color of the counter when the text input has not reached the maximum character limit.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t  | Counter text color in 0xARGB format. Returns **0** if no color has been set via [OH_ArkUI_ShowCounterConfig_SetCounterTextColor](#oh_arkui_showcounterconfig_setcountertextcolor).|


### OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor()

```c
uint32_t OH_ArkUI_ShowCounterConfig_GetCounterTextOverflowColor(ArkUI_ShowCounterConfig* config)
```

**Description**


Obtains the text color of the counter when the text input exceeds the maximum character limit.

**Since**: 22


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ShowCounterConfig](capi-arkui-nativemodule-arkui-textshowcounterconfig.md)* config | Pointer to the text input counter configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t | Counter text color in 0xARGB format. Returns **0** if no color has been set via [OH_ArkUI_ShowCounterConfig_SetCounterTextOverflowColor](#oh_arkui_showcounterconfig_setcountertextoverflowcolor).|

### OH_ArkUI_SelectionOptions_Create()

```c
ArkUI_SelectionOptions OH_ArkUI_SelectionOptions_Create()
```

**Description**


Creates a selection option.

**Since**: 23


**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)* | Pointer to the selection option.|

### OH_ArkUI_SelectionOptions_Dispose()

```c
void OH_ArkUI_SelectionOptions_Dispose(ArkUI_SelectionOptions* options)
```

**Description**


Releases a selection option object.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)* options | Pointer to the selection option to be released.|

### OH_ArkUI_SelectionOptions_SetMenuPolicy()

```c
void OH_ArkUI_SelectionOptions_SetMenuPolicy(ArkUI_SelectionOptions* options, ArkUI_MenuPolicy menuPolicy)
```

**Description**


Sets the menu pop-up policy for selection options.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)* options | Pointer to the selection option.|
| [ArkUI_MenuPolicy ](#arkui_menupolicy) menuPolicy | Menu display policy.|

### OH_ArkUI_SelectionOptions_GetMenuPolicy()

```c
ArkUI_MenuPolicy  OH_ArkUI_SelectionOptions_GetMenuPolicy(ArkUI_SelectionOptions* options)
```

**Description**


Obtains the menu pop-up policy for selection options.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)* options | Pointer to the selection option.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_MenuPolicy ](#arkui_menupolicy) | Menu display policy.|

### OH_ArkUI_TextContentBaseController_Create()

```c
ArkUI_TextContentBaseController* OH_ArkUI_TextContentBaseController_Create()
```

**Description**

Creates a basic controller object for text content.

**Since**: 23

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* | Pointer to the controller object.|

### OH_ArkUI_TextContentBaseController_Dispose()

```c
void OH_ArkUI_TextContentBaseController_Dispose(ArkUI_TextContentBaseController* controller)
```

**Description**

Destroys a basic controller object for text content.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the controller to be destroyed.|

### OH_ArkUI_TextContentBaseController_DeleteBackward()

```c
void OH_ArkUI_TextContentBaseController_DeleteBackward(ArkUI_TextContentBaseController* controller)
```

**Description**

Deletes the character before the cursor in editing state; deletes the last character of the text box component in other states.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the configuration object to be modified.|

### OH_ArkUI_TextContentBaseController_ScrollToVisible()

```c
void OH_ArkUI_TextContentBaseController_ScrollToVisible(ArkUI_TextContentBaseController* controller, int32_t start, int32_t end)
```

**Description**

Passes the start and end indexes to the bound text box component, and scrolls the text within the range to the visible area.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextContentBaseController](capi-arkui-nativemodule-arkui-textcontentbasecontroller.md)* controller | Pointer to the configuration object to be modified.<br>Pass the start and end indexes to the bound text box component and scroll the text within the range.|
| int32_t start | Start text index.<br>The start index must be less than or equal to the end index. Otherwise, the API call is invalid. The value range is [0, Total length of the text in the text box]. If the start index is less than 0, the start index is regarded as 0. If the start index is greater than the total length, the start index is regarded as the total length.|
| int32_t end | End text index.<br>The end index must be greater than or equal to the start index. Otherwise, the API call is invalid. The value range is [0, Total length of the text in the text box]. If the end index is less than 0, the end index is regarded as 0. If the end index is greater than the total length, the end index is regarded as the total length.|

### OH_ArkUI_TextMenuItem_Create()

```c
ArkUI_TextMenuItem* OH_ArkUI_TextMenuItem_Create()
```

**Description**

Creates a text menu item object.

**Since**: 22

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* | Pointer to the **ArkUI_TextMenuItem** object.|

### OH_ArkUI_TextMenuItem_Dispose()

```c
void OH_ArkUI_TextMenuItem_Dispose(ArkUI_TextMenuItem* textMenuItem)
```

**Description**

Releases a text menu item object.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* textMenuItem | Pointer to the **ArkUI_TextMenuItem** object.|

### OH_ArkUI_TextMenuItem_SetContent()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetContent(ArkUI_TextMenuItem* item, const char* content)
```

**Description**

Sets the title of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| const char* content | Pointer to the title of a text menu item. The default value is an empty string.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_GetContent()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetContent(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the title of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| char* buffer | Pointer to the buffer. You can create it and allocate memory to store the title information of the text menu item.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_SetIcon()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetIcon(ArkUI_TextMenuItem* item, const char* icon)
```

**Description**

Sets the icon path of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| const char* icon | Pointer to the icon path of the text menu item. The default value is an empty string.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_GetIcon()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetIcon(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the icon path of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| char* buffer | Pointer to the buffer. You can create it and allocate memory to store the icon path of the text menu item.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_SetLabelInfo()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetLabelInfo(ArkUI_TextMenuItem* item, const char* labelInfo)
```

**Description**

Sets the shortcut hint for a text menu item, for example, the shortcut hint for the **Copy** menu item can be set to **Ctrl+C**.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| const char* labelInfo | Pointer to the shortcut hint of a text menu item. The default value is an empty string.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_GetLabelInfo()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetLabelInfo(const ArkUI_TextMenuItem* item, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the shortcut hint for a text menu item, for example, the shortcut hint for the **Copy** menu item is typically **Ctrl+C**.

**Since**: 22

**Parameters**

| Name| Description|
| ------ | --- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| char* buffer | Pointer to the buffer. You can create it and allocate memory to store the shortcut hint of the text menu item.|
| int32_t bufferSize | Buffer size.|
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_SetId()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_SetId(ArkUI_TextMenuItem* item, int32_t id)
```

**Description**

Sets the ID of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| int32_t id | ID of a text menu item.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItem_GetId()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItem_GetId(const ArkUI_TextMenuItem* item, int32_t* id)
```

**Description**

Obtains the ID of a text menu item.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| int32_t* id | Pointer to the ID of a text menu item.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItemArray_GetSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetSize(ArkUI_TextMenuItemArray* items, int32_t* size)
```

**Description**

Obtains the size of the text menu item array.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object.|
| int32_t* size | Pointer to the size of the text menu item array.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItemArray_GetItem()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_GetItem(ArkUI_TextMenuItemArray* items, int32_t index, ArkUI_TextMenuItem** item)
```

**Description**

Obtains the text menu item at a specified index from the text menu item array.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object.|
| int32_t index | Index position.|
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)** item | Double pointer to the **ArkUI_TextMenuItem** object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItemArray_Insert()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Insert(ArkUI_TextMenuItemArray* items, ArkUI_TextMenuItem* item, int32_t index)
```

**Description**

Inserts a text menu item at a specified index into the text menu item array.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object.|
| [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object.|
| int32_t index | Index position of the text menu item to be inserted.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItemArray_Erase()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Erase(ArkUI_TextMenuItemArray* items, int32_t index)
```

**Description**

Deletes the text menu item at a specified index from the text menu item array.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object.|
| int32_t index | Index of the text menu item to be deleted.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMenuItemArray_Clear()

```c
ArkUI_ErrorCode OH_ArkUI_TextMenuItemArray_Clear(ArkUI_TextMenuItemArray* items)
```

**Description**

Clears all text menu items in the text menu item array.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditMenuOptions_Create()

```c
ArkUI_TextEditMenuOptions* OH_ArkUI_TextEditMenuOptions_Create()
```

**Description**

Creates a text menu extension object.

**Since**: 22

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object.|


### OH_ArkUI_TextEditMenuOptions_Dispose()

```c
void OH_ArkUI_TextEditMenuOptions_Dispose(ArkUI_TextEditMenuOptions* editMenuOptions)
```

**Description**

Releases a text menu extension object.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object.|

### ArkUI_TextCreateMenuCallback()

```c
typedef void (*ArkUI_TextCreateMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**Description**

Callback for the text menu creation event. This callback is triggered when a text menu is created, allowing you to set menu data in it.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object, which is created and released by the system. You can call [OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert) and [OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase) to modify the array in the callback.|
| void\* userData | Pointer to the user-defined data.|

### ArkUI_TextPrepareMenuCallback()

```c
typedef void (*ArkUI_TextPrepareMenuCallback)(ArkUI_TextMenuItemArray* items, void* userData)
```

**Description**

Callback for the text menu preparation event. This callback is called when the text selection area changes and before the menu is displayed, allowing you to set menu data in it.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMenuItemArray](capi-arkui-nativemodule-arkui-textmenuitemarray.md)* items | Pointer to the **ArkUI_TextMenuItemArray** object, which is created and released by the system. You can call [OH_ArkUI_TextMenuItemArray_Insert](capi-native-type-h.md#oh_arkui_textmenuitemarray_insert) and [OH_ArkUI_TextMenuItemArray_Erase](capi-native-type-h.md#oh_arkui_textmenuitemarray_erase) to modify the array in the callback.|
| void\* userData | Pointer to the user-defined data.|

### ArkUI_TextMenuItemClickCallback()

```c
typedef bool (*ArkUI_TextMenuItemClickCallback)(const ArkUI_TextMenuItem* item,int32_t start, int32_t end, void* userData)
```

**Description**

Callback for the text menu item click event. This callback is called when a menu item is clicked. You can intercept the default processing behavior in this callback.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkUI_TextMenuItem](capi-arkui-nativemodule-arkui-textmenuitem.md)* item | Pointer to the **ArkUI_TextMenuItem** object, indicating the clicked text menu item.|
| int32_t start | Start index of the selected text.|
| int32_t end | End index of the selected text.|
| void\* userData | Pointer to the user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether to intercept the default processing behavior of the system.<br> **true**: Intercept the system's default processing behavior. For example, clicking text menu items such as **Paste** or **Copy** will only execute the custom processing behavior.<br> **false**: Do not intercept the system's default processing behavior. For example, clicking text menu items such as **Paste** or **Copy** will first execute the custom processing behavior and then the default processing behavior.|

### OH_ArkUI_TextEditMenuOptions_RegisterOnCreateMenuCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnCreateMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextCreateMenuCallback cb)
```

**Description**

Registers the callback for creating text menus.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object.|
| void* userData | Pointer to the user-defined data.|
| [ArkUI_TextCreateMenuCallback](capi-native-type-h.md#arkui_textcreatemenucallback) cb | Callback for creating text menus.|

**Returns**

| Type| Description|
| ---- | --- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditMenuOptions_RegisterOnPrepareMenuCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnPrepareMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextPrepareMenuCallback cb)
```

**Description**

Registers the callback for preparing text menus.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object.|
| void* userData | Pointer to the user-defined data.|
| [ArkUI_TextPrepareMenuCallback](capi-native-type-h.md#arkui_textpreparemenucallback) cb | Callback for preparing text menus.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditMenuOptions_RegisterOnMenuItemClickCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnMenuItemClickCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextMenuItemClickCallback cb)
```

**Description**

Registers the callback for text menu item clicks.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextEditMenuOptions](capi-arkui-nativemodule-arkui-texteditmenuoptions.md)* editMenuOptions | Pointer to the **ArkUI_TextEditMenuOptions** object.|
| void* userData | Pointer to the user-defined data.|
| [ArkUI_TextMenuItemClickCallback](capi-native-type-h.md#arkui_textmenuitemclickcallback) cb | Callback for text menu item clicks.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_Create()

```c
ArkUI_TextSelectionMenuOptions* OH_ArkUI_TextSelectionMenuOptions_Create();
```

**Description**

Creates a custom text selection menu object.

**Since**: 22

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|


### OH_ArkUI_TextSelectionMenuOptions_Dispose()

```c
void OH_ArkUI_TextSelectionMenuOptions_Dispose(ArkUI_TextSelectionMenuOptions* selectionMenuOptions)
```

**Description**

Releases a custom text selection menu object.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|

### OH_ArkUI_TextSelectionMenuOptions_SetSpanType()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType textSpanType)
```

**Description**

Sets the text recognition type of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_TextSpanType](capi-native-type-h.md#arkui_textspantype) textSpanType | Recognition type of a custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_GetSpanType()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType* spanType)
```

**Description**

Obtains the text recognition type of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_TextSpanType](capi-native-type-h.md#arkui_textspantype)* spanType | Pointer to the recognition type of a custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_SetContentNode()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle node)
```

**Description**

Sets the content node of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Content node of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_GetContentNode()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle* node)
```

**Description**

Obtains the content node of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* node | Pointer to the content node of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_SetResponseType()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType responseType)
```

**Description**

Sets the response type of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_TextResponseType](capi-native-type-h.md#arkui_textresponsetype) responseType | Response type of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_GetResponseType()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType* responseType)
```

**Description**

Obtains the response type of a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| [ArkUI_TextResponseType](capi-native-type-h.md#arkui_textresponsetype)* responseType | Pointer to the response type of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (*callback)(int32_t start, int32_t end, void* userData))
```

**Description**

Registers the callback for the event of showing a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| void* userData | Pointer to the user-defined data, which can be any value. After the setting, the value is returned through the callback.|
| void (\*callback)(int32_t start, int32_t end, void* userData) | Callback for the event of showing a custom text selection menu.<br> **start**: start position of the selected text.<br> **end**: end position of the selected text.<br> **userData**: user-defined data, which corresponds to the input parameter **userData** of the **OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback** API.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (*callback)(int32_t start, int32_t end, void* userData))
```

**Description**

Registers the callback for the event of hiding a custom text selection menu.

**Since**: 22

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextSelectionMenuOptions](capi-arkui-nativemodule-arkui-textselectionmenuoptions.md)* selectionMenuOptions | Pointer to the **ArkUI_TextSelectionMenuOptions** object.|
| void* userData | Pointer to the user-defined data, which can be any value. After the setting, the value is returned through the callback.|
| void (\*callback)(int32_t start, int32_t end, void* userData) | Callback for the event of hiding a custom text selection menu.<br> **start**: start position of the selected text.<br> **end**: end position of the selected text.<br> **userData**: user-defined data, which corresponds to the input parameter **userData** of the **OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback** API.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextMarqueeOptions_Create()
``` c
ArkUI_TextMarqueeOptions* OH_ArkUI_TextMarqueeOptions_Create()
```

**Description**

Creates text marquee options.

**Since**: 23

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)*| Pointer to the text marquee option to be created.|

### OH_ArkUI_TextMarqueeOptions_Dispose()
``` c
void OH_ArkUI_TextMarqueeOptions_Dispose(ArkUI_TextMarqueeOptions* option)
```

**Description**

Destroys the pointer to the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to a text marquee option to be destroyed.|


### OH_ArkUI_TextMarqueeOptions_SetStart()
``` c
void OH_ArkUI_TextMarqueeOptions_SetStart(ArkUI_TextMarqueeOptions* option, bool start)
```

**Description**

Sets whether to play the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| bool start | Whether to play the text marquee option. **true** indicates to play; **false** indicates not to play.|

### OH_ArkUI_TextMarqueeOptions_GetStart()
``` c
bool OH_ArkUI_TextMarqueeOptions_GetStart(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains whether the text marquee option is played.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the text marquee option is played. **true** indicates the text marquee option is played; **false** indicates the opposite.|


### OH_ArkUI_TextMarqueeOptions_SetStep()
``` c
void OH_ArkUI_TextMarqueeOptions_SetStep(ArkUI_TextMarqueeOptions* option, float step)
```

**Description**

Sets the step of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| float step | Step. Unit: vp.|

### OH_ArkUI_TextMarqueeOptions_GetStep()
``` c
float OH_ArkUI_TextMarqueeOptions_GetStep(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the step of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| float | Step. Unit: vp.|


### OH_ArkUI_TextMarqueeOptions_SetSpacing()
``` c
void OH_ArkUI_TextMarqueeOptions_SetSpacing(ArkUI_TextMarqueeOptions* option, float spacing)
```

**Description**

Sets the distance between the start and end items of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| float spacing | Spacing between the start and end items. Unit: vp.|

### OH_ArkUI_TextMarqueeOptions_GetSpacing()
``` c
float OH_ArkUI_TextMarqueeOptions_GetSpacing(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the distance between the start and end items of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| float | Spacing between the start and end items. Unit: vp.|



### OH_ArkUI_TextMarqueeOptions_SetLoop()
``` c
void OH_ArkUI_TextMarqueeOptions_SetLoop(ArkUI_TextMarqueeOptions* option, int32_t loop)
```

**Description**

Sets the number of repetitions for looping the text marquee option. The value **0** or negative value indicates infinite looping.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| int32_t loop | Number of loops.|

### OH_ArkUI_TextMarqueeOptions_GetLoop()
``` c
int32_t OH_ArkUI_TextMarqueeOptions_GetLoop(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the number of repetitions for looping the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of loops.|



### OH_ArkUI_TextMarqueeOptions_SetFromStart()
``` c
void OH_ArkUI_TextMarqueeOptions_SetFromStart(ArkUI_TextMarqueeOptions* option, bool fromStart)
```

**Description**

Sets the scrolling direction for looping the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| bool fromStart | Scrolling direction for looping the text marquee option. **true** to scroll from the start; **false** to scroll in reverse.|

### OH_ArkUI_TextMarqueeOptions_GetFromStart()
``` c
bool OH_ArkUI_TextMarqueeOptions_GetFromStart(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the scrolling direction for looping the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Scrolling direction for looping the text marquee option. **true** to scroll from the start; **false** to scroll in reverse.|


### OH_ArkUI_TextMarqueeOptions_SetDelay()
``` c
void OH_ArkUI_TextMarqueeOptions_SetDelay(ArkUI_TextMarqueeOptions* option, int32_t delay)
```

**Description**

Sets the delay of each loop for the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| int32_t delay| Delay of each loop, in milliseconds.|

### OH_ArkUI_TextMarqueeOptions_GetDelay()
``` c
int32_t OH_ArkUI_TextMarqueeOptions_GetDelay(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the delay of each loop for the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Delay of each loop, in milliseconds.|

### OH_ArkUI_TextMarqueeOptions_SetFadeout()
``` c
void OH_ArkUI_TextMarqueeOptions_SetFadeout(ArkUI_TextMarqueeOptions* option, bool fadeout)
```

**Description**

Sets whether the text marquee option supports a fade-out effect when the text is too long. When supported, if the text content exceeds the display range, the edges of the partially visible text will have a fade-out effect applied.<br> If both ends have partially visible text, both ends will have the fade-out effect applied.<br> When the fade-out effect is enabled, the **NODE_CLIP** attribute in [ArkUI_NodeAttributeType](./capi-native-node-h.md#arkui_nodeattributetype) is automatically locked to **true** and cannot be set to **false**.


**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| bool fadeout| Whether the text marquee option supports a fade-out effect when the text is too long.<br>**true** to apply a fade-out effect when the text is too long, **false** otherwise.|

### OH_ArkUI_TextMarqueeOptions_GetFadeout()
``` c
bool OH_ArkUI_TextMarqueeOptions_GetFadeout(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains whether the text marquee option supports a fade-out effect when the text is too long.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the text marquee option supports a fade-out effect when the text is too long.|


### OH_ArkUI_TextMarqueeOptions_SetStartPolicy()
``` c
void OH_ArkUI_TextMarqueeOptions_SetStartPolicy(ArkUI_TextMarqueeOptions* option, ArkUI_MarqueeStartPolicy startPolicy)

```

**Description**

Sets the startup policy of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| [ArkUI_MarqueeStartPolicy](#arkui_marqueestartpolicy) startPolicy| Startup policy.|

### OH_ArkUI_TextMarqueeOptions_GetStartPolicy()
``` c
ArkUI_MarqueeStartPolicy OH_ArkUI_TextMarqueeOptions_GetStartPolicy(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the startup policy of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| ArkUI_MarqueeStartPolicy | Startup policy.|


### OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy()
``` c
void OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy(ArkUI_TextMarqueeOptions* option,
    ArkUI_MarqueeUpdatePolicy updatePolicy)
```

**Description**

Sets the update policy of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|
| [ArkUI_MarqueeUpdatePolicy](#arkui_marqueeupdatepolicy) updatePolicy| Update policy.|

### OH_ArkUI_TextMarqueeOptions_GetUpdatePolicy()
``` c
ArkUI_MarqueeUpdatePolicy OH_ArkUI_TextMarqueeOptions_GetUpdatePolicy(ArkUI_TextMarqueeOptions* option)
```

**Description**

Obtains the update policy of the text marquee option.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_TextMarqueeOptions](./capi-arkui-nativemodule-arkui-textmarqueeoptions.md)* option | Pointer to the text marquee option.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_MarqueeUpdatePolicy](#arkui_marqueeupdatepolicy) | Update policy.|

### OH_ArkUI_SelectedDragPreviewStyle_Create()

```c
ArkUI_SelectedDragPreviewStyle* OH_ArkUI_SelectedDragPreviewStyle_Create();
```

**Description**

Creates a preview style shown when dragging selected text.

**Since**: 23

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)* | Pointer to the **ArkUI_SelectedDragPreviewStyle** object.|


### OH_ArkUI_SelectedDragPreviewStyle_Dispose()

```c
void OH_ArkUI_SelectedDragPreviewStyle_Dispose(ArkUI_SelectedDragPreviewStyle* config)
```

**Description**

Destroys the preview style shown when dragging selected text.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)* config | Pointer to the **ArkUI_SelectedDragPreviewStyle** object.|

### OH_ArkUI_SelectedDragPreviewStyle_SetColor()

```c
void  OH_ArkUI_SelectedDragPreviewStyle_SetColor(ArkUI_SelectedDragPreviewStyle* config, uint32_t color);
```

**Description**

Sets the background color of the preview style shown when dragging selected text.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)* config | Pointer to the **ArkUI_SelectedDragPreviewStyle** object.|
| uint32_t color  | Background color of the preview style shown when dragging selected text, in RGBA format.|

### OH_ArkUI_SelectedDragPreviewStyle_GetColor()

```c
uint32_t OH_ArkUI_SelectedDragPreviewStyle_GetColor(ArkUI_SelectedDragPreviewStyle* config)
```

**Description**

Obtains the background color of the preview style shown when dragging selected text.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md)* config | Pointer to the **ArkUI_SelectedDragPreviewStyle** object.|

**Returns**

| Type| Description|
| -- | -- |
| uint32_t color | Background color of the preview style shown when dragging selected text, in RGBA format.|

### OH_ArkUI_DecorationStyleOptions_Create()

```c
OH_ArkUI_DecorationStyleOptions* OH_ArkUI_DecorationStyleOptions_Create()
```

**Description**

Creates a decorative line style object. When the object is no longer used, call [OH_ArkUI_DecorationStyleOptions_Destroy](capi-native-type-h.md#oh_arkui_decorationstyleoptions_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions*](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|

### OH_ArkUI_DecorationStyleOptions_Destroy()

```c
void OH_ArkUI_DecorationStyleOptions_Destroy(OH_ArkUI_DecorationStyleOptions* options)
```

**Description**

Destroys the decorative line style object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the option object to be destroyed.|

### OH_ArkUI_DecorationStyleOptions_SetTextDecorationType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType type)
```

**Description**

Sets the decoration type of the decorative line style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| [ArkUI_TextDecorationType](capi-native-type-h.md#arkui_textdecorationtype) type | Decoration type ([ArkUI_TextDecorationType](capi-native-type-h.md#arkui_textdecorationtype)).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_GetTextDecorationType()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType* type)
```

**Description**

Obtains the decoration type of the decorative line style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| [ArkUI_TextDecorationType](capi-native-type-h.md#arkui_textdecorationtype)* type | Pointer to the decoration type ([ArkUI_TextDecorationType](capi-native-type-h.md#arkui_textdecorationtype)).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_SetColor()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t color)
```

**Description**

Sets the color of the decorative line.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| uint32_t color | Color of the decorative line, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_GetColor()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t* color)
```

**Description**

Obtains the color of the decorative line.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| uint32_t* color | Pointer to the color of the decorative line, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_SetTextDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle style)
```

**Description**

Sets the style of the decorative line.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| [ArkUI_TextDecorationStyle](capi-native-type-h.md#arkui_textdecorationstyle) style | Style of the decorative line ([ArkUI_TextDecorationStyle](capi-native-type-h.md#arkui_textdecorationstyle)).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_GetTextDecorationStyle()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle* style)
```

**Description**

Obtains the style of the decorative line.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| [ArkUI_TextDecorationStyle](capi-native-type-h.md#arkui_textdecorationstyle)* style | Pointer to the style of the decorative line ([ArkUI_TextDecorationStyle](capi-native-type-h.md#arkui_textdecorationstyle)).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_SetThicknessScale()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float thicknessScale)
```

**Description**

Sets the scale factor of the decorative line thickness.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| float thicknessScale | Scale factor of the decorative line thickness. The value range is [0, +∞).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_DecorationStyleOptions_GetThicknessScale()

```c
ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float* thicknessScale)
```

**Description**

Obtains the scale factor of the decorative line thickness.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|
| float* thicknessScale | Pointer to the scale factor of the decorative line thickness.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_Create()

```c
OH_ArkUI_TextDataDetectorConfig* OH_ArkUI_TextDataDetectorConfig_Create()
```

**Description**

Creates a text entity recognition configuration object. When the object is no longer used, call [OH_ArkUI_TextDataDetectorConfig_Destroy](capi-native-type-h.md#oh_arkui_textdatadetectorconfig_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig*](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|

### OH_ArkUI_TextDataDetectorConfig_Destroy()

```c
void OH_ArkUI_TextDataDetectorConfig_Destroy(OH_ArkUI_TextDataDetectorConfig* config)
```

**Description**

Destroys the text entity recognition configuration object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|

### OH_ArkUI_TextDataDetectorConfig_SetTypes()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetTypes(OH_ArkUI_TextDataDetectorConfig* config, const ArkUI_TextDataDetectorType* types, int32_t length)
```

**Description**

Sets the types of the text entity recognition configuration.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| [const ArkUI_TextDataDetectorType](capi-native-type-h.md#arkui_textdatadetectortype)* types | Pointer to the types of the text entity recognition configuration. The value is an enumerated value of [ArkUI_TextDataDetectorType](capi-native-type-h.md#arkui_textdatadetectortype).|
| int32_t length | Type quantity.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_GetTypes()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetTypes(OH_ArkUI_TextDataDetectorConfig* config, ArkUI_TextDataDetectorType* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the types of the text entity recognition configuration.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| [ArkUI_TextDataDetectorType](capi-native-type-h.md#arkui_textdatadetectortype)* buffer | Pointer to the buffer of the type array.|
| int32_t bufferSize | Maximum number of types that can be written to the buffer reserved for the types.|
| int32_t* writeLength | Pointer to the number of types that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

### OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback(OH_ArkUI_TextDataDetectorConfig* config, void* userData, void (*callback)(const char* result, int32_t length, void* userData))
```

**Description**

Sets the callback for text entity recognition result updates.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)\* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| void\* userData | Pointer to the user data.|
| void (\*callback)(const char\* result | Pointer to the callback when the recognition result is updated. **result** indicates the recognized text entity content. **length** indicates the end position of the selected text. **userData** indicates the user-defined data, which corresponds to the input parameter **userData** of the **OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback** API.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_SetColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t color)
```

**Description**

Sets the color of the recognized content.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| uint32_t color | Color of the recognized content, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_GetColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t* color)
```

**Description**

Obtains the color of the recognized content.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| uint32_t* color | Pointer to the color of the recognized content, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_SetDecorationStyleOptions()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)
```

**Description**

Sets the decoration style of the recognized content.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* decoration | Pointer to the decoration style of the recognized content. The value is an enumerated value of [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_GetDecorationStyleOptions()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)
```

**Description**

Obtains the decoration style of the recognized content.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* decoration | Pointer to the decoration style of the recognized content. The value is an enumerated value of [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_SetEnablePreviewMenu()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool enablePreviewMenu)
```

**Description**

Sets whether to display the preview menu when the recognized content is long-pressed.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| bool enablePreviewMenu | Whether to display the preview menu when the recognized content is long-pressed. **true** means to display the preview menu, and **false** means the opposite. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextDataDetectorConfig_GetEnablePreviewMenu()

```c
ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool* enablePreviewMenu)
```

**Description**

Obtains whether the preview menu is displayed when the recognized content is long-pressed.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md)* config | Pointer to the [OH_ArkUI_TextDataDetectorConfig](capi-arkui-nativemodule-oh-arkui-textdatadetectorconfig.md) object.|
| bool* enablePreviewMenu | Pointer to the **enablePreviewMenu** parameter indicating whether the preview menu is displayed when the recognized content is long-pressed. **true** means that the preview menu is displayed, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_Create()

```c
OH_ArkUI_TextEditorPlaceholderOptions* OH_ArkUI_TextEditorPlaceholderOptions_Create()
```

**Description**

Creates an option object for the placeholder text used when there is no input. When the object is no longer used, call [OH_ArkUI_TextEditorPlaceholderOptions_Destroy](capi-native-type-h.md#oh_arkui_texteditorplaceholderoptions_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions*](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|

### OH_ArkUI_TextEditorPlaceholderOptions_Destroy()

```c
void OH_ArkUI_TextEditorPlaceholderOptions_Destroy(OH_ArkUI_TextEditorPlaceholderOptions* options)
```

**Description**

Destroys the option object for the placeholder text used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetValue()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetValue(OH_ArkUI_TextEditorPlaceholderOptions* options, const char* value)
```

**Description**

Sets the text for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| const char* value | Pointer to the placeholder text.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetValue()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetValue(OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the text for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| char* buffer | Pointer to the buffer for storing the placeholder text in the memory. You need to allocate the memory.|
| int32_t bufferSize | Maximum number of characters that can be written to the buffer.|
| int32_t* writeLength | Pointer to the number of characters that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontSize(OH_ArkUI_TextEditorPlaceholderOptions* options, float fontSize)
```

**Description**

Sets the font size for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| float fontSize | Font size, in fp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontSize(OH_ArkUI_TextEditorPlaceholderOptions* options, float* fontSize)
```

**Description**

Obtains the font size for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| float* fontSize | Pointer to the font size, in fp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontWeight(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontWeight)
```

**Description**

Sets the font weight for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| uint32_t fontWeight | Font weight. The value is an integer multiple of 100 within the [100, 900] range, for example, **100** or **900**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontWeight(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t* fontWeight)
```

**Description**

Obtains the font weight for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| uint32_t* fontWeight | Pointer to the font weight. The value is an integer multiple of 100 within the [100, 900] range, for example, **100** or **900**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontFamily(OH_ArkUI_TextEditorPlaceholderOptions* options, const char* fontFamily)
```

**Description**

Sets the font family for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| const char* fontFamily | Pointer to the font family, containing the font names to be set. Different font names are separated by commas (,).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontFamily(OH_ArkUI_TextEditorPlaceholderOptions* options, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the font family for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| char* buffer | Pointer to the buffer for storing the font family in the memory. You need to allocate the memory.|
| int32_t bufferSize | Maximum number of characters that can be written to the buffer.|
| int32_t* writeLength | Pointer to the number of characters that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-native-type-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontStyle(OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle fontStyle)
```

**Description**

Sets the font style for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle) fontStyle | Font style. The value is an enumerated value of [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontStyle(OH_ArkUI_TextEditorPlaceholderOptions* options, ArkUI_FontStyle* fontStyle)
```

**Description**

Obtains the font style for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle)* fontStyle | Pointer to the font style. The value is an enumerated value of [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_SetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_SetFontColor(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t fontColor)
```

**Description**

Sets the font color for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| uint32_t fontColor | Font color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorPlaceholderOptions_GetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorPlaceholderOptions_GetFontColor(OH_ArkUI_TextEditorPlaceholderOptions* options, uint32_t* fontColor)
```

**Description**

Obtains the font color for the placeholder text options used when there is no input.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorPlaceholderOptions](capi-arkui-nativemodule-oh-arkui-texteditorplaceholderoptions.md) object.|
| uint32_t* fontColor | Pointer to the font color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_Create()

```c
OH_ArkUI_TextEditorStyledStringController* OH_ArkUI_TextEditorStyledStringController_Create()
```

**Description**

Creates a styled string controller object for the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorStyledStringController_Destroy](capi-native-type-h.md#oh_arkui_texteditorstyledstringcontroller_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController*](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|

### OH_ArkUI_TextEditorStyledStringController_Destroy()

```c
void OH_ArkUI_TextEditorStyledStringController_Destroy(OH_ArkUI_TextEditorStyledStringController* controller)
```

**Description**

Destroys the styled string controller object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|

### OH_ArkUI_TextEditorStyledStringController_SetCaretOffset()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t caretOffset)
```

**Description**

Sets the caret offset using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| int32_t caretOffset | Caret offset.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_GetCaretOffset()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t* caretOffset)
```

**Description**

Obtains the caret offset using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| int32_t* caretOffset | Pointer to the caret offset.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_SetSelection()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetSelection(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t start, uint32_t end, ArkUI_MenuPolicy menuPolicy)
```

**Description**

Sets the selected area using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| uint32_t start | Start position of the selected area.|
| uint32_t end | End position of the selected area.|
| [ArkUI_MenuPolicy](capi-native-type-h.md#arkui_menupolicy) menuPolicy | Policy for displaying the menu in the selected area. The value is an enumerated value of [ArkUI_MenuPolicy](capi-native-type-h.md#arkui_menupolicy).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_IsEditing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_IsEditing(OH_ArkUI_TextEditorStyledStringController* controller, bool* isEditing)
```

**Description**

Obtains the editing status of the text editor using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| bool* isEditing | Pointer to the **isEditing** parameter indicating whether the text editor is in the editing state. **true** means that the text editor is in the editing state, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_StopEditing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_StopEditing(OH_ArkUI_TextEditorStyledStringController* controller)
```

**Description**

Exits the editing status of the text editor using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_GetPreviewText()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetPreviewText(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* offset, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the preview text using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| uint32_t* offset | Pointer to the preview text offset.|
| char* buffer | Pointer to the buffer for storing the preview text in the memory. You need to allocate the memory.|
| int32_t bufferSize | Maximum number of characters that can be written to the buffer.|
| int32_t* writeLength | Pointer to the number of characters that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_GetCaretRect()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretRect(OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_Rect* rect)
```

**Description**

Obtains the caret-selected rectangle using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md)* rect | Pointer to the caret-selected rectangle information. The value is an enumerated value of [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_DeleteBackward()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_DeleteBackward(OH_ArkUI_TextEditorStyledStringController* controller)
```

**Description**

Deletes characters using the styled string controller. If no content is selected, one character before the current caret position is deleted. If content is selected, the selected content is deleted.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_Create()

```c
OH_ArkUI_TextEditorParagraphStyle* OH_ArkUI_TextEditorParagraphStyle_Create()
```

**Description**

Creates a paragraph style object for the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorParagraphStyle_Destroy](capi-native-type-h.md#oh_arkui_texteditorparagraphstyle_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle*](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|

### OH_ArkUI_TextEditorParagraphStyle_Destroy()

```c
void OH_ArkUI_TextEditorParagraphStyle_Destroy(OH_ArkUI_TextEditorParagraphStyle* style)
```

**Description**

Destroys the paragraph style object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|

### OH_ArkUI_TextEditorParagraphStyle_SetTextAlign()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment align)
```

**Description**

Sets the text alignment mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextAlignment](capi-native-type-h.md#arkui_textalignment) align | Text alignment mode. The value is an enumerated value of [ArkUI_TextAlignment](capi-native-type-h.md#arkui_textalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetTextAlign()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextAlignment* align)
```

**Description**

Obtains the text alignment mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextAlignment](capi-native-type-h.md#arkui_textalignment)* align | Pointer to the text alignment mode. The value is an enumerated value of [ArkUI_TextAlignment](capi-native-type-h.md#arkui_textalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginPixelMap(OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative* pixelmap)
```

**Description**

Sets the PixelMap for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [struct OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)* pixelmap | Pointer to the PixelMap for paragraph indentation.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginPixelMap()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginPixelMap(OH_ArkUI_TextEditorParagraphStyle* style, struct OH_PixelmapNative** pixelmap)
```

**Description**

Obtains the PixelMap for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [struct OH_PixelmapNative](../../reference/apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md)** pixelmap | Double pointer to the PixelMap for paragraph indentation.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginWidth()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t width)
```

**Description**

Sets the width for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t width | Width for paragraph indentation, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginWidth()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginWidth(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* width)
```

**Description**

Obtains the width for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t* width | Pointer to the width for paragraph indentation, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginHeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t height)
```

**Description**

Sets the height for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t height | Height for paragraph indentation, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginHeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLeadingMarginHeight(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* height)
```

**Description**

Obtains the height for paragraph indentation in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t* height | Pointer to the height for paragraph indentation, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetWordBreak()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_WordBreak wordBreak)
```

**Description**

Sets the word breaking mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_WordBreak](capi-native-type-h.md#arkui_wordbreak) wordBreak | Word breaking mode. The value is an enumerated value of [ArkUI_WordBreak](capi-native-type-h.md#arkui_wordbreak).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetWordBreak()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetWordBreak(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_WordBreak* wordBreak)
```

**Description**

Obtains the word breaking mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_WordBreak](capi-native-type-h.md#arkui_wordbreak)* wordBreak | Pointer to the word breaking mode. The value is an enumerated value of [ArkUI_WordBreak](capi-native-type-h.md#arkui_wordbreak).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetLineBreakStrategy()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style, OH_ArkUI_LineBreakStrategy lineBreakStrategy)
```

**Description**

Sets the line breaking strategy in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [OH_ArkUI_LineBreakStrategy](capi-native-type-h.md#oh_arkui_linebreakstrategy) lineBreakStrategy | Line breaking strategy. The value is an enumerated value of [OH_ArkUI_LineBreakStrategy](capi-native-type-h.md#oh_arkui_linebreakstrategy).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetLineBreakStrategy()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetLineBreakStrategy(OH_ArkUI_TextEditorParagraphStyle* style, OH_ArkUI_LineBreakStrategy* lineBreakStrategy)
```

**Description**

Obtains the line breaking strategy in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [OH_ArkUI_LineBreakStrategy](capi-native-type-h.md#oh_arkui_linebreakstrategy)* lineBreakStrategy | Pointer to the line breaking strategy. The value is an enumerated value of [OH_ArkUI_LineBreakStrategy](capi-native-type-h.md#oh_arkui_linebreakstrategy).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetParagraphSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t paragraphSpacing)
```

**Description**

Sets the paragraph spacing in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t paragraphSpacing | Paragraph spacing, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetParagraphSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetParagraphSpacing(OH_ArkUI_TextEditorParagraphStyle* style, uint32_t* paragraphSpacing)
```

**Description**

Obtains the paragraph spacing in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| uint32_t* paragraphSpacing | Pointer to the paragraph spacing, in vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetTextVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextVerticalAlignment verticalAlignment)
```

**Description**

Sets the text vertical alignment mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextVerticalAlignment](capi-native-type-h.md#arkui_textverticalalignment) verticalAlignment | Text vertical alignment mode. The value is an enumerated value of [ArkUI_TextVerticalAlignment](capi-native-type-h.md#arkui_textverticalalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetTextVerticalAlign()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextVerticalAlign(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextVerticalAlignment* verticalAlignment)
```

**Description**

Obtains the text vertical alignment mode in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextVerticalAlignment](capi-native-type-h.md#arkui_textverticalalignment)* verticalAlignment | Text vertical alignment mode. The value is an enumerated value of [ArkUI_TextVerticalAlignment](capi-native-type-h.md#arkui_textverticalalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_SetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_SetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextDirection textDirection)
```

**Description**

Sets the text direction in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextDirection](capi-native-type-h.md#arkui_textdirection) textDirection | Text direction. The value is an enumerated value of [ArkUI_TextDirection](capi-native-type-h.md#arkui_textdirection).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorParagraphStyle_GetTextDirection()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorParagraphStyle_GetTextDirection(OH_ArkUI_TextEditorParagraphStyle* style, ArkUI_TextDirection* textDirection)
```

**Description**

Obtains the text direction in the paragraph style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md) object.|
| [ArkUI_TextDirection](capi-native-type-h.md#arkui_textdirection)* textDirection | Pointer to the text direction. The value is an enumerated value of [ArkUI_TextDirection](capi-native-type-h.md#arkui_textdirection).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_SetTypingParagraphStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingParagraphStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorParagraphStyle* style)
```

**Description**

Sets the typing paragraph style using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| [OH_ArkUI_TextEditorParagraphStyle](capi-arkui-nativemodule-oh-arkui-texteditorparagraphstyle.md)* style | Pointer to the typing paragraph style.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_Create()

```c
OH_ArkUI_TextEditorTextStyle* OH_ArkUI_TextEditorTextStyle_Create()
```

**Description**

Creates a text style object. When the object is no longer used, call [OH_ArkUI_TextEditorTextStyle_Destroy](capi-native-type-h.md#oh_arkui_texteditortextstyle_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle*](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) | Pointer to the [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) object.|

### OH_ArkUI_TextEditorTextStyle_Destroy()

```c
void OH_ArkUI_TextEditorTextStyle_Destroy(OH_ArkUI_TextEditorTextStyle* style)
```

**Description**

Destroys the text style object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md) object.|

### OH_ArkUI_TextEditorTextStyle_SetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t color)
```

**Description**

Sets the font color of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t color | Font color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t* color)
```

**Description**

Obtains the font color of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t* color | Pointer to the font color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontSize(OH_ArkUI_TextEditorTextStyle* style, float size)
```

**Description**

Sets the font size of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| float size | Font size, in fp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontSize()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontSize(OH_ArkUI_TextEditorTextStyle* style, float* size)
```

**Description**

Obtains the font size of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| float* size | Pointer to the font size, in fp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontStyle(OH_ArkUI_TextEditorTextStyle* style, ArkUI_FontStyle fontStyle)
```

**Description**

Sets the font style of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle) fontStyle | Font style. The value is an enumerated value of [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontStyle(OH_ArkUI_TextEditorTextStyle* style, ArkUI_FontStyle* fontStyle)
```

**Description**

Obtains the font style of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle)* fontStyle | Pointer to the font style. The value is an enumerated value of [ArkUI_FontStyle](capi-native-type-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t fontWeight)
```

**Description**

Sets the font weight of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t fontWeight | Font weight. The value is an integer multiple of 100 within the [100, 900] range, for example, **100** or **900**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontWeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontWeight(OH_ArkUI_TextEditorTextStyle* style, uint32_t* fontWeight)
```

**Description**

Obtains the font weight of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t* fontWeight | Pointer to the font weight. The value is an integer multiple of 100 within the [100, 900] range, for example, **100** or **900**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFamily(OH_ArkUI_TextEditorTextStyle* style, const char* fontFamily)
```

**Description**

Sets the font family of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| const char* fontFamily | Pointer to the font family, containing the font names to be set. Different font names are separated by commas (,).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontFamily()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFamily(OH_ArkUI_TextEditorTextStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the font family of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| char* buffer | Pointer to the buffer for storing the font family in the memory. You need to allocate the memory.|
| int32_t bufferSize | Maximum number of characters that can be written to the buffer.|
| int32_t* writeLength | Pointer to the number of characters that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetDecoration()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetDecoration(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_DecorationStyleOptions* options)
```

**Description**

Sets the text decoration options of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetDecoration()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetDecoration(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_DecorationStyleOptions* options)
```

**Description**

Obtains the text decoration options of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* options | Pointer to the [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetTextShadows()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextShadows(OH_ArkUI_TextEditorTextStyle* style, const OH_ArkUI_ShadowOptions** options, int32_t length)
```

**Description**

Sets the text shadow options of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [const OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)** options | Double pointer to the text shadow options.|
| int32_t length | Length of the text shadow options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetTextShadows()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextShadows(OH_ArkUI_TextEditorTextStyle* style, OH_ArkUI_ShadowOptions** shadowOptions, uint32_t shadowOptionsSize, uint32_t* writeLength)
```

**Description**

Obtains the text shadow options of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| [OH_ArkUI_ShadowOptions](capi-arkui-nativemodule-oh-arkui-shadowoptions.md)** shadowOptions | Double pointer to the text shadow options.|
| uint32_t shadowOptionsSize | Size of the shadow option buffer.|
| uint32_t* writeLength | Pointer to the number of actual text shadow options in the text style.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetLineHeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t lineHeight)
```

**Description**

Sets the line height of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| int32_t lineHeight | Line height.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetLineHeight()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLineHeight(OH_ArkUI_TextEditorTextStyle* style, int32_t* lineHeight)
```

**Description**

Obtains the line height of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| int32_t* lineHeight | Pointer to the line height.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetLetterSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style, int32_t letterSpacing)
```

**Description**

Sets the letter spacing of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| int32_t letterSpacing | Letter spacing.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetLetterSpacing()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetLetterSpacing(OH_ArkUI_TextEditorTextStyle* style, int32_t* letterSpacing)
```

**Description**

Obtains the letter spacing of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| int32_t* letterSpacing | Pointer to the letter spacing.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetFontFeature()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetFontFeature(OH_ArkUI_TextEditorTextStyle* style, const char* fontFeature)
```

**Description**

Sets the font feature of the text style, such as monospaced digits.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| const char* fontFeature | Pointer to the font features, containing font features to be set. Multiple features are separated by commas (,).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetFontFeature()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetFontFeature(OH_ArkUI_TextEditorTextStyle* style, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the font feature of the text style, such as monospaced digits.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| char* buffer | Pointer to the buffer for storing the font features in the memory. You need to allocate the memory.|
| int32_t bufferSize | Maximum number of characters that can be written to the buffer.|
| int32_t* writeLength | Pointer to the number of characters that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetHalfLeading()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool halfLeading)
```

**Description**

Sets whether to evenly distribute the line spacing to the top and bottom of each line in the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| bool halfLeading | Whether to enable half leading.<br>                    **true** means to enable, and **false** means the opposite. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetHalfLeading()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetHalfLeading(OH_ArkUI_TextEditorTextStyle* style, bool* halfLeading)
```

**Description**

Obtains whether the line spacing is evenly distributed to the top and bottom of each line in the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| bool* halfLeading | Pointer to the **halfLeading** parameter indicating whether half leading is enabled.<br>                    **true** means half leading is enabled, and **false** means the opposite. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetTextBackgroundColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t color)
```

**Description**

Sets the text background color of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t color | Text background color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetTextBackgroundColor()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundColor(OH_ArkUI_TextEditorTextStyle* style, uint32_t* color)
```

**Description**

Obtains the text background color of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| uint32_t* color | Pointer to the text background color, in 0xARGB format.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_SetTextBackgroundRadius()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_SetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style, float topLeft, float topRight, float bottomLeft, float bottomRight)
```

**Description**

Sets the radius of the rounded corner of the text background of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| float topLeft | Radius of the rounded corner in the upper left corner of the text background. The unit is vp.|
| float topRight | Radius of the rounded corner in the upper right corner of the text background. The unit is vp.|
| float bottomLeft | Radius of the rounded corner in the lower left corner of the text background. The unit is vp.|
| float bottomRight | Radius of the rounded corner in the lower right corner of the text background. The unit is vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorTextStyle_GetTextBackgroundRadius()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorTextStyle_GetTextBackgroundRadius(OH_ArkUI_TextEditorTextStyle* style, float* topLeft, float* topRight, float* bottomLeft, float* bottomRight)
```

**Description**

Obtains the radius of the rounded corner of the text background of the text style.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the text style of the **TextEditor** component.|
| float* topLeft | Pointer to the radius of the rounded corner in the upper left corner of the text background. The unit is vp.|
| float* topRight | Pointer to the radius of the rounded corner in the upper right corner of the text background. The unit is vp.|
| float* bottomLeft | Pointer to the radius of the rounded corner in the lower left corner of the text background. The unit is vp.|
| float* bottomRight | Pointer to the radius of the rounded corner in the lower right corner of the text background. The unit is vp.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_SetTypingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetTypingStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)
```

**Description**

Sets the typing style using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the typing style.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_GetTypingStyle()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetTypingStyle(OH_ArkUI_TextEditorStyledStringController* controller, OH_ArkUI_TextEditorTextStyle* style)
```

**Description**

Obtains the typing style using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| [OH_ArkUI_TextEditorTextStyle](capi-arkui-nativemodule-oh-arkui-texteditortextstyle.md)* style | Pointer to the typing style.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_Create()

```c
OH_ArkUI_TextEditorSelectionMenuOptions* OH_ArkUI_TextEditorSelectionMenuOptions_Create()
```

**Description**

Creates a text selection menu option object of the text editor. When the object is no longer used, call [OH_ArkUI_TextEditorSelectionMenuOptions_Destroy](capi-native-type-h.md#oh_arkui_texteditorselectionmenuoptions_destroy) to destroy it.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions*](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|

### OH_ArkUI_TextEditorSelectionMenuOptions_Destroy()

```c
void OH_ArkUI_TextEditorSelectionMenuOptions_Destroy(OH_ArkUI_TextEditorSelectionMenuOptions* options)
```

**Description**

Destroys the text selection menu option object of the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|

### OH_ArkUI_TextEditorSelectionMenuOptions_SetSpanType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetSpanType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType textEditorSpanType)
```

**Description**

Sets the span type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextEditorSpanType](capi-native-type-h.md#oh_arkui_texteditorspantype) textEditorSpanType | Span type. The value is an enumerated value of [OH_ArkUI_TextEditorSpanType](capi-native-type-h.md#oh_arkui_texteditorspantype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_GetSpanType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetSpanType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorSpanType* textEditorSpanType)
```

**Description**

Obtains the span type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextEditorSpanType](capi-native-type-h.md#oh_arkui_texteditorspantype)* textEditorSpanType | Pointer to the span type. The value is an enumerated value of [OH_ArkUI_TextEditorSpanType](capi-native-type-h.md#oh_arkui_texteditorspantype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_SetContentNode()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options, ArkUI_NodeHandle node)
```

**Description**

Sets the content node of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Content node.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_GetContentNode()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetContentNode(OH_ArkUI_TextEditorSelectionMenuOptions* options, ArkUI_NodeHandle* node)
```

**Description**

Obtains the content node of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md)* node | Pointer to the content node.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_SetResponseType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetResponseType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType responseType)
```

**Description**

Sets the response type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextEditorResponseType](capi-native-type-h.md#oh_arkui_texteditorresponsetype) responseType | Response type. The value is an enumerated value of [OH_ArkUI_TextEditorResponseType](capi-native-type-h.md#oh_arkui_texteditorresponsetype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_GetResponseType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetResponseType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextEditorResponseType* responseType)
```

**Description**

Obtains the response type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextEditorResponseType](capi-native-type-h.md#oh_arkui_texteditorresponsetype)* responseType | Pointer to the response type. The value is an enumerated value of [OH_ArkUI_TextEditorResponseType](capi-native-type-h.md#oh_arkui_texteditorresponsetype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_SetMenuType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextMenuType menuType)
```

**Description**

Sets the type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextMenuType](capi-native-type-h.md#oh_arkui_textmenutype) menuType | Menu type. The value is an enumerated value of [OH_ArkUI_TextMenuType](capi-native-type-h.md#oh_arkui_textmenutype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_GetMenuType()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetMenuType(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_TextMenuType* menuType)
```

**Description**

Obtains the type of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_TextMenuType](capi-native-type-h.md#oh_arkui_textmenutype)* menuType | Pointer to the menu type. The value is an enumerated value of [OH_ArkUI_TextMenuType](capi-native-type-h.md#oh_arkui_textmenutype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuShowCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuShowCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (*callback)(int32_t start, int32_t end, void* callbackUserData))
```

**Description**

Sets the callback triggered when the text selection menu is displayed.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)\* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| void\* userData | Pointer to the user data.|
| void (\*callback)(int32_t start | Pointer to the callback when the menu is displayed. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuHideCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuHideCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (*callback)(int32_t start, int32_t end, void* callbackUserData))
```

**Description**

Sets the callback triggered when the text selection menu is hidden.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)\* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| void\* userData | Pointer to the user data.|
| void (\*callback)(int32_t start | Pointer to the callback when the menu is hidden. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuAppearCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuAppearCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (*callback)(int32_t start, int32_t end, void* callbackUserData))
```

**Description**

Sets the callback triggered when the text selection menu appears.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)\* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| void\* userData | Pointer to the user data.|
| void (\*callback)(int32_t start | Pointer to the callback when the menu appears. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuDisappearCallback()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_RegisterOnMenuDisappearCallback(OH_ArkUI_TextEditorSelectionMenuOptions* options, void* userData, void (*callback)(void* callbackUserData))
```

**Description**

Sets the callback triggered when the text selection menu disappears.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)\* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| void\* userData | Pointer to the user data.|
| void (\*callback)(void\* callbackUserData) | Pointer to the callback when the menu disappears. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_SetHapticFeedbackMode()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_SetHapticFeedbackMode(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode mode)
```

**Description**

Sets the haptic feedback mode of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_HapticFeedbackMode](capi-native-type-h.md#oh_arkui_hapticfeedbackmode) mode | Haptic feedback mode. The value is an enumerated value of [OH_ArkUI_HapticFeedbackMode](capi-native-type-h.md#oh_arkui_hapticfeedbackmode).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorSelectionMenuOptions_GetHapticFeedbackMode()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorSelectionMenuOptions_GetHapticFeedbackMode(OH_ArkUI_TextEditorSelectionMenuOptions* options, OH_ArkUI_HapticFeedbackMode* mode)
```

**Description**

Obtains the haptic feedback mode of the text selection menu in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md)* options | Pointer to the [OH_ArkUI_TextEditorSelectionMenuOptions](capi-arkui-nativemodule-oh-arkui-texteditorselectionmenuoptions.md) object.|
| [OH_ArkUI_HapticFeedbackMode](capi-native-type-h.md#oh_arkui_hapticfeedbackmode)* mode | Pointer to the haptic feedback mode. The value is an enumerated value of [OH_ArkUI_HapticFeedbackMode](capi-native-type-h.md#oh_arkui_hapticfeedbackmode).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_CloseSelectionMenu()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_CloseSelectionMenu(OH_ArkUI_TextEditorStyledStringController* controller)
```

**Description**

Closes the text selection menu of the styled string controller in the text editor.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
### OH_ArkUI_TextEditorStyledStringController_GetSelection()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetSelection(const OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* start, uint32_t* end)
```

**Description**

Obtains the selected area using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| uint32_t* start | Pointer to the start position of the selected area.|
| uint32_t* end | Pointer to the end position of the selected area.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_SetStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledString(const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Sets the styled string displayed using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [ OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| const [ ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to the [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_GetStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetStyledString(const OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Obtains the styled string displayed using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [ OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to the [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_SetStyledPlaceholder()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetStyledPlaceholder(const OH_ArkUI_TextEditorStyledStringController* controller, const ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Sets the placeholder text in the styled string style using the styled string controller.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| const [ OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| const [ ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to the [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_TextEditorStyledStringController_ScrollToVisible()

```c
ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_ScrollToVisible(const OH_ArkUI_TextEditorStyledStringController* controller, int32_t start, int32_t end)
```

**Description**

Scrolls the content within the range from the specified start index to the end index to the visible area using the styled string controller.

**Since**: 26.0.0

**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md)* controller | Pointer to the [OH_ArkUI_TextEditorStyledStringController](capi-arkui-nativemodule-oh-arkui-texteditorstyledstringcontroller.md) object.|
| int32_t start                                                | Start index.<br>     The start index must be less than or equal to the end index. Otherwise, the API call is invalid. The value range is [0, Total length of the content in the **TextEditor** component]. If the start index is less than 0, 0 is used. If the start index is greater than the total length, the total length is used.|
| int32_t end                                                  | End index.<br>     The end index must be greater than or equal to the start index. Otherwise, the API call is invalid. The value range is [0, Total length of the content in the **TextEditor** component]. If the end index is less than 0, 0 is used. If the end index is greater than the total length, the total length is used.|

**Returns**

| Type                                                    | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PickerIndicatorStyle_ConfigureBackground()

``` c
ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorBackground* background)
```

**Description**

Sets the background style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_BACKGROUND](capi-picker-h.md#arkui_pickerindicatortype).

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)* style | Pointer to the [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md) instance.|
| [ArkUI_PickerIndicatorBackground](capi-arkui-nativemodule-arkui-pickerindicatorbackground.md)* background | Pointer to the background.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_PickerIndicatorStyle_ConfigureDivider()

``` c
ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorDivider* divider)
```

**Description**

Sets the divider style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_DIVIDER](capi-picker-h.md#arkui_pickerindicatortype).

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)* style | Pointer to the [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md) instance.|
| [ArkUI_PickerIndicatorDivider](capi-arkui-nativemodule-arkui-pickerindicatordivider.md)* divider | Pointer to the divider style.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_FontWeightConfigs_Create()

```c
OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontWeightConfigs_Create()
```

**Description**

Creates a text font weight configuration object.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs*](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md) | Pointer to the text font weight configuration object. If the creation fails, a null pointer is returned.|

### OH_ArkUI_FontWeightConfigs_Destroy()

```c
void OH_ArkUI_FontWeightConfigs_Destroy(OH_ArkUI_FontWeightConfigs* option)
```

**Description**

Destroys the text font weight configuration object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* option | Pointer to the text font weight configuration object to be destroyed.|

### OH_ArkUI_FontWeightConfigs_SetEnableVariableFontWeight()

```c
void OH_ArkUI_FontWeightConfigs_SetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option, bool enable)
```

**Description**

Sets whether to enable variable font weight adjustment.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* option | Pointer to the text font weight configuration object to be modified.|
| bool enable | Whether to enable variable font weight adjustment. **true** indicates to enable variable font weight adjustment. If the value of **weight** is any integer in the range of [100, 900], the value of **weight** is used. Otherwise, the default value **400** is used. **false** indicates to disable variable font weight adjustment. If the value of **weight** is an integer multiple of 100 in the range of [100, 900], the value of **weight** is used. Otherwise, the default value **400** is used. The default value is **false**.|

### OH_ArkUI_FontWeightConfigs_GetEnableVariableFontWeight()

```c
bool OH_ArkUI_FontWeightConfigs_GetEnableVariableFontWeight(OH_ArkUI_FontWeightConfigs* option)
```

**Description**

Obtains whether variable weight adjustment is enabled for the text font weight configuration object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* option | Pointer to the text font weight configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether variable font weight adjustment is enabled.<br>        **true** indicates variable font weight adjustment is enabled. If the value of **weight** is any integer in the range of [100, 900], the value of **weight** is used. Otherwise, the default value **400** is used.<br>         **false** indicates variable font weight adjustment is disabled. If the value of **weight** is an integer multiple of 100 in the range of [100, 900], the value of **weight** is used. Otherwise, the default value **400** is used.<br>         The default value is **false**. If the value of **weight** is not within the range of [100, 900], the default value **400** is used.|

### OH_ArkUI_FontWeightConfigs_SetEnableDeviceFontWeightCategory()

```c
void OH_ArkUI_FontWeightConfigs_SetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option, bool enable)
```

**Description**

Sets whether to automatically update the text font weight when the font weight level of the device changes.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* option | Pointer to the text font weight configuration object to be modified.|
| bool enable | Whether to enable the text font weight to be updated along with the font weight level of the device. **true** indicates that the text font weight is automatically updated when the font weight level of the device changes. **false** indicates that the text font weight is not automatically updated when the font weight level of the device changes. The default value is **true**.|

### OH_ArkUI_FontWeightConfigs_GetEnableDeviceFontWeightCategory()

```c
bool OH_ArkUI_FontWeightConfigs_GetEnableDeviceFontWeightCategory(OH_ArkUI_FontWeightConfigs* option)
```

**Description**

Obtains whether the text font weight is updated along with the font weight level of the device.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* option | Pointer to the text font weight configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Whether the text font weight is updated along with the font weight level of the device.<br>         **true** indicates that the text font weight is automatically updated when the font weight level of the device changes.<br>         **false** indicates that the text font weight is not automatically updated when the font weight level of the device changes.|

### OH_ArkUI_FontConfigs_Create()

```c
OH_ArkUI_FontConfigs* OH_ArkUI_FontConfigs_Create()
```

**Description**

Creates a text font configuration object.

**Since**: 24

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_FontConfigs*](capi-arkui-nativemodule-oh-arkui-fontconfigs.md) | Pointer to the text font configuration object. If the creation fails, a null pointer is returned.|

### OH_ArkUI_FontConfigs_Destroy()

```c
void OH_ArkUI_FontConfigs_Destroy(OH_ArkUI_FontConfigs* option)
```

**Description**

Destroys the text font configuration object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md)* option | Pointer to the text font configuration object to be destroyed.|

### OH_ArkUI_FontConfigs_SetFontWeightConfigs()

```c
void OH_ArkUI_FontConfigs_SetFontWeightConfigs(OH_ArkUI_FontConfigs* option, OH_ArkUI_FontWeightConfigs* fontWeightConfigs)
```

**Description**

Sets the text font weight configurations for the text font configuration object. When the object is a null pointer, if the user does not explicitly set the object, the default values of the parameters are used (that is, variable font weight adjustment is disabled by default, and the text font weight is updated based on the device font weight level by default). When the object is a null pointer, the default values are not used, and the text font weight behavior is the same as that of the parent component.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md)* option | Pointer to the text font configuration object to be modified.|
| [OH_ArkUI_FontWeightConfigs](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md)* fontWeightConfigs | Pointer to the font weight configuration.|

### OH_ArkUI_FontConfigs_GetFontWeightConfigs()

```c
OH_ArkUI_FontWeightConfigs* OH_ArkUI_FontConfigs_GetFontWeightConfigs(OH_ArkUI_FontConfigs* option)
```

**Description**

Obtains the text font weight configurations of the text font configuration object.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_FontConfigs](capi-arkui-nativemodule-oh-arkui-fontconfigs.md)* option | Pointer to the text font configuration object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_FontWeightConfigs*](capi-arkui-nativemodule-oh-arkui-fontweightconfigs.md) | Text font width configurations.|

### OH_ArkUI_TextController_Create()

```c
OH_ArkUI_TextController* OH_ArkUI_TextController_Create()
```

**Description**

Creates a text component controller object.

**Since**: 26.0.0

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_TextController*](capi-arkui-nativemodule-oh-arkui-textcontroller.md) | Pointer to the text component controller object. If the creation fails, a null pointer is returned.|

### OH_ArkUI_TextController_Destroy()

```c
void OH_ArkUI_TextController_Destroy(OH_ArkUI_TextController* controller)
```

**Description**

Destroys the text component controller object.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextController](capi-arkui-nativemodule-oh-arkui-textcontroller.md)* controller | Pointer to the text component controller object.|

### OH_ArkUI_TextController_SetStyledString()

```c
ArkUI_ErrorCode OH_ArkUI_TextController_SetStyledString(OH_ArkUI_TextController* controller, ArkUI_StyledString_Descriptor* descriptor)
```

**Description**

Sets a styled string for the text component.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_TextController](capi-arkui-nativemodule-oh-arkui-textcontroller.md)* controller | Pointer to the [OH_ArkUI_TextController](capi-arkui-nativemodule-oh-arkui-textcontroller.md) object.|
| [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md)* descriptor | Pointer to the [ArkUI_StyledString_Descriptor](capi-arkui-nativemodule-arkui-styledstring-descriptor.md) object.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_Create()

```c
OH_ArkUI_LinearGradientOptions* OH_ArkUI_LinearGradientOptions_Create()
```

**Description**

Creates an object for linear gradient effect options.

**Since**: 26.0.0

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions*](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) | Pointer to the [OH_ArkUI_LinearGradientOptions*](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|

### OH_ArkUI_LinearGradientOptions_Destroy()

```c
void OH_ArkUI_LinearGradientOptions_Destroy(OH_ArkUI_LinearGradientOptions* options)
```

**Description**

Destroys the object for linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|

### OH_ArkUI_LinearGradientOptions_SetAngle()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetAngle(OH_ArkUI_LinearGradientOptions* options, float angle)
```

**Description**

Sets the angle in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| float angle | Angle in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_GetAngle()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetAngle(const OH_ArkUI_LinearGradientOptions* options, float* angle)
```

**Description**

Obtains the angle in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| float* angle | Pointer to the angle in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_SetDirection()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetDirection(OH_ArkUI_LinearGradientOptions* options, ArkUI_LinearGradientDirection direction)
```

**Description**

Sets the direction in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| [ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection) direction | Direction in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_GetDirection()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetDirection(const OH_ArkUI_LinearGradientOptions* options, ArkUI_LinearGradientDirection* direction)
```

**Description**

Obtains the direction in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| [ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection)* direction | Pointer to the direction in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_SetRepeating()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetRepeating(OH_ArkUI_LinearGradientOptions* options, bool repeating)
```

**Description**

Sets whether the color is repeated in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| bool repeating | Whether the color is repeated in linear gradient options. The value **false** indicates that the color is not repeated, and the value **true** indicates that the color is repeated. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_GetRepeating()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetRepeating(const OH_ArkUI_LinearGradientOptions* options, bool* repeating)
```

**Description**

Obtains whether the color is repeated in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| bool* repeating | Pointer to the **repeating** parameter indicating whether the color is repeated in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_SetColorStop()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetColorStop(OH_ArkUI_LinearGradientOptions* options, const uint32_t* colors, const float* stops, int32_t colorsAndStopsSize)
```

**Description**

Sets the color stop in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| const uint32_t* colors | Pointer to the color array.|
| const float* stops | Pointer to the color stop array.|
| int32_t colorsAndStopsSize | Number of elements in the color and color stop arrays. The number of elements in the color array must be the same as that in the color stop array.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_GetColorStop()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_GetColorStop(const OH_ArkUI_LinearGradientOptions* options, uint32_t* colors, float* stops, int32_t colorsAndStopsSize, int32_t* writeLength)
```

**Description**

Obtains the color stop in linear gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| uint32_t* colors | Pointer to the color array.|
| float* stops | Pointer to the color stop array.|
| int32_t colorsAndStopsSize | Number of elements in the color and color stop arrays. The number of elements in the color array must be the same as that in the color stop array.|
| int32_t* writeLength | Pointer to the number of colors and color stops that are actually written.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_Create()

```c
OH_ArkUI_RadialGradientOptions* OH_ArkUI_RadialGradientOptions_Create()
```

**Description**

Creates an object for radial gradient effect options.

**Since**: 26.0.0

**Returns**

| Type| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions*](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|

### OH_ArkUI_RadialGradientOptions_Destroy()

```c
void OH_ArkUI_RadialGradientOptions_Destroy(OH_ArkUI_RadialGradientOptions* options)
```

**Description**

Destroys the object for radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|

### OH_ArkUI_RadialGradientOptions_SetCenterX()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetCenterX(OH_ArkUI_RadialGradientOptions* options, float centerX)
```

**Description**

Sets the X coordinate of the center point in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float centerX | X coordinate of the center point in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_GetCenterX()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetCenterX(const OH_ArkUI_RadialGradientOptions* options, float* centerX)
```

**Description**

Obtains the X coordinate of the center point in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float* centerX | Pointer to the X coordinate of the center point in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_SetCenterY()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetCenterY(OH_ArkUI_RadialGradientOptions* options, float centerY)
```

**Description**

Sets the Y coordinate of the center point in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float centerY | Y coordinate of the center point in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_GetCenterY()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetCenterY(const OH_ArkUI_RadialGradientOptions* options, float* centerY)
```

**Description**

Obtains the Y coordinate of the center point in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float* centerY | Pointer to the Y coordinate of the center point in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_SetRadius()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetRadius(OH_ArkUI_RadialGradientOptions* options, float radius)
```

**Description**

Sets the radius in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float radius | Radius in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_GetRadius()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetRadius(const OH_ArkUI_RadialGradientOptions* options, float* radius)
```

**Description**

Obtains the radius in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| float* radius | Pointer to the radius in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_SetRepeating()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetRepeating(OH_ArkUI_RadialGradientOptions* options, bool repeating)
```

**Description**

Sets whether the color is repeated in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| bool repeating | Whether the color is repeated in radial gradient options. The value **false** indicates that the color is not repeated, and the value **true** indicates that the color is repeated. The default value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_GetRepeating()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetRepeating(const OH_ArkUI_RadialGradientOptions* options, bool* repeating)
```

**Description**

Obtains whether the color is repeated in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| bool* repeating | Pointer to the **repeating** parameter indicating whether the color is repeated in radial gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_SetColorStop()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_SetColorStop(OH_ArkUI_RadialGradientOptions* options, const uint32_t* colors, const float* stops, int32_t colorsAndStopsSize)
```

**Description**

Sets the color stop in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| const uint32_t* colors | Pointer to the color array.|
| const float* stops | Pointer to the color stop array.|
| int32_t colorsAndStopsSize | Number of elements in the color and color stop arrays. The number of elements in the color array must be the same as that in the color stop array.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_RadialGradientOptions_GetColorStop()

```c
ArkUI_ErrorCode OH_ArkUI_RadialGradientOptions_GetColorStop(const OH_ArkUI_RadialGradientOptions* options, uint32_t* colors, float* stops, int32_t colorsAndStopsSize, int32_t* writeLength)
```

**Description**

Obtains the color stop in radial gradient effect options.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md)* options | Pointer to the [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) object.|
| uint32_t* colors | Pointer to the buffer of the color array.|
| float* stops | Pointer to the color stop array.|
| int32_t colorsAndStopsSize | Number of elements in the color and color stop arrays. The number of elements in the color array must be the same as that in the color stop array.|
| int32_t* writeLength | Pointer to the number of color stops that are actually written.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
