# Resource Categories and Access

## Resource Categories

Resource files used during application development must be stored in specified directories for management.

### resources Directory

The **resources** directory consists of three types of sub-directories: the **base** sub-directory, qualifiers sub-directories, and the **rawfile** sub-directory. The common resource files used across projects in the stage model are stored in the **resources** directory under **AppScope**.

  Example of the **resources** directory:

```
resources
|---base  // Default directory
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---en_GB-vertical-car-mdpi // Example of a qualifiers sub-directory, which needs to be created on your own  
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---rawfile
```

**Table 1** Classification of the resources directory

| Category  | base Sub-directory                          | Qualifiers Sub-directory                                   | rawfile Sub-directory                               |
| ---- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| Structure| The **base** sub-directory is a default directory. If no qualifiers sub-directories in the **resources** directory of the application match the device status, the resource file in the **base** sub-directory will be automatically referenced.<br>Resource group sub-directories are located at the second level of sub-directories to store basic elements such as strings, colors, and boolean values, as well as resource files such as media, animations, and layouts. For details, see [Resource Group Sub-directories](#resource-group-sub-directories).| You need to create qualifiers sub-directories on your own. Each directory name consists of one or more qualifiers that represent the application scenarios or device characteristics. For details, see [Qualifiers Sub-directories](#qualifiers-sub-directories).<br>Resource group sub-directories are located at the second level of sub-directories to store basic elements such as strings, colors, and boolean values, as well as resource files such as media, animations, and layouts. For details, see [Resource Group Sub-directories](#resource-group-sub-directories). | You can create multiple levels of sub-directories with custom directory names. They can be used to store various resource files.<br>However, resource files in the **rawfile** sub-directory will not be matched based on the device status.|
| Compilation| Resource files in the sub-directory are compiled into binary files, and each resource file is assigned an ID.           | Resource files in the sub-directory are compiled into binary files, and each resource file is assigned an ID.           | Resource files in the sub-directory are directly packed into the application without being compiled, and no IDs will be assigned to the resource files.   |
| Reference| Resource files in the sub-directory are referenced based on the resource type and resource name.           | Resource files in the sub-directory are referenced based on the resource type and resource name.           | Resource files in the sub-directory are referenced based on the file path and file name.                        |


### Qualifiers Sub-directories

The name of a qualifiers sub-directory consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the mobile country code (MCC), mobile network code (MNC), language, script, country or region, screen orientation, device type, night mode, and screen density. The qualifiers are separated using underscores (\_) or hyphens (\-). Before creating a qualifiers sub-directory, familiarize yourself with the directory naming conventions and the rules for matching qualifiers sub-directories and the device status.

**Naming Conventions for Qualifiers Sub-directories**

- Qualifiers are ordered in the following sequence: **\_MCC_MNC-language_script_country/region-orientation-device-color mode-density**. You can select one or multiple qualifiers to name your sub-directory based on your application scenarios and device characteristics.

- Separation between qualifiers: The language, script, and country/region qualifiers are separated using underscores (\_); the MNC and MCC qualifiers are also separated using underscores (\_); other qualifiers are separated using hyphens (\-). For example, **zh_Hant_CN** and **zh_CN-car-ldpi**.

- Value range of qualifiers: The value of each qualifier must meet the requirements specified in the following table. Otherwise, the resource files in the resources directory cannot be matched.

**Table 2** Requirements for qualifier values

| Qualifier Type      | Description and Value Range                                 |
| ----------- | ---------------------------------------- |
| MCC&MNC| Indicates the MCC and MNC, which are obtained from the network where the device is registered. The MCC can be either followed by the MNC with an underscore (\_) in between or be used independently. For example, **mcc460** indicates China, and **mcc460\_mnc00** indicates China\_China Mobile.<br>For details about the value range, refer to **ITU-T E.212** (the international identification plan for public networks and subscriptions).|
| Language         | Indicates the language used by the device. The value consists of two or three lowercase letters. For example, **zh** indicates Chinese, **en** indicates English, and **mai** indicates Maithili.<br>For details about the value range, refer to **ISO 639** (codes for the representation of names of languages).|
| Text         | Indicates the script type used by the device. The value starts with one uppercase letter followed by three lowercase letters. For example, **Hans** indicates simplified Chinese, and **Hant** indicates traditional Chinese.<br>For details about the value range, refer to **ISO 15924** (codes for the representation of names of scripts).|
| Country/Region      | Indicates the country or region where the user is located. The value consists of two or three uppercase letters or three digits. For example, **CN** indicates China, and **GB** indicates the United Kingdom.<br>For details about the value range, refer to **ISO 3166-1** (codes for the representation of names of countries and their subdivisions).|
| Screen orientation        | Indicates the screen orientation of the device. The value can be:<br>- **vertical**: portrait orientation<br>- **horizontal**: landscape orientation|
| Device type       | Indicates the device type. The value can be:<br>- **car**: head unit<br>- **tv**: smart TV<br>- **wearable**: smart wearable|
| Color mode       | Indicates the color mode of the device. The value can be:<br>- **dark**: dark mode<br>- **light**: light mode|
| Screen density       | Indicates the screen density of the device, in dpi. The value can be:<br>- **sdpi**: screen density with small-scale dots per inch (SDPI). This value is applicable for devices with a DPI range of (0, 120].<br>- **mdpi**: medium-scale screen density (Medium-scale Dots Per Inch), applicable to DPI whose value is (120,  160] device.<br>- **ldpi**: screen density with large-scale dots per inch (LDPI). This value is applicable for devices with a DPI range of (160, 240].<br>- **xldpi**: screen density with extra-large-scale dots per inch (XLDPI). This value is applicable for devices with a DPI range of (240, 320].<br>- **xxldpi**: screen density with extra-extra-large-scale dots per inch (XXLDPI). This value is applicable for devices with a DPI range of (320, 480].<br>- **xxxldpi**: screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI). This value is applicable for devices with a DPI range of (480, 640].|

