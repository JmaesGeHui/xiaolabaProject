//
//  SearchViewController.h
//  xiaolaba
//
//  Created by 斯陈 on 2018/1/9.
//  Copyright © 2018年 jackzhang. All rights reserved.
//


/*
 *  备注：搜索控制器 🐾
 */


#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, SearchMode)
{
    /// 实时搜索(搜索内容随着文字的改变实时改变)
    SearchModeRealTime = 0,
    
    /// 非实时搜索(只有当点击键盘上面的搜索按钮时，才进行搜索)
    SearchModeAction
};


@interface SearchViewController : BaseViewController <UITableViewDelegate>

@property(nonatomic, strong) UISearchController *searchController;

@property (weak, nonatomic, readonly) UITableView *tableView;
/** 👀 搜索模式 👀 */
@property (assign, nonatomic) SearchMode searchMode;
/** 👀 搜索框占位文字：默认 “请输入搜索内容” 👀 */
@property (copy, nonatomic) NSString *placeholder;

#pragma mark - 👀 Configure - Data 👀 💤
@property (assign, nonatomic) BOOL showBtn;

@property (assign, nonatomic) NSInteger page;
@property (assign, nonatomic) NSInteger size;
/** 👀 数据源 👀 */
@property(nonatomic, strong) NSMutableArray *dataArr;

/** 👀 搜索结果 👀 */
@property(nonatomic, strong) NSMutableArray *searchResults;

/** 👀 更新搜索结果的数据源 👀 */
@property (copy, nonatomic) NSArray * (^updateSearchResultsConfigure)(NSString *searchText);

- (void) showHudWithText:(NSString *)text;
- (void) hideHud;
#pragma mark - 👀 Configure - TableView 👀 💤

/** 👀 配置组数：默认是 1 👀 */
@property (copy) NSInteger (^numberOfSectionsInTableViewCofigure)(UITableView *tableView, BOOL isSearching);
/** 👀 配置每组的行数：默认是 dataArr/searchResults 的个数 👀 */
@property (copy) NSInteger (^numberOfRowsInSectionConfigure)(UITableView *tableView, NSInteger section, BOOL isSearching);
/** 👀 配置每个cell 👀 */
//@property (copy) UITableViewCell * (^cellForRowAtIndexPathConfigure)(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching);
/** 👀 配置每个cell的高度：默认是 50 👀 */
@property (copy) CGFloat (^heightForRowAtIndexPathConfigure)(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching);
/** 👀 点击了每个cell的回调 👀 */
@property (copy) void (^didSelectRowAtIndexPathConfigure)(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching);
/** 👀 取消点击cell的回调 👀 */
@property (copy) void (^didDeselectRowAtIndexPathConfigure)(UITableView *tableView, NSIndexPath *indexPath, BOOL isSearching);

@end
