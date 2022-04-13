# 访问系统资源


系统资源包含色彩、圆角、字体、间距、字符串及图片等。通过使用系统资源，不同的开发者可以开发出具有相同视觉风格的应用。


开发者可以通过```“$r('sys.type.resource_id')”```的形式引用系统资源。sys代表是系统资源；type代表资源类型，可以取“color”、“float”、“string”、“media”；resource_id代表资源id。

```
Text('Hello')
    .fontColor($r('sys.color.ohos_id_color_emphasize'))
    .fontSize($r('sys.float.ohos_id_text_size_headline1'))
    .fontFamily($r('sys.string.ohos_id_text_font_family_medium'))
    .backgroundColor($r('sys.color.ohos_id_color_palette_aux1'))
Image($r('sys.media.ohos_app_icon'))
    .border({color: $r('sys.color.ohos_id_color_palette_aux1'), radius: $r('sys.float.ohos_id_corner_radius_button'), width: 2})
    .margin({top: $r('sys.float.ohos_id_elements_margin_horizontal_m'), bottom: $r('sys.float.ohos_id_elements_margin_horizontal_l')})
    .height(200)
    .width(300)
```
