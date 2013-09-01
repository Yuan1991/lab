<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<style>
body{
	background-image:url(../JudgeOnline/image/background.jpg)
}
font{
	font-size:20px;
	font-family:微软雅黑;
}
table{
	border-collapse:collapse;
	}
table td{
border:2px solid #FFF;
}

.h{
	font-size:17px;
}
.img_updown{
	width:auto;
	height:auto;
	border:0;
}
	
.img_tx{
	width:50px;
	height:50px;
	border-radius:5px;
	border:5px solid;
	border-color:#FFF;
	margin-top:5px;
	position:relative;
	margin-left:10px;
}
a{
	text-decoration:none;
	color:#333;
}
a:hover{
	color:#2d953c;
}
a:visit{
	color:#333;
}
</style>
<title>实验室在线检测系统</title>
</head>
<body>
</body>
<?php
include "sut_header.html";
?>
<br />
<br />
<br />
<br />
<br />
<?php
$arra['樊毅伟']="349628968"; $arra['李东']="284649813"; $arra['秦思源']="280633000"; $arra['郭鹏程']="417419176"; 
$arra['陈冠希']="438370807"; $arra['王春辉']="739597731"; $arra['王圣林']="428330558"; $arra['李博']="431737446"; 
$arra['常娜']="433177695"; $arra['张婷婷']="349628968"; $arra['杨爽']="349628968"; $arra['毛鹏宇']="236592722"; 
$arra['宫健']="402348605"; $arra['膜拜楼上众神']="349628968"; $arra['王猛']="357026082"; $arra['赵一超']="388966618"; 
$arra['张云鹏']="450878334";$arra['王珏鑫']="343300074";$arra['郭峰']="423584742";$arra['崔文龙']="400357397";
$img_up['1']="shang.png";
$img_up['-1']="xia.png";
$img_up['0']="deng.png";

?>
<centen>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr height="43px;"align="center" bgcolor="#2d953c">
  <td width="10%;"><font  color="#FFFFFF"; style="font-size:25px; font-family:微软雅黑;">rank</font></td>
  <td width="25%;"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">name</font></td>
   <td width="10%;"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">online</font></td>
  <td width="15%"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">time<font class="h">&nbsp;(min)</font></font></td>
  <td width="15%;"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">solved<font class="h">&nbsp;(poj)</font></font></td>
  <td width="15%;"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">result</font></td>
  <td width="10%;"><font color="#FFFFFF" style="font-size:25px;  font-family:微软雅黑;">change</font></td>
  </tr>
  <tr>
  <td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td><td><hr style="width:100%;" color="#2d953c" /></td>
   </tr>
   <?php
	$i=1;
	$f = fopen("acmer6.txt", "r");
	while(! feof($f))
	{
		$line = fgets($f);
		if(!$line)
			break;
		$split_line = explode(' ',$line);
		if($split_line[2]==1)
			$color = "#0F3";
		else
			$color = "#999";
		echo "<tr bgcolor=\"#e9f5e9\" height=\"25%;\" >
		<td height=\"35px;\"align=\"center\"><font>".$i."</font></td>
   		<td height=\"35px;\"align=\"left\"><a href=\"http://www.renren.com/".$arra["$split_line[1]"]."/profile\" target=\"_blank\"><img class=\"img_tx\" src=\"image/".$split_line[1].".gif\" /><font>&nbsp;&nbsp;&nbsp;&nbsp;".$split_line[1]."</font></a></td>
		
		<td  height=\"35px;\"align=\"center\"><div style=\"width:13px; height:13px; background-color:$color;\"></div></font></td>
		<td height=\"35px;\"align=\"center\"><font>".$split_line[3]."</font></td>
		<td height=\"35px;\"align=\"center\"><font>".$split_line[4]."</font></td>
		<td height=\"35px;\"align=\"center\"><font>".$split_line[5]."</font></td>
		<td height=\"35px;\"align=\"center\"><font><img class=\"img_updown\"src=\"image/".$split_line[6].".png\" /></font></td>
  </tr>";
  $i++; 
  }
  fclose($f);
 
?>
</table>
</center>
<br />
<br />

 <?php
include "../JudgeOnline/oj-footer.php";
?>
</body>
</html>
