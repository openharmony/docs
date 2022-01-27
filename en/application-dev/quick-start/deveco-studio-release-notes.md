# Version Change History

- [V3.0 Beta2 (2021-12-31)](#V30-Beta2-2021-12-31)
 - [Version Compatibility](#Version-Compatibility)
 - [Version Change History](#Version-Change-History)
- [V3.0 Beta1 (2021-09-29)](#V30-Beta1-2021-09-29)

## V3.0 Beta2 (2021-12-31)


### Version Compatibility

DevEco Studio 3.0 Beta2 is compatible with the module versions listed below.

| Module | Version | Description | 
| -------- | -------- | -------- |
| Gradle | 7.3&nbsp;(7.2&nbsp;at&nbsp;minimum) | DevEco&nbsp;Studio&nbsp;has&nbsp;Gradle&nbsp;7.3&nbsp;preinstalled.&nbsp;No&nbsp;separate&nbsp;installation&nbsp;is&nbsp;required. | 
| JDK | 11.0.x | DevEco&nbsp;Studio&nbsp;has&nbsp;JDK&nbsp;11&nbsp;preinstalled.&nbsp;No&nbsp;separate&nbsp;installation&nbsp;is&nbsp;required. | 
| OpenHarmony&nbsp;SDK | 3.1.0.0&nbsp;(API&nbsp;Version&nbsp;8&nbsp;Beta) | This&nbsp;version&nbsp;is&nbsp;compatible&nbsp;with&nbsp;SDKs&nbsp;of&nbsp;earlier&nbsp;versions. | 
| Toolchinas | 3.1.0.0 | Update&nbsp;them&nbsp;to&nbsp;the&nbsp;latest&nbsp;version. | 
| hap&nbsp;plug-in | 3.0.5.2 | 
| decctest&nbsp;plug-in | 1.2.7.2 | 


### Version Change History

| |
| -------- |
| **New&nbsp;Features**<br/>-&nbsp;Introduced&nbsp;the&nbsp;Chinese&nbsp;UI.&nbsp;By&nbsp;default,&nbsp;the&nbsp;UI&nbsp;is&nbsp;displayed&nbsp;in&nbsp;English.&nbsp;To&nbsp;enable&nbsp;the&nbsp;Chinese&nbsp;UI,&nbsp;go&nbsp;to&nbsp;**Settings**,&nbsp;choose&nbsp;**Plugins**&nbsp;&gt;&nbsp;**installed**,&nbsp;and&nbsp;select&nbsp;**Chinese&nbsp;(Simplified)**.&nbsp;Then,&nbsp;restart&nbsp;DevEco&nbsp;Studio&nbsp;for&nbsp;the&nbsp;settings&nbsp;to&nbsp;take&nbsp;effect.<br/>-&nbsp;Introduced&nbsp;support&nbsp;for&nbsp;OpenHarmony&nbsp;apps&nbsp;and&nbsp;services,&nbsp;with&nbsp;various&nbsp;debugging&nbsp;features,&nbsp;from&nbsp;breakpoint&nbsp;management&nbsp;and&nbsp;variable&nbsp;observation&nbsp;to&nbsp;stepping.<br/>**Enhanced&nbsp;Features**<br/>-&nbsp;Updated&nbsp;the&nbsp;OpenHarmony&nbsp;SDK&nbsp;to&nbsp;3.1.0.0,&nbsp;whose&nbsp;API&nbsp;version&nbsp;is&nbsp;API&nbsp;8&nbsp;Beta&nbsp;and&nbsp;corresponding&nbsp;compilation&nbsp;and&nbsp;building&nbsp;plugin&nbsp;is&nbsp;3.0.5.2.<br/>-&nbsp;Added&nbsp;an&nbsp;ability&nbsp;template&nbsp;that&nbsp;supports&nbsp;low-code&nbsp;development:&nbsp;**[Standard]Empty&nbsp;Ability**.<br/>-&nbsp;Added&nbsp;eTS&nbsp;component&nbsp;preview:&nbsp;allows&nbsp;previewing&nbsp;of&nbsp;eTS&nbsp;components;&nbsp;requires&nbsp;compileSdkVersion&nbsp;8&nbsp;or&nbsp;later.<br/>-&nbsp;Added&nbsp;eTS&nbsp;livee&nbsp;preview:&nbsp;allows&nbsp;viewing&nbsp;of&nbsp;the&nbsp;attribute&nbsp;changes&nbsp;in&nbsp;real&nbsp;time&nbsp;as&nbsp;you&nbsp;make&nbsp;them;&nbsp;requires&nbsp;compileSdkVersion&nbsp;8&nbsp;or&nbsp;later. | 


## V3.0 Beta1 (2021-09-29)

| |
| -------- |
| **New&nbsp;Features**<br/>-&nbsp;Added&nbsp;support&nbsp;for&nbsp;OpenHarmony&nbsp;SDK&nbsp;management.&nbsp;You&nbsp;can&nbsp;use&nbsp;SDK&nbsp;Manager&nbsp;to&nbsp;download&nbsp;and&nbsp;manage&nbsp;OpenHarmony&nbsp;SDKs.<br/>-&nbsp;Allowed&nbsp;for&nbsp;building&nbsp;of&nbsp;a&nbsp;single&nbsp;module&nbsp;during&nbsp;HAP&nbsp;compilation&nbsp;and&nbsp;building&nbsp;to&nbsp;accelerate&nbsp;building&nbsp;for&nbsp;multi-module&nbsp;projects;&nbsp;allowed&nbsp;for&nbsp;one-click&nbsp;re-building&nbsp;of&nbsp;HAPs,&nbsp;by&nbsp;automatically&nbsp;conducting&nbsp;the&nbsp;Clean&nbsp;Project&nbsp;operation&nbsp;before&nbsp;a&nbsp;HAP&nbsp;build.<br/>**Enhanced&nbsp;Features**<br/>-&nbsp;Updated&nbsp;the&nbsp;compilation&nbsp;and&nbsp;building&nbsp;plugin&nbsp;to&nbsp;version&nbsp;3.0.3.2.<br/>-&nbsp;Improved&nbsp;the&nbsp;JSON&nbsp;editor,&nbsp;which&nbsp;now&nbsp;enables&nbsp;quick&nbsp;rectification&nbsp;of&nbsp;resource&nbsp;index&nbsp;errors&nbsp;and&nbsp;instant&nbsp;access&nbsp;to&nbsp;resource&nbsp;values.<br/>-&nbsp;Provided&nbsp;Ohos&nbsp;and&nbsp;Project&nbsp;(default)&nbsp;views&nbsp;for&nbsp;projects,&nbsp;which&nbsp;you&nbsp;can&nbsp;switch&nbsp;between&nbsp;easily.<br/>-&nbsp;Enabled&nbsp;OpenHarmony&nbsp;projects&nbsp;to&nbsp;support&nbsp;Ark&nbsp;build.<br/>-&nbsp;Moved&nbsp;the&nbsp;**supportSystem&nbsp;"standard"**&nbsp;field,&nbsp;which&nbsp;is&nbsp;exclusive&nbsp;to&nbsp;OpenHarmony&nbsp;projects,&nbsp;from&nbsp;the&nbsp;module-level&nbsp;**build.gradle**&nbsp;file&nbsp;to&nbsp;the&nbsp;project-level&nbsp;**build.gradle**&nbsp;file. | 
