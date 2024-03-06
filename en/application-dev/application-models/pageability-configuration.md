# PageAbility Configuration


The PageAbility is configured in **abilities** under **module** in the **config.json** file. The **icon** field indicates the index of the ability icon resource file, and the **label** field indicates the ability name presented to users, and the **skills** field indicates the type of Want that is acceptable to the ability.

**Table 1** PageAbility configuration items

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| icon | Index to the ability icon file. Example value: **$media:ability_icon**. In the **skills** attribute of the ability, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the icon of the ability is also used as the icon of the application. If multiple abilities address this condition, the icon of the first candidate ability is used as the application icon.<br>Note: The **icon** and **label** values of an application are visible to users. Ensure that at least one of them is different from any existing icons or labels.| String| Yes (initial value: left empty)|
| label | Ability name visible to users. The value can be a name string or a resource index to names in multiple languages. In the **skills** attribute of the ability, if the **actions** value contains **action.system.home** and the **entities** value contains **entity.system.home**, the label of the ability is also used as the label of the application. If multiple abilities address this condition, the label of the first candidate ability is used as the application label.<br>Note: The **icon** and **label** values of an application are visible to users. Ensure that at least one of them is different from any existing icons or labels. The value can be a reference to a string defined in a resource file or a string enclosed in brackets ({}). The value can contain a maximum of 255 characters.| String| Yes (initial value: left empty)|
| skills | Types of the Want that can be accepted by the ability.| Object array| Yes (initial value: left empty)|
