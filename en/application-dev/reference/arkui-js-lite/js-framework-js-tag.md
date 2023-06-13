# "js" Tag


The "js" tag contains the instance name and page route information.


| Tag   | Type    | Default Value    | Mandatory  | Description                           |
| ----- | ------ | ------- | ---- | ----------------------------- |
| name  | string | default | Yes   | Name of the JavaScript instance.                   |
| pages | Array  | -       | Yes   | Route information. For details, see ["pages"](#pages).|


>  **NOTE**
>
>  The "name" and "pages" tags are configured in the "js" tag of the **config.json** file.


## pages

The **"pages"** defines the route information of each page. Each page consists of the page path and page name. The following is an example:


```
{
  ...
  "pages": [
    "pages/index/index",
    "pages/detail/detail"
  ]
  ...
}
```


>  **NOTE**
>
>
>  - The application home page is fixed to **pages/index/index**.
>
>  - The page name should not be a component name, for example, **text.hml** or **button.hml**.


## Example


```
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
        ]
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
