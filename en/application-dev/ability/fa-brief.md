# FA Model Overview

## Overall Architecture
The development of an OpenHarmony application is essentially the development of one or more abilities. By scheduling abilities and managing their lifecycle, OpenHarmony implements application scheduling.

The Feature Ability (FA) model applies to application development using API version 8 and earlier versions. In this model, there are Page, Service, Data, and Form abilities.  
- The Page ability implements the ArkUI and provides the capability of interacting with users.
- The Service ability does not have a UI. It runs in the background and provides custom services for other abilities to invoke. 
- The Data ability does not have a UI. It runs in the background and enables other abilities to insert, delete, and query data.
- The Form ability provides a widget, which is a UI display mode.

## Lifecycle

Among all abilities, the Page ability has the most complex lifecycle, because it has a UI and acts as a touchpoint for interacting with users.

**The following figure shows the lifecycle of the Page ability.**

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)

The other abilities do not involve the foreground/background switchover and the **onShow** callback.
You can override the lifecycle callbacks in **app.js/app.ets** to process application logic.

Currently, the **app.js** file provides only the **onCreate** and **onDestroy** callbacks, and the **app.ets** file provides the full lifecycle callbacks.


## Process and Thread Model
An application exclusively uses an independent process, and an ability exclusively uses an independent thread. When an ability is started for the first time, an application process as well as a thread for this ability is created. After the application is started, other abilities in the application are started, and a thread is created for every of these started abilities. Each ability is bound to an independent JSRuntime instance. In this way, abilities are isolated from each other.

![fa-threading-model](figures/fa-threading-model.png)

## Application Package Structure

For details about the project directory structure of the FA model, see [OpenHarmony Project Overview](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-project-overview-0000001218440650#section4154183910141).

For details about how to configure the application package structure of the FA model, see [Application Package Structure Configuration File](../quick-start/package-structure.md).
