# @ohos.WallpaperExtensionAbility (WallpaperExtensionAbility)

The **WallpaperExtensionAbility** module provides lifecycle callbacks for wallpaper extension abilities and APIs for listening for wallpaper changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```js
import WallpaperExtensionAbility from '@ohos.WallpaperExtensionAbility';
```

## WallpaperExtensionAbility.onCreate

onCreate(want: object): void

Called to initialize a wallpaper extension ability when it is launched.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [object](js-apis-app-ability-want.md) | Yes  | Want information related to the wallpaper extension ability, including the ability name and bundle name.|

**Example**

```js
import WallpaperExtensionAbility from '@ohos.WallpaperExtensionAbility';

class WallpaperExt extends WallpaperExtensionAbility {
    onCreate(want) {
        console.log('onCreate, want:' + want.abilityName);
    }
}
```

## WallpaperExtensionAbility.onWallpaperChange

onWallpaperChange(wallpaperType: number): void

Called when the wallpaper changes.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Parameters**

| Name| Type       | Mandatory| Description                  |
| ------ | --------- | --- |----------------------|
| wallpaperType  | number | Yes | Wallpaper type. **0**: home screen wallpaper.<br>**1**: lock screen wallpaper.|

**Example**

```js
import WallpaperExtensionAbility from '@ohos.WallpaperExtensionAbility';

class WallpaperExt extends WallpaperExtensionAbility {
    onWallpaperChange(wallpaperType) {
        console.log('onWallpaperChange, wallpaperType:' + wallpaperType);
    }
}
```

## WallpaperExtensionAbility.onDestroy

onDestroy(): void

Called when this wallpaper extension ability is destroyed to clear resources.

**System capability**: SystemCapability.MiscServices.Wallpaper

**Example**

```js
import WallpaperExtensionAbility from '@ohos.WallpaperExtensionAbility';

class WallpaperExt extends WallpaperExtensionAbility {
    onDestroy() {
        console.log('onDestroy');
    }
}
```
