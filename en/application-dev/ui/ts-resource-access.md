# Resource Access


## Accessing Application Resources

To reference an application resource in a project, use the `"$r('app.type.name')"` format. **app** indicates the resource defined in the **resources** directory of the application. **type** indicates the resource type (or the location where the resource is stored). The value can be **color**, **float**, **string**, **plural**, or **media**. **name** indicates the resource name, which you set when defining the resource.

When referencing resources in the **rawfile** sub-directory, use the ```"$rawfile('filename')"``` format. Currently, **$rawfile** allows only the **\<Image>** component to reference image resources. **filename** indicates the relative path of a file in the **rawfile** directory, and the file name must contain the file name extension. Note that the relative path cannot start with a slash (/).

> **NOTE**
>
> Resource descriptors accept only strings, such as `'app.type.name'`, and cannot be combined.
>
>  `$r` returns a **Resource** object. To obtain the corresponding string, use [getString](../reference/apis/js-apis-resource-manager.md#getstring). 

  In the **.ets** file, you can use the resources defined in the **resources** directory.

```ts
Text($r('app.string.string_hello'))
    .fontColor($r('app.color.color_hello'))
    .fontSize($r('app.float.font_hello'))
}

Text($r('app.string.string_world'))
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Text($r('app.string.message_arrive', "five of the clock")) // Reference string resources. The second parameter of $r is used to replace %s.
    .fontColor($r('app.color.color_hello'))
    .fontSize($r('app.float.font_hello'))
}

Text($r('app.plural.eat_apple', 5, 5)) // Reference plural resources. The first parameter indicates the plural resource, and the second parameter indicates the number of plural resources. The third parameter indicates the substitute of %d.
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Image($r('app.media.my_background_image')) // Reference media resources.

Image($rawfile('test.png')) // Reference an image in the rawfile directory.

Image($rawfile('newDir/newTest.png')) // Reference an image in the rawfile directory.
```


## Accessing System Resources


System resources include colors, rounded corners, fonts, spacing, character strings, and images. By using system resources, you can develop different applications with the same visual style.


To reference a system resource, use the ```"$r('sys.type.resource_id')"``` format. Wherein: **sys** indicates a system resource; **type** indicates the resource type, which can be **color**, **float**, **string**, or **media**; **resource_id** indicates the resource ID.

```ts
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
## Resource File Examples

The content of the **color.json** file is as follows:


```json
{
    "color": [
        {
            "name": "color_hello",
            "value": "#ffff0000"
        },
        {
            "name": "color_world",
            "value": "#ff0000ff"
        }
    ]
}
```

The content of the **float.json** file is as follows:


```json
{
    "float":[
        {
            "name":"font_hello",
            "value":"28.0fp"
        },
	{
            "name":"font_world",
            "value":"20.0fp"
        }
    ]
}
```

The content of the **string.json** file is as follows:


```json
{
    "string":[
        {
            "name":"string_hello",
            "value":"Hello"
        },
	{
            "name":"string_world",
            "value":"World"
        },
	{
            "name":"message_arrive",
            "value":"We will arrive at %s."
        }
    ]
}
```

The content of the **plural.json** file is as follows:


```json
{
    "plural":[
        {
            "name":"eat_apple",
            "value":[
                {
                    "quantity":"one",
                    "value":"%d apple"
                },
                {
                    "quantity":"other",
                    "value":"%d apples"
                }
            ]
        }
    ]
}
```
