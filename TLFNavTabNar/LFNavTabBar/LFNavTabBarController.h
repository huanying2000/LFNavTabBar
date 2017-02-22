//
//  LFNavTabBarController.h
//  TLFNavTabNar
//
//  Created by mac on 17/2/22.
//  Copyright © 2017年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LFNavTabBarController : UIViewController

@property (nonatomic, assign)   BOOL showArrowButton;
@property (nonatomic, assign)   BOOL scrollAnimation;
@property (nonatomic, assign)   BOOL mainViewBounces;

@property (nonatomic, strong)   NSArray *subViewControllers;

@property (nonatomic, strong)   UIColor *navTabBarColor;
@property (nonatomic, strong)   UIColor *navTabBarLineColor;
@property (nonatomic, strong)   UIImage *navTabBarArrowImage;


- (id)initWithShowArrowButton:(BOOL)show;

- (id)initWithSubViewControllers:(NSArray *)subViewControllers;

- (id)initWithParentViewController:(UIViewController *)viewController;

- (id)initWithSubViewControllers:(NSArray *)subControllers andParentViewController:(UIViewController *)viewController showArrowButton:(BOOL)show;

- (void)addParentController:(UIViewController *)viewController;

@end
