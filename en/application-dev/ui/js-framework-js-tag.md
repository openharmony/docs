# "js" Tag

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=857c0cf28fe353452da96535373d5d9536ab1775 translatedAt=2026-08-05T01:25:29.326Z pushedAt=2026-08-05T02:52:22.329Z -->

The "js" tag contains the instance name, window style, and page route information.

| Tag | Data Type | Default Value | Mandatory | Description |
| ------ | ------ | ------- | ---- | ------------------------------- |
| name   | String | default | Yes   | Name of the JavaScript instance.                     |
| pages  | Array  | -       | Yes   | Route information. For details, see ["pages"](#pages).  |
| window | Object | -       | No   | Window information. For details, see ["window"](#window).|

> **NOTE**
>
> The **"name"**, **"window"**, and **"pages"** tags are configured in the **"js"** tag of the **config.json** file.

## pages

"pages" defines the route information of each page. Each page consists of the page path and page name. The following is an example:

```json5
{
    // ...
    "pages": [
        "pages/index/index",
        "pages/detail/detail"
    ]
    // ...
}
```

> **NOTE**
>
> - The first page in the **pages** list is the homepage, also referred to as the entry, of the application.
>
>
> - The page name should not be a component name, for example, **text.hml** or **button.hml**.

## window

**"window"** defines window-related configurations. You can configure screen adaptation in either of the following ways:

- Specify **designWidth**, which is the logical screen width. All size styles, such as **width** and **font-size**, are scaled at the ratio of **designWidth** to the physical screen width. For example, when **designWidth** is 720 px and if you set **width** to 100 px, the actual display width is scaled to 200 physical px on the screen whose physical width is 1440 px.

- Set **autoDesignWidth** to **true**. Under this setting, the **designWidth** field will be ignored, and the component and layout will be scaled automatically based on the screen density. The logical screen width is automatically calculated based on the physical screen width and screen density. The logical screen width may vary depending on the device. Use the relative layout to adapt to different devices. For example, on a device with a resolution of 466 x 466 and 320 DPI (a screen density of 2x, with 160 DPI as the base), 1 px is equivalent to 2 physical px.

  > **NOTE**
  > 1. The default **\<length>** value in style attributes is calculated based on the screen density. For example, if the screen density is x2 (with 160 DPI as the baseline) and the default **\<length>** value is 1 px, the actual length rendered on the device is 2 physical pixels.
  >
  > 2. Values of **autoDesignWidth** and **designWidth** do not affect how the default **\<length>** value is calculated and the final effect.

<!--Table: 20%; 10%; 10%; 10%; 50%-->

| Attribute             | Type     | Mandatory  | Default Value      | Description                                      |
| --------------- | ------- | ---- | -------- | ---------------------------------------- |
| designWidth     | number  | No   | 720<br>| Logical screen width, which is a reference value for page design. The actual display width is scaled at the ratio of the value to the device width.  |
| autoDesignWidth | boolean | No   | false    | Whether to automatically calculate the baseline width for page design.<br>The value **true** means to automatically calculate the baseline width for page design, and **false** means the opposite.<br>If it is set to **true**, the **designWidth** attribute becomes invalid. The baseline width is calculated based on the device width and screen density.|

The following is an example.

```json5
{
    // ...
    "window": {
        "designWidth": 720,
        "autoDesignWidth": false
    }
    // ...
}
```

## Example

```json5
{
  "app": {
    "bundleName": "com.example.player",
    "version": {
        "code": 1,
        "name": "1.0"
    },
    "vendor": "example"
  },
  "module": {
      // ...
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
          // ...
      }
    ]
  }
}
```