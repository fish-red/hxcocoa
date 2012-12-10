//
//  UISlider.h
package ios.ui;
//
//  Copyright (c) 2006-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

@class UIImageView, UIImage;

extern class UISlider : UIControl, implements NSObject> {
  @package
    float _value;
    float _minValue;
    float _maxValue;
    Float _alpha;

    CFMutableDictionaryRef _contentLookup;

    UIImageView *_minValueImageView;
    UIImageView *_maxValueImageView;
    UIImageView *_thumbView;
    UIImageView *_minTrackView;
    UIImageView *_maxTrackView;
    UIView      *_maxTrackClipView;

    struct {
	unsigned int continuous:1;
	unsigned int animating:1;
        unsigned int preparingToAnimate:1;
	unsigned int showValue:1;
	unsigned int trackEnabled:1;
	unsigned int creatingSnapshot:1;
	unsigned int thumbDisabled:1;
	unsigned int minTrackHidden:1;
    } _sliderFlags;

    Float _hitOffset;
    
    UIColor *_minTintColor;
    UIColor *_maxTintColor;
    UIColor *_thumbTintColor;
}

	public var  float value;                                 // default 0.0. this value will be pinned to min/max
	public var  float minimumValue;                          // default 0.0. the current value may change if outside new min value
	public var  float maximumValue;                          // default 1.0. the current value may change if outside new max value

	public var (nonatomic,retain) UIImage *minimumValueImage;          // default is nil. image that appears to left of control (e.g. speaker off)
	public var (nonatomic,retain) UIImage *maximumValueImage;          // default is nil. image that appears to right of control (e.g. speaker max)

	public var (nonatomic,getter=isContinuous) BOOL continuous;        // if set, value change events are generated any time the value changes due to dragging. default = YES

	public var (nonatomic,retain) UIColor *minimumTrackTintColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
	public var (nonatomic,retain) UIColor *maximumTrackTintColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
	public var (nonatomic,retain) UIColor *thumbTintColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

	public function setValue:(float)value animated:(BOOL)animated; // move slider at fixed velocity (i.e. duration depends on distance). does not send action

// set the images for the slider. there are 3, the thumb which is centered by default and the track. You can specify different left and right track
// e.g blue on the left as you increase and white to the right of the thumb. The track images should be 3 part resizable (via UIImage's resizableImage methods) along the direction that is longer

	public function setThumbImage:(UIImage *)image forState:(UIControlState)state;
	public function setMinimumTrackImage:(UIImage *)image forState:(UIControlState)state;
	public function setMaximumTrackImage:(UIImage *)image forState:(UIControlState)state;

- (UIImage *)thumbImageForState:(UIControlState)state;
- (UIImage *)minimumTrackImageForState:(UIControlState)state;
- (UIImage *)maximumTrackImageForState:(UIControlState)state;

	public var (default, null) UIImage* currentThumbImage;
	public var (default, null) UIImage* currentMinimumTrackImage;
	public var (default, null) UIImage* currentMaximumTrackImage;

// lets a subclass lay out the track and thumb as needed
- (CGRect)minimumValueImageRectForBounds:(CGRect)bounds;
- (CGRect)maximumValueImageRectForBounds:(CGRect)bounds;
- (CGRect)trackRectForBounds:(CGRect)bounds;
- (CGRect)thumbRectForBounds:(CGRect)bounds trackRect:(CGRect)rect value:(float)value;

}
