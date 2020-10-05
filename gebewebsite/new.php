<!DOCTYPE html>
<html>  
<head>

<title>REGISTER HERE FOR GABS PLEASE</title>
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.0.8/css/all.css">
<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<link href="new.css" rel ="stylesheet" type = "text/css">
</head>

<body>
<div class="container register-form">
            <div class="form">
				<form method="post" action="register.php">
                <div class="note">
                    <p>Register into Gabs' domain.</p>
                </div>
				<?php
				if(isset($_SESSION['message'])){
				echo '<p style="color: red;">'.$_SESSION['message'].'</p>';
				$_SESSION['message'] = NULL; 
				}
				?>
                <div class="form-content">
                    <div class="row">
                        <div class="col-md-6">
                            <div class="form-group">
                                <input type="text" name="fullname" class="form-control" placeholder="Please give your full name *">
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="form-group">
                                <input type="text" name="username" class="form-control" placeholder="What would you like to be referred as on this website? (username) *">
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="form-group">
                                <input type="password" name="password" class="form-control" placeholder="Please input your desired password *">
                            </div>
                        </div>
                        <div class="col-md-6">
                                <input type="number" name="phone" class="form-control" placeholder="Please give us your phone number *">
                        </div>			
                        <div class="col-md-6">
                            <div class="form-group">
                                <input type="text" name="address" class="form-control" placeholder="Where do you live? *">
                            </div>
                        </div>	
                        <div class="col-md-6">
                            <div class="form-group">
                                <input type="text" name="city" class="form-control" placeholder="What city do you live in? *">
                            </div>
                        </div>						
                    </div>
                    <input type="submit" name="login" value="Register">
					<button type="button" class="btnSubmit" onclick="location.href='index.php'">Login</button>
				</form>
                </div>
            </div>
        </div>
</body>
</html>