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
| [ArkUI_Node](capi-arkui-nativemodule-arkui-node-descriptor.md) | ArkUI_Node | Defines an ArkUI native component object, which is used by the **ArkUI_NodeHandle** pointer to identify and pass component instances in native APIs.|
| [ArkUI_ContextCallback](capi-arkui-nativemodule-arkui-contextcallback.md) | ArkUI_ContextCallback | Defines an event callback type, which is used to define the callback function and its user-defined data. When an API of this type is called to trigger a callback, the callback is invoked and **userData** is passed as a parameter.|
| [ArkUI_NumberValue](capi-arkui-nativemodule-arkui-numbervalue.md) | ArkUI_NumberValue | Defines a numeric type used by ArkUI on the native side, including floating-point, signed integer, and unsigned integer types.|
| [ArkUI_ColorStop](capi-arkui-nativemodule-arkui-colorstop.md) | ArkUI_ColorStop | Defines a color stop, which is used to configure the gradient effect of a component. Multiple gradient styles can be defined by combining the color array and position array.|
| [ArkUI_Rect](capi-arkui-nativemodule-arkui-rect.md) | ArkUI_Rect | Defines a mask area.|
| [ArkUI_IntSize](capi-arkui-nativemodule-arkui-intsize.md) | ArkUI_IntSize | Describes the width and height of a component.|
| [ArkUI_IntOffset](capi-arkui-nativemodule-arkui-intoffset.md) | ArkUI_IntOffset | Defines an offset, which describes the position of the current component relative to its parent component.|
| [ArkUI_NativeDialog](capi-arkui-nativemodule-arkui-nativedialog.md) | - | Defines a custom dialog box controller object for ArkUI on the native side.|
| [ArkUI_LayoutConstraint](capi-arkui-nativemodule-arkui-layoutconstraint.md) | ArkUI_LayoutConstraint | Defines the layout constraint, which is used to limit the size range during component layout. You can set the minimum and maximum size constraints. The constraint values are non-negative floating-point numbers. During component layout, the system limits the final size range of the component based on the constraint values to ensure that the layout result meets the constraints. This struct is applicable to scenarios where the size range of child components needs to be controlled during custom layout container design. For example, in a waterfall layout, the height of image cards can be limited; in a grid layout, the size of cells can be limited. It is also applicable to scenarios where the upper and lower limits of the component size need to be restricted. For example, the maximum width of an image display component can be limited to prevent stretching, and the minimum size can be limited in a responsive layout to ensure readability. This prevents the component size from exceeding the expected range, enabling more precise layout control, improving the predictability and stability of the layout, and enhancing the controllability of the interface.|
| [ArkUI_DrawContext](capi-arkui-nativemodule-arkui-drawcontext.md) | ArkUI_DrawContext | Defines component drawing context, which is used to provide drawing context information during the drawing of a custom component. You can obtain the canvas pointer used for drawing and the size of the drawing area.|
| [ArkUI_Node*](capi-arkui-nativemodule-arkui-node8h.md) | ArkUI_NodeHandle | Defines the pointer to an ArkUI native component object, which is used to identify and pass component instances in ArkUI native APIs, for example, creating, mounting, removing, or destroying component nodes.|
| [ArkUI_NativeDialog*](capi-arkui-nativemodule-arkui-nativedialog8h.md) | ArkUI_NativeDialogHandle | Defines the handle to the custom dialog box controller of ArkUI on the native side.|
| [ArkUI_GestureCollectInterceptInfo](capi-arkui-nativemodule-arkui-gesturecollectinterceptinfo.md) | ArkUI_GestureCollectInterceptInfo | Defines gesture collection interception information.|
| [ArkUI_ListItemSwipeActionItem](capi-arkui-nativemodule-arkui-listitemswipeactionitem.md) | ArkUI_ListItemSwipeActionItem | Defines the item configuration for **ListItemSwipeActionOption**.|
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md) | ArkUI_ListItemSwipeActionOption | Defines the configuration for **ListItemSwipeActionOption**.|
| [ArkUI_Context](capi-arkui-nativemodule-arkui-context.md) | ArkUI_Context | Defines a context object of the ArkUI native UI, which is used to represent the UI context of the page where the component is located. The pointer type is [ArkUI_ContextHandle](capi-arkui-nativemodule-arkui-context8h.md). You can obtain the context using [OH_ArkUI_GetContextByNode](capi-native-node-h.md#oh_arkui_getcontextbynode) and use it as the context input parameter for APIs such as dragging, animation, and UI task scheduling.|
| [ArkUI_Context*](capi-arkui-nativemodule-arkui-context8h.md) | ArkUI_ContextHandle | Defines the pointer to the context object of ArkUI on the native side, which is used to represent the UI context of the page where the component is located. You can obtain the pointer through [OH_ArkUI_GetContextByNode](capi-native-node-h.md#oh_arkui_getcontextbynode) or [OH_ArkUI_GetContextFromNapiValue](capi-native-node-napi-h.md#oh_arkui_getcontextfromnapivalue) and use it as the context input parameter for APIs such as UI task scheduling, animation, and focus control.|
| [ArkUI_NodeContent*](capi-arkui-nativemodule-arkui-nodecontent8h.md) | ArkUI_NodeContentHandle | Defines the pointer to the node content on the native side, which is used to reference and pass the **NodeContent** instance in native APIs.|
| [ArkUI_CustomProperty](capi-arkui-nativemodule-arkui-customproperty.md) | ArkUI_CustomProperty | Defines custom property information, which is used to represent the custom property of a component. You can use related APIs to add, remove, and obtain custom properties for ArkUI components, and obtain the string values of custom properties.|
| [ArkUI_HostWindowInfo](capi-arkui-nativemodule-arkui-hostwindowinfo.md) | ArkUI_HostWindowInfo | Defines host window information.|
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) | ArkUI_ActiveChildrenInfo | Defines active child node information, which is used to store information about the FrameNode child nodes whose internal active state is **true**. You can query the number of child nodes and obtain child nodes by subscript. The instance of this struct is generated by calling **OH_ArkUI_NodeUtils_GetActiveChildrenInfo**. After using the instance, you must call **OH_ArkUI_ActiveChildrenInfo_Destroy** to destroy it.|
| [ArkUI_CrossLanguageOption](capi-arkui-nativemodule-arkui-crosslanguageoption.md) | ArkUI_CrossLanguageOption | Defines a cross-language configuration option, which is used to configure the cross-language access capability of a target node, for example, whether cross-language attribute modification is allowed. Since API version 26.0.0, you can also configure cross-language operation status of a node tree.|
| [ArkUI_AccessibilityState](capi-arkui-nativemodule-arkui-accessibilitystate.md) | ArkUI_AccessibilityState | Defines a component accessibility state.|
| [ArkUI_AccessibilityValue](capi-arkui-nativemodule-arkui-accessibilityvalue.md) | ArkUI_AccessibilityValue | Defines a component accessibility value.|
| [ArkUI_SystemFontStyleEvent](capi-arkui-nativemodule-arkui-systemfontstyleevent.md) | ArkUI_SystemFontStyleEvent | Defines a system font style change event, which is used to pass the event information to the registered system font style change callback when the system font size or weight changes.|
| [ArkUI_SelectionOptions](capi-arkui-nativemodule-arkui-selectionoptions.md)| ArkUI_SelectionOptions | Defines the options for the selection operation in ArkUI. It is applicable to scenarios where selection interaction is required within an application, providing you with the capability to customize selection behavior.|
| [ArkUI_ContentTransitionEffect](capi-arkui-nativemodule-arkui-contenttransitioneffect.md)|ArkUI_ContentTransitionEffect|Defines the content transition effect.|
| [ArkUI_SelectedDragPreviewStyle](capi-arkui-nativemodule-arkui-textselecteddragpreviewstyle.md) | ArkUI_SelectedDragPreviewStyle | Defines the text drag preview style in the selected state. It is applicable to scenarios where the preview effect in selected state needs to be displayed during text dragging, improving user interaction experience.|
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) | OH_ArkUI_LinearGradientOptions | Defines linear gradient options, which are used to describe the linear color gradient configuration of UI components. You can set the gradient direction, angle, and color to implement flexible linear gradient effects, improving the visual presentation capability of the UI. This is applicable to scenarios where a linear gradient style needs to be applied to components.|
| [OH_ArkUI_RadialGradientOptions](capi-arkui-nativemodule-oh-arkui-radialgradientoptions.md) | OH_ArkUI_RadialGradientOptions | Defines radial gradient options, which are applicable to scenarios where a radial gradient effect needs to be implemented in UI components. This helps you enrich the visual hierarchy of the UI.|

