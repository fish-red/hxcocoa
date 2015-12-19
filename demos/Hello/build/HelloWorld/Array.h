//
//  Array
//  HelloWorld
//
//  Source generated by Haxe Objective-C target
//



#import "Array.h"
#import "HxIterator.h"
#import "String.h"

@interface NSMutableArray ( Array )

- (id)hx_objectAtIndex:(int)index;
- (void)hx_replaceObjectAtIndex:(int)index withObject:(id)withObject;
- (NSMutableArray *)filter:(id)f;
- (NSMutableArray *)map:(id)f;
- (id)iterator;
- (NSMutableArray *)splice:(int)pos len:(int)len;
- (void)sort:(id)f;
- (NSMutableArray *)slice:(int)pos end:(int)end;
- (id)shift;
- (void)reverse;
- (BOOL)remove:(id)x;
- (void)unshift:(id)x;
- (int)push:(id)x;
- (id)pop;
- (NSString *)toString;
- (NSString *)join:(NSString *)sep;
- (int)lastIndexOf:(id)x fromIndex:(int)fromIndex;
- (int)indexOf:(id)x fromIndex:(int)fromIndex;
- (void)insert:(int)pos x:(id)x;
- (NSMutableArray *)copy;
- (NSMutableArray *)concat:(NSMutableArray *)a;
@property (nonatomic) int length;
- (id)init;

@end

