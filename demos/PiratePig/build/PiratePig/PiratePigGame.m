//
//  PiratePigGame
//  PiratePig
//
//  Code generated by Haxe Objective-C target
//

#import "PiratePigGame.h"

@implementation PiratePigGame

static NSInteger NUM_COLUMNS;
+ (NSInteger)NUM_COLUMNS {
	if (NUM_COLUMNS == nil) NUM_COLUMNS = 8;
	return NUM_COLUMNS;
}
+ (void) setNUM_COLUMNS:(NSInteger)hx_val {
	NUM_COLUMNS = hx_val;
}
static NSInteger NUM_ROWS;
+ (NSInteger)NUM_ROWS {
	if (NUM_ROWS == nil) NUM_ROWS = 8;
	return NUM_ROWS;
}
+ (void) setNUM_ROWS:(NSInteger)hx_val {
	NUM_ROWS = hx_val;
}
static NSMutableArray<id>* tileImages;
+ (NSMutableArray<id>*)tileImages {
	if (tileImages == nil) tileImages = [@[@"game_bear.png", @"game_bunny_02.png", @"game_carrot.png", @"game_lemon.png", @"game_panda.png", @"game_piratePig.png"] mutableCopy];
	return tileImages;
}
+ (void) setTileImages:(NSMutableArray<id>*)hx_val {
	tileImages = hx_val;
}
- (void)resize:(NSInteger)newWidth newHeight:(NSInteger)newHeight {
	
	CGFloat maxWidth = newWidth * 0.90;
	CGFloat maxHeight = newHeight * 0.86;
	self.currentScale = 1;
	CGFloat currentWidth = self.frame.size.width;
	CGFloat currentHeight = self.frame.size.height;
	if (currentWidth > maxWidth || currentHeight > maxHeight)  {
		
		CGFloat maxScaleX = maxWidth / currentWidth;
		CGFloat maxScaleY = maxHeight / currentHeight;
		if (maxScaleX < maxScaleY)  {
			self.currentScale = maxScaleX;
		}
		else  {
			self.currentScale = maxScaleY;
		}
	}
	CGRect rect = self.frame;
	rect.origin.x = newWidth / 2 - currentWidth * self.currentScale / 2;
	self.frame = rect;
}
- (void)loop:(NSTimer*)aTimer {
	
	if (self.needToCheckMatches)  {
		
		
		NSMutableArray<id> *matchedTiles = [[NSMutableArray<id> alloc] init];
		matchedTiles = [matchedTiles concat:[self findMatches:YES accumulateScore:nil]];
		matchedTiles = [matchedTiles concat:[self findMatches:NO accumulateScore:nil]];
		
		Tile *tile = nil;
		NSInteger i = 0;
		while (i < matchedTiles.length)  {
			
			tile = [matchedTiles hx_objectAtIndex:i];
			[self removeTile:tile.row column:tile.column animate:nil];
			i++;
		}
		if (matchedTiles.length > 0)  {
			
			self.Score.text = [NSString stringWithFormat:@"%i", currentScore];
			[self dropTiles];
		}
	}
}
- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)withEvent {
	
}
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)withEvent {
	
	[Log trace:@"release finger" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"437", @"className":@"PiratePigGame", @"methodName":@"touchesEnded"}];
	self.selectedTile.transform =  CGAffineTransformScale(self.selectedTile.transform, 0.7, 0.7);
	if (! CGPointEqualToPoint(self.cacheMouse, CGPointMake(0,0)) && self.selectedTile != nil && !self.selectedTile.moving)  {
		
		
		UITouch *aTouch = [touches anyObject];
		CGPoint pos = [aTouch locationInView:self];
		CGFloat differenceX = pos.x - self.cacheMouse.x - 10;
		CGFloat differenceY = pos.y - self.cacheMouse.y - 73 - 20;
		if (fabsf(differenceX) > 10 || fabsf(differenceY) > 10)  {
			
			NSInteger swapToRow = self.selectedTile.row;
			NSInteger swapToColumn = self.selectedTile.column;
			if (fabsf(differenceX) > fabsf(differenceY))  {
				
				if (differenceX < 0)  {
					swapToColumn--;
				}
				else  {
					swapToColumn++;
				}
			}
			else  {
				if (differenceY < 0)  {
					swapToRow--;
				}
				else  {
					swapToRow++;
				}
			}
			[self swapTile:self.selectedTile targetRow:swapToRow targetColumn:swapToColumn];
		}
	}
	self.selectedTile = nil;
	self.cacheMouse = CGPointMake(0,0);
}
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)withEvent {
	
}
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)withEvent {
	
	
	NSSet *touchesForView = [withEvent touchesForView:self];
	
	UITouch *aTouch = [touchesForView anyObject];
	self.cacheMouse = [aTouch locationInView:self];
	self.cacheMouse =  CGPointMake(self.cacheMouse.x - 10, self.cacheMouse.y - 73 - 20);
	[Log trace:aTouch infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"406", @"className":@"PiratePigGame", @"methodName":@"touchesBegan"}];
	NSLog(@"cacheMouse %.2fx%.2f", cacheMouse.x, cacheMouse.y);
	if ([touches count] == 1)  {
		
		 {
			
			NSInteger _g1 = 0;
			NSInteger _g = PiratePigGame.NUM_ROWS;
			while (_g1 < _g)  {
				
				NSInteger i = _g1++;
				 {
					
					NSInteger _g3 = 0;
					NSInteger _g2 = PiratePigGame.NUM_COLUMNS;
					while (_g3 < _g2)  {
						
						NSInteger j = _g3++;
						
						Tile *tile = [[self.tiles hx_objectAtIndex:i] hx_objectAtIndex:j];
						if ( CGRectContainsPoint(tile.frame, self.cacheMouse))  {
							
							[Log trace:@"------------------touched something" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"415", @"className":@"PiratePigGame", @"methodName":@"touchesBegan"}];
							NSLog(@"%ix%i %.2f,%.2f %.2fx%.2f", i, j, tile.frame.origin.x, tile.frame.origin.y, tile.frame.size.width, tile.frame.size.height);
							self.selectedTile = tile;
							self.selectedTile.transform =  CGAffineTransformScale(self.selectedTile.transform, 1.4, 1.4);
							return;
						}
						else  {
							self.selectedTile = nil;
						}
					}
				}
			}
		}
		if (self.selectedTile == nil)  {
			self.cacheMouse = CGPointMake(0,0);
		}
	}
}
- (void)dropTiles {
	
	NSInteger _g1 = 0;
	NSInteger _g = PiratePigGame.NUM_COLUMNS;
	while (_g1 < _g)  {
		
		NSInteger column = _g1++;
		NSInteger spaces = 0;
		 {
			
			NSInteger _g3 = 0;
			NSInteger _g2 = PiratePigGame.NUM_ROWS;
			while (_g3 < _g2)  {
				
				NSInteger row = _g3++;
				NSInteger index = PiratePigGame.NUM_ROWS - 1 - row;
				
				Tile *tile = [[self.tiles hx_objectAtIndex:index] hx_objectAtIndex:column];
				if (tile == nil)  {
					spaces++;
				}
				else  {
					if (spaces > 0)  {
						
						CGPoint position = [self getPosition:index + spaces column:column];
						[tile moveTo:0.15 * spaces targetX:position.x targetY:position.y];
						tile.row = index + spaces;
						
						NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:index + spaces];
						[t hx_replaceObjectAtIndex:column withObject:tile];
						t = [self.tiles hx_objectAtIndex:index];
						[t hx_replaceObjectAtIndex:column withObject:[NSNull null]];
						self.needToCheckMatches = YES;
					}
				}
			}
		}
		 {
			
			NSInteger _g21 = 0;
			while (_g21 < spaces)  {
				
				NSInteger i = _g21++;
				NSInteger row1 = spaces - 1 - i;
				[self addTile:row1 column:column animate:YES];
			}
		}
	}
}
- (void)swapTile:(Tile*)tile targetRow:(NSInteger)targetRow targetColumn:(NSInteger)targetColumn {
	
	[Log trace:[@"swipe tile " stringByAppendingString:[Std string:tile]] infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"321", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
	if (targetColumn >= 0 && targetColumn < PiratePigGame.NUM_COLUMNS && targetRow >= 0 && targetRow < PiratePigGame.NUM_ROWS)  {
		
		[Log trace:@"ok" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"323", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
		
		Tile *targetTile = [[self.tiles hx_objectAtIndex:targetRow] hx_objectAtIndex:targetColumn];
		[Log trace:[@"to tile " stringByAppendingString:[Std string:targetTile]] infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"325", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
		if (targetTile != nil && !targetTile.moving)  {
			
			[Log trace:@"ok" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"327", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
			
			NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:targetRow];
			[t hx_replaceObjectAtIndex:targetColumn withObject:tile];
			t = [self.tiles hx_objectAtIndex:tile.row];
			[t hx_replaceObjectAtIndex:tile.column withObject:targetTile];
			[Log trace:@"CHECK FOR MATCHES" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"332", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
			if ([[self findMatches:YES accumulateScore:NO] count] > 0 || [[self findMatches:NO accumulateScore:NO] count] > 0)  {
				
				[Log trace:@"found matches" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"334", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
				targetTile.row = tile.row;
				targetTile.column = tile.column;
				tile.row = targetRow;
				tile.column = targetColumn;
				CGPoint targetTilePosition = [self getPosition:targetTile.row column:targetTile.column];
				CGPoint tilePosition = [self getPosition:tile.row column:tile.column];
				[targetTile moveTo:0.3 targetX:targetTilePosition.x targetY:targetTilePosition.y];
				[tile moveTo:0.3 targetX:tilePosition.x targetY:tilePosition.y];
				self.needToCheckMatches = YES;
			}
			else  {
				 {
					
					[Log trace:@"matches not found" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"348", @"className":@"PiratePigGame", @"methodName":@"swapTile"}];
					
					NSMutableArray<id> *t1 = [self.tiles hx_objectAtIndex:targetRow];
					[t1 hx_replaceObjectAtIndex:targetColumn withObject:targetTile];
					t1 = [self.tiles hx_objectAtIndex:tile.row];
					[t1 hx_replaceObjectAtIndex:tile.column withObject:tile];
				}
			}
		}
	}
}
- (void)removeTile:(NSInteger)row column:(NSInteger)column animate:(BOOL)animate {
	
	// Optional arguments
	if (!animate) animate = YES;
	
	
	NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:row];
	
	Tile *tile = [t hx_objectAtIndex:column];
	if (tile != nil)  {
		
		[tile remove:animate];
		[self.usedTiles push:tile];
	}
	[t hx_replaceObjectAtIndex:column withObject:[NSNull null]];
}
- (void)addTile:(NSInteger)row column:(NSInteger)column animate:(BOOL)animate {
	
	// Optional arguments
	if (!animate) animate = YES;
	
	
	Tile *tile = nil;
	NSInteger type = roundf(rand() %  ([PiratePigGame.tileImages count] - 1));
	NSInteger i = 0;
	
	Tile *usedTile = nil;
	while (i < self.usedTiles.length)  {
		
		usedTile = [self.usedTiles hx_objectAtIndex:i];
		i++;
	}
	if (tile == nil)  {
		tile = [[Tile alloc] init:[PiratePigGame.tileImages hx_objectAtIndex:type]];
	}
	[tile initialize];
	tile.type = type;
	tile.row = row;
	tile.column = column;
	
	NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:row];
	[t hx_replaceObjectAtIndex:column withObject:tile];
	CGPoint position = [self getPosition:row column:column];
	if (animate)  {
		
		CGPoint firstPosition = [self getPosition:-1 column:column];
		tile.alpha = 0;
		CGRect rect = tile.frame;
		rect.origin.x = firstPosition.x;
		rect.origin.y = firstPosition.y;
		tile.frame = rect;
		[tile moveTo:0.15 *  (row + 1) targetX:position.x targetY:position.y];
	}
	else  {
		 {
			
			CGRect rect1 = tile.frame;
			rect1.origin.x = position.x;
			rect1.origin.y = position.y;
			tile.frame = rect1;
		}
	}
	[self.TileContainer addSubview:tile];
	self.needToCheckMatches = YES;
}
- (CGPoint)getPosition:(NSInteger)row column:(NSInteger)column {
	
	return  CGPointMake(column * 73, row * 73);
}
- (NSMutableArray<id>*)findMatches:(BOOL)byRow accumulateScore:(BOOL)accumulateScore {
	
	// Optional arguments
	if (!accumulateScore) accumulateScore = YES;
	
	
	NSMutableArray<id> *matchedTiles = [[NSMutableArray<id> alloc] init];
	NSInteger max;
	NSInteger secondMax;
	if (byRow)  {
		
		max = PiratePigGame.NUM_ROWS;
		secondMax = PiratePigGame.NUM_COLUMNS;
	}
	else  {
		 {
			
			max = PiratePigGame.NUM_COLUMNS;
			secondMax = PiratePigGame.NUM_ROWS;
		}
	}
	 {
		
		NSInteger _g = 0;
		while (_g < max)  {
			
			NSInteger index = _g++;
			NSInteger matches = 0;
			
			NSMutableArray<id> *foundTiles = [[NSMutableArray<id> alloc] init];
			NSInteger previousType = -1;
			 {
				
				NSInteger _g1 = 0;
				while (_g1 < secondMax)  {
					
					NSInteger secondIndex = _g1++;
					
					Tile *tile;
					if (byRow)  {
						
						
						NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:index];
						tile = [t hx_objectAtIndex:secondIndex];
					}
					else  {
						 {
							
							
							NSMutableArray<id> *t1 = [self.tiles hx_objectAtIndex:secondIndex];
							tile = [t1 hx_objectAtIndex:index];
						}
					}
					if (tile != nil && !tile.moving)  {
						
						if (previousType == -1)  {
							
							previousType = tile.type;
							[foundTiles push:tile];
							continue;
						}
						else  {
							if (tile.type == previousType)  {
								
								[foundTiles push:tile];
								matches++;
							}
						}
					}
					if (tile == nil || tile.moving || tile.type != previousType || secondIndex == secondMax - 1)  {
						
						if (matches >= 2 && previousType != -1)  {
							
							if (accumulateScore)  {
								self.currentScore += [Std _int:powf(matches, 2) * 50];
							}
							matchedTiles = [matchedTiles concat:foundTiles];
						}
						matches = 0;
						foundTiles = [[NSMutableArray<id> alloc] init];
						if (tile == nil || tile.moving)  {
							
							self.needToCheckMatches = YES;
							previousType = -1;
						}
						else  {
							 {
								
								previousType = tile.type;
								[foundTiles push:tile];
							}
						}
					}
				}
			}
		}
	}
	return matchedTiles;
}
- (void)newGame {
	
	self.currentScore = 0;
	self.Score.text = @"0";
	 {
		
		NSInteger _g1 = 0;
		NSInteger _g = PiratePigGame.NUM_ROWS;
		while (_g1 < _g)  {
			
			NSInteger row = _g1++;
			 {
				
				NSInteger _g3 = 0;
				NSInteger _g2 = PiratePigGame.NUM_COLUMNS;
				while (_g3 < _g2)  {
					
					NSInteger column = _g3++;
					[self removeTile:row column:column animate:NO];
				}
			}
		}
	}
	 {
		
		NSInteger _g11 = 0;
		NSInteger _g4 = PiratePigGame.NUM_ROWS;
		while (_g11 < _g4)  {
			
			NSInteger row1 = _g11++;
			 {
				
				NSInteger _g31 = 0;
				NSInteger _g21 = PiratePigGame.NUM_COLUMNS;
				while (_g31 < _g21)  {
					
					NSInteger column1 = _g31++;
					[self addTile:row1 column:column1 animate:NO];
				}
			}
		}
	}
	
	NSTimer *timer = [NSTimer timerWithTimeInterval:0.2 target:self selector:@selector(loop:) userInfo:nil repeats:YES];
	
	NSRunLoop *runner = [NSRunLoop currentRunLoop];
	[runner addTimer:timer forMode:NSDefaultRunLoopMode];
}
- (void)construct {
	
	[Log trace:@"Construct" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"79", @"className":@"PiratePigGame", @"methodName":@"construct"}];
	[self addSubview:self.Logo];
	NSInteger contentWidth = 75 * PiratePigGame.NUM_COLUMNS;
	CGRect rect = self.Score.frame;
	rect.origin.x = 0;
	rect.origin.y = 12;
	rect.size.width = 200;
	self.Score.frame = rect;
	[self addSubview:self.Score];
	[self addSubview:self.Background];
	CGRect rect1 = self.TileContainer.frame;
	rect1.origin.x = 14;
	rect1.origin.y = 99;
	self.TileContainer.frame = rect1;
	[self addSubview:self.TileContainer];
}
- (void)initialize {
	
	[Log trace:@"initialize" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"45", @"className":@"PiratePigGame", @"methodName":@"initialize"}];
	self.currentScale = 1;
	self.currentScore = 0;
	self.tiles = [[NSMutableArray<id> alloc] init];
	self.usedTiles = [[NSMutableArray<id> alloc] init];
	 {
		
		NSInteger _g1 = 0;
		NSInteger _g = PiratePigGame.NUM_ROWS;
		while (_g1 < _g)  {
			
			NSInteger row = _g1++;
			[self.tiles push:[[NSMutableArray<id> alloc] init]];
			 {
				
				NSInteger _g3 = 0;
				NSInteger _g2 = PiratePigGame.NUM_COLUMNS;
				while (_g3 < _g2)  {
					
					NSInteger column = _g3++;
					
					NSMutableArray<id> *t = [self.tiles hx_objectAtIndex:row];
					[t hx_replaceObjectAtIndex:column withObject:[NSNull null]];
				}
			}
		}
	}
	self.Background = [[UIView alloc] init];
	self.Logo = [[UIImageView alloc]  initWithImage:[UIImage imageNamed:@"logo.png"]];
	CGRect bs = self.Logo.frame;
	bs.origin.x = 320. - bs.size.width / 2;
	self.Logo.frame = bs;
	self.Score = [[UILabel alloc] init];
	self.Score.frame = CGRectMake(0,0,100,50);
	self.Score.textColor = [UIColor redColor];
	self.Score.backgroundColor = [UIColor clearColor];
	self.Score.textAlignment = NSTextAlignmentLeft;
	self.Score.font = [UIFont boldSystemFontOfSize:30];
	self.TileContainer = [[UIView alloc] init];
}
@synthesize usedTiles;
@synthesize tiles;
@synthesize selectedTile;
@synthesize needToCheckMatches;
@synthesize cacheMouse;
@synthesize currentScore;
@synthesize currentScale;
@synthesize TileContainer;
@synthesize Score;
@synthesize Logo;
@synthesize Background;
- (id)init {
	
	self = [super init];
	[Log trace:@"start" infos:@{@"fileName":@"PiratePigGame.hx", @"lineNumber":@"38", @"className":@"PiratePigGame", @"methodName":@"new"}];
	[self initialize];
	[self construct];
	[self newGame];
	return self;
}

@end
