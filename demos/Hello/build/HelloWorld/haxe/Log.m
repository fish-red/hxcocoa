//
//  Log
//  HelloWorld
//
//  Source generated by Haxe Objective-C target
//

#import "../haxe/Log.h"

@implementation Log

// Dynamic method defined with an objc method and a block property
+ (void)trace:(id)v infos:(id)infos {
	// Optional arguments
	if (!infos) infos = nil;
	
	printf("%s:%s: %s\n",
		   [[infos objectForKey:@"fileName"] cStringUsingEncoding:NSStringEncodingConversionAllowLossy],
		   [[infos objectForKey:@"lineNumber"] cStringUsingEncoding:NSStringEncodingConversionAllowLossy],
		   [[v description] cStringUsingEncoding:NSStringEncodingConversionAllowLossy]);
}
@synthesize hx_dyn_trace;


@end
