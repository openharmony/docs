# Environment


Environment is a singleton object created by the framework when the application is started. It provides the AppStorage with a series of environment state attributes required by the application. These attributes describe the device environment where the application runs. Environment and its attributes are immutable, and all attribute values are of the simple type. The following example shows how to obtain the semantic environment from Environment:



```
Environment.EnvProp("accessibilityEnabled", "default");
var enable = AppStorage.Get("accessibilityEnabled");
```


accessibilityEnabled is the default system variable identifier provided by Environment. You need to bind the corresponding system attribute to the AppStorage. Then, you can use the methods or decorators in the AppStorage to access the corresponding system attribute data.


## Environment APIs

| key | Parameter | Return Value | Description |
| -------- | -------- | -------- | -------- |
| EnvProp | key: string,<br/>defaultValue: any | boolean | Binds this system attribute to the AppStorage. You are advised to use this API during application startup. If the attribute already exists in the AppStorage, false is returned. Do not use the variables in the AppStorage. Instead, call this method to bind environment variables. |
| EnvProps | keys: {<br/>key: string,<br/>defaultValue: any<br/>}[] | void | Associates this system item array with the AppStorage. |
| Keys | Array&lt;string&gt; | number | Returns the associated system item array. |


## Built-in Environment Variables

  | key | Type | Description | 
| -------- | -------- | -------- |
| accessibilityEnabled | boolean | Whether to enable accessibility. | 
| colorMode | ColorMode | Color mode. The options are as follows:<br/>- ColorMode.LIGHT: light mode.<br/>- ColorMode.DARK: dark mode. | 
| fontScale | number | Font scale. The value range is [0.85, 1.45]. | 
| fontWeightScale | number | Font weight scale. The value range is [0.6, 1.6]. | 
| layoutDirection | LayoutDirection | Layout direction. The options are as follows:<br/>- LayoutDirection.LTR: The direction is from left to right.<br/>- LayoutDirection.RTL: The direction is from right to left. | 
| languageCode | string | Current system language. The value is in lowercase, for example, zh. | 
