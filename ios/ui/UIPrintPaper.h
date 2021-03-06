//
//  UIPrintPaper.h
package ios.ui;
//
//  Copyright 2010-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@:require(4_2)extern class UIPrintPaper extends NSObject {
  @private
    int _paperOrientation;
    id  _internal;
}

+ (UIPrintPaper *)bestPaperForPageSize:(CGSize)contentSize withPapersFromArray:(NSArray *)paperList; // for use by delegate. pass in list

	public var  (default, null) extends CGSize paperSize;
	public var  (default, null) extends CGRect printableRect;

}

//_____________________________________________

extern class UIPrintPaper(Deprecated_Nonfunctional)
- (CGRect)printRect;
}
