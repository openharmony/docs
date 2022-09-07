# "js" Tag


The "js" tag contains the instance name, window style, and page route information.


| Tag | Data Type | Default Value | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| name | string | default | Yes | Name of the JavaScript instance. |
| pages | Array | - | Yes | Route information. For details, see ["pages"](#pages). |
| window | Object | - | No | Window information. For details, see ["window"](#window). |


> **NOTE**
>
> The "name", "window", and "pages" tags are configured in the "js" tag of the **config.json** file.


## "pages"

The "pages" defines the route information of each page. Each page consists of the page path and page name. The following is an example:

```json
{
    ...
    "pages": [
        "pages/index/index",
        "pages/detail/detail"
    ]
    ...
}
```


> **NOTE**
> 
> - The first page in the pages list is the home page, also referred to as the entry, of the application.
>
> 
> - The page name should not be a component name, for example, text.hml or button.hml.

## window

The "window" defines window-related configurations. To solve the screen adaptation problem, you can use either of the following methods:

- Specify designWidth, which is the logical screen width. All size styles, such as width and font-size, are scaled at the ratio of designWidth to the physical screen width. For example, when designWidth is 720 px and if you set width to 100 px, the actual display width is scaled to 200 physical px on the screen whose physical width is 1440 px.

- Set autoDesignWidth to true, the designWidth field will be ignored, and the component and layout will be scaled automatically based on the screen density. The logical screen width is automatically calculated based on the physical screen width and screen density. The logical screen width may vary depending on the device. Use the relative layout to adapt to different devices. For example, on a device with a resolution of 466x466 and 320 DPI (a screen density of 2x, with 160 DPI as the base), 1 px is equivalent to 2 physical px.
  
  > **NOTE**
  >
  > 1. The default  &lt;length&gt; value in the current style is calculated based on the screen density. For example, if the screen density is x2 (with 160 DPI as the baseline) and the default  &lt;length&gt; value is 1 px, the actual length rendered on the device is 2 physical px.
  >
  > 2. Values of autoDesignWidth and designWidth do not affect how the default  &lt;length&gt; value is calculated and the final effect.


| Attribute | Type | Mandatory | Default Value | Description |
| -------- | -------- | -------- | -------- | -------- |
| designWidth | number | No | 720 | Logical screen width, which is a reference value for page design. The actual display width is scaled at the ratio of the value to the device width. |
| autoDesignWidth | boolean | No | false | Whether to automatically calculate the baseline width. If autoDesignWidth is set to true, designWidth is ignored. The baseline width is calculated based on the physical screen width and screen density. |

The following is a sample code snippet:

```json
{
    ...
    "window": {
        "designWidth": 720,
        "autoDesignWidth": false
    }
    ...
}
```


## Example


```json
{
  "app": {
    "bundleName": "com.example.player",
    "version": {
        "code": 1,
        "name": "1.0"
    },
    "vendor": "example"
  }
  "module": {
      ...
      "js": [
      {
          "name": "default",
          "pages": [
              "pages/index/index",
              "pages/detail/detail"
          ],
          "window": {
              "designWidth": 720,
              "autoDesignWidth": false
          }
      }
      ],
      "abilities": [
      {
          ...
      }
    ]
  }
}
```
