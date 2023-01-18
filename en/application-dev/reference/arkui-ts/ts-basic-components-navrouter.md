# NavRouter

The **\<NavRouter>** component provides default logic for click response processing, eliminating the need for manual logic definition.

> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component must contain two child components, the second of which must be **[\<NavDestination>](ts-basic-components-navdestination.md)**.

## APIs

NavRouter()


## Events

| Name                                                    | Description                                                  |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| onStateChange(callback: (isActivated: boolean) => void) | Invoked when the component activation status changes. The value **true** means that component is activated, and **false** means the opposite.<br>**NOTE**<br>After the user clicks **NavRouter**, if the **\<NavRouter>** component is activated and the corresponding **\<NavDestination>** child component loaded, **onStateChange(true)** is called. If the corresponding **\<NavDestination>** child component is no longer displayed, **onStateChange(false)** is called. |
