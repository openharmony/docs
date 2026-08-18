# Using Theme Fonts (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=8e9d3b746529fedba672cd46a96d4746984bcb6c translatedAt=2026-08-15T01:52:03.567Z pushedAt=2026-08-15T08:36:22.302Z -->

## Overview

Theme fonts are specialized custom fonts available for use in theme applications. You can enable them using specific APIs.

## Implementation Mechanism

**Figure 1** Switching and using theme fonts

![themeText_native](figures/themeText_native.jpg)

When switching and using theme fonts, the application must subscribe to theme font change events. After receiving such an event, it must call the page refresh API to switch the theme font. Without this step, the new theme font will apply only after the application is restarted. To draw text with a theme font, use **OH_Drawing_GetFontCollectionGlobalInstance** to obtain the global font collection object, which contains theme font information.

> **NOTE**
>
> You cannot use **OH_Drawing_CreateSharedFontCollection** to draw text with a theme font because this API returns a font collection object that does not contain any theme font information.

## Available APIs

The following table lists the APIs for registering and using theme fonts. For details, see [Drawing](../reference/apis-arkgraphics2d/capi-drawing.md).

| Name| Description|
| -------- | -------- |
| OH_Drawing_FontCollection\* OH_Drawing_GetFontCollectionGlobalInstance(void) | Obtains an **OH_Drawing_FontCollection** object.|
| [onConfigurationUpdate(newConfig: Configuration): void](../reference/apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) | Called when system configuration is updated.<br/>Currently, theme applications provide only an ArkTS API to publish change events. Therefore, cross-language invocation is required for your app. |

## How to Develop

1. Make sure that you can apply a theme font in the theme applications on your device.

2. Override the **onConfigurationUpdate** function in the application entry file (**EntryAbility.ets** in the default project) to respond to **fontId** changes, adapt to theme font switching, and refresh pages. For details, see [Using Theme Fonts (ArkTS)](./theme-font-arkts.md#how-to-develop).

   When the system configuration information (**newConfig** in the example) changes, the **onConfigurationUpdate** function is triggered. The application can obtain the **fontId** from the configuration information sent by the system and determine whether the **fontId** is the same as that saved locally to identify the theme font switching. If they are different, update the local **fontId** and call the C++ code to update the typography result. The call path from ArkTS to C++ requires the application to select the appropriate calling method based on actual scenarios, and no recommendation is provided in this example. For details about cross-language calling, see [Node-API Overview](../napi/napi-introduction.md).

3. Import the C++ dependencies. This step and subsequent steps describe the usage of theme fonts on the C++ side.

   Add the following library to the `src/main/cpp/CMakeLists.txt` file of the project.

   ```c++
   libnative_drawing.so
   ```

   Include header files.

   <!-- @[theme_font_c_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_register_font.h>
   ```

4. Create a font manager.

   > **NOTE**
   >
   > Theme fonts are registered on the global font collection object. Therefore, you must use **OH_Drawing_GetFontCollectionGlobalInstance** to obtain the global font collection object for drawing. If you use **OH_Drawing_CreateSharedFontCollection** or **OH_Drawing_CreateFontCollection** to create a font collection object, theme fonts cannot be applied. The global font collection obtained through **OH_Drawing_GetFontCollectionGlobalInstance** must not be released by the developer; otherwise, font rendering may become disordered.

   <!-- @[theme_font_c_draw_text_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   OH_Drawing_FontCollection *fontCollection = OH_Drawing_GetFontCollectionGlobalInstance();
   ```

5. **OH_Drawing_SetTextStyleFontFamilies()** can be used to specify the font family name for implementing the specified font. However, to use a theme font, do not call **OH_Drawing_SetTextStyleFontFamilies()** to avoid using the specified font instead of the theme font.

   <!-- @[theme_font_c_draw_text_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   OH_Drawing_TextStyle *myTextStyle = OH_Drawing_CreateTextStyle();
   ```

6. Set the paragraph text content to "Hello World. \nThis is the theme font." In this case, the theme font is used for the paragraph text.

   <!-- @[theme_font_c_draw_text_step3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Set other text styles.
   OH_Drawing_SetTextStyleColor(myTextStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   // Set the font size to 100.0.
   OH_Drawing_SetTextStyleFontSize(myTextStyle, 100.0);
   // Create a paragraph style object to set the typography style.
   OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
   OH_Drawing_SetTypographyTextAlign(typographyStyle, TEXT_ALIGN_LEFT); // Set the typography to left alignment.
   // Create a paragraph generator.
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // Set the text style in the paragraph generator.
   OH_Drawing_TypographyHandlerPushTextStyle(handler, myTextStyle);
   // Set the text content in the paragraph generator.
   const char *text = "Hello World. \nThis is the theme font.";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // Generate a paragraph using the paragraph generator.
   OH_Drawing_Typography *typography = OH_Drawing_CreateTypography(handler);
   ```

## Effect

The following figures show how text is rendered with different theme fonts in a theme application.

The following figures are for reference only.

**Figure 2** Effect of theme font 1

![themeFont_native_01](figures/NdkThemeFont.PNG)

**Figure 3** Effect of theme font 2

![themeFont_native_02](figures/themeFont_native_02.png)