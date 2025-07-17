# @ohos.ability.ability (Ability)

The module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ability } from '@kit.AbilityKit';
```

## DataAbilityHelper

type DataAbilityHelper = _DataAbilityHelper

Defines the level-2 module DataAbilityHelper.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md) | Level-2 module DataAbilityHelper.|


## PacMap

type PacMap = _PacMap

Defines the level-2 module PacMap.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Type| Description|
| --- | --- |
| [_PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap) | Level-2 module DataAbilityHelper.|


## DataAbilityOperation

type DataAbilityOperation = _DataAbilityOperation

Defines the level-2 module DataAbilityOperation.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md) | Level-2 module DataAbilityOperation.|


## DataAbilityResult

type DataAbilityResult = _DataAbilityResult

Defines the level-2 module DataAbilityResult.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md) | Level-2 module DataAbilityResult.|


## AbilityResult

type AbilityResult = _AbilityResult

Defines the level-2 module AbilityResult.

**System capability**: SystemCapability.Ability.AbilityBase

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_AbilityResult](js-apis-inner-ability-abilityResult.md) | Level-2 module AbilityResult.|


## ConnectOptions

type ConnectOptions = _ConnectOptions

Defines the level-2 module ConnectOptions.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_ConnectOptions](js-apis-inner-ability-connectOptions.md) | Level-2 module ConnectOptions.|


## StartAbilityParameter

type StartAbilityParameter = _StartAbilityParameter

Defines the level-2 module StartAbilityParameter.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Model restriction**: This API can be used only in the FA model.

| Type| Description|
| --- | --- |
| [_StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md) | Level-2 module StartAbilityParameter.|


**Example**
```ts
import { ability } from '@kit.AbilityKit';

let dataAbilityHelper: ability.DataAbilityHelper;
let pacMap: ability.PacMap;
let dataAbilityOperation: ability.DataAbilityOperation;
let dataAbilityResult: ability.DataAbilityResult;
let abilityResult: ability.AbilityResult;
let connectOptions: ability.ConnectOptions;  
let startAbilityParameter: ability.StartAbilityParameter;
```
