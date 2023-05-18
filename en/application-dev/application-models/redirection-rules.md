# Redirection Rules


Generally, UI redirection within an application is triggered by users. However, an application can call **startAbility()** to implement UI redirection.


The PageAbility has a UI. It can use **startAbility()** to start an ability that has a UI and is visible to users.


The **exported** field under **abilities** in the **config.json** file specifies whether an ability can be started by other application components.


**Table 1** Description of exported

| Name| Description| Initial Value Allowed|
| -------- | -------- | -------- |
| exported | Whether the ability can be called by other applications.<br>**true**: The ability can be called by any application.<br>**false**: The ability can be called only by other components of the same application.| Yes (initial value: **false**)|


To enable an ability to be called by any application, configure the **config.json** file as follows:

```ts
{
  "module": {
    // ...
    "abilities": [
      {
        "exported": "true",
        // ...
      }
    ]
  }
}
```


If the ability contains **skills**, you are advised to set **exported** to **true** so that the ability can be [implicitly started](explicit-implicit-want-mappings.md#matching-rules-of-implicit-want) by other applications. If this attribute is set to **false**, the system returns **PERMISSION_DENIED** when other applications attempt to start the ability. In this case, a system application can request the [START_INVISIBLE_ABILITY](../security/permission-list.md) permission to start the ability. Example abilities with **exported** set to **false** are home screen, voice assistant, or search assistant.
