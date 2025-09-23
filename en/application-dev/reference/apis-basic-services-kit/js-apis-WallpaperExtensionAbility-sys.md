# @ohos.WallpaperExtensionAbility (WallpaperExtensionAbility) (System APIs)

The **WallpaperExtensionAbility** module provides lifecycle callbacks for wallpaper extension abilities and APIs for listening for wallpaper changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
```

## WallpaperExtensionAbility.onCreate

onCreate(want: object): void

Called to initialize a wallpaper extension ability when it is launched. Multi-thread concurrent calls are not supported.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [object](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information related to the wallpaper extension ability, including the ability name and bundle name.|

**Example**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onCreate(want: Want): void {
        console.log('onCreate, want:' + want.abilityName);
    }
}
```

## WallpaperExtensionAbility.onWallpaperChange

onWallpaperChange(wallpaperType: number): void

Called when the wallpaper changes. Multi-thread concurrent calls are not supported.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Parameters**

| Name| Type       | Mandatory| Description                  |
| ------ | --------- | --- |----------------------|
| wallpaperType  | number | Yes | Wallpaper type.<br>**0**: home screen wallpaper.<br>**1**: lock screen wallpaper. |

**Example**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';
import { wallpaper } from '@kit.BasicServicesKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onWallpaperChange(wallpaperType: wallpaper.WallpaperType): void {
        console.log('onWallpaperChange, wallpaperType:' + wallpaperType);
    }
}
```

## WallpaperExtensionAbility.onDestroy

onDestroy(): void

Called when this wallpaper extension ability is destroyed to clear resources. Multi-thread concurrent calls are not supported.

**System capability**: SystemCapability.MiscServices.Wallpaper

**System API**: This is a system API.

**Example**

```ts
import { WallpaperExtensionAbility } from '@kit.BasicServicesKit';

class WallpaperExt extends WallpaperExtensionAbility {
    onDestroy(): void {
        console.log('onDestroy');
    }
}
```
