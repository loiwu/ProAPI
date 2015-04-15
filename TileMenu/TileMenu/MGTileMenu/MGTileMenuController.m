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

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
