//
//  MGTileMenuDelegate.h
//  TileMenu
//
//  Created by loi on 4/10/15.
//  Copyright (c) 2015 GWrabbit. All rights reserved.
//

#ifndef TileMenu_MGTileMenuDelegate_h
#define TileMenu_MGTileMenuDelegate_h
#endif

#define MG_PAGE_SWITCHING_TILE_INDEX -1

@class MGTileMenuController;
@protocol MGTileMenuDelegate <NSObject>

// Configuration
@required
- (NSInteger)numberOfTilesInMenu:(MGTileMenuController *)tileMenu; // in total (will shown in groups of up to 5 per page)
- (UIImage *)imageForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
- (NSString *)labelForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
- (NSString *)descriptionForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
// N.B. Labels and descriptions (hints) are used for accessibility, and are thus required. They are not displayed.
// N.B. Images are centered on the tile, and are not scaled.
@optional
- (BOOL)isTileEnabled:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber

@end
