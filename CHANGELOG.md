# Estimote Bluetooth Scanning Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.0.7] - 2019-10-02
### Fixed:
- corrected headers and imports within the library.

## [1.0.6] - 2019-09-19
### Fixed:
- iOS 13 compatibility

## [1.0.5] - 2019-06-10
### Fixed:
- `isPressed` flag is back _nonnullable_. Only in previous release (1.0.4) it was _nullable_.
- minor code cleanup and bugfixing.

## [1.0.4] - 2019-06-06

### Fixed:
- Enhanced support for LTE beacon's packet (0.1.0+ versions).

## [1.0.3] - 2019-05-07

### Added:
- Support for next generation of LTE beacon's packets.

### Changed:
- `EBSScanInfoLTEConnectivity` assumes nonnullability, except for  `appVersion`, `bootloaderVersion`, `isPressed`. Next generation of LTE beacon's packet does not contain any information regarding these properties.

## [1.0.2] - 2019-04-26

### Fixed

- Corrected validation of the LTE beacon packet's app and boo version to support firmwares 0.0.12+

## [1.0.1] - 2019-04-16

### Fixed

- Parsing different LTE beacon's firmware versions, so beacons with firmware 0.0.9 - 0.0.13 would be detectable.

## [1.0.0] - 2019-02-01

### Added

- LTE Connectivity packet has a new flag indicating if LTE beacon's button was pressed. This flag should be toggled for a limited time (most likely 10 seconds).
- Support for iOS 10.0

## [0.3.0-lte] - 2018-08-27

### Added

- Support for LTE Connectivity packet.
- Sample apps for ease of developement.

## [0.2.0] - 2018-02-22

### Added

- Added inits for `EBSScanInfoLocationConnectivity`, `EBSScanInfoEstimoteTelemetryA`, `EBSScanInfoEstimoteTelemetryB`.

### Changed

- Renamed `advertisementData` to `serviceData` in `EBSScanInfoEstimoteEncrypted`.
- Updated `EBSScanInfoFrameType` enum's cases to fit Estimote packet names.

### Fixed

- Fixed warning on `EBSUniversalScanner`'s `state` property by using a custom enum instead of deprecated `CBCentralManagerState`.


## [0.1.1] - 2018-02-07

### Added

- Added `EBSScanInfoEstimoteEncrypted`. It allows scanning for frames encrypted with Estimote Secure Monitoring.


## [0.1.0] - 2018-01-22

### Added

- Added `EBSScanInfoGeneric` that scans for any packet with Estimote Service UUID that wasn't deserialized by other ScanInfo classes.


## [0.0.5] - 2018-01-04

### Changed

- Changed type of EstimoteBluetoothScanning to dynamic framework with slices for both iOS Simulator & iOS Device architectures.


## [0.0.4] - 2018-01-04

### Added

- Universal scanner has a protocol now (`EBSUniversalScannerProtocol`).
- The framework now contains a module map so it should be visible by dynamic frameworks.

### Changed

- `EBSUniversalScannerDelegate` methods changed the first parameter type from `EBSUniversalScanner *` to `id<EBSUniversalScannerProtocol>`.
- Scanning uses a different restarting rule now. It should result in more data when the app is in the background.