**Rules for Matching Qualifiers Sub-directories and Device Resources**

- Qualifiers are matched with the device resources in the following priorities: MCC&MNC > locale (options: language, language_script, language_country/region, and language_script_country/region) > screen orientation > device type > color mode > screen density.

- If the qualifiers sub-directories contain the **MCC, MNC, language, script, screen orientation, device type, and color mode** qualifiers, their values must be consistent with the current device status so that the sub-directories can be used for matching the device resources. For example, the qualifiers sub-directory **zh_CN-car-ldpi** cannot be used for matching the resource files labeled **en_US**.


### Resource Group Sub-directories

You can create resource group sub-directories (including element, media, and profile) in the **base** and qualifiers sub-directories to store resource files of specific types.


  **Table 3** Resource group sub-directories

| Resource Group Sub-directory  | Description                                    | Resource File                                    |
| ------- | ---------------------------------------- | ---------------------------------------- |
| element | Indicates element resources. Each type of data is represented by a JSON file. The options are as follows:<br>- **boolean**: boolean data<br>- **color**: color data<br>- **float**: floating-point data<br>- **intarray**: array of integers<br>- **integer**: integer data<br>- **pattern**: pattern data<br>- **plural**: plural form data<br>- **strarray**: array of strings<br>- **string**: string data| It is recommended that files in the **element** sub-directory be named the same as the following files, each of which can contain only data of the same type:<br>- boolean.json<br>- color.json<br>- float.json<br>- intarray.json<br>- integer.json<br>- pattern.json<br>- plural.json<br>- strarray.json<br>- string.json |
| media   | Indicates media resources, including non-text files such as images, audios, and videos.             | The file name can be customized, for example, **icon.png**.                    |
| rawfile | Indicates other types of files, which are stored in their raw formats after the application is built as an HAP file. They will not be integrated into the **resources.index** file.| The file name can be customized.                                |

**Media Resource Types**

**Table 4** Image resource types

