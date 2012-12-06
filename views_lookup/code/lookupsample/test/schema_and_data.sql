# `city_list` 的追踪报告
# 2012-11-28 06:16:35

DROP TABLE IF EXISTS `city_list`;

CREATE TABLE `city_list` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'identifier of the city',
  `name` varchar(36) NOT NULL,
  `country` varchar(36) NOT NULL,
  `code` varchar(6) NOT NULL,
  `continent` varchar(16) NOT NULL,
  `country_code` varchar(6) NOT NULL,
  PRIMARY KEY (`id`)
);



INSERT INTO `city_list` (`id`, `name`, `country`, `code`, `continent`, `country_code`) VALUES
(1, 'Beijing', 'China', 'BJ', 'Asia', 'CN'),
(2, 'Auckland', 'New Zealand', 'AK', 'Oceania ', 'NZ'),
(3, 'Chicago', 'USA', 'CH', 'North America', 'US');

