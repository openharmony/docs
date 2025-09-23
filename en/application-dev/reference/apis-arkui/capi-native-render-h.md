# native_render.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @xiang-shouxing-->
<!--Designer: @xiang-shouxing-->
<!--Tester: @sally__-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the APIs of **NativeRender**.

**File to include**: <arkui/native_render.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 20

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Structs

| Name                                                                                           | typedef Keyword                      | Description               |
|-----------------------------------------------------------------------------------------------|----------------------------------|-------------------|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)               | ArkUI_RenderNodeHandle         | Defines a struct for the render node pointer.        |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md)               | ArkUI_RenderContentModifierHandle                                | Defines a struct for the content modifier pointer.      |
| [ArkUI_FloatPropertyHandle](./capi-arkui-nativemodule-arkui-floatpropertyhandle.md)               | ArkUI_FloatPropertyHandle                                | Defines a struct for the float property pointer.      |
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md)               | ArkUI_Vector2PropertyHandle                                | Defines a struct for the 2D vector property pointer.      |
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md)               | ArkUI_ColorPropertyHandle                                | Defines a struct for the color property pointer.      |
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md)               | ArkUI_FloatAnimatablePropertyHandle                                | Defines a struct for the animatable float property pointer.      |
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md)               | ArkUI_Vector2AnimatablePropertyHandle                                | Defines a struct for the animatable 2D vector property pointer.      |
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md)               | ArkUI_ColorAnimatablePropertyHandle                                | Defines a struct for the animatable color property pointer.      |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)               | ArkUI_RectShapeOption                                | Defines a struct for the rectangle shape configuration.      |
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)               | ArkUI_NodeBorderStyleOption                                | Defines a struct for the node border style configuration.      |
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)               | ArkUI_NodeBorderWidthOption                                | Defines a struct for the node border width configuration.      |
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)               | ArkUI_NodeBorderColorOption                                | Defines a struct for the node border color configuration.      |
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)               | ArkUI_NodeBorderRadiusOption                                | Defines a struct for the node border radius configuration.      |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)               | ArkUI_CircleShapeOption                                | Defines a struct for the circle shape configuration.      |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)               | ArkUI_RoundRectShapeOption                                | Defines a struct for the rounded rectangle shape configuration.      |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md)               | ArkUI_CommandPathOption                                | Defines a struct for the custom path configuration.      |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md)               | ArkUI_RenderNodeMaskOption                                | Defines a struct for the render node mask configuration.      |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)               | ArkUI_RenderNodeClipOption                                | Defines a struct for the render node clip configuration.      |

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [int32_t OH_ArkUI_RenderNodeUtils_AddRenderNode(ArkUI_NodeHandle node, ArkUI_RenderNodeHandle child)](#oh_arkui_rendernodeutils_addrendernode) | - | Adds a child render node to the parent custom node.|
| [int32_t OH_ArkUI_RenderNodeUtils_RemoveRenderNode(ArkUI_NodeHandle node, ArkUI_RenderNodeHandle child)](#oh_arkui_rendernodeutils_removerendernode) | - | Removes all child render nodes from the specified node.|
| [int32_t OH_ArkUI_RenderNodeUtils_ClearRenderNodeChildren(ArkUI_NodeHandle node)](#oh_arkui_rendernodeutils_clearrendernodechildren) | - | Clears child render nodes in the parent node.|
| [int32_t OH_ArkUI_RenderNodeUtils_Invalidate(ArkUI_NodeHandle node)](#oh_arkui_rendernodeutils_invalidate) | - | Marks the target custom node as dirty, causing its child render nodes to re-render.|
| [ArkUI_RenderNodeHandle OH_ArkUI_RenderNodeUtils_CreateNode()](#oh_arkui_rendernodeutils_createnode) | - | Creates a render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_DisposeNode(ArkUI_RenderNodeHandle node)](#oh_arkui_rendernodeutils_disposenode) | - | Destroys the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_AddChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child)](#oh_arkui_rendernodeutils_addchild) | - | Adds a child node to the target parent render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_InsertChildAfter(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child, ArkUI_RenderNodeHandle sibling)](#oh_arkui_rendernodeutils_insertchildafter) | - | Adds a child node after the target child node of the parent node.|
| [int32_t OH_ArkUI_RenderNodeUtils_RemoveChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child)](#oh_arkui_rendernodeutils_removechild) | - | Removes a child node from the specified render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_ClearChildren(ArkUI_RenderNodeHandle node)](#oh_arkui_rendernodeutils_clearchildren) | - | Clears all child nodes of the specified render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetChild(ArkUI_RenderNodeHandle node, int32_t index, ArkUI_RenderNodeHandle* child)](#oh_arkui_rendernodeutils_getchild) | - | Obtains the child node at the specified index.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetFirstChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* child)](#oh_arkui_rendernodeutils_getfirstchild) | - | Obtains the first child node of the specified render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetNextSibling(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* sibling)](#oh_arkui_rendernodeutils_getnextsibling) | - | Obtains the next sibling node of the specified node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetPreviousSibling(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* sibling)](#oh_arkui_rendernodeutils_getprevioussibling) | - | Obtains the previous sibling node of the specified node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetChildren(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle** children, int32_t* count)](#oh_arkui_rendernodeutils_getchildren) | - | Obtains all child render nodes of the parent render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetChildrenCount(ArkUI_RenderNodeHandle node, int32_t* count)](#oh_arkui_rendernodeutils_getchildrencount) | - | Obtains the number of child render nodes of the specified render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBackgroundColor(ArkUI_RenderNodeHandle node, uint32_t color)](#oh_arkui_rendernodeutils_setbackgroundcolor) | - | Sets the background color for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBackgroundColor(ArkUI_RenderNodeHandle node, uint32_t* color)](#oh_arkui_rendernodeutils_getbackgroundcolor) | - | Obtains the background color of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetClipToFrame(ArkUI_RenderNodeHandle node, int32_t clipToFrame)](#oh_arkui_rendernodeutils_setcliptoframe) | - | Sets whether to clip the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetClipToFrame(ArkUI_RenderNodeHandle node, int32_t* clipToFrame)](#oh_arkui_rendernodeutils_getcliptoframe) | - | Obtains whether the render node is clipped.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetClipToBounds(ArkUI_RenderNodeHandle node, int32_t clipToBounds)](#oh_arkui_rendernodeutils_setcliptobounds) | - | Sets whether to clip to the bounds of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetClipToBounds(ArkUI_RenderNodeHandle node, int32_t* clipToBounds)](#oh_arkui_rendernodeutils_getcliptobounds) | - | Sets whether clipping to the bounds of the render node is enabled.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetOpacity(ArkUI_RenderNodeHandle node, float opacity)](#oh_arkui_rendernodeutils_setopacity) | - | Sets the opacity value for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetOpacity(ArkUI_RenderNodeHandle node, float* opacity)](#oh_arkui_rendernodeutils_getopacity) | - | Obtains the opacity value of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetSize(ArkUI_RenderNodeHandle node, int32_t width, int32_t height)](#oh_arkui_rendernodeutils_setsize) | - | Sets the size for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetSize(ArkUI_RenderNodeHandle node, int32_t* width, int32_t* height)](#oh_arkui_rendernodeutils_getsize) | - | Obtains the size of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetPosition(ArkUI_RenderNodeHandle node, int32_t x, int32_t y)](#oh_arkui_rendernodeutils_setposition) | - | Sets the position coordinates for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetPosition(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y)](#oh_arkui_rendernodeutils_getposition) | - | Obtains the position coordinates of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetPivot(ArkUI_RenderNodeHandle node, float x, float y)](#oh_arkui_rendernodeutils_setpivot) | - | Sets the pivot point for the transformation of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetPivot(ArkUI_RenderNodeHandle node, float* x, float* y)](#oh_arkui_rendernodeutils_getpivot) | - | Obtains the pivot point coordinates of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetScale(ArkUI_RenderNodeHandle node, float x, float y)](#oh_arkui_rendernodeutils_setscale) | - | Sets the scale factors for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetScale(ArkUI_RenderNodeHandle node, float* x, float* y)](#oh_arkui_rendernodeutils_getscale) | - | Obtains the scale factors of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetTranslation(ArkUI_RenderNodeHandle node, float x, float y)](#oh_arkui_rendernodeutils_settranslation) | - | Sets the translation offset for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetTranslation(ArkUI_RenderNodeHandle node, float* x, float* y)](#oh_arkui_rendernodeutils_gettranslation) | - | Obtains the translation offset of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetRotation(ArkUI_RenderNodeHandle node, float x, float y, float z)](#oh_arkui_rendernodeutils_setrotation) | - | Sets the rotation angles for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetRotation(ArkUI_RenderNodeHandle node, float* x, float* y, float* z)](#oh_arkui_rendernodeutils_getrotation) | - | Obtains the rotation angles of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetTransform(ArkUI_RenderNodeHandle node, float* matrix)](#oh_arkui_rendernodeutils_settransform) | - | Sets the transformation matrix for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetShadowColor(ArkUI_RenderNodeHandle node, uint32_t color)](#oh_arkui_rendernodeutils_setshadowcolor) | - | Sets the shadow color for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetShadowColor(ArkUI_RenderNodeHandle node, uint32_t* color)](#oh_arkui_rendernodeutils_getshadowcolor) | - | Obtains the shadow color of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetShadowOffset(ArkUI_RenderNodeHandle node, int32_t x, int32_t y)](#oh_arkui_rendernodeutils_setshadowoffset) | - | Sets the shadow offset for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetShadowOffset(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y)](#oh_arkui_rendernodeutils_getshadowoffset) | - | Obtains the shadow offset of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetShadowAlpha(ArkUI_RenderNodeHandle node, float alpha)](#oh_arkui_rendernodeutils_setshadowalpha) | - | Sets the shadow alpha (transparency) for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetShadowAlpha(ArkUI_RenderNodeHandle node, float* alpha)](#oh_arkui_rendernodeutils_getshadowalpha) | - | Obtains the shadow alpha (transparency) of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetShadowElevation(ArkUI_RenderNodeHandle node, float elevation)](#oh_arkui_rendernodeutils_setshadowelevation) | - | Sets the shadow elevation for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetShadowElevation(ArkUI_RenderNodeHandle node, float* elevation)](#oh_arkui_rendernodeutils_getshadowelevation) | - | Obtains the shadow elevation of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetShadowRadius(ArkUI_RenderNodeHandle node, float radius)](#oh_arkui_rendernodeutils_setshadowradius) | - | Sets the shadow radius for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetShadowRadius(ArkUI_RenderNodeHandle node, float* radius)](#oh_arkui_rendernodeutils_getshadowradius) | - | Obtains the shadow radius of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBorderStyle(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderStyleOption* borderStyle)](#oh_arkui_rendernodeutils_setborderstyle) | - | Sets the border style for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBorderStyle(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderStyleOption** borderStyle)](#oh_arkui_rendernodeutils_getborderstyle) | - | Obtains the border style of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBorderWidth(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderWidthOption* borderWidth)](#oh_arkui_rendernodeutils_setborderwidth) | - | Sets the border width for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBorderWidth(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderWidthOption** borderWidth)](#oh_arkui_rendernodeutils_getborderwidth) | - | Obtains the border width of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBorderColor(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderColorOption* borderColor)](#oh_arkui_rendernodeutils_setbordercolor) | - | Sets the border color for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBorderColor(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderColorOption** borderColor)](#oh_arkui_rendernodeutils_getbordercolor) | - | Obtains the border color of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBorderRadius(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderRadiusOption* borderRadius)](#oh_arkui_rendernodeutils_setborderradius) | - | Sets the border corner radius for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBorderRadius(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderRadiusOption** borderRadius)](#oh_arkui_rendernodeutils_getborderradius) | - | Obtains the border corner radius of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetMask(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeMaskOption* option)](#oh_arkui_rendernodeutils_setmask) | - | Applies a mask to the render node using the mask configuration.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetClip(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeClipOption* option)](#oh_arkui_rendernodeutils_setclip) | - | Applies clipping to the render node using the clipping configuration.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetMarkNodeGroup(ArkUI_RenderNodeHandle node, bool markNodeGroup)](#oh_arkui_rendernodeutils_setmarknodegroup) | - | Marks whether to prioritize drawing the node and its child nodes.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetBounds(ArkUI_RenderNodeHandle node, int32_t x, int32_t y, int32_t width, int32_t height)](#oh_arkui_rendernodeutils_setbounds) | - | Sets the bounds for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetBounds(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y, int32_t* width, int32_t* height)](#oh_arkui_rendernodeutils_getbounds) | - | Obtains the bounds of the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetDrawRegion(ArkUI_RenderNodeHandle node, float x, float y, float w, float h)](#oh_arkui_rendernodeutils_setdrawregion) | - | Sets the drawing region for the render node.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachContentModifier(ArkUI_RenderNodeHandle node, ArkUI_RenderContentModifierHandle modifier)](#oh_arkui_rendernodeutils_attachcontentmodifier) | - | Attaches a content modifier to the render node.|
| [ArkUI_RenderContentModifierHandle OH_ArkUI_RenderNodeUtils_CreateContentModifier()](#oh_arkui_rendernodeutils_createcontentmodifier) | - | Creates a content modifier.|
| [void OH_ArkUI_RenderNodeUtils_DisposeContentModifier(ArkUI_RenderContentModifierHandle modifier)](#oh_arkui_rendernodeutils_disposecontentmodifier) | - | Disposes the content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachFloatProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_FloatPropertyHandle property)](#oh_arkui_rendernodeutils_attachfloatproperty) | - | Attaches a float property to the target content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachVector2Property(ArkUI_RenderContentModifierHandle modifier, ArkUI_Vector2PropertyHandle property)](#oh_arkui_rendernodeutils_attachvector2property) | - | Attaches a 2D vector property to the target content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachColorProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_ColorPropertyHandle property)](#oh_arkui_rendernodeutils_attachcolorproperty) | - | Attaches a color property to the target content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_FloatAnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_attachfloatanimatableproperty) | - | Attaches an animatable float property to the target content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachVector2AnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_Vector2AnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_attachvector2animatableproperty) | - | Attaches an animatable 2D vector property to the target content modifier.|
| [int32_t OH_ArkUI_RenderNodeUtils_AttachColorAnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_ColorAnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_attachcoloranimatableproperty) | - | Attaches an animatable color property to the target content modifier.|
| [ArkUI_FloatPropertyHandle OH_ArkUI_RenderNodeUtils_CreateFloatProperty(float value)](#oh_arkui_rendernodeutils_createfloatproperty) | - | Creates a float property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetFloatPropertyValue(ArkUI_FloatPropertyHandle property, float value)](#oh_arkui_rendernodeutils_setfloatpropertyvalue) | - | Sets the value of the float property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetFloatPropertyValue(ArkUI_FloatPropertyHandle property, float* value)](#oh_arkui_rendernodeutils_getfloatpropertyvalue) | - | Obtains the value of the float property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeFloatProperty(ArkUI_FloatPropertyHandle property)](#oh_arkui_rendernodeutils_disposefloatproperty) | - | Disposes the float property.|
| [ArkUI_Vector2PropertyHandle OH_ArkUI_RenderNodeUtils_CreateVector2Property(float x, float y)](#oh_arkui_rendernodeutils_createvector2property) | - | Creates a 2D vector property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetVector2PropertyValue(ArkUI_Vector2PropertyHandle property, float x, float y)](#oh_arkui_rendernodeutils_setvector2propertyvalue) | - | Sets the value of the 2D vector property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetVector2PropertyValue(ArkUI_Vector2PropertyHandle property, float* x, float* y)](#oh_arkui_rendernodeutils_getvector2propertyvalue) | - | Obtains the value of the 2D vector property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeVector2Property(ArkUI_Vector2PropertyHandle property)](#oh_arkui_rendernodeutils_disposevector2property) | - | Disposes the 2D vector property.|
| [ArkUI_ColorPropertyHandle OH_ArkUI_RenderNodeUtils_CreateColorProperty(uint32_t value)](#oh_arkui_rendernodeutils_createcolorproperty) | - | Creates a color property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetColorPropertyValue(ArkUI_ColorPropertyHandle property, uint32_t value)](#oh_arkui_rendernodeutils_setcolorpropertyvalue) | - | Sets the value of the color property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetColorPropertyValue(ArkUI_ColorPropertyHandle property, uint32_t* value)](#oh_arkui_rendernodeutils_getcolorpropertyvalue) | - | Obtains the value of the color property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeColorProperty(ArkUI_ColorPropertyHandle property)](#oh_arkui_rendernodeutils_disposecolorproperty) | - | Disposes the color property.|
| [ArkUI_FloatAnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(float value)](#oh_arkui_rendernodeutils_createfloatanimatableproperty) | - | Creates an animatable float property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(ArkUI_FloatAnimatablePropertyHandle property, float value)](#oh_arkui_rendernodeutils_setfloatanimatablepropertyvalue) | - | Sets the value of the animatable float property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetFloatAnimatablePropertyValue(ArkUI_FloatAnimatablePropertyHandle property, float* value)](#oh_arkui_rendernodeutils_getfloatanimatablepropertyvalue) | - | Obtains the value of the animatable float property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeFloatAnimatableProperty(ArkUI_FloatAnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_disposefloatanimatableproperty) | - | Disposes the animatable float property.|
| [ArkUI_Vector2AnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateVector2AnimatableProperty(float x, float y)](#oh_arkui_rendernodeutils_createvector2animatableproperty) | - | Creates an animatable 2D vector property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetVector2AnimatablePropertyValue(ArkUI_Vector2AnimatablePropertyHandle property, float x, float y)](#oh_arkui_rendernodeutils_setvector2animatablepropertyvalue) | - | Sets the value of the animatable 2D vector property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetVector2AnimatablePropertyValue(ArkUI_Vector2AnimatablePropertyHandle property, float* x, float* y)](#oh_arkui_rendernodeutils_getvector2animatablepropertyvalue) | - | Obtains the value of the animatable 2D vector property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeVector2AnimatableProperty(ArkUI_Vector2AnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_disposevector2animatableproperty) | - | Disposes the animatable 2D vector property.|
| [ArkUI_ColorAnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateColorAnimatableProperty(uint32_t value)](#oh_arkui_rendernodeutils_createcoloranimatableproperty) | - | Creates an animatable color property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetColorAnimatablePropertyValue(ArkUI_ColorAnimatablePropertyHandle property, uint32_t value)](#oh_arkui_rendernodeutils_setcoloranimatablepropertyvalue) | - | Sets the value of the animatable color property.|
| [int32_t OH_ArkUI_RenderNodeUtils_GetColorAnimatablePropertyValue(ArkUI_ColorAnimatablePropertyHandle property, uint32_t* value)](#oh_arkui_rendernodeutils_getcoloranimatablepropertyvalue) | - | Obtains the value of the animatable color property.|
| [void OH_ArkUI_RenderNodeUtils_DisposeColorAnimatableProperty(ArkUI_ColorAnimatablePropertyHandle property)](#oh_arkui_rendernodeutils_disposecoloranimatableproperty) | - | Disposes the animatable color property.|
| [int32_t OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw(ArkUI_RenderContentModifierHandle modifier, void* userData, void (callback)(ArkUI_DrawContext context, void* userData))](#oh_arkui_rendernodeutils_setcontentmodifierondraw) | - | Sets the **onDraw** callback function for the content modifier.|
| [ArkUI_RectShapeOption* OH_ArkUI_RenderNodeUtils_CreateRectShapeOption()](#oh_arkui_rendernodeutils_createrectshapeoption) | - | Creates a rectangle shape option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeRectShapeOption(ArkUI_RectShapeOption* option)](#oh_arkui_rendernodeutils_disposerectshapeoption) | - | Disposes the rectangle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetRectShapeOptionEdgeValue(ArkUI_RectShapeOption* option, float top, float right, float bottom, float left)](#oh_arkui_rendernodeutils_setrectshapeoptionedgevalue) | - | Sets the edge values of the rectangle shape option.|
| [ArkUI_NodeBorderStyleOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderStyleOption()](#oh_arkui_rendernodeutils_createnodeborderstyleoption) | - | Creates a node border style option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderStyleOption(ArkUI_NodeBorderStyleOption* option)](#oh_arkui_rendernodeutils_disposenodeborderstyleoption) | - | Disposes the node border style option.|
| [void OH_ArkUI_RenderNodeUtils_SetNodeBorderStyleOptionEdgeStyle(ArkUI_NodeBorderStyleOption* option, ArkUI_BorderStyle edgeStyle, ArkUI_EdgeDirection direction)](#oh_arkui_rendernodeutils_setnodeborderstyleoptionedgestyle) | - | Sets the edge style for the node border style option.|
| [ArkUI_NodeBorderWidthOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderWidthOption()](#oh_arkui_rendernodeutils_createnodeborderwidthoption) | - | Creates a node border width option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderWidthOption(ArkUI_NodeBorderWidthOption* option)](#oh_arkui_rendernodeutils_disposenodeborderwidthoption) | - | Disposes the node border width option.|
| [void OH_ArkUI_RenderNodeUtils_SetNodeBorderWidthOptionEdgeWidth(ArkUI_NodeBorderWidthOption* option, float edgeWidth, ArkUI_EdgeDirection direction)](#oh_arkui_rendernodeutils_setnodeborderwidthoptionedgewidth) | - | Sets the edge width for the node border width option.|
| [ArkUI_NodeBorderColorOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderColorOption()](#oh_arkui_rendernodeutils_createnodebordercoloroption) | - | Creates a node border color option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderColorOption(ArkUI_NodeBorderColorOption* option)](#oh_arkui_rendernodeutils_disposenodebordercoloroption) | - | Disposes the node border color option.|
| [void OH_ArkUI_RenderNodeUtils_SetNodeBorderColorOptionEdgeColor(ArkUI_NodeBorderColorOption* option, uint32_t edgeColor, ArkUI_EdgeDirection direction)](#oh_arkui_rendernodeutils_setnodebordercoloroptionedgecolor) | - | Sets the edge color for the node border color option.|
| [ArkUI_NodeBorderRadiusOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderRadiusOption()](#oh_arkui_rendernodeutils_createnodeborderradiusoption) | - | Creates a node border radius option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderRadiusOption(ArkUI_NodeBorderRadiusOption* option)](#oh_arkui_rendernodeutils_disposenodeborderradiusoption) | - | Disposes the node border radius option.|
| [void OH_ArkUI_RenderNodeUtils_SetNodeBorderRadiusOptionCornerRadius(ArkUI_NodeBorderRadiusOption* option, uint32_t cornerRadius, ArkUI_CornerDirection direction)](#oh_arkui_rendernodeutils_setnodeborderradiusoptioncornerradius) | - | Sets the corner radius for the node border radius option.|
| [ArkUI_CircleShapeOption* OH_ArkUI_RenderNodeUtils_CreateCircleShapeOption()](#oh_arkui_rendernodeutils_createcircleshapeoption) | - | Creates a circle shape option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeCircleShapeOption(ArkUI_CircleShapeOption* option)](#oh_arkui_rendernodeutils_disposecircleshapeoption) | - | Disposes the circle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterX(ArkUI_CircleShapeOption* option, float centerX)](#oh_arkui_rendernodeutils_setcircleshapeoptioncenterx) | - | Sets the x-coordinate of the center for the circle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterY(ArkUI_CircleShapeOption* option, float centerY)](#oh_arkui_rendernodeutils_setcircleshapeoptioncentery) | - | Sets the y-coordinate of the center for the circle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionRadius(ArkUI_CircleShapeOption* option, float radius)](#oh_arkui_rendernodeutils_setcircleshapeoptionradius) | - | Sets the radius value for the circle shape option.|
| [ArkUI_RoundRectShapeOption* OH_ArkUI_RenderNodeUtils_CreateRoundRectShapeOption()](#oh_arkui_rendernodeutils_createroundrectshapeoption) | - | Creates a rounded rectangle shape option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeRoundRectShapeOption(ArkUI_RoundRectShapeOption* option)](#oh_arkui_rendernodeutils_disposeroundrectshapeoption) | - | Disposes the rounded rectangle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionEdgeValue(ArkUI_RoundRectShapeOption* option, float top, float right, float bottom, float left)](#oh_arkui_rendernodeutils_setroundrectshapeoptionedgevalue) | - | Sets the edge values for the rounded rectangle shape option.|
| [void OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionCornerXY(ArkUI_RoundRectShapeOption* option, float x, float y, ArkUI_CornerDirection direction)](#oh_arkui_rendernodeutils_setroundrectshapeoptioncornerxy) | - | Sets the coordinates for the target corner.|
| [ArkUI_CommandPathOption* OH_ArkUI_RenderNodeUtils_CreateCommandPathOption()](#oh_arkui_rendernodeutils_createcommandpathoption) | - | Creates a custom drawing path option.|
| [void OH_ArkUI_RenderNodeUtils_DisposeCommandPathOption(ArkUI_CommandPathOption* option)](#oh_arkui_rendernodeutils_disposecommandpathoption) | - | Disposes the custom drawing path option.|
| [void OH_ArkUI_RenderNodeUtils_SetCommandPathOptionCommands(ArkUI_CommandPathOption* option, char* commands)](#oh_arkui_rendernodeutils_setcommandpathoptioncommands) | - | Sets the command values for the custom drawing path option.|
| [ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRectShape(ArkUI_RectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodemaskoptionfromrectshape) | - | Creates a mask from a rectangle shape.|
| [ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRoundRectShape(ArkUI_RoundRectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodemaskoptionfromroundrectshape) | - | Creates a mask from a rounded rectangle shape.|
| [ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCircleShape(ArkUI_CircleShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodemaskoptionfromcircleshape) | - | Creates a mask from a circle shape.|
| [ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromOvalShape(ArkUI_RectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodemaskoptionfromovalshape) | - | Creates a mask from an oval shape.|
| [ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCommandPath(ArkUI_CommandPathOption* path)](#oh_arkui_rendernodeutils_createrendernodemaskoptionfromcommandpath) | - | Creates a mask from a custom drawing path.|
| [void OH_ArkUI_RenderNodeUtils_DisposeRenderNodeMaskOption(ArkUI_RenderNodeMaskOption* option)](#oh_arkui_rendernodeutils_disposerendernodemaskoption) | - | Disposes the render node mask option.|
| [void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionFillColor(ArkUI_RenderNodeMaskOption* mask, uint32_t fillColor)](#oh_arkui_rendernodeutils_setrendernodemaskoptionfillcolor) | - | Sets the fill color for the render node mask option.|
| [void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeColor(ArkUI_RenderNodeMaskOption* mask, uint32_t strokeColor)](#oh_arkui_rendernodeutils_setrendernodemaskoptionstrokecolor) | - | Sets the stroke color for the render node mask option.|
| [void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeWidth(ArkUI_RenderNodeMaskOption* mask, float strokeWidth)](#oh_arkui_rendernodeutils_setrendernodemaskoptionstrokewidth) | - | Sets the stroke width for the render node mask option.|
| [ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRectShape(ArkUI_RectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodeclipoptionfromrectshape) | - | Creates a render node clip option from a rectangle shape.|
| [ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRoundRectShape(ArkUI_RoundRectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodeclipoptionfromroundrectshape) | - | Creates a render node clip option from a rounded rectangle shape.|
| [ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCircleShape(ArkUI_CircleShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodeclipoptionfromcircleshape) | - | Creates a render node clip option from a circle shape.|
| [ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromOvalShape(ArkUI_RectShapeOption* shape)](#oh_arkui_rendernodeutils_createrendernodeclipoptionfromovalshape) | - | Creates a render node clip option from an oval shape.|
| [ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCommandPath(ArkUI_CommandPathOption* path)](#oh_arkui_rendernodeutils_createrendernodeclipoptionfromcommandpath) | - | Creates a render node clip option from a custom drawing path.|
| [void OH_ArkUI_RenderNodeUtils_DisposeRenderNodeClipOption(ArkUI_RenderNodeClipOption* option)](#oh_arkui_rendernodeutils_disposerendernodeclipoption) | - | Disposes the render node clip option.|


## Function Description

### OH_ArkUI_RenderNodeUtils_AddRenderNode()

```
int32_t OH_ArkUI_RenderNodeUtils_AddRenderNode(ArkUI_NodeHandle node, ArkUI_RenderNodeHandle child)
```

**Description**
Adds a child render node to the parent custom node.
 <br>Only parent nodes of the **customNode** type are supported.
 <br>Each custom node can be attached with only one **ArkUI_RenderNodeHandle** instance.
 <br>A **customNode** instance cannot be attached with other types of **ArkUI_NodeHandle**.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) child | Target render node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_NOT_CUSTOM_NODE](capi-native-type-h.md#arkui_errorcode) if the target node is not a custom node.<br>         Returns [ARKUI_ERROR_CODE_CHILD_EXISTED](capi-native-type-h.md#arkui_errorcode) if the target node already has a child node.<br>         Returns [ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED](capi-native-type-h.md#arkui_errorcode) if the target rendering node already has a parent node.|

### OH_ArkUI_RenderNodeUtils_RemoveRenderNode()

```
int32_t OH_ArkUI_RenderNodeUtils_RemoveRenderNode(ArkUI_NodeHandle node, ArkUI_RenderNodeHandle child)
```

**Description**
Removes all child render nodes from the specified node.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) child | Target render node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_NOT_CUSTOM_NODE](capi-native-type-h.md#arkui_errorcode) if the target node is not a custom node.

### OH_ArkUI_RenderNodeUtils_ClearRenderNodeChildren()

```
int32_t OH_ArkUI_RenderNodeUtils_ClearRenderNodeChildren(ArkUI_NodeHandle node)
```

**Description**
Clears child render nodes in the parent node.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_NOT_CUSTOM_NODE](capi-native-type-h.md#arkui_errorcode) if the target node is not a custom node.

### OH_ArkUI_RenderNodeUtils_Invalidate()

```
int32_t OH_ArkUI_RenderNodeUtils_Invalidate(ArkUI_NodeHandle node)
```

**Description**
Marks the target custom node as dirty, causing its child render nodes to re-render.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_CreateNode()

```
ArkUI_RenderNodeHandle OH_ArkUI_RenderNodeUtils_CreateNode()
```

**Description**
Creates a render node.

**Since**: 20

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) | Target render node.|

### OH_ArkUI_RenderNodeUtils_DisposeNode()

```
int32_t OH_ArkUI_RenderNodeUtils_DisposeNode(ArkUI_RenderNodeHandle node)
```

**Description**
Destroys the render node.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) | Target render node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AddChild()

```
int32_t OH_ArkUI_RenderNodeUtils_AddChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child)
```

**Description**
Adds a child node to the target parent render node.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node| Target parent render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) child| Child render node to add.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_InsertChildAfter()

```
int32_t OH_ArkUI_RenderNodeUtils_InsertChildAfter(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child, ArkUI_RenderNodeHandle sibling)
```

**Description**
Adds a child node after the target child node of the parent node.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node| Target parent render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) child| Child render node to add.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) sibling| Target child render node.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_RemoveChild()

```
int32_t OH_ArkUI_RenderNodeUtils_RemoveChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle child)
```

**Description**
Removes a child node from the specified render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target parent render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) child | Child render node to remove.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_ClearChildren()

```
int32_t OH_ArkUI_RenderNodeUtils_ClearChildren(ArkUI_RenderNodeHandle node)
```

**Description**
Clears all child nodes of the specified render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetChild()

```
int32_t OH_ArkUI_RenderNodeUtils_GetChild(ArkUI_RenderNodeHandle node, int32_t index, ArkUI_RenderNodeHandle* child)
```

**Description**
Obtains the child node at the specified index.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target parent render node.|
| int32_t index | Zero-based index of the child node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)* child | Render node pointer used to receive the child node.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST](capi-native-type-h.md#arkui_errorcode) if the corresponding render child node is not found.

### OH_ArkUI_RenderNodeUtils_GetFirstChild()

```
int32_t OH_ArkUI_RenderNodeUtils_GetFirstChild(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* child)
```

**Description**
Obtains the first child node of the specified render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)* child | Render node pointer used to receive the first child node.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST](capi-native-type-h.md#arkui_errorcode) if the corresponding render child node is not found.

### OH_ArkUI_RenderNodeUtils_GetNextSibling()

```
int32_t OH_ArkUI_RenderNodeUtils_GetNextSibling(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* sibling)
```

**Description**
Obtains the next sibling node of the specified node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)* sibling | Render node pointer used to receive the next sibling node.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST](capi-native-type-h.md#arkui_errorcode) if the corresponding render child node is not found.

### OH_ArkUI_RenderNodeUtils_GetPreviousSibling()

```
int32_t OH_ArkUI_RenderNodeUtils_GetPreviousSibling(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle* sibling)
```

**Description**
Obtains the previous sibling node of the specified node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Reference node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)* sibling | Render node pointer used to receive the previous sibling node.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST](capi-native-type-h.md#arkui_errorcode) if the corresponding render child node is not found.

### OH_ArkUI_RenderNodeUtils_GetChildren()

```
int32_t OH_ArkUI_RenderNodeUtils_GetChildren(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeHandle** children, int32_t* count)
```

**Description**
Obtains all child render nodes of the parent render node. The caller is responsible for releasing the returned child node array.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target parent render node.|
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md)** children | Pointer array used to store all child render nodes.|
| int32_t* count | Pointer used to store the number of obtained child nodes.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetChildrenCount()

```
int32_t OH_ArkUI_RenderNodeUtils_GetChildrenCount(ArkUI_RenderNodeHandle node, int32_t* count)
```

**Description**
Obtains the number of child render nodes of the specified render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target parent render node.|
| int32_t* count | Pointer used to store the number of child nodes.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBackgroundColor()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBackgroundColor(ArkUI_RenderNodeHandle node, uint32_t color)
```

**Description**
Sets the background color for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| uint32_t color | ARGB color value (32-bit unsigned integer).<br>Default value: **0x00000000**.<br>**Description of color byte layout**:<br>- Bits 24-31: alpha channel (0x00 for fully transparent, 0xFF for fully opaque).<br>- Bits 16-23: red channel.<br>- Bits 8-15: green channel.<br>- Bits 0-7: blue channel.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetBackgroundColor()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBackgroundColor(ArkUI_RenderNodeHandle node, uint32_t* color)
```

**Description**
Obtains the background color of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| uint32_t* color | Integer pointer used to store the obtained RGBA color value.<br>Default value: **0x00000000**.<br>**Description of color byte layout**:<br>- Bits 24-31: alpha channel (0x00 for fully transparent, 0xFF for fully opaque).<br>- Bits 16-23: red channel.<br>- Bits 8-15: green channel.<br>- Bits 0-7: blue channel.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetClipToFrame()

```
int32_t OH_ArkUI_RenderNodeUtils_SetClipToFrame(ArkUI_RenderNodeHandle node, int32_t clipToFrame)
```

**Description**
Sets whether to clip the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t clipToFrame | Whether to clip the current render node. **1**: Clip to frame. **0**: Do not clip.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetClipToFrame()

```
int32_t OH_ArkUI_RenderNodeUtils_GetClipToFrame(ArkUI_RenderNodeHandle node, int32_t* clipToFrame)
```

**Description**
Obtains whether the render node is clipped.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* clipToFrame | Integer pointer used to receive the clipping status (1 or 0).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetClipToBounds()

```
int32_t OH_ArkUI_RenderNodeUtils_SetClipToBounds(ArkUI_RenderNodeHandle node, int32_t clipToBounds)
```

**Description**
Sets whether to clip to the bounds of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t clipToBounds | Clipping flag. **1**: Clip to bounds. **0**: Do not clip.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetClipToBounds()

```
int32_t OH_ArkUI_RenderNodeUtils_GetClipToBounds(ArkUI_RenderNodeHandle node, int32_t* clipToBounds)
```

**Description**
Sets whether clipping to the bounds of the render node is enabled.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* clipToBounds | Clipping flag. **1**: Clip to bounds. **0**: Do not clip.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetOpacity()

```
int32_t OH_ArkUI_RenderNodeUtils_SetOpacity(ArkUI_RenderNodeHandle node, float opacity)
```

**Description**
Sets the opacity value for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float opacity | Opacity value (0.0–1.0).<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetOpacity()

```
int32_t OH_ArkUI_RenderNodeUtils_GetOpacity(ArkUI_RenderNodeHandle node, float* opacity)
```

**Description**
Obtains the opacity value of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* opacity | Pointer used to store the opacity value (0.0–1.0).<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetSize()

```
int32_t OH_ArkUI_RenderNodeUtils_SetSize(ArkUI_RenderNodeHandle node, int32_t width, int32_t height)
```

**Description**
Sets the size for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t width | Width value (in px).<br>Default value: **0**, in px.|
| int32_t height | Height value (in px).<br>Default value: **0**, in px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetSize()

```
int32_t OH_ArkUI_RenderNodeUtils_GetSize(ArkUI_RenderNodeHandle node, int32_t* width, int32_t* height)
```

**Description**
Obtains the size of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* width | Pointer used to store the width value (in px).<br>Default value: **0**, in px.|
| int32_t* height | Pointer used to store the height value (in px).<br>Default value: **0**, in px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetPosition()

```
int32_t OH_ArkUI_RenderNodeUtils_SetPosition(ArkUI_RenderNodeHandle node, int32_t x, int32_t y)
```

**Description**
Sets the position coordinates for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t x |X-coordinate (in px).<br>Default value: **0**, in px.|
| int32_t y |Y-coordinate (in px).<br>Default value: **0**, in px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetPosition()

```
int32_t OH_ArkUI_RenderNodeUtils_GetPosition(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y)
```

**Description**
Obtains the position coordinates of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* x | Pointer used to store the x-coordinate (in px).<br>Default value: **0**, in px.|
| int32_t* y | Pointer used to store the y-coordinate (in px).<br>Default value: **0**, in px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetPivot()

```
int32_t OH_ArkUI_RenderNodeUtils_SetPivot(ArkUI_RenderNodeHandle node, float x, float y)
```

**Description**
Sets the pivot point for the transformation of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float x | X-coordinate of the pivot point. Standard value range: 0.0–1.0.<br>Default value: **0.5**.|
| float y | Y-coordinate of the pivot point. Standard value range: 0.0–1.0.<br>Default value: **0.5**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetPivot()

```
int32_t OH_ArkUI_RenderNodeUtils_GetPivot(ArkUI_RenderNodeHandle node, float* x, float* y)
```

**Description**
Obtains the pivot point coordinates of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* x | Pointer used to store the x-coordinate of the pivot point.<br>Default value: **0.5**.|
| float* y | Pointer used to store the y-coordinate of the pivot point.<br>Default value: **0.5**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetScale()

```
int32_t OH_ArkUI_RenderNodeUtils_SetScale(ArkUI_RenderNodeHandle node, float x, float y)
```

**Description**
Sets the scale factors for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float x | Scale factor on the x-axis.<br>Default value: **1**.|
| float y | Scale factor on the y-axis.<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetScale()

```
int32_t OH_ArkUI_RenderNodeUtils_GetScale(ArkUI_RenderNodeHandle node, float* x, float* y)
```

**Description**
Obtains the scale factors of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* x | Pointer used to store the scale factor on the x-axis.<br>Default value: **1**.|
| float* y | Pointer used to store the scale factor on the y-axis.<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetTranslation()

```
int32_t OH_ArkUI_RenderNodeUtils_SetTranslation(ArkUI_RenderNodeHandle node, float x, float y)
```

**Description**
Sets the translation offset for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float x | Horizontal translation offset (in pixels).<br>Default value: **0**.|
| float y | Vertical translation offset (in pixels).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetTranslation()

```
int32_t OH_ArkUI_RenderNodeUtils_GetTranslation(ArkUI_RenderNodeHandle node, float* x, float* y)
```

**Description**
Obtains the translation offset of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* x | Pointer used to store the horizontal translation offset.<br>Default value: **0**.|
| float* y | Pointer used to store the horizontal translation offset.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetRotation()

```
int32_t OH_ArkUI_RenderNodeUtils_SetRotation(ArkUI_RenderNodeHandle node, float x, float y, float z)
```

**Description**
Sets the rotation angles for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float x | Rotation angle around the x-axis (in degrees).<br>Default value: **0**.|
| float y | Rotation angle around the y-axis (in degrees).<br>Default value: **0**.|
| float z | Rotation angle around the z-axis (in degrees).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetRotation()

```
int32_t OH_ArkUI_RenderNodeUtils_GetRotation(ArkUI_RenderNodeHandle node, float* x, float* y, float* z)
```

**Description**
Obtains the rotation angles of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* x | Pointer used to store the rotation angle around the x-axis (in degrees).<br>Default value: **0**.|
| float* y | Pointer used to store the rotation angle around the y-axis (in degrees).<br>Default value: **0**.|
| float* z | Pointer used to store the rotation angle around the z-axis (in degrees).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetTransform()

```
int32_t OH_ArkUI_RenderNodeUtils_SetTransform(ArkUI_RenderNodeHandle node, float* matrix)
```

**Description**
Sets the transformation matrix for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* matrix | Float array of 4x4 transformation matrix (16 consecutive values).|

The transformation matrix must be provided as 16 consecutive float values in row-major order:<br>
[m00, m01, m02, m03,<br>
m10, m11, m12, m13,<br>
m20, m21, m22, m23,<br>
m30, m31, m32, m33]<br>
The matrix is represented as follows:<br>
| m00 m01 m02 m03 |<br>
| m10 m11 m12 m13 |<br>
| m20 m21 m22 m23 |<br>
| m30 m31 m32 m33 |<br>
Matrix components:
| Matrix Element| Description|
| -- | -- |
| m00 | Scale value for the x-axis. The default value is **1** in the identity matrix.|
| m01 | Second value, affected by rotation or skewing around x, y, z axes.|
| m02 | Third value, affected by rotation around x, y, z axes.|
| m03 | Fourth value, affected by perspective projection.|
| m10 | Fifth value, affected by rotation or skewing around x, y, z axes.|
| m11 | Scale value for the y-axis. The default value is **1** in the identity matrix.|
| m12 | Seventh value, affected by rotation around x, y, z axes.|
| m13 | Eighth value, affected by perspective projection.|
| m20 | Ninth value, affected by rotation around x, y, z axes.|
| m21 | Tenth value, affected by rotation around x, y, z axes.|
| m22 | Scale value for the z-axis. The default value is **1** in the identity matrix.|
| m23 | Twelfth value, affected by perspective projection.|
| m30 | Translation value for the x-axis (in px). The default value is **0** in the identity matrix.|
| m31 | Translation value for the y-axis (in px). The default value is **0** in the identity matrix.|
| m32 | Translation value for the z-axis (in px). The default value is **0** in the identity matrix.|
| m33 | Valid in homogeneous coordinates, producing perspective projection effects.| |

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_SetShadowColor()

```
int32_t OH_ArkUI_RenderNodeUtils_SetShadowColor(ArkUI_RenderNodeHandle node, uint32_t color)
```

**Description**
Sets the shadow color for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| uint32_t color | ARGB color value (32-bit unsigned integer).<br>Default value: **0xFF000000**.<br>**Description of color byte layout**:<br>- Bits 24-31: alpha channel (0x00 for fully transparent, 0xFF for fully opaque).<br>- Bits 16-23: red channel.<br>- Bits 8-15: green channel.<br>- Bits 0-7: blue channel.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetShadowColor()

```
int32_t OH_ArkUI_RenderNodeUtils_GetShadowColor(ArkUI_RenderNodeHandle node, uint32_t* color)
```

**Description**
Obtains the shadow color of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| uint32_t* color | Integer pointer used to store the obtained RGBA color value.<br>Default value: **0xFF000000**.<br>**Description of color byte layout**:<br>- Bits 24-31: alpha channel (0x00 for fully transparent, 0xFF for fully opaque).<br>- Bits 16-23: red channel.<br>- Bits 8-15: green channel.<br>- Bits 0-7: blue channel.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetShadowOffset()

```
int32_t OH_ArkUI_RenderNodeUtils_SetShadowOffset(ArkUI_RenderNodeHandle node, int32_t x, int32_t y)
```

**Description**
Sets the shadow offset for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t x | Horizontal offset (in pixels).<br>Default value: **0**.|
| int32_t y | Vertical offset (in pixels).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetShadowOffset()

```
int32_t OH_ArkUI_RenderNodeUtils_GetShadowOffset(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y)
```

**Description**
Obtains the shadow offset of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* x | Pointer used to store the horizontal offset.<br>Default value: **0**.|
| int32_t* y | Pointer used to store the vertical offset.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetShadowAlpha()

```
int32_t OH_ArkUI_RenderNodeUtils_SetShadowAlpha(ArkUI_RenderNodeHandle node, float alpha)
```

**Description**
Sets the shadow alpha (transparency) for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float alpha | Shadow alpha value (0.0–1.0).<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetShadowAlpha()

```
int32_t OH_ArkUI_RenderNodeUtils_GetShadowAlpha(ArkUI_RenderNodeHandle node, float* alpha)
```

**Description**
Obtains the shadow alpha (transparency) of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* alpha | Pointer used to store the shadow alpha value.<br>Default value: **1**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetShadowElevation()

```
int32_t OH_ArkUI_RenderNodeUtils_SetShadowElevation(ArkUI_RenderNodeHandle node, float elevation)
```

**Description**
Sets the shadow elevation for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float elevation | Elevation.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetShadowElevation()

```
int32_t OH_ArkUI_RenderNodeUtils_GetShadowElevation(ArkUI_RenderNodeHandle node, float* elevation)
```

**Description**
Obtains the shadow elevation of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* elevation | Pointer used to store the elevation value.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetShadowRadius()

```
int32_t OH_ArkUI_RenderNodeUtils_SetShadowRadius(ArkUI_RenderNodeHandle node, float radius)
```

**Description**
Sets the shadow radius for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float radius | Radius value.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetShadowRadius()

```
int32_t OH_ArkUI_RenderNodeUtils_GetShadowRadius(ArkUI_RenderNodeHandle node, float* radius)
```

**Description**
Obtains the shadow radius of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float* radius | Pointer used to store the radius value.<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBorderStyle()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBorderStyle(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderStyleOption* borderStyle)
```

**Description**
Sets the border style for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)* borderStyle | Pointer to the border style.<br>Default value in the struct pointer: [ARKUI_BORDER_STYLE_SOLID](capi-native-type-h.md#arkui_borderstyle).|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetBorderStyle()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBorderStyle(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderStyleOption** borderStyle)
```

**Description**
Obtains the border style of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)** borderStyle | Pointer used to store the border style.<br>Default value in the struct pointer: [ARKUI_BORDER_STYLE_SOLID](capi-native-type-h.md#arkui_borderstyle).|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBorderWidth()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBorderWidth(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderWidthOption* borderWidth)
```

**Description**
Sets the border width for the render node. The border width must be smaller than the node size.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)* borderWidth | Pointer to the border width.<br>Default value in the struct pointer: **0**. Unit: px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetBorderWidth()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBorderWidth(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderWidthOption** borderWidth)
```

**Description**
Obtains the border width of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)** borderWidth | Pointer used to store the border width.<br>Default value in the struct pointer: **0**. Unit: px.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBorderColor()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBorderColor(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderColorOption* borderColor)
```

**Description**
Sets the border color for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)* borderColor | Pointer to the border color.<br>Default value in the struct pointer: **0x00000000**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetBorderColor()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBorderColor(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderColorOption** borderColor)
```

**Description**
Obtains the border color of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)** borderColor | Pointer used to store the border color.<br>Default value in the struct pointer: **0x00000000**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBorderRadius()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBorderRadius(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderRadiusOption* borderRadius)
```

**Description**
Sets the border corner radius for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)* borderRadius | Pointer to the border radius.<br>Default value in the struct pointer: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetBorderRadius()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBorderRadius(ArkUI_RenderNodeHandle node, ArkUI_NodeBorderRadiusOption** borderRadius)
```

**Description**
Obtains the border corner radius of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)** borderRadius | Pointer used to store the border corner radius.<br>Default value in the struct pointer: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetMask()

```
int32_t OH_ArkUI_RenderNodeUtils_SetMask(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeMaskOption* option)
```

**Description**
Applies a mask to the render node using the mask configuration.<br>         The mask is created as follows:<br>         1. Add brightness and linear color filters to the mask layer.<br>         2. Draw the mask graphic under this filter.<br>         3.
Use the original node image as the source color and the mask graphic as the target color, and blend them into a mask image using the [BlendMode.SRC_IN](../apis-arkgraphics2d/arkts-apis-graphics-drawing-e.md#blendmode) API.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md)* option | Pointer to the mask configuration.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetClip()

```
int32_t OH_ArkUI_RenderNodeUtils_SetClip(ArkUI_RenderNodeHandle node, ArkUI_RenderNodeClipOption* option)
```

**Description**
Applies clipping to the render node using the clipping configuration.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* option | Pointer to the clipping configuration.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetMarkNodeGroup()

```
int32_t OH_ArkUI_RenderNodeUtils_SetMarkNodeGroup(ArkUI_RenderNodeHandle node, bool markNodeGroup)
```

**Description**
Marks whether to prioritize drawing the node and its child nodes.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| bool markNodeGroup | Whether to prioritize drawing the node and its child nodes.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetBounds()

```
int32_t OH_ArkUI_RenderNodeUtils_SetBounds(ArkUI_RenderNodeHandle node, int32_t x, int32_t y, int32_t width, int32_t height)
```

**Description**
Sets the bounds for the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t x | X-coordinate of the upper left corner of the bounds, in pixels.<br>Default value: **0**.|
| int32_t y | Y-coordinate of the upper left corner of the bounds, in pixels.<br>Default value: **0**.|
| int32_t width | Width of the bounds (in pixels).<br>Default value: **0**.|
| int32_t height | Height of the bounds (in pixels).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.<br>         Returns [ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE](capi-native-type-h.md#arkui_errorcode) if the parameter value is out of range.

### OH_ArkUI_RenderNodeUtils_GetBounds()

```
int32_t OH_ArkUI_RenderNodeUtils_GetBounds(ArkUI_RenderNodeHandle node, int32_t* x, int32_t* y, int32_t* width, int32_t* height)
```

**Description**
Obtains the bounds of the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| int32_t* x | Pointer used to store the x-coordinate of the upper left corner of the bounds, in pixels.<br>Default value: **0**.|
| int32_t* y | Pointer used to store the y-coordinate of the upper left corner of the bounds, in pixels.<br>Default value: **0**.|
| int32_t* width | Pointer used to store the width of the bounds (in pixels).<br>Default value: **0**.|
| int32_t* height | Pointer used to store the height of the bounds (in pixels).<br>Default value: **0**.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetDrawRegion()

```
int32_t OH_ArkUI_RenderNodeUtils_SetDrawRegion(ArkUI_RenderNodeHandle node, float x, float y, float w, float h)
```

**Description**
Sets the drawing region for the render node. This drawing region is mainly used to address drawing issues caused by exceeding boundaries. When possible, set the size according to the actual drawing range.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| float x | X-coordinate of the upper left corner of the bounds, in pixels.|
| float y | Y-coordinate of the upper left corner of the bounds, in pixels.|
| float w | Width of the bounds (in pixels).|
| float h | Height of the bounds (in pixels).|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachContentModifier()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachContentModifier(ArkUI_RenderNodeHandle node, ArkUI_RenderContentModifierHandle modifier)
```

**Description**
Attaches a content modifier to the render node.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeHandle](./capi-arkui-nativemodule-arkui-rendernodehandle.md) node | Target render node.|
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Content modifier.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_CreateContentModifier()

```
ArkUI_RenderContentModifierHandle OH_ArkUI_RenderNodeUtils_CreateContentModifier()
```

**Description**
Creates a content modifier.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeContentModifier()

```
void OH_ArkUI_RenderNodeUtils_DisposeContentModifier(ArkUI_RenderContentModifierHandle modifier)
```

**Description**
Disposes the content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Content modifier.|

### OH_ArkUI_RenderNodeUtils_AttachFloatProperty()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachFloatProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_FloatPropertyHandle property)
```

**Description**
Attaches a float property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| ArkUI_FloatPropertyHandle property | Float property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachVector2Property()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachVector2Property(ArkUI_RenderContentModifierHandle modifier, ArkUI_Vector2PropertyHandle property)
```

**Description**
Attaches a 2D vector property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md) property | 2D vector property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachColorProperty()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachColorProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_ColorPropertyHandle property)
```

**Description**
Attaches a color property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md) property | Color property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachFloatAnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_FloatAnimatablePropertyHandle property)
```

**Description**
Attaches an animatable float property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md) property | Animatable float property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachVector2AnimatableProperty()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachVector2AnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_Vector2AnimatablePropertyHandle property)
```

**Description**
Attaches an animatable 2D vector property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md) property | Animatable 2D vector property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_AttachColorAnimatableProperty()

```
int32_t OH_ArkUI_RenderNodeUtils_AttachColorAnimatableProperty(ArkUI_RenderContentModifierHandle modifier, ArkUI_ColorAnimatablePropertyHandle property)
```

**Description**
Attaches an animatable color property to the target content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md) property | Animatable color property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_CreateFloatProperty()

```
ArkUI_FloatPropertyHandle OH_ArkUI_RenderNodeUtils_CreateFloatProperty(float value)
```

**Description**
Creates a float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| float value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_FloatPropertyHandle](./capi-arkui-nativemodule-arkui-floatpropertyhandle.md) | Float property.

### OH_ArkUI_RenderNodeUtils_SetFloatPropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetFloatPropertyValue(ArkUI_FloatPropertyHandle property, float value)
```

**Description**
Sets the value of the float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatPropertyHandle](./capi-arkui-nativemodule-arkui-floatpropertyhandle.md) property | Float property.|
| float value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetFloatPropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetFloatPropertyValue(ArkUI_FloatPropertyHandle property, float* value)
```

**Description**
Obtains the value of the float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatPropertyHandle](./capi-arkui-nativemodule-arkui-floatpropertyhandle.md) property | Float property.|
| float* value | Pointer used to store the property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeFloatProperty()

```
void OH_ArkUI_RenderNodeUtils_DisposeFloatProperty(ArkUI_FloatPropertyHandle property)
```

**Description**
Disposes the float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatPropertyHandle](./capi-arkui-nativemodule-arkui-floatpropertyhandle.md) property | Float property.|

### OH_ArkUI_RenderNodeUtils_CreateVector2Property()

```
ArkUI_Vector2PropertyHandle OH_ArkUI_RenderNodeUtils_CreateVector2Property(float x, float y)
```

**Description**
Creates a 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| float x | X-coordinate of the property.|
| float y | Y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md) | 2D vector property.

### OH_ArkUI_RenderNodeUtils_SetVector2PropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetVector2PropertyValue(ArkUI_Vector2PropertyHandle property, float x, float y)
```

**Description**
Sets the value of the 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md) property | 2D vector property.|
| float x | X-coordinate of the property.|
| float y | Y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetVector2PropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetVector2PropertyValue(ArkUI_Vector2PropertyHandle property, float* x, float* y)
```

**Description**
Obtains the value of the 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md) property | 2D vector property.|
| float* x | Pointer used to store the x-coordinate of the property.|
| float* y | Pointer used to store the y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeVector2Property()

```
void OH_ArkUI_RenderNodeUtils_DisposeVector2Property(ArkUI_Vector2PropertyHandle property)
```

**Description**
Disposes the 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2PropertyHandle](./capi-arkui-nativemodule-arkui-vector2propertyhandle.md) property | 2D vector property.|

### OH_ArkUI_RenderNodeUtils_CreateColorProperty()

```
ArkUI_ColorPropertyHandle OH_ArkUI_RenderNodeUtils_CreateColorProperty(uint32_t value)
```

**Description**
Creates a color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| uint32_t value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md) | Color property.

### OH_ArkUI_RenderNodeUtils_SetColorPropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetColorPropertyValue(ArkUI_ColorPropertyHandle property, uint32_t value)
```

**Description**
Sets the value of the color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md) property | Color property.|
| uint32_t value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetColorPropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetColorPropertyValue(ArkUI_ColorPropertyHandle property, uint32_t* value)
```

**Description**
Obtains the value of the color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md) property | Color property.|
| uint32_t* value | Pointer used to store the property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeColorProperty()

```
void OH_ArkUI_RenderNodeUtils_DisposeColorProperty(ArkUI_ColorPropertyHandle property)
```

**Description**
Disposes the color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorPropertyHandle](./capi-arkui-nativemodule-arkui-colorpropertyhandle.md) property | Color property.|

### OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty()

```
ArkUI_FloatAnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateFloatAnimatableProperty(float value)
```

**Description**
Creates an animatable float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| float value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md) | Animatable float property.

### OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetFloatAnimatablePropertyValue(ArkUI_FloatAnimatablePropertyHandle property, float value)
```

**Description**
Sets the value of the animatable float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md) property | Animatable float property.|
| float value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetFloatAnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetFloatAnimatablePropertyValue(ArkUI_FloatAnimatablePropertyHandle property, float* value)
```

**Description**
Obtains the value of the animatable float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md) property | Animatable float property.|
| float* value | Pointer used to store the property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeFloatAnimatableProperty()

```
void OH_ArkUI_RenderNodeUtils_DisposeFloatAnimatableProperty(ArkUI_FloatAnimatablePropertyHandle property)
```

**Description**
Disposes the animatable float property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_FloatAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-floatanimatablepropertyhandle.md) property | Animatable float property.|

### OH_ArkUI_RenderNodeUtils_CreateVector2AnimatableProperty()

```
ArkUI_Vector2AnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateVector2AnimatableProperty(float x, float y)
```

**Description**
Creates an animatable 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| float x | X-coordinate of the property.|
| float y | Y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md) | Animatable 2D vector property.

### OH_ArkUI_RenderNodeUtils_SetVector2AnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetVector2AnimatablePropertyValue(ArkUI_Vector2AnimatablePropertyHandle property, float x, float y)
```

**Description**
Sets the value of the animatable 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md) property | Animatable 2D vector property.|
| float x | X-coordinate of the property.|
| float y | Y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetVector2AnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetVector2AnimatablePropertyValue(ArkUI_Vector2AnimatablePropertyHandle property, float* x, float* y)
```

**Description**
Obtains the value of the animatable 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md) property | Animatable 2D vector property.|
| float* x | Pointer used to store the x-coordinate of the property.|
| float* y | Pointer used to store the y-coordinate of the property.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeVector2AnimatableProperty()

```
void OH_ArkUI_RenderNodeUtils_DisposeVector2AnimatableProperty(ArkUI_Vector2AnimatablePropertyHandle property)
```

**Description**
Disposes the animatable 2D vector property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_Vector2AnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-vector2animatablepropertyhandle.md) property | Animatable 2D vector property.|

### OH_ArkUI_RenderNodeUtils_CreateColorAnimatableProperty()

```
ArkUI_ColorAnimatablePropertyHandle OH_ArkUI_RenderNodeUtils_CreateColorAnimatableProperty(uint32_t value)
```

**Description**
Creates an animatable color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| uint32_t value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md) | Animatable color property.

### OH_ArkUI_RenderNodeUtils_SetColorAnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_SetColorAnimatablePropertyValue(ArkUI_ColorAnimatablePropertyHandle property, uint32_t value)
```

**Description**
Sets the value of the animatable color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md) property | Animatable color property.|
| uint32_t value | Property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_GetColorAnimatablePropertyValue()

```
int32_t OH_ArkUI_RenderNodeUtils_GetColorAnimatablePropertyValue(ArkUI_ColorAnimatablePropertyHandle property, uint32_t* value)
```

**Description**
Obtains the value of the animatable color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md) property | Animatable color property.|
| uint32_t* value | Pointer used to store the property value.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_DisposeColorAnimatableProperty()

```
void OH_ArkUI_RenderNodeUtils_DisposeColorAnimatableProperty(ArkUI_ColorAnimatablePropertyHandle property)
```

**Description**
Disposes the animatable color property.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_ColorAnimatablePropertyHandle](./capi-arkui-nativemodule-arkui-coloranimatablepropertyhandle.md) property | Animatable color property.|

### OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw()

```
int32_t OH_ArkUI_RenderNodeUtils_SetContentModifierOnDraw(ArkUI_RenderContentModifierHandle modifier, void* userData, void (callback)(ArkUI_DrawContext context, void* userData))
```

**Description**
Sets the **onDraw** callback function for the content modifier.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderContentModifierHandle](./capi-arkui-nativemodule-arkui-rendercontentmodifierhandle.md) modifier | Target content modifier.|
| void* userData | Custom data to be passed to the callback.|
| void (callback)(ArkUI_DrawContext context, void* userData) | Callback for receiving drawing events.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_CreateRectShapeOption()

```
ArkUI_RectShapeOption* OH_ArkUI_RenderNodeUtils_CreateRectShapeOption()
```

**Description**
Creates a rectangle shape option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)* | Pointer to the rectangle shape option.

### OH_ArkUI_RenderNodeUtils_DisposeRectShapeOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeRectShapeOption(ArkUI_RectShapeOption* option)
```

**Description**
Disposes the rectangle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)* option | Pointer to the rectangle shape option.|

### OH_ArkUI_RenderNodeUtils_SetRectShapeOptionEdgeValue()

```
void OH_ArkUI_RenderNodeUtils_SetRectShapeOptionEdgeValue(ArkUI_RectShapeOption* option, float top, float right, float bottom, float left)
```

**Description**
Sets the edge values for the rectangle shape option. When the left and top boundaries are set to negative values, part of the content that exceeds the node may fail to draw due to the layer overlay effect involved in display.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)* option | Pointer to the rectangle shape option.|
| float top | Top edge value of the rectangle shape option.|
| float right | Right edge value of the rectangle shape option.|
| float bottom | Bottom edge value of the rectangle shape option.|
| float left | Left edge value of the rectangle shape option.|

### OH_ArkUI_RenderNodeUtils_CreateNodeBorderStyleOption()

```
ArkUI_NodeBorderStyleOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderStyleOption()
```

**Description**
Creates a node border style option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)* | Pointer to the node border style.

### OH_ArkUI_RenderNodeUtils_DisposeNodeBorderStyleOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderStyleOption(ArkUI_NodeBorderStyleOption* option)
```

**Description**
Disposes the node border style option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)* option | Pointer to the node border style option.|

### OH_ArkUI_RenderNodeUtils_SetNodeBorderStyleOptionEdgeStyle()

```
void OH_ArkUI_RenderNodeUtils_SetNodeBorderStyleOptionEdgeStyle(ArkUI_NodeBorderStyleOption* option, ArkUI_BorderStyle edgeStyle, ArkUI_EdgeDirection direction)
```

**Description**
Sets the edge style for the node border style option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderStyleOption](./capi-arkui-nativemodule-arkui-nodeborderstyleoption.md)* option | Pointer to the node border style option.|
| [ArkUI_BorderStyle](capi-native-type-h.md#arkui_borderstyle) edgeStyle | Edge border style value of the node border style option.|
| [ArkUI_EdgeDirection](capi-native-type-h.md#arkui_edgedirection) direction | Edge direction.|

### OH_ArkUI_RenderNodeUtils_CreateNodeBorderWidthOption()

```
ArkUI_NodeBorderWidthOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderWidthOption()
```

**Description**
Creates a node border width option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)* | Pointer to the node border width option.

### OH_ArkUI_RenderNodeUtils_DisposeNodeBorderWidthOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderWidthOption(ArkUI_NodeBorderWidthOption* option)
```

**Description**
Disposes the node border width option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)* option | Pointer to the node border width option.|

### OH_ArkUI_RenderNodeUtils_SetNodeBorderWidthOptionEdgeWidth()

```
void OH_ArkUI_RenderNodeUtils_SetNodeBorderWidthOptionEdgeWidth(ArkUI_NodeBorderWidthOption* option, float edgeWidth, ArkUI_EdgeDirection direction)
```

**Description**
Sets the edge width for the node border width option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderWidthOption](./capi-arkui-nativemodule-arkui-nodeborderwidthoption.md)* option | Pointer to the node border width option.|
| float edgeWidth | Edge width of the node border width option.<br>Value range: [0, +∞).|
| [ArkUI_EdgeDirection](capi-native-type-h.md#arkui_edgedirection) direction | Edge direction.|

### OH_ArkUI_RenderNodeUtils_CreateNodeBorderColorOption()

```
ArkUI_NodeBorderColorOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderColorOption()
```

**Description**
Creates a node border color option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)* | Pointer to the node border color option.

### OH_ArkUI_RenderNodeUtils_DisposeNodeBorderColorOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderColorOption(ArkUI_NodeBorderColorOption* option)
```

**Description**
Disposes the node border color option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)* option | Pointer to the node border color option.|

### OH_ArkUI_RenderNodeUtils_SetNodeBorderColorOptionEdgeColor()

```
void OH_ArkUI_RenderNodeUtils_SetNodeBorderColorOptionEdgeColor(ArkUI_NodeBorderColorOption* option, uint32_t edgeColor, ArkUI_EdgeDirection direction)
```

**Description**
Sets the edge color for the node border color option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderColorOption](./capi-arkui-nativemodule-arkui-nodebordercoloroption.md)* option | Pointer to the node border color option.|
| uint32_t edgeColor | Edge color of the node border color option.|
| [ArkUI_EdgeDirection](capi-native-type-h.md#arkui_edgedirection) direction | Edge direction.|

### OH_ArkUI_RenderNodeUtils_CreateNodeBorderRadiusOption()

```
ArkUI_NodeBorderRadiusOption* OH_ArkUI_RenderNodeUtils_CreateNodeBorderRadiusOption()
```

**Description**
Creates a node border radius option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)* | Pointer to the node border radius option.

### OH_ArkUI_RenderNodeUtils_DisposeNodeBorderRadiusOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeNodeBorderRadiusOption(ArkUI_NodeBorderRadiusOption* option)
```

**Description**
Disposes the node border radius option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)* option | Pointer to the node border radius option.|

### OH_ArkUI_RenderNodeUtils_SetNodeBorderRadiusOptionCornerRadius()

```
void OH_ArkUI_RenderNodeUtils_SetNodeBorderRadiusOptionCornerRadius(ArkUI_NodeBorderRadiusOption* option, uint32_t cornerRadius, ArkUI_CornerDirection direction)
```

**Description**
Sets the corner radius for the node border radius option. Note that the input parameter **cornerRadius** is of type uint32_t, and only positive integers are supported.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_NodeBorderRadiusOption](./capi-arkui-nativemodule-arkui-nodeborderradiusoption.md)* option | Pointer to the node border radius option.|
| uint32_t cornerRadius | Corner radius of the node border radius option.|
| [ArkUI_CornerDirection](capi-native-type-h.md#arkui_cornerdirection) direction | Edge direction.|

### OH_ArkUI_RenderNodeUtils_CreateCircleShapeOption()

```
ArkUI_CircleShapeOption* OH_ArkUI_RenderNodeUtils_CreateCircleShapeOption()
```

**Description**
Creates a circle shape option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* | Pointer to the circle shape option.

### OH_ArkUI_RenderNodeUtils_DisposeCircleShapeOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeCircleShapeOption(ArkUI_CircleShapeOption* option)
```

**Description**
Disposes the circle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* option | Pointer to the circle shape option.|

### OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterX()

```
void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterX(ArkUI_CircleShapeOption* option, float centerX)
```

**Description**
Sets the x-coordinate of the center for the circle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* option | Pointer to the circle shape option.|
| float centerX | X-coordinate of the center of the circle shape option.|

### OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterY()

```
void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionCenterY(ArkUI_CircleShapeOption* option, float centerY)
```

**Description**
Sets the y-coordinate of the center for the circle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* option | Pointer to the circle shape option.|
| float centerY | Y-coordinate of the center of the circle shape option.|

### OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionRadius()

```
void OH_ArkUI_RenderNodeUtils_SetCircleShapeOptionRadius(ArkUI_CircleShapeOption* option, float radius)
```

**Description**
Sets the radius value for the circle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* option | Pointer to the circle shape option.|
| float radius | Radius value.|

### OH_ArkUI_RenderNodeUtils_CreateRoundRectShapeOption()

```
ArkUI_RoundRectShapeOption* OH_ArkUI_RenderNodeUtils_CreateRoundRectShapeOption()
```

**Description**
Creates a rounded rectangle shape option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)* | Pointer to the rounded rectangle shape option.

### OH_ArkUI_RenderNodeUtils_DisposeRoundRectShapeOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeRoundRectShapeOption(ArkUI_RoundRectShapeOption* option)
```

**Description**
Disposes the rounded rectangle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)* option | Pointer to the rounded rectangle shape option.|

### OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionEdgeValue()

```
void OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionEdgeValue(ArkUI_RoundRectShapeOption* option, float top, float right, float bottom, float left)
```

**Description**
Sets the edge values for the rounded rectangle shape option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)* option | Pointer to the rounded rectangle shape option.|
| float top | Top edge value of the rounded rectangle shape option.|
| float right | Right edge value of the rounded rectangle shape option.|
| float bottom | Bottom edge value of the rounded rectangle shape option.|
| float left | Left edge value of the rounded rectangle shape option.|

### OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionCornerXY()

```
void OH_ArkUI_RenderNodeUtils_SetRoundRectShapeOptionCornerXY(ArkUI_RoundRectShapeOption* option, float x, float y, ArkUI_CornerDirection direction)
```

**Description**
Sets the coordinates for the target corner.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)* option | Pointer to the rounded rectangle shape option.|
| float x | X-coordinate of the target corner, in pixels.|
| float y | Y-coordinate of the target corner, in pixels.|
| ArkUI_CornerDirection direction | Direction of the target corner.|

### OH_ArkUI_RenderNodeUtils_CreateCommandPathOption()

```
ArkUI_CommandPathOption* OH_ArkUI_RenderNodeUtils_CreateCommandPathOption()
```

**Description**
Creates a custom drawing path option.

**Since**: 20

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md)* | Pointer to the custom drawing path option.

### OH_ArkUI_RenderNodeUtils_DisposeCommandPathOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeCommandPathOption(ArkUI_CommandPathOption* option)
```

**Description**
Disposes the custom drawing path option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md)* option | Pointer to the custom drawing path option.|

### OH_ArkUI_RenderNodeUtils_SetCommandPathOptionCommands()

```
void OH_ArkUI_RenderNodeUtils_SetCommandPathOptionCommands(ArkUI_CommandPathOption* option, char* commands)
```

**Description**
Sets the command values for the custom drawing path option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md)* option | Pointer to the custom drawing path option.|
| char* commands | Command values.|

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRectShape()

```
ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRectShape(ArkUI_RectShapeOption* shape)
```

**Description**
Creates a mask from a rectangle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md) shape | Pointer to the rectangle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) | Pointer to the render node mask.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRoundRectShape()

```
ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromRoundRectShape(ArkUI_RoundRectShapeOption* shape)
```

**Description**
Creates a mask from a rounded rectangle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md) shape | Pointer to the rounded rectangle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) | Pointer to the render node mask.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCircleShape()

```
ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCircleShape(ArkUI_CircleShapeOption* shape)
```

**Description**
Creates a mask from a circle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md) shape | Pointer to the circle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) | Pointer to the render node mask.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromOvalShape()

```
ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromOvalShape(ArkUI_RectShapeOption* shape)
```

**Description**
Creates a mask from an oval shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md) shape | Pointer to the oval shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) | Pointer to the render node mask.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCommandPath()

```
ArkUI_RenderNodeMaskOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeMaskOptionFromCommandPath(ArkUI_CommandPathOption* path)
```

**Description**
Creates a mask from a custom drawing path.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md) path | Pointer to the custom drawing path option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) | Pointer to the render node mask.

### OH_ArkUI_RenderNodeUtils_DisposeRenderNodeMaskOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeRenderNodeMaskOption(ArkUI_RenderNodeMaskOption* option)
```

**Description**
Disposes the render node mask option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md) option | Pointer to the render node mask.|

### OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionFillColor()

```
void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionFillColor(ArkUI_RenderNodeMaskOption* mask, uint32_t fillColor)
```

**Description**
Sets the fill color for the render node mask option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md)* mask | Pointer to the render node mask.|
| uint32_t fillColor | Fill color of the mask.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeColor()

