# State Management with Application-level Variables (System API)


The state management module provides data storage, persistent data management, UIAbility data storage, and environment state required by applications.


>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>This topic describes only the system APIs provided by the module. For details about its public APIs, see [State Management with Application-level Variables](./ts-state-management.md).

## SubscribedAbstractProperty\<T\>

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### subscribers\_

protected subscribers_: Set\<number\>;

A set of subscribers.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description      |
|-----------|--------------|
|Set\<number\>  |A set of subscribers.|

### id\_

private id_;

Private member variable ID.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### info\_

private info\_\?;

Variable information.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(subscribeMe?: IPropertySubscriber,info?: string,);

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Variable properties.   |
|info   |string   |No  |Variable information.  |

### id

id(): number;

Obtains the ID.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description      |
|-----------|--------------|
|number  |Obtained ID.|

### createTwoWaySync

createTwoWaySync(subscribeMe?: IPropertySubscriber, info?: string): SyncedPropertyTwoWay\<T\>;

Creates two-way synchronization.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Variable properties.   |
|info   |string   |No  |Variable information.  |

**Return value**

|Type  |Description      |
|-----------|--------------|
|[SyncedPropertyTwoWay\<T\>](#syncedpropertytwowayt)  |Two-way synchronized property.|

### createOneWaySync

createOneWaySync(subscribeMe?: IPropertySubscriber, info?: string): SyncedPropertyOneWay\<T\>;

Creates one-way synchronization.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Variable properties.   |
|info   |string   |No  |Variable information.  |

**Return value**

|Type  |Description      |
|-----------|--------------|
|[SyncedPropertyOneWay\<T\>](#syncedpropertytwowayt)  |One-way synchronized property.|

### unlinkSuscriber

unlinkSuscriber(subscriberId: number): void;

Removes a subscriber.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscriberId   |number   |Yes  |ID of the subscriber to remove.   |

### notifyHasChanged

protected notifyHasChanged(newValue: T): void;

Notifies subscribers that the value has changed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value after the change.   |

### notifyPropertyRead

protected notifyPropertyRead(): void;

Notifies subscribers that the property has been read.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### numberOfSubscrbers

numberOfSubscrbers(): number;

Obtains the number of subscribers.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description      |
|-----------|--------------|
|number  |Number of subscribers.|

## IPropertySubscriber

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### id

id(): number;

Obtains the ID.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description      |
|-----------|--------------|
|number  |Variable ID obtained.|

### aboutToBeDeleted

aboutToBeDeleted(owningView?: IPropertySubscriber): void;

Called when the object is about to be destroyed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|owningView   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Component that owns the current property.   |

## SyncedPropertyTwoWay\<T\>

Inherits from [SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt). Represents a property with two-way synchronization.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### source\_

private source_;

Data source for the two-way synchronized property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(source: SubscribedAbstractProperty\<T\>, subscribeMe?: IPropertySubscriber, info?: string);

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|source   |[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)   |Yes  |Data source for the two-way synchronized property.   |
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Subscriber.  |
|info  |string   |No  |Additional information about the subscriber.  |

### aboutToBeDeleted

aboutToBeDeleted(unsubscribeMe?: IPropertySubscriber): void;

Called when the object is about to be destroyed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|unsubscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Subscriber to remove.   |

### hasChanged

hasChanged(newValue: T): void;

Notifies subscribers that the property value has changed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description  |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value of the property.    |

### get

get(): T;

Obtains the current value of the property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description    |
|------|------------|
|T   |Current value of the property.   |

### set

set(newValue: T): void;

Sets a new value for the property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value to set for the property.   |

## SyncedPropertyOneWay\<T\>

Inherits from [SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt). Represents a property with one-way synchronization.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### wrappedValue\_

private wrappedValue_;

Value used for one-way binding.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### source\_

private source_;

Data source for the one-way synchronized property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(source: SubscribedAbstractProperty\<T\>, subscribeMe?: IPropertySubscriber, info?: string);

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|source   |[SubscribedAbstractProperty\<T\>](#subscribedabstractpropertyt)   |Yes  |Data source for the one-way synchronized property.   |
|subscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Subscriber.  |
|info  |string   |No  |Additional information of the subscriber.  |

### aboutToBeDeleted

aboutToBeDeleted(unsubscribeMe?: IPropertySubscriber): void;

Called when the object is about to be destroyed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|unsubscribeMe   |[IPropertySubscriber](#ipropertysubscriber)   |No  |Subscriber to remove.   |

### hasChanged

hasChanged(newValue: T): void;

Notifies subscribers that the property value has changed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description  |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value of the property.    |

### get

get(): T;

Obtains the current value of the property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description    |
|------|------------|
|T   |Current value of the property.   |

### set

set(newValue: T): void;

Sets a new value for the property.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value to set for the property.   |

## ISinglePropertyChangeSubscriber\<T\>

Inherits from [IPropertySubscriber](#ipropertysubscriber). Represents a subscriber that subscribes to changes in a property value.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### hasChanged

hasChanged(newValue: T): void;

Notifies subscribers that the property value has changed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|newValue   |T   |Yes  |New value of the property.   |

## SubscribaleAbstract

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### owningProperties\_

private owningProperties_: Set\<number\>;

A set of property IDs that this instance owns.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

|Type  |Description    |
|------|------------|
|Set\<number\>   |A set of property IDs.   |

### constructor

constructor();

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### notifyPropertyHasChanged

protected notifyPropertyHasChanged(propName: string, newValue: any): void;

Notify subscribers that a property value has changed.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|propName   |string   |Yes  |Property name.   |
|newValue   |any   |No  |New value after the change.  |

### addOwningProperty

public addOwningProperty(subscriber: IPropertySubscriber): void;

Adds a subscriber to the list of owned properties.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscriber   |[IPropertySubscriber](#ipropertysubscriber)   |Yes  |Subscriber.   |

### removeOwningProperty

public removeOwningProperty(property: IPropertySubscriber): void;

Removes a subscriber from the list of owned properties.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|property   |[IPropertySubscriber](#ipropertysubscriber)   |Yes  |Subscriber to remove.   |

### removeOwningPropertyById

public removeOwningPropertyById(subscriberId: number): void;

Removes a subscriber from the list of owned properties by ID.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|subscriberId   |number   |Yes  |ID of the subscriber to remove.   |

## Environment

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor();

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## PersistentStorage

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor(appStorage: AppStorage, storage: Storage);

Constructor.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

|Name  |Type  |Mandatory  |Description            |
|---------|-----------|------------|--------------|
|appStorage   |AppStorage   |Yes  |Application-level storage.   |
|storage   |Storage   |Yes  |Storage.   |

## appStorage

declare const appStorage: AppStorage;

Defines the application-level storage.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

|Type   |Description         |
|----------|------------|
|AppStorage   |Application-level storage. |
