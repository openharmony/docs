# AbilityBase

## Overview

As the basic definition module of Ability Kit, AbilityBase provides definitions and APIs for [Want](capi-want-h.md), which can be used to transfer information between application components.

**System capability**: SystemCapability.Ability.AbilityBase

**Since**: 15

## Files

| Name| Description|
| -- | -- |
| [ability_base_common.h](capi-ability-base-common-h.md) | Describes the error codes defined by AbilityBase.|
| [want.h](capi-want-h.md) | Want is a carrier for information transfer between objects (application components). Want can be used as a parameter of **startAbility** to specify a startup target and information that needs to be carried during startup, for example, **bundleName** and **abilityName**, which respectively indicate the bundle name of the target ability and the ability name in the bundle. When ability A needs to start ability B and transfer some data to ability B, it can use Want a carrier to transfer the data.|
