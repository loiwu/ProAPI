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

// Tile background
@optional
- (UIImage *)backgroundImageForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
- (CGGradientRef)gradientForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
- (UIColor *)colorForTile:(NSInteger)tileNumber inMenu:(MGTileMenuController *)tileMenu; // zero-based tileNumber
// N.B. Background images take precedence over gradients, which take precedence over flat colors. Only one will be rendered.
//      Background images are scaled (non-proportionately, so it's best to supply square images) to fit the tile.
//      If none of the above three methods are implemented, or don't return valid data, tiles be rendered with the menu's tileGradient.
//      In all cases, the tiles' backgrounds will be clipped to a rounded rectangle.
//      Note that these methods are also called for the page-switching tile, with tileNumber MG_PAGE_SWITCHING_TILE_INDEX.

@end
