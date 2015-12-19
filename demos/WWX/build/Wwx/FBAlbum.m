//
//  FBAlbum
//  Wwx
//
//  Source generated by Haxe Objective-C target
//

#import "FBAlbum.h"

@implementation FBAlbum

- (void)dispatchLoadingEvent {
	
	[self onImageCached:self.image];
}
- (void)cacheImage:(NSData *)imageData {
	
	
	UIImage  *image2 = [[UIImage alloc] init];
	
	UIImage  *image3 = [[UIImage alloc]  initWithData:imageData];
	self.image = [[UIImage alloc]  initWithData:imageData];
	[self dispatchLoadingEvent];
}
- (void)loadImageData:(NSString *)url {
	
	
	NSData  *imageData = [[NSData alloc]  initWithContentsOfURL:[NSURL URLWithString:url]];
	[self performSelectorOnMainThread:@selector(cacheImage:) withObject:imageData waitUntilDone:NO];
}
- (void)preload {
	
	if (self.image != nil)  {
		
		[self dispatchLoadingEvent];
		return;
	}
	
	NSString  *url = [[@"https://graph.facebook.com/" stringByAppendingString:self.albumId] stringByAppendingString:@"/picture"];
	[NSThread detachNewThreadSelector:@selector(loadImageData:) toTarget:self withObject:url];
}
// Dynamic method defined with an objc method and a block property
- (void)onImageCached:(UIImage *)image {
	if ( hx_dyn_onImageCached ) { hx_dyn_onImageCached(image); return; }
}
@synthesize hx_dyn_onImageCached;

@synthesize delegate;
@synthesize image;
@synthesize name;
@synthesize albumId;
@synthesize coverPhoto;
@synthesize nr;
- (id)init {
	
	self = [super init];
	return self;
}

@end
