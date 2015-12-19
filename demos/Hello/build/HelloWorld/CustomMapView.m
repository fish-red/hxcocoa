//
//  CustomMapView
//  HelloWorld
//
//  Source generated by Haxe Objective-C target
//

#import "CustomMapView.h"

@implementation CustomMapView

- (void)locate:(float)lat _long:(float)_long zoom:(float)zoom {
	
	CLLocationCoordinate2D zoomLocation;
	zoomLocation.latitude = lat;
	zoomLocation.longitude = _long;
	MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance (zoomLocation, 40000, 40000);
	MKCoordinateRegion adjustedRegion = [self regionThatFits:viewRegion];
	[self setRegion:adjustedRegion animated:YES];
}
- (void)locateMe {
	
	self.showsUserLocation = YES;
}
- (void)locateLondon {
	
	[self locate:51.4788 _long:0.0106 zoom:1.2];
}

@end
