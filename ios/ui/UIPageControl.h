//
//  UIPageControl.h
package ios.ui;
//
//  Copyright (c) 2008-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

extern class UIPageControl extends UIControl {
  @private
    NSMutableArray* _indicators;
    NSInteger       _currentPage;
    NSInteger       _displayedPage;
    struct {
        unsigned int hideForSinglePage:1;
        unsigned int defersCurrentPageDisplay:1;
    } _pageControlFlags;
    UIImage*        _currentPageImage;
    UIImage*        _pageImage;
}

	public var  NSInteger numberOfPages;          // default is 0
	public var  NSInteger currentPage;            // default is 0. value pinned to 0..numberOfPages-1

	public var  BOOL hidesForSinglePage;          // hide the the indicator if there is only one page. default is NO

	public var  BOOL defersCurrentPageDisplay;    // if set, clicking to a new page won't update the currently displayed page until -updateCurrentPageDisplay is called. default is NO
	public function updateCurrentPageDisplay;                      // update page display to match the currentPage. ignored if defersCurrentPageDisplay is NO. setting the page value directly will update immediately

- (CGSize)sizeForNumberOfPages:(Int)pageCount;   // returns minimum size required to display dots for given page count. can be used to size control if page count could change

	public var (nonatomic,retain) UIColor *pageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
	public var (nonatomic,retain) UIColor *currentPageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

}
