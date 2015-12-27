//
//  AlbumPickerController
//  Wwx
//
//  Code generated by Haxe Objective-C target
//


#import <FacebookSDK/FacebookSDK.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <CoreGraphics/CoreGraphics.h>

#import "AlbumPickerController.h"
#import "Array.h"
#import "FBAlbum.h"
#import "haxe/Log.h"
#import "String.h"
#import "AlbumTableViewCell.h"
#import <QuartzCore/QuartzCore.h>

@interface AlbumPickerController : UIViewController <UITableViewDataSource, UITableViewDelegate>

- (BOOL)canSwipeRight;
- (BOOL)canSwipeLeft;
- (void)update;
- (void)loginToFacebook;
- (CGFloat)tableView:(UITableView*)tableView heightForHeaderInSection:(NSInteger)section;
- (UIView*)tableView:(UITableView*)tableView_ viewForHeaderInSection:(NSInteger)section;
- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView;
- (void)tableView:(UITableView*)tableView_ didSelectRowAtIndexPath:(NSIndexPath*)indexPath;
- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath;
- (UITableViewCell*)tableView:(UITableView*)tableView_ cellForRowAtIndexPath:(NSIndexPath*)indexPath;
- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewDidLoad;
- (void)loadView;
// Dynamic method defined with an objc method and a block property
- (void)selectMovieAtPath:(NSString*)path;
@property (nonatomic, copy) void(^hx_dyn_selectMovieAtPath)(NSString*);
// Dynamic method defined with an objc method and a block property
- (void)facebookAlbumPicked:(FBAlbum*)album;
@property (nonatomic, copy) void(^hx_dyn_facebookAlbumPicked)(FBAlbum*);
// Dynamic method defined with an objc method and a block property
- (void)localAlbumPicked:(ALAssetsGroup*)album;
@property (nonatomic, copy) void(^hx_dyn_localAlbumPicked)(ALAssetsGroup*);
@property (nonatomic) id delegate;
@property (nonatomic) BOOL loadingFacebook;
@property (nonatomic, strong) UIActivityIndicatorView *activityView;
@property (nonatomic, strong) NSMutableArray<id> *movies;
@property (nonatomic, strong) NSMutableArray<id> *fb_albums;
@property (nonatomic, strong) NSMutableArray<id> *groups;
@property (nonatomic, strong) ALAssetsLibrary *library;
@property (nonatomic, strong) UITableView *tableView;

@end




@protocol AlbumPickerDelegate<NSObject>




@end
