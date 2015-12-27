//
//  CollectionCell
//  Wwx
//
//  Code generated by Haxe Objective-C target
//

#import "CollectionCell.h"

@implementation CollectionCell

- (void)dealloc {
	
	[Log trace:@"dealloc collection cell" infos:@{@"fileName":@"CollectionCell.hx", @"lineNumber":@"58", @"className":@"CollectionCell", @"methodName":@"dealloc"}];
	[self.imageView removeFromSuperview];
	self.imageView = nil;
	[self.markImage removeFromSuperview];
	self.markImage = nil;
}
- (void)select:(BOOL)sel {
	
	self.markImage.hidden = !sel;
	if (sel)  {
		
		[UIView beginAnimations:@"zoom" context:nil];
		[UIView setAnimationDuration:0.2];
		self.imageView.frame =  CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
		self.imageView.alpha = 1;
		[UIView commitAnimations];
	}
	else  {
		 {
			
			self.imageView.frame = CGRectMake(6,6,self.frame.size.width - 12,self.frame.size.height - 12);
			self.imageView.alpha = 0.6;
		}
	}
}
- (id) initWithFrame:(CGRect)frame {
	
	self = [super initWithFrame:frame];;
	self.imageView = [[UIImageView alloc] init];
	self.imageView.frame = CGRectMake(0,0,frame.size.width,frame.size.height);
	self.imageView.contentMode = UIViewContentModeScaleAspectFill;
	self.imageView.clipsToBounds = YES;
	[self addSubview:self.imageView];
	self.markImage = [[UIImageView alloc] init];
	self.markImage.frame = CGRectMake(6,6,16,16);
	self.markImage.image = [UIImage imageNamed:@"Checkmark"];
	self.markImage.hidden = YES;
	[self addSubview:self.markImage];
	return self;
}
@synthesize index;
@synthesize markImage;
@synthesize imageView;

@end