| Format  | File Name Extension|
| ---- | ----- |
| JPEG | .jpg  |
| PNG  | .png  |
| GIF  | .gif  |
| SVG  | .svg  |
| WEBP | .webp |
| BMP  | .bmp  |

**Table 5** Audio and video resource types

| Format                                  | File Name Extension        |
| ------------------------------------ | --------------- |
| H.263                                | .3gp <br>.mp4   |
| H.264 AVC <br> Baseline Profile (BP) | .3gp <br>.mp4   |
| MPEG-4 SP                            | .3gp            |
| VP8                                  | .webm <br> .mkv |

**Resource File Examples**

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

## Resource Access

### Application Resources

**Creating a Resource File**

You can create a sub-directory and its files under the **resources** directory based on the preceding descriptions of the qualifiers sub-directories and resource group sub-directories.

DevEco Studio provides a wizard for you to create resource directories and resource files.

- Creating a Resource Directory and Resource File

  Right-click the **resources** directory and choose **New > Resource File**.

  If no qualifier is selected, the file is created in a resource type sub-directory under **base**. If one or more qualifiers are selected, the system automatically generates a sub-directory and creates the file in this sub-directory.

  The created sub-directory is automatically named in the format of **Qualifiers.Resource type**. For example, if you create a sub-directory by setting **Orientation** to **Vertical** and **Resource type** to **Graphic**, the system automatically generates a sub-directory named **vertical.graphic**.

  ![create-resource-file-1](figures/create-resource-file-1.png)

- Creating a Resource Directory

  Right-click the **resources** directory and choose **New > Resource Directory**. This operation creates a sub-directory only.

  Select a resource group type and set qualifiers. Then the system automatically generates the sub-directory name. The sub-directory is automatically named in the format of **Qualifiers.Resource group**. For example, if you create a sub-directory by setting **Orientation** to **Vertical** and **Resource type** to **Graphic**, the system automatically generates a sub-directory named **vertical.graphic**.

  ![create-resource-file-2](figures/create-resource-file-2.png)

- Creating a Resource File

  Right-click a sub-directory under **resources** and choose **New > *XXX* Resource File**. This operation creates a resource file under this sub-directory.

  For example, you can create an element resource file in the **element** sub-directory.

  ![create-resource-file-3](figures/create-resource-file-3.png)

**Accessing Application Resources**

To reference an application resource in a project, use the **"$r('app.type.name')"** format. **app** indicates the resource defined in the **resources** directory of the application. **type** indicates the resource type (or the location where the resource is stored). The value can be **color**, **float**, **string**, **plural**, or **media**. **name** indicates the resource name, which you set when defining the resource.

When referencing resources in the **rawfile** sub-directory, use the **"$rawfile('filename')"** format. Wherein, **filename** indicates the relative path of a file in the **rawfile** directory, which must contain the file name extension in the file name and cannot start with a slash (/).

> **NOTE**
> 
> Resource descriptors accept only strings, such as **'app.type.name'**, and cannot be combined.
>
> The return value of **$r** is a **Resource** object. You can obtain the corresponding string by using the [getStringValue](../reference/apis/js-apis-resource-manager.md) API.

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

Text($r('app.plural.eat_apple', 5, 5))       // Reference plural resources. The first parameter indicates the plural resource, the second parameter indicates the number of plural resources, and the third parameter indicates the substitute of %d.
    .fontColor($r('app.color.color_world'))
    .fontSize($r('app.float.font_world'))
}

Image($r('app.media.my_background_image'))  // Reference media resources.

Image($rawfile('test.png'))                 // Reference an image in the rawfile directory.

Image($rawfile('newDir/newTest.png'))       // Reference an image in the rawfile directory.
```

### System Resources

System resources include colors, rounded corners, fonts, spacing, character strings, and images. By using system resources, you can develop different applications with the same visual style.


To reference a system resource, use the **"$r('sys.type.resource_id')"** format. Wherein: **sys** indicates a system resource; **type** indicates the resource type, which can be **color**, **float**, **string**, or **media**; **resource_id** indicates the resource ID.

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
