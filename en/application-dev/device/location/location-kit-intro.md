# Introduction to Location Kit

## Overview

People take their mobile devices wherever they go. Mobile devices have become a necessity in people's daily routines, whether it be for looking at the weather forecast, browsing news, hailing a taxi, navigating, or recording data from a workout. All these activities are so much associated with the location services on mobile devices.

With the location awareness capability offered by OpenHarmony, mobile devices will be able to obtain real-time, accurate location data. Building location awareness into your application can also lead to a better contextual experience for application users.

Your application can call location-specific APIs to obtain the location information of a mobile device for offering location-based services such as drive navigation and motion track recording.

### Concepts

Location awareness helps determine where a mobile device locates. Location Kit allows your system to identify the location of a mobile device with its coordinates, and uses location technologies such as Global Navigation Satellite System (GNSS) and network positioning (for example, base station positioning or WLAN/Bluetooth positioning) to provide diverse location-based services.

These advanced location technologies make it possible to obtain the accurate location of the mobile device, regardless of whether it is indoors or outdoors.

- **Coordinate**<br>
  A coordinate describes a location on the earth using the longitude and latitude in reference to the World Geodetic Coordinate System 1984.

- **GNSS positioning**<br>
  GNSS positioning locates a mobile device by using the location algorithm offered by the device chip to compute the location information provided by the global navigation satellite system (GNSS), for example, GPS, GLONASS, BeiDou, and Galileo. Whichever positioning system will be used during the location process depends on a hardware capability of the device.

- **Base station positioning**<br>
  Base station positioning estimates the current location of a mobile device based on the location of the resident base station in reference to the neighboring base stations. This technology provides only a low accuracy and requires access to the cellular network.

- **WLAN or Bluetooth positioning**<br>
  WLAN or Bluetooth positioning estimates the current location of a mobile device based on the locations of WLANs and Bluetooth devices that can be discovered by the device. The location accuracy of this technology depends on the distribution of fixed WLAN access points (APs) and Bluetooth devices around the device. A high density of WLAN APs and Bluetooth devices can produce a more accurate location result than base station positioning. This technology also requires access to the network.


### Constraints

Location awareness is offered by the system as a basic service for applications. Depending on the service scenario, an application needs to initiate a location request to the system and stop the location request when the service scenario ends. In this process, the system reports the location information to the application on a real-time basis.

Your application can use the location function only after the user has granted the required permission and turned on the location function. If the location function is off, the system will not provide the location service for any application.

Since the location information is considered sensitive, your application still needs to obtain the location access permission from the user even if the user has turned on the location function. The system will provide the location service for your application only after it has been granted the permission to access the device location information.

Depending on the hardware support, Location Kit provides different capabilities on different devices. For example, a GPS or Beidou positioning chip provides devices with the GNSS positioning capabilities. If a WLAN or cellular network module, instead of a positioning chip, is available, then the devices can use the WLAN or base station positioning capabilities.
