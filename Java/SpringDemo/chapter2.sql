DROP DATABASE IF EXISTS sampledb;

CREATE DATABASE sampledb DEFAULT CHARACTER SET utf8;

USE sampledb;

CREATE TABLE t_user (
	`user_id` INT AUTO_INCREMENT,
	`user_name` VARCHAR(30),
	`credits` INT,
	`password` VARCHAR(32),
	`last_visit` datetime,
	`last_ip` VARCHAR(23),
	pPRIMARY KEY (`user_id`)
)ENGINE=InnoDB;

CREATE TABLE t_login_log (
	`login_log_id` INT AUTO_INCREMENT,
	`user_id` INT,
	`ip` VARCHAR(32),
	`login_datetime` datetime,
	PRIMARY KEY (`login_log_id`)
)ENGINE=InnoDB;

INSERT INTO t_user (user_name, password)
            VALUES('admin', '123456');
COMMIT;