### Enums

| Name                                                                 | typedef Keyword                     | Description                               |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_CopyOptions](#arkui_copyoptions)                             | ArkUI_CopyOptions               | Enumerates the text copy and paste modes.                   |
| [ArkUI_AccessibilityCheckedState](#arkui_accessibilitycheckedstate) | ArkUI_AccessibilityCheckedState | Enumerates the accessibility check box states.                 |
| [ArkUI_AccessibilityActionType](#arkui_accessibilityactiontype)     | ArkUI_AccessibilityActionType   | Enumerates the accessibility action types.                       |
| [ArkUI_BorderStyle](#arkui_borderstyle)                             | ArkUI_BorderStyle               | Enumerates the border styles.                       |
| [ArkUI_AccessibilityMode](#arkui_accessibilitymode)                 | ArkUI_AccessibilityMode         | Enumerates the accessibility modes.                     |
| [ArkUI_AdaptiveColor](#arkui_adaptivecolor)                         | ArkUI_AdaptiveColor             | Enumerates the adaptive color modes.                          |
| [ArkUI_ColorMode](#arkui_colormode)                                 | ArkUI_ColorMode                 | Enumerates the color modes.                         |
| [ArkUI_SystemColorMode](#arkui_systemcolormode)                     | ArkUI_SystemColorMode           | Enumerates the system color modes.                       |
| [ArkUI_LengthMetricUnit](#arkui_lengthmetricunit)                   | ArkUI_LengthMetricUnit          | Enumerates the component units.                       |
| [ArkUI_ListItemSwipeActionState](#arkui_listitemswipeactionstate)   | ArkUI_ListItemSwipeActionState  | Enumerates the item states of [swipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the [Listitem](./arkui-ts/ts-container-listitem.md#listitem10) component.|
| [ArkUI_ListItemSwipeEdgeEffect](#arkui_listitemswipeedgeeffect)     | ArkUI_ListItemSwipeEdgeEffect   | Enumerates the item edge effects of [swipeAction](./arkui-ts/ts-container-listitem.md#swipeaction9) of the [Listitem](./arkui-ts/ts-container-listitem.md#listitem10) component.|
| [ArkUI_ListItemSwipeActionDirection](#arkui_listitemswipeactiondirection) | ArkUI_ListItemSwipeActionDirection | Enumerates the swipe action menu display directions for the **ListItem** component.|
| [ArkUI_SafeAreaType](#arkui_safeareatype)                           | ArkUI_SafeAreaType              | Enumerates the types of expanded safe areas.                    |
| [ArkUI_KeyboardAvoidMode](#arkui_keyboardavoidmode)                 | ArkUI_KeyboardAvoidMode         | Enumerates the soft keyboard avoidance modes.                          |
| [ArkUI_HoverModeAreaType](#arkui_hovermodeareatype)                 | ArkUI_HoverModeAreaType         | Enumerates the types of display areas for the hover mode.                         |
| [ArkUI_ExpandMode](#arkui_expandmode)                               | ArkUI_ExpandMode                | Enumerates the expansion mode of child nodes.                    |
| [ArkUI_FocusWrapMode](#arkui_focuswrapmode)                         | ArkUI_FocusWrapMode             | Enumerates the focus wrap mode of components.                        |
| [ArkUI_ItemFillPolicy](#arkui_itemfillpolicy)                         | ArkUI_ItemFillPolicy             | Enumerates preset column layouts for different responsive breakpoints.                        |
| [ArkUI_EdgeDirection](#arkui_edgedirection)                         | ArkUI_EdgeDirection             | Enumerates rectangle edge directions.                        |
| [ArkUI_CornerDirection](#arkui_cornerdirection)                     | ArkUI_CornerDirection           | Enumerates corner directions.                        |
| [ArkUI_MenuPolicy](#arkui_menupolicy)                               | ArkUI_MenuPolicy                | Enumerates menu display policies.                            |
| [ArkUI_RenderStrategy](#arkui_renderstrategy)                       | ArkUI_RenderStrategy             | Defines rendering strategies for drawing rounded corners.               |
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
| [void OH_ArkUI_CustomProperty_Destroy(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_destroy) | - | Destroys a **CustomProperty** instance.|
| [const char* OH_ArkUI_CustomProperty_GetStringValue(ArkUI_CustomProperty* handle)](#oh_arkui_customproperty_getstringvalue) | - | Obtains the value of a custom property.|
| [const char* OH_ArkUI_HostWindowInfo_GetName(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_getname) | - | Obtains the window name from a **HostWindowInfo** object.|
| [void OH_ArkUI_HostWindowInfo_Destroy(ArkUI_HostWindowInfo* info)](#oh_arkui_hostwindowinfo_destroy) | - | Destroys a **HostWindowInfo** object.|
| [void OH_ArkUI_ActiveChildrenInfo_Destroy(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_destroy) | - | Destroys an **ArkUI_ActiveChildrenInfo** instance and releases the resources allocated when obtaining active child node information.|
| [ArkUI_NodeHandle OH_ArkUI_ActiveChildrenInfo_GetNodeByIndex(ArkUI_ActiveChildrenInfo* handle, int32_t index)](#oh_arkui_activechildreninfo_getnodebyindex) | - | Obtains the child node whose subscript is index in **ArkUI_ActiveChildrenInfo**. This API is applicable to traversing active child nodes by subscript.|
| [int32_t OH_ArkUI_ActiveChildrenInfo_GetCount(ArkUI_ActiveChildrenInfo* handle)](#oh_arkui_activechildreninfo_getcount) | - | Obtains the number of child nodes in **ArkUI_ActiveChildrenInfo**. This API is applicable to determining the number of active child nodes before traversal.|
| [ArkUI_CrossLanguageOption* OH_ArkUI_CrossLanguageOption_Create(void)](#oh_arkui_crosslanguageoption_create) | - | Creates an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_Destroy(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_destroy) | - | Destroys an instance of the cross-language configuration option.|
| [void OH_ArkUI_CrossLanguageOption_SetAttributeSettingStatus(ArkUI_CrossLanguageOption* option, bool enabled)](#oh_arkui_crosslanguageoption_setattributesettingstatus) | - | Sets whether cross-language attribute setting is allowed in the configuration option.|
| [bool OH_ArkUI_CrossLanguageOption_GetAttributeSettingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_getattributesettingstatus) | - | Checks whether cross-language attribute setting is allowed in the configuration option.|
| [void OH_ArkUI_CrossLanguageOption_SetTreeOperatingStatus(ArkUI_CrossLanguageOption* option, OH_ArkUI_CrossLanguageOperatingStatus status)](#oh_arkui_crosslanguageoption_settreeoperatingstatus) | - | Sets the node tree operation state of a cross-language configuration option.|
| [OH_ArkUI_CrossLanguageOperatingStatus OH_ArkUI_CrossLanguageOption_GetTreeOperatingStatus(ArkUI_CrossLanguageOption* option)](#oh_arkui_crosslanguageoption_gettreeoperatingstatus) | - | Obtains the node tree operation state of a cross-language configuration option.|
| [ArkUI_ContentTransitionEffect* OH_ArkUI_ContentTransitionEffect_Create(int32_t type)](#oh_arkui_contenttransitioneffect_create) | - | Creates a **ContentTransitionEffect** attribute object.|
| [ArkUI_SelectionOptions* OH_ArkUI_SelectionOptions_Create()](#oh_arkui_selectionoptions_create) | - | Creates a selection option.|
| [void OH_ArkUI_SelectionOptions_Dispose(ArkUI_SelectionOptions* options)](#oh_arkui_selectionoptions_dispose) | - | Releases a selection option object.|
| [void OH_ArkUI_SelectionOptions_SetMenuPolicy(ArkUI_SelectionOptions* options, ArkUI_MenuPolicy menuPolicy)](#oh_arkui_selectionoptions_setmenupolicy) | - | Sets the menu pop-up policy for selection options.|
| [ArkUI_MenuPolicy OH_ArkUI_SelectionOptions_GetMenuPolicy(ArkUI_SelectionOptions* options)](#oh_arkui_selectionoptions_getmenupolicy) | - | Obtains the menu pop-up policy for selection options.|
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
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnCreateMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextCreateMenuCallback cb)](#oh_arkui_texteditmenuoptions_registeroncreatemenucallback) | - | Registers the callback for creating text menus.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnPrepareMenuCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextPrepareMenuCallback cb)](#oh_arkui_texteditmenuoptions_registeronpreparemenucallback) | - | Registers the callback for preparing text menus.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditMenuOptions_RegisterOnMenuItemClickCallback(ArkUI_TextEditMenuOptions* editMenuOptions, void* userData, ArkUI_TextMenuItemClickCallback cb)](#oh_arkui_texteditmenuoptions_registeronmenuitemclickcallback) | - | Registers the callback for text menu item clicks.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType textSpanType)](#oh_arkui_textselectionmenuoptions_setspantype) | - | Sets the text recognition type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetSpanType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextSpanType* spanType)](#oh_arkui_textselectionmenuoptions_getspantype) | - | Obtains the text recognition type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle node)](#oh_arkui_textselectionmenuoptions_setcontentnode) | - | Sets the content node of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetContentNode(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_NodeHandle* node)](#oh_arkui_textselectionmenuoptions_getcontentnode) | - | Obtains the content node of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_SetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType responseType)](#oh_arkui_textselectionmenuoptions_setresponsetype) | - | Sets the response type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_GetResponseType(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, ArkUI_TextResponseType* responseType)](#oh_arkui_textselectionmenuoptions_getresponsetype) | - | Obtains the response type of a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuShowCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (\*callback)(int32_t start, int32_t end, void* userData))](#oh_arkui_textselectionmenuoptions_registeronmenushowcallback) | - | Registers the callback for the event of showing a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_TextSelectionMenuOptions_RegisterOnMenuHideCallback(ArkUI_TextSelectionMenuOptions* selectionMenuOptions, void* userData, void (\*callback)(int32_t start, int32_t end, void* userData))](#oh_arkui_textselectionmenuoptions_registeronmenuhidecallback) | - | Registers the callback for the event of hiding a custom text selection menu.|
| [ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureBackground(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorBackground* background)](#oh_arkui_pickerindicatorstyle_configurebackground) | - | Sets the background style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_BACKGROUND](capi-picker-h.md#arkui_pickerindicatortype).|
| [ArkUI_ErrorCode OH_ArkUI_PickerIndicatorStyle_ConfigureDivider(ArkUI_PickerIndicatorStyle* style, ArkUI_PickerIndicatorDivider* divider)](#oh_arkui_pickerindicatorstyle_configuredivider) | - | Sets the divider style. This API takes effect only when the type of the selected item indicator is [ARKUI_PICKER_INDICATOR_DIVIDER](capi-picker-h.md#arkui_pickerindicatortype).|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType type)](#oh_arkui_decorationstyleoptions_settextdecorationtype) | - | Sets the decoration type of the decorative line style.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationType(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationType* type)](#oh_arkui_decorationstyleoptions_gettextdecorationtype) | - | Obtains the decoration type of the decorative line style.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t color)](#oh_arkui_decorationstyleoptions_setcolor) | - | Sets the color of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetColor(OH_ArkUI_DecorationStyleOptions* options, uint32_t* color)](#oh_arkui_decorationstyleoptions_getcolor) | - | Obtains the color of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle style)](#oh_arkui_decorationstyleoptions_settextdecorationstyle) | - | Sets the style of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetTextDecorationStyle(OH_ArkUI_DecorationStyleOptions* options, ArkUI_TextDecorationStyle* style)](#oh_arkui_decorationstyleoptions_gettextdecorationstyle) | - | Obtains the style of the decorative line.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_SetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float thicknessScale)](#oh_arkui_decorationstyleoptions_setthicknessscale) | - | Sets the scale factor of the decorative line thickness.|
| [ArkUI_ErrorCode OH_ArkUI_DecorationStyleOptions_GetThicknessScale(OH_ArkUI_DecorationStyleOptions* options, float* thicknessScale)](#oh_arkui_decorationstyleoptions_getthicknessscale) | - | Obtains the scale factor of the decorative line thickness.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetTypes(OH_ArkUI_TextDataDetectorConfig* config, const ArkUI_TextDataDetectorType* types, int32_t length)](#oh_arkui_textdatadetectorconfig_settypes) | - | Sets the types of the text entity recognition configuration.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetTypes(OH_ArkUI_TextDataDetectorConfig* config, ArkUI_TextDataDetectorType* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_textdatadetectorconfig_gettypes) | - | Obtains the types of the text entity recognition configuration.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback(OH_ArkUI_TextDataDetectorConfig* config, void* userData, void (\*callback)(const char* result, int32_t length, void* userData))](#oh_arkui_textdatadetectorconfig_registerondetectresultupdatecallback) | - | Sets the callback for text entity recognition result updates.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t color)](#oh_arkui_textdatadetectorconfig_setcolor) | - | Sets the color of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetColor(OH_ArkUI_TextDataDetectorConfig* config, uint32_t* color)](#oh_arkui_textdatadetectorconfig_getcolor) | - | Obtains the color of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)](#oh_arkui_textdatadetectorconfig_setdecorationstyleoptions) | - | Sets the decoration style of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetDecorationStyleOptions(OH_ArkUI_TextDataDetectorConfig* config, OH_ArkUI_DecorationStyleOptions* decoration)](#oh_arkui_textdatadetectorconfig_getdecorationstyleoptions) | - | Obtains the decoration style of the recognized content.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_SetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool enablePreviewMenu)](#oh_arkui_textdatadetectorconfig_setenablepreviewmenu) | - | Sets whether to display the preview menu when the recognized content is long-pressed.|
| [ArkUI_ErrorCode OH_ArkUI_TextDataDetectorConfig_GetEnablePreviewMenu(OH_ArkUI_TextDataDetectorConfig* config, bool* enablePreviewMenu)](#oh_arkui_textdatadetectorconfig_getenablepreviewmenu) | - | Obtains whether the preview menu is displayed when the recognized content is long-pressed.|
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
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t caretOffset)](#oh_arkui_texteditorstyledstringcontroller_setcaretoffset) | - | Sets the caret offset using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretOffset(OH_ArkUI_TextEditorStyledStringController* controller, int32_t* caretOffset)](#oh_arkui_texteditorstyledstringcontroller_getcaretoffset) | - | Obtains the caret offset using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_SetSelection(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t start, uint32_t end, ArkUI_MenuPolicy menuPolicy)](#oh_arkui_texteditorstyledstringcontroller_setselection) | - | Sets the selected area using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_IsEditing(OH_ArkUI_TextEditorStyledStringController* controller, bool* isEditing)](#oh_arkui_texteditorstyledstringcontroller_isediting) | - | Obtains the editing status of the text editor using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_StopEditing(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_stopediting) | - | Exits the editing status of the text editor using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetPreviewText(OH_ArkUI_TextEditorStyledStringController* controller, uint32_t* offset, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_arkui_texteditorstyledstringcontroller_getpreviewtext) | - | Obtains the preview text using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_GetCaretRect(OH_ArkUI_TextEditorStyledStringController* controller, ArkUI_Rect* rect)](#oh_arkui_texteditorstyledstringcontroller_getcaretrect) | - | Obtains the caret-selected rectangle using the styled string controller.|
| [ArkUI_ErrorCode OH_ArkUI_TextEditorStyledStringController_DeleteBackward(OH_ArkUI_TextEditorStyledStringController* controller)](#oh_arkui_texteditorstyledstringcontroller_deletebackward) | - | Deletes characters using the styled string controller. If no content is selected, one character before the current caret position is deleted. If content is selected, the selected content is deleted.|
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

Creates layout constraints. After the created layout constraint pointer is used, call [OH_ArkUI_LayoutConstraint_Dispose](#oh_arkui_layoutconstraint_dispose) to release it. If the pointer is not released, memory leakage may occur.

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

Performs a deep copy of a layout constraint. The new layout constraint pointer returned by the deep copy is independent of the original pointer. You need to call [OH_ArkUI_LayoutConstraint_Dispose](#oh_arkui_layoutconstraint_dispose) to release them separately after use.

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

Disposes of a layout constraint pointer. This API must be used together with [OH_ArkUI_LayoutConstraint_Create](#oh_arkui_layoutconstraint_create) or [OH_ArkUI_LayoutConstraint_Copy](#oh_arkui_layoutconstraint_copy). Each layout constraint pointer can be destroyed only once. After being destroyed, the pointer should not be used anymore.

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
| [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight) fontWeight | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight).|

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
| [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight) | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight).|

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
| [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight) selectedFontWeight | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight).|

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
| [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight) | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight).|

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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|
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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|
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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|
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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|

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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|
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
| [ArkUI_ListItemSwipeActionOption](capi-arkui-nativemodule-arkui-listitemswipeactionoption.md)* option | Pointer to the **ListItemSwipeActionOption** instance.|
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
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_PARAM_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the passed node object type is incorrect.<br>         Returns [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the passed node is not mounted to the component tree.|

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
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_PARAM_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the passed node object type is incorrect.<br>         Returns [ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the passed node is not mounted to the component tree.|

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


Destroys the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance and releases the resources allocated when obtaining information about active child nodes.

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


Obtains the child node whose subscript is index in the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) struct. This API is applicable to traversing active child nodes by subscript.

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


Obtains the number of child nodes in the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) struct. This API is applicable to determining the number of child nodes before traversing active child nodes.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md)* handle | Pointer to the [ArkUI_ActiveChildrenInfo](capi-arkui-nativemodule-arkui-activechildreninfo.md) instance from which the information is to be obtained.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Number of child nodes. The default value is **0**.|

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

### OH_ArkUI_SelectionOptions_Create()

```c
ArkUI_SelectionOptions* OH_ArkUI_SelectionOptions_Create()
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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| int32_t* writeLength | Pointer to the length of the data actually written to the buffer if [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.<br> Pointer to the minimum length required for writing the entire string to the buffer if [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the buffer size is insufficient.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextCreateMenuCallback](capi-text-common-h.md#arkui_textcreatemenucallback) cb | Callback for creating text menus.|

**Returns**

| Type| Description|
| ---- | --- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextPrepareMenuCallback](capi-text-common-h.md#arkui_textpreparemenucallback) cb | Callback for preparing text menus.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextMenuItemClickCallback](capi-text-common-h.md#arkui_textmenuitemclickcallback) cb | Callback for text menu item clicks.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextSpanType](capi-text-common-h.md#arkui_textspantype) textSpanType | Recognition type of a custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextSpanType](capi-text-common-h.md#arkui_textspantype)* spanType | Pointer to the recognition type of a custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextResponseType](capi-text-common-h.md#arkui_textresponsetype) responseType | Response type of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextResponseType](capi-text-common-h.md#arkui_textresponsetype)* responseType | Pointer to the response type of the custom text selection menu.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| uint32_t | Background color of the preview style shown when dragging selected text, in RGBA format.|

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
| [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype) type | Decoration type, specified using [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype)* type | Pointer to the decoration type, specified using [ArkUI_TextDecorationType](capi-text-common-h.md#arkui_textdecorationtype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle) style | Decorative line style, specified using [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle)* style | Pointer to the decorative line style, specified using [ArkUI_TextDecorationStyle](capi-text-common-h.md#arkui_textdecorationstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [const ArkUI_TextDataDetectorType](capi-text-h.md#arkui_textdatadetectortype)* types | Type of the text entity recognition configuration. The value is an enumerated value of [ArkUI_TextDataDetectorType](capi-text-h.md#arkui_textdatadetectortype).|
| int32_t length | Type quantity.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDataDetectorType](capi-text-h.md#arkui_textdatadetectortype)* buffer | Pointer to the buffer of the type array.|
| int32_t bufferSize | Maximum number of types that can be written to the buffer reserved for the types.|
| int32_t* writeLength | Pointer to the number of types that are actually written to the buffer.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

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
| void (\*callback)(const char* result, int32_t length, void* userData) | Pointer to the callback when the recognition result is updated. **result** indicates the recognized text entity content. **length** indicates the end position of the selected text. **userData** indicates the user-defined data, which corresponds to the input parameter **userData** of the **OH_ArkUI_TextDataDetectorConfig_RegisterOnDetectResultUpdateCallback** API.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* decoration | Pointer to the decoration style of the recognized content.|


**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_DecorationStyleOptions](capi-arkui-nativemodule-oh-arkui-decorationstyleoptions.md)* decoration | Pointer to the decoration style of the recognized content.|


**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| uint32_t fontWeight | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_W400**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| uint32_t* fontWeight | Pointer to the font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_W400**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the value of **bufferSize** is less than that of **writeLength**.|

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
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle) fontStyle | Font style. The value is an enumerated value of [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)* fontStyle | Pointer to the font style. The value is an enumerated value of [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment) align | Text alignment mode. The value is an enumerated value of [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment)* align | Pointer to the text alignment mode. The value is an enumerated value of [ArkUI_TextAlignment](capi-text-common-h.md#arkui_textalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak) wordBreak | Word breaking mode. The value is an enumerated value of [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak)* wordBreak | Pointer to the word breaking mode. The value is an enumerated value of [ArkUI_WordBreak](capi-text-common-h.md#arkui_wordbreak).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_LineBreakStrategy](capi-text-common-h.md#oh_arkui_linebreakstrategy) lineBreakStrategy | Line breaking strategy. The value is an enumerated value of [OH_ArkUI_LineBreakStrategy](capi-text-common-h.md#oh_arkui_linebreakstrategy).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_LineBreakStrategy](capi-text-common-h.md#oh_arkui_linebreakstrategy)* lineBreakStrategy | Pointer to the line breaking strategy. The value is an enumerated value of [OH_ArkUI_LineBreakStrategy](capi-text-common-h.md#oh_arkui_linebreakstrategy).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment) verticalAlignment | Text vertical alignment mode. The value is an enumerated value of [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment)* verticalAlignment | Pointer to the text vertical alignment mode. The value is an enumerated value of [ArkUI_TextVerticalAlignment](capi-text-common-h.md#arkui_textverticalalignment).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection) textDirection | Text direction. The value is an enumerated value of [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection)* textDirection | Pointer to the text direction. The value is an enumerated value of [ArkUI_TextDirection](capi-text-common-h.md#arkui_textdirection).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle) fontStyle | Font style. The value is an enumerated value of [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle)* fontStyle | Pointer to the font style. The value is an enumerated value of [ArkUI_FontStyle](capi-text-h.md#arkui_fontstyle).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| uint32_t fontWeight | Font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_W400**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| uint32_t* fontWeight | Pointer to the font weight. The value is an enumerated value of [ArkUI_FontWeight](capi-text-h.md#arkui_fontweight). The default value is **ARKUI_FONT_WEIGHT_W400**.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextEditorSpanType](capi-rich-editor-h.md#oh_arkui_texteditorspantype) textEditorSpanType | Span type. The value is an enumerated value of [OH_ArkUI_TextEditorSpanType](capi-rich-editor-h.md#oh_arkui_texteditorspantype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextEditorSpanType](capi-rich-editor-h.md#oh_arkui_texteditorspantype)* textEditorSpanType | Pointer to the span type. The value is an enumerated value of [OH_ArkUI_TextEditorSpanType](capi-rich-editor-h.md#oh_arkui_texteditorspantype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextEditorResponseType](capi-rich-editor-h.md#oh_arkui_texteditorresponsetype) responseType | Response type. The value is an enumerated value of [OH_ArkUI_TextEditorResponseType](capi-rich-editor-h.md#oh_arkui_texteditorresponsetype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextEditorResponseType](capi-rich-editor-h.md#oh_arkui_texteditorresponsetype)* responseType | Pointer to the response type. The value is an enumerated value of [OH_ArkUI_TextEditorResponseType](capi-rich-editor-h.md#oh_arkui_texteditorresponsetype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextMenuType](capi-rich-editor-h.md#oh_arkui_textmenutype) menuType | Menu type. The value is an enumerated value of [OH_ArkUI_TextMenuType](capi-rich-editor-h.md#oh_arkui_textmenutype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_TextMenuType](capi-rich-editor-h.md#oh_arkui_textmenutype)* menuType | Pointer to the menu type. The value is an enumerated value of [OH_ArkUI_TextMenuType](capi-rich-editor-h.md#oh_arkui_textmenutype).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| void (\*callback)(int32_t start, int32_t end, void* callbackUserData) | Pointer to the callback when the menu is displayed. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| void (\*callback)(int32_t start, int32_t end, void* callbackUserData) | Pointer to the callback when the menu is hidden. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| void (\*callback)(int32_t start, int32_t end, void* callbackUserData) | Pointer to the callback when the menu appears. **start** indicates the start offset of the selected content. **end** indicates the end offset of the selected content. **callbackUserData** indicates the user data.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_HapticFeedbackMode](capi-rich-editor-h.md#oh_arkui_hapticfeedbackmode) mode | Haptic feedback mode. The value is an enumerated value of [OH_ArkUI_HapticFeedbackMode](capi-rich-editor-h.md#oh_arkui_hapticfeedbackmode).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [OH_ArkUI_HapticFeedbackMode](capi-rich-editor-h.md#oh_arkui_hapticfeedbackmode)* mode | Pointer to the haptic feedback mode. The value is an enumerated value of [OH_ArkUI_HapticFeedbackMode](capi-rich-editor-h.md#oh_arkui_hapticfeedbackmode).|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|
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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Return result.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br>Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_LinearGradientOptions_SetDirection()

```c
ArkUI_ErrorCode OH_ArkUI_LinearGradientOptions_SetDirection(OH_ArkUI_LinearGradientOptions* options, ArkUI_LinearGradientDirection direction)
```

**Description**

Sets the direction in linear gradient effect options.

> **NOTE**
>
> When [OH_ArkUI_LinearGradientOptions_SetAngle](#oh_arkui_lineargradientoptions_setangle) is called to set the angle, the direction setting does not take effect.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md)* options | Pointer to the [OH_ArkUI_LinearGradientOptions](capi-arkui-nativemodule-oh-arkui-lineargradientoptions.md) object.|
| [ArkUI_LinearGradientDirection](capi-native-type-visual-h.md#arkui_lineargradientdirection) direction | Direction in linear gradient effect options.|

**Returns**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|

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
| [ArkUI_ErrorCode](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) | Result code.<br> Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if the operation is successful.<br> Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-arkui-nativemodule-arkui-error-code-h.md#arkui_errorcode) if a parameter error occurs.|
