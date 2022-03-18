# Resource File Categories


## resources Directory

All the application resource files, such as strings, images, and audio files, are stored in the **resources** directory, allowing you to easily access, use, and maintain them. The **resources** directory consists of two types of sub-directories: the **base** sub-directory and qualifiers sub-directories, and the **rawfile** sub-directory. For details, see Categories of the **resources** directory.

  Example of the **resources** directory:

```
resources
|---base  // Default directory
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---en_GB-vertical-car-mdpi // Example of a qualifiers sub-directory, which needs to be created on your own
|   |---element
|   |   |---string.json
|   |---media
|   |   |---icon.png
|---rawfile  // Default directory
```

  **Table 1** Categories of the **resources** directory

| Category | base&nbsp;and&nbsp;Qualifiers&nbsp;Sub-directories | rawfile&nbsp;Sub-directory |
| -------- | -------- | -------- |
| Structure | Sub-directories&nbsp;are&nbsp;structured&nbsp;in&nbsp;two&nbsp;levels.&nbsp;The&nbsp;directory&nbsp;name&nbsp;must&nbsp;comply&nbsp;with&nbsp;specified&nbsp;naming&nbsp;conventions&nbsp;so&nbsp;that&nbsp;its&nbsp;target&nbsp;resource&nbsp;file&nbsp;in&nbsp;the&nbsp;correct&nbsp;directory&nbsp;can&nbsp;be&nbsp;matched&nbsp;based&nbsp;on&nbsp;the&nbsp;device&nbsp;status.<br/>&nbsp;&nbsp;The&nbsp;**base**&nbsp;sub-directory&nbsp;and&nbsp;qualifiers&nbsp;sub-directories&nbsp;are&nbsp;the&nbsp;first&nbsp;level&nbsp;of&nbsp;sub-directories&nbsp;under&nbsp;**resources**.<br/>-&nbsp;The&nbsp;**base**&nbsp;sub-directory&nbsp;is&nbsp;generated&nbsp;by&nbsp;default.&nbsp;If&nbsp;no&nbsp;qualifiers&nbsp;sub-directories&nbsp;in&nbsp;the&nbsp;**resources**&nbsp;directory&nbsp;of&nbsp;the&nbsp;application&nbsp;match&nbsp;the&nbsp;device&nbsp;status,&nbsp;the&nbsp;resource&nbsp;file&nbsp;in&nbsp;the&nbsp;**base**&nbsp;sub-directory&nbsp;will&nbsp;be&nbsp;automatically&nbsp;referenced.<br/>-&nbsp;You&nbsp;need&nbsp;to&nbsp;create&nbsp;qualifiers&nbsp;sub-directories&nbsp;on&nbsp;your&nbsp;own.&nbsp;Each&nbsp;directory&nbsp;name&nbsp;consists&nbsp;of&nbsp;one&nbsp;or&nbsp;more&nbsp;qualifiers&nbsp;that&nbsp;represent&nbsp;the&nbsp;application&nbsp;scenarios&nbsp;or&nbsp;device&nbsp;characteristics.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[Qualifiers&nbsp;Sub-directories](#qualifiers-sub-directories).<br/>Resource&nbsp;group&nbsp;sub-directories&nbsp;are&nbsp;located&nbsp;at&nbsp;the&nbsp;second&nbsp;level&nbsp;of&nbsp;sub-directories&nbsp;to&nbsp;store&nbsp;basic&nbsp;elements&nbsp;such&nbsp;as&nbsp;strings,&nbsp;colors,&nbsp;and&nbsp;boolean&nbsp;values,&nbsp;as&nbsp;well&nbsp;as&nbsp;resource&nbsp;files&nbsp;such&nbsp;as&nbsp;media,&nbsp;animations,&nbsp;and&nbsp;layouts.&nbsp;For&nbsp;details,&nbsp;see&nbsp;[Resource&nbsp;Group&nbsp;Sub-directories](#resource-group-sub-directories). | You&nbsp;can&nbsp;create&nbsp;multiple&nbsp;levels&nbsp;of&nbsp;sub-directories&nbsp;with&nbsp;custom&nbsp;directory&nbsp;names.&nbsp;They&nbsp;can&nbsp;be&nbsp;used&nbsp;to&nbsp;store&nbsp;various&nbsp;resource&nbsp;files.<br/>However,&nbsp;resource&nbsp;files&nbsp;in&nbsp;the&nbsp;**rawfile**&nbsp;sub-directory&nbsp;will&nbsp;not&nbsp;be&nbsp;matched&nbsp;based&nbsp;on&nbsp;the&nbsp;device&nbsp;status. |
| Compilation | Resource&nbsp;files&nbsp;in&nbsp;the&nbsp;sub-directories&nbsp;are&nbsp;compiled&nbsp;into&nbsp;binary&nbsp;files,&nbsp;and&nbsp;each&nbsp;resource&nbsp;file&nbsp;is&nbsp;assigned&nbsp;an&nbsp;ID. | Resource&nbsp;files&nbsp;in&nbsp;the&nbsp;sub-directory&nbsp;are&nbsp;directly&nbsp;packed&nbsp;into&nbsp;the&nbsp;application&nbsp;without&nbsp;being&nbsp;compiled,&nbsp;and&nbsp;no&nbsp;IDs&nbsp;will&nbsp;be&nbsp;assigned&nbsp;to&nbsp;the&nbsp;resource&nbsp;files. |
| Reference | Resource&nbsp;files&nbsp;in&nbsp;the&nbsp;sub-directories&nbsp;are&nbsp;referenced&nbsp;based&nbsp;on&nbsp;the&nbsp;resource&nbsp;type&nbsp;and&nbsp;resource&nbsp;name. | Resource&nbsp;files&nbsp;in&nbsp;the&nbsp;sub-directories&nbsp;are&nbsp;referenced&nbsp;based&nbsp;on&nbsp;the&nbsp;specified&nbsp;file&nbsp;path&nbsp;and&nbsp;file&nbsp;name. |


## Qualifiers Sub-directories

The name of a qualifiers sub-directory consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the mobile country code (MCC), mobile network code (MNC), language, script, country or region, screen orientation, device type, color mode, and screen density. The qualifiers are separated using underscores (_) or hyphens (-). When creating a qualifiers sub-directory, you need to understand the directory naming conventions and the rules for matching qualifiers sub-directories and the device status.

**Naming Conventions for Qualifiers Sub-directories**

- Qualifiers are ordered in the following sequence: _MCC_MNC-language_script_country/region-screen orientation-device type-color mode-screen density_. You can select one or multiple qualifiers to name your sub-directory based on your application scenarios and device characteristics.

- Separation between qualifiers: The language, script, and country/region qualifiers are separated using underscores (_); the MNC and MCC qualifiers are also separated using underscores (_); other qualifiers are separated using hyphens (-). For example, **zh_Hant_CN** and **zh_CN-car-ldpi**.

- Value range of qualifiers: The value of each qualifier must meet the requirements. Otherwise, the resource files in the sub-directory cannot be matched.
    **Table 2** Requirements for qualifier values
  
  | Qualifier&nbsp;Type | Description&nbsp;and&nbsp;Value&nbsp;Range | 
  | -------- | -------- |
  | MCC&amp;MNC | Indicates&nbsp;the&nbsp;MCC&nbsp;and&nbsp;MNC,&nbsp;which&nbsp;are&nbsp;obtained&nbsp;from&nbsp;the&nbsp;network&nbsp;where&nbsp;the&nbsp;device&nbsp;is&nbsp;registered.&nbsp;The&nbsp;MCC&nbsp;can&nbsp;be&nbsp;either&nbsp;followed&nbsp;by&nbsp;the&nbsp;MNC&nbsp;with&nbsp;an&nbsp;underscore&nbsp;(_)&nbsp;in&nbsp;between&nbsp;or&nbsp;be&nbsp;used&nbsp;independently.&nbsp;For&nbsp;example,&nbsp;**mcc460**&nbsp;represents&nbsp;China,&nbsp;and&nbsp;**mcc460_mnc00**&nbsp;represents&nbsp;China&nbsp;Mobile.<br/>For&nbsp;details&nbsp;about&nbsp;the&nbsp;value&nbsp;range,&nbsp;refer&nbsp;to&nbsp;**ITU-T&nbsp;E.212**&nbsp;(the&nbsp;international&nbsp;identification&nbsp;plan&nbsp;for&nbsp;public&nbsp;networks&nbsp;and&nbsp;subscriptions). | 
  | Language | Indicates&nbsp;the&nbsp;language&nbsp;used&nbsp;by&nbsp;the&nbsp;device.&nbsp;The&nbsp;value&nbsp;consists&nbsp;of&nbsp;two&nbsp;or&nbsp;three&nbsp;lowercase&nbsp;letters,&nbsp;for&nbsp;example,&nbsp;**zh**&nbsp;indicates&nbsp;Chinese,&nbsp;**en**&nbsp;indicates&nbsp;English,&nbsp;and&nbsp;**mai**&nbsp;indicates&nbsp;Maithili.<br/>For&nbsp;details&nbsp;about&nbsp;the&nbsp;value&nbsp;range,&nbsp;refer&nbsp;to&nbsp;**ISO&nbsp;639**&nbsp;(codes&nbsp;for&nbsp;the&nbsp;representation&nbsp;of&nbsp;names&nbsp;of&nbsp;languages). | 
  | Script | Indicates&nbsp;the&nbsp;script&nbsp;type&nbsp;used&nbsp;by&nbsp;the&nbsp;device.&nbsp;The&nbsp;value&nbsp;starts&nbsp;with&nbsp;one&nbsp;uppercase&nbsp;letter&nbsp;followed&nbsp;by&nbsp;three&nbsp;lowercase&nbsp;letters,&nbsp;for&nbsp;example,&nbsp;**Hans**&nbsp;indicates&nbsp;simplified&nbsp;Chinese&nbsp;and&nbsp;**Hant**&nbsp;indicates&nbsp;traditional&nbsp;Chinese.<br/>For&nbsp;details&nbsp;about&nbsp;the&nbsp;value&nbsp;range,&nbsp;refer&nbsp;to&nbsp;**ISO&nbsp;15924**&nbsp;(codes&nbsp;for&nbsp;the&nbsp;representation&nbsp;of&nbsp;names&nbsp;of&nbsp;scripts). | 
  | Country/Region | Indicates&nbsp;the&nbsp;country&nbsp;or&nbsp;region&nbsp;where&nbsp;a&nbsp;user&nbsp;is&nbsp;located.&nbsp;The&nbsp;value&nbsp;consists&nbsp;of&nbsp;two&nbsp;or&nbsp;three&nbsp;uppercase&nbsp;letters&nbsp;or&nbsp;three&nbsp;digits,&nbsp;for&nbsp;example,&nbsp;**CN**&nbsp;indicates&nbsp;China&nbsp;and&nbsp;**GB**&nbsp;indicates&nbsp;the&nbsp;United&nbsp;Kingdom.<br/>For&nbsp;details&nbsp;about&nbsp;the&nbsp;value&nbsp;range,&nbsp;refer&nbsp;to&nbsp;**ISO&nbsp;3166-1**&nbsp;(codes&nbsp;for&nbsp;the&nbsp;representation&nbsp;of&nbsp;names&nbsp;of&nbsp;countries&nbsp;and&nbsp;their&nbsp;subdivisions). | 
  | Screen&nbsp;orientation | Indicates&nbsp;the&nbsp;screen&nbsp;orientation&nbsp;of&nbsp;the&nbsp;device.&nbsp;The&nbsp;value&nbsp;can&nbsp;be:<br/>-&nbsp;**vertical**:&nbsp;portrait&nbsp;orientation<br/>-&nbsp;**horizontal**:&nbsp;landscape&nbsp;orientation | 
  | Device&nbsp;type | Indicates&nbsp;the&nbsp;device&nbsp;type.&nbsp;The&nbsp;value&nbsp;can&nbsp;be:<br/>-&nbsp;**phone**:&nbsp;smartphones<br/>-&nbsp;**tablet**:&nbsp;tablets<br/>-&nbsp;**car**:&nbsp;head&nbsp;units<br/>-&nbsp;**tv**:&nbsp;smart&nbsp;TVs<br/>-&nbsp;**wearable**:&nbsp;wearables | 
  | Color&nbsp;mode | Indicates&nbsp;the&nbsp;color&nbsp;mode&nbsp;of&nbsp;the&nbsp;device.&nbsp;The&nbsp;value&nbsp;can&nbsp;be:<br/>-&nbsp;**dark**:&nbsp;dark&nbsp;mode<br/>-&nbsp;**light**:&nbsp;light&nbsp;mode | 
  | Screen&nbsp;density | Indicates&nbsp;the&nbsp;screen&nbsp;density&nbsp;of&nbsp;the&nbsp;device,&nbsp;in&nbsp;dpi.&nbsp;The&nbsp;value&nbsp;can&nbsp;be:<br/>-&nbsp;**sdpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;small-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(SDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(0,&nbsp;120].<br/>-&nbsp;**mdpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;medium-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(MDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(120,&nbsp;160].<br/>-&nbsp;**ldpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;large-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(LDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(160,&nbsp;240].<br/>-&nbsp;**xldpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;extra-large-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(XLDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(240,&nbsp;320].<br/>-&nbsp;**xxldpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;extra-extra-large-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(XXLDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(320,&nbsp;480].<br/>-&nbsp;**xxxldpi**:&nbsp;screen&nbsp;density&nbsp;with&nbsp;extra-extra-extra-large-scale&nbsp;dots&nbsp;per&nbsp;inch&nbsp;(XXXLDPI).&nbsp;This&nbsp;value&nbsp;is&nbsp;applicable&nbsp;for&nbsp;devices&nbsp;with&nbsp;a&nbsp;DPI&nbsp;range&nbsp;of&nbsp;(480,&nbsp;640]. | 

**Rules for Matching Qualifiers Sub-directories and Device Resources**

- Qualifiers are matched with the device resources in the following priorities: MCC&amp;MNC &gt; locale (options: language, language_script, language_country/region, and language_script_country/region) &gt; screen orientation &gt; device type &gt; color mode &gt; screen density

- If the qualifiers sub-directories contain the **MCC, MNC, language, script, screen orientation, device type, and color mode** qualifiers, their values must be consistent with the current device status so that the sub-directories can be used for matching the device resources. For example, the qualifiers sub-directory **zh_CN-car-ldpi** cannot be used for matching the resource files labeled **en_US**.


## Resource Group Sub-directories

You can create resource group sub-directories (including element, media, animation, layout, graphic, and profile) in the **base** and qualifiers sub-directories to store resource files of specific types. For details, see Resource group sub-directories.


  **Table 3** Resource group sub-directories

| Resource&nbsp;Group&nbsp;Sub-directory | Description | Resource&nbsp;File | 
| -------- | -------- | -------- |
| element | Indicates&nbsp;element&nbsp;resources.&nbsp;Each&nbsp;type&nbsp;of&nbsp;data&nbsp;is&nbsp;represented&nbsp;by&nbsp;a&nbsp;JSON&nbsp;file.&nbsp;The&nbsp;options&nbsp;are&nbsp;as&nbsp;follows:<br/>-&nbsp;**boolean**:&nbsp;boolean&nbsp;data<br/>-&nbsp;**color**:&nbsp;color&nbsp;data<br/>-&nbsp;**float**:&nbsp;floating-point&nbsp;data<br/>-&nbsp;**intarray**:&nbsp;array&nbsp;of&nbsp;integer<br/>-&nbsp;**integer**:&nbsp;integer&nbsp;data<br/>-&nbsp;**pattern**:&nbsp;pattern&nbsp;data<br/>-&nbsp;**plural**:&nbsp;plural&nbsp;form&nbsp;data<br/>-&nbsp;**strarray**:&nbsp;array&nbsp;of&nbsp;strings<br/>-&nbsp;**string**:&nbsp;string&nbsp;data | It&nbsp;is&nbsp;recommended&nbsp;that&nbsp;files&nbsp;in&nbsp;the&nbsp;**element**&nbsp;sub-directory&nbsp;be&nbsp;named&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;following&nbsp;files,&nbsp;each&nbsp;of&nbsp;which&nbsp;can&nbsp;contain&nbsp;only&nbsp;data&nbsp;of&nbsp;the&nbsp;same&nbsp;type:<br/>-&nbsp;boolean.json<br/>-&nbsp;color.json<br/>-&nbsp;float.json<br/>-&nbsp;intarray.json<br/>-&nbsp;integer.json<br/>-&nbsp;pattern.json<br/>-&nbsp;plural.json<br/>-&nbsp;strarray.json<br/>-&nbsp;string.json | 
| media | Indicates&nbsp;media&nbsp;resources,&nbsp;including&nbsp;non-text&nbsp;files&nbsp;such&nbsp;as&nbsp;images,&nbsp;audios,&nbsp;and&nbsp;videos. | The&nbsp;file&nbsp;name&nbsp;can&nbsp;be&nbsp;customized,&nbsp;for&nbsp;example,&nbsp;**icon.png**. | 
| animation | Indicates&nbsp;animation&nbsp;resources,&nbsp;in&nbsp;XML&nbsp;format. | The&nbsp;file&nbsp;name&nbsp;can&nbsp;be&nbsp;customized,&nbsp;for&nbsp;example,&nbsp;**zoom_in.xml**. | 
| layout | Indicates&nbsp;layout&nbsp;resources,&nbsp;in&nbsp;XML&nbsp;format. | The&nbsp;file&nbsp;name&nbsp;can&nbsp;be&nbsp;customized,&nbsp;for&nbsp;example,&nbsp;**home_layout.xml**. | 
| graphic | Indicates&nbsp;graphic&nbsp;resources,&nbsp;in&nbsp;XML&nbsp;format. | The&nbsp;file&nbsp;name&nbsp;can&nbsp;be&nbsp;customized,&nbsp;for&nbsp;example,&nbsp;**notifications_dark.xml**. | 
| profile | Indicates&nbsp;other&nbsp;types&nbsp;of&nbsp;files,&nbsp;which&nbsp;are&nbsp;stored&nbsp;in&nbsp;their&nbsp;raw&nbsp;formats. | The&nbsp;file&nbsp;name&nbsp;can&nbsp;be&nbsp;customized. |
