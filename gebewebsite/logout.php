<?php
// Start the session 
session_start();
 
// Destroy everything in this session
session_destroy();

//Go to the front page, because you are logged off, it will display the login screen.
header("Location: index.php");
?>