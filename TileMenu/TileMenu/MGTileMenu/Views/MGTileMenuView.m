//
//  MGTileMenuView.m
//  TileMenu
//
//  Created by loi on 4/10/15.
//  Copyright (c) 2015 GWrabbit. All rights reserved.
//

#import "MGTileMenuView.h"
#import <QuartzCore/QuartzCore.h>

@implementation MGTileMenuView

@synthesize controller;

- (void)drawRect:(CGRect)rect
{
    // It's tough being this good, but somehow I manage.
    [controller.bezelColor set];
    [[controller _bezelPath] fill];
}

@end
