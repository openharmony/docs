# Distributed Data Management Changelog

 

## cl.distributeddatamgr.1 Added Error Code 15700013 to Some DataShareHelper APIs

The **close()** API can be used to close the **DataShareHelper** instance. If **insert()**, **update()**, or **on()** is called after the **DataShareHelper** instance is clsed, error code 15700013 will be thrown. For details, see [DataShare](../../../application-dev/reference/apis-arkdata/js-apis-data-dataShare-sys.md).

**Access Level**

System API

**Reason for Change** 

The **close()** interface can be used to close the **DataShareHelper** instance.

**Change Impact**

Before the change: 

The service does not proactively close the **DataShareHelper** instance.

After the change: 

After the service closes the **DataShareHelper** instance, you need to create a new **DataShareHelper** instance when it is required.

**Start API Level** 

9

**Change Since**

OpenHarmony SDK 5.0.0.20
