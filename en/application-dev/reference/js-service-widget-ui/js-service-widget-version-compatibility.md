# Version Compatibility Adaptation


As you incorporate new features into service widgets of your applications, take measures to avoid abnormal display of these features on earlier versions. You can specify the minimum SDK version in the service widget project so that service widgets incorporating new features will not be installed on incompatible systems. You can also follow the instructions in this section to implement forward compatibility during your service widget development.

Configure forward compatibility in the JSON configuration file. Specifically, set the **apiVersion** attribute, which is at the same level as the **data** and **actions** fields in the service widget configuration file. The content defined in **apiVersion** overwrites the original content in **data** based on the current version information.


Example:

Assume that the JS service widget framework supports WebP image sources since API version 9. Then you can implement forward compatibility as follows:

```html
<!-- xxx.hml -->
<div>
    <image src="{{imageSrc}}" style="width: 100px;height: 100px;"></image>
</div>
```

JSON configuration file:

```json
{
  "data": {
    "imageSrc": "defaultSrc.png"
  },
  "apiVersion": {
    "9": {
      "imageSrc": "newSrc.webp"
    }
  }
}
```

The JS service widget development framework selects the most appropriate data based on the application configuration and the current API version.

If the API version is 8 or earlier, the value of **imageSrc** is **defaultSrc.png**.

If the API version is 9, the value of **imageSrc** is **newSrc.webp**.
