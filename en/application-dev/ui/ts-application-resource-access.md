# Accessing Application Resources<a name="EN-US_TOPIC_0000001181883223"></a>

## Resource Definition<a name="section141821629195413"></a>

Application resources are defined by in the project's  **resources**  directory, which is organized as follows:

-   Level-1:  **base**  sub-directory, qualifiers sub-directories, and  **rawfile**  sub-directory
    -   The  **base**  sub-directory is a default directory. If no qualifiers sub-directories in the  **resources**  directory of the application match the device status, the resource file in the  **base**  sub-directory will be automatically referenced.
    -   You need to create qualifiers sub-directories on your own. The name of a qualifiers sub-directory consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the mobile country code \(MCC\), mobile network code \(MNC\), language, script, country or region, screen orientation, device type, color mode, and screen density. The qualifiers are separated using underscores \(\_\) or hyphens \(-\).
    -   When the resources in the  **rawfile**  sub-directory are referenced, resource files will not be matched based on the device status. You can directly store resource files in the  **rawfile**  sub-directory.

-   Level-2: resource sub-directories
    -   Resource sub-directories store basic elements such as character strings, colors, and floating point numbers, and resource files such as media files.
    -   Supported files and resource types are listed in the table below:

        <a name="table53961740178"></a>
        <table><thead align="left"><tr id="row739634012720"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p143974401277"><a name="p143974401277"></a><a name="p143974401277"></a>File Name</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p103976401277"><a name="p103976401277"></a><a name="p103976401277"></a>Resource Type</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row1739794010715"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33978409717"><a name="p33978409717"></a><a name="p33978409717"></a>color.json</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p153975401772"><a name="p153975401772"></a><a name="p153975401772"></a>Color resource.</p>
        </td>
        </tr>
        <tr id="row173971140175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p839719401717"><a name="p839719401717"></a><a name="p839719401717"></a>float.json</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339713405710"><a name="p339713405710"></a><a name="p339713405710"></a>Resources such as spacing, rounded corners, and fonts.</p>
        </td>
        </tr>
        <tr id="row19397194011717"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6397124013714"><a name="p6397124013714"></a><a name="p6397124013714"></a>string.json</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339819401577"><a name="p339819401577"></a><a name="p339819401577"></a>String resource.</p>
        </td>
        </tr>
        <tr id="row5990342889"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899219427811"><a name="p899219427811"></a><a name="p899219427811"></a>plural.json</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799214425811"><a name="p799214425811"></a><a name="p799214425811"></a>String resource.</p>
        </td>
        </tr>
        <tr id="row59657261599"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896710269917"><a name="p896710269917"></a><a name="p896710269917"></a>media directory</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396772617914"><a name="p1396772617914"></a><a name="p1396772617914"></a>Image resource.</p>
        </td>
        </tr>
        </tbody>
        </table>



## Referencing Resources<a name="section1077218431548"></a>

To reference an application resource in a project, use the  **"$r\('app.type.name'\)"**  format.  **app**  indicates the resource defined in the  **resources**  directory of the application.  **type**  indicates the resource type \(or the location where the resource is stored\). The value can be  **color**,  **float**,  **string**,  **plural**, or  **media**.  **name**  indicates the resource name, which you set when defining the resource.

When referencing resources in the  **rawfile**  sub-directory, use the  **"$rawfile\('filename'\)"**  format. Currently,  **$rawfile**  allows only the  **<Image\>**  component to reference image resources. In the format,  **filename**  indicates the relative path of a file in the  **rawfile**  directory, and the file name must contain the file name extension. Note that the relative path cannot start with a slash \(/\).

## Example<a name="section1997322145516"></a>

Some custom resources in the  **base**  sub-directory are as follows:

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

The content of the  **color.json**  file is as follows:

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

The content of the  **float.json**  file is as follows:

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

The content of the  **string.json**  file is as follows:

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

The content of the  **plural.json**  file is as follows:

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

In the  **ets**  file, you can use the resources defined in the  **resources**  directory.

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

Text($r('app.plural.eat_apple', 5, 5)) // Reference plural resources. The first parameter specifies the plural resource, and the second parameter specifies the number of plural resources. The third number indicates the substitute of %d.
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Image($r(?app.media.my_background_image creation)) // Reference media resources.

Image($rawfile( Femaletest.png loaded)) // Reference an image in the rawfile directory.

Image($rawfile(newDir/newTest.png loaded)) // Reference an image in the rawfile directory.
```

