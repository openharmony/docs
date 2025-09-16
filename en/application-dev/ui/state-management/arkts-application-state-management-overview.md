# Application State Management Overview
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->


The decorators described in the previous topics are used to share state variables within a page, that is, within a component tree. If you want to share state data at the application level or across multiple pages, you would need to apply application-level state management. ArkTS provides a wide variety of application state management capabilities:


- [LocalStorage](arkts-localstorage.md): API for storing the UI state, usually used for state sharing within a [UIAbility](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) or between pages.

- [AppStorage](arkts-appstorage.md): special, singleton LocalStorage object within the application, which is created by the UI framework at application startup and provides the central storage for application UI state attributes.

- [PersistentStorage](arkts-persiststorage.md): API for persisting application attributes. It is usually used together with AppStorage to persist selected AppStorage attributes to the disk so that their values are the same upon application re-start as they were when the application was closed.

- [Environment](arkts-environment.md): a range of environment parameters regarding the device where the application runs. The environment parameters are synchronized to AppStorage and can be used together with AppStorage.
