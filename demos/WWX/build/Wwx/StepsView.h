//
//  StepsView
//  Wwx
//
//  Code generated by Haxe Objective-C target
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

#import "StepLabel.h"
#import "String.h"
#import "Array.h"

@interface StepsView : UIView 

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)withEvent;
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)withEvent;
- (void)stepTouched:(NSInteger)i;
- (void)setStep:(NSInteger)j;
- (void)_initWithFrame:(CGRect)frame;
@property (nonatomic, strong) NSMutableArray<id> *steps;
@property (nonatomic) NSInteger currentStep;
@property (nonatomic) id delegate;

@end

