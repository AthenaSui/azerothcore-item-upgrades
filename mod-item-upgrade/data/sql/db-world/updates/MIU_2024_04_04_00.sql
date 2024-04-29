DELETE FROM `command` WHERE `name`='item_upgrade lock';
INSERT INTO `command`(`name`, `security`, `help`) VALUES ('item_upgrade lock', 3, '语法：.item_upgrade lock
锁定装备升级NPC以进行安全的数据库编辑。玩家将无法再使用NPC，使用.item_upgrade reload命令解除锁定');
 