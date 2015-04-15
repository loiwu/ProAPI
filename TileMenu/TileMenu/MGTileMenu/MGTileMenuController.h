//
//  MGTileMenuController.h
//  TileMenu
//
//  Created by loi on 4/10/15.
//  Copyright (c) 2015 GWrabbit. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGTileMenuDelegate.h"

@interface MGTileMenuController : UIViewController
{
    UIButton *_closeButton;
    NSMutableArray *_tileButtons;
    UIButton *pageButton;
    BOOL _tilesArranged;
    BOOL _animatingTiles;
    BOOL _tileAnimatonInterrupted;
    NSMutableArray *_animationOrder;
    BOOL _singlePageMaxTiles; // indicates the expectional situation of having exactly 6 tiles.
}

@property (nonatomic, weak, readonly) id<MGTileMenuDelegate> delegate; // must be specified via initializer method.
@property (nonatomic, readonly) CGPoint centerPoint; // in parent view's coordinate system. If menu not visible, will be CGPointZero
@property (nonatomic, weak, readonly) UIView *parentView;
@property (nonatomic, readonly) BOOL isVisible;
@property (nonatomic, readonly) NSInteger currentPage; // zero-based

// N.B. All of the following properties should be set BEFORE displaying the menu.
@property (nonatomic) BOOL dismissAfterTileActivated; // automatically dismiss menu after a tile is activated (YES; default)
@property (nonatomic) BOOL rightHanded; // leave gap for right-handed finger (YES; default) or left-handed (NO)
@property (nonatomic) BOOL shadowsEnabled; // whether to draw shadows below bezel and tiles (default: YES)
@property (nonatomic) NSInteger tileSide; // width and height of each tile, in pixels (default 72 pixels)
@property (nonatomic) NSInteger tileGap; // horizontal and vertical gaps between tiles, in pixels (default: 20 pixels)
@property (nonatomic) CGFloat cornerRadius; // corner radius for bezel and all tiles, in pixels (default: 12.0 pixels)
@property (nonatomic) CGGradientRef tileGradient; // gradient to apply to tile backgrounds (default: a lovely blue)
@property (nonatomic) NSInteger selectionBorderWidth; // default: 5 pixels
@property (nonatomic) CGGradientRef selectionGradient; // default: a subtle white (top) to grey (bottom) gradient
@property (nonatomic, strong) UIColor *bezelColor; // color of the background bezel/HUD; default: black, 50% opaque
@property (nonatomic, strong) UIImage *closeButtonImage; // default: nil (which renders a Home Screen-like "X" button)
@property (nonatomic, strong) UIImage *selectedCloseButtonImage; // default: nil (as above)
@property (nonatomic, strong) UIImage *pageButtonImage; // default: nil (which renders an ellipsis "...")
@property (nonatomic) BOOL shouldMoveToStayVisibleAfterRotation; // whether the menu should automatically move to remain fully visible after the device has been rotated (default: YES)
@property (nonatomic) BOOL closeButtonVisible; // whether the close button is visible (default: YES). If NO, the user can still dismiss the menu by tapping outside its bounds (which you can also disable via the tileMenuShouldDismiss: delegate method)

// Creation.
- (id)initWithDelegate:(id<MGTileMenuDelegate>)theDelegate; // required parameter; cannot be nil.

// Utilities
CGGradientRef MGCreateGradientWithColors(UIColor *topColorRGB, UIColor *bottomColorRGB);

@end
