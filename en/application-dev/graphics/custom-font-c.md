# Registering and Using Custom Fonts (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=983fa161ee12961fd07ba0428e932a03e0d706d9 translatedAt=2026-08-03T11:18:09.052Z pushedAt=2026-08-04T03:48:42.215Z -->

## Overview

Custom fonts are fonts created or selected by developers based on application requirements. They are usually used to implement specific text styles or fulfill distinct design goals. To render specific text styles and characters, applications can register and use custom fonts.

## Workflow

**Registering custom fonts** is to register font files (such as .ttf and .otf files) from application resources to the system so that applications can use these fonts for text rendering. The registration process is to register font files with the system font library through the font management API so that the font files can be called in the application.

**Using custom fonts** is to explicitly specify registered custom fonts for text drawing in an application. You can select a specific text style (such as regular, bold, and italic) as required and apply it to UI elements, text controls, or other text display areas to meet design requirements and provide consistent visual effect.

## Available APIs

The following table lists the APIs for registering and using custom fonts. For details, see [Drawing](../reference/apis-arkgraphics2d/capi-drawing.md).

| API| Description|
| -------- | -------- |
| OH_Drawing_CreateSharedFontCollection(void) | Creates a shareable font collection object **OH_Drawing_FontCollection**. |
| OH_Drawing_RegisterFont(OH_Drawing_FontCollection\* , const char\* fontFamily, const char\* familySrc ) | Registers a custom font in the font manager. Supported font file formats include ttf and otf. |
| OH_Drawing_CreateTextStyle(void) | Creates a pointer to an **OH_Drawing_TextStyle** object to set the text style.|
| OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle \*, int, const char \*fontFamilies[]) | Sets the font type. |
| OH_Drawing_UnregisterFont(OH_Drawing_FontCollection\* , const char\* fontFamily) | Unregisters a custom font by its font family name. |

## How to Develop

1. Add the following library to the `src/main/cpp/CMakeLists.txt` file of the project.

   ```c++
   libnative_drawing.so
   ```

2. Import the required header files.

   <!-- @[theme_font_c_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_register_font.h>
   ```

3. Create a font manager. You are advised to use **OH_Drawing_CreateSharedFontCollection()** to create a sharable font set object.

   > **NOTE**
   >
   > **OH_Drawing_CreateFontCollection()** and **OH_Drawing_CreateSharedFontCollection()** both create an **OH_Drawing_FontCollection** object. However, **OH_Drawing_CreateFontCollection** creates font set pointers that cannot be shared across **OH_Drawing_TypographyCreate** objects. Therefore, you are advised to use **OH_Drawing_CreateSharedFontCollection** to create a sharable font set object.

   <!-- @[custom_font_c_custom_font_text_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   OH_Drawing_FontCollection *fontCollection = OH_Drawing_CreateSharedFontCollection();
   ```

4. Set the font family name and sandbox path of the custom font file.

   > **NOTE**
   >
   > Ensure that the available custom font file to be registered is correctly placed in the **/system/fonts/NotoSerifTamil[wdth,wght].ttf** directory of the application device.

   <!-- @[custom_font_c_custom_font_text_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // The font family name is required when the custom font is used.
   const char* fontFamily = "myFamilyName"; 
   // This path is the path of the custom font file to be registered on the application device. Ensure that the custom font file is properly placed in this path.
   const char* fontPath = "/system/fonts/NotoSerifTamil[wdth,wght].ttf"; 
   ```

5. Register the custom font with the font manager by calling **OH_Drawing_RegisterFont()**.

   You can check the return result of the API to determine whether the registration is successful.

   The return results of **OH_Drawing_RegisterFont** are as follows:

   **0**: The registration is successful. **1**: The file does not exist. **2**: Failed to open the file. **3**: Failed to read the file. **4**: Failed to find the file. **5**: Failed to obtain the file size. **9**: The file is damaged.

   <!-- @[custom_font_c_custom_font_text_step3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   int errorCode = OH_Drawing_RegisterFont(fontCollection, fontFamily, fontPath);
   ```

6. After the custom font is successfully registered, call **OH_Drawing_CreateTextStyle()** to create a text style object and call **OH_Drawing_SetTextStyleFontFamilies()** to add the custom font.

   <!-- @[custom_font_c_custom_font_text_step4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // If the custom font has been successfully registered, enter the font family name of the custom font.
   const char* myFontFamilies[] = {"myFamilyName"}; 
   // Add the available custom font.
   OH_Drawing_SetTextStyleFontFamilies(textStyle, 1, myFontFamilies);
   ```

7. Generate the final paragraph to implement text drawing and display using the custom font.

   <!-- @[custom_font_c_custom_font_text_step5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Set other text styles.
   OH_Drawing_SetTextStyleColor(textStyle , OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   // Set the font size to 60.0.
   OH_Drawing_SetTextStyleFontSize(textStyle, 60.0);
   // Create a paragraph style object to set the typography style.
   OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
   OH_Drawing_SetTypographyTextAlign(typographyStyle, TEXT_ALIGN_LEFT); // Set the typography to left alignment.
   // Create a paragraph generator.
   OH_Drawing_TypographyCreate* handler = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // Set the text style in the paragraph generator.
   OH_Drawing_TypographyHandlerPushTextStyle(handler, textStyle);
   // Set the text content in the paragraph generator.
   const char* text = "Hello, this text uses the custom font.";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // Generate a paragraph using the paragraph generator.
   OH_Drawing_Typography* typography = OH_Drawing_CreateTypography(handler);
   // Set the maximum width.
   double maxWidth = width_;
   OH_Drawing_TypographyLayout(typography, maxWidth);
   // Draw the text on the canvas (0,100).
   OH_Drawing_TypographyPaint(typography, cCanvas_, 0, 100);
   ```

8. To release a custom font, call the **OH_Drawing_UnregisterFont** API.

   <!-- @[custom_font_c_custom_font_text_step6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Unregister the custom font.
   OH_Drawing_UnregisterFont(fontCollection, fontFamily);
   OH_Drawing_TypographyCreate* handler1 = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // Set the text style in the paragraph generator.
   OH_Drawing_TypographyHandlerPushTextStyle(handler1, textStyle);
   // Set the text content in the paragraph generator.
   const char* text1 = "Hello, the custom font of this text is unregistered.";
   OH_Drawing_TypographyHandlerAddText(handler1, text1);
   // Generate a paragraph using the paragraph generator.
   OH_Drawing_Typography* typography1 = OH_Drawing_CreateTypography(handler1);
   OH_Drawing_TypographyLayout(typography1, maxWidth);
   // Draw the text on the canvas (0, 300).
   OH_Drawing_TypographyPaint(typography1, cCanvas_, 0, 300);
   ```