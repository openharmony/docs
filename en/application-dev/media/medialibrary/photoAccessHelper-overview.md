# Introduction to Media Library Kit
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Media Library Kit provides the capabilities of managing albums and media files, including images and videos, to enable your application to quickly display images and play back videos.

## Available Capabilities

With Media Library Kit, you can manage albums and media files, including creating and accessing albums and modifying media assets in albums.

The following capabilities are opened to all applications:

- Selecting or saving media assets
  - [Selecting Media Assets Using Picker](photoAccessHelper-photoviewpicker.md)
  - [Saving Media Assets](photoAccessHelper-savebutton.md)
- Managing moving photos
  - [Accessing and Managing Moving Photos](photoAccessHelper-movingphoto.md)
  - [Playing Moving Photos with MovingPhotoView](movingphotoview-guidelines.md)
<!--RP2--><!--RP2End-->

The following capabilities are restrictedly opened to third-party applications:

> **NOTE**
>
> To use the restricted open capabilities, the application must have the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions). <!--RP1-->The following permissions are opened to third-party applications with certain restrictions.<!--RP1End-->

- [Media asset management](photoAccessHelper-resource-guidelines.md), including:
  - Obtaining media assets
  - Obtaining image and video thumbnails
  - Renaming a media asset
- [User album management](photoAccessHelper-userAlbum-guidelines.md), including:
  - Obtaining a user album
  - Renaming a user album
  - Adding images and videos to a user album.
  - Obtaining images and videos from a user album
  - Removing images and videos from a user album
- [Management of system albums](photoAccessHelper-systemAlbum-guidelines.md), including:
  - Favorites
  - Video album
- [Change notifications of images, videos, and albums](photoAccessHelper-notify-guidelines.md), including:
  - Registering a listener for the specified URI
  - Unregistering a listener for the specified URI

<!--Del-->
The following capabilities are opened to system applications:

- Media asset operations, including:
  - Creating a media asset
  - Moving a media asset to the trash
  - Deleting a media asset permanently

- Album-related operations, including:
  - Creating a user album
  - Deleting a user album
  - Hiding an album
  - Favoriting and unfavoriting an album
  - Using the Screenshots album
<!--DelEnd-->

## Features

- Simple and efficient development thanks to object-based API design.
- Integrated device-cloud access management.
- Precise security control and automatic authorization with Pickers and security component **SaveButton**.
- Intelligent format conversion completed at the framework layer in a unified manner.

## Working Principles

The media library receives requests for obtaining or changing media assets from users, verifies the request validity and permissions, interacts with the database if the verification is successful, and returns the result.
