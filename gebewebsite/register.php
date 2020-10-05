<?php 
session_start();
//Including the code from connect.php to connect to your database
include "connect.php";

//Check if there is POSTed data (must have ALL)
if(    
	!empty($_POST['fullname']) &&     //username,
	!empty($_POST['username']) &&     //password,
	!empty($_POST['password']) &&     //username,
	!empty($_POST['phone']) && 
	!empty($_POST['address']) && 
	!empty($_POST['city'])
	)
		{
		  //If posted data available:	 
			  //Check the database if the email is used/registered
			    $query = $db->query("SELECT * FROM tbl_userdata1 WHERE username='".$_POST['username']."'");
			    
				if($query->num_rows > 0) {  //Meaning there is username found in database
				
				  //If the email is registered, go back to new.php send message
			  	    $_SESSION['message'] = "Username entered already been registered. Try another one!";
				    header("Location: new.php");		
				    exit();
				
				} else {
					//Email is not yet registered: (We will not study Validation, Considered all Correct)
				    //Enter all the registration form to the database
					//Go to index informing that registration complete, try login after

					 date_default_timezone_set("Asia/Makassar");
					 $_SESSION['lastlogin'] = date("Y-m-d H:i:s");   //For last login value
					 
					 //This can be put in one line, just to be readable by you
				     $query = "INSERT INTO tbl_userdata1 ( 
								userID,
								fullname,
								username,
								password,
								phone,
								address,
								city,
								lastlogin
								) 
								VALUES (
								NULL,
								'".$_POST['fullname']."',
								'".$_POST['username']."',
								'".$_POST['password']."',
								'".$_POST['phone']."',
								'".$_POST['address']."',
								'".$_POST['city']."',
								'".$_SESSION['lastlogin']."'
								)";
										
					
					//Set the message, registration complete. Open index.php
					    if ($db->query($query) === TRUE) {
						    $_SESSION['message'] = "Registration complete. Please Login to continue!";
					        header("Location: index.php");		
						    exit();
						} else {
							echo "Error: " . $query . "<br>" . $db->error;
						}
				}
		} else {
			//There is empty box, back to registration and fill them all
			$_SESSION['message'] = "Please fill in all fields!";
			header("Location: new.php");		
			exit();
		}
?>