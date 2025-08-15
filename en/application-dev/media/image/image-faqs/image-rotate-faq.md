# Obtaining the Rotation Angle of an Image
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Introduction to Image Rotation Angles

In digital photography, the shooting device (such as a smartphone or camera) saves the rotation angle (orientation) information of the image in the **Orientation** field of the Exchangeable Image File Format (EXIF) data of the image. The information does not alter the pixel content of the image. It instructs the image viewer how to correctly display the image orientation.

The EXIF standard defines the orientation values, their corresponding string representations, and operational instructions, as listed in the table below.

| Value    | String Representation     | Operational Instructions                       |
|--------|----------------|--------------------------------|
| 1      | "Top-left"     | Normal orientation (no rotation required).          |
| 2      | "Top-right"    | Horizontal mirror flip.                  |
| 3      | "Bottom-right" | Rotate 180°.                     |
| 4      | "Bottom-left"  | Vertical mirror flip.                  |
| 5      | "Left-top"     | Horizontal mirror flip followed by a clockwise rotation of 270°.|
| 6      | "Right-top"    | Clockwise rotation of 90°.                |
| 7      | "Right-bottom" | Horizontal mirror flip followed by a clockwise rotation of 90°.|
| 8      | "Left-bottom"  | Clockwise rotation of 270°.               |

In ArkTS scenarios, for details about how to read and edit the rotation angle information of an image, see [Editing EXIF Data](../image-tool.md). The corresponding **propertyKey** must be set to **ORIENTATION**.

In C/C++ scenarios, for details about how to read and edit the rotation angle information of an image, see [Using Image_NativeModule to Edit EXIF Data](../image-tool-c.md). The corresponding **key** must be set to **OHOS_IMAGE_PROPERTY_ORIENTATION**.

## FAQs

### What should I do If the image rotation angle is null?

Some images may lack EXIF data or may not have the **Orientation** field written in the EXIF data. These images do not require rotation (consistent with the case where **Orientation** is 1).

### Why EXIF Data might be lost?

This is related to the source of the image. Images transmitted over the network may have been re-encoded without preserving EXIF data. As a result, the rotation angle cannot be obtained.

### How do I save EXIF data during image encoding?

When calling the image encoding API, set **needsPackProperties** of [packingOption](../../../reference/apis-image-kit/arkts-apis-image-i.md#packingoption) to **true**. (The default value is **false**.)
