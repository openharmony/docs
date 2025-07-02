# ImageEffect

## Overview

The ImageEffect module provides the APIs for editing an image.

For details about the development guide and sample, see [Using ImageEffect to Edit Images](../../media/image/image-effect-guidelines.md).

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [image_effect.h](capi-image-effect-h.md) | Declares the APIs related to an image effector.<br>You can use the APIs to add, delete, and query image effect filters. You can connect multiple filters in series to implement complex effect adjustment.<br>The effector supports multiple input types, such as PixelMap, URI, surface, and picture. Different input types are converted into buffer objects in the effector, and effect processing is implemented through the filters.|
| [image_effect_errors.h](capi-image-effect-errors-h.md) | Declares the error codes used by the image effector.|
| [image_effect_filter.h](capi-image-effect-filter-h.md) | Declares the APIs related to an image effect filter.<br>With these APIs, you can quickly implement basic effect processing or connect multiple filters in series in an image effector to implement complex effect processing. The system provides basic effect processing filters such as brightness and crop filters.|
