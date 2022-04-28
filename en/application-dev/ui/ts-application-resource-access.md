# Accessing Application Resources


## Resource Definition

Application resources are defined in the project's **resources** directory, which is organized as follows:

- Level-1: **base** sub-directory, qualifiers sub-directories, and **rawfile** sub-directory
  - The **base** sub-directory is a default directory. If no qualifiers sub-directories in the **resources** directory of the application match the device status, the resource file in the **base** sub-directory will be automatically referenced.
  - You need to create qualifiers sub-directories on your own. The name of a qualifiers sub-directory consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the mobile country code (MCC), mobile network code (MNC), language, script, country or region, screen orientation, device type, color mode, and screen density. The qualifiers are separated using underscores (_) or hyphens (-).
  - When the resources in the **rawfile** sub-directory are referenced, resource files will not be matched based on the device status. You can directly store resource files in the **rawfile** sub-directory.

- Level-2: resource sub-directories
  - Resource sub-directories store basic elements such as character strings, colors, and floating point numbers, and resource files such as media files.
  - Supported files and resource types are listed in the table below.
       | File Name| Resource Type|
     | -------- | -------- |
     | color.json | Color resource.|
     | float.json | Resources such as spacing, rounded corners, and fonts.|
     | string.json | String resource.|
     | plural.json | String resource.|
     | media directory| Image resource.|


## Referencing Resources

To reference an application resource in a project, use the `"$r('app.type.name')"` format. **app** indicates the resource defined in the **resources** directory of the application. **type** indicates the resource type (or the location where the resource is stored). The value can be **color**, **float**, **string**, **plural**, or **media**. **name** indicates the resource name, which you set when defining the resource.

When referencing resources in the **rawfile** sub-directory, use the `"$rawfile('filename')"` format. Currently, **$rawfile** allows only the **\<Image>** component to reference image resources. **filename** indicates the relative path of a file in the **rawfile** directory, and the file name must contain the file name extension. Note that the relative path cannot start with a slash (/).

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> Resource descriptors accept only strings, such as `'app.type.name'`, and cannot be combined.


## Example

Some custom resources in the **base** sub-directory are as follows:


```
    resources
      ├─ base 
      │    ├─ element 
      │    │   ├─ color.json
      │    │   ├─ string.json
      │    │   └─ float.json
      │    └─ media
      │       └─ my_background_image.png
      └─ rawfile
           ├─ test.png
           └─ newDir
               └─ newTest.png  
```

The content of the **color.json** file is as follows:


```
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


```
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


```
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


```
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

  In the **.ets** file, you can use the resources defined in the **resources** directory.

```
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


## Samples

The following sample is provided to help you better understand how to access application resources:

- [`ResourceManager`: eTS Resource Management (API 7)](https://gitee.com/openharmony/app_samples/tree/master/common/ResourceManager)
