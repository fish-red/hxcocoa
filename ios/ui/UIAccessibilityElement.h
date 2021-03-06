//
//  UIAccessibilityElement.h
//  UIAccessibility
//
//  Copyright (c) 2008-2012, Apple Inc. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIAccessibilityConstants.h>
#import <UIKit/UIAccessibilityIdentification.h>

/*
 UIAccessibilityElement
 
 Instances of this class can be used as "fake" accessibility elements.
 An accessibility container (see UIAccessibility.h) can create and vend instances
 of UIAccessibilityElement to cover for user interface items that are not
 backed by a UIView (for example: painted text or icon).
 */
@:require(3_0)extern class UIAccessibilityElement extends NSObject<UIAccessibilityIdentification>

// initialize with the accessibility container that contains this element
- (id)initWithAccessibilityContainer:(id)container;

	public var id accessibilityContainer;
	public var BOOL isAccessibilityElement;
	public var String *accessibilityLabel;
	public var String *accessibilityHint;
	public var String *accessibilityValue;
	public var CGRect accessibilityFrame;
	public var UIAccessibilityTraits accessibilityTraits;

}
