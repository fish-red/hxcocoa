//
//  MKMapItem.h
//  MapKit
//
//  Copyright 2011-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MapKit/MKPlacemark.h>

MK_CLASS_AVAILABLE(NA, 6_0)
extern class MKMapItem extends NSObject

// If this MKMapItem represents your current location (isCurrentLocation == YES), then placemark will be nil.
	public var (default, null) MKPlacemark *placemark;
	public var BOOL isCurrentLocation;

	public var String *name;
	public var String *phoneNumber;
	public var NSURL *url;

+ (MKMapItem *)mapItemForCurrentLocation;
- (id)initWithPlacemark:(MKPlacemark *)placemark;

- (BOOL)openInMapsWithLaunchOptions:(NSDictionary *)launchOptions;
+ (BOOL)openMapsWithItems:(NSArray *)mapItems launchOptions:(NSDictionary *)launchOptions;

}

MK_EXTERN String * const MKLaunchOptionsDirectionsModeKey     NS_AVAILABLE_IOS(6_0); // Key to a directions mode
MK_EXTERN String * const MKLaunchOptionsMapTypeKey            NS_AVAILABLE_IOS(6_0); // Key to an NSNumber corresponding to a MKMapType
MK_EXTERN String * const MKLaunchOptionsMapCenterKey          NS_AVAILABLE_IOS(6_0); // Key to an NSValue-encoded MKCoordinate
MK_EXTERN String * const MKLaunchOptionsMapSpanKey            NS_AVAILABLE_IOS(6_0); // Key to an NSValue-encoded MKCoordinateSpan
MK_EXTERN String * const MKLaunchOptionsShowsTrafficKey       NS_AVAILABLE_IOS(6_0); // Key to a boolean NSNumber

// Directions modes
MK_EXTERN String * const MKLaunchOptionsDirectionsModeDriving NS_AVAILABLE_IOS(6_0);
MK_EXTERN String * const MKLaunchOptionsDirectionsModeWalking NS_AVAILABLE_IOS(6_0);
