# Redirection Rules


Generally, UI redirection within an application is triggered by users. However, an application can call **startAbility()** to implement UI redirection.


The PageAbility has a UI. It can use **startAbility()** to start an ability that has a UI and is visible to users.


The **visible** field under **abilities** in the **config.json** file specifies whether an ability can be started by other application components.

**Table 1** Description of visible

| Name| Description| Initial Value Allowed|
| -------- | -------- | -------- |
| visible | Whether the ability can be called by other applications.<br>**true**: The ability can be called by any application.<br>**false**: The ability can be called only by other components of the same application.| Yes (initial value: **false**)|


To enable an ability to be called by any application, configure the **config.json** file as follows:

```json
{
  "module": {
    ...
    "abilities": [
      {
        "visible": "true",
        ...
      }
    ]
  }
}
```


If the ability contains **skills**, you are advised to set **visible** to **true** so that the ability can be [implicitly started](explicit-implicit-want-mappings.md) by other applications. If this attribute is set to **false**, the system returns **PERMISSION_DENIED** when other applications attempt to start the ability. In this case, a system application can request the <!--Del-->[<!--DelEnd-->START_INVISIBLE_ABILITY<!--Del-->](../security/AccessToken/permissions-for-system-apps.md#ohospermissionstart_invisible_ability)<!--DelEnd--> permission to start the ability. Example abilities with **visible** set to **false** are the home screen, voice assistant, or search assistant.
