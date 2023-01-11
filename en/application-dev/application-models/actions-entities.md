# Common action and entities Values

The [action](../reference/apis/js-apis-ability-wantConstant.md#wantconstantaction) field specifies the common operation (such as viewing, sharing, and application details) to be performed by the caller. In implicit Want, you can define this field and use it together with **uri** or **parameters** to specify the operation to be performed on the data, for example, viewing URI data. For example, if the URI is a website and the action is **ohos.want.action.viewData**, the ability that supports website viewing is matched. Declaring the **action** field in Want indicates that the invoked application should support the declared operation. The **actions** field under **skills** in the configuration file indicates the operations supported by the application.

**Common action Values**


- **ACTION_HOME**: action of starting the application entry component. It must be used together with **ENTITY_HOME**. The application icon on the home screen is an explicit entry component. Users can touch the icon to start the entry component. Multiple entry components can be configured for an application.

- **ACTION_CHOOSE**: action of selecting local resource data, such as Contacts and Gallery. Generally, the system has corresponding Picker applications for different types of data.

- **ACTION_VIEW_DATA**: action of viewing data. A website URI indicates the action for opening the website.

- **ACTION_VIEW_MULTIPLE_DATA**: action of launching the UI for sending multiple data records.

The [entities](../reference/apis/js-apis-ability-wantConstant.md#wantconstantentity) field specifies the additional category information (such as browser and video player) of the target ability. It is a supplement to **action** in implicit Want. You can define this field to filter application categories, for example, browser. Declaring the **entities** field in Want indicates that the invoked application should belong to the declared category. The **entities** field under **skills** in the configuration file indicates the categories supported by the application.

**Common entities Values**


- **ENTITY_DEFAULT**: default category, which is meaningless.

- **ENTITY_HOME**: abilities with an icon displayed on the home screen.

- **ENTITY_BROWSABLE**: browser type.
