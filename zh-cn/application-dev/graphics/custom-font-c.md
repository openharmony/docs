# 自定义字体的注册和使用（C/C++）
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->

## 场景介绍

自定义字体是指开发者根据应用需求创建或选择的字体，通常用于实现特定的文字风格或满足独特的设计要求。当应用需要使用特定的文本样式和字符集时，可以注册并使用自定义字体进行文本渲染。


## 实现流程

**自定义字体的注册**是指将字体文件（如ttf、otf文件等）从应用资源注册到系统中，使得应用能够使用这些字体进行文本渲染。注册过程通常指将字体文件通过字体管理接口注册到系统字体库中，以便在应用中进行调用。

**自定义字体的使用**是指在应用中显式指定使用已注册的自定义字体进行文本绘制。开发者可以根据需要选择特定的文本样式（如常规、粗体、斜体等），并将其应用到UI元素、文本控件或其他文本展示区域，以确保符合设计要求并提供一致的视觉效果。


## 接口说明

注册使用自定义字体的相关接口如下所示，详细接口说明请参考[Drawing](../reference/apis-arkgraphics2d/capi-drawing.md)。

| 接口名 | 描述 | 
| -------- | -------- |
| OH_Drawing_CreateSharedFontCollection(void) | 创建可共享的字体集对象OH_Drawing_FontCollection。 | 
| OH_Drawing_RegisterFont(OH_Drawing_FontCollection\* fontCollection, const char\* fontFamily, const char\* familySrc) | 用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。 | 
| OH_Drawing_CreateTextStyle(void) | 创建指向OH_Drawing_TextStyle对象的指针，用于设置文本样式。 | 
| OH_Drawing_SetTextStyleFontFamilies(OH_Drawing_TextStyle\* style, int fontFamiliesNumber, const char \*fontFamilies[]) | 设置指定文本样式的字体家族类型。 | 
| OH_Drawing_UnregisterFont(OH_Drawing_FontCollection\* fontCollection, const char\* fontFamily) | 通过字体家族名称取消注册自定义字体。 | 

## 开发步骤
1. 在工程的`src/main/cpp/CMakeLists.txt`文件中添加以下lib。
   ```c++
   libnative_drawing.so
   ```

2. 导入依赖的相关头文件。

   <!-- @[theme_font_c_header](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_register_font.h>
   ```

3. 创建字体管理器，建议优先使用OH_Drawing_CreateSharedFontCollection()创建可共享的字体集对象。

   > **说明：**
   >
   > 使用OH_Drawing_CreateFontCollection()和OH_Drawing_CreateSharedFontCollection()均可创建字体管理器OH_Drawing_FontCollection对象，但前者创建的字体集指针对象只能被一个段落生成器OH_Drawing_TypographyCreate对象使用，无法被多个段落生成器OH_Drawing_TypographyCreate对象共享使用。如需在多个段落生成器OH_Drawing_TypographyCreate对象间共享使用，请使用后者创建可共享的字体集对象。

   <!-- @[custom_font_c_custom_font_text_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   OH_Drawing_FontCollection *fontCollection = OH_Drawing_CreateSharedFontCollection();
   ```

4. 设置自定义字体的字体家族名和字体文件所在的沙箱路径。

   > **说明：**
   >
   > 确保需注册的可用自定义字体文件已正确放置在应用设备的/system/fonts/NotoSerifTamil[wdth,wght].ttf路径下。

   <!-- @[custom_font_c_custom_font_text_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 后续使用自定义字体时，需使用到该字体家族名
   const char* fontFamily = "myFamilyName"; 
   // 该路径是待注册的自定义字体文件在应用设备下的路径，确保该自定义字体文件已正确放置在该路径下
   const char* fontPath = "/system/fonts/NotoSerifTamil[wdth,wght].ttf"; 
   ```

5. 在字体管理器中使用OH_Drawing_RegisterFont()注册自定义字体。

   可通过接口返回结果，查看具体情况，确认注册成功与否。

   OH_Drawing_RegisterFont接口返回结果的几种情况及含义如下所示：

   0表示注册成功，1表示文件不存在，2表示打开文件失败，3表示读取文件失败，4表示寻找文件失败，5表示获取大小失败，9表示文件损坏。

   <!-- @[custom_font_c_custom_font_text_step3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   int errorCode = OH_Drawing_RegisterFont(fontCollection, fontFamily, fontPath);
   ```

6. 确保自定义字体注册成功后，使用OH_Drawing_CreateTextStyle()接口创建文本样式对象，并使用OH_Drawing_SetTextStyleFontFamilies()接口加入自定义字体。

   <!-- @[custom_font_c_custom_font_text_step4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 如果已经注册成功自定义字体，填入自定义字体的字体家族名
   const char* myFontFamilies[] = {"myFamilyName"}; 
   // 加入可使用的自定义字体
   OH_Drawing_SetTextStyleFontFamilies(textStyle, 1, myFontFamilies);
   ```

7. 生成最终段落文本，使用自定义字体，以便实现最终的文本绘制和显示。

   <!-- @[custom_font_c_custom_font_text_step5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 设置其他文本样式
   OH_Drawing_SetTextStyleColor(textStyle , OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   // 设置字体大小为60.0
   OH_Drawing_SetTextStyleFontSize(textStyle, 60.0);
   // 创建一个段落样式对象，以设置排版风格
   OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
   OH_Drawing_SetTypographyTextAlign(typographyStyle, TEXT_ALIGN_LEFT); // 设置段落样式为左对齐
   // 创建一个段落生成器
   OH_Drawing_TypographyCreate* handler = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // 在段落生成器中设置文本样式
   OH_Drawing_TypographyHandlerPushTextStyle(handler, textStyle);
   // 在段落生成器中设置文本内容
   const char* text = "hello, 这段文字使用了自定义字体";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // 通过段落生成器生成段落
   OH_Drawing_Typography* typography = OH_Drawing_CreateTypography(handler);
   // 设置页面最大宽度
   double maxWidth = width_;
   OH_Drawing_TypographyLayout(typography, maxWidth);
   // 将文本绘制到画布(0,100)上
   OH_Drawing_TypographyPaint(typography, cCanvas_, 0, 100);
   ```

8. 如果需要释放自定义字体，可以使用OH_Drawing_UnregisterFont接口。

   <!-- @[custom_font_c_custom_font_text_step6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKThemFontAndCustomFontText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 注销对应的自定义字体
   OH_Drawing_UnregisterFont(fontCollection, fontFamily);
   OH_Drawing_TypographyCreate* handler1 = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // 在段落生成器中设置文本样式
   OH_Drawing_TypographyHandlerPushTextStyle(handler1, textStyle);
   // 在段落生成器中设置文本内容
   const char* text1 = "hello, 这段文本的自定义字体被注销了";
   OH_Drawing_TypographyHandlerAddText(handler1, text1);
   // 通过段落生成器生成段落
   OH_Drawing_Typography* typography1 = OH_Drawing_CreateTypography(handler1);
   OH_Drawing_TypographyLayout(typography1, maxWidth);
   // 将文本绘制到画布(0,300)上
   OH_Drawing_TypographyPaint(typography1, cCanvas_, 0, 300);
   ```