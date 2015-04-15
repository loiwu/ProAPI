//
//  MGTileMenuController.h
//  TileMenu
//
//  Created by loi on 4/10/15.
//  Copyright (c) 2015 GWrabbit. All rights reserved.
//

#import <UIKit/UIKit.h>

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

@end
