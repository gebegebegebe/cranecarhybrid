<?php
//This file is used to connect to your database
//Fill in the following with the information from your database


//Because we connect directly from the hosting, fill in with localhost, otherwise fill the MySQL database server address/ip address
$dbHost =        'localhost';                  
$dbUsername =    'id12317080_usernamep';
$dbPassword =    '#%@(e>ae3LziH@@t';
$dbName =        'id12317080_practise';

//This variable is the command to connect to your database
$db = new mysqli($dbHost,$dbUsername,$dbPassword,$dbName);  //connects application to database   


?>
