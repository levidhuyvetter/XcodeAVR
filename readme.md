# XcodeAVR
This project aims to create a custom platform plugin for Xcode. Unlike other "external build system" templates we are aiming to fully integrate with most of the features that Xcode offers.
The project is currently in an experimental stage and serves as a bare minimum starting point for something that will actually load into Xcode.

## Goals
- [x] AVR category and templates in template chooser;
- [x] Custom product for templates that results in a .elf file;
- [x] Custom toolchain with clang and gcc built for AVR;
- [x] Get Xcode to use clang to compile for AVR;
- [x] Custom base SDK with AVR-LIBC headers and libraries;
- [x] Get Xcode to recognise programmers as destination device;
- [ ] Get Xcode to use avrdude to upload to AVR device on run;
- [ ] Get Xcode to use the AVR-GDB debugger;
- [ ] Get Xcode to use debug view as a serial monitor;

## Project Structure

- AVR.platform ("Platform" target: main product to be installed in /Applications/Xcode.app/Contents/Developer/Platforms)
  - AVR.sdk ("SDK" target: sets up an SDK with AVR-LIBC headers and libraries)
  - Base.xctemplate ("Template" target: defines a non-concrete template to serve as a base)
    - Application.xctemplate ("AppTemplate" target: defines a concrete template for a project that blinks an LED)
  - IDEAVRPlatfromSupportCore.ideplugin ("Core" target: integration with Xcode for devices, compilers, debuggers, etc...)
- AVR.xctoolchain ("Toolchain" target: toolchain with clang and gcc built with AVR target)

## Contributing

As Xcode currently doesn't load plugins signed by third party certificates, you will need to re-codesign Xcode with the same certificate used to sign when building this project.
A simple self-signed certificate with private key is included in the repository, the password to open certificate.p12 is "XcodeAVR". While testing, I strongly suggest you make a copy of the full Xcode application. This will allow you to open the project in your main Xcode copy and use the second copy to run with the platform, it also prevents from have to re-codesign your main Xcode copy which could cause problems when trying to submit apps to the app store.

### Making a re-codesigned copy of Xcode

- Open certificate.p12 with password "XcodeAVR" and install to your login keychain;
- Make a copy of Xcode.app;
```sudo cp /Applications/Xcode.app /Applications.XcodeAVR.app```
- Re-codesign your copy of Xcode;
```sudo codesign -f -s XcodeAVR /Applications/XcodeAVR.app```

### Setting up the project to use XcodeAVR.app

- In the build settings for the "Core" target, ensure it is set up to sign with the XcodeAVR certificate;
- Edit the "Platform" scheme and set /Applications/XcodeAVR.app as the executable to run and debug;
- If you have named your copy of Xcode differently or it is in a different location, you will have to adjust the "Install Platform" build phase in the "Platform" target;
- Build the "Toolchain" target and copy AVR.toolchain to ~/Library/Developer/Toolchains (or equivalent system directory);
- You can now edit the project in your main copy of Xcode, once you press run it will copy the platform bundle to your copy of Xcode and then run and debug the copy;
