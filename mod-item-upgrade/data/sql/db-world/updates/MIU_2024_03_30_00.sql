DELETE FROM `command` WHERE `name`='item_upgrade reload';
INSERT INTO `command`(`name`, `security`, `help`) VALUES ('item_upgrade reload', 3, '语法：.item_upgrade reload
重新加载装备升级模块的所有必要数据。');
 