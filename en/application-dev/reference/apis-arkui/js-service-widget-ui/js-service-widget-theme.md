# Theme Configuration


To configure the theme for a service widget, use the attribute described below.

|      Name         |             Description                |
| ------------------  |  -----------------------------  |
|   app_background    |        Background color of the widget.       |


To configure the theme, create the **resources** folder at the same level as **pages** in the **widget** folder and set the above attribute in the **widget/resources/styles/default.json** file. For example, to configure the default theme of a widget to light gray:

```json
{
  "style": {
    "app_background": "#dcdcdc"
  }
}
```
