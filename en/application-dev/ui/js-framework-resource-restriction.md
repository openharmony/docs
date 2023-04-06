# Resource Limitations and Access


## Resource Qualifiers

The name of a resource qualifier consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the screen density, and more. The qualifiers are separated using hyphens (-). When creating a qualifiers file under resources, you need to understand the file naming conventions and the rules for matching qualifiers files and the device status.


## Naming Conventions for Resource Qualifiers

- Qualifiers are ordered in the following sequence: screen density. You can select one or multiple qualifiers to name your file based on your application scenarios and device characteristics, while following the preceding sequence. 

- The qualifiers are separated using hyphens (-), for example, res-dark-ldpi.json.

- Value range of qualifiers: The value of each qualifier must meet the requirements specified in the following table. Otherwise, the resource files in the resources directory cannot be matched. The qualifiers are case sensitive.

- Qualifier prefix: The name of a qualifier file in the resources file has the prefix res, for example, res-ldpi.json.

- Default resource qualifier file: By default, the resource qualifier file in resources is res-defaults.json.

- In the resource qualifier file, color enumeration cannot be used to set resources.


**Table 1** Resource qualifiers

| Data Type | Description and Value Range |
| -------- | -------- |
| Screen density | Indicates the screen density of the device, in dpi. The value can be:<br/>- ldpi: low-density screen (\~120 dpi) (0.75 x Reference density)<br/>- mdpi: medium-density screen (\~160 dpi) (reference density)<br/>- hdpi: high-density screen (\~240 dpi) (1.5 x Reference density)<br/>- xhdpi: extra high-density screen (\~320 dpi) (2.0 x Reference density)<br/>- xxhdpi: extra extra high-density screen (\~480 dpi) (3.0 x Reference density)<br/>- xxxhdpi: extra extra extra high-density screen (\~640 dpi) (4.0 x Reference density) |


## Rules for Matching Qualifiers Files and Device Resources

- Qualifiers are matched with the device resources in the following priorities: screen orientation > dark mode > screen density. If no matching resource qualifier file is found, the default resource qualifier file is used.

- If a qualifier file contains resource qualifiers, their values must be consistent with the current device status so that the file can be used for matching the device status. For example, the res-hdpi.json qualifier file does not match the device density xhdpi.


## Referencing Resources in the JS Module

You can use the $r syntax in the application development files .hml and .js to format the JSON resources in the resources directory of the JS module and obtain the corresponding resources.

| Attribute | Type | Description |
| -------- | -------- | -------- |
| $r | (key: string) => string | Obtains the resource content that matches the specific qualifiers, for example, **this.$r('strings.hello loaded)**.<br/>Parameter description:<br/>- **key**: key value defined in the resource qualifier file, for example, **strings.hello**. |

Example of res-defaults.json:<br/>

```json
{
    "strings": {        
        "hello": "hello world" 
    }
}
```

## Example

resources/res-dark.json:

```json
{
    "image": {
        "clockFace": "common/dark_face.png"
    },
    "colors": {
	"background": "#000000"
    }
}
```

resources/res-defaults.json:

```json
{
    "image": {
        "clockFace": "common/face.png"
    },
    "colors": {
	"background": "#ffffff"
    }
}
```

```html
<!-- xxx.hml -->
<div style="background-color: {{ $r('colors.background') }}">
    <image src="{{ $r('image.clockFace') }}"></image>
</div>
```

> **NOTE**
>
> The resource qualifier file does not support color enumeration.
