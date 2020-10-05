<?php
session_start();
//Including the code from connect.php to connect to your database
include "connect.php";

//BLOCK IF, if no data POSTed, go to else (which will go back to the index.php)
if(!empty($_POST['username']) || !empty($_POST['password'])) {
	
	//This Code will do query to database to get username that is equal
	//with the $_POST['username']
    $query = $db->query("SELECT * FROM tbl_userdata1 WHERE username='".$_POST['username']."'");
    
	//The data received (from row name, if zero no username) then populated to the variable $data
    if($query->num_rows < 1) {
		
		//Username is Incorrect
		$_SESSION['message'] = "Username is not registered.";
		header("Location: index.php");
		exit();
		
	} else {
		//Username found, get the data from database
		while ($row = $query->fetch_assoc()) {
		$data['username'] = $row['username'];
		$data['password'] = $row['password'];
		$data['ID']       = $row['userID'];
		}
	
		//Check if Password is same with the ones saved in the database
		if ($data['password'] != $_POST['password']) {
			
			//Password is wrong so comeback to index.php page, display message.
			$_SESSION['message'] = "Wrong password or password is empty";
			header("Location: index.php");
			exit();
		
			} else {
		
			//Password is correct, so comeback to index.php and display 
			//personalized page
			$_SESSION['message'] = "Login accepted, please wait";    
			$_SESSION['logged'] = TRUE;
			$_SESSION['user_id'] = $data['ID'];
			$_SESSION['email'] = $data['username'];
			
			//Update the last login information to database
			date_default_timezone_set("Asia/Makassar");
			$_SESSION['lastlogin'] = date("Y-m-d H:i:s");
			$query = $db->query("UPDATE tbl_userdata1 SET lastlogin='".$_SESSION['lastlogin']."' WHERE userID='".$data['ID']."'");
			
			//Go to the index.php file
			header("Location: index.php");
			exit();
			}
	}
}
else
{
    //If no $POST data send message back to index.php
	$_SESSION['message'] = "Username and/or password is empty";
    header("Location: index.php");
    exit();
}
?>