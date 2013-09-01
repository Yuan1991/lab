<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>沈阳工业大学ACM实验室</title>
	<link rel="stylesheet" type="text/css" href="css/index.css">
	<script type="text/javascript" src="js/index.js"></script>
</head>
<body>
	<?php include "conn.php"; ?>
	<?php
		//分割sum_solved为数组，并调用js填写表格write_table()函数
		function sum_solved($p_id,$sum_solved){
			
			$Arr_sum_solved = explode(",",$sum_solved);
			for($i=0;$i<count($Arr_sum_solved);$i++){
				echo "<script>write_table($p_id,$i,$Arr_sum_solved[$i])</script>";
			}
		}
		//截取中文字符串
		function substring($str, $start, $len) {
		     $tmpstr = "";
		     $strlen = $start + $len;
		     for($i = 0; $i < $strlen; $i++) {
		         if(ord(substr($str, $i, 1)) > 0xa0) {
		             $tmpstr .= substr($str, $i, 2);
		             $i++;
		         } else
		             $tmpstr .= substr($str, $i, 1);
		     }
		     return $tmpstr;
		} 
		function getGrade($grade){
			if($grade<=50)
			{
				$color="#1FC8F6";
				$title="初入江湖";
			}
			else if($grade<=100)
			{
				$color="#5AD21F";
				$title="暂露头角";
			}
			else if($grade<=150)
			{
				$color="#F4D800";
				$title="渐入佳境";
			}
			else if($grade<=200)
			{
				$color="#F59B2A";
				$title="炉火纯青";
			}
			else
			{
				$color="#F43500";
				$title="登峰造极";
			}
			$color_title_array['color']=$color;
			$color_title_array['title']=$title;
			return $color_title_array;
		}
	?>
	<div id="contianer">
		<table class="rank_table">
			<tr class="rank_table_tr rank_table_tr1">
				<td>RANK</td>
				<td>NAME</td>
				<td>for(day=0; day<28; day++)</td>
				<td>CF</td>
				<td>POJ</td>
				<td>HDOJ</td>
				<td>SUM_TIME</td>
			</tr>
			<?php
				$sql = "SELECT * FROM acmer ORDER BY `sum30` desc";
				$result = mysql_query($sql);
				$k = 1;
				while($info = mysql_fetch_array($result)){
					if($info['online']){
						echo "<tr class='rank_table_tr rank_table_tr_online'>";
					}
					else{
						echo "<tr class='rank_table_tr'>";
					}
					//rank
					echo "<td class='td1'>".$k."</td>";
					//name
					echo "<td class='td2'><a target='_blank' title='人人网' href='http://www.renren.com/".$info['renren_id']."/profile'><img src=\"image/".$info['name'].".gif\" /></a>";
						echo "<div class='td2_div0'>";
							echo "<div class='td2_div1'><a target'_blank' title='个人博客' href=''>".$info['name']."</a></div>";
							echo "<div class='td2_div2' title='".$info['sign']."'>".substring($info['sign'],0,24)."...</div>";
						echo "</div>";
					echo "</td>";
					//月销量
					echo "<td class='td3'>";//.$info['sum_solved'];
						echo "<table class=\"write_table\" id='".$info['id']."''>";
							for($i=1;$i<=10;$i++){
								echo "<tr>";
								for($j=1;$j<=28;$j++){
									echo "<td></td>";
								}
								echo "</tr>";
							}
							echo "</table>";
					sum_solved($info['id'],$info['sum_solved']);
					echo "</td>";
					//cf rating
					$cf_ct = getGrade($info['cf_rating']);
					echo "<td><a target='_blank' style='color:".$cf_ct['color']."' title='".$cf_ct['title']."' href='http://codeforces.com/profile/".$info['cf_name']."'>".$info['cf_rating']."</a></td>";
					//poj题数
					$poj_ct = getGrade($info['poj_solved']);
					echo "<td><a target='_blank' style='color:".$poj_ct['color']."' title='".$poj_ct['title']."' href='http://poj.org/userstatus?user_id=".$info['poj_name']."'>".$info['poj_solved']."</a></td>";
					//hdoj题数
					$hdoj_ct = getGrade($info['hdoj_solved']);
					echo "<td><a target='_blank' style='color:".$hdoj_ct['color']."' title='".$hdoj_ct['title']."' href='http://acm.hdu.edu.cn/userstatus.php?user=".$info['hdoj_name']."'>".$info['hdoj_solved']."</a></td>";
					//sum_time在线时长
					$sum_time = $info['sum_time'];
					echo "<td  class='td7'>$sum_time</td>";

					echo "</tr>";
					$k++;
				}
			?>
		</table>
	</div>
</body>
</html>
