/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBControlCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A Value object that represents the Configuration of a iPhone, iPad, Watch or TV Simulator.

 Class is designed around maximum convenience for specifying a configuration.
 For example to specify an iPad 2 on iOS 8.2:
 `FBSimulatorConfiguration.iPad2.iOS_8_2`.

 It is also possible to specify configurations based on a NSString.
 This is helpful when creating a device from something specified in an Environment Variable:
 `[FBSimulatorConfiguration.iPhone5 iOS:NSProcessInfo.processInfo.environment[@"TARGET_OS"]]`
 */
@interface FBSimulatorConfiguration : NSObject <NSCopying, NSCoding, FBJSONSerializable, FBDebugDescribeable>

#pragma mark Properties

/**
 The Device Configuration.
 */
@property (nonatomic, strong, readonly) id<FBControlCoreConfiguration_Device> device;

/**
 The OS Configuration.
 */
@property (nonatomic, strong, readonly) id<FBControlCoreConfiguration_OS> os;

/**
 The Name of the Device to Simulate. Must not be nil.
 */
@property (nonatomic, copy, readonly) FBDeviceName deviceName;

/**
 A String Representation of the OS Version of the Simulator. Must not be nil.
 */
@property (nonatomic, copy, readonly) NSString *osVersionString;

/**
 A String Representation of the Instruction Set Architecture of the Simulator. Must not be nil.
 */
@property (nonatomic, copy, readonly) NSString *architecture;

/**
 The Location to store auxillary files in.
 Auxillary files are stored per-simulator, so will be nested inside directories for each Simulator.
 If no path is provided, a default Auxillary directory inside the Simulator's data directory will be used.
 */
@property (nonatomic, copy, nullable, readonly) NSString *auxillaryDirectory;

/**
 Returns the Default Configuration.
 The OS Version is derived from the SDK Version.
 */
+ (instancetype)defaultConfiguration;

#pragma mark - Devices

/**
 A Configuration with the provided Device Configuration.
 */
+ (instancetype)withDevice:(id<FBControlCoreConfiguration_Device>)device;
- (instancetype)withDevice:(id<FBControlCoreConfiguration_Device>)device;

/**
 A Configuration with the provided Device Name.
 Will assert if the deviceName is not a valid Device Name.
 */
+ (instancetype)withDeviceNamed:(FBDeviceName)deviceName;
- (instancetype)withDeviceNamed:(FBDeviceName)deviceName;

#pragma mark - OS Versions

/**
 A Configuration with the provided OS.
 */
+ (instancetype)withOS:(id<FBControlCoreConfiguration_OS>)os;
- (instancetype)withOS:(id<FBControlCoreConfiguration_OS>)os;

/**
 A Configuration with the provided OS Name.
 Will assert if the deviceName is not a valid Device Name.
 */
+ (instancetype)withOSNamed:(FBOSVersionName)osName;
- (instancetype)withOSNamed:(FBOSVersionName)osName;

#pragma mark Auxillary Directory

/**
 Updates the Auxillary Directory.
 */
- (instancetype)withAuxillaryDirectory:(NSString *)auxillaryDirectory;

@end

NS_ASSUME_NONNULL_END
