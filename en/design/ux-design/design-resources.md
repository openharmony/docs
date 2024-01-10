# Resources

This topic provides the following information for UX designers and developers:


- [OpenHarmony System Resource Layer Design V1.0.xlsm](figures/OpenHarmony_System_Resource_Layer_Design_V1.0.xlsm), where you can get the scenarios, IDs, and more of [layered parameters](visual-basis.md)

- [OpenHarmony Weather Application UX Design Deliverable V1.0.zip](figures/OpenHarmony_Weather_Application_UX_Design_Deliverable_V1.0.zip), where you can get a sample of standard [design deliverables](design-deliverable-overview.md)

- [OpenHarmony_Icons.zip](figures/OpenHarmony_Icons.zip), where you can get OpenHarmony [icons](visual-icons.md)

- [OpenHarmony Application Icon Templates.zip](figures/OpenHarmony-application-icon-templates.zip), where you can get OpenHarmony [application icon](visual-app-icons.md) design templates


**OpenHarmony System Resource Layer Design** lists the IDs of available system resources in OpenHarmony and their values on different types of devices. It consists of six sheets, as described below.


  | Sheet| Description| 
| -------- | -------- |
| Application Color Parameters| Color-related system resources that can be used during application development.| 
| Application Rounded Corner Parameters| System resources related to rounded corners that can be used during application development.| 
| Application Font Parameters| Font-related system resources that can be used during application development.| 
| Application Spacing Parameters| Spacing-related system resources that can be used during application development.| 
| Service Widget Parameters| System resources that can be used during service widget development.| 
| Quick Reference for Opacity Values| A quick reference for converting opacity between percentage and hexadecimal representations.| 


> **NOTE**
> - You are advised to use application-related system parameters during application development and widget-related system parameters during widget development.
> 
> - A system parameter has different values on different device types. Currently, only system parameter values on the default device are provided. Values for others device types will be provided later.
> 
> - Colors can be expressed in the form of RGB or ARGB. The color represented by RGB is completely opaque, and the opacity of the color represented by ARGB is determined by A (alpha channel). For example, \#7FFF0000 indicates red with 50% opacity, and \#FFFF0000 and \#FF0000 indicate red with 100% opacity.