```
void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeColor(ArkUI_RenderNodeMaskOption* mask, uint32_t strokeColor)
```

**Description**
Sets the stroke color for the render node mask option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md)* mask | Pointer to the render node mask.|
| uint32_t strokeColor | Stroke color of the mask.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeWidth()

```
void OH_ArkUI_RenderNodeUtils_SetRenderNodeMaskOptionStrokeWidth(ArkUI_RenderNodeMaskOption* mask, float strokeWidth)
```

**Description**
Sets the stroke width for the render node mask option. Drawing with the corresponding width is performed centered on the border path.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeMaskOption](./capi-arkui-nativemodule-arkui-rendernodemaskoption.md)* mask | Pointer to the render node mask.|
| float strokeWidth | Stroke width of the mask.<br>Value range: (0, +∞). If the value is a negative number or 0, the stroke width is set to 1 pixel during drawing.|

**Return value**
| Type| Description|
| -- | -- |
| int32_t | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.<br>         Returns [ARKUI_ERROR_CODE_CAPI_INIT_ERROR](capi-native-type-h.md#arkui_errorcode) if C API initialization failed.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRectShape()

```
ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRectShape(ArkUI_RectShapeOption* shape)
```

**Description**
Creates a render node clip option from a rectangle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)* shape | Pointer to the rectangle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* | Pointer to the render node clip.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRoundRectShape()

