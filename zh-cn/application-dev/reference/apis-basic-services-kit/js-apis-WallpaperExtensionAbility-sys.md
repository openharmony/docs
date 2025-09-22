# @ohos.WallpaperExtensionAbility (WallpaperExtensionAbility)（系统接口）

<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @gcw_jQMboB9m-->
<!--Designer: @gcw_jQMboB9m-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

WallpaperExtensionAbility为壁纸拓展模块，提供应用生命周期回调和监听壁纸变化的能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
```

## WallpaperExtensionAbility.onCreate

onCreate(want: object): void

初始化壁纸拓展应用。在拉起Extension壁纸拓展应用时触发回调，执行初始化应用操作。不支持多线程并发调用。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型          | 必填 | 说明                             |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [object](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onCreate(want: Want): void {
        console.info('onCreate, want:' + want.abilityName);
    }
}
```

## WallpaperExtensionAbility.onWallpaperChange

onWallpaperChange(wallpaperType: number): void

监听壁纸变化。在壁纸变化时触发回调。不支持多线程并发调用。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型        | 必填 | 说明                   |
| ------ | --------- | --- |----------------------|
| wallpaperType  | number | 是  | 壁纸类型。主屏幕壁纸为0，锁屏壁纸为1。 |

**示例：**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
import { wallpaper } from '@kit.BasicServicesKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onWallpaperChange(wallpaperType: wallpaper.WallpaperType): void {
        console.info('onWallpaperChange, wallpaperType:' + wallpaperType);
    }
}
```

## WallpaperExtensionAbility.onDestroy

onDestroy(): void

清理壁纸拓展应用资源。在销毁壁纸拓展应用时触发回调，执行资源清理。不支持多线程并发调用。

**系统能力：** SystemCapability.MiscServices.Wallpaper

**系统接口**：此接口为系统接口。

**示例：**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onDestroy(): void {
        console.info('onDestroy');
    }
}
```
