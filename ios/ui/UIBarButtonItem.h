//
//  UIBarButtonItem.h
package ios.ui;
//
//  Copyright (c) 2008-2012, Apple Inc. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIBarItem.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIApplication.h>

typedef NS_ENUM(NSInteger, UIBarMetrics) {
    UIBarMetricsDefault,
    UIBarMetricsLandscapePhone,
};

typedef NS_ENUM(NSInteger, UIBarButtonItemStyle) {
    UIBarButtonItemStylePlain,    // shows glow when pressed
    UIBarButtonItemStyleBordered,
    UIBarButtonItemStyleDone,
};

typedef NS_ENUM(NSInteger, UIBarButtonSystemItem) {
    UIBarButtonSystemItemDone,
    UIBarButtonSystemItemCancel,
    UIBarButtonSystemItemEdit,  
    UIBarButtonSystemItemSave,  
    UIBarButtonSystemItemAdd,
    UIBarButtonSystemItemFlexibleSpace,
    UIBarButtonSystemItemFixedSpace,
    UIBarButtonSystemItemCompose,
    UIBarButtonSystemItemReply,
    UIBarButtonSystemItemAction,
    UIBarButtonSystemItemOrganize,
    UIBarButtonSystemItemBookmarks,
    UIBarButtonSystemItemSearch,
    UIBarButtonSystemItemRefresh,
    UIBarButtonSystemItemStop,
    UIBarButtonSystemItemCamera,
    UIBarButtonSystemItemTrash,
    UIBarButtonSystemItemPlay,
    UIBarButtonSystemItemPause,
    UIBarButtonSystemItemRewind,
    UIBarButtonSystemItemFastForward,
#if __IPHONE_3_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    UIBarButtonSystemItemUndo,
    UIBarButtonSystemItemRedo,
#endif
#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
    UIBarButtonSystemItemPageCurl,
#endif
};

@class UIImage, UIView;

extern class UIBarButtonItem : UIBarItem, implements NSObject> {
  @private
    NSString     *_title;
    NSSet        *_possibleTitles;
    SEL           _action;
    id            _target;
    UIImage      *_image;
    UIImage      *_landscapeImagePhone;
    UIEdgeInsets  _imageInsets;
    UIEdgeInsets  _landscapeImagePhoneInsets;
    Float       _width;   
    UIView       *_view;
    NSInteger     _tag;
    id            _appearanceStorage;
    struct {
        unsigned int enabled:1;
        unsigned int style:3;
        unsigned int isSystemItem:1;
        unsigned int systemItem:7;
        unsigned int viewIsCustom:1;
        unsigned int isMinibarView:1;
        unsigned int disableAutosizing:1;
        unsigned int selected:1;
        unsigned int imageHasEffects:1;
    } _barButtonItemFlags;
}

- (id)initWithImage:(UIImage *)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (id)initWithImage:(UIImage *)image landscapeImagePhone:(UIImage *)landscapeImagePhone style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action NS_AVAILABLE_IOS(5_0); // landscapeImagePhone will be used for the bar button image in landscape bars in UIUserInterfaceIdiomPhone only
- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(id)target action:(SEL)action;
- (id)initWithCustomView:(UIView *)customView;

	public var          UIBarButtonItemStyle style;            // default is UIBarButtonItemStylePlain
	public var          Float              width;            // default is 0.0
public var     NSSet               *possibleTitles;   // default is nil
	public var (nonatomic,retain)  UIView              *customView;       // default is nil
	public var          SEL                  action;           // default is NULL
	public var   id                   target;           // default is nil

//
// Appearance modifiers
//

/* Send these messages to the [UIBarButtonItem appearance] proxy to customize all buttons, or, to customize a specific button, send them to a specific UIBarButtonItem instance, which may be used in all the usual places in a UINavigationItem (backBarButtonItem, leftBarButtonItem, rightBarButtonItem) or a UIToolbar.
 */

/* In general, you should specify a value for the normal state to be used by other states which don't have a custom value set.
 
 Similarly, when a property is dependent on the bar metrics (on the iPhone in landscape orientation, bars have a different height from standard), be sure to specify a value for UIBarMetricsDefault.
 
 This sets the background image for buttons of any style.
 */
	public function setBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (UIImage *)backgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* This sets the background image for buttons with a specific style. When calling this on a UIBarButtonItem instance, the style argument must match the button's style; when calling on the UIAppearance proxy, any style may be passed.
 */
	public function setBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state style:(UIBarButtonItemStyle)style barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
- (UIImage *)backgroundImageForState:(UIControlState)state style:(UIBarButtonItemStyle)style barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

	public var (nonatomic,retain) UIColor *tintColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* For adjusting the vertical centering of bordered bar buttons within the bar 
 */
	public function setBackgroundVerticalPositionAdjustment:(Float)adjustment forBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; 
- (Float)backgroundVerticalPositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* For adjusting the position of a title (if any) within a bordered bar button 
 */
	public function setTitlePositionAdjustment:(UIOffset)adjustment forBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; 
- (UIOffset)titlePositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* The remaining appearance modifiers apply solely to UINavigationBar back buttons and are ignored by other buttons.
 */
/*
 backgroundImage must be a resizable image for good results.
 */
	public function setBackButtonBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (UIImage *)backButtonBackgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

	public function setBackButtonTitlePositionAdjustment:(UIOffset)adjustment forBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (UIOffset)backButtonTitlePositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* For adjusting the vertical centering of bordered bar buttons within the bar 
 */
	public function setBackButtonBackgroundVerticalPositionAdjustment:(Float)adjustment forBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR; 
- (Float)backButtonBackgroundVerticalPositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

}

