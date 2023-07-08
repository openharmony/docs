# @ohos.WallpaperExtensionAbility (WallpaperExtensionAbility)

开发者可通过继承本模块开发自己的壁纸应用并管理壁纸应用生命周期。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import WallpaperExtensionAbility from '@ohos.WallpaperExtensionAbility';
```

## 属性

**系统能力：** SystemCapability.MiscServices.Wallpaper

## WallpaperExtensionAbility.onCreate

onCreate(want: Want): void

Extension生命周期回调，在拉起Extension壁纸拓展应用时调用，执行初始化应用操作。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [Want](js-apis-app-ability-want.md) | 是   | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```js
class WallpaperExt extends WallpaperExtensionAbility {
  onCreate(want) {
    console.log('onCreate, want:' + want.abilityName);
  }
}
```

## WallpaperExtensionAbility.onWallpaperChange

onWallpaperChange(wallpaperType: number): void

用户修改壁纸时触发回调，在Extension壁纸拓展应用监听壁纸变化时调用。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**参数：**

| 参数名 | 类型          | 必填 | 说明                   |
| ------ | ----------- | ---- |----------------------|
| wallpaperType  | [number] | 是   | 壁纸类型，包括主屏幕壁纸0和锁屏壁纸1。 |

**示例：**

```js
class WallpaperExt extends WallpaperExtensionAbility {
  onWallpaperChange(wallpaperType) {
    console.log('onWallpaperChange, wallpaperType:' + wallpaperType);
  }
}
```

## WallpaperExtensionAbility.onDestroy

onDestroy(): void

Extension生命周期回调，在销毁输入法应用时回调，执行资源清理等操作。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**示例：**

```js
class WallpaperExt extends WallpaperExtensionAbility {
  onDestroy() {
    console.log('onDestroy');
  }
}
```
