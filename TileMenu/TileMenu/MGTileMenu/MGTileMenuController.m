//
//  MGTileMenuController.m
//  TileMenu
//
//  Created by loi on 4/10/15.
//  Copyright (c) 2015 GWrabbit. All rights reserved.
//

#import "MGTileMenuController.h"

@interface MGTileMenuController ()

@end

@implementation MGTileMenuController

@synthesize delegate = _delegate;
@synthesize centerPoint = _centerPoint;
@synthesize parentView = _parentView;
@synthesize isVisible = _isVisible;
@synthesize currentPage = _currentPage;

@synthesize dismissAfterTileActivated = _dismissAfterTileActivated;
@synthesize rightHanded = _rightHanded;
@synthesize shadowsEnabled = _shadowsEnabled;
@synthesize tileSide = _tileSide;
@synthesize tileGap = _tileGap;
@synthesize cornerRadius = _cornerRadius;
@synthesize tileGradient = _tileGradient;
@synthesize selectionBorderWidth = _selectionBorderWidth;
@synthesize selectionGradient = _selectionGradient;
@synthesize bezelColor = _bezelColor;
@synthesize closeButtonImage = _closeButtonImage;
@synthesize selectedCloseButtonImage = _selectedCloseButtonImage;
@synthesize pageButtonImage = _pageButtonImage;
@synthesize shouldMoveToStayVisibleAfterRotation = _shouldMoveToStayVisibleAfterRotation;
@synthesize closeButtonVisible = _closeButtonVisible;

#pragma mark - Creation and destruction

- (id)initWithDelegate:(id<MGTileMenuDelegate>)theDelegate
{
    if (theDelegate && [theDelegate conformsToProtocol:@protocol(MGTileMenuDelegate)]) {
        _delegate = theDelegate;
        return (self = [self initWithNibName:nil bundle:nil]);
    }
    
    return nil;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        _centerPoint = CGPointZero;
        _isVisible = NO;
        _currentPage = 0;
        _dismissAfterTileActivated = YES;
        _rightHanded = YES;
        _shadowsEnabled = YES;
        _tileSide = 72;
        _tileGap = 20;
        _cornerRadius = 12.0;
        _tileGradient = MGCreateGradientWithColors([UIColor colorWithRed:0.28 green:0.67 blue:0.90 alpha:1.0], [UIColor colorWithRed:0.19 green:0.46 blue:0.76 alpha:1.0]);
        _selectionBorderWidth = 5;
        _selectionGradient = MGCreateGradientWithColors([UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:1.0], [UIColor colorWithRed:0.93 green:0.93 blue:0.93 alpha:1.0]);
        _bezelColor = [UIColor colorWithWhite:0 alpha:0.50];
        _closeButtonImage = nil;
        _selectedCloseButtonImage = nil;
        _pageButtonImage = nil;
        _shouldMoveToStayVisibleAfterRotation = YES;
        _closeButtonVisible = YES;
        
        // Clockwise from left.
        _animationOrder = [NSMutableArray arrayWithObjects:
                           [NSNumber numberWithInteger:3],
                           [NSNumber numberWithInteger:0],
                           [NSNumber numberWithInteger:1],
                           [NSNumber numberWithInteger:2],
                           [NSNumber numberWithInteger:4],
                           nil];
        
        _singlePageMaxTiles = NO;
    }
    return self;
}

- (void)dealloc
{
    CGGradientRelease(_tileGradient);
    CGGradientRelease(_selectionGradient);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Utilities

CGGradientRef MGCreateGradientWithColors(UIColor *topColorRGB, UIColor *bottomColorRGB)
{
    CGColorSpaceRef rgb = CGColorSpaceCreateDeviceRGB();
    CGFloat locations[2] = {0, 1};
    CGFloat topRed, topGreen, topBlue, topAlpha, bottomRed, bottomGreen, bottomBlue, bottomAlpha;
    [topColorRGB getRed:&topRed green:&topGreen blue:&topBlue alpha:&topAlpha];
    [bottomColorRGB getRed:&bottomRed green:&bottomGreen blue:&bottomBlue alpha:&bottomAlpha];
    CGFloat gradientColors[] =
    {
        topRed, topGreen, topBlue, topAlpha,
        bottomRed, bottomGreen, bottomBlue, bottomAlpha,
    };
    CGGradientRef gradient = CGGradientCreateWithColorComponents(rgb, gradientColors, locations, 2);
    CGColorSpaceRelease(rgb);
    
    return gradient; // follows the "Create rule"; i.e. must be released by caller (even with ARC)
}

@end