```
ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromRoundRectShape(ArkUI_RoundRectShapeOption* shape)
```

**Description**
Creates a render node clip option from a rounded rectangle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RoundRectShapeOption](./capi-arkui-nativemodule-arkui-roundrectshapeoption.md)* shape | Pointer to the rounded rectangle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* | Pointer to the render node clip.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCircleShape()

```
ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCircleShape(ArkUI_CircleShapeOption* shape)
```

**Description**
Creates a render node clip option from a circle shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CircleShapeOption](./capi-arkui-nativemodule-arkui-circleshapeoption.md)* shape | Pointer to the circle shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* | Pointer to the render node clip.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromOvalShape()

```
ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromOvalShape(ArkUI_RectShapeOption* shape)
```

**Description**
Creates a render node clip option from an oval shape.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RectShapeOption](./capi-arkui-nativemodule-arkui-rectshapeoption.md)* shape | Pointer to the oval shape option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* | Pointer to the render node clip.

### OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCommandPath()

```
ArkUI_RenderNodeClipOption* OH_ArkUI_RenderNodeUtils_CreateRenderNodeClipOptionFromCommandPath(ArkUI_CommandPathOption* path)
```

**Description**
Creates a render node clip option from a custom drawing path.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_CommandPathOption](./capi-arkui-nativemodule-arkui-commandpathoption.md)* path | Pointer to the custom drawing path option.|

**Return value**
| Type| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* | Pointer to the render node clip.

### OH_ArkUI_RenderNodeUtils_DisposeRenderNodeClipOption()

```
void OH_ArkUI_RenderNodeUtils_DisposeRenderNodeClipOption(ArkUI_RenderNodeClipOption* option)
```

**Description**
Disposes the render node clip option.

**Since**: 20

**Parameters**
| Name| Description|
| -- | -- |
| [ArkUI_RenderNodeClipOption](./capi-arkui-nativemodule-arkui-rendernodeclipoption.md)* option | Pointer to the render node clip.|
<!--no_check-->