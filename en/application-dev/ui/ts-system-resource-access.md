# Accessing System Resources


System resources include colors, rounded corners, fonts, spacing, character strings, and images. By using system resources, you can develop different applications with the same visual style.


To reference a system resource, use the "$r('sys.type.resource_id')" format. Wherein: sys indicates a system resource; type indicates the resource type, which can be color, float, string, or media; resource_id indicates the resource ID, which is determined when the system resource is provided. For details about available system resource IDs.

```
Text('Hello')
    .fontColor($r('sys.color.id_color_emphasize'))
    .fontSize($r('sys.float.id_text_size_headline1'))
    .fontFamily($r('sys.string.id_text_font_family_medium'))
    .backgroundColor($r('sys.color.id_color_palette_aux1'))
Image($r('sys.media.ic_app'))
    .border({color: $r('sys.color.id_color_palette_aux1'), radius: $r('sys.float.id_corner_radius_button'), width: 2})
    .margin({top: $r('sys.float.id_elements_margin_horizontal_m'), bottom: $r('sys.float.id_elements_margin_horizontal_l')})
    .height(200)
    .width(300)
```
