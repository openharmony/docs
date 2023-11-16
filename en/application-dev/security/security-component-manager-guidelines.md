# Security Component Development


## When to Use

Security components are a set of ArkUI components provided by OpenHarmony. You can integrate the security components to your app UI. The security components come with automatic authorization, which eliminates authorization dialog boxes.

Currently, OpenHarmony provides security components **\<LocationButton>**, **\<PasteButton>**, and **\<SaveButton>**, with precise positioning, clipboard reading, and media library writing permissions, respectively.

- **\<LocationButton>**

  When **\<LocationButton>** is tapped, the app can call the location service to obtain the precise location no matter whether the app has applied for or is granted with the precise location permission. The temporary authorization for precise location remains valid until the screen is turned off, the app is switched to the background, or the app exits. Then, the permission state transits to the state prior to the temporary authorization. During the temporary authorization period, there is no limit on the number of times that the app calls the APIs that request the permission.

  You can use the **\<LocationButton>** component for apps that may use the location information in certain scenarios, such as city location, clock-in/out, and location sharing. This component is not applicable for location-based apps, such as navigation and health apps. If location information needs to be used for a long period of time or in the background, apply for the location permission for your app.

- **\<PasteButton>**

  When **\<PasteButton>** is tapped, the app can call the API to read data from the clipboard. The temporary authorization for reading data from the clipboard remains invalid until the screen is turned off, the app is switched to the background, or the app exits. During the temporary authorization period, there is no limit on the number of times that the app calls the API for reading data from the clipboard.

  You can use the **\<PasteButton>** component for apps that need to read data from the clipboard.

- **\<SaveButton>**

  When **\<SaveButton>** is tapped, the app can access the privileged APIs of the media library without limitation within 10 seconds.

  When using **\<SaveButton>**, observe the following:

  - The interval for calling **onClick()** to trigger a **mediaLibrary** API cannot exceed 10 seconds after **\<SaveButton>** is tapped.
  - Each time **\<SaveButton>** is tapped, the app can access the privileged APIs multiple times.

You can use **\<SaveButton>** for apps that need to save files to the media library (such as saving images and videos). The **\<SaveButton>** component features simpler and faster operations than **filePicker**, which needs to start the system application and requires the user to select a directory for saving the file.


## Creating a Security Component

A security component is a button consisting of an icon, text, and background. Either the icon or text is mandatory, and the background is optional. The icon and text cannot be customized. You can only select from the existing options. 

When declaring the API for creating a security component, you can determine whether to pass in parameters. If parameters are passed in, the component is created based on the specified parameters. If no parameter is passed in, a component with default icon, text, and background is created.

The following uses the **\<SaveButton>** component as an example.

```
/* Create a default <SaveButton>. */
SaveButton()

/* Create a <SaveButton> with the icon only. */
SaveButton({ icon:SaveIconStyle.FULL_FILLED })

/* Create a <SaveButton> with the text and icon only. */
SaveButton({ icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD })
```


## Common Attributes

The following table describes the common UX attributes for security components.

| Attribute| Description|
| -------- | -------- |
| iconSize(value: Dimension) | Icon size of the security component.|
| layoutDirection(value: SecurityComponentLayoutDirection) | Direction of the icon and text on the security component.|
| position(value: Position) | Absolute position of the security component.|
| markAnchor(value: Position) | Anchor for the absolute position.|
| offset(value: Position) | Offset of the position of the security component.|
| fontSize(value: Dimension) | Font size of the text on the security component.|
| fontStyle(value: FontStyle) | Font style of the text on the security component.|
| fontWeight(value: number \| FontWeight \| string) | Font weight of the text on the security component.|
| fontFamily(value: string \| Resource) | Font family of the text on the security component.|
| fontColor(value: ResourceColor) | Font color of the text on the security component.|
| iconColor(value: ResourceColor) | Color of the icon on the security component.|
| backgroundColor(value: ResourceColor) | Background color of the icon on the security component.|
| borderStyle(value: BorderStyle) | Border style of the security component.|
| borderWidth(value: Dimension) | Border width of the security component.|
| borderColor(value: ResourceColor) | Border color of the security component.|
| borderRadius(value: Dimension) | Radius of the rounded border corners of the security component.|
| padding(value: Padding \| Dimension) | Inner margins of the security component.|
| textIconSpace(value: Dimension) | Space between the icon and text on the security component.|


## How to Develop

1. Declare the security component in the .ets file.
   ```
      LocationButton()
   ```

2. Configure the attributes of the security component.
   ```
      LocationButton().iconSize(40.0)
   ```

3. Register the **onClick** callback for calling the API protected by the permission. The following uses the **\<LocationButton>** component as an example.
   ```
   import geoLocationManager from '@ohos.geoLocationManager';
   import BusinessError from "@ohos.base";
   @Entry
   @Component
   struct locationButton {
     build() {
       Row() {
         Column() {
           LocationButton({ icon: LocationIconStyle.FULL_FILLED }).iconSize(40.0)
             .onClick((event: ClickEvent, result: LocationButtonOnClickResult) => {
               if (result == LocationButtonOnClickResult.SUCCESS) {
                 /* The API to call is js-apis-geoLocationManager.md#currentlocationrequest. */
                 let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
                 let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location):void => {
                   if (err) {
                     console.log('locationChanger: err=' + JSON.stringify(err));
                   }
                   if (location) {
                     console.log('locationChanger: location=' + JSON.stringify(location));
                   }
                 };

                 try {
                   geoLocationManager.getCurrentLocation(requestInfo, locationChange);
                 } catch (err) {
                   console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
                 }
               }
             })
         }.width('100%')
       }.height('100%')
     }
   }
   ```
