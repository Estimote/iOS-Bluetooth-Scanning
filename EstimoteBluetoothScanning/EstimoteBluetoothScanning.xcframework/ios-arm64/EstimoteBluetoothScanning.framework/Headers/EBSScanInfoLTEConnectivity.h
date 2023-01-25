//
//    ____  _            _              _   _       ____                        _
//   | __ )| |_   _  ___| |_ ___   ___ | |_| |__   / ___|  ___ __ _ _ __  _ __ (_)_ __   __ _
//   |  _ \| | | | |/ _ \ __/ _ \ / _ \| __| '_ \  \___ \ / __/ _` | '_ \| '_ \| | '_ \ / _` |
//   | |_) | | |_| |  __/ || (_) | (_) | |_| | | |  ___) | (_| (_| | | | | | | | | | | | (_| |
//   |____/|_|\__,_|\___|\__\___/ \___/ \__|_| |_| |____/ \___\__,_|_| |_|_| |_|_|_| |_|\__, |
//                                                                                      |___/
//
//
//  Copyright © 2018 Estimote. All rights reserved.

#import <Foundation/Foundation.h>
#import "EBSScanInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Connectivity packet of LTE beacons.
 */
@interface EBSScanInfoLTEConnectivity : EBSScanInfo

/**
 *  Cloud identifier of discovered device.
 */
@property (nonatomic, strong, readonly) NSString *publicID;

/**
 *  Version of application running on the device.
 */
@property (nonatomic, strong, readonly, nullable) NSString *appVersion;

/**
 *  Version of bootloader running on the device.
 */
@property (nonatomic, strong, readonly, nullable) NSString *bootloaderVersion;

/**
 *  Flag indicating if beacon's button was pressed.
 */
@property (nonatomic, strong, readonly) NSNumber *isPressed;

/**
 *  Device family version.
 */
@property (nonatomic, strong, readonly) NSNumber* deviceFamily;

/**
 Initializer.

 @param peripheralIdentifier Identifier of scanned peripheral.
 @param rssi RSSI value measured during the scan.
 @param scanDate Time when the device was scanned.
 @param publicID Cloud identifier of discovered device.
 @param appVersion Version of application running on the device.
 @param bootloaderVersion Version of bootloader running on the device.
 
 */

/// Initializer.
/// @param peripheralIdentifier Identifier of scanned peripheral.
/// @param rssi RSSI value measured during the scan.
/// @param scanDate Time when the device was scanned.
/// @param publicID Cloud identifier of discovered device.
/// @param appVersion Version of application running on the device.
/// @param bootloaderVersion Version of bootloader running on the device.
/// @param isPressed Flag inidcation if beacon's button was pressed.
/// @param deviceFamily Device's family.
- (instancetype)initWithPeripheralIdentifier:(NSUUID *)peripheralIdentifier
                                        rssi:(NSNumber *)rssi
                                    scanDate:(NSDate *)scanDate
                                    publicID:(NSString *)publicID
                                  appVersion:(nullable NSString *)appVersion
                           bootloaderVersion:(nullable NSString *)bootloaderVersion
                                   isPressed:(NSNumber *)isPressed
                                deviceFamily:(NSNumber *)deviceFamily;

@end

NS_ASSUME_NONNULL_END
