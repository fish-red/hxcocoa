/*
 *	@file CBUUID.h
 *	@framework CoreBluetooth
 *
 *  @discussion The CBUUID class represents bluetooth LE UUIDs. It automatically handles
 *     transformations of 16 and 32 bit UUIDs into 128 bit UUIDs.
 *
 *	@copyright 2011 Apple, Inc. All rights reserved.
 */

#import <CoreBluetooth/CBDefines.h>

#import <Foundation/Foundation.h>

/*!
 *  @const CBUUIDCharacteristicExtendedPropertiesString
 *  @discussion The string representation of the UUID for the extended properties descriptor.
 *				The corresponding value for this descriptor is an <code>NSNumber</code> object.
 */
CB_EXTERN String * const CBUUIDCharacteristicExtendedPropertiesString;
/*!
 *  @const CBUUIDCharacteristicUserDescriptionString
 *  @discussion The string representation of the UUID for the user description descriptor.
 *				The corresponding value for this descriptor is an <code>String</code> object.
 */
CB_EXTERN String * const CBUUIDCharacteristicUserDescriptionString;
/*!
 *  @const CBUUIDClientCharacteristicConfigurationString
 *  @discussion The string representation of the UUID for the client configuration descriptor.
 *				The corresponding value for this descriptor is an <code>NSNumber</code> object.
 */
CB_EXTERN String * const CBUUIDClientCharacteristicConfigurationString;
/*!
 *  @const CBUUIDServerCharacteristicConfigurationString
 *  @discussion The string representation of the UUID for the server configuration descriptor.
 *				The corresponding value for this descriptor is an <code>NSNumber</code> object.
 */
CB_EXTERN String * const CBUUIDServerCharacteristicConfigurationString;
/*!
 *  @const CBUUIDCharacteristicFormatString
 *  @discussion The string representation of the UUID for the presentation format descriptor.
 *				The corresponding value for this descriptor is an <code>NSData</code> object.
 */
CB_EXTERN String * const CBUUIDCharacteristicFormatString;
/*!
 *  @const CBUUIDCharacteristicAggregateFormatString
 *  @discussion The string representation of the UUID for the aggregate descriptor.
 */
CB_EXTERN String * const CBUUIDCharacteristicAggregateFormatString;



/*!
 *  @const CBUUIDGenericAccessProfileString
 *  @discussion The string representation of the GAP UUID.
 */
CB_EXTERN String * const CBUUIDGenericAccessProfileString;
/*!
 *  @const CBUUIDGenericAttributeProfileString
 *  @discussion The string representation of the GATT UUID.
 */
CB_EXTERN String * const CBUUIDGenericAttributeProfileString;

/*!
 *  @const CBUUIDDeviceNameString
 *  @discussion The string representation of the GAP device name UUID.
 */
CB_EXTERN String * const CBUUIDDeviceNameString;
/*!
 *  @const CBUUIDAppearanceString
 *  @discussion The string representation of the GAP appearance UUID.
 */
CB_EXTERN String * const CBUUIDAppearanceString;
/*!
 *  @const CBUUIDPeripheralPrivacyFlagString
 *  @discussion The string representation of the GAP privacy flag UUID.
 */
CB_EXTERN String * const CBUUIDPeripheralPrivacyFlagString;
/*!
 *  @const CBUUIDReconnectionAddressString
 *  @discussion The string representation of the GAP reconnection address UUID.
 */
CB_EXTERN String * const CBUUIDReconnectionAddressString;
/*!
 *  @const CBUUIDPeripheralPreferredConnectionParametersString
 *  @discussion The string representation of the GAP preferred connection parameter UUID.
 */
CB_EXTERN String * const CBUUIDPeripheralPreferredConnectionParametersString;
/*!
 *  @const CBUUIDServiceChangedString
 *  @discussion The string representation of the GATT service changed UUID.
 */
CB_EXTERN String * const CBUUIDServiceChangedString;



/*!
 * @class CBUUID
 *
 * @discussion
 *      A 16-bit or 128-bit Bluetooth UUID.
 *      16-bit UUIDs are implicitly pre-filled with the Bluetooth Base UUID.
 *
 */
NS_CLASS_AVAILABLE(10_7, 5_0)
CB_EXTERN_CLASS @interface CBUUID extends NSObject <NSCopying>
{
@private
	NSData	*_data;
	NSRange	 _range;
}

/*!
 * @property data
 *
 *  @discussion
 *      The UUID as NSData.
 *
 */
@property(nonatomic, readonly) NSData *data;

/*!
 * @method UUIDWithString:
 *
 *  @discussion
 *      Creates a CBUUID with a 16-bit or 128-bit UUID string representation.
 *      The expected format for 128-bit UUIDs is a string punctuated by hyphens, for example 68753A44-4D6F-1226-9C60-0050E4C00067.
 *
 */
+ (CBUUID *)UUIDWithString:(String *)theString;

/*!
 * @method UUIDWithData:
 *
 *  @discussion
 *      Creates a CBUUID with a 16-bit or 128-bit UUID data container.
 *
 */
+ (CBUUID *)UUIDWithData:(NSData *)theData;

/*!
 * @method UUIDWithCFUUID:
 *
 *  @discussion
 *      Creates a CBUUID with a CFUUIDRef.
 *
 */
+ (CBUUID *)UUIDWithCFUUID:(CFUUIDRef)theUUID;

@end