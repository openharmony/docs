# "js" Tag


Configure the "js" tag in the config.json file of your application. The "js" tag contains the instance name, page route, and window configuration information.


  | Tag | Type | Default Value | Mandatory | Description | 
| -------- | -------- | -------- | -------- | -------- |
| name | string | default | Yes | Name of the eTS instance. | 
| pages | Array | - | Yes | Page route information. For details, see ["pages"](#pages). | 
| window | Object | - | No | Window configuration information. For details, see ["window"](#window). | 
| mode | Object | - | No | Running type and syntax style of the JS component. For details, see ["mode"](#mode). | 


## pages

The "pages" defines the route information of each page's entry component. Each page consists of the page path and page name. The following is an example:


```
{
    "pages": [
        "pages/index",
        "pages/detail"
    ]
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> - The first page in the "pages" list is the home page of the application.
>
> - The page name must not be a component name, for example, Text.ets or Button.ets.
>
> - Each page file must contain the [page entry component](ts-component-based-entry.md) (with the @Entry decoration).


## window

The "window" configures the view window. The following attributes can be configured:

  | Type | Default Value | Description | 
| -------- | -------- | -------- |
| designWidth | - | Logical width of the view. The default value is 720. (The default value is 454 for wearables.) The logical width of the view determines the unit size of lpx. For example, if designWidth is 720 and the view width is 1440 physical pixels, 1 lpx is 2 physical pixels. For details, see [lpx](ts-pixel-units.md). | 


```
{
  ...
  "window": {
    "designWidth": 720
  }
  ...
}
```


## mode

The "mode" configures the running type and syntax style of a JS component. The following attributes are supported:

  | Type | Default Value | Description | 
| -------- | -------- | -------- |
| type | - | Running type of the JS component. The options are as follows:<br/>- pageAbility: Run the JS component in ability mode.<br/>- form: Run the JS component as a service widget. | 
| syntax | - | Syntax type of the JS component. The options are as follows:<br/>- hml: compiled in the .hml, .css, or .js style.<br/>- ets: compiled in the declarative syntax style. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> If type is set to form, syntax cannot be ets.


## Example

config.json:


```
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
        "js": [{            
            "name": "default",            
            "pages": [                
                "pages/index",                
                "pages/detail"            
            ],            
            "window": {                
                "designWidth": 720            
            },            
            "mode": {                
                "type": "pageAbility",                
                "syntax": "ets"            
            },        
        }],
        "abilities": [{
            ... 
        }]
    }
}
```
