<?php
	$conn =  mysql_connect("localhost","root","000000") or die("数据库链接错误");
	mysql_select_db("acm_lab", $conn) or die("数据库选择错误");
	mysql_query("set names utf8 ");
?>
