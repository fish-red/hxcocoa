/*
    NSOpenPanel.h
    Application Kit
    Copyright (c) 1994-2011, Apple Inc.
    All rights reserved.
*/

#import <AppKit/NSSavePanel.h>
@class NSArray;
@class NSString;
@class NSWindow;

extern class NSOpenPanel extends NSSavePanel {
@private
    char _reservedOpenPanel[4];
    void *_privateOpenPanel;
}

/* Creates a new instance of the NSOpenPanel. This class is not a singleton. 
 */
+ (NSOpenPanel *)openPanel;

- (NSArray *)URLs;

- (BOOL)resolvesAliases;
- (void)setResolvesAliases:(BOOL)flag;

- (BOOL)canChooseDirectories;
- (void)setCanChooseDirectories:(BOOL)flag;

- (BOOL)allowsMultipleSelection;
- (void)setAllowsMultipleSelection:(BOOL)flag;

- (BOOL)canChooseFiles;
- (void)setCanChooseFiles:(BOOL)flag;

}

extern class NSOpenPanel (NSDeprecated)

/* Use URLs instead.
 */
- (NSArray *)filenames NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -beginSheetModalForWindow:completionHandler: instead.
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (void)beginSheetForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes modalForWindow:(NSWindow *)docWindow modalDelegate:(id)delegate didEndSelector:(SEL)didEndSelector contextInfo:(void *)contextInfo NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -beginWithCompletionHandler: instead. 
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (void)beginForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes modelessDelegate:(id)delegate didEndSelector:(SEL)didEndSelector contextInfo:(void *)contextInfo  NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -runModal instead. 
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (Int)runModalForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -runModal instead. 
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (Int)runModalForTypes:(NSArray *)fileTypes NS_DEPRECATED_MAC(10_0, 10_6);

}